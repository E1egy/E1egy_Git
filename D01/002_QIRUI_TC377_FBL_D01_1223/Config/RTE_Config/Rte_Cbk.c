/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Cbk.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-03-29 10:48:51>
 */
/*============================================================================*/

/* Rte_Cbk.c */
/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte_Cbk.h"
#include "Com.h"
#include "PCTest.h"
#include "ReadDTCInformation_0x19.h"
#define E2ESwitch 0x00 /*01 on,00 off*/
/*******************************************************************************
 **                        Global Function                                    **
******************************************************************************/
boolean Rx_Flag_Byte0_bit0_ABM_State = FALSE;
boolean Rx_Flag_Byte0_bit1_EPB_State_R = FALSE;
boolean Rx_Flag_Byte0_bit2_EPS_State = FALSE;
boolean Rx_Flag_Byte0_bit3_IPB_Wheel = FALSE;
boolean Rx_Flag_Byte0_bit4_ADS_State = FALSE;
boolean Rx_Flag_Byte0_bit5_TBOX_TimeInfo = FALSE;
boolean Rx_Flag_Byte0_bit6_VIU_Info = FALSE;
boolean DTC_FlagAccPedlActPosn_RangeOut = 0;
/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock(void)
{
    boolean VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock, &VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_DrvrDoorLockStVld_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorLockStsValid_DrivDoorLockStsValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_RRDoorSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_RRDoorSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_RRDoorSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_RRDoorSt_IPDU_COM_VIU_DoorLock, &VIU_RRDoorSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_RRDoorSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_RRDoorSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_RRDoorSts_RRDoorSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_HoodLockSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_HoodLockSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_HoodLockSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_HoodLockSt_IPDU_COM_VIU_DoorLock, &VIU_HoodLockSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_HoodLockSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_HoodLockSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_HoodLockSts_HoodLockSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1(void)
{
    boolean IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1, &IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1_buf;
        data = 0 + 1 * IPB_BrakePedalPressVaild_IPDU_COM_IPB_State1_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_BrkPedPressValid_BrkPedPressValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_ABM_IMU_YawRateValid_IPDU_COM_ABM_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_ABM_IMU_YawRateValid_IPDU_COM_ABM_State(void)
{
    boolean ABM_IMU_YawRateValid_IPDU_COM_ABM_State_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(ABM_IMU_YawRateValid_IPDU_COM_ABM_State, &ABM_IMU_YawRateValid_IPDU_COM_ABM_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)ABM_IMU_YawRateValid_IPDU_COM_ABM_State_buf;
        data = 0 + 1 * ABM_IMU_YawRateValid_IPDU_COM_ABM_State_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAglRZValid_IMUAglRZValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock, &VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_ChrgCapLockSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_ChargCapLockSts_ChargCapLockSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_BMS_SOC_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_BMS_SOC_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_BMS_SOC_IPDU_COM_VDC_PTSt_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_BMS_SOC_IPDU_COM_VDC_PTSt, &VDC_BMS_SOC_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)VDC_BMS_SOC_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_BMS_SOC_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 255)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VDCBMSSOC_VDCBMSSOC = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS(void)
{
    uint8 BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS, &BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS_buf;
        data = 0 + 1 * BMS_DCChrgConnectSt_IPDU_COM_VIU_Route_SUS_buf;
        if (data >= 0 && data <= 7)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_DCChrgConnectSt_DCChrgConnectSt = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_RSM_RelHum_IPDU_COM_VIU_Route_SUS
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_RSM_RelHum_IPDU_COM_VIU_Route_SUS(void)
{
    uint8 RSM_RelHum_IPDU_COM_VIU_Route_SUS_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(RSM_RelHum_IPDU_COM_VIU_Route_SUS, &RSM_RelHum_IPDU_COM_VIU_Route_SUS_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)RSM_RelHum_IPDU_COM_VIU_Route_SUS_buf;
        data = -0.5 + 0.5 * RSM_RelHum_IPDU_COM_VIU_Route_SUS_buf;
        if (data >= -0.5 && data <= 100)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_RelHum_RelHum = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_LBMS_SOC_IPDU_COM_VIU_Route_SUS
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_LBMS_SOC_IPDU_COM_VIU_Route_SUS(void)
{
    uint8 LBMS_SOC_IPDU_COM_VIU_Route_SUS_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(LBMS_SOC_IPDU_COM_VIU_Route_SUS, &LBMS_SOC_IPDU_COM_VIU_Route_SUS_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)LBMS_SOC_IPDU_COM_VIU_Route_SUS_buf;
        data = 0 + 1 * LBMS_SOC_IPDU_COM_VIU_Route_SUS_buf;
        if (data >= 0 && data <= 100)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_BattSOC_BattSOC = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_ABM_IMU_YawRate_IPDU_COM_ABM_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_ABM_IMU_YawRate_IPDU_COM_ABM_State(void)
{
    uint16 ABM_IMU_YawRate_IPDU_COM_ABM_State_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(ABM_IMU_YawRate_IPDU_COM_ABM_State, &ABM_IMU_YawRate_IPDU_COM_ABM_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)ABM_IMU_YawRate_IPDU_COM_ABM_State_buf;
        data = -300 + 0.01 * ABM_IMU_YawRate_IPDU_COM_ABM_State_buf;
        if (data >= -300 && data <= 355.35)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAglRZ_IMUAglRZ = data;
			Rx_Flag_Byte0_bit0_ABM_State = TRUE;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_ABM_IMU_YawRate_IPDU_COM_ABM_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbkRxTOut_ABM_IMU_YawRate_IPDU_COM_ABM_State(void)
{
    Rx_Flag_Byte0_bit0_ABM_State = FALSE;
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock, &VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_TailgateLockSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TailGateLockSts_TailGateLockSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_VDCActive_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_VDCActive_IPDU_COM_IPB_State1(void)
{
    boolean IPB_VDCActive_IPDU_COM_IPB_State1_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_VDCActive_IPDU_COM_IPB_State1, &IPB_VDCActive_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_VDCActive_IPDU_COM_IPB_State1_buf;
        data = 0 + 1 * IPB_VDCActive_IPDU_COM_IPB_State1_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VDCAct_VDCAct = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_PushRodActTrvl_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_PushRodActTrvl_IPDU_COM_IPB_State1(void)
{
    uint16 IPB_PushRodActTrvl_IPDU_COM_IPB_State1_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_PushRodActTrvl_IPDU_COM_IPB_State1, &IPB_PushRodActTrvl_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)IPB_PushRodActTrvl_IPDU_COM_IPB_State1_buf;
        data = -5 + 0.05 * IPB_PushRodActTrvl_IPDU_COM_IPB_State1_buf;
        if (data >= -5 && data <= 46.15)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_PushRodActTrvl_PushRodActTrvl = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_HydBrkActvTq_IPDU_COM_IPB_Tq
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_HydBrkActvTq_IPDU_COM_IPB_Tq(void)
{
    uint16 IPB_HydBrkActvTq_IPDU_COM_IPB_Tq_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_HydBrkActvTq_IPDU_COM_IPB_Tq, &IPB_HydBrkActvTq_IPDU_COM_IPB_Tq_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)IPB_HydBrkActvTq_IPDU_COM_IPB_Tq_buf;
        data = -32768 + 1 * IPB_HydBrkActvTq_IPDU_COM_IPB_Tq_buf;
        if (data >= -32768 && data <= 32767)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_HydBrkActTq_HydBrkActTq = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo(void)
{
    uint8 TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo, &TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo_buf;
        data = 0 + 1 * TBOX_TimeZoneNum_IPDU_COM_TBOX_TimeInfo_buf;
        if (data >= 0 && data <= 31)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TimeZoneNum_TimeZoneNum = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_towMode_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_towMode_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_towMode_IPDU_COM_VDC_PTSt_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_towMode_IPDU_COM_VDC_PTSt, &VDC_towMode_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_towMode_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_towMode_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VDCtowerMode_VDCtowerMode = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo(void)
{
    uint8 TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo, &TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo_buf;
        data = 0 + 1 * TBOX_TimeHour_IPDU_COM_TBOX_TimeInfo_buf;
        if (data >= 0 && data <= 23)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TimeHour_TimeHour = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_EPS_SteerWheelAngleValid_IPDU_COM_EPS_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_EPS_SteerWheelAngleValid_IPDU_COM_EPS_State(void)
{
    boolean EPS_SteerWheelAngleValid_IPDU_COM_EPS_State_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(EPS_SteerWheelAngleValid_IPDU_COM_EPS_State, &EPS_SteerWheelAngleValid_IPDU_COM_EPS_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)EPS_SteerWheelAngleValid_IPDU_COM_EPS_State_buf;
        data = 0 + 1 * EPS_SteerWheelAngleValid_IPDU_COM_EPS_State_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_StrWhAngValid_StrWhAngValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq(void)
{
    boolean VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq, &VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq_buf;
        data = 0 + 1 * VDC_frontMotorTorquePedValid_IPDU_COM_VDC_FMtTq_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqFValid_MTorqFValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_PassDoorSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_PassDoorSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_PassDoorSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_PassDoorSt_IPDU_COM_VIU_DoorLock, &VIU_PassDoorSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_PassDoorSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_PassDoorSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_PassgDoorSts_PassgDoorSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo(void)
{
    uint8 TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo, &TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo_buf;
        data = 0 + 1 * TBOX_TimeSecond_IPDU_COM_TBOX_TimeInfo_buf;
        if (data >= 0 && data <= 59)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TimeSecond_TimeSecond = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq(void)
{
    uint16 VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq, &VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq_buf;
        data = -32768 + 1 * VDC_VehWhlActTq_IPDU_COM_VDC_RMtTq_buf;
        if (data >= -32768 && data <= 32767)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VehWhActTq_VehWhActTq = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_HV_State_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_HV_State_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_HV_State_IPDU_COM_VDC_PTSt_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_HV_State_IPDU_COM_VDC_PTSt, &VDC_HV_State_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_HV_State_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_HV_State_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 7)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VDCHVState_VDCHVState = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_ABSActive_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_ABSActive_IPDU_COM_IPB_State1(void)
{
    boolean IPB_ABSActive_IPDU_COM_IPB_State1_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_ABSActive_IPDU_COM_IPB_State1, &IPB_ABSActive_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_ABSActive_IPDU_COM_IPB_State1_buf;
        data = 0 + 1 * IPB_ABSActive_IPDU_COM_IPB_State1_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_ABSAct_ABSAct = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_ABM_IMU_LateralAccValid_IPDU_COM_ABM_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_ABM_IMU_LateralAccValid_IPDU_COM_ABM_State(void)
{
    boolean ABM_IMU_LateralAccValid_IPDU_COM_ABM_State_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(ABM_IMU_LateralAccValid_IPDU_COM_ABM_State, &ABM_IMU_LateralAccValid_IPDU_COM_ABM_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)ABM_IMU_LateralAccValid_IPDU_COM_ABM_State_buf;
        data = 0 + 1 * ABM_IMU_LateralAccValid_IPDU_COM_ABM_State_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccYValid_IMUAccYValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_CarMode_IPDU_COM_VIU_Info
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_CarMode_IPDU_COM_VIU_Info(void)
{
    uint8 VIU_CarMode_IPDU_COM_VIU_Info_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_CarMode_IPDU_COM_VIU_Info, &VIU_CarMode_IPDU_COM_VIU_Info_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_CarMode_IPDU_COM_VIU_Info_buf;
        data = 0 + 1 * VIU_CarMode_IPDU_COM_VIU_Info_buf;
        if (data >= 0 && data <= 15)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_CarMode_CarMode = data;
			Rx_Flag_Byte0_bit6_VIU_Info = TRUE;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_VIU_CarMode_IPDU_COM_VIU_Info
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbkRxTOut_VIU_CarMode_IPDU_COM_VIU_Info(void)
{
    Rx_Flag_Byte0_bit6_VIU_Info = FALSE;
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo(void)
{
    uint8 TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo_buf = 0;
    UInt16 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo, &TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt16)TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo_buf;
        data = 2000 + 1 * TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo_buf;
        if (data >= 2000 && data <= 2255)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TimeYear_TimeYear = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbkRxTOut_TBOX_TimeYear_IPDU_COM_TBOX_TimeInfo(void)
{
    Rx_Flag_Byte0_bit5_TBOX_TimeInfo = FALSE;
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt(void)
{
    boolean VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt, &VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_VehicleStopTimeValid_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VehStopTimeValid_VehStopTimeValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo(void)
{
    uint8 TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo, &TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo_buf;
        data = 0 + 1 * TBOX_TimeFlag_IPDU_COM_TBOX_TimeInfo_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TimeFlag_TimeFlag = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_ABPActive_IPDU_COM_IPB_ADS
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_ABPActive_IPDU_COM_IPB_ADS(void)
{
    boolean IPB_ABPActive_IPDU_COM_IPB_ADS_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_ABPActive_IPDU_COM_IPB_ADS, &IPB_ABPActive_IPDU_COM_IPB_ADS_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_ABPActive_IPDU_COM_IPB_ADS_buf;
        data = 0 + 1 * IPB_ABPActive_IPDU_COM_IPB_ADS_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_ABPActive_ABPActive = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_TailgateSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_TailgateSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_TailgateSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_TailgateSt_IPDU_COM_VIU_DoorLock, &VIU_TailgateSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_TailgateSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_TailgateSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 15)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TailGateSts_TailGateSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State(void)
{
    uint16 ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State, &ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State_buf;
        data = -49.05 + 0.01 * ABM_IMU_LateralAcceleration_IPDU_COM_ABM_State_buf;
        if (data >= -49.05 && data <= 114.78)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccY_IMUAccY = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_RLDoorSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_RLDoorSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_RLDoorSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_RLDoorSt_IPDU_COM_VIU_DoorLock, &VIU_RLDoorSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_RLDoorSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_RLDoorSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_RLDoorSts_RLDoorSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt(void)
{
    uint16 VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt, &VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 0.1 * VDC_AccPedalActualPosition_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 102.3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_AccCalPedPos_AccCalPedPos = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo(void)
{
    uint8 TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo, &TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo_buf;
        data = 0 + 1 * TBOX_TimeZone_IPDU_COM_TBOX_TimeInfo_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TimeZone_TimeZone = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt, &VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_ECASMaintenanceMode_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_MaintMode_MaintMode = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State(void)
{
    boolean ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State, &ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State_buf;
        data = 0 + 1 * ABM_IMU_LongAccelerationValid_IPDU_COM_ABM_State_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccXValid_IMUAccXValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet(void)
{
    uint8 VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet, &VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet_buf;
        data = 0 + 1 * VDC_CDC_HighwayModset_IPDU_COM_VDC_CDCSet_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_HighwayModset_HighwayModset = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_PlungerPressureValid_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_PlungerPressureValid_IPDU_COM_IPB_State1(void)
{
    boolean IPB_PlungerPressureValid_IPDU_COM_IPB_State1_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_PlungerPressureValid_IPDU_COM_IPB_State1, &IPB_PlungerPressureValid_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_PlungerPressureValid_IPDU_COM_IPB_State1_buf;
        data = 0 + 1 * IPB_PlungerPressureValid_IPDU_COM_IPB_State1_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_BrakPlgPValid_BrakPlgPValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_UsageMode_IPDU_COM_VIU_Info
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_UsageMode_IPDU_COM_VIU_Info(void)
{
    uint8 VIU_UsageMode_IPDU_COM_VIU_Info_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_UsageMode_IPDU_COM_VIU_Info, &VIU_UsageMode_IPDU_COM_VIU_Info_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_UsageMode_IPDU_COM_VIU_Info_buf;
        data = 0 + 1 * VIU_UsageMode_IPDU_COM_VIU_Info_buf;
        if (data >= 0 && data <= 15)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_UsageMode_UsageMode = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_EDCModeSet_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_EDCModeSet_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_EDCModeSet_IPDU_COM_VDC_PTSt_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_EDCModeSet_IPDU_COM_VDC_PTSt, &VDC_EDCModeSet_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_EDCModeSet_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_EDCModeSet_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 7)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VehDampModReq_VehDampModReq = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt(void)
{
    boolean VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt, &VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_AccPedalPositionValid_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_AccActPosValid_AccActPosValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel(void)
{
    boolean IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel, &IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel_buf;
        data = 0 + 1 * IPB_WheelSpeedFLValid_IPDU_COM_IPB_Wheel_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFLValid_WheelSpdFLValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_TotalRang_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_TotalRang_IPDU_COM_VDC_PTSt(void)
{
    uint32 VDC_TotalRang_IPDU_COM_VDC_PTSt_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_TotalRang_IPDU_COM_VDC_PTSt, &VDC_TotalRang_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)VDC_TotalRang_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_TotalRang_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 1048575)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VDCTotalRange_VDCTotalRange = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq(void)
{
    boolean VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq, &VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq_buf;
        data = 0 + 1 * VDC_VehWhlActTqVld_IPDU_COM_VDC_RMtTq_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VehWhActTqValid_VehWhActTqValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_driveReady_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_driveReady_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_driveReady_IPDU_COM_VDC_PTSt_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_driveReady_IPDU_COM_VDC_PTSt, &VDC_driveReady_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_driveReady_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_driveReady_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VDCDriveReady_VDCDriveReady = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_AEBActive_IPDU_COM_IPB_ADS
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_AEBActive_IPDU_COM_IPB_ADS(void)
{
    boolean IPB_AEBActive_IPDU_COM_IPB_ADS_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_AEBActive_IPDU_COM_IPB_ADS, &IPB_AEBActive_IPDU_COM_IPB_ADS_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_AEBActive_IPDU_COM_IPB_ADS_buf;
        data = 0 + 1 * IPB_AEBActive_IPDU_COM_IPB_ADS_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_AEBActive_AEBActive = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS(void)
{
    uint8 OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS, &OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS_buf;
        data = 0 + 1 * OBC_ChrgGunCCSts_IPDU_COM_VIU_Route_SUS_buf;
        if (data >= 0 && data <= 7)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_ChrgGunCCSts_ChrgGunCCSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel(void)
{
    boolean IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel, &IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel_buf;
        data = 0 + 1 * IPB_WheelSpeedRRValid_IPDU_COM_IPB_Wheel_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRRValid_WheelSpdRRValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_SimulatorPressure_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_SimulatorPressure_IPDU_COM_IPB_State1(void)
{
    uint16 IPB_SimulatorPressure_IPDU_COM_IPB_State1_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_SimulatorPressure_IPDU_COM_IPB_State1, &IPB_SimulatorPressure_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)IPB_SimulatorPressure_IPDU_COM_IPB_State1_buf;
        data = -5 + 0.3 * IPB_SimulatorPressure_IPDU_COM_IPB_State1_buf;
        if (data >= -5 && data <= 301.6)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_BrkPress_BrkPress = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State(void)
{
    uint16 EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State, &EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State_buf;
        data = -1024 + 0.1 * EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State_buf;
        if (data >= -1024 && data <= 2252.7)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_StrgWhlAngGrd_StrgWhlAngGrd = data;
			Rx_Flag_Byte0_bit2_EPS_State = TRUE;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbkRxTOut_EPS_SteerWheelAngleSpeed_IPDU_COM_EPS_State(void)
{
    Rx_Flag_Byte0_bit2_EPS_State = FALSE;
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel(void)
{
    uint16 IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel, &IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel_buf;
        data = 0 + 0.05625 * IPB_WheelSpeedRR_IPDU_COM_IPB_Wheel_buf;
        if (data >= 0 && data <= 460.74375)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRR_WheelSpdRR = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_EPS_SteerWheelAngle_IPDU_COM_EPS_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_EPS_SteerWheelAngle_IPDU_COM_EPS_State(void)
{
    uint16 EPS_SteerWheelAngle_IPDU_COM_EPS_State_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(EPS_SteerWheelAngle_IPDU_COM_EPS_State, &EPS_SteerWheelAngle_IPDU_COM_EPS_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)EPS_SteerWheelAngle_IPDU_COM_EPS_State_buf;
        data = -780 + 0.1 * EPS_SteerWheelAngle_IPDU_COM_EPS_State_buf;
        if (data >= -780 && data <= 858.3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_StrgWhlAng_StrgWhlAng = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State(void)
{
    boolean EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State, &EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State_buf;
        data = 0 + 1 * EPS_SteerWheelAngleSpeedValid_IPDU_COM_EPS_State_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_StrWhAngSpdValid_StrWhAngSpdValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock, &VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_RRDoorLockSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_RRDoorLockSts_RRDoorLockSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq(void)
{
    boolean VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq, &VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq_buf;
        data = 0 + 1 * VDC_rearMotorTorquePedValid_IPDU_COM_VDC_RMtTq_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqRValid_MTorqRValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_PlungerPressure_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_PlungerPressure_IPDU_COM_IPB_State1(void)
{
    uint16 IPB_PlungerPressure_IPDU_COM_IPB_State1_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_PlungerPressure_IPDU_COM_IPB_State1, &IPB_PlungerPressure_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)IPB_PlungerPressure_IPDU_COM_IPB_State1_buf;
        data = -5 + 0.3 * IPB_PlungerPressure_IPDU_COM_IPB_State1_buf;
        if (data >= -5 && data <= 301.6)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_BrakPlgP_BrakPlgP = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel(void)
{
    boolean IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel, &IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel_buf;
        data = 0 + 1 * IPB_WheelSpeedRLValid_IPDU_COM_IPB_Wheel_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRLValid_WheelSpdRLValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet(void)
{
    uint8 VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet, &VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet_buf;
        data = 0 + 1 * VDC_CDC_AutoEasyEntrySet_IPDU_COM_VDC_CDCSet_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_AutoEasyEntrySet_AutoEasyEntrySet = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel(void)
{
    uint16 IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel, &IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel_buf;
        data = 0 + 0.05625 * IPB_WheelSpeedRL_IPDU_COM_IPB_Wheel_buf;
        if (data >= 0 && data <= 460.74375)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdRL_WheelSpdRL = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq(void)
{
    uint16 VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq, &VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq_buf;
        data = -5000 + 1 * VDC_rearMotorTorquePed_IPDU_COM_VDC_RMtTq_buf;
        if (data >= -5000 && data <= 11383)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqR_MTorqR = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_EPB_ActrSt_IPDU_COM_EPB_State_R
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_EPB_ActrSt_IPDU_COM_EPB_State_R(void)
{
    uint8 EPB_ActrSt_IPDU_COM_EPB_State_R_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(EPB_ActrSt_IPDU_COM_EPB_State_R, &EPB_ActrSt_IPDU_COM_EPB_State_R_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)EPB_ActrSt_IPDU_COM_EPB_State_R_buf;
        data = 0 + 1 * EPB_ActrSt_IPDU_COM_EPB_State_R_buf;
        if (data >= 0 && data <= 7)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_EPBActSt_EPBActSt = data;
			Rx_Flag_Byte0_bit1_EPB_State_R = TRUE;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_EPB_ActrSt_IPDU_COM_EPB_State_R
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbkRxTOut_EPB_ActrSt_IPDU_COM_EPB_State_R(void)
{
    Rx_Flag_Byte0_bit1_EPB_State_R = FALSE;
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel(void)
{
    boolean IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel, &IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel_buf;
        data = 0 + 1 * IPB_VehicleSpeedValid_IPDU_COM_IPB_Wheel_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VSpeedValid_VSpeedValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo(void)
{
    uint8 VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo, &VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo_buf;
        data = -40 + 0.5 * VDC_AmbT_IPDU_COM_VDC_VIU_BodyInfo_buf;
        if (data >= -40 && data <= 87)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_AmbieTemp_AmbieTemp = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt(void)
{
    boolean VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt, &VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_AccPedalAcPositionValid_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_AccCalPosValid_AccCalPosValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_HoodSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_HoodSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_HoodSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_HoodSt_IPDU_COM_VIU_DoorLock, &VIU_HoodSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_HoodSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_HoodSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_HoodSts_HoodSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo(void)
{
    boolean TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo, &TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo_buf;
        data = 0 + 1 * TBOX_AltitudeValid_IPDU_COM_VDC_VIU_BodyInfo_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_AltitudeValid_AltitudeValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo(void)
{
    boolean VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo, &VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo_buf;
        data = 0 + 1 * VDC_AmbTVld_IPDU_COM_VDC_VIU_BodyInfo_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_AmbieTempValid_AmbieTempValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_VehicleSpeed_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_VehicleSpeed_IPDU_COM_IPB_Wheel(void)
{
    uint16 IPB_VehicleSpeed_IPDU_COM_IPB_Wheel_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_VehicleSpeed_IPDU_COM_IPB_Wheel, &IPB_VehicleSpeed_IPDU_COM_IPB_Wheel_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)IPB_VehicleSpeed_IPDU_COM_IPB_Wheel_buf;
        data = 0 + 0.05625 * IPB_VehicleSpeed_IPDU_COM_IPB_Wheel_buf;
        if (data >= 0 && data <= 460.74375)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VehSpd_VehSpd = data;
			Rx_Flag_Byte0_bit3_IPB_Wheel = TRUE;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_IPB_VehicleSpeed_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbkRxTOut_IPB_VehicleSpeed_IPDU_COM_IPB_Wheel(void)
{
    Rx_Flag_Byte0_bit3_IPB_Wheel = FALSE;
}

/*******************************************************************************
*Function-Name        Rte_COMCbkTAck_ECAS_CarModFb_IPDU_COM_ECAS_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbkTAck_ECAS_CarModFb_IPDU_COM_ECAS_State(void)
{
	SET_DTCBUSOFF_Flag(TRUE);

}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo(void)
{
    uint16 TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo_buf = 0;
    SInt16 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo, &TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (SInt16)TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo_buf;
        data = -50 + 1 * TBOX_Altitude_IPDU_COM_VDC_VIU_BodyInfo_buf;
        if (data >= -50 && data <= 10000)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_Altitude_Altitude = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock, &VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_DrvrDoorSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorSts_DrivDoorSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_SimulatorPressureValid_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_SimulatorPressureValid_IPDU_COM_IPB_State1(void)
{
    boolean IPB_SimulatorPressureValid_IPDU_COM_IPB_State1_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_SimulatorPressureValid_IPDU_COM_IPB_State1, &IPB_SimulatorPressureValid_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_SimulatorPressureValid_IPDU_COM_IPB_State1_buf;
        data = 0 + 1 * IPB_SimulatorPressureValid_IPDU_COM_IPB_State1_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_BrakePreValid_BrakePreValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_ABM_IMU_LongAcceleration_IPDU_COM_ABM_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_ABM_IMU_LongAcceleration_IPDU_COM_ABM_State(void)
{
    uint16 ABM_IMU_LongAcceleration_IPDU_COM_ABM_State_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(ABM_IMU_LongAcceleration_IPDU_COM_ABM_State, &ABM_IMU_LongAcceleration_IPDU_COM_ABM_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)ABM_IMU_LongAcceleration_IPDU_COM_ABM_State_buf;
        data = -49.05 + 0.01 * ABM_IMU_LongAcceleration_IPDU_COM_ABM_State_buf;
        if (data >= -49.05 && data <= 114.78)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_IMUAccX_IMUAccX = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_VehicleStopTime_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_VehicleStopTime_IPDU_COM_VDC_PTSt(void)
{
    uint16 VDC_VehicleStopTime_IPDU_COM_VDC_PTSt_buf = 0;
    UInt16 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_VehicleStopTime_IPDU_COM_VDC_PTSt, &VDC_VehicleStopTime_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt16)VDC_VehicleStopTime_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_VehicleStopTime_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 1023)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VehStopTime_VehStopTime = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_AccPedalPosition_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_AccPedalPosition_IPDU_COM_VDC_PTSt(void)
{
    uint16 VDC_AccPedalPosition_IPDU_COM_VDC_PTSt_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_AccPedalPosition_IPDU_COM_VDC_PTSt, &VDC_AccPedalPosition_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)VDC_AccPedalPosition_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 0.1 * VDC_AccPedalPosition_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 102.3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_AccPedlActPosn_AccPedlActPosn = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo(void)
{
    uint8 TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo, &TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo_buf;
        data = 0 + 1 * TBOX_TimeMinute_IPDU_COM_TBOX_TimeInfo_buf;
        if (data >= 0 && data <= 59)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TimeMinute_TimeMinute = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo(void)
{
    uint8 TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo, &TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo_buf;
        data = 0 + 1 * TBOX_TimeDay_IPDU_COM_TBOX_TimeInfo_buf;
        if (data >= 1 && data <= 31)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TimeDay_TimeDay = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_DrvMod_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_DrvMod_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_DrvMod_IPDU_COM_VDC_PTSt_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_DrvMod_IPDU_COM_VDC_PTSt, &VDC_DrvMod_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_DrvMod_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_DrvMod_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 15)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VDCDriveMode_VDCDriveMode = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_actualGearValid_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_actualGearValid_IPDU_COM_VDC_PTSt(void)
{
    boolean VDC_actualGearValid_IPDU_COM_VDC_PTSt_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_actualGearValid_IPDU_COM_VDC_PTSt, &VDC_actualGearValid_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)VDC_actualGearValid_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_actualGearValid_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VCUActGearValid_VCUActGearValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_PowerMode_IPDU_COM_VIU_Info
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_PowerMode_IPDU_COM_VIU_Info(void)
{
    uint8 VIU_PowerMode_IPDU_COM_VIU_Info_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_PowerMode_IPDU_COM_VIU_Info, &VIU_PowerMode_IPDU_COM_VIU_Info_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_PowerMode_IPDU_COM_VIU_Info_buf;
        data = 0 + 1 * VIU_PowerMode_IPDU_COM_VIU_Info_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VDCPowerMode_VDCPowerMode = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_actualGear_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_actualGear_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_actualGear_IPDU_COM_VDC_PTSt_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_actualGear_IPDU_COM_VDC_PTSt, &VDC_actualGear_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_actualGear_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_actualGear_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VCUActGear_VCUActGear = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_CDCremindReq_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_CDCremindReq_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_CDCremindReq_IPDU_COM_VDC_PTSt_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_CDCremindReq_IPDU_COM_VDC_PTSt, &VDC_CDCremindReq_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_CDCremindReq_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_CDCremindReq_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 7)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VDCRedReq_VDCRedReq = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel(void)
{
    boolean IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel, &IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel_buf;
        data = 0 + 1 * IPB_WheelSpeedFRValid_IPDU_COM_IPB_Wheel_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFRValid_WheelSpdFRValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt, &VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_ECASFuncLimit_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_ECASFuncLimit_ECASFuncLimit = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo(void)
{
    uint8 TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo, &TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo_buf;
        data = 0 + 1 * TBOX_TimeMonth_IPDU_COM_TBOX_TimeInfo_buf;
        if (data >= 1 && data <= 12)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TimeMonth_TimeMonth = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel(void)
{
    uint16 IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel, &IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel_buf;
        data = 0 + 0.05625 * IPB_WheelSpeedFR_IPDU_COM_IPB_Wheel_buf;
        if (data >= 0 && data <= 460.74375)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFR_WheelSpdFR = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock, &VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_DrvrDoorLockSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorLockSts_DrivDoorLockSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock, &VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_ChrgCapSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_ChargCapSts_ChargCapSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_ADS_SuspensionStatus_IPDU_COM_ADS_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_ADS_SuspensionStatus_IPDU_COM_ADS_State(void)
{
    uint8 ADS_SuspensionStatus_IPDU_COM_ADS_State_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(ADS_SuspensionStatus_IPDU_COM_ADS_State, &ADS_SuspensionStatus_IPDU_COM_ADS_State_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)ADS_SuspensionStatus_IPDU_COM_ADS_State_buf;
        data = 0 + 1 * ADS_SuspensionStatus_IPDU_COM_ADS_State_buf;
        if (data >= 0 && data <= 7)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_ADSSuspSts_ADSSuspSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbkRxTOut_ADS_SuspensionStatus_IPDU_COM_ADS_State
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbkRxTOut_ADS_SuspensionStatus_IPDU_COM_ADS_State(void)
{
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq(void)
{
    uint16 VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq, &VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq_buf;
        data = -5000 + 1 * VDC_frontMotorTorquePed_IPDU_COM_VDC_FMtTq_buf;
        if (data >= -5000 && data <= 11383)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_MTorqF_MTorqF = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq(void)
{
    uint16 VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq, &VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq_buf;
        data = -32768 + 1 * VDC_DriverTorqueDesired_IPDU_COM_VDC_RMtTq_buf;
        if (data >= -32768 && data <= 32767)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_DriveTqDesired_DriveTqDesired = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1(void)
{
    boolean IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1, &IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1_buf;
        data = 0 + 1 * IPB_PushRodActTrvlVld_IPDU_COM_IPB_State1_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_PushRodActTrvlVld_PushRodActTrvlVld = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_ESCActive_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_ESCActive_IPDU_COM_IPB_State1(void)
{
    boolean IPB_ESCActive_IPDU_COM_IPB_State1_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_ESCActive_IPDU_COM_IPB_State1, &IPB_ESCActive_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_ESCActive_IPDU_COM_IPB_State1_buf;
        data = 0 + 1 * IPB_ESCActive_IPDU_COM_IPB_State1_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_ESCAct_ESCAct = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock, &VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_PassDoorLockSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_PassgDoorLockSts_PassgDoorLockSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel(void)
{
    uint16 IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel, &IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel_buf;
        data = 0 + 0.05625 * IPB_WheelSpeedFL_IPDU_COM_IPB_Wheel_buf;
        if (data >= 0 && data <= 460.74375)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_WheelSpdFL_WheelSpdFL = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt(void)
{
    uint8 VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt, &VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt_buf;
        data = 0 + 1 * VDC_ECASHeightAdjust_IPDU_COM_VDC_PTSt_buf;
        if (data >= 0 && data <= 7)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_VehLvlCtrModReq_VehLvlCtrModReq = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_TCSActive_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_TCSActive_IPDU_COM_IPB_State1(void)
{
    boolean IPB_TCSActive_IPDU_COM_IPB_State1_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_TCSActive_IPDU_COM_IPB_State1, &IPB_TCSActive_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_TCSActive_IPDU_COM_IPB_State1_buf;
        data = 0 + 1 * IPB_TCSActive_IPDU_COM_IPB_State1_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_TCSAct_TCSAct = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_BrakePedalPress_IPDU_COM_IPB_State1
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_BrakePedalPress_IPDU_COM_IPB_State1(void)
{
    uint8 IPB_BrakePedalPress_IPDU_COM_IPB_State1_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_BrakePedalPress_IPDU_COM_IPB_State1, &IPB_BrakePedalPress_IPDU_COM_IPB_State1_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)IPB_BrakePedalPress_IPDU_COM_IPB_State1_buf;
        data = 0 + 1 * IPB_BrakePedalPress_IPDU_COM_IPB_State1_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_BrkPedPress_BrkPedPress = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R(void)
{
    boolean EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R, &EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R_buf;
        data = 0 + 1 * EPB_Dyn_BrkgSt_IPDU_COM_EPB_State_R_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_EPBDynBrkgSt_EPBDynBrkgSt = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock(void)
{
    uint8 VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock, &VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_RLDoorLockSt_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 3)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_RLDoorLockSts_RLDoorLockSts = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock(void)
{
    boolean VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock_buf = 0;
    UInt8 data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock, &VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (UInt8)VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock_buf;
        data = 0 + 1 * VIU_DrvrDoorStVld_IPDU_COM_VIU_DoorLock_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_DrivDoorStsValid_DrivDoorStsValid = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_LBMS_PackExtU_IPDU_COM_VIU_Route_SUS
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_LBMS_PackExtU_IPDU_COM_VIU_Route_SUS(void)
{
    uint16 LBMS_PackExtU_IPDU_COM_VIU_Route_SUS_buf = 0;
    Float data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(LBMS_PackExtU_IPDU_COM_VIU_Route_SUS, &LBMS_PackExtU_IPDU_COM_VIU_Route_SUS_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Float)LBMS_PackExtU_IPDU_COM_VIU_Route_SUS_buf;
        data = 0 + 0.001 * LBMS_PackExtU_IPDU_COM_VIU_Route_SUS_buf;
        if (data >= 0 && data <= 20)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_BattVolt_BattVolt = data;
        }
    }
}

/*******************************************************************************
*Function-Name        Rte_COMCbk_IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               void
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

void Rte_COMCbk_IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq(void)
{
    boolean IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq_buf = 0;
    Boolean data;
    boolean isSuccess = TRUE;
    Std_ReturnType comStatus;
    comStatus = Com_ReceiveSignal(IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq, &IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq_buf);
    if (comStatus != E_OK)
    {
        isSuccess = FALSE;
    }
    if (isSuccess == TRUE)
    {
        data = (Boolean)IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq_buf;
        data = 0 + 1 * IPB_HydBrkActvTqVld_IPDU_COM_IPB_Tq_buf;
        if (data >= 0 && data <= 1)
        {
            Rte_Buf_DicTotalModelCDCASV3QR0104_HydBrkActTqValid_HydBrkActTqValid = data;
        }
    }
}

boolean EPB_State_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x196_EPB_State(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean IPB_ADS_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[24] = {0};
        uint32 bufferLength = 24;
        uint32 inputBufferLength = 24;
        rettype = E2EXf_Inv_0x195_IPB_ADS(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean VIU_DoorLock_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x2b0_VIU_DoorLock(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif 
}

boolean VIU_Info_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[8] = {0};
        uint32 bufferLength = 8;
        uint32 inputBufferLength = 8;
        rettype = E2EXf_Inv_0x1d2_VIU_Info(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean EPS_State_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x114_EPS_State(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean ABM_State_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[20] = {0};
        uint32 bufferLength = 20;
        uint32 inputBufferLength = 20;
        rettype = E2EXf_Inv_0x119_ABM_State(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean IPB_State1_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x192_IPB_State1(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif 
}

boolean IPB_Tq_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x116_IPB_Tq(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean IPB_Wheel_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x112_IPB_Wheel(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean ECAS_DV_BA_Req_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    uint16 calculate = 0;
    uint8 count = 0;

    if((PduInfoPtr->SduLength == 8)&&(PduInfoPtr->SduDataPtr[0] == 0x55))
    {
    	for(count = 0; count < 7; count++)
        {
            calculate += PduInfoPtr->SduDataPtr[count];
        }

        calculate &= 0xFF;
        if(calculate == PduInfoPtr->SduDataPtr[7])
        {
            SetPcCommandMsg(TRUE,&PduInfoPtr->SduDataPtr[0],7);

        }else
        {
            SetPcCommandMsg(FALSE,&PduInfoPtr->SduDataPtr[0],7);
        }
    }
}

boolean VIU_Config_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x39a_VIU_Config(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean ADS_ECAS_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x134_ADS_ECAS(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif 
}

boolean ADS_State_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x32a_ADS_State(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean VDC_CDCSet_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[8] = {0};
        uint32 bufferLength = 8;
        uint32 inputBufferLength = 8;
        rettype = E2EXf_Inv_0x3f0_VDC_CDCSet(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif 
}

boolean VDC_VIU_BodyInfo_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x3b5_VDC_VIU_BodyInfo(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif 
}

boolean ECAS_State_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[24] = {0};
        uint32 bufferLength = 24;
        uint32 inputBufferLength = 21;
        E2EXf_0x342_ECAS_State(buffer,&bufferLength,PduInfoPtr->SduDataPtr + 3,inputBufferLength);
        rte_memcpy(PduInfoPtr->SduDataPtr,buffer,24);
        return TRUE;
    #else
        return TRUE;
    #endif
}

boolean VIU_Route_SUS_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x34b_VIU_Route_SUS(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean VDC_FMtTq_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[24] = {0};
        uint32 bufferLength = 24;
        uint32 inputBufferLength = 24;
        rettype = E2EXf_Inv_0x115_VDC_FMtTq(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean VDC_RMtTq_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x113_VDC_RMtTq(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

boolean VDC_PTSt_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    #if(0x01 == E2ESwitch)
        uint8 buffer[32] = {0};
        uint32 bufferLength = 32;
        uint32 inputBufferLength = 32;
        rettype = E2EXf_Inv_0x11b_VDC_PTSt(buffer,&inputBufferLength,PduInfoPtr->SduDataPtr,bufferLength);
        if(E_OK == rettype)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    #else
        return TRUE;
    #endif
}

