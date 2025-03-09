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
**  FILENAME    : CanSM_ComM.h                                                **
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
**                      REVISION   HISTORY                                    **
*******************************************************************************/
/* <VERSION>  <DATE>    <AUTHOR>      <REVISION LOG>
 *  V2.0.0    2020-08-17  lili.wang    R19_11 initial version.
*/
#ifndef CANSM_COMM_H
#define CANSM_COMM_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComM.h"
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
#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This service shall change the communication mode of a CAN
 *                     network to the requested one.
 * ServiceId           0x02
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant (only for different network handles)
 * Param-Name[in]      network, Handle of destined communication network for request
 *                     ComM_Mode, Requested communication mode
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: Service accepted
 *                     E_NOT_OK: Service denied
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANSM_COMM_CODE)
CanSM_RequestComMode(
    NetworkHandleType network,
    ComM_ModeType ComM_Mode
);

/******************************************************************************/
/*
 * Brief               This service shall put out the current communication mode
 *                     of a CAN network.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      network, Network handle, whose current communication mode
 *                     shall be put out
 * Param-Name[out]     ComM_ModePtr, Pointer where to put out the current
 *                     communication mode
 * Param-Name[in/out]  NA
 * Return              E_OK: Service accepted E_NOT_OK: Service denied
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANSM_COMM_CODE)
CanSM_GetCurrentComMode(
    NetworkHandleType network,
    P2VAR(ComM_ModeType, AUTOMATIC, CANSM_APPL_DATA) ComM_ModePtr
);

#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.h"

#endif /* CANSM_COMM_H */
