/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech

Description: virtual com port driver

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis and Gregory Cristian
*/
/**
  ******************************************************************************
  * @file    vcom.h
  * @author  MCD Application Team
  * @brief   Header for vcom.c module
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
#ifndef __VCOM_H__
#define __VCOM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

/**
* @brief  Init the VCOM.
* @param  None
* @return None
*/
void vcom_Init(void);

/**
* @brief  DeInit the VCOM.
* @param  None
* @return None
*/
void vcom_DeInit(void);

/**
* @brief  Init the VCOM IOs.
* @param  None
* @return None
*/
void vcom_IoInit(void);

/**
* @brief  DeInit the VCOM IOs.
* @param  None
* @return None
*/
void vcom_IoDeInit(void);

/**
* @brief  Records string on circular Buffer
* @note   Set NVIC to call vocm
* @param  string
* @return None
*/
void vcom_Send(char *format, ...);

/**
* @brief  Sends circular Buffer on com port in IT mode
* @note   called from low Priority interrupt
* @param  None
* @return None
*/
void vcom_Print(void);

/**
* @brief  Sends string on com port in poll mode
* @note   To be called only from critical section from low power section
*         Other wise use vcom_Send
* @param  string
* @return None
*/
void vcom_PrintCS(char *format, ...);

/* Exported macros -----------------------------------------------------------*/
#if 1
#define PRINTF(...)            vcom_Send(__VA_ARGS__)
#define PRINTF_CRITICAL(...)   vcom_PrintCS(__VA_ARGS__)
#else
#define PRINTF(...)
#endif


#ifdef __cplusplus
}
#endif

#endif /* __VCOM_H__*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
