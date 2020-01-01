/**
  ******************************************************************************
  * @file    mapping_sbsfu.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for SBSFU mapping
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright(c) 2017 STMicroelectronics International N.V.
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
#ifndef MAPPING_SBSFU_H
#define MAPPING_SBSFU_H

/* SE Code region protected by firewall */
#define VECTOR_SIZE                         0x200
#define ROM_START                           0x08000000
#define SE_CODE_REGION_ROM_START            (ROM_START + VECTOR_SIZE)

#define SE_CALLGATE_REGION_ROM_START        (SE_CODE_REGION_ROM_START + 0x4)

#define SE_CALLGATE_REGION_ROM_END          (SE_CODE_REGION_ROM_START + 0x1FF)

/* SE key region protected by firewall */
#define SE_KEY_REGION_ROM_START             (SE_CALLGATE_REGION_ROM_END + 0x1)
#define SE_KEY_REGION_ROM_END               (SE_KEY_REGION_ROM_START+ 0xFF)

/* SE Startup: call before enabling firewall*/
#define SE_STARTUP_REGION_ROM_START         (SE_KEY_REGION_ROM_END + 0x1)
#define SE_CODE_NOKEY_REGION_ROM_START      (SE_STARTUP_REGION_ROM_START + 0x100)
#define SE_CODE_REGION_ROM_END              (SE_STARTUP_REGION_ROM_START + 0x92FF)

/* SE IF ROM: used to locate Secure Engine interface code out of firewall     */
#define SE_IF_REGION_ROM_START              (SE_CODE_REGION_ROM_END + 0x1)
#define SE_IF_REGION_ROM_END                (SE_IF_REGION_ROM_START + 0x4FF)

/* SBSFU Code region */
#define SB_REGION_ROM_START                 (SE_IF_REGION_ROM_END + 0x1)
#define SB_REGION_ROM_END                   0x08013FFF

/* ROM regions size definition */
#define SE_CALLGATE_REGION_ROM_SIZE         (SE_CALLGATE_REGION_ROM_END - SE_CODE_REGION_ROM_START + 0x1)
#define SE_KEY_REGION_ROM_SIZE              (SE_KEY_REGION_ROM_END - SE_KEY_REGION_ROM_START + 0x1)
#define SE_ROM_REGION_SIZE                  (SE_CODE_REGION_ROM_END - SE_CODE_NOKEY_REGION_ROM_START + 0x1)
#define SE_IF_ROM_REGION_SIZE               (SE_IF_REGION_ROM_END - SE_IF_REGION_ROM_START + 0x1)
#define SB_ROM_REGION_SIZE                  (SB_REGION_ROM_END - SB_REGION_ROM_START + 0x1)

/*                              RAM section                                   */
/* SE RAM1 region protected by firewall */
/* SE stack is placed 1st in RAM, stack overflow does not write on other RAM area */

#define SE_REGION_SRAM1_START               0x20000000
#define SE_REGION_SRAM1_STACK_TOP           0x20001000
#define SE_REGION_SRAM1_END                 0x20002DFF

/* SBSFU RAM1 region */
#define SB_REGION_SRAM1_START               (SE_REGION_SRAM1_END + 0x01)
#define SB_REGION_SRAM1_END                 0x20017FFF

#define SE_SRAM1_REGION_START               (SE_REGION_SRAM1_STACK_TOP)
#define SE_SRAM1_REGION_SIZE                (SE_REGION_SRAM1_END - SE_REGION_SRAM1_STACK_TOP + 0x1)
#define SB_SRAM1_REGION_SIZE                (SB_REGION_SRAM1_END - SB_REGION_SRAM1_START)

#endif

