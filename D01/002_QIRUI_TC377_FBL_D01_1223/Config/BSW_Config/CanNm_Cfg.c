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
**  FILENAME    : CanNm_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2023/05/23 19:43:51                                         **
**  Author      : wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration data for CanNm                                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"
#include "PduR_Cfg.h"
#include "CanIf_Cfg.h"
#include "ComM_Cfg.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
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
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanNm_MemMap.h"

CONST(CanNm_RxPduType, CANNM_CONST) CanNm_RxPduData[CANNM_RX_PDU_NUMBER_MAX] =
{
        {
            0u,           /* RxPduId */
        },
};

CONST(CanNm_TxPduType, CANNM_CONST)  CanNm_TxPduData[CANNM_TX_PDU_NUMBER_MAX] =
{
        {
            0u,           /* TxConfirmationPduId*/
            CANIF_TXPDU_CANNM_TX_CANFD,      /* CanNmTxPduRef */
            FALSE        /*TxPduIsTriggerTrans*/
        },
};

CONST(CanNm_UserDataTxPduType, CANNM_CONST) CanNM_UserDataTxPdu[CANNM_USER_DATA_TX_PDU_MAX]=
{
        {
             0u,                 /* CanNmTxUserDataPduId*/
             PDUR_DESTPDU_CanNmUserDataTxPdu,       /* CanNmTxUserDataPduRef */
             6u,  /* CanNm_UserDataLen */
              2u,  /* CanNm_UserDataOffsetPos */
        },
};

CONST(CanNm_ChannelConfigType, CANNM_CONST)
CanNm_ChannelCfgData[CANNM_NUMBER_OF_CHANNEL]=
{
    {
        TRUE,    /* CanNmActiveWakeupBitEnabled */
        20u,        /* CanNmImmediateNmCycleTime */
        10u,        /* CanNmImmediateNmTransmissions */
        0u,        /* CanNmMsgCycleOffset */
        500u,        /* CanNmMsgCycleTime */
        0u,        /* CanNmMsgTimeoutTime */
        13u,        /* CanNmNodeId */
        CANNM_PDU_BYTE_1,    /* CanNmPduCbvPosition */
        CANNM_PDU_BYTE_0,    /* CanNmPduNidPosition */
        1500u,                    /* CanNmRepeatMessageTime */
        TRUE,                /* CanNmRetryFirstMessageRequest */
        FALSE,    /* CanNmStayInPbsEnabled */
        2000u,                    /* CanNmTimeoutTime */
        2000u,                    /* CanNmWaitBusSleepTime */
        Channel_CanController_CAN1_FD,    /* CanNmComMNetworkHandleRef */
        &CanNm_RxPduData[0],    /* CanNmRxPdu */
        1u,              /* RxPduNum */
        &CanNm_TxPduData[0],   /* CanNmTxPdu */
        &CanNM_UserDataTxPdu[0],   /* CanNmUserDataTxPdu */
    },

};

CONST(CanNm_ConfigType, CANNM_CONST) CanNm_Config =
{
    0x5u,    /* CanNmMainFunctionPeriod */
    CanNm_ChannelCfgData,       /* CanNmChannelConfig */

};
#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanNm_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

