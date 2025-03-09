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
**  FILENAME    : Com_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2023/04/28 10:58:28                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of Com                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#ifndef  COM_CFG_H
#define  COM_CFG_H

#include "ComStack_Types.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define COM_CFG_H_AR_MAJOR_VERSION    4u
#define COM_CFG_H_AR_MINOR_VERSION    2u
#define COM_CFG_H_AR_PATCH_VERSION    2u
#define COM_CFG_H_SW_MAJOR_VERSION    2u
#define COM_CFG_H_SW_MINOR_VERSION    0u
#define COM_CFG_H_SW_PATCH_VERSION    0u

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define COM_CANCELLATION_SUPPORT                     STD_OFF
#define COM_DEV_ERROR_DETECT                         STD_ON
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API            STD_OFF
#define COM_VERSION_INFO_API                         STD_OFF
#define COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION       STD_ON
#define COM_METADATA_SUPPORT                         STD_OFF
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS           STD_OFF

#define COM_IPDUGROUP_NUMBER                         4u
#define Com_RxPduGroup_CanController_CAN1_FD        0u
#define Com_TxPduGroup_CanController_CAN1_FD        1u
#define Com_RxPduGroup_CanController_TEST_CAN        2u
#define Com_TxPduGroup_CanController_TEST_CAN        3u

#define COM_RXIPDU_NUMBER        23u
#define COM_RXPDU_COM_EPB_State_R        0u
#define COM_RXPDU_COM_IPB_ADS        1u
#define COM_RXPDU_COM_VIU_DoorLock        2u
#define COM_RXPDU_COM_VIU_Info        3u
#define COM_RXPDU_COM_EPS_State        4u
#define COM_RXPDU_COM_ABM_State        5u
#define COM_RXPDU_COM_IPB_State1        6u
#define COM_RXPDU_COM_IPB_Tq        7u
#define COM_RXPDU_COM_IPB_Wheel        8u
#define COM_RXPDU_COM_TBOX_TimeInfo        9u
#define COM_RXPDU_COM_ScrToECAS        10u
#define COM_RXPDU_Com_BT_Master        11u
#define COM_RXPDU_COM_ECAS_DV_BA_Req        12u
#define COM_RXPDU_COM_VIU_Config        13u
#define COM_RXPDU_COM_VIU_ConfigTrig        14u
#define COM_RXPDU_COM_ADS_ECAS        15u
#define COM_RXPDU_COM_ADS_State        16u
#define COM_RXPDU_COM_VDC_CDCSet        17u
#define COM_RXPDU_COM_VDC_VIU_BodyInfo        18u
#define COM_RXPDU_COM_VIU_Route_SUS        19u
#define COM_RXPDU_COM_VDC_FMtTq        20u
#define COM_RXPDU_COM_VDC_RMtTq        21u
#define COM_RXPDU_COM_VDC_PTSt        22u

#define COM_TXIPDU_NUMBER    8u
#define COM_TXPDU_COM_ECAS_EDC_Test        23u
#define COM_TXPDU_COM_ECAS_EDC_State        24u
#define COM_TXPDU_COM_ECASToScr        25u
#define COM_TXPDU_Com_BT_Slave        26u
#define COM_TXPDU_ComCanNmUserDataTxPdu        27u
#define COM_TXPDU_COM_ECAS_State        28u
#define COM_TXPDU_COM_ECAS_RemoteDiag        29u
#define COM_TXPDU_COM_ECAS_EDC_RemoteDiag        30u
#define COM_RXIPDUBUFF_SIZE        540u
#define COM_TXIPDUBUFF_SIZE        166u

#define COM_SIGNAL_BOOLBUFF_SIZE            67u
#define COM_RXGROUPSIGNAL_BOOLBUFF_SIZE     0u
#define COM_SIGNAL_BOOL_INVALID_SIZE        0u

#define COM_SIGNAL_8BITBUFF_SIZE            146u
#define COM_RXGROUPSIGNAL_8BITBUFF_SIZE     0u
#define COM_SIGNAL_8BIT_INVALID_SIZE        0u

