
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
**  FILENAME    : CanIf_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2023/02/27 21:42:14                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : cfg parameter declaration of CanIf                          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef CANIF_CFG_H
#define CANIF_CFG_H

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/
#define CANIF_CFG_H_AR_MAJOR_VERSION    4u
#define CANIF_CFG_H_AR_MINOR_VERSION    2u
#define CANIF_CFG_H_AR_PATCH_VERSION    2u
#define CANIF_CFG_H_SW_MAJOR_VERSION    2u
#define CANIF_CFG_H_SW_MINOR_VERSION    0u
#define CANIF_CFG_H_SW_PATCH_VERSION    0u

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#define CANIF_SOFTWARE_FILTER_BINARY                0u
#define CANIF_SOFTWARE_FILTER_INDEX                 1u
#define CANIF_SOFTWARE_FILTER_LINEAR                2u
#define CANIF_SOFTWARE_FILTER_TABLE                 3u

#define CANIF_FIXED_BUFFER            STD_ON

#define CANIF_PRIVATE_DLC_CHECK       STD_ON

#define CANIF_SOFTWARE_FILTER_TYPE    CANIF_SOFTWARE_FILTER_LINEAR

#define CANIF_SUPPORT_TTCAN           STD_OFF

#define CANIF_META_DATA_SUPPORT       STD_OFF

#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT               STD_OFF

#define CANIF_PUBLIC_DEV_ERROR_DETECT                      STD_ON

#define CANIF_PUBLIC_ICOM_SUPPORT                          STD_OFF

#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT                  STD_ON

#define CANIF_PUBLIC_PN_SUPPORT                            STD_OFF

#define CANIF_PUBLIC_READ_RX_PDU_DATA_API                  STD_OFF

#define CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API         STD_OFF

#define CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API         STD_OFF

#define CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API                 STD_OFF

#define CANIF_PUBLIC_TX_BUFFERING                          STD_OFF

#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT            STD_ON

#define CANIF_PUBLIC_VERSION_INFO_API                      STD_ON

#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM              STD_OFF

#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT            STD_OFF

#define CANIF_SET_BAUDRATE_API                             STD_OFF

#define CANIF_TRIGGER_TRANSMIT_SUPPORT            STD_OFF

#define CANIF_TX_OFFLINE_ACTIVE_SUPPORT           STD_OFF

#define CANIF_WAKE_UP_SUPPORT                     STD_ON

#define CANIF_CANDRV_WAKE_UP_SUPPORT              STD_OFF

#define CANIF_CANTRCV_WAKE_UP_SUPPORT             STD_OFF

#define CANIF_WAKEUPSOURCE_MAX                    0x7Fu
/*******************************************************************************************/

#define CANIF_RXPDU_NUMBER              27u
#define CANIF_RXPDU_CanIf_PhyReq         0u
#define CANIF_RXPDU_CanIf_FunReq         1u
#define CANIF_RXPDU_EPB_State_R         2u
#define CANIF_RXPDU_IPB_ADS         3u
#define CANIF_RXPDU_VIU_Route_SUS         4u
#define CANIF_RXPDU_VIU_DoorLock         5u
#define CANIF_RXPDU_VIU_Info         6u
#define CANIF_RXPDU_EPS_State         7u
#define CANIF_RXPDU_ABM_State         8u
#define CANIF_RXPDU_IPB_State1         9u
#define CANIF_RXPDU_IPB_Tq         10u
#define CANIF_RXPDU_IPB_Wheel         11u
#define CANIF_RXPDU_TBOX_TimeInfo         12u
#define CANIF_RXPDU_ScrToECAS         13u
#define CANIF_RXPDU_CANNM_RX_CANFD         14u
#define CANIF_RXPDU_XCP_Master_0x601         15u
#define CANIF_RXPDU_BT_Master         16u
#define CANIF_RXPDU_ECAS_DV_BA_Req         17u
#define CANIF_RXPDU_VIU_Config         18u
#define CANIF_RXPDU_VIU_ConfigTrig         19u
#define CANIF_RXPDU_ADS_ECAS         20u
#define CANIF_RXPDU_ADS_State         21u
#define CANIF_RXPDU_VDC_CDCSet         22u
#define CANIF_RXPDU_VDC_VIU_BodyInfo         23u
#define CANIF_RXPDU_VDC_FMtTq         24u
#define CANIF_RXPDU_VDC_RMtTq         25u
#define CANIF_RXPDU_VDC_PTSt         26u

