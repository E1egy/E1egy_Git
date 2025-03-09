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
**  FILENAME    : Nm_Cbk.h                                                    **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef NM_CBK_H_
#define NM_CBK_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nm_Cfg.h"
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
#define NM_START_SEC_NM_NETWORKSTARTINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
/******************************************************************************/
/*
* Brief               Notification that a NM-message has been received in the
*                     Bus-Sleep Mode, what indicates that some nodes in the
*                     network have already entered the Network Mode.
* ServiceId           0x11
* Sync/Async          Asynchronous
* Reentrancy          Reentrant
* Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
* Param-Name[out]     NA
* Param-Name[in/out]  NA
* Return              NA
*/
/******************************************************************************/
FUNC(void, NM_CODE)
Nm_NetworkStartIndication(
    NetworkHandleType nmNetworkHandle
);
#define NM_STOP_SEC_NM_NETWORKSTARTINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"

#define NM_START_SEC_NM_NETWORKMODE_CALLBACK_CODE
#include "Nm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Notification that the network management has entered Network Mode.
 * ServiceId           0x12
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[in/out]  NA
 * Param-Name[out]     NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, NM_CODE)
Nm_NetworkMode(
    NetworkHandleType nmNetworkHandle
);
#define NM_STOP_SEC_NM_NETWORKMODE_CALLBACK_CODE
#include "Nm_MemMap.h"

#define NM_START_SEC_NM_BUSSLEEPMODE_CALLBACK_CODE
#include "Nm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Notification that the network management has entered Bus-Sleep
 *                     Mode.
 * ServiceId           0x14
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, NM_CODE) Nm_BusSleepMode(
    NetworkHandleType nmNetworkHandle
);
#define NM_STOP_SEC_NM_BUSSLEEPMODE_CALLBACK_CODE
#include "Nm_MemMap.h"

#define NM_START_SEC_NM_PREPAREBUSSLEEPMODE_CALLBACK_CODE
#include "Nm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Notification that the network management has entered Prepare
 *                     Bus-Sleep Mode.
 * ServiceId           0x13
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, NM_CODE) Nm_PrepareBusSleepMode(
    NetworkHandleType nmNetworkHandle
);
#define NM_STOP_SEC_NM_PREPAREBUSSLEEPMODE_CALLBACK_CODE
#include "Nm_MemMap.h"


#if (STD_ON ==  NM_REMOTE_SLEEP_IND_ENABLED)
/******************************************************************************/
/*
 * Brief               Notification that the network management has detected that
 *                     all other nodes on the network are ready to enter Bus-Sleep
 *                     Mode.
 * ServiceId           0x17
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_REMOTESLEEPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_RemoteSleepIndication(
    NetworkHandleType nmNetworkHandle
);
#define NM_STOP_SEC_NM_REMOTESLEEPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"

#define NM_START_SEC_NM_REMOTESLEEPCANCELLATION_CALLBACK_CODE
#include "Nm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Notification that the network management has detected that
 *                     not all other nodes on the network are longer ready to enter
 *                     Bus-Sleep Mode
 * ServiceId           0x18
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, NM_CODE) Nm_RemoteSleepCancellation(
    NetworkHandleType nmNetworkHandle
);
#define NM_STOP_SEC_NM_REMOTESLEEPCANCELLATION_CALLBACK_CODE
#include "Nm_MemMap.h"

#define NM_START_SEC_NM_SYNCHRONIZATIONPOINT_CALLBACK_CODE
#include "Nm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Notification to the NM Coordinator functionality that this
 *                     is a suitable point in time to initiate the coordinated
 *                     shutdown on
 * ServiceId           0x19
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, NM_CODE)
Nm_SynchronizationPoint(
    NetworkHandleType nmNetworkHandle
);
#define NM_STOP_SEC_NM_SYNCHRONIZATIONPOINT_CALLBACK_CODE
#include "Nm_MemMap.h"

#endif/* STD_ON ==  NM_REMOTE_SLEEP_IND_ENABLED */

#if (STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT)
#define NM_START_SEC_NM_COORDREADYTOSLEEPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Sets an indication, when the NM Coordinator Sleep Ready
 *                     bit in the Control Bit Vector is set
 * ServiceId           0x1e
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, NM_CODE)
Nm_CoordReadyToSleepIndication(
    NetworkHandleType nmChannelHandle
);
#define NM_STOP_SEC_NM_COORDREADYTOSLEEPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"

#define NM_START_SEC_NM_COORDREADYTOSLEEPCANCELLATION_CALLBACK_CODE
#include "Nm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Cancels an indication, when the NM Coordinator Sleep Ready
 *                     bit in the Control Bit Vector is set back to 0
 * ServiceId           0x1f
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, NM_CODE)
Nm_CoordReadyToSleepCancellation(
    NetworkHandleType nmChannelHandle
);
#define NM_STOP_SEC_NM_COORDREADYTOSLEEPCANCELLATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif/* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */

/* 8.4.2
Extra Call-back notifications */
#if (STD_ON ==  NM_PDU_RX_INDICATION_ENABLED)
/******************************************************************************/
/*
 * Brief               Notification that a NM message has been received.
 * ServiceId           0x15
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_PDURXINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_PduRxIndication(
    NetworkHandleType nmNetworkHandle
);
#define NM_STOP_SEC_NM_PDURXINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif/* STD_ON ==  NM_PDU_RX_INDICATION_ENABLED */

#if (STD_ON == NM_STATE_CHANGE_IND_ENABLED)
/******************************************************************************/
/*
 * Brief               Notification that a NM message has been received.
 * ServiceId           0x16
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 *                     nmPreviousState,Previous state of the NM-channel
 *                     nmCurrentState,Current (new) state of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_STATECHANGENOTIFICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_StateChangeNotification(
    NetworkHandleType nmNetworkHandle,
    Nm_StateType nmPreviousState,
    Nm_StateType nmCurrentState
);
#define NM_STOP_SEC_NM_STATECHANGENOTIFICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif/* STD_ON == NM_STATE_CHANGE_IND_ENABLED */

#if (STD_ON ==  NM_REPEAT_MSG_IND_ENABLED)
/******************************************************************************/
/*
 * Brief               Service to indicate that an NM message with set Repeat
 *                     Message Request Bit has been received
 * ServiceId           0x1a
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_REPEATMESSAGEINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_RepeatMessageIndication(
    NetworkHandleType nmNetworkHandle
);
#define NM_STOP_SEC_NM_REPEATMESSAGEINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif/* STD_ON ==  NM_REPEAT_MSG_IND_ENABLED */

/******************************************************************************/
/*
 * Brief               Service to indicate that an attempt to send an NM message
 *                     failed.
 * ServiceId           0x1b
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_TxTimeoutException(
    NetworkHandleType nmNetworkHandle
);
#define NM_STOP_SEC_NM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#include "Nm_MemMap.h"

#if (STD_ON == NM_CAR_WAKE_UP_RX_ENABLED)
/******************************************************************************/
/*
 * Brief               This function is called by a <Bus>Nm to indicate reception
 *                     of a CWU request
 * ServiceId           0x1d
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmNetworkHandle,Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
#define NM_START_SEC_NM_CARWAKEUPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
FUNC(void, NM_CODE)
Nm_CarWakeUpIndication(
    NetworkHandleType nmChannelHandle
);
#define NM_STOP_SEC_NM_CARWAKEUPINDICATION_CALLBACK_CODE
#include "Nm_MemMap.h"
#endif/* STD_ON == NM_CAR_WAKE_UP_RX_ENABLED */

#endif/* NM_CBK_H_ */
