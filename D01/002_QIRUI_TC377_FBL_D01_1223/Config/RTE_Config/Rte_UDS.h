/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_UDS.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-03-29 10:48:52>
 */
/*============================================================================*/

/* Rte_UDS.h */

#ifndef RTE_UDS_H
#define RTE_UDS_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte_DataHandleType.h"
#include "Rte_UDS_Type.h"

/*******************************************************************************
 **                        Macro Definitions                                  **
******************************************************************************/

typedef struct
{
    P2VAR(Rte_DE_UInt8, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_CDCCurrentMode_CDCCurrentMode;
    P2VAR(Rte_DE_UInt8, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_VehTarPosnSt_VehTarPosnSt;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCEna_HSCEna;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCReq_HSCReq;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR;
    P2VAR(Rte_DE_UInt8, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCRoutineSts_HSCRoutineSts;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCNVMWrtReq_HSCNVMWrtReq;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCValid_HSCValidFL;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCValid_HSCValidFR;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCValid_HSCValidRL;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCValid_HSCValidRR;
    P2VAR(Rte_DE_UInt8, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_HSCRoutineStage_HSCRoutineStage;
    P2VAR(Rte_DE_UInt8, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_ExtSts;
    P2VAR(Rte_DE_UInt8, AUTOMATIC, RTE_DATA)  RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_FailRasn;
    P2VAR(Rte_DE_UInt8, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_CDCMemMode_CDCMemMode;
    P2VAR(Rte_DE_UInt8, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCStartRoutineFlag_HSCStartRoutineFlag;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCMesWheelPosInput_HSCMesWheelPosInput;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFL;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFR;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRL;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRR;
    P2VAR(Rte_DE_UInt8, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFL;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFR;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRL;
    P2VAR(Rte_DE_Float, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRR;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag;
    P2VAR(Rte_DE_UInt8, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl;
    P2VAR(Rte_DE_Boolean, AUTOMATIC, RTE_DATA)  RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut;
} Rte_CDS_UDS;

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h"
extern CONST(Rte_CDS_UDS, RTE_CONST) Rte_Inst_UDS;
#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h"

/** API mappings */

#define Rte_IRead_RE_UDS_rPort_CDCCurrentMode_CDCCurrentMode() ((CONST(UInt8,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_CDCCurrentMode_CDCCurrentMode->value)

#define Rte_IRead_RE_UDS_rPort_VehTarPosnSt_VehTarPosnSt() ((CONST(UInt8,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_VehTarPosnSt_VehTarPosnSt->value)

#define Rte_IRead_RE_UDS_rPort_HSCEna_HSCEna() ((CONST(Boolean,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCEna_HSCEna->value)

#define Rte_IRead_RE_UDS_rPort_HSCReq_HSCReq() ((CONST(Boolean,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCReq_HSCReq->value)

#define Rte_IRead_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL() ((CONST(Float,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL->value)

#define Rte_IRead_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR() ((CONST(Float,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR->value)

#define Rte_IRead_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL() ((CONST(Float,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL->value)

#define Rte_IRead_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR() ((CONST(Float,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR->value)

#define Rte_IRead_RE_UDS_rPort_HSCRoutineSts_HSCRoutineSts() ((CONST(UInt8,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCRoutineSts_HSCRoutineSts->value)

#define Rte_IRead_RE_UDS_rPort_HSCNVMWrtReq_HSCNVMWrtReq() ((CONST(Boolean,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCNVMWrtReq_HSCNVMWrtReq->value)

#define Rte_IRead_RE_UDS_rPort_HSCValid_HSCValidFL() ((CONST(Boolean,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCValid_HSCValidFL->value)

#define Rte_IRead_RE_UDS_rPort_HSCValid_HSCValidFR() ((CONST(Boolean,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCValid_HSCValidFR->value)

#define Rte_IRead_RE_UDS_rPort_HSCValid_HSCValidRL() ((CONST(Boolean,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCValid_HSCValidRL->value)

#define Rte_IRead_RE_UDS_rPort_HSCValid_HSCValidRR() ((CONST(Boolean,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCValid_HSCValidRR->value)

#define Rte_IRead_RE_UDS_rPort_HSCRoutineStage_HSCRoutineStage() ((CONST(UInt8,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_HSCRoutineStage_HSCRoutineStage->value)

#define Rte_IRead_RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_ExtSts() ((CONST(UInt8,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_ExtSts->value)

#define Rte_IRead_RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_FailRasn() ((CONST(UInt8,  RTE_DATA))  Rte_Inst_UDS.RE_UDS_rPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_FailRasn->value)

#define Rte_IWrite_RE_UDS_pPort_CDCMemMode_CDCMemMode(data) (Rte_Inst_UDS.RE_UDS_pPort_CDCMemMode_CDCMemMode->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_CDCMemMode_CDCMemMode() ((P2VAR(UInt8, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_CDCMemMode_CDCMemMode->value)

#define Rte_IWrite_RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod(data) (Rte_Inst_UDS.RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod() ((P2VAR(UInt8, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod->value)

#define Rte_IWrite_RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM() ((P2VAR(Boolean, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM->value)

#define Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM->value)

#define Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM->value)

#define Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM->value)

#define Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM->value)

#define Rte_IWrite_RE_UDS_pPort_HSCStartRoutineFlag_HSCStartRoutineFlag(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCStartRoutineFlag_HSCStartRoutineFlag->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCStartRoutineFlag_HSCStartRoutineFlag() ((P2VAR(Boolean, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCStartRoutineFlag_HSCStartRoutineFlag->value)

#define Rte_IWrite_RE_UDS_pPort_HSCMesWheelPosInput_HSCMesWheelPosInput(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPosInput_HSCMesWheelPosInput->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCMesWheelPosInput_HSCMesWheelPosInput() ((P2VAR(Boolean, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPosInput_HSCMesWheelPosInput->value)

#define Rte_IWrite_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFL(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFL->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFL() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFL->value)

#define Rte_IWrite_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFR(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFR->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFR() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosFR->value)

#define Rte_IWrite_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRL(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRL->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRL() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRL->value)

#define Rte_IWrite_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRR(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRR->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRR() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCMesWheelPos_HSCMesWheelPosRR->value)

#define  Rte_IWrite_RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts() ((P2VAR(UInt8, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts->value)

#define Rte_IWrite_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFL(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFL->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFL() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFL->value)

#define Rte_IWrite_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFR(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFR->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFR() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosFR->value)

#define Rte_IWrite_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRL(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRL->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRL() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRL->value)

#define Rte_IWrite_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRR(data) (Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRR->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRR() ((P2VAR(Float, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_HSCReMesWheelPos_HSCReMesWheelPosRR->value)

#define Rte_IWrite_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag(data) (Rte_Inst_UDS.RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag() ((P2VAR(Boolean, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_CtrlFlag->value)

#define Rte_IWrite_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl(data) (Rte_Inst_UDS.RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl() ((P2VAR(UInt8, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TarLvl->value)

#define Rte_IWrite_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut(data) (Rte_Inst_UDS.RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut->value= data)

#define Rte_IWriteRef_RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut() ((P2VAR(Boolean, AUTOMATIC, RTE_DATA))  &Rte_Inst_UDS.RE_UDS_pPort_Rout_SysLvlAdjust_Rout_SysLvlAdjust_TiOut->value)

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/** API functions */

void Rte_RE_UDS_Init(void);

void Rte_RE_UDS(void);

/** runnables */

extern void RE_UDS_Init(void);

extern void RE_UDS(void);

#endif

