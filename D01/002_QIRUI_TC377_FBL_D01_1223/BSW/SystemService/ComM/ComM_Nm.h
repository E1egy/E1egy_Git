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
**  FILENAME    : ComM_Nm.h                                                   **
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
#ifndef COMM_NM_H
#define COMM_NM_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "NmStack_Types.h"
#include "ComM_Cfg.h"
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
#if (STD_ON == COMM_NM_USED)
#define COMM_START_SEC_COMMNMNETWORKSTARTINDICATION_CALLBACK_CODE
#include "ComM_MemMap.h"
/******************************************************************************/
/*
 * Brief               Indication that a NM-message has been received in the Bus
 *                     Sleep Mode, what indicates that some nodes in the network
 *                     have already entered the Network Mode.
 * ServiceId           0x15
 * ServiceId           Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Channel
 * Param-Name[in/out]  None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COMM_NM_CODE)
ComM_Nm_NetworkStartIndication(
    NetworkHandleType Channel
);
#define COMM_STOP_SEC_COMMNMNETWORKSTARTINDICATION_CALLBACK_CODE
#include "ComM_MemMap.h"

#define COMM_START_SEC_COMMNMNETWORKMODE_CALLBACK_CODE
#include "ComM_MemMap.h"
/******************************************************************************/
/*
 * Brief               Notification that the network management has entered
 *                     Network Mode.
 * ServiceId           0x18
 * ServiceId           Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Channel
 * Param-Name[in/out]  None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COMM_NM_CODE)
ComM_Nm_NetworkMode(
    NetworkHandleType Channel
);
#define COMM_STOP_SEC_COMMNMNETWORKMODE_CALLBACK_CODE
#include "ComM_MemMap.h"

#define COMM_START_SEC_COMMNMPREPAREBUSSLEEPMODE_CALLBACK_CODE
#include "ComM_MemMap.h"
/******************************************************************************/
/*
 * Brief               Notification that the network management has entered
 *                     Prepare Bus-Sleep Mode.
 * ServiceId           0x19
 * ServiceId           Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Channel
 * Param-Name[in/out]  None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COMM_NM_CODE)
ComM_Nm_PrepareBusSleepMode(
    NetworkHandleType Channel
);
#define COMM_STOP_SEC_COMMNMPREPAREBUSSLEEPMODE_CALLBACK_CODE
#include "ComM_MemMap.h"

#define COMM_START_SEC_COMMNMBUSSLEEPMODE_CALLBACK_CODE
#include "ComM_MemMap.h"
/******************************************************************************/
/*
 * Brief               Notification that the network management has entered
 *                     Bus-Sleep Mode.
 * ServiceId           0x1A
 * ServiceId           Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Channel
 * Param-Name[in/out]  None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COMM_NM_CODE)
ComM_Nm_BusSleepMode(
    NetworkHandleType Channel
);
#define COMM_STOP_SEC_COMMNMBUSSLEEPMODE_CALLBACK_CODE
#include "ComM_MemMap.h"

#define COMM_START_SEC_COMMNMRESTARTINDICATION_CALLBACK_CODE
#include "ComM_MemMap.h"
/******************************************************************************/
/*
 * Brief               If NmIf has started to shut down the coordinated busses,
 *                     AND not all coordinated busses have indicated bus sleep
 *                     state, AND on at least on one of the coordinated busses
 *                     NM is restarted, THEN the NM Interface shall call the
 *                     callback function ComM_Nm_RestartIndication with the
 *                     nmNetworkHandle of the channels which have already
 *                     indicated bus sleep state.
 * ServiceId           0x1B
 * ServiceId           Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Channel
 * Param-Name[in/out]  None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COMM_NM_CODE)
ComM_Nm_RestartIndication(
    NetworkHandleType Channel
);
#define COMM_STOP_SEC_COMMNMRESTARTINDICATION_CALLBACK_CODE
#include "ComM_MemMap.h"

#endif/* (STD_ON == COMM_NM_USED) */

#endif /* COMM_NM_H */
