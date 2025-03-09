/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_PBcfg.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-01-26 15:23:03>
 */
/*============================================================================*/

/*============================================================================*/
#ifndef CANTP_PBCFG_H
#define CANTP_PBCFG_H

/*======== [I N C L U D E S]========================*/
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*========[M A C R O S] ==========================*/
/* Total number of channel used in CanTp module. */
#define CANTP_CHANNEL_NUMBER                        0x1u

/*configuration MACRO addressing mode for cutting*/
#define CANTP_EXTENDED_ADDRESSING_SUPPORT           STD_OFF
#define CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT       STD_OFF
#define CANTP_MIXED_ADDRESSING_SUPPORT              STD_OFF
#define CANTP_MIXED29_ADDRESSING_SUPPORT            STD_OFF

/* -------------------- CanTpChannel -------------------- */

/* CanTpRxNSdu_PHY */    
#define CANTP_CanTp_PhyReq                                0x3au/*RxNSdu Id*/
#define CANTP_CanIf_PhyReq                                 0x37u/*RxNPdu Id*/
#define CANTP_CanIf_PhyResp                               0x36u/*TxFcNPdu Id*/

/* CanTpRxNSdu_FUN */    
#define CANTP_CanTp_FunReq                                0x3bu/*RxNSdu Id*/
#define CANTP_CanIf_FunReq                                 0x38u/*RxNPdu Id*/

/* CanTpTxNSdu_RES */    
#define CANTP_CanTP_PhyResp                                0x39u/*TxNSdu Id*/
#define CANTP_CanIf_PhyResp                                 0x36u/*TxNPdu Id*/
#define CANTP_CanIf_PhyReq                               0x37u/*RxFcNPdu Id*/

#ifdef __cplusplus
}
#endif  /* __cplusplus */
#endif /* CANTP_PBCFG_H */
