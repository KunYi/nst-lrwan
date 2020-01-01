/**
  ******************************************************************************
  * @file    bsp.h
  * @author  MCD Application Team
  * @brief   contains all hardware driver
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
#ifndef __BSP_H__
#define __BSP_H__

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

#define SENSOR_ENABLED
/* Exported types ------------------------------------------------------------*/

typedef struct
{
  float pressure;    /* in mbar */
  float temperature; /* in °C   */
  float humidity;    /* in %    */
  int32_t latitude;
  int32_t longitude ;
  int16_t  altitudeGps;       /* in m */
  int16_t altitudeBar ;       /* in m * 10 */
  /**more may be added*/
} sensor_t;


/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/**
 * @brief  initialises the sensor
 *
 * @note
 * @retval None
 */
void BSP_sensor_Init(void);

/**
 * @brief  sensor  read.
 *
 * @note none
 * @retval sensor_data
 */
void BSP_sensor_Read(sensor_t *sensor_data);


/**
  * @brief  Configures LED GPIO for external modem.
  * @param  Led: Led to be configured.
  * @retval None
  */
void BSP_LED_Modem_Init(Led_TypeDef Led);


/**
  * @brief  DeInit LEDs GPIO for external modem.
  * @param  Led: LED to be de-init.
  * @note Led DeInit does not disable the GPIO clock nor disable the Mfx
  * @retval None
  */
void BSP_LED_Modem_DeInit(Led_TypeDef Led);



/**
  * @brief  Turns selected LED Modem On.
  * @param  Led: Specifies the Led to be set on.
  * @retval None
  */
void BSP_LED_Modem_On(Led_TypeDef Led);


/**
  * @brief  Turns selected LED Modem Off.
  * @param  Led: Specifies the Led to be set off.
  * @retval None
  */
void BSP_LED_Modem_Off(Led_TypeDef Led);


#ifdef __cplusplus
}
#endif

#endif /* __BSP_H__ */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
