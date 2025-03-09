/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-03-29 10:36:10>
 */
/*============================================================================*/

/* Rte.c */
/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

#define RTE_CORE

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Os.h"
#include "Rte_Type.h"
#include "Rte_Data.h"
#include "Rte_Main.h"
#include "Rte_UDS.h"
#include "Com.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/

/*******************************************************************************
 **                        Global Function Definitions                        **
******************************************************************************/





Rte_DE_UInt8 Rte_Buf_RE_UDS_rPort_CDCCurrentMode_CDCCurrentMode_ibuffer;
Rte_DE_UInt8 Rte_Buf_RE_UDS_rPort_VehTarPosnSt_VehTarPosnSt_ibuffer;
Rte_DE_Boolean Rte_Buf_RE_UDS_rPort_HSCEna_HSCEna_ibuffer;
Rte_DE_Boolean Rte_Buf_RE_UDS_rPort_HSCReq_HSCReq_ibuffer;
Rte_DE_Float Rte_Buf_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR_ibuffer = {.value = 0};
Rte_DE_UInt8 Rte_Buf_RE_UDS_rPort_HSCRoutineSts_HSCRoutineSts_ibuffer = {.value = 0};
Rte_DE_Boolean Rte_Buf_RE_UDS_rPort_HSCNVMWrtReq_HSCNVMWrtReq_ibuffer = {.value = 0};
Rte_DE_Boolean Rte_Buf_RE_UDS_rPort_HSCValid_HSCValidFL_ibuffer = {.value = 0};
Rte_DE_Boolean Rte_Buf_RE_UDS_rPort_HSCValid_HSCValidFR_ibuffer = {.value = 0};
Rte_DE_Boolean Rte_Buf_RE_UDS_rPort_HSCValid_HSCValidRL_ibuffer = {.value = 0};
Rte_DE_Boolean Rte_Buf_RE_UDS_rPort_HSCValid_HSCValidRR_ibuffer = {.value = 0};
Rte_DE_UInt8 Rte_Buf_RE_UDS_rPort_HSCRoutineStage_HSCRoutineStage_ibuffer = {.value = 0};
Rte_DE_UInt8 Rte_Buf_RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_ExtSts_ibuffer = {.value = 0};
Rte_DE_UInt8 Rte_Buf_RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_FailRasn_ibuffer = {.value = 0};
Rte_DE_UInt8 Rte_Buf_RE_UDS_pPort_CDCMemMode_CDCMemMode_ibuffer;
Rte_DE_UInt8 Rte_Buf_RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod_ibuffer;
Rte_DE_Boolean Rte_Buf_RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM_ibuffer = {.value = 0};
Rte_DE_Boolean Rte_Buf_RE_UDS_pPort_HSCStartRoutineFlag_HSCStartRoutineFlag_ibuffer = {.value = 0};
Rte_DE_Boolean Rte_Buf_RE_UDS_pPort_HSCMesWheelPosInput_HSCMesWheelPosInput_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFL_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFR_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRL_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRR_ibuffer = {.value = 0};
Rte_DE_UInt8 Rte_Buf_RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFL_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFR_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRL_ibuffer = {.value = 0};
Rte_DE_Float Rte_Buf_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRR_ibuffer = {.value = 0};
Rte_DE_Boolean Rte_Buf_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag_ibuffer = {.value = 0};
Rte_DE_UInt8 Rte_Buf_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl_ibuffer = {.value = 0};
Rte_DE_Boolean Rte_Buf_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut_ibuffer = {.value = 0};
CONST(Rte_CDS_UDS, RTE_CONST) Rte_Inst_UDS =
{
    .RE_UDS_rPort_CDCCurrentMode_CDCCurrentMode = &Rte_Buf_RE_UDS_rPort_CDCCurrentMode_CDCCurrentMode_ibuffer,
    .RE_UDS_rPort_VehTarPosnSt_VehTarPosnSt = &Rte_Buf_RE_UDS_rPort_VehTarPosnSt_VehTarPosnSt_ibuffer,
    .RE_UDS_rPort_HSCEna_HSCEna = &Rte_Buf_RE_UDS_rPort_HSCEna_HSCEna_ibuffer,
    .RE_UDS_rPort_HSCReq_HSCReq = &Rte_Buf_RE_UDS_rPort_HSCReq_HSCReq_ibuffer,
    .RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL = &Rte_Buf_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL_ibuffer,
    .RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR = &Rte_Buf_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR_ibuffer,
    .RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL = &Rte_Buf_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL_ibuffer,
    .RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR = &Rte_Buf_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR_ibuffer,
    .RE_UDS_rPort_HSCRoutineSts_HSCRoutineSts = &Rte_Buf_RE_UDS_rPort_HSCRoutineSts_HSCRoutineSts_ibuffer,
    .RE_UDS_rPort_HSCNVMWrtReq_HSCNVMWrtReq = &Rte_Buf_RE_UDS_rPort_HSCNVMWrtReq_HSCNVMWrtReq_ibuffer,
    .RE_UDS_rPort_HSCValid_HSCValidFL = &Rte_Buf_RE_UDS_rPort_HSCValid_HSCValidFL_ibuffer,
    .RE_UDS_rPort_HSCValid_HSCValidFR = &Rte_Buf_RE_UDS_rPort_HSCValid_HSCValidFR_ibuffer,
    .RE_UDS_rPort_HSCValid_HSCValidRL = &Rte_Buf_RE_UDS_rPort_HSCValid_HSCValidRL_ibuffer,
    .RE_UDS_rPort_HSCValid_HSCValidRR = &Rte_Buf_RE_UDS_rPort_HSCValid_HSCValidRR_ibuffer,
    .RE_UDS_rPort_HSCRoutineStage_HSCRoutineStage = &Rte_Buf_RE_UDS_rPort_HSCRoutineStage_HSCRoutineStage_ibuffer,
    .RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_ExtSts = &Rte_Buf_RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_ExtSts_ibuffer,
    .RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_FailRasn = &Rte_Buf_RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_FailRasn_ibuffer,
    .RE_UDS_pPort_CDCMemMode_CDCMemMode = &Rte_Buf_RE_UDS_pPort_CDCMemMode_CDCMemMode_ibuffer,
    .RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod = &Rte_Buf_RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod_ibuffer,
    .RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM = &Rte_Buf_RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM_ibuffer,
    .RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM = &Rte_Buf_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM_ibuffer,
    .RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM = &Rte_Buf_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM_ibuffer,
    .RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM = &Rte_Buf_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM_ibuffer,
    .RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM = &Rte_Buf_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM_ibuffer,
    .RE_UDS_pPort_HSCStartRoutineFlag_HSCStartRoutineFlag = &Rte_Buf_RE_UDS_pPort_HSCStartRoutineFlag_HSCStartRoutineFlag_ibuffer,
    .RE_UDS_pPort_HSCMesWheelPosInput_HSCMesWheelPosInput = &Rte_Buf_RE_UDS_pPort_HSCMesWheelPosInput_HSCMesWheelPosInput_ibuffer,
    .RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFL = &Rte_Buf_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFL_ibuffer,
    .RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFR = &Rte_Buf_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFR_ibuffer,
    .RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRL = &Rte_Buf_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRL_ibuffer,
    .RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRR = &Rte_Buf_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRR_ibuffer,
    .RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts = &Rte_Buf_RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts_ibuffer,
    .RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFL = &Rte_Buf_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFL_ibuffer,
    .RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFR = &Rte_Buf_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFR_ibuffer,
    .RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRL = &Rte_Buf_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRL_ibuffer,
    .RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRR = &Rte_Buf_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRR_ibuffer,
    .RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag = &Rte_Buf_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag_ibuffer,
    .RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl = &Rte_Buf_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl_ibuffer,
    .RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut = &Rte_Buf_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut_ibuffer,
};

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*Function-Name        Rte_Start
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

