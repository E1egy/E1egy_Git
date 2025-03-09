/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Data.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-03-29 10:48:53>
 */
/*============================================================================*/

/* Rte_Data.h */

#ifndef RTE_DATA_H
#define RTE_DATA_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte_Type.h"

static inline void Rte_DataInit(void * data,uint32 Length)
{
    uint32 i;
    uint8* pBuf = (uint8*)data;
    for (i = 0; i < Length; i++)
    {
        pBuf[i] = 0;
    }
}

/*******************************************************************************
 **                        Global Variable Declarations                       **
******************************************************************************/

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ABSAct_ABSAct;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_AccActPosValid_AccActPosValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_AccCalPosValid_AccCalPosValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_AEBActive_AEBActive;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_BrakePreValid_BrakePreValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_BrakPlgPValid_BrakPlgPValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_BrkPedPressValid_BrkPedPressValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ESCAct_ESCAct;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_HydBrkActTqValid_HydBrkActTqValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccXValid_IMUAccXValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccYValid_IMUAccYValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAglRZValid_IMUAglRZValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqFValid_MTorqFValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqRValid_MTorqRValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_TCSAct_TCSAct;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VCUActGearValid_VCUActGearValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VDCAct_VDCAct;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VSpeedValid_VSpeedValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFLValid_WheelSpdFLValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFRValid_WheelSpdFRValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRLValid_WheelSpdRLValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRRValid_WheelSpdRRValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ABPActive_ABPActive;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_AltitudeValid_AltitudeValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_PushRodActTrvlVld_PushRodActTrvlVld;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VehStopTimeValid_VehStopTimeValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VehWhActTqValid_VehWhActTqValid;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPosInput_HSCMesWheelPosInput;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_HSCStartRoutineFlag_HSCStartRoutineFlag;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_HSCSts_EEM_HSCSts_EEM;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_RelayCtrlState_RelayCtrlState;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ReleaseCtrlState_ReleaseCtrlState;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_Rout_SysLvlAdjust_R_Rout_SysLvlAdjust_CtrlFlag;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ValveFLState_ValveFLState;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ValveFRState_ValveFRState;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ValveResState_ValveResState;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ValveRLState_ValveRLState;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ValveRRState_ValveRRState;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_Rout_SysLvlAdjust_R_Rout_SysLvlAdjust_TiOut;

extern Boolean Rte_Buf_UDS_rPort_HSCEna_HSCEna;

extern Boolean Rte_Buf_UDS_rPort_HSCNVMWrtReq_HSCNVMWrtReq;

extern Boolean Rte_Buf_UDS_rPort_HSCReq_HSCReq;

extern Boolean Rte_Buf_UDS_rPort_HSCValid_HSCValidFL;

extern Boolean Rte_Buf_UDS_rPort_HSCValid_HSCValidFR;

extern Boolean Rte_Buf_UDS_rPort_HSCValid_HSCValidRL;

extern Boolean Rte_Buf_UDS_rPort_HSCValid_HSCValidRR;

extern Boolean Rte_Buf_L9301Ctrl_rPort_RelayCtrl_RelayCtrl;

extern Boolean Rte_Buf_L9301Ctrl_rPort_ReleaseCtrl_ReleaseCtrl;

extern Boolean Rte_Buf_L9301Ctrl_rPort_ValveFL_ValveFL;

extern Boolean Rte_Buf_L9301Ctrl_rPort_ValveFR_ValveFR;

extern Boolean Rte_Buf_L9301Ctrl_rPort_ValveRes_ValveRes;

extern Boolean Rte_Buf_L9301Ctrl_rPort_ValveRL_ValveRL;

extern Boolean Rte_Buf_L9301Ctrl_rPort_ValveRR_ValveRR;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag;

extern Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_BodyAccFLN_BodyAccFLN;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_BodyAccFRN_BodyAccFRN;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_BodyAccRLN_BodyAccRLN;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_ADWheelPosFL_ADWheelPosFL;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_ADWheelPosFR_ADWheelPosFR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_ADWheelPosRL_ADWheelPosRL;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_ADWheelPosRR_ADWheelPosRR;

extern Float Irv_DicTotalModelCDCASV3QR0104_HHFL1to10ms;

