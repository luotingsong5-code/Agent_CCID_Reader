/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f1xx_hal_timebase_tim.c
 * @brief   使用定时器作为 HAL 库系统滴答时钟源文件
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
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_tim.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef        htim2;
/* Private function prototypes -----------------------------------------------*/
void TIM2_IRQHandler(void);
/* Private functions ---------------------------------------------------------*/

/**
 * @brief   初始化 HALTick 外设
 * @param   TickPriority TickPriority 参数
 * @retval  HAL_StatusTypeDef HAL 通道操作状态
*/
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
    RCC_ClkInitTypeDef    clkconfig;
    uint32_t              uwTimclock, uwAPB1Prescaler = 0U;

    uint32_t              uwPrescalerValue = 0U;
    uint32_t              pFLatency;

    HAL_StatusTypeDef     status = HAL_OK;

    /* Enable TIM2 clock */
    __HAL_RCC_TIM2_CLK_ENABLE();

    /* Get clock configuration */
    HAL_RCC_GetClockConfig(&clkconfig, &pFLatency);

    /* Get APB1 prescaler */
    uwAPB1Prescaler = clkconfig.APB1CLKDivider;
    /* Compute TIM2 clock */
    if (uwAPB1Prescaler == RCC_HCLK_DIV1)
    {
        uwTimclock = HAL_RCC_GetPCLK1Freq();
    }
    else
    {
        uwTimclock = 2UL * HAL_RCC_GetPCLK1Freq();
    }

    /* Compute the prescaler value to have TIM2 counter clock equal to 1MHz */
    uwPrescalerValue = (uint32_t) ((uwTimclock / 1000000U) - 1U);

    /* Initialize TIM2 */
    htim2.Instance = TIM2;

    /* Initialize TIMx peripheral as follow:
     * Period = [(TIM2CLK/1000) - 1]. to have a (1/1000) s time base.
     * Prescaler = (uwTimclock/1000000 - 1) to have a 1MHz counter clock.
     * ClockDivision = 0
     * Counter direction = Up
    */
    htim2.Init.Period = (1000000U / 1000U) - 1U;
    htim2.Init.Prescaler = uwPrescalerValue;
    htim2.Init.ClockDivision = 0;
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    status = HAL_TIM_Base_Init(&htim2);
    if (status == HAL_OK)
    {
        /* Start the TIM time Base generation in interrupt mode */
        status = HAL_TIM_Base_Start_IT(&htim2);
        if (status == HAL_OK)
        {
            /* Enable the TIM2 global Interrupt */
            HAL_NVIC_EnableIRQ(TIM2_IRQn);
            /* Configure the SysTick IRQ priority */
            if (TickPriority < (1UL << __NVIC_PRIO_BITS))
            {
                /* Configure the TIM IRQ priority */
                HAL_NVIC_SetPriority(TIM2_IRQn, TickPriority, 0U);
                uwTickPrio = TickPriority;
            }
            else
            {
                status = HAL_ERROR;
            }
        }
    }

    /* Return function status */
    return status;
}

/**
 * @brief   HAL 库回调/操作函数: HAL_SuspendTick
 * @retval  无
*/
void HAL_SuspendTick(void)
{
    /* Disable TIM2 update Interrupt */
    __HAL_TIM_DISABLE_IT(&htim2, TIM_IT_UPDATE);
}

/**
 * @brief   HAL 库回调/操作函数: HAL_ResumeTick
 * @retval  无
*/
void HAL_ResumeTick(void)
{
    /* Enable TIM2 Update interrupt */
    __HAL_TIM_ENABLE_IT(&htim2, TIM_IT_UPDATE);
}

