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
**  FILENAME    : CanSM_MemMap.h                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of CanSM             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#if defined CANSM_START_SEC_CODE
    #undef CANSM_START_SEC_CODE
    #define START_SEC_CODE
#elif defined CANSM_STOP_SEC_CODE
    #undef CANSM_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined CANSM_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CANSM_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN
#elif defined CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR_CLEARED_BOOLEAN

#elif defined CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define STOP_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined CANSM_START_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE
    #undef CANSM_START_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANSM_STOP_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE
    #undef CANSM_STOP_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANSM_START_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE
    #undef CANSM_START_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANSM_STOP_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE
    #undef CANSM_STOP_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANSM_START_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE
    #undef CANSM_START_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANSM_STOP_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE
    #undef CANSM_STOP_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANSM_START_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
    #undef CANSM_START_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANSM_STOP_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
    #undef CANSM_STOP_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANSM_START_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE
    #undef CANSM_START_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANSM_STOP_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE
    #undef CANSM_STOP_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANSM_START_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
    #undef CANSM_START_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANSM_STOP_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
    #undef CANSM_STOP_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANSM_START_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE
    #undef CANSM_START_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANSM_STOP_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE
    #undef CANSM_STOP_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANSM_START_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
    #undef CANSM_START_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANSM_STOP_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
    #undef CANSM_STOP_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define STOP_SEC_CONFIG_DATA_UNSPECIFIED
#else
#error "CanSM not include this section"
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
/*=======[E N D   O F   F I L E]==============================================*/
