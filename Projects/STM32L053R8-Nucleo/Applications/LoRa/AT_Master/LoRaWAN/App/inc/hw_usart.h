/**
  ******************************************************************************
  * @file    hw_usart.h
  * @author  MCD Application Team
  * @brief   This file provides code for the configuration of the USART
  *          instances.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "hw_msp.h"
#include "low_power_manager.h"


extern UART_HandleTypeDef huart2;

/* Private defines -----------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

#ifdef USE_MDM32L07X01
#define BAUD_RATE 9600
#elif USE_I_NUCLEO_LRWAN1
#define BAUD_RATE 115200
#elif USE_LRWAN_NS1
#define BAUD_RATE 9600
extern UART_HandleTypeDef huart1;
#endif

/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

HAL_StatusTypeDef HW_UART_Modem_Init(uint32_t BaudRate);

void HW_UART_Modem_IRQHandler(UART_HandleTypeDef *huart);

FlagStatus HW_UART_Modem_IsNewCharReceived(void);

uint8_t HW_UART_Modem_GetNewChar(void);


#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
