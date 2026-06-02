/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    gpio.c
 * @brief   GPIO 外设初始化及引脚配置源文件
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
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
 * @brief   GPIO 初始化配置
 * @retval  无
*/
void MX_GPIO_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOA, SPI1_CS_Pin|SC_CMDVCC_Pin|SPI2_CS_Pin, GPIO_PIN_SET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(CLRC663_PDOWN_GPIO_Port, CLRC663_PDOWN_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(USB_DISCONNECT_GPIO_Port, USB_DISCONNECT_Pin, GPIO_PIN_SET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOE, BUZZER_Pin|LED_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOD, SC_RESET_Pin|SC_18V_Pin|SC_3_5V_Pin|SC_CLKDIV_2_Pin
    |SC_CLKDIV_1_Pin|GPIO_PIN_5, GPIO_PIN_RESET);

    /*Configure GPIO pin : CLRC663_IRQ_Pin */
    GPIO_InitStruct.Pin = CLRC663_IRQ_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(CLRC663_IRQ_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pins : SPI1_CS_Pin SC_CMDVCC_Pin */
    GPIO_InitStruct.Pin = SPI1_CS_Pin|SC_CMDVCC_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : CLRC663_PDOWN_Pin */
    GPIO_InitStruct.Pin = CLRC663_PDOWN_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CLRC663_PDOWN_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : USB_DISCONNECT_Pin */
    GPIO_InitStruct.Pin = USB_DISCONNECT_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(USB_DISCONNECT_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : BUZZER_Pin */
    GPIO_InitStruct.Pin = BUZZER_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(BUZZER_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : LED_Pin */
    GPIO_InitStruct.Pin = LED_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : SC_OFF_Pin */
    GPIO_InitStruct.Pin = SC_OFF_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(SC_OFF_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pins : SC_RESET_Pin SC_18V_Pin SC_3_5V_Pin SC_CLKDIV_2_Pin
    SC_CLKDIV_1_Pin */
    GPIO_InitStruct.Pin = SC_RESET_Pin|SC_18V_Pin|SC_3_5V_Pin|SC_CLKDIV_2_Pin
    |SC_CLKDIV_1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Configure GPIO pin : SPI2_CS_Pin */
    GPIO_InitStruct.Pin = SPI2_CS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(SPI2_CS_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : PD5 */
    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
