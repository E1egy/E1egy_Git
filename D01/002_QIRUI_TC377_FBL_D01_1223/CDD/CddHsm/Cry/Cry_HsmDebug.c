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
**  FILENAME    : Cry_HsmDebug.c                                              **
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
**  DESCRIPTION : This file contains the services related to Debug            **
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

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Cry_Hsm_Priv.h"
#include "Cry_HsmDebug.h"

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
**                     Global Constant Definition                            **
******************************************************************************/
#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"

static Cry_HsmPrimitiveIdType Cry_PRMIDDebug = CRY_HSM_DEBUG;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
#else
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

static const Cry_HsmPrimitiveIdType Cry_PRMIDDebug = CRY_HSM_DEBUG;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
#endif
/******************************************************************************
**                     Global Variable Definitions                           **
******************************************************************************/

/******************************************************************************
**                     Global Structure Definition                           **
******************************************************************************/
/*******************************************************************************
**                     Global Function Definition                             **
*******************************************************************************/

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"


/******************************************************************************
** Traceability    :  [$Satisfies $CDS_CDRV 620], [$Satisfies $CDS_CDRV 621] **
**                    [$Satisfies $CDS_CDRV 622], [$Satisfies $CDS_CDRV 623] **
**                    [$Satisfies $CDS_CDRV 624], [$Satisfies $CDS_CDRV 625] **
**                    [$Satisfies $CDS_CDRV 579], [$Satisfies $CDS_CDRV 636] **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmDebugStart(uint8* Cry_Challenge)  **
**                                                                           **
** Description     : This function implements Cry_HsmDebugStart. It requests **
**                   debugger activation  on the HSM side.                   **
**                                                                           **
** Service ID      : CRY_HSM_SID_DEBUG_START                                 **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): Cry_Challenge  - Random number of length 128 bits       **
**                                    that is input for calculating the      **
**                                    debugger activation.                   **
**                                                                           **
** Return value    : CSM_E_OK       - Request successful                     **
**                   CSM_E_BUSY     - Request failed as underlying HSM       **
**                                    communication is busy                  **
**                   CSM_E_NOT_OK   - Request failed                         **
******************************************************************************/
Csm_ReturnType Cry_HsmDebugStart(uint8* Cry_Challenge)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  /* Pointer to the structure that defines the parameters to be stored in shared
   * buffer */
  HsmCom_DebugStartParams *ParamPtr;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_DEBUG_START, Cry_Challenge, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    INIT_VALIDATION(CRY_HSM_SID_DEBUG_START, Cry_HsmInitStatus, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    if(Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT] !=
                                CRY_HSM_PRIM_FINISHED)
    {
      DET_REPORT(CRY_HSM_SID_DEBUG_START,
              CRY_HSM_E_SERVICE_NOT_STARTED, DetErr)
    }
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
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDDebug);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      HandlePtr = Cry_lHsmGetActiveHandle(Cry_PRMIDDebug);

      /* Call HsmCom_GetParamsBuffer to fetch shared memory address */
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
       * aligned to the struture pointer containing the elements
       * for Debug */
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);

      /* Load the Output Pointer address to Shared memory */
      /*IFX_MISRA_RULE_11_04_STATUS=Type casting is required as the
       * input Cry_Challenge is of type uint8*/
      /*IFX_MISRA_RULE_11_06_STATUS=Type casting is required as the
       * input Cry_Challenge is of type uint8*/
      ParamPtr->Challenge = (HostAddr) Cry_Challenge;


      /* Store Key page value (dummy for this service) and
      * AES mode (dummy for this service) in session data */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                   CRY_HSM_AES_MODE_DUMMY);
      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                 HSMCOM_CMD_DEBUG_START,
                 CRY_HSM_DEBUG_START_TIMEOUT);

      /* In both sync and async mode, if we get an error, then we close the
       * session since we want to be able to call start again */
      if (RetVal != CSM_E_OK)
      {
        Cry_lHsmDeinitiateHandle(HandlePtr);
      }
      #if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON) && \
           (CRY_HSM_DEV_ERROR_DETECT == STD_ON))
      else {
      /* Set the indication that START service is successful.
      * To be used by FINISH services to check the
      * DET "CSM_E_SERVICE_NOT_STARTED" */
      Cry_PrimStatus[Cry_PRMIDDebug] = CRY_HSM_PRIM_STARTED;
      }
      #endif
    }
  }
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    /* Set the indication to main function that START service is executed.
     * Note that we set the state to UPDATE because we need the command response
     * to be checked.  */
    Cry_PrimStatusAsync[Cry_PRMIDDebug] =  ASYNC_STATE_UPDATE;
    /* Store the service return value. To be used by the main function to report
     * the status to upper layer */
    Cry_PrimErr[Cry_PRMIDDebug] = RetVal;
    #endif

  return RetVal;
}

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/******************************************************************************
** Traceability    :  [$Satisfies $CDS_CDRV 626], [$Satisfies $CDS_CDRV 627] **
**                    [$Satisfies $CDS_CDRV 628], [$Satisfies $CDS_CDRV 629] **
**                    [$Satisfies $CDS_CDRV 630], [$Satisfies $CDS_CDRV 631] **
**                    [$Satisfies $CDS_CDRV 579]  [$Satisfies $CDS_CDRV 637] **
**                    [$Satisfies $CDS_CDRV 638]                             **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmDebugFinish(                      **
**                        uint8* Cry_Authorization)                          **
**                                                                           **
** Description     : This function sends the authorization value for         **
**                   activation of debugger to the HSM                       **
**                                                                           **
** Service ID      : CRY_HSM_SID_DEBUG_FINISH                                **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : Cry_Authorization - Authorization value for activation  **
**                                      of debugger to the HSM               **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK       - Request successful                     **
**                   CSM_E_NOT_OK   - Request failed                         **
**                   CSM_E_BUSY     - Request failed due to underlying HSM   **
**                                    communication is busy                  **
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmDebugFinish (uint8* Cry_Authorization)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
#ifdef CONTROLLER_TC23x
  uint32 TrapDisStat;
#endif
  /* Pointer to the structure that defines the parameters to be stored in
   * shared buffer */
  HsmCom_DebugFinishParams *ParamPtr;

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_DEBUG_FINISH, Cry_Authorization, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_DEBUG_FINISH,
                   Cry_PrimStatus[Cry_PRMIDDebug], DetErr)
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
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDDebug);
    if(RetVal == CSM_E_OK)
    {
      /* Get the active handle for the primitive */
      HandlePtr = &(Cry_HsmData[Cry_PRMIDDebug]);
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
       * aligned to the struture pointer containing the elements
       * for Debug */
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /*IFX_MISRA_RULE_11_04_STATUS=Type casting is required as the
       * input Cry_Authorization is of type uint8*/
      /*IFX_MISRA_RULE_11_06_STATUS=Type casting is required as the
       * input Cry_Authorization is of type uint8*/
      ParamPtr->Authorization = (HostAddr)(Cry_Authorization);
      /* Store Key page value (dummy for this service) and
      * AES mode (dummy for this service) in session data */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                   CRY_HSM_AES_MODE_DUMMY);
