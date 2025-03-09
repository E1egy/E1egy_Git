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
**  FILENAME    : E2EXf_LCfg.c                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "E2EXf_LCfg.h"
#include "Xf_Cfg.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
CONST(EndToEndTransformationDescriptionType_PROFILE_05, E2EXF_CONST) EndToEndTransformationDescription_0 =
{
    2,          /*maxDeltaCounter*/
    0,          /*maxErrorStateInit*/
    0,          /*maxErrorStateInvalid*/
    0,          /*maxErrorStateValid*/
    1,          /*minOkStateInit*/
    1,          /*minOkStateInvalid*/
    1,          /*minOkStateValid*/
    0,          /*offset*/
    "PROFILE_05",   /*PROFILE_05*/
    0,          /*upperHeaderBitsToShift*/
    1,          /*windowSizeInit*/
    1,          /*windowSizeValid*/
    1,          /*windowSizeInvalid*/
    TRUE        /*clearFromValidToInvalid*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x119 =
{
    0x611f,           /*dataId*/
    160,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x134 =
{
    0x6134,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x32a =
{
    0x632a,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x11d =
{
    0x611d,           /*dataId*/
    384,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x342 =
{
    0x6342,           /*dataId*/
    192,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x196 =
{
    0x6196,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x114 =
{
    0x6114,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x195 =
{
    0x6195,           /*dataId*/
    192,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x192 =
{
    0x6192,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x116 =
{
    0x6116,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x112 =
{
    0x6117,           /*dataId*/
    256,         /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x3f0 =
{
    0x63f0,           /*dataId*/
    64,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x115 =
{
    0x6115,           /*dataId*/
    192,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x11b =
{
    0x611b,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x113 =
{
    0x6113,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x3b5 =
{
    0x63b5,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x39a =
{
    0x639a,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x2b0 =
{
    0x62b0,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x1d2 =
{
    0x61d2,           /*dataId*/
    64,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_05, E2EXF_CONST) EndToEndTransformationISignalProps_0x34b =
{
    0x634b,           /*dataId*/
    256,            /*dataLength*/
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
static CONST(E2EXf_ConfigType_PROFILE_05, E2EXF_CONST) E2ETransformer_profile05[20] =
{
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x119,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x134,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x32a,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x11d,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x342,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x196,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x114,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x195,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x192,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x116,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x112,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x3f0,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x115,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x11b,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x113,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x3b5,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x39a,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x2b0,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x1d2,
       NULL_PTR
   },
   {
       &TransformationTechnology_0,
       &EndToEndTransformationISignalProps_0x34b,
       NULL_PTR
   }
};
#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

#define E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
CONST(E2EXf_ConfigType, E2EXF_CONST) E2EXf_Config =
{
    E2ETransformer_profile05,
};

#define E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"

