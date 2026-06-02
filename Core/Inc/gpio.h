/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    gpio.h
 * @brief   GPIO 外设配置及引脚宏定义头文件
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

    /* Includes ------------------------------------------------------------------*/
#include "main.h"

    /* USER CODE BEGIN Includes */

    /* USER CODE END Includes */

    /* USER CODE BEGIN Private defines */

    /* USER CODE END Private defines */

    void MX_GPIO_Init(void);

    /* USER CODE BEGIN Prototypes */

    /* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

