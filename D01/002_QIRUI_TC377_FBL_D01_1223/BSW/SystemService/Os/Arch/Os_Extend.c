/********************************************************************/
/*  Copyright (C) 2009-2011, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  File         Os_Extened.c
 *  Brief        Extended functions by FAW
 *
 *  Revision History:
 *
 *     V0.1.0  2015-03-23  Initial version, add this file.
 *     V0.2.0  2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *     V1.0.0  2019-11-21  shun.li   Functional safety version.
 */
 /*******************************************************************/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Extend.h"
#include "Os_Internal.h"

/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/********************************************************************/
/*
 * Brief                <Provide Version information to user.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <Versioninfo>
 * Param-Name[out]      <no>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(void, OS_CODE) osGetVersionInfo(Std_VersionInfoType * osVerInfoPtr)
{
    if (NULL_PTR == osVerInfoPtr)
    {
        /*nothing to do*/
    }
    else
    {
        osVerInfoPtr->vendorID = OS_VENDOR_ID;
        osVerInfoPtr->moduleID = OS_MODULE_ID;
        osVerInfoPtr->sw_major_version = OS_CFG_H_SW_MAJOR_VERSION;
        osVerInfoPtr->sw_minor_version = OS_CFG_H_SW_MINOR_VERSION;
        osVerInfoPtr->sw_patch_version = OS_CFG_H_SW_PATCH_VERSION;
    }
}
#if (CHECK_STACK_USAGE > 0)
/********************************************************************/
/*
 * Brief                <Get max usage of system,task,ISR2 stack.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <id>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <osStackUsageType>
 * PreCondition         <None>
 * REQ ID               <DD_1_0707, DD_1_0709, DD_1_0708, DD_1_1323, DD_1_1324, DD_1_1325>
 */
/********************************************************************/
FUNC(osStackUsageType, OS_CODE) osGetStackUsage(osStackObject stack, uint16 id)
{
    osStackUsageType MaxUsage = 0U;
    uint8 const* ptr = NULL_PTR;
    uint8 const* stackBottom = NULL_PTR;
    uint8 const* stackTop = NULL_PTR;
    boolean Status = TRUE;
    OS_ARCH_DECLEAR_CRITICAL();

    id = Os_GetObjLocalId(id);

    switch (stack)
    {
        case OS_STACK_SYSTEM:
        {
            stackBottom = Os_SystemStack->stackBottom;
            stackTop = Os_SystemStack->stackTop;
        }
        break;

        #if (CFG_TASK_MAX > 0U)
        case OS_STACK_TASK:
        {
            /* Input_para check. */
            if (id >= Os_CfgTaskMax)
            {
                Status = FALSE;
            }

            stackBottom = Os_TaskStack[id].stackBottom;
            stackTop = Os_TaskStack[id].stackTop;
        }
        break;
        #endif /* CFG_TASK_MAX > 0U */

        #if (CFG_ISR2_MAX > 0U)
        case OS_STACK_ISR2:
        {
            /* Input_para check. */
            if (id >= Os_CfgIsr2Max)
            {
                Status = FALSE;
            }

            stackBottom = Os_ISR2Stack[id].stackBottom;
            stackTop = Os_ISR2Stack[id].stackTop;
        }
        break;
        #endif /* CFG_ISR2_MAX > 0U */

        /*add comments to pass QAC.*/
        default:
            /* Nothing to do. */
            Status = FALSE;
            break;
    }

    if ((boolean)TRUE == Status)
    {
        OS_ARCH_ENTRY_CRITICAL();

        /*
         * MISRA-C:2004 Rule 17.4
         * Msg(4:0489) The integer value 1 is being added or subtracted from a
         *             pointer.
         */
        /* In stack storage area, all bytes are initialized to magic word(0xCC).
         * if this byte is used, the value will be changed. */
        for (ptr = stackBottom; ptr < stackTop; ptr++)
        {
            if (OS_STACK_FILL_PATTERN != (*ptr))
            {
                break;
            }
        }

        MaxUsage = (osStackUsageType)(stackTop - ptr);

        OS_ARCH_EXIT_CRITICAL();
    }

    return MaxUsage;
}
#endif
/********************************************************************/
/*
 * Brief                <Get max usage of system csa>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <osCsaUsageType>
 * PreCondition         <None>
 * REQ ID               <DD_1_0710, DD_1_0712, DD_1_0711, DD_1_1326>
 */
