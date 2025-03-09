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
**  FILENAME    : BswM.c                                                      **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-03-24  qinchun.yang    R19_11 BswM initial version.
 *  V2.0.0       2021-04-08  qinchun.yang    R1911 stable version.
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Internal.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"
/*Initialize event request port*/
static FUNC(void, BSWM_CODE)
BswM_InitEventRequestPort(
    void
);

/*Initialize event request port*/
static FUNC(void, BSWM_CODE)
BswM_InitModeRequestPort(
    void
);

/*Initialize rules*/
static FUNC(void, BSWM_CODE)
BswM_InitRules(
    void
);

/*Execute specific the action list in the specific partition*/
static FUNC(void, BSWM_CODE)
BswM_DoActionList
(
    ApplicationType partIdx,
    BswM_ActionListIndexType actionListIdx
);

/*Do the specific action job of specific type in specific partition*/
static FUNC(Std_ReturnType, BSWM_CODE)
BswM_DoAction
(
    ApplicationType partIdx,
    BswM_ActionEnumType actionType,
    uint8 actionIdx
);
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
/*runtime status information of BSWM partition on this local core. If it is
 * mulit-core ECU, every CORE running BSW will have a core-specific status*/
volatile VAR(BswM_RuntimeStatusType, BSWM_CLEARED) BswM_RuntimeStatus;
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"
/**
 * Initializes the BSW Mode Manager.
 * Service ID: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Conditionally Reentrant
 * Parameters(IN): ConfigPtr, Pointer to post-build configuration data
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_CODE)
BswM_Init(
    P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_DATA) ConfigPtr
)
{
#if (BSWM_MAX_NUM_CORE > 1u)
    CoreIdType coreId;
    uint8 coreIdx;
#endif /*(BSWM_MAX_NUM_CORE > 1u)*/

    (void)ConfigPtr;
#if (BSWM_MAX_NUM_CORE > 1u)
    coreId = GetCoreID();
    for (coreIdx = 0u; coreIdx < BSWM_MAX_NUM_CORE; coreIdx++)
    {
        if (BswM_CorePCCfg[coreIdx].bswmCoreId == coreId)
        {
            BswM_RuntimeStatus.numOfPartitions = BswM_CorePCCfg[coreIdx].numOfPartitions;
            BswM_RuntimeStatus.bswmPartPCCfgs = BswM_CorePCCfg[coreIdx].bswmPartPCCfgs;
            BswM_RuntimeStatus.bswmPartLCfgs = BswM_CoreLinkCfg[coreIdx].bswmPartLCfgs;
            break;
        }
    }
#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    if (BSWM_MAX_NUM_CORE == coreIdx)
    {
        /*no configure for this core, configure data error*/
        (void)Det_ReportError(BSWM_MODULE_ID, BSWM_INSTANCE_ID, BSWM_API_ID_INIT, BSWM_E_INIT_FAILED);
    }
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
#else /*(BSWM_MAX_NUM_CORE == 1u)*/
    BswM_RuntimeStatus.numOfPartitions = BswM_CorePCCfg->numOfPartitions;
    BswM_RuntimeStatus.bswmPartPCCfgs = BswM_CorePCCfg->bswmPartPCCfgs;
    BswM_RuntimeStatus.bswmPartLCfgs = BswM_CoreLinkCfg->bswmPartLCfgs;
#endif /*(BSWM_MAX_NUM_CORE > 1u)*/
    BswM_InitRules();
    BswM_InitEventRequestPort();
    BswM_InitModeRequestPort();
    BswM_RuntimeStatus.bswmInitState = BSWM_INITED;
}

