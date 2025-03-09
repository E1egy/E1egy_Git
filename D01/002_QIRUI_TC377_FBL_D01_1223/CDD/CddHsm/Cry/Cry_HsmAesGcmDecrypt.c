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
**  FILENAME   : Cry_HsmAesGcmDecrypt.c                                      **
**                                                                           **
**  VERSION    : 1.0.0                                                       **
**                                                                           **
**  DATE       : 2016-12-28                                                  **
**                                                                           **
**  VARIANT   : NA                                                           **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR      : Sandeep H                                                  **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the services corresponding to           **
**                                           GCM decryption                  **
**                                                                           **
**  SPECIFICATION(S) :  Aurix_SHE+_TC-CDRV_DS.docx                           **
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
#include "Cry_HsmAesGcmDecrypt.h"
/******************************************************************************
**                      Imported Compiler Switch Check                        *
******************************************************************************/

/******************************************************************************
**                      Private Type Definitions                              *
******************************************************************************/

/******************************************************************************
** Private Constant Definitions (Local preprocessor # define constants)      **
******************************************************************************/

/******************************************************************************
** Private Variable Definitions (Local preprocessor # define macros)         **
******************************************************************************/

/******************************************************************************
**                      Local Type Declarations                              **
******************************************************************************/

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

const Cry_HsmAesGcmDecryptConfigType Cry_kHsmAesGcmDecryptConfig =
     {.TimeOut = CRY_HSM_AES_GCM_DECRYPT_ALL_TIMEOUT};

static const Cry_HsmPrimitiveIdType Cry_PRMIDGCMDec = CRY_HSM_SYM_GCM_DECRYPT;

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
/* Structure for storing the parameters while processing the GCM
 * decrypt service */
static struct
{
  HsmAesGcm_Block Block;
  HsmCom_KeyAddr KeyAddress;
} Cry_HsmAesGcmDecryptData;
#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
**                      Local Object Definitions                             **
******************************************************************************/
/******************************************************************************
** Local function prototypes                                                 **
******************************************************************************/

