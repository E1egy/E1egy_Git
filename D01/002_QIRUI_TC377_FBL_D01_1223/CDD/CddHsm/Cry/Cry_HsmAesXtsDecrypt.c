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
**  FILENAME    : Cry_HsmAesXtsDecrypt.c                                      **
**                                                                            **
**  VERSION     : 1.0.0                                                       **
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
**  DESCRIPTION : This file contains the services related to XTS Decryption   **
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
#include "Cry_HsmAesXtsDecrypt.h"
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
#define CRY_START_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

const Cry_HsmAesXtsDecryptConfigType    Cry_kHsmAesXtsDecryptConfig =
                              {.TimeOut = CRY_HSM_AES_XTS_DECRYPT_ALL_TIMEOUT};

static const Cry_HsmPrimitiveIdType Cry_PRMIDXtsDec = CRY_HSM_SYM_XTS_DECRYPT;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/

/******************************************************************************
**                     Global Structure Definition                           **
******************************************************************************/

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/* Structure for storing the parameters while processing the XTS
 * decrypt service */
static struct
{
  HsmAes_Block Block;
  HostAddr Param2;
  HsmCom_KeyAddr KeyAddress1;
  HsmCom_KeyAddr KeyAddress2;
} Cry_HsmAesXtsDecryptData;
#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/*******************************************************************************
**                      Local Object Definitions                              **
*******************************************************************************/

/*******************************************************************************
** Local function prototypes                                                  **
*******************************************************************************/

/*******************************************************************************
** Local Inline function definitions and #define function like macros         **
*******************************************************************************/

/******************************************************************************
**                      Global Function Decleartion                          **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 682] [$Satisfies $CDS_CDRV 683]    **
**                   [$Satisfies $CDS_CDRV 684] [$Satisfies $CDS_CDRV 685]    **
**                   [$Satisfies $CDS_CDRV 686] [$Satisfies $CDS_CDRV 687]    **
**                   [$Satisfies $CDS_CDRV 688] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : Csm_ReturnType Cry_HsmAesXtsDecryptStart(                **
**                                        const void *CfgPtr,                 **
**                                        const Csm_SymKeyType *KeyPtr1,      **
**                                        const Csm_SymKeyType *KeyPtr2,      **
**                                        const uint8 *InitVectorPtr,         **
**                                        uint32 InitVectorLength)            **
**                                                                            **
** Description     : This function implements Cry_HsmAesXtsDecryptStart which **
**                   reserves and initializes resources for XTS service       **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_XTS_DECRYPT_START                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmAesXtsDecryptConfigType                  **
**                   KeyPtr1 - Pointer to key structure of Csm_SymKeyType.This**
**                             key has to be used during the symmetrical XTS  **
**                             Decryption operation                           **
**                             1) KeyPtr->length shall be 1                   **
**                             2) KeyPtr->data[0] shall be a value taken from **
**                             Cry_HsmKeySlotIdType and is used to calculate  **
**                             global key address                             **
**                   KeyPtr2 - Pointer to key structure of Csm_SymKeyType.This**
**                             will be used only for XTS mode                 **
**                   InitVectorPtr - Pointer to initialization vector which   **
**                                   will be used during symmetrical XTS      **
**                                   decryption                               **
**                   InitVectorLength - Length of initialization vector       **
**                                      which will be used during symmetrical **
**                                      XTS Decryption                        **
**                                      - InitVectorLength shall be 16        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType Cry_HsmAesXtsDecryptStart( const void *CfgPtr,
                                          const Csm_SymKeyType *KeyPtr1,
                                          const Csm_SymKeyType *KeyPtr2,
                                          const uint8 *InitVectorPtr,
                                          uint32 InitVectorLength)
{
  Csm_ReturnType RetVal;

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  #endif

  UNUSED_POINTER (CfgPtr)

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;

  PTR_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_START, KeyPtr1, DetErr)

  /* Check the next DET only if the DET error doesn't occur.
   *  DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_START, KeyPtr2, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_START, InitVectorPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    INIT_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_START, Cry_HsmInitStatus,
                                                                   DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    KEY_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_START,
                                      Cry_lCalcKeyAddr(KeyPtr1), DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    KEY_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_START,
                                      Cry_lCalcKeyAddr(KeyPtr2), DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    if (InitVectorLength != CRY_HSM_BLOCK_SIZE)
    {
      DET_REPORT(CRY_HSM_SID_AES_XTS_DECRYPT_START,
                 CRY_HSM_E_PARAM_METHOD_INVALID,
                 DetErr)
    }
  }
  /* If any DET error occurs, return CSM_E_NOT_OK. Further processing is not
   * required */
  if(DetErr != DEV_NO_ERROR)
  {
    RetVal = CSM_E_NOT_OK;
  }
  else
  #else
  UNUSED_PARAMETER (InitVectorLength);
  #endif
  {
    /* Initiate the handle for the session */
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDXtsDec);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      /* Store the AES mode and KEY address in the struture to be used later in
      * UPDATE service */
      Cry_HsmAesXtsDecryptData.KeyAddress1 = Cry_lCalcKeyAddr(KeyPtr1);
      Cry_HsmAesXtsDecryptData.KeyAddress2 = Cry_lCalcKeyAddr(KeyPtr2);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      Cry_HsmAesXtsDecryptData.Param2 =
                                   (HostAddr)&Cry_HsmAesXtsDecryptData.Block;
      /*IFX_MISRA_RULE_11_03_STATUS=Typecasting is required as Input Pointer
       * InitVectorPtr is of type uint8*/
      Cry_HsmAesXtsDecryptData.Block = *((const HsmAes_Block*)InitVectorPtr);
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the indication that START service is successful. To be used by
       * UPDATE and FINISH services to check the DET
       * "CSM_E_SERVICE_NOT_STARTED" */
      Cry_PrimStatus[Cry_PRMIDXtsDec] = CRY_HSM_PRIM_STARTED;
      #endif
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that START service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDXtsDec] = ASYNC_STATE_START;
  /* Store the service return value.
   * To be used by the main function to report the status to upper layer */
  Cry_PrimErr[Cry_PRMIDXtsDec] = RetVal;
  #endif

  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 689] [$Satisfies $CDS_CDRV 690]    **