/**
 * Main function of the BswM.
 * Shall perform evaluation of all rules that uses at least one mode request with
 * configuration parameter BswMRequestProcessing set to BSWM_DEFERRED as input.
 * Service ID: 0x03
 * Parameters(IN): NA
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_CODE)
BswM_MainFunction(
    void
)
{
#if (BSWM_TIMER_ENABLED == STD_ON)
    P2CONST(BswM_ModeRqstPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) modeRunRqstPtr;
    BswM_TimerIdxType timerNum;
    BswM_TimerIdxType timerIdx;
#endif /*(BSWM_TIMER_ENABLED == STD_ON)*/
    BswM_RuleIndexType defRuleNum;
    BswM_RuleIndexType defIdx;
    BswM_RuleIndexType ruleIdx;
    ApplicationType partIdx;
    boolean result;

    if (BSWM_INITED == BswM_RuntimeStatus.bswmInitState)
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            /*1.Perform evaluation of all deferred rules.*/
            defRuleNum = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].numOfDefRules;
            for (ruleIdx = 0u; ruleIdx < defRuleNum; ruleIdx++)
            {
                defIdx = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].defRuleRefLCfg[ruleIdx];
                BswM_ArbitrateRule(defIdx, partIdx);
            }
            /*2.Handle BSWM timer.*/
        #if (BSWM_TIMER_ENABLED == STD_ON)
            timerNum = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg->numOfBswMTimer;
            modeRunRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
            for (timerIdx = 0u; timerIdx < timerNum; timerIdx++)
            {
                if ((BSWM_TIMER_START== modeRunRqstPtr->timerStatus[timerIdx])
                        && (modeRunRqstPtr->timerCycle[timerIdx] > 0u))
                {
                    modeRunRqstPtr->timerCycle[timerIdx]--;
                    if (0u == modeRunRqstPtr->timerCycle[timerIdx])
                    {
                        modeRunRqstPtr->timerStatus[timerIdx] = BSWM_TIMER_EXPIRED;
                    }
                }
            }
        #endif /*(BSWM_TIMER_ENABLED == STD_ON)*/
        }
    }
}

/**
 * Deinitializes the BSW Mode Manager.
 * After a call of BswM_Deinit no mode processing shall be performed by BswM
 * even if any mode requests are made or the BswM main function is called.
 * Service ID: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters(IN): NA
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_CODE) BswM_Deinit
(
    void
)
{
    BswM_RuntimeStatus.bswmInitState = BSWM_UNINITED;
}

#if (BSWM_GENERIC_REQUEST_ENABLED == STD_ON)
/**
 * Generic function call to request modes. This function shall only be used by
 * other BSW modules that does not have a specific mode request interface.
 * Service ID: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): requesting_user, The user that requests the mode
 *                 requested_mode, The requested mode
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_CODE)
BswM_RequestMode
(
    BswM_UserType requestingUser,
    uint16 requestedMode
)
{
    P2CONST(BswM_ModeRqstPortPCCfgType, AUTOMATIC, BSWM_CONST) modeRqstPCfgPtr;
    P2CONST(BswM_ModeRqstPortLCfgType, AUTOMATIC, BSWM_CONST) modeRqstLCfgPtr;
    P2CONST(BswM_ModeRqstPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) modeRqstPtr;
    P2CONST(BswM_RuleLcCfgType, AUTOMATIC, BSWM_CONST) ruleLCfgPtr;
    BswM_RuleIndexType numOfRules;
    BswM_RuleIndexType idx;
    BswM_RuleIndexType ruleIdx;
    ApplicationType partIdx;
    boolean result;
    BswM_UserType numOfGenericReq;
    BswM_UserType userIdx;

#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    /*Don't check requestedMode*/
    if ((Std_ReturnType)E_OK == BswM_DetChkGenericRqst(requestingUser))
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            modeRqstPCfgPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg;
            modeRqstLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].modeRqstLCfg;
            numOfGenericReq = modeRqstPCfgPtr->numOfGenericReq;
            for (userIdx = 0u; userIdx < numOfGenericReq; userIdx++)
            {
                if (requestingUser == modeRqstLCfgPtr->genRqstUserRef[userIdx])
                {
                    modeRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
                    modeRqstPtr->genericReqStatus[userIdx] = requestedMode;
                    if (BSWM_IMMEDIATE == modeRqstLCfgPtr->genericRqst[userIdx].process)
                    {
                        numOfRules = modeRqstLCfgPtr->genericRqst[userIdx].belongToRlueNum;
                        ruleLCfgPtr =  BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleLCfg;
                        for (idx = 0u; idx < numOfRules; idx++)
                        {
                            ruleIdx = modeRqstLCfgPtr->genericRqst[userIdx].belongToRlue[idx];
                            if ((boolean)FALSE == ruleLCfgPtr[ruleIdx].isNestExe)
                            {
                                /* An Independent rule,to be evaluated each time applicable*/
                                BswM_ArbitrateRule(ruleIdx, partIdx);
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
}

/*Initialize BswMGenericRequest request port*/
FUNC(void, BSWM_CODE)
BswM_InitGenericRequestPorts(
    void
)
{
    P2CONST(BswM_ModeRqstPortPCCfgType, AUTOMATIC, BSWM_CONST) modeRqstPCfgPtr;
    P2CONST(BswM_ModeRqstPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) modeRqstPtr;
    ApplicationType partIdx;
    boolean result;
    BswM_UserType numOfGenericReq;
    BswM_UserType userIdx;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        modeRqstPCfgPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg;
        modeRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
        numOfGenericReq = modeRqstPCfgPtr->numOfGenericReq;
        for (userIdx = 0u; userIdx < numOfGenericReq; userIdx++)
        {
            if (NULL_PTR != modeRqstPCfgPtr->genRqstInitMode)
            {
                modeRqstPtr->genericReqStatus[userIdx] = *(modeRqstPCfgPtr->genRqstInitMode);
            }
            else
            {
                break;
            }
        }
    }
#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    else
    {
        (void)Det_ReportError(BSWM_MODULE_ID, BSWM_INSTANCE_ID, BSWM_API_ID_INIT, BSWM_E_INIT_FAILED);
    }
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
}

/*Get generic request status*/
FUNC(uint16, BSWM_CODE)
BswM_GetGeneRqstStatus
(
    BswM_UserType userIdx
)
{
    uint16 retStatus = BSWM_INVALID_U16;
    ApplicationType partIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        retStatus = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr->genericReqStatus[userIdx];
    }
    return retStatus;
}
#endif /*(BSWM_GENERIC_REQUEST_ENABLED == STD_ON)*/

#if (BSWM_VERSION_INFO_API == STD_ON)
/**
 * Returns the version information of this module.
 * Service ID: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): NA
 * Parameters(INOUT): NA
 * Parameters(OUT): VersionInfo, pointer to where to store the version
 *                               information of the module
 * Return value: NA
 */
FUNC(void, BSWM_CODE)
BswM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, BSWM_APPL_DATA) VersionInfo
)
{
#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError(
                        BSWM_MODULE_ID,
                        BSWM_INSTANCE_ID,
                        BSWM_API_ID_GET_VERSION_INFO,
                        BSWM_E_NULL_POINTER);
    }
    else
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
    {
        VersionInfo->moduleID = BSWM_MODULE_ID;
        VersionInfo->vendorID = BSWM_VENDOR_ID;
        VersionInfo->instanceID = BSWM_INSTANCE_ID;
        VersionInfo->sw_major_version = BSWM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = BSWM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = BSWM_SW_PATCH_VERSION;
    }
}
#endif /*(BSWM_VERSION_INFO_API == STD_ON)*/

#if (BSWM_MULTI_PARTITION_ENABLED == STD_ON)
/**
 * Function called by Restart Task if the partition containing the BswM has
 * been restarted.
 * Service ID: 0x1e
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): NA
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_CODE)
BswM_BswMPartitionRestarted
(
    void
)
{
    P2CONST(BswM_EventRqstPortLCfgType, AUTOMATIC, BSWM_CONST) evRqstLCfgPtr;
    P2VAR(BswM_EventRquestPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) evRqstPtr;
    P2CONST(BswM_RuleLcCfgType, AUTOMATIC, BSWM_CONST) ruleLCfgPtr;
    BswM_RuleIndexType numOfRules;
    BswM_RuleIndexType idx;
    BswM_RuleIndexType ruleIdx;
    BswM_EventRqstPortIdxType evIdx;
    ApplicationType partIdx;
    boolean result;

#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    if (E_OK == BswM_DetChkParRestart())
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            evRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].eventRqstPortRunPtr;
            evIdx = *(BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].evRqstPCCfg->parRestartIdxPtr);
            evRqstPtr[evIdx] = BSWM_EVENT_IS_SET;
            evRqstLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].evRqstLCfg;
            if (BSWM_IMMEDIATE == evRqstLCfgPtr->bswMParRestart->process)
            {
                numOfRules = evRqstLCfgPtr->bswMParRestart->belongToRlueNum;
                ruleLCfgPtr =  BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleLCfg;
                for (idx = 0u; idx < numOfRules; idx++)
                {
                    ruleIdx = evRqstLCfgPtr->bswMParRestart->belongToRlue[idx];
                    if ((boolean)FALSE == ruleLCfgPtr[ruleIdx].isNestExe)
                    {
                        /* An Independent rule,to be evaluated each time applicable*/
                        BswM_ArbitrateRule(ruleIdx, partIdx);
                    }
                }
            }
        }
    }
}

