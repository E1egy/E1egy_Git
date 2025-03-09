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
**  FILENAME   : Cry_Hsm.c                                                   **
**                                                                           **
**  VERSION    : 6.0.0                                                       **
**                                                                           **
**  DATE       : 2018-06-13                                                  **
**                                                                           **
**  VARIANT    : NA                                                          **
**                                                                           **
**  PLATFORM   : Infineon TC2xxxx Aurix Family                               **
**               [Refer Release Package for Supported Device]                **
**  AUTHOR     : Prashant K                                                  **
**                                                                           **
**  VENDOR     : Infineon Technologies                                       **
**                                                                           **
**  DESCRIPTION : This file contains the                                     **
**                functions related to Cry module                            **
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
#include "Cry_Hsm.h"
#include "Cry_Hsm_Priv.h"
/******************************************************************************
**                     Imported Compiler Switch Check                        **
******************************************************************************/
#if CSM_SYM_KEY_MAX_SIZE < 48
#error "This CRY HSM SHE emulation requires that CSM_SYM_KEY_MAX_SIZE >= 48"
#endif
#if ((CRY_HSM_TRIGGERED_INIT == STD_ON) && (CRY_HSM_SECURE_BOOT == STD_ON))
#error "Secure Boot can be enabled only if CRY_HSM_TRIGGERED_INIT is OFF"
#endif
/******************************************************************************
**                     Global Structure Declaration                          **
******************************************************************************/

/******************************************************************************
**                     Global Variable Definitions                           **
******************************************************************************/
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
 /* Structure containing the CSM callbacks to be called for Asynchronous mode*/
/*IFX_MISRA_RULE_08_09_STATUS=Cry_HsmCallbacksData should be declared as
 * variable to support Flash programming*/
static Cry_HsmCallbacksType Cry_HsmCallbacksData[CRY_HSM_NUM_SERVICES] =
  {
    { CRY_HSM_RANDOM_SEED_INIT, &Csm_RandomSeedCallbackNotification,
                          &Csm_RandomSeedServiceFinishNotification },
    { CRY_HSM_RANDOM_SEED_EXTEND, &Csm_RandomSeedCallbackNotification,
                          &Csm_RandomSeedServiceFinishNotification },
    { CRY_HSM_RANDOM_GENERATE, &Csm_RandomGenerateCallbackNotification,
                          &Csm_RandomGenerateServiceFinishNotification },
    { CRY_HSM_TRUE_RANDOM_GENERATE, &Csm_RandomGenerateCallbackNotification,
                          &Csm_RandomGenerateServiceFinishNotification },
    { CRY_HSM_MAC_GENERATE, &Csm_MacGenerateCallbackNotification,
                            &Csm_MacGenerateServiceFinishNotification },
    { CRY_HSM_MAC_VERIFY, &Csm_MacVerifyCallbackNotification,
                          &Csm_MacVerifyServiceFinishNotification },
    { CRY_HSM_SYM_ENCRYPT, &Csm_SymEncryptCallbackNotification,
                           &Csm_SymEncryptServiceFinishNotification },
    { CRY_HSM_SYM_DECRYPT, &Csm_SymDecryptCallbackNotification,
                           &Csm_SymDecryptServiceFinishNotification },
    { CRY_HSM_KEY_LOAD, &Csm_SymKeyExtractCallbackNotification,
                        &Csm_SymKeyExtractServiceFinishNotification },
    { CRY_HSM_KEY_LOAD_PLAIN, &Csm_SymKeyExtractCallbackNotification,
                              &Csm_SymKeyExtractServiceFinishNotification },
    { CRY_HSM_KEY_WRAP, &Csm_SymKeyWrapSymCallbackNotification,
                        &Csm_SymKeyWrapSymServiceFinishNotification },
    { CRY_HSM_SYM_ECB_ENCRYPT, &Csm_SymBlockEncryptCallbackNotification,
                               &Csm_SymBlockEncryptServiceFinishNotification },
    { CRY_HSM_SYM_ECB_DECRYPT, &Csm_SymBlockDecryptCallbackNotification,
                               &Csm_SymBlockDecryptServiceFinishNotification },
    { CRY_HSM_UID, &Csm_GetUidCallbackNotification,
                               &Csm_GetUidServiceFinishNotification },
    { CRY_HSM_DEBUG, &Csm_DebugCallbackNotification,
                               &Csm_DebugServiceFinishNotification },
#if (CRY_HSM_SECURE_BOOT == STD_ON)
    { CRY_HSM_BOOT_FAILURE, &Csm_BootFailureCallbackNotification,
                               &Csm_BootFailureServiceFinishNotification },
    { CRY_HSM_BOOT_OK, &Csm_BootOkCallbackNotification,
                               &Csm_BootOkServiceFinishNotification },
#endif
    { CRY_HSM_SYM_XTS_ENCRYPT, &Csm_SymXtsEncryptCallbackNotification,
                               &Csm_SymXtsEncryptServiceFinishNotification },
    { CRY_HSM_SYM_XTS_DECRYPT, &Csm_SymXtsDecryptCallbackNotification,
                               &Csm_SymXtsDecryptServiceFinishNotification },
    { CRY_HSM_SYM_GCM_ENCRYPT, &Csm_SymGcmEncryptCallbackNotification,
                               &Csm_SymGcmEncryptServiceFinishNotification },
    { CRY_HSM_SYM_GCM_DECRYPT, &Csm_SymGcmDecryptCallbackNotification,
                               &Csm_SymGcmDecryptServiceFinishNotification }
  };