/******************************************************************************
** Local Inline function definitions and #define function like macros        **
******************************************************************************/
/******************************************************************************
**                      Global Function Definition                           **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 650]                               **
** Syntax          : Csm_ReturnType Cry_HsmAesGcmDecryptStart(               **
**                      const void *CfgPtr, const Csm_SymKeyType *KeyPtr,    **
**                      const uint8 *InitVectorPtr, uint32 InitVectorLength) **
**                                                                           **
** Description     :This function opens a session on CRY for GCM Decryption  **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_GCM_DECRYPT_START                       **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr          :Pointer to configuration structure of  **
**                                    Cry_HsmAesGcmDecryptConfigType         **
**                   KeyPtr          :Pointer to key structure of            **
**                                    Csm_SymKeyType                         **
**                   InitVectorPtr   :Pointer to initialization vector which **
**                                    will be used during GCM                **
**                                    decryption                             **
**                   InitVectorLength:Length of initialization vector        **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK    :Request successful                         **
**                   CSM_E_BUSY  :Request failed due to underlying HSM       **
**                                communication is busy                      **
**                   CSM_E_NOT_OK:Request failed                             **
**                                                                           **
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmAesGcmDecryptStart(
                                       const void *CfgPtr,
                                       const Csm_SymKeyType *KeyPtr,
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
  PTR_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_START, KeyPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_START,InitVectorPtr , DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    INIT_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_START, Cry_HsmInitStatus,
                                                                      DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    KEY_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_START,Cry_lCalcKeyAddr(KeyPtr),
                                                                       DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    if (InitVectorLength != CRY_GCM_IV_LENGTH)
    {
      /* LIMITATION: initial vector length shall be 12 bytes (96 bits) */
      DET_REPORT(CRY_HSM_SID_AES_GCM_DECRYPT_START,
                 CRY_HSM_E_PARAM_METHOD_INVALID, DetErr)
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
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDGCMDec);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      /* Store the  KEY address in the struture to be used later in
       * UPDATE service */
      Cry_HsmAesGcmDecryptData.KeyAddress = Cry_lCalcKeyAddr(KeyPtr);

      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input config
     * pointer is of type uint8 */
      Cry_HsmAesGcmDecryptData.Block =
                                  *((const HsmAesGcm_Block *)InitVectorPtr);

      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the indication that START service is successful. To be used by
       * UPDATE and FINISH services to check the DET
       * "CSM_E_SERVICE_NOT_STARTED" */
      Cry_PrimStatus[Cry_PRMIDGCMDec] = CRY_HSM_PRIM_STARTED;
      #endif
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that START service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDGCMDec] = ASYNC_STATE_START;
  /* Store the service return value. To be used by the main function to report
   * the status to upper layer */
  Cry_PrimErr[Cry_PRMIDGCMDec] = RetVal;
  #endif

  return RetVal;
}
/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 651]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesGcmDecryptUpdate(             **
**                          const void *CfgPtr, const uint8 *CipherTextPtr,  **
**                          uint32 CipherTextLength, uint8 *PlainTextPtr,    **
**                          uint32 *PlainTextLengthPtr, const uint8* AadPtr, **
**                          uint32 AadLength)                                **
**                                                                           **
** Description     :This function sends request to HSM for GCM decryption    **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr             :Pointer to configuration structure  **
**                                       of Cry_HsmAesGcmDecryptConfigType   **
**                   CipherTextPtr      :Pointer to the cipher text that     **
**                                       shall be decrypted                  **
**                   CipherTextLength   :The length of the Cipher text in    **
**                                       bytes                               **
**                   PlainTextLengthPtr :Pointer to the memory location in   **
**                                       which the length information is     **
**                                       stored                              **
**                   AadPtr             :Pointer to initialization additional**
**                                       authenticated data which will be    **
**                                       used during GCM decryption          **
**                   AadLength          :Length of additional authenticated  **
**                                       data vector (in bytes) which will be**
**                                       used during GCM decryption.         **
**                                                                           **
** Parameters (out): PlainTextPtr       :Pointer to the memory location      **
**                                       which will hold the decrypted text. **
**                   PlainTextLengthPtr:Pointer to the memory location       **
**                                       in which the length information is  **
**                                       stored. When the request has        **
**                                       finished, the actual length of the  **
**                                       returned decrypted text will be     **
**                                       stored.                             **
**                                                                           **
** Return value    : CSM_E_OK          :Request successful                   **
**                   CSM_E_BUSY        :Request failed due to underlying HSM **
**                                      communication is busy                **
**                   CSM_E_SMALL_BUFFER:Request failed due to too small      **
**                                      buffer provided                      **
**                   CSM_E_NOT_OK      :Request failed                       **
**                                                                           **
******************************************************************************/
Csm_ReturnType  Cry_HsmAesGcmDecryptUpdate(
                             const void *CfgPtr, const uint8 *CipherTextPtr,
                             uint32 CipherTextLength, uint8 *PlainTextPtr,
                             uint32 *PlainTextLengthPtr,
                             const uint8 *AadPtr, uint32 AadLength)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmAesGcmDecryptConfigType *GcmCfgPtr;
  /*Pointer to the structure that defines the parameters to be stored
    in shared buffer */
  HsmCom_CryptGcmUpdateParams *ParamPtr;

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;

  PTR_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE, CipherTextPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE, PlainTextPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE, PlainTextLengthPtr,
                                                                  DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE, AadPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE,
                                   Cry_PrimStatus[Cry_PRMIDGCMDec], DetErr)
  }
  /* If any DET error occurs, return CSM_E_NOT_OK. Further processing
   * is not required */
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
                      (uint8)CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE,
                      (uint8)CRY_HSM_E_BUFFER_TOO_SMALL);
      #endif
    }
    else
    {
      /* Check the HSM status. COmmand is sent only if the HSM is not busy */
      RetVal = Cry_HsmStatusCheck(Cry_PRMIDGCMDec);
      if(RetVal == CSM_E_OK)
      {
        /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
          config pointer is of type void*/
        /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
       * config pointer is of type void */
        GcmCfgPtr = (const Cry_HsmAesGcmDecryptConfigType *) CfgPtr;
        HandlePtr = &(Cry_HsmData[Cry_PRMIDGCMDec]);

       /* Store the Sesion and KEY address in session data. To be updated into
        * the HT2HSMF register later while sending the command */
        HsmCom_SetPackedParams(HandlePtr->Session,
                               Cry_HsmAesGcmDecryptData.KeyAddress,
                               CRY_HSM_AES_MODE_GCM);

        /* Get the shared buffer address */
        /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
       * config pointer is of type void */
        ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
        /* Update the prameters in shared buffer */
        /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        ParamPtr->InitialVarAddr = (HostAddr)&Cry_HsmAesGcmDecryptData.Block;
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

        /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        ParamPtr->AADSource = (HostAddr)AadPtr;
        ParamPtr->AADLen = AadLength;

        /* Send the command to HSM */
        RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                   HSMCOM_CMD_GCM_DECRYPT_UPDATE,
                   CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(GcmCfgPtr,
                           (CipherTextLength + AadLength)));
        Cry_HsmAesGcmDecryptData.KeyAddress = HSMCOM_INVALID_KEY;

        *PlainTextLengthPtr = CipherTextLength;

      }
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that UPDATE service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDGCMDec] = ASYNC_STATE_UPDATE;
  /* Store the service return value. To be used by the main function to do
   * further processing */
  Cry_PrimErr[Cry_PRMIDGCMDec] = RetVal;
  #endif

  return RetVal;
}
/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 652]                               **
** Syntax          : Csm_ReturnType Cry_HsmAesGcmDecryptFinish(              **
**                                  const void *CfgPtr,                      **
**                                  Csm_VerifyResultType *AuthTagResultPtr,  **
**                                  const uint8 *AuthTagPtr,                 **
**                                  uint32 AuthTagLen)                       **
**                                                                           **
** Description     : This function finalizes calculation and closes the      **
**                   session that was called for GCM decryption              **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_GCM_DECRYPT_FINISH                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr             :Pointer to configuration structure  **
**                                       of Cry_HsmAesGcmDecryptConfigType   **
**                   AuthTagPtr         :This parameter shall contain the    **
**                                       input authentication tag to be      **
**                                       compared                            **
**                   AuthtagLen         :Number of authetication tag bytes   **
**                                       to be compared                      **
** Parameters (out): AuthTagResultPtr   :Result of authentication tag        **
**                                       comparison                          **
**                                                                           **
** Return value    : CSM_E_OK     :Request successful                        **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK :Request failed                            **
**                                                                           **
******************************************************************************/
Csm_ReturnType  Cry_HsmAesGcmDecryptFinish( const void *CfgPtr,
                                     Csm_VerifyResultType *AuthTagResultPtr,
                                     const uint8 *AuthTagPtr,
                                     uint32 AuthTagLen)
{

  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmAesGcmDecryptConfigType *GcmCfgPtr;
  /*Pointer to the structure that defines the parameters to be stored
    in shared buffer */
  HsmCom_CryptGcmFinishParams *ParamPtr;

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_FINISH, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_FINISH, AuthTagResultPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_FINISH, AuthTagPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_AES_GCM_DECRYPT_FINISH,
                     Cry_PrimStatus[Cry_PRMIDGCMDec], DetErr)
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
    /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input config
     * pointer is of type void*/
    /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the
     * input config pointer is of type void */
    GcmCfgPtr = (const Cry_HsmAesGcmDecryptConfigType *) CfgPtr;
    /* Check the HSM status. COmmand is sent only if the
     * HSM is not busy */
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDGCMDec);
    if(RetVal == CSM_E_OK)
    {
      /* Get the active handle for the primitive */
      HandlePtr = &(Cry_HsmData[Cry_PRMIDGCMDec]);

      /* Store Mode and KEY address in session data */
       HsmCom_SetPackedParams(HandlePtr->Session,
                              Cry_HsmAesGcmDecryptData.KeyAddress,
                              CRY_HSM_AES_MODE_GCM);

      /* Get the shared buffer address */
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
     * config pointer is of type void */
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
      ParamPtr->AuthTagSource = (HostAddr)AuthTagPtr;
      ParamPtr->AuthTagLength = AuthTagLen;
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
      ParamPtr->AuthTagResultAddr = (HostAddr)AuthTagResultPtr;
      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                                HSMCOM_CMD_GCM_DECRYPT_FINISH,
                                CRY_HSM_GET_FINISH_TIMEOUT_TICKS(GcmCfgPtr));
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the primitive status to FINISHED. Status will be changed again if
       * the START is executed successfully */
      Cry_PrimStatus[Cry_PRMIDGCMDec] = CRY_HSM_PRIM_FINISHED;
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
  Cry_PrimStatusAsync[Cry_PRMIDGCMDec] = ASYNC_STATE_FINISH;
  /* Store the service return value.
   * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDGCMDec] = RetVal;
  #endif

  return RetVal;
}
/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 653]                               **
**                                                                           **
** Syntax          :  void Cry_HsmAesGcmDecryptMainFunction(void)            **
**                                                                           **
** Description     : This function doesnt exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation, this function checks **
**                   the command response for                                **
**                   HSMCOM_CMD_AES_GCM_DECRYPT_UPDATE and                   **
**                   HSMCOM_CMD_AES_GCM_DECRYPT_FINISH commands and closes   **
**                   the session.                                            **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
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
void Cry_HsmAesGcmDecryptMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDGCMDec, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_GCM_DECRYPT_C*/
