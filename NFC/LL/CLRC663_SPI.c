/**
 * @file        CLRC663_SPI.c
 * @brief       CLRC663 底层 SPI 驱动实现文件
 * @details     基于 STM32 HAL 库 SPI1 和 NSS 软件控制（PA4），实现了
 *              数据手册中定义的 CLRC663 特殊管线式（Pipelined）SPI 读时序
 *              以及连续自增/非自增（FIFO）读写功能。
 * @author      Antigravity (Pair Programming with USER)
 * @date        2026-06-02
 * @version     V1.0
 * @copyright   Copyright (c) 2026
 */

#include "CLRC663_SPI.h"
#include "CLRC663_Register.h"
#include "spi.h"

/* -------------------------------------------------------------------------- */
/*                                1. 写寄存器操作 */
/* -------------------------------------------------------------------------- */

/**
 * @brief       向 CLRC663 写入单字节数据
 * @param       reg 寄存器物理地址
 * @param       val 写入的数值
 */
void CLRC663_WriteReg(uint8_t reg, uint8_t val) {
  uint8_t tx_data[2];
  /* 地址字节格式：Bit 7..1 存放寄存器地址高 7 位，LSB (Bit 0) 为 0 代表写操作
   */
  tx_data[0] = (reg << 1) & 0xFE;
  tx_data[1] = val;

  CLRC663_NSS_LOW();
  HAL_SPI_Transmit(&hspi1, tx_data, 2, 100);
  CLRC663_NSS_HIGH();
}

/**
 * @brief       向 CLRC663 连续写入多个字节（寄存器地址自增）
 * @param       reg 起始寄存器物理地址
 * @param       data 待写入数据缓冲区指针
 * @param       len 写入的字节数
 */
void CLRC663_WriteRegs(uint8_t reg, uint8_t *data, uint16_t len) {
  if (len == 0 || data == NULL)
    return;

  /* 连续写首字节地址：LSB (Bit 0) 为 0 代表写 */
  uint8_t addr_byte = (reg << 1) & 0xFE;

  CLRC663_NSS_LOW();
  /* 发送起始地址 */
  HAL_SPI_Transmit(&hspi1, &addr_byte, 1, 100);
  /* 连续写入后续数据（CLRC663 硬件会自动将地址累加） */
  HAL_SPI_Transmit(&hspi1, data, len, 100);
  CLRC663_NSS_HIGH();
}

/**
 * @brief       向 CLRC663 FIFO 缓冲区连续写入多字节数据（FIFO
 * 寄存器地址不自增）
 * @param       data 待写入 FIFO 数据的缓冲区指针
 * @param       len 数据字节数
 */
void CLRC663_WriteFifo(uint8_t *data, uint16_t len) {
  /* 写入 FIFO 缓冲区只需要往 FIFODATA 寄存器连续写数据，地址自动保持不递增 */
  CLRC663_WriteRegs(CLRC663_REG_FIFODATA, data, len);
}

/* -------------------------------------------------------------------------- */
/*                                2. 读寄存器操作 */
/* -------------------------------------------------------------------------- */

/**
 * @brief       从 CLRC663 读取单字节数据
 * @details     由于 CLRC663 采用管线式读时序，通过 2 字节一次性全双工传输
 *              可以有效防止 STM32 SPI 接收缓冲区产生 Overrun (OVR) 错误：
 *              1. 第一个字节为要读取的寄存器地址（LSB = 1）
 *              2. 第二个字节为 Dummy 字节（0x00）
 * @param       reg 寄存器物理地址
 * @return      读取到的数值
 */
uint8_t CLRC663_ReadReg(uint8_t reg) {
  uint8_t tx_data[2];
  uint8_t rx_data[2] = {0};

  /* 地址字节格式：Bit 7..1 存放寄存器地址高 7 位，LSB (Bit 0) 为 1 代表读操作
   */
  tx_data[0] = (reg << 1) | 0x01;
  tx_data[1] = 0x00;

  CLRC663_NSS_LOW();
  /* 采用 2 字节一次性全双工传输，避免 Overrun 溢出错误和时钟间断 */
  HAL_SPI_TransmitReceive(&hspi1, tx_data, rx_data, 2, 100);
  CLRC663_NSS_HIGH();

  return rx_data[1];
}

