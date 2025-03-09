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
**  FILENAME    : PduR_Cfg.h                                                  **
**                                                                            **
**  Created on  : 2023/02/27 21:42:18                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef  PDUR_CFG_H
#define  PDUR_CFG_H
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "ComStack_Types.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_CFG_H_AR_MAJOR_VERSION  4u
#define PDUR_CFG_H_AR_MINOR_VERSION  2u
#define PDUR_CFG_H_AR_PATCH_VERSION  2u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define PDUR_ZERO_COST_OPERATION        STD_OFF

#define PDUR_DEV_ERROR_DETECT           STD_OFF

#define PDUR_META_DATA_SUPPORT          STD_OFF

#define PDUR_VERSION_INFO_API           STD_OFF

#define PDUR_BSW_MODULE_SUM             5u
#define PDUR_CANIF      0u
#define PDUR_COM      1u
#define PDUR_CANNM      2u
#define PDUR_CANTP      3u
#define PDUR_DCM      4u

#define PDUR_CANIF_SUPPORT        STD_ON
#define PDUR_CANTP_SUPPORT        STD_ON
#define PDUR_J1939TP_SUPPORT      STD_OFF
#define PDUR_COM_SUPPORT          STD_ON
#define PDUR_DCM_SUPPORT          STD_ON
#define PDUR_J1939DCM_SUPPORT     STD_OFF
#define PDUR_IPDUM_SUPPORT        STD_OFF
#define PDUR_J1939RM_SUPPORT      STD_OFF
#define PDUR_LDCOM_SUPPORT        STD_OFF
#define PDUR_SECOC_SUPPORT        STD_OFF
#define PDUR_DBG_SUPPORT          STD_OFF
#define PDUR_CANNM_SUPPORT        STD_ON
#define PDUR_OSEKNM_SUPPORT       STD_OFF
#define PDUR_LINIF_SUPPORT        STD_OFF
#define PDUR_LINTP_SUPPORT        STD_OFF
#define PDUR_FRIF_SUPPORT         STD_OFF
#define PDUR_FRNM_SUPPORT         STD_OFF
#define PDUR_DOIP_SUPPORT         STD_OFF
#define PDUR_SOAD_SUPPORT         STD_OFF
#define PDUR_UDPNM_SUPPORT        STD_OFF
#define PDUR_DLT_SUPPORT          STD_OFF
#define PDUR_SOMEIPTP_SUPPORT     STD_OFF

#define PDUR_TRANSMIT_SUPPORT                 STD_ON

#define PDUR_CANCEL_TRANSMIT                       STD_ON
#define PDUR_CANIF_CANCEL_TRANSMIT                 STD_OFF
#define PDUR_CANTP_CANCEL_TRANSMIT                 STD_OFF
#define PDUR_J1939TP_CANCEL_TRANSMIT               STD_OFF
#define PDUR_SECOC_CANCEL_TRANSMIT                 STD_OFF
#define PDUR_LINIF_CANCEL_TRANSMIT                 STD_OFF
#define PDUR_DOIP_CANCEL_TRANSMIT                  STD_OFF
#define PDUR_SOAD_CANCEL_TRANSMIT                  STD_OFF
#define PDUR_FRIF_CANCEL_TRANSMIT                  STD_OFF

#define PDUR_CHANGE_PARAMETER                      STD_OFF
#define PDUR_CANTP_CHANGE_PARAMETER                STD_OFF
#define PDUR_J1939TP_CHANGE_PARAMETER              STD_OFF
#define PDUR_LINIF_CHANGE_PARAMETER                STD_OFF
#define PDUR_SOAD_CHANGE_PARAMETER                 STD_OFF

#define PDUR_CANCEL_RECEIVE                        STD_OFF
#define PDUR_CANTP_CANCEL_RECEIVE                  STD_OFF
#define PDUR_J1939TP_CANCEL_RECEIVE                STD_OFF
#define PDUR_LINIF_CANCEL_RECEIVE                  STD_OFF
#define PDUR_DOIP_CANCEL_RECEIVE                   STD_OFF
#define PDUR_SOAD_CANCEL_RECEIVE                   STD_OFF
#define PDUR_SECOC_CANCEL_RECEIVE                  STD_OFF

#define PDUR_RX_INDICATION                         STD_ON
#define PDUR_TX_CONFIRMATION                       STD_ON
#define PDUR_TRIGGER_TRANSMIT                      STD_ON
#define PDUR_COM_TRIGGER_TRANSMIT                  STD_ON
#define PDUR_LDCOM_TRIGGER_TRANSMIT                STD_OFF
#define PDUR_DLT_TRIGGER_TRANSMIT                  STD_OFF
#define PDUR_SECOC_TRIGGER_TRANSMIT                STD_OFF
#define PDUR_IPDUM_TRIGGER_TRANSMIT                STD_OFF
#define PDUR_SOMEIPTP_TRIGGER_TRANSMIT             STD_OFF

#define PDUR_TP_STARTOFRECEPTION_TRANSMIT     STD_ON
#define PDUR_TP_COPYRXDATA                    STD_ON
#define PDUR_TP_RXINDICATION                  STD_ON
#define PDUR_TP_COPYTXDATA                    STD_ON
#define PDUR_TP_TXCONFIRMATION                STD_ON

#define PDUR_SRC_PDU_SUM           34u

