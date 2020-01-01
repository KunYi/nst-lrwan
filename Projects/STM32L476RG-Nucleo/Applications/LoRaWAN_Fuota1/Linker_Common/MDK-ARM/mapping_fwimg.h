/**
  ******************************************************************************
  * @file    mapping_fwimg.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for firmware images mapping
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
#ifndef MAPPING_FWIMG_H
#define MAPPING_FWIMG_H

/* Slots Regions must be aligned on 2048 bytes (0x800) */

/* swap region (8 kbytes) */
#define REGION_SWAP_START                   0x080F0000
#define REGION_SWAP_END                     0x080F1FFF

/* slot 0 region (432 kbytes) */
#define REGION_SLOT_0_START                 0x08086000
#define REGION_SLOT_0_END                   0x080EFFFF

/* slot 1 region (432 kbytes) */
#define REGION_SLOT_1_START                 0x08014000
#define REGION_SLOT_1_END                   0x0807Dfff

#endif
