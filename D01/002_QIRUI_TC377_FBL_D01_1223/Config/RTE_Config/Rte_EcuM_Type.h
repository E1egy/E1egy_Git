/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_EcuM_Type.h>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2022-04-08 22:53:22>
 */
/*============================================================================*/

/* Rte_EcuM_Type.h */

#ifndef RTE_ECUM_TYPE_H
#define RTE_ECUM_TYPE_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte_Type.h"

#ifdef __cplusplus
extern "C"{

#endif


#ifndef E_OK
#define E_OK  0U
#endif /*E_OK*/
#ifndef E_NOT_OK
#define E_NOT_OK  1U
#endif /*E_NOT_OK*/


#ifndef ECUM_BOOT_TARGET_APP
#define ECUM_BOOT_TARGET_APP ((EcuM_BootTargetType)0)
#endif /*ECUM_BOOT_TARGET_APP*/
#ifndef ECUM_BOOT_TARGET_OEM_BOOTLOADER
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER ((EcuM_BootTargetType)1)
#endif /*ECUM_BOOT_TARGET_OEM_BOOTLOADER*/
#ifndef ECUM_BOOT_TARGET_SYS_BOOTLOADER
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER ((EcuM_BootTargetType)2)
#endif /*ECUM_BOOT_TARGET_SYS_BOOTLOADER*/


#define _DEFINED_TYPEDEF_FOR_EcuM_BootTargetType_ 

#ifndef ECUM_CAUSE_UNKNOWN
#define ECUM_CAUSE_UNKNOWN ((EcuM_ShutdownCauseType)0)
#endif /*ECUM_CAUSE_UNKNOWN*/
#ifndef ECUM_CAUSE_ECU_STATE
#define ECUM_CAUSE_ECU_STATE ((EcuM_ShutdownCauseType)1)
#endif /*ECUM_CAUSE_ECU_STATE*/
#ifndef ECUM_CAUSE_WDGM
#define ECUM_CAUSE_WDGM ((EcuM_ShutdownCauseType)2)
#endif /*ECUM_CAUSE_WDGM*/
#ifndef ECUM_CAUSE_DCM
#define ECUM_CAUSE_DCM ((EcuM_ShutdownCauseType)3)
#endif /*ECUM_CAUSE_DCM*/


#define _DEFINED_TYPEDEF_FOR_EcuM_ShutdownCauseType_ 



#define _DEFINED_TYPEDEF_FOR_EcuM_ShutdownModeType_ 

#ifndef ECUM_SHUTDOWN_TARGET_SLEEP
#define ECUM_SHUTDOWN_TARGET_SLEEP ((EcuM_ShutdownTargetType)0x0)
#endif /*ECUM_SHUTDOWN_TARGET_SLEEP*/
#ifndef ECUM_SHUTDOWN_TARGET_RESET
#define ECUM_SHUTDOWN_TARGET_RESET ((EcuM_ShutdownTargetType)0x1)
#endif /*ECUM_SHUTDOWN_TARGET_RESET*/
#ifndef ECUM_SHUTDOWN_TARGET_OFF
#define ECUM_SHUTDOWN_TARGET_OFF ((EcuM_ShutdownTargetType)0x2)
#endif /*ECUM_SHUTDOWN_TARGET_OFF*/


#define _DEFINED_TYPEDEF_FOR_EcuM_ShutdownTargetType_ 



#define _DEFINED_TYPEDEF_FOR_EcuM_TimeType_ 

#ifdef __cplusplus
}
#endif




#endif