/*Get BswM_BswMPartitionRestarted status*/
FUNC(BswM_EventRquestPortRuntimeType, BSWM_DCM_CODE)
BswM_GetParRestartStatus
(
    void
)
{
    BswM_EventRquestPortRuntimeType parRstStatus;
    BswM_EventRqstPortIdxType evIdx;
    ApplicationType partIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        evIdx = *(BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].evRqstPCCfg->parRestartIdxPtr);
        parRstStatus = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].eventRqstPortRunPtr[evIdx];
    }
    return parRstStatus;
}
#endif /*(BSWM_MULTI_PARTITION_ENABLED == STD_ON)*/

/*Get current partition index*/
FUNC(boolean, BSWM_CODE)
BswM_GetPartitionIdx(
    P2VAR(ApplicationType, AUTOMATIC, BSWM_VAR_CLEARED) partitionIdx
)
{
    boolean foundResult = TRUE;
#if (BSWM_MULTI_PARTITION_ENABLED == STD_ON)
    ApplicationType idx;
    ApplicationType partId;
    ApplicationType numOfPartition;
#endif /*(BSWM_MULTI_PARTITION_ENABLED == STD_ON)*/

#if (BSWM_MULTI_PARTITION_ENABLED == STD_ON)
    partId = GetApplicationID();
    numOfPartition = BswM_RuntimeStatus.numOfPartitions;
    for (idx = 0u; idx < numOfPartition; idx++)
    {
        if (partId == BswM_RuntimeStatus.bswmPartPCCfgs[idx].partitionId)
        {
            *partitionIdx = idx;
            break;
        }
    }
    if (idx == numOfPartition)
    {
        foundResult = FALSE;
    }
#else
    *partitionIdx = 0u;
#endif /*(BSWM_MULTI_PARTITION_ENABLED == STD_ON)*/
    return foundResult;
}

/*Execute the arbitration the specific rule in a specific partition*/
FUNC(void, BSWM_CODE)
BswM_ArbitrateRule
(
    BswM_RuleIndexType ruleIdx,
    ApplicationType partIdx
)
{
    P2CONST(BswM_RuleLcCfgType, AUTOMATIC, BSWM_CONST) ruleLCfgPtr;
    P2CONST(BswM_ActionListLCfgType, AUTOMATIC, BSWM_CONST) actionListPtr;
    BswM_RuleStateType ruleRet;
    BswM_RuleStateType oldState;
    BswM_ActionListIndexType actListIdx;

    ruleLCfgPtr = &(BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleLCfg[ruleIdx]);
    /*Execution mode arbitration function*/
    ruleRet = ruleLCfgPtr->modeArbitraFunc();
    if ((BSWM_TRUE == ruleRet) &&
            (NULL_PTR != ruleLCfgPtr->trueActList))
    {
        actListIdx = *(ruleLCfgPtr->trueActList);
    }
    else if ((BSWM_FALSE == ruleRet) &&
            (NULL_PTR != ruleLCfgPtr->falseActList))
    {
        actListIdx = *(ruleLCfgPtr->falseActList);
    }
    else
    {
        goto UPDATE_RULE_STATE;
    }
    actionListPtr = &(BswM_RuntimeStatus.bswmPartLCfgs[partIdx].acListLCfg[actListIdx]);
    oldState = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleRutTimeStatus[ruleIdx].ruleStatus;
    if ((BSWM_CONDITION == actionListPtr->executeType)
            /*Trigger:Evaluated only when the evaluation result has changed from the previous evaluation*/
            || (ruleRet != oldState)
        )
    {
        BswM_DoActionList(partIdx, actListIdx);
    }
    UPDATE_RULE_STATE:
    /*update the old state of this rule with the current state*/
     BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleRutTimeStatus[ruleIdx].ruleStatus = ruleRet;
}
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"
/*Initialize event request port*/
static FUNC(void, BSWM_CODE)
BswM_InitEventRequestPort(
    void
)
{
    P2VAR(BswM_EventRquestPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) evRqstPtr;
    ApplicationType partId;
    BswM_EventRqstPortIdxType numOfEvPort;
    BswM_EventRqstPortIdxType evIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partId);
    if ((boolean)TRUE == result)
    {
        evRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partId].eventRqstPortRunPtr;
        numOfEvPort = BswM_RuntimeStatus.bswmPartPCCfgs[partId].evRqstSrcNum;
        for (evIdx = 0u; evIdx < numOfEvPort; evIdx++)
        {
            /*All BswMEventRequestPorts shall be initialized to a CLEAR state.*/
            evRqstPtr[evIdx] = BSWM_EVENT_IS_CLEARED;
        }
    }
#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    else
    {
        (void)Det_ReportError(BSWM_MODULE_ID, BSWM_INSTANCE_ID, BSWM_API_ID_INIT, BSWM_E_INIT_FAILED);
    }
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
}

/*Initialize event request port*/
static FUNC(void, BSWM_CODE)
BswM_InitModeRequestPort(
    void
)
{
#if (BSWM_SCHM_ENABLED == STD_ON)
    /*BswMBswModeNotification*/
    BswM_InitBswModeRqstPort();
#endif /*(BSWM_SCHM_ENABLED == STD_ON)*/

#if (BSWM_CANSM_ENABLED == STD_ON)
    BswM_InitCanSMRequestPorts();
#endif /*BSWM_CANSM_ENABLED == STD_ON)*/

#if (BSWM_COMM_ENABLED == STD_ON)
    BswM_InitComMRequestPorts();
#endif /*(BSWM_COMM_ENABLED == STD_ON)*/

#if (BSWM_DCM_ENABLED == STD_ON)
    BswM_InitDcmRequestPorts();
#endif /*(BSWM_DCM_ENABLED == STD_ON)*/

#if (BSWM_ECUM_ENABLED == STD_ON)
    BswM_InitEcuMRequestPorts();
#endif /*(BSWM_ECUM_ENABLED == STD_ON)*/

#if (BSWM_ETHIF_ENABLED == STD_ON)
    BswM_InitEthIfRequestPorts();
#endif /*(BSWM_ETHIF_ENABLED == STD_ON)*/

#if (BSWM_ETHSM_ENABLED == STD_ON)
    BswM_InitEthSMRequestPorts();
#endif /*(BSWM_ETHSM_ENABLED == STD_ON)*/

#if (BSWM_FRSM_ENABLED == STD_ON)
    BswM_InitFrSMRequestPorts();
#endif /*(BSWM_FRSM_ENABLED == STD_ON)*/

#if (BSWM_GENERIC_REQUEST_ENABLED == STD_ON)
    BswM_InitGenericRequestPorts();
#endif /*(BSWM_GENERIC_REQUEST_ENABLED == STD_ON)*/

#if (BSWM_J1939DCM_ENABLED == STD_ON)
    BswM_InitJ1939DcmRequestPorts();
#endif /*(BSWM_J1939DCM_ENABLED == STD_ON)*/

#if (BSWM_J1939NM_ENABLED == STD_ON)
    BswM_InitJ1939NmRequestPorts();
#endif /*(BSWM_J1939NM_ENABLED == STD_ON)*/

#if (BSWM_LINSM_ENABLED == STD_ON)
    BswM_InitLinSMRequestPorts();
#endif /*(BSWM_LINSM_ENABLED == STD_ON)*/

#if (BSWM_LINTP_ENABLED == STD_ON)
    BswM_InitLinTpRequestPorts();
#endif /*(BSWM_LINTP_ENABLED == STD_ON)*/

#if (BSWM_NVM_ENABLED == STD_ON)
    BswM_InitNvMRequestPorts();
#endif /*(BSWM_NVM_ENABLED == STD_ON)*/

#if (BSWM_SD_ENABLED == STD_ON)
    BswM_InitSDRequestPorts();
#endif /*(BSWM_SD_ENABLED == STD_ON)*/

#if (BSWM_RTE_ENABLED == STD_ON)
    BswM_InitSwcRequestPorts();
#endif /*(BSWM_RTE_ENABLED == STD_ON)*/

#if (BSWM_TIMER_ENABLED == STD_ON)
    BswM_InitBswMTimer();
#endif /*(BSWM_TIMER_ENABLED == STD_ON)*/
}

