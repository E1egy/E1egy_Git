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
**  FILENAME    : BswM_Bsw.h                                                  **
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
#ifndef BSWM_BSW_H
#define BSWM_BSW_H

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
#if (BSWM_SCHM_ENABLED == STD_ON)
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"
/**
 * This is a mode request source emanating from another BSW Module.
 * Service ID:
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): modeGroup, the mode group in that the mode was switched
 *                 mode, the mode that was switched to.
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_CODE)
BswM_BswModeNotification(
    BswM_ModeGroupType modeGroup,
    BswM_ModeType mode
);
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif /*(BSWM_SCHM_ENABLED == STD_ON)*/
#endif /* BSWM_BSW_H */
