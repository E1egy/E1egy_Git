/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dem_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-05-12 13:46:38>
 */
/*============================================================================*/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Cfg.h"
#include "Dem_CfgTypes.h"
#include "Dem_Internal.h"
#if (DEM_NVRAM_BLOCKID_NUM > 0)
#include "NvM_Cfg.h"
#endif

/*******************************************************************************
*                          General Configuration
*******************************************************************************/

/*******************************************************************************
*                          DemDataElementClass Configuration
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType DemReadOccctr(uint8* Buffer)
{
    *Buffer = DemInternalData.Occctr;
    return E_OK;
};
Std_ReturnType DemReadAgingUpCnt(uint8* Buffer)
{
    *Buffer = DemInternalData.AgingUpCnt;
    return E_OK;
};
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(DemDataElementClassTypes,AUTOMATIC) DemDataElementClass[DEM_DATA_ELEMENT_CLASS_NUM] =
{
    {
        3u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_395C_ReadData,/*DemDataElementClass*/
    },
    {
        2u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_395D_ReadData,/*DemDataElementClass*/
    },
    {
        3u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_395E_ReadData,/*DemDataElementClass*/
    },
    {
        8u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_395F_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3961_ReadData,/*DemDataElementClass*/
    },
    {
        8u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3962_ReadData,/*DemDataElementClass*/
    },
    {
        8u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3963_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3964_ReadData,/*DemDataElementClass*/
    },
    {
        8u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3965_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3966_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3967_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3968_ReadData,/*DemDataElementClass*/
    },
    {
        2u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3969_ReadData,/*DemDataElementClass*/
    },
    {
        3u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_396A_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_396B_ReadData,/*DemDataElementClass*/
    },
    {
        8u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_396C_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3908_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3909_ReadData,/*DemDataElementClass*/
    },
    {
        4u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_390D_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3913_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3914_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3915_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3918_ReadData,/*DemDataElementClass*/
    },
    {
        6u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_3919_ReadData,/*DemDataElementClass*/
    },
    {
        6u,/*DemDataElementDataSize*/
        Rte_Call_Dem_CS_DataServices_DemDataElementClass_391A_ReadData,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        DemReadOccctr,/*DemDataElementClass*/
    },
    {
        1u,/*DemDataElementDataSize*/
        DemReadAgingUpCnt,/*DemDataElementClass*/
    },
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          Condition Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemOperationCycle */
CONST(Dem_OperationCycleType,AUTOMATIC) DemOperationCycle[DEM_OPERATION_CYCLE_NUM] =
{
    { /* ECU_Wakeup */
        FALSE,
        TRUE,
        DEM_OPCYC_IGNITION
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemEnableCondition */
CONST(uint8,AUTOMATIC) DemEnableCondition[DEM_ENABLE_CONDITION_NUM_BYTE] =
{
    0x0u,
    0x0u,

};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemEnableConditionGroup */
CONST(uint8,AUTOMATIC) DemEnableConditionGroup[DEM_ENABLE_CONDITION_GROUP_NUM][DEM_ENABLE_CONDITION_NUM_BYTE] =
{
    {0x47u,0x0u,},
    {0xc3u,0x0u,},
    {0xc1u,0x0u,},
    {0xc9u,0x0u,},
    {0xd1u,0x0u,},
    {0xe1u,0x0u,},
    {0xc3u,0x1u,},
    {0xc3u,0x2u,},
    {0xc3u,0x4u,},
    {0xc3u,0x8u,},
    {0xc3u,0x10u,},
    {0xc1u,0x20u,}
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          FreezeFrame Configuration
*******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDidClass */
CONST(Dem_DidClassType,AUTOMATIC) DemDidClass[DEM_DID_CLASS_NUM] =
{
    { /* DemDidClass_395C */
        0x395cu,
        0u,
        1u,
        3u,
    },
    { /* DemDidClass_395D */
        0x395du,
        1u,
        1u,
        2u,
    },
    { /* DemDidClass_395E */
        0x395eu,
        2u,
        1u,
        3u,
    },
    { /* DemDidClass_395F */
        0x395fu,
        3u,
        1u,
        8u,
    },
    { /* DemDidClass_3961 */
        0x3961u,
        4u,
        1u,
        1u,
    },
    { /* DemDidClass_3962 */
        0x3962u,
        5u,
        1u,
        8u,
    },
    { /* DemDidClass_3963 */
        0x3963u,
        6u,
        1u,
        8u,
    },
    { /* DemDidClass_3964 */
        0x3964u,
        7u,
        1u,
        1u,
    },
    { /* DemDidClass_3965 */
        0x3965u,
        8u,
        1u,
        8u,
    },
    { /* DemDidClass_3966 */
        0x3966u,
        9u,
        1u,
        1u,
    },
    { /* DemDidClass_3967 */
        0x3967u,
        10u,
        1u,
        1u,
    },
    { /* DemDidClass_3968 */
        0x3968u,
        11u,
        1u,
        1u,
    },
    { /* DemDidClass_3969 */
        0x3969u,
        12u,
        1u,
        2u,
    },
    { /* DemDidClass_396A */
        0x396au,
        13u,
        1u,
        3u,
    },
    { /* DemDidClass_396B */
        0x396bu,
        14u,
        1u,
        1u,
    },
    { /* DemDidClass_396C */
        0x396cu,
        15u,
        1u,
        8u,
    },
    { /* DemDidClass_3908 */
        0x3908u,
        16u,
        1u,
        1u,
    },
    { /* DemDidClass_3909 */
        0x3909u,
        17u,
        1u,
        1u,
    },
    { /* DemDidClass_390D */
        0x390du,
        18u,
        1u,
        4u,
    },
    { /* DemDidClass_3913 */
        0x3913u,
        19u,
        1u,
        1u,
    },
    { /* DemDidClass_3914 */
        0x3914u,
        20u,
        1u,
        1u,
    },
    { /* DemDidClass_3915 */
        0x3915u,
        21u,
        1u,
        1u,
    },
    { /* DemDidClass_3918 */
        0x3918u,
        22u,
        1u,
        1u,
    },
    { /* DemDidClass_3919 */
        0x3919u,
        23u,
        1u,
        6u,
    },
    { /* DemDidClass_391A */
        0x391au,
        24u,
        1u,
        6u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint16,AUTOMATIC) DemDidClassRef[DEM_DID_CLASS_REF_TOTAL_NUM] =
{
    /* DemFreezeFrameClass_08671415 */
    0x10u,
    0xau,
    0x14u,
    0x15u,
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x8u,
    0x9u,
    /* DemFreezeFrameClass_6B186C */
    0xeu,
    0x16u,
    0xfu,
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x8u,
    0x9u,
    /* DemFreezeFrameClass_696A0D13 */
    0xcu,
    0xdu,
    0x12u,
    0x13u,
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x8u,
    0x9u,
    /* DemFreezeFrameClass_0D130968 */
    0x12u,
    0x13u,
    0x11u,
    0xbu,
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x8u,
    0x9u,
    /* DemFreezeFrameClass_191A */
    0x17u,
    0x18u,
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x8u,
    0x9u,
    /* DemFreezeFrameClass_63 */
    0x6u,
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x8u,
    0x9u,
    /* DemFreezeFrameClass_6462 */
    0x7u,
    0x5u,
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x8u,
    0x9u,
    /* DemFreezeFrameClass_0D09681314 */
    0x12u,
    0x11u,
    0xbu,
    0x13u,
    0x14u,
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x8u,
    0x9u,
    /* DemFreezeFrameClass_640D0968 */
    0x7u,
    0x12u,
    0x11u,
    0xbu,
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x8u,
    0x9u,
    /* DemFreezeFrameClass_5C5D5E5F616566 */
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x8u,
    0x9u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_FreezeFrameClassType,AUTOMATIC) DemFreezeFrameClass[DEM_FREEZE_FRAME_CLASS_NUM] =
{
    { /* DemFreezeFrameClass_08671415 DID*/
        30u,
        0u,
        11u
    },
    { /* DemFreezeFrameClass_6B186C DID*/
        36u,
        11u,
        10u
    },
    { /* DemFreezeFrameClass_696A0D13 DID*/
        36u,
        21u,
        11u
    },
    { /* DemFreezeFrameClass_0D130968 DID*/
        33u,
        32u,
        11u
    },
    { /* DemFreezeFrameClass_191A DID*/
        38u,
        43u,
        9u
    },
    { /* DemFreezeFrameClass_63 DID*/
        34u,
        52u,
        8u
    },
    { /* DemFreezeFrameClass_6462 DID*/
        35u,
        60u,
        9u
    },
    { /* DemFreezeFrameClass_0D09681314 DID*/
        34u,
        69u,
        12u
    },
    { /* DemFreezeFrameClass_640D0968 DID*/
        33u,
        81u,
        11u
    },
    { /* DemFreezeFrameClass_5C5D5E5F616566 DID*/
        26u,
        92u,
        7u
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGeneral/DemFreezeFrameRecordClass */
CONST(Dem_FreezeFrameRecordClassType,AUTOMATIC) DemFreezeFrameRecordClass[DEM_FREEZE_FRAME_RECORD_CLASS_NUM] =
{
    { /* DemFreezeFrameRecordClass_1 */
        1u,                       /* DemFreezeFrameRecordNumber */
        DEM_TRIGGER_ON_TEST_FAILED,   /* DemFreezeFrameRecordTrigger */
        DEM_UPDATE_RECORD_NO       /* DemFreezeFrameRecordUpdate */
    },
    { /* DemFreezeFrameRecordClass_2 */
        2u,                       /* DemFreezeFrameRecordNumber */
        DEM_TRIGGER_ON_TEST_FAILED,   /* DemFreezeFrameRecordTrigger */
        DEM_UPDATE_RECORD_YES       /* DemFreezeFrameRecordUpdate */
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint8,AUTOMATIC) DemFreezeFrameRecordClassRef[DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM] =
{
    /* DemFreezeFrameRecNumClass_0 */
    0x0u,
    0x1u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_FreezeFrameRecNumClassType,AUTOMATIC) DemFreezeFrameRecNumClass[DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM] =
{
    { /* DemFreezeFrameRecNumClass_0 */
        0u,
        2u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          ExtendedData Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemExtendedDataRecordClass */
CONST(Dem_ExtendedDataRecordClassType,AUTOMATIC) DemExtendedDataRecordClass[DEM_EXTENDED_DATA_RECORD_CLASS_NUM] =
{
    { /* DemExtendedDataRecordClass_1 */
        0x1u,
        DEM_TRIGGER_ON_TEST_FAILED,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        25u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    },
    { /* DemExtendedDataRecordClass_2 */
        0x2u,
        DEM_TRIGGER_ON_TEST_FAILED,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        26u,/*DemDataElementClassIndex*/
        1u,/*DemDataElementClassNum*/
        1u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint8,AUTOMATIC) DemExtendedDataRecordClassRef[DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM] =
{
    /* DemExtendedDataClass_0 */
    0x0u,
    0x1u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/* DemGeneral/DemExtendedDataClass */
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_ExtendedDataClassType,AUTOMATIC) DemExtendedDataClass[DEM_EXTENDED_DATA_CLASS_NUM] =
{
    { /* DemExtendedDataClass_0 */
        0u,
        2u
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/*******************************************************************************
*                          DTC Configuration
*******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTC 0-65535 */
CONST(Dem_DTCType,AUTOMATIC) DemDTC[DEM_DTC_NUM] =
{
    { /* DemDTC_0x620016 */
        0x620016u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620017 */
        0x620017u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620104 */
        0x620104u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620212 */
        0x620212u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620214 */
        0x620214u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620213 */
        0x620213u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620312 */
        0x620312u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620314 */
        0x620314u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620313 */
        0x620313u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620412 */
        0x620412u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620414 */
        0x620414u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620413 */
        0x620413u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620785 */
        0x620785u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620784 */
        0x620784u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620885 */
        0x620885u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620884 */
        0x620884u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620A86 */
        0x620a86u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620B4B */
        0x620b4bu, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620C13 */
        0x620c13u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620C12 */
        0x620c12u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620C11 */
        0x620c11u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620D13 */
        0x620d13u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620D12 */
        0x620d12u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620D11 */
        0x620d11u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620E13 */
        0x620e13u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620E12 */
        0x620e12u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620E11 */
        0x620e11u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620F13 */
        0x620f13u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620F12 */
        0x620f12u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620F11 */
        0x620f11u, /* DemDtcValue */
        1u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x62107C */
        0x62107cu, /* DemDtcValue */
        2u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621101 */
        0x621101u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621114 */
        0x621114u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621112 */
        0x621112u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621211 */
        0x621211u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621212 */
        0x621212u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621313 */
        0x621313u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621312 */
        0x621312u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621311 */
        0x621311u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621413 */
        0x621413u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621412 */
        0x621412u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621411 */
        0x621411u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621513 */
        0x621513u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621512 */
        0x621512u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621511 */
        0x621511u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621613 */
        0x621613u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621612 */
        0x621612u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621611 */
        0x621611u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621713 */
        0x621713u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621712 */
        0x621712u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621711 */
        0x621711u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621813 */
        0x621813u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621812 */
        0x621812u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621811 */
        0x621811u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x62197C */
        0x62197cu, /* DemDtcValue */
        2u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621A29 */
        0x621a29u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621B29 */
        0x621b29u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622454 */
        0x622454u, /* DemDtcValue */
        6u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x62291E */
        0x62291eu, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622916 */
        0x622916u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622917 */
        0x622917u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622A1E */
        0x622a1eu, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622A16 */
        0x622a16u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622A17 */
        0x622a17u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622B1E */
        0x622b1eu, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622B16 */
        0x622b16u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622B17 */
        0x622b17u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622C1E */
        0x622c1eu, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622C16 */
        0x622c16u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622C17 */
        0x622c17u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x625C63 */
        0x625c63u, /* DemDtcValue */
        7u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x625D63 */
        0x625d63u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x625E63 */
        0x625e63u, /* DemDtcValue */
        8u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x625F63 */
        0x625f63u, /* DemDtcValue */
        3u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC15187 */
        0xc15187u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC12887 */
        0xc12887u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC13187 */
        0xc13187u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC12987 */
        0xc12987u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC15C87 */
        0xc15c87u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC19887 */
        0xc19887u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC14787 */
        0xc14787u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC07988 */
        0xc07988u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621186 */
        0x621186u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621286 */
        0x621286u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622344 */
        0x622344u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x626044 */
        0x626044u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x626128 */
        0x626128u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x626129 */
        0x626129u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621F29 */
        0x621f29u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621E29 */
        0x621e29u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621D29 */
        0x621d29u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621C29 */
        0x621c29u, /* DemDtcValue */
        4u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621F07 */
        0x621f07u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621E07 */
        0x621e07u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x621D07 */
        0x621d07u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622147 */
        0x622147u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622029 */
        0x622029u, /* DemDtcValue */
        5u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622007 */
        0x622007u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC26C87 */
        0xc26c87u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x626283 */
        0x622200u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x626383 */
        0x626383u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x626483 */
        0x626483u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x626583 */
        0x626583u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x626683 */
        0x626683u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD30055 */
        0xd30055u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620952 */
        0x620952u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622912 */
        0x622912u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622A12 */
        0x622a12u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622B12 */
        0x622b12u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x622C12 */
        0x622c12u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC41881 */
        0xc41881u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC45281 */
        0xc45281u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC57E81 */
        0xc57e81u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC44381 */
        0xc44381u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC41781 */
        0xc41781u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x620698 */
        0x620698u, /* DemDtcValue */
        9u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTCAttributes */
CONST(Dem_DTCAttributesType,AUTOMATIC) DemDTCAttributes[DEM_DTC_ATTRIBUTES_NUM] =
{
    { /* DemDTCAttributes_08671415 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        40u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_6B186C */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        40u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        1u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_696A0D13 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        40u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        2u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_0D130968 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        40u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        3u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_191A */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        40u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        4u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_63 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        40u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        5u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_6462 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        40u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        6u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_0D09681314 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        40u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        7u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_640D0968 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        40u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        8u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    },
    { /* DemDTCAttributes_5C5D5E5F616566 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        40u, /* DemAgingCycleCounterThresholdForTFSLC */
        1u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        FALSE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        9u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          Indicator Configuration
*******************************************************************************/
/*******************************************************************************
*                          Debounce Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_DebounceCounterBasedClassType,AUTOMATIC) DemDebounceCounterBasedClass[DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM] =
{
    { /* DemDebounceCounterBasedClass_5t_0 */
        128u, /* DemDebounceCounterDecrementStepSize */
        26u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        FALSE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounterBasedClass_10t_0 */
        128u, /* DemDebounceCounterDecrementStepSize */
        13u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        FALSE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounterBasedClass_5t_5t */
        26u, /* DemDebounceCounterDecrementStepSize */
        26u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounterBasedClass_10t_10t */
        13u, /* DemDebounceCounterDecrementStepSize */
        13u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceCounterBasedClass_5t_3t */
        43u, /* DemDebounceCounterDecrementStepSize */
        26u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        127, /* DemDebounceCounterFailedThreshold */
        -128, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemConfigSet/DemDebounceTimeBaseClass 0-65535 */
CONST(Dem_DebounceTimeBaseClassType,AUTOMATIC) DemDebounceTimeBaseClass[DEM_DEBOUNCE_TIME_BASE_CLASS_NUM] =
{
    { /* DemDebounceTimeBaseClass_400ms_100ms */
        400UL, /* DemDebounceTimeFailedThreshold */
        100UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_20ms_20ms */
        20UL, /* DemDebounceTimeFailedThreshold */
        20UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_3000ms_3000ms */
        3000UL, /* DemDebounceTimeFailedThreshold */
        3000UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_2000ms_2000ms */
        2000UL, /* DemDebounceTimeFailedThreshold */
        2000UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_60s_0 */
        60000UL, /* DemDebounceTimeFailedThreshold */
        1UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_200ms_200ms */
        200UL, /* DemDebounceTimeFailedThreshold */
        200UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_100ms_100ms */
        100UL, /* DemDebounceTimeFailedThreshold */
        100UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_1000ms_1000ms */
        1000UL, /* DemDebounceTimeFailedThreshold */
        1000UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_5000ms_5000ms */
        5000UL, /* DemDebounceTimeFailedThreshold */
        5000UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_1000ms_0 */
        1000UL, /* DemDebounceTimeFailedThreshold */
        1UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_50ms_30ms */
        50UL, /* DemDebounceTimeFailedThreshold */
        30UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_500ms_300ms */
        500UL, /* DemDebounceTimeFailedThreshold */
        300UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    },
    { /* DemDebounceTimeBaseClass_100ms_60ms */
        100UL, /* DemDebounceTimeFailedThreshold */
        60UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/*******************************************************************************
*                          Event Configuration
*******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_EventParameterType,AUTOMATIC) DemEventParameter[DEM_EVENT_PARAMETER_NUM] =
{
    {  /* DemEventParameter_0x620016*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        0u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620017*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        1u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        1u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620104*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        2u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620212*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        3u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        2u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620214*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        4u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        3u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620213*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        5u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        4u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620312*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        6u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        5u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620314*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        7u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        6u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620313*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        8u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        7u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620412*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        9u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        8u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620414*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        10u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        9u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620413*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        11u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        10u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620785*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        12u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620784*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        13u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        1u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620885*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        14u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        2u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620884*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        15u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        3u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620A86*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        16u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        4u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620B4B*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        17u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        11u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620C13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        18u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        12u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620C12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        19u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        13u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620C11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        20u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        14u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620D13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        21u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        15u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620D12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        22u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        16u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620D11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        23u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        17u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620E13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        24u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        18u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620E12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        25u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        19u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620E11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        26u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        20u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620F13*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        27u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        21u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620F12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        28u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        22u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620F11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        29u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        23u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x62107C*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        30u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        3u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621101*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        31u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        24u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621114*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        32u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        25u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621112*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        33u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        26u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621211*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        34u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        27u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621212*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        35u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        28u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621313*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        36u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        29u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621312*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        37u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        30u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621311*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        38u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        31u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621413*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        39u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        32u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621412*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        40u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        33u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621411*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        41u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        34u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621513*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        42u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        35u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621512*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        43u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        36u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621511*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        44u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        37u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621613*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        45u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        38u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621612*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        46u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        39u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621611*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        47u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        40u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621713*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        48u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        41u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621712*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        49u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        42u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621711*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        50u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        43u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621813*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        51u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        44u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621812*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        52u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        45u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621811*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        53u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        46u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x62197C*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        54u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        4u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621A29*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        55u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        47u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621B29*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        56u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        48u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621F29*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        88u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        49u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622454*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        57u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        5u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x62291E*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        58u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        50u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622916*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        59u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        51u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622917*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        60u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        52u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622A1E*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        61u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        53u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622A16*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        62u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        54u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622A17*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        63u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        55u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622B1E*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        64u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        56u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622B16*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        65u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        57u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622B17*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        66u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        58u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622C1E*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        67u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        59u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622C16*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        68u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        60u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622C17*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        69u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        61u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x625C63*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        70u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x625D63*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        71u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x625E63*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        72u, /* DemDTCRef */
        6u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x625F63*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        73u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC15187*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        74u, /* DemDTCRef */
        6u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        62u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC12887*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        75u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        63u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC13187*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        76u, /* DemDTCRef */
        6u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        64u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC12987*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        77u, /* DemDTCRef */
        6u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        65u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC15C87*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        78u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        66u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC19887*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        79u, /* DemDTCRef */
        8u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        67u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC14787*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        80u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        68u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC07988*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        81u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        5u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621186*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        82u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        69u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621286*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        83u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        70u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622344*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        84u, /* DemDTCRef */
        8u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x626044*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        85u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x626128*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        86u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        6u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x626129*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        87u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        7u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621F07*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        92u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        71u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621E07*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        93u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        72u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621D07*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        94u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        73u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622147*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        95u, /* DemDTCRef */
        10u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC26C87*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        98u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        74u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x626283*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        99u, /* DemDTCRef */
        11u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x626383*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        100u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x626483*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        101u, /* DemDTCRef */
        13u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x626583*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        102u, /* DemDTCRef */
        14u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x626683*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        103u, /* DemDTCRef */
        15u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD30055*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        104u, /* DemDTCRef */
        16u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621C29*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        91u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        75u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621D29*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        90u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        76u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x621E29*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        89u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        77u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622029*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        96u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        78u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        1u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622007*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        97u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        79u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        2u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620952*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        105u, /* DemDTCRef */
        17u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622912*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        106u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        80u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622A12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        107u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        81u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622B12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        108u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        82u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x622C12*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        109u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        83u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC41881*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        110u, /* DemDTCRef */
        10u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        84u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        6u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC45281*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        111u, /* DemDTCRef */
        10u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        85u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        7u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC57E81*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        112u, /* DemDTCRef */
        11u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        86u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        8u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC44381*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        113u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        87u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        9u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC41781*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        114u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        88u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        10u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x620698*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        115u, /* DemDTCRef */
        18u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        11u, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/*******************************************************************************
*                          Memory Configuration
*******************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGeneral/DemPrimaryMemory 1-1 */
VAR(Dem_EventMemEntryType,AUTOMATIC) DemPrimaryMemory[DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

/* Dem_EventMemEntryType DemUserDefinedMemory<Mem/Name>[Mem/DemMaxNumberEventEntryUserDefined]; */
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_MemDestConfigType,AUTOMATIC) DemMemDestCfg[DEM_MEM_DEST_TOTAL_NUM] =
{
    /* DemPrimaryMemory */
    {
        DemPrimaryMemory,
        DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
    },
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint16,AUTOMATIC) DemNvRamBlockId[DEM_NVRAM_BLOCKID_NUM] =
{
    NvMBlockNvm_Block_DEM_2, /* DemNvRamBlockIdRef  */
    NvMBlockNvm_Block_DEM_1, /* DemNvRamBlockIdRef  */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          OBD Configuration
*******************************************************************************/

/*******************************************************************************
*                          J1939 Configuration
*******************************************************************************/
/*******************************************************************************
*                          PB DemConfigSet Configuration
*******************************************************************************/
#define DEM_START_SEC_PBCFG_GLOBALROOT
#include "Dem_MemMap.h"
CONST(Dem_ConfigType, AUTOMATIC) DemPbCfg =
{
    NULL_PTR,
    DemDTC,
    DemDTCAttributes,
    DemDebounceCounterBasedClass,
    DemDebounceTimeBaseClass,
    NULL_PTR,
    DemEventParameter,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
};
#define DEM_STOP_SEC_PBCFG_GLOBALROOT
#include "Dem_MemMap.h"
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

