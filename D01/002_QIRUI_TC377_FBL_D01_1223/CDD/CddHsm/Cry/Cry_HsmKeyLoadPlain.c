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
**  FILENAME    : Cry_HsmKeyLoadPlain.c                                       **
**                                                                            **
**  VERSION     : 3.0.0                                                       **
**                                                                            **
**  DATE        : 2016-07-11                                                  **
**                                                                            **
**  VARIANT     :  NA                                                         **
**                                                                            **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                               **
**                [Refer Release Package for Supported Device]                **
**  AUTHOR      : Trivikram G                                                 **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains services relted to Plain Key Loading     **
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
#include "Cry_HsmKeyLoadPlain.h"

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
**                     Global Constant Definition                             **
*******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

const Cry_HsmLoadPlainConfigType        Cry_kHsmLoadPlainConfig =
        {.TimeOut = CRY_HSM_KEY_LOAD_PLAIN_ALL_TIMEOUT};

static const Cry_HsmPrimitiveIdType Cry_PRMIDKeyLoadPlain =
                                                       CRY_HSM_KEY_LOAD_PLAIN;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

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
**                     Global Function Definition                            **
******************************************************************************/

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 164] [$Satisfies $CDS_CDRV 165]    **
**                   [$Satisfies $CDS_CDRV 166] [$Satisfies $CDS_CDRV 167]    **
**                   [$Satisfies $CDS_CDRV 168] [$Satisfies $CDS_CDRV 579]    **
** Syntax          :Csm_ReturnType Cry_HsmKeyLoadPlainStart                   **
**                                                  (const void *CfgPtr)      **
**                                                                            **
** Description     : This function implements Cry_HsmKeyLoadPlainStart for    **
**                   Csm_KeyExtractStart service. It reserves and             **
**                   initializes resources for Csm_SymKeyExtract service      **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_PLAIN_START                         **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmLoadPlainConfigType.                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType Cry_HsmKeyLoadPlainStart(const void *CfgPtr)
{
  Csm_ReturnType RetVal;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
#endif
  UNUSED_POINTER (CfgPtr)
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  INIT_VALIDATION(CRY_HSM_SID_KEY_LOAD_PLAIN_START, Cry_HsmInitStatus, DetErr)
  /* If any DET error occurs, return CSM_E_NOT_OK. Further processing
   * is not required */
  if(DetErr != DEV_NO_ERROR)
  {
    RetVal = CSM_E_NOT_OK;
  }
  else
#endif
  {
    /* Initiate the handle for the session */
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDKeyLoadPlain);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the indication that START service is successful.
      * To be used by UPDATE and FINISH services to check the
      * DET "CSM_E_SERVICE_NOT_STARTED" */
      Cry_PrimStatus[Cry_PRMIDKeyLoadPlain] = CRY_HSM_PRIM_STARTED;
#endif
    }
  }

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that START service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDKeyLoadPlain] = ASYNC_STATE_START;
  /* Store the service return value.
  * To be used by the main function to report the status to upper layer */
  Cry_PrimErr[Cry_PRMIDKeyLoadPlain] = RetVal;
#endif

  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 169] [$Satisfies $CDS_CDRV 170]    **
