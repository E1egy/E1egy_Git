/*******************************************************************************
**                                                                            **
** Copyright (C) (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : E2E_P11.h                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : YangBo                                                      **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef E2E_P11_H_
#define E2E_P11_H_

#ifdef __cplusplus

extern "C" {
#endif
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "E2E.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef enum
{
    E2E_P11_DATAID_BOTH = 0,
    E2E_P11_DATAID_NIBBLE = 3
}E2E_P11DataIDMode;

typedef struct
{
    /*Length of data, in bits.*/
    uint16 DataLength;
    /*A unique identifier, for protection against masquerading*/
    uint16 DataID;
    /*Maximum allowed gap between two counter values of two consecutively
received valid Data*/
    uint8 MaxDeltaCounter;
    E2E_P11DataIDMode  DataIDMode;
    /*Bit offset of CRC (i.e. since *Data) in MSB first order*/
    uint16 CRCOffset;
    /*Bit offset of Counter in MSB first order. In variants 1A and 1B, Counter
Offset is 8. The offset shall be a multiple of 4.*/
    uint16 CounterOffset;
    /*Bit offset of the low nibble of the high byte of Data ID.*/
    uint16 DataIDNibbleOffset;
}E2E_P11ConfigType;

typedef struct
{
    /*Counter to be used for protecting the next Data.*/
    uint8 Counter;
}E2E_P11ProtectStateType;

typedef enum
{
    E2E_P11STATUS_OK = 0x00,
    E2E_P11STATUS_NONEWDATA = 0x01,
    E2E_P11STATUS_ERROR = 0x07,
    E2E_P11STATUS_REPEATED = 0x08,
    E2E_P11STATUS_OKSOMELOST = 0x20,
    E2E_P11STATUS_WRONGSEQUENCE = 0x40
}E2E_P11CheckStatusType;

typedef struct
{
    /*Result of the verification of the Data in this cycle, determined by the
Check function.*/
    E2E_P11CheckStatusType Status;
    /*Counter of the data in previous cycle.*/
    uint8 Counter;
}E2E_P11CheckStateType;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
extern FUNC(Std_ReturnType, E2E_CODE) E2E_P11Protect(P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_APPL_DATA) ConfigPtr,P2VAR(E2E_P11ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr, uint16 Length );
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
extern FUNC(Std_ReturnType, E2E_CODE) E2E_P11ProtectInit(P2VAR(E2E_P11ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr );
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
extern FUNC(Std_ReturnType, E2E_CODE) E2E_P11Check(P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_APPL_DATA) ConfigPtr,P2VAR(E2E_P11CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr, uint16 Length );
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
extern FUNC(Std_ReturnType, E2E_CODE) E2E_P11CheckInit(P2VAR(E2E_P11CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr );
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
extern FUNC(E2E_PCheckStatusType, E2E_CODE) E2E_P11MapStatusToSM( Std_ReturnType CheckReturn, E2E_P11CheckStatusType Status );
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

#ifdef __cplusplus

  }

#endif /* end of __cplusplus */
#endif /*E2E_P11_H_ */
