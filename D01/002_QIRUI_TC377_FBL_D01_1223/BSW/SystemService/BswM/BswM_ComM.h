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
**  FILENAME    : BswM_ComM.h                                                 **
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
#ifndef BSWM_COMM_H
#define BSWM_COMM_H

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
#if (BSWM_COMM_ENABLED == STD_ON)
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"
/**
 * Function called by ComM to signal a shutdown.
 * Service ID: 0x22
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters(IN): NA
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_COMM_CODE)
BswM_ComM_InitiateReset
(
    void
);

/**
 * Function called by ComM to indicate the current communication mode of a ComM
 * channel.
 * Service ID: 0x0e
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Network, the ComM communication channel that the indicated
 *                          state corresponds to
 *                 RequestedMode, the current state of the ComM communication channel
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_COMM_CODE)
BswM_ComM_CurrentMode
(
    NetworkHandleType Network,
    ComM_ModeType RequestedMode
);

#if (BSWM_COMM_PNC_ENABLED == STD_ON)
/**
 * Function called by ComM to indicate the current mode of the PNC.
 * Service ID: 0x15
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): PNC, the handle of the PNC for which the current state is reported
 *                 CurrentPncMode, the current mode of the PNC
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_COMM_CODE)
BswM_ComM_CurrentPNCMode
(
    PNCHandleType PNC,
    ComM_PncModeType CurrentPncMode
);
#endif /*(BSWM_COMM_PNC_ENABLED == STD_ON)*/
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif /*(BSWM_COMM_ENABLED == STD_ON)*/
#endif /* BSWM_COMM_H */