/*Initialize rules*/
static FUNC(void, BSWM_CODE)
BswM_InitRules(
    void
)
{
    P2CONST(BswM_RuleLcCfgType, AUTOMATIC, BSWM_CONST) ruleLCfgPtr;
    P2VAR(BswM_RuleRunTimeType, AUTOMATIC, BSWM_VAR_CLEARED) ruleStatusPtr;
    ApplicationType partIdx;
    BswM_RuleIndexType numOfRules;
    BswM_RuleIndexType ruleIdx;
    BswM_RuleIndexType defRuleIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        ruleLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleLCfg;
        ruleStatusPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleRutTimeStatus;
        numOfRules = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].numOfRules;
        for (ruleIdx = 0u; ruleIdx < numOfRules; ruleIdx++)
        {
            ruleStatusPtr[ruleIdx].ruleNeedArbitrate = FALSE;
            ruleStatusPtr[ruleIdx].ruleStatus = ruleLCfgPtr[ruleIdx].ruleInitState;
        }
        /*Set deferred rule status*/
        numOfRules = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].numOfDefRules;
        for (ruleIdx = 0u; ruleIdx < numOfRules; ruleIdx++)
        {
            defRuleIdx = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].defRuleRefLCfg[ruleIdx];
            /*Only for deferred rule need to set the flag.*/
            ruleStatusPtr[defRuleIdx].ruleNeedArbitrate = TRUE;
        }
    }
}

/*Execute specific the action list in the specific partition*/
static FUNC(void, BSWM_CODE)
BswM_DoActionList
(
    ApplicationType partIdx,
    BswM_ActionListIndexType actionListIdx
)
{
    P2CONST(BswM_ActionListLCfgType, AUTOMATIC, BSWM_CONST) actionListPtr;
    P2CONST(BswM_ActionListItemType, AUTOMATIC, BSWM_CONST) actionItemPtr;
    Std_ReturnType itemResult;
    uint8 numOfActionItem;
    uint8 itemIdx;
    boolean loopExit = FALSE;

    actionListPtr = &(BswM_RuntimeStatus.bswmPartLCfgs[partIdx].acListLCfg[actionListIdx]);
    numOfActionItem = actionListPtr->numOfActionItem;
    for (itemIdx = 0u; itemIdx < numOfActionItem; itemIdx++)
    {
        actionItemPtr = &(actionListPtr->actionItems[itemIdx]);
        switch (actionItemPtr->actionItemType)
        {
            case BSWM_ACTIONITEM_ACTION:
                /*the action list item is action, do the action job*/
                itemResult = BswM_DoAction(
                        partIdx,
                        actionItemPtr->actionRef->avActType->avbActType,
                        actionItemPtr->actionRef->avActType->refActIdx);
                if ((Std_ReturnType)E_NOT_OK == itemResult)
                {
                    if (NULL_PTR != actionItemPtr->runtimeErrId)
                    {
                        (void)Det_ReportRuntimeError(BSWM_MODULE_ID,
                                                BSWM_INSTANCE_ID,
                                                BSWM_API_ID_DO_ACTION_LIST,
                                                *(actionItemPtr->runtimeErrId));
                    }
                    if ((boolean)TRUE == actionItemPtr->abortOnFail)
                    {
                        /* the action list shall be aborted if this specific action returns E_NOT_OK*/
                        loopExit = TRUE;
                    }
                }
                break;
            case BSWM_ACTIONITEM_ACTIONLIST:
                BswM_DoActionList(partIdx, *(actionItemPtr->actionRef->actListRefIdx));
                break;
            case BSWM_ACTIONITEM_RULE:
                BswM_ArbitrateRule(*(actionItemPtr->actionRef->ruleRefIdx), partIdx);
                break;
            default:
                /*Do nothing*/
                break;
        }
        if ((boolean)TRUE == loopExit)
        {
            break;
        }
    }
}