#define COM_SIGNAL_16BITBUFF_SIZE           98u
#define COM_RXGROUPSIGNAL_16BITBUFF_SIZE    0u
#define COM_SIGNAL_16BIT_INVALID_SIZE       0u

#define COM_SIGNAL_32BITBUFF_SIZE           1u
#define COM_RXGROUPSIGNAL_32BITBUFF_SIZE    0u
#define COM_SIGNAL_32BIT_INVALID_SIZE       0u

#define COM_SIGNAL_64BITBUFF_SIZE           0u
#define COM_RXGROUPSIGNAL_64BITBUFF_SIZE    0u
#define COM_SIGNAL_64BIT_INVALID_SIZE       0u

#define COM_TMCTXSIGNAL_NUMBER              0u
#define COM_TMCTXGROUPSIGNAL_NUMBER         0u

#define COM_TXSIGNALGROUP_NUMBER            0u

#define COM_RXSIGNALGROUP_NUMBER            0u

#define COM_TXSIGNAL_NUMBER                  116u
#define EDC_IRRFb_IPDU_COM_ECAS_EDC_Test               0u
#define EDC_IRLFb_IPDU_COM_ECAS_EDC_Test               1u
#define EDC_IFRFb_IPDU_COM_ECAS_EDC_Test               2u
#define EDC_IFLFb_IPDU_COM_ECAS_EDC_Test               3u
#define EDC_SystemFaultSts_IPDU_COM_ECAS_EDC_State               4u
#define EDC_Actualmode_IPDU_COM_ECAS_EDC_State               5u
#define EDC_REAR_bodyacceleration_IPDU_COM_ECAS_EDC_State               6u
#define EDC_REAR_bodyaccelerationValid_IPDU_COM_ECAS_EDC_State               7u
#define EDC_FR_bodyacceleration_IPDU_COM_ECAS_EDC_State               8u
#define EDC_FR_bodyaccelerationValid_IPDU_COM_ECAS_EDC_State               9u
#define EDC_FL_bodyacceleration_IPDU_COM_ECAS_EDC_State               10u
#define EDC_FL_bodyaccelerationValid_IPDU_COM_ECAS_EDC_State               11u
#define EDC_State_RollingCounter_IPDU_COM_ECAS_EDC_State               12u
#define EDC_State_Checksum_IPDU_COM_ECAS_EDC_State               13u
#define ScrLvlAdjtSts_IPDU_COM_ECASToScr               14u
#define ScrFaultLamp_IPDU_COM_ECASToScr               15u
#define ScrCurrentLvl_IPDU_COM_ECASToScr               16u
#define ScrLvlAdjModLamp_IPDU_COM_ECASToScr               17u
#define ScrDrivModLamp_IPDU_COM_ECASToScr               18u
#define Data0_IPDU_COM_BT_Slave               19u
#define Data1_IPDU_COM_BT_Slave               20u
#define Data2_IPDU_COM_BT_Slave               21u
#define Data3_IPDU_COM_BT_Slave               22u
#define isCanNmUserData_ECAS               23u
#define EDC_FaultNum20_IPDU_COM_ECAS_EDC_RemoteDiag               24u
#define EDC_FaultNum19_IPDU_COM_ECAS_EDC_RemoteDiag               25u
#define EDC_FaultNum18_IPDU_COM_ECAS_EDC_RemoteDiag               26u
#define EDC_FaultNum17_IPDU_COM_ECAS_EDC_RemoteDiag               27u
#define EDC_FaultNum16_IPDU_COM_ECAS_EDC_RemoteDiag               28u
#define EDC_FaultNum15_IPDU_COM_ECAS_EDC_RemoteDiag               29u
#define EDC_FaultNum14_IPDU_COM_ECAS_EDC_RemoteDiag               30u
#define EDC_FaultNum13_IPDU_COM_ECAS_EDC_RemoteDiag               31u
#define EDC_FaultNum12_IPDU_COM_ECAS_EDC_RemoteDiag               32u
#define EDC_FaultNum11_IPDU_COM_ECAS_EDC_RemoteDiag               33u
#define EDC_FaultNum10_IPDU_COM_ECAS_EDC_RemoteDiag               34u
#define EDC_FaultNum9_IPDU_COM_ECAS_EDC_RemoteDiag               35u
#define EDC_FaultNum8_IPDU_COM_ECAS_EDC_RemoteDiag               36u
#define EDC_FaultNum7_IPDU_COM_ECAS_EDC_RemoteDiag               37u
#define EDC_FaultNum6_IPDU_COM_ECAS_EDC_RemoteDiag               38u
#define EDC_FaultNum5_IPDU_COM_ECAS_EDC_RemoteDiag               39u
#define EDC_FaultNum4_IPDU_COM_ECAS_EDC_RemoteDiag               40u
#define EDC_FaultNum3_IPDU_COM_ECAS_EDC_RemoteDiag               41u
#define EDC_FaultNum2_IPDU_COM_ECAS_EDC_RemoteDiag               42u
#define EDC_FaultNum1_IPDU_COM_ECAS_EDC_RemoteDiag               43u
#define EDC_SupplierNum_IPDU_COM_ECAS_EDC_RemoteDiag               44u
#define EDC_FrameIndex_IPDU_COM_ECAS_EDC_RemoteDiag               45u
#define EDC_TotalFaultNum_IPDU_COM_ECAS_EDC_RemoteDiag               46u
#define ECAS_FaultNum20_IPDU_COM_ECAS_RemoteDiag               47u
#define ECAS_FaultNum19_IPDU_COM_ECAS_RemoteDiag               48u
#define ECAS_FaultNum18_IPDU_COM_ECAS_RemoteDiag               49u
#define ECAS_FaultNum17_IPDU_COM_ECAS_RemoteDiag               50u
#define ECAS_FaultNum16_IPDU_COM_ECAS_RemoteDiag               51u
#define ECAS_FaultNum15_IPDU_COM_ECAS_RemoteDiag               52u
#define ECAS_FaultNum14_IPDU_COM_ECAS_RemoteDiag               53u
#define ECAS_FaultNum13_IPDU_COM_ECAS_RemoteDiag               54u
#define ECAS_FaultNum12_IPDU_COM_ECAS_RemoteDiag               55u
#define ECAS_FaultNum11_IPDU_COM_ECAS_RemoteDiag               56u
#define ECAS_FaultNum10_IPDU_COM_ECAS_RemoteDiag               57u
#define ECAS_FaultNum9_IPDU_COM_ECAS_RemoteDiag               58u
#define ECAS_FaultNum8_IPDU_COM_ECAS_RemoteDiag               59u
#define ECAS_FaultNum7_IPDU_COM_ECAS_RemoteDiag               60u
#define ECAS_FaultNum6_IPDU_COM_ECAS_RemoteDiag               61u
#define ECAS_FaultNum5_IPDU_COM_ECAS_RemoteDiag               62u
#define ECAS_FaultNum4_IPDU_COM_ECAS_RemoteDiag               63u
#define ECAS_FaultNum3_IPDU_COM_ECAS_RemoteDiag               64u
#define ECAS_FaultNum2_IPDU_COM_ECAS_RemoteDiag               65u
#define ECAS_FaultNum1_IPDU_COM_ECAS_RemoteDiag               66u
#define ECAS_SupplierNum_IPDU_COM_ECAS_RemoteDiag               67u
#define ECAS_FrameIndex_IPDU_COM_ECAS_RemoteDiag               68u
#define ECAS_TotalFaultNum_IPDU_COM_ECAS_RemoteDiag               69u
#define ECAS_HighwayModFb_IPDU_COM_ECAS_State               70u
#define ECAS_OvldSts_IPDU_COM_ECAS_State               71u
#define ECAS_CarModFb_IPDU_COM_ECAS_State               72u
#define ECAS_DrvModHeiLvlFb_IPDU_COM_ECAS_State               73u
#define EDC_RoadPreDamCon_IPDU_COM_ECAS_State               74u
#define ECAS_AutoEasyEntryFb_IPDU_COM_ECAS_State               75u
#define ECAS_LiftModFb_IPDU_COM_ECAS_State               76u
#define ECAS_FuncLimitState_IPDU_COM_ECAS_State               77u
#define ECAS_VehicleTargetPositionState_IPDU_COM_ECAS_State               78u
#define ECAS_VehiclePositionState_IPDU_COM_ECAS_State               79u
#define ECAS_VehicleUpDownState_IPDU_COM_ECAS_State               80u
#define ECAS_ExtraLoPosn_IPDU_COM_ECAS_State               81u
#define ECAS_ExtraHiPosn_IPDU_COM_ECAS_State               82u
#define ECAS_LvlAdj_Restriction_IPDU_COM_ECAS_State               83u
#define ECAS_SystemState_IPDU_COM_ECAS_State               84u
#define ECAS_Overheat_warning_IPDU_COM_ECAS_State               85u
#define ECAS_MntnSts_IPDU_COM_ECAS_State               86u
#define ECAS_AirSpringPressure_RR_IPDU_COM_ECAS_State               87u
#define ECAS_AirSpringPressure_RL_IPDU_COM_ECAS_State               88u
#define ECAS_AirSpringPressure_FR_IPDU_COM_ECAS_State               89u
#define ECAS_AirSpringPressure_FL_IPDU_COM_ECAS_State               90u
#define ECAS_TgtLvlRR_IPDU_COM_ECAS_State               91u
#define ECAS_TgtLvlRL_IPDU_COM_ECAS_State               92u
#define ECAS_TgtLvlFR_IPDU_COM_ECAS_State               93u
#define ECAS_TgtLvlFL_IPDU_COM_ECAS_State               94u
#define ECAS_RearRiLvlAdjm_IPDU_COM_ECAS_State               95u
#define ECAS_RearLeLvlAdjm_IPDU_COM_ECAS_State               96u
#define ECAS_FrntRiLvlAdjm_IPDU_COM_ECAS_State               97u
#define ECAS_FrntLeLvlAdjm_IPDU_COM_ECAS_State               98u
#define ECAS_SuspensionheightModeRRValid_IPDU_COM_ECAS_State               99u
#define ECAS_SuspensionheightModeRR_IPDU_COM_ECAS_State               100u
#define ECAS_SuspensionheightModeRLValid_IPDU_COM_ECAS_State               101u
#define ECAS_SuspensionheightModeRL_IPDU_COM_ECAS_State               102u
#define ECAS_SuspensionheightModeFRValid_IPDU_COM_ECAS_State               103u
#define ECAS_SuspensionheightModeFR_IPDU_COM_ECAS_State               104u
#define ECAS_SuspensionheightModeFLValid_IPDU_COM_ECAS_State               105u
#define ECAS_SuspensionheightModeFL_IPDU_COM_ECAS_State               106u
#define ECAS_ActvLvlRR_IPDU_COM_ECAS_State               107u
#define ECAS_ActvLvlRL_IPDU_COM_ECAS_State               108u
#define ECAS_ActvLvlFR_IPDU_COM_ECAS_State               109u
#define ECAS_ActvLvlFL_IPDU_COM_ECAS_State               110u
#define ECAS_State_RollingCounter_IPDU_COM_ECAS_State               111u
#define ECAS_State_Checksum_IPDU_COM_ECAS_State               112u
#define EDC_TSnsrErrSts_IPDU_COM_ECAS_EDC_State               113u
#define EDC_PSnsrErrSts_IPDU_COM_ECAS_EDC_State               114u
#define EDC_ASnsrErrSts_IPDU_COM_ECAS_EDC_State               115u