extern Float Irv_DicTotalModelCDCASV3QR0104_IRV3;

extern Float Irv_DicTotalModelCDCASV3QR0104_IRV6;

extern Float Irv_DicTotalModelCDCASV3QR0104_IRV7;

extern Float Irv_DicTotalModelCDCASV3QR0104_WheelPosDevto10msFL;

extern Float Irv_DicTotalModelCDCASV3QR0104_WheelPosDevto10msFR;

extern Float Irv_DicTotalModelCDCASV3QR0104_WheelPosDevto10msRL;

extern Float Irv_DicTotalModelCDCASV3QR0104_WheelPosDevto10msRR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV3;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV6;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV7;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_HHFL1to10ms;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_WheelPosDevto10msFL;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_WheelPosDevto10msFR;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_WheelPosDevto10msRL;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_WheelPosDevto10msRR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_AccCalPedPos_AccCalPedPos;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_AccPedlActPosn_AccPedlActPosn;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_BattSOC_BattSOC;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_BrkPress_BrkPress;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccX_IMUAccX;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccY_IMUAccY;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAglRZ_IMUAglRZ;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqF_MTorqF;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqR_MTorqR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_PushRodActTrvl_PushRodActTrvl;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_StrgWhlAng_StrgWhlAng;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_StrgWhlAngGrd_StrgWhlAngGrd;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_VehSpd_VehSpd;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_VehWhActTq_VehWhActTq;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFL_WheelSpdFL;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFR_WheelSpdFR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRL_WheelSpdRL;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRR_WheelSpdRR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_AmbieTemp_AmbieTemp;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_AmbieTempValid_AmbieTempValid;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_BattVolt_BattVolt;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_BrakPlgP_BrakPlgP;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_DriveTqDesired_DriveTqDesired;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HydBrkActTq_HydBrkActTq;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_RelHum_RelHum;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_VDCBMSSOC_VDCBMSSOC;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_VDCTotalRange_VDCTotalRange;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosFL;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosFR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosRL;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosRR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_PWMFL_PWMFL;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_PWMFR_PWMFR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_PWMRL_PWMRL;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_PWMRR_PWMRR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_SysVoltage_SysVoltage;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosFL;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosFR;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosRL;

extern Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosRR;

extern Float Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL;

extern Float Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR;

extern Float Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL;

extern Float Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV3;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV6;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV7;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_HHFL1to10ms;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_WheelPosDevto10msFL;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_WheelPosDevto10msFR;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_WheelPosDevto10msRL;

extern Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_WheelPosDevto10msRR;

extern SInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_Altitude_Altitude;

extern UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeYear_TimeYear;

extern UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_VehStopTime_VehStopTime;

extern UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_ADCurrentFL_ADCurrentFL;

extern UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_ADCurrentFR_ADCurrentFR;

extern UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_ADCurrentRL_ADCurrentRL;

extern UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_ADCurrentRR_ADCurrentRR;

extern UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_PreVol_PreVol;

extern UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_TempVol_TempVol;

extern UInt16 Rte_Buf_L9305Ctrl_rPort_CommdCurrentFL_CommdCurrentFL;

extern UInt16 Rte_Buf_L9305Ctrl_rPort_CommdCurrentFR_CommdCurrentFR;

extern UInt16 Rte_Buf_L9305Ctrl_rPort_CommdCurrentRL_CommdCurrentRL;

