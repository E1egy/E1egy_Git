/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : Cry_HsmAesCMacVerify.c                                      **
**                                                                           **
**  VERSION    : 5.0.0                                                       **
**                                                                           **
**  DATE       : 2018-06-13                                                  **
**                                                                           **
**  VARIANT   : NA                                                           **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR      : Prashant K                                                 **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of Cry module                                **
**                                                                           **
**  SPECIFICATION(S) : Aurix_SHE+_TC-CDRV_DS.docx                            **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
/*******************************************************************************
**                      Revision Control History                             **
*******************************************************************************/
/*
<IFX_RCH>
</IFX_RCH>
*/
/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_Hsm_Priv.h"
#include "Cry_HsmAesCMacVerify.h"

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/

/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/

/******************************************************************************
**                     Global Structure Definition                           **
******************************************************************************/

/******************************************************************************
**                     Global Variable Definition                            **
******************************************************************************/
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"

Cry_HsmAesCMacVerifyConfigType    Cry_kHsmAesCMacVerifyConfig  =
        {.TimeOut = CRY_HSM_AES_CMAC_VERIFY_ALL_TIMEOUT};

static Cry_HsmPrimitiveIdType Cry_PRMIDMacVer = CRY_HSM_MAC_VERIFY;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/*To Hold mac verification message*/
static uint32 Cry_HsmAesCMacVerMsg[4];

/*To hold Reference Mac for verification*/
static uint32 Cry_HsmAesCMacVerRefMac[4];

/*To hold Inverted Reference Mac for verification*/
static uint32 Cry_HsmAesCMacVerInvRefMac[4];

/*Structure to hold the Key address*/
static struct
{
  HsmCom_KeyAddr  KeyAddr;
} Cry_HsmAesCMacVerifyData;

#if (CRY_HSM_MAC_SAFE_VERIFY == STD_ON)
static Csm_SafeVerifyResultType Cry_HsmAesCMacVerResult;
#else
static Csm_VerifyResultType Cry_HsmAesCMacVerResult;
#endif

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/* [$Satisfies $CDS_CDRV 610] */
#if (CRY_HSM_MAC_SAFE_VERIFY == STD_ON)
#define CRY_START_SEC_VAR_ALIGN16
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

static HsmAes_Block InvertedMAC;

#define CRY_STOP_SEC_VAR_ALIGN16
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"
#endif
/******************************************************************************
**                     Global Function Definition                            **
******************************************************************************/

/******************************************************************************
**                      Global Function Decleartion                          **
******************************************************************************/
#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 60] [$Satisfies $CDS_CDRV 61]     **
**                   [$Satisfies $CDS_CDRV 62] [$Satisfies $CDS_CDRV 63]     **
**                   [$Satisfies $CDS_CDRV 64] [$Satisfies $CDS_CDRV 65]     **
**                   [$Satisfies $CDS_CDRV 579] [$Satisfies $CDS_CDRV 604]   **
**                   [$Satisfies $CDS_CDRV 605] [$Satisfies $CDS_CDRV 602]   **
**                   [$Satisfies $CDS_CDRV 603]                              **
** Syntax          : Csm_ReturnType Cry_HsmAesCMacVerifyStart(               **
                        const void *CfgPtr, const Csm_SymKeyType *KeyPtr)    **
**                                                                           **
** Description     : This function implements Cry_HsmAesCMacVerifyStart for  **
**                   Csm_MacVerifyStart service. It reserves and initializes **
**                   resources for Csm_MacVerify service and sends request to**
**                   HSM to initiate CMAC verification.                      **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_VERIFY_START                            **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr- Pointer to configuration structure of           **
**                           Cry_HsmAesCMacVerifyConfigType. This parameter  **
**                           is ignored.                                     **
**                   KeyPtr-Pointer to key structure of Csm_SymKeyType       **
**                          1. KeyPtr->length shall be 1                     **
**                          2. KeyPtr->data[0] shall be a value taken from   **
**                          Cry_HsmKeySlotIdType and is used to calculate    **
**                          global key address                               **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK- Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK- Request failed                            **
**                                                                           **
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmAesCMacVerifyStart( const void *CfgPtr,
                                          const Csm_SymKeyType *KeyPtr)
{
  /*To store Return value from Cry Api's*/
  Csm_ReturnType ErrorVal;

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  /*To store DET errors*/
  boolean DetErr;
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_MAC_VERIFY_START , KeyPtr , DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DEV_NO_ERROR == DetErr)
  {
    INIT_VALIDATION(CRY_HSM_SID_MAC_VERIFY_START, Cry_HsmInitStatus ,
                                                                   DetErr )
  }
  if(DEV_NO_ERROR == DetErr)
  {
    KEY_VALIDATION(CRY_HSM_SID_MAC_VERIFY_START,
                                          Cry_lCalcKeyAddr(KeyPtr), DetErr)
  }
  /* If any DET error occurs, return CSM_E_NOT_OK. Further processing
                                                         is not required */
  if(DEV_NO_ERROR != DetErr)
  {
    ErrorVal = CSM_E_NOT_OK;
  }
  else
  #endif
  {
    /* Initiate the handle for the session */
    ErrorVal = Cry_HsmPrimitiveStart(Cry_PRMIDMacVer);
    /* Check if the session opened successfully */
    if(CSM_E_BUSY != ErrorVal)
    {
      /*Store the key*/
      Cry_HsmAesCMacVerifyData.KeyAddr = Cry_lCalcKeyAddr(KeyPtr);
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the indication that START service is successful. To be used by
       * UPDATE and FINISH services to check the DET
       * "CSM_E_SERVICE_NOT_STARTED" */
      Cry_PrimStatus[Cry_PRMIDMacVer] = CRY_HSM_PRIM_STARTED;
      #endif
    }
  }
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that START service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDMacVer] = ASYNC_STATE_START;
  /* Store the service return value. To be used by the main function to report
   * the status to upper layer */
  Cry_PrimErr[Cry_PRMIDMacVer] = ErrorVal;
  #endif
  UNUSED_POINTER (CfgPtr);
#if (CRY_HSM_MAC_SAFE_VERIFY == STD_ON)
  /* To avoid the misra warning */
  UNUSED_PARAMETER(InvertedMAC.Data[0]);
#endif
  return ErrorVal;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 66] [$Satisfies $CDS_CDRV 67]     **
**                   [$Satisfies $CDS_CDRV 68] [$Satisfies $CDS_CDRV 69]     **
**                   [$Satisfies $CDS_CDRV 70] [$Satisfies $CDS_CDRV 71]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType Cry_HsmAesCMacVerifyUpdate(              **
**              const void *CfgPtr, const uint8 *DataPtr, uint32 DataLength) **
**                                                                           **
** Description     : This function implements Cry_HsmAesCMacVerifyUpdate for **
**                   Csm_MacVerifyUpdate service. It sends request to HSM to **
**                   update CMAC verification.                               **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_VERIFY_UPDATE                           **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Parameters (in) : CfgPtr-Pointer to configuration structure of            **
**                          Cry_HsmAesCMacVerifyConfigType                   **
**                   DataPtr- Pointer to the data for which the MAC shall be **
**                            computed                                       **
**                   DataLength- Number of bytes for which the MAC shall be  **
**                   computed                                                **
**                     1. Only multiple of 16 allowed, for non-final input   **
**                     2. Non-multiple of 16 also allowed, for final input   **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK- Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK- Request failed                            **
**                                                                           **
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmAesCMacVerifyUpdate(
                const void *CfgPtr, const uint8 *DataPtr, uint32 DataLength)
{
  Csm_ReturnType ErrorVal;
  Cry_Hsm *HandlePtr;
  HsmCom_MacUpdateParams *ParamPtr;
  const Cry_HsmAesCMacVerifyConfigType *MacCfgPtr;

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_MAC_VERIFY_UPDATE, CfgPtr ,DetErr )
  if(DEV_NO_ERROR == DetErr)
  {
    PTR_VALIDATION(CRY_HSM_SID_MAC_VERIFY_UPDATE, DataPtr , DetErr)
  }
  if(DEV_NO_ERROR == DetErr)
  {
    START_VALIDATION(CRY_HSM_SID_MAC_VERIFY_UPDATE,
                        Cry_PrimStatus[Cry_PRMIDMacVer], DetErr)
  }
  /* If any DET error occurs, return CSM_E_NOT_OK. Further processing
                                                           is not required */
  if(DEV_NO_ERROR != DetErr)
  {
    ErrorVal = CSM_E_NOT_OK;
  }
  else
  #endif
  {
    /* Check the HSM status. COmmand is sent only if the HSM is not busy */
    ErrorVal = Cry_HsmStatusCheck(Cry_PRMIDMacVer);
    if(CSM_E_OK == ErrorVal)
    {
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
       * config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
       * config pointer is of type void*/
      MacCfgPtr = (const Cry_HsmAesCMacVerifyConfigType *)CfgPtr;
      /*Get the active handle*/
      HandlePtr = &(Cry_HsmData[Cry_PRMIDMacVer]);
      /*Store key address in Session data*/
      HsmCom_SetPackedParams(HandlePtr->Session,
                             Cry_HsmAesCMacVerifyData.KeyAddr,
                             CRY_HSM_AES_MODE_DUMMY);
      /*Get shared memory address*/
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be aligned to
       * the struture pointer containing the elements for MacUpdation*/
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /*Load the parameters needed*/

      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      ParamPtr->SourceAddr = (HostAddr)DataPtr;
      ParamPtr->SizeBytes  =  DataLength;
      /*Send command to HSM*/
      ErrorVal = Cry_HsmSendCommandCommon(HandlePtr,
                                          HSMCOM_CMD_MAC_VER_UPDATE,
                                          CRY_HSM_GET_UPDATE_TIMEOUT_TICKS
                                          (MacCfgPtr,DataLength));
      /*Make keyid invalid for 2nd update onwards*/
      Cry_HsmAesCMacVerifyData.KeyAddr = HSMCOM_INVALID_KEY;
    }
  }
 #if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
  /* Set the indication to main function that UPDATE service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDMacVer] = ASYNC_STATE_UPDATE;
  /* Store the service return value. To be used by the main function to do
   * further processing */
  Cry_PrimErr[Cry_PRMIDMacVer] = ErrorVal;
  #endif
  return ErrorVal;
}

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 72] [$Satisfies $CDS_CDRV 73]     **
**                   [$Satisfies $CDS_CDRV 74] [$Satisfies $CDS_CDRV 75]     **
**                   [$Satisfies $CDS_CDRV 76] [$Satisfies $CDS_CDRV 77]     **
**                   [$Satisfies $CDS_CDRV 78] [$Satisfies $CDS_CDRV 79]     **
**                   [$Satisfies $CDS_CDRV 80] [$Satisfies $CDS_CDRV 81]     **
**                   [$Satisfies $CDS_CDRV 82] [$Satisfies $CDS_CDRV 83]     **
**                   [$Satisfies $CDS_CDRV 84] [$Satisfies $CDS_CDRV 85]     **
**                   [$Satisfies $CDS_CDRV 86] [$Satisfies $CDS_CDRV 87]     **
**                   [$Satisfies $CDS_CDRV 579][$Satisfies $CDS_CDRV 741]    **
** Syntax          : Csm_ReturnType  Cry_HsmAesCMacVerifyFinish(             **
**                         const void *CfgPtr, const uint8 *MacPtr,          **
**                         uint32 MacLength, Csm_VerifyResultType *ResultPtr)**
**                                                                           **
** Description     : This function sends request to HSM to finalize CMAC     **
**                   verification.                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_VERIFY_FINISH                           **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr- Pointer to configuration structure of           **
**                           Cry_HsmAesCMacVerifyConfigType                  **
**                   MacPtr- Pointer to the memory location which hold the   **
**                           MAC to verify.                                  **
**                   MacLength- The length (in bits) of the MAC to be        **
**                              verified                                     **
**                                                                           **
** Parameters (out): ResultPtr- Pointer to the memory location which will    **
**                    hold the result of the MAC verification.               **
**                    In a QM configuration the content is:                  **
**                    1. CSM_E_VER_OK: verification pass                     **
**                    2. CSM_E_VER_NOT_OK: verification fail                 **
                      In a safety configuration the content of the structure **
                      is enhanced to include additional data allowing the    **
                      upper layer to detect possible faults:                 **
