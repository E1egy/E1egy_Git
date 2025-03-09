/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-07-05 11:18:43>
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>     <AUTHOR>      <REVISION LOG>
 *   V1.0.0       20141111     bo.zeng      Initial version
 *   V1.1.0       20160418     shi.shu      Add SC34
 *   V2.0.0       20191121     shun.li      Functional safety version
 *   V2.1.0       20200421     shun.li      Add IOC function
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Cfg.h"
#include "Os_CfgData.h"
#include "Os.h"
#include "Os_Processor.h"
#include "Os_Internal.h"

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_CFG_C_AR_MAJOR_VERSION     4U
#define OS_CFG_C_AR_MINOR_VERSION     2U
#define OS_CFG_C_AR_PATCH_VERSION     2U
#define OS_CFG_C_SW_MAJOR_VERSION     1U
#define OS_CFG_C_SW_MINOR_VERSION     0U
#define OS_CFG_C_SW_PATCH_VERSION     0U


/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_CFG_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Major Version"
#endif
#if (OS_CFG_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Minor Version"
#endif
#if (OS_CFG_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Patch Version"
#endif
#if (OS_CFG_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Major Version"
#endif
#if (OS_CFG_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Minor Version"
#endif

/*=======[M A C R O S]========================================================*/
#define  OS_STACK_TOP(stack)    ((Os_StackPtrType)((&(stack)[0]) + (sizeof(stack) / sizeof((stack)[0]))))
#define  OS_STACK_BOTTOM(stack) ((Os_StackPtrType)(stack))

/*=======[I N T E R N A L   D A T A]==========================================*/
/* Ready Queue Manager */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_0[1];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_1[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_2[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_3[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_4[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_5[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_6[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_7[3];
VAR(Os_ReadyQueueType, OS_VAR)  Os_ReadyQueueMark_Core0[CFG_PRIORITY_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_TaskType, OS_CONST, OS_VAR) Os_ReadyQueue_Core0[CFG_PRIORITY_MAX_CORE0] =
{
    Os_ActivateQueue_Core0_0,
    Os_ActivateQueue_Core0_1,
    Os_ActivateQueue_Core0_2,
    Os_ActivateQueue_Core0_3,
    Os_ActivateQueue_Core0_4,
    Os_ActivateQueue_Core0_5,
    Os_ActivateQueue_Core0_6,
    Os_ActivateQueue_Core0_7,
};

CONST(uint32, OS_CONST) Os_ActivateQueueSize_Core0[CFG_PRIORITY_MAX_CORE0] =
{
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_PriorityType, OS_CONST) Os_PrioGroupCore0[CFG_PRIORITY_MAX_CORE0] =
{
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
};

CONST(Os_PriorityType, OS_CONST) Os_PrioMaskCore0[CFG_PRIORITY_MAX_CORE0] =
{
    0x0001,
    0x0002,
    0x0004,
    0x0008,
    0x0010,
    0x0020,
    0x0040,
    0x0080,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* ------------------------stack Management---------------------- */
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysStack_Core0[1024];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_SystemStackCore0 =
{
    OS_STACK_TOP(Os_SysStack_Core0), OS_STACK_BOTTOM(Os_SysStack_Core0)
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_CORE0_100MS_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_CORE0_10MS_Stack[1024];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_CORE0_1MS_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_CORE0_2MS_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_CORE0_5MS_Stack[1024];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_CORE0_INIT_Stack[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_CORE0_NVM_5MS_Stack[1024];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_TaskStack_Idle_Core0[100];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_TaskStackCore0[CFG_TASK_MAX_CORE0] =
{
    {OS_STACK_TOP(Os_OsTask_CORE0_100MS_Stack), OS_STACK_BOTTOM(Os_OsTask_CORE0_100MS_Stack)},
    {OS_STACK_TOP(Os_OsTask_CORE0_10MS_Stack), OS_STACK_BOTTOM(Os_OsTask_CORE0_10MS_Stack)},
    {OS_STACK_TOP(Os_OsTask_CORE0_1MS_Stack), OS_STACK_BOTTOM(Os_OsTask_CORE0_1MS_Stack)},
    {OS_STACK_TOP(Os_OsTask_CORE0_2MS_Stack), OS_STACK_BOTTOM(Os_OsTask_CORE0_2MS_Stack)},
    {OS_STACK_TOP(Os_OsTask_CORE0_5MS_Stack), OS_STACK_BOTTOM(Os_OsTask_CORE0_5MS_Stack)},
    {OS_STACK_TOP(Os_OsTask_CORE0_INIT_Stack), OS_STACK_BOTTOM(Os_OsTask_CORE0_INIT_Stack)},
    {OS_STACK_TOP(Os_OsTask_CORE0_NVM_5MS_Stack), OS_STACK_BOTTOM(Os_OsTask_CORE0_NVM_5MS_Stack)},
    {OS_STACK_TOP(Os_TaskStack_Idle_Core0), OS_STACK_BOTTOM(Os_TaskStack_Idle_Core0)}
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysTimer_Stack_Core0[512];/*system timer*/
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CAN0_INT4_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CAN0_INT5_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CAN0_INT6_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CAN0_INT7_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CAN1_INT0_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CAN1_INT1_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CAN1_INT2_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CAN1_INT3_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_GTM_TOM0_2_Stack_Core0[128];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_GTM_TOM1_0_Stack_Core0[128];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_ISR2StackCore0[CFG_ISR2_MAX_CORE0] =
{
    {OS_STACK_TOP(Os_SysTimer_Stack_Core0), OS_STACK_BOTTOM(Os_SysTimer_Stack_Core0)},/*system timer*/
    {OS_STACK_TOP(Os_CAN0_INT4_Stack_Core0), OS_STACK_BOTTOM(Os_CAN0_INT4_Stack_Core0)},
    {OS_STACK_TOP(Os_CAN0_INT5_Stack_Core0), OS_STACK_BOTTOM(Os_CAN0_INT5_Stack_Core0)},
    {OS_STACK_TOP(Os_CAN0_INT6_Stack_Core0), OS_STACK_BOTTOM(Os_CAN0_INT6_Stack_Core0)},
    {OS_STACK_TOP(Os_CAN0_INT7_Stack_Core0), OS_STACK_BOTTOM(Os_CAN0_INT7_Stack_Core0)},
    {OS_STACK_TOP(Os_CAN1_INT0_Stack_Core0), OS_STACK_BOTTOM(Os_CAN1_INT0_Stack_Core0)},
    {OS_STACK_TOP(Os_CAN1_INT1_Stack_Core0), OS_STACK_BOTTOM(Os_CAN1_INT1_Stack_Core0)},
    {OS_STACK_TOP(Os_CAN1_INT2_Stack_Core0), OS_STACK_BOTTOM(Os_CAN1_INT2_Stack_Core0)},
    {OS_STACK_TOP(Os_CAN1_INT3_Stack_Core0), OS_STACK_BOTTOM(Os_CAN1_INT3_Stack_Core0)},
    {OS_STACK_TOP(Os_GTM_TOM0_2_Stack_Core0), OS_STACK_BOTTOM(Os_GTM_TOM0_2_Stack_Core0)},
    {OS_STACK_TOP(Os_GTM_TOM1_0_Stack_Core0), OS_STACK_BOTTOM(Os_GTM_TOM1_0_Stack_Core0)},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* -------------------------Task Management---------------------- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_TaskCfgType, OS_CONST) Os_TaskCfgCore0[CFG_TASK_MAX_CORE0] =
{
    {
        &Os_TaskEntry_OsTask_CORE0_100MS,       /*osTaskEntry*/
        Os_GetObjLocalId(OsTask_CORE0_100MS),   /*osTaskStackId*/
        1,                              /*osTaskActivation*/
        3,                              /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,             /*osTaskSchedule*/
        0U,                             /*osRsv1*/
        OS_NULL_APPMODE,                /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask_CORE0_10MS,    /*osTaskEntry*/
        Os_GetObjLocalId(OsTask_CORE0_10MS),   /*osTaskStackId*/
        1,                              /*osTaskActivation*/
        4,                              /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,             /*osTaskSchedule*/
        0U,                             /*osRsv1*/
        OS_NULL_APPMODE,                /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask_CORE0_1MS,     /*osTaskEntry*/
        Os_GetObjLocalId(OsTask_CORE0_1MS),   /*osTaskStackId*/
        1,                              /*osTaskActivation*/
        7,                              /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,             /*osTaskSchedule*/
        0U,                             /*osRsv1*/
        OS_NULL_APPMODE,                /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask_CORE0_2MS,     /*osTaskEntry*/
        Os_GetObjLocalId(OsTask_CORE0_2MS),   /*osTaskStackId*/
        1,                              /*osTaskActivation*/
        6,                              /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,             /*osTaskSchedule*/
        0U,                             /*osRsv1*/
        OS_NULL_APPMODE,                /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask_CORE0_5MS,     /*osTaskEntry*/
        Os_GetObjLocalId(OsTask_CORE0_5MS),   /*osTaskStackId*/
        1,                              /*osTaskActivation*/
        5,                              /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,             /*osTaskSchedule*/
        0U,                             /*osRsv1*/
        OS_NULL_APPMODE,                /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask_CORE0_INIT,    /*osTaskEntry*/
        Os_GetObjLocalId(OsTask_CORE0_INIT),   /*osTaskStackId*/
        1,                              /*osTaskActivation*/
        1,                              /*osTaskPriority*/
        OS_PREEMPTIVE_NON,              /*osTaskSchedule*/
        0U,                             /*osRsv1*/
        OSDEFAULTAPPMODE,               /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask_CORE0_NVM_5MS,     /*osTaskEntry*/
        Os_GetObjLocalId(OsTask_CORE0_NVM_5MS),   /*osTaskStackId*/
        1,                              /*osTaskActivation*/
        2,                              /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,             /*osTaskSchedule*/
        0U,                             /*osRsv1*/
        OS_NULL_APPMODE,                /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_IdleCore0,            /*osTaskEntry*/
        Os_GetObjLocalId(OS_TASK_IDLE_CORE0), /*osTaskStackId*/
        1,                                        /*osTaskActivation*/
        0,                                        /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,                       /*osTaskSchedule*/
        0U,                                       /*osRsv1*/
        OS_ALL_APPMODE,                           /*osTaskAutoStartMode*/

    }
};

CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_CORE0_100MS[1] =
{

    0x1U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_CORE0_10MS[1] =
{

    0x1U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_CORE0_1MS[1] =
{

    0x1U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_CORE0_2MS[1] =
{

    0x1U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_CORE0_5MS[1] =
{

    0x1U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_CORE0_INIT[1] =
{

    0x1U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_CORE0_NVM_5MS[1] =
{

    0x1U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OS_TASK_IDLE_CORE0[1] =
{
    0x0000U
};
P2CONST(uint16, OS_VAR, OS_CONST) Os_TaskResourceAccessMaskCore0[CFG_TASK_MAX_CORE0] =
{
    Os_ResourceAccessMask_OsTask_CORE0_100MS,
    Os_ResourceAccessMask_OsTask_CORE0_10MS,
    Os_ResourceAccessMask_OsTask_CORE0_1MS,
    Os_ResourceAccessMask_OsTask_CORE0_2MS,
    Os_ResourceAccessMask_OsTask_CORE0_5MS,
    Os_ResourceAccessMask_OsTask_CORE0_INIT,
    Os_ResourceAccessMask_OsTask_CORE0_NVM_5MS,
    Os_ResourceAccessMask_OS_TASK_IDLE_CORE0,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* ------------------------Counter Management--------------------- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore0[CFG_COUNTER_MAX_CORE0] =
{    {
        65535,    /*osCounterMaxAllowedValue*/
        1,    /*osCounterMinCycle*/
        1,    /*osCounterTicksPerBase*/
        COUNTER_HARDWARE, /*osCounterType*/
        1000, /*osSecondsPerTick*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_ArchSystemTimerCore0(void)
{
    (void)Os_IncrementHardCounter(SystemTimer_Core0);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/* --------------------------Alarm Management---------------------- */
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_CORE0_100MS(void)
{
    (void)ActivateTask(OsTask_CORE0_100MS);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_CORE0_10MS(void)
{
    (void)ActivateTask(OsTask_CORE0_10MS);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_CORE0_1MS(void)
{
    (void)ActivateTask(OsTask_CORE0_1MS);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_CORE0_2MS(void)
{
    (void)ActivateTask(OsTask_CORE0_2MS);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_CORE0_5MS(void)
{
    (void)ActivateTask(OsTask_CORE0_5MS);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_CORE0_NVM_5MS(void)
{
    (void)ActivateTask(OsTask_CORE0_NVM_5MS);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore0[CFG_ALARM_MAX_CORE0] =
{
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,   /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_CORE0_100MS, /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,   /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_CORE0_10MS,  /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,   /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_CORE0_1MS,   /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,   /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_CORE0_2MS,   /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,   /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_CORE0_5MS,   /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,   /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_CORE0_NVM_5MS,   /*osAlarmCallback*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* -------------------------Resource Management------------------ */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_ResourceCfgType, OS_CONST) Os_ResourceCfgCore0[CFG_STD_RESOURCE_MAX_CORE0] =
{

    {
     7U,    /*ceiling*/
     OCCUPIED_BY_TASK,  /*resourceOccupyType*/
     0U,/*rsv1*/
     },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* -----------------------ISR Management-------------------------- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_IsrCfgType, OS_CONST) Os_IsrCfgCore0[CFG_ISR_MAX_CORE0] =
{
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
    },

    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,              /*OsNestedEnable*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,              /*OsNestedEnable*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,              /*OsNestedEnable*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,              /*OsNestedEnable*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        TRUE,               /*OsNestedEnable*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        TRUE,               /*OsNestedEnable*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        TRUE,               /*OsNestedEnable*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        TRUE,               /*OsNestedEnable*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,              /*OsNestedEnable*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        TRUE,               /*OsNestedEnable*/
    },
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_STM0_SR0[1] =
{
    0x1U
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CAN0_INT4[1] =
{

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CAN0_INT5[1] =
{

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CAN0_INT6[1] =
{

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CAN0_INT7[1] =
{

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CAN1_INT0[1] =
{

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CAN1_INT1[1] =
{

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CAN1_INT2[1] =
{

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CAN1_INT3[1] =
{

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_GTM_TOM0_2[1] =
{

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_GTM_TOM1_0[1] =
{

    0x0U,
};
P2CONST(uint16, OS_VAR, OS_CONST) Os_IsrResourceAccessMaskCore0[CFG_ISR2_MAX_CORE0] =
{
    Os_ResourceAccessMask_ISR_STM0_SR0,
    Os_ResourceAccessMask_ISR_CAN0_INT4,
    Os_ResourceAccessMask_ISR_CAN0_INT5,
    Os_ResourceAccessMask_ISR_CAN0_INT6,
    Os_ResourceAccessMask_ISR_CAN0_INT7,
    Os_ResourceAccessMask_ISR_CAN1_INT0,
    Os_ResourceAccessMask_ISR_CAN1_INT1,
    Os_ResourceAccessMask_ISR_CAN1_INT2,
    Os_ResourceAccessMask_ISR_CAN1_INT3,
    Os_ResourceAccessMask_ISR_GTM_TOM0_2,
    Os_ResourceAccessMask_ISR_GTM_TOM1_0,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* -----------------Control block definition--------------------- */
/*
 * Private data,be accessed by own core.
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_TCBType volatile, OS_VAR) Os_TCBCore0[CFG_TASK_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_CCBType volatile, OS_VAR) Os_CCBCore0[CFG_COUNTER_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_ACBType volatile, OS_VAR) Os_ACBCore0[CFG_ALARM_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_RCBType volatile, OS_VAR) Os_RCBCore0[CFG_STD_RESOURCE_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_ICBType volatile,  OS_VAR) Os_ICBCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

/*
 * Private data, be accessed by own core.
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_IsrType,  OS_VAR) Os_SysIsrNestQueueCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

/*
 * Global data, be accessed by all core.
 */
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
Os_CoreCBType volatile              Os_CoreCB;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"

/*
 * Clone data, Each core has a copy.
 */
#define OS_START_SEC_VAR_CLONE_32
#include "Os_MemMap.h"
VAR(Os_SCBType volatile, OS_VAR)    Os_SCB;
#define OS_STOP_SEC_VAR_CLONE_32
#include "Os_MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/

