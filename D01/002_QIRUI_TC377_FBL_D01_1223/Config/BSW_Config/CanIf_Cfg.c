
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
**  FILENAME    : CanIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2023/02/27 21:42:14                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :parameter declaration of CanIf                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define CANIF_CFG_C_AR_MAJOR_VERSION  4u
#define CANIF_CFG_C_AR_MINOR_VERSION  2u
#define CANIF_CFG_C_AR_PATCH_VERSION  2u
#define CANIF_CFG_C_SW_MAJOR_VERSION  2u
#define CANIF_CFG_C_SW_MINOR_VERSION  0u
#define CANIF_CFG_C_SW_PATCH_VERSION  0u

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf.h"
#include "CanSM_Cbk.h"
#include "CanTp_Cbk.h"
#include "CanTp.h"
#include "CanNm_Cbk.h"
#include "PduR_CanIf.h"
#include "XcpOnCan_Cbk.h"
#include "Can_17_McmCan.h"
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CANIF_CFG_C_AR_MAJOR_VERSION != CANIF_CFG_H_AR_MAJOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Major Version"
#endif

#if (CANIF_CFG_C_AR_MINOR_VERSION != CANIF_CFG_H_AR_MINOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Minor Version"
#endif

#if (CANIF_CFG_C_AR_PATCH_VERSION != CANIF_CFG_H_AR_PATCH_VERSION)
    #error "CanIf.c:Mismatch in Specification Patch Version"
#endif

#if (CANIF_CFG_C_SW_MAJOR_VERSION != CANIF_CFG_H_SW_MAJOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Major Version"
#endif

