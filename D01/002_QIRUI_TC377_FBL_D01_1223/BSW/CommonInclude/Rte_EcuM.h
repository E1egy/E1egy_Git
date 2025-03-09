/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_EcuM.h>
 *  @brief      <>
 *  
 *  <MCU:TC233>
 *  
 *  @author     <>
 *  @date       <2021-12-24 16:09:13>
 */
/*============================================================================*/

/* Rte_EcuM.h */

#ifndef RTE_ECUM_H
#define RTE_ECUM_H

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
#include "Rte_ModeHandling.h"
#include "BswM_Cfg.h"
#include "BswM_Swc.h"
/*******************************************************************************
 **                        Macro Definitions                                  **
******************************************************************************/

#define RTE_E_EcuM_BootTarget_E_OK 0
#define RTE_E_EcuM_BootTarget_E_NOT_OK 1
#define RTE_E_EcuM_StateRequest_E_OK 0
#define RTE_E_EcuM_StateRequest_E_NOT_OK 1
#define RTE_E_EcuM_Time_E_OK 0
#define RTE_E_EcuM_Time_E_NOT_OK 1
#define RTE_E_EcuM_ShutdownTarget_E_OK 0
#define RTE_E_EcuM_ShutdownTarget_E_NOT_OK 1

/** API mappings */

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/** API functions */

Std_ReturnType Rte_Switch_EcuM_CurrentMode_currentMode(Rte_ModeType_EcuM_Mode mode);

Rte_ModeType_EcuM_Mode Rte_Mode_EcuM_CurrentMode_currentMode(void);

/** runnables */

Std_ReturnType EcuM_ReleasePOST_RUN(EcuM_UserType User);

Std_ReturnType EcuM_ReleaseRUN(EcuM_UserType User);

Std_ReturnType EcuM_RequestPOST_RUN(EcuM_UserType User);

Std_ReturnType EcuM_RequestRUN(EcuM_UserType User);

Std_ReturnType EcuM_GetLastShutdownTarget(EcuM_ShutdownTargetType* shutdownTarget, EcuM_ShutdownModeType* shutdownMode);

Std_ReturnType EcuM_GetShutdownCause(EcuM_ShutdownCauseType* shutdownCause);

Std_ReturnType EcuM_GetShutdownTarget(EcuM_ShutdownTargetType* shutdownTarget, EcuM_ShutdownModeType* shutdownMode);

Std_ReturnType EcuM_SelectShutdownCause(EcuM_ShutdownCauseType shutdownCause);

Std_ReturnType EcuM_SelectShutdownTarget(EcuM_ShutdownTargetType shutdownTarget, EcuM_ShutdownModeType shutdownMode);

/*void EcuM_MainFunction(void);*/

Std_ReturnType EcuM_GetBootTarget(EcuM_BootTargetType* target);

Std_ReturnType EcuM_SelectBootTarget(EcuM_BootTargetType target);

Std_ReturnType EcuM_GetCurrentTime(EcuM_TimeType* time);

Std_ReturnType EcuM_GetWakeupTime(EcuM_TimeType* time);

#define Rte_SwitchAck_EcuM_CurrentMode_currentMode() ((Std_ReturnType) 0)

#endif