/*Do the specific action job of specific type in specific partition*/
static FUNC(Std_ReturnType, BSWM_CODE)
BswM_DoAction
(
    ApplicationType partIdx,
    BswM_ActionEnumType actionType,
    uint8 actionIdx
)
{
    Std_ReturnType result = E_OK;

       /*do the specific action according to it type*/
        switch (actionType)
        {
            case BSWM_CLEAR_EVENT_REQST:
                result = BswM_DoClrEventRqst(partIdx, actionIdx);
                break;
    #if (BSWM_COMM_ENABLED == STD_ON)
            case BSWM_COMM_ALLOW_COM:
                result = BswM_DoComMAllowCom(partIdx, actionIdx);
                break;
    #if (BSWM_COMM_MODE_LIMITATION_ENABLED == STD_ON)
            case BSWM_COMM_MODE_LIMITATION:
                result = BswM_DoComMModeLimit(partIdx, actionIdx);
                break;
    #endif /*(BSWM_COMM_MODE_LIMITATION_ENABLED == STD_ON)*/
            case BSWM_COMM_MODE_SWITCH:
                result = BswM_DoComMModeSwitch(partIdx, actionIdx);
                break;
    #endif /*BSWM_COMM_ENABLED == STD_ON)*/
    #if (BSWM_MAX_NUM_CORE > 1u)
            case BSWM_CORE_HALT_MODE:
                result = BswM_DoCoreHaltMode(partIdx, actionIdx);
                break;
    #endif /*BSWM_MAX_NUM_CORE > 1)*/
    #if (BSWM_COM_ENABLED == STD_ON)
            case BSWM_DEADLINE_MONITOR_CONTROL:
                result = BswM_DoDMControl(partIdx, actionIdx);
                break;
    #endif /*BSWM_COM_ENABLED == STD_ON)*/
    #if (BSWM_ECUM_ENABLED == STD_ON)
        #if (BSWM_ECUM_VERSION == BSWM_V_4_2_2)
            case BSWM_ECUM_GO_DOWN:
                result = BswM_DoEcuMGoDown(partIdx, actionIdx);
                break;
            case BSWM_ECUM_GO_HALT:
                result = BswM_DoEcuMGoHalt(partIdx, actionIdx);
                break;
            case BSWM_ECUM_GO_POLL:
                result = BswM_DoEcuMGoPoll(partIdx, actionIdx);
                break;
        #else
            case BSWM_ECUM_GO_DOWN_HALT_POLL:
                result = BswM_DoEcuMGoDownHaltPoll(partIdx, actionIdx);
                break;
        #endif /*(BSWM_ECUM_VERSION == BSWM_V_4_2_2)*/
            case BSWM_ECUM_DRIVER_INIT_BSWM:
                result = BswM_DoEcuMInitBswM(partIdx, actionIdx);
                break;
            case BSWM_ECUM_SELECT_SHUTDOWN_TARGET:
                result = BswM_DoEcuMSelectShutTgt(partIdx, actionIdx);
                break;
            case BSWM_ECUM_STATE_SWITCH:
                result = BswM_DoEcuMStateSwitch(partIdx, actionIdx);
                break;
    #endif /*BSWM_ECUM_ENABLED == STD_ON)*/
    #if (BSWM_ETHIF_ENABLED == STD_ON)
            case BSWM_ETHIF_SWITCH_PORT_GROUP:
                result = BswM_DoEthIfSwiPortGruRqst(partIdx, actionIdx);
                break;
    #endif /*BSWM_ETHIF_ENABLED == STD_ON)*/

    #if (BSWM_FRSM_ENABLED == STD_ON)
            case BSWM_FRSM_ALL_SLOTS:
                result = BswM_DoFrSMAllSlots(partIdx, actionIdx);
                break;
    #endif /*BSWM_FRSM_ENABLED == STD_ON)*/
    #if (BSWM_J1939DCM_ENABLED == STD_ON)
            case BSWM_J1939DCM_STATE_SWITCH:
                result = BswM_DoJ1939DcmStateSwitch(partIdx, actionIdx);
                break;
    #endif /*BSWM_J1939DCM_ENABLED == STD_ON)*/
    #if (BSWM_J1939RM_ENABLED == STD_ON)
            case BSWM_J1939RM_STATE_SWITCH:
                result = BswM_DoJ1939RmStateSwitch(partIdx, actionIdx);
                break;
    #endif /*BSWM_J1939RM_ENABLED == STD_ON)*/
    #if (BSWM_LINSM_ENABLED == STD_ON)
            case BSWM_LIN_SCHEDULE_SWITCH:
                result = BswM_DoLinScheduleSwitch(partIdx, actionIdx);
                break;
    #endif /*BSWM_LINSM_ENABLED == STD_ON)*/
    #if (BSWM_NM_ENABLED == STD_ON)
            case BSWM_NM_CONTROL:
                result = BswM_DoNMControl(partIdx, actionIdx);
                break;
    #endif /*BSWM_NM_ENABLED == STD_ON)*/
    #if (BSWM_COM_ENABLED == STD_ON)
            case BSWM_PDU_GROUP_SWITCH:
                result = BswM_DoPduGrpSwitch(partIdx, actionIdx);
                break;
    #endif /*BSWM_COM_ENABLED == STD_ON)*/
    #if (BSWM_PDUR_ENABLED == STD_ON)
            case BSWM_PDU_ROUTER_CONTROL:
                result = BswM_DoPduRouterControl(partIdx, actionIdx);
                break;
    #endif /*BSWM_PDUR_ENABLED == STD_ON)*/
    #if (BSWM_RTE_ENABLED == STD_ON)
            case BSWM_RTE_MODE_REQUEST:
                result = BswM_DoRteModeRequest(partIdx, actionIdx);
                break;
            case BSWM_RTE_SWITCH:
                result = BswM_DoRteSwitch(partIdx, actionIdx);
                break;
    #endif /*BSWM_RTE_ENABLED == STD_ON)*/
    #if (BSWM_SCHM_ENABLED == STD_ON)
            case BSWM_SCHM_SWITCH:
                result = BswM_DoSchMSwitch(partIdx, actionIdx);
                break;
    #endif /*BSWM_SCHM_ENABLED == STD_ON)*/
    #if (BSWM_SD_ENABLED == STD_ON)
            case BSWM_SD_CLIENT_SERVICE_MODE_REQUEST:
                result = BswM_DoSdCliServiceModeReq(partIdx, actionIdx);
                break;
            case BSWM_SD_CONSUMED_EVENT_GROUP_MODE_REQUEST:
                result = BswM_DoSdEvGrpModeReq(partIdx, actionIdx);
                break;
            case BSWM_SD_SERVER_SERVICE_MODE_REQUEST:
                result = BswM_DoSdSvrServiceModeReq(partIdx, actionIdx);
                break;
    #endif /*BSWM_SD_ENABLED == STD_ON)*/
    #if (BSWM_TIMER_ENABLED == STD_ON)
            case BSWM_TIMER_CONTROL:
                result = BswM_DoTimerControl(partIdx, actionIdx);
                break;
    #endif /*BSWM_TIMER_ENABLED == STD_ON)*/
    #if (BSWM_COM_ENABLED == STD_ON)
            case BSWM_SWITCH_IPDU_MODE:
                result = BswM_DoSwitchIpduMode(partIdx, actionIdx);
                break;
            case BSWM_TRIGGER_IPDU_SEND:
                result = BswM_DoTriggerIpduSend(partIdx, actionIdx);
                break;
    #endif /*BSWM_COM_ENABLED == STD_ON)*/
            case BSWM_USER_CALLOUT:
                result = BswM_DoUserCallout(partIdx, actionIdx);
                break;
            default:
                /*Do nothing*/
                break;
        }
    return result;
}
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
