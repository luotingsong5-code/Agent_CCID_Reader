/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    tim.h
 * @brief   定时器配置及初始化函数声明头文件
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
#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

    /* Includes ------------------------------------------------------------------*/
#include "main.h"

    /* USER CODE BEGIN Includes */

    /* USER CODE END Includes */

    extern TIM_HandleTypeDef htim1;

    extern TIM_HandleTypeDef htim3;

    extern TIM_HandleTypeDef htim4;

    /* USER CODE BEGIN Private defines */

    /* USER CODE END Private defines */

    void MX_TIM1_Init(void);
    void MX_TIM3_Init(void);
    void MX_TIM4_Init(void);

    /* USER CODE BEGIN Prototypes */

    /* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */

