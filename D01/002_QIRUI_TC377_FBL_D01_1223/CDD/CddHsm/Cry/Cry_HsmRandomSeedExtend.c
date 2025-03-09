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
**  FILENAME   : Cry_HsmRandomSeedExtend.c                                   **
**                                                                           **
**  VERSION :   3.0.0                                                        **
**                                                                           **
**  DATE       : 2016-07-11                                                  **
**                                                                           **
**  VARIANT   : NA                                                           **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR      : Trivikram G                                                **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the services related to Random seed     **
**                extension                                                  **
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
#include "Cry_HsmRandomSeedExtend.h"

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

const Cry_HsmRandomSeedExtendConfigType Cry_kHsmRandomSeedExtendConfig   =
                          {.TimeOut = CRY_HSM_RANDOM_SEED_EXTEND_ALL_TIMEOUT};


static const Cry_HsmPrimitiveIdType Cry_PRMIDRndExt =
                                             CRY_HSM_RANDOM_SEED_EXTEND;

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
** Traceability    : [$Satisfies $CDS_CDRV 18] [$Satisfies $CDS_CDRV 19]     **
**                   [$Satisfies $CDS_CDRV 20] [$Satisfies $CDS_CDRV 21]     **
*                    [$Satisfies $CDS_CDRV 22] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType Cry_HsmRandomSeedExtendStart             **
**                                              (const void *CfgPtr)         **
**                                                                           **
** Description     : This functionimplements Cry_HsmRandomSeedExtendStart for**
**                   Csm_RandomSeedStart service. It reserves and initializes**
**                    resources for Csm_RandomSeed service                   **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_EXTEND_START                       **
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
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmRandomSeedExtendStart(const void *CfgPtr)
{
  Csm_ReturnType RetVal;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
#endif

  UNUSED_POINTER (CfgPtr)

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  INIT_VALIDATION(CRY_HSM_SID_RND_SEED_EXTEND_START, Cry_HsmInitStatus,
                            DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    if(Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT] != CRY_HSM_PRIM_FINISHED)
    {
      DET_REPORT(CRY_HSM_SID_RND_SEED_EXTEND_START,
                  CRY_HSM_E_SERVICE_NOT_STARTED, DetErr)
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
    /* Initiate the handle for the session */
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDRndExt);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the indication that START service is successful.
       * To be used by UPDATE and FINISH services to check the
       * DET "CSM_E_SERVICE_NOT_STARTED" */
       Cry_PrimStatus[Cry_PRMIDRndExt] = CRY_HSM_PRIM_STARTED;
#endif
    }
  }

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    /* Set the indication to main function that START service is executed */
    Cry_PrimStatusAsync[Cry_PRMIDRndExt] = ASYNC_STATE_START;
    /* Store the service return value.
     * To be used by the main function to report the status to upper layer */
    Cry_PrimErr[Cry_PRMIDRndExt] = RetVal;
#endif
  return RetVal;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 24]                               **
