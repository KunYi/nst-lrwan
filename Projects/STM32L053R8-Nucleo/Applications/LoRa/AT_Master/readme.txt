/**
  @page AT_Master Readme file
 
  @verbatim
  ******************************************************************************
  * @file    AT_Master/readme.txt 
  * @author  MCD Application Team
  * @brief   This application is a simple demo application software of a LoRa
  *          modem controlled though AT command interface over UART by an
  *          external host
  ******************************************************************************
  *
  * Copyright (c) 2018 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                               www.st.com/SLA0044
  *
  ******************************************************************************
   @endverbatim

@par Example Description

This directory contains a set of source files that implements a host AT_Master
application, featuring a complete set of AT commands to drive an external
LoRa modem.

The application provides a way to establish a LoRa Link, to read sensors
(temperature, humidity and pressure) and to transmit associated data to the
LoRa Network.

This application is targeting the NUCLEO-L053R8 and NUCLEO-L073RZ boards.
  ******************************************************************************



@par Directory contents 


  - AT_Master/Core/inc/stm32l0xx_hal_conf.h       HAL configuration file.
  - AT_Master/Core/inc/stm32l0xx_hw_conf.h        contains hardaware configuration Macros and Constants
  - AT_Master/Core/inc/stm32l0xx_it.h             This file contains the headers of the interrupt handlers.
  - AT_Master/LoRaWAN/App/inc/bsp.h               contains all hardware driver
  - AT_Master/LoRaWAN/App/inc/debug.h             Header for driver debug.c module
  - AT_Master/LoRaWAN/App/inc/ee.h                Interface for ee driver API
  - AT_Master/LoRaWAN/App/inc/hw.h                contains all hardware driver
  - AT_Master/LoRaWAN/App/inc/hw_conf.h           contains hardware configuration Macros and Constants
  - AT_Master/LoRaWAN/App/inc/hw_gpio.h           Header for driver hw_gpio.c module
  - AT_Master/LoRaWAN/App/inc/hw_msp.h            Header for driver hw msp module
  - AT_Master/LoRaWAN/App/inc/hw_rtc.h            Header for driver hw_rtc.c module
  - AT_Master/LoRaWAN/App/inc/hw_usart.h          This file provides code for the configuration of the USART
                                                  instances.
  - AT_Master/LoRaWAN/App/inc/lora_driver.h       Header for lora driver module
  - AT_Master/LoRaWAN/App/inc/tiny_sscanf.h       Header for driver tiny_sscanf.c module
  - AT_Master/LoRaWAN/App/inc/tiny_vsnprintf.h    Header for tiny_vsnprintf.c module
  - AT_Master/LoRaWAN/App/inc/utilities_conf.h    configuration for utilities
  - AT_Master/LoRaWAN/App/inc/vcom.h              Header for vcom.c module

  - AT_Master/Core/src/stm32l0xx_hal_msp.c        This file provides code for the MSP Initialization and
                                                  de-Initialization codes.
  - AT_Master/Core/src/stm32l0xx_hw.c             system hardware driver
  - AT_Master/Core/src/stm32l0xx_it.c             Interrupt Service Routines.
  - AT_Master/LoRaWAN/App/src/bsp.c               manages the sensors on the application
  - AT_Master/LoRaWAN/App/src/debug.c             debug API
  - AT_Master/LoRaWAN/App/src/ee.c                This file contains a R/W function for EEPROM
  - AT_Master/LoRaWAN/App/src/hw_gpio.c           driver for GPIO
  - AT_Master/LoRaWAN/App/src/hw_rtc.c            driver for RTC
  - AT_Master/LoRaWAN/App/src/hw_usart.c          This file provides code for the configuration of the USART
                                                  instances.
  - AT_Master/LoRaWAN/App/src/lora_driver.c       LoRa module API
  - AT_Master/LoRaWAN/App/src/main.c              Main program body
  - AT_Master/LoRaWAN/App/src/tiny_sscanf.c       Tiny implementation of sscanf
  - AT_Master/LoRaWAN/App/src/tiny_vsnprintf.c    Tiny implementation of vsnprintf like function

@par Hardware and Software environment 


  - This example runs on the STM32L053R8 and STM32L073RZ devices and has been tested with
    STMicroelectronics NUCLEO-L053R8 RevC and NUCLEO-L073RZ RevC boards.

  - NUCLEO-L053R8/NUCLEO-L073RZ board Set-up 
    - When using MDM32L07X01 expansion board, plug the X_NUCLEO_IKS01A1 shield (sensors) 
    - Plug the  expansion board (I-NUCLEO-LRWAN1 or MDM32L07X01 or LRWAN_NS1) on the NUCLEO-L053R8 board   
    - Connect the Nucleo board to your PC with a USB cable type A to micro-B 
      to ST-LINK connector (CN1).
    - Please ensure that the ST-LINK connector CN2 jumpers are fitted.


  -Set Up:


     -----------------                      -----------------------  V    V  ----------------------
     |  AT-Master    |                      |      LoRa Modem     |  |    |  |      LoRa Network  |
     |  Application  |                      |                     |  |    |  |                    |
     |               |<--AT_CMD over UART-->|                     |--|    |--|                    |-->Web Server
     |               |                      |                     |          |                    |
     -----------------                      -----------------------          ----------------------

@par How to use it ? 
In order to make the program work, you must do the following :
  - Open your preferred toolchain 
  - Rebuild all files and load your image into target memory (select the right workspace following the expansion board I_NUCLEO_LRWAN1 or
    MDM32L07X01 or LRWAN_NS1)
  - Run the example
  - Note : If needed and in order to spy the communication between AT_MAster and LoRa modem 
    - Open an Hyperterminal Terminal and connect it (could be an FTDI cable) to the "D1:LPUART1_RX/D0:LPUART1_TX" of the LoRa Modem
    - UART Config = 115200, 8b, 1 stopbit, no parity, no flow control
    - Terminal Config: Select 'CR+LF' for Transmit New-Line and switch 'Local echo' on
   
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */