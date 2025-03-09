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
**  FILENAME   : Cry_HsmRandomSeedInit.c                                     **
**                                                                           **
**  VERSION :    3.0.0                                                       **
**                                                                           **
**  DATE       : 2016-07-11                                                  **
**                                                                           **
**  VARIANT   : NA                                                           **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR    : Trivikram G                                                  **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the services related to Random seed     **
**                initialization                                             **
**                                                                           **
**  SPECIFICATION(S) : Aurix_SHE+_TC-CDRV_DS.docx                            **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*
<IFX_RCH>
</IFX_RCH>
*/
/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_Hsm_Priv.h"
#include "Cry_HsmRandomSeedInit.h"
/******************************************************************************
**                      Imported Compiler Switch Check                       **
******************************************************************************/

/******************************************************************************
**                      Private Type Definitions                             **
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
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

const Cry_HsmRandomSeedInitConfigType   Cry_kHsmRandomSeedInitConfig     =
                             {.TimeOut = CRY_HSM_RANDOM_SEED_INIT_ALL_TIMEOUT};

static const Cry_HsmPrimitiveIdType Cry_PRMIDRndInit =
                                                  CRY_HSM_RANDOM_SEED_INIT;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Variable Definitions                           **
******************************************************************************/

/******************************************************************************
**                     Global Function Defintion                             **
******************************************************************************/

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 1] [$Satisfies $CDS_CDRV 2]       **
**                   [$Satisfies $CDS_CDRV 3] [$Satisfies $CDS_CDRV 4]       **
**                   [$Satisfies $CDS_CDRV 5] [$Satisfies $CDS_CDRV 579]     **
** Syntax          : Csm_ReturnType Cry_HsmRandomSeedInitStart               **
**                                                      (const void *CfgPtr) **
**                                                                           **
** Description     : This function implements Cry_HsmRandomSeedInitStart for **
**                   Csm_RandomSeedStart service. It reserves and initializes**
**                   resources for Csm_RandomSeed service                    **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_INIT_START                         **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr   -Pointer to configuration structure of         **
**                             Cry_HsmRandomSeedExtendConfigType This        **
**                             parameter is ignored                          **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
******************************************************************************/
Csm_ReturnType Cry_HsmRandomSeedInitStart(const void *CfgPtr)
{
    Csm_ReturnType RetVal;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
    boolean DetErr;
#endif

    UNUSED_POINTER (CfgPtr)

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
    DetErr = DEV_NO_ERROR;
    INIT_VALIDATION(CRY_HSM_SID_RND_SEED_INIT_START, Cry_HsmInitStatus,
                                                  DetErr)
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
        RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDRndInit);
        /* Check if the session opened successfully */
        if(RetVal != CSM_E_BUSY)
        {
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
            /* Set the indication that START service is successful.
             * To be used by UPDATE and FINISH services to check the
             * DET "CSM_E_SERVICE_NOT_STARTED" */
            Cry_PrimStatus[Cry_PRMIDRndInit] = CRY_HSM_PRIM_STARTED;
#endif
        }
    }

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    /* Set the indication to main function that START service is executed */
    Cry_PrimStatusAsync[Cry_PRMIDRndInit] = ASYNC_STATE_START;
    /* Store the service return value.
     * To be used by the main function to report the status to upper layer */
    Cry_PrimErr[Cry_PRMIDRndInit] = RetVal;
#endif

    return RetVal;
}

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 6] [$Satisfies $CDS_CDRV 7]       **
**                   [$Satisfies $CDS_CDRV 8] [$Satisfies $CDS_CDRV 9]       **
**                   [$Satisfies $CDS_CDRV 10] [$Satisfies $CDS_CDRV 11]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType  Cry_HsmRandomSeedInitUpdate(            **
**                            const void *CfgPtr, const uint8 *SeedPtr,      **
**                            uint32 SeedLength)                             **
**                                                                           **
** Description     : This function implements Cry_HsmRandomSeedInitUpdate for**
**                   Csm_RandomSeedUpdate service. It sends request to HSM   **
**                   to initialize the RNG                                   **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_INIT_UPDATE                        **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr   -Pointer to configuration structure of         **
                                Cry_HsmRandomSeedInitConfigType.             **
                    SeedPtr   -This parameter is ignored                     **
                    SeedLength-This parameter is ignored                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
