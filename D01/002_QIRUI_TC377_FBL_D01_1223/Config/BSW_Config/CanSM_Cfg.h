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
**  FILENAME    : CanSM_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2023/01/06 16:29:50                                         **
**  Author      : wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile configuration parameter of CANSM                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef CANSM_CFG_H
#define CANSM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"
/*generated by configure parameter CanSMGetBusOffDelayHeader*/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* development error tracer switch */
#define CANSM_DEV_ERROR_DETECT      STD_ON                /* CanSMDevErrorDetect */

/*<User_GetBusOffDelay> callout function*/
#define CANSM_GET_BUSOFF_DELAY_FUNCTION_USED   STD_OFF

/*Selects support of Pretended Network features in CanSM*/
#define CANSM_ICOM_SUPPORT                   STD_OFF                        /*CanSMIcomSupport */

/*Enables or disables support of partial networking*/
#define CANSM_PNC_SUPPORT                    STD_OFF                           /*CanSMPncSupport */

/*Enables or disables support of CanSM_SetBaudrate*/
#define CANSM_SET_BAUDRATE_API               STD_OFF                /*CanSMSetBaudrateApi */

/*Determines whether the ECU passive feature is supported by CanSM*/
#define CANSM_TX_OFFLINE_ACTIVE_SUPPORT      STD_OFF                /*CanSMTxOfflineActiveSupport */

/* version information switch */
#define CANSM_VERSION_INFO_API               STD_OFF                            /*CanSMVersionInfoApi */

/* PN filter functionality on the indicated NM channel*/
#define CANSM_CANNM_CONF_PN_AVA            STD_OFF

#define CANSM_DEM_SUPPORT                    STD_OFF

#define CANSM_MAINFUNCTION_PERIOD            5u
/* CanSM network handle number */
#define CANSM_NETWORK_NUM                    2u                                    /*CanSMManagerNetwork number */

#define CANSM_TRCV_NUM                       0u

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif /* CANSM_CFG_H */

