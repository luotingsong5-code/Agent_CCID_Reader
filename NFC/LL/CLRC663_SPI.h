/**
 * @file        CLRC663_SPI.h
 * @brief       CLRC663 底层 SPI 驱动头文件
 * @details     提供 SPI NSS 片选引脚的宏控制、寄存器单字节与多字节读写、
 *              以及 FIFO 读写底层函数声明。
 * @author      Antigravity (Pair Programming with USER)
 * @date        2026-06-02
 * @version     V1.0
 * @copyright   Copyright (c) 2026
 */

#ifndef CLRC663_SPI_H
#define CLRC663_SPI_H

#include "main.h"

/* ========================================================================== */
/*                             SPI1 NSS 引脚配置与控制                         */
/* ========================================================================== */

#define CLRC663_NSS_PORT            GPIOA
#define CLRC663_NSS_PIN             SPI1_CS_Pin

#define CLRC663_NSS_LOW()           HAL_GPIO_WritePin(CLRC663_NSS_PORT, CLRC663_NSS_PIN, GPIO_PIN_RESET)
#define CLRC663_NSS_HIGH()          HAL_GPIO_WritePin(CLRC663_NSS_PORT, CLRC663_NSS_PIN, GPIO_PIN_SET)

/* ========================================================================== */
/*                             CLRC663 底层读写函数接口                         */
/* ========================================================================== */

/**
 * @brief       向 CLRC663 写入单字节数据
 * @param       reg 寄存器物理地址
 * @param       val 写入的数值
 */
void CLRC663_WriteReg(uint8_t reg, uint8_t val);

/**
 * @brief       从 CLRC663 读取单字节数据
 * @param       reg 寄存器物理地址
 * @return      读取到的数值
 */
uint8_t CLRC663_ReadReg(uint8_t reg);

/**
 * @brief       向 CLRC663 连续写入多个字节（寄存器地址自增）
 * @param       reg 起始寄存器物理地址
 * @param       data 待写入数据缓冲区指针
 * @param       len 写入的字节数
 */
void CLRC663_WriteRegs(uint8_t reg, uint8_t *data, uint16_t len);

/**
 * @brief       从 CLRC663 连续读取多个字节（寄存器地址自增）
 * @param       reg 起始寄存器物理地址
 * @param       data 存放数据的缓冲区指针
 * @param       len 待读取的字节数
 */
void CLRC663_ReadRegs(uint8_t reg, uint8_t *data, uint16_t len);

/**
 * @brief       向 CLRC663 FIFO 缓冲区连续写入多字节数据（FIFO 寄存器地址不自增）
 * @param       data 待写入 FIFO 数据的缓冲区指针
 * @param       len 数据字节数
 */
void CLRC663_WriteFifo(uint8_t *data, uint16_t len);

/**
 * @brief       从 CLRC663 FIFO 缓冲区连续读取多字节数据（FIFO 寄存器地址不自增）
 * @param       data 接收 FIFO 数据的缓冲区指针
 * @param       len 数据字节数
 */
void CLRC663_ReadFifo(uint8_t *data, uint16_t len);

#endif /* CLRC663_SPI_H */
