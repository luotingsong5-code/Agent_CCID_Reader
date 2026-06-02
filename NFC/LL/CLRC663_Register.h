/**
 * @file        CLRC663_Register.h
 * @brief       CLRC663 芯片寄存器及命令宏定义头文件
 * @details     根据 CLRC663 官方数据手册，定义了所有寄存器物理地址、
 *              芯片硬件命令集以及关键控制/状态寄存器的位掩码。
 * @author      Antigravity (Pair Programming with USER)
 * @date        2026-06-02
 * @version     V1.0
 * @copyright   Copyright (c) 2026
 */

#ifndef CLRC663_REGISTER_H
#define CLRC663_REGISTER_H

/* ========================================================================== */
/*                          1. CLRC663 寄存器物理地址定义                       */
/* ========================================================================== */

#define CLRC663_REG_COMMAND                 0x00    /**< 启动和停止命令执行 */
#define CLRC663_REG_HOSTCTRL                0x01    /**< 主机控制寄存器 */
#define CLRC663_REG_FIFOCONTROL             0x02    /**< FIFO 缓冲区控制寄存器 */
#define CLRC663_REG_WATERLEVEL              0x03    /**< FIFO 上溢与下溢警告阈值 */
#define CLRC663_REG_FIFOLENGTH              0x04    /**< FIFO 缓冲区当前数据长度 */
#define CLRC663_REG_FIFODATA                0x05    /**< FIFO 缓冲区数据输入/输出交换端口 */
#define CLRC663_REG_IRQ0                    0x06    /**< 中断请求寄存器 0 */
#define CLRC663_REG_IRQ1                    0x07    /**< 中断请求寄存器 1 */
#define CLRC663_REG_IRQ0EN                  0x08    /**< 中断使能寄存器 0 */
#define CLRC663_REG_IRQ1EN                  0x09    /**< 中断使能寄存器 1 */
#define CLRC663_REG_ERROR                   0x0A    /**< 错误状态寄存器（显示最后一次命令执行错误） */
#define CLRC663_REG_STATUS                  0x0B    /**< 传输与通信状态寄存器 */
#define CLRC663_REG_RXBITCTRL               0x0C    /**< 接收位控制寄存器（用于防冲突位调整） */
#define CLRC663_REG_RXCOLL                  0x0D    /**< 冲突位置寄存器 */
#define CLRC663_REG_TCONTROL                0x0E    /**< 定时器 0..3 全局控制寄存器 */
#define CLRC663_REG_T0CONTROL               0x0F    /**< 定时器 0 控制寄存器 */
#define CLRC663_REG_T0RELOADHI              0x10    /**< 定时器 0 重装载值高字节 */
#define CLRC663_REG_T0RELOADLO              0x11    /**< 定时器 0 重装载值低字节 */
#define CLRC663_REG_T0COUNTERVALHI          0x12    /**< 定时器 0 计数器当前值高字节 */
#define CLRC663_REG_T0COUNTERVALLO          0x13    /**< 定时器 0 计数器当前值低字节 */
#define CLRC663_REG_T1CONTROL               0x14    /**< 定时器 1 控制寄存器 */
#define CLRC663_REG_T1RELOADHI              0x15    /**< 定时器 1 重装载值高字节 */
#define CLRC663_REG_T1RELOADLO              0x16    /**< 定时器 1 重装载值低字节 */
#define CLRC663_REG_T1COUNTERVALHI          0x17    /**< 定时器 1 计数器当前值高字节 */
#define CLRC663_REG_T1COUNTERVALLO          0x18    /**< 定时器 1 计数器当前值低字节 */
#define CLRC663_REG_T2CONTROL               0x19    /**< 定时器 2 控制寄存器 */
#define CLRC663_REG_T2RELOADHI              0x1A    /**< 定时器 2 重装载值高字节 */
#define CLRC663_REG_T2RELOADLO              0x1B    /**< 定时器 2 重装载值低字节 */
#define CLRC663_REG_T2COUNTERVALHI          0x1C    /**< 定时器 2 计数器当前值高字节 */
#define CLRC663_REG_T2COUNTERVALLO          0x1D    /**< 定时器 2 计数器当前值低字节 */
#define CLRC663_REG_T3CONTROL               0x1E    /**< 定时器 3 控制寄存器 */
#define CLRC663_REG_T3RELOADHI              0x1F    /**< 定时器 3 重装载值高字节 */
#define CLRC663_REG_T3RELOADLO              0x20    /**< 定时器 3 重装载值低字节 */
#define CLRC663_REG_T3COUNTERVALHI          0x21    /**< 定时器 3 计数器当前值高字节 */
#define CLRC663_REG_T3COUNTERVALLO          0x22    /**< 定时器 3 计数器当前值低字节 */
#define CLRC663_REG_T4CONTROL               0x23    /**< 定时器 4 控制寄存器 */
#define CLRC663_REG_T4RELOADHI              0x24    /**< 定时器 4 重装载值高字节 */
#define CLRC663_REG_T4RELOADLO              0x25    /**< 定时器 4 重装载值低字节 */
#define CLRC663_REG_T4COUNTERVALHI          0x26    /**< 定时器 4 计数器当前值高字节 */
#define CLRC663_REG_T4COUNTERVALLO          0x27    /**< 定时器 4 计数器当前值低字节 */
#define CLRC663_REG_DRVMOD                  0x28    /**< 驱动器输出模式寄存器 */
#define CLRC663_REG_TXAMP                   0x29    /**< 发送器放大器调节寄存器 */
#define CLRC663_REG_DRVCON                  0x2A    /**< 驱动器配置寄存器 */
#define CLRC663_REG_TXI                     0x2B    /**< 发送器配置寄存器 */
#define CLRC663_REG_TXCRCPRESET             0x2C    /**< 发送器 CRC 计算器控制与初始值预设寄存器 */
#define CLRC663_REG_RXCRCPRESET             0x2D    /**< 接收器 CRC 计算器控制与初始值预设寄存器 */
#define CLRC663_REG_TXDATANUM               0x2E    /**< 发送数据位数及控制寄存器 */
#define CLRC663_REG_TXMODWIDTH              0x2F    /**< 发送器调制宽度设置寄存器 */
#define CLRC663_REG_TXSYM10BURSTLEN         0x30    /**< 发送器符号 1+0 突发长度 */
#define CLRC663_REG_TXWAITCTRL              0x31    /**< 发送等待控制寄存器 */
#define CLRC663_REG_TXWAITLO                0x32    /**< 发送等待低字节设置寄存器 */
#define CLRC663_REG_FRAMECON                0x33    /**< 发送帧控制寄存器 */
#define CLRC663_REG_RXSOFD                  0x34    /**< 接收帧起始检测寄存器 */
#define CLRC663_REG_RXCTRL                  0x35    /**< 接收器控制寄存器 */
#define CLRC663_REG_RXWAIT                  0x36    /**< 接收等待周期设置寄存器 */
#define CLRC663_REG_RXTHRESHOLD             0x37    /**< 接收器解调阈值设置寄存器 */
#define CLRC663_REG_RCV                     0x38    /**< 接收控制与增益调节寄存器 */
#define CLRC663_REG_RXANA                   0x39    /**< 接收模拟配置寄存器 */
#define CLRC663_REG_LPCD_OPTIONS            0x3A    /**< LPCD 低功耗检测卡片配置选项（CLRC66303） */
#define CLRC663_REG_SERIALSPEED             0x3B    /**< 串行主机接口速率设置 */
#define CLRC663_REG_LFO_TRIMM               0x3C    /**< 低功耗振荡器 (LFO) 微调寄存器 */
#define CLRC663_REG_PLL_CTRL                0x3D    /**< 内置 PLL 锁相环控制寄存器 */
#define CLRC663_REG_PLL_DIVOUT              0x3E    /**< PLL 输出分频控制寄存器 */
#define CLRC663_REG_LPCD_QMIN               0x3F    /**< LPCD Q通道判定下限阈值 */
#define CLRC663_REG_LPCD_QMAX               0x40    /**< LPCD Q通道判定上限阈值 */
#define CLRC663_REG_LPCD_IMIN               0x41    /**< LPCD I通道判定下限阈值 */
#define CLRC663_REG_LPCD_I_RESULT           0x42    /**< LPCD I通道测量结果 */
#define CLRC663_REG_LPCD_Q_RESULT           0x43    /**< LPCD Q通道测量结果 */
#define CLRC663_REG_PADEN                   0x44    /**< GPIO 引脚输出使能寄存器 */
#define CLRC663_REG_PADOUT                  0x45    /**< GPIO 引脚输出电平寄存器 */
#define CLRC663_REG_PADIN                   0x46    /**< GPIO 引脚输入状态寄存器 */
#define CLRC663_REG_SIGOUT                  0x47    /**< SIGOUT 引脚使能与配置寄存器 */
#define CLRC663_REG_TXBITMOD                0x48    /**< 发送器位模式控制寄存器 */
#define CLRC663_REG_TXDATACON               0x4A    /**< 发送器数据格式配置寄存器 */
#define CLRC663_REG_TXDATAMOD               0x4B    /**< 发送器数据调制控制寄存器 */
#define CLRC663_REG_TXSYMFREQ               0x4C    /**< 发送器符号频率设置寄存器 */
#define CLRC663_REG_TXSYM0H                 0x4D    /**< 发送器符号 0 模式高位 */
#define CLRC663_REG_TXSYM0L                 0x4E    /**< 发送器符号 0 模式低位 */
#define CLRC663_REG_TXSYM1H                 0x4F    /**< 发送器符号 1 模式高位 */
#define CLRC663_REG_TXSYM1L                 0x50    /**< 发送器符号 1 模式低位 */
#define CLRC663_REG_TXSYM2                  0x51    /**< 发送器符号 2 配置寄存器 */
#define CLRC663_REG_TXSYM3                  0x52    /**< 发送器符号 3 配置寄存器 */
#define CLRC663_REG_TXSYM10LEN              0x53    /**< 发送器符号 1+0 符号长度 */
#define CLRC663_REG_TXSYM32LEN              0x54    /**< 发送器符号 3+2 符号长度 */
#define CLRC663_REG_TXSYM10BURSTCTRL        0x55    /**< 发送器符号 1+0 突发控制 */
#define CLRC663_REG_TXSYM10MOD              0x56    /**< 发送器符号 1+0 调制控制 */
#define CLRC663_REG_TXSYM32MOD              0x57    /**< 发送器符号 3+2 调制控制 */
#define CLRC663_REG_RXBITMOD                0x58    /**< 接收器位解调配置寄存器 */
#define CLRC663_REG_RXEOFSYM                0x59    /**< 接收器帧结束 (EOF) 符号定义 */
#define CLRC663_REG_RXSYNCVALH              0x5A    /**< 接收器同步字高字节 */
#define CLRC663_REG_RXSYNCVALL              0x5B    /**< 接收器同步字低字节 */
#define CLRC663_REG_RXSYNCMOD               0x5C    /**< 接收器同步模式控制 */
#define CLRC663_REG_RXMOD                   0x5D    /**< 接收器副载波调制模式寄存器 */
#define CLRC663_REG_RXCORR                  0x5E    /**< 接收器副载波相关器配置 */
#define CLRC663_REG_FABCAL                  0x5F    /**< 接收校准寄存器（出厂固化） */
#define CLRC663_REG_VERSION                 0x7F    /**< 版本信息寄存器 */