#define PDUR_SRCPDU_Dcm_PhyResp          0u
#define PDUR_SRCPDU_COM_ECAS_EDC_RemoteDiag          1u
#define PDUR_SRCPDU_COM_ECAS_RemoteDiag          2u
#define PDUR_SRCPDU_COM_ECAS_State          3u
#define PDUR_SRCPDU_COM_ECAS_EDC_Test          4u
#define PDUR_SRCPDU_COM_ECAS_EDC_State          5u
#define PDUR_SRCPDU_CanTp_PhyReq          6u
#define PDUR_SRCPDU_CanTp_FunReq          7u
#define PDUR_SRCPDU_EPB_State_R          8u
#define PDUR_SRCPDU_IPB_ADS          9u
#define PDUR_SRCPDU_VIU_Route_SUS          10u
#define PDUR_SRCPDU_VIU_DoorLock          11u
#define PDUR_SRCPDU_VIU_Info          12u
#define PDUR_SRCPDU_EPS_State          13u
#define PDUR_SRCPDU_ABM_State          14u
#define PDUR_SRCPDU_IPB_State1          15u
#define PDUR_SRCPDU_IPB_Tq          16u
#define PDUR_SRCPDU_IPB_Wheel          17u
#define PDUR_SRCPDU_TBOX_TimeInfo          18u
#define PDUR_SRCPDU_ScrToECAS          19u
#define PDUR_SRCPDU_COM_ECASToScr          20u
#define PDUR_SRCPDU_BT_Master          21u
#define PDUR_SRCPDU_Com_BT_Slave          22u
#define PDUR_SRCPDU_ECAS_DV_BA_Req          23u
#define PDUR_SRCPDU_ComCanNmUserDataTxPdu          24u
#define PDUR_SRCPDU_VIU_Config          25u
#define PDUR_SRCPDU_VIU_ConfigTrig          26u
#define PDUR_SRCPDU_ADS_ECAS          27u
#define PDUR_SRCPDU_ADS_State          28u
#define PDUR_SRCPDU_VDC_CDCSet          29u
#define PDUR_SRCPDU_VDC_VIU_BodyInfo          30u
#define PDUR_SRCPDU_VDC_FMtTq          31u
#define PDUR_SRCPDU_VDC_RMtTq          32u
#define PDUR_SRCPDU_VDC_PTSt          33u

#define PDUR_DEST_PDU_SUM              34u

#define PDUR_DEST_GATEWAY_TP_PDU_SUM   0u

#define PDUR_DESTPDU_CanTP_PhyResp          0u
#define PDUR_DESTPDU_ECAS_EDC_RemoteDiag          1u
#define PDUR_DESTPDU_ECAS_RemoteDiag          2u
#define PDUR_DESTPDU_ECAS_State          3u
#define PDUR_DESTPDU_ECAS_EDC_Test          4u
#define PDUR_DESTPDU_ECAS_EDC_State          5u
#define PDUR_DESTPDU_Dcm_PhyReq          6u
#define PDUR_DESTPDU_Dcm_FunReq          7u
#define PDUR_DESTPDU_COM_EPB_State_R          8u
#define PDUR_DESTPDU_COM_IPB_ADS          9u
#define PDUR_DESTPDU_COM_VIU_Route_SUS          10u
#define PDUR_DESTPDU_COM_VIU_DoorLock          11u
#define PDUR_DESTPDU_COM_VIU_Info          12u
#define PDUR_DESTPDU_COM_EPS_State          13u
#define PDUR_DESTPDU_COM_ABM_State          14u
#define PDUR_DESTPDU_COM_IPB_State1          15u
#define PDUR_DESTPDU_COM_IPB_Tq          16u
#define PDUR_DESTPDU_COM_IPB_Wheel          17u
#define PDUR_DESTPDU_COM_TBOX_TimeInfo          18u
#define PDUR_DESTPDU_COM_ScrToECAS          19u
#define PDUR_DESTPDU_ECASToScr          20u
#define PDUR_DESTPDU_Com_BT_Master          21u
#define PDUR_DESTPDU_BT_Slave          22u
#define PDUR_DESTPDU_COM_ECAS_DV_BA_Req          23u
#define PDUR_DESTPDU_CanNmUserDataTxPdu          24u
#define PDUR_DESTPDU_COM_VIU_Config          25u
#define PDUR_DESTPDU_COM_VIU_ConfigTrig          26u
#define PDUR_DESTPDU_COM_ADS_ECAS          27u
#define PDUR_DESTPDU_COM_ADS_State          28u
#define PDUR_DESTPDU_COM_VDC_CDCSet          29u
#define PDUR_DESTPDU_COM_VDC_VIU_BodyInfo          30u
#define PDUR_DESTPDU_COM_VDC_FMtTq          31u
#define PDUR_DESTPDU_COM_VDC_RMtTq          32u
#define PDUR_DESTPDU_COM_VDC_PTSt          33u

#define PDUR_ROUTING_PATH_GROUP_SUM        0u

#define PDUR_SRC_UP_MULTICAST_TX_IF_SUM              0u
#define PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM           0u

#define PDUR_TP_BUFFER_SUM           0u
#define PDUR_TX_BUFFER_SUM           0u

#define PDUR_DEFAULT_VALUE_LENGTH           0u
#define PDUR_DEFAULT_VALUE_PDU                  0u

#endif  /* end of PDUR_CFG_H */

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

