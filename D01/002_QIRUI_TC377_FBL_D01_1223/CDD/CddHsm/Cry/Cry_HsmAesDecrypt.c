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
**  FILENAME   : Cry_HsmAesDecrypt.c                                         **
**                                                                           **
**  VERSION :   3.0.0                                                        **
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
**  DESCRIPTION : This file contains the services corresponding to           **
**                                           AES decryption                  **
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
#include "Cry_HsmAesDecrypt.h"
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
#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

const Cry_HsmAesDecryptConfigType       Cry_kHsmAesDecryptConfigModeCbc =
     {.Mode = CRY_HSM_AES_MODE_CBC,.TimeOut = CRY_HSM_AES_DECRYPT_ALL_TIMEOUT};

const Cry_HsmAesDecryptConfigType       Cry_kHsmAesDecryptConfigModeCtr =
     {.Mode = CRY_HSM_AES_MODE_CTR,.TimeOut = CRY_HSM_AES_DECRYPT_ALL_TIMEOUT};

const Cry_HsmAesDecryptConfigType       Cry_kHsmAesDecryptConfigModeOfb =
     {.Mode = CRY_HSM_AES_MODE_OFB,.TimeOut = CRY_HSM_AES_DECRYPT_ALL_TIMEOUT};

const Cry_HsmAesDecryptConfigType       Cry_kHsmAesDecryptConfigModeCfb =
     {.Mode = CRY_HSM_AES_MODE_CFB,.TimeOut = CRY_HSM_AES_DECRYPT_ALL_TIMEOUT};

static const Cry_HsmPrimitiveIdType Cry_PRMIDSymDec = CRY_HSM_SYM_DECRYPT;
#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
#endif
/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/

/******************************************************************************
**                     Global Structure Definition                           **
******************************************************************************/
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
#ifndef CONTROLLER_TC23x

Cry_HsmAesDecryptConfigType       Cry_kHsmAesDecryptConfigModeCbc =
     {.Mode = CRY_HSM_AES_MODE_CBC,.TimeOut = CRY_HSM_AES_DECRYPT_ALL_TIMEOUT};

Cry_HsmAesDecryptConfigType       Cry_kHsmAesDecryptConfigModeCtr =
     {.Mode = CRY_HSM_AES_MODE_CTR,.TimeOut = CRY_HSM_AES_DECRYPT_ALL_TIMEOUT};

Cry_HsmAesDecryptConfigType       Cry_kHsmAesDecryptConfigModeOfb =
     {.Mode = CRY_HSM_AES_MODE_OFB,.TimeOut = CRY_HSM_AES_DECRYPT_ALL_TIMEOUT};

Cry_HsmAesDecryptConfigType       Cry_kHsmAesDecryptConfigModeCfb =
     {.Mode = CRY_HSM_AES_MODE_CFB,.TimeOut = CRY_HSM_AES_DECRYPT_ALL_TIMEOUT};

static Cry_HsmPrimitiveIdType Cry_PRMIDSymDec = CRY_HSM_SYM_DECRYPT;
#endif

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/* Structure for storing the parameters while processing the AES
 * decrypt services */
static struct
{
  HsmAes_Block Block;
  HostAddr Param2;
  HsmCom_KeyAddr KeyAddress;
  Cry_HsmAesModeType Mode;
} Cry_HsmAesDecryptData;

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


