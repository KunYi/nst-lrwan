/**
  ******************************************************************************
  * @file    ee.h
  * @author  MCD Application Team
  * @brief   Interface for ee driver API
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
#ifndef EE_H__
#define EE_H__

#include <stdint.h>


/* Definition of the functions return value */
enum
{
  EE_OK = 0,
  EE_NOT_FOUND,     /* read data is not found in flash */
  EE_CLEAN_NEEDED,  /* data is written but a "clean" is needed */
  EE_ERASE_ERROR,   /* an error occurs during flash erase */
  EE_WRITE_ERROR,   /* an error occurs during flash write */
  EE_STATE_ERROR    /* state of flash is incoherent (needs clean or format) */
};


/******************************************************************************
* @brief Dumy Init  EEPROM emulator.
* @param1 format :
* @return EE_OK
*****************************************************************************/
int EE_Init(int format);

/******************************************************************************
* @brief Read stored variable data in EEPROM emulator.
* @param1 bank:   index of the bank (0 or 1)  -- Not used
* @param2 addr:   variable address
* @param3 data:   ptr data to be read
* @return EE_OK in case of success
*****************************************************************************/
extern int EE_Read(int bank, uint16_t addr, /*uint32_t*/ uint8_t *data);

/******************************************************************************
* @brief Writes/updates variable data in EEPROM emulator.
* @param1 bank:   index of the bank (0 or 1)  -- Not used
* @param2 addr:   variable virtual address
* @param3 data:   32-bit data word to be written
* @return EE_OK in case of success
*****************************************************************************/
extern int EE_Write(int bank, uint16_t addr, uint32_t data);

/******************************************************************************
* @brief Dumy Clean  EEPROM emulator.
* @param1 bank:  not used
* @param2 interrupt : not used
* @return EE_OK
*****************************************************************************/
int EE_Clean(int bank, int interrupt);

/******************************************************************************
 * @brief Compare content of Arrays
 * Param1:   Array1
 * Param2:   Array2
 * return: Arrays are identical --> 1
 *         Arrays are different --> 0
*****************************************************************************/
extern int EE_compareArrays(uint8_t a[], uint8_t b[], int n) ;
#endif /* EE_H__ */
