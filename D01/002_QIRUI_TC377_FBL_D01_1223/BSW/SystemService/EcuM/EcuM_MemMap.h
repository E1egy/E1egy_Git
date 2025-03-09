/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2019)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : EcuM_MemMap.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11.                     **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-06-28  qinchun.yang    R19_11 EcuM initial version.
 *  V2.0.0       2021-04-08  qinchun.yang    R1911 stable version.
 */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*General function.*/
#if defined ECUM_START_SEC_CODE
    #undef ECUM_START_SEC_CODE
    #define START_SEC_CODE
#elif defined ECUM_STOP_SEC_CODE
    #undef ECUM_STOP_SEC_CODE
    #define STOP_SEC_CODE
/*Call-out function.*/
#elif defined ECUM_START_SEC_CALLOUT_CODE
    #undef ECUM_START_SEC_CALLOUT_CODE
    #define START_SEC_CALLOUT_CODE
#elif defined ECUM_STOP_SEC_CALLOUT_CODE
    #undef ECUM_STOP_SEC_CALLOUT_CODE
    #define STOP_SEC_CALLOUT_CODE
/*Call-back function.*/
#elif defined ECUM_START_SEC_SETWAKEUPEVENT_CALLBACK_CODE
    #undef ECUM_START_SEC_SETWAKEUPEVENT_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined ECUM_STOP_SEC_SETWAKEUPEVENT_CALLBACK_CODE
    #undef ECUM_STOP_SEC_SETWAKEUPEVENT_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined ECUM_START_SEC_VALIDATEWAKEUPEVENT_CALLBACK_CODE
    #undef ECUM_START_SEC_VALIDATEWAKEUPEVENT_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined ECUM_STOP_SEC_VALIDATEWAKEUPEVENT_CALLBACK_CODE
    #undef ECUM_STOP_SEC_VALIDATEWAKEUPEVENT_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined ECUM_START_SEC_CHECKWAKEUP_CALLBACK_CODE
    #undef ECUM_START_SEC_CHECKWAKEUP_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined ECUM_STOP_SEC_CHECKWAKEUP_CALLBACK_CODE
    #undef ECUM_STOP_SEC_CHECKWAKEUP_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE
/*Bss data(clear)*/
#elif defined ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined ECUM_START_SEC_VAR_CLEARED_PTR
    #undef ECUM_START_SEC_VAR_CLEARED_PTR
    #define START_SEC_VAR_CLEARED_PTR
#elif defined ECUM_STOP_SEC_VAR_CLEARED_PTR
    #undef ECUM_STOP_SEC_VAR_CLEARED_PTR
    #define STOP_SEC_VAR_CLEARED_PTR

#elif defined ECUM_START_SEC_VAR_CLEARED_32
    #undef ECUM_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32
#elif defined ECUM_STOP_SEC_VAR_CLEARED_32
    #undef ECUM_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR_CLEARED_32

#elif defined ECUM_START_SEC_VAR_CLEARED_16
    #undef ECUM_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16
#elif defined ECUM_STOP_SEC_VAR_CLEARED_16
    #undef ECUM_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR_CLEARED_16

#elif defined ECUM_START_SEC_VAR_CLEARED_8
    #undef ECUM_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8
#elif defined ECUM_STOP_SEC_VAR_CLEARED_8
    #undef ECUM_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR_CLEARED_8

#elif defined ECUM_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ECUM_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN
#elif defined ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR_CLEARED_BOOLEAN
/*Init data(clear)*/
#elif defined ECUM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED
#elif defined ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_INIT_UNSPECIFIED

#elif defined ECUM_START_SEC_VAR_INIT_PTR
    #undef ECUM_START_SEC_VAR_INIT_PTR
    #define START_SEC_VAR_INIT_PTR
#elif defined ECUM_STOP_SEC_VAR_INIT_PTR
    #undef ECUM_STOP_SEC_VAR_INIT_PTR
    #define STOP_SEC_VAR_INIT_PTR

#elif defined ECUM_START_SEC_VAR_INIT_32
    #undef ECUM_START_SEC_VAR_INIT_32
    #define START_SEC_VAR_INIT_32
#elif defined ECUM_STOP_SEC_VAR_INIT_32
    #undef ECUM_STOP_SEC_VAR_INIT_32
    #define STOP_SEC_VAR_INIT_32

#elif defined ECUM_START_SEC_VAR_INIT_16
    #undef ECUM_START_SEC_VAR_INIT_16
    #define START_SEC_VAR_INIT_16
#elif defined ECUM_STOP_SEC_VAR_INIT_16
    #undef ECUM_STOP_SEC_VAR_INIT_16
    #define STOP_SEC_VAR_INIT_16

#elif defined ECUM_START_SEC_VAR_INIT_8
    #undef ECUM_START_SEC_VAR_INIT_8
    #define START_SEC_VAR_INIT_8
#elif defined ECUM_STOP_SEC_VAR_INIT_8
    #undef ECUM_STOP_SEC_VAR_INIT_8
    #define STOP_SEC_VAR_INIT_8

#elif defined ECUM_START_SEC_VAR_INIT_BOOLEAN
    #undef ECUM_START_SEC_VAR_INIT_BOOLEAN
    #define START_SEC_VAR_INIT_BOOLEAN
#elif defined ECUM_STOP_SEC_VAR_INIT_BOOLEAN
    #undef ECUM_STOP_SEC_VAR_INIT_BOOLEAN
    #define STOP_SEC_VAR_INIT_BOOLEAN
/*No-Init data(clear)*/
#elif defined ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#elif defined ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_NO_INIT_UNSPECIFIED

#elif defined ECUM_START_SEC_VAR_NO_INIT_PTR
    #undef ECUM_START_SEC_VAR_NO_INIT_PTR
    #define START_SEC_VAR_NO_INIT_PTR
#elif defined ECUM_STOP_SEC_VAR_NO_INIT_PTR
    #undef ECUM_STOP_SEC_VAR_NO_INIT_PTR
    #define STOP_SEC_VAR_NO_INIT_PTR

#elif defined ECUM_START_SEC_VAR_NO_INIT_32
    #undef ECUM_START_SEC_VAR_NO_INIT_32
    #define START_SEC_VAR_NO_INIT_32
#elif defined ECUM_STOP_SEC_VAR_NO_INIT_32
    #undef ECUM_STOP_SEC_VAR_NO_INIT_32
    #define STOP_SEC_VAR_NO_INIT_32

#elif defined ECUM_START_SEC_VAR_NO_INIT_16
    #undef ECUM_START_SEC_VAR_NO_INIT_16
    #define START_SEC_VAR_NO_INIT_16
#elif defined ECUM_STOP_SEC_VAR_NO_INIT_16
    #undef ECUM_STOP_SEC_VAR_NO_INIT_16
    #define STOP_SEC_VAR_NO_INIT_16

#elif defined ECUM_START_SEC_VAR_NO_INIT_8
    #undef ECUM_START_SEC_VAR_NO_INIT_8
    #define START_SEC_VAR_NO_INIT_8
#elif defined ECUM_STOP_SEC_VAR_NO_INIT_8
    #undef ECUM_STOP_SEC_VAR_NO_INIT_8
    #define STOP_SEC_VAR_NO_INIT_8

#elif defined ECUM_START_SEC_VAR_NO_INIT_BOOLEAN
    #undef ECUM_START_SEC_VAR_NO_INIT_BOOLEAN
    #define START_SEC_VAR_NO_INIT_BOOLEAN
#elif defined ECUM_STOP_SEC_VAR_NO_INIT_BOOLEAN
    #undef ECUM_STOP_SEC_VAR_NO_INIT_BOOLEAN
    #define STOP_SEC_VAR_NO_INIT_BOOLEAN
/*Config data(PB Root.for EcuM pbcfg).*/
#elif defined ECUM_START_SEC_PBCFG_GLOBALROOT
    #undef ECUM_START_SEC_PBCFG_GLOBALROOT
    #define START_SEC_PBCFG_GLOBALROOT
#elif defined ECUM_STOP_SEC_PBCFG_GLOBALROOT
    #undef ECUM_STOP_SEC_PBCFG_GLOBALROOT
    #define STOP_SEC_PBCFG_GLOBALROOT
/*Config data(PB,for other BSW module.).*/
#elif defined ECUM_START_SEC_CONST_PBCFG_UNSPECIFIED
    #undef ECUM_START_SEC_CONST_PBCFG_UNSPECIFIED
    #define START_SEC_CONST_PBCFG_UNSPECIFIED
#elif defined ECUM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
    #undef ECUM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
    #define STOP_SEC_CONST_PBCFG_UNSPECIFIED

#elif defined ECUM_START_SEC_CONST_PBCFG_PTR
    #undef ECUM_START_SEC_CONST_PBCFG_PTR
    #define START_SEC_CONST_PBCFG_PTR
