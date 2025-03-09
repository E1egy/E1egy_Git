/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dcm_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-05-23 16:20:01>
 */
/*============================================================================*/

/******************************* references ************************************/
#include "Dcm_Types.h"
#include "Rte_Dcm.h"
#include "Dcm_Cfg.h"
#if (STD_ON == DCM_UDS_FUNC_ENABLED)
#include "UDS.h"
#endif
#if (STD_ON == DCM_OBD_FUNC_ENABLED)
#include "OBD.h"
#endif

uint8 Dcm_UDS_UDS0x31_37Flag = Unperform;
/*******************Com Control********************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DspComControlAllChannelType, DCM_CONST) Dcm_DspComControlAllChannelCfg[1] =
{
    {
        TRUE, /*DcmDspComControlAllChannelUsed*/
        1u, /*DcmDspComMChannelId*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspComControlType, DCM_CONST) Dcm_DspComControlCfg =
{
    1u, /*DcmDspComControlAllChannelNum*/
    &Dcm_DspComControlAllChannelCfg[0], /*DcmDspComControlAllChannel*/
    NULL_PTR, /*DcmDspComControlSetting*/
    0u, /*DcmDspComControlSpecificChannelNum*/
    NULL_PTR, /*DcmDspComControlSpecificChannel*/
    0u, /*DcmDspComControlSubNodeNum*/
    NULL_PTR /*DcmDspComControlSubNode*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************Common Authorization********************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_03_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_03_S1_SecRef[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_03_S1_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_02_S11_SecRef[1] = {9u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_02_S11_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_02_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_01_SesRef[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_010203_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_0203_S0111_SecRef[2] = {9u, 1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_0203_S0111_SesRef[2] = {2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspCommonAuthorizationType, DCM_CONST) Dcm_DspCommonAuthorizationCfg[7] =
{
    {
        0u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        NULL_PTR, /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_03_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        1u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        &DcmDspCommonAuthorization_03_S1_SecRef[0], /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_03_S1_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        1u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        &DcmDspCommonAuthorization_02_S11_SecRef[0], /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_02_S11_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        0u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        NULL_PTR, /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_02_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        0u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        NULL_PTR, /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_01_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        0u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        NULL_PTR, /*DcmDspCommonAuthorizationSecurityLevelRef*/
        3u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_010203_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        2u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        &DcmDspCommonAuthorization_0203_S0111_SecRef[0], /*DcmDspCommonAuthorizationSecurityLevelRef*/
        2u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_0203_S0111_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDataType, DCM_CONST) Dcm_DspDataCfg[65] =
{
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF187_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        128u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18A_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF197_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18C_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        328u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF190_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF190_WriteData, /*DcmDspDataWriteFnc*/
        136u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18B_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F0_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF184_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF184_WriteData, /*DcmDspDataWriteFnc*/
        152u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF189_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        192u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F1_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F3_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3900_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3901_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3902_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3903_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3905_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        72u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x390B_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x390C_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x390E_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x390F_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3910_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3911_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3912_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x391B_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x391C_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x391D_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x391E_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x391F_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3920_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3922_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3923_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3924_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3925_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3926_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3927_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x394A_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x394A_WriteData, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3907_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3940_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3960_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF013_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        128u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF031_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        128u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF089_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        192u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF032_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        192u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF180_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        256u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF186_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F2_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF025_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        128u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF091_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        4648u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3906_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x396D_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x396E_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x396E_WriteData, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x396F_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3970_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3971_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        24u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3972_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3973_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3974_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3975_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3976_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT16, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x390A_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x390A_WriteData, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_FreezeCurrentState,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ReadData, /*DcmDspDataReadFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ResetToDefault, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF090_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        192u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF160_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,     /*DcmDspDataConditionCheckReadFnc*/
        FALSE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_0xF162_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        280u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/********************Dsp Did******************************/
/******************************************
 *DcmDspDidRead container configration
 *****************************************/                                                                        
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_0_Read_SesRefCfg[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_0_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    2u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_0_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_1_Read_SecRefCfg[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_1_Read_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_1_ReadCfg =
{
    1u, /*DcmDspDidReadSecurityLevelRefNum*/
    &Dcm_DidInfo_1_Read_SecRefCfg[0], /*pDcmDspDidReadSecurityLevelRow*/
    1u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_1_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_2_Read_SesRefCfg[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_2_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    2u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_2_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_3_Read_SesRefCfg[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_3_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    3u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_3_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_4_Read_SesRefCfg[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_4_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    3u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_4_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_5_Read_SecRefCfg[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_5_Read_SesRefCfg[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_5_ReadCfg =
{
    1u, /*DcmDspDidReadSecurityLevelRefNum*/
    &Dcm_DidInfo_5_Read_SecRefCfg[0], /*pDcmDspDidReadSecurityLevelRow*/
    2u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_5_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************************************
 *DcmDspDidWrite container configuration,
 which is in the DcmDspDidInfo container
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_2_Write_SecRefCfg[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_2_Write_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_2_WriteCfg=
{
    1u,/*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_2_Write_SecRefCfg[0],    /*pDcmDspDidWriteSecurityLevelRow*/
    1u,    /*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_2_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_4_Write_SecRefCfg[1] = {9u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_4_Write_SesRefCfg[2] = {2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_4_WriteCfg=
{
    1u,/*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_4_Write_SecRefCfg[0],    /*pDcmDspDidWriteSecurityLevelRow*/
    2u,    /*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_4_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************************************
 *DcmDspDidControl container configuration,
 which is in the DcmDspDidInfo container
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(uint8,DCM_CONST)Dcm_DidInfo_1_Control_SecRefCfg[1]= {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(uint8,DCM_CONST)Dcm_DidInfo_1_Control_SesRefCfg[1]={3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidControlType,DCM_CONST) Dcm_DidInfo_1_ControlCfg =
{
    DCM_CONTROLMASK_NO, /*DcmDspDidControlMask*/
    0u, /*DcmDspDidControlMaskSize*/
    1u, /*DcmDspDidControlSecurityLevelRefNum*/
    &Dcm_DidInfo_1_Control_SecRefCfg[0], /*pDcmDspDidControlSecurityLevelRow*/
    1u, /*DcmDspDidControlSessionRefNum*/
    &Dcm_DidInfo_1_Control_SesRefCfg[0], /*pDcmDspDidControlSessionRow*/
    TRUE, /*DcmDspDidFreezeCurrentState*/
    TRUE, /*DcmDspDidResetToDefault*/
    TRUE, /*DcmDspDidShortTermAdjustement*/
    NULL_PTR, /*DcmDspDidControlEnableMask*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/******************************************
 *DcmDspDidInfo container Configuration ***
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidInfoType,DCM_CONST)Dcm_DspDidInfoCfg[6] =
{
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_0_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        &Dcm_DidInfo_1_ControlCfg, /*pDcmDspDidControl*/
        &Dcm_DidInfo_1_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_2_ReadCfg, /*pDcmDspDidRead*/
        &Dcm_DidInfo_2_WriteCfg, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_3_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_4_ReadCfg, /*pDcmDspDidRead*/
        &Dcm_DidInfo_4_WriteCfg, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_5_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR, /*pDcmDspDidWrite*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F187_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[0],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F18A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[1],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F197_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[2],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F18C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[3],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F190_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[4],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F18B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[5],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F0F0_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[6],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F184_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[7],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F189_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[8],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F0F1_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[9],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F0F3_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[10],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3900_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[11],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3901_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[12],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3902_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[13],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3903_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[14],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3905_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[15],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_390B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[16],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_390C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[17],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_390E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[18],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_390F_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[19],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3910_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[20],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3911_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[21],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3912_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[22],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_391B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[23],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F160_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[63],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F162_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[64],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_391C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[24],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_391D_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[25],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_391E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[26],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_391F_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[27],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3920_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[28],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3922_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[29],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3923_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[30],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3924_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[31],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3925_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[32],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3926_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[33],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3927_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[34],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_394A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[35],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3929_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[61],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3940_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[37],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3960_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[38],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F013_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[39],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F031_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[40],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F089_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[41],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F032_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[42],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F180_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[43],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F186_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[44],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F0F2_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[45],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3907_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[36],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F025_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[46],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F091_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[47],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3906_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[48],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_396D_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[49],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_396E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[50],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_396F_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[51],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3970_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[52],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3971_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[53],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3972_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[54],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3973_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[55],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3974_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[56],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3975_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[57],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3976_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[58],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3977_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[59],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_390A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[60],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F090_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[62],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************
 *DcmDspDid container configration*************
 **********************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidType,DCM_CONST)Dcm_DspDidCfg[65] =
{
    { /* Did_0xF187 */
        0xF187u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F187_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF18A */
        0xF18Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F18A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF197 */
        0xF197u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F197_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF18C */
        0xF18Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F18C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF190 */
        0xF190u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        2u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F190_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF18B */
        0xF18Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F18B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF0F0 */
        0xF0F0u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F0F0_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF184 */
        0xF184u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        4u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F184_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF189 */
        0xF189u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F189_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF0F1 */
        0xF0F1u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F0F1_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF0F3 */
        0xF0F3u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F0F3_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3900 */
        0x3900u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3900_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3901 */
        0x3901u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3901_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3902 */
        0x3902u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3902_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3903 */
        0x3903u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3903_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3905 */
        0x3905u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3905_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x390B */
        0x390Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_390B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x390C */
        0x390Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_390C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x390E */
        0x390Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_390E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x390F */
        0x390Fu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_390F_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3910 */
        0x3910u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3910_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3911 */
        0x3911u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3911_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3912 */
        0x3912u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3912_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x391B */
        0x391Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_391B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x391C */
        0x391Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_391C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x391D */
        0x391Du,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_391D_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x391E */
        0x391Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_391E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x391F */
        0x391Fu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_391F_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3920 */
        0x3920u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3920_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3922 */
        0x3922u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3922_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3923 */
        0x3923u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3923_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3924 */
        0x3924u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3924_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3925 */
        0x3925u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3925_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3926 */
        0x3926u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3926_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3927 */
        0x3927u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3927_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x394A */
        0x394Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        2u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_394A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3929 */
        0x3929u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3929_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3940 */
        0x3940u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3940_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3960 */
        0x3960u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3960_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF013 */
        0xF013u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F013_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF031 */
        0xF031u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F031_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF089 */
        0xF089u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F089_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF032 */
        0xF032u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F032_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF180 */
        0xF180u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F180_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF186 */
        0xF186u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F186_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF0F2 */
        0xF0F2u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F0F2_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3907 */
        0x3907u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3907_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF025 */
        0xF025u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F025_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF091 */
        0xF091u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F091_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3906 */
        0x3906u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3906_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x396D */
        0x396Du,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_396D_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x396E */
        0x396Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        2u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_396E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x396F */
        0x396Fu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_396F_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3970 */
        0x3970u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3970_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3971 */
        0x3971u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3971_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3972 */
        0x3972u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3972_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3973 */
        0x3973u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3973_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3974 */
        0x3974u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3974_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3975 */
        0x3975u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3975_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3976 */
        0x3976u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3976_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3977 */
        0x3977u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3977_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x390A */
        0x390Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        2u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_390A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF090 */
        0xF090u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F090_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF160 */
        0xF160u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F160_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF162 */
        0xF162u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F162_SignalCfg[0],     /*pDcmDspDidSignal*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Memory**************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspAddressAndLengthFormatIdentifierType,DCM_CONST)Dcm_DspAddressAndLengthFormatIdentifierCfg[1] =
{
    {
        68u     /*DcmDspSupportedAddressAndLengthFormatIdentifier*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspWriteMemoryRangeInfoType,DCM_CONST)Dcm_DspWriteMemoryRangeInfoCfg[2] =
{
    {
        0x7010ffffUL, /*DcmDspWriteMemoryRangeHigh*/
        0x7010f000UL, /*DcmDspWriteMemoryRangeLow*/
        0u, /*DcmDspWriteMemorySessionLevelRefNum*/
        NULL_PTR, /*pDcmDspWriteMemorySessionLevelRow*/
        0u, /*DcmDspWriteMemorySecurityLevelRefNum*/
        NULL_PTR, /*pDcmDspWriteMemorySecurityLevelRow*/
    },
    {
        0xa05fffffUL, /*DcmDspWriteMemoryRangeHigh*/
        0xa0300000UL, /*DcmDspWriteMemoryRangeLow*/
        0u, /*DcmDspWriteMemorySessionLevelRefNum*/
        NULL_PTR, /*pDcmDspWriteMemorySessionLevelRow*/
        0u, /*DcmDspWriteMemorySecurityLevelRefNum*/
        NULL_PTR, /*pDcmDspWriteMemorySecurityLevelRow*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspMemoryIdInfoType,DCM_CONST)Dcm_DspMemoryIdInfoCfg[2] =
{
    {
        0u, /*DcmDspMemoryIdValue*/
        0u,/*DcmDspReadMemoryRangeInfoNum*/
        NULL_PTR, /*DcmDspReadMemoryRangeInfo*/
        1u,/*DcmDspWriteMemoryRangeInfoNum*/
        &Dcm_DspWriteMemoryRangeInfoCfg[0], /*DcmDspWriteMemoryRangeInfo*/
    },
    {
        1u, /*DcmDspMemoryIdValue*/
        0u,/*DcmDspReadMemoryRangeInfoNum*/
        NULL_PTR, /*DcmDspReadMemoryRangeInfo*/
        1u,/*DcmDspWriteMemoryRangeInfoNum*/
        &Dcm_DspWriteMemoryRangeInfoCfg[1], /*DcmDspWriteMemoryRangeInfo*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspMemoryType,DCM_CONST)Dcm_DspMemoryCfg =
{
    1u, /*DcmDspAddressAndLengthFormatIdentifierNum*/
    &Dcm_DspAddressAndLengthFormatIdentifierCfg[0], /*DcmDspAddressAndLengthFormatIdentifier*/
    2u,/*DcmDspMemoryIdInfoNum*/
    &Dcm_DspMemoryIdInfoCfg[0], /*DcmDspMemoryIdInfo*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Routine**************/
/***********************************
 *DcmDspRequestRoutineResults container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD0F_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xFF01_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x203_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xFF00_SignalCfg[2] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        72u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD01_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD02_SignalCfg[2] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        3072u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD04_SignalCfg[2] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD03_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x392A_SignalCfg[2] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        32u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x392C_SignalCfg[3] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        96u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x392D_SignalCfg[4] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        24u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x392E_SignalCfg[4] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        40u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x392F_SignalCfg[4] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        40u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x3930_SignalCfg[4] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x3955_SignalCfg[2] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x3956_SignalCfg[2] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        24u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x395A_SignalCfg[3] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x395B_SignalCfg[3] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD30_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD31_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD32_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD35_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD36_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD37_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD38_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD39_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xDD3A_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x392B_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/***********************************
 *DcmDspRequestRoutineResults container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD04_RequestRoutineResultsOutCfg =
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0xDD04_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0xDD04_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD04_RequestResults, /*DcmDspRequestResultsRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0xDD04_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392A_RequestRoutineResultsOutCfg =
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x392A_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x392A_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392A_RequestResults, /*DcmDspRequestResultsRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x392A_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392C_RequestRoutineResultsOutCfg =
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x392C_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x392C_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392C_RequestResults, /*DcmDspRequestResultsRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x392C_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392D_RequestRoutineResultsOutCfg =
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x392D_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x392D_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392D_RequestResults, /*DcmDspRequestResultsRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x392D_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392E_RequestRoutineResultsOutCfg =
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x392E_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x392E_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392E_RequestResults, /*DcmDspRequestResultsRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x392E_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392F_RequestRoutineResultsOutCfg =
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x392F_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x392F_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392F_RequestResults, /*DcmDspRequestResultsRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x392F_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x3930_RequestRoutineResultsOutCfg =
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x3930_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x3930_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3930_RequestResults, /*DcmDspRequestResultsRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x3930_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x3956_RequestRoutineResultsOutCfg =
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x3956_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x3956_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3956_RequestResults, /*DcmDspRequestResultsRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x3956_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x395B_RequestRoutineResultsOutCfg =
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x395B_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x395B_ResultsCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395B_RequestResults, /*DcmDspRequestResultsRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x395B_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/***********************************
 *DcmDspRoutineStart container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD0F_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD0F_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD0F_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD0F_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[2], /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD0F_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xFF01_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xFF01_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xFF01_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xFF01_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[2], /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xFF01_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x203_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x203_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x203_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x0203_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[0], /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x203_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xFF00_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xFF00_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xFF00_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xFF00_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xFF00_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xFF00_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[2], /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0xFF00_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xFF00_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD01_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD01_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD01_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD01_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[4], /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD01_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD02_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD02_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD02_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD02_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD02_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD02_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[2], /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0xDD02_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD02_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD04_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD04_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD04_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD04_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD04_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD03_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD03_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD03_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD03_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[2], /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD03_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392A_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x392A_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x392A_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392A_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x392A_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392C_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x392C_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x392C_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392C_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x392C_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392D_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x392D_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392D_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x392D_SignalCfg[2],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x392D_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392D_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0x392D_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x392D_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392E_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x392E_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392E_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x392E_SignalCfg[2],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x392E_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392E_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0x392E_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x392E_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392F_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x392F_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392F_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x392F_SignalCfg[2],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x392F_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392F_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0x392F_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x392F_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x3930_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x3930_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x3930_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x3930_SignalCfg[2],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x3930_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3930_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0x3930_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x3930_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x3955_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x3955_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x3955_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x3955_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x3955_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3955_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0x3955_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x3955_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x3956_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x3956_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x3956_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3956_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x3956_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x395A_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x395A_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x395A_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x395A_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x395A_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395A_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0x395A_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x395A_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x395B_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x395B_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x395B_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395B_Start, /*DcmDspStartRoutineFnc*/
     &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x395B_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD30_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD30_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD30_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD30_Start, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD30_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD31_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD31_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD31_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD31_Start, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD31_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD32_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD32_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD32_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD32_Start, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD32_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD35_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD35_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD35_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD35_Start, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD35_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD36_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD36_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD36_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD36_Start, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD36_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD37_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD37_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD37_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD37_Start, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD37_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD38_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD38_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD38_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD38_Start, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD38_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD39_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD39_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD39_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD39_Start, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD39_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xDD3A_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xDD3A_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xDD3A_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD3A_Start, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xDD3A_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x392B_StartRoutineOutCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x392B_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x392B_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392B_Start, /*DcmDspStartRoutineFnc*/
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0x392B_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/***********************************
 *DcmDspRoutineStop container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0x392C_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0x392C_SignalCfg[2],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0x392C_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392C_Stop, /*DcmDspRoutineStopFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0x392C_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0x392D_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0x392D_SignalCfg[3],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0x392D_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392D_Stop, /*DcmDspRoutineStopFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0x392D_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0x392E_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0x392E_SignalCfg[3],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0x392E_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392E_Stop, /*DcmDspRoutineStopFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0x392E_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0x392F_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0x392F_SignalCfg[3],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0x392F_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392F_Stop, /*DcmDspRoutineStopFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0x392F_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0x3930_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0x3930_SignalCfg[3],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0x3930_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3930_Stop, /*DcmDspRoutineStopFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0x3930_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0x395A_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0x395A_SignalCfg[2],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0x395A_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395A_Stop, /*DcmDspRoutineStopFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0x395A_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)    Dcm_Routine_0x395B_StopRoutineOutCfg =
{
    1u,
    &Dcm_Routine_0x395B_SignalCfg[2],
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStopRoutineType,DCM_CONST)Dcm_RoutineInfo_0x395B_StopCfg =
{
    Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395B_Stop, /*DcmDspRoutineStopFnc*/
    &Dcm_DspCommonAuthorizationCfg[1], /*DcmDspStopRoutineCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspStopRoutineIn*/
    &Dcm_Routine_0x395B_StopRoutineOutCfg, /*DcmDspStopRoutineIn*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/***********************************
 *DcmDspRoutine container configration
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineType,DCM_CONST)Dcm_DspRoutineCfg[33] =
{
    { /* DcmDspRoutine_0xDD0F */
        0xDD0Fu, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[2],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD0F_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xFF01 */
        0xFF01u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[2],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xFF01_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x0203 */
        0x203u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x203_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xFF00 */
        0xFF00u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[2],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xFF00_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD01 */
        0xDD01u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[4],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD01_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD02 */
        0xDD02u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[2],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD02_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD04 */
        0xDD04u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0xDD04_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD04_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD03 */
        0xDD03u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[2],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD03_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x392A */
        0x392Au, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x392A_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x392A_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x392C */
        0x392Cu, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x392C_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x392C_StartCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0x392C_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x392D */
        0x392Du, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x392D_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x392D_StartCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0x392D_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x392E */
        0x392Eu, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x392E_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x392E_StartCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0x392E_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x392F */
        0x392Fu, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x392F_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x392F_StartCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0x392F_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x3930 */
        0x3930u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x3930_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x3930_StartCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0x3930_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x3955 */
        0x3955u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x3955_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x3956 */
        0x3956u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x3956_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x3956_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x395A */
        0x395Au, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x395A_StartCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0x395A_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x395B */
        0x395Bu, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x395B_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x395B_StartCfg, /*DcmDspRequestRoutineResults*/
        &Dcm_RoutineInfo_0x395B_StopCfg, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD30 */
        0xDD30u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD30_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD31 */
        0xDD31u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD31_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD32 */
        0xDD32u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD32_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD35 */
        0xDD35u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD35_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD36 */
        0xDD36u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD36_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD37 */
        0xDD37u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD37_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD38 */
        0xDD38u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD38_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD39 */
        0xDD39u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD39_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD3A */
        0xDD3Au, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xDD3A_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD40 */
        0xDD40u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        NULL_PTR,     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        NULL_PTR, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD41 */
        0xDD41u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        NULL_PTR,     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        NULL_PTR, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD42 */
        0xDD42u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        NULL_PTR,     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        NULL_PTR, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD43 */
        0xDD43u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        NULL_PTR,     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        NULL_PTR, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xDD44 */
        0xDD44u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        NULL_PTR,     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        NULL_PTR, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x392B */
        0x392Bu, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        TRUE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x392B_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/******************Dsp Security Row**************/
/************************************************
 ****DcmDspSecurityRow container(Multiplicity=0..31)****
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspSecurityRowType,DCM_CONST)Dcm_DspSecurityRow[2] =
{
    { /* DcmDspSecurityRow_0102 */
        1u,          /*DcmDspSecurityLevel*/
        16u,          /*DcmDspSecuritySeedSize*/
        16u,          /*DcmDspSecurityKeySize*/
        0u,          /*DcmDspSecurityADRSize*/
        TRUE,        /*DcmDspSecurityAttemptCounterEnabled*/
        2u,    /*DcmDspSecurityNumAttDelay*/
        10000u,  /*DcmDspSecurityDelayTime,10s */
        5000u,/*DcmDspSecurityDelayTimeOnBoot*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_GetSeed,    /*Dcm_GetSeedFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_CompareKey,    /*Dcm_CompareKeyFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_GetSecurityAttemptCounter,    /*Dcm_GetSecurityAttemptCounterFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_SetSecurityAttemptCounter,    /*DcmDspSecurityUsePort*/
        USE_ASYNCH_CLIENT_SERVER,    /*DcmDspSecurityUsePort*/
    },
    { /* DcmDspSecurityRow_1112 */
        9u,          /*DcmDspSecurityLevel*/
        16u,          /*DcmDspSecuritySeedSize*/
        16u,          /*DcmDspSecurityKeySize*/
        0u,          /*DcmDspSecurityADRSize*/
        TRUE,        /*DcmDspSecurityAttemptCounterEnabled*/
        2u,    /*DcmDspSecurityNumAttDelay*/
        10000u,  /*DcmDspSecurityDelayTime,10s */
        5000u,/*DcmDspSecurityDelayTimeOnBoot*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_GetSeed,    /*Dcm_GetSeedFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_CompareKey,    /*Dcm_CompareKeyFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_GetSecurityAttemptCounter,    /*Dcm_GetSecurityAttemptCounterFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_SetSecurityAttemptCounter,    /*DcmDspSecurityUsePort*/
        USE_ASYNCH_CLIENT_SERVER,    /*DcmDspSecurityUsePort*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/************************************************
 ****DcmDspSecurity container(Multiplicity=1)****
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspSecurityType,DCM_CONST)Dcm_DspSecurity =
{
    &Dcm_DspSecurityRow[0],    /*pDcm_DspSecurityRow*/
    2u,    /*DcmDspSecurityRow_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Session Row**************/
/************************************************
 ****DcmDspSessionRow container(Multiplicity=0..31)
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspSessionRowType,DCM_CONST)Dcm_DspSessionRow[3] =
{
    { /* DcmDspSessionRow_1 */
        DCM_NO_BOOT,    /*DcmDspSessionForBoot*/
        1u,    /*DcmDspSessionLevel*/
        50u,    /*DcmDspSessionP2ServerMax*/
        5000u,    /*DcmDspSessionP2StarServerMax*/
    },
    { /* DcmDspSessionRow_2 */
        DCM_NO_BOOT,    /*DcmDspSessionForBoot*/
        2u,    /*DcmDspSessionLevel*/
        50u,    /*DcmDspSessionP2ServerMax*/
        5000u,    /*DcmDspSessionP2StarServerMax*/
    },
    { /* DcmDspSessionRow_3 */
        DCM_NO_BOOT,    /*DcmDspSessionForBoot*/
        3u,    /*DcmDspSessionLevel*/
        50u,    /*DcmDspSessionP2ServerMax*/
        5000u,    /*DcmDspSessionP2StarServerMax*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/************************************************
 *******Dcm_DspSession container(Multiplicity=1)*
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspSessionType,DCM_CONST)Dcm_DspSession =
{
    &Dcm_DspSessionRow[0],    /*pDcmDspSessionRow*/
    3u,        /*DcmDspSessionRow_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 ****************DcmDsp container configration********
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DspCfgType,DCM_CONST) Dcm_DspCfg =
{
    NULL_PTR,    /*DcmDspDDDIDcheckPerSourceDID*/
    DCM_BIG_ENDIAN,    /*DcmDspDataDefaultEndianness*/
    FALSE,/*DcmDspEnableObdMirror*/
    5,/*DcmDspMaxDidToRead*/
    DCM_DSP_MAX_PERIODIC_DID_TO_READ,/*DcmDspMaxPeriodicDidToRead*/
    0u,/*DcmDspPowerDownTime*/
    AFTER_RESET,    /*DcmResponseToEcuReset*/
    NULL_PTR,        /*pDcmDspClearDTC*/
    &Dcm_DspComControlCfg,        /*pDcmDspComControl*/
    &Dcm_DspCommonAuthorizationCfg[0],        /*pDcmDspCommonAuthorization*/
    NULL_PTR,    /*pDcmDspControlDTCSetting*/
    &Dcm_DspDataCfg[0],    /*pDcmDspData*/    NULL_PTR,    /*pDcmDspDataInfo*/
    65u,    /*DcmDspDidNum*/
    &Dcm_DspDidCfg[0],        /*pDcmDspDid*/
    6u,    /*DcmDspDidInfoNum*/
    &Dcm_DspDidInfoCfg[0],        /*pDcmDspDidInfo*/
    0u,    /*DcmDspDidRangeNum*/
    NULL_PTR,        /*pDcmDspDidRange*/
    &Dcm_DspMemoryCfg, /*pDcmDspMemory*/

    NULL_PTR,    /*DcmDspRequestFileTransfer*/

    33u,        /*DcmDspRoutineNum*/
    &Dcm_DspRoutineCfg[0],    /*pDcmDspRoutine*/

    &Dcm_DspSecurity,  /* pDcm_DspSecurity */
    &Dcm_DspSession,  /* pDcm_DspSession */

    DCM_DSP_MAX_PERIODIC_DID_SCHEDULER,
    NULL_PTR,

};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************************************************
 ********************************* DSD container configration*****************************
 *****************************************************************************************/

/*DcmDsdService_0x10 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x10_1_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x10_2_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x10_3_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_UDS_DsdSubService_UDS0x10[3] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x10_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        3u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x10_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        3u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x3u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x10_3_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x11 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x11_1_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_UDS_DsdSubService_UDS0x11[1] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x11_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        3u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x19 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x19_1_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x19_2_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x19_4_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x19_6_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x19_A_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_UDS_DsdSubService_UDS0x19[5] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x19_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x19_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x4u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x19_4_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x6u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x19_6_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0xAu,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x19_A_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x31 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x31_1_SesRef[2] = {2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x31_2_SesRef[2] = {2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x31_3_SesRef[2] = {2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_UDS_DsdSubService_UDS0x31[3] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x31_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x31_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x3u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x31_3_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x27 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x27_1_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x27_2_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x27_11_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x27_12_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_UDS_DsdSubService_UDS0x27[4] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x27_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x27_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x11u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x27_11_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x12u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x27_12_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x28 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x28_0_SesRef[2] = {3u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x28_1_SesRef[2] = {3u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x28_3_SesRef[2] = {3u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_UDS_DsdSubService_UDS0x28[3] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x0u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x28_0_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x28_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x3u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x28_3_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x85 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x85_1_SesRef[2] = {3u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x85_2_SesRef[2] = {3u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_UDS_DsdSubService_UDS0x85[2] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x85_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x85_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_0x3E SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x3E_0_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_UDS_DsdSubService_UDS0x3E[1] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x0u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_UDS_UDS0x3E_0_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        3u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*UDS Service session and security configuration*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x10_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x11_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x14_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x19_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x22_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x2E_SecRef[2] = {1u, 9u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x2E_SesRef[2] = {2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x31_SesRef[3] = {2u, 3u, 1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x27_SesRef[2] = {2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x28_SesRef[2] = {3u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x85_SesRef[2] = {3u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x34_SecRef[1] = {9u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x34_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x36_SecRef[1] = {9u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x36_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x37_SecRef[1] = {9u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x37_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x3E_SesRef[3] = {1u, 2u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x2F_SecRef[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_UDS_UDS0x2F_SesRef[2] = {3u, 1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/*DcmDsdService UDS*/    
static  CONST(Dcm_DsdServiceCfgType,DCM_CONST)UDS_Service[15] =
{
    { /*DiagnosticSessionControl*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x10,    /*DcmDsdSidTabFnc*/
        0x10u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        3u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x10_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        3u,    /*DcmDsdSubService_Num*/
        &Dcm_UDS_DsdSubService_UDS0x10[0],    /*DcmDsdSubService*/
    },
    { /*ECUReset*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x11,    /*DcmDsdSidTabFnc*/
        0x11u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        3u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x11_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        1u,    /*DcmDsdSubService_Num*/
        &Dcm_UDS_DsdSubService_UDS0x11[0],    /*DcmDsdSubService*/
    },
    { /*ClearDiagnosticInformation*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x14,    /*DcmDsdSidTabFnc*/
        0x14u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        2u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x14_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*ReadDTCInformation*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x19,    /*DcmDsdSidTabFnc*/
        0x19u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        2u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x19_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        5u,    /*DcmDsdSubService_Num*/
        &Dcm_UDS_DsdSubService_UDS0x19[0],    /*DcmDsdSubService*/
    },
    { /*ReadDataByIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x22,    /*DcmDsdSidTabFnc*/
        0x22u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        3u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x22_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*WriteDataByIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x2E,    /*DcmDsdSidTabFnc*/
        0x2Eu,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        2u, /*DcmDsdSecurityLevel_Num*/
        &Dcm_UDS_UDS0x2E_SecRef[0],    /*pDcmDsdSecurityLevelRef*/
        2u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x2E_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*RoutineControl*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x31,    /*DcmDsdSidTabFnc*/
        0x31u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        3u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x31_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        3u,    /*DcmDsdSubService_Num*/
        &Dcm_UDS_DsdSubService_UDS0x31[0],    /*DcmDsdSubService*/
    },
    { /*SecurityAccess*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x27,    /*DcmDsdSidTabFnc*/
        0x27u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        2u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x27_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        4u,    /*DcmDsdSubService_Num*/
        &Dcm_UDS_DsdSubService_UDS0x27[0],    /*DcmDsdSubService*/
    },
    { /*CommunicationControl*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x28,    /*DcmDsdSidTabFnc*/
        0x28u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        2u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x28_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        3u,    /*DcmDsdSubService_Num*/
        &Dcm_UDS_DsdSubService_UDS0x28[0],    /*DcmDsdSubService*/
    },
    { /*ControlDTCSetting*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x85,    /*DcmDsdSidTabFnc*/
        0x85u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        2u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x85_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        2u,    /*DcmDsdSubService_Num*/
        &Dcm_UDS_DsdSubService_UDS0x85[0],    /*DcmDsdSubService*/
    },
    { /*RequestDownload*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x34,    /*DcmDsdSidTabFnc*/
        0x34u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        1u, /*DcmDsdSecurityLevel_Num*/
        &Dcm_UDS_UDS0x34_SecRef[0],    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x34_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*TransferData*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x36,    /*DcmDsdSidTabFnc*/
        0x36u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        1u, /*DcmDsdSecurityLevel_Num*/
        &Dcm_UDS_UDS0x36_SecRef[0],    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x36_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*RequestTransferExit*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x37,    /*DcmDsdSidTabFnc*/
        0x37u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        1u, /*DcmDsdSecurityLevel_Num*/
        &Dcm_UDS_UDS0x37_SecRef[0],    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x37_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*TesterPresent*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x3E,    /*DcmDsdSidTabFnc*/
        0x3Eu,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        3u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x3E_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        1u,    /*DcmDsdSubService_Num*/
        &Dcm_UDS_DsdSubService_UDS0x3E[0],    /*DcmDsdSubService*/
    },
    { /*InputOutputControlByIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x2F,    /*DcmDsdSidTabFnc*/
        0x2Fu,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        1u, /*DcmDsdSecurityLevel_Num*/
        &Dcm_UDS_UDS0x2F_SecRef[0],    /*pDcmDsdSecurityLevelRef*/
        2u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_UDS_UDS0x2F_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************/
/*DCM Support Service Table(Multiplicity=1..256)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdServiceTableCfgType,DCM_CONST)Dcm_DsdServiceTable[DCM_SERVICE_TAB_NUM]=
{
    {
        0x0u,    /*DcmDsdSidTabId*/
        &UDS_Service[0],    /*pDcmDsdService*/
        15u    /*DcmDsdSidTab_ServiceNum*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/*DcmDsdServiceRequestSupplierNotification(Multiplicity=1..*)*/
static  CONST(Dcm_DsdServiceReqSuppNotiType,DCM_CONST) Dcm_DsdServiceReqSuppNoti[1] =
{
    {
        Rte_Call_Dcm_ServiceRequestSupplierNotification_DcmDsdServiceRequestSupplierNotification_0_Indication,        /*Indication*/
        Rte_Call_Dcm_ServiceRequestSupplierNotification_DcmDsdServiceRequestSupplierNotification_0_Confirmation,    /*Confirmation*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************/
/*Dsd container(Multiplicity=1)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DsdCfgType,DCM_CONST)Dcm_DsdCfg =
{
        /*DcmDsdServiceReqManufacturerNoti_PortNum*/
    &Dcm_DsdServiceReqSuppNoti[0],    /*pDcmDsdServiceReqSupplierNoti*/
    1u,    /*DcmDsdServiceReqSupplierNoti_PortNum*/
    &Dcm_DsdServiceTable[0],    /*pDcmDsdServiceTable*/
    DCM_SERVICE_TAB_NUM        /*DcmDsdServiceTable_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************************************************
 ********************************* DSL container configration*****************************
 *****************************************************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/*DcmDslBuffer container(Multiplicity=1..256)*/
static  CONST(Dcm_DslBufferType,DCM_CONST)Dcm_DslBufferCfg[DCM_CHANNEL_NUM] =
{
    {/* DcmDslBuffer_Rx*/
        0x0u,    /*Dcm_DslBufferId*/
        8194u,    /*Dcm_DslBufferSize*/
        0u    /*offset*/
    },
    {/* DcmDslBuffer_Tx*/
        0x1u,    /*Dcm_DslBufferId*/
        8194u,    /*Dcm_DslBufferSize*/
        8194u    /*offset*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/***********************************/
/*DcmDslDiagResp container(Multiplicity=1)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DslDiagRespType,DCM_CONST)Dcm_DslDiagRespCfg =
{
    TRUE,        /*DcmDslDiagRespOnSecondDeclinedRequest*/
    255u        /*DcmDslDiagRespMaxNumRespPend*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 *DcmDslCallbackDCMRequestService port configuration(Multiplicity=1..*)
 *****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DslCallbackDCMRequestServiceType,DCM_CONST)Dcm_DslCallbackDCMRequestServiceCfg[1] =
{
    {
        NULL_PTR,
        NULL_PTR
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/********************UDS protocol Connection configuration*******************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslProtocolRxType,DCM_CONST)Dsl_Protocol_Connection_RxCfg[DCM_DSL_RX_ID_NUM]=
{
    {
        0x0u,              /*DcmDslParentConnectionCtrlId*/
        DCM_PHYSICAL,    /*DcmDslProtocolRxAddrType*/
        DCM_Dcm_PhyReq,       /*DcmDslProtocolRxPduId*/

    },
    {
        0x0u,              /*DcmDslParentConnectionCtrlId*/
        DCM_FUNCTIONAL,    /*DcmDslProtocolRxAddrType*/
        DCM_Dcm_FunReq,       /*DcmDslProtocolRxPduId*/

    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslProtocolTxType,DCM_CONST)Dsl_Protocol_Connection_TxCfg[DCM_DSL_TX_ID_NUM]=
{
    {
        0x0u,            /*parent connection id*/
        DCM_Dcm_PhyResp,       /*DcmDslProtocolTxPduId*/
        DCM_PDUR_Dcm_PhyResp,   /*DcmDslProtocolTx Pdu Id of PduR*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Connection1,Mainconnection,ProtocolTx configration(Multiplicity=1..*)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslMainConnectionType,DCM_CONST) Dsl_Protocol_MainConnectionCfg[DCM_MAINCONNECTION_NUM] =
{
    {
        0x00000000u,                            /*DcmDslProtocolRxTesterSourceAddr*/
        NULL_PTR,  /*pDcmDslPeriodicTranmissionConRef*/
        1u,                                     /*DcmDslProtocolComMChannelId*/
        NULL_PTR,  /*pDcmDslROEConnectionRef*/
        &Dsl_Protocol_Connection_RxCfg[0],    /*pDcmDslProtocolRx*/
        2u,                                   /*DcmDslProtocolRx_Num*/
        &Dsl_Protocol_Connection_TxCfg[0],  /*pDcmDslProtocolTx*/
        1u                                    /*DcmDslProtocolTx_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Connection1 configration*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslConnectionType,DCM_CONST)Dsl_Protocol_ConnectionCfg[DCM_CONNECTION_NUM]=
{
    {
        0x0u,                                /*parent protocolRow id*/
        &Dsl_Protocol_MainConnectionCfg[0],    /*pDcmDslMainConnection*/
        NULL_PTR,                             /*pDcmDslPeriodicTransmission*/
        NULL_PTR                              /*pDcmDslResponseOnEvent*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*****************************************************
 ****Dcm_DslProtocolRow container configration(Multiplicity=1..*)*******
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslProtocolRowType,DCM_CONST)Dsl_ProtocolRowCfg[DCM_DSLPROTOCOLROW_NUM_MAX] =
{
    {
        DCM_UDS_ON_CAN,        /*DcmDslProtocolID*/
        0u,                    /*DcmDslProtocolPreemptTimes*/
        0u,                    /*DcmDslProtocolPriority*/
        TRUE,                /*true-protocol is available*/
        DCM_PROTOCAL_TRAN_NOT_VALID,
        FALSE,                /*True-send 0x78 before transitioning to the bootloader */
        50u,                     /*DcmTimStrP2ServerAdjust*/
        5000u,                /*DcmTimStrP2StarServerAdjust*/
        &Dcm_DslBufferCfg[0],/*DcmDslProtocolRxBuffer*/
        &Dcm_DslBufferCfg[1],/*DcmDslProtocolTxBuffer*/
        0u,                 /*DcmDslServiceTableId*/
        &Dsl_Protocol_ConnectionCfg[0] /*DcmDslConnection*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 *DcmDslProtocol container configration(Multiplicity=1)
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslProtocolType,DCM_CONST)Dcm_DslProtocol =
{
    &Dsl_ProtocolRowCfg[0],    /*pDcmDslProtocolRow*/
    DCM_DSLPROTOCOLROW_NUM_MAX,    /*DcmDslProtocolRow_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 ****************DcmDsl container configration*****
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslCfgType,DCM_CONST)Dcm_DslCfg =
{
    DCM_CHANNEL_NUM,        /*Number of Channel configration*/
    &Dcm_DslBufferCfg[0],    /*DcmDslBuffer*/
    0u,                        /*Number of DslCallbackDCMRequestService port*/
    &Dcm_DslCallbackDCMRequestServiceCfg[0],    /*pDcmDslCallback_DCMRequestService*/
    &Dcm_DslDiagRespCfg,       /*reference to DcmDslDiagResp configration*/
    &Dcm_DslProtocol,        /*reference to DcmDslProtocol configration*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_CfgType,DCM_CONST)Dcm_Cfg =
{
    &Dcm_DslCfg,    /*pDcmDslCfg*/
    &Dcm_DsdCfg,    /*pDcmDsdCfg*/
    &Dcm_DspCfg,    /*pDcmDspCfg*/
    NULL_PTR,        /*pDcmPageBufferCfg*/
    NULL_PTR,        /*pDcmProcessingConditionsCfg*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************
 ***********************DcmGeneral Container***************************
 **********************************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_GeneralCfgType,DCM_CONST)Dcm_GeneralCfg =
{
    TRUE, /*DcmDDDIDStorage*/
    DCM_DEV_ERROR_DETECT, /*DcmDevErrorDetect*/
    NULL_PTR, /*DcmHeaderFileInclusion*/
    DCM_RESPOND_ALL_REQUEST, /*DcmRespondAllRequest*/
    DCM_VERSION_INFO_API, /*DcmVersionInfoApi*/
    10, /*DcmTaskTime*/
    NULL_PTR, /*DcmVinRef*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
