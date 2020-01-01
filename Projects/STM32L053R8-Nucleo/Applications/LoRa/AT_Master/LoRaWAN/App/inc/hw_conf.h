/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech

Description: contains hardaware configuration Macros and Constants

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis and Gregory Cristian
*/
/**
  ******************************************************************************
  * @file    hw_conf.h
  * @author  MCD Application Team
  * @brief   contains hardware configuration Macros and Constants
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
#ifndef __HW_CONF_H__
#define __HW_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#ifdef USE_STM32F0XX_NUCLEO
#include "stm32f0xx_hal.h"
#include "stm32f0xx_nucleo.h"
#include "stm32f0xx_hal_conf.h"
#include "stm32f0xx_ll_rtc.h"
#error "create stm32f0xx_hw_conf.h "
#endif

#ifdef USE_STM32F1XX_NUCLEO
#include "stm32f1xx_hal.h"
#include "stm32f1xx_nucleo.h"
#include "stm32f1xx_hal_conf.h"
#include "stm32f1xx_ll_rtc.h"
#error "create stm32f1xx_hw_conf.h "
#endif

#ifdef USE_STM32F3XX_NUCLEO
#include "stm32f3xx_hal.h"
#include "stm32f3xx_nucleo.h"
#include "stm32f3xx_hal_conf.h"
#include "stm32f3xx_ll_rtc.h"
#error "create stm32f3xx_hw_conf.h "
#endif

#ifdef USE_STM32F4XX_NUCLEO
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo.h"
#include "stm32f4xx_hal_conf.h"
#include "stm32f4xx_ll_rtc.h"
#error "create stm32f4xx_hw_conf.h "
#endif

#ifdef USE_STM32L0XX_NUCLEO
#include "stm32l0xx_hal.h"
#include "stm32l0xx_nucleo.h"
#include "stm32l0xx_hal_conf.h"
#include "stm32l0xx_hw_conf.h"
#include "stm32l0xx_ll_rtc.h"
#endif

#ifdef USE_STM32L1XX_NUCLEO
#include "stm32l1xx_hal.h"
#include "stm32l1xx_nucleo.h"
#include "stm32l1xx_hal_conf.h"
#include "stm32l1xx_hw_conf.h"
#include "stm32l1xx_ll_rtc.h"
#endif

#ifdef USE_STM32L4XX_NUCLEO
#include "stm32l4xx_hal.h"
#include "stm32l4xx_nucleo.h"
#include "stm32l4xx_hal_conf.h"
#include "stm32l4xx_hw_conf.h"
#include "stm32l4xx_ll_rtc.h"
#endif

#ifdef USE_B_L072Z_LRWAN1
#include "stm32l0xx_hal.h"
#include "b-l072z-lrwan1.h"
#include "stm32l0xx_hal_conf.h"
#include "mlm32l0xx_hw_conf.h"
#include "stm32l0xx_ll_rtc.h"
#endif

/* --------Preprocessor compile swicth------------ */
/* debug swicthes in debug.h */
/*#define DEBUG */
/*#define TRACE */

/* uncomment below line to never enter lowpower modes in main.c*/
/*#define LOW_POWER_DISABLE */

/* debug swicthes in bsp.c */
/*#define SENSOR_ENABLED */

/*UART used : USART2 or LPUART1 - if LPUART1 used comment the USE_USART2*/
#define USE_USART2 1

/* Define with type of modem device application will use*/
#ifdef USE_MDM32L07X01
#define ATCMD_MODEM  "atcmd.h"
#elif USE_I_NUCLEO_LRWAN1
#define ATCMD_MODEM  "i_nucleo_lrwan1_wm_sg_sm_xx.h"
#elif USE_LRWAN_NS1
#define ATCMD_MODEM  "lrwan_ns1_atcmd.h"
#endif

/*USI Modem MCU in sleep mode*/
/*#define MODEM_IN_SLEEP_MODE */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __HW_CONF_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
