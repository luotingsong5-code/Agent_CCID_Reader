/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    usbd_desc.c
 * @brief   USB 设备描述符配置源文件
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
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_conf.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
 * @{
*/

/** @addtogroup USBD_DESC
 * @{
*/

/** @defgroup USBD_DESC_Private_TypesDefinitions USBD_DESC_Private_TypesDefinitions
 * @brief Private types.
 * @{
*/

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
 * @}
*/

/** @defgroup USBD_DESC_Private_Defines USBD_DESC_Private_Defines
 * @brief Private defines.
 * @{
*/

#define USBD_VID     1155
#define USBD_LANGID_STRING     1033
#define USBD_MANUFACTURER_STRING     "STMicroelectronics"
#define USBD_PID_FS     22352
#define USBD_PRODUCT_STRING_FS     "STM32 Custom Human interface"
#define USBD_CONFIGURATION_STRING_FS     "Custom HID Config"
#define USBD_INTERFACE_STRING_FS     "Custom HID Interface"

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
 * @}
*/

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/** @defgroup USBD_DESC_Private_Macros USBD_DESC_Private_Macros
 * @brief Private macros.
 * @{
*/

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
 * @}
*/

/** @defgroup USBD_DESC_Private_FunctionPrototypes USBD_DESC_Private_FunctionPrototypes
 * @brief Private functions declaration.
 * @{
*/

static void Get_SerialNum(void);
static void IntToUnicode(uint32_t value, uint8_t * pbuf, uint8_t len);

/**
 * @}
*/

/** @defgroup USBD_DESC_Private_FunctionPrototypes USBD_DESC_Private_FunctionPrototypes
 * @brief Private functions declaration for FS.
 * @{
*/

uint8_t * USBD_FS_DeviceDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_LangIDStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_ManufacturerStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_ProductStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_SerialStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_ConfigStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_InterfaceStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);

/**
 * @}
*/

/** @defgroup USBD_DESC_Private_Variables USBD_DESC_Private_Variables
 * @brief Private variables.
 * @{
*/

USBD_DescriptorsTypeDef FS_Desc =
{
    USBD_FS_DeviceDescriptor
    , USBD_FS_LangIDStrDescriptor
    , USBD_FS_ManufacturerStrDescriptor
    , USBD_FS_ProductStrDescriptor
    , USBD_FS_SerialStrDescriptor
    , USBD_FS_ConfigStrDescriptor
    , USBD_FS_InterfaceStrDescriptor
};

#if defined ( __ICCARM__ ) /* IAR Compiler */
#pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */
/** USB standard device descriptor. */
__ALIGN_BEGIN uint8_t USBD_FS_DeviceDesc[USB_LEN_DEV_DESC] __ALIGN_END =
{
    0x12,                       /*bLength */
    USB_DESC_TYPE_DEVICE,       /*bDescriptorType*/
    0x00,                       /*bcdUSB */
    0x02,
    0x00,                       /*bDeviceClass*/
    0x00,                       /*bDeviceSubClass*/
    0x00,                       /*bDeviceProtocol*/
    USB_MAX_EP0_SIZE,           /*bMaxPacketSize*/
    LOBYTE(USBD_VID),           /*idVendor*/
    HIBYTE(USBD_VID),           /*idVendor*/
    LOBYTE(USBD_PID_FS),        /*idProduct*/
    HIBYTE(USBD_PID_FS),        /*idProduct*/
    0x00,                       /*bcdDevice rel. 2.00*/
    0x02,
    USBD_IDX_MFC_STR,           /*Index of manufacturer  string*/
    USBD_IDX_PRODUCT_STR,       /*Index of product string*/
    USBD_IDX_SERIAL_STR,        /*Index of serial number string*/
    USBD_MAX_NUM_CONFIGURATION  /*bNumConfigurations*/
};

/* USB_DeviceDescriptor */

/**
 * @}
*/

/** @defgroup USBD_DESC_Private_Variables USBD_DESC_Private_Variables
 * @brief Private variables.
 * @{
*/

#if defined ( __ICCARM__ ) /* IAR Compiler */
#pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */

/** USB lang identifier descriptor. */
__ALIGN_BEGIN uint8_t USBD_LangIDDesc[USB_LEN_LANGID_STR_DESC] __ALIGN_END =
{
    USB_LEN_LANGID_STR_DESC,
    USB_DESC_TYPE_STRING,
    LOBYTE(USBD_LANGID_STRING),
    HIBYTE(USBD_LANGID_STRING)
};

#if defined ( __ICCARM__ ) /* IAR Compiler */
#pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */
/* Internal string descriptor. */
__ALIGN_BEGIN uint8_t USBD_StrDesc[USBD_MAX_STR_DESC_SIZ] __ALIGN_END;

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
#pragma data_alignment=4
#endif
__ALIGN_BEGIN uint8_t USBD_StringSerial[USB_SIZ_STRING_SERIAL] __ALIGN_END = {
    USB_SIZ_STRING_SERIAL,
    USB_DESC_TYPE_STRING,
};

/**
 * @}
*/