extern UInt16 Rte_Buf_L9305Ctrl_rPort_CommdCurrentRR_CommdCurrentRR;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_CarMode_CarMode;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_ChargCapSts_ChargCapSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_ChrgGunCCSts_ChrgGunCCSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_DCChrgConnectSt_DCChrgConnectSt;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorLockSts_DrivDoorLockSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorSts_DrivDoorSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_EPBActSt_EPBActSt;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_HoodSts_HoodSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_MaintMode_MaintMode;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_PassgDoorLockSts_PassgDoorLockSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_PassgDoorSts_PassgDoorSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_RLDoorLockSts_RLDoorLockSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_RLDoorSts_RLDoorSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_RRDoorLockSts_RRDoorLockSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_RRDoorSts_RRDoorSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_StrWhAngSpdValid_StrWhAngSpdValid;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_StrWhAngValid_StrWhAngValid;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TailGateLockSts_TailGateLockSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TailGateSts_TailGateSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VCUActGear_VCUActGear;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCPowerMode_VDCPowerMode;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCtowerMode_VDCtowerMode;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VehDampModReq_VehDampModReq;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VehLvlCtrModReq_VehLvlCtrModReq;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_ADSSuspSts_ADSSuspSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_AutoEasyEntrySet_AutoEasyEntrySet;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_BrkPedPress_BrkPedPress;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_ChargCapLockSts_ChargCapLockSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorLockStsValid_DrivDoorLockStsValid;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorStsValid_DrivDoorStsValid;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_ECASFuncLimit_ECASFuncLimit;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_EPBDynBrkgSt_EPBDynBrkgSt;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_HighwayModset_HighwayModset;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_HoodLockSts_HoodLockSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeDay_TimeDay;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeFlag_TimeFlag;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeHour_TimeHour;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeMinute_TimeMinute;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeMonth_TimeMonth;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeSecond_TimeSecond;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeZone_TimeZone;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeZoneNum_TimeZoneNum;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_UsageMode_UsageMode;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCDriveMode_VDCDriveMode;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCDriveReady_VDCDriveReady;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCHVState_VDCHVState;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCRedReq_VDCRedReq;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_CDCMemMode_CDCMemMode;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_HSCNVMWrtSts_HSCNVMWrtSts;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_KL15State_KL15State;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_Rout_SysLvlAdjust_R_Rout_SysLvlAdjust_TarLvl;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VehLvlMemMod_VehLvlMemMod;

extern UInt8 Rte_Buf_UDS_rPort_CDCCurrentMode_CDCCurrentMode;

extern UInt8 Rte_Buf_EnviroMonitor_rPort_HeightAdjFin_HeightAdjFin;

extern UInt8 Rte_Buf_UDS_rPort_HSCRoutineStage_HSCRoutineStage;

extern UInt8 Rte_Buf_UDS_rPort_HSCRoutineSts_HSCRoutineSts;

extern UInt8 Rte_Buf_UDS_rPort_VehTarPosnSt_VehTarPosnSt;

extern UInt8 Rte_Buf_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_ExtSts;

extern UInt8 Rte_Buf_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_FailRasn;

extern UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_IRV10;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_IRV11;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_IRV8;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_IRV9;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV8;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV9;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV10;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV11;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV8;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV9;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV10;

extern rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV11;

extern rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_IRV1;

extern rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_IRV2;

extern rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_IRV4;

extern rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step1_WRITE_IRV1;

extern rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step1_WRITE_IRV2;

extern rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step1_WRITE_IRV4;

extern rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV1;

extern rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV2;

extern rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV4;

#define RTE_START_SEC_VAR_NO_INIT_8
#include "RTE_MemMap.h"

extern Std_ReturnType Rte_Status_VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_VIU_RRDoorSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_VIU_HoodLockSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_ABM_IMU_YawRateValid_IPDU_COM_ABM_State;

extern Std_ReturnType Rte_Status_VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_VDC_BMS_SOC_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS;

extern Std_ReturnType Rte_Status_RSM_RelHum_IPDU_COM_VIU_Route_SUS;

extern Std_ReturnType Rte_Status_LBMS_SOC_IPDU_COM_VIU_Route_SUS;

extern Std_ReturnType Rte_Status_ABM_IMU_YawRate_IPDU_COM_ABM_State;

extern Std_ReturnType Rte_Status_VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_IPB_VDCActive_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_IPB_PushRodActTrvl_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_IPB_HydBrkActvTq_IPDU_COM_IPB_Tq;

extern Std_ReturnType Rte_Status_TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo;

extern Std_ReturnType Rte_Status_VDC_towMode_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo;

extern Std_ReturnType Rte_Status_EPS_SteerWheelAngleValid_IPDU_COM_EPS_State;

extern Std_ReturnType Rte_Status_VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq;

extern Std_ReturnType Rte_Status_VIU_PassDoorSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo;

extern Std_ReturnType Rte_Status_VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq;

extern Std_ReturnType Rte_Status_VDC_HV_State_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_IPB_ABSActive_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_ABM_IMU_LateralAccValid_IPDU_COM_ABM_State;

