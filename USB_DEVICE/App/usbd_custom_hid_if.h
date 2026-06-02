/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    usbd_custom_hid_if.h
 * @brief   USB 自定义 HID 接口声明头文件
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
#ifndef __USBD_CUSTOM_HID_IF_H__
#define __USBD_CUSTOM_HID_IF_H__

#ifdef __cplusplus
extern "C" {
#endif

    /* Includes ------------------------------------------------------------------*/
#include "usbd_customhid.h"

    /* USER CODE BEGIN INCLUDE */

    /* USER CODE END INCLUDE */

    /** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
     * @brief For Usb device.
     * @{
    */

    /** @defgroup USBD_CUSTOM_HID USBD_CUSTOM_HID
     * @brief Usb custom human interface device module.
     * @{
    */

    /** @defgroup USBD_CUSTOM_HID_Exported_Defines USBD_CUSTOM_HID_Exported_Defines
     * @brief Defines.
     * @{
    */

    /* USER CODE BEGIN EXPORTED_DEFINES */

    /* USER CODE END EXPORTED_DEFINES */

    /**
     * @}
    */

    /** @defgroup USBD_CUSTOM_HID_Exported_Types USBD_CUSTOM_HID_Exported_Types
     * @brief Types.
     * @{
    */

    /* USER CODE BEGIN EXPORTED_TYPES */

    /* USER CODE END EXPORTED_TYPES */

    /**
     * @}
    */

    /** @defgroup USBD_CUSTOM_HID_Exported_Macros USBD_CUSTOM_HID_Exported_Macros
     * @brief Aliases.
     * @{
    */

    /* USER CODE BEGIN EXPORTED_MACRO */

    /* USER CODE END EXPORTED_MACRO */

    /**
     * @}
    */

    /** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
     * @brief Public variables.
     * @{
    */

    /** CUSTOMHID Interface callback. */
    extern USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS;

    /* USER CODE BEGIN EXPORTED_VARIABLES */

    /* USER CODE END EXPORTED_VARIABLES */

    /**
     * @}
    */

    /** @defgroup USBD_CUSTOM_HID_Exported_FunctionsPrototype USBD_CUSTOM_HID_Exported_FunctionsPrototype
     * @brief Public functions declaration.
     * @{
    */

    /* USER CODE BEGIN EXPORTED_FUNCTIONS */

    /* USER CODE END EXPORTED_FUNCTIONS */

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

#endif /* __USBD_CUSTOM_HID_IF_H__ */

