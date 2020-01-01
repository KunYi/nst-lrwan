/**
  ******************************************************************************
  * @file    ee.c
  * @author  MCD Application Team
  * @brief   This file contains a R/W function for EEPROM
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
#include "hw.h"
#include "ee.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions ------------------------------------------------------- */



/******************************************************************************
* @brief Dumy Init  EEPROM emulator.
* @param1 format :
* @return EE_OK
*****************************************************************************/
int EE_Init(int format)
{
  return EE_OK;
}


/******************************************************************************
* @brief Read stored variable data in EEPROM.
* @param1 bank:   index of the bank (0 or 1)  -- Not used
* @param2 addr:   variable address
* @param3 data:   ptr data to be read
* @return EE_OK in case of success
*****************************************************************************/
int EE_Read(int bank, uint16_t addr, uint8_t *data)
{
  /*Read*/
  *data = *((uint8_t *)(DATA_EEPROM_BASE + (addr)));
  return EE_OK;
}

/******************************************************************************
 * @brief Writes/updates variable data in EEPROM.
 * @param1 bank:   index of the bank (0 or 1)  -- Not used
 * @param2 addr:   variable virtual address
 * @param3 data:   32-bit data word to be written
 * @return EE_OK in case of success
******************************************************************************/
int EE_Write(int bank, uint16_t addr, uint32_t data)
{
  /*Unlock*/
  HAL_FLASHEx_DATAEEPROM_Unlock();
  HAL_FLASHEx_DATAEEPROM_EnableFixedTimeProgram();

  /*Write -- Arbitrary "0xYYYY" offset has been added for DevEUI @*/
  *((uint8_t *)(DATA_EEPROM_BASE + (addr))) = data;

  /*lock*/
  HAL_FLASHEx_DATAEEPROM_Lock();

  return EE_OK;
}


/******************************************************************************
* @brief Dumy Clean  EEPROM emulator.
* @param1 bank:  not used
* @param2 interrupt : not used
* @return EE_OK
*****************************************************************************/
int EE_Clean(int bank, int interrupt)
{
  return EE_OK;
}

/******************************************************************************
 * @brief Compare content of Arrays
 * Param1:   Array1
 * Param2:   Array2
 * return: Arrays are identical --> 1
 *         Arrays are different --> 0
*****************************************************************************/
int EE_compareArrays(uint8_t a[], uint8_t b[], int n)
{
  int ii;
  for (ii = 0; ii <= n - 1; ii++)
  {
    if (a[ii] != b[ii])
    {
      return 0;
    }
  }
  return 1;
}