#if (CANIF_CFG_C_SW_MINOR_VERSION != CANIF_CFG_H_SW_MINOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Minor Version"
#endif

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_DispatchConfigType,CANIF_CONST) CanIf_DispatchConfigData =
{
    /* void XXX_ControllerBusOff(uint8 ControllerId) */
    &CanSM_ControllerBusOff,
    /* void XXX_ControllerModeIndication(uint8 ControllerId,CanIf_ControllerModeType ControllerMode)  */
    &CanSM_ControllerModeIndication,
    /* void XXX_TransceiverModeIndication(uint8 TransceiverId,CanTrcv_TrcvModeType TransceiverMode) */
    NULL_PTR,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(Can_DriverApiType,CANIF_CONST_PBCFG) Can_DriverApi[CANIF_CANDRIVER_NUMBER] =
{
    {
        &Can_17_McmCan_SetControllerMode,
        &Can_17_McmCan_Write,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfCtrlCanCtrlRefType,CANIF_CONST_PBCFG) CanIf_CtrlRef[CANIF_CANCONTROLLER_NUMBER] =
{
    {
        0u,0u|0u
    },
    {
        1u,0u|0u
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_ControllerCfgType,CANIF_CONST) CanIf_CtrlCfgData[CANIF_CANCONTROLLER_NUMBER] =
{
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_TEST_CAN,
        CANIF_CAN_17_MCMCAN,
        FALSE,
        &CanIf_CtrlRef[0],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        CANIF_CAN_17_MCMCAN,
        FALSE,
        &CanIf_CtrlRef[1],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfHrhIdSymRefType,CANIF_CONST_PBCFG) CanIf_HrhRef[CANIF_HRH_NUMBER] =
{
    {
        5u,
        CANIF_BASIC_CAN,
    },
    {
        4u,
        CANIF_FULL_CAN,
    },
    {
        6u,
        CANIF_FULL_CAN,
    },
    {
        8u,
        CANIF_FULL_CAN,
    },
    {
        15u,
        CANIF_FULL_CAN,
    },
    {
        13u,
        CANIF_FULL_CAN,
    },
    {
        14u,
        CANIF_FULL_CAN,
    },
    {
        7u,
        CANIF_FULL_CAN,
    },
    {
        20u,
        CANIF_FULL_CAN,
    },
    {
        9u,
        CANIF_FULL_CAN,
    },
    {
        10u,
        CANIF_FULL_CAN,
    },
    {
        11u,
        CANIF_FULL_CAN,
    },
    {
        12u,
        CANIF_FULL_CAN,
    },
    {
        0u,
        CANIF_FULL_CAN,
    },
    {
        17u,
        CANIF_BASIC_CAN,
    },
    {
        1u,
        CANIF_FULL_CAN,
    },
    {
        2u,
        CANIF_FULL_CAN,
    },
    {
        3u,
        CANIF_FULL_CAN,
    },
    {
        24u,
        CANIF_FULL_CAN,
    },
    {
        25u,
        CANIF_FULL_CAN,
    },
    {
        21u,
        CANIF_FULL_CAN,
    },
    {
        22u,
        CANIF_FULL_CAN,
    },
    {
        23u,
        CANIF_FULL_CAN,
    },
    {
        26u,
        CANIF_FULL_CAN,
    },
    {
        16u,
        CANIF_FULL_CAN,
    },
    {
        19u,
        CANIF_FULL_CAN,
    },
    {
        18u,
        CANIF_FULL_CAN,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef0[1] =
{
    CANIF_RXPDU_CanIf_PhyReq,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef1[1] =
{
    CANIF_RXPDU_CanIf_FunReq,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef2[1] =
{
    CANIF_RXPDU_EPB_State_R,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef3[1] =
{
    CANIF_RXPDU_IPB_ADS,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef4[1] =
{
    CANIF_RXPDU_VIU_Route_SUS,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef5[1] =
{
    CANIF_RXPDU_VIU_DoorLock,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef6[1] =
{
    CANIF_RXPDU_VIU_Info,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef7[1] =
{
    CANIF_RXPDU_EPS_State,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef8[1] =
{
    CANIF_RXPDU_ABM_State,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef9[1] =
{
    CANIF_RXPDU_IPB_State1,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef10[1] =
{
    CANIF_RXPDU_IPB_Tq,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef11[1] =
{
    CANIF_RXPDU_IPB_Wheel,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef12[1] =
{
    CANIF_RXPDU_TBOX_TimeInfo,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef13[1] =
{
    CANIF_RXPDU_ScrToECAS,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef14[1] =
{
    CANIF_RXPDU_CANNM_RX_CANFD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef15[1] =
{
    CANIF_RXPDU_XCP_Master_0x601,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef16[1] =
{
    CANIF_RXPDU_BT_Master,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef17[1] =
{
    CANIF_RXPDU_ECAS_DV_BA_Req,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef18[1] =
{
    CANIF_RXPDU_VIU_Config,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef19[1] =
{
    CANIF_RXPDU_VIU_ConfigTrig,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef20[1] =
{
    CANIF_RXPDU_ADS_ECAS,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef21[1] =
{
    CANIF_RXPDU_ADS_State,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef22[1] =
{
    CANIF_RXPDU_VDC_CDCSet,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef23[1] =
{
    CANIF_RXPDU_VDC_VIU_BodyInfo,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef24[1] =
{
    CANIF_RXPDU_VDC_FMtTq,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef25[1] =
{
    CANIF_RXPDU_VDC_RMtTq,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef26[1] =
{
    CANIF_RXPDU_VDC_PTSt,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfHrhCfgType,CANIF_CONST) CanIf_HrhCfgData[CANIF_HRH_NUMBER] =
{
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef0[0],
        NULL_PTR,
        &CanIf_HrhRef[0],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef1[0],
        NULL_PTR,
        &CanIf_HrhRef[1],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef2[0],
        NULL_PTR,
        &CanIf_HrhRef[2],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef3[0],
        NULL_PTR,
        &CanIf_HrhRef[3],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef4[0],
        NULL_PTR,
        &CanIf_HrhRef[4],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef5[0],
        NULL_PTR,
        &CanIf_HrhRef[5],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef6[0],
        NULL_PTR,
        &CanIf_HrhRef[6],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef7[0],
        NULL_PTR,
        &CanIf_HrhRef[7],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef8[0],
        NULL_PTR,
        &CanIf_HrhRef[8],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef9[0],
        NULL_PTR,
        &CanIf_HrhRef[9],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef10[0],
        NULL_PTR,
        &CanIf_HrhRef[10],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef11[0],
        NULL_PTR,
        &CanIf_HrhRef[11],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef12[0],
        NULL_PTR,
        &CanIf_HrhRef[12],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_TEST_CAN,
        0u,
        1u,
        &CanIf_HrhRxPduRef13[0],
        NULL_PTR,
        &CanIf_HrhRef[13],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef14[0],
        NULL_PTR,
        &CanIf_HrhRef[14],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_TEST_CAN,
        0u,
        1u,
        &CanIf_HrhRxPduRef15[0],
        NULL_PTR,
        &CanIf_HrhRef[15],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_TEST_CAN,
        0u,
        1u,
        &CanIf_HrhRxPduRef16[0],
        NULL_PTR,
        &CanIf_HrhRef[16],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef17[0],
        NULL_PTR,
        &CanIf_HrhRef[17],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef18[0],
        NULL_PTR,
        &CanIf_HrhRef[18],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef19[0],
        NULL_PTR,
        &CanIf_HrhRef[19],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef20[0],
        NULL_PTR,
        &CanIf_HrhRef[20],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef21[0],
        NULL_PTR,
        &CanIf_HrhRef[21],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef22[0],
        NULL_PTR,
        &CanIf_HrhRef[22],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef23[0],
        NULL_PTR,
        &CanIf_HrhRef[23],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef24[0],
        NULL_PTR,
        &CanIf_HrhRef[24],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef25[0],
        NULL_PTR,
        &CanIf_HrhRef[25],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        0u,
        1u,
        &CanIf_HrhRxPduRef26[0],
        NULL_PTR,
        &CanIf_HrhRef[26],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfHthIdSymRefType,CANIF_CONST_PBCFG) CanIf_HthRef[CANIF_HTH_NUMBER] =
{
    {
        40u,
        CANIF_FULL_CAN,
    },
    {
        37u,
        CANIF_FULL_CAN,
    },
    {
        41u,
        CANIF_FULL_CAN,
    },
    {
        38u,
        CANIF_FULL_CAN,
    },
    {
        39u,
        CANIF_FULL_CAN,
    },
    {
        36u,
        CANIF_FULL_CAN,
    },
    {
        42u,
        CANIF_FULL_CAN,
    },
    {
        27u,
        CANIF_FULL_CAN,
    },
    {
        28u,
        CANIF_FULL_CAN,
    },
    {
        29u,
        CANIF_FULL_CAN,
    },
    {
        30u,
        CANIF_FULL_CAN,
    },
    {
        31u,
        CANIF_FULL_CAN,
    },
    {
        32u,
        CANIF_FULL_CAN,
    },
    {
        33u,
        CANIF_FULL_CAN,
    },
    {
        34u,
        CANIF_FULL_CAN,
    },
    {
        35u,
        CANIF_FULL_CAN,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfHthCfgType,CANIF_CONST) CanIf_HthCfgData[CANIF_HTH_NUMBER] =
{
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[0],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[1],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[2],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[3],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[4],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[5],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[6],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_TEST_CAN,
        &CanIf_HthRef[7],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_TEST_CAN,
        &CanIf_HthRef[8],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_TEST_CAN,
        &CanIf_HthRef[9],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[10],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[11],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[12],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[13],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[14],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN1_FD,
        &CanIf_HthRef[15],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_InitHohCfgType,CANIF_CONST) CanIf_InitHohCfgData =
{
    CanIf_HrhCfgData,
    CanIf_HthCfgData,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfRxPduRefType,CANIF_CONST_PBCFG) CanIf_RxPduRef[CANIF_RXPDU_NUMBER] =
{
    {
        CANTP_CanIf_PhyReq,
        FALSE
    },
    {
        CANTP_CanIf_FunReq,
        FALSE
    },
    {
        PDUR_SRCPDU_EPB_State_R,
        FALSE
    },
    {
        PDUR_SRCPDU_IPB_ADS,
        FALSE
    },
    {
        PDUR_SRCPDU_VIU_Route_SUS,
        FALSE
    },
    {
        PDUR_SRCPDU_VIU_DoorLock,
        FALSE
    },
    {
        PDUR_SRCPDU_VIU_Info,
        FALSE
    },
    {
        PDUR_SRCPDU_EPS_State,
        FALSE
    },
    {
        PDUR_SRCPDU_ABM_State,
        FALSE
    },
    {
        PDUR_SRCPDU_IPB_State1,
        FALSE
    },
    {
        PDUR_SRCPDU_IPB_Tq,
        FALSE
    },
    {
        PDUR_SRCPDU_IPB_Wheel,
        FALSE
    },
    {
        PDUR_SRCPDU_TBOX_TimeInfo,
        FALSE
    },
    {
        PDUR_SRCPDU_ScrToECAS,
        FALSE
    },
    {
        CANNM_RX_PDU_0,
        FALSE
    },
    {
        XCP_XCP_Master_0x601,
        FALSE
    },
    {
        PDUR_SRCPDU_BT_Master,
        FALSE
    },
    {
        PDUR_SRCPDU_ECAS_DV_BA_Req,
        FALSE
    },
    {
        PDUR_SRCPDU_VIU_Config,
        FALSE
    },
    {
        PDUR_SRCPDU_VIU_ConfigTrig,
        FALSE
    },
    {
        PDUR_SRCPDU_ADS_ECAS,
        FALSE
    },
    {
        PDUR_SRCPDU_ADS_State,
        FALSE
    },
    {
        PDUR_SRCPDU_VDC_CDCSet,
        FALSE
    },
    {
        PDUR_SRCPDU_VDC_VIU_BodyInfo,
        FALSE
    },
    {
        PDUR_SRCPDU_VDC_FMtTq,
        FALSE
    },
    {
        PDUR_SRCPDU_VDC_RMtTq,
        FALSE
    },
    {
        PDUR_SRCPDU_VDC_PTSt,
        FALSE
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_RxPduConfigType,CANIF_CONST) CanIf_RxPduConfigData[CANIF_RXPDU_NUMBER] =
{
    {
        CANIF_RXPDU_CanIf_PhyReq,
        0x72bu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_0,
        FALSE,
        &CanTp_RxIndication,
        &CanIf_RxPduRef[0],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_CanIf_FunReq,
        0x7dfu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_1,
        FALSE,
        &CanTp_RxIndication,
        &CanIf_RxPduRef[1],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_EPB_State_R,
        0x196u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_2,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[2],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_IPB_ADS,
        0x195u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        24u,
        CANIF_HOH0_HRH_3,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[3],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_VIU_Route_SUS,
        0x34bu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_4,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[4],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_VIU_DoorLock,
        0x2b0u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_5,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[5],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_VIU_Info,
        0x1d2u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_6,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[6],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_EPS_State,
        0x114u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_7,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[7],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_ABM_State,
        0x119u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        20u,
        CANIF_HOH0_HRH_8,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[8],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_IPB_State1,
        0x192u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_9,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[9],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_IPB_Tq,
        0x116u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_10,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[10],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_IPB_Wheel,
        0x112u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_11,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[11],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_TBOX_TimeInfo,
        0x5e2u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_12,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[12],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_ScrToECAS,
        0xau,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_13,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[13],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_CANNM_RX_CANFD,
        0x400u,
        0x780u,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_14,
        TRUE,
        &CanNm_RxIndication,
        &CanIf_RxPduRef[14],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_XCP_Master_0x601,
        0x601u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_15,
        FALSE,
        &Xcp_CanIfRxIndication,
        &CanIf_RxPduRef[15],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_BT_Master,
        0x765u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_16,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[16],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_ECAS_DV_BA_Req,
        0x6a1u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_17,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[17],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_VIU_Config,
        0x39au,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_18,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[18],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_VIU_ConfigTrig,
        0x80u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_19,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[19],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_ADS_ECAS,
        0x134u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_20,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[20],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_ADS_State,
        0x32au,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_21,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[21],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_VDC_CDCSet,
        0x3f0u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_22,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[22],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_VDC_VIU_BodyInfo,
        0x3b5u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_23,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[23],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_VDC_FMtTq,
        0x115u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        24u,
        CANIF_HOH0_HRH_24,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[24],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_VDC_RMtTq,
        0x113u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_25,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[25],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_VDC_PTSt,
        0x11bu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_26,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[26],
        0x0u,
        0x7ffu
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfTxPduRefType,CANIF_CONST_PBCFG) CanIf_TxPduRef[CANIF_TXPDU_NUMBER] =
{
    {
        CANTP_CanIf_PhyResp,
        FALSE,
        64u
    },
    {
        CANNM_TX_PDU_0,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_ECAS_EDC_RemoteDiag,
        FALSE,
        32u
    },
    {
        PDUR_DESTPDU_ECAS_RemoteDiag,
        FALSE,
        32u
    },
    {
        PDUR_DESTPDU_ECAS_State,
        FALSE,
        24u
    },
    {
        PDUR_DESTPDU_ECAS_EDC_Test,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_ECAS_EDC_State,
        FALSE,
        48u
    },
    {
        PDUR_DESTPDU_ECASToScr,
        FALSE,
        8u
    },
    {
        XCP_XCP_Slave_0x60f,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BT_Slave,
        FALSE,
        8u
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_TxPduConfigType,CANIF_CONST) CanIf_TxPduConfigData[CANIF_TXPDU_NUMBER] =
{
    {
        CANIF_TXPDU_CanIf_PhyResp,
        0x7abu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_0,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &CanTp_TxConfirmation,
        &CanIf_TxPduRef[0],
    },
    {
        CANIF_TXPDU_CANNM_TX_CANFD,
        0x40du,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &CanNm_TxConfirmation,
        &CanIf_TxPduRef[1],
    },
    {
        CANIF_TXPDU_ECAS_EDC_RemoteDiag,
        0x598u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[2],
    },
    {
        CANIF_TXPDU_ECAS_RemoteDiag,
        0x595u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[3],
    },
    {
        CANIF_TXPDU_ECAS_State,
        0x342u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_4,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[4],
    },
    {
        CANIF_TXPDU_ECAS_EDC_Test,
        0x603u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_5,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[5],
    },
    {
        CANIF_TXPDU_ECAS_EDC_State,
        0x11du,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[6],
    },
    {
        CANIF_TXPDU_ECASToScr,
        0xbu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_7,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[7],
    },
    {
        CANIF_TXPDU_XCP_Slave_0x60f,
        0x60fu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_8,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &Xcp_CanIfTxConfirmation,
        &CanIf_TxPduRef[8],
    },
    {
        CANIF_TXPDU_BT_Slave,
        0x76du,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_9,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[9],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_ConfigType,CANIF_CONST) CanIf_InitCfgSet =
{
    NULL_PTR,
    CanIf_CtrlCfgData,
    &CanIf_InitHohCfgData,
    CanIf_RxPduConfigData,
    CanIf_TxPduConfigData,
    NULL_PTR,
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
