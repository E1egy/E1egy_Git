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
**  FILENAME    : BswM_EcuM.h                                                 **
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
#ifndef BSWM_ECUM_H
#define BSWM_ECUM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Internal.h"
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
#if (BSWM_ECUM_ENABLED == STD_ON)
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"
/**
 * Function called by EcuM to indicate the current state of a wakeup source.
 * Service ID: 0x10
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): source, wakeup source(s) that changed state
 *                 state, the new state of the wakeup source(s)
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_ECUM_CODE)
BswM_EcuM_CurrentWakeup
(
    EcuM_WakeupSourceType source,
    EcuM_WakeupStatusType state
);

/******Compatible with lower versions******/

/**
 * Function called by EcuM to notify about current Status of the Run Request
 * Protocol.
 * Service ID: 0x23
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): State, the requested state by EcuMFlex
 *                 CurrentStatus, result of the Run Request Protocol
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_ECUM_CODE)
BswM_EcuM_RequestedState(
    EcuM_StateType State,
    EcuM_RunStatusType CurrentStatus
);

/**
 * Function called by EcuM to indicate the current ECU Operation Mode.
 * Service ID: 0x0f
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): CurrentState, the requested ECU Operation Mode
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_ECUM_CODE)
BswM_EcuM_CurrentState(
    EcuM_StateType CurrentState
);
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif /*(BSWM_ECUM_ENABLED == STD_ON)*/
#endif /* BSWM_ECUM_H */
