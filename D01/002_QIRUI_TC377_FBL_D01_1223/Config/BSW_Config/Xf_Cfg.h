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
**  FILENAME    : Xf.h                                                        **
**                                                                            **
**  Created on  :                                                             **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef XF_CFG_H_
#define XF_CFG_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "TransformerTypes.h"
#include "E2EXf_LCfg.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define IN_PLACE_0X119_ABM_STATE        STD_OFF
#define IN_PLACE_0X134_ADS_ECAS     STD_OFF
#define IN_PLACE_0X32A_ADS_STATE        STD_OFF
#define IN_PLACE_0X11D_ECAS_EDC_STATE       STD_OFF
#define IN_PLACE_0X342_ECAS_STATE       STD_OFF
#define IN_PLACE_0X196_EPB_STATE        STD_OFF
#define IN_PLACE_0X114_EPS_STATE        STD_OFF
#define IN_PLACE_0X195_IPB_ADS      STD_OFF
#define IN_PLACE_0X192_IPB_STATE1       STD_OFF
#define IN_PLACE_0X116_IPB_TQ       STD_OFF
#define IN_PLACE_0X112_IPB_WHEEL        STD_OFF
#define IN_PLACE_0X3F0_VDC_CDCSET       STD_OFF
#define IN_PLACE_0X115_VDC_FMTTQ        STD_OFF
#define IN_PLACE_0X11B_VDC_PTST     STD_OFF
#define IN_PLACE_0X113_VDC_RMTTQ        STD_OFF
#define IN_PLACE_0X3B5_VDC_VIU_BODYINFO     STD_OFF
#define IN_PLACE_0X39A_VIU_CONFIG       STD_OFF
#define IN_PLACE_0X2B0_VIU_DOORLOCK     STD_OFF
#define IN_PLACE_0X1D2_VIU_INFO     STD_OFF
#define IN_PLACE_0X34B_VIU_ROUTE_SUS        STD_OFF
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
#define E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
extern CONST(TransformationTechnologyType_PROFILE_05, E2EXF_CONST) TransformationTechnology_0;
#define E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "E2EXf_MemMap.h"
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif/* XF_CFG_H_ */