/**
 * @brief       从 CLRC663 连续读取多个字节（寄存器地址自增）
 * @details     管线式连续读原理（根据数据手册表格 7.4.2.2）：
 *              在传输第 n 字节时，MOSI 必须提供要读的第 n 字节的寄存器地址；
 *              此时 MISO 正在返回第 n-1 字节读出的寄存器数据。
 *              因此最后需要多传输一次虚拟字节（0x00）来获取最后一个寄存器的值。
 * @param       reg 起始寄存器物理地址
 * @param       data 存放数据的缓冲区指针
 * @param       len 待读取的字节数
 */
void CLRC663_ReadRegs(uint8_t reg, uint8_t *data, uint16_t len) {
  if (len == 0 || data == NULL)
    return;

  CLRC663_NSS_LOW();

  /* 发送第 1 个寄存器的读地址字节 */
  uint8_t tx_val = (reg << 1) | 0x01;
  HAL_SPI_Transmit(&hspi1, &tx_val, 1, 100);

  /* 循环发送第 2 ~ len 个寄存器的地址，并在过程中收取前一个读取到的数据 */
  for (uint16_t i = 0; i < len - 1; i++) {
    tx_val = ((reg + i + 1) << 1) | 0x01;
    HAL_SPI_TransmitReceive(&hspi1, &tx_val, &data[i], 1, 100);
  }

  /* 发送最后一个虚拟字节 0x00 获取最后一个寄存器的数据 */
  tx_val = 0x00;
  HAL_SPI_TransmitReceive(&hspi1, &tx_val, &data[len - 1], 1, 100);

  CLRC663_NSS_HIGH();
}

/**
 * @brief       从 CLRC663 FIFO 缓冲区连续读取多字节数据（FIFO
 * 寄存器地址不自增）
 * @details     原理与普通连续读相同，但由于 FIFO 不需要自增地址，
 *              在过程中传输的 MOSI 地址始终保持为 FIFODATA 寄存器（0x05）。
 * @param       data 接收 FIFO 数据的缓冲区指针
 * @param       len 数据字节数
 */
void CLRC663_ReadFifo(uint8_t *data, uint16_t len) {
  if (len == 0 || data == NULL)
    return;

  CLRC663_NSS_LOW();

  /* 始终发送 FIFODATA 寄存器的读地址 */
  uint8_t tx_val = (CLRC663_REG_FIFODATA << 1) | 0x01;
  HAL_SPI_Transmit(&hspi1, &tx_val, 1, 100);

  /* 持续发送 FIFODATA 地址以连续获取 FIFO 数据 */
  for (uint16_t i = 0; i < len - 1; i++) {
    HAL_SPI_TransmitReceive(&hspi1, &tx_val, &data[i], 1, 100);
  }

  /* 发送最后一个虚拟字节 0x00 导出最后一个 FIFO 字节 */
  uint8_t dummy = 0x00;
  HAL_SPI_TransmitReceive(&hspi1, &dummy, &data[len - 1], 1, 100);

  CLRC663_NSS_HIGH();
}

/**
 * @brief       CLRC663 芯片硬件复位
 * @details     控制 CLRC663_PDOWN 引脚（PC4），拉高复位，持续至少 2ms。
 *              放开复位拉低，延时 1ms 后，通过读取 COMMAND
 * 寄存器验证复位后的默认值（0x00） 来确认复位及 SPI 通信是否成功。
 * @return      uint8_t 返回 1 表示复位成功且通信正常，返回 0
 * 表示复位失败或通信异常
 */
uint8_t CLRC663_HW_Reset(void) {
  uint8_t cmd_val;
  /* 1. 控制 PDOWN 引脚（PC4）拉高，进入硬件复位/掉电状态 */
  HAL_GPIO_WritePin(CLRC663_PDOWN_GPIO_Port, CLRC663_PDOWN_Pin, GPIO_PIN_SET);
  /* 2. 保证复位持续 2ms 以上 */
  HAL_Delay(2);
  /* 3. 放开复位（拉低 PDOWN 引脚） */
  HAL_GPIO_WritePin(CLRC663_PDOWN_GPIO_Port, CLRC663_PDOWN_Pin, GPIO_PIN_RESET);
  /* 4. 可靠复位放开之后，延时 1ms 确保芯片内部逻辑和时钟稳定 */
  HAL_Delay(10);

  /* 5. 读取 COMMAND 寄存器并校验复位默认值 (0x00) */
  cmd_val = CLRC663_ReadReg(CLRC663_REG_COMMAND);

  if (cmd_val == 0x40) {
    return 1; // 复位正确，通信正常
  } else {
    return 0; // 复位错误，通信异常
  }
}
