/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2021)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
**************************************************************************** **
**                                                                           **
**  FILENAME    : Cantp_MemMap.h                                             **
**                                                                           **
**  Created on  : 2021/7/30 14:29:43                                         **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION : memmap of CanTp module.                                    **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                           **
**************************************************************************** */

#ifdef CANTP_START_SEC_CODE
    #undef CANTP_START_SEC_CODE
    #define START_SEC_CODE
#elif defined CANTP_STOP_SEC_CODE
    #undef CANTP_STOP_SEC_CODE
    #define STOP_SEC_CODE
#elif defined CANTP_START_SEC_VAR_POWER_ON_INIT_8
    #undef CANTP_START_SEC_VAR_POWER_ON_INIT_8
    #define START_SEC_VAR_POWER_ON_INIT_8
#elif defined CANTP_STOP_SEC_VAR_POWER_ON_INIT_8
    #undef CANTP_STOP_SEC_VAR_POWER_ON_INIT_8
    #define STOP_SEC_VAR_POWER_ON_INIT_8
#elif defined CANTP_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef CANTP_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#elif defined CANTP_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef CANTP_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#elif defined CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#elif defined CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#elif defined CANTP_START_SEC_CONST_32
    #undef CANTP_START_SEC_CONST_32
    #define START_SEC_CONST_32
#elif defined CANTP_STOP_SEC_CONST_32
    #undef CANTP_STOP_SEC_CONST_32
    #define STOP_SEC_CONST_32
#elif defined CANTP_START_SEC_CONST_8
    #undef CANTP_START_SEC_CONST_8
    #define START_SEC_CONST_8
#elif defined CANTP_STOP_SEC_CONST_8
    #undef CANTP_STOP_SEC_CONST_8
    #define STOP_SEC_CONST_8
#elif defined CANTP_START_SEC_CONST_UNSPECIFIED
    #undef CANTP_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined CANTP_STOP_SEC_CONST_UNSPECIFIED
    #undef CANTP_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST_UNSPECIFIED
#elif defined CANTP_START_SEC_CANTPRXINDICATION_CALLBACK_CODE
    #undef CANTP_START_SEC_CANTPRXINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANTP_STOP_SEC_CANTPRXINDICATION_CALLBACK_CODE
    #undef CANTP_STOP_SEC_CANTPRXINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE
#elif defined CANTP_START_SEC_CANTPTXCONFIRMATION_CALLBACK_CODE
    #undef CANTP_START_SEC_CANTPTXCONFIRMATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANTP_STOP_SEC_CANTPTXCONFIRMATION_CALLBACK_CODE
    #undef CANTP_STOP_SEC_CANTPTXCONFIRMATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE
#else
    #error "CanTp not include this section"
#endif

#include "MemMap.h"