/** @defgroup USBD_DESC_Private_Functions USBD_DESC_Private_Functions
 * @brief Private functions.
 * @{
*/

/**
 * @brief   获取全速设备描述符
 * @param   speed 传输速度
 * @param   length length 参数
 * @retval  uint8_t* 缓冲区指针
*/
uint8_t * USBD_FS_DeviceDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
    UNUSED(speed);
    *length = sizeof(USBD_FS_DeviceDesc);
    return USBD_FS_DeviceDesc;
}

/**
 * @brief   获取全速语言 ID 字符串描述符
 * @param   speed 传输速度
 * @param   length length 参数
 * @retval  uint8_t* 缓冲区指针
*/
uint8_t * USBD_FS_LangIDStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
    UNUSED(speed);
    *length = sizeof(USBD_LangIDDesc);
    return USBD_LangIDDesc;
}

/**
 * @brief   获取全速产品字符串描述符
 * @param   speed 传输速度
 * @param   length length 参数
 * @retval  uint8_t* 缓冲区指针
*/
uint8_t * USBD_FS_ProductStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
    if(speed == 0)
    {
        USBD_GetString((uint8_t *)USBD_PRODUCT_STRING_FS, USBD_StrDesc, length);
    }
    else
    {
        USBD_GetString((uint8_t *)USBD_PRODUCT_STRING_FS, USBD_StrDesc, length);
    }
    return USBD_StrDesc;
}

/**
 * @brief   获取全速制造商字符串描述符
 * @param   speed 传输速度
 * @param   length length 参数
 * @retval  uint8_t* 缓冲区指针
*/
uint8_t * USBD_FS_ManufacturerStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
    UNUSED(speed);
    USBD_GetString((uint8_t *)USBD_MANUFACTURER_STRING, USBD_StrDesc, length);
    return USBD_StrDesc;
}

/**
 * @brief   获取全速序列号字符串描述符
 * @param   speed 传输速度
 * @param   length length 参数
 * @retval  uint8_t* 缓冲区指针
*/
uint8_t * USBD_FS_SerialStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
    UNUSED(speed);
    *length = USB_SIZ_STRING_SERIAL;

    /* Update the serial number string descriptor with the data from the unique
     * ID */
    Get_SerialNum();
    /* USER CODE BEGIN USBD_FS_SerialStrDescriptor */

    /* USER CODE END USBD_FS_SerialStrDescriptor */
    return (uint8_t *) USBD_StringSerial;
}

/**
 * @brief   获取全速配置字符串描述符
 * @param   speed 传输速度
 * @param   length length 参数
 * @retval  uint8_t* 缓冲区指针
*/
uint8_t * USBD_FS_ConfigStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
    if(speed == USBD_SPEED_HIGH)
    {
        USBD_GetString((uint8_t *)USBD_CONFIGURATION_STRING_FS, USBD_StrDesc, length);
    }
    else
    {
        USBD_GetString((uint8_t *)USBD_CONFIGURATION_STRING_FS, USBD_StrDesc, length);
    }
    return USBD_StrDesc;
}

/**
 * @brief   获取全速接口字符串描述符
 * @param   speed 传输速度
 * @param   length length 参数
 * @retval  uint8_t* 缓冲区指针
*/
uint8_t * USBD_FS_InterfaceStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
    if(speed == 0)
    {
        USBD_GetString((uint8_t *)USBD_INTERFACE_STRING_FS, USBD_StrDesc, length);
    }
    else
    {
        USBD_GetString((uint8_t *)USBD_INTERFACE_STRING_FS, USBD_StrDesc, length);
    }
    return USBD_StrDesc;
}

/**
 * @brief   执行 Get_SerialNum 操作
 * @retval  static void 返回值
*/
static void Get_SerialNum(void)
{
    uint32_t deviceserial0;
    uint32_t deviceserial1;
    uint32_t deviceserial2;

    deviceserial0 = *(uint32_t *) DEVICE_ID1;
    deviceserial1 = *(uint32_t *) DEVICE_ID2;
    deviceserial2 = *(uint32_t *) DEVICE_ID3;

    deviceserial0 += deviceserial2;

    if (deviceserial0 != 0)
    {
        IntToUnicode(deviceserial0, &USBD_StringSerial[2], 8);
        IntToUnicode(deviceserial1, &USBD_StringSerial[18], 4);
    }
}

/**
 * @brief   执行 IntToUnicode 操作
 * @param   value value 参数
 * @param   pbuf 数据缓冲区指针
 * @param   len 数据长度
 * @retval  static void 返回值
*/
static void IntToUnicode(uint32_t value, uint8_t * pbuf, uint8_t len)
{
    uint8_t idx = 0;

    for (idx = 0; idx < len; idx++)
    {
        if (((value >> 28)) < 0xA)
        {
            pbuf[2 * idx] = (value >> 28) + '0';
        }
        else
        {
            pbuf[2 * idx] = (value >> 28) + 'A' - 10;
        }

        value = value << 4;

        pbuf[2 * idx + 1] = 0;
    }
}
/**
 * @}
*/

/**
 * @}
*/

/**
 * @}
*/

