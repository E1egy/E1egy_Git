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
**  FILENAME    : ComM_Dcm.h                                                  **
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
 *  V2.0.0       2020-07-24  Wanglili       R19_11 initial version.
 */
#ifndef COMM_DCM_H
#define COMM_DCM_H

#include "ComM_Cfg.h"

#if (STD_ON == COMM_DCM_USED)
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define COMM_START_SEC_COMMDCMACTIVEDIAGNOSTIC_CALLBACK_CODE
#include "ComM_MemMap.h"
/******************************************************************************/
/*
 * Brief               Indication of active diagnostic by the DCM.
 * ServiceId           0x1F
 * ServiceId           Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel
 * Param-Name[in/out]  None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COMM_DCM_CODE)
ComM_DCM_ActiveDiagnostic(
    NetworkHandleType Channel
);
#define COMM_STOP_SEC_COMMDCMACTIVEDIAGNOSTIC_CALLBACK_CODE
#include "ComM_MemMap.h"

#define COMM_START_SEC_COMMDCMINACTIVEDIAGNOSTIC_CALLBACK_CODE
#include "ComM_MemMap.h"
/******************************************************************************/
/*
 * Brief               Indication of inactive diagnostic by the DCM.
 * ServiceId           0x20
 * ServiceId           Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel
 * Param-Name[in/out]  None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COMM_DCM_CODE)
ComM_DCM_InactiveDiagnostic(
    NetworkHandleType Channel
);
#define COMM_STOP_SEC_COMMDCMINACTIVEDIAGNOSTIC_CALLBACK_CODE
#include "ComM_MemMap.h"

#endif /*#if (STD_ON == COMM_DCM_USED)*/
#endif /* COMM_DCM_H */
