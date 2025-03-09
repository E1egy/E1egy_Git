/*!
****************************************************************************************
*
*  Copyright ~{B)~} 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   PFlashDriver.h
* \author  BL_zq
* \version 1.0
* \date    2022-05-27
* \btief  The header file of PFlashDriver.c
*
*---------------------------------------------------------------------------------------
* \attention
*
*
****************************************************************************************
*/

/***************************************************************************************
   change history:
      1.date  : 2022-05-27
         author: BL_zq
         change: create file

***************************************************************************************/

#ifndef  DFLASHDRIVER_H
#define  DFLASHDRIVER_H

/***************************************Includes***************************************/
#include "Platform_Types.h"
#include <stdio.h>
#include <string.h>
#include "IfxFlash_cfg.h"

/***************************************Macros****************************************/
#define DFLASH_DCM_BLOCK_ADDR (0xAF03E000)
#define DFLASH_PROG_FLAG_ADDR (0xAF03F000)

#define DFLASH_DCM_F184_OFFSET    (0)
#define DFLASH_DCM_F184_LENGTH    (0x20)
#define DFLASH_DCM_F0F1_OFFSET    (DFLASH_DCM_F184_OFFSET + DFLASH_DCM_F184_LENGTH)
#define DFLASH_DCM_F0F1_LENGTH    (0x20)
#define DFLASH_DCM_F0F3_OFFSET    (DFLASH_DCM_F0F1_OFFSET + DFLASH_DCM_F0F1_LENGTH)
#define DFLASH_DCM_F0F3_LENGTH    (0x20)
#define DFLASH_DCM_F162_OFFSET    (DFLASH_DCM_F0F3_OFFSET + DFLASH_DCM_F0F3_LENGTH)
#define DFLASH_DCM_F162_LENGTH    (0x28)
#define DFLASH_DCM_ALL_LENGTH      136//(DFLASH_DCM_F184_LENGTH+DFLASH_DCM_F0F1_LENGTH+DFLASH_DCM_F0F3_LENGTH+DFLASH_DCM_F162_LENGTH)
#define DFLASH_DCM_PAGE_NUM       (17) //(0x20+0x20+0x20+0x20) / 8
/***************************************Enum*****************************************/

/***************************************Union****************************************/

/***************************************Struct***************************************/

/***************************************Variables*************************************/
extern uint8 DCM_Block_RAM_Buf[DFLASH_DCM_ALL_LENGTH];
/***************************************Functions************************************/
extern void DFlashDriver_SetProgFlag(uint32 ProgFlag, uint32 ResponseFlag);
extern void DFlashDriver_ClearProgFlag(void);
extern uint8 DFlashDriver_ReadDcmBlock(void);
extern void DFlashDriver_WriteDcmBlock(void);
extern void DFlashDriver_WriteDID_F184(uint8 * DidData);
extern void DFlashDriver_WriteDID_F0F1(uint8 * DidData);
extern void DFlashDriver_WriteDID_F0F3(uint8 * DidData);
extern void DFlashDriver_WriteDID_F162(uint8 * DidData);
#endif
/*  END OF FILE */