**                   [$Satisfies $CDS_CDRV 171] [$Satisfies $CDS_CDRV 172]    **
**                   [$Satisfies $CDS_CDRV 173] [$Satisfies $CDS_CDRV 174]    **
**                   [$Satisfies $CDS_CDRV 175] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType Cry_HsmKeyLoadPlainUpdate(                **
**                                                     const void *CfgPtr,    **
**                                                     const uint8 *DataPtr,  **
**                                                     uint32 DataLength)     **
**                                                                            **
** Description     : This function implements Cry_HsmKeyLoadPlainUpdate for   **
**                   Csm_KeyExtractUpdate service. It sends request to HSM    **
**                   to load a plain key into HSMCOM_RAM_KEY slot             **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr     - Pointer to configuration structure of       **
**                                Cry_HsmLoadPlainConfigType                  **
**                   DataPtr    - Pointer to data block, which represents the **
**                                plain key that will be loaded into the      **
**                                RAM_KEY slot of the HSM SHE                 **
**                   DataLength - The length of the key (data block) in       **
**                                bytes. This value shall be 16               **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType  Cry_HsmKeyLoadPlainUpdate(
        const void *CfgPtr, HsmCom_KeyAddr KeyAddr,const uint8 *DataPtr, uint32 DataLength)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  uint32 DataAddr;
  const Cry_HsmLoadPlainConfigType* LoadCfgPtr;
  HsmCom_LoadPlainKeyParams *ParamPtr; /*Pointer to  structure that defines
                                        the parameters to be stored in shared
                                        buffer */
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
#endif
  /*UNUSED_PARAMETER (DataLength);*/

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE, DataPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE,
                     Cry_PrimStatus[Cry_PRMIDKeyLoadPlain], DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    if((KeyAddr == HSMCOM_RAM_KEY)&&(DataLength != CRY_HSM_BLOCK_SIZE))
    {
      /* LIMITATION: Key shall be 16 bytes */
      DET_REPORT(CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE,
                 CRY_HSM_E_PARAM_METHOD_INVALID, DetErr)
    }
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
    /* Check the HSM status. COmmand is sent only if the
    * HSM is not busy */
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDKeyLoadPlain);
    if(RetVal == CSM_E_OK)
    {
      HandlePtr = &(Cry_HsmData[Cry_PRMIDKeyLoadPlain]);
      HsmCom_SetPackedParams(HandlePtr->Session, KeyAddr,
                 CRY_HSM_AES_MODE_DUMMY);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      DataAddr = (uint32)DataPtr;
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the
      * input config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the
      * input config pointer is of type void */
      LoadCfgPtr = (const Cry_HsmLoadPlainConfigType*) CfgPtr;
      /* Get the shared buffer address */
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
      *aligned to the struture pointer containing the elements
      *for MacGeneration */
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /* Update the prameters in shared buffer */
      ParamPtr->KeyAddr = (HostAddr)(DataAddr);

	  ParamPtr->PlainKeyLen = DataLength;
      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
               HSMCOM_CMD_KEY_LOAD_PLAIN,
               CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(LoadCfgPtr,0U));
    }
  }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that UPDATE service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDKeyLoadPlain] = ASYNC_STATE_UPDATE;
  /* Store the service return value.
  * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDKeyLoadPlain] = RetVal;
#endif

  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 176] [$Satisfies $CDS_CDRV 177]    **
**                   [$Satisfies $CDS_CDRV 178] [$Satisfies $CDS_CDRV 179]    **
**                   [$Satisfies $CDS_CDRV 180] [$Satisfies $CDS_CDRV 181]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType  Cry_HsmKeyLoadPlainFinish(               **
**                                                 const void *CfgPtr,        **
**                                                 Csm_SymKeyType *KeyPtr)    **
**                                                                            **
** Description     : This function implements Cry_HsmKeyLoadPlainFinish for   **
**                   Csm_KeyExtractFinish service. It releases resources      **
**                   used by Csm_SymKeyExtract service. This function         **
**                   invokes function that closes the HSM communication       **
**                   session.                                                 **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_PLAIN_FINISH                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmLoadPlainConfigType                      **
**                   KeyPtr - KeyPtr parameter is ignored                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM         **
**                               communication is busy                        **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType  Cry_HsmKeyLoadPlainFinish(
        const void *CfgPtr, Csm_SymKeyType *KeyPtr)
{
  Csm_ReturnType RetVal;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
#endif
  UNUSED_POINTER (CfgPtr)
  UNUSED_POINTER (KeyPtr)
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  START_VALIDATION(CRY_HSM_SID_KEY_LOAD_PLAIN_FINISH,
                   Cry_PrimStatus[Cry_PRMIDKeyLoadPlain], DetErr)
  /* If any DET error occurs, return CSM_E_NOT_OK. Further processing
  * is not required */
  if(DetErr != DEV_NO_ERROR)
  {
    RetVal = CSM_E_NOT_OK;
  }
  else
#endif
  {
    /* Check the HSM status. Session is not closed if HSM is BUSY */
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDKeyLoadPlain);
    if(RetVal == CSM_E_OK)
    {
      /* Finish the primitive by closing the session */
      RetVal = Cry_HsmPrimitiveFinish(Cry_PRMIDKeyLoadPlain);
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      if(RetVal == CSM_E_OK)
      {
        /* Set the primitive status to FINISHED.
        * Status will be changed again if the START
        * is executed successfully */
        Cry_PrimStatus[Cry_PRMIDKeyLoadPlain] = CRY_HSM_PRIM_FINISHED;
      }
#endif
    }
  }

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    /* Set the indication to main function that FINISH service is executed */
    Cry_PrimStatusAsync[Cry_PRMIDKeyLoadPlain] = ASYNC_STATE_FINISH;
    /* Store the service return value.
     * To be used by the main function to do further processing */
    Cry_PrimErr[Cry_PRMIDKeyLoadPlain] = RetVal;
#endif

  return RetVal;
/*IFX_MISRA_RULE_08_13_STATUS=Function prototype can't be changed*/
}

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 182][$Satisfies $CDS_CDRV 579]     **
**                                                                            **
** Syntax          : void Cry_HsmKeyLoadPlainMainFunction(void)               **
**                                                                            **
** Description     : This function does not exist in case of synchronous      **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.         **
**                   In case of asynchronous operation, this function checks  **
**                   the command response for HSMCOM_CMD_KEY_LOAD_PLAIN       **
**                   command and closes the session                           **
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
void Cry_HsmKeyLoadPlainMainFunction(void)
{
    Cry_HsmPrimitiveMainFunction(Cry_PRMIDKeyLoadPlain, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_KEY_LOAD_PLAIN_C*/
