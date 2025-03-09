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
**  FILENAME    : E2EXf_MemMap.h                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef E2EXF_MEMMAP_H_
#define E2EXF_MEMMAP_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#if defined E2EXF_START_SEC_CODE
    #undef E2EXF_START_SEC_CODE
    #define START_SECTION_CODE
#elif defined E2EXF_STOP_SEC_CODE
    #undef E2EXF_STOP_SEC_CODE
    #define STOP_SECTION_CODE
#elif defined E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SECTION_DATA_CLEARED_UNSPECIFIED
#elif defined E2EXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef E2EXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SECTION_DATA_CLEARED_UNSPECIFIED
#elif defined E2EXF_START_SEC_VAR_CLEARED_BOOLEAN
    #undef E2EXF_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SECTION_DATA_CLEARED_BOOLEAN
#elif defined E2EXF_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef E2EXF_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SECTION_DATA_CLEARED_BOOLEAN
#elif defined E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SECTION_CONFIG_DATA_UNSPECIFIED
#elif defined E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SECTION_CONFIG_DATA_UNSPECIFIED
#elif defined E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
    #undef E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
    #define START_SECTION_PBCFG_DATA_UNSPECIFIED
#elif defined E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
    #undef E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
    #define START_SECTION_PBCFG_DATA_UNSPECIFIED
#elif defined E2EXF_START_SEC_CONST_UNSPECIFIED
    #undef E2EXF_START_SEC_CONST_UNSPECIFIED
    #define START_SECTION_CONST_UNSPECIFIED
#elif defined E2EXF_STOP_SEC_CONST_UNSPECIFIED
    #undef E2EXF_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SECTION_CONST_UNSPECIFIED
#else
#error "E2EXF not include this section"
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
#endif /* E2EXF_MEMMAP_H_ */

