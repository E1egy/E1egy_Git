/*!
****************************************************************************************
*
*  Copyright © 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   include_config.h
* \author  BL_zq
* \version 1.0
* \date    2022-05-27
* \btief  The header file of include_config.c
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

#ifndef  INCLUDE_CONFIG_H
#define  INCLUDE_CONFIG_H

/***************************************Includes***************************************/
#include "Platform_Types.h"
#include "PFlashDriver.h"


/***************************************Macros****************************************/
#define ECUSoftwareNumber1          'Q'
#define ECUSoftwareNumber2          'Y'
#define ECUSoftwareNumber3          '1'
#define ECUSoftwareNumber4          '2'
#define ECUSoftwareNumber5          '2'
#define ECUSoftwareNumber6          '3'

#define ECUHardwareNumber1          'V'
#define ECUHardwareNumber2          '0'
#define ECUHardwareNumber3          '3'
#define ECUHardwareNumber4          ' '

#define ASCII_SPACE                 ' '
#define ASCII_ZERO                  0x00

#define ECUSoftwareVersionNumber1   'V'
#define ECUSoftwareVersionNumber2   '3'
#define ECUSoftwareVersionNumber3   '.'
#define ECUSoftwareVersionNumber4   '0'
#define ECUSoftwareVersionNumber5   '.'
#define ECUSoftwareVersionNumber6   '0'

 #define OEMSparePartNumber1        '6'        
 #define OEMSparePartNumber2        '6'
 #define OEMSparePartNumber3        '0'
 #define OEMSparePartNumber4        '0'
 #define OEMSparePartNumber5        '0'        
 #define OEMSparePartNumber6        '4'
 #define OEMSparePartNumber7        '1'
 #define OEMSparePartNumber8        '2'
 #define OEMSparePartNumber9        '4'
 #define OEMSparePartNumber10       '9'

/**APP space:500KB
 * Start address:0xA0032000
 * End address:0xA007D000  
**/
#define APP0_ERASE_PFLASH0_START_ADDRESS        0xA0040000
#define APP0_START_PFLASH0_ADDRESS              0xA0040000
#define APP0_END_PFLASH0_ADDRESS                0xA00A3FFF
#define APP1_2_START_PFLASH1_ADDRESS            0xA00A4000
#define APP1_2_END_PFLASH1_ADDRESS              0xA00F7FFF

#define  FLASH_ADDR_OF_BOOTLOAD_CRCCHECKSUM     (APP1_2_END_PFLASH1_ADDRESS+1)
#define  FLASH_ADDR_OF_BOOTLOAD_CRCCHECKSUM_WR  (FLASH_ADDR_OF_BOOTLOAD_CRCCHECKSUM+PFLASH1_LOGICAL_SECTOR_SIZE)
#define  FLASH_SIZE_FOR_CRCCHECKSUM             (APP1_2_END_PFLASH1_ADDRESS-APP0_START_PFLASH0_ADDRESS+1)
#define  BOOTLOAD_CRCCHECKSUM_LEN               4
#define SINGLE_LOGICAL_SECTOR_SIZE              0x4000

#define EEPROM_ACCESS_CYCLE                     3
#define BOOT_TO_APP_COUNT                       5
#define BOOT_SECURITY_ACCESS_TIMEOUT_COUNT      5

#define PMIC_PWR_DDR              //DDRT_DDRT3
#define PMIC_PWR                  //PTT_PTT3
#define ALARM_LED2_DDR            //DDRP_DDRP3
#define ALARM_LED2                //PTP_PTP3
#define MCU_PWR_EN_DDR            //DDRT_DDRT4
#define MCU_PWR_EN                //PTT_PTT4
#define CAM_PWR_EN_DDR            //DDRT_DDRT5
#define CAM_PWR_EN                //PTT_PTT5
#define DCDC_PWON_DDR             //DRP_DDRP5
#define DCDC_PWON                 //PTP_PTP5  

/***************************************Enum*****************************************/

/***************************************Union****************************************/

/***************************************Struct***************************************/

/***************************************Variables*************************************/

#endif
/*  END OF FILE */