#ifdef CONTROLLER_TC23x
      TrapDisStat = HsmMcal_GetTrapDisableStatus();
      /* PF0 traps must be disabled because of ECC errors that may occur during
      * FEE/FLS initialization or write operations
      */
      HsmMcal_DisableEccErrors();
#endif
      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                 HSMCOM_CMD_DEBUG_FINISH,
                 CRY_HSM_DEBUG_FINISH_TIMEOUT);
#ifdef CONTROLLER_TC23x
      HsmMcal_EnableEccErrors(TrapDisStat);
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

      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
        /* Set the primitive status to FINISHED.
        * Status will be changed again if the START
        * is executed successfully */
        Cry_PrimStatus[Cry_PRMIDDebug] = CRY_HSM_PRIM_FINISHED;
      #endif
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that FINISH service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDDebug] = ASYNC_STATE_FINISH;
  /* Store the service return value.
   * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDDebug] = RetVal;
  #endif

  return RetVal;
}

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 619] [$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          : void Cry_HsmDebugMainFunction(void)                     **
**                                                                           **
** Description     : This function doesn't exist in case of synchronous      **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_DEBUG command       **
**                   and closes the session                                  **
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
void Cry_HsmDebugMainFunction(void)
{

  Cry_HsmPrimitiveMainFunction(Cry_PRMIDDebug, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_DEBUG*/
