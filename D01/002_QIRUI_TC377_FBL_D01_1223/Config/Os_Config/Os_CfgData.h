/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_CfgData.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-07-05 11:18:43>
 */
/*============================================================================*/

/*============================================================================*/
#ifndef OS_CFGDATA_H
#define OS_CFGDATA_H

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>     <AUTHOR>    <REVISION LOG>
 *  V1.0.0      20141111    bo.zeng     Initial version
 *  V1.1.0      20160418    shi.shu     Add SC34
 *  V2.0.0      20191121    shun.li     Functional safety version
 *  V2.1.0      20200421    shun.li     Add IOC function
 */

/*=======[I N C L U D E S]====================================================*/
#include "Os_Cfg.h"
#include "Os_Types.h"

/*=======[F I L E  V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_CFGDATA_H_AR_MAJOR_VERSION     4U
#define OS_CFGDATA_H_AR_MINOR_VERSION     2U
#define OS_CFGDATA_H_AR_PATCH_VERSION     2U
#define OS_CFGDATA_H_SW_MAJOR_VERSION     1U
#define OS_CFGDATA_H_SW_MINOR_VERSION     0U
#define OS_CFGDATA_H_SW_PATCH_VERSION     0U

/*=======[M A C R O S]========================================================*/

extern CONSTP2VAR(Os_TaskType, OS_CONST, OS_VAR)    Os_ReadyQueue_Core0[CFG_PRIORITY_MAX_CORE0];
extern CONST(uint32, OS_CONST)                      Os_ActivateQueueSize_Core0[CFG_PRIORITY_MAX_CORE0];
extern VAR(Os_ReadyQueueType, OS_VAR)               Os_ReadyQueueMark_Core0[CFG_PRIORITY_MAX_CORE0];

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
extern CONST(Os_PriorityType, OS_CONST) Os_PrioGroupCore0[CFG_PRIORITY_MAX_CORE0];
extern CONST(Os_PriorityType, OS_CONST) Os_PrioMaskCore0[CFG_PRIORITY_MAX_CORE0];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
extern CONST(Os_StackType, OS_CONST) Os_SystemStackCore0;
extern CONST(Os_StackType, OS_CONST) Os_TaskStackCore0[CFG_TASK_MAX_CORE0];
extern CONST(Os_StackType, OS_CONST) Os_ISR2StackCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
extern CONST(Os_TaskCfgType,  OS_CONST) Os_TaskCfgCore0[CFG_TASK_MAX_CORE0];
extern P2CONST(uint16, OS_VAR, OS_CONST) Os_TaskResourceAccessMaskCore0[CFG_TASK_MAX_CORE0];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
extern CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore0[CFG_COUNTER_MAX_CORE0];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
extern CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore0[CFG_ALARM_MAX_CORE0];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
extern CONST(Os_IsrCfgType, OS_CONST)      Os_IsrCfgCore0[CFG_ISR_MAX_CORE0];
extern P2CONST(uint16, OS_VAR, OS_CONST)   Os_IsrResourceAccessMaskCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
extern CONST(Os_ResourceCfgType, OS_CONST) Os_ResourceCfgCore0[CFG_STD_RESOURCE_MAX_CORE0];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(Os_TCBType volatile, OS_VAR) Os_TCBCore0[CFG_TASK_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(Os_CCBType volatile, OS_VAR) Os_CCBCore0[CFG_COUNTER_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(Os_ACBType volatile, OS_VAR) Os_ACBCore0[CFG_ALARM_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(Os_RCBType volatile, OS_VAR) Os_RCBCore0[CFG_STD_RESOURCE_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(Os_ICBType volatile,  OS_VAR) Os_ICBCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(Os_IsrType,  OS_VAR) Os_SysIsrNestQueueCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE_32
#include "Os_MemMap.h"
extern VAR(Os_SCBType volatile , OS_VAR)    Os_SCB;
#define OS_STOP_SEC_VAR_CLONE_32
#include "Os_MemMap.h"

/* 
 * DeclareTask
 */  
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
DeclareTask(OsTask_CORE0_100MS);
DeclareTask(OsTask_CORE0_10MS);
DeclareTask(OsTask_CORE0_1MS);
DeclareTask(OsTask_CORE0_2MS);
DeclareTask(OsTask_CORE0_5MS);
DeclareTask(OsTask_CORE0_INIT);
DeclareTask(OsTask_CORE0_NVM_5MS);
DeclareTask(TaskIdleCore0);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/* 
 * DeclareISR
 */ 
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
DeclareISR(ISR_CAN0_INT4);
DeclareISR(ISR_CAN0_INT5);
DeclareISR(ISR_CAN0_INT6);
DeclareISR(ISR_CAN0_INT7);
DeclareISR(ISR_CAN1_INT0);
DeclareISR(ISR_CAN1_INT1);
DeclareISR(ISR_CAN1_INT2);
DeclareISR(ISR_CAN1_INT3);
DeclareISR(ISR_GTM_TOM0_2);
DeclareISR(ISR_GTM_TOM1_0);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*
 * Declare IOC Receiver Callback
 */

/* 
 * Declare Os_ArchSystemTimer
 */ 
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
extern FUNC(void, OS_CODE) Os_ArchSystemTimerCore0(void);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*
 * Declare Alarm Callback
 */ 
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*
 * Declare Trusted Function
 */ 

/*
 * Declare Os_App hooks
 */ 

/* the core default execute start address. reference ld. */
extern uint8 _start;

#endif /* #define OS_CFGDATA_H */
/*=======[E N D   O F   F I L E]==============================================*/

