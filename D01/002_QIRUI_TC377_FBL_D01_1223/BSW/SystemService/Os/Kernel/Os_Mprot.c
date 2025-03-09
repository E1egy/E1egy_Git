/********************************************************************/
/*  Copyright (C) 2009-2017, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  File       : Os_Mprot.c
 *  Brief      : AutoSar Memory Protection Managment
 *
 *  Revision History:
 *
 *     1. 2016-03-29: 32u; Initial version, add this file.
 *
 */
 /*******************************************************************/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2016-07-08  32           Initial version.
 *  V0.2.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li      Functional safety version.
 */
/*============================================================================*/
/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[M A C R O S]========================================================*/

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
static FUNC(AccessType, OS_CODE) Os_CheckTaskAccess
(
    TaskType TaskID,
    MemoryStartAddressType Address,
    MemorySizeType Size
);

static FUNC(AccessType, OS_CODE) Os_CheckISR2Access
(
    ISRType ISRID,
    MemoryStartAddressType Address,
    MemorySizeType Size
);

/******************************************************************************/
/*
 * Brief                <This function find out the according access right of
 *                       ISR on the assigned memory area>
 * Service ID           <CheckISRMemoryAccess>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-Name[in]       <ISRID>
 *                      <Address>
 *                      <Size>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return value         <AccessType>
 * Caveats              <None>
 * Configuration        <SC3 and SC4>
 * REQ ID               <DD_1_0444, DD_1_1024, DD_1_0447, DD_1_1262, DD_1_1273, DD_1_1583,
 *                       DD_1_0449, DD_1_1607, DD_1_1608, DD_1_1609, DD_1_1664>
 */
/******************************************************************************/
FUNC(AccessType, OS_CODE) CheckISRMemoryAccess
(
    ISRType ISRID,
    MemoryStartAddressType Address,
    MemorySizeType Size
)
{
    AccessType Access = 0u;

    OS_ARCH_DECLEAR_CRITICAL();

    #if (TRUE == CFG_SRV_SHELLOS)
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
    #endif /* TRUE == CFG_SRV_SHELLOS */

    #if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_CHECK_TASK_MEMORY_ACCESS) != TRUE)
    {
        Access = OSMEMORY_SET_NOACCESS(Access);
    }
    else if (Os_IgnoreService() != TRUE)
    {
        Access = OSMEMORY_SET_NOACCESS(Access);
    }
    else
    #endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
        OS_ARCH_ENTRY_CRITICAL();

        if (Os_GetObjCoreId(ISRID) != Os_SCB.sysCore)
        {
            Access = OSMEMORY_SET_NOACCESS(Access);
        }
        else
        {
             /* OS268 */
            if (Os_GetObjLocalId(ISRID) >= Os_CfgIsr2Max)
            {
                #if (TRUE == CFG_ERRORHOOK)
                Os_CallErrorHook(E_OS_ID);
                #endif /* TRUE == CFG_ERRORHOOK */

                Access = OSMEMORY_SET_NOACCESS(Access);
            }
            else
            {
                /*get the access right*/
                Access = Os_CheckISR2Access(ISRID, Address, Size);
            }
        }
        OS_ARCH_EXIT_CRITICAL();
    }
    return Access;
}

/******************************************************************************/
/*
 * Brief                <This function find out the according access right of
 *                      task on the assigned memory area>
 * Service ID           <CheckTaskMemoryAccess>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-Name[in]       <TaskID>
 *                      <Address>
 *                      <Size>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return value         AccessType
 * Caveats              <None>
 * Configuration        <SC3 and SC4>
 * REQ ID               <DD_1_0450, DD_1_1025, DD_1_0453, DD_1_1261, DD_1_1274, DD_1_1584, 
 *                       DD_1_0455, DD_1_1604, DD_1_1605, DD_1_1606, DD_1_1665>
 */
