/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Data.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-03-29 10:48:51>
 */
/*============================================================================*/

/* Rte_Data.c */
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
#include "Rte_Data.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ABSAct_ABSAct;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_AccActPosValid_AccActPosValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_AccCalPosValid_AccCalPosValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_AEBActive_AEBActive;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_BrakePreValid_BrakePreValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_BrakPlgPValid_BrakPlgPValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_BrkPedPressValid_BrkPedPressValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ESCAct_ESCAct;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_HydBrkActTqValid_HydBrkActTqValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccXValid_IMUAccXValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccYValid_IMUAccYValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAglRZValid_IMUAglRZValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqFValid_MTorqFValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqRValid_MTorqRValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_TCSAct_TCSAct;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VCUActGearValid_VCUActGearValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VDCAct_VDCAct;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VSpeedValid_VSpeedValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFLValid_WheelSpdFLValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFRValid_WheelSpdFRValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRLValid_WheelSpdRLValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRRValid_WheelSpdRRValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ABPActive_ABPActive;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_AltitudeValid_AltitudeValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_PushRodActTrvlVld_PushRodActTrvlVld;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VehStopTimeValid_VehStopTimeValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VehWhActTqValid_VehWhActTqValid;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPosInput_HSCMesWheelPosInput = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_HSCStartRoutineFlag_HSCStartRoutineFlag = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_HSCSts_EEM_HSCSts_EEM = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_RelayCtrlState_RelayCtrlState = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ReleaseCtrlState_ReleaseCtrlState = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_Rout_SysLvlAdjust_R_Rout_SysLvlAdjust_CtrlFlag = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ValveFLState_ValveFLState = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ValveFRState_ValveFRState = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ValveResState_ValveResState = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ValveRLState_ValveRLState = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_ValveRRState_ValveRRState = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_Rout_SysLvlAdjust_R_Rout_SysLvlAdjust_TiOut = 0;

Boolean Rte_Buf_UDS_rPort_HSCEna_HSCEna;

Boolean Rte_Buf_UDS_rPort_HSCNVMWrtReq_HSCNVMWrtReq = 0;

Boolean Rte_Buf_UDS_rPort_HSCReq_HSCReq;

Boolean Rte_Buf_UDS_rPort_HSCValid_HSCValidFL = 0;

Boolean Rte_Buf_UDS_rPort_HSCValid_HSCValidFR = 0;

Boolean Rte_Buf_UDS_rPort_HSCValid_HSCValidRL = 0;

Boolean Rte_Buf_UDS_rPort_HSCValid_HSCValidRR = 0;

Boolean Rte_Buf_L9301Ctrl_rPort_RelayCtrl_RelayCtrl;

Boolean Rte_Buf_L9301Ctrl_rPort_ReleaseCtrl_ReleaseCtrl;

Boolean Rte_Buf_L9301Ctrl_rPort_ValveFL_ValveFL;

Boolean Rte_Buf_L9301Ctrl_rPort_ValveFR_ValveFR;

Boolean Rte_Buf_L9301Ctrl_rPort_ValveRes_ValveRes;

Boolean Rte_Buf_L9301Ctrl_rPort_ValveRL_ValveRL;

Boolean Rte_Buf_L9301Ctrl_rPort_ValveRR_ValveRR;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag = 0;

Boolean Rte_Buf_DicTotalModelCDCASV3QR0104_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_BodyAccFLN_BodyAccFLN = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_BodyAccFRN_BodyAccFRN = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_BodyAccRLN_BodyAccRLN = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_ADWheelPosFL_ADWheelPosFL = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_ADWheelPosFR_ADWheelPosFR = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_ADWheelPosRL_ADWheelPosRL = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_ADWheelPosRR_ADWheelPosRR = 0;

Float Irv_DicTotalModelCDCASV3QR0104_HHFL1to10ms = 0;

Float Irv_DicTotalModelCDCASV3QR0104_IRV3 = 0;

Float Irv_DicTotalModelCDCASV3QR0104_IRV6 = 0;

Float Irv_DicTotalModelCDCASV3QR0104_IRV7 = 0;

Float Irv_DicTotalModelCDCASV3QR0104_WheelPosDevto10msFL = 0;

Float Irv_DicTotalModelCDCASV3QR0104_WheelPosDevto10msFR = 0;

Float Irv_DicTotalModelCDCASV3QR0104_WheelPosDevto10msRL = 0;