**                   [$Satisfies $CDS_CDRV 25] [$Satisfies $CDS_CDRV 26]     **
**                   [$Satisfies $CDS_CDRV 27] [$Satisfies $CDS_CDRV 28]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType  Cry_HsmRandomSeedExtendUpdate(          **
**              const void *CfgPtr, const uint8 *SeedPtr, uint32 SeedLength) **
**                                                                           **
** Description     : This functionimplements Cry_HsmRandomSeedExtendUpdate   **
**                   for Csm_RandomSeedUpdate service. It sends request to   **
**                   HSM to extend the RNG seed.                             **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_EXTEND_UPDATE                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) :CfgPtr   -Pointer to configuration structure of          **
**                            Cry_HsmRandomSeedExtendConfigType              **
**                  SeedPtr  -Pointer to data which will be used as ENTROPY  **
**                            of CMD_EXTEND_SEED                             **
**                  seedLength-Only 16 bytes block size is supported. So     **
**                             this parameter is unused.                     **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
Csm_ReturnType  Cry_HsmRandomSeedExtendUpdate(
        const void *CfgPtr, const uint8 *SeedPtr, uint32 SeedLength)
{

  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmRandomSeedExtendConfigType* SeedCfgPtr;
  HsmCom_RandomSeedParams *ParamPtr;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
#endif

  UNUSED_PARAMETER (SeedLength);

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_RND_SEED_EXTEND_UPDATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_RND_SEED_EXTEND_UPDATE, SeedPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_RND_SEED_EXTEND_UPDATE,
                  Cry_PrimStatus[Cry_PRMIDRndExt], DetErr)
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
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDRndExt);
    if(RetVal == CSM_E_OK)
    {
      HandlePtr = &(Cry_HsmData[Cry_PRMIDRndExt]);
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the
      * input config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the
      * input config pointer is of type void */
      SeedCfgPtr = (const Cry_HsmRandomSeedExtendConfigType*) CfgPtr;
      /* Store Key page value (dummy for this service) and
       * AES mode (dummy for this service) in session data */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                    CRY_HSM_AES_MODE_DUMMY);
      /* Get the shared buffer address */
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
      *aligned to the struture pointer containing the elements
      *for Random Seed*/
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /* Update seed address in shared buffer*/
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle
       *data sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      ParamPtr->SeedAddr = (HostAddr) SeedPtr;
      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
               HSMCOM_CMD_RND_SEED_EXTEND,
               CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(SeedCfgPtr,0U));
    }
  }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    /* Set the indication to main function that UPDATE service is executed */
    Cry_PrimStatusAsync[Cry_PRMIDRndExt] = ASYNC_STATE_UPDATE;
    /* Store the service return value.
     * To be used by the main function to do further processing */
    Cry_PrimErr[Cry_PRMIDRndExt] = RetVal;
#endif
  return RetVal;
}

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 29] [$Satisfies $CDS_CDRV 30]     **
**                   [$Satisfies $CDS_CDRV 31] [$Satisfies $CDS_CDRV 32]     **
**                   [$Satisfies $CDS_CDRV 33] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType  Cry_HsmRandomSeedExtendFinish           **
**                                              (const void *CfgPtr)         **
**                                                                           **
** Description     : This functionimplements Cry_HsmRandomSeedExtendFinishfor**
**                   Csm_RandomSeedFinish service. It releases resources used**
**                   by Csm_RandomSeed service                               **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_EXTEND_FINISH                      **
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
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
Csm_ReturnType  Cry_HsmRandomSeedExtendFinish(const void *CfgPtr)
{
  Csm_ReturnType RetVal;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
#endif

  UNUSED_POINTER (CfgPtr)

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  START_VALIDATION(CRY_HSM_SID_RND_SEED_EXTEND_FINISH,
                   Cry_PrimStatus[Cry_PRMIDRndExt], DetErr)
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
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDRndExt);
    if(RetVal == CSM_E_OK)
    {
      /* Finish the primitive by closing the session */
      RetVal = Cry_HsmPrimitiveFinish(Cry_PRMIDRndExt);
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      if(RetVal == CSM_E_OK)
      {
        /* Set the primitive status to FINISHED.
        * Status will be changed again if the START
        * is executed successfully */
        Cry_PrimStatus[Cry_PRMIDRndExt] = CRY_HSM_PRIM_FINISHED;
      }
#endif
    }
  }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that FINISH service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDRndExt] = ASYNC_STATE_FINISH;
  /* Store the service return value.
  * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDRndExt] = RetVal;
#endif
  return RetVal;
}
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 34] [$Satisfies $CDS_CDRV 579]    **
**                                                                           **
** Syntax          : void Cry_HsmRandomSeedExtendMainFunction(void)          **
**                                                                           **
** Description     : This function implements Cry_MainFunction for           **
**                    Csm_RandomSeed... service                              **
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
void Cry_HsmRandomSeedExtendMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDRndExt, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_RANDOM_SEEED_EXTEND_C*/
