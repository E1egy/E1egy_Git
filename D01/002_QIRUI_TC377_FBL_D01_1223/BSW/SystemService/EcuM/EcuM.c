/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : EcuM.c                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Implement code for ECUM stats and RUN/POST_RUN arbitrate    **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-06-28  qinchun.yang    R19_11 EcuM initial version.
 *  V2.0.0       2021-04-08  qinchun.yang    R1911 stable version.
 *  V2.1.0       2021-11-25  qinchun.yang    Modify EcuM mode handle function.
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM_Internal.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#if (ECUM_MODE_HANDING == STD_ON)
#define ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "EcuM_MemMap.h"
/* Current Rte State to notify during MainFunction */
VAR(Rte_ModeType_EcuM_Mode, ECUM_CLEARED) EcuM_RteState;
#define ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "EcuM_MemMap.h"
#endif
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
#define ECUM_START_SEC_VAR_INIT_BOOLEAN
#include "EcuM_MemMap.h"
VAR(boolean, ECUM_CLEARED) EcuM_IsInit = FALSE;
#define ECUM_STOP_SEC_VAR_INIT_BOOLEAN
#include "EcuM_MemMap.h"
#endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */

#define ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "EcuM_MemMap.h"
VAR(EcuM_RunTimeType, ECUM_CLEARED) EcuMRunData;
#define ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "EcuM_MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"
#if (ECUM_VERSION_INFO_API == STD_ON)
/**
 * Returns the version information of this module.
 * Service ID: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): NA
 * Parameters(INOUT): NA
 * Parameters(OUT): versioninfo, Pointer to where to store the version
 *                               information of this module.
 * Return value: NA
 */
FUNC(void, ECUM_CODE) EcuM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) versioninfo
)
{
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_GETVERSION, ECUM_E_NULL_POINTER);
    }
    else
#endif /*(ECUM_DEV_ERROR_DETECT == STD_ON)*/
    {
        versioninfo->moduleID = ECUM_MODULE_ID;
        versioninfo->vendorID = ECUM_VENDOR_ID;
        versioninfo->instanceID = ECUM_INSTANCE_ID;
        versioninfo->sw_major_version = ECUM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = ECUM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = ECUM_SW_PATCH_VERSION;
    }
}
#endif /*(ECUM_VERSION_INFO_API == STD_ON)*/

/**
 * Function called by BswM to notify about State Switch.
 * Service ID[hex]: 0x2b
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): state, State indicated by BswM.
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, ECUM_CODE) EcuM_SetState
(
    EcuM_StateType state
)
{
#if (ECUM_MODE_HANDING == STD_ON)
    Rte_ModeType_EcuM_Mode mode;
#endif
    boolean errFlag = FALSE;

    #if (ECUM_DEV_ERROR_DETECT == STD_ON)
    /* Init Check */
    if ((boolean)FALSE == EcuM_IsInit)
    {
        (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_SETSTATE, ECUM_E_UNINIT);
    }
    else if ((state != ECUM_STATE_STARTUP) && (state != ECUM_STATE_APP_RUN) && (state != ECUM_STATE_APP_POST_RUN)
            && (state != ECUM_STATE_SHUTDOWN) && (state != ECUM_STATE_SLEEP))
    {
        (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_SETSTATE, ECUM_E_STATE_PAR_OUT_OF_RANGE);
    }
    else
    #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
    {
    #if (ECUM_MODE_HANDING == STD_ON)
        switch (state)
        {
            case ECUM_STATE_STARTUP:
                mode = RTE_MODE_EcuM_Mode_STARTUP;
                break;

            case ECUM_STATE_APP_RUN:
                mode = RTE_MODE_EcuM_Mode_RUN;
                break;

            case ECUM_STATE_APP_POST_RUN:
                mode = RTE_MODE_EcuM_Mode_POST_RUN;
                break;

            case ECUM_STATE_SHUTDOWN:
                /*Same with sleep.*/
            case ECUM_STATE_SLEEP:
                if(EcuMRunData.SdtgNext.Target
                        == ECUM_SHUTDOWN_TARGET_SLEEP)
                {
                    mode = RTE_MODE_EcuM_Mode_SLEEP;
                }
                else
                {
                    mode = RTE_MODE_EcuM_Mode_SHUTDOWN;
                }
                break;

            default:
                errFlag = TRUE;
        }
    #endif/*(ECUM_MODE_HANDING == STD_ON)*/

        if ((boolean)errFlag == FALSE)
        {
        #if (ECUM_MODE_HANDING == STD_ON)
            EcuM_RteState = mode;
        #endif
            EcuMRunData.rqstState = state;
        }
    }
}

