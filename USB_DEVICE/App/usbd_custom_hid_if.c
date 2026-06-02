/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    usbd_custom_hid_if.c
 * @brief   USB 自定义 HID 接口层回调函数源文件
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
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
 * @brief Usb device.
 * @{
*/

/** @addtogroup USBD_CUSTOM_HID
 * @{
*/

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions USBD_CUSTOM_HID_Private_TypesDefinitions
 * @brief Private types.
 * @{
*/

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
 * @}
*/

/** @defgroup USBD_CUSTOM_HID_Private_Defines USBD_CUSTOM_HID_Private_Defines
 * @brief Private defines.
 * @{
*/

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
 * @}
*/

/** @defgroup USBD_CUSTOM_HID_Private_Macros USBD_CUSTOM_HID_Private_Macros
 * @brief Private macros.
 * @{
*/

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
 * @}
*/

/** @defgroup USBD_CUSTOM_HID_Private_Variables USBD_CUSTOM_HID_Private_Variables
 * @brief Private variables.
 * @{
*/

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
    /* USER CODE BEGIN 0 */
    0x00,
    /* USER CODE END 0 */
    0xC0    /*     END_COLLECTION	             */
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
 * @}
*/

/** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
 * @brief Public variables.
 * @{
*/
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
 * @}
*/

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
 * @brief Private functions declaration.
 * @{
*/

static int8_t CUSTOM_HID_Init_FS(void);
static int8_t CUSTOM_HID_DeInit_FS(void);
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state);

/**
 * @}
*/

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS =
{
    CUSTOM_HID_ReportDesc_FS,
    CUSTOM_HID_Init_FS,
    CUSTOM_HID_DeInit_FS,
    CUSTOM_HID_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
 * @brief Private functions.
 * @{
*/

/* Private functions ---------------------------------------------------------*/

/**
 * @brief   初始化自定义 HID 全速设备
 * @retval  static int8_t 返回值
*/
static int8_t CUSTOM_HID_Init_FS(void)
{
    /* USER CODE BEGIN 4 */
    return (USBD_OK);
    /* USER CODE END 4 */
}

/**
 * @brief   反初始化自定义 HID 全速设备
 * @retval  static int8_t 返回值
*/
static int8_t CUSTOM_HID_DeInit_FS(void)
{
    /* USER CODE BEGIN 5 */
    return (USBD_OK);
    /* USER CODE END 5 */
}

/**
 * @brief   处理自定义 HID 全速设备的 OUT 传输事件
 * @param   event_idx event_idx 参数
 * @param   state 状态
 * @retval  static int8_t 返回值
*/
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state)
{
    /* USER CODE BEGIN 6 */
    return (USBD_OK);
    /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
 * @brief  Send the report to the Host
 * @param  report: The report to be sent
 * @param  len: The report length
 * @retval USBD_OK if all operations are OK else USBD_FAIL
*/
/*
static int8_t USBD_CUSTOM_HID_SendReport_FS(uint8_t *report, uint16_t len)
{
return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
}
*/
/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
 * @}
*/

/**
 * @}
*/

/**
 * @}
*/

