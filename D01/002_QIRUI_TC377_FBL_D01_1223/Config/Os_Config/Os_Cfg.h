/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-07-05 11:18:43>
 */
/*============================================================================*/

/*============================================================================*/
#ifndef OS_CFG_H
#define OS_CFG_H
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>     <AUTHOR>    <REVISION LOG>
 *  V1.0.0      20141111    bo.zeng     Initial version
 *  V1.1.0      20160418    shi.shu     Add SC34
 *  V2.0.0      20170102    shi.shu     Multicore configuration
 *  V3.0.0      20191121    shun.li     Functional safety version
 *  V3.1.0      20200421    shun.li     Add IOC function
 */

/*=======[I N C L U D E S]====================================================*/
#include "Std_Types.h"

/*=======[F I L E  V E R S I O N   I N F O R M A T I O N]===============================*/
#define     OS_CFG_H_AR_MAJOR_VERSION              4U
#define     OS_CFG_H_AR_MINOR_VERSION              2U
#define     OS_CFG_H_AR_PATCH_VERSION              2U
#define     OS_CFG_H_SW_MAJOR_VERSION              1U
#define     OS_CFG_H_SW_MINOR_VERSION              0U
#define     OS_CFG_H_SW_PATCH_VERSION              0U

/*=======[M A C R O S]========================================================*/

/* --------------------Core-------------------- */
/* Core Definition*/
#define     CFG_CORE_MAX                           3U
#define     OS_CORE_ID_MASTER                      ((Os_CoreIdType)0U)
#define     OS_CORE_ID_0                           ((Os_CoreIdType)0U)
#define     OS_NONAUTOSARCORE_ID_0                     ((Os_CoreIdType)1U)
#define     OS_NONAUTOSARCORE_ID_1                     ((Os_CoreIdType)2U)
/* OsNumberOfCores: number of cores that are controlled by the AUTOSAR OS*/
#define     OS_AUTOSAR_CORES                       1U
#define     CFG_CORE0_AUTOSAROS_ENABLE             TRUE
#define     CFG_CORE1_AUTOSAROS_ENABLE             FALSE
#define     CFG_CORE2_AUTOSAROS_ENABLE             FALSE
/* core start address. */
#define     CFG_CORE0_START_ADDRESS                    &_start
#define     CFG_CORE1_START_ADDRESS                    &_start
#define     CFG_CORE2_START_ADDRESS                    &_start
/* --------------------system-------------------- */
/* Scalability Class */
#define     CFG_SC                                  OS_SC1

/* Conformance  Class */
#define     CFG_CC                                  OS_ECC2

/* System Status: stardard, extended */
#define     CFG_STATUS                              OS_STATUS_EXTENDED

/* Scheduling policy: full preemptive, no preemptive, mixed preemptive */
#define     CFG_SCHED_POLICY                        OS_PREEMPTIVE_MIXED

/* App Mode Definition */
#define     DONOTCARE                              ((Os_AppModeType)0x0U)
#define     OSDEFAULTAPPMODE                        ((Os_AppModeType)0x1U)

/* Csa Management */
#define     CFG_CSA_MAX_CORE0                       80U
#define     CFG_CSA_MAX_CORE1                       80U
#define     CFG_CSA_MAX_CORE2                       80U

/* system timer */
#define     CFG_SYSTEM_TIMER_ENABLE               TRUE
#define     CFG_SYSTEM_TIMER_ENABLE_CORE0           TRUE
#define     CFG_SYSTEM_TIMER_ENABLE_CORE1           FALSE
#define     CFG_SYSTEM_TIMER_ENABLE_CORE2           FALSE
/* System timer register value define */
#define     CFG_REG_OSTIMER_VALUE_CORE0             100000U
#define     CFG_REG_OSTIMER_VALUE_CORE1             100000U
#define     CFG_REG_OSTIMER_VALUE_CORE2             100000U

/* Timing Protection */
#define     CFG_TIMING_PROTECTION_ENABLE            FALSE
#define     CFG_TIMING_PROTECTION_ENABLE_CORE0      FALSE
#define     CFG_TIMING_PROTECTION_ENABLE_CORE1      FALSE
#define     CFG_TIMING_PROTECTION_ENABLE_CORE2      FALSE

/* timing protection timer register value */
#define     CFG_REG_TP_TIMER_VALUE_CORE0            10000U
#define     CFG_REG_TP_TIMER_VALUE_CORE1            10000U
#define     CFG_REG_TP_TIMER_VALUE_CORE2            10000U

#define     CFG_SYSTEM_STACK_MAX                    1U

/* wether support trace function */
#define     CFG_TRACE_ENABLE                        FALSE

