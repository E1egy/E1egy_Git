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
**  FILENAME    : Cry_HsmAesEcbEncrypt.c                                      **
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
**  DESCRIPTION : This file contains the services related to ECB Encryption   **
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
#include "Cry_HsmAesEcbEncrypt.h"
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

/* Structure containing the timeouts for ECB Encryption */
const Cry_HsmAesEcbEncryptConfigType    Cry_kHsmAesEcbEncryptConfig =
        {.TimeOut = CRY_HSM_AES_ECB_ENCRYPT_ALL_TIMEOUT};

static const Cry_HsmPrimitiveIdType Cry_PRMIDEcbEnc = CRY_HSM_SYM_ECB_ENCRYPT;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
#else
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/* Structure containing the timeouts for ECB Encryption */
Cry_HsmAesEcbEncryptConfigType    Cry_kHsmAesEcbEncryptConfig =
        {.TimeOut = CRY_HSM_AES_ECB_ENCRYPT_ALL_TIMEOUT};

static Cry_HsmPrimitiveIdType Cry_PRMIDEcbEnc = CRY_HSM_SYM_ECB_ENCRYPT;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
#endif
/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/

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
#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_CODE
#else
#define CRY_START_SEC_RAMCODE
#endif
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 129] [$Satisfies $CDS_CDRV 130]    **
**                   [$Satisfies $CDS_CDRV 131] [$Satisfies $CDS_CDRV 132]    **
**                   [$Satisfies $CDS_CDRV 133] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType Cry_HsmAesEcbEncryptStart(                **
**                                            const void *CfgPtr,             **
**                                            const Csm_SymKeyType *KeyPtr)   **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbEncryptStart for   **
**                   Csm_SymBlockEncryptStart service. It reserves and        **
**                   initializes resources for Csm_SymBlockEncrypt service    **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_ENCRYPT_START                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmAesEcbEncryptConfigType                  **
**                   KeyPtr - Pointer to key structure of Csm_SymKeyType. This**
**                            key has to be used during the symmetrical ECB   **
**                            encryption operation                            **
**                            1. KeyPtr->length shall be 1                    **
**                            2. KeyPtr->data[0] shall be a value taken       **
**                            from Cry_HsmKeySlotIdType and is used to        **
**                            calculate global key address                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType Cry_HsmAesEcbEncryptStart(
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
  PTR_VALIDATION(CRY_HSM_SID_AES_ECB_ENCRYPT_START, KeyPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    INIT_VALIDATION(CRY_HSM_SID_AES_ECB_ENCRYPT_START, Cry_HsmInitStatus,
                                                                   DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    KEY_VALIDATION(CRY_HSM_SID_AES_ECB_ENCRYPT_START,
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
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDEcbEnc);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      HandlePtr = Cry_lHsmGetActiveHandle(Cry_PRMIDEcbEnc);
      /* Store the key address and AES mode in session data. To be used in
       * UPDATE service while sending the command. AES mode is dummy for this
       * primitive */
      HsmCom_SetPackedParams(HandlePtr->Session, Cry_lCalcKeyAddr(KeyPtr),
                             CRY_HSM_AES_MODE_DUMMY);
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the indication that START service is successful.
       * To be used by UPDATE and FINISH services to check the
       * DET "CSM_E_SERVICE_NOT_STARTED" */
      Cry_PrimStatus[Cry_PRMIDEcbEnc] = CRY_HSM_PRIM_STARTED;
      #endif
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that START service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDEcbEnc] = ASYNC_STATE_START;
  /* Store the service return value.
   * To be used by the main function to report the status to upper layer */
  Cry_PrimErr[Cry_PRMIDEcbEnc] = RetVal;
  #endif

  return RetVal;
  /*IFX_MISRA_RULE_08_13_STATUS=HandlePtr can't be declared as const */
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 134] [$Satisfies $CDS_CDRV 135]    **
**                   [$Satisfies $CDS_CDRV 136] [$Satisfies $CDS_CDRV 137]    **
**                   [$Satisfies $CDS_CDRV 138] [$Satisfies $CDS_CDRV 139]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesEcbEncryptUpdate(              **
**                                            const void *CfgPtr,             **
**                                            const uint8 *PlainTextPtr,      **
**                                            uint32 PlainTextLength,         **
**                                            uint8 *CipherTextPtr,           **
**                                            uint32 *CipherTextLengthPtr)    **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbEncryptUpdate for  **
**                   Csm_SymBlockEncryptUpdate service. It sends request to   **
**                   HSM for AES ECB mode encryption.                         **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr              - Pointer to configuration structure **
**                                         of Cry_HsmAesEcbEncryptConfigType  **
**                   PlainTextPtr        - Pointer to the plain text that     **
**                                         shall be encrypted                 **
**                   PlainTextLength     - The length of the plain text in    **
**                                         bytes. It should be 16             **
**                   CipherTextLengthPtr - Pointer to the memory location in  **
**                                         which the length information is    **
**                                         stored.On calling this function    **
**                                         this parameter shall contain the   **
**                                         size of the provided buffer which  **
**                                         should be greater than or equal to **
**                                         the PlainTextLength parameter.     **
**                                                                            **
** Parameters (out): CipherTextPtr       - Pointer to the memory location     **
**                                         which will hold the encrypted text **
**                   CipherTextLengthPtr - Pointer to the memory location in  **
**                                         which the length information is    **
**                                         stored. When the request has       **
**                                         finished, the actual length of the **
**                                         returned encrypted text shall be   **
**                                         stored.                            **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_SMALL_BUFFER - Request failed due to too small     **
**                                         buffer provided                    **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType  Cry_HsmAesEcbEncryptUpdate(
                                           const void *CfgPtr,
                                           const uint8 *PlainTextPtr,
                                           uint32 PlainTextLength,
                                           uint8 *CipherTextPtr,
                                           uint32 *CipherTextLengthPtr)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmAesEcbEncryptConfigType *AesCfgPtr;
  HsmCom_CryptParams *ParamPtr; /*Pointer to the structure that defines
                                  the parameters to be stored in shared
                                  buffer */
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE,
                                    PlainTextPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE,
                                    CipherTextPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE,
                                    CipherTextLengthPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE,
                                    Cry_PrimStatus[Cry_PRMIDEcbEnc], DetErr)
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
      if ((PlainTextLength != CRY_HSM_BLOCK_SIZE) ||
          (*CipherTextLengthPtr < PlainTextLength) )
      {
        RetVal = CSM_E_SMALL_BUFFER;
        #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
        /* LIMITATION: we only support length of 16 and equal length of plain
         * text and cipher text */
        Det_ReportError(CSM_MODULE_ID,CRY_HSM_INSTANCE_ID,
                       (uint8)CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE,
                       (uint8)CRY_HSM_E_BUFFER_TOO_SMALL);
        #endif
      }
      else
      {
        /* Check the HSM status. COmmand is sent only if the HSM is not busy */
        RetVal = Cry_HsmStatusCheck(Cry_PRMIDEcbEnc);
        if(RetVal == CSM_E_OK)
        {
          HandlePtr = &(Cry_HsmData[Cry_PRMIDEcbEnc]);
          /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
           * config pointer is of type void*/
          /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
           * config pointer is of type void*/
          AesCfgPtr = (const Cry_HsmAesEcbEncryptConfigType *) CfgPtr;
          /* Get the shared buffer address */
          /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
           *aligned to the structure pointer containing the elements
           *for ECB encryption*/
          ParamPtr= HsmCom_GetParamsBuffer(HandlePtr->Session);

          /* Update the prameters in shared buffer */
          /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle
           data sharing between Host and HSM through shared buffer*/
          /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
           data sharing between Host and HSM through shared buffer*/
          ParamPtr->SourceAddr = (HostAddr)PlainTextPtr;
          /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle
           data sharing between Host and HSM through shared buffer*/
          /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
            data sharing between Host and HSM through shared buffer*/
          ParamPtr->DestAddr   = (HostAddr)CipherTextPtr;
          ParamPtr->NBlocks    = 1U;
          /* Send the command to HSM */
          RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                 HSMCOM_CMD_ECB_ENCRYPT,
                 CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(AesCfgPtr,PlainTextLength));
          *CipherTextLengthPtr = PlainTextLength;
       }
     }
   }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that UPDATE service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDEcbEnc] = ASYNC_STATE_UPDATE;
  /* Store the service return value.
   * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDEcbEnc] = RetVal;
  #endif

 return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 140] [$Satisfies $CDS_CDRV 141]    **
**                   [$Satisfies $CDS_CDRV 142] [$Satisfies $CDS_CDRV 143]    **
**                   [$Satisfies $CDS_CDRV 144] [$Satisfies $CDS_CDRV 573]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesEcbEncryptFinish(              **
**                                            const void *CfgPtr,             **
**                                            uint8 *CipherTextPtr,           **
**                                            uint32 *CipherTextLengthPtr)    **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbEncryptFinish for  **
**                   Csm_SymBlockEncryptFinish service. It releases resources **
**                   used by Csm_SymBlockEncrypt service. This function       **
**                   invokes function that closes the HSM communication       **
**                   session.                                                 **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_ENCRYPT_FINISH                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr              - Pointer to configuration structure **
**                                         of Cry_HsmAesEcbEncryptConfigType. **
**                                         This parameter is ignored.         **
**                   CipherTextPtr       - CipherTextPtr is ignored           **
**                   CipherTextLengthPtr - CipherTextLengthPtr is ignored     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM         **
**                               communication is busy                        **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType  Cry_HsmAesEcbEncryptFinish(
                                           const void *CfgPtr,
                                           uint8 *CipherTextPtr,
                                           uint32 *CipherTextLengthPtr)
{
  Csm_ReturnType RetVal;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  #endif

  UNUSED_POINTER (CfgPtr)
  UNUSED_POINTER (CipherTextPtr)
  UNUSED_POINTER (CipherTextLengthPtr)

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  START_VALIDATION(CRY_HSM_SID_AES_ECB_ENCRYPT_FINISH,
                   Cry_PrimStatus[Cry_PRMIDEcbEnc], DetErr)
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
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDEcbEnc);
    if(RetVal == CSM_E_OK)
    {
      /* Finish the primitive by closing the session */
      RetVal = Cry_HsmPrimitiveFinish(Cry_PRMIDEcbEnc);
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      if(RetVal == CSM_E_OK)
      {
        /* Set the primitive status to FINISHED. Status is changed again if
         * the START is executed successfully */
        Cry_PrimStatus[Cry_PRMIDEcbEnc] = CRY_HSM_PRIM_FINISHED;
      }
      #endif
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that FINISH service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDEcbEnc] = ASYNC_STATE_FINISH;
  /* Store the service return value. To be used by the main function to do
   * further processing */
  Cry_PrimErr[Cry_PRMIDEcbEnc] = RetVal;
  #endif

  return RetVal;
  /*IFX_MISRA_RULE_08_13_STATUS=Function prototype can't be changed */
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 145]  [$Satisfies $CDS_CDRV 579]   **
**                                                                            **
** Syntax          : void Cry_HsmAesEcbEncryptMainFunction(void)              **
**                                                                            **
** Description     : This function doesnt exist in case of synchronous        **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON. In case **
**                   of asynchronous operation, this function checks the      **
**                   command response for HSMCOM_CMD_ECB_ENCRYPT command and  **
**                   closes the session.                                      **
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
void Cry_HsmAesEcbEncryptMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDEcbEnc, NULL_PTR);
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
/*End of CRY_HSM_ECB_ENCRYPT_C*/
