/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dem_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-05-12 13:46:36>
 */
/*============================================================================*/

#ifndef DEM_CFG_H_
#define DEM_CFG_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Dem_Types.h"
#include "Dem_CfgEnum.h"
#include "Rte_Dem.h"
#include "Rte_Dem.h"
/*******************************************************************************
*                          General Configuration
*******************************************************************************/
/* DemAvailabilitySupport type: Enum
#define DEM_EVENT_AVAILABILITY 1
#define DEM_NO_AVAILABILITY 2 */
#define DEM_AVAILABILITY_SUPPORT DEM_EVENT_AVAILABILITY

/* DemBswErrorBufferSize Range:0~255 */
#define DEM_BSW_ERROR_BUFFER_SIZE 0u

/* DemClearDTCBehavior type: Enum
#define DEM_CLRRESP_NONVOLATILE_FINISH 1
#define DEM_CLRRESP_NONVOLATILE_TRIGGER 2
#define DEM_CLRRESP_VOLATILE 3 */
#define DEM_CLEAR_DTCBEHAVIOR DEM_CLRRESP_NONVOLATILE_TRIGGER

/* DemClearDTCLimitation type: Enum
#define DEM_ALL_SUPPORTED_DTCS 1
#define DEM_ONLY_CLEAR_ALL_DTCS 2 */
#define DEM_CLEAR_DTCLIMITATION DEM_ALL_SUPPORTED_DTCS

/* DemDebounceCounterBasedSupport Range: true or false */
#define DEM_DEBOUNCE_COUNTER_BASED_SUPPORT STD_ON

/* DemDebounceTimeBasedSupport Range: true or false */
#define DEM_DEBOUNCE_TIME_BASED_SUPPORT STD_ON

/* DemDevErrorDetect Range: true or false */
#define DEM_DEV_ERROR_DETECT STD_OFF

/* DemEnvironmentDataCapture type: Enum
#define DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING 1
#define DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING 2 */
#define DEM_ENVIRONMENT_DATA_CAPTURE DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING

/* DemEventCombinationSupport type: Enum
#define DEM_EVCOMB_DISABLED 1
#define DEM_EVCOMB_ONRETRIEVAL 2
#define DEM_EVCOMB_ONSTORAGE 3 */
#define DEM_EVENT_COMBINATION_SUPPORT DEM_EVCOMB_DISABLED

/* DemEventDisplacementStrategy type: Enum
#define DEM_DISPLACEMENT_FULL 1
#define DEM_DISPLACEMENT_NONE 2
#define DEM_DISPLACEMENT_PRIO_OCC 3 */
#define DEM_EVENT_DISPLACEMENT_STRATEGY DEM_DISPLACEMENT_NONE

/* DemEventMemoryEntryStorageTrigger type: Enum
#define DEM_TRIGGER_ON_CONFIRMED 1
#define DEM_TRIGGER_ON_FDC_THRESHOLD 2
#define DEM_TRIGGER_ON_PENDING 3
#define DEM_TRIGGER_ON_TEST_FAILED 4 */
#define DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER DEM_TRIGGER_ON_TEST_FAILED

/* DemGeneralInterfaceSupport Range: true or false */
#define DEM_GENERAL_INTERFACE_SUPPORT STD_ON

/* DemImmediateNvStorageLimit Range:1~255 */
#define DEM_IMMEDIATE_NV_STORAGE_LIMIT 0xffu

/* DemMaxNumberEventEntryEventBuffer Range:1~250 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_EVENT_BUFFER 116u

/* DemMaxNumberPrestoredFF Range:0~255 */
#define DEM_MAX_NUMBER_PRESTORED_FF 0u

/* DemOccurrenceCounterProcessing type: Enum
#define DEM_PROCESS_OCCCTR_CDTC 1
#define DEM_PROCESS_OCCCTR_TF 2 */ /*the occurrence counter is only
triggered by the TestFailed bit (and the fault confirmation is not considered) This parameter is mandatory in case of J1939*/
#define DEM_OCCURRENCE_COUNTER_PROCESSING DEM_PROCESS_OCCCTR_TF

/* DemOperationCycleStatusStorage Range: true or false */
#define DEM_OPERATION_CYCLE_STATUS_STORAGE STD_OFF

/*DemPTOSupport*/
#define DEM_PTO_SUPPORT STD_OFF

