/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_UDS.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-03-29 10:48:52>
 */
/*============================================================================*/

/* Rte_UDS.c */
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
#include "Rte_UDS.h"
#include "Rte_Data.h"
#include "HscXcp.h"
/*******************************************************************************
 **                        Private Function Declarations                      **
******************************************************************************/

static void Rte_PRE_RE_UDS(void);

static void Rte_POST_RE_UDS(void);

/*******************************************************************************
*Function-Name        RE_UDS_Init
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

void Rte_RE_UDS_Init(void)
{
    RE_UDS_Init();
}

void RE_UDS_Init(void)
{
    RE_MemModeBSW_Init();
}

/*******************************************************************************
*Function-Name        RE_UDS
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

void Rte_RE_UDS(void)
{
    Rte_PRE_RE_UDS();
    RE_UDS();
    Rte_POST_RE_UDS();
}

void RE_UDS(void)
{
    Mem_CdcModeBsw();
    HeightMsgCalibrationBsw();
}

/*******************************************************************************
 **                        Global Function                                    **
******************************************************************************/

#define RTE_START_SEC_CODE
#include "RTE_MemMap.h"

static void Rte_PRE_RE_UDS(void)
    {
        GetResource(RES_SCHEDULER);
        Rte_Inst_UDS.RE_UDS_rPort_CDCCurrentMode_CDCCurrentMode->value = Rte_Buf_UDS_rPort_CDCCurrentMode_CDCCurrentMode;
        Rte_Inst_UDS.RE_UDS_rPort_VehTarPosnSt_VehTarPosnSt->value = Rte_Buf_UDS_rPort_VehTarPosnSt_VehTarPosnSt;
        Rte_Inst_UDS.RE_UDS_rPort_HSCEna_HSCEna->value = Rte_Buf_UDS_rPort_HSCEna_HSCEna;
        Rte_Inst_UDS.RE_UDS_rPort_HSCReq_HSCReq->value = Rte_Buf_UDS_rPort_HSCReq_HSCReq;
        Rte_Inst_UDS.RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL->value = Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL;
        Rte_Inst_UDS.RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR->value = Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR;
        Rte_Inst_UDS.RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL->value = Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL;
        Rte_Inst_UDS.RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR->value = Rte_Buf_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR;
        Rte_Inst_UDS.RE_UDS_rPort_HSCRoutineSts_HSCRoutineSts->value = Rte_Buf_UDS_rPort_HSCRoutineSts_HSCRoutineSts;
        Rte_Inst_UDS.RE_UDS_rPort_HSCNVMWrtReq_HSCNVMWrtReq->value = Rte_Buf_UDS_rPort_HSCNVMWrtReq_HSCNVMWrtReq;
        Rte_Inst_UDS.RE_UDS_rPort_HSCValid_HSCValidFL->value = Rte_Buf_UDS_rPort_HSCValid_HSCValidFL;
        Rte_Inst_UDS.RE_UDS_rPort_HSCValid_HSCValidFR->value = Rte_Buf_UDS_rPort_HSCValid_HSCValidFR;
        Rte_Inst_UDS.RE_UDS_rPort_HSCValid_HSCValidRL->value = Rte_Buf_UDS_rPort_HSCValid_HSCValidRL;
        Rte_Inst_UDS.RE_UDS_rPort_HSCValid_HSCValidRR->value = Rte_Buf_UDS_rPort_HSCValid_HSCValidRR;
        Rte_Inst_UDS.RE_UDS_rPort_HSCRoutineStage_HSCRoutineStage->value = Rte_Buf_UDS_rPort_HSCRoutineStage_HSCRoutineStage;
        Rte_Inst_UDS.RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_ExtSts->value = Rte_Buf_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_ExtSts;
        Rte_Inst_UDS.RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_FailRasn->value = Rte_Buf_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_FailRasn;
        ReleaseResource(RES_SCHEDULER);
    }

static void Rte_POST_RE_UDS(void)
    {
        GetResource(RES_SCHEDULER);
        Rte_Buf_DicTotalModelCDCASV3QR0104_CDCMemMode_CDCMemMode = Rte_Inst_UDS.RE_UDS_pPort_CDCMemMode_CDCMemMode->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_VehLvlMemMod_VehLvlMemMod = Rte_Inst_UDS.RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCSts_EEM_HSCSts_EEM = Rte_Inst_UDS.RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM = Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM = Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM = Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM = Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCStartRoutineFlag_HSCStartRoutineFlag = Rte_Inst_UDS.RE_UDS_pPort_HSCStartRoutineFlag_HSCStartRoutineFlag->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPosInput_HSCMesWheelPosInput = Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPosInput_HSCMesWheelPosInput->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosFL = Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFL->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosFR = Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFR->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosRL = Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRL->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCMesWheelPos_HSCMesWheelPosRR = Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRR->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCNVMWrtSts_HSCNVMWrtSts = Rte_Inst_UDS.RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosFL = Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFL->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosFR = Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFR->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosRL = Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRL->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_HSCReMesWheelPos_HSCReMesWheelPosRR = Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRR->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag = Rte_Inst_UDS.RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl = Rte_Inst_UDS.RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl->value;
        Rte_Buf_DicTotalModelCDCASV3QR0104_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut = Rte_Inst_UDS.RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut->value;
        ReleaseResource(RES_SCHEDULER);
    }

#define RTE_STOP_SEC_CODE
#include "RTE_MemMap.h"

