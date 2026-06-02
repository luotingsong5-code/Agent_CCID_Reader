/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f1xx_it.h
 * @brief   中断服务函数声明头文件
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
#ifndef __STM32F1xx_IT_H
#define __STM32F1xx_IT_H

#ifdef __cplusplus
extern "C" {
#endif

    /* Private includes ----------------------------------------------------------*/
    /* USER CODE BEGIN Includes */

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
    void NMI_Handler(void);
    void HardFault_Handler(void);
    void MemManage_Handler(void);
    void BusFault_Handler(void);
    void UsageFault_Handler(void);
    void SVC_Handler(void);
    void DebugMon_Handler(void);
    void PendSV_Handler(void);
    void SysTick_Handler(void);
    void USB_LP_CAN1_RX0_IRQHandler(void);
    void TIM1_CC_IRQHandler(void);
    void TIM2_IRQHandler(void);
    void TIM3_IRQHandler(void);
    void TIM4_IRQHandler(void);
    void SPI1_IRQHandler(void);
    /* USER CODE BEGIN EFP */

    /* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_IT_H */