#endif

/*vector table to map Update & Finish commands */
static uint8 Cry_Hsm_CommandMemoryMap[(uint32)HSMCOM_MAX_CMD_VALUE + 1U]
   /*IFX_MISRA_RULE_08_09_STATUS=This table is required in Two functions in
    * Async mode*/
    = {
    0xFF,           /*COMMAND NOTHING TO DO    */
    0xFF,           /*ECB_ENCRYPT              */
    0xFF,           /*ECB_DECRYPT              */
    0xAA,           /*AES_ENCRYPT_UPDATE       */
    0xBB,           /*AES_ENCRYPT_FINISH       */
    0xAA,           /*AES_DECRYPT_UPDATE       */
    0xBB,           /*AES_DECRYPT_FINISH       */
    0xAA,           /*MAC_GEN_UPDATE           */
    0xBB,           /*MAC_GEN_FINISH           */
    0xAA,           /*MAC_VER_UPDATE           */
    0xBB,           /*MAC_VER_FINISH           */
    0xFF,           /*KEY_LOAD                 */
    0xFF,           /*KEY_LOAD_PLAIN           */
    0xFF,           /*KEY_EXPORT               */
    0xFF,           /*RND_INIT                 */
    0xFF,           /*RND_SEED_EXTEND          */
    0xFF,           /*RND_GEN                  */
    0xFF,           /*GET_ID                   */
    0xFF,           /*BOOT_FAILURE             */
    0xFF,           /*BOOT_OK                  */
    0xFF,           /*DEBUG_START              */
    0xFF,           /*DEBUG_FINISH             */
    0xBB,           /*SAFE_MAC_VER_FINISH      */
    0xFF,           /*SAFE_MAC_VER_FINISH_CHECK*/
    0xFF,           /*TRNG_GEN                 */
    0xAA,           /*GCM ENCRYPT UPDATE       */
    0xBB,           /*GCM ENCRYPT FINISH       */
    0xAA,           /*GCM DECRYPT UPDATE       */
    0xBB,           /*GCM DECRYPT FINISH       */
    0xAA,           /*XTS ENCRYPT UPDATE       */
    0xBB,           /*XTS ENCRYPT FINISH       */
    0xAA,           /*XTS DECRYPT UPDATE       */
    0xBB,           /*XTS DECRYPT FINISH       */
	0xFF,           /*HASH                     */
    0xFF            /*INIT SET BUFFER          */
    };
#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/* Array to hold the session pointers when session is opened
 * for the primitive services */
Cry_Hsm Cry_HsmData[CRY_HSM_NUM_SERVICES];

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/*Array that represents the state (Start, Update, Finish)of primitive services
 *for asynchronous mode.
  ex: ASYNC_STATE_START indicates that START is executed for the primitive */
Cry_HsmStateType Cry_PrimStatusAsync[CRY_HSM_NUM_SERVICES];

/*Array that represents the result of primitive services
  for asynchronous mode.
  ex: CSM_E_OK indicates that service (indicated by Cry_PrimStatusAsync) is
  executed successfully for the primitive */
Csm_ReturnType Cry_PrimErr[CRY_HSM_NUM_SERVICES];

#endif

#if((CRY_HSM_E_POLICY_VIOLATION != STD_OFF)||  \
    (CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF))
/* Flag to check if SAFE_MAC_VER_FINISH command returns ERROR */
boolean Cry_MacVerError;
#endif

/* Variable to hold HSMCOM_ERC_KEY_EMPTY / HSMCOM_ERC_KEY_INVALID return value
 for AES/MAC-GEN/MAC-VER/GCM/XTS update commands */
static HsmCom_Error Cry_UpdateReturnValue;

/*Flag to indicate that KEY_EMPTY/KEY_INVALID is returned by update service */
static boolean Cry_UpdateReturnFlag;

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
/* Array that represents the state (Start, Finish)of primitive services.
 * Used for checking the DET "CSM_E_SERVICE_NOT_STARTED"
 */
Cry_PrimStatusVal Cry_PrimStatus[CRY_HSM_NUM_SERVICES];
/*Variable that represents the init status of CRY module.
 *CRY_HSM_UNINITIALIZED: Indicates that CRY is not initialized successfully
  CRY_HSM_INITIALIZED: Indicates that CRY is initialized successfully
  Used for checking the DET "CSM_E_UNINIT" for the primitive services
 */
Cry_HsmStateRef Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
#endif

#define CRY_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/******************************************************************************
**                     Global Function Decleartion                           **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 243] [$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          : void Cry_HsmInit(void)                                  **
**                                                                           **
** Description     : This function initializes the CRY module                **
**                   and the communication to HSM                            **
**                                                                           **
** Service ID      : CRY_HSM_SID_INIT                                        **
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
void Cry_HsmInit(void)
{
  HsmCom_Error ErrorVal;
  HsmAes_Block *BuffersPtr;
  uint32 LoopValue;

  /* Initialize Cry_UpdateReturnValue and Cry_UpdateReturnFlag */
  Cry_UpdateReturnValue = HSMCOM_ERC_NO_ERROR;
  Cry_UpdateReturnFlag = FALSE;

  /* Initialize the flag Cry_MacVerError to FALSE */
#if((CRY_HSM_E_POLICY_VIOLATION != STD_OFF)||  \
    (CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF))
  Cry_MacVerError = FALSE;
#endif

  /* initiate service data */
  for (LoopValue = 0U; LoopValue < (uint32)CRY_HSM_NUM_SERVICES; LoopValue++)
  {
    /* Initialize the session pointers to NULL indicating that
     * session is not opened */
    Cry_HsmData[LoopValue].Session = HSMCOM_INVALID_SESSION;

    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    Cry_PrimStatusAsync[LoopValue] = ASYNC_STATE_IDLE;
    Cry_PrimErr[LoopValue] = CSM_E_OK;
    #endif

    #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
    Cry_PrimStatus[LoopValue] = CRY_HSM_PRIM_NOT_STARTED;
    #endif
  }

  /* Initialize HSMCom by calling HsmCom_Init function */
  HsmCom_Init();

  BuffersPtr = &(HsmCom_DataBuffers.Ht2Hsm[0].Blocks[0]);

  /*Update parameters for dummy MAC verification to improve the performance*/
  Cry_HsmAesCMacDummyMacVerification();

  /* Initialize the shared buffer by calling the HSMCom interface
   * function */
  ErrorVal = HsmCom_InitSharedBuffer(BuffersPtr);

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  if (ErrorVal == HSMCOM_ERC_NO_ERROR )
  {
      Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
  }
  else
  {
      Det_ReportError(CSM_MODULE_ID,                                          \
      CRY_HSM_INSTANCE_ID, (uint8)CRY_HSM_SID_INIT, (uint8)CRY_HSM_E_UNINIT);
  }
#endif

#if(CRY_HSM_BSWM_ERROR_NOTIFICATION == STD_ON)
  BSWM_REPORT(ErrorVal)
#else
  if(ErrorVal != HSMCOM_ERC_NO_ERROR)
  {
    /* Do Nothing */
  }
#endif

}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmPrimitiveStart(                   **
**                                    Cry_HsmPrimitiveIdType PrimitiveId)    **
** Description     : This function initiates the handle for the primitive    **
**                   if the session is opened successfully.                  **
**                   This API is used by Cry_<Primitive>Start services.      **
**                                                                           **
**                                                                           **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : PrimitiveId                                             **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_BUSY: session not available / HsmCom busy         **
**                   CSM_E_OK: Session opened and handle initiated           **
**                             successfully for the primitive                **
******************************************************************************/
Csm_ReturnType Cry_HsmPrimitiveStart(Cry_HsmPrimitiveIdType PrimitiveId)
{
  Csm_ReturnType ErrorVal;
    Cry_Hsm *HandlePtr;

  ErrorVal = CSM_E_BUSY;

  /*check if HsmCom is busy */
  if( HsmCom_IsComBusy() == FALSE )
  {
    HandlePtr = Cry_lHsmInitiateHandle(PrimitiveId);
    /* HandlePtr == NULL indicates that session is not opened
     * HandlePtr != NULL indicates that session is opened */
    if (HandlePtr != NULL_PTR)
    {
      ErrorVal = CSM_E_OK;
    }
  }
  return ErrorVal;
  /* IFX_MISRA_RULE_08_13_STATUS=HandlePtr can't be declared as const */
}
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmPrimitiveFinish                   **
**                                   (Cry_HsmPrimitiveIdType PrimitiveId)    **
** Description     : This API deinitiates the handle by closing the session  **
**                   This API is used by Cry_<Primitive>Finish services.     **
**                                                                           **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous based on the configuration  **
**                    parameter CRY_HSM_USE_SYNC_JOB_PROCESSING              **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : PrimitiveId                                             **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK: Session closed and handle deinitiated         **
**                                                     successfully          **
**                   CSM_E_NOT_OK: Session is invalid                        **
******************************************************************************/
Csm_ReturnType Cry_HsmPrimitiveFinish(Cry_HsmPrimitiveIdType PrimitiveId)
{
  Csm_ReturnType ErrorVal;
  Cry_Hsm *HandlePtr;

  ErrorVal = CSM_E_NOT_OK;

  HandlePtr = Cry_lHsmGetActiveHandle(PrimitiveId);
  if (HandlePtr != NULL_PTR)
  {
    ErrorVal = CSM_E_OK;
    Cry_lHsmDeinitiateHandle(HandlePtr);
  }
  return ErrorVal;
}
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmStatusCheck                       **
**                                  (Cry_HsmPrimitiveIdType PrimitiveId      **
** Description     :  This API checks the present status of Hsm.             **
**                    This API is used in Cry_<Primitive>Update              **
**                     and Cry_<Primitive>Finish services to check the status**
**                     of HSM, before sending a new command                  **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : PrimitiveId                                             **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK: Hsm is free to send a new command             **
**                   CSM_E_BUSY: Hsm is busy as previous command is          **
**                                 not completed                             **
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmStatusCheck(Cry_HsmPrimitiveIdType PrimitiveId)
{
  Csm_ReturnType ErrorVal;
    Cry_Hsm *HandlePtr;

  ErrorVal = CSM_E_NOT_OK;
  HandlePtr = Cry_lHsmGetActiveHandle(PrimitiveId);

  if (HandlePtr != NULL_PTR)
  {
    /* HsmCom_IsComBusy == TRUE indicates that either HT2HSMF register is
     * not cleared or BUSY flag is not cleared  */
    if( HsmCom_IsComBusy() != FALSE )
    {
      ErrorVal = CSM_E_BUSY;
    }
    else
    {
      ErrorVal = CSM_E_OK;
    }
  }
  return ErrorVal;
  /*IFX_MISRA_RULE_08_13_STATUS=HandlePtr can't be declared as const*/
}

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 585] [$Satisfies $CDS_CDRV 736]   **
**                                                                           **
** Syntax          : void Cry_HsmPrimitiveMainFunction                       **
**                          (Cry_HsmPrimitiveIdType PrimitiveId,             **
**                              Cry_HsmAction FinishAction)                  **
** Description     : This is the common mainfunction for all the primitives  **
**                   in case of asynchronous mode                            **
**                                                                           **
**                                                                           **
** Service ID      : CRY_HSM_MAINFUNCTION_SID                                **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Reentrant                                               **
**                                                                           **
** Parameters (in) : PrimitiveId                                             **
**                   FinishAction: Function that cotains the action to be    **
**                    taken after the command is executed successfully.      **
**                    Ex: Copying the results to the application buffers     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
void Cry_HsmPrimitiveMainFunction(Cry_HsmPrimitiveIdType PrimitiveId,
                                            Cry_HsmAction FinishAction)
{
  Cry_Hsm *HandlePtr;
  HsmCom_Error HsmErr;
#if(CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF)
  HsmCom_Error HsmErrBswm;
#endif
  Csm_ReturnType ErrorVal;

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = FALSE;
  INIT_VALIDATION(CRY_HSM_MAINFUNCTION_SID, Cry_HsmInitStatus, DetErr)
  if(DetErr == FALSE)
  #endif
  {
    switch (Cry_PrimStatusAsync[PrimitiveId])
    {

      /* Cry_<Primitive>Start is executed for the primitive */
      case ASYNC_STATE_START:
      {
        /* Report the service return value to upper layer through callback */
        Cry_HsmCallbacksData[PrimitiveId].CallbackNotification
                                               (Cry_PrimErr[PrimitiveId]);
        Cry_PrimStatusAsync[PrimitiveId] = ASYNC_STATE_IDLE;
      }
      break;

      /* Cry_<Primitive>Update is executed for the primitive */
      case ASYNC_STATE_UPDATE:
      {
        /* check the status of Update service */
        if(Cry_PrimErr[PrimitiveId] != CSM_E_OK)
        {
          /* Update service is not successful. No need to wait for the
           * command result. Report the status to upper layer */
          Cry_HsmCallbacksData[PrimitiveId].CallbackNotification
                                             (Cry_PrimErr[PrimitiveId]);
          Cry_PrimStatusAsync[PrimitiveId] = ASYNC_STATE_IDLE;
        }
        else
          /* Update service is successful. Wait for the command response */
        {
          HandlePtr = Cry_lHsmGetActiveHandle(PrimitiveId);
          /* Wait till command is executed by HSM */
          if (HsmCom_IsCmdExecuted() != FALSE)
          {
            /* Read command result */
            HsmErr = HandlePtr->Session->Error;
            /*Check if KEY_EMPTY or KEY_INVALID is returned by HSM */
            if((HsmErr == HSMCOM_ERC_KEY_EMPTY) ||
               (HsmErr == HSMCOM_ERC_KEY_INVALID))
            {
              /* Check for AES/MAC-GEN/MAC-VER/GCM/XTS update command */
              if(Cry_Hsm_CommandMemoryMap[HsmCom_AsyncCommand] == 0xAAU)
              {
                /* Store the error */
                Cry_UpdateReturnValue = HsmErr;
                /* Set indication that update returned
                          KEY_EMPTY/KEY_INVALID error */
                Cry_UpdateReturnFlag = TRUE;
              }
            }
            #if(CRY_HSM_E_POLICY_VIOLATION != STD_OFF)
            /* Report the HSM error state to DEM */
            DEM_REPORT(HsmErr)
            #endif

            #if(CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF)
            HsmErrBswm = HsmErr;
            /* Report the HSM error state to BswM */
            BSWM_REPORT(HsmErrBswm)
            #endif

            /* Convert HSM response to corresponding CSM response
             *  to be reported to upper layer */
            ErrorVal = Cry_lHsmErrValidate(HsmErr);
            /* Report the command result to upper layer through callback */
            Cry_HsmCallbacksData[PrimitiveId].CallbackNotification (ErrorVal);
            /* Special case - if this Debug, then we must close the session! */
            /* De initiate the handle by closing the session */
            if (PrimitiveId == CRY_HSM_DEBUG)
            {
              if (ErrorVal!=CSM_E_OK)
              {
                Cry_lHsmDeinitiateHandle(HandlePtr);
              }
              else
              {
                #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
                Cry_PrimStatus[CRY_HSM_DEBUG] = CRY_HSM_PRIM_STARTED;
                #else
                /*Do Nothing*/
                #endif
              }
            }
            Cry_PrimStatusAsync[PrimitiveId] = ASYNC_STATE_IDLE;
          }
        }
      }
      break;

      /* Cry_<Primitive>Finish is executed for the primitive */
      case ASYNC_STATE_FINISH:
      {
        /* check the status of Finish service */
        if(Cry_PrimErr[PrimitiveId] != CSM_E_OK)
        {
          /* Finish service is not successful. No need to wait for the
           * command result. Report the status to upper layer */
           Cry_HsmCallbacksData[PrimitiveId].CallbackNotification
                      (Cry_PrimErr[PrimitiveId]);
           Cry_HsmCallbacksData[PrimitiveId].FinishNotification();
           Cry_PrimStatusAsync[PrimitiveId] = ASYNC_STATE_IDLE;
         }
         else
         /* Finish service is successful. Wait for the
          * command response */
         {
           HandlePtr = Cry_lHsmGetActiveHandle(PrimitiveId);
           if(HandlePtr == NULL_PTR)
           {
             /* Finish service returned CSM_E_OK but HandlePtr == NULL,
              * means the session is already closed as no command is
              * required to be sent in Finish */
             Cry_HsmCallbacksData[PrimitiveId].CallbackNotification
                                           (Cry_PrimErr[PrimitiveId]);
             Cry_HsmCallbacksData[PrimitiveId].FinishNotification();
             Cry_PrimStatusAsync[PrimitiveId] = ASYNC_STATE_IDLE;
           }
           /* Wait till command is executed by HSM */
           else if (HsmCom_IsCmdExecuted() != FALSE)
           {
             /* Read command result */
             HsmErr = HandlePtr->Session->Error;
             /* Check if update returned key empty or key invalid error */
             if (Cry_UpdateReturnFlag == TRUE)
             {
               /* Check for AES/MAC-GEN/MAC-VER/GCM/XTS finish command */
               if(Cry_Hsm_CommandMemoryMap[HsmCom_AsyncCommand] == 0xBBU)
               {
                 /* Over write the error, except for command CANCELLED */
                 if(HsmErr != HSMCOM_ERC_CANCELLED)
                 {
                   HsmErr = Cry_UpdateReturnValue;
                 }
                 /* clear the flag as finish command is executed */
                 Cry_UpdateReturnFlag = FALSE;
               }
             }
             #if(CRY_HSM_E_POLICY_VIOLATION != STD_OFF)
             /* Report the HSM error state to DEM */
             DEM_REPORT(HsmErr)
             #endif

             #if(CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF)
             HsmErrBswm = HsmErr;
             /* Report the HSM error state to BswM */
             BSWM_REPORT(HsmErrBswm)
             #endif

             /* Convert HSM response to corresponding CSM
              * response to be reported to upper layer */
             ErrorVal = Cry_lHsmErrValidate(HsmErr);
             Cry_HsmCallbacksData[PrimitiveId].CallbackNotification(ErrorVal);
             /* Execute Finish action, only if the command is successfully
              * completed. */
             if (FinishAction != NULL_PTR)
             {
               FinishAction();
             }
             /* De initiate the handle by closing the session */
             Cry_lHsmDeinitiateHandle(HandlePtr);
             Cry_HsmCallbacksData[PrimitiveId].FinishNotification();
             Cry_PrimStatusAsync[PrimitiveId]= ASYNC_STATE_IDLE;
           }
           else
           {
             /*Dummy*/
           }
         }
       }
       break;

      case ASYNC_STATE_IDLE:
      {
        /*Do nothing */
      }
      break;

      default:
      {
        /*Do nothing */
      }
      break;
    }
  }
}
#endif

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 567] [$Satisfies $CDS_CDRV 583]   **
**                   [$Satisfies $CDS_CDRV 737]                              **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmSendCommandCommon      **
**                      (Cry_Hsm *HandlePtr,HsmCom_Command Command,          **
**                               uint32 TimeOut)                             **
**                                                                           **
** Description     :                                                         **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : HandlePtr- Handle pointer that contains the session     **
**                              pointer                                      **
**                   Command- Command to be processed by HSM                 **
**                   TimeOut- Timeout value                                  **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK- Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK- Request failed                            **
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmSendCommandCommon(Cry_Hsm *HandlePtr,
            HsmCom_Command Command, uint32 TimeOut)
{
  Csm_ReturnType ErrorVal;
  HsmCom_Error ComErr;
#if(CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF)
  HsmCom_Error ComErrBswm;
#endif
  HsmCom_Session SessionDataPtr;
  CRY_HSM_TICK_TYPE StartTime = 0U;
  CRY_HSM_TICK_TYPE ElapsedTime;
  CRY_HSM_TICK_TYPE TimeoutTicks;
  Cry_HsmStatesType CurrentState;
  boolean CmdResult;
  boolean CallbackNotifyTmp;

  ComErr = HSMCOM_ERC_NO_ERROR;
  SessionDataPtr = HandlePtr->Session;

  TimeoutTicks = TimeOut;
  HsmCom_CallbackNotify = FALSE;
  /* Clear the HSM2HTF register before sending a new command
   * to make sure that late response from HSM is cleared */
  HsmCom_ClearHsmResp();

  /* Send the command to HSM */
  HsmCom_SendCommand(SessionDataPtr, Command);
  /* Start the timer after sending the command. */
  StartTime = Cry_Hsm_StartTimer(TimeoutTicks);
  #if CRY_HSM_USER_TIMEOUT_API == STD_OFF
  Gpt_EnableNotification(CRY_HSM_GPT_CHANNEL);
  #endif
  CurrentState = CRY_HSM_STATEWAITFORRESPONSE;

  do
  {
    /* Get elapsed time since the Command has been sent */
    /** Traceability    : [$Satisfies $CDS_CDRV 582]    **/
    ElapsedTime = Cry_Hsm_GetElapsedTime(StartTime);
    CallbackNotifyTmp = HsmCom_CallbackNotify;
    /** Traceability    : [$Satisfies $CDS_CDRV 571]   **/
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    /* HSMCOM_CMD_SAFE_MAC_VER_FINISH is a special case,
     * where CRY has to wait till the command is executed
     * even though the mode is Asynchronous */
    /** Traceability    : [$Satisfies $CDS_CDRV 573]
                          [$Satisfies $CDS_CDRV 584]
                          [$Satisfies $CDS_CDRV 585]  **/
    if(Command == HSMCOM_CMD_SAFE_MAC_VER_FINISH)
    {
      CmdResult = HsmCom_IsCmdExecuted();
      ComErr = SessionDataPtr->Error;
    }
    else
    {
      /* Check if the command is Accepted by HSM */
      /** Traceability    : [$Satisfies $CDS_CDRV 584]   **/
      CmdResult = HsmCom_IsCmdAccepted();
    }
    if (CmdResult != FALSE)
    {
      /* Command is accepted by HSM.
       * Incase of HSMCOM_CMD_SAFE_MAC_VER_FINISH, command
       * is executed */
      CurrentState = CRY_HSM_STATEREADY;
    }
    #else
    /* Check if the command is executed by HSM */
    CmdResult = HsmCom_IsCmdExecuted();
    if (CmdResult != FALSE)
    {
      CurrentState = CRY_HSM_STATEREADY;
      ComErr = SessionDataPtr->Error;
    }
    #endif
    else
    {
      /* check if timeout occurs */
      /** Traceability    : [$Satisfies $CDS_CDRV 582]    **/
      if ( (ElapsedTime >= TimeoutTicks) || (CallbackNotifyTmp == TRUE) )
      {
        CurrentState = CRY_HSM_STATETIMEOUT;
        ComErr = HSMCOM_ERC_TIMEOUT;
      }
    }
  }while (CurrentState == CRY_HSM_STATEWAITFORRESPONSE);
  /*End of "do while while (CurrentState == CRY_HSM_STATEWAITFORRESPONSE)" */
  /* Stop the timer */
  Cry_Hsm_StopTimer();

  /* Modify error code for FINISH if UPDATE returns HSMCOM_ERC_KEY_EMPTY
     or HSMCOM_ERC_KEY_INVALID */
  ComErr = FinishCommandErrorValidate(ComErr, Command);

#if(CRY_HSM_E_POLICY_VIOLATION != STD_OFF)
  /* For SAFE_MAC_VER_FINISH_CHECK command, report DEM error only if
     SAFE_MAC_VER_FINISH command was success earlier. This is to ensure
     that Cry_HsmAesCMacVerifyFinish function reports error only once */
  if(Cry_MacVerError == FALSE)
  {
    /* Report the HSM error state to DEM */
    DEM_REPORT(ComErr)
  }
#endif

#if(CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF)
  /* For SAFE_MAC_VER_FINISH_CHECK command, report BswM error only if
     SAFE_MAC_VER_FINISH command was success earlier. This is to ensure
     that Cry_HsmAesCMacVerifyFinish function reports error only once */
  if(Cry_MacVerError == FALSE)
  {
    ComErrBswm = ComErr;
    /* Report the HSM error state to BswM */
    BSWM_REPORT(ComErrBswm)
  }
#endif

  if (CurrentState != CRY_HSM_STATEREADY)
  {
    /** Traceability    : [$Satisfies $CDS_CDRV 581]    **/
    ErrorVal = CSM_E_NOT_OK;
  }
  else
  {
    /* Convert the HSM response to corresponding CSM response to be
     * returned to the upper layer */
    ErrorVal = Cry_lHsmErrValidate(ComErr);
  }


  return ErrorVal;
  /*IFX_MISRA_RULE_08_13_STATUS= HandlePtr cannot be made const
   * as the calling functions doesn't support */
}
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : HsmCom_Error FinishCommandErrorValidate(HsmCom_Error    **
**                   Err, HsmCom_Command Command)                            **
**                                                                           **
** Description     : Function validates the HSM return value for Finish      **
**                   command, if corresponding update command returned       **
**                   KEY EMPTY or KEY INVALID                                **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : Err: Command response returned by HSM                   **
                     Command: Command sent to HSM                            **
