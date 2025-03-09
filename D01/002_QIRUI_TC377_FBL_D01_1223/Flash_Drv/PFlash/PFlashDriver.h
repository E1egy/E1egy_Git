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

#ifndef  PFLASHDRIVER_H
#define  PFLASHDRIVER_H

/***************************************Includes***************************************/
#include "Platform_Types.h"
#include <stdio.h>
#include <string.h>
#include "IfxFlash_cfg.h"

/***************************************Macros****************************************/

/**Programming Flash 0:
 * Size -- 3M
 * Address -- 0xA000 0000~~0xA02F FFFF
 * Width -- 32
 * Logical Sector Size -- 16Kb
 * Logical Sector Number -- 192  **/
#define PFLASH_0 0
#define FLASH_TYPE_OF_PFLASH0 IfxFlash_FlashType_P0
#define PFLASH0_3M_LOGICAL_SECTOR_NUMBER 192
#define PFLASH0_LOGICAL_SECTOR_SIZE 0x00004000
#define PFLASH0_START_ADDR 0xA0000000
#define PFLASH0_END_ADDR   0XA02FFFFF


/**Programming Flash 1:
 * Size -- 3M
 * Address -- 0xA030 0000~~0xA05F FFFF
 * Width -- 32
 * Logical Sector Size -- 16Kb
 * Logical Sector Number -- 192  **/
#define PFLASH_1 1
#define FLASH_TYPE_OF_PFLASH1 IfxFlash_FlashType_P1
#define PFLASH1_3M_LOGICAL_SECTOR_NUMBER 192
#define PFLASH1_LOGICAL_SECTOR_SIZE 0x00004000
#define PFLASH1_START_ADDR 0xA0300000
#define PFLASH1_END_ADDR   0XA05FFFFF



/**Definition of the addresses where to relocate the erase and program routines, given their reserved space.  **/

#define ERASESECTORS_ADDR           (0x70100100U )
#define WAITUNBUSY_ADDR             (0x70100140U)
#define ENTERPAGEMODE_ADDR          (0x70100170U)
#define LOAD2X32_ADDR               (0x701001B0U)
#define WRITEPAGE_ADDR              (0x701001D0U)
#define ERASESECTOR_ADDR            (0x70100210U)
#define PROGRAMPAGE_ADDR            (0x70100370U)
#define WRITEPFLASH_ADDR            (0x70100580U)
#define READPFLASH_ADDR             (0x70100700U)

/***************************************Enum*****************************************/

/***************************************Union****************************************/

/***************************************Struct***************************************/
typedef struct
{
   void (*setBuffer)(void *s, int c, uint32 n);
   void (*eraseSectors)(uint32 sectorAddr, uint32 numSector);
   uint8 (*waitUnbusy)(uint32 flash,IfxFlash_FlashType flashType);
   uint8 (*enterPageMode)(uint32 pageAddr);
   void (*load2X32bits)(uint32 pageAddr, uint32 wordL, uint32 wordU);
   void (*writePage)(uint32 pageAddr);
   uint8 (*eraseSector)(uint32 addr,uint32 sectorNumber);
   sint8 (*eraseAllPflash0)(void);
   uint8 (*eraseAllPflash1)(void);
   uint32 (*programPage)(uint32 addr,uint8* p_data);
   uint8 (*writeFlash)(uint32 addr, uint8 *p_data, uint32 len);
   uint8 (*readFlash)(uint32 addr, uint8 *p_data, uint16 len);
} Function;


/***************************************Variables*************************************/
extern Function g_commandFromPSPR;
/***************************************Functions************************************/
extern void PFlashDriver_maskPFlashUncorrectableEccBitErr(void);
extern void PFlashDriver_pflashCopyFunctionIntoPSPR(void);
extern uint8 PFlashDriver_pflashEraseSector(uint32 addr,uint32 sectorNumber);
extern uint32 PFlashDriver_pflashProgramPage(uint32 addr,uint8* p_data);
extern uint8 PFlashDriver_pflashReadDataFromPflash(uint32 addr, uint8 *p_data, uint16 len);
extern uint8 PFlashDriver_pflashWriteDataIntoPflash(uint32 addr, uint8 *p_data, uint32 len);
extern uint8 PFlashDriver_pflashCheckWriteData(uint32 addr, uint8 *p_data);
extern uint32 PFlashDriver_pflashCrcCcitt1021(uint32 initCrcValue,uint32 address,uint32 len);
#endif
/*  END OF FILE */