/********************************************************************/
FUNC(osCsaUsageType, OS_CODE) osGetSystemCsaUsage(void)
{
    uint32 i = 0;
    osCsaUsageType MaxUsage = 0U;

    for (i = 0u; i < Os_CfgCsaMax; i++)
    {
        if (0U != Os_Csas[i].reg[1])
        {
            MaxUsage++;
        }
    }

    return MaxUsage;
}

/********************************************************************/
/*
 * Brief                <check ISR source>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(StatusType, OS_CODE) osCheckISRSource(uint32 Source)
{
    StatusType osRet = FALSE;

    /* OS263. */
    #if ((CFG_ISR2_MAX > 0) && (CFG_SC == OS_SC4))
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        if (OS_ISR_CATEGORY2 == Os_IsrCfg[Os_IntCfgIsrId].OsIsrCatType)
        {
            if (Source == Os_IsrCfg[Os_IntCfgIsrId].OsIsrSrc)
            {
                osRet=TRUE;
            }
        }
    }
    #else
    (void)Source;
    #endif /* (CFG_ISR2_MAX > 0) && (CFG_SC == OS_SC4) */

    return osRet;
}

/********************************************************************/
/*
 * Brief                <check whether CPU information is correct.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(void, OS_CODE) osCheckCPUInformation(void)
{
    uint32 Index = 0u;
    StatusType osRet = TRUE;
    #define    DeviceNumber     10
    uint32 DeviceIDAddress[DeviceNumber] = {
                /*CPU1_CPU_ID,CPU2_CPU_ID,STM0_ID,STM1_ID,STM2_ID*/
                0xF883FE18UL,0xF885FE18UL,0xF0000008UL,0xF0000108UL,0xF0000208UL
                /*FLASH0_ID, INI_ID,    PMU0_ID,  SMU_ID,   LMU_MODID*/
                ,0xF8002008UL,0xF0037008UL,0xF8000508UL,0xF0036808UL,0xF8700808UL
                };
    uint32 DeviceIDValue[DeviceNumber] = {
                0x00C0C012UL,0x00C0C012UL,0x0000C007UL,0x0000C007UL,0x0000C007UL,
                0x00DBC001UL,0x00B9C001UL,0x00DAC001UL,0x0089C001UL,0x0088C002UL
                };

    if (Os_SCB.sysOsLevel != OS_LEVEL_MAIN)
    {
        /*nothing to do*/
    }
    else
    {
        for (Index = 0u; Index < (uint32)DeviceNumber; Index++)
        {
            if (0u == Index)
            {
                /*CPU0_CPU_ID shall be checked*/
                if (OS_ARCH_MFCR(0xFE18u) != 0x00B7C002u)
                {
                    osRet = FALSE;
                    break;
                }
            }

            if (OS_REG32(DeviceIDAddress[Index]) != DeviceIDValue[Index])
            {
                osRet = FALSE;
                break;
            }
        }
        while(osRet == FALSE)
        {
            /*endless loop*/
        }
    }
}

/********************************************************************/
/*
 * Brief                <check whether safety register is correct.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(void, OS_CODE) osCheckSafeTRegister(void)
{
    /* Check whether the safety registers are correct to Guarantee MPU is correct */
    if ((Os_ArchMsrType)0x00000000 != OS_ARCH_MFCR(OS_REG_SYSCON))
    {
        while(1);
    }
    else
    {
        /* nothing to do */
    }
}

#if (CFG_CPU_USAGE_ENABLE == TRUE)
/********************************************************************/
/*
 * Brief                <Get task cpu usage>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(StatusType, OS_CODE) osGetTaskCpuUsage(Os_TaskType taskId, Os_ExcuteUsageTypeRef usage)
{
    return Os_GetTaskCpuUsage(taskId, usage);
}

/********************************************************************/
/*
 * Brief                <Get isr2 cpu usage>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(StatusType, OS_CODE) osGetIsrCpuUsage(Os_IsrType isrId, Os_ExcuteUsageTypeRef usage)
{
    return Os_GetIsrCpuUsage(isrId, usage);
}

/********************************************************************/
/*
 * Brief                <Object start excute>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(void, OS_CODE) osSetObjectStartPoint(void)
{
    Os_SetObjectStartPoint();
}

/********************************************************************/
/*
 * Brief                <Object stop excute>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(void, OS_CODE) osSetObjectStopPoint(void)
{
	Os_SetObjectStopPoint();
}
#endif /* (CFG_CPU_USAGE_ENABLE == TRUE) */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
