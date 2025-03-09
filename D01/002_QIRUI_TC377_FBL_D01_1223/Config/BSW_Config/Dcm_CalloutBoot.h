/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dcm_CalloutBoot.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-02-22 20:06:29>
 */
/*============================================================================*/

/* Dcm_CalloutBoot.h */

#ifndef DCM_CALLOUTBOOT_H
#define DCM_CALLOUTBOOT_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/
#define FOTA_ENABLE 0
typedef struct
{
    /** Value indicate an external programming request. */
    uint32 FlBootMode;

    /** Value indicate an update of the application software. */
    uint32 FlApplUpdate;

    /** Value indicate default session request from prog. of the bootloader software. */
    uint32 FlBootDefault;

#if (FOTA_ENABLE == STD_ON)
    /*active the new app*/
    uint32 ActiveFlag;

    /*rollback to the old app*/
    uint32 RollbackFlag;

    uint32 JumpAddress;
#endif
}BL_AppFlagType;

/** Value indicate an update of the application software. */
#define ACTIVE_FLAG 0xD5u

/** Value indicate default session request from prog. of the bootloader software. */
#define ROLL_BACK_FLAG       0x01U

/** The physical memory location of boot request flag. LOCAL address*/
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
#define FL_BOOT_MODE            /*TODO Need to add address*/
/** The physical memory location of application software update flag. LOCAL address*/
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
#define FL_APPL_UPDATE      /*TODO Need to add address*/

#define BL_APP_FLAG_ADDRESS /*TODO Need to add address*/

typedef enum
{
    BUS_MODE_ETH = 0x12345678,
    BUS_MODE_CAN = 0x87654321,
}BusmodeType;

extern BL_AppFlagType* BL_AppFlag;

/*  FBL operation memory type */
#define MEMORY_TYPE_NULL              (0x00U)
#define MEMORY_TYPE_RAM               (0xAAU)
#define MEMORY_TYPE_FLASH_BANK_A      (0xBBU) 
#define MEMORY_TYPE_FLASH_BANK_B      (0xCCU) 

/*RAM Address range*/
#define FLASHDRV_START_ADDR           (uint32)(0x7010F000U)
#define FLASHDRV_END_ADDR             (uint32)(0x7010FFFFU)
/*Code Flash A Address range*/
#define FLASH_BANK_A_START_ADDR       (uint32)(0xA0000000)
#define FLASH_BANK_A_END_ADDR         (uint32)(0xA02fffff)
/*Code Flash B Address range*/
#define FLASH_BANK_B_START_ADDR       (uint32)(0xA0300000)
#define FLASH_BANK_B_END_ADDR         (uint32)(0xA05fffff)

extern uint8 Dcm_memoryTypeCheck(uint32 addr, uint32 size);

#endif /* DCM_CALLOUTBOOT_H */