#define CANIF_TXPDU_NUMBER              10u
#define CANIF_DYNAMIC_TXPDU_NUMBER      0u
#define CANIF_TXPDU_CanIf_PhyResp         0u
#define CANIF_TXPDU_CANNM_TX_CANFD         1u
#define CANIF_TXPDU_ECAS_EDC_RemoteDiag         2u
#define CANIF_TXPDU_ECAS_RemoteDiag         3u
#define CANIF_TXPDU_ECAS_State         4u
#define CANIF_TXPDU_ECAS_EDC_Test         5u
#define CANIF_TXPDU_ECAS_EDC_State         6u
#define CANIF_TXPDU_ECASToScr         7u
#define CANIF_TXPDU_XCP_Slave_0x60f         8u
#define CANIF_TXPDU_BT_Slave         9u

#define CANIF_HRH_NUMBER           27u
#define CANIF_HOH0_HRH_0           0u
#define CANIF_HOH0_HRH_1           1u
#define CANIF_HOH0_HRH_2           2u
#define CANIF_HOH0_HRH_3           3u
#define CANIF_HOH0_HRH_4           4u
#define CANIF_HOH0_HRH_5           5u
#define CANIF_HOH0_HRH_6           6u
#define CANIF_HOH0_HRH_7           7u
#define CANIF_HOH0_HRH_8           8u
#define CANIF_HOH0_HRH_9           9u
#define CANIF_HOH0_HRH_10           10u
#define CANIF_HOH0_HRH_11           11u
#define CANIF_HOH0_HRH_12           12u
#define CANIF_HOH0_HRH_13           13u
#define CANIF_HOH0_HRH_14           14u
#define CANIF_HOH0_HRH_15           15u
#define CANIF_HOH0_HRH_16           16u
#define CANIF_HOH0_HRH_17           17u
#define CANIF_HOH0_HRH_18           18u
#define CANIF_HOH0_HRH_19           19u
#define CANIF_HOH0_HRH_20           20u
#define CANIF_HOH0_HRH_21           21u
#define CANIF_HOH0_HRH_22           22u
#define CANIF_HOH0_HRH_23           23u
#define CANIF_HOH0_HRH_24           24u
#define CANIF_HOH0_HRH_25           25u
#define CANIF_HOH0_HRH_26           26u

#define CANIF_HTH_NUMBER           16u
#define CANIF_HOH0_HTH_0           0u
#define CANIF_HOH0_HTH_1           1u
#define CANIF_HOH0_HTH_2           2u
#define CANIF_HOH0_HTH_3           3u
#define CANIF_HOH0_HTH_4           4u
#define CANIF_HOH0_HTH_5           5u
#define CANIF_HOH0_HTH_6           6u
#define CANIF_HOH0_HTH_7           7u
#define CANIF_HOH0_HTH_8           8u
#define CANIF_HOH0_HTH_9           9u
#define CANIF_HOH0_HTH_10           10u
#define CANIF_HOH0_HTH_11           11u
#define CANIF_HOH0_HTH_12           12u
#define CANIF_HOH0_HTH_13           13u
#define CANIF_HOH0_HTH_14           14u
#define CANIF_HOH0_HTH_15           15u

#define CANIF_TXBUFFER_NUMBER          0u
#define CANIF_RXBUFFER_NUMBER          0u

#define CANIF_RXNOTIFYSTATUS_BUFFER    0u
#define CANIF_TXNOTIFYSTATUS_BUFFER    0u

#define CANIF_CANDRIVER_NUMBER      1u
#define CANIF_CAN_17_MCMCAN    0u
#define CANIF_CANCONTROLLER_NUMBER      2u
#define CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_TEST_CAN    0u
#define CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD    1u

#define CANIF_TRCVDRIVER_NUMBER      0u
#define CANIF_TRCV_NUMBER      0u

#endif
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
