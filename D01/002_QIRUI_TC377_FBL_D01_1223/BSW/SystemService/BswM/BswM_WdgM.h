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
**  FILENAME    : BswM_WdgM.h                                                 **
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
#ifndef BSWM_WDGM_H
#define BSWM_WDGM_H

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
#if (BSWM_WDGM_ENABLED == STD_ON)
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"
/**
 * Function called by WdgM to request a partition reset.
 * Usage/Configuration clarification:
 * Service ID: 0x11
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Application, The identifier of an OS-Application
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_WDGM_CODE)
BswM_WdgM_RequestPartitionReset
(
    ApplicationType Application
);
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif /*(BSWM_WDGM_ENABLED == STD_ON)*/
#endif /* BSWM_WDGM_H */
