

# BSP 说明



USB_DISCONNECT 引脚，输出高电平开启USB连接，输出低电平关闭USB连接
#define USB_DISCONNECT_PORT GPIOE
#define USB_DISCONNECT_PIN  GPIO_Pin_13
GPIO_SetBits(USB_DISCONNECT_PORT, USB_DISCONNECT_PIN);
GPIOPinxConfig(USB_DISCONNECT_PORT, USB_DISCONNECT_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_OD);


LED控制引脚,输出高电平表示亮灯，输出低电平表示灭灯
#define LED_PORT         	GPIOE
#define LED_PIN_1        	GPIO_Pin_15
GPIO_ResetBits(LED_PORT, LED_PIN_1);
GPIOPinxConfig(LED_PORT, LED_PIN_1, GPIO_Speed_50MHz, GPIO_Mode_Out_PP);

蜂鸣器引脚，输出高电平蜂鸣器响，输出电平蜂鸣器不响
#define BUZ_PORT			GPIOE
#define BUZ_PIN				GPIO_Pin_14
GPIO_ResetBits(BUZ_PORT, BUZ_PIN);
GPIOPinxConfig(BUZ_PORT, BUZ_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_PP);

CLRC663 IRQ = PA3
#define CLRC663_IRQ_PORT		GPIOA
#define CLRC663_IRQ_PIN 		GPIO_Pin_3

CLRC663 PODWN/RESET  = PC4
#define CLRC663_PODWN_PORT		GPIOC
#define CLRC663_PDOWN_PIN 		GPIO_Pin_4


CLRC663 SPI IF3(NSS) = PA4
#define SPI1_NSS_PORT  		GPIOA           //IF3 NSS
#define SPI1_NSS_PIN   		GPIO_Pin_4	    //PA4

CLRC663 SPI_IF1(SCK) = PA5
#define SPI1_SCK_PORT  		GPIOA
#define SPI1_SCK_PIN   		GPIO_Pin_5      //PA5

CLRC663 SPI_IF2(MISO) = PA6
#define SPI1_MISO_PORT  	GPIOA
#define SPI1_MISO_PIN   	GPIO_Pin_6      //PA6

CLRC663 SPI_IF0(MOSI) = PA7
#define SPI1_MOSI_PORT  	GPIOA
#define SPI1_MOSI_PIN   	GPIO_Pin_7      //PA7

# 硬件连接细节说明
~ STM32F103VB (Cortex-M3)通过SPI和CLRC663连接，CLRC663的IFSEL0/IFSEL1在系统上接固定电平，明确选择SPI
~ USB总线供电，可以提供500mA驱动能力，外置天线已经完成天线匹配

# CCID实现
~ 参考开源的 CCID vsmartcard 进行移植

# 中间层
~ 如何从pyscard发出的 ISO7816 APDU指令，转换成NTAG213原生指令，参考开源代码实现

# 知识储备
~ 我不熟悉USB协议，都需要AI来实现
~ 没有CLRC663驱动代码，可以参看开源代码

# 建立Debug Printf log机制
为整个工程，通过SWO建立log机制，能够在IDE（Vscode或者Keil），通过printf输出调试信息