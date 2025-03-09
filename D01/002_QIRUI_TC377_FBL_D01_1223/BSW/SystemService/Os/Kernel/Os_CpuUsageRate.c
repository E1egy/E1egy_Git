/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2021)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Os_CpuUsageRate.c                                           **
**                                                                            **
**  Created on  : 2021-07-31                                                  **
**  Author      : lizhi.huang                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Calculation CPU usage.                                      **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/


/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"
#if (TRUE == CFG_CPU_USAGE_ENABLE)
/*=======[M A C R O S]========================================================*/


/*=======[T Y P E   D E F I N I T I O N S]====================================*/


/*=======[E X T E R N A L   D A T A]==========================================*/
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(Os_TimeUsageType, AUTOMATIC, OS_VAR)         Os_TaskTimeUsage;
P2VAR(Os_TimeUsageType, AUTOMATIC, OS_VAR)         Os_IsrTimeUsage;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/******************************************************************************/
/*
 * Brief                <Init CPU usage variable.>
 * Service ID
 * Sync/Async           <Synchronous>
 * Reentrancy           <NonReentrant>
 * param-CoreID[in]     <N/A>
 * Param-Status[out]    <N/A>
 * return               <N/A>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InitCpuUsage(void)
{
    int loop = 0;

    for(loop = 0; loop < Os_CfgTaskMax; ++loop)
    {
        Os_TaskTimeUsage[loop].usageRateCurrent = 0;
        Os_TaskTimeUsage[loop].usageRateLastValid = 0;
        Os_TaskTimeUsage[loop].usageRateMin = Os_SysTimerReloadVal;
        Os_TaskTimeUsage[loop].usageRateMax = 0;
        Os_TaskTimeUsage[loop].totalTick = 0;

        Os_TaskTimeUsage[loop].isStart = FALSE;
        Os_TaskTimeUsage[loop].excuteTick = 0;
        Os_TaskTimeUsage[loop].excuteTimeMin = 0xFFFFFFFF;
        Os_TaskTimeUsage[loop].excuteTimeMax = 0;
    }

    for(loop = 0; loop < Os_CfgIsr2Max; ++loop)
    {
        Os_IsrTimeUsage[loop].usageRateCurrent = 0;
        Os_IsrTimeUsage[loop].usageRateLastValid = 0;
        Os_IsrTimeUsage[loop].usageRateMin = Os_SysTimerReloadVal;
        Os_IsrTimeUsage[loop].usageRateMax = 0;
        Os_IsrTimeUsage[loop].totalTick = 0;

        Os_IsrTimeUsage[loop].isStart = FALSE;
        Os_IsrTimeUsage[loop].excuteTick = 0;
        Os_IsrTimeUsage[loop].excuteTimeMin = 0xFFFFFFFF;
        Os_IsrTimeUsage[loop].excuteTimeMax = 0;
    }
}

/******************************************************************************/
/*
 * Brief                <Calc cpu usage by cycle isr.>
 * Service ID
 * Sync/Async           <Synchronous>
 * Reentrancy           <NonReentrant>
 * param-CoreID[in]     <N/A>
 * Param-Status[out]    <N/A>
 * return               <N/A>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_CpuUsageCalc(void)
{
    int loop = 0;

    OS_ARCH_DECLEAR_CRITICAL();
    OS_ARCH_ENTRY_CRITICAL();
    for(loop = 0; loop < Os_CfgTaskMax; ++loop)
    {
        Os_TaskTimeUsage[loop].usageRateCurrent = Os_TaskTimeUsage[loop].totalTick;

        if(TRUE == Os_TaskTimeUsage[loop].isStart)
        {
        	Os_TaskTimeUsage[loop].excuteTick += Os_TaskTimeUsage[loop].totalTick;
        }

        if(Os_TaskTimeUsage[loop].totalTick != 0)
        {
            Os_TaskTimeUsage[loop].usageRateLastValid = Os_TaskTimeUsage[loop].usageRateCurrent;

            if(Os_TaskTimeUsage[loop].usageRateMin > Os_TaskTimeUsage[loop].usageRateCurrent)
            {
                Os_TaskTimeUsage[loop].usageRateMin = Os_TaskTimeUsage[loop].usageRateCurrent;
            }
            if(Os_TaskTimeUsage[loop].usageRateMax < Os_TaskTimeUsage[loop].usageRateCurrent)
            {
                Os_TaskTimeUsage[loop].usageRateMax = Os_TaskTimeUsage[loop].usageRateCurrent;
            }
            Os_TaskTimeUsage[loop].totalTick = 0;
        }
    }

    for(loop = 0; loop < Os_CfgIsr2Max; ++loop)
    {
        Os_IsrTimeUsage[loop].usageRateCurrent = Os_IsrTimeUsage[loop].totalTick;

        if(TRUE == Os_IsrTimeUsage[loop].isStart)
        {
        	Os_IsrTimeUsage[loop].excuteTick += Os_IsrTimeUsage[loop].totalTick;
        }

        if(Os_IsrTimeUsage[loop].totalTick != 0)
        {
            Os_IsrTimeUsage[loop].usageRateLastValid = Os_IsrTimeUsage[loop].usageRateCurrent;
            if(Os_IsrTimeUsage[loop].usageRateMin > Os_IsrTimeUsage[loop].usageRateCurrent)
            {
                Os_IsrTimeUsage[loop].usageRateMin = Os_IsrTimeUsage[loop].usageRateCurrent;
            }
            if(Os_IsrTimeUsage[loop].usageRateMax < Os_IsrTimeUsage[loop].usageRateCurrent)
            {
                Os_IsrTimeUsage[loop].usageRateMax = Os_IsrTimeUsage[loop].usageRateCurrent;
            }
            Os_IsrTimeUsage[loop].totalTick = 0;
        }
    }
    OS_ARCH_EXIT_CRITICAL();
}

/******************************************************************************/
/*
 * Brief                <Start task usage timer.>
 * Service ID
 * Sync/Async           <Synchronous>
 * Reentrancy           <NonReentrant>
 * param-CoreID[in]     <N/A>
 * Param-Status[out]    <N/A>
 * return               <N/A>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_TaskUsageTimerStart(Os_TaskType taskId)
{
    if(taskId < Os_CfgTaskMax)
    {
        Os_TaskTimeUsage[taskId].entryTick = CPU_USARG_TIMER_VALUE(Os_SCB.sysCore);
    }
    else
	{
		/* do nothing */
	}
}

/******************************************************************************/
/*
 * Brief                <Stop task usage timer.>
 * Service ID
 * Sync/Async           <Synchronous>
 * Reentrancy           <NonReentrant>
 * param-CoreID[in]     <N/A>
 * Param-Status[out]    <N/A>
 * return               <N/A>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_TaskUsageTimerStop(Os_TaskType taskId)
{
    Os_TickType tick = CPU_USARG_TIMER_VALUE(Os_SCB.sysCore);
    if(taskId < Os_CfgTaskMax)
    {
        if(tick > Os_TaskTimeUsage[taskId].entryTick)
        {
            Os_TaskTimeUsage[taskId].totalTick += (tick - Os_TaskTimeUsage[taskId].entryTick);
        }
        else
        {
            Os_TaskTimeUsage[taskId].totalTick += (CPU_USARG_TIMER_VALUE_MAX - Os_TaskTimeUsage[taskId].entryTick);
            Os_TaskTimeUsage[taskId].totalTick += tick;
        }
    }
    else
	{
		/* do nothing */
	}
}

/******************************************************************************/
/*
 * Brief                <Start isr2 usage timer.>
 * Service ID
 * Sync/Async           <Synchronous>
 * Reentrancy           <NonReentrant>
 * param-CoreID[in]     <N/A>
 * Param-Status[out]    <N/A>
 * return               <N/A>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_IsrUsageTimerStart(Os_IsrType isrId)
{
    if(isrId < Os_CfgIsr2Max)
    {
        Os_IsrTimeUsage[isrId].entryTick = CPU_USARG_TIMER_VALUE(Os_SCB.sysCore);
    }
    else
	{
		/* do nothing */
	}
}

/******************************************************************************/
/*
 * Brief                <Stop isr2 usage timer.>
 * Service ID
 * Sync/Async           <Synchronous>
 * Reentrancy           <NonReentrant>
 * param-CoreID[in]     <N/A>
 * Param-Status[out]    <N/A>
 * return               <N/A>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_IsrUsageTimerStop(Os_IsrType isrId)
{
    Os_TickType tick = CPU_USARG_TIMER_VALUE(Os_SCB.sysCore);
    if(isrId < Os_CfgIsr2Max)
    {
        if(tick > Os_IsrTimeUsage[isrId].entryTick)
        {
            Os_IsrTimeUsage[isrId].totalTick += (tick - Os_IsrTimeUsage[isrId].entryTick);
        }
        else
        {
            Os_IsrTimeUsage[isrId].totalTick += (CPU_USARG_TIMER_VALUE_MAX - Os_IsrTimeUsage[isrId].entryTick);
            Os_IsrTimeUsage[isrId].totalTick += tick;
        }
    }
    else
    {
    	/* do nothing */
    }
}

/******************************************************************************/
/*
 * Brief                <Get task cpu usage.>
 * Service ID
 * Sync/Async           <Synchronous>
 * Reentrancy           <NonReentrant>
 * param-CoreID[in]     <N/A>
 * Param-Status[out]    <N/A>
 * return               <StatusType>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) Os_GetTaskCpuUsage(Os_TaskType taskId, Os_ExcuteUsageTypeRef usage)
{
    StatusType ret = E_NOT_OK;
    if(taskId < Os_CfgTaskMax && usage != NULL_PTR)
    {
    	usage->us_excuteTimeCurrent = Os_TaskTimeUsage[taskId].excuteTimeCurrent / 100;
        usage->us_excuteTimeMax = Os_TaskTimeUsage[taskId].excuteTimeMax / 100;
        usage->us_excuteTimeMin = Os_TaskTimeUsage[taskId].excuteTimeMin / 100;
        usage->usageRateCurrent = 100 * Os_TaskTimeUsage[taskId].usageRateCurrent / Os_SysTimerReloadVal;
        usage->usageRateLastValid = 100 * Os_TaskTimeUsage[taskId].usageRateLastValid / Os_SysTimerReloadVal;
        usage->usageRateMax = 100 * Os_TaskTimeUsage[taskId].usageRateMax / Os_SysTimerReloadVal;
        usage->usageRateMin = 100 * Os_TaskTimeUsage[taskId].usageRateMin / Os_SysTimerReloadVal;

        ret = E_OK;
    }
    else
	{
		/* do nothing */
	}
    return ret;
}

/******************************************************************************/
/*
 * Brief                <Get isr2 cpu usage.>
 * Service ID
 * Sync/Async           <Synchronous>
 * Reentrancy           <NonReentrant>
 * param-CoreID[in]     <N/A>
 * Param-Status[out]    <N/A>
 * return               <StatusType>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) Os_GetIsrCpuUsage(Os_IsrType isrId, Os_ExcuteUsageTypeRef usage)
{
    StatusType ret = E_NOT_OK;
    if(isrId < Os_CfgIsr2Max && usage != NULL_PTR)
    {
    	usage->us_excuteTimeCurrent = Os_IsrTimeUsage[isrId].excuteTimeCurrent / 100;
        usage->us_excuteTimeMax = Os_IsrTimeUsage[isrId].excuteTimeMax / 100;
        usage->us_excuteTimeMin = Os_IsrTimeUsage[isrId].excuteTimeMin / 100;
        usage->usageRateCurrent = 100 * Os_IsrTimeUsage[isrId].usageRateCurrent / Os_SysTimerReloadVal;
        usage->usageRateLastValid = 100 * Os_IsrTimeUsage[isrId].usageRateLastValid / Os_SysTimerReloadVal;
        usage->usageRateMax = 100 * Os_IsrTimeUsage[isrId].usageRateMax / Os_SysTimerReloadVal;
        usage->usageRateMin = 100 * Os_IsrTimeUsage[isrId].usageRateMin / Os_SysTimerReloadVal;

        ret = E_OK;
    }
    else
	{
		/* do nothing */
	}
    return ret;
}

/******************************************************************************/
/*
 * Brief                <Set object start excute point.>
 * Service ID
 * Sync/Async           <Synchronous>
 * Reentrancy           <NonReentrant>
 * param-CoreID[in]     <N/A>
 * Param-Status[out]    <N/A>
 * return               <StatusType>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_SetObjectStartPoint(void)
{
	OS_ARCH_DECLEAR_CRITICAL();
	OS_ARCH_ENTRY_CRITICAL();
	if(Os_SCB.sysOsLevel == OS_LEVEL_TASK)
	{
		Os_TaskTimeUsage[Os_SCB.sysRunningTaskID].isStart = TRUE;
	}
	else if(Os_SCB.sysOsLevel == OS_LEVEL_ISR2)
	{
		Os_IsrTimeUsage[Os_SCB.sysRunningIsrCat2Id].isStart = TRUE;
	}
	else
	{
		/* do nothing */
	}
	OS_ARCH_EXIT_CRITICAL();
}

/******************************************************************************/
/*
 * Brief                <Set object stop excute point.>
 * Service ID
 * Sync/Async           <Synchronous>
 * Reentrancy           <NonReentrant>
 * param-CoreID[in]     <N/A>
 * Param-Status[out]    <N/A>
 * return               <StatusType>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_SetObjectStopPoint(void)
{
	Os_TickType tick;
	Os_TaskType taskId;
	Os_IsrType isrId;

	OS_ARCH_DECLEAR_CRITICAL();
	OS_ARCH_ENTRY_CRITICAL();

	tick = CPU_USARG_TIMER_VALUE(Os_SCB.sysCore);
	taskId = Os_SCB.sysRunningTaskID;
	isrId = Os_SCB.sysRunningIsrCat2Id;

	if(Os_SCB.sysOsLevel == OS_LEVEL_TASK)
	{
		Os_TaskTimeUsage[taskId].isStart = FALSE;
        if(tick > Os_TaskTimeUsage[taskId].entryTick)
        {
        	Os_TaskTimeUsage[taskId].excuteTick += (tick - Os_TaskTimeUsage[taskId].entryTick);
        }
        else
        {
        	Os_TaskTimeUsage[taskId].excuteTick += (CPU_USARG_TIMER_VALUE_MAX - Os_TaskTimeUsage[taskId].entryTick);
        	Os_TaskTimeUsage[taskId].excuteTick += tick;
        }
        Os_TaskTimeUsage[taskId].excuteTick += Os_TaskTimeUsage[taskId].totalTick;

        Os_TaskTimeUsage[taskId].excuteTimeCurrent = Os_TaskTimeUsage[taskId].excuteTick;
        if(Os_TaskTimeUsage[taskId].excuteTick > Os_TaskTimeUsage[taskId].excuteTimeMax)
        {
        	Os_TaskTimeUsage[taskId].excuteTimeMax = Os_TaskTimeUsage[taskId].excuteTick;
        }
        if(Os_TaskTimeUsage[taskId].excuteTick < Os_TaskTimeUsage[taskId].excuteTimeMin)
		{
			Os_TaskTimeUsage[taskId].excuteTimeMin = Os_TaskTimeUsage[taskId].excuteTick;
		}
        Os_TaskTimeUsage[taskId].excuteTick = 0;
	}
	else if(Os_SCB.sysOsLevel == OS_LEVEL_ISR2)
	{
		Os_IsrTimeUsage[isrId].isStart = FALSE;
		if(tick > Os_IsrTimeUsage[isrId].entryTick)
		{
			Os_IsrTimeUsage[isrId].excuteTick += (tick - Os_IsrTimeUsage[isrId].entryTick);
		}
		else
		{
			Os_IsrTimeUsage[isrId].excuteTick += (CPU_USARG_TIMER_VALUE_MAX - Os_IsrTimeUsage[isrId].entryTick);
			Os_IsrTimeUsage[isrId].excuteTick += tick;
		}
		Os_IsrTimeUsage[taskId].excuteTick += Os_IsrTimeUsage[isrId].totalTick;

		Os_IsrTimeUsage[isrId].excuteTimeCurrent = Os_IsrTimeUsage[isrId].excuteTick;
        if(Os_IsrTimeUsage[isrId].excuteTick > Os_IsrTimeUsage[isrId].excuteTimeMax)
        {
        	Os_IsrTimeUsage[isrId].excuteTimeMax = Os_IsrTimeUsage[isrId].excuteTick;
        }
        if(Os_IsrTimeUsage[isrId].excuteTick < Os_IsrTimeUsage[isrId].excuteTimeMin)
		{
        	Os_IsrTimeUsage[isrId].excuteTimeMin = Os_IsrTimeUsage[isrId].excuteTick;
		}
        Os_IsrTimeUsage[isrId].excuteTick = 0;
	}
	else
	{
		/* do nothing */
	}
	OS_ARCH_EXIT_CRITICAL();
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* #if (TRUE == CFG_CPU_USAGE_ENABLE) */

/*=======[E N D   O F   F I L E]==============================================*/
