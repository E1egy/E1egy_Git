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
**  FILENAME    : E2EXf.c                                                     **
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
/* <VERSION>     <DATE>       <AUTHOR>       <REVISION LOG>
 *  V1.0.0       20200610     Wanglili       Initial version
 *  V1.0.1       20201130     Wanglili       QAC check version and bug fix
 *  V1.0.2       20201217     Wanglili
 *  1.modify the scenarios when multiple signals use the same technology.
 *  2.rename the E2EXf_PBCfg and E2EXf_PBCfg.h to E2EXf_Lcfg.c and E2EXf_Lcfg.h.
 *  3.In E2EXf_SMConfigDataInit_E2ETransformerXX:the size of window should be
 *  configuration parameter WindowSizeValid.
 *  V1.0.3       20210527     Wanglili
 *  1.Modify the processing of each profile using upperheader
 ******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define E2EXF_C_AR_RELEASE_MAJOR_VERSION  19u
#define E2EXF_C_AR_RELEASE_MINOR_VERSION  11u
#define E2EXF_C_AR_RELEASE_PATCH_VERSION  0u
#define E2EXF_C_SW_MAJOR_VERSION  2u
#define E2EXF_C_SW_MINOR_VERSION  0u
#define E2EXF_C_SW_PATCH_VERSION  3u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* @Req<SWS_E2EXf_00047> */
#include "E2EXf.h"
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
#include "Det.h"
#endif/*STD_ON == E2EXF_DEV_ERROR_DETECT*/
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (E2EXF_C_AR_RELEASE_MAJOR_VERSION != E2EXF_H_AR_RELEASE_MAJOR_VERSION)
  #error "E2EXf.c : Mismatch in Specification Major Version"
#endif
#if (E2EXF_C_AR_RELEASE_MINOR_VERSION != E2EXF_H_AR_RELEASE_MINOR_VERSION)
  #error "E2EXf.c : Mismatch in Specification _MINOR Version"
#endif
#if (E2EXF_C_AR_RELEASE_PATCH_VERSION != E2EXF_H_AR_RELEASE_PATCH_VERSION)
  #error "E2EXf.c : Mismatch in Specification PATCH Version"
#endif
#if (E2EXF_C_SW_MAJOR_VERSION != E2EXF_H_SW_MAJOR_VERSION)
  #error "E2EXf.c : Mismatch in Software Major Version"
#endif
#if (E2EXF_C_SW_MINOR_VERSION != E2EXF_H_SW_MINOR_VERSION)
  #error "E2EXf.c : Mismatch in Software MINOR Version"
#endif
#if (E2EXF_C_SW_PATCH_VERSION != E2EXF_H_SW_PATCH_VERSION)
  #error "E2EXf.c : Mismatch in Software PATCH Version"