/* ========================================================================== */
/*                          2. CLRC663 硬件命令集定义                          */
/* ========================================================================== */

#define CLRC663_CMD_IDLE                    0x00    /**< 无动作，取消当前正在执行的命令 */
#define CLRC663_CMD_LPCD                    0x01    /**< 低功耗卡检测，并自动校准 LFO */
#define CLRC663_CMD_LOADKEY                 0x02    /**< 从 FIFO 加载 6 字节密钥至密钥缓冲区 */
#define CLRC663_CMD_MFAUTHENT               0x03    /**< 执行 MIFARE Classic 三重相互认证 */
#define CLRC663_CMD_ACKREQ                  0x04    /**< 执行 ISO18000-3/EPC-HF 下的 Query/Ack/Req-Rn */
#define CLRC663_CMD_RECEIVE                 0x05    /**< 启动接收电路，等待卡片返回数据 */
#define CLRC663_CMD_TRANSMIT                0x06    /**< 发送 FIFO 中的数据到天线 */
#define CLRC663_CMD_TRANSCEIVE              0x07    /**< 发送 FIFO 数据，并在发送完后自动转为接收状态 */
#define CLRC663_CMD_WRITEE2                 0x08    /**< 写 1 字节数据到内部 EEPROM */
#define CLRC663_CMD_WRITEE2PAGE             0x09    /**< 写最多 1 页（64字节）数据到 EEPROM */
#define CLRC663_CMD_READE2                  0x0A    /**< 从内部 EEPROM 读取指定长度数据到 FIFO */
#define CLRC663_CMD_LOADREG                 0x0C    /**< 从 EEPROM 读取指定区间的数据初始化寄存器 */
#define CLRC663_CMD_LOADPROTOCOL            0x0D    /**< 从 EEPROM 协议配置区读取数据以改变射频协议设置 */
#define CLRC663_CMD_LOADKEYE2               0x0E    /**< 从 EEPROM 扇区拷贝密钥至芯片硬件密钥缓冲区 */
#define CLRC663_CMD_STOREKEYE2              0x0F    /**< 将密钥存储至内部 EEPROM 的密钥区 */
#define CLRC663_CMD_READRNR                 0x1C    /**< 从芯片随机数发生器提取伪随机数填充 FIFO */
#define CLRC663_CMD_SOFTRESET               0x1F    /**< 软件复位，恢复 EEPROM 配置的寄存器默认值 */

