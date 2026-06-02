/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    main.h
 * @brief   主程序头文件，包含核心宏定义与全局声明
 * @author  Antigravity
 * @version 1.0
 * @date    2026-06-02
 *
 * @copyright Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * 本软件根据可以在本软件组件根目录的 LICENSE 文件中找到的条款进行许可。
 * 如果没有 LICENSE 文件，则按“原样”提供本软件。
 ******************************************************************************
*/
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

    /* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

    /* Private includes ----------------------------------------------------------*/
    /* USER CODE BEGIN Includes */
#include <stdio.h>
#include "SEGGER_RTT.h"
#define printf(...) SEGGER_RTT_printf(0, __VA_ARGS__)
    /* USER CODE END Includes */

    /* Exported types ------------------------------------------------------------*/
    /* USER CODE BEGIN ET */

    /* USER CODE END ET */

    /* Exported constants --------------------------------------------------------*/
    /* USER CODE BEGIN EC */

    /* USER CODE END EC */

    /* Exported macro ------------------------------------------------------------*/
    /* USER CODE BEGIN EM */

    /* USER CODE END EM */

    /* Exported functions prototypes ---------------------------------------------*/
    void Error_Handler(void);

    /* USER CODE BEGIN EFP */

    /* USER CODE END EFP */

    /* Private defines -----------------------------------------------------------*/
#define CLRC663_IRQ_Pin GPIO_PIN_3
#define CLRC663_IRQ_GPIO_Port GPIOA
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define CLRC663_PDOWN_Pin GPIO_PIN_4
#define CLRC663_PDOWN_GPIO_Port GPIOC
#define USB_DISCONNECT_Pin GPIO_PIN_13
#define USB_DISCONNECT_GPIO_Port GPIOE
#define BUZZER_Pin GPIO_PIN_14
#define BUZZER_GPIO_Port GPIOE
#define LED_Pin GPIO_PIN_15
#define LED_GPIO_Port GPIOE
#define SC_OFF_Pin GPIO_PIN_9
#define SC_OFF_GPIO_Port GPIOD
#define SC_RESET_Pin GPIO_PIN_10
#define SC_RESET_GPIO_Port GPIOD
#define SC_18V_Pin GPIO_PIN_11
#define SC_18V_GPIO_Port GPIOD
#define SC_3_5V_Pin GPIO_PIN_12
#define SC_3_5V_GPIO_Port GPIOD
#define SC_CLKDIV_2_Pin GPIO_PIN_13
#define SC_CLKDIV_2_GPIO_Port GPIOD
#define SC_CLKDIV_1_Pin GPIO_PIN_14
#define SC_CLKDIV_1_GPIO_Port GPIOD
#define SC_CMDVCC_Pin GPIO_PIN_10
#define SC_CMDVCC_GPIO_Port GPIOA
#define SPI2_CS_Pin GPIO_PIN_15
#define SPI2_CS_GPIO_Port GPIOA

    /* USER CODE BEGIN Private defines */

    /* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