#if (STD_ON == ECUM_MODE_HANDING)
/**
 * Places a request for the RUN state. Requests can be placed by every user
 * made known to the state manager at configuration time.
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): user, ID of the entity requesting the RUN state
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: E_OK: The request was accepted by EcuM.
 *               E_NOT_OK: The request was not accepted by EcuM, a detailed error
 *               condition was sent to DET (see Error Codes).
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestRUN
(
    EcuM_UserType user
)
{
    uint8 uid;
    Std_ReturnType ret = E_OK;
    P2VAR(EcuM_RunTimeType, AUTOMATIC, ECUM_VAR)pRt = &EcuMRunData;

    #if (ECUM_DEV_ERROR_DETECT == STD_ON)
    /* Init Check */
    if (FALSE == EcuM_IsInit)
    {
        Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_REQUESTRUN, ECUM_E_UNINIT);
        ret = E_NOT_OK;
    }
    else
    #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
    {
        ret = EcuM_SearchUserByCaller(user, &uid);

        if (E_OK == ret)
        {
            if (FALSE == pRt->Users.IsRun[uid])
            {
                pRt->Users.IsRun[uid] = TRUE;
                if (pRt->Users.RunNum == 0)
                {
                    BswM_EcuM_RequestedState(ECUM_STATE_APP_RUN, ECUM_RUNSTATUS_REQUESTED);
                }
                pRt->Users.RunNum = pRt->Users.RunNum + 1u;
            }
            #if (ECUM_DEV_ERROR_DETECT == STD_ON)
            else
            {

                Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_REQUESTRUN, ECUM_E_MULTIPLE_RUN_REQUESTS);
                ret = E_NOT_OK;
            }
            #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */

        }
        #if (ECUM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_REQUESTRUN, ECUM_E_INVALID_PAR);
            ret = E_NOT_OK;
        }
        #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
    }

    return ret;
}

/**
 * Releases a RUN request previously done with a call to EcuM_RequestRUN.
 * The service is intended for implementing AUTOSAR ports.
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): user, ID of the entity releasing the RUN state
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: E_OK: The request was accepted by EcuM.
 *               E_NOT_OK: The request was not accepted by EcuM, a detailed error
 *               condition was sent to DET (see Error Codes).
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleaseRUN
(
    EcuM_UserType user
)
{
    uint8 uid;
    Std_ReturnType ret = E_OK;
    P2VAR(EcuM_RunTimeType, AUTOMATIC, ECUM_VAR)pRt = &EcuMRunData;

    #if (ECUM_DEV_ERROR_DETECT == STD_ON)
    /* Init Check */
    if (FALSE == EcuM_IsInit)
    {
        Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_RELEASERUN, ECUM_E_UNINIT);
        ret = E_NOT_OK;
    }
    else
    #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
    {
        ret = EcuM_SearchUserByCaller(user, &uid);

        if (E_OK == ret)
        {
            if (TRUE == pRt->Users.IsRun[uid])
            {
                pRt->Users.IsRun[uid] = FALSE;
                pRt->Users.RunNum = pRt->Users.RunNum - 1u;
                if (pRt->Users.RunNum == 0)
                {
                    BswM_EcuM_RequestedState(ECUM_STATE_APP_RUN, ECUM_RUNSTATUS_RELEASED);
                }
            }
            #if (ECUM_DEV_ERROR_DETECT == STD_ON)
            else
            {
                Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_RELEASERUN, ECUM_E_MISMATCHED_RUN_RELEASE);
                ret = E_NOT_OK;
            }
            #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
        }
        #if (ECUM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_RELEASERUN, ECUM_E_INVALID_PAR);
            ret = E_NOT_OK;
        }
        #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
    }
    return ret;
}

