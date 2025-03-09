
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
**  FILENAME    : ComM_Cfg.c                                                  **
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
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define COMM_CFG_C_AR_RELEASE_MAJOR_VERSION  19u
#define COMM_CFG_C_AR_RELEASE_MINOR_VERSION  11u
#define COMM_CFG_C_AR_RELEASE_PATCH_VERSION  0u
#define COMM_CFG_C_SW_MAJOR_VERSION          1u
#define COMM_CFG_C_SW_MINOR_VERSION          0u
#define COMM_CFG_C_SW_PATCH_VERSION          0u

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComM_Cfg.h"
#include "ComM.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (COMM_CFG_C_AR_MAJOR_VERSION != COMM_CFG_H_AR_MAJOR_VERSION)
    #error "ComM_Cfg.c:Mismatch in Specification Major Version"
#endif /*COMM_CFG_C_AR_MAJOR_VERSION != COMM_CFG_H_AR_MAJOR_VERSION */
#if (COMM_CFG_C_AR_MINOR_VERSION != COMM_CFG_H_AR_MINOR_VERSION)
    #error "ComM_Cfg.c:Mismatch in Specification Minor Version"
#endif /*COMM_CFG_C_AR_MINOR_VERSION != COMM_CFG_H_AR_MINOR_VERSION */
#if (COMM_CFG_C_AR_PATCH_VERSION != COMM_CFG_H_AR_PATCH_VERSION)
    #error "ComM_Cfg.c:Mismatch in Specification Patch Version"
#endif /*COMM_CFG_C_AR_PATCH_VERSION != COMM_CFG_H_AR_PATCH_VERSION */
#if (COMM_CFG_C_SW_MAJOR_VERSION != COMM_CFG_H_SW_MAJOR_VERSION)
    #error "ComM_Cfg.c:Mismatch in Specification Major Version"
#endif /*COMM_CFG_C_SW_MAJOR_VERSION != COMM_CFG_H_SW_MAJOR_VERSION */
#if (COMM_CFG_C_SW_MINOR_VERSION != COMM_CFG_H_SW_MINOR_VERSION)
    #error "ComM_Cfg.c:Mismatch in Specification Minor Version"
#endif /*COMM_CFG_C_SW_MINOR_VERSION != COMM_CFG_H_SW_MINOR_VERSION */

/*===========================[E X T E R N A L   D A T A]==========================================*/
#define COMM_START_SEC_CONST_BOOLEAN
#include "ComM_MemMap.h"
CONST(boolean, COMM_CONST) ComMPncEnabledcfg = FALSE;    /*ComMPncEnabled*/

#define COMM_STOP_SEC_CONST_BOOLEAN
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "ComM_MemMap.h"

CONST(uint8, COMM_CONST) ComM_UserIndex_RefToChannel_CanController_TEST_CAN[1u] ={0u};

CONST(uint8, COMM_CONST) ComM_UserIndex_RefToChannel_CanController_CAN1_FD[1u] ={1u};

CONST(ComM_ChannelCfgType, COMM_CONST) ComM_ChannelConfig[COMM_NUMBER_OF_CHANNELS] =
{
    {
        COMM_BUS_TYPE_CAN,/*ComMBusType*/
        0u,    /*ComMCDDBusPrefix*/
        FALSE,   /*ComMFullCommRequestNotificationEnabled*/
        10u,  /*ComMMainFunctionPeriod*/
        FALSE, /*ComMNoWakeUpInhibitionNvmStorage*/
        COMM_CHANNEL_TYPE_NULL,/*ComMManageType*/
        0,/*ComMManageChannelNum*/
        NULL_PTR,/*ComMManageReference*/
        COMM_LIGHT,   /*ComMNmVariant*/
        10000u,  /*ComMNmLightTimeout*/
        1u,  /*NumofUserRefToChannel*/
        &ComM_UserIndex_RefToChannel_CanController_TEST_CAN[0],  /*UserRefToChannelMap*/
        0u,  /*NumofPncRefToChannel*/
        NULL_PTR,  /*PncRefToChannelMap*/
        NULL_PTR /*ChannelPartitionRef*/
    },
    {
        COMM_BUS_TYPE_CAN,/*ComMBusType*/
        0u,    /*ComMCDDBusPrefix*/
        FALSE,   /*ComMFullCommRequestNotificationEnabled*/
        10u,  /*ComMMainFunctionPeriod*/
        FALSE, /*ComMNoWakeUpInhibitionNvmStorage*/
        COMM_CHANNEL_TYPE_NULL,/*ComMManageType*/
        0,/*ComMManageChannelNum*/
        NULL_PTR,/*ComMManageReference*/
        COMM_FULL,   /*ComMNmVariant*/
        0u,  /*ComMNmLightTimeout*/
        1u,  /*NumofUserRefToChannel*/
        &ComM_UserIndex_RefToChannel_CanController_CAN1_FD[0],  /*UserRefToChannelMap*/
        0u,  /*NumofPncRefToChannel*/
        NULL_PTR,  /*PncRefToChannelMap*/
        NULL_PTR /*ChannelPartitionRef*/
    },
};
CONST(uint8, COMM_CONST) ComM_ChannelIndex_RefToComMUser_Ch0[1u] = {0u};
CONST(uint8, COMM_CONST) ComM_ChannelIndex_RefToComMUser_Ch1[1u] = {1u};

CONST(ComM_UserCfgType, COMM_CONST) ComM_UserConfig[COMM_NUMBER_OF_USERS] =
{
    {
        1u,  /*NumofChannelRefToUser*/
        &ComM_ChannelIndex_RefToComMUser_Ch0[0],  /*ChannelRefToUserMap*/
        NULL_PTR,/*RteNotify*/
        0u,  /*NumofPncRefToUser*/
        NULL_PTR,  /*PncRefToUserMap*/
        NULL_PTR
    } ,
    {
        1u,  /*NumofChannelRefToUser*/
        &ComM_ChannelIndex_RefToComMUser_Ch1[0],  /*ChannelRefToUserMap*/
        NULL_PTR,/*RteNotify*/
        0u,  /*NumofPncRefToUser*/
        NULL_PTR,  /*PncRefToUserMap*/
        NULL_PTR
    } ,
};

CONST(ComM_ConfigType, COMM_CONST) ComM_Config =
{
    &ComMPncEnabledcfg,    /*pComMPncEnabled, Multiplicity 0...1*/
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "ComM_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