/******************************************************************************/
FUNC(AccessType, OS_CODE) CheckTaskMemoryAccess
(
    TaskType TaskID,
    MemoryStartAddressType Address,
    MemorySizeType Size
)
{
    AccessType Access = 0u;

    OS_ARCH_DECLEAR_CRITICAL();


    #if (TRUE == CFG_SRV_SHELLOS)
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
    #endif /* TRUE == CFG_SRV_SHELLOS */

    #if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_CHECK_TASK_MEMORY_ACCESS) != TRUE)
    {
        Access = OSMEMORY_SET_NOACCESS(Access);
    }
    else if (Os_IgnoreService() != TRUE)
    {
        Access = OSMEMORY_SET_NOACCESS(Access);
    }
    else
    #endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
        OS_ARCH_ENTRY_CRITICAL();

        if (Os_GetObjCoreId(TaskID) != Os_SCB.sysCore)
        {
            Access = OSMEMORY_SET_NOACCESS(Access);
        }
        else
        {
            if (Os_GetObjLocalId(TaskID) >= Os_CfgTaskMax)
            {
                #if (TRUE == CFG_ERRORHOOK)
                Os_CallErrorHook(E_OS_ID);
                #endif /* TRUE == CFG_ERRORHOOK */

                Access = OSMEMORY_SET_NOACCESS(Access);
            }
            else
            {
                /*get the access right*/
                Access = Os_CheckTaskAccess(TaskID, Address, Size);
            }
        }
        OS_ARCH_EXIT_CRITICAL();
    }

    return Access;
}

/******************************************************************************/
/*
 * Brief                <This function find out the checked space whether has
 *                      nothing to do with stack> the checked space is one part
 *                      of the stack  or eaual to the stack or the checked space
 *                      include one whole stack,but not equeal to the stack or
 *                      the checked space cross the stack or the stack and
 *                      checked space are not mixed
 * Service ID           <Os_StackAndCheckedSpace>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-Name[in]       <Address>
 *                      <Size>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return value         Os_StackAndCheckedSpaceStatus
 * Caveats              <None>
 * Configuration        <the address area is on the RAM>
 * CallByAPI            <Os_CheckTaskAccess>
 * REQ ID               <DD_1_0938, DD_1_0939>
 */
/******************************************************************************/
static FUNC(Os_StackAndCheckedSpaceStatus, OS_CODE) Os_StackAndCheckedSpace
(
    const Os_StackType *Stack,
    uint16 StackNumber,
    MemoryStartAddressType Address,
    MemorySizeType Size
)
{
    uint16 i = 0u;
    Os_StackPtrType stackBottom;
    Os_StackPtrType stackTop;
    Os_StackAndCheckedSpaceStatus Status = STACK_NOTMIXED_CHEKEDSPACE;

    /*  if the checked space is the stackspace*/
    for (i = 0u; i < StackNumber; i++)
    {
        /* MISRA-C: 17.4  Array subscripting applied to an object of pointer
         * type. Stack is pointor of static_cfg_array, StackNumber is the size
         * of array, it must be used like below. */
        stackBottom = Stack[i].stackBottom;
        stackTop    = Stack[i].stackTop;
                                             
        if (( Address >= (MemoryStartAddressType)stackBottom)
            && (Address <= (MemoryStartAddressType)stackTop))
        {
            /*the checked space is one part of the stack*/
            /*                         |    checked space     |          */
            /*                  |            stack                  |    */
            if ((Address + Size) <= (MemoryStartAddressType)stackTop)
            {
                Status = STACK_INCLUDE_CHEKEDSPACE;     
                break;
            }
            /*the checked space cross upper the stack*/
            /*                 |    checked space     |                 */
            /*                         |       stack       |            */
            else
            {
                Status = STACK_CROSS_CHEKEDSPACE;
                break;
            }
        }
        else if (Address < (MemoryStartAddressType)stackBottom)
        {
            /*the checked space include one whole stack, but not equeal to
             * the stack*/
            /*                         |    checked space     |         */
            /*                                | stack   |               */
            if ((Address + Size) > (MemoryStartAddressType)stackTop)
            {
                Status = CHEKEDSPACE_INCLUDE_STACK; 
                break;
            }
            /*the checked space cross lower the stack*/
            /*                         |    checked space     |         */
            /*                      |       stack    |                  */
            else  if ((Address + Size) >= (MemoryStartAddressType)stackBottom)
            {
                Status = STACK_CROSS_CHEKEDSPACE;
                break;
            }
            else
            {
                /* Intentionally Empty */
            }
        }
        else
        {
            /* Intentionally Empty */
        }

        /*if the code step to here, the stack and checked space are not mixed            */
        /*                                          |checked space|                    */
        /*                                                                       |stack |   */
        /*                           or                                                                            */
        /*                                          |checked space|                    */
        /*              |stack |                                                            */
        /*exclude the conditions before ,in this condition, should return no
         * access this should be checked at last,because there are lots of
         * stacks need to be check */
        Status = STACK_NOTMIXED_CHEKEDSPACE;       
    }

    return Status;
}

