/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dcm.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-05-23 16:20:01>
 */
/*============================================================================*/

#ifndef RTEDCM_H
#define RTEDCM_H

#include "Rte_Dcm_Type.h"

/***************************Security Part****************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_GetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8*  AttemptCounter );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_GetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8*  AttemptCounter );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_GetSeed(
        Dcm_OpStatusType OpStatus,uint8* Seed,Dcm_NegativeResponseCodeType* ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_GetSeed(
        Dcm_OpStatusType OpStatus,uint8* Seed,Dcm_NegativeResponseCodeType* ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_SetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_SetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/***************************Did Part****************************************/

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_FreezeCurrentState(
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_FreezeCurrentState(
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF187_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF197_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF190_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF184_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF189_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F1_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F3_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3900_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3901_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3902_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3903_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3905_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390F_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3910_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3911_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3912_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x391B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x391C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x391D_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x391E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x391F_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3920_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3922_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3923_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3924_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3925_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3926_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3927_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x394A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3907_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3940_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3960_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF013_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF031_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF089_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF032_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF180_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF186_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F2_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF025_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF091_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3906_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x396D_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x396E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x396F_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3970_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3971_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3972_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3973_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3974_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3975_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3976_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF090_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF160_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF162_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ResetToDefault(
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ResetToDefault(
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ReturnControlToECU(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ReturnControlToECU(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ShortTermAdjustment(
             P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
            uint16 DataLength,
            Dcm_OpStatusType OpStatus,
            P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
            P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ShortTermAdjustment(
             P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
            uint16 DataLength,
            Dcm_OpStatusType OpStatus,
            P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
            P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF190_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF184_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x394A_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x396E_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390A_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/***************************Routine Part****************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD04_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392A_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392C_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392D_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392E_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392F_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3930_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3956_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395B_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD0F_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xFF01_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x0203_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xFF00_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD01_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD02_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD04_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD03_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392A_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392C_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392D_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392E_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392F_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3930_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3955_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3956_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395A_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395B_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD30_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD31_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD32_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD35_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD36_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD37_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD38_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD39_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD3A_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392B_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392C_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392D_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392E_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392F_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3930_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395A_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395B_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/********* PreConditon Check ***********************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern Std_ReturnType Dcm_Rte_PreConditonCheck;
extern Std_ReturnType RTE_PreConditonCheck(void);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/***********call back functions called by DCM when a service request received******/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern Std_ReturnType  Rte_Call_Dcm_ServiceRequestSupplierNotification_DcmDsdServiceRequestSupplierNotification_0_Indication(
        uint8 SID,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)RequestData,
        uint16 DataSize,
        uint8 ReqType,
        uint16 SourceAddress,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR) ErrorCode);

extern Std_ReturnType  Rte_Call_Dcm_ServiceRequestSupplierNotification_DcmDsdServiceRequestSupplierNotification_0_Confirmation(
        uint8 SID,
        uint8 ReqType,
        uint16 SourceAddress,
        Dcm_ConfirmationStatusType ConfirmationStatus);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern Std_ReturnType SchM_PerformReset(Rte_ModeType_DcmEcuReset Reset);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /*RTEDCM_H*/
