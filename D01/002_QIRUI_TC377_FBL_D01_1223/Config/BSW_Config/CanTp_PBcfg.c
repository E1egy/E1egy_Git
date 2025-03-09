/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_PBcfg.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-01-26 15:23:03>
 */
/*============================================================================*/

/*=======[I N C L U D E S]================================*/
#include "CanTp_PBcfg.h"
#include "CanTp_Types.h"
#include "CanIf_Cfg.h"
#include "PduR_Cfg.h"

/*=======[I N T E R N A L   D A T A]=======================*/

/*CanTpChannel RxSdu address information*/
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_PhyReq_Nar = 25u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_PhyReq_Ncr = 150u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_PhyReq_Bs = 0u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_PhyReq_RxWftMax = 255u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_PhyReq_STmin = 0u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_FunReq_Nar = 25u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_FunReq_Ncr = 150u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_FunReq_Bs = 0u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_FunReq_RxWftMax = 255u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CanTp_FunReq_STmin = 0u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_RxNSduType, CANTP_CONST) CanTp_Ch0RxNSdus[2] =
{
    {
        &CanTp_Ch0RxSdu_CANTP_CanTp_PhyReq_Bs,
        &CanTp_Ch0RxSdu_CANTP_CanTp_PhyReq_Nar,
        25u,
        &CanTp_Ch0RxSdu_CANTP_CanTp_PhyReq_Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CanTp_PhyReq,
        CANTP_CanTp_PhyReq,
        CANTP_CanIf_PhyReq,
        CANTP_CanIf_PhyResp,
        CANIF_TXPDU_CanIf_PhyResp,
        0u,
        64u,
        CANTP_PADDING_ON,
        CANTP_CANFD_PHYSICAL,
        &CanTp_Ch0RxSdu_CANTP_CanTp_PhyReq_RxWftMax,
        &CanTp_Ch0RxSdu_CANTP_CanTp_PhyReq_STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN_FD,
    },
    {
        &CanTp_Ch0RxSdu_CANTP_CanTp_FunReq_Bs,
        &CanTp_Ch0RxSdu_CANTP_CanTp_FunReq_Nar,
        25u,
        &CanTp_Ch0RxSdu_CANTP_CanTp_FunReq_Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CanTp_FunReq,
        CANTP_CanTp_FunReq,
        CANTP_CanIf_FunReq,
        0xFFu,
        0xFFu,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_CANFD_FUNCTIONAL,
        &CanTp_Ch0RxSdu_CANTP_CanTp_FunReq_RxWftMax,
        &CanTp_Ch0RxSdu_CANTP_CanTp_FunReq_STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN_FD,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*CanTpChannel TxSdu address information*/
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0TxSdu_CANTP_CanTP_PhyResp_Nbs = 75u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0TxSdu_CANTP_CanTP_PhyResp_Ncs = 50u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_TxNSduType, CANTP_CONST) CanTp_Ch0TxNSdus[1] =
{
    {
        25u,
        &CanTp_Ch0TxSdu_CANTP_CanTP_PhyResp_Nbs,
        &CanTp_Ch0TxSdu_CANTP_CanTP_PhyResp_Ncs,
        CANTP_STANDARD,
        PDUR_DESTPDU_CanTP_PhyResp,
        CANTP_CanTP_PhyResp,
        CANTP_CanIf_PhyResp,
        CANTP_CanIf_PhyReq,
        CANIF_TXPDU_CanIf_PhyResp,
        0u,
        64u,
        CANTP_PADDING_ON,
        CANTP_PHYSICAL_TX,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN_FD,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_ChannelType, CANTP_CONST) CanTp_CfgChannel[CANTP_CHANNEL_NUMBER] =
{
    {
        CANTP_MODE_FULL_DUPLEX,
        0x2u,
        &CanTp_Ch0RxNSdus[0],
        0x1u,
        &CanTp_Ch0TxNSdus[0]
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
CONST(CanTp_ConfigType, CANTP_CONST) CanTp_Config =
{
    CANTP_CHANNEL_NUMBER,
    &CanTp_CfgChannel[0]
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*=======[E X T E R N A L   D A T A]===========================*/
/*=======[E N D   O F   F I L E]==============================*/