/******************************************************************************/
/*
 * Brief                <This function find out the according access right of
 *                      task on the assigned memory area>
                        <called only by CheckTaskMemoryAccess>
 * Service ID           <Os_CheckTaskAccess>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-Name[in]       <TaskID>
 *                      <Address>
 *                      <Size>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return value         AccessType
 * Caveats              <None>
 * Configuration        <memory protect is on>
 * CallByAPI            <CheckTaskMemoryAccess>
 * REQ ID               <DD_1_0940, DD_1_0941, DD_1_0452, DD_1_1619, DD_1_1620, DD_1_1621,
 *                       DD_1_1622, DD_1_1623, DD_1_1624, DD_1_1625, DD_1_1626>
 */
/******************************************************************************/
static FUNC(AccessType, OS_CODE) Os_CheckTaskAccess
(
    TaskType TaskID,
    MemoryStartAddressType Address,
    MemorySizeType Size
)
{
    /*Indicate the Task belong to which app*/
    StatusType      StackSpaceErr = E_OK;
    uint16          appsuborID = OS_APPLICATION_INVALID;
    boolean         apptrust = FALSE;
    Os_CoreIdType   coreId;
    Os_TaskType     localTaskId;
    AccessType      Access = 0u;
    Os_StackAndCheckedSpaceStatus StackStatus = STACK_NOTMIXED_CHEKEDSPACE;

    /*the access area is on the ram*/   
    if (((Os_MemProtKnAddrCfg.OsKernelAddr.pCPU2DataRamStart <= Address)
            && (Os_MemProtKnAddrCfg.OsKernelAddr.pGlobleRamEnd >= (Address + Size)))
            || ((Os_MemProtKnAddrCfg.OsKernelAddr.pLocalDRamStart <= Address)
            && (Os_MemProtKnAddrCfg.OsKernelAddr.pLocalDRamEnd >= (Address + Size))))
    {

        /*if the checked space is the system stackspace*/
        StackStatus = Os_StackAndCheckedSpace(Os_SystemStack,
                CFG_SYSTEM_STACK_MAX, Address, Size);
        if (STACK_INCLUDE_CHEKEDSPACE == StackStatus)
        {
            Access = OSMEMORY_SET_STACKSPACE(Access);
            StackSpaceErr = E_NOT_OK;
        }
        else if ((CHEKEDSPACE_INCLUDE_STACK == StackStatus)
                || (STACK_CROSS_CHEKEDSPACE == StackStatus))
        {
            Access = OSMEMORY_SET_NOACCESS(Access);
            StackSpaceErr = E_NOT_OK;
        }
        else
        {
            /* nothing to do */
        }
        if ((StatusType)E_OK == StackSpaceErr)
        {
            /*if the checked space is the task stackspace*/
            StackStatus = Os_StackAndCheckedSpace(Os_TaskStack,
                    Os_CfgTaskMax, Address, Size);
            if (STACK_INCLUDE_CHEKEDSPACE == StackStatus)
            {
                Access = OSMEMORY_SET_STACKSPACE(Access);
                StackSpaceErr = E_NOT_OK;
            }
            else if ((CHEKEDSPACE_INCLUDE_STACK == StackStatus)
                    || (STACK_CROSS_CHEKEDSPACE == StackStatus))
            {
                Access = OSMEMORY_SET_NOACCESS(Access);
                StackSpaceErr = E_NOT_OK;
            }
            else
            {
                /* nothing to do */
            }
        }
        if ((StatusType)E_OK == StackSpaceErr)
        {
            /*if the checked space is the ISR stackspace*/
            #if (CFG_ISR2_MAX > 0U)
            StackStatus = Os_StackAndCheckedSpace(Os_ISR2Stack,
                    Os_CfgIsr2Max, Address, Size);
            #endif /* CFG_ISR2_MAX > 0U */

            if (STACK_INCLUDE_CHEKEDSPACE == StackStatus)
            {
                Access = OSMEMORY_SET_STACKSPACE(Access);
                StackSpaceErr = E_NOT_OK;
            }
            else if ((CHEKEDSPACE_INCLUDE_STACK == StackStatus)
                    || (STACK_CROSS_CHEKEDSPACE == StackStatus))
            {
                Access = OSMEMORY_SET_NOACCESS(Access);
                StackSpaceErr = E_NOT_OK;
            }
            else
            {
                /*nothing to do*/
            }
        }

        if ((StatusType)E_OK == StackSpaceErr)
        {
            /*find out which app the isr is belong under,and the app is trusted
             * or not */
            localTaskId = Os_GetObjLocalId(TaskID);
            appsuborID  = (uint16)Os_ObjectAppCfg[OBJECT_TASK][localTaskId].hostApp;
            apptrust    = Os_AppCfg[appsuborID].OsTrusted;

            /*trusted app's Tasks and tasks have both read and write access on the
             * whole ram*/
            if (TRUE == apptrust)
            {
                Access = OSMEMORY_SET_READABLE(Access);
                if (Os_AppCfg[appsuborID].OsTrustedAppWithProtection != TRUE)
                {
                    Access = OSMEMORY_SET_WRITEABLE(Access);
                }
                else
                {
                    /*SWS_Os_00795*/
                    /*write access only for father app's private data and the
                     * Task's data*/
                    if (((Os_AppPriDataAddr[appsuborID].APP_ADDR_START <= Address)
                            && (Os_AppPriDataAddr[appsuborID].APP_ADDR_END >= (Address + Size)))
                            || ((Os_TaskDAddr[localTaskId].Task_ADDR_START <= Address)
                            && (Os_TaskDAddr[localTaskId].Task_ADDR_END >= (Address + Size))))
                    {
                        Access = OSMEMORY_SET_WRITEABLE(Access);
                    }
                }
            }
            /*hand on non-trusted app's Task*/
            else
            {
                coreId = Os_GetCoreLogID(Os_ArchGetCoreID());
                /*read access for all the ram, except for ohter app's data*/
                if (((Os_MemProtKnAddrCfg.OsKernelAddr.pCPU2DataRamStart <= Address)
                        && (Os_Core_App_DAddr[coreId].APP_ADDR_START >= (Address + Size)))
                        || ((Os_Core_App_DAddr[coreId].APP_ADDR_END <= Address)
                        && (Os_MemProtKnAddrCfg.OsKernelAddr.pPeripheralEnd >= (Address + Size)))
                        || ((Os_App_DAddr[appsuborID].APP_ADDR_START <= Address)
                        && (Os_App_DAddr[appsuborID].APP_ADDR_END >= (Address + Size))))
                {
                    Access = OSMEMORY_SET_READABLE(Access);
                }
                /*write access only for father app's private data and the Task's
                 * data*/
                if (((Os_AppPriDataAddr[appsuborID].APP_ADDR_START <= Address)
                        && (Os_AppPriDataAddr[appsuborID].APP_ADDR_END >= (Address + Size)))
                        || ((Os_TaskDAddr[localTaskId].Task_ADDR_START <= Address)
                        && (Os_TaskDAddr[localTaskId].Task_ADDR_END >= (Address + Size))))
                {
                    Access = OSMEMORY_SET_WRITEABLE(Access);
                }
            }
        }
    }
    /*the access area is on the flash*/
    else if ((Os_MemProtKnAddrCfg.OsKernelAddr.pRomStart <= Address)
            && (Os_MemProtKnAddrCfg.OsKernelAddr.pRomEnd >= (Address + Size)))
    {
        /*need to access RoData area,read right*/
        if ((Os_RoData_DAddr.RoData_ADDR_START <= Address)
                && (Os_RoData_DAddr.RoData_ADDR_END >= (Address + Size)))
        {
            Access = OSMEMORY_SET_READABLE(Access);
        }
        /*Rodata is on the right or left side of the checked space*/
        else if ((Os_RoData_DAddr.RoData_ADDR_START >= (Address + Size))
                || (Os_RoData_DAddr.RoData_ADDR_END <= Address))
        {
            Access = OSMEMORY_SET_EXECUTABLE(Access);
        }
        else/* the area cross Rodata and others,do not allow to access*/
        {
            Access = OSMEMORY_SET_NOACCESS(Access);
        }
    }
    else
    {
        Access = OSMEMORY_SET_NOACCESS(Access);
    }

    return Access;
}