/* DemResetConfirmedBitOnOverflow Range: true or false */
#define DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW STD_ON

/* DemGeneral/DemStatusBitHandlingTestFailedSinceLastClear
#define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT 1
#define DEM_STATUS_BIT_NORMAL 2 */
#define DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR DEM_STATUS_BIT_AGING_AND_DISPLACEMENT

/* DemStatusBitStorageTestFailed Range: true or false */
#define DEM_STATUS_BIT_STORAGE_TEST_FAILED STD_OFF

/* DemSuppressionSupport type: Enum
#define DEM_DTC_SUPPRESSION 1
#define DEM_NO_SUPPRESSION 2 */
#define DEM_SUPPRESSION_SUPPORT DEM_NO_SUPPRESSION

/* DemTaskTime */
#define DEM_TASK_TIME 10u

/* DemTriggerDcmReports Range: true or false */
#define DEM_TRIGGER_DCM_REPORTS STD_OFF

/* DemTriggerDltReports Range: true or false */
#define DEM_TRIGGER_DLT_REPORTS STD_OFF

/* DemTriggerFiMReports Range: true or false */
#define DEM_TRIGGER_FIM_REPORTS STD_OFF

/* DemTriggerMonitorInitBeforeClearOk Range: true or false */
#define DEM_TRIGGER_MONITOR_INIT_BEFORE_CLEAR_OK STD_OFF

/* DemTypeOfDTCSupported type: Enum
#define DEM_DTC_TRANSLATION_ISO11992_4 1
#define DEM_DTC_TRANSLATION_ISO14229_1 2
#define DEM_DTC_TRANSLATION_ISO15031_6 3
#define DEM_DTC_TRANSLATION_SAEJ1939_73 4
#define DEM_DTC_TRANSLATION_SAE_J2012_DA_DTCFORMAT_04 5 */
#define DEM_TYPE_OF_DTCSUPPORTED DEM_DTC_TRANSLATION_ISO15031_6

/* DemTypeOfFreezeFrameRecordNumeration type: Enum
#define DEM_FF_RECNUM_CALCULATED 1
#define DEM_FF_RECNUM_CONFIGURED 2 */
#define DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION DEM_FF_RECNUM_CONFIGURED

/* DemVersionInfoApi Range: true or false */
#define DEM_VERSION_INFO_API STD_ON

/* COUNT(DemGeneral/DemCallbackDTCStatusChanged) 0-* */
#define DEM_CALLBACK_DTC_STATUS_CHANGED_NUM 0u

/* DemAgingRequieresTestedCycle Range: true or false */
#define DEM_AGING_REQUIERES_TESTED_CYCLE STD_OFF

/*******************************************************************************
*                          DemDataElementClass Configuration
*******************************************************************************/
/*DemDataElementClass*/
#define DEM_DATA_ELEMENT_CLASS_NUM  27

#define DEM_EXTERAL_DATA_ELEMENT_CLASS_NUM  25u

/*******************************************************************************
*                          Condition Configuration
*******************************************************************************/
/* DemOperationCycle 1-256 */
#define DEM_OPERATION_CYCLE_NUM 1u

#define ECU_Wakeup_ID 0u

/* DemEnableCondition 0-255 */
#define DEM_ENABLE_CONDITION_NUM 14u

#define Serve_0x85_02_deactivate_ID 0u
#define Not_BusOff_ID 1u
#define Battery_Normal_Or_Recovery_1000ms_ID 2u
#define Pressure_Drop_Less_Normal_ID 3u
#define Pressure_Rise_Less_Normal_ID 4u
#define Level_Sensor_Calibration_ID 5u
#define IgnOn_1_5s_ID 6u
#define Battery_Normal_Or_Recovery_500ms_ID 7u
#define IPB_Normal_ID 8u
#define ABM_Normal_ID 9u
#define VDC_Normal_ID 10u
#define VIU2_Normal_ID 11u
#define EPB_Normal_ID 12u
#define CompressorRun_ID 13u

/* DemEnableConditionGroup 0-255 */
#define DEM_ENABLE_CONDITION_GROUP_NUM 12u

/* DemEnableCondition 0-255 */
#define DEM_STORAGE_CONDITION_NUM 0u

/* DemStorageConditionGroup 0-255 */
#define DEM_STORAGE_CONDITION_GROUP_NUM 0u
/*******************************************************************************
*                          FreezeFrame Configuration
*******************************************************************************/
#define DEM_FFPRESTORAGE_SUPPORT   STD_OFF

