/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    usb_device.c
 * @brief   USB 设备初始化及启动源文件
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

/* Includes ------------------------------------------------------------------*/

#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_customhid.h"
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USB Device Core handle declaration. */
USBD_HandleTypeDef hUsbDeviceFS;

/*
 * -- Insert your variables declaration here --
*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*
 * -- Insert your external function declaration here --
*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
 * @brief   USB DEVICE 初始化配置
 * @retval  无
*/
void MX_USB_DEVICE_Init(void)
{
    /* USER CODE BEGIN USB_DEVICE_Init_PreTreatment */

    /* USER CODE END USB_DEVICE_Init_PreTreatment */

    /* Init Device Library, add supported class and start the library. */
    if (USBD_Init(&hUsbDeviceFS, &FS_Desc, DEVICE_FS) != USBD_OK)
    {
        Error_Handler();
    }
    if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_CUSTOM_HID) != USBD_OK)
    {
        Error_Handler();
    }
    if (USBD_CUSTOM_HID_RegisterInterface(&hUsbDeviceFS, &USBD_CustomHID_fops_FS) != USBD_OK)
    {
        Error_Handler();
    }
    if (USBD_Start(&hUsbDeviceFS) != USBD_OK)
    {
        Error_Handler();
    }

    /* USER CODE BEGIN USB_DEVICE_Init_PostTreatment */

    /* USER CODE END USB_DEVICE_Init_PostTreatment */
}

/**
 * @}
*/

/**
 * @}
*/