**                                                                           **
** Parameters (out): Modified command response                               **
**                                                                           **
******************************************************************************/
HsmCom_Error FinishCommandErrorValidate(HsmCom_Error Err, HsmCom_Command
                                                                   Command)
{
  HsmCom_Error RetErr;

  RetErr = Err;
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON)
  /* Check if HSM returned KEY_EMPTY or KEY_INVALID error */
  if((RetErr == HSMCOM_ERC_KEY_EMPTY) ||
     (RetErr == HSMCOM_ERC_KEY_INVALID))
  {
    /* Check for AES/MAC-GEN/MAC-VER/GCM/XTS update command */
    if(Cry_Hsm_CommandMemoryMap[Command] == 0xAAU)
    {
      /* Store the error */
      Cry_UpdateReturnValue = RetErr;
      /* Set indication that update returned KEY_EMPTY/KEY_INVALID error */
      Cry_UpdateReturnFlag = TRUE;
    }
  }
  if (Cry_UpdateReturnFlag == TRUE)
  {
    /* Check for AES/MAC-GEN/MAC-VER/GCM/XTS finish command */
    if(Cry_Hsm_CommandMemoryMap[Command] == 0xBBU)
    {
      /* Over write the error, except for CANCELLED and TIMEOUT */
      if((RetErr != HSMCOM_ERC_CANCELLED) && (RetErr != HSMCOM_ERC_TIMEOUT))
      {
        RetErr = Cry_UpdateReturnValue;
      }
      /* Clear the flag as Finish command is executed */
      Cry_UpdateReturnFlag = FALSE;
    }
  }
