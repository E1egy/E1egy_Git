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
**  FILENAME    : BswM_MemMap.h                                               **
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
#ifndef BSWM_MEMMAP_H
#define BSWM_MEMMAP_H

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
#if (BSWM_SD_ENABLED == STD_ON)
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"
/**
 * Function called by Service Discovery to indicate current state of the Client
 * Service (available/down).
 * Service ID: 0x1f
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): SdClientServiceHandleId, HandleId to identify the ClientService
 *                 CurrentClientState, Current state of the ClientService
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_SD_CODE)
BswM_Sd_ClientServiceCurrentState
(
    uint16 SdClientServiceHandleId,
    Sd_ClientServiceCurrentStateType CurrentClientState
);

/**
 * Function called by Service Discovery to indicate current status of the
 * Consumed Eventgroup (available/down).
 * Service ID: 0x21
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): SdConsumedEventGroupHandleId, HandleId to identify the Consumed Eventgroup
 *                 ConsumedEventGroupState, Status of the Consumed Eventgroup
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_SD_CODE)
BswM_Sd_ConsumedEventGroupCurrentState
(
    uint16 SdConsumedEventGroupHandleId,
    Sd_ConsumedEventGroupCurrentStateType ConsumedEventGroupState
);

/**
 * Function called by Service Discovery to indicate current status of the
 * EventHandler (requested/released).
 * Service ID: 0x20
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): SdEventHandlerHandleId, HandleId to identify the EventHandler
 *                 EventHandlerStatus, Status of the EventHandler
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_SD_CODE)
BswM_Sd_EventHandlerCurrentState
(
    uint16 SdEventHandlerHandleId,
    Sd_EventHandlerCurrentStateType EventHandlerStatus
);
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif /*(BSWM_SD_ENABLED == STD_ON)*/
#endif /* BSWM_MEMMAP_H */