#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_CODE
#else
#define CRY_START_SEC_RAMCODE
#endif
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 109] [$Satisfies $CDS_CDRV 110]   **
**                   [$Satisfies $CDS_CDRV 111] [$Satisfies $CDS_CDRV 112]   **
**                   [$Satisfies $CDS_CDRV 113] [$Satisfies $CDS_CDRV 114]   **
**                   [$Satisfies $CDS_CDRV 115] [$Satisfies $CDS_CDRV 579]   **
** Syntax          : Csm_ReturnType Cry_HsmAesDecryptStart(                  **
**                      const void *CfgPtr, const Csm_SymKeyType *KeyPtr,    **
**                      const uint8 *InitVectorPtr, uint32 InitVectorLength) **
**                                                                           **
** Description     :This function implements Cry_HsmAesDecryptStart for      **
**                  Csm_SymDecryptStart service. It reserves and initializes **
**                  resources for Csm_SymDecrypt service.                    **
**                                                                           **
**                                                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_DECRYPT_START                           **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr          :Pointer to configuration structure of  **
**                                    Cry_HsmAesDecryptConfigType            **
**                   KeyPtr          :Pointer to key structure of            **
**                                    Csm_SymKeyType                         **
**                   InitVectorPtr   :Pointer to initialization vector which **
**                                    will be used during symmetrical        **
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
Csm_ReturnType Cry_HsmAesDecryptStart(
                                       const void *CfgPtr,
                                       const Csm_SymKeyType *KeyPtr,
                                       const uint8 *InitVectorPtr,
                                       uint32 InitVectorLength)
{
  Csm_ReturnType RetVal;
  const Cry_HsmAesDecryptConfigType *AesCfgPtr;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_AES_DECRYPT_START, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_DECRYPT_START, KeyPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_DECRYPT_START, InitVectorPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    INIT_VALIDATION(CRY_HSM_SID_AES_DECRYPT_START, Cry_HsmInitStatus,
                                                                      DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    KEY_VALIDATION(CRY_HSM_SID_AES_DECRYPT_START,Cry_lCalcKeyAddr(KeyPtr),
                                                                       DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    if (InitVectorLength != CRY_HSM_BLOCK_SIZE)
    {
      /* LIMITATION: initial vector length shall be 16 bytes (128 bits)*/
      DET_REPORT(CRY_HSM_SID_AES_DECRYPT_START,
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
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDSymDec);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
       * config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
       * config pointer is of type void */
      AesCfgPtr = (const Cry_HsmAesDecryptConfigType *) CfgPtr;
      /* Store the AES mode and KEY address in the struture to be used later in
       * UPDATE service */
      Cry_HsmAesDecryptData.Mode = AesCfgPtr->Mode;
      Cry_HsmAesDecryptData.KeyAddress = Cry_lCalcKeyAddr(KeyPtr);

      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      Cry_HsmAesDecryptData.Param2 = (HostAddr)&Cry_HsmAesDecryptData.Block;
      /*IFX_MISRA_RULE_11_03_STATUS=Typecasting is required as input pointer
       * is of type uint8*/
      Cry_HsmAesDecryptData.Block = *((const HsmAes_Block*)InitVectorPtr);

      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the indication that START service is successful. To be used by
       * UPDATE and FINISH services to check the DET
       * "CSM_E_SERVICE_NOT_STARTED" */
      Cry_PrimStatus[Cry_PRMIDSymDec] = CRY_HSM_PRIM_STARTED;
      #endif
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  UNUSED_PARAMETER (InitVectorLength);
  /* Set the indication to main function that START service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDSymDec] = ASYNC_STATE_START;
  /* Store the service return value. To be used by the main function to report
   * the status to upper layer */
  Cry_PrimErr[Cry_PRMIDSymDec] = RetVal;
  #endif

  return RetVal;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 116] [$Satisfies $CDS_CDRV 117]   **
**                   [$Satisfies $CDS_CDRV 118] [$Satisfies $CDS_CDRV 119]   **
**                   [$Satisfies $CDS_CDRV 120] [$Satisfies $CDS_CDRV 121]   **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType  Cry_HsmAesDecryptUpdate(                **
**                          const void *CfgPtr, const uint8 *CipherTextPtr,  **
**                          uint32 CipherTextLength, uint8 *PlainTextPtr,    **
**                          uint32 *PlainTextLengthPtr)                      **
**                                                                           **
** Description     : This function implements Cry_HsmAesDecryptUpdate for    **
**                   Csm_SymDecryptUpdate service. It sends request to HSM   **
**                  for AES decryption using mode specified by               **
**                  Cry_HsmAesModeType enum type.                            **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_DECRYPT_UPDATE                          **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr            :Pointer to configuration structure of**
**                                      Cry_HsmAesDecryptConfigType          **
**                   CipherTextPtr     :Pointer to the cipher text that shall**
**                                      be decrypted                         **
**                   CipherTextLength  :The length of cipher text in bytes   **
**                   PlainTextLengthPtr:Pointer to the memory location in    **
**                                   which the length information is stored. **
**                                                                           **
** Parameters (out): PlainTextPtr      :Pointer to the memory location which **
**                                      will hold the decrypted text         **
**                   PlainTextLengthPtr:Pointer to the memory location in    **
**                                      which the length information is      **
**                                      stored.                              **
**                                                                           **
** Return value    : CSM_E_OK          :Request successful                   **
**                   CSM_E_BUSY        :Request failed due to underlying HSM **
**                                      communication is busy                **
**                   CSM_E_SMALL_BUFFER:Request failed due to too small      **
**                                      buffer provided                      **
**                   CSM_E_NOT_OK      :Request failed                       **
**                                                                           **
******************************************************************************/
Csm_ReturnType  Cry_HsmAesDecryptUpdate(
                             const void *CfgPtr, const uint8 *CipherTextPtr,
                             uint32 CipherTextLength, uint8 *PlainTextPtr,
                             uint32 *PlainTextLengthPtr)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmAesDecryptConfigType *AesCfgPtr;
  HsmCom_CryptParams *ParamPtr; /*Pointer to the structure that defines
                                  the parameters to be stored in shared
                                  buffer */

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;

  PTR_VALIDATION(CRY_HSM_SID_AES_DECRYPT_UPDATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_DECRYPT_UPDATE, CipherTextPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_DECRYPT_UPDATE, PlainTextPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_DECRYPT_UPDATE, PlainTextLengthPtr,
                                                                  DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_AES_DECRYPT_UPDATE,
                                   Cry_PrimStatus[Cry_PRMIDSymDec], DetErr)
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
                      (uint8)CRY_HSM_SID_AES_DECRYPT_UPDATE,
                      (uint8)CRY_HSM_E_BUFFER_TOO_SMALL);
      #endif
    }
    else if(((CipherTextLength % CRY_HSM_BLOCK_SIZE) != 0U ) &&
            (Cry_HsmAesDecryptData.Mode == CRY_HSM_AES_MODE_CBC))
    {
      RetVal = CSM_E_SMALL_BUFFER;
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError(CSM_MODULE_ID,CRY_HSM_INSTANCE_ID,
              (uint8)CRY_HSM_SID_AES_DECRYPT_UPDATE,
              (uint8)CRY_HSM_E_BUFFER_TOO_SMALL);
      #endif
    }
    else
    {
      /* Check the HSM status. COmmand is sent only if the HSM is not busy */
      RetVal = Cry_HsmStatusCheck(Cry_PRMIDSymDec);
      if(RetVal == CSM_E_OK)
      {
        /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
        * config pointer is of type void*/
        /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
        * config pointer is of type void */
        AesCfgPtr = (const Cry_HsmAesDecryptConfigType *) CfgPtr;
        HandlePtr = &(Cry_HsmData[Cry_PRMIDSymDec]);

        /* Store the Sesion and KEY address in session data. To be updated into
        * the HT2HSMF register later while sending the command */
        HsmCom_SetPackedParams(HandlePtr->Session,
                              Cry_HsmAesDecryptData.KeyAddress,
                              Cry_HsmAesDecryptData.Mode);

        /* Get the shared buffer address */
        /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be aligned
        * to the struture pointer containing the elements for MacGeneration
        * AES Decryption*/
        ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
        /* Update the prameters in shared buffer */
        ParamPtr->InitialVarAddr = Cry_HsmAesDecryptData.Param2;
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
        if((CipherTextLength % CRY_HSM_BLOCK_SIZE) == 0U)
        {
          ParamPtr->NBlocks = (CipherTextLength / CRY_HSM_BLOCK_SIZE);
        }
        else
        {
          ParamPtr->NBlocks = (CipherTextLength / CRY_HSM_BLOCK_SIZE) + 1U;
        }
        /* Send the command to HSM */
        RetVal = Cry_HsmSendCommandCommon(HandlePtr,
               HSMCOM_CMD_AES_DECRYPT_UPDATE,
               CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(AesCfgPtr, CipherTextLength));
        Cry_HsmAesDecryptData.KeyAddress = HSMCOM_INVALID_KEY;

        *PlainTextLengthPtr = CipherTextLength;
      }
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that UPDATE service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDSymDec] = ASYNC_STATE_UPDATE;
  /* Store the service return value. To be used by the main function to do
   * further processing */
  Cry_PrimErr[Cry_PRMIDSymDec] = RetVal;
  #endif

  return RetVal;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 122] [$Satisfies $CDS_CDRV 123]   **