/* ========================================================================== */
/*                          3. 关键寄存器的 Bit 掩码及属性定义                 */
/* ========================================================================== */

/* --- FIFOControl 寄存器 (0x02) 属性定义 --- */
#define CLRC663_FIFO_SIZE_255               (1 << 7)    /**< 1: FIFO 容量限制为 255 字节 */
#define CLRC663_FIFO_SIZE_512               (0 << 7)    /**< 0: FIFO 容量可达 512 字节 */
#define CLRC663_FIFO_HI_ALERT               (1 << 6)    /**< FIFO 剩余空间等于或小于 WaterLevel 时置位 */
#define CLRC663_FIFO_LO_ALERT               (1 << 5)    /**< FIFO 已存数据等于或小于 WaterLevel 时置位 */
#define CLRC663_FIFO_FLUSH                  (1 << 4)    /**< 写入 1 立即清空 FIFO 缓冲区 */
#define CLRC663_FIFO_WATERLEVEL_MSB         (1 << 2)    /**< 512字节模式下的 WaterLevel 计数高位 (Bit 8) */

/* --- IRQ0 / IRQ0En 寄存器 (0x06 / 0x08) 中断控制位 --- */
#define CLRC663_IRQ0_SET                    (1 << 7)    /**< 1: 写入 6..0 位将置位中断标志; 0: 清零中断标志 */
#define CLRC663_IRQ0_HIALERT                (1 << 6)    /**< 高警戒标志中断（FIFO 接近满） */
#define CLRC663_IRQ0_LOALERT                (1 << 5)    /**< 低警戒标志中断（FIFO 接近空） */
#define CLRC663_IRQ0_IDLE                   (1 << 4)    /**< 命令自动终止或异常终止中断 */
#define CLRC663_IRQ0_TX                     (1 << 3)    /**< 发送器发送完成（最后一个 Bit 送出）中断 */
#define CLRC663_IRQ0_RX                     (1 << 2)    /**< 接收器收到完整数据流（不保证校验正确）中断 */
#define CLRC663_IRQ0_ERR                    (1 << 1)    /**< 错误中断（Error 寄存器任意错误位置 1） */
#define CLRC663_IRQ0_RXSOF                  (1 << 0)    /**< 接收器检测到帧起始信号 (SOF) 中断 */

