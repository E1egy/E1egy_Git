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
**  FILENAME   : Cry_HsmAesCMacGenerate.c                                    **
**                                                                           **
**  VERSION :    4.0.0                                                       **
**                                                                           **
**  DATE       : 2018-06-13                                                  **
**                                                                           **
**  VARIANT   : NA                                                           **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR      :  Prashant K                                                **
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
**                      Revision Control History                              **
*******************************************************************************/
/*
<IFX_RCH>
</IFX_RCH>
*/
/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_Hsm_Priv.h"
#include "Cry_HsmAesCMacGenerate.h"

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

Cry_HsmAesCMacGenerateConfigType  Cry_HsmAesCMacGenerateConfig =
        {.TimeOut = CRY_HSM_AES_CMAC_GENERATE_ALL_TIMEOUT};

static Cry_HsmPrimitiveIdType Cry_PRMIDMacGen = CRY_HSM_MAC_GENERATE;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/

/******************************************************************************
**                      Global Structure Declaration                         **
******************************************************************************/
#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
static struct
{
   HsmCom_KeyAddr KeyAddr;
} Cry_HsmAesCMacGenerateData;
#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/******************************************************************************
**                      Global Function Decleartion                          **
******************************************************************************/
#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 41] [$Satisfies $CDS_CDRV 42]     **
**                   [$Satisfies $CDS_CDRV 43] [$Satisfies $CDS_CDRV 44]     **
**                   [$Satisfies $CDS_CDRV 45] [$Satisfies $CDS_CDRV 46]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType Cry_HsmAesCMacGenerateStart(             **
                        const void *CfgPtr, const Csm_SymKeyType *KeyPtr)    **
**                                                                           **
** Description     : This function implements Cry_HsmAesCMacGenerateStart for**
**                 Csm_MacGenerateStart service. It reserves and initializes **
**                 resources for Csm_MacGenerate service and sends request to**
**                  HSM to initiate CMAC generation.                         **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_GENERATE_START                          **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr- Pointer to configuration structure of           **
**                           Cry_HsmAesCMacGenerateConfigType. This parameter**
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
******************************************************************************/
Csm_ReturnType Cry_HsmAesCMacGenerateStart( const void *CfgPtr,
        const Csm_SymKeyType *KeyPtr)
{
  /*To store Return value from Cey Api's*/
  Csm_ReturnType ErrorVal;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  /*To store DET errors*/
  boolean DetErr;
  #endif
  UNUSED_POINTER (CfgPtr)

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_MAC_GENERATE_START , KeyPtr , DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DEV_NO_ERROR == DetErr)
  {
    INIT_VALIDATION(CRY_HSM_SID_MAC_GENERATE_START, Cry_HsmInitStatus ,
                                                                     DetErr)
  }
  if(DEV_NO_ERROR == DetErr)
  {
    KEY_VALIDATION(CRY_HSM_SID_MAC_GENERATE_START,Cry_lCalcKeyAddr(KeyPtr)
                                                                , DetErr)
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
    ErrorVal = Cry_HsmPrimitiveStart(Cry_PRMIDMacGen);
    /* Check if the session opened successfully */
    if(CSM_E_BUSY != ErrorVal)
    {
      /*Store the key*/
      Cry_HsmAesCMacGenerateData.KeyAddr = Cry_lCalcKeyAddr(KeyPtr);
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the indication that START service is successful.
       * To be used by UPDATE and FINISH services to check the
       * DET "CSM_E_SERVICE_NOT_STARTED" */
      Cry_PrimStatus[Cry_PRMIDMacGen] = CRY_HSM_PRIM_STARTED;
      #endif
    }
  }
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that START service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDMacGen] = ASYNC_STATE_START;
  /* Store the service return value.
   * To be used by the main function to report the status to
   * upper layer */
  Cry_PrimErr[Cry_PRMIDMacGen] = ErrorVal;
  #endif
  return ErrorVal;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 47] [$Satisfies $CDS_CDRV 48]     **
