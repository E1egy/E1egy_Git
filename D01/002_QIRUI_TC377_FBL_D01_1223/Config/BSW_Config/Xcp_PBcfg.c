/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Xcp_PBcfg.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2022-11-24 17:36:06>
 */
/*============================================================================*/

#include "Xcp.h"
#include "CanIf_Cfg.h"

/*
 *  Tx & Rx Pdu Config
 */
#define XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"    
const Xcp_TxPduType Xcp_TxPdu[XCP_TX_PDU_NUMBER_MAX] =
{
    {
        XCP_XCP_Slave_0x60f,    /* XcpLocalTxPduId */
        CANIF_TXPDU_XCP_Slave_0x60f                /* LowLayerTxPduId */
    }
};
#define XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"    

#define XCP_START_SEC_CONST_PBCFG_16
#include "Xcp_MemMap.h"
const Xcp_RxPduType Xcp_RxPdu[XCP_RX_PDU_NUMBER_MAX] =
{
    {
        XCP_XCP_Master_0x601    /* XcpLocalRxPduId */
    }
};
#define XCP_STOP_SEC_CONST_PBCFG_16
#include "Xcp_MemMap.h"    

#define XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"    
const Xcp_PduType Xcp_Pdu =
{
    &Xcp_RxPdu[0],
    &Xcp_TxPdu[0]
};
#define XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"    

#define XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"    
const Xcp_PduType Xcp_Daq_Pdu[XCP_MAX_DAQ] =
{
    {
        NULL_PTR,
        &Xcp_TxPdu[0]
    },
};
#define XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"    

#define XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"    
const Xcp_ConfigType Xcp_PBConfig =
{
    XCP_RX_PDU_NUMBER_MAX,
    XCP_TX_PDU_NUMBER_MAX,
    &Xcp_Pdu
};
#define XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "Xcp_MemMap.h"    
