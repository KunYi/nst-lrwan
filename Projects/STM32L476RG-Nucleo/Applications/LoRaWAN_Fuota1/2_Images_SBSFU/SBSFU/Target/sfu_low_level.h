/**
  ******************************************************************************
  * @file    sfu_low_level.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for Secure Firmware Update low level
  *          interface.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
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
#ifndef  SFU_LOW_LEVEL_H
#define  SFU_LOW_LEVEL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "sfu_def.h"

/** @addtogroup SFU Secure Secure Boot / Firmware Update
  * @{
  */

/** @addtogroup SFU_LOW_LEVEL
  * @{
  */

/** @defgroup SFU_LOW_LEVEL_General General Low Level Interface
  * @{
  */

/** @defgroup SFU_LOW_LEVEL_Configuration Hardware Configuration
  * @{
  */

/** @defgroup SFU_CONFIG_UART  UART Configuration
  * @{
  */
#define SFU_UART                                USART2
#define SFU_UART_CLK_ENABLE()                   __HAL_RCC_USART2_CLK_ENABLE()
#define SFU_UART_CLK_DISABLE()                  __HAL_RCC_USART2_CLK_DISABLE()

#define SFU_UART_TX_AF                          GPIO_AF7_USART2
#define SFU_UART_TX_GPIO_PORT                   GPIOA
#define SFU_UART_TX_PIN                         GPIO_PIN_2
#define SFU_UART_TX_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOA_CLK_ENABLE()
#define SFU_UART_TX_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOA_CLK_DISABLE()

#define SFU_UART_RX_AF                          GPIO_AF7_USART2
#define SFU_UART_RX_GPIO_PORT                   GPIOA
#define SFU_UART_RX_PIN                         GPIO_PIN_3
#define SFU_UART_RX_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOA_CLK_ENABLE()
#define SFU_UART_RX_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOA_CLK_DISABLE()

/**
  * @}
  */

/** @defgroup SFU_CONFIG_CLOCK RTC Clock Configuration
  * @{
  */
/* Uncomment to enable the adaquate Clock Source */
#define RTC_CLOCK_SOURCE_LSI
/*#define RTC_CLOCK_SOURCE_LSE*/

#ifdef RTC_CLOCK_SOURCE_LSI
#define RTC_ASYNCH_PREDIV    0x7FU
#define RTC_SYNCH_PREDIV     0xF9
#endif /* RTC_CLOCK_SOURCE_LSI */

#ifdef RTC_CLOCK_SOURCE_LSE
#define RTC_ASYNCH_PREDIV  0x7FU
#define RTC_SYNCH_PREDIV   0x00FFU
#endif /* RTC_CLOCK_SOURCE_LSE */

/**
  * @}
  */

/**
  * @}
  */


/** @defgroup SFU_LOW_LEVEL_Exported_Constants Exported Constants
  * @{
  */

/**
  * @brief  SFU CRC Configuration definition
  */
typedef enum
{
  SFU_CRC_CONFIG_NONE = 0U,   /*!< None */
  SFU_CRC_CONFIG_DEFAULT,     /*!< Default configuration */
  SFU_CRC_CONFIG_16BIT        /*!< 16 bit configuration */
} SFU_CRC_ConfigTypeDef;

/**
  * @}
  */

/** @defgroup SFU_LOW_LEVEL_Exported_Macros Exported Macros
  * @{
  */

#define IS_SFU_CRC_CONF(CONF) (((CONF) == SFU_CRC_CONFIG_NONE) || \
                               ((CONF) == SFU_CRC_CONFIG_DEFAULT) || \
                               ((CONF) == SFU_CRC_CONFIG_16BIT))

/**
  * @}
  */

/** @defgroup SFU_LOW_LEVEL_Exported_Functions Exported Functions
  * @{
  */

/** @defgroup SFU_LOW_LEVEL_Initialization_Functions
  * @{
  */
SFU_ErrorStatus    SFU_LL_Init(void);
SFU_ErrorStatus    SFU_LL_DeInit(void);

/**
  * @}
  */

/** @defgroup SFU_LOW_LEVEL_CRC_Functions CRC Functions
  * @{
  */
SFU_ErrorStatus    SFU_LL_CRC_Init(void);
SFU_ErrorStatus    SFU_LL_CRC_Config(SFU_CRC_ConfigTypeDef eCRCConfg);
uint32_t           SFU_LL_CRC_Calculate(uint32_t pBuffer[], uint32_t BufferLength);

/**
  * @}
  */

/** @defgroup SFU_LOW_LEVEL_UART_Functions UART Functions
  * @{
  */
SFU_ErrorStatus    SFU_LL_UART_Init(void);
SFU_ErrorStatus    SFU_LL_UART_DeInit(void);
SFU_ErrorStatus    SFU_LL_UART_Transmit(uint8_t *pData, uint16_t DataLength, uint32_t Timeout);
SFU_ErrorStatus    SFU_LL_UART_Receive(uint8_t *pData, uint16_t DataLength, uint32_t Timeout);
SFU_ErrorStatus    SFU_LL_UART_Flush(void);

/**
  * @}
  */

#ifndef SFU_TAMPER_PROTECT_ENABLE
/** @defgroup SFU_LOW_LEVEL_RTC_Functions RTC Functions
  * @{
  */
SFU_ErrorStatus SFU_LL_RTC_Init(void);
SFU_ErrorStatus SFU_LL_RTC_DeInit(void);

/**
  * @}
  */
#endif /*SFU_TAMPER_PROTECT_ENABLE*/

/** @defgroup SFU_LOW_LEVEL_SRAM_Functions SRAM Functions
  * @{
  */
void SFU_LL_SB_SRAM_Erase(void);

/**
  * @}
  */



/** @defgroup SFU_LOW_LEVEL_MSP_Functions MSP Functions
  * @{
  */
void  SFU_LL_RTC_MspInit(RTC_HandleTypeDef *hrtc);
void  SFU_LL_RTC_MspDeInit(RTC_HandleTypeDef *hrtc);
void  SFU_LL_UART_MspInit(UART_HandleTypeDef *huart);
void  SFU_LL_UART_MspDeInit(UART_HandleTypeDef *huart);

/**
  * @}
  */

/**
  * @}
  */

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

#endif /*  SFU_LOW_LEVEL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