#else
  if (Cry_UpdateReturnFlag == TRUE)
  {
    /* Check for SAFE_MAC_VER_FINISH command */
    if(Command == HSMCOM_CMD_SAFE_MAC_VER_FINISH)
    {
      /* Over write the error, except for CANCELLED and TIMEOUT */
      if((RetErr != HSMCOM_ERC_CANCELLED) && (RetErr != HSMCOM_ERC_TIMEOUT))
      {
        RetErr = Cry_UpdateReturnValue;
      }
      /* Clear the flag as SAFE_MAC_VER_FINISH command is completed */
      Cry_UpdateReturnFlag = FALSE;
    }
    else
    {
      /* Check for AES/MAC-GEN/MAC-VER/GCM/XTS finish command
         Clear the flag if TIMEOUT occurs */
      if((Cry_Hsm_CommandMemoryMap[Command] == 0xBBU) &&
          (RetErr == HSMCOM_ERC_TIMEOUT))
      {
        Cry_UpdateReturnFlag = FALSE;
      }
    }
  }
#endif
  return RetErr;
}

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 611]                              **
**                                                                           **
** Syntax          : uint32 Cry_HsmGetStatus(void)                           **
**                                                                           **
** Description     : This API returns the status of the HSM by calling       **
**                   HsmCom_GetStatus                                        **
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
** Return value    : The status of the HSM                                   **
**                                                                           **
******************************************************************************/
uint32 Cry_HsmGetStatus(void)
{
  uint32 HsmStatus;
  /* HsmCom_GetStatus function returns the lowest 8 bits of
   * HSM2HTS status register value */
  HsmStatus = HsmCom_GetStatus();
  return HsmStatus;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 645] [$Satisfies $CDS_CDRV 744]   **
**                                                                           **
** Syntax          : void Cry_HsmSheCancel(void)                             **
**                                                                           **
** Description     : This API Cancels the ongoing command by calling         **
**                   HsmCom_SheCancel()                                      **
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
void Cry_HsmSheCancel(void)
{
  HsmCom_Error Retval;
  Retval = HsmCom_SheCancel();
  /*If timeout happens, a BswM error HSM_ERC_TIMEOUT (0xE0) shall be
    reported*/
#if(CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF)
  BSWM_REPORT(Retval)
#else
  if(Retval != HSMCOM_ERC_NO_ERROR)
  {
    /* Do Nothing */
  }
#endif
}
#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_C*/