#elif defined ECUM_STOP_SEC_CONST_PBCFG_PTR
    #undef ECUM_STOP_SEC_CONST_PBCFG_PTR
    #define STOP_SEC_CONST_PBCFG_PTR

#elif defined ECUM_START_SEC_CONST_PBCFG_32
    #undef ECUM_START_SEC_CONST_PBCFG_32
    #define START_SEC_CONST_PBCFG_32
#elif defined ECUM_STOP_SEC_CONST_PBCFG_32
    #undef ECUM_STOP_SEC_CONST_PBCFG_32
    #define STOP_SEC_CONST_PBCFG_32

#elif defined ECUM_START_SEC_CONST_PBCFG_16
    #undef ECUM_START_SEC_CONST_PBCFG_16
    #define START_SEC_CONST_PBCFG_16
#elif defined ECUM_STOP_SEC_CONST_PBCFG_16
    #undef ECUM_STOP_SEC_CONST_PBCFG_16
    #define STOP_SEC_CONST_PBCFG_16

#elif defined ECUM_START_SEC_CONST_PBCFG_8
    #undef ECUM_START_SEC_CONST_PBCFG_8
    #define START_SEC_CONST_PBCFG_8
#elif defined ECUM_STOP_SEC_CONST_PBCFG_8
    #undef ECUM_STOP_SEC_CONST_PBCFG_8
    #define STOP_SEC_CONST_PBCFG_8

#elif defined ECUM_START_SEC_CONST_PBCFG_BOOLEAN
    #undef ECUM_START_SEC_CONST_PBCFG_BOOLEAN
    #define START_SEC_CONST_PBCFG_BOOLEAN
#elif defined ECUM_STOP_SEC_CONST_PBCFG_BOOLEAN
    #undef ECUM_STOP_SEC_CONST_PBCFG_BOOLEAN
    #define STOP_SEC_CONST_PBCFG_BOOLEAN
/*Config data(PC/LC).*/
#elif defined ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define STOP_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined ECUM_START_SEC_CONFIG_DATA_PTR
    #undef ECUM_START_SEC_CONFIG_DATA_PTR
    #define START_SEC_CONFIG_DATA_PTR
#elif defined ECUM_STOP_SEC_CONFIG_DATA_PTR
    #undef ECUM_STOP_SEC_CONFIG_DATA_PTR
    #define STOP_SEC_CONFIG_DATA_PTR

#elif defined ECUM_START_SEC_CONFIG_DATA_32
    #undef ECUM_START_SEC_CONFIG_DATA_32
    #define START_SEC_CONFIG_DATA_32
#elif defined ECUM_STOP_SEC_CONFIG_DATA_32
    #undef ECUM_STOP_SEC_CONFIG_DATA_32
    #define STOP_SEC_CONFIG_DATA_32

#elif defined ECUM_START_SEC_CONFIG_DATA_16
    #undef ECUM_START_SEC_CONFIG_DATA_16
    #define START_SEC_CONFIG_DATA_16
#elif defined ECUM_STOP_SEC_CONFIG_DATA_16
    #undef ECUM_STOP_SEC_CONFIG_DATA_16
    #define STOP_SEC_CONFIG_DATA_16

#elif defined ECUM_START_SEC_CONFIG_DATA_8
    #undef ECUM_START_SEC_CONFIG_DATA_8
    #define START_SEC_CONFIG_DATA_8
#elif defined ECUM_STOP_SEC_CONFIG_DATA_8
    #undef ECUM_STOP_SEC_CONFIG_DATA_8
    #define STOP_SEC_CONFIG_DATA_8

#elif defined ECUM_START_SEC_CONFIG_DATA_BOOLEAN
    #undef ECUM_START_SEC_CONFIG_DATA_BOOLEAN
    #define START_SEC_CONFIG_DATA_BOOLEAN
#elif defined ECUM_STOP_SEC_CONFIG_DATA_BOOLEAN
    #undef ECUM_STOP_SEC_CONFIG_DATA_BOOLEAN
    #define STOP_SEC_CONFIG_DATA_BOOLEAN
/*Const data.*/
#elif defined ECUM_START_SEC_CONST_UNSPECIFIED
    #undef ECUM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined ECUM_STOP_SEC_CONST_UNSPECIFIED
    #undef ECUM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST_UNSPECIFIED

#elif defined ECUM_START_SEC_CONST_PTR
    #undef ECUM_START_SEC_CONST_PTR
    #define START_SEC_CONST_PTR
#elif defined ECUM_STOP_SEC_CONST_PTR
    #undef ECUM_STOP_SEC_CONST_PTR
    #define STOP_SEC_CONST_PTR

#elif defined ECUM_START_SEC_CONST_32
    #undef ECUM_START_SEC_CONST_32
    #define START_SEC_CONST_32
#elif defined ECUM_STOP_SEC_CONST_32
    #undef ECUM_STOP_SEC_CONST_32
    #define STOP_SEC_CONST_32

#elif defined ECUM_START_SEC_CONST_16
    #undef ECUM_START_SEC_CONST_16
    #define START_SEC_CONST_16
#elif defined ECUM_STOP_SEC_CONST_16
    #undef ECUM_STOP_SEC_CONST_16
    #define STOP_SEC_CONST_16

#elif defined ECUM_START_SEC_CONST_8
    #undef ECUM_START_SEC_CONST_8
    #define START_SEC_CONST_8
#elif defined ECUM_STOP_SEC_CONST_8
    #undef ECUM_STOP_SEC_CONST_8
    #define STOP_SEC_CONST_8

#elif defined ECUM_START_SEC_CONST_BOOLEAN
    #undef ECUM_START_SEC_CONST_BOOLEAN
    #define START_SEC_CONST_BOOLEAN
#elif defined ECUM_STOP_SEC_CONST_BOOLEAN
    #undef ECUM_STOP_SEC_CONST_BOOLEAN
    #define STOP_SEC_CONST_BOOLEAN
/*Share data.*/
#elif defined ECUM_START_SEC_VAR_CLEARED_SHARE_UNSPECIFIED
    #undef ECUM_START_SEC_VAR_CLEARED_SHARE_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_SHARE_UNSPECIFIED
#elif defined ECUM_STOP_SEC_VAR_CLEARED_SHARE_UNSPECIFIED
    #undef ECUM_STOP_SEC_VAR_CLEARED_SHARE_UNSPECIFIED
    #define STOP_SEC_VAR_CLEARED_SHARE_UNSPECIFIED

#elif defined ECUM_START_SEC_VAR_CLEARED_SHARE_PTR
    #undef ECUM_START_SEC_VAR_CLEARED_SHARE_PTR
    #define START_SEC_VAR_CLEARED_SHARE_PTR
#elif defined ECUM_STOP_SEC_VAR_CLEARED_SHARE_PTR
    #undef ECUM_STOP_SEC_VAR_CLEARED_SHARE_PTR
    #define STOP_SEC_VAR_CLEARED_SHARE_PTR

#elif defined ECUM_START_SEC_VAR_CLEARED_SHARE_32
    #undef ECUM_START_SEC_VAR_CLEARED_SHARE_32
    #define START_SEC_VAR_CLEARED_SHARE_32
#elif defined ECUM_STOP_SEC_VAR_CLEARED_SHARE_32
    #undef ECUM_STOP_SEC_VAR_CLEARED_SHARE_32
    #define STOP_SEC_VAR_CLEARED_SHARE_32

#elif defined ECUM_START_SEC_VAR_CLEARED_SHARE_16
    #undef ECUM_START_SEC_VAR_CLEARED_SHARE_16
    #define START_SEC_VAR_CLEARED_SHARE_16
#elif defined ECUM_STOP_SEC_VAR_CLEARED_SHARE_16
    #undef ECUM_STOP_SEC_VAR_CLEARED_SHARE_16
    #define STOP_SEC_VAR_CLEARED_SHARE_16

#elif defined ECUM_START_SEC_VAR_CLEARED_SHARE_8
    #undef ECUM_START_SEC_VAR_CLEARED_SHARE_8
    #define START_SEC_VAR_CLEARED_SHARE_8
#elif defined ECUM_STOP_SEC_VAR_CLEARED_SHARE_8
    #undef ECUM_STOP_SEC_VAR_CLEARED_SHARE_8
    #define STOP_SEC_VAR_CLEARED_SHARE_8

#elif defined ECUM_START_SEC_VAR_CLEARED_SHARE_BOOLEAN
    #undef ECUM_START_SEC_VAR_CLEARED_SHARE_BOOLEAN
    #define START_SEC_VAR_CLEARED_SHARE_BOOLEAN
#elif defined ECUM_STOP_SEC_VAR_CLEARED_SHARE_BOOLEAN
    #undef ECUM_STOP_SEC_VAR_CLEARED_SHARE_BOOLEAN
    #define STOP_SEC_VAR_CLEARED_SHARE_BOOLEAN
#else
#error "EcuM not include this section"
#endif
#include "MemMap.h"
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

