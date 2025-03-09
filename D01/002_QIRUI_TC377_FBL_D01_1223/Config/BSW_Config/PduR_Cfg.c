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
**  FILENAME    : PduR_Cfg.c                                                  **
**                                                                            **
**  Created on  : 2023/02/27 21:42:18                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_CFG_C_AR_MAJOR_VERSION  4u
#define PDUR_CFG_C_AR_MINOR_VERSION  2u
#define PDUR_CFG_C_AR_PATCH_VERSION  2u

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PDUR_CFG_C_AR_MAJOR_VERSION != PDUR_CFG_H_AR_MAJOR_VERSION)
   #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_CFG_C_AR_MINOR_VERSION != PDUR_CFG_H_AR_MINOR_VERSION)
   #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_CFG_C_AR_PATCH_VERSION != PDUR_CFG_H_AR_PATCH_VERSION)
   #error "PduR.c : Mismatch in Specification Major Version"
#endif

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRBswModuleType,PDUR_CONST)
PduR_BswModuleConfigData[PDUR_BSW_MODULE_SUM] =
{
    {
        PDUR_CANIF,
        FALSE,
        FALSE,
        FALSE,
        TRUE,
        FALSE,
        TRUE,
        FALSE,
        FALSE,
        FALSE,
        TRUE,
        TRUE
    },
    {
        PDUR_COM,
        FALSE,
        FALSE,
        FALSE,
        TRUE,
        TRUE,
        FALSE,
        TRUE,
        TRUE,
        TRUE,
        TRUE,
        TRUE
    },
    {
        PDUR_CANNM,
        FALSE,
        TRUE,
        FALSE,
        TRUE,
        FALSE,
        TRUE,
        FALSE,
        FALSE,
        FALSE,
        TRUE,
        TRUE
    },
    {
        PDUR_CANTP,
        FALSE,
        FALSE,
        FALSE,
        FALSE,
        TRUE,
        TRUE,
        FALSE,
        TRUE,
        FALSE,
        FALSE,
        TRUE
    },
    {
        PDUR_DCM,
        FALSE,
        FALSE,
        FALSE,
        TRUE,
        TRUE,
        FALSE,
        TRUE,
        TRUE,
        FALSE,
        TRUE,
        TRUE
    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRDestPduType,PDUR_CONST)
PduR_DestPduConfigData[PDUR_DEST_PDU_SUM] =
{
    {
        PDUR_DESTPDU_CanTP_PhyResp,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_Dcm_PhyResp,
        CANTP_CanTP_PhyResp,
        PDUR_CANTP,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ECAS_EDC_RemoteDiag,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_COM_ECAS_EDC_RemoteDiag,
        CANIF_TXPDU_ECAS_EDC_RemoteDiag,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ECAS_RemoteDiag,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_COM_ECAS_RemoteDiag,
        CANIF_TXPDU_ECAS_RemoteDiag,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ECAS_State,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_COM_ECAS_State,
        CANIF_TXPDU_ECAS_State,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ECAS_EDC_Test,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_COM_ECAS_EDC_Test,
        CANIF_TXPDU_ECAS_EDC_Test,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ECAS_EDC_State,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_COM_ECAS_EDC_State,
        CANIF_TXPDU_ECAS_EDC_State,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Dcm_PhyReq,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_CanTp_PhyReq,
        DCM_Dcm_PhyReq,
        PDUR_DCM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Dcm_FunReq,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_CanTp_FunReq,
        DCM_Dcm_FunReq,
        PDUR_DCM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_EPB_State_R,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_EPB_State_R,
        COM_RXPDU_COM_EPB_State_R,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_IPB_ADS,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_IPB_ADS,
        COM_RXPDU_COM_IPB_ADS,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_VIU_Route_SUS,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_VIU_Route_SUS,
        COM_RXPDU_COM_VIU_Route_SUS,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_VIU_DoorLock,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_VIU_DoorLock,
        COM_RXPDU_COM_VIU_DoorLock,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_VIU_Info,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_VIU_Info,
        COM_RXPDU_COM_VIU_Info,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_EPS_State,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_EPS_State,
        COM_RXPDU_COM_EPS_State,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ABM_State,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_ABM_State,
        COM_RXPDU_COM_ABM_State,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_IPB_State1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_IPB_State1,
        COM_RXPDU_COM_IPB_State1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_IPB_Tq,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_IPB_Tq,
        COM_RXPDU_COM_IPB_Tq,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_IPB_Wheel,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_IPB_Wheel,
        COM_RXPDU_COM_IPB_Wheel,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_TBOX_TimeInfo,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_TBOX_TimeInfo,
        COM_RXPDU_COM_TBOX_TimeInfo,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ScrToECAS,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_ScrToECAS,
        COM_RXPDU_COM_ScrToECAS,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ECASToScr,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_COM_ECASToScr,
        CANIF_TXPDU_ECASToScr,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_BT_Master,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_BT_Master,
        COM_RXPDU_Com_BT_Master,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BT_Slave,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_Com_BT_Slave,
        CANIF_TXPDU_BT_Slave,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ECAS_DV_BA_Req,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_ECAS_DV_BA_Req,
        COM_RXPDU_COM_ECAS_DV_BA_Req,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CanNmUserDataTxPdu,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_ComCanNmUserDataTxPdu,
        CANNM_USER_TX_PDU_0,
        PDUR_CANNM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_VIU_Config,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_VIU_Config,
        COM_RXPDU_COM_VIU_Config,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_VIU_ConfigTrig,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_VIU_ConfigTrig,
        COM_RXPDU_COM_VIU_ConfigTrig,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ADS_ECAS,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_ADS_ECAS,
        COM_RXPDU_COM_ADS_ECAS,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ADS_State,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_ADS_State,
        COM_RXPDU_COM_ADS_State,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_VDC_CDCSet,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_VDC_CDCSet,
        COM_RXPDU_COM_VDC_CDCSet,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_VDC_VIU_BodyInfo,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_VDC_VIU_BodyInfo,
        COM_RXPDU_COM_VDC_VIU_BodyInfo,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_VDC_FMtTq,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_VDC_FMtTq,
        COM_RXPDU_COM_VDC_FMtTq,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_VDC_RMtTq,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_VDC_RMtTq,
        COM_RXPDU_COM_VDC_RMtTq,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_VDC_PTSt,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        PDUR_SRCPDU_VDC_PTSt,
        COM_RXPDU_COM_VDC_PTSt,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRSrcPduType,PDUR_CONST)
PduR_SrcPduConfigData[PDUR_SRC_PDU_SUM] =
{
    {
        PDUR_SRCPDU_Dcm_PhyResp,
        TRUE,
        PDUR_UNUSED_UINT16,
        DCM_Dcm_PhyResp,
        PDUR_DCM,

    },
    {
        PDUR_SRCPDU_COM_ECAS_EDC_RemoteDiag,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_ECAS_EDC_RemoteDiag,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_ECAS_RemoteDiag,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_ECAS_RemoteDiag,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_ECAS_State,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_ECAS_State,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_ECAS_EDC_Test,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_ECAS_EDC_Test,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_ECAS_EDC_State,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_ECAS_EDC_State,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_CanTp_PhyReq,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANTP_CanTp_PhyReq,
        PDUR_CANTP,

    },
    {
        PDUR_SRCPDU_CanTp_FunReq,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANTP_CanTp_FunReq,
        PDUR_CANTP,

    },
    {
        PDUR_SRCPDU_EPB_State_R,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_EPB_State_R,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_IPB_ADS,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_IPB_ADS,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_VIU_Route_SUS,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_VIU_Route_SUS,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_VIU_DoorLock,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_VIU_DoorLock,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_VIU_Info,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_VIU_Info,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_EPS_State,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_EPS_State,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ABM_State,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ABM_State,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_IPB_State1,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_IPB_State1,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_IPB_Tq,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_IPB_Tq,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_IPB_Wheel,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_IPB_Wheel,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_TBOX_TimeInfo,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_TBOX_TimeInfo,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ScrToECAS,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ScrToECAS,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_COM_ECASToScr,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_ECASToScr,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_BT_Master,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BT_Master,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_Com_BT_Slave,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_BT_Slave,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_ECAS_DV_BA_Req,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ECAS_DV_BA_Req,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ComCanNmUserDataTxPdu,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_ComCanNmUserDataTxPdu,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_VIU_Config,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_VIU_Config,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_VIU_ConfigTrig,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_VIU_ConfigTrig,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ADS_ECAS,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ADS_ECAS,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ADS_State,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ADS_State,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_VDC_CDCSet,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_VDC_CDCSet,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_VDC_VIU_BodyInfo,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_VDC_VIU_BodyInfo,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_VDC_FMtTq,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_VDC_FMtTq,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_VDC_RMtTq,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_VDC_RMtTq,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_VDC_PTSt,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_VDC_PTSt,
        PDUR_CANIF,

    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ECAS_Diag_Resp[1] =
{
    PDUR_DESTPDU_CanTP_PhyResp,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ECAS_EDC_RemoteDiag[1] =
{
    PDUR_DESTPDU_ECAS_EDC_RemoteDiag,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ECAS_RemoteDiag[1] =
{
    PDUR_DESTPDU_ECAS_RemoteDiag,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ECAS_State[1] =
{
    PDUR_DESTPDU_ECAS_State,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ECAS_EDC_Test[1] =
{
    PDUR_DESTPDU_ECAS_EDC_Test,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ECAS_EDC_State[1] =
{
    PDUR_DESTPDU_ECAS_EDC_State,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ECAS_Diag_PhyReq[1] =
{
    PDUR_DESTPDU_Dcm_PhyReq,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_FuncReq[1] =
{
    PDUR_DESTPDU_Dcm_FunReq,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_EPB_State_R[1] =
{
    PDUR_DESTPDU_COM_EPB_State_R,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_IPB_ADS[1] =
{
    PDUR_DESTPDU_COM_IPB_ADS,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VIU_Route_SUS[1] =
{
    PDUR_DESTPDU_COM_VIU_Route_SUS,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VIU_DoorLock[1] =
{
    PDUR_DESTPDU_COM_VIU_DoorLock,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VIU_Info[1] =
{
    PDUR_DESTPDU_COM_VIU_Info,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_EPS_State[1] =
{
    PDUR_DESTPDU_COM_EPS_State,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ABM_State[1] =
{
    PDUR_DESTPDU_COM_ABM_State,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_IPB_State1[1] =
{
    PDUR_DESTPDU_COM_IPB_State1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_IPB_Tq[1] =
{
    PDUR_DESTPDU_COM_IPB_Tq,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_IPB_Wheel[1] =
{
    PDUR_DESTPDU_COM_IPB_Wheel,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TBOX_TimeInfo[1] =
{
    PDUR_DESTPDU_COM_TBOX_TimeInfo,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ScrToECAS[1] =
{
    PDUR_DESTPDU_COM_ScrToECAS,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ECASToScr[1] =
{
    PDUR_DESTPDU_ECASToScr,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BT_Master[1] =
{
    PDUR_DESTPDU_Com_BT_Master,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BT_Slave[1] =
{
    PDUR_DESTPDU_BT_Slave,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ECAS_DV_BA_Req[1] =
{
    PDUR_DESTPDU_COM_ECAS_DV_BA_Req,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CANNM_USERDATA[1] =
{
    PDUR_DESTPDU_CanNmUserDataTxPdu,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VIU_Config[1] =
{
    PDUR_DESTPDU_COM_VIU_Config,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VIU_ConfigTrig[1] =
{
    PDUR_DESTPDU_COM_VIU_ConfigTrig,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ADS_ECAS[1] =
{
    PDUR_DESTPDU_COM_ADS_ECAS,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ADS_State[1] =
{
    PDUR_DESTPDU_COM_ADS_State,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VDC_CDCSet[1] =
{
    PDUR_DESTPDU_COM_VDC_CDCSet,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VDC_VIU_BodyInfo[1] =
{
    PDUR_DESTPDU_COM_VDC_VIU_BodyInfo,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VDC_FMtTq[1] =
{
    PDUR_DESTPDU_COM_VDC_FMtTq,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VDC_RMtTq[1] =
{
    PDUR_DESTPDU_COM_VDC_RMtTq,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VDC_PTSt[1] =
{
    PDUR_DESTPDU_COM_VDC_PTSt,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRRoutingPathType,PDUR_CONST)
PduR_RoutingPathConfigData0[34] =
{
    {
        PDUR_SRCPDU_Dcm_PhyResp,
        1u,
        PduR_PDUR_ROUTING_ECAS_Diag_Resp,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_ECAS_EDC_RemoteDiag,
        1u,
        PduR_PDUR_ROUTING_ECAS_EDC_RemoteDiag,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_ECAS_RemoteDiag,
        1u,
        PduR_PDUR_ROUTING_ECAS_RemoteDiag,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_ECAS_State,
        1u,
        PduR_PDUR_ROUTING_ECAS_State,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_ECAS_EDC_Test,
        1u,
        PduR_PDUR_ROUTING_ECAS_EDC_Test,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_ECAS_EDC_State,
        1u,
        PduR_PDUR_ROUTING_ECAS_EDC_State,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CanTp_PhyReq,
        1u,
        PduR_PDUR_ROUTING_ECAS_Diag_PhyReq,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CanTp_FunReq,
        1u,
        PduR_PDUR_ROUTING_Diag_FuncReq,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_EPB_State_R,
        1u,
        PduR_PDUR_ROUTING_EPB_State_R,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_IPB_ADS,
        1u,
        PduR_PDUR_ROUTING_IPB_ADS,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_VIU_Route_SUS,
        1u,
        PduR_PDUR_ROUTING_VIU_Route_SUS,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_VIU_DoorLock,
        1u,
        PduR_PDUR_ROUTING_VIU_DoorLock,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_VIU_Info,
        1u,
        PduR_PDUR_ROUTING_VIU_Info,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_EPS_State,
        1u,
        PduR_PDUR_ROUTING_EPS_State,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ABM_State,
        1u,
        PduR_PDUR_ROUTING_ABM_State,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_IPB_State1,
        1u,
        PduR_PDUR_ROUTING_IPB_State1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_IPB_Tq,
        1u,
        PduR_PDUR_ROUTING_IPB_Tq,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_IPB_Wheel,
        1u,
        PduR_PDUR_ROUTING_IPB_Wheel,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_TBOX_TimeInfo,
        1u,
        PduR_PDUR_ROUTING_TBOX_TimeInfo,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ScrToECAS,
        1u,
        PduR_PDUR_ROUTING_ScrToECAS,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_ECASToScr,
        1u,
        PduR_PDUR_ROUTING_ECASToScr,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BT_Master,
        1u,
        PduR_PDUR_ROUTING_BT_Master,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_BT_Slave,
        1u,
        PduR_PDUR_ROUTING_BT_Slave,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ECAS_DV_BA_Req,
        1u,
        PduR_PDUR_ROUTING_ECAS_DV_BA_Req,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ComCanNmUserDataTxPdu,
        1u,
        PduR_PDUR_ROUTING_CANNM_USERDATA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_VIU_Config,
        1u,
        PduR_PDUR_ROUTING_VIU_Config,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_VIU_ConfigTrig,
        1u,
        PduR_PDUR_ROUTING_VIU_ConfigTrig,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ADS_ECAS,
        1u,
        PduR_PDUR_ROUTING_ADS_ECAS,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ADS_State,
        1u,
        PduR_PDUR_ROUTING_ADS_State,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_VDC_CDCSet,
        1u,
        PduR_PDUR_ROUTING_VDC_CDCSet,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_VDC_VIU_BodyInfo,
        1u,
        PduR_PDUR_ROUTING_VDC_VIU_BodyInfo,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_VDC_FMtTq,
        1u,
        PduR_PDUR_ROUTING_VDC_FMtTq,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_VDC_RMtTq,
        1u,
        PduR_PDUR_ROUTING_VDC_RMtTq,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_VDC_PTSt,
        1u,
        PduR_PDUR_ROUTING_VDC_PTSt,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRRoutingTableType,PDUR_CONST)
PduR_RoutingTableConfigData[1] =
{
   {
      PduR_RoutingPathConfigData0
   }
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
const PduR_PBConfigType PduR_PBConfigData =
{
    0u,
    NULL_PTR,
    PduR_RoutingTableConfigData,
    PduR_SrcPduConfigData,
    PduR_DestPduConfigData,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

