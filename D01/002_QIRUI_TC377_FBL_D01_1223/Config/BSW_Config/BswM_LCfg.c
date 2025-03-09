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
**  FILENAME    : BswM_LCfg.c                                                  **
**                                                                            **
**  Created on  : 2023/05/24 14:44:00                                           **
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
/*  <VERSION>    <DATE>        <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-03-24  qinchun.yang    R19_11 BswM initial version.
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Internal.h"
#include "BswM_Ext.h"

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/* BswMConfig*/
/********BswMEventRequestPort**********/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_EvRqst_ComMInitReset_LCfg_Core0_Par0[1u] =
{
    {
        NULL_PTR,    /*belongToRlue*/
        0u,                    /*belongToRlueNum*/
        BSWM_DEFERRED    /*BswMEventRequestProcessing*/
    }
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_EventRqstPortLCfgType, BSWM_CONST) BswM_EvRqstLCfg_Core0_Par0 =
{
    &(BswM_EvRqst_ComMInitReset_LCfg_Core0_Par0[0]),    /*BswMComMInitiateReset*/
    NULL_PTR,    /*BswMDcmApplicationUpdatedIndication*/
    NULL_PTR,    /*BswMNmCarWakeUpIndication*/
    NULL_PTR,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

/*********************BswMModeRequestPort******************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_CanSMInd0Rule_Core0_Par0[7u] =
{
    6u,
    7u,
    8u,
    9u,
    10u,
    11u,
    12u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_CanSMInd1Rule_Core0_Par0[12u] =
{
    13u,
    14u,
    15u,
    23u,
    25u,
    26u,
    27u,
    28u,
    29u,
    30u,
    31u,
    32u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_CansmInd_LCfg_Core0_Par0[2u] =
{
    /*ReqPort_CanSm_Ch0 : BswMCanSMIndication*/
    {
        &(BswM_CanSMInd0Rule_Core0_Par0[0]),        /*belongToRlue*/
        7u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
    /*ReqPort_CanSm_Ch1 : BswMCanSMIndication*/
    {
        &(BswM_CanSMInd1Rule_Core0_Par0[0]),        /*belongToRlue*/
        12u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(NetworkHandleType, BSWM_CONST) BswM_CansmIndChRef_Core0_Par0[2u] =
{
    Channel_CanController_TEST_CAN,
    Channel_CanController_CAN1_FD,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_ComMInd_LCfg_Core0_Par0[1u] =
{
    /*ReqPort_ComM_Ch0 : BswMComMIndication*/
    {
        NULL_PTR,    /*belongToRlue*/
        0u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(NetworkHandleType, BSWM_CONST) BswM_ComMIndChRef_Core0_Par0[1u] =
{
    Channel_CanController_TEST_CAN,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_DcmComModeRqstInd0Rule_Core0_Par0[6u] =
{
    33u,
    34u,
    35u,
    36u,
    37u,
    38u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_DcmComModeRqst_LCfg_Core0_Par0[1u] =
{
    /*ReqPort_Dcm_Ch1 : BswMDcmComModeRequest*/
    {
        &(BswM_DcmComModeRqstInd0Rule_Core0_Par0[0]),        /*belongToRlue*/
        6u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(NetworkHandleType, BSWM_CONST) BswM_DcmChRef_Core0_Par0[1u] =
{
    Channel_CanController_CAN1_FD,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_EcuMState0Rule_Core0_Par0[2u] =
{
    17u,
    24u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_EcuMState_LCfg_Core0_Par0[1u] =
{
    /*ReqPort_EcuMStateIndication : BswMEcuMIndication*/
    {
        &(BswM_EcuMState0Rule_Core0_Par0[0]),        /*belongToRlue*/
        2u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_EcuMWkSrcRqstInd0Rule_Core0_Par0[3u] =
{
    0u,
    5u,
    14u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_EcuMWkSrcRqstInd1Rule_Core0_Par0[3u] =
{
    1u,
    5u,
    15u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_EcuMWkSrcRqst_LCfg_Core0_Par0[2u] =
{
    /*ReqPort_EcuM_EcuMWakeupSource_Ch1 : BswMEcuMWakeupSource*/
    {
        &(BswM_EcuMWkSrcRqstInd0Rule_Core0_Par0[0]),        /*belongToRlue*/
        3u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
    /*ReqPort_EcuM_EcuMWakeupSource_Local : BswMEcuMWakeupSource*/
    {
        &(BswM_EcuMWkSrcRqstInd1Rule_Core0_Par0[0]),        /*belongToRlue*/
        3u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(EcuM_WakeupSourceType, BSWM_CONST) BswM_EcuMWkSrcRef_Core0_Par0[2u] =
{
    EcuMWakeupSource_Can,
    EcuMWakeupSource_Local,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_EcuMRunRqst0Rule_Core0_Par0[4u] =
{
    4u,
    18u,
    19u,
    20u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_EcuMRunRqst1Rule_Core0_Par0[6u] =
{
    2u,
    3u,
    4u,
    18u,
    19u,
    20u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_EcuMRunRqst_LCfg_Core0_Par0[2u] =
{
    /*ReqPort_EcuM_ReqPostRun : BswMEcuMRUNRequestIndication*/
    {
        &(BswM_EcuMRunRqst0Rule_Core0_Par0[0]),        /*belongToRlue*/
        4u,                    /*belongToRlueNum*/
        BSWM_DEFERRED    /*BswMRequestProcessing*/
    },
    /*ReqPort_EcuM_ReqRun : BswMEcuMRUNRequestIndication*/
    {
        &(BswM_EcuMRunRqst1Rule_Core0_Par0[0]),        /*belongToRlue*/
        6u,                    /*belongToRlueNum*/
        BSWM_DEFERRED    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(EcuM_StateType, BSWM_CONST) BswM_EcuMRunRqstRef_Core0_Par0[2u] =
{
    ECUM_STATE_APP_POST_RUN,
    ECUM_STATE_APP_RUN,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_GeneRqstInd0Rule_Core0_Par0[2u] =
{
    9u,
    10u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_GeneRqstInd1Rule_Core0_Par0[1u] =
{
    16u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_GeneRqstInd2Rule_Core0_Par0[3u] =
{
    18u,
    19u,
    20u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_GeneRqstInd3Rule_Core0_Par0[2u] =
{
    31u,
    32u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_GeneRqst_LCfg_Core0_Par0[4u] =
{
    /*ReqPort_GenericCanSmBusOff_Ch0 : BswMGenericRequest*/
    {
        &(BswM_GeneRqstInd0Rule_Core0_Par0[0]),        /*belongToRlue*/
        2u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
    /*RepPort_GerericComControl : BswMGenericRequest*/
    {
        &(BswM_GeneRqstInd1Rule_Core0_Par0[0]),        /*belongToRlue*/
        1u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
    /*RepPort_ECUSleepControl : BswMGenericRequest*/
    {
        &(BswM_GeneRqstInd2Rule_Core0_Par0[0]),        /*belongToRlue*/
        3u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
    /*ReqPort_GenericCanSmBusOff_Ch1 : BswMGenericRequest*/
    {
        &(BswM_GeneRqstInd3Rule_Core0_Par0[0]),        /*belongToRlue*/
        2u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_UserType, BSWM_CONST) BswM_GenRqstUserRef_Core0_Par0[4u] =
{
    240,
    66,
    95,
    88,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_NvmJobInd1Rule_Core0_Par0[4u] =
{
    19u,
    20u,
    21u,
    22u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_NvmJobInd_LCfg_Core0_Par0[2u] =
{
    /*ReqPort_WriteAll : BswMNvMJobModeIndication*/
    {
        NULL_PTR,    /*belongToRlue*/
        0u,                    /*belongToRlueNum*/
        BSWM_DEFERRED    /*BswMRequestProcessing*/
    },
    /*ReqPort_ReadAll : BswMNvMJobModeIndication*/
    {
        &(BswM_NvmJobInd1Rule_Core0_Par0[0]),        /*belongToRlue*/
        4u,                    /*belongToRlueNum*/
        BSWM_DEFERRED    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(NvM_MultiBlockRequestType, BSWM_CONST)BswM_NvmService_Core0_Par0[2u] =
{
    NVM_WRITE_ALL,
    NVM_READ_ALL,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ModeRqstPortLCfgType, BSWM_CONST) BswM_ModeRqstLCfg_Core0_Par0 =
{

    &(BswM_CansmInd_LCfg_Core0_Par0[0]),    /*BswMCanSMIndication*/
    &(BswM_CansmIndChRef_Core0_Par0[0]),    /*BswMCanSMChannelRef*/
    &(BswM_ComMInd_LCfg_Core0_Par0[0]),    /*BswMComMIndication*/
    &(BswM_ComMIndChRef_Core0_Par0[0]),    /*BswMComMChannelRef*/
    &(BswM_DcmComModeRqst_LCfg_Core0_Par0[0]),    /*BswMDcmComModeRequest*/
    &(BswM_DcmChRef_Core0_Par0[0]),    /*BswMDcmComMChannelRef*/
    &(BswM_EcuMState_LCfg_Core0_Par0[0]),
    &(BswM_EcuMWkSrcRqst_LCfg_Core0_Par0[0]),    /*BswMEcuMWakeupSource*/
    &(BswM_EcuMWkSrcRef_Core0_Par0[0]),    /*BswMEcuMWakeupSrcRef*/
    &(BswM_EcuMRunRqst_LCfg_Core0_Par0[0]),    /*BswMEcuMRUNRequestIndication*/
    &(BswM_EcuMRunRqstRef_Core0_Par0[0]),    /*BswMEcuMRUNRequestProtocolPort*/
    &(BswM_GeneRqst_LCfg_Core0_Par0[0]),    /*BswMGenericRequest*/
    &(BswM_GenRqstUserRef_Core0_Par0[0]),    /*BswMModeRequesterId*/
    &(BswM_NvmJobInd_LCfg_Core0_Par0[0]),    /*BswMNvMJobModeIndication*/
    &(BswM_NvmService_Core0_Par0[0]),    /*BswMNvmService*/
    NULL_PTR,    /*BswMNvMRequest*/
    NULL_PTR,    /*BswMNvMBlockRef*/
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

/*********Rules**********/ 

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule0Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_WKSTATUS_VALIDATED == BswM_GetEcuMWakeSrcStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule0TrueActList_Core0_Par0[1u] =
{
    2u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule1Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_WKSTATUS_VALIDATED == BswM_GetEcuMWakeSrcStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule1TrueActList_Core0_Par0[1u] =
{
    3u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule2Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_RUNSTATUS_REQUESTED == BswM_GetEcuMRunRqstStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule2TrueActList_Core0_Par0[1u] =
{
    4u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule3Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule3TrueActList_Core0_Par0[1u] =
{
    5u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule4Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(1))
    && (ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule4TrueActList_Core0_Par0[1u] =
{
    7u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule5Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((ECUM_WKSTATUS_PENDING == BswM_GetEcuMWakeSrcStatus(1))
    || (ECUM_WKSTATUS_PENDING == BswM_GetEcuMWakeSrcStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule5TrueActList_Core0_Par0[1u] =
{
    8u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule6Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_NO_COMMUNICATION != BswM_GetCanSmIndStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule6FalseActList_Core0_Par0[1u] =
{
    27u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule6TrueActList_Core0_Par0[1u] =
{
    26u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule7Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_FULL_COMMUNICATION == BswM_GetCanSmIndStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule7FalseActList_Core0_Par0[1u] =
{
    25u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule7TrueActList_Core0_Par0[1u] =
{
    24u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule8Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_FULL_COMMUNICATION != BswM_GetCanSmIndStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule8TrueActList_Core0_Par0[1u] =
{
    22u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule9Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((CANSM_BSWM_FULL_COMMUNICATION == BswM_GetCanSmIndStatus(0))
    && (1 == BswM_GetGeneRqstStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule9TrueActList_Core0_Par0[1u] =
{
    21u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule10Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((0 == BswM_GetGeneRqstStatus(0))
    && (CANSM_BSWM_FULL_COMMUNICATION == BswM_GetCanSmIndStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule10TrueActList_Core0_Par0[1u] =
{
    23u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule11Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_NO_COMMUNICATION == BswM_GetCanSmIndStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule11TrueActList_Core0_Par0[1u] =
{
    0u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule12Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((CANSM_BSWM_BUS_OFF == BswM_GetCanSmIndStatus(0))
    || (CANSM_BSWM_SILENT_COMMUNICATION == BswM_GetCanSmIndStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule12TrueActList_Core0_Par0[1u] =
{
    1u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule13Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_NO_COMMUNICATION == BswM_GetCanSmIndStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule13TrueActList_Core0_Par0[1u] =
{
    9u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule14Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((CANSM_BSWM_NO_COMMUNICATION == BswM_GetCanSmIndStatus(1))
    && (ECUM_WKSTATUS_EXPIRED == BswM_GetEcuMWakeSrcStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule14TrueActList_Core0_Par0[1u] =
{
    18u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule15Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((CANSM_BSWM_NO_COMMUNICATION == BswM_GetCanSmIndStatus(1))
    && (ECUM_WKSTATUS_EXPIRED == BswM_GetEcuMWakeSrcStatus(1)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule15TrueActList_Core0_Par0[1u] =
{
    19u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule16Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(1 == BswM_GetGeneRqstStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule16FalseActList_Core0_Par0[1u] =
{
    29u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule16TrueActList_Core0_Par0[1u] =
{
    28u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule17Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_STATE_STARTUP == BswM_GetEcuMState())
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule17TrueActList_Core0_Par0[1u] =
{
    30u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule18Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(1))
    && (ECUM_RUNSTATUS_REQUESTED == BswM_GetEcuMRunRqstStatus(0))
    && (BSWM_TIMER_EXPIRED == BswM_GerTimerStatus(0))
    && (1 == BswM_GetGeneRqstStatus(2)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule18TrueActList_Core0_Par0[1u] =
{
    32u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule19Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(1))
    && (ECUM_RUNSTATUS_REQUESTED == BswM_GetEcuMRunRqstStatus(0))
    && (NVM_REQ_OK == BswM_GetCurNvmJobMode(1))
    && (1 == BswM_GetGeneRqstStatus(2)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule19TrueActList_Core0_Par0[1u] =
{
    6u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule20Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(1))
    && (ECUM_RUNSTATUS_REQUESTED == BswM_GetEcuMRunRqstStatus(0))
    && (NVM_REQ_OK == BswM_GetCurNvmJobMode(1))
    && (1 == BswM_GetGeneRqstStatus(2)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule20TrueActList_Core0_Par0[1u] =
{
    32u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule21Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((BSWM_TIMER_EXPIRED == BswM_GerTimerStatus(0))
    && (NVM_REQ_OK != BswM_GetCurNvmJobMode(1)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule22Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(NVM_REQ_OK == BswM_GetCurNvmJobMode(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule23Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_FULL_COMMUNICATION == BswM_GetCanSmIndStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule24Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_STATE_SHUTDOWN == BswM_GetEcuMState())
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule25Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_FULL_COMMUNICATION == BswM_GetCanSmIndStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule26Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_NO_COMMUNICATION == BswM_GetCanSmIndStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule26TrueActList_Core0_Par0[1u] =
{
    35u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule27Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((CANSM_BSWM_BUS_OFF == BswM_GetCanSmIndStatus(1))
    || (CANSM_BSWM_SILENT_COMMUNICATION == BswM_GetCanSmIndStatus(1)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule27TrueActList_Core0_Par0[1u] =
{
    36u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule28Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_NO_COMMUNICATION != BswM_GetCanSmIndStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule28FalseActList_Core0_Par0[1u] =
{
    43u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule28TrueActList_Core0_Par0[1u] =
{
    42u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule29Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_FULL_COMMUNICATION == BswM_GetCanSmIndStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule29FalseActList_Core0_Par0[1u] =
{
    41u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule29TrueActList_Core0_Par0[1u] =
{
    40u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule30Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_FULL_COMMUNICATION != BswM_GetCanSmIndStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule30TrueActList_Core0_Par0[1u] =
{
    38u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule31Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((CANSM_BSWM_FULL_COMMUNICATION == BswM_GetCanSmIndStatus(1))
    && (1 == BswM_GetGeneRqstStatus(3)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule31TrueActList_Core0_Par0[1u] =
{
    37u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule32Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((0 == BswM_GetGeneRqstStatus(3))
    && (CANSM_BSWM_FULL_COMMUNICATION == BswM_GetCanSmIndStatus(1)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule32TrueActList_Core0_Par0[1u] =
{
    39u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule33Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((DCM_ENABLE_RX_TX_NORM == BswM_GetDcmCurModeStatus(0))
    || (DCM_ENABLE_RX_DISABLE_TX_NORM == BswM_GetDcmCurModeStatus(0))
    || (DCM_ENABLE_RX_DISABLE_TX_NORM_NM == BswM_GetDcmCurModeStatus(0))
    || (DCM_ENABLE_RX_TX_NORM_NM == BswM_GetDcmCurModeStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule33TrueActList_Core0_Par0[1u] =
{
    12u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule34Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((DCM_DISABLE_RX_ENABLE_TX_NORM == BswM_GetDcmCurModeStatus(0))
    || (DCM_DISABLE_RX_TX_NORMAL == BswM_GetDcmCurModeStatus(0))
    || (DCM_DISABLE_RX_TX_NORM_NM == BswM_GetDcmCurModeStatus(0))
    || (DCM_DISABLE_RX_ENABLE_TX_NORM_NM == BswM_GetDcmCurModeStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule34TrueActList_Core0_Par0[1u] =
{
    13u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule35Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((DCM_ENABLE_RX_TX_NORM == BswM_GetDcmCurModeStatus(0))
    || (DCM_DISABLE_RX_ENABLE_TX_NORM == BswM_GetDcmCurModeStatus(0))
    || (DCM_ENABLE_RX_TX_NORM_NM == BswM_GetDcmCurModeStatus(0))
    || (DCM_DISABLE_RX_ENABLE_TX_NORM_NM == BswM_GetDcmCurModeStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule35TrueActList_Core0_Par0[1u] =
{
    14u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule36Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((DCM_DISABLE_RX_TX_NORMAL == BswM_GetDcmCurModeStatus(0))
    || (DCM_ENABLE_RX_DISABLE_TX_NORM == BswM_GetDcmCurModeStatus(0))
    || (DCM_DISABLE_RX_TX_NORM_NM == BswM_GetDcmCurModeStatus(0))
    || (DCM_ENABLE_RX_DISABLE_TX_NORM_NM == BswM_GetDcmCurModeStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule36TrueActList_Core0_Par0[1u] =
{
    15u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule37Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((DCM_ENABLE_RX_TX_NM == BswM_GetDcmCurModeStatus(0))
    || (DCM_DISABLE_RX_ENABLE_TX_NM == BswM_GetDcmCurModeStatus(0))
    || (DCM_ENABLE_RX_TX_NORM_NM == BswM_GetDcmCurModeStatus(0))
    || (DCM_DISABLE_RX_ENABLE_TX_NORM_NM == BswM_GetDcmCurModeStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule37TrueActList_Core0_Par0[1u] =
{
    16u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule38Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((DCM_ENABLE_RX_DISABLE_TX_NM == BswM_GetDcmCurModeStatus(0))
    || (DCM_DISABLE_RX_TX_NM == BswM_GetDcmCurModeStatus(0))
    || (DCM_ENABLE_RX_DISABLE_TX_NORM_NM == BswM_GetDcmCurModeStatus(0))
    || (DCM_DISABLE_RX_TX_NORM_NM == BswM_GetDcmCurModeStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule38TrueActList_Core0_Par0[1u] =
{
    17u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleLcCfgType, BSWM_CONST) BswM_RuleLCfg_Core0_Par0[39u] =
{
    {
        BswM_Rule0Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule0TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule1Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule1TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule2Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule2TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule3Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule3TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule4Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule4TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule5Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule5TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule6Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        BswM_Rule6FalseActList_Core0_Par0, /*BswMRuleFalseActionList*/
        BswM_Rule6TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule7Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        BswM_Rule7FalseActList_Core0_Par0, /*BswMRuleFalseActionList*/
        BswM_Rule7TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule8Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule8TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule9Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule9TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule10Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule10TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule11Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_TRUE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule11TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule12Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule12TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule13Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_TRUE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule13TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule14Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule14TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule15Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule15TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule16Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_TRUE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        BswM_Rule16FalseActList_Core0_Par0, /*BswMRuleFalseActionList*/
        BswM_Rule16TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule17Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule17TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule18Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule18TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule19Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule19TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule20Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule20TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule21Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        NULL_PTR,    /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule22Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        NULL_PTR,    /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule23Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        NULL_PTR,    /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule24Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        NULL_PTR,    /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule25Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        NULL_PTR,    /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule26Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule26TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule27Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule27TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule28Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        BswM_Rule28FalseActList_Core0_Par0, /*BswMRuleFalseActionList*/
        BswM_Rule28TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule29Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        BswM_Rule29FalseActList_Core0_Par0, /*BswMRuleFalseActionList*/
        BswM_Rule29TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule30Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule30TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule31Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule31TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule32Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule32TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule33Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule33TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule34Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule34TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule35Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule35TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule36Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule36TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule37Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule37TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule38Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_FALSE,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule38TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_DefRuleLCfg_Core0_Par0[8u] =
{
    2u,
    3u,
    4u,
    18u,
    19u,
    20u,
    21u,
    22u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

/********************ActionItem*******************/

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionType, BSWM_CONST) BswM_ActListItemsRefAction_Core0_Par0[64u] =
{
    {
        BSWM_USER_CALLOUT,
        0
    },
    {
        BSWM_USER_CALLOUT,
        1
    },
    {
        BSWM_USER_CALLOUT,
        2
    },
    {
        BSWM_USER_CALLOUT,
        3
    },
    {
        BSWM_COMM_MODE_SWITCH,
        3
    },
    {
        BSWM_ECUM_STATE_SWITCH,
        0
    },
    {
        BSWM_USER_CALLOUT,
        11
    },
    {
        BSWM_ECUM_STATE_SWITCH,
        1
    },
    {
        BSWM_USER_CALLOUT,
        7
    },
    {
        BSWM_TIMER_CONTROL,
        0
    },
    {
        BSWM_USER_CALLOUT,
        9
    },
    {
        BSWM_USER_CALLOUT,
        6
    },
    {
        BSWM_ECUM_STATE_SWITCH,
        2
    },
    {
        BSWM_ECUM_GO_DOWN_HALT_POLL,
        0
    },
    {
        BSWM_USER_CALLOUT,
        4
    },
    {
        BSWM_COMM_ALLOW_COM,
        0
    },
    {
        BSWM_USER_CALLOUT,
        12
    },
    {
        BSWM_COMM_ALLOW_COM,
        2
    },
    {
        BSWM_USER_CALLOUT,
        5
    },
    {
        BSWM_USER_CALLOUT,
        10
    },
    {
        BSWM_USER_CALLOUT,
        15
    },
    {
        BSWM_NM_CONTROL,
        0
    },
    {
        BSWM_NM_CONTROL,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        5
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        6
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        7
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        9
    },
    {
        BSWM_NM_CONTROL,
        0
    },
    {
        BSWM_NM_CONTROL,
        1
    },
    {
        BSWM_USER_CALLOUT,
        5
    },
    {
        BSWM_USER_CALLOUT,
        2
    },
    {
        BSWM_USER_CALLOUT,
        15
    },
    {
        BSWM_USER_CALLOUT,
        3
    },
    {
        BSWM_ECUM_GO_DOWN_HALT_POLL,
        0
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        2
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        4
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        3
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        0
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        0
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        5
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        2
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        7
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        6
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        3
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        9
    },
    {
        BSWM_ECUM_DRIVER_INIT_BSWM,
        0
    },
    {
        BSWM_USER_CALLOUT,
        8
    },
    {
        BSWM_TIMER_CONTROL,
        1
    },
    {
        BSWM_USER_CALLOUT,
        11
    },
    {
        BSWM_USER_CALLOUT,
        6
    },
    {
        BSWM_ECUM_GO_DOWN_HALT_POLL,
        0
    },
    {
        BSWM_COMM_MODE_SWITCH,
        1
    },
    {
        BSWM_COMM_MODE_SWITCH,
        2
    },
    {
        BSWM_USER_CALLOUT,
        13
    },
    {
        BSWM_USER_CALLOUT,
        14
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        7
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        9
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        8
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        2
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        3
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        5
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        6
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList0Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[0u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList1Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[1u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList2Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[2u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList3Ref_Core0_Par0[2u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[3u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[4u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList4Ref_Core0_Par0[2u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[5u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[6u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList5Ref_Core0_Par0[4u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[7u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[8u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[9u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[10u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList6Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[11u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList7Ref_Core0_Par0[2u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[12u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[13u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList8Ref_Core0_Par0[4u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[14u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[15u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[16u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[17u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList9Ref_Core0_Par0[3u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[18u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[19u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[20u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList10Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[21u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList11Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[22u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList12Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[23u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList13Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[24u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList14Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[25u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList15Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[26u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList16Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[27u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList17Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[28u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList18Ref_Core0_Par0[3u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[29u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[30u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[31u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList19Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[32u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList20Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[33u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList21Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[34u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList22Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[35u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList23Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[36u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList24Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[37u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList25Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[38u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList26Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[39u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList27Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[40u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList28Ref_Core0_Par0[3u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[41u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[42u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[43u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList29Ref_Core0_Par0[3u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[44u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[45u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[46u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList30Ref_Core0_Par0[3u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[47u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[48u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[49u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList31Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[50u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList32Ref_Core0_Par0[2u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[51u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[52u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList33Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[53u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList34Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[54u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList35Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[55u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList36Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[56u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList37Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[57u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList38Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[58u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList39Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[59u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList40Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[60u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList41Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[61u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList42Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[62u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList43Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[63u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ActionListItemsLCfg_Core0_Par0[64u] =
{
    {
        0u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList0Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        1u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList1Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        2u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList2Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        3u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList3Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        4u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList3Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        5u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList4Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        6u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList4Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        7u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList5Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        8u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList5Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        9u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList5Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        10u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList5Ref_Core0_Par0[3u])    /*actionRef*/
    },
    {
        11u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList6Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        12u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList7Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        13u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList7Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        14u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList8Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        15u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList8Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        16u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList8Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        17u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList8Ref_Core0_Par0[3u])    /*actionRef*/
    },
    {
        18u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList9Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        19u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList9Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        20u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList9Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        21u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList10Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        22u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList11Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        23u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList12Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        24u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList13Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        25u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList14Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        26u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList15Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        27u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList16Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        28u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList17Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        29u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList18Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        30u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList18Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        31u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList18Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        32u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList19Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        33u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList20Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        34u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList21Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        35u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList22Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        36u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList23Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        37u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList24Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        38u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList25Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        39u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList26Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        40u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList27Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        41u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList28Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        42u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList28Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        43u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList28Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        44u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList29Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        45u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList29Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        46u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList29Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        47u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList30Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        48u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList30Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        49u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList30Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        50u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList31Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        51u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList32Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        52u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList32Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        53u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList33Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        54u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList34Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        55u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList35Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        56u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList36Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        57u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList37Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        58u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList38Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        59u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList39Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        60u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList40Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        61u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList41Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        62u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList42Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        63u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList43Ref_Core0_Par0[0u])    /*actionRef*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListLCfgType, BSWM_CONST) BswM_ActionListLCfg_Core0_Par0[44u] =
{
    /* AL_GenericCanSmBusOff_NO_COM_Ch0 */
    {
        BSWM_CONDITION,    /*executeType*/
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[0u])    /*actionItems*/
    },
    /* AL_GenericCanSmBusOff_BUSOFF_SILENT_Ch0 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[1u]),    /* actionItems */
    },
    /* AL_EcuM_ClearWakeUpSource_EcuMWakeupSource_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[2u]),    /* actionItems */
    },
    /* AL_EcuM_ClearWakeUpSource_EcuMWakeupSource_Local */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        2u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[3u]),    /* actionItems */
    },
    /* AL_EcuM_RequestStatus_RUN_REQUEST */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        2u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[5u]),    /* actionItems */
    },
    /* AL_EcuM_RequestStatus_RUN_RELEASE */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        4u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[7u]),    /* actionItems */
    },
    /* AL_EcuM_RequestStatus_POSTRUN_RELEASE */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[11u]),    /* actionItems */
    },
    /* AL_EcuM_RequestStatus_SLEEP_RELEASE */
    {
        BSWM_CONDITION,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        2u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[12u]),    /* actionItems */
    },
    /* AL_EcuM_WakeupSourcePending */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        4u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[14u]),    /* actionItems */
    },
    /* AL_ComM_AllChanel_NO_COM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        3u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[18u]),    /* actionItems */
    },
    /* AL_NmCtrol_Enable_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[21u]),    /* actionItems */
    },
    /* AL_NmCtrol_Disable_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[22u]),    /* actionItems */
    },
    /* AL_DCM_Normal_Rx_Enable_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[23u]),    /* actionItems */
    },
    /* AL_DCM_Normal_Rx_Disable_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[24u]),    /* actionItems */
    },
    /* AL_DCM_Normal_Tx_Enable_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[25u]),    /* actionItems */
    },
    /* AL_DCM_Normal_Tx_Disable_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[26u]),    /* actionItems */
    },
    /* AL_DCM_Nm_Tx_Enable_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[27u]),    /* actionItems */
    },
    /* AL_DCM_Nm_Tx_Disable_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[28u]),    /* actionItems */
    },
    /* AL_EcuM_ClearExpiredWakeUpSource_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        3u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[29u]),    /* actionItems */
    },
    /* AL_EcuM_ClearExpiredWakeUpSource_Local */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[32u]),    /* actionItems */
    },
    /* AL_EcuM_Shutdown */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[33u]),    /* actionItems */
    },
    /* AL_TxEnableGroupSwitch_Ch0 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[34u]),    /* actionItems */
    },
    /* AL_TxDisableGroupSwitch_Ch0 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[35u]),    /* actionItems */
    },
    /* AL_ReinitTxEnableGroupSwitch_Ch0 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[36u]),    /* actionItems */
    },
    /* AL_RxEnableDM_Ch0 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[37u]),    /* actionItems */
    },
    /* AL_RxDisableDM_Ch0 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[38u]),    /* actionItems */
    },
    /* AL_RxEnableGroupSwitch_Ch0 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[39u]),    /* actionItems */
    },
    /* AL_RxDisableGroupSwitch_Ch0 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[40u]),    /* actionItems */
    },
    /* AL_ComControl_ON */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        3u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[41u]),    /* actionItems */
    },
    /* AL_ComControl_OFF */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        3u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[44u]),    /* actionItems */
    },
    /* AL_StartUp */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        3u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[47u]),    /* actionItems */
    },
    /* AL_ComM_AllChanel_FULL_COM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[50u]),    /* actionItems */
    },
    /* AL_EcuM_ReleasePostRun */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        2u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[51u]),    /* actionItems */
    },
    /* AL_EnableSubChannel_Online */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[53u]),    /* actionItems */
    },
    /* AL_EnableSubChannel_Offline */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[54u]),    /* actionItems */
    },
    /* AL_GenericCanSmBusOff_NO_COM_Ch1 */
    {
        BSWM_CONDITION,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[55u]),    /* actionItems */
    },
    /* AL_GenericCanSmBusOff_BUSOFF_SILENT_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[56u]),    /* actionItems */
    },
    /* AL_TxEnableGroupSwitch_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[57u]),    /* actionItems */
    },
    /* AL_TxDisableGroupSwitch_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[58u]),    /* actionItems */
    },
    /* AL_ReinitTxEnableGroupSwitch_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[59u]),    /* actionItems */
    },
    /* AL_RxEnableDM_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[60u]),    /* actionItems */
    },
    /* AL_RxDisableDM_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[61u]),    /* actionItems */
    },
    /* AL_RxEnableGroupSwitch_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[62u]),    /* actionItems */
    },
    /* AL_RxDisableGroupSwitch_Ch1 */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[63u]),    /* actionItems */
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

/********************Action*******************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionComMAllowComLCfgType, BSWM_CONST) BswM_AllowComMLCfg_Core0_Par0[3u] =
{
    /* BswMComMAllowCom*/
    {
        /* comAllowed */
        TRUE,
        /* channel */    
        Channel_CanController_TEST_CAN,
    },
    /* BswMComMAllowCom*/
    {
        /* comAllowed */
        FALSE,
        /* channel */    
        Channel_CanController_TEST_CAN,
    },
    /* BswMComMAllowCom*/
    {
        /* comAllowed */
        TRUE,
        /* channel */    
        Channel_CanController_CAN1_FD,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionComMModeSwitchLCfgType, BSWM_CONST) BswM_ComMModeSwiLCfg_Core0_Par0[4u] =
{
    /* BswMComMModeSwitch*/
    {
        /* BswMComMRequestedMode */
        COMM_FULL_COMMUNICATION,
        /* BswMComMUserRef */    
        ComMUser_Ch0,
    },
    /* BswMComMModeSwitch*/
    {
        /* BswMComMRequestedMode */
        COMM_FULL_COMMUNICATION,
        /* BswMComMUserRef */    
        ComMUser_Ch0,
    },
    /* BswMComMModeSwitch*/
    {
        /* BswMComMRequestedMode */
        COMM_NO_COMMUNICATION,
        /* BswMComMUserRef */    
        ComMUser_Ch0,
    },
    /* BswMComMModeSwitch*/
    {
        /* BswMComMRequestedMode */
        COMM_FULL_COMMUNICATION,
        /* BswMComMUserRef */    
        ComMUser_Ch1,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ComIpduGruType, BSWM_CONST) BswM_ComEnAbleDmGruLCfg_Core0_Par0[2u] =
{
    Com_RxPduGroup_CanController_TEST_CAN,
    Com_RxPduGroup_CanController_CAN1_FD,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ComIpduGruType, BSWM_CONST) BswM_ComDisAbleDmGruLCfg_Core0_Par0[2u] =
{
    Com_RxPduGroup_CanController_TEST_CAN,
    Com_RxPduGroup_CanController_CAN1_FD,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionDMControlLCfgType, BSWM_CONST) BswM_ComDmCtrlLCfg_Core0_Par0[4u] =
{
    /* BswMDeadlineMonitoringControl*/
    {
        &(BswM_ComEnAbleDmGruLCfg_Core0_Par0[0U]),    /*enableRecDmGruId*/
        1u,        /*numOfEnableRecDmGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableRecDmGru*/
    },
    /* BswMDeadlineMonitoringControl*/
    {
        NULL_PTR,    /*enableRecDmGruId*/
        0u,        /*numOfEnableRecDmGru*/
        &(BswM_ComDisAbleDmGruLCfg_Core0_Par0[0U]), /*disableRecDmGruId*/
        1u,     /*numOfDisableRecDmGru*/
    },
    /* BswMDeadlineMonitoringControl*/
    {
        &(BswM_ComEnAbleDmGruLCfg_Core0_Par0[1U]),    /*enableRecDmGruId*/
        1u,        /*numOfEnableRecDmGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableRecDmGru*/
    },
    /* BswMDeadlineMonitoringControl*/
    {
        NULL_PTR,    /*enableRecDmGruId*/
        0u,        /*numOfEnableRecDmGru*/
        &(BswM_ComDisAbleDmGruLCfg_Core0_Par0[1U]), /*disableRecDmGruId*/
        1u,     /*numOfDisableRecDmGru*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ComIpduGruType, BSWM_CONST) BswM_ComEnAblePduGruLCfg_Core0_Par0[6u] =
{
    Com_RxPduGroup_CanController_TEST_CAN,
    Com_TxPduGroup_CanController_TEST_CAN,
    Com_TxPduGroup_CanController_TEST_CAN,
    Com_RxPduGroup_CanController_CAN1_FD,
    Com_TxPduGroup_CanController_CAN1_FD,
    Com_TxPduGroup_CanController_CAN1_FD,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ComIpduGruType, BSWM_CONST) BswM_ComDisAblePduGruLCfg_Core0_Par0[4u] =
{
    Com_RxPduGroup_CanController_TEST_CAN,
    Com_TxPduGroup_CanController_TEST_CAN,
    Com_RxPduGroup_CanController_CAN1_FD,
    Com_TxPduGroup_CanController_CAN1_FD,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

static CONST(BswM_ActionPduGrpSwitchLCfgType, BSWM_CONST) BswM_ComPduGruCtrlLCfg_Core0_Par0[10u] =
{
    /* BswMPduGroupSwitch*/
    {
        FALSE,
        &(BswM_ComEnAblePduGruLCfg_Core0_Par0[0U]),    /*enableIpduGruId*/
        1u,        /*numOfEnableIpduGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        FALSE,
        NULL_PTR,    /*enableRecDmGruId*/
        0u,        /*numOfEnableIpduGru*/
        &(BswM_ComDisAblePduGruLCfg_Core0_Par0[0U]), /*disableIpduGruId*/
        1u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        FALSE,
        &(BswM_ComEnAblePduGruLCfg_Core0_Par0[1U]),    /*enableIpduGruId*/
        1u,        /*numOfEnableIpduGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        TRUE,
        &(BswM_ComEnAblePduGruLCfg_Core0_Par0[2U]),    /*enableIpduGruId*/
        1u,        /*numOfEnableIpduGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        FALSE,
        NULL_PTR,    /*enableRecDmGruId*/
        0u,        /*numOfEnableIpduGru*/
        &(BswM_ComDisAblePduGruLCfg_Core0_Par0[1U]), /*disableIpduGruId*/
        1u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        FALSE,
        &(BswM_ComEnAblePduGruLCfg_Core0_Par0[3U]),    /*enableIpduGruId*/
        1u,        /*numOfEnableIpduGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        FALSE,
        NULL_PTR,    /*enableRecDmGruId*/
        0u,        /*numOfEnableIpduGru*/
        &(BswM_ComDisAblePduGruLCfg_Core0_Par0[2U]), /*disableIpduGruId*/
        1u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        FALSE,
        &(BswM_ComEnAblePduGruLCfg_Core0_Par0[4U]),    /*enableIpduGruId*/
        1u,        /*numOfEnableIpduGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        TRUE,
        &(BswM_ComEnAblePduGruLCfg_Core0_Par0[5U]),    /*enableIpduGruId*/
        1u,        /*numOfEnableIpduGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        TRUE,
        NULL_PTR,    /*enableRecDmGruId*/
        0u,        /*numOfEnableIpduGru*/
        &(BswM_ComDisAblePduGruLCfg_Core0_Par0[3U]), /*disableIpduGruId*/
        1u,     /*numOfDisableIpduGru*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionEcuMDrvInitLCfgType, BSWM_CONST) BswM_EcuMDrvInitListLCfg_Core0_Par0[1u] =
{
    /* BswMEcuMDriverInitListBswM*/
    {
        EcuMDriverInitListBswM_bsw
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionEcuMGoDownLCfgType, BSWM_CONST) BswM_EcuMGoDownHaltPollLCfg_Core0_Par0[1u] =
{
    /* BswMEcuMGoDownHaltPoll*/
    {
        EcuMFlexUserConfig
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionEcuMSelectShutTgtLCfgType, BSWM_CONST) BswM_EcuMSelectShutTgtLCfg_Core0_Par0[1u] =
{
    /* BswMEcuMSelectShutdownTarget*/
    {
        /* target */
        ECUM_SHUTDOWN_TARGET_SLEEP,
        /* mode */
        0U,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionEcuMStateSwitchLCfgType, BSWM_CONST) BswM_EcuMStateSwitchLCfg_Core0_Par0[4u] =
{
    /* BswMEcuMStateSwitch*/
    {
        /* ecuMState */
        ECUM_STATE_APP_RUN,
    },
    /* BswMEcuMStateSwitch*/
    {
        /* ecuMState */
        ECUM_STATE_APP_POST_RUN,
    },
    /* BswMEcuMStateSwitch*/
    {
        /* ecuMState */
        ECUM_STATE_SLEEP,
    },
    /* BswMEcuMStateSwitch*/
    {
        /* ecuMState */
        ECUM_STATE_SHUTDOWN,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionNMControlLCfgType, BSWM_CONST) BswM_NmControlLCfg_Core0_Par0[2u] =
{
    /* BswMNMControl*/
    {
        /* action */
        BSWM_NM_ENABLE,
        /* channel */
        Channel_CanController_CAN1_FD,
    },
    /* BswMNMControl*/
    {
        /* action */
        BSWM_NM_DISABLE,
        /* channel */
        Channel_CanController_CAN1_FD,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionTimerCtrlLCfgType, BSWM_CONST) BswM_TimerActionLCfg_Core0_Par0[2u] =
{
    /* BswMTimerControl*/
    {
        /* BswMTimerAction */
        BSWM_TIMER_START,
        /* BswMTimerValue */
        100.0,
        /* BswMTimerRef */
        0
    },
    /* BswMTimerControl*/
    {
        /* BswMTimerAction */
        BSWM_TIMER_START,
        /* BswMTimerValue */
        20.0,
        /* BswMTimerRef */
        0
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionUserCalloutLCfgType, BSWM_CONST) BswM_UserCallLCfg_Core0_Par0[16u] =
{
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        GenericSwitch_CanSmBusOff_NoCom_Ch0,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        GenericSwitch_CanSmBusOff_BusOffSilent_Ch1,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        User_EcuM_ClearWakeUpSource_EcuMWakeupSource_Ch1,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        User_EcuM_ClearWakeUpSource_EcuMWakeupSource_Local,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        BswM_EcuM_RequestRun,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        BswM_EcuM_ReleaseRun,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        BswM_EcuM_ReleasePostRun,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        BswM_EcuM_RequestPostRun,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        NvM_MainFunction,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        BSW_User_Shutdown,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        WakeupSource_Enable,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        WakeupSource_Disable,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        BswM_CanTrcv_ModeShiftToNormal,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        GenericSwitch_CanSmBusOff_NoCom_Ch1,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        GenericSwitch_CanSmBusOff_BusOffSilent_Ch1,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        BswM_CanTrcv_ModeShiftToStandBy,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionItemsLCfgType, BSWM_CONST) BswM_ActionItemsLCfg_Core0_Par0 =
{
    NULL_PTR,    /*BswMClearEventRequest*/
    &(BswM_AllowComMLCfg_Core0_Par0[0U]),    /*BswMComMAllowCom*/
    NULL_PTR,    /*BswMComMModeLimitation*/
    &(BswM_ComMModeSwiLCfg_Core0_Par0[0U]),    /*BswMComMModeSwitch*/
    &(BswM_ComDmCtrlLCfg_Core0_Par0[0U]),    /*BswMDeadlineMonitoringControl*/
    &(BswM_ComPduGruCtrlLCfg_Core0_Par0[0U]),    /*BswMPduGroupSwitch*/
    NULL_PTR,    /*BswMSwitchIPduMode*/
    NULL_PTR,    /*BswMTriggerIPduSend*/
    &(BswM_EcuMDrvInitListLCfg_Core0_Par0[0U]),    /*BswMEcuMDriverInitListBswM*/
    &(BswM_EcuMGoDownHaltPollLCfg_Core0_Par0[0U]),    /*BswMEcuMGoDownHaltPoll*/
    &(BswM_EcuMSelectShutTgtLCfg_Core0_Par0[0U]),    /*BswMEcuMSelectShutdownTarget*/
    &(BswM_EcuMStateSwitchLCfg_Core0_Par0[0U]),    /*BswMEcuMStateSwitch*/
    &(BswM_NmControlLCfg_Core0_Par0[0U]),    /*BswMNMControl*/
    &(BswM_TimerActionLCfg_Core0_Par0[0U]),    /*BswMTimerControl*/
    &(BswM_UserCallLCfg_Core0_Par0[0U]),    /*BswMUserCallout*/
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"
static VAR(BswM_RuleRunTimeType, BSWM_VAR_CLEARED) BswM_RuleRunTime_Core0_Par0[39u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_PartitionLCfgType, BSWM_CONST) BswM_PartitionLCfg_Core0[1u] =
{
    {
        &BswM_EvRqstLCfg_Core0_Par0,    /*evRqstLCfg*/
        &BswM_ModeRqstLCfg_Core0_Par0,    /*modeRqstLCfg*/
        39u,    /*numOfRules*/
        &(BswM_RuleLCfg_Core0_Par0[0]),    /*ruleLCfg*/
        8u,    /*numOfDefRules*/
        &(BswM_DefRuleLCfg_Core0_Par0[0]),    /*defRuleRefLCfg*/
        44u,    /*numOfActionList*/
        &(BswM_ActionListLCfg_Core0_Par0[0]),    /*acListLCfg*/
        &BswM_ActionItemsLCfg_Core0_Par0,    /*acItemsLCfg*/
        &(BswM_RuleRunTime_Core0_Par0[0]),    /*ruleRutTimeStatus*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_LCfgType, BSWM_CONST) BswM_LCfg[1u] =
{
    {
        &(BswM_PartitionLCfg_Core0[0u]),
    },
};
#define BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define BSWM_START_SEC_CONST_PTR
#include "BswM_MemMap.h"
CONSTP2CONST(BswM_LCfgType, BSWM_CONST, BSWM_CONST) BswM_CoreLinkCfg = &(BswM_LCfg[0u]);
#define BSWM_STOP_SEC_CONST_PTR
#include "BswM_MemMap.h"