Float Irv_DicTotalModelCDCASV3QR0104_WheelPosDevto10msRR = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV3 = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV6 = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV7 = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_HHFL1to10ms = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_WheelPosDevto10msFL = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_WheelPosDevto10msFR = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_WheelPosDevto10msRL = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_WheelPosDevto10msRR = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_AccCalPedPos_AccCalPedPos;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_AccPedlActPosn_AccPedlActPosn;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_BattSOC_BattSOC;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_BrkPress_BrkPress;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccX_IMUAccX;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccY_IMUAccY;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAglRZ_IMUAglRZ;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqF_MTorqF;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqR_MTorqR;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_PushRodActTrvl_PushRodActTrvl;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_StrgWhlAng_StrgWhlAng;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_StrgWhlAngGrd_StrgWhlAngGrd;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_VehSpd_VehSpd;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_VehWhActTq_VehWhActTq;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFL_WheelSpdFL;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFR_WheelSpdFR;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRL_WheelSpdRL;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRR_WheelSpdRR;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_AmbieTemp_AmbieTemp;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_AmbieTempValid_AmbieTempValid;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_BattVolt_BattVolt;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_BrakPlgP_BrakPlgP;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_DriveTqDesired_DriveTqDesired;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HydBrkActTq_HydBrkActTq;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_RelHum_RelHum;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_VDCBMSSOC_VDCBMSSOC;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_VDCTotalRange_VDCTotalRange;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosFL = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosFR = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosRL = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosRR = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_PWMFL_PWMFL = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_PWMFR_PWMFR = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_PWMRL_PWMRL = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_PWMRR_PWMRR = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_SysVoltage_SysVoltage = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosFL = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosFR = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosRL = 0;

Float Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosRR = 0;

Float Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL = 0;

Float Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR = 0;

Float Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL = 0;

Float Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV3 = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV6 = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV7 = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_HHFL1to10ms = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_WheelPosDevto10msFL = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_WheelPosDevto10msFR = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_WheelPosDevto10msRL = 0;

Float Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_WheelPosDevto10msRR = 0;

SInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_Altitude_Altitude;

UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeYear_TimeYear;

UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_VehStopTime_VehStopTime;

UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_ADCurrentFL_ADCurrentFL = 0;

UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_ADCurrentFR_ADCurrentFR = 0;

UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_ADCurrentRL_ADCurrentRL = 0;

UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_ADCurrentRR_ADCurrentRR = 0;

UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_PreVol_PreVol = 0;

UInt16 Rte_Buf_DicTotalModelCDCASV3QR0104_TempVol_TempVol = 0;

UInt16 Rte_Buf_L9305Ctrl_rPort_CommdCurrentFL_CommdCurrentFL;

UInt16 Rte_Buf_L9305Ctrl_rPort_CommdCurrentFR_CommdCurrentFR;

UInt16 Rte_Buf_L9305Ctrl_rPort_CommdCurrentRL_CommdCurrentRL;

UInt16 Rte_Buf_L9305Ctrl_rPort_CommdCurrentRR_CommdCurrentRR;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_CarMode_CarMode;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_ChargCapSts_ChargCapSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_ChrgGunCCSts_ChrgGunCCSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_DCChrgConnectSt_DCChrgConnectSt;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorLockSts_DrivDoorLockSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorSts_DrivDoorSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_EPBActSt_EPBActSt;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_HoodSts_HoodSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_MaintMode_MaintMode;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_PassgDoorLockSts_PassgDoorLockSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_PassgDoorSts_PassgDoorSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_RLDoorLockSts_RLDoorLockSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_RLDoorSts_RLDoorSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_RRDoorLockSts_RRDoorLockSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_RRDoorSts_RRDoorSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_StrWhAngSpdValid_StrWhAngSpdValid;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_StrWhAngValid_StrWhAngValid;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TailGateLockSts_TailGateLockSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TailGateSts_TailGateSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VCUActGear_VCUActGear;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCPowerMode_VDCPowerMode;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCtowerMode_VDCtowerMode;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VehDampModReq_VehDampModReq;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VehLvlCtrModReq_VehLvlCtrModReq;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_ADSSuspSts_ADSSuspSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_AutoEasyEntrySet_AutoEasyEntrySet;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_BrkPedPress_BrkPedPress;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_ChargCapLockSts_ChargCapLockSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorLockStsValid_DrivDoorLockStsValid;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorStsValid_DrivDoorStsValid;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_ECASFuncLimit_ECASFuncLimit;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_EPBDynBrkgSt_EPBDynBrkgSt;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_HighwayModset_HighwayModset;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_HoodLockSts_HoodLockSts;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeDay_TimeDay;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeFlag_TimeFlag;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeHour_TimeHour;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeMinute_TimeMinute;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeMonth_TimeMonth;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeSecond_TimeSecond;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeZone_TimeZone;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_TimeZoneNum_TimeZoneNum;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_UsageMode_UsageMode;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCDriveMode_VDCDriveMode;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCDriveReady_VDCDriveReady;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCHVState_VDCHVState;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VDCRedReq_VDCRedReq;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_CDCMemMode_CDCMemMode = 0;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_HSCNVMWrtSts_HSCNVMWrtSts = 0;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_KL15State_KL15State = 0;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_Rout_SysLvlAdjust_R_Rout_SysLvlAdjust_TarLvl = 0;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_VehLvlMemMod_VehLvlMemMod = 0;