/******************************************************************************/
/*
 * Brief                <This function find out the according access right of
 *                      task on the assigned memory area>
                        <called only by CheckISRMemoryAccess>
 * Service ID           <Os_CheckISR2Access>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-Name[in]       <ISRID>
 *                      <Address>
 *                      <Size>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return value         AccessType
 * Caveats              <None>
 * Configuration        <memory protect is on>
 * CallByAPI            <CheckISRMemoryAccess>
 * REQ ID               <DD_1_0942, DD_1_0943, DD_1_1627, DD_1_1628, DD_1_1629, DD_1_1630,
 *                       DD_1_1631, DD_1_1632, DD_1_1633, DD_1_1634>
 */
/******************************************************************************/
static FUNC(AccessType, OS_CODE) Os_CheckISR2Access
(
    ISRType ISRID,
    MemoryStartAddressType Address,
    MemorySizeType Size
)
{
    /*Indicate the ISR belong to which app*/
    uint16 appsuborID = OS_APPLICATION_INVALID;
    StatusType StackSpaceErr = E_OK;
    boolean apptrust = FALSE;
    Os_CoreIdType coreId;
    Os_TaskType localIsrId;
    AccessType Access = 0u;
    Os_StackAndCheckedSpaceStatus StackStatus = STACK_NOTMIXED_CHEKEDSPACE;

    /*the access area is on the ram*/
    if (((Os_MemProtKnAddrCfg.OsKernelAddr.pCPU2DataRamStart <= Address)
            && (Os_MemProtKnAddrCfg.OsKernelAddr.pGlobleRamEnd >= (Address + Size)))
            || ((Os_MemProtKnAddrCfg.OsKernelAddr.pLocalDRamStart <= Address)
            && (Os_MemProtKnAddrCfg.OsKernelAddr.pLocalDRamEnd >= (Address + Size))))
    {
        /*if the checked space is the system stackspace*/
        StackStatus = Os_StackAndCheckedSpace(Os_SystemStack,
                CFG_SYSTEM_STACK_MAX, Address, Size);
        if (StackStatus == STACK_INCLUDE_CHEKEDSPACE)
        {
            Access = OSMEMORY_SET_STACKSPACE(Access);
            StackSpaceErr = E_NOT_OK;
        }
        else if ((StackStatus == CHEKEDSPACE_INCLUDE_STACK)
                || (StackStatus == STACK_CROSS_CHEKEDSPACE))
        {
            Access = OSMEMORY_SET_NOACCESS(Access);
            StackSpaceErr = E_NOT_OK;
        }
        else
        {
            /* nothing to do */
        }
        if ((StatusType)E_OK == StackSpaceErr)
        {
            /*if the checked space is the task stackspace*/
            StackStatus = Os_StackAndCheckedSpace(Os_TaskStack,
                    Os_CfgTaskMax, Address, Size);
            if (StackStatus == STACK_INCLUDE_CHEKEDSPACE)
            {
                Access = OSMEMORY_SET_STACKSPACE(Access);
                StackSpaceErr = E_NOT_OK;
            }
            else if ((StackStatus == CHEKEDSPACE_INCLUDE_STACK)
                    || (StackStatus == STACK_CROSS_CHEKEDSPACE))
            {
                Access = OSMEMORY_SET_NOACCESS(Access);
                StackSpaceErr = E_NOT_OK;
            }
            else
            {
                /* nothing to do */
            }
        }
        if ((StatusType)E_OK == StackSpaceErr)
        {
                /*if the checked space is the ISR stackspace*/
                #if (CFG_ISR2_MAX > 0U)
                StackStatus = Os_StackAndCheckedSpace(Os_ISR2Stack,
                        Os_CfgIsr2Max, Address, Size);
                #endif /* CFG_ISR2_MAX > 0 */
                if (StackStatus == STACK_INCLUDE_CHEKEDSPACE)
                {
                    Access = OSMEMORY_SET_STACKSPACE(Access);
                    StackSpaceErr = E_NOT_OK;
                }
                else if ((StackStatus == CHEKEDSPACE_INCLUDE_STACK)
                        || (StackStatus == STACK_CROSS_CHEKEDSPACE))
                {
                    Access = OSMEMORY_SET_NOACCESS(Access);
                    StackSpaceErr = E_NOT_OK;
                }
                else
                {
                    /*nothing to do*/
                }
        }

        if ((StatusType)E_OK == StackSpaceErr)
        {
            localIsrId = Os_GetObjLocalId(ISRID);
            /*find out which app the isr is belong under,and the app is trusted
             * or not */
            appsuborID = (uint16)Os_ObjectAppCfg[OBJECT_ISR][localIsrId].hostApp;
            apptrust = Os_AppCfg[appsuborID].OsTrusted;

            /*trusted app's ISRs and tasks have both read and write access on the
             *  whole ram*/
            if (TRUE == apptrust)
            {
                Access = OSMEMORY_SET_READABLE(Access);
                if (Os_AppCfg[appsuborID].OsTrustedAppWithProtection != TRUE)
                {
                    Access = OSMEMORY_SET_WRITEABLE(Access);
                }
                else
                {
                    /*SWS_Os_00795*/
                    /*write access only for father app's private data and the Isr's
                     * data*/
                    if (((Os_AppPriDataAddr[appsuborID].APP_ADDR_START <= Address)
                    && (Os_AppPriDataAddr[appsuborID].APP_ADDR_END >= (Address + Size)))
                    || ((Os_IsrDAddr[localIsrId].ISR_ADDR_START <= Address)
                    && (Os_IsrDAddr[localIsrId].ISR_ADDR_END >= (Address + Size))))
                    {
                        Access = OSMEMORY_SET_WRITEABLE(Access);
                    }
                }
            }
            /*hand on non-trusted app's ISR*/
            /*read access for all the ram,write access only for father app's private
             *  data and the ISR's data*/
            else
            {
                coreId = Os_GetCoreLogID(Os_ArchGetCoreID());

                /*read access for all the ram, except for ohter app's data*/
                if (((Os_MemProtKnAddrCfg.OsKernelAddr.pCPU2DataRamStart <= Address)
                && (Os_Core_App_DAddr[coreId].APP_ADDR_START >= (Address + Size)))
                || ((Os_Core_App_DAddr[coreId].APP_ADDR_END <= Address)
                && (Os_MemProtKnAddrCfg.OsKernelAddr.pPeripheralEnd >= (Address + Size)))
                || ((Os_App_DAddr[appsuborID].APP_ADDR_START <= Address)
                && (Os_App_DAddr[appsuborID].APP_ADDR_END >= (Address + Size))))
                {
                    Access = OSMEMORY_SET_READABLE(Access);
                }
                /*write access only for father app's private data and the Task's
                 * data*/
                if (((Os_AppPriDataAddr[appsuborID].APP_ADDR_START <= Address)
                && (Os_AppPriDataAddr[appsuborID].APP_ADDR_END >= (Address + Size)))
                || ((Os_IsrDAddr[localIsrId].ISR_ADDR_START <= Address)
                && (Os_IsrDAddr[localIsrId].ISR_ADDR_END >= (Address + Size))))
                {
                    Access = OSMEMORY_SET_WRITEABLE(Access);
                }
            }
        }
    }
    /*the access area is on the flash*/
    else if ((Os_MemProtKnAddrCfg.OsKernelAddr.pRomStart <= Address)
            && (Os_MemProtKnAddrCfg.OsKernelAddr.pRomEnd >= (Address + Size)))
    {
        /*need to access RoData area,read right*/
        if ((Os_RoData_DAddr.RoData_ADDR_START <= Address)
                && (Os_RoData_DAddr.RoData_ADDR_END >= (Address + Size)))
        {
            Access = OSMEMORY_SET_READABLE(Access);
        }
        /*Rodata is on the right or left side of the checked space*/
        else if ((Os_RoData_DAddr.RoData_ADDR_START >= (Address + Size))
                || (Os_RoData_DAddr.RoData_ADDR_END <= Address))
        {
            Access = OSMEMORY_SET_EXECUTABLE(Access);
        }
        else/* the area cross Rodata and others,do not allow to access*/
        {
            Access = OSMEMORY_SET_NOACCESS(Access);
        }
    }
    else
    {
        Access = OSMEMORY_SET_NOACCESS(Access);
    }

    return Access;
}

/********************************************************************/
/*
 * Brief                <Init function by memory protection>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0846, DD_1_0847>
 */            
/********************************************************************/
FUNC(void, OS_CODE) Os_InitMemProt(void)
{
    /* Set memory protection map for os_kernel. */
    Os_ArchInitKnMemMap();

    return;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (TRUE == CFG_MEMORY_PROTECTION_ENABLE) */
