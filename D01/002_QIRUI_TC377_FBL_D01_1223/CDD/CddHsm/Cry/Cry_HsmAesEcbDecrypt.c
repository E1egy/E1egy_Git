/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Cry_HsmAesEcbDecrypt.c                                      **
**                                                                            **
**  VERSION     : 3.0.0                                                       **
**                                                                            **
**  DATE        : 2018-06-13                                                  **
**                                                                            **
**  VARIANT     : NA                                                          **
**                                                                            **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                               **
**                [Refer Release Package for Supported Device]                **
**  AUTHOR      : Prashant K                                                  **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains the services related to ECB Decryption   **
**                                                                            **
**  SPECIFICATION(S) :  Aurix_SHE+_TC-CDRV_DS.docx                            **
**                                                                            **
**  MAY BE CHANGED BY USER : No                                               **
**                                                                            **
*******************************************************************************/
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
#include "Cry_HsmAesEcbDecrypt.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
** Private Constant Definitions (Local preprocessor # define constants)       **
*******************************************************************************/

/*******************************************************************************
** Private Variable Definitions (Local preprocessor # define macros)          **
*******************************************************************************/
/*******************************************************************************
**                      Local Type Declarations                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant variable Definitions                  **
*******************************************************************************/
#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

const Cry_HsmAesEcbDecryptConfigType    Cry_kHsmAesEcbDecryptConfig =
        {.TimeOut = CRY_HSM_AES_ECB_DECRYPT_ALL_TIMEOUT};

static const Cry_HsmPrimitiveIdType Cry_PRMIDEcbDec = CRY_HSM_SYM_ECB_DECRYPT;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
#else
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"

Cry_HsmAesEcbDecryptConfigType    Cry_kHsmAesEcbDecryptConfig =
        {.TimeOut = CRY_HSM_AES_ECB_DECRYPT_ALL_TIMEOUT};

static Cry_HsmPrimitiveIdType Cry_PRMIDEcbDec = CRY_HSM_SYM_ECB_DECRYPT;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
#endif
/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/

/******************************************************************************
**                      Global Function Decleartion                          **
******************************************************************************/
#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_CODE
#else
#define CRY_START_SEC_RAMCODE
#endif
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 146] [$Satisfies $CDS_CDRV 147]    **
**                   [$Satisfies $CDS_CDRV 148] [$Satisfies $CDS_CDRV 149]    **
**                   [$Satisfies $CDS_CDRV 150] [$Satisfies $CDS_CDRV 579]    **
** Syntax          :   Csm_ReturnType Cry_HsmAesEcbDecryptStart(              **
**                                             const void *CfgPtr,            **
**                                             const Csm_SymKeyType *KeyPtr)  **
**                                                                            **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbDecryptStart for   **
**                   Csm_SymBlockDecryptStart service. It reserves and        **
**                   initializes resources for Csm_SymBlockDecrypt service    **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_DECRYPT_START                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmAesEcbDecryptConfigType.                 **
**                   KeyPtr - Pointer to key structure of Csm_SymKeyType.     **
**                            This key has to be used during the symmetrical  **
**                            ECB decryption operation                        **
**                            1. KeyPtr->length shall be 1                    **
**                            2. KeyPtr->data[0] shall be a value taken from  **
**                            Cry_HsmKeySlotIdType and is used to calculate   **
**                            global key address                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
**                                                                            **
*******************************************************************************/
Csm_ReturnType Cry_HsmAesEcbDecryptStart(
                                          const void *CfgPtr,
                                          const Csm_SymKeyType *KeyPtr)
{
  Csm_ReturnType RetVal;
    Cry_Hsm *HandlePtr;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  #endif

  UNUSED_POINTER (CfgPtr)

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_AES_ECB_DECRYPT_START, KeyPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   *  DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    INIT_VALIDATION(CRY_HSM_SID_AES_ECB_DECRYPT_START, Cry_HsmInitStatus,
                                                                DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    KEY_VALIDATION(CRY_HSM_SID_AES_ECB_DECRYPT_START,
                   Cry_lCalcKeyAddr(KeyPtr), DetErr)
  }
  /* If any DET error occurs, return CSM_E_NOT_OK. Further processing is not
   * required */
  if(DetErr != DEV_NO_ERROR)
  {
    RetVal = CSM_E_NOT_OK;
  }
  else
  #endif
  {
   /* Initiate the handle for the session */
   RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDEcbDec);
   /* Check if the session opened successfully */
   if(RetVal != CSM_E_BUSY)
   {
     HandlePtr = Cry_lHsmGetActiveHandle(Cry_PRMIDEcbDec);
     /* Store the key address and AES mode in session data. To be used in
      * UPDATE service while sending the command. AES mode is dummy for this
      * primitive */
     HsmCom_SetPackedParams(HandlePtr->Session, Cry_lCalcKeyAddr(KeyPtr),
                            CRY_HSM_AES_MODE_DUMMY);
     #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
     /* Set the indication that START service is successful. To be used by
      * UPDATE and FINISH services to check the DET
      * "CSM_E_SERVICE_NOT_STARTED" */
     Cry_PrimStatus[Cry_PRMIDEcbDec] = CRY_HSM_PRIM_STARTED;
     #endif
   }
 }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that START service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDEcbDec] = ASYNC_STATE_START;
  /* Store the service return value.
   * To be used by the main function to report the status to upper layer */
  Cry_PrimErr[Cry_PRMIDEcbDec] = RetVal;
  #endif

  return RetVal;
/*IFX_MISRA_RULE_08_13_STATUS=HandlePtr can't be declared as const*/
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 151] [$Satisfies $CDS_CDRV 152]    **
**                   [$Satisfies $CDS_CDRV 153] [$Satisfies $CDS_CDRV 154]    **
**                   [$Satisfies $CDS_CDRV 155] [$Satisfies $CDS_CDRV 156]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesEcbDecryptUpdate(              **
**                                              const void *CfgPtr,           **
**                                              const uint8 *CipherTextPtr,   **
**                                              uint32 CipherTextLength,      **
**                                              uint8 *PlainTextPtr,          **
**                                              uint32 *PlainTextLengthPtr)   **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbDecryptUpdate for  **
**                    Csm_SymBlockDecryptUpdate service. It sends request to  **
**                    HSM for AES ECB mode decryption.                        **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr             - Pointer to configuration structure  **
**                                        of Cry_HsmAesEcbDecryptConfigType   **
**                   CipherTextPtr      - Pointer to the cipher text that     **
**                                        shall be decrypted                  **
**                   CipherTextLength   - The length of the cipher text in    **
**                                        bytes that should be 16             **
**                   PlainTextLengthPtr - Pointer to the memory location in   **
**                                        which the length information is     **
**                                        stored.On calling this function this**
**                                        parameter shall contain the size of **
**                                        the provided buffer which should be **
**                                        greater than or equal to the        **
**                                        CipherTextLength parameter.         **
**                                                                            **
** Parameters (out): PlainTextPtr       - Pointer to the memory location which**
**                                        will hold the decrypted text        **
**                   PlainTextLengthPtr - Pointer to the memory location in   **
**                                        which the length information is     **
**                                        stored. When the request has        **
**                                        finished, the actual length of the  **
**                                        returned decrypted text shall be    **
**                                        stored                              **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_SMALL_BUFFER - Request failed due to too small     **
**                                         buffer provided                    **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType  Cry_HsmAesEcbDecryptUpdate(
                                            const void *CfgPtr,
                                            const uint8 *CipherTextPtr,
                                            uint32 CipherTextLength,
                                            uint8 *PlainTextPtr,
                                            uint32 *PlainTextLengthPtr)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmAesEcbDecryptConfigType *AesCfgPtr;
  HsmCom_CryptParams *ParamPtr; /*Pointer to the structure that defines
                                  the parameters to be stored in shared
                                  buffer */
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
      PTR_VALIDATION(CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE,
                     CipherTextPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE,
                   PlainTextPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE,
                   PlainTextLengthPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE,
                                 Cry_PrimStatus[Cry_PRMIDEcbDec],DetErr)
  }
  /* If any DET error occurs, return CSM_E_NOT_OK. Further processing is not
   * required */
  if(DetErr != DEV_NO_ERROR)
  {
    RetVal = CSM_E_NOT_OK;
  }
  else
  #endif
  {
    if ((CipherTextLength != CRY_HSM_BLOCK_SIZE) ||
        (*PlainTextLengthPtr < CipherTextLength) )
    {
      RetVal = CSM_E_SMALL_BUFFER;
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* LIMITATION: we only support length of 16 and equal length of plain
       * text and cipher text */
      Det_ReportError(CSM_MODULE_ID,CRY_HSM_INSTANCE_ID,
                      (uint8)CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE,
                      (uint8)CRY_HSM_E_BUFFER_TOO_SMALL);
      #endif
    }
    else
    {
      /* Check the HSM status. COmmand is sent only if the HSM is not busy */
      RetVal = Cry_HsmStatusCheck(Cry_PRMIDEcbDec);
      if(RetVal == CSM_E_OK)
      {
        HandlePtr = &(Cry_HsmData[Cry_PRMIDEcbDec]);

        /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
         * config pointer is of type void*/
        /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
         * config pointer is of type void */
        AesCfgPtr = (const Cry_HsmAesEcbDecryptConfigType *) CfgPtr;

        /* Get the shared buffer address */
        /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be  aligned
         * to the struture pointer containing the elements for MacGeneration*/
        ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);

        /* Update the prameters in shared buffer */
        /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        ParamPtr->SourceAddr = (HostAddr)CipherTextPtr;
        /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        ParamPtr->DestAddr   = (HostAddr)PlainTextPtr;
        ParamPtr->NBlocks    = 1U;

        /* Send the command to HSM */
        RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                HSMCOM_CMD_ECB_DECRYPT,
                CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(AesCfgPtr,CipherTextLength));

        *PlainTextLengthPtr = CipherTextLength;

      }
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that UPDATE service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDEcbDec] = ASYNC_STATE_UPDATE;
  /* Store the service return value.
   * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDEcbDec] = RetVal;
  #endif

  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 157] [$Satisfies $CDS_CDRV 158]    **
**                   [$Satisfies $CDS_CDRV 159] [$Satisfies $CDS_CDRV 160]    **
**                   [$Satisfies $CDS_CDRV 161] [$Satisfies $CDS_CDRV 162]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesEcbDecryptFinish(              **
**                                          const void *CfgPtr,               **
**                                          uint8 *PlainTextPtr,              **
**                                          uint32 *PlainTextLengthPtr)       **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbDecryptFinish for  **
**                   Csm_SymBlockDecryptFinish service. It releases resources **
**                   used by Csm_SymBlockDecrypt service. This function       **
**                   invokes function that closes the HSM communication       **
**                   session                                                  **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_DECRYPT_FINISH                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr             - Pointer to configuration structure  **
**                                        of Cry_HsmAesEcbDecryptConfigType.  **
**                   PlainTextPtr       - PlainTextPtr is ignored             **
**                   PlainTextLengthPtr - PlainTextLengthPtr is ignored       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM         **
**                               communication is busy                        **
**                   CSM_E_NOT_OK - Request failed                            **
**                                                                            **
*******************************************************************************/
Csm_ReturnType  Cry_HsmAesEcbDecryptFinish(
                                           const void *CfgPtr,
                                           uint8 *PlainTextPtr,
                                           uint32 *PlainTextLengthPtr)
{
  Csm_ReturnType RetVal;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  #endif
  UNUSED_POINTER (CfgPtr)
  UNUSED_POINTER (PlainTextPtr)
  UNUSED_POINTER (PlainTextLengthPtr)

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  START_VALIDATION(CRY_HSM_SID_AES_ECB_DECRYPT_FINISH,
                             Cry_PrimStatus[Cry_PRMIDEcbDec], DetErr)
  /* If any DET error occurs, return CSM_E_NOT_OK. Further processing is not
   * required */
  if(DetErr != DEV_NO_ERROR)
  {
    RetVal = CSM_E_NOT_OK;
  }
  else
  #endif
  {
    /* Check the HSM status. Session is not closed if HSM is BUSY */
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDEcbDec);
    if(RetVal == CSM_E_OK)
    {
      /* Finish the primitive by closing the session */
      RetVal = Cry_HsmPrimitiveFinish(Cry_PRMIDEcbDec);
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      if(RetVal == CSM_E_OK)
      {
        /* Set the primitive status to FINISHED.Status will be changed again if
         * the START is executed successfully */
        Cry_PrimStatus[Cry_PRMIDEcbDec] = CRY_HSM_PRIM_FINISHED;
      }
      #endif
    }
  }
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that FINISH service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDEcbDec] = ASYNC_STATE_FINISH;
  /* Store the service return value. To be used by the main function to do
   * further processing */
  Cry_PrimErr[Cry_PRMIDEcbDec] = RetVal;
  #endif

  return RetVal;
  /*IFX_MISRA_RULE_08_13_STATUS=Function prototype can't be changed*/
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 163] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : void Cry_HsmAesEcbDecryptMainFunction(void)              **
**                                                                            **
** Description     : This function doesnt exist in case of synchronous        **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON. In case **
**                   of asynchronous operation, this function checks the      **
**                   command response for HSMCOM_CMD_ECB_DECRYPT command and  **
**                   closes the session                                       **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
void Cry_HsmAesEcbDecryptMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDEcbDec, NULL_PTR);
}
#endif

#ifdef CONTROLLER_TC23x
#define CRY_STOP_SEC_CODE
#else
#define CRY_STOP_SEC_RAMCODE
#endif
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_ECB_DECRYPT_C*/