/* DemSPNClass 0-0xFFFF */
#define DEM_SPN_CLASS_NUM 0u

#define DEM_J1939_FREEZE_FRAME_CLASS_NUM 0u

#define DEM_SPN_CLASS_REF_TOTAL_NUM 0u

/* DemDidClass 0-0xFFFF */
#define DEM_DID_CLASS_NUM 25u

/* DemFreezeFrameClass 0-65535 */
#define DEM_FREEZE_FRAME_CLASS_NUM 10u

/* SUM(COUNT(DemFreezeFrameClass/DemDidClassRef)) */
#define DEM_DID_CLASS_REF_TOTAL_NUM 99u

/* DemFreezeFrameRecordClass 0-255 */
#define DEM_FREEZE_FRAME_RECORD_CLASS_NUM 2u

#define DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM 1u

/* SUM(COUNT(DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)) */
#define DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM 2u

#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
/* MAX(COUNT((DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)))  1-254 */
#define DEM_MAX_NUMBER_FF_RECORDS 2u
#endif

/* DemPidClass 0-0xFFFF */
#define DEM_PID_CLASS_NUM 0u
#define DEM_PID_TOTAL_SIZE  0u /*total size of all pid*/

/* max value of PID and all ref freezeframe size) */
#define DEM_FREEZE_FRAME_MAX_LEN 38u
/*******************************************************************************
*                          ExtendedData Configuration
*******************************************************************************/
/* DemExtendedDataRecordClass 0-253 */
#define DEM_EXTENDED_DATA_RECORD_CLASS_NUM 2u

/* DemExtendedDataClass 0-* */
#define DEM_EXTENDED_DATA_CLASS_NUM 1u

/* SUM(COUNT(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef)) */
#define DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM  2u

/* MAX(COUNT(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef)) */
#define DEM_EXTENDED_DATA_MAX_REF_NUM 2u

/* MAX(SUM(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef/DataSize)) */
#define DEM_EXTENDED_DATA_MAX_LEN 2u
/*******************************************************************************
*                          DTC Configuration
*******************************************************************************/
/* DemGroupOfDTC 0-255 */
#define DEM_GROUP_OF_DTC_NUM 0u

#define DEM_DTC_REF_EMISSION_NUM  0u

/* DemDTC 0-65535 */
#define DEM_DTC_NUM 116u

#define DEM_WWWOBD_NUM 0u

/* DemDTCAttributes 0-65535 */
#define DEM_DTC_ATTRIBUTES_NUM 10u

/* DemDtcStatusAvailabilityMask Range:0~255 */
#define DEM_DTC_STATUS_AVAILABILITY_MASK 0x9u

#define DEM_J1939_NODE_NUM 0u
#define DEM_J1939_NODEID_MAX_NUM  0u

/* DemObdDTC 0-65535 */
#define DEM_OBD_DTC_NUM 0u

#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CALCULATED)
/* MAX(DemConfigSet/DemDTCAttributes/DemMaxNumberFreezeFrameRecords) */
#define DEM_MAX_NUMBER_FF_RECORDS 0u
#endif

/*******************************************************************************
*                          Indicator Configuration
*******************************************************************************/
/* DemIndicator 0..255 */
#define DEM_INDICATOR_NUM 0u

/*DemMILIndicatorRef*/
#define DEM_MALFUNCTION_LAMP_INDICATOR DemIndicator_INVALID

/*DemProtectLampIndicatorRef */
#define DEM_PROTECT_LAMP_INDICATOR DemIndicator_INVALID

/*DemRedStopLampIndicatorRef */
#define DEM_RED_STOP_LAMP_INDICATOR DemIndicator_INVALID

/*DemAmberWarningLampIndicatorRef */
#define DEM_AMBER_WARING_LAMP_INDICATOR DemIndicator_INVALID

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemIndicatorAttribute)) */
#define DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM 0u

/*******************************************************************************
*                          Debounce Configuration
*******************************************************************************/
/* DemDebounceCounterBasedClass 0-65535 */
#define DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM 5u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE ((DemEventParameter/DemDebounceAlgorithmClass == DemDebounceCounterBased)
 *         && DemDebounceCounterBased/DemDebounceCounterBasedClassRef/DemDebounceCounterStorage == true) */
