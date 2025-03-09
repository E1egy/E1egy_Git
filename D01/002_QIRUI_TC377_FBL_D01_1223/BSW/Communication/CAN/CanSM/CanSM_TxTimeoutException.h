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
**  FILENAME    : CanSM_TxTimeoutException.h                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Callback function CanSM_TxTimeoutException as optional      **
**                interface to the CanNm module                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#ifndef CANSM_TXTIMEOUTEXCEPTION_H
#define CANSM_TXTIMEOUTEXCEPTION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"
#include "CanSM.h"
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
#define CANSM_START_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This function shall notify the CanSM module, that the
 *                     CanNm has detected for the affected partial CAN network
 *                     CAN network a tx timeout exception, which shall be
 *                     recovered within the respective network state machine of
 *                     the CanSM module.
 * ServiceId           0x0b
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel, Affected CAN network
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_TXTIMEOUTEXCEPTION_CODE)
CanSM_TxTimeoutException(
    NetworkHandleType Channel
);
#define CANSM_STOP_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#include "CanSM_MemMap.h"

#endif /* CANSM_TXTIMEOUTEXCEPTION_H */