Csm_ReturnType  Cry_HsmRandomSeedInitUpdate(
        const void *CfgPtr, const uint8 *SeedPtr, uint32 SeedLength)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmRandomSeedInitConfigType* SeedCfgPtr;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
#endif
  UNUSED_POINTER (SeedPtr)
  UNUSED_PARAMETER (SeedLength);

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_RND_SEED_INIT_UPDATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_RND_SEED_INIT_UPDATE,
                     Cry_PrimStatus[Cry_PRMIDRndInit], DetErr)
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
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDRndInit);
    if(RetVal == CSM_E_OK)
    {
      HandlePtr = &(Cry_HsmData[Cry_PRMIDRndInit]);
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the
       * input config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the
       * input config pointer is of type void */
      SeedCfgPtr = (const Cry_HsmRandomSeedInitConfigType*) CfgPtr;
      /* Store Key page value (dummy for this service) and
       * AES mode (dummy for this service) in session data */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                   CRY_HSM_AES_MODE_DUMMY);
      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                   HSMCOM_CMD_RND_INIT,
                   CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(SeedCfgPtr,0U));
    }
  }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    /* Set the indication to main function that UPDATE service is executed */
    Cry_PrimStatusAsync[Cry_PRMIDRndInit] = ASYNC_STATE_UPDATE;
    /* Store the service return value.
     * To be used by the main function to do further processing */
    Cry_PrimErr[Cry_PRMIDRndInit] = RetVal;
#endif

  return RetVal;
}

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 12] [$Satisfies $CDS_CDRV 13]     **
**                   [$Satisfies $CDS_CDRV 14] [$Satisfies $CDS_CDRV 15]     **
**                   [$Satisfies $CDS_CDRV 16] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType  Cry_HsmRandomSeedInitFinish             **
**                                                  (const void *CfgPtr)     **
**                                                                           **
** Description     : This function implements Cry_HsmRandomSeedInitFinish    **
**                   for Csm_RandomSeedFinish service. It releases resources **
**                    used by Csm_RandomSeed service                         **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_INIT_FINISH                        **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr                                                  **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK - Request failed                           **
******************************************************************************/
Csm_ReturnType  Cry_HsmRandomSeedInitFinish(const void *CfgPtr)
{
    Csm_ReturnType RetVal;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
#endif
  UNUSED_POINTER (CfgPtr)

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  START_VALIDATION(CRY_HSM_SID_RND_SEED_INIT_FINISH,
                   Cry_PrimStatus[Cry_PRMIDRndInit], DetErr)
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
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDRndInit);
    if(RetVal == CSM_E_OK)
    {
      /* Finish the primitive by closing the session */
      RetVal = Cry_HsmPrimitiveFinish(Cry_PRMIDRndInit);
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      if(RetVal == CSM_E_OK)
      {
        /* Set the primitive status to FINISHED.
         * Status will be changed again if the START
         * is executed successfully */
        Cry_PrimStatus[Cry_PRMIDRndInit] = CRY_HSM_PRIM_FINISHED;
      }
#endif
    }
  }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that FINISH service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDRndInit] = ASYNC_STATE_FINISH;
  /* Store the service return value.
   * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDRndInit] = RetVal;
#endif

  return RetVal;
}
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 17] [$Satisfies $CDS_CDRV 579]    **
**                                                                           **
** Syntax          : void Cry_HsmRandomSeedInitMainFunction(void)            **
**                                                                           **
** Description     : This function implements                                **
                     Cry_HsmRandomSeedInitMainFunction                       **
                     for Csm_RandomSeed... service                           **
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
void Cry_HsmRandomSeedInitMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDRndInit, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_SEED_INIT_C*/