/* wether check stack overflow */
#define     CFG_STACK_CHECK                         TRUE

#define     CFG_CRITICAL_ZONE_MAX                   1U

/* Hooks */
#define     CFG_ERRORHOOK                           TRUE
#define     CFG_PRETASKHOOK                         FALSE
#define     CFG_POSTTASKHOOK                        FALSE
#define     CFG_STARTUPHOOK                         TRUE
#define     CFG_SHUTDOWNHOOK                        TRUE
#define     CFG_USEGETSERVICEID                     FALSE
#define     CFG_USEPARAMETERACCESS                  FALSE
#define     CFG_PROTECTIONHOOK                      FALSE
#define     CFG_READYTASKHOOK                       FALSE

#define     CFG_APPL_STARTUPHOOK                   FALSE
#define     CFG_APPL_ERRORHOOK                     FALSE
#define     CFG_APPL_SHUTDOWNHOOK                  FALSE

/* --------------------Task Definition-------------------- */
/* number of task and resource priority in system */
#define     CFG_PRIORITY_MAX_CORE0                  8U
/* group of priority */
#define     CFG_PRIORITY_GROUP_CORE0                1U
/* All of the tasks */
#define     CFG_TASK_MAX                           8U
#define     CFG_EXTENDED_TASK_MAX                  0U
/* Core0 */
#define     CFG_TASK_MAX_CORE0                      8U
#define     CFG_EXTENDED_TASK_MAX_CORE0             0U
#define     OsTask_CORE0_100MS                                  ((Os_TaskType)0x0000U)
#define     OsTask_CORE0_10MS                               ((Os_TaskType)0x0001U)
#define     OsTask_CORE0_1MS                                ((Os_TaskType)0x0002U)
#define     OsTask_CORE0_2MS                                ((Os_TaskType)0x0003U)
#define     OsTask_CORE0_5MS                                ((Os_TaskType)0x0004U)
#define     OsTask_CORE0_INIT                               ((Os_TaskType)0x0005U)
#define     OsTask_CORE0_NVM_5MS                                ((Os_TaskType)0x0006U)
#define     OS_TASK_IDLE_CORE0                      ((Os_TaskType)0x0007U)
/* Core1 */
#define     CFG_TASK_MAX_CORE1                      0U
#define     CFG_EXTENDED_TASK_MAX_CORE1             0U
/* Core2 */
#define     CFG_TASK_MAX_CORE2                      0U
#define     CFG_EXTENDED_TASK_MAX_CORE2             0U
/* --------------------ISR Definition-------------------- */
#define     CFG_ISR_MAX                             11U
#define     CFG_ISR2_MAX                            11U
/* wether support interrupt nest */
#define     CFG_INT_NEST_ENABLE                     TRUE
/* highest ISR2 interrupt priority */
#define     CFG_ISR2_IPL_MAX_CORE0                  199U
#define     CFG_ISR2_IPL_MAX_CORE1                  0U
#define     CFG_ISR2_IPL_MAX_CORE2                  0U