**                   [$Satisfies $CDS_CDRV 691] [$Satisfies $CDS_CDRV 692]    **
**                   [$Satisfies $CDS_CDRV 693] [$Satisfies $CDS_CDRV 694]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
**                                                                            **
** Syntax          : Csm_ReturnType  Cry_HsmAesXtsDecryptUpdate(              **
**                                              const void *CfgPtr,           **
**                                              const uint8 *CipherTextPtr,   **
**                                              uint32 CipherTextLength,      **
**                                              uint8 *PlainTextPtr,          **
**                                              uint32 *PlainTextLengthPtr)   **
**                                                                            **
** Description     : This function implements Cry_HsmAesXtsDecryptUpdate which**
**                   sends request to HSM for AES decryption using XTS mode   **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr             - Pointer to configuration structure  **
**                                        of Cry_HsmAesXtsDecryptConfigType   **
**                   CipherTextPtr      - Pointer to the cipher text that     **
**                                        shall be decrypted                  **
**                   CipherTextLength   - The length of the cipher text in    **
**                                        bytes                               **
**                                         - shall be multiple of 16          **
**                                           (Minimum one 16 bytes block).    **
**                                         - shall be less than or equal to   **
**                                           plainTextLength.                **
**                                         - Last update can be <16 bytes or  **
**                                           >16 bytes.                       **
**                                                                            **
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
Csm_ReturnType  Cry_HsmAesXtsDecryptUpdate(
                                            const void *CfgPtr,
                                            const uint8 *CipherTextPtr,
                                            uint32 CipherTextLength,
                                            uint8 *PlainTextPtr,
                                            uint32 *PlainTextLengthPtr)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmAesXtsDecryptConfigType *XtsCfgPtr;
  /*Pointer to the structure that defines the parameters to be stored
    in shared buffer */
  HsmCom_CryptXtsParams *ParamPtr;

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE,
                     CipherTextPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE,
                   PlainTextPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE,
                   PlainTextLengthPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE,
                                 Cry_PrimStatus[Cry_PRMIDXtsDec],DetErr)
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
    if (CipherTextLength > *PlainTextLengthPtr)
    {
      RetVal = CSM_E_SMALL_BUFFER;
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError(CSM_MODULE_ID,CRY_HSM_INSTANCE_ID,
                      (uint8)CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE,
                      (uint8)CRY_HSM_E_BUFFER_TOO_SMALL);
      #endif
    }
    else
    {
      /* Check the HSM status. COmmand is sent only if the HSM is not busy*/
      RetVal = Cry_HsmStatusCheck(Cry_PRMIDXtsDec);
      if(RetVal == CSM_E_OK)
      {
        /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
         * config pointer is of type void*/
        /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
         * config pointer is of type void */
        XtsCfgPtr = (const Cry_HsmAesXtsDecryptConfigType *) CfgPtr;
        HandlePtr = &(Cry_HsmData[Cry_PRMIDXtsDec]);
        /* Store the Session and KEY address in session data. To be updated
         * into the HT2HSMF register later while sending the command */
        HsmCom_SetPackedParams(HandlePtr->Session,
                               Cry_HsmAesXtsDecryptData.KeyAddress1,
                               CRY_HSM_AES_MODE_XTS);
        /* Get the shared buffer address */
        /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be aligned
         * to the struture pointer containing the elements for AES Encryption*/
        ParamPtr= HsmCom_GetParamsBuffer(HandlePtr->Session);
        /* Update the parameters in shared buffer */
        ParamPtr->InitialVarAddr = Cry_HsmAesXtsDecryptData.Param2;
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
        ParamPtr->DestAddr = (HostAddr)PlainTextPtr;
        ParamPtr->InputLength = CipherTextLength;
        ParamPtr->KeyId2 = Cry_HsmAesXtsDecryptData.KeyAddress2;
        /* Send the command to HSM */
        RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                HSMCOM_CMD_XTS_DECRYPT_UPDATE,
                CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(XtsCfgPtr,CipherTextLength));
        Cry_HsmAesXtsDecryptData.KeyAddress1 = HSMCOM_INVALID_KEY;
        Cry_HsmAesXtsDecryptData.KeyAddress2 = HSMCOM_INVALID_KEY;
        *PlainTextLengthPtr = CipherTextLength;

      }
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that UPDATE service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDXtsDec] = ASYNC_STATE_UPDATE;
  /* Store the service return value.
   * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDXtsDec] = RetVal;
  #endif

  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 695] [$Satisfies $CDS_CDRV 696]    **
**                   [$Satisfies $CDS_CDRV 697] [$Satisfies $CDS_CDRV 698]    **
**                   [$Satisfies $CDS_CDRV 699] [$Satisfies $CDS_CDRV 700]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
**                                                                            **
** Syntax          : Csm_ReturnType  Cry_HsmAesXtsDecryptFinish(              **
**                                          const void *CfgPtr,               **
**                                          uint8 *PlainTextPtr,              **
**                                          uint32 *PlainTextLengthPtr)       **
**                                                                            **
** Description     : This function implements Cry_HsmAesXtsDecryptFinish which**
**                   releases resources used by AES XTS mode.                 **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_XTS_DECRYPT_FINISH                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr             - Pointer to configuration structure  **
**                                        of Cry_HsmAesXtsDecryptConfigType.  **
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
Csm_ReturnType  Cry_HsmAesXtsDecryptFinish(
                                           const void *CfgPtr,
                                           uint8 *PlainTextPtr,
                                           uint32 *PlainTextLengthPtr)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmAesXtsDecryptConfigType *XtsCfgPtr;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  #endif
  UNUSED_POINTER (PlainTextPtr)
  UNUSED_POINTER (PlainTextLengthPtr)

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_FINISH, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_AES_XTS_DECRYPT_FINISH,
                             Cry_PrimStatus[Cry_PRMIDXtsDec], DetErr)
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
    /* Check the HSM status. Session is not closed if HSM is BUSY */
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDXtsDec);
    if(RetVal == CSM_E_OK)
    {
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
       * config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
       * config pointer is of type void */
      XtsCfgPtr = (const Cry_HsmAesXtsDecryptConfigType *) CfgPtr;
      /* Finish the primitive by closing the session */
      /* Get the active handle for the primitive */
      HandlePtr = &(Cry_HsmData[Cry_PRMIDXtsDec]);

      /* Store the Mode and KEY address in session data */
      HsmCom_SetPackedParams(HandlePtr->Session,
                             Cry_HsmAesXtsDecryptData.KeyAddress1,
                             CRY_HSM_AES_MODE_XTS);

      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                             HSMCOM_CMD_XTS_DECRYPT_FINISH,
                             CRY_HSM_GET_FINISH_TIMEOUT_TICKS(XtsCfgPtr));
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
        /* Set the primitive status to FINISHED.Status will be changed again if
         * the START is executed successfully */
        Cry_PrimStatus[Cry_PRMIDXtsDec] = CRY_HSM_PRIM_FINISHED;
      #endif

      #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
      /* For Sync mode, close the session irrespective of command result */
      Cry_lHsmDeinitiateHandle(HandlePtr);
      #else
      /* For Async mode, close the session only if the command fails. If the
       * command is successful, main function does further processing of the
       * command and closes the session  */
      if(RetVal != CSM_E_OK)
      {
        Cry_lHsmDeinitiateHandle(HandlePtr);
      }
      #endif
    }
  }
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that FINISH service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDXtsDec] = ASYNC_STATE_FINISH;
  /* Store the service return value. To be used by the main function to do
   * further processing */
  Cry_PrimErr[Cry_PRMIDXtsDec] = RetVal;
  #endif
  return RetVal;
  /*IFX_MISRA_RULE_08_13_STATUS=Function prototype can't be changed*/
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 701]  [$Satisfies $CDS_CDRV 579]   **
**                                                                            **
** Syntax          : void Cry_HsmAesXtsDecryptMainFunction(void)              **
**                                                                            **
** Description     : This function doesnt exist in case of synchronous        **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON. In case **
**                   of asynchronous operation, this function checks the      **
**                   command response for XTS decryption commands and         **
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
void Cry_HsmAesXtsDecryptMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDXtsDec, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_XTS_DECRYPT_C*/