#endif
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*used to mark disable the action of E2E check*/
#define E2EXf_DISCHECK  2u
#define PROFILE_05_0_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_0_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_1_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_1_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_2_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_2_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_3_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_3_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_4_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_4_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_5_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_5_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_6_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_6_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_7_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_7_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_8_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_8_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_9_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_9_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_10_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_10_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_11_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_11_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_12_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_12_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_13_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_13_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_14_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_14_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_15_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_15_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_16_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_16_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_17_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_17_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_18_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_18_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_05_19_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_05_19_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x119(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x134(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x32a(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x11d(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x342(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x196(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x114(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x195(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x192(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x116(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x112(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x3f0(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x115(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x11b(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x113(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x3b5(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x39a(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x2b0(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x1d2(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x34b(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x119(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x134(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x32a(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x11d(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x342(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x196(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x114(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x195(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x192(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x116(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x112(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x3f0(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x115(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x11b(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x113(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x3b5(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x39a(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x2b0(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x1d2(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x34b(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define E2EXF_START_SEC_VAR_CLEARED_BOOLEAN
#include "E2EXf_MemMap.h"
/* represent E2EXf init or not */
static VAR(boolean, E2EXF_VAR_POWER_ON_INIT) E2EXf_InitFlag = FALSE;
#define E2EXF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "E2EXf_MemMap.h"
#define E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "E2EXf_MemMap.h"
/* @Req<SWS_E2EXf_00126> */ 
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x119;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x134;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x32a;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x11d;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x342;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x196;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x114;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x195;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x192;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x116;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x112;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x3f0;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x115;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x11b;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x113;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x3b5;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x39a;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x2b0;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x1d2;
VAR(E2E_P05ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x34b;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x119;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x134;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x32a;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x11d;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x342;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x196;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x114;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x195;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x192;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x116;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x112;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x3f0;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x115;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x11b;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x113;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x3b5;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x39a;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x2b0;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x1d2;
VAR(E2E_SMConfigType, E2EXF_VAR)  E2EXf_SMConfigData_E2ETransformer_0x34b;
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x119 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x134 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x32a = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x11d = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x342 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x196 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x114 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x195 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x192 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x116 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x112 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x3f0 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x115 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x11b = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x113 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x3b5 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x39a = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x2b0 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x1d2 = {0xFF};
VAR(E2E_P05ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x34b = {0xFF};
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x119;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x134;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x32a;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x11d;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x342;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x196;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x114;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x195;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x192;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x116;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x112;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x3f0;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x115;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x11b;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x113;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x3b5;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x39a;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x2b0;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x1d2;
VAR(E2E_P05CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x34b;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x119;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x134;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x32a;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x11d;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x342;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x196;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x114;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x195;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x192;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x116;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x112;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x3f0;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x115;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x11b;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x113;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x3b5;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x39a;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x2b0;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x1d2;
VAR(E2E_SMCheckStateType, E2EXF_VAR)  E2EXf_SMCheckState_E2ETransformer_0x34b;
VAR(E2E_PCheckStatusType, E2EXF_VAR)  E2E_PCheckStatus;
#define E2EXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "E2EXf_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

#define E2EXF_START_SEC_CONST_UNSPECIFIED
#include "E2EXF_MemMap.h"
static P2CONST(E2EXf_ConfigType, E2E_CONST_UNSPECIFIED, E2EXF_CONST) E2EXf_ConfigPtr = NULL_PTR;
#define E2EXF_STOP_SEC_CONST_UNSPECIFIED
#include "E2EXF_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               This service initializes  the state of  the E2E
 *                     Transformer
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* <SWS_E2EXf_00035> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(void, E2EXF_CODE)
E2EXf_Init
(
    P2CONST(E2EXf_ConfigType, AUTOMATIC, E2EXF_CONST) config
)
{
    if(NULL_PTR == config)
    {
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INIT_SERVICEID, E2EXF_E_PARAM_POINTER);
        #endif/*STD_ON == E2EXF_DEV_ERROR_DETECT*/
        E2EXf_InitFlag = FALSE;
    }
    else
    {
        Std_ReturnType initRet = E_OK;
        E2EXf_ConfigPtr = config;
        /* @Req<SWS_E2EXf_00021> */        
        E2EXf_ConfigDataInit_E2ETransformer_0x119();
        E2EXf_ConfigDataInit_E2ETransformer_0x134();
        E2EXf_ConfigDataInit_E2ETransformer_0x32a();
        E2EXf_ConfigDataInit_E2ETransformer_0x11d();
        E2EXf_ConfigDataInit_E2ETransformer_0x342();
        E2EXf_ConfigDataInit_E2ETransformer_0x196();
        E2EXf_ConfigDataInit_E2ETransformer_0x114();
        E2EXf_ConfigDataInit_E2ETransformer_0x195();
        E2EXf_ConfigDataInit_E2ETransformer_0x192();
        E2EXf_ConfigDataInit_E2ETransformer_0x116();
        E2EXf_ConfigDataInit_E2ETransformer_0x112();
        E2EXf_ConfigDataInit_E2ETransformer_0x3f0();
        E2EXf_ConfigDataInit_E2ETransformer_0x115();
        E2EXf_ConfigDataInit_E2ETransformer_0x11b();
        E2EXf_ConfigDataInit_E2ETransformer_0x113();
        E2EXf_ConfigDataInit_E2ETransformer_0x3b5();
        E2EXf_ConfigDataInit_E2ETransformer_0x39a();
        E2EXf_ConfigDataInit_E2ETransformer_0x2b0();
        E2EXf_ConfigDataInit_E2ETransformer_0x1d2();
        E2EXf_ConfigDataInit_E2ETransformer_0x34b();
        E2EXf_SMConfigDataInit_E2ETransformer_0x119();
        E2EXf_SMConfigDataInit_E2ETransformer_0x134();
        E2EXf_SMConfigDataInit_E2ETransformer_0x32a();
        E2EXf_SMConfigDataInit_E2ETransformer_0x11d();
        E2EXf_SMConfigDataInit_E2ETransformer_0x342();
        E2EXf_SMConfigDataInit_E2ETransformer_0x196();
        E2EXf_SMConfigDataInit_E2ETransformer_0x114();
        E2EXf_SMConfigDataInit_E2ETransformer_0x195();
        E2EXf_SMConfigDataInit_E2ETransformer_0x192();
        E2EXf_SMConfigDataInit_E2ETransformer_0x116();
        E2EXf_SMConfigDataInit_E2ETransformer_0x112();
        E2EXf_SMConfigDataInit_E2ETransformer_0x3f0();
        E2EXf_SMConfigDataInit_E2ETransformer_0x115();
        E2EXf_SMConfigDataInit_E2ETransformer_0x11b();
        E2EXf_SMConfigDataInit_E2ETransformer_0x113();
        E2EXf_SMConfigDataInit_E2ETransformer_0x3b5();
        E2EXf_SMConfigDataInit_E2ETransformer_0x39a();
        E2EXf_SMConfigDataInit_E2ETransformer_0x2b0();
        E2EXf_SMConfigDataInit_E2ETransformer_0x1d2();
        E2EXf_SMConfigDataInit_E2ETransformer_0x34b();
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x119);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x119);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x134);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x134);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x32a);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x32a);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x11d);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x11d);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x342);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x342);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x196);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x196);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x114);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x114);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x195);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x195);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x192);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x192);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x116);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x116);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x112);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x112);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x3f0);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x3f0);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x115);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x115);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x11b);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x11b);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x113);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x113);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x3b5);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x3b5);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x39a);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x39a);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x2b0);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x2b0);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x1d2);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x1d2);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_P05ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x34b);
        }
        if(E_OK == initRet)
        {
              initRet = E2E_P05CheckInit(&E2EXf_CheckState_E2ETransformer_0x34b);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x119,&E2EXf_SMConfigData_E2ETransformer_0x119);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x134,&E2EXf_SMConfigData_E2ETransformer_0x134);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x32a,&E2EXf_SMConfigData_E2ETransformer_0x32a);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x11d,&E2EXf_SMConfigData_E2ETransformer_0x11d);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x342,&E2EXf_SMConfigData_E2ETransformer_0x342);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x196,&E2EXf_SMConfigData_E2ETransformer_0x196);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x114,&E2EXf_SMConfigData_E2ETransformer_0x114);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x195,&E2EXf_SMConfigData_E2ETransformer_0x195);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x192,&E2EXf_SMConfigData_E2ETransformer_0x192);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x116,&E2EXf_SMConfigData_E2ETransformer_0x116);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x112,&E2EXf_SMConfigData_E2ETransformer_0x112);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x3f0,&E2EXf_SMConfigData_E2ETransformer_0x3f0);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x115,&E2EXf_SMConfigData_E2ETransformer_0x115);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x11b,&E2EXf_SMConfigData_E2ETransformer_0x11b);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x113,&E2EXf_SMConfigData_E2ETransformer_0x113);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x3b5,&E2EXf_SMConfigData_E2ETransformer_0x3b5);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x39a,&E2EXf_SMConfigData_E2ETransformer_0x39a);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x2b0,&E2EXf_SMConfigData_E2ETransformer_0x2b0);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x1d2,&E2EXf_SMConfigData_E2ETransformer_0x1d2);
        }
        if(E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(&E2EXf_SMCheckState_E2ETransformer_0x34b,&E2EXf_SMConfigData_E2ETransformer_0x34b);
        }
        if(E_OK == initRet)
        {
            /* @Req<SWS_E2EXf_00130> */
            E2EXf_InitFlag = TRUE;
        }
      }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               This service deinitializes  the state of  the E2E
 *                     Transformer
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* <SWS_E2EXf_00138> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(void, E2EXF_CODE)
E2EXf_DeInit(void)
{
    /* @Req<SWS_E2EXf_00148> */
    if(TRUE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00132> */
        E2EXf_InitFlag = FALSE;
        E2EXf_SMCheckState_E2ETransformer_0x119.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x134.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x32a.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x11d.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x342.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x196.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x114.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x195.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x192.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x116.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x112.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x3f0.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x115.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x11b.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x113.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x3b5.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x39a.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x2b0.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x1d2.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x34b.SMState = E2E_SM_DEINIT;
    }
    else
    {
        /* @Req<SWS_E2EXf_00137>, <SWS_E2EXf_00146> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_DEINIT_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

#if (STD_ON == E2EXF_VERSION_INFO_API)
/******************************************************************************/
/*
 * Brief               This service returns the version information of
 *                     this module
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Versioninfo: Pointer to where to store the version
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00036> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
void E2EXf_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    if (NULL_PTR == (VersionInfo))
    {
        /* @Req<SWS_E2EXf_00149> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_GETVERSIONINFO_ID, E2EXF_E_PARAM_POINTER);
        #endif/*STD_ON == E2EXF_DEV_ERROR_DETECT*/
        /*do nothing*/
    }
    else
    {
        (VersionInfo)->vendorID = E2EXF_VENDOR_ID;
        (VersionInfo)->moduleID = E2EXF_MODULE_ID;
        (VersionInfo)->sw_major_version = E2EXF_C_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = E2EXF_C_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = E2EXF_C_SW_PATCH_VERSION;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#endif/* STD_ON == E2EXF_VERSION_INFO_API */

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x119_ABM_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X119_ABM_STATE)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_0_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_0_HEADERLENGTH_DIV8) + (PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_0_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x119, &E2EXf_ProtectState_E2ETransformer_0x119, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x134_ADS_ECAS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X134_ADS_ECAS)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_1_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_1_HEADERLENGTH_DIV8) + (PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_1_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x134, &E2EXf_ProtectState_E2ETransformer_0x134, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x32a_ADS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X32A_ADS_STATE)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_2_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_2_HEADERLENGTH_DIV8) + (PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_2_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x32a, &E2EXf_ProtectState_E2ETransformer_0x32a, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x11d_ECAS_EDC_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X11D_ECAS_EDC_STATE)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_3_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_3_HEADERLENGTH_DIV8) + (PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_3_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x11d, &E2EXf_ProtectState_E2ETransformer_0x11d, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x342_ECAS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X342_ECAS_STATE)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_4_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_4_HEADERLENGTH_DIV8) + (PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_4_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x342, &E2EXf_ProtectState_E2ETransformer_0x342, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x196_EPB_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X196_EPB_STATE)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_5_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_5_HEADERLENGTH_DIV8) + (PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_5_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x196, &E2EXf_ProtectState_E2ETransformer_0x196, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x114_EPS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X114_EPS_STATE)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_6_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_6_HEADERLENGTH_DIV8) + (PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_6_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x114, &E2EXf_ProtectState_E2ETransformer_0x114, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x195_IPB_ADS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X195_IPB_ADS)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_7_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_7_HEADERLENGTH_DIV8) + (PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_7_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x195, &E2EXf_ProtectState_E2ETransformer_0x195, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x192_IPB_State1
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X192_IPB_STATE1)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_8_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_8_HEADERLENGTH_DIV8) + (PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_8_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x192, &E2EXf_ProtectState_E2ETransformer_0x192, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x116_IPB_Tq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X116_IPB_TQ)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_9_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_9_HEADERLENGTH_DIV8) + (PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_9_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x116, &E2EXf_ProtectState_E2ETransformer_0x116, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x112_IPB_Wheel
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X112_IPB_WHEEL)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_10_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_10_HEADERLENGTH_DIV8) + (PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_10_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x112, &E2EXf_ProtectState_E2ETransformer_0x112, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x3f0_VDC_CDCSet
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X3F0_VDC_CDCSET)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_11_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_11_HEADERLENGTH_DIV8) + (PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_11_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x3f0, &E2EXf_ProtectState_E2ETransformer_0x3f0, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x115_VDC_FMtTq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X115_VDC_FMTTQ)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_12_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_12_HEADERLENGTH_DIV8) + (PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_12_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x115, &E2EXf_ProtectState_E2ETransformer_0x115, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x11b_VDC_PTSt
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X11B_VDC_PTST)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_13_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_13_HEADERLENGTH_DIV8) + (PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_13_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x11b, &E2EXf_ProtectState_E2ETransformer_0x11b, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x113_VDC_RMtTq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X113_VDC_RMTTQ)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_14_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_14_HEADERLENGTH_DIV8) + (PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_14_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x113, &E2EXf_ProtectState_E2ETransformer_0x113, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x3b5_VDC_VIU_BodyInfo
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X3B5_VDC_VIU_BODYINFO)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_15_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_15_HEADERLENGTH_DIV8) + (PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_15_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x3b5, &E2EXf_ProtectState_E2ETransformer_0x3b5, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x39a_VIU_Config
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X39A_VIU_CONFIG)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_16_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_16_HEADERLENGTH_DIV8) + (PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_16_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x39a, &E2EXf_ProtectState_E2ETransformer_0x39a, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x2b0_VIU_DoorLock
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X2B0_VIU_DOORLOCK)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_17_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_17_HEADERLENGTH_DIV8) + (PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_17_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x2b0, &E2EXf_ProtectState_E2ETransformer_0x2b0, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x1d2_VIU_Info
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X1D2_VIU_INFO)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_18_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_18_HEADERLENGTH_DIV8) + (PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_18_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x1d2, &E2EXf_ProtectState_E2ETransformer_0x1d2, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x34b_VIU_Route_SUS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        #if (STD_ON == IN_PLACE_0X34B_VIU_ROUTE_SUS)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if( (NULL_PTR == buffer) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if( (E_OK == retVal) && ((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u))) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint16 len = PROFILE_05_19_HEADERLENGTH_DIV8;
            uint32 offset;
            for(offset = (inputBufferLength + (uint32)len); offset > ((uint32)len + ((uint32)PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u)); offset--)
            {
                buffer[offset - 1u] = buffer[offset -(uint32)len - 1u];
            }
        }
        #else
        /* @Req<SWS_E2EXf_00106> */
        if( (NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if( ((E_OK == retVal) || (NULL_PTR != inputBuffer)) && (inputBufferLength < ((uint32)PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u)) )
        {
            /* @Req<SWS_E2EXf_00150> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len = (PROFILE_05_19_HEADERLENGTH_DIV8) + (PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for(offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for(offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
        #endif
        if(E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111> */
            *bufferLength = ((uint32)PROFILE_05_19_HEADERLENGTH_DIV8) + inputBufferLength;
            /* @Req<SWS_E2EXf_00107> */
            retVal = E2E_P05Protect(&E2EXf_ConfigData_E2ETransformer_0x34b, &E2EXf_ProtectState_E2ETransformer_0x34b, buffer, (uint16)(*bufferLength));
           if(E2E_E_OK == retVal)
            {
               *bufferLength += (uint32)PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u;
            }
           else
            {
               /* @Req<SWS_E2EXf_00018> */
               retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x119_ABM_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X119_ABM_STATE)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_0_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_0_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x119,&E2EXf_CheckState_E2ETransformer_0x119,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x119,&E2EXf_CheckState_E2ETransformer_0x119,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_0_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_0_HEADERLENGTH_DIV8) + (PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_0_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_0_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x119,&E2EXf_CheckState_E2ETransformer_0x119,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x119,&E2EXf_CheckState_E2ETransformer_0x119,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_0_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_0_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_0_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x119.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x119,&E2EXf_SMCheckState_E2ETransformer_0x119) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x119.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_0_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x134_ADS_ECAS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X134_ADS_ECAS)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_1_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_1_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x134,&E2EXf_CheckState_E2ETransformer_0x134,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x134,&E2EXf_CheckState_E2ETransformer_0x134,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_1_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_1_HEADERLENGTH_DIV8) + (PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_1_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_1_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x134,&E2EXf_CheckState_E2ETransformer_0x134,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x134,&E2EXf_CheckState_E2ETransformer_0x134,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_1_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_1_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_1_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x134.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x134,&E2EXf_SMCheckState_E2ETransformer_0x134) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x134.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_1_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x32a_ADS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X32A_ADS_STATE)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_2_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_2_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x32a,&E2EXf_CheckState_E2ETransformer_0x32a,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x32a,&E2EXf_CheckState_E2ETransformer_0x32a,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_2_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_2_HEADERLENGTH_DIV8) + (PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_2_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_2_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x32a,&E2EXf_CheckState_E2ETransformer_0x32a,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x32a,&E2EXf_CheckState_E2ETransformer_0x32a,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_2_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_2_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_2_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x32a.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x32a,&E2EXf_SMCheckState_E2ETransformer_0x32a) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x32a.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_2_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x11d_ECAS_EDC_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X11D_ECAS_EDC_STATE)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_3_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_3_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x11d,&E2EXf_CheckState_E2ETransformer_0x11d,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x11d,&E2EXf_CheckState_E2ETransformer_0x11d,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_3_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_3_HEADERLENGTH_DIV8) + (PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_3_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_3_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x11d,&E2EXf_CheckState_E2ETransformer_0x11d,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x11d,&E2EXf_CheckState_E2ETransformer_0x11d,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_3_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_3_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_3_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x11d.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x11d,&E2EXf_SMCheckState_E2ETransformer_0x11d) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x11d.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_3_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x342_ECAS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X342_ECAS_STATE)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_4_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_4_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x342,&E2EXf_CheckState_E2ETransformer_0x342,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x342,&E2EXf_CheckState_E2ETransformer_0x342,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_4_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_4_HEADERLENGTH_DIV8) + (PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_4_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_4_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x342,&E2EXf_CheckState_E2ETransformer_0x342,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x342,&E2EXf_CheckState_E2ETransformer_0x342,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_4_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_4_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_4_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x342.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x342,&E2EXf_SMCheckState_E2ETransformer_0x342) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x342.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_4_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x196_EPB_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X196_EPB_STATE)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_5_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_5_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x196,&E2EXf_CheckState_E2ETransformer_0x196,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x196,&E2EXf_CheckState_E2ETransformer_0x196,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_5_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_5_HEADERLENGTH_DIV8) + (PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_5_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_5_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x196,&E2EXf_CheckState_E2ETransformer_0x196,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x196,&E2EXf_CheckState_E2ETransformer_0x196,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_5_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_5_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_5_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x196.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x196,&E2EXf_SMCheckState_E2ETransformer_0x196) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x196.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_5_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x114_EPS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X114_EPS_STATE)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_6_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_6_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x114,&E2EXf_CheckState_E2ETransformer_0x114,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x114,&E2EXf_CheckState_E2ETransformer_0x114,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_6_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_6_HEADERLENGTH_DIV8) + (PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_6_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_6_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x114,&E2EXf_CheckState_E2ETransformer_0x114,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x114,&E2EXf_CheckState_E2ETransformer_0x114,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_6_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_6_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_6_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x114.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x114,&E2EXf_SMCheckState_E2ETransformer_0x114) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x114.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_6_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x195_IPB_ADS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X195_IPB_ADS)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_7_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_7_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x195,&E2EXf_CheckState_E2ETransformer_0x195,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x195,&E2EXf_CheckState_E2ETransformer_0x195,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_7_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_7_HEADERLENGTH_DIV8) + (PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_7_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_7_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x195,&E2EXf_CheckState_E2ETransformer_0x195,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x195,&E2EXf_CheckState_E2ETransformer_0x195,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_7_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_7_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_7_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x195.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x195,&E2EXf_SMCheckState_E2ETransformer_0x195) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x195.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_7_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x192_IPB_State1
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X192_IPB_STATE1)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_8_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_8_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x192,&E2EXf_CheckState_E2ETransformer_0x192,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x192,&E2EXf_CheckState_E2ETransformer_0x192,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_8_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_8_HEADERLENGTH_DIV8) + (PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_8_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_8_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x192,&E2EXf_CheckState_E2ETransformer_0x192,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x192,&E2EXf_CheckState_E2ETransformer_0x192,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_8_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_8_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_8_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x192.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x192,&E2EXf_SMCheckState_E2ETransformer_0x192) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x192.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_8_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x116_IPB_Tq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X116_IPB_TQ)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_9_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_9_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x116,&E2EXf_CheckState_E2ETransformer_0x116,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x116,&E2EXf_CheckState_E2ETransformer_0x116,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_9_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_9_HEADERLENGTH_DIV8) + (PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_9_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_9_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x116,&E2EXf_CheckState_E2ETransformer_0x116,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x116,&E2EXf_CheckState_E2ETransformer_0x116,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_9_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_9_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_9_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x116.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x116,&E2EXf_SMCheckState_E2ETransformer_0x116) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x116.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_9_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x112_IPB_Wheel
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X112_IPB_WHEEL)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_10_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_10_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x112,&E2EXf_CheckState_E2ETransformer_0x112,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x112,&E2EXf_CheckState_E2ETransformer_0x112,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_10_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_10_HEADERLENGTH_DIV8) + (PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_10_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_10_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x112,&E2EXf_CheckState_E2ETransformer_0x112,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x112,&E2EXf_CheckState_E2ETransformer_0x112,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_10_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_10_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_10_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x112.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x112,&E2EXf_SMCheckState_E2ETransformer_0x112) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x112.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_10_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x3f0_VDC_CDCSet
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X3F0_VDC_CDCSET)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_11_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_11_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x3f0,&E2EXf_CheckState_E2ETransformer_0x3f0,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x3f0,&E2EXf_CheckState_E2ETransformer_0x3f0,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_11_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_11_HEADERLENGTH_DIV8) + (PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_11_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_11_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x3f0,&E2EXf_CheckState_E2ETransformer_0x3f0,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x3f0,&E2EXf_CheckState_E2ETransformer_0x3f0,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_11_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_11_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_11_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x3f0.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x3f0,&E2EXf_SMCheckState_E2ETransformer_0x3f0) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x3f0.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_11_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x115_VDC_FMtTq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X115_VDC_FMTTQ)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_12_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_12_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x115,&E2EXf_CheckState_E2ETransformer_0x115,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x115,&E2EXf_CheckState_E2ETransformer_0x115,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_12_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_12_HEADERLENGTH_DIV8) + (PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_12_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_12_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x115,&E2EXf_CheckState_E2ETransformer_0x115,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x115,&E2EXf_CheckState_E2ETransformer_0x115,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_12_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_12_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_12_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x115.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x115,&E2EXf_SMCheckState_E2ETransformer_0x115) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x115.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_12_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x11b_VDC_PTSt
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X11B_VDC_PTST)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_13_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_13_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x11b,&E2EXf_CheckState_E2ETransformer_0x11b,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x11b,&E2EXf_CheckState_E2ETransformer_0x11b,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_13_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_13_HEADERLENGTH_DIV8) + (PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_13_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_13_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x11b,&E2EXf_CheckState_E2ETransformer_0x11b,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x11b,&E2EXf_CheckState_E2ETransformer_0x11b,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_13_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_13_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_13_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x11b.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x11b,&E2EXf_SMCheckState_E2ETransformer_0x11b) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x11b.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_13_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x113_VDC_RMtTq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X113_VDC_RMTTQ)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_14_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_14_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x113,&E2EXf_CheckState_E2ETransformer_0x113,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x113,&E2EXf_CheckState_E2ETransformer_0x113,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_14_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_14_HEADERLENGTH_DIV8) + (PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_14_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_14_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x113,&E2EXf_CheckState_E2ETransformer_0x113,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x113,&E2EXf_CheckState_E2ETransformer_0x113,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_14_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_14_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_14_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x113.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x113,&E2EXf_SMCheckState_E2ETransformer_0x113) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x113.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_14_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x3b5_VDC_VIU_BodyInfo
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X3B5_VDC_VIU_BODYINFO)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_15_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_15_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x3b5,&E2EXf_CheckState_E2ETransformer_0x3b5,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x3b5,&E2EXf_CheckState_E2ETransformer_0x3b5,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_15_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_15_HEADERLENGTH_DIV8) + (PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_15_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_15_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x3b5,&E2EXf_CheckState_E2ETransformer_0x3b5,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x3b5,&E2EXf_CheckState_E2ETransformer_0x3b5,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_15_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_15_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_15_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x3b5.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x3b5,&E2EXf_SMCheckState_E2ETransformer_0x3b5) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x3b5.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_15_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x39a_VIU_Config
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X39A_VIU_CONFIG)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_16_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_16_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x39a,&E2EXf_CheckState_E2ETransformer_0x39a,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x39a,&E2EXf_CheckState_E2ETransformer_0x39a,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_16_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_16_HEADERLENGTH_DIV8) + (PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_16_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_16_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x39a,&E2EXf_CheckState_E2ETransformer_0x39a,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x39a,&E2EXf_CheckState_E2ETransformer_0x39a,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_16_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_16_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_16_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x39a.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x39a,&E2EXf_SMCheckState_E2ETransformer_0x39a) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x39a.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_16_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x2b0_VIU_DoorLock
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X2B0_VIU_DOORLOCK)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_17_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_17_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x2b0,&E2EXf_CheckState_E2ETransformer_0x2b0,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x2b0,&E2EXf_CheckState_E2ETransformer_0x2b0,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_17_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_17_HEADERLENGTH_DIV8) + (PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_17_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_17_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x2b0,&E2EXf_CheckState_E2ETransformer_0x2b0,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x2b0,&E2EXf_CheckState_E2ETransformer_0x2b0,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_17_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_17_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_17_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x2b0.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x2b0,&E2EXf_SMCheckState_E2ETransformer_0x2b0) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x2b0.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_17_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x1d2_VIU_Info
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X1D2_VIU_INFO)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_18_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_18_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x1d2,&E2EXf_CheckState_E2ETransformer_0x1d2,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x1d2,&E2EXf_CheckState_E2ETransformer_0x1d2,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_18_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_18_HEADERLENGTH_DIV8) + (PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_18_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_18_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x1d2,&E2EXf_CheckState_E2ETransformer_0x1d2,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x1d2,&E2EXf_CheckState_E2ETransformer_0x1d2,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_18_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_18_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_18_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x1d2.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x1d2,&E2EXf_SMCheckState_E2ETransformer_0x1d2) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x1d2.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_18_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x34b_VIU_Route_SUS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
)
{
    uint8 retVal = E_OK;
    uint16 E2E_dataLength = (uint16)inputBufferLength;
    /* @Req<SWS_E2EXf_00153> */
    if(FALSE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
        #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
        #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if(E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        #if (STD_ON == IN_PLACE_0X34B_VIU_ROUTE_SUS)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if( ((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if( (E_OK == retVal) && (((NULL_PTR != buffer) && (inputBufferLength < (((uint32)PROFILE_05_19_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u))))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_19_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == buffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x34b,&E2EXf_CheckState_E2ETransformer_0x34b,buffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x34b,&E2EXf_CheckState_E2ETransformer_0x34b,buffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_05_19_UPPERHEADERBITSTOSHIFT >= 0u))
            {

                uint16 len = (PROFILE_05_19_HEADERLENGTH_DIV8) + (PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;

                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
        #else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if( ((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM_POINTER);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if( (E_OK == retVal) && ((NULL_PTR != inputBuffer) && (inputBufferLength < (((uint32)PROFILE_05_19_HEADERLENGTH_DIV8) + ((uint32)PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u)))) )
        {
            /* @Req<SWS_E2EXf_00152> */
            #if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INV_TRANSFORMERID_SERVICEID, E2EXF_E_PARAM);
            #endif /* (STD_ON == E2EXF_DEV_ERROR_DETECT) */
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        if(E_OK == retVal)
        {
            if(NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps)
            {
                if(TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if(0u ==inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_05_19_HEADERLENGTH_DIV8);
                    }
                }
            }
            if(E2EXf_DISCHECK != checkRet)
            {
                if((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x34b,&E2EXf_CheckState_E2ETransformer_0x34b,inputBuffer,(uint16)inputBufferLength);
                }
                else
                {
                    checkRet = E2E_P05Check(&E2EXf_ConfigData_E2ETransformer_0x34b,&E2EXf_CheckState_E2ETransformer_0x34b,inputBuffer,E2E_dataLength);
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if((E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer) && (PROFILE_05_19_UPPERHEADERBITSTOSHIFT >= 0u))
            {
                uint16 shiftLen = PROFILE_05_19_UPPERHEADERBITSTOSHIFT >> 3u;
                uint16 len = (PROFILE_05_19_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;

                for(offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for(offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
        #endif
        if((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus = E2E_P05MapStatusToSM(checkRet,E2EXf_CheckState_E2ETransformer_0x34b.Status);

            /* @Req<SWS_E2EXf_00028> */
            if(E2E_E_OK == E2E_SMCheck(E2E_PCheckStatus,&E2EXf_SMConfigData_E2ETransformer_0x34b,&E2EXf_SMCheckState_E2ETransformer_0x34b) )
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x34b.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if( 0u == inputBufferLength )
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_05_19_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/    
/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x119(void)
{
    E2EXf_ConfigData_E2ETransformer_0x119.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x119.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x119.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x119.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x119.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x134(void)
{
    E2EXf_ConfigData_E2ETransformer_0x134.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x134.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x134.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x134.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x134.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x32a(void)
{
    E2EXf_ConfigData_E2ETransformer_0x32a.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x32a.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x32a.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x32a.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x32a.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x11d(void)
{
    E2EXf_ConfigData_E2ETransformer_0x11d.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x11d.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x11d.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x11d.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x11d.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x342(void)
{
    E2EXf_ConfigData_E2ETransformer_0x342.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x342.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x342.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x342.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x342.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x196(void)
{
    E2EXf_ConfigData_E2ETransformer_0x196.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x196.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x196.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x196.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x196.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x114(void)
{
    E2EXf_ConfigData_E2ETransformer_0x114.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x114.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x114.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x114.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x114.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x195(void)
{
    E2EXf_ConfigData_E2ETransformer_0x195.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x195.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x195.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x195.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x195.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x192(void)
{
    E2EXf_ConfigData_E2ETransformer_0x192.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x192.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x192.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x192.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x192.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x116(void)
{
    E2EXf_ConfigData_E2ETransformer_0x116.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x116.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x116.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x116.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x116.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x112(void)
{
    E2EXf_ConfigData_E2ETransformer_0x112.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x112.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x112.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x112.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x112.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x3f0(void)
{
    E2EXf_ConfigData_E2ETransformer_0x3f0.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x3f0.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x3f0.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x3f0.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x3f0.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x115(void)
{
    E2EXf_ConfigData_E2ETransformer_0x115.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x115.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x115.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x115.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x115.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x11b(void)
{
    E2EXf_ConfigData_E2ETransformer_0x11b.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x11b.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x11b.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x11b.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x11b.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x113(void)
{
    E2EXf_ConfigData_E2ETransformer_0x113.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x113.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x113.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x113.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x113.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x3b5(void)
{
    E2EXf_ConfigData_E2ETransformer_0x3b5.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x3b5.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x3b5.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x3b5.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x3b5.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x39a(void)
{
    E2EXf_ConfigData_E2ETransformer_0x39a.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x39a.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x39a.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x39a.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x39a.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x2b0(void)
{
    E2EXf_ConfigData_E2ETransformer_0x2b0.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x2b0.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x2b0.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x2b0.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x2b0.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x1d2(void)
{
    E2EXf_ConfigData_E2ETransformer_0x1d2.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x1d2.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x1d2.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x1d2.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x1d2.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_ConfigDataInit_E2ETransformer_0x34b(void)
{
    E2EXf_ConfigData_E2ETransformer_0x34b.DataID = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x34b.DataLength = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfISignalProps->dataLength+ PROFILE_05_0_UPPERHEADERBITSTOSHIFT;
    E2EXf_ConfigData_E2ETransformer_0x34b.Offset = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->offset;

    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x34b.MaxDeltaCounter = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->maxDeltaCounter;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x34b.MaxDeltaCounter =(uint8) E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->maxDeltaCounter;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x119(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x119.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x119.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x119.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x119.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x119.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x119.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x119.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x119.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x119.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x119.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x119.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x119.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x119.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x119.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x119.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x119.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x119.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x119.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x119.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x119.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x119.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x119.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[0].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x134(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x134.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x134.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x134.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x134.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x134.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x134.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x134.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x134.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x134.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x134.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x134.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x134.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x134.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x134.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x134.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x134.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x134.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x134.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x134.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x134.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x134.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x134.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[1].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x32a(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x32a.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x32a.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x32a.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x32a.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x32a.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x32a.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x32a.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[2].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x11d(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x11d.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x11d.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x11d.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x11d.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x11d.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x11d.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x11d.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[3].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x342(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x342.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x342.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x342.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x342.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x342.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x342.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x342.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x342.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x342.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x342.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x342.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x342.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x342.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x342.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x342.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x342.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x342.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x342.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x342.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x342.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x342.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x342.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[4].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x196(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x196.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x196.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x196.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x196.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x196.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x196.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x196.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x196.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x196.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x196.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x196.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x196.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x196.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x196.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x196.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x196.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x196.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x196.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x196.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x196.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x196.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x196.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[5].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x114(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x114.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x114.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x114.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x114.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x114.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x114.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x114.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x114.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x114.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x114.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x114.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x114.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x114.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x114.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x114.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x114.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x114.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x114.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x114.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x114.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x114.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x114.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[6].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x195(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x195.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x195.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x195.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x195.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x195.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x195.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x195.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x195.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x195.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x195.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x195.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x195.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x195.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x195.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x195.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x195.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x195.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x195.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x195.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x195.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x195.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x195.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[7].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x192(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x192.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x192.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x192.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x192.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x192.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x192.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x192.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x192.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x192.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x192.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x192.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x192.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x192.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x192.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x192.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x192.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x192.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x192.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x192.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x192.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x192.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x192.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[8].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x116(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x116.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x116.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x116.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x116.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x116.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x116.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x116.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x116.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x116.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x116.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x116.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x116.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x116.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x116.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x116.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x116.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x116.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x116.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x116.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x116.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x116.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x116.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[9].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x112(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x112.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x112.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x112.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x112.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x112.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x112.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x112.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x112.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x112.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x112.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x112.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x112.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x112.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x112.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x112.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x112.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x112.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x112.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x112.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x112.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x112.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x112.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[10].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x3f0(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x3f0.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x3f0.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x3f0.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x3f0.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x3f0.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[11].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x115(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x115.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x115.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x115.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x115.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x115.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x115.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x115.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x115.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x115.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x115.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x115.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x115.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x115.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x115.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x115.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x115.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x115.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x115.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x115.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x115.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x115.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x115.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[12].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x11b(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x11b.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x11b.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x11b.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x11b.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x11b.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x11b.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x11b.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[13].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x113(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x113.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x113.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x113.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x113.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x113.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x113.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x113.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x113.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x113.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x113.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x113.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x113.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x113.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x113.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x113.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x113.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x113.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x113.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x113.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x113.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x113.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x113.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[14].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x3b5(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x3b5.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x3b5.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x3b5.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x3b5.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x3b5.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[15].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x39a(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x39a.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x39a.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x39a.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x39a.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x39a.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x39a.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x39a.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[16].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x2b0(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x2b0.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x2b0.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x2b0.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x2b0.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x2b0.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[17].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x1d2(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x1d2.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x1d2.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x1d2.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x1d2.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1d2.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[18].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE)
E2EXf_SMConfigDataInit_E2ETransformer_0x34b(void)
{
    static uint8 window[1];
    E2EXf_SMCheckState_E2ETransformer_0x34b.ProfileStatusWindow = window;
    E2EXf_SMCheckState_E2ETransformer_0x34b.SMState = E2E_SM_DEINIT;
    if(NULL_PTR == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x34b.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x34b.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x34b.WindowSizeInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x34b.WindowSizeValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.WindowSizeInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.ClearToInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MinOkStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MaxErrorStateInit = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MinOkStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MinOkStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MaxErrorStateValid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x34b.MaxErrorStateInvalid = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_05[19].E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