/* --- IRQ1 / IRQ1En 寄存器 (0x07 / 0x09) 中断控制位 --- */
#define CLRC663_IRQ1_SET                    (1 << 7)    /**< 1: 写入 5..0 位置位对应中断; 0: 清零对应中断 */
#define CLRC663_IRQ1_GLOBAL                 (1 << 6)    /**< 全局中断触发指示位 */
#define CLRC663_IRQ1_LPCD                   (1 << 5)    /**< LPCD 低功耗寻卡检测到卡片中断 */
#define CLRC663_IRQ1_TIMER4                 (1 << 4)    /**< 定时器 4 溢出（减到 0）中断 */
#define CLRC663_IRQ1_TIMER3                 (1 << 3)    /**< 定时器 3 溢出（减到 0）中断 */
#define CLRC663_IRQ1_TIMER2                 (1 << 2)    /**< 定时器 2 溢出（减到 0）中断 */
#define CLRC663_IRQ1_TIMER1                 (1 << 1)    /**< 定时器 1 溢出（减到 0）中断 */
#define CLRC663_IRQ1_TIMER0                 (1 << 0)    /**< 定时器 0 溢出（减到 0）中断 */

/* --- Error 寄存器 (0x0A) 错误标志定义 --- */
#define CLRC663_ERR_EE                      (1 << 7)    /**< 上一次 EEPROM 操作出错 */
#define CLRC663_ERR_FIFOWR                  (1 << 6)    /**< 在不可写入时向 FIFO 写入产生写错误 */
#define CLRC663_ERR_FIFOOVL                 (1 << 5)    /**< FIFO 发生溢出 */
#define CLRC663_ERR_MINFRAME                (1 << 4)    /**< 收到有效 SOF 但数据少于 4 bit */
#define CLRC663_ERR_NODATA                  (1 << 3)    /**< FIFO 中无数据但触发了发送操作 */
#define CLRC663_ERR_COLLDET                 (1 << 2)    /**< 防冲突过程中检测到碰撞位 */
#define CLRC663_ERR_PROT                    (1 << 1)    /**< 协议错误（如 wrong EOF, wrong SOF, wrong stop bit） */
#define CLRC663_ERR_INTEG                   (1 << 0)    /**< 数据完整性校验错误（奇偶校验错或 CRC 校验错） */

/* --- Status 寄存器 (0x0B) 状态信息定义 --- */
#define CLRC663_STATUS_CRYPTO1ON            (1 << 5)    /**< MIFARE Classic 加密控制流开启状态 */
#define CLRC663_STATUS_COMSTATE_MASK        0x07        /**< 收发状态机状态掩码 */
#define CLRC663_STATUS_COM_IDLE             0x00        /**< 状态机状态：空闲 (Idle) */
#define CLRC663_STATUS_COM_TXWAIT           0x01        /**< 状态机状态：发送等待 (TxWait) */
#define CLRC663_STATUS_COM_TRANSMITTING     0x03        /**< 状态机状态：正在发送 (Transmitting) */
#define CLRC663_STATUS_COM_RXWAIT           0x05        /**< 状态机状态：接收等待 (RxWait) */
#define CLRC663_STATUS_COM_WAIT_FOR_DATA    0x06        /**< 状态机状态：等待数据 (Wait for data) */
#define CLRC663_STATUS_COM_RECEIVING        0x07        /**< 状态机状态：正在接收 (Receiving) */

#endif /* CLRC663_REGISTER_H */
