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
**  FILENAME    : BswM_Sd.h                                                   **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-03-24  qinchun.yang    R19_11 BswM initial version.
 *  V2.0.0       2021-04-08  qinchun.yang    R1911 stable version.
 */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#if defined BSWM_START_SEC_CODE
    #undef BSWM_START_SEC_CODE
    #define START_SEC_CODE
#elif defined BSWM_STOP_SEC_CODE
    #undef BSWM_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined BSWM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED
#elif defined BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_INIT_UNSPECIFIED

#elif defined BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined BSWM_START_SEC_VAR_CLEARED_32
    #undef BSWM_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32
#elif defined BSWM_STOP_SEC_VAR_CLEARED_32
    #undef BSWM_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR_CLEARED_32

#elif defined BSWM_START_SEC_VAR_CLEARED_16
    #undef BSWM_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16
#elif defined BSWM_STOP_SEC_VAR_CLEARED_16
    #undef BSWM_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR_CLEARED_16

#elif defined BSWM_START_SEC_VAR_CLEARED_8
    #undef BSWM_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8
#elif defined BSWM_STOP_SEC_VAR_CLEARED_8
    #undef BSWM_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR_CLEARED_8

#elif defined BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define STOP_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined BSWM_START_SEC_CONST_PTR
    #undef BSWM_START_SEC_CONST_PTR
    #define START_SEC_CONST_PTR
#elif defined BSWM_STOP_SEC_CONST_PTR
    #undef BSWM_STOP_SEC_CONST_PTR
    #define STOP_SEC_CONST_PTR

#elif defined BSWM_START_SEC_CONST_8
    #undef BSWM_START_SEC_CONST_8
    #define START_SEC_CONST_8
#elif defined BSWM_STOP_SEC_CONST_8
    #undef BSWM_STOP_SEC_CONST_8
    #define STOP_SEC_CONST_8

#elif defined BSWM_START_SEC_CONST_16
    #undef BSWM_START_SEC_CONST_16
    #define START_SEC_CONST_16
#elif defined BSWM_STOP_SEC_CONST_16
    #undef BSWM_STOP_SEC_CONST_16
    #define STOP_SEC_CONST_16

#elif defined BSWM_START_SEC_CONST_32
    #undef BSWM_START_SEC_CONST_32
    #define START_SEC_CONST_32
#elif defined BSWM_STOP_SEC_CONST_32
    #undef BSWM_STOP_SEC_CONST_32
    #define STOP_SEC_CONST_32

#elif defined BSWM_START_SEC_CONST_UNSPECIFIED
    #undef BSWM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined BSWM_STOP_SEC_CONST_UNSPECIFIED
    #undef BSWM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST_UNSPECIFIED
#else
#error "BswM not include this section"
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