/**
 * Places a request for the POST RUN state. Requests can be placed by every user
 * made known to the state manager at configuration time. Requests for RUN and
 * POST RUN must be tracked independently (in other words: two independent
 *  variables). The service is intended for implementing AUTOSAR ports.
 * Service ID[hex]: 0x0a
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): user, ID of the entity requesting the POST RUN state
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: E_OK: The request was accepted by EcuM
 *               E_NOT_OK: The request was not accepted by EcuM, a detailed
 *                         error condition was sent to DET (see Error Codes).
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestPOST_RUN
(
    EcuM_UserType user
)
{
       uint8 uid;
        Std_ReturnType ret = E_OK;
        P2VAR(EcuM_RunTimeType, AUTOMATIC, ECUM_VAR)pRt = &EcuMRunData;

        #if (ECUM_DEV_ERROR_DETECT == STD_ON)
        /* Init Check */
        if (FALSE == EcuM_IsInit)
        {
            Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_REQUESTPOST_RUN, ECUM_E_UNINIT);
            ret = E_NOT_OK;
        }
        else
        #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
        {
            ret = EcuM_SearchUserByCaller(user, &uid);

            if (E_OK == ret)
            {
                if (FALSE == pRt->Users.IsPostRun[uid])
                {
                    pRt->Users.IsPostRun[uid] = TRUE;
                    if (pRt->Users.PostRunNum == 0)
                    {
                        BswM_EcuM_RequestedState(ECUM_STATE_APP_POST_RUN, ECUM_RUNSTATUS_REQUESTED);
                    }
                    pRt->Users.PostRunNum = pRt->Users.PostRunNum + 1u;
                }
                #if (ECUM_DEV_ERROR_DETECT == STD_ON)
                else
                {

                    Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_REQUESTPOST_RUN, ECUM_E_MULTIPLE_RUN_REQUESTS);
                    ret = E_NOT_OK;
                }
                #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
            }
            #if (ECUM_DEV_ERROR_DETECT == STD_ON)
            else
            {
                Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_REQUESTPOST_RUN, ECUM_E_INVALID_PAR);
                return E_NOT_OK;
            }
            #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
        }
        return ret;
}

/**
 * Releases a POST RUN request previously done with a call to EcuM_RequestPOST_RUN.
 * The service is intended for implementing AUTOSAR ports.
 * Service ID[hex]: 0x0b
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): user, ID of the entity releasing the POST RUN state
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: E_OK: The release request was accepted by EcuM
 *               E_NOT_OK: The release request was not accepted by EcuM,
 *                         a detailed error condition was sent to DET (see Error Codes).
 */
FUNC(Std_ReturnType, ECUM_COE) EcuM_ReleasePOST_RUN
(
    EcuM_UserType user
)
{
    uint8 uid;
    Std_ReturnType ret = E_OK;
    P2VAR(EcuM_RunTimeType, AUTOMATIC, ECUM_VAR)pRt = &EcuMRunData;

    #if (ECUM_DEV_ERROR_DETECT == STD_ON)
    /* Init Check */
    if (FALSE == EcuM_IsInit)
    {
        Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_RELEASEPOST_RUN, ECUM_E_UNINIT);
        ret = E_NOT_OK;
    }
    else
    #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
    {
        ret = EcuM_SearchUserByCaller(user, &uid);

        if (E_OK == ret)
        {
            if (TRUE == pRt->Users.IsPostRun[uid])
            {
                pRt->Users.IsPostRun[uid] = FALSE;
                pRt->Users.PostRunNum = pRt->Users.PostRunNum - 1u;
                if (pRt->Users.PostRunNum == 0)
                {
                    BswM_EcuM_RequestedState(ECUM_STATE_APP_POST_RUN, ECUM_RUNSTATUS_RELEASED);
                }
            }
            #if (ECUM_DEV_ERROR_DETECT == STD_ON)
            else
            {
                Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_RELEASEPOST_RUN, ECUM_E_MISMATCHED_RUN_RELEASE);
                ret = E_NOT_OK;
            }
            #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
        }
        #if (ECUM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_RELEASEPOST_RUN, ECUM_E_INVALID_PAR);
            ret = E_NOT_OK;
        }
        #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
    }
    return ret;
}
#endif /*(STD_ON == ECUM_MODE_HANDING)*/