#define DEM_DEBOUNCE_COUNTER_STORAGE_NUM 0u

/* DemDebounceTimeBaseClass 0-65535 */
#define DEM_DEBOUNCE_TIME_BASE_CLASS_NUM 13u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceTimeBase) */
#define DEM_DEBOUNCE_TIME_BASED_EVENT_NUM 89u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceCounterBased) */
#define DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM 8u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceMonitorInternal) */
#define DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM 0u

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemCallbackEventStatusChanged))) */
#define DEM_CALLBACK_EVENT_STATUS_CHANGED_TOTAL_NUM 0u

/*******************************************************************************
*                          Event Configuration
*******************************************************************************/
/*DemComponentClass*/
#define DEM_COMPONENT_NUM 0u

#define DEM_IMMEDITE_CHILD_COMPONENT_MAX_NUM  1u

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemCallbackClearEventAllowed))) */
#define DEM_CALLBACK_CLEAR_EVENT_ALLOWED_TOTAL_NUM 0u

/* DemEventParameter 1-65535 */
#define DEM_EVENT_PARAMETER_NUM 116u

#define DemEventParameter_0x620016  1u
#define DemEventParameter_0x620017  2u
#define DemEventParameter_0x620104  3u
#define DemEventParameter_0x620212  4u
#define DemEventParameter_0x620214  5u
#define DemEventParameter_0x620213  6u
#define DemEventParameter_0x620312  7u
#define DemEventParameter_0x620314  8u
#define DemEventParameter_0x620313  9u
#define DemEventParameter_0x620412  10u
#define DemEventParameter_0x620414  11u
#define DemEventParameter_0x620413  12u
#define DemEventParameter_0x620785  13u
#define DemEventParameter_0x620784  14u
#define DemEventParameter_0x620885  15u
#define DemEventParameter_0x620884  16u
#define DemEventParameter_0x620A86  17u
#define DemEventParameter_0x620B4B  18u
#define DemEventParameter_0x620C13  19u
#define DemEventParameter_0x620C12  20u
#define DemEventParameter_0x620C11  21u
#define DemEventParameter_0x620D13  22u
#define DemEventParameter_0x620D12  23u
#define DemEventParameter_0x620D11  24u
#define DemEventParameter_0x620E13  25u
#define DemEventParameter_0x620E12  26u
#define DemEventParameter_0x620E11  27u
#define DemEventParameter_0x620F13  28u
#define DemEventParameter_0x620F12  29u
#define DemEventParameter_0x620F11  30u
#define DemEventParameter_0x62107C  31u
#define DemEventParameter_0x621101  32u
#define DemEventParameter_0x621114  33u
#define DemEventParameter_0x621112  34u
#define DemEventParameter_0x621211  35u
#define DemEventParameter_0x621212  36u
#define DemEventParameter_0x621313  37u
#define DemEventParameter_0x621312  38u
#define DemEventParameter_0x621311  39u
#define DemEventParameter_0x621413  40u
#define DemEventParameter_0x621412  41u
#define DemEventParameter_0x621411  42u
#define DemEventParameter_0x621513  43u
#define DemEventParameter_0x621512  44u
#define DemEventParameter_0x621511  45u
#define DemEventParameter_0x621613  46u
#define DemEventParameter_0x621612  47u
#define DemEventParameter_0x621611  48u
#define DemEventParameter_0x621713  49u
#define DemEventParameter_0x621712  50u
#define DemEventParameter_0x621711  51u
#define DemEventParameter_0x621813  52u
#define DemEventParameter_0x621812  53u
#define DemEventParameter_0x621811  54u
#define DemEventParameter_0x62197C  55u
#define DemEventParameter_0x621A29  56u
#define DemEventParameter_0x621B29  57u
#define DemEventParameter_0x621F29  58u
#define DemEventParameter_0x622454  59u
#define DemEventParameter_0x62291E  60u
#define DemEventParameter_0x622916  61u
#define DemEventParameter_0x622917  62u
#define DemEventParameter_0x622A1E  63u
#define DemEventParameter_0x622A16  64u
#define DemEventParameter_0x622A17  65u
#define DemEventParameter_0x622B1E  66u
#define DemEventParameter_0x622B16  67u
#define DemEventParameter_0x622B17  68u
#define DemEventParameter_0x622C1E  69u
#define DemEventParameter_0x622C16  70u
#define DemEventParameter_0x622C17  71u
#define DemEventParameter_0x625C63  72u
#define DemEventParameter_0x625D63  73u
#define DemEventParameter_0x625E63  74u
#define DemEventParameter_0x625F63  75u
#define DemEventParameter_0xC15187  76u
#define DemEventParameter_0xC12887  77u
#define DemEventParameter_0xC13187  78u
#define DemEventParameter_0xC12987  79u
#define DemEventParameter_0xC15C87  80u
#define DemEventParameter_0xC19887  81u
#define DemEventParameter_0xC14787  82u
#define DemEventParameter_0xC07988  83u
#define DemEventParameter_0x621186  84u
#define DemEventParameter_0x621286  85u
#define DemEventParameter_0x622344  86u
#define DemEventParameter_0x626044  87u
#define DemEventParameter_0x626128  88u
#define DemEventParameter_0x626129  89u
#define DemEventParameter_0x621F07  90u
#define DemEventParameter_0x621E07  91u
#define DemEventParameter_0x621D07  92u
#define DemEventParameter_0x622147  93u
#define DemEventParameter_0xC26C87  94u
#define DemEventParameter_0x622200  95u
#define DemEventParameter_0x626383  96u
#define DemEventParameter_0x626483  97u
#define DemEventParameter_0x626583  98u
#define DemEventParameter_0x626683  99u
#define DemEventParameter_0xD30055  100u
#define DemEventParameter_0x621C29  101u
#define DemEventParameter_0x621D29  102u
#define DemEventParameter_0x621E29  103u
#define DemEventParameter_0x622029  104u
#define DemEventParameter_0x622007  105u
#define DemEventParameter_0x620952  106u
#define DemEventParameter_0x622912  107u
#define DemEventParameter_0x622A12  108u
#define DemEventParameter_0x622B12  109u
#define DemEventParameter_0x622C12  110u
#define DemEventParameter_0xC41881  111u
#define DemEventParameter_0xC45281  112u
#define DemEventParameter_0xC57E81  113u
#define DemEventParameter_0xC44381  114u
#define DemEventParameter_0xC41781  115u
#define DemEventParameter_0x620698  116u
/*******************************************************************************
*                          Memory Configuration
*******************************************************************************/
/* COUNT(DemGeneral/Dem<xx>Memory) */
#define DEM_MEM_DEST_TOTAL_NUM 1u