**                    1. Result: same as AUTOSAR standard                    **
**                    2. CodedResult1: Coded result (CMAC) if the check is   **
**                    successful (cf. safety concept). Otherwise 0           **
**                    3. CodedResult2: Coded result (~CMAC) if the check is  **
**                      successful (cf. safety concept). Otherwise 0         **
**                    4. BitsCompared1 according to safety concept           **
**                    5. BitsCompared2 according to safety concept           **
**                    6. DataLength: data length value according to safety   **
**                       concept                                             **
**                    7. Coding of data pointer for verified                 **
**                       message, cf. safety concept                         **
**                                                                           **
** Return value    : CSM_E_OK- Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK- Request failed                            **
**                                                                           **
******************************************************************************/
Csm_ReturnType  Cry_HsmAesCMacVerifyFinish(
                             const void *CfgPtr, const uint8 *MacPtr,
                             uint32 MacLength, Csm_VerifyResultType *ResultPtr)
{
  Csm_ReturnType ErrorVal;
  Cry_Hsm *HandlePtr;
  HsmCom_MacVerifyParams *ParamPtr;
  const Cry_HsmAesCMacVerifyConfigType* MacCfgPtr;
  #if (CRY_HSM_MAC_SAFE_VERIFY == STD_ON)
  Csm_ReturnType ErrorStep1;
  Csm_ReturnType ErrorStep2;
  Csm_SafeVerifyResultType *Cry_HsmAesCMacSafeResult;
  const HsmAes_Block* RefMacPtr;
  #endif

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_MAC_VERIFY_FINISH, CfgPtr , DetErr)
  if(DEV_NO_ERROR == DetErr)
  {
    PTR_VALIDATION(CRY_HSM_SID_MAC_VERIFY_FINISH, ResultPtr , DetErr)
  }
  if(DEV_NO_ERROR == DetErr)
  {
    PTR_VALIDATION(CRY_HSM_SID_MAC_VERIFY_FINISH, MacPtr , DetErr)
  }
  if(DEV_NO_ERROR == DetErr)
  {
    START_VALIDATION(CRY_HSM_SID_MAC_VERIFY_FINISH,
                               Cry_PrimStatus[Cry_PRMIDMacVer] , DetErr)
  }
  /*If any DET error occurs, return CSM_E_NOT_OK. Further processing
    is not required */
  if(DEV_NO_ERROR != DetErr)
  {
    ErrorVal = CSM_E_NOT_OK;
  }
  else
  #endif
  {
    ErrorVal = Cry_HsmStatusCheck(Cry_PRMIDMacVer);
    if(CSM_E_OK == ErrorVal)
    {
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
       * config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
       * config pointer is of type void */
      MacCfgPtr = (const Cry_HsmAesCMacVerifyConfigType*)CfgPtr;
      /*Get the active handle*/
      HandlePtr = &(Cry_HsmData[Cry_PRMIDMacVer]);
      /*Get shared memory address*/
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be aligned to
       * the struture pointer containing the elements for MacVerification*/
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
       * data sharing between Host and HSM through shared buffer*/
      ParamPtr->MacInputAddr = (HostAddr)MacPtr;
      ParamPtr->VerifyBits   =  MacLength;
      #if (CRY_HSM_MAC_SAFE_VERIFY == STD_OFF)
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
       * data sharing between Host and HSM through shared buffer*/
      ParamPtr->MacVerAddr   = (HostAddr)(ResultPtr);
      /*Send command for normal MacVer finish, since Safe Mac is disabled*/
      ErrorVal = Cry_HsmSendCommandCommon(HandlePtr,
                                HSMCOM_CMD_MAC_VER_FINISH,
                                CRY_HSM_GET_FINISH_TIMEOUT_TICKS(MacCfgPtr));
      #else
      /*IFX_MISRA_RULE_11_03_STATUS=Typecating is required as input  MacPtr is
       * of type uint8*/
      RefMacPtr = (const HsmAes_Block*)(MacPtr);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
       * data sharing between Host and HSM through shared buffer*/
      ParamPtr->MacVerAddr   = (HostAddr)(ResultPtr);
      /*IFX_MISRA_RULE_01_03_STATUS=Typecasting is required as ResultPtr
       * is of type Csm_SafeVerifyResultType when CRY_HSM_MAC_SAFE_VERIFY is
       * STD_ON*/
      /*IFX_MISRA_RULE_11_03_STATUS=Typecasting is required as ResultPtr
       * is of type Csm_SafeVerifyResultType when CRY_HSM_MAC_SAFE_VERIFY is
       * STD_ON*/
      Cry_HsmAesCMacSafeResult = (Csm_SafeVerifyResultType*)(ResultPtr);
      InvertedMAC.Data[3] = ~(RefMacPtr -> Data[3]);
      InvertedMAC.Data[2] = ~(RefMacPtr -> Data[2]);
      InvertedMAC.Data[1] = ~(RefMacPtr -> Data[1]);
      InvertedMAC.Data[0] = ~(RefMacPtr -> Data[0]);
      Cry_HsmAesCMacSafeResult->Result = CSM_E_VER_NOT_OK;
      Cry_HsmAesCMacSafeResult->CodedResult1 = 0U;
      Cry_HsmAesCMacSafeResult->CodedResult2 = 0U;
      Cry_HsmAesCMacSafeResult->BitsCompared1 = 0U;
      Cry_HsmAesCMacSafeResult->BitsCompared2 = 0U;
      Cry_HsmAesCMacSafeResult->DataPtr = 0U;
      Cry_HsmAesCMacSafeResult->DataLength = 0U;
      /*Send command to HSM for Step1 of Safe Mac Ver*/
      ErrorStep1 = Cry_HsmSendCommandCommon(HandlePtr,
                       HSMCOM_CMD_SAFE_MAC_VER_FINISH,
              CRY_HSM_GET_FINISH_TIMEOUT_TICKS(MacCfgPtr));
      /*Change address to address of Inverted Mac*/

      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      ParamPtr->MacInputAddr  = (HostAddr)(&(InvertedMAC));
      /*Send command to HSM for Step2 of Safe Mac Ver*/
      ErrorStep2 = Cry_HsmSendCommandCommon(HandlePtr,
                HSMCOM_CMD_SAFE_MAC_VER_FINISH_CHECK,
            CRY_HSM_GET_FINISH_TIMEOUT_TICKS(MacCfgPtr));
      /*Check return from both function and proceed if both passes*/
      if ((CSM_E_OK == ErrorStep1) && (CSM_E_OK == ErrorStep2))
      {
        ErrorVal = CSM_E_OK;
      }
      else
      {
        ErrorVal = CSM_E_NOT_OK;
      }

      #endif
      #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
      Cry_lHsmDeinitiateHandle(HandlePtr);
      #else
      if(ErrorVal != CSM_E_OK)
      {
        Cry_lHsmDeinitiateHandle(HandlePtr);
      }
      #endif
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      Cry_PrimStatus[Cry_PRMIDMacVer] = CRY_HSM_PRIM_FINISHED;
      #endif
    }
  }
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /*Indicate Finish action*/
  Cry_PrimStatusAsync[Cry_PRMIDMacVer] = ASYNC_STATE_FINISH;
  Cry_PrimErr[Cry_PRMIDMacVer] = ErrorVal;
  #endif

  #if((CRY_HSM_E_POLICY_VIOLATION != STD_OFF)||  \
    (CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF))
  /* Clear Cry_MacVerError flag, set by Cry_HsmSendCommandCommon function */
  Cry_MacVerError = FALSE;
  #endif
  return ErrorVal;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 88] [$Satisfies $CDS_CDRV 579]    **