Std_ReturnType Rte_Start(void)
{

//	(void)SetRelAlarm(OsAlarm_CORE0_10MS, 10, OS_TICKS2MS_SystemTimer_Core0(10));
//
//	(void)SetRelAlarm(OsAlarm_CORE0_1MS, 1, OS_TICKS2MS_SystemTimer_Core0(1));
//
//	(void)SetRelAlarm(OsAlarm_CORE0_2MS, 2, OS_TICKS2MS_SystemTimer_Core0(2));

//	(void)SetRelAlarm(OsAlarm_CORE1_1MS, 1, OS_TICKS2MS_SystemTimer_Core0(1));

//	(void)SetRelAlarm(OsAlarm_CORE1_2MS, 2, OS_TICKS2MS_SystemTimer_Core0(2));

//	(void)SetRelAlarm(OsAlarm_CORE1_10MS, 10, OS_TICKS2MS_SystemTimer_Core0(10));

    return RTE_E_OK;
}

/*******************************************************************************
*Function-Name        Rte_Stop
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

Std_ReturnType Rte_Stop(void)
{
    return RTE_E_OK;
}

void Os_TaskEntry_Rte_OsTask_CORE0_INIT(void)
{
    //Rte_RE_UDS_Init();

}

void Os_TaskEntry_Rte_OsTask_CORE0_10MS(void)
{
    //Rte_RE_UDS();

}

void Os_TaskEntry_Rte_OsTask_CORE0_2MS(void)
{

}

void Os_TaskEntry_Rte_OsTask_CORE1_1MS(void)
{

}

void Os_TaskEntry_Rte_OsTask_CORE1_2MS(void)
{

}

void Os_TaskEntry_Rte_OsTask_CORE1_10MS(void)
{

}

void Os_TaskEntry_Rte_OsTask_CORE1_INIT(void)
{

}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