/* MAX(DemGeneral/Dem<XX>Memory/DemMaxNumberEventEntry<XX>) */
#define DEM_MEM_DEST_MAX_ENTRY_NUM 116u

/* DemMaxNumberEventEntryPermanent Range:0~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT 0u

/* DemPrimaryMemory 1-1 */
/* DemMaxNumberEventEntryPrimary Range:1~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY 116u

/* DemMirrorMemory 0-1 */
/* DemMaxNumberEventEntryMirror Range:0~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_MIRROR  0u

/*DemMaxNumberEventEntryUserDefined*/

/*DemUserDefinedMemoryIdentifier*/

/* COUNT(DemGeneral/DemNvRamBlockId) */
#define DEM_NVRAM_BLOCKID_NUM 2

#define DEM_NVRAM_DIVADED    STD_OFF

/* MAX(DemConfigSet/DemDTCAttributes/DemMemoryDestinationRef) 0~2 */
#define DEM_MEM_DEST_MAX_NUM_OF_DTC 1u /* DemMemoryDestinationRef 0-2 */
/*******************************************************************************
*                          OBD Configuration
*******************************************************************************/
/*DemOBDSupport
 * #define DEM_OBD_DEP_SEC_ECU 1
#define DEM_OBD_MASTER_ECU 2
#define DEM_OBD_NO_OBD_SUPPORT 3
#define DEM_OBD_PRIMARY_ECU 4*/
#define DEM_OBD_SUPPORT DEM_OBD_NO_OBD_SUPPORT

#define DEM_SECONDARY_FUNCTIONID_REF_MAX_NUM  2u

#define DEM_RATIO_NUM 0u

#define DEM_DTR_NUM 0u

/*******************************************************************************
*                          J1939 Configuration
*******************************************************************************/
#define DEM_J1939_SUPPORT STD_OFF

#define DEM_DEAL_MAINFUNCTION_ENABLE   STD_OFF

#define DEM_ENABLE_SOFT_FILTER_OF_PASS STD_OFF

#endif /* DEM_CFG_H_ */
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

