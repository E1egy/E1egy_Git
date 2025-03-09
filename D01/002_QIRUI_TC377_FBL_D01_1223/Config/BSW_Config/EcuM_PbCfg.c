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
**  FILENAME    : EcuM_PbCfg.c                                                **
**                                                                            **
**  Created on  : 2023/01/06 16:29:59                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :  Configuration constant variables for pre-compile           **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19_11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
#include "Port.h"
#include "Can_17_McmCan.h"
#include "Spi.h"
#include "Adc.h"
#include "Pwm_17_GtmCcu6.h"
#include "Icu_17_TimerIp.h"
#include "CanIf.h"
#include "Com.h"
#include "PduR.h"
#include "Nm.h"
#include "CanNm.h"
#include "CanSM.h"
#include "ComM.h"
#include "CanTp.h"
#include "Dcm.h"
#include "Dem.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_PBCFG_GLOBALROOT
#include "EcuM_MemMap.h"
CONST(EcuM_GenBSWPbCfgType, ECUM_VAR_NO_INIT) EcuM_GenMcalConfig =
{
    NULL_PTR, /*bswmPbCfg*/
    (void *)&Port_Config,
    (void *)&Can_17_McmCan_Config,
    (void *)&Spi_Config,
    (void *)&Adc_Config,
    (void *)&Pwm_17_GtmCcu6_Config,
    (void *)&Icu_17_TimerIp_Config,
    (void *)&CanIf_InitCfgSet,
    (void *)&Com_PBConfigData,
    (void *)&PduR_PBConfigData,
    (void *)&Nm_Config,
    (void *)&CanNm_Config,
    (void *)&CanSM_Config,
    (void *)&ComM_Config,
    (void *)&CanTp_Config,
    (void *)&Dcm_Cfg,
    (void *)&DemPbCfg,
};
CONST(EcuM_ConfigType, ECUM_VAR_NO_INIT) EcuM_Config =
{
    1,    /*EcuMConfigConsistencyHash*/
    OSDEFAULTAPPMODE,    /*EcuMDefaultAppMode*/
    ECUM_SHUTDOWN_TARGET_OFF,
    0,
    &EcuM_GenMcalConfig
};
#define ECUM_STOP_SEC_PBCFG_GLOBALROOT
#include "EcuM_MemMap.h"

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/

