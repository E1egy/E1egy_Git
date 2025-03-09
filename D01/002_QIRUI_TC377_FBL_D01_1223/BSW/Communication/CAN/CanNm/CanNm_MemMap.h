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
**  FILENAME    : CanNm_MemMap.h                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>       <REVISION LOG>
 *  V2.0.0       2020-07-29  Wanglili       R19_11 initial version.
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#if defined CANNM_START_SEC_CODE
    #undef CANNM_START_SEC_CODE
    #define START_SEC_CODE
#elif defined CANNM_STOP_SEC_CODE
    #undef CANNM_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined CANNM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef CANNM_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED
#elif defined CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_INIT_UNSPECIFIED

#elif defined CANNM_START_SEC_VAR_INIT_PTR
    #undef CANNM_START_SEC_VAR_INIT_PTR
    #define START_SEC_VAR_INIT_PTR
#elif defined CANNM_STOP_SEC_VAR_INIT_PTR
    #undef CANNM_STOP_SEC_VAR_INIT_PTR
    #define STOP_SEC_VAR_INIT_PTR

#elif defined CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined CANNM_START_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE
    #undef CANNM_START_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANNM_STOP_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE
    #undef CANNM_STOP_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANNM_START_SEC_CANNM_RXINDICATION_CALLBACK_CODE
    #undef CANNM_START_SEC_CANNM_RXINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANNM_STOP_SEC_CANNM_RXINDICATION_CALLBACK_CODE
    #undef CANNM_STOP_SEC_CANNM_RXINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANNM_START_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
    #undef CANNM_START_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANNM_STOP_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
    #undef CANNM_STOP_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANNM_START_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE
    #undef CANNM_START_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined CANNM_STOP_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE
    #undef CANNM_STOP_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define STOP_SEC_CONFIG_DATA_UNSPECIFIED

#else
    #error "Undefined section in CANNM"
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
