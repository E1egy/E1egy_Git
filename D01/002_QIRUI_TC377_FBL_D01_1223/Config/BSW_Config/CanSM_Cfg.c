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
**  FILENAME    : CanSM_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2023/01/07 16:32:06                                         ** 
**  Author      : wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build configuration parameter of CANSM                 **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*=======[I N C L U D E S]====================================================*/
#include "CanSM_Cfg.h"
#include "CanSM.h"
#include "CanIf_Cfg.h"
#include "ComM_Cfg.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"

static CONST(uint8, CANSM_CONST) CanSM_MN_0ControllerId[1] = {CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_TEST_CAN};/*CanSMControllerId*/
static CONST(uint8, CANSM_CONST) CanSM_MN_1ControllerId[1] = {CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD};/*CanSMControllerId*/

static CONST(CanSM_ControllerRefType, CANSM_CONST) CanSM_ControllerConfig[CANSM_NETWORK_NUM] =
{
    {
        0x1,
        &CanSM_MN_0ControllerId[0]
    },
    {
        0x1,
        &CanSM_MN_1ControllerId[0]
    },
};

static CONST(CanSM_ManagerNetworkType, CANSM_CONST) CanSM_NetworkConfig [CANSM_NETWORK_NUM] =
{
    {
        0x5,    /*CanSMBorCounterL1ToL2 */
        0x64,           /*CanSMBorTimeL1 */
        0x3e8,           /*CanSMBorTimeL2 */
        0xa,           /*CanSMBorTimeTxEnsured */
        FALSE,          /*CanSMBorTxConfirmationPolling */
        FALSE,          /*CanSMEnableBusOffDelay */
        Channel_CanController_TEST_CAN,                        /*CanSMComMNetworkHandleRef*/
        NULL_PTR,
        &CanSM_ControllerConfig[0],

    },
    {
        0x5,    /*CanSMBorCounterL1ToL2 */
        0x64,           /*CanSMBorTimeL1 */
        0x3e8,           /*CanSMBorTimeL2 */
        0xa,           /*CanSMBorTimeTxEnsured */
        FALSE,          /*CanSMBorTxConfirmationPolling */
        FALSE,          /*CanSMEnableBusOffDelay */
        Channel_CanController_CAN1_FD,                        /*CanSMComMNetworkHandleRef*/
        NULL_PTR,
        &CanSM_ControllerConfig[1],

    },
};

CONST(CanSM_ConfigType, CANSM_CONST) CanSM_Config =
{
    0xa,    /*CanSMModeRequestRepetitionMax */
    0xa,    /*CanSMModeRequestRepetitionTime */
    &CanSM_NetworkConfig[0]
};

#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