UInt8 Rte_Buf_UDS_rPort_CDCCurrentMode_CDCCurrentMode;

UInt8 Rte_Buf_EnviroMonitor_rPort_HeightAdjFin_HeightAdjFin;

UInt8 Rte_Buf_UDS_rPort_HSCRoutineStage_HSCRoutineStage = 0;

UInt8 Rte_Buf_UDS_rPort_HSCRoutineSts_HSCRoutineSts = 0;

UInt8 Rte_Buf_UDS_rPort_VehTarPosnSt_VehTarPosnSt;

UInt8 Rte_Buf_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_ExtSts = 0;

UInt8 Rte_Buf_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_FailRasn = 0;

UInt8 Rte_Buf_DicTotalModelCDCASV3QR0104_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl = 0;

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_IRV10 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_IRV11 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_IRV8 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_IRV9 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV8 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV9 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV10 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step_WRITE_IRV11 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV8 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV9 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV10 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_10 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV11 = {0,0,0,0,0,0,0,0,0,0};

rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_IRV1 = {0,0,0,0,0};

rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_IRV2 = {0,0,0,0,0};

rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_IRV4 = {0,0,0,0,0};

rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step1_WRITE_IRV1 = {0,0,0,0,0};

rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step1_WRITE_IRV2 = {0,0,0,0,0};

rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step1_WRITE_IRV4 = {0,0,0,0,0};

rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV1 = {0,0,0,0,0};

rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV2 = {0,0,0,0,0};

rt_Array_Float_5 Irv_DicTotalModelCDCASV3QR0104_Runnable_Step2_READ_IRV4 = {0,0,0,0,0};

#define RTE_START_SEC_VAR_NO_INIT_8
#include "RTE_MemMap.h"

Std_ReturnType Rte_Status_VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_RRDoorSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_HoodLockSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_ABM_IMU_YawRateValid_IPDU_COM_ABM_State = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_BMS_SOC_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS = RTE_E_OK;

Std_ReturnType Rte_Status_RSM_RelHum_IPDU_COM_VIU_Route_SUS = RTE_E_OK;

Std_ReturnType Rte_Status_LBMS_SOC_IPDU_COM_VIU_Route_SUS = RTE_E_OK;

Std_ReturnType Rte_Status_ABM_IMU_YawRate_IPDU_COM_ABM_State = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_VDCActive_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_PushRodActTrvl_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_HydBrkActvTq_IPDU_COM_IPB_Tq = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_towMode_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo = RTE_E_OK;

Std_ReturnType Rte_Status_EPS_SteerWheelAngleValid_IPDU_COM_EPS_State = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_PassDoorSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_HV_State_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_ABSActive_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_ABM_IMU_LateralAccValid_IPDU_COM_ABM_State = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_CarMode_IPDU_COM_VIU_Info = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_ABPActive_IPDU_COM_IPB_ADS = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_TailgateSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_RLDoorSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_PlungerPressureValid_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_UsageMode_IPDU_COM_VIU_Info = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_EDCModeSet_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_TotalRang_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_driveReady_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_AEBActive_IPDU_COM_IPB_ADS = RTE_E_OK;

Std_ReturnType Rte_Status_OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_SimulatorPressure_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel = RTE_E_OK;

Std_ReturnType Rte_Status_EPS_SteerWheelAngle_IPDU_COM_EPS_State = RTE_E_OK;

Std_ReturnType Rte_Status_EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_PlungerPressure_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq = RTE_E_OK;

Std_ReturnType Rte_Status_EPB_ActrSt_IPDU_COM_EPB_State_R = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_HoodSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_VehicleSpeed_IPDU_COM_IPB_Wheel = RTE_E_OK;

Std_ReturnType Rte_Status_ECAS_CarModFb_IPDU_COM_ECAS_State = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_SimulatorPressureValid_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_ABM_IMU_LongAcceleration_IPDU_COM_ABM_State = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_VehicleStopTime_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_AccPedalPosition_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_DrvMod_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_actualGearValid_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_PowerMode_IPDU_COM_VIU_Info = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_actualGear_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_CDCremindReq_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_ADS_SuspensionStatus_IPDU_COM_ADS_State = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_ESCActive_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel = RTE_E_OK;

Std_ReturnType Rte_Status_VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_TCSActive_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_BrakePedalPress_IPDU_COM_IPB_State1 = RTE_E_OK;

Std_ReturnType Rte_Status_EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock = RTE_E_OK;

Std_ReturnType Rte_Status_LBMS_PackExtU_IPDU_COM_VIU_Route_SUS = RTE_E_OK;

Std_ReturnType Rte_Status_IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq = RTE_E_OK;

#define RTE_STOP_SEC_VAR_NO_INIT_8
#include "RTE_MemMap.h"

void rte_memcpy(uint8 * pDest, const uint8 * pSrc, uint32 length)
{
    while (length--)
    {
        *pDest++ = *pSrc++;
    }
}