**                   [$Satisfies $CDS_CDRV 745]                              **
**                                                                           **
** Syntax          : void Cry_HsmAesCMacVerifyMainFunction(void)             **
**                                                                           **
** Description     : This function doesnt exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation:                      **
**                   This function checks the command response for           **
**                   HSMCOM_CMD_MAC_VER_UPDATE command.                      **
**                   If CryHsmSafeMacVerify == FALSE (safety concept not     **
**                   required to be supported), the function checks the      **
**                   command response for HSMCOM_CMD_MAC_VER_FINISH command  **
**                   and closes the session.                                 **
**                   If CryHsmSafeMacVerify == TRUE (safety concept is       **
**                   required to be supported), the function checks the      **
**                  command response for HSMCOM_CMD_SAFE_MAC_VER_FINISH_CHECK**
**                   command and closes the session.                         **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
void Cry_HsmAesCMacVerifyMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDMacVer, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
**                                                                           **
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmAesCMacVarInit(void)                        **
**                                                                           **
** Description     : This function is  used to initialize MacVerify          **
**                   variables                                               **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
void Cry_HsmAesCMacVarInit(void)
{
  #if (CRY_HSM_MAC_SAFE_VERIFY == STD_ON)
  Cry_HsmAesCMacVerResult.Result = CSM_E_VER_NOT_OK;
  #else
  Cry_HsmAesCMacVerResult = CSM_E_VER_NOT_OK;
  #endif
  /*Initialize MAC Verification message */
  {
    Cry_HsmAesCMacVerMsg[0] = 0xe2bec16bU;
    Cry_HsmAesCMacVerMsg[1] = 0x969f402eU;
    Cry_HsmAesCMacVerMsg[2] = 0x117e3de9U;
    Cry_HsmAesCMacVerMsg[3] = 0x2a179373U;
  }
  /* Initialize reference MAC for dummy MAC verification */
  {
    Cry_HsmAesCMacVerRefMac[0] = 0xb4160a07U;
    Cry_HsmAesCMacVerRefMac[1] = 0x44414d6bU;
    Cry_HsmAesCMacVerRefMac[2] = 0x9ddd9bf7U;
    Cry_HsmAesCMacVerRefMac[3] = 0x7c284ad0U;
  }
  /* Initialize inverted reference MAC for dummy MAC verification */
  {
    Cry_HsmAesCMacVerInvRefMac[0] = 0x4be9f5f8U;
    Cry_HsmAesCMacVerInvRefMac[1] = 0xbbbeb294U;
    Cry_HsmAesCMacVerInvRefMac[2] = 0x62226408U;
    Cry_HsmAesCMacVerInvRefMac[3] = 0x83d7b52fU;
  }
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 243]                              **
**                                                                           **
** Syntax          : void Cry_HsmAesCMacDummyMacVerification(void)           **
**                                                                           **
** Description     : This function is used for updating parameters for       **
**                   dummy MAC verification                                  **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
void Cry_HsmAesCMacDummyMacVerification(void)
{
  HsmCom_DummyMacVerification *ParamPtr;

  /*Initialise cMac message , CMac verification message and Inverted
   * cMac msg*/
  Cry_HsmAesCMacVarInit();
  /*Block [0] is used for handshaking between HSM and Host and Blocks[1] to
   * set Dummy MAC Verification parameter   */
  /*IFX_MISRA_RULE_01_03_STATUS=Typecasting is required as HsmCom_DataBuffers
    is of type HsmCom_Buffers */
  /*IFX_MISRA_RULE_11_03_STATUS=Typecasting is required as HsmCom_DataBuffers
   * is of type HsmCom_Buffers */
  ParamPtr = (HsmCom_DummyMacVerification *)
                       &(HsmCom_DataBuffers.Ht2Hsm[0].Blocks[1]);
  /*Set parameters for MAC verication */
  /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
   * sharing between Host and HSM through shared buffer*/
  /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
   * sharing between Host and HSM through shared buffer*/
  ParamPtr->SourceAddr = (HostAddr)&Cry_HsmAesCMacVerMsg;
  /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
   * sharing between Host and HSM through shared buffer*/
  /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
   * sharing between Host and HSM through shared buffer*/
  ParamPtr->RefMacAddr = (HostAddr)&Cry_HsmAesCMacVerRefMac;
  /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
   * sharing between Host and HSM through shared buffer*/
  /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
   * sharing between Host and HSM through shared buffer*/
  ParamPtr->InvertedRefMacAddr =
                         (HostAddr)&Cry_HsmAesCMacVerInvRefMac;
  /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
   * sharing between Host and HSM through shared buffer*/
  /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
   * sharing between Host and HSM through shared buffer*/
  ParamPtr->MacVerAddr = (HostAddr)&Cry_HsmAesCMacVerResult;
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_MAC_VERIFY_C*/
