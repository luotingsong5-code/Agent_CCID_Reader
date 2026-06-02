/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    usb_device.h
 * @brief   USB 设备初始化声明头文件
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
#ifndef __USB_DEVICE__H__
#define __USB_DEVICE__H__

#ifdef __cplusplus
extern "C" {
#endif

    /* Includes ------------------------------------------------------------------*/
#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"
#include "usbd_def.h"

    /* USER CODE BEGIN INCLUDE */

    /* USER CODE END INCLUDE */

    /** @addtogroup USBD_OTG_DRIVER
     * @{
    */

    /** @defgroup USBD_DEVICE USBD_DEVICE
     * @brief Device file for Usb otg low level driver.
     * @{
    */

    /** @defgroup USBD_DEVICE_Exported_Variables USBD_DEVICE_Exported_Variables
     * @brief Public variables.
     * @{
    */

    /* Private variables ---------------------------------------------------------*/
    /* USER CODE BEGIN PV */

    /* USER CODE END PV */

    /* Private function prototypes -----------------------------------------------*/
    /* USER CODE BEGIN PFP */

    /* USER CODE END PFP */

    /*
     * -- Insert your variables declaration here --
    */
    /* USER CODE BEGIN VARIABLES */

    /* USER CODE END VARIABLES */
    /**
     * @}
    */

    /** @defgroup USBD_DEVICE_Exported_FunctionsPrototype USBD_DEVICE_Exported_FunctionsPrototype
     * @brief Declaration of public functions for Usb device.
     * @{
    */

    /** USB Device initialization function. */
    void MX_USB_DEVICE_Init(void);

    /*
     * -- Insert functions declaration here --
    */
    /* USER CODE BEGIN FD */

    /* USER CODE END FD */
    /**
     * @}
    */

    /**
     * @}
    */

    /**
     * @}
    */

#ifdef __cplusplus
}
#endif

#endif /* __USB_DEVICE__H__ */