/* Core0*/
#define     CFG_ISR_MAX_CORE0                       11U
#define     CFG_ISR2_MAX_CORE0                      11U
#define     CFG_SYS_TIMER_CORE0_ID                  0x0000U       /*system timer*/
#define     CFG_ISR_CAN0_INT4_ID                        0x0001U
#define     CFG_ISR_CAN0_INT5_ID                        0x0002U
#define     CFG_ISR_CAN0_INT6_ID                        0x0003U
#define     CFG_ISR_CAN0_INT7_ID                        0x0004U
#define     CFG_ISR_CAN1_INT0_ID                        0x0005U
#define     CFG_ISR_CAN1_INT1_ID                        0x0006U
#define     CFG_ISR_CAN1_INT2_ID                        0x0007U
#define     CFG_ISR_CAN1_INT3_ID                        0x0008U
#define     CFG_ISR_GTM_TOM0_2_ID                       0x0009U
#define     CFG_ISR_GTM_TOM1_0_ID                       0x000aU
/* Core1*/
#define     CFG_ISR_MAX_CORE1                       0U
#define     CFG_ISR2_MAX_CORE1                      0U
/* Core2*/
#define     CFG_ISR_MAX_CORE2                       0U
#define     CFG_ISR2_MAX_CORE2                      0U
/* --------------------Counter Definition-------------------- */
#define     CFG_COUNTER_MAX                         1U
/* Core0*/
#define     CFG_COUNTER_MAX_CORE0                   1U
#define     SystemTimer_Core0                       ((Os_CounterType)0x0000U)
#define     OS_TICKS2NS_SystemTimer_Core0(ticks)    (ticks*1000*1000)
#define     OS_TICKS2US_SystemTimer_Core0(ticks)    (ticks*1000)
#define     OS_TICKS2MS_SystemTimer_Core0(ticks)    (ticks*1000/1000)
#define     OS_TICKS2SEC_SystemTimer_Core0(ticks)   (ticks*1000/1000000)
#define     OS_NS2TICKS_SystemTimer_Core0(ns)       (ns/1000/1000)
#define     OS_US2TICKS_SystemTimer_Core0(us)       (us/1000)
#define     OS_MS2TICKS_SystemTimer_Core0(ms)       (ms*1000/1000)
#define     OS_SEC2TICKS_SystemTimer_Core0(sec)     (sec*1000000/1000)
/* Core1*/
#define     CFG_COUNTER_MAX_CORE1                   0U
/* Core2*/
#define     CFG_COUNTER_MAX_CORE2                   0U
/* --------------------Alarm Definition-------------------- */
#define     CFG_ALARM_MAX                           6U
#define     CFG_AUTO_ALARM_MAX                      0U
/* Core0*/
#define     CFG_ALARM_MAX_CORE0                     6U
#define     CFG_AUTO_ALARM_MAX_CORE0                0U
#define     OsAlarm_CORE0_100MS                                 ((Os_AlarmType)0x0000U)
#define     OsAlarm_CORE0_10MS                                  ((Os_AlarmType)0x0001U)
#define     OsAlarm_CORE0_1MS                               ((Os_AlarmType)0x0002U)
#define     OsAlarm_CORE0_2MS                               ((Os_AlarmType)0x0003U)
#define     OsAlarm_CORE0_5MS                               ((Os_AlarmType)0x0004U)
#define     OsAlarm_CORE0_NVM_5MS                               ((Os_AlarmType)0x0005U)
/* Core1*/
#define     CFG_ALARM_MAX_CORE1                     0U
#define     CFG_AUTO_ALARM_MAX_CORE1                0U
/* Core2*/
#define     CFG_ALARM_MAX_CORE2                     0U
#define     CFG_AUTO_ALARM_MAX_CORE2                0U
/* --------------------Schedule Table Definition-------------------- */
#define     CFG_SCHEDTBL_MAX                        0U
/* Core0*/
#define     CFG_SCHEDTBL_MAX_CORE0                  0U
/* Core1*/
#define     CFG_SCHEDTBL_MAX_CORE1                  0U
/* Core2*/
#define     CFG_SCHEDTBL_MAX_CORE2                  0U
/* --------------------Event Definition-------------------- */
#define     CFG_EVENT_MAX                           0U
/* -------------------Resource Definition------------------ */
#define     CFG_USERESSCHEDULER                     TRUE
#define     CFG_RESOURCE_MAX                         1U     /* STD + INTERNAL */
#define     CFG_STD_RESOURCE_MAX                    1U
#define     CFG_INTERNAL_RESOURCE_MAX               0U
/* Core0*/
#define     CFG_RESOURCE_MAX_CORE0                  1U     /* STD + INTERNAL */
#define     CFG_STD_RESOURCE_MAX_CORE0              1U
#define     CFG_INTERNAL_RESOURCE_MAX_CORE0         0U
#define     RES_SCHEDULER_CORE0                     ((Os_ResourceType)0x0000U)
/* Core1*/
#define     CFG_RESOURCE_MAX_CORE1                  0U
#define     CFG_STD_RESOURCE_MAX_CORE1              0U
#define     CFG_INTERNAL_RESOURCE_MAX_CORE1         0U
/* Core2*/
#define     CFG_RESOURCE_MAX_CORE2                  0U
#define     CFG_STD_RESOURCE_MAX_CORE2              0U
#define     CFG_INTERNAL_RESOURCE_MAX_CORE2         0U
/* ---------------OsApplication Definition----------------- */
#define     CFG_OSAPPLICATION_MAX                   0U
/* ---------------OsAppEcucPartitionRef-------------------- */
/*Spinlock Definition*/
#define     CFG_SPINLOCK_MAX                       0U

/*  whether shell the os service*/
#define     CFG_SRV_SHELLOS                         FALSE

/* SC34: Memory Protection. */
#define     CFG_MEMORY_PROTECTION_ENABLE            FALSE

/* SC34: Service Protection. */
#define     CFG_SERVICE_PROTECTION_ENABLE           FALSE

#define     CFG_CPU_USAGE_ENABLE                   FALSE

#endif /* #define OS_CFG_H */
/*=======[E N D   O F   F I L E]==============================================*/