extern Std_ReturnType Rte_Status_VIU_CarMode_IPDU_COM_VIU_Info;

extern Std_ReturnType Rte_Status_TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo;

extern Std_ReturnType Rte_Status_VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo;

extern Std_ReturnType Rte_Status_IPB_ABPActive_IPDU_COM_IPB_ADS;

extern Std_ReturnType Rte_Status_VIU_TailgateSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State;

extern Std_ReturnType Rte_Status_VIU_RLDoorSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo;

extern Std_ReturnType Rte_Status_VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State;

extern Std_ReturnType Rte_Status_VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet;

extern Std_ReturnType Rte_Status_IPB_PlungerPressureValid_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_VIU_UsageMode_IPDU_COM_VIU_Info;

extern Std_ReturnType Rte_Status_VDC_EDCModeSet_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel;

extern Std_ReturnType Rte_Status_VDC_TotalRang_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq;

extern Std_ReturnType Rte_Status_VDC_driveReady_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_IPB_AEBActive_IPDU_COM_IPB_ADS;

extern Std_ReturnType Rte_Status_OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS;

extern Std_ReturnType Rte_Status_IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel;

extern Std_ReturnType Rte_Status_IPB_SimulatorPressure_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State;

extern Std_ReturnType Rte_Status_IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel;

extern Std_ReturnType Rte_Status_EPS_SteerWheelAngle_IPDU_COM_EPS_State;

extern Std_ReturnType Rte_Status_EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State;

extern Std_ReturnType Rte_Status_VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq;

extern Std_ReturnType Rte_Status_IPB_PlungerPressure_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel;

extern Std_ReturnType Rte_Status_VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet;

extern Std_ReturnType Rte_Status_IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel;

extern Std_ReturnType Rte_Status_VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq;

extern Std_ReturnType Rte_Status_EPB_ActrSt_IPDU_COM_EPB_State_R;

extern Std_ReturnType Rte_Status_IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel;

extern Std_ReturnType Rte_Status_VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo;

extern Std_ReturnType Rte_Status_VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_VIU_HoodSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo;

extern Std_ReturnType Rte_Status_VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo;

extern Std_ReturnType Rte_Status_IPB_VehicleSpeed_IPDU_COM_IPB_Wheel;

extern Std_ReturnType Rte_Status_ECAS_CarModFb_IPDU_COM_ECAS_State;

extern Std_ReturnType Rte_Status_TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo;

extern Std_ReturnType Rte_Status_VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_IPB_SimulatorPressureValid_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_ABM_IMU_LongAcceleration_IPDU_COM_ABM_State;

extern Std_ReturnType Rte_Status_VDC_VehicleStopTime_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_VDC_AccPedalPosition_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo;

extern Std_ReturnType Rte_Status_TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo;

extern Std_ReturnType Rte_Status_VDC_DrvMod_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_VDC_actualGearValid_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_VIU_PowerMode_IPDU_COM_VIU_Info;

extern Std_ReturnType Rte_Status_VDC_actualGear_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_VDC_CDCremindReq_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel;

extern Std_ReturnType Rte_Status_VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo;

extern Std_ReturnType Rte_Status_IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel;

extern Std_ReturnType Rte_Status_VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_ADS_SuspensionStatus_IPDU_COM_ADS_State;

extern Std_ReturnType Rte_Status_VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq;

extern Std_ReturnType Rte_Status_VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq;

extern Std_ReturnType Rte_Status_IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_IPB_ESCActive_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel;

extern Std_ReturnType Rte_Status_VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt;

extern Std_ReturnType Rte_Status_IPB_TCSActive_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_IPB_BrakePedalPress_IPDU_COM_IPB_State1;

extern Std_ReturnType Rte_Status_EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R;

extern Std_ReturnType Rte_Status_VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock;

extern Std_ReturnType Rte_Status_LBMS_PackExtU_IPDU_COM_VIU_Route_SUS;

extern Std_ReturnType Rte_Status_IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq;

#define RTE_STOP_SEC_VAR_NO_INIT_8
#include "RTE_MemMap.h"

void rte_memcpy(uint8 * pDest, const uint8 * pSrc, uint32 length);

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

#endif