#define COM_RXSIGNAL_NUMBER               184u
#define EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R             0u
#define EPB_ActrSt_IPDU_COM_EPB_State_R             1u
#define EPB_State_RollingCounter_IPDU_COM_EPB_State_R             2u
#define EPB_State_Checksum_IPDU_COM_EPB_State_R             3u
#define IPB_AEBActive_IPDU_COM_IPB_ADS             4u
#define IPB_ABPActive_IPDU_COM_IPB_ADS             5u
#define IPB_ADS_RollingCounter_IPDU_COM_IPB_ADS             6u
#define IPB_ADS_Checksum_IPDU_COM_IPB_ADS             7u
#define VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock             8u
#define VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock             9u
#define VIU_HoodLockSt_IPDU_COM_VIU_DoorLock             10u
#define VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock             11u
#define VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock             12u
#define VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock             13u
#define VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock             14u
#define VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock             15u
#define VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock             16u
#define VIU_TailgateSt_IPDU_COM_VIU_DoorLock             17u
#define VIU_HoodSt_IPDU_COM_VIU_DoorLock             18u
#define VIU_RRDoorSt_IPDU_COM_VIU_DoorLock             19u
#define VIU_RLDoorSt_IPDU_COM_VIU_DoorLock             20u
#define VIU_PassDoorSt_IPDU_COM_VIU_DoorLock             21u
#define VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock             22u
#define VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock             23u
#define VIU_DoorLock_RollingCounter_IPDU_COM_VIU_DoorLock             24u
#define VIU_DoorLock_Checksum_IPDU_COM_VIU_DoorLock             25u
#define VIU_PowerMode_IPDU_COM_VIU_Info             26u
#define VIU_CarMode_IPDU_COM_VIU_Info             27u
#define VIU_UsageMode_IPDU_COM_VIU_Info             28u
#define VIU_Info_RollingCounter_IPDU_COM_VIU_Info             29u
#define VIU_Info_Checksum_IPDU_COM_VIU_Info             30u
#define EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State             31u
#define EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State             32u
#define EPS_SteerWheelAngle_IPDU_COM_EPS_State             33u
#define EPS_SteerWheelAngleValid_IPDU_COM_EPS_State             34u
#define EPS_State_RollingCounter_IPDU_COM_EPS_State             35u
#define EPS_State_Checksum_IPDU_COM_EPS_State             36u
#define ABM_IMU_YrsCalibStatus_IPDU_COM_ABM_State             37u
#define ABM_IMU_YawRateValid_IPDU_COM_ABM_State             38u
#define ABM_IMU_LateralAccValid_IPDU_COM_ABM_State             39u
#define ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State             40u
#define ABM_IMU_YawRate_IPDU_COM_ABM_State             41u
#define ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State             42u
#define ABM_IMU_LongAcceleration_IPDU_COM_ABM_State             43u
#define ABM_State_RollingCounter_IPDU_COM_ABM_State             44u
#define ABM_State_Checksum_IPDU_COM_ABM_State             45u
#define IPB_PlungerPressureValid_IPDU_COM_IPB_State1             46u
#define IPB_PlungerPressure_IPDU_COM_IPB_State1             47u
#define IPB_SimulatorPressure_IPDU_COM_IPB_State1             48u
#define IPB_SimulatorPressureValid_IPDU_COM_IPB_State1             49u
#define IPB_VDCActive_IPDU_COM_IPB_State1             50u
#define IPB_TCSActive_IPDU_COM_IPB_State1             51u
#define IPB_ABSActive_IPDU_COM_IPB_State1             52u
#define IPB_ESCActive_IPDU_COM_IPB_State1             53u
#define IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1             54u
#define IPB_BrakePedalPress_IPDU_COM_IPB_State1             55u
#define IPB_State1_RollingCounter_IPDU_COM_IPB_State1             56u
#define IPB_State1_Checksum_IPDU_COM_IPB_State1             57u
#define IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq             58u
#define IPB_HydBrkActvTq_IPDU_COM_IPB_Tq             59u
#define IPB_Tq_RollingCounter_IPDU_COM_IPB_Tq             60u
#define IPB_Tq_Checksum_IPDU_COM_IPB_Tq             61u
#define IPB_VehicleSpeed_IPDU_COM_IPB_Wheel             62u
#define IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel             63u
#define IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel             64u
#define IPB_SumOfEdgeRRWSSValid_IPDU_COM_IPB_Wheel             65u
#define IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel             66u
#define IPB_SumOfEdgeRLWSSValid_IPDU_COM_IPB_Wheel             67u
#define IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel             68u
#define IPB_SumOfEdgeFRWSSValid_IPDU_COM_IPB_Wheel             69u
#define IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel             70u
#define IPB_SumOfEdgeFLWSSValid_IPDU_COM_IPB_Wheel             71u
#define IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel             72u
#define IPB_WheelDirectionRRValid_IPDU_COM_IPB_Wheel             73u
#define IPB_WheelDirectionRR_IPDU_COM_IPB_Wheel             74u
#define IPB_SumOfEdgeRRWSS_IPDU_COM_IPB_Wheel             75u
#define IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel             76u
#define IPB_WheelDirectionRLValid_IPDU_COM_IPB_Wheel             77u
#define IPB_WheelDirectionRL_IPDU_COM_IPB_Wheel             78u
#define IPB_SumOfEdgeRLWSS_IPDU_COM_IPB_Wheel             79u
#define IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel             80u
#define IPB_WheelDirectionFRValid_IPDU_COM_IPB_Wheel             81u
#define IPB_WheelDirectionFR_IPDU_COM_IPB_Wheel             82u
#define IPB_SumOfEdgeFRWSS_IPDU_COM_IPB_Wheel             83u
#define IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel             84u
#define IPB_WheelDirectionFLValid_IPDU_COM_IPB_Wheel             85u
#define IPB_WheelDirectionFL_IPDU_COM_IPB_Wheel             86u
#define IPB_SumOfEdgeFLWSS_IPDU_COM_IPB_Wheel             87u
#define IPB_Wheel_RollingCounter_IPDU_COM_IPB_Wheel             88u
#define IPB_Wheel_Checksum_IPDU_COM_IPB_Wheel             89u
#define TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo             90u
#define TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo             91u
#define TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo             92u
#define TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo             93u
#define TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo             94u
#define TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo             95u
#define TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo             96u
#define TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo             97u
#define TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo             98u
#define ScrMainMod_IPDU_COM_ScrToECAS             99u
#define ScrEasyEntryEna_IPDU_COM_ScrToECAS             100u
#define ScrEasyLoadEna_IPDU_COM_ScrToECAS             101u
#define ScrSuisuCtrlEna_IPDU_COM_ScrToECAS             102u
#define ScrLvlModReq_IPDU_COM_ScrToECAS             103u
#define ScrLvlAdjReq_IPDU_COM_ScrToECAS             104u
#define ScrDrivModReq_IPDU_COM_ScrToECAS             105u
#define Data0_IPDU_COM_BT_Master             106u
#define Data1_IPDU_COM_BT_Master             107u
#define Data2_IPDU_COM_BT_Master             108u
#define Data3_IPDU_COM_BT_Master             109u
#define MagicNum_IPDU_COM_ECAS_DV_BA_Req             110u
#define VIU_Config_SN_IPDU_COM_VIU_Config             111u
#define VIU_Config_RollingCounter_IPDU_COM_VIU_Config             112u
#define VIU_Config_Checksum_IPDU_COM_VIU_Config             113u
#define VIU_ConfigMsgTrig_IPDU_COM_VIU_ConfigTrig             114u
#define ADS_RiWhlLgtDst_IPDU_COM_ADS_ECAS             115u
#define ADS_RiWhlRoadHei_IPDU_COM_ADS_ECAS             116u
#define ADS_RiWhlRoadFeature_IPDU_COM_ADS_ECAS             117u
#define ADS_RiWhlRoadSts_IPDU_COM_ADS_ECAS             118u
#define ADS_LeWhlLgtDst_IPDU_COM_ADS_ECAS             119u
#define ADS_LeWhlRoadHei_IPDU_COM_ADS_ECAS             120u
#define ADS_LeWhlRoadFeature_IPDU_COM_ADS_ECAS             121u
#define ADS_LeWhlRoadSts_IPDU_COM_ADS_ECAS             122u
#define ADS_RoadTyp_IPDU_COM_ADS_ECAS             123u
#define ADS_RoadInfoAvl_IPDU_COM_ADS_ECAS             124u
#define ADS_ECAS_RollingCounter_IPDU_COM_ADS_ECAS             125u
#define ADS_ECAS_Checksum_IPDU_COM_ADS_ECAS             126u
#define ADS_SuspensionStatus_IPDU_COM_ADS_State             127u
#define ADS_State_RollingCounter_IPDU_COM_ADS_State             128u
#define ADS_State_Checksum_IPDU_COM_ADS_State             129u
#define VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet             130u
#define VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet             131u
#define VDC_CDCSet_RollingCounter_IPDU_COM_VDC_CDCSet             132u
#define VDC_CDCSet_Checksum_IPDU_COM_VDC_CDCSet             133u
#define TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo             134u
#define TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo             135u
#define VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo             136u
#define VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo             137u
#define VDC_RollingCounter_IPDU_COM_VDC_VIU_BodyInfo             138u
#define VDC_Checksum_IPDU_COM_VDC_VIU_BodyInfo             139u
#define IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1             140u
#define IPB_PushRodActTrvl_IPDU_COM_IPB_State1             141u
#define BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS             142u
#define OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS             143u
#define BMS_PackSOCDisp_IPDU_COM_VIU_Route_SUS             144u
#define RSM_RelHum_IPDU_COM_VIU_Route_SUS             145u
#define LBMS_SOC_IPDU_COM_VIU_Route_SUS             146u
#define LBMS_PackExtU_IPDU_COM_VIU_Route_SUS             147u
#define VIU_BodyInfo_RollingCounter_IPDU_COM_VIU_Route_SUS             148u
#define VIU_BodyInfo_Checksum_IPDU_COM_VIU_Route_SUS             149u
#define VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq             150u
#define VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq             151u
#define VDC_FMtTq_RollingCounter_IPDU_COM_VDC_FMtTq             152u
#define VDC_FMtTq_Checksum_IPDU_COM_VDC_FMtTq             153u
#define VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq             154u
#define VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq             155u
#define VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq             156u
#define VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq             157u
#define VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq             158u
#define VDC_RMtTq_RollingCounter_IPDU_COM_VDC_RMtTq             159u
#define VDC_RMtTq_Checksum_IPDU_COM_VDC_RMtTq             160u
#define VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt             161u
#define VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt             162u
#define VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt             163u
#define VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt             164u
#define VDC_VehicleStopTime_IPDU_COM_VDC_PTSt             165u
#define VDC_CDCremindReq_IPDU_COM_VDC_PTSt             166u
#define VDC_DrvMod_IPDU_COM_VDC_PTSt             167u
#define VDC_EDCModeSet_IPDU_COM_VDC_PTSt             168u
#define VDC_BMS_SOC_IPDU_COM_VDC_PTSt             169u
#define VDC_HV_State_IPDU_COM_VDC_PTSt             170u
#define VDC_driveReady_IPDU_COM_VDC_PTSt             171u
#define VDC_towMode_IPDU_COM_VDC_PTSt             172u
#define VDC_actualGear_IPDU_COM_VDC_PTSt             173u
#define VDC_actualGearValid_IPDU_COM_VDC_PTSt             174u
#define VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt             175u
#define VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt             176u
#define VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt             177u
#define VDC_AccPedalPosition_IPDU_COM_VDC_PTSt             178u
#define VDC_TotalRang_IPDU_COM_VDC_PTSt             179u
#define VDC_PTSt_RollingCounter_IPDU_COM_VDC_PTSt             180u
#define VDC_PTSt_Checksum_IPDU_COM_VDC_PTSt             181u
#define VDC_LVEM_LoEgyCnsModReq_IPDU_COM_VDC_PTSt             182u
#define ABM_CrashTyp_IPDU_COM_ABM_State             183u

#define COM_GWSOURCESIGNAL_UPDATE_NUMBER           0u
#define COM_ONEEVERYNFILTERSIGNAL_NUMBER           0u
#define COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER    0u

#define COM_GWSIGNAL_BOOLBUFF_SIZE          0u
#define COM_GWSIGNAL_8BITBUFF_SIZE          0u
#define COM_GWSIGNAL_16BITBUFF_SIZE         0u
#define COM_GWSIGNAL_32BITBUFF_SIZE         0u
#define COM_GWSIGNAL_64BITBUFF_SIZE         0u

#define COM_TXGROUPSIGNAL_NUMBER        0u

#define COM_RXGROUPSIGNAL_NUMBER        0u

#define COM_GWMAPPING_NUMBER         0u
#define COM_SOURCE_SIGNAL_NUMBER     0u
#define COM_DST_SIGNAL_NUMBER        0u

#define COM_TXTPPDU_SUPPORT          STD_OFF
#define COM_RXTPPDU_SUPPORT          STD_OFF

#endif