**                   [$Satisfies $CDS_CDRV 124] [$Satisfies $CDS_CDRV 125]   **
**                   [$Satisfies $CDS_CDRV 127] [$Satisfies $CDS_CDRV 579]   **
** Syntax          : Csm_ReturnType Cry_HsmAesDecryptFinish(                 **
**      const void *CfgPtr, uint8 *PlainTextPtr, uint32 *PlainTextLengthPtr) **
**                                                                           **
** Description     : This function implements Cry_HsmAesDecryptFinish for    **
**                   Csm_ SymDecryptFinish service. It releases resources    **
**                   used by Csm_SymDecrypt service.                         **
**                                                                           **
**                                                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_DECRYPT_FINISH                          **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr            :Pointer to configuration structure of**
**                                      Cry_HsmAesEncryptConfigType          **
**                   PlainTextPtr      :This parameter is ignored            **
**                   PlainTextLengthPtr:This parameter is ignored            **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK     :Request successful                        **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK :Request failed                            **
**                                                                           **
******************************************************************************/
Csm_ReturnType  Cry_HsmAesDecryptFinish( const void *CfgPtr,
        uint8 *PlainTextPtr, uint32 *PlainTextLengthPtr)
{

  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmAesDecryptConfigType *AesCfgPtr;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  #endif
  UNUSED_POINTER (PlainTextPtr)
  UNUSED_POINTER (PlainTextLengthPtr)

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_AES_DECRYPT_FINISH, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_AES_DECRYPT_FINISH,
                     Cry_PrimStatus[Cry_PRMIDSymDec], DetErr)
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
    AesCfgPtr = (const Cry_HsmAesDecryptConfigType *) CfgPtr;
    /* Check the HSM status. COmmand is sent only if the
     * HSM is not busy */
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDSymDec);
    if(RetVal == CSM_E_OK)
    {
      /* Get the active handle for the primitive */
      HandlePtr = &(Cry_HsmData[Cry_PRMIDSymDec]);
      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                                HSMCOM_CMD_AES_DECRYPT_FINISH,
                                CRY_HSM_GET_FINISH_TIMEOUT_TICKS(AesCfgPtr));
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the primitive status to FINISHED. Status will be changed again if
       * the START is executed successfully */
      Cry_PrimStatus[Cry_PRMIDSymDec] = CRY_HSM_PRIM_FINISHED;
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
  Cry_PrimStatusAsync[Cry_PRMIDSymDec] = ASYNC_STATE_FINISH;
  /* Store the service return value.
   * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDSymDec] = RetVal;
  #endif

  return RetVal;
  /*IFX_MISRA_RULE_08_13_STATUS=Function prototype can't be changed*/
}
/******************************************************************************
** Traceability    :  [$Satisfies $CDS_CDRV 128][$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          :  void Cry_HsmAesDecryptMainFunction(void)               **
**                                                                           **
** Description     : This function doesnt exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_AES_DECRYPT_UPDATE  **
**                   and HSMCOM_CMD_AES_DECRYPT_FINISH commands and closes   **
**                   the session.                                            **
**                                                                           **
**                                                                           **
**                                                                           **
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
void Cry_HsmAesDecryptMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDSymDec, NULL_PTR);
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
/*End of CRY_HSM__DECRYPT_C*/
