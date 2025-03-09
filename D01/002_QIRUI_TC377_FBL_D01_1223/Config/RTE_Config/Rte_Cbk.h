/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Cbk.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-03-29 10:48:52>
 */
/*============================================================================*/

/* Rte_Cbk.h */

#ifndef RTE_CBK_H
#define RTE_CBK_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Os.h"
#include "Com.h"
#include "Rte_Data.h"

/*******************************************************************************
 **                        Global Function Definitions                        **
******************************************************************************/
extern boolean Rx_Flag_Byte0_bit0_ABM_State;
extern boolean Rx_Flag_Byte0_bit1_EPB_State_R;
extern boolean Rx_Flag_Byte0_bit2_EPS_State;
extern boolean Rx_Flag_Byte0_bit3_IPB_Wheel;
extern boolean Rx_Flag_Byte0_bit4_ADS_State;
extern boolean Rx_Flag_Byte0_bit5_TBOX_TimeInfo;
extern boolean Rx_Flag_Byte0_bit6_VIU_Info;
extern boolean DTC_FlagAccPedlActPosn_RangeOut;

void Rte_COMCbk_VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_VIU_RRDoorSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_VIU_HoodLockSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_ABM_IMU_YawRateValid_IPDU_COM_ABM_State(void);

void Rte_COMCbk_VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_VDC_BMS_SOC_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS(void);

void Rte_COMCbk_RSM_RelHum_IPDU_COM_VIU_Route_SUS(void);

void Rte_COMCbk_LBMS_SOC_IPDU_COM_VIU_Route_SUS(void);

void Rte_COMCbk_ABM_IMU_YawRate_IPDU_COM_ABM_State(void);

void Rte_COMCbkRxTOut_ABM_IMU_YawRate_IPDU_COM_ABM_State(void);

void Rte_COMCbk_VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_IPB_VDCActive_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_IPB_PushRodActTrvl_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_IPB_HydBrkActvTq_IPDU_COM_IPB_Tq(void);

void Rte_COMCbk_TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo(void);

void Rte_COMCbk_VDC_towMode_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo(void);

void Rte_COMCbk_EPS_SteerWheelAngleValid_IPDU_COM_EPS_State(void);

void Rte_COMCbk_VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq(void);

void Rte_COMCbk_VIU_PassDoorSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo(void);

void Rte_COMCbk_VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq(void);

void Rte_COMCbk_VDC_HV_State_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_IPB_ABSActive_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_ABM_IMU_LateralAccValid_IPDU_COM_ABM_State(void);

void Rte_COMCbk_VIU_CarMode_IPDU_COM_VIU_Info(void);

void Rte_COMCbkRxTOut_VIU_CarMode_IPDU_COM_VIU_Info(void);

void Rte_COMCbk_TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo(void);

void Rte_COMCbkRxTOut_TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo(void);

void Rte_COMCbk_VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo(void);

void Rte_COMCbk_IPB_ABPActive_IPDU_COM_IPB_ADS(void);

void Rte_COMCbk_VIU_TailgateSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State(void);

void Rte_COMCbk_VIU_RLDoorSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo(void);

void Rte_COMCbk_VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State(void);

void Rte_COMCbk_VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet(void);

void Rte_COMCbk_IPB_PlungerPressureValid_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_VIU_UsageMode_IPDU_COM_VIU_Info(void);

void Rte_COMCbk_VDC_EDCModeSet_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbk_VDC_TotalRang_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq(void);

void Rte_COMCbk_VDC_driveReady_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_IPB_AEBActive_IPDU_COM_IPB_ADS(void);

void Rte_COMCbk_OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS(void);

void Rte_COMCbk_IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbk_IPB_SimulatorPressure_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State(void);

void Rte_COMCbkRxTOut_EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State(void);

void Rte_COMCbk_IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbk_EPS_SteerWheelAngle_IPDU_COM_EPS_State(void);

void Rte_COMCbk_EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State(void);

void Rte_COMCbk_VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq(void);

void Rte_COMCbk_IPB_PlungerPressure_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbk_VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet(void);

void Rte_COMCbk_IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbk_VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq(void);

void Rte_COMCbk_EPB_ActrSt_IPDU_COM_EPB_State_R(void);

void Rte_COMCbkRxTOut_EPB_ActrSt_IPDU_COM_EPB_State_R(void);

void Rte_COMCbk_IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbk_VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo(void);

void Rte_COMCbk_VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_VIU_HoodSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo(void);

void Rte_COMCbk_VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo(void);

void Rte_COMCbk_IPB_VehicleSpeed_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbkRxTOut_IPB_VehicleSpeed_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbkTAck_ECAS_CarModFb_IPDU_COM_ECAS_State(void);

void Rte_COMCbk_TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo(void);

void Rte_COMCbk_VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_IPB_SimulatorPressureValid_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_ABM_IMU_LongAcceleration_IPDU_COM_ABM_State(void);

void Rte_COMCbk_VDC_VehicleStopTime_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_VDC_AccPedalPosition_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo(void);

void Rte_COMCbk_TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo(void);

void Rte_COMCbk_VDC_DrvMod_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_VDC_actualGearValid_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_VIU_PowerMode_IPDU_COM_VIU_Info(void);

void Rte_COMCbk_VDC_actualGear_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_VDC_CDCremindReq_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbk_VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo(void);

void Rte_COMCbk_IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbk_VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_ADS_SuspensionStatus_IPDU_COM_ADS_State(void);

void Rte_COMCbkRxTOut_ADS_SuspensionStatus_IPDU_COM_ADS_State(void);

void Rte_COMCbk_VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq(void);

void Rte_COMCbk_VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq(void);

void Rte_COMCbk_IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_IPB_ESCActive_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel(void);

void Rte_COMCbk_VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt(void);

void Rte_COMCbk_IPB_TCSActive_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_IPB_BrakePedalPress_IPDU_COM_IPB_State1(void);

void Rte_COMCbk_EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R(void);

void Rte_COMCbk_VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock(void);

void Rte_COMCbk_LBMS_PackExtU_IPDU_COM_VIU_Route_SUS(void);

void Rte_COMCbk_IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq(void);

boolean EPB_State_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPB_ADS_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean VIU_DoorLock_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean VIU_Info_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean EPS_State_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean ABM_State_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPB_State1_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPB_Tq_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPB_Wheel_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean ECAS_DV_BA_Req_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean VIU_Config_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean ADS_ECAS_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean ADS_State_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean VDC_CDCSet_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean VDC_VIU_BodyInfo_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean ECAS_State_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean VIU_Route_SUS_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean VDC_FMtTq_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean VDC_RMtTq_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean VDC_PTSt_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

#endif