**                   [$Satisfies $CDS_CDRV 49] [$Satisfies $CDS_CDRV 50]     **
**                   [$Satisfies $CDS_CDRV 51] [$Satisfies $CDS_CDRV 52]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType  Cry_HsmAesCMacGenerateUpdate(           **
**              const void *CfgPtr, const uint8 *DataPtr, uint32 DataLength) **
**                                                                           **
** Description     :This function implements Cry_HsmAesCMacGenerateUpdate for**
**                  Csm_MacGenerateUpdate service. It sends request to HSM to**
**                   update CMAC generation.                                 **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_GENERATE_UPDATE                         **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr-Pointer to configuration structure of            **
**                          Cry_HsmAesCMacGenerateConfigType                 **
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
******************************************************************************/
Csm_ReturnType Cry_HsmAesCMacGenerateUpdate(const void *CfgPtr,
                                      const uint8 *DataPtr, uint32 DataLength)
{
  /*To store the return value*/
  Csm_ReturnType ErrorVal;
  /*To store the handler for session*/
  Cry_Hsm *HandlePtr;
  /*Pointer containing elements for MacGen update*/
  HsmCom_MacUpdateParams *ParamPtr;
  const Cry_HsmAesCMacGenerateConfigType *MacCfgPtr;

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  /*For Det errors storing*/
  boolean DetErr;
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_MAC_GENERATE_UPDATE, CfgPtr ,DetErr)
  /* Check the next DET only if the DET error doesn't occur.
       DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DEV_NO_ERROR == DetErr)
  {
    PTR_VALIDATION(CRY_HSM_SID_MAC_GENERATE_UPDATE, DataPtr , DetErr)
  }
  if(DEV_NO_ERROR == DetErr)
  {
    START_VALIDATION(CRY_HSM_SID_MAC_GENERATE_UPDATE,
                               Cry_PrimStatus[Cry_PRMIDMacGen] , DetErr)
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
    /* Check the HSM status. COmmand is sent only if the
                     * HSM is not busy */
    ErrorVal = Cry_HsmStatusCheck(Cry_PRMIDMacGen);
    if(CSM_E_OK == ErrorVal)
    {
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the
       * input config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the
       * input config pointer is of type void */
      MacCfgPtr = (const Cry_HsmAesCMacGenerateConfigType *)CfgPtr;
      HandlePtr = &(Cry_HsmData[Cry_PRMIDMacGen]);
      /*Store key address in Session data*/
      HsmCom_SetPackedParams(HandlePtr->Session,
                                Cry_HsmAesCMacGenerateData.KeyAddr,
                                CRY_HSM_AES_MODE_DUMMY);
      /* Get the shared buffer address */
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
       * aligned to the struture pointer containing the elements
       * for MacGeneration */
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /* Update the prameters in shared buffer */
      /*IFX_MISRA_RULE_11_04_STATUS=Type casting is required as the
       * input DataPtr is of type uint8*/
      /*IFX_MISRA_RULE_11_06_STATUS=Type casting is required as the
       * input DataPtr is of type uint8*/
      ParamPtr->SourceAddr = (HostAddr)DataPtr;
      ParamPtr->SizeBytes  =  DataLength;
      /* Send the command to HSM */
      ErrorVal = Cry_HsmSendCommandCommon(HandlePtr,
                       HSMCOM_CMD_MAC_GEN_UPDATE,
                       CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(MacCfgPtr,DataLength));
      /* Make the KEY as invalid as valid KEY has to be
                             sent only for the first UPDATE command */
      Cry_HsmAesCMacGenerateData.KeyAddr = HSMCOM_INVALID_KEY;
    }
  }

  #if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
  /* Set the indication to main function that UPDATE service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDMacGen] = ASYNC_STATE_UPDATE;
  /* Store the service return value.
   * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDMacGen] = ErrorVal;
  #endif
  return ErrorVal;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 53] [$Satisfies $CDS_CDRV 54]     **
**                   [$Satisfies $CDS_CDRV 55] [$Satisfies $CDS_CDRV 56]     **
**                   [$Satisfies $CDS_CDRV 57] [$Satisfies $CDS_CDRV 58]     **
** Syntax          : Csm_ReturnType  Cry_HsmAesCMacGenerateFinish(           **
**                   const void *CfgPtr, uint8 *ResultPtr,                   **
**                   uint32 *ResultLengthPtr, boolean TruncationIsAllowed)   **
**                                                                           **
** Description     : This function implements Cry_HsmAesCMacGenerateFinish   **
                     for Csm_MacGenerateFinish service. It sends request to  **
                     HSM to finalize CMAC generation.                        **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_GENERATE_FINISH                         **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr-Pointer to configuration structure of            **
                            Cry_HsmAesCMacGenerateConfigType                 **
**                   ResultLengthPtr- Pointer to the memory location in which**
**                   the length in byte of the MAC to be returned is stored. **
**                   On calling this function this parameter shall contain a **
**                   size lower or equal to the buffer provided by ResultPtr **
**                   TruncationIsAllowed- Specifies whether a truncation of  **
**                   the result is allowed or not                            **
**                    1. TRUE: truncation is allowed                         **
**                    2. FALSE: truncation is not allowed                    **
**                                                                           **
** Parameters (out): ResultPtr- Pointer to the memory location which will    **
**                    hold the result of the MAC generation. If the generated**
**                    MAC does not fit into the given ResultLength, and      **
**                    truncation is allowed, the result will be truncated.   **
**                   ResultLengthPtr- Pointer to the memory location in which**
**                    the length information is stored.                      **
**                    When the request has finished, the actual length of the**
**                    returned MAC shall be stored. In case of error         **
**                    CSM_E_SMALL_BUFFER the pointer do not need to be       **
**                    updated                                                **
**                                                                           **
** Return value    : CSM_E_OK- Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_SMALL_BUFFER- Request failed due to too small     **
**                                       buffer provided                     **
**                   CSM_E_NOT_OK- Request failed                            **
**                                                                           **
******************************************************************************/
Csm_ReturnType  Cry_HsmAesCMacGenerateFinish(
        const void *CfgPtr, uint8 *ResultPtr,
        uint32 *ResultLengthPtr, boolean TruncationIsAllowed)
{
  /*For handler pointer*/
  Cry_Hsm *HandlePtr;
  /*To store the return value*/
  Csm_ReturnType ErrorVal;
  HsmCom_MacGenerateParams *ParamPtr;
  const Cry_HsmAesCMacGenerateConfigType *MacCfgPtr;

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_MAC_GENERATE_FINISH, CfgPtr , DetErr)
  if(DEV_NO_ERROR == DetErr)
  {
    PTR_VALIDATION(CRY_HSM_SID_MAC_GENERATE_FINISH, ResultLengthPtr,
                                                                      DetErr)
  }
  if(DEV_NO_ERROR == DetErr)
  {
    PTR_VALIDATION(CRY_HSM_SID_MAC_GENERATE_FINISH, ResultPtr, DetErr)
  }
  if(DEV_NO_ERROR == DetErr)
  {
    START_VALIDATION(CRY_HSM_SID_MAC_GENERATE_FINISH,
                                  Cry_PrimStatus[Cry_PRMIDMacGen], DetErr)
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
    /*Assign result length as 16 bytes if of greater length */
    if (*ResultLengthPtr > CRY_HSM_BLOCK_SIZE)
    {
      *ResultLengthPtr = CRY_HSM_BLOCK_SIZE;
    }
    /*If reuslt length is less than 16 bytes & truncation is false,
                                         set error as CSM_E_SMALL_BUFFER*/
    if ((*ResultLengthPtr != CRY_HSM_BLOCK_SIZE) &&
                                            (TruncationIsAllowed == FALSE))
    {
      ErrorVal = CSM_E_SMALL_BUFFER;
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError(CSM_MODULE_ID,CRY_HSM_INSTANCE_ID,
                      (uint8)CRY_HSM_SID_MAC_GENERATE_FINISH,
                      (uint8)CRY_HSM_E_BUFFER_TOO_SMALL);
      #endif
    }
    else
    {
      /* Check the HSM status. COmmand is sent only if the HSM is not busy */
      ErrorVal = Cry_HsmStatusCheck(Cry_PRMIDMacGen);
      if(CSM_E_OK == ErrorVal)
      {
        /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
         * config pointer is of type void*/
        /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
         * config pointer is of type void */
        MacCfgPtr = (const Cry_HsmAesCMacGenerateConfigType *)CfgPtr;
        /*Get the active handle*/
        HandlePtr = &(Cry_HsmData[Cry_PRMIDMacGen]);
        /*Get shared memory address*/
        /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be aligned
         * to the struture pointer containing the elements for MacGeneration */
        ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
        /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        ParamPtr->MacOutputAddr = (HostAddr) ResultPtr;
        ParamPtr->MacLength = *ResultLengthPtr;

        /*Send command to HSM*/
        ErrorVal = Cry_HsmSendCommandCommon(HandlePtr,
                                 HSMCOM_CMD_MAC_GEN_FINISH,
                                 CRY_HSM_GET_FINISH_TIMEOUT_TICKS(MacCfgPtr));

        #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
        Cry_PrimStatus[Cry_PRMIDMacGen] = CRY_HSM_PRIM_FINISHED;
        #endif

        #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
        Cry_lHsmDeinitiateHandle(HandlePtr);
        #else
        if(ErrorVal != CSM_E_OK)
        {
          Cry_lHsmDeinitiateHandle(HandlePtr);
        }
        #endif
      }
    }
  }
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  Cry_PrimStatusAsync[Cry_PRMIDMacGen] = ASYNC_STATE_FINISH;
  Cry_PrimErr[Cry_PRMIDMacGen] = ErrorVal;
  #endif
  return ErrorVal;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 59] [$Satisfies $CDS_CDRV 579]    **
**                                                                           **
** Syntax          : void Cry_HsmAesCMacGenerateMainFunction(void)           **
**                                                                           **
** Description     : This function doesnt exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_MAC_GEN_UPDATE and  **
**                   HSMCOM_CMD_MAC_GEN_FINISH commands and closes the       **
**                   session.                                                **
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
void Cry_HsmAesCMacGenerateMainFunction(void)
{
 Cry_HsmPrimitiveMainFunction(Cry_PRMIDMacGen, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_MAC_GENERATE_C*/