/**
 * Selects a boot target.
 * EcuM_SelectBootTarget is part of the ECU Manager Module port interface.
 * Service ID[hex]: 0x12
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): target, the selected boot target.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: E_OK: The new boot target was accepted by EcuM
 *               E_NOT_OK: The new boot target was not accepted by EcuM
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectBootTarget
(
    EcuM_BootTargetType target
)
{
    Std_ReturnType ret = E_OK;

    #if (ECUM_DEV_ERROR_DETECT == STD_ON)
    /* Init Check */
    if ((boolean)FALSE == EcuM_IsInit)
    {
        (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_SELECTBOOTTARGET, ECUM_E_UNINIT);
        ret = E_NOT_OK;
    }
    else if((ECUM_BOOT_TARGET_APP != target) &&
            (ECUM_BOOT_TARGET_OEM_BOOTLOADER != target) &&
            (ECUM_BOOT_TARGET_SYS_BOOTLOADER != target))
    {
         (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_SELECTBOOTTARGET, ECUM_E_INVALID_PAR);
        ret = E_NOT_OK;
    }
    else
    #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
    {
        /*EcuM2247 EcuM2835 */
        /*The implementer must ensure that the boot target information is placed at a safe location
          which then can be evaluated by the boot manager after a reset. */
        EcuMRunData.BootTarget = target;
    }

    return ret;
}

/**
 * Returns the current boot target.
 * EcuM_GetBootTarget is part of the ECU Manager Module port interface.
 * Service ID[hex]: 0x13
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  target, the currently selected boot target.
 * Return value: E_OK: The service always succeeds.
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetBootTarget
(
    P2VAR(EcuM_BootTargetType, AUTOMATIC, ECUM_APPL_DATA) target
)
{
       Std_ReturnType ret = E_OK;

        #if (ECUM_DEV_ERROR_DETECT == STD_ON)
        /* Init Check */
        if ((boolean)FALSE == EcuM_IsInit)
        {
            (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_GETBOOTTARGET, ECUM_E_UNINIT);
            ret = E_NOT_OK;
        }
        else if (NULL_PTR == target)
        {
            (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_GETBOOTTARGET, ECUM_E_NULL_POINTER);
            ret = E_NOT_OK;
        }
        else
        #endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
        {
            *target = EcuMRunData.BootTarget;
        }

        return ret;
}

#if (ECUM_MAX_MCU_CORE_NUM > 1)
/*Get slave core index in configuration*/
FUNC(uint8, ECUM_CODE)
EcuM_GetSlaveCoreIndex(
    CoreIdType coreId
)
{
    uint8 coreIdx = ECUM_MAX_MCU_CORE_NUM;
    uint8 index;

    for (index = 0; index < ECUM_MAX_MCU_CORE_NUM - 1; index++)
    {
        if (EcuM_SlaveCoreIds[index] == coreId)
        {
            coreIdx = index;
            break;
        }
    }

    return coreIdx;
}
#endif /*(ECUM_MAX_MCU_CORE_NUM > 1)*/

/*Query the corresponding configured user id*/
FUNC(Std_ReturnType, ECUM_CODE)
EcuM_SearchUserByCaller(
    uint16 caller, uint8* userIndex
)
{
    uint8 index;
    boolean flag = FALSE;
    Std_ReturnType ret;

    for (index = 0; index < (uint8)ECUM_MAX_USER_NUM; index++)
    {
        if ((uint16)EcuM_UserCfgs[index].usrId == caller)
        {
            flag = TRUE;
            break;
        }
    }
    if ((boolean)TRUE == flag)
    {
        *userIndex = index;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
}
#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

