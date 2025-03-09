/*!
****************************************************************************************
*
*  Copyright © 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   UCB_DataFlashDriver.h
* \author  BL_zq
* \version 1.0
* \date    2022-05-26
* \btief  The header file of EepromDriver.c
*
*---------------------------------------------------------------------------------------
* \attention
*
*
****************************************************************************************
*/

/***************************************************************************************
    change history:
        1.date  : 2022-05-26
         author: BL_zq
         change: create file

***************************************************************************************/

#ifndef  EEPROMDRIVER_H
#define  EEPROMDRIVER_H

/***************************************Includes***************************************/
#include "Platform_Types.h"

/***************************************Macros****************************************/
#define DISABLE 0
#define ENABLE 1

/**Data Flash 0:
 * size -- 256Kb
 * Address -- 0xAF00 0000~0xAF03 FFFF
 * Width -- 32
 * Logical Sector Size -- 4Kb
 * Logical Sector Number -- 64  **/
#define DFLASH_0 0
#define DFLASH0_START_ADDR 0xAF000000
#define DFLASH0_END_ADDR   0XAFBFFFFF

/**Data Flash 1:
 * size -- 128Kb
 * Address -- 0xAFC0 0000~0xAF01 FFFF
 * Width -- 32
 * Logical Sector Size -- 4Kb
 * Logical Sector Number -- 32  **/
#define DFLASH_1 1
#define DFLASH1_START_ADDR 0xAFC00000
#define DFLASH1_END_ADDR   0XAFC1FFFF

/***************************************Enum*****************************************/

/***************************************Union****************************************/

/***************************************Struct***************************************/

/***************************************Variables*************************************/

/***************************************Functions************************************/
extern void UCBDriver_ucbEraseSector(uint32 Addr);
extern void UCBDriver_ucbProgramPage(uint32 Addr, uint32 lword, uint32 hword);
extern uint8 UCBDriver_ucbReadDataFromUcb(uint32 startAddr,uint8 *p_data,uint16 len, uint32 checksumEnable);
extern uint8 UCBDriver_ucbWriteDataIntoUcb(uint32 startAddr,uint8 *p_data,uint16 len, uint32 checksumEnable);

#endif
/*  END OF FILE */