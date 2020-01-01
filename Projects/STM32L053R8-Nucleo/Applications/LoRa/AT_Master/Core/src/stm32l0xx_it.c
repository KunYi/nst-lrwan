/**
  ******************************************************************************
  * @file    stm32l0xx_it.c
  * @author  MCD Application Team
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "stm32l0xx.h"
#include "hw.h"
#include "stm32l0xx_it.h"



/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart2;

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Functions Definition ------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M0+ Processor Interruption and Exception Handlers         */
/******************************************************************************/

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{

  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();

}


/**
* @brief This function handles USART2 global interrupt / USART2 wake-up interrupt through EXTI line 26.
*/
#ifndef USE_LRWAN_NS1
#if USE_USART2
void USART2_IRQHandler(void)
#else
void RNG_LPUART1_IRQHandler(void)
#endif
{

  HW_UART_Modem_IRQHandler(&huart2);

}
#else
void USART1_IRQHandler(void)
{

  HW_UART_Modem_IRQHandler(&huart1);

}

/**
* @brief This function handles the EXTI4_15_IRQn interrupts.
*/
void EXTI4_15_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(USER_BUTTON_PIN);
}
#endif


/**
* @brief This function handles the RTC Alarm A interrupts.
*/
void RTC_IRQHandler(void)
{
  HW_RTC_IrqHandler();
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
