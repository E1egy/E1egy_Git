/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-01-26 15:23:03>
 */
/*============================================================================*/

/*============================================================================*/
#ifndef CANTP_CFG_H
#define CANTP_CFG_H

/*======== [I N C L U D E S]========================*/
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*========[M A C R O S] ==========================*/
/* Switches the Development Error Detection and Notification ON or OFF */
#define CANTP_DEV_ERROR_DETECT                     STD_ON

/* Switches the time service ON or OFF */
#define CANTP_TM                                   STD_OFF

/* The time for MainFunction,expressed as the value with ms */
#define CANTP_MAIN_FUNCTION_PERIOD                 0x0u

/* Used for the initialization of unused bytes with a certain value */
#define CANTP_PADDING_BYTE                         0xAAu

/* Preprocessor switch for enabling Transmit Cancellation and Receive Cancellation. */
#define CANTP_TC                                   STD_OFF

/* Preprocessor switch for enabling CanTp_ChangeParameterRequest Api*/
#define CANTP_CHANGE_PARAMETER                     STD_ON

/* Preprocessor switch for enabling CanTpReadParameterApi Api*/
#define CANTP_READ_PARAMETER                       STD_OFF

#define CANTP_VERSION_INFO_API                     STD_OFF

/*Enable support for CAN FD frames*/
#define CANTP_FD                                   STD_ON

#define CANTP_DYN_ID_SUPPORT                       STD_OFF
#define CANTP_GENERIC_CONNECTION_SUPPORT           STD_OFF

/* Total number of channel used in CanTp module. */
#define CANTP_MAX_CHANNEL_NUMBER                   0x1u

#ifdef __cplusplus
}
#endif  /* __cplusplus */
#endif /* CANTP_CFG_H */
