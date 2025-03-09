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
**  FILENAME    : BswM_EthIf.h                                                **
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

#ifndef BSWM_ETHIF_H
#define BSWM_ETHIF_H

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
#if (BSWM_ETHIF_ENABLED == STD_ON)
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

/**
 * Function called by EthIf to indicate the link state change of a certain Ethernet switch port group.
 * Service ID: 0x26
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): PortGroupIdx, The port group index in the context of the Ethernet Interface
 *                 PortGroupState, The state of the port group. State is derived from the physical link of the
 *                                  Ethernet Transceiver: ETHTRCV_LINK_STATE_DOWN == Port group
 *                                  has link down. ETHTRCV_LINK_STATE_ACTIVE == Port group has link
 *                                  up.
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_ETHIF_CODE)
BswM_EthIf_PortGroupLinkStateChg
(
    EthIf_SwitchPortGroupIdxType PortGroupIdx,
    EthTrcv_LinkStateType PortGroupState
);
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif /*(BSWM_ETHIF_ENABLED == STD_ON)*/
#endif /* BSWM_ETHIF_H */
