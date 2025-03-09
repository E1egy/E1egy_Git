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
**  FILENAME   : Cry_HsmRandomGenerate.c                                     **
**                                                                           **
**  VERSION    : 5.0.0                                                       **
**                                                                           **
**  DATE       : 2017-10-31                                                  **
**                                                                           **
**  VARIANT   : NA                                                           **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR      : Sandeep H                                                  **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the services related to Random number   **
**                generation                                                 **
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
#include "Cry_HsmRandomGenerate.h"

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
const Cry_HsmRandomGenerateConfigType   Cry_kHsmRandomGenerateConfig =
                              {.TimeOut = CRY_HSM_RANDOM_GENERATE_ALL_TIMEOUT};
const Cry_HsmTRNGConfigType   Cry_kHsmTRNGConfig =
                        {.TimeOut = CRY_HSM_TRUE_RANDOM_GENERATE_ALL_TIMEOUT};
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
static const Cry_HsmPrimitiveIdType Cry_PRMIDRndGen = CRY_HSM_RANDOM_GENERATE;
static const Cry_HsmPrimitiveIdType Cry_kPRMIDTrueRndGen =
                                                CRY_HSM_TRUE_RANDOM_GENERATE;
#endif
#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Variable Definitions                           **
******************************************************************************/

/******************************************************************************
**                     Global Structure Definition                           **
******************************************************************************/
/* [$Satisfies $CDS_CDRV 610] */
#define CRY_START_SEC_VAR_ALIGN16
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
static struct
{
  /* Srtucture element Block is updated by HSM. This must be the first element
   * in the structure to ensure proper alignment */
  HsmAes_Block Block;
  HostAddr     Param2;
  uint8        *Param1;
} Cry_HsmRandomGenerateData;
#define CRY_STOP_SEC_VAR_ALIGN16
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Function Definition                            **
******************************************************************************/

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmRandomGenerateFinishAction(void)            **
**                                                                           **
** Description     : This function is used to copy the generated random      **
**                  number into destination pointer                          **
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
void Cry_HsmRandomGenerateFinishAction(void)
{
  uint32 ResultLength; /* number of bytes to be copied */
  uint32 LoopVal;
  uint8 *DstPtr; /* Destination pointer */
  uint8 *SrcPtr; /* Source pointer */

  ResultLength = (uint32)Cry_HsmRandomGenerateData.Param2;
  DstPtr = Cry_HsmRandomGenerateData.Param1;
  SrcPtr = (uint8*)&Cry_HsmRandomGenerateData.Block;
  /* Copy from source to destination */
  for (LoopVal = 0U; LoopVal < ResultLength; LoopVal++)
  {
    *DstPtr = *SrcPtr;
    DstPtr = &DstPtr[1];
    SrcPtr = &SrcPtr[1];
  }
}

/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmRandomGenerateClearBuffer(void)             **
**                                                                           **
** Description     : This function is used to copy the generated random      **
**                  number into destination pointer                          **
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
void Cry_HsmRandomGenerateClearBuffer(void)
{
  uint32 ResultLength; /* number of bytes to be copied */
  uint32 LoopVal;
  uint8 *DstPtr; /* Destination pointer */

  ResultLength = (uint32)Cry_HsmRandomGenerateData.Param2;
  DstPtr = Cry_HsmRandomGenerateData.Param1;

  /* Copy from source to destination */
  for (LoopVal = 0U; LoopVal < ResultLength; LoopVal++)
  {
    *DstPtr = 0x00;
    DstPtr = &DstPtr[1];
  }
}
/******************************************************************************
** Traceability    :  [$Satisfies $CDS_CDRV 35]  [$Satisfies $CDS_CDRV 36]   **
**                    [$Satisfies $CDS_CDRV 37]                              **
**                    [$Satisfies $CDS_CDRV 39]  [$Satisfies $CDS_CDRV 590]  **
**                    [$Satisfies $CDS_CDRV 579]                             **
** Syntax          : Csm_ReturnType Cry_HsmRandomGenerate(                   **
**         const void *CfgPtr, uint8 *ResultPtr, uint32 ResultLength)        **
**                                                                           **
** Description     :  This function implements Cry_<Primitive> for           **
**                    Csm_ RandomGenerate service. It sends request to HSM to**
**                    generate a random number.                              **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_GENERATE                                **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr       -Pointer to configuration structure of     **
**                                 Cry_HsmRandomGenerateConfigType           **
**                   ResultLength -The amount of random bytes which should   **
**                                 be generated. Value range [1 to 16]       **
**                                                                           **
** Parameters (out): ResultPtr    -Pointer to the memory location which will **
**                                 hold the result of the random number      **
**                                 generation                                **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmRandomGenerate(
        const void *CfgPtr, uint8 *ResultPtr, uint32 ResultLength)
{
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
  static const Cry_HsmPrimitiveIdType Cry_PRMIDRndGen =
                                                     CRY_HSM_RANDOM_GENERATE;
#endif
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmRandomGenerateConfigType *RndCfgPtr;
  HsmCom_RandomGenerateParams *ParamPtr;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_RND_GENERATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
  * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_RND_GENERATE, ResultPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    INIT_VALIDATION(CRY_HSM_SID_RND_GENERATE, Cry_HsmInitStatus, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    if (ResultLength > CRY_HSM_BLOCK_SIZE)
    {
      DET_REPORT(CRY_HSM_SID_RND_GENERATE,
      CRY_HSM_E_PARAM_METHOD_INVALID, DetErr)
    }
  }
  if(DetErr == DEV_NO_ERROR)
  {
    if(Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT] !=
                                CRY_HSM_PRIM_FINISHED)
    {
      DET_REPORT(CRY_HSM_SID_RND_GENERATE,
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
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDRndGen);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      HandlePtr = Cry_lHsmGetActiveHandle(Cry_PRMIDRndGen);
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the
      * input config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the
      * input config pointer is of type void */
      RndCfgPtr = (const Cry_HsmRandomGenerateConfigType *) CfgPtr;
      /* Get the shared buffer address */
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
      aligned to the struture pointer containing the elements
      for Random Number Generation*/
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      ParamPtr->DestAddr = (HostAddr)&Cry_HsmRandomGenerateData.Block;

      Cry_HsmRandomGenerateData.Param1 = ResultPtr;
      Cry_HsmRandomGenerateData.Param2 = (HostAddr)ResultLength;
      /* Store Key page value (dummy for this service) and
      * AES mode (dummy for this service) in session data */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                   CRY_HSM_AES_MODE_DUMMY);

      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                   HSMCOM_CMD_RND_GEN,
                   CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(RndCfgPtr,0U));

      if(CSM_E_OK == RetVal)
      {
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING != STD_OFF)
        /* Copy the result if the service is executed successfully */
        Cry_HsmRandomGenerateFinishAction();
#endif
      }
      else
      {
        Cry_HsmRandomGenerateClearBuffer();
      }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
      /* Close the session */
      Cry_lHsmDeinitiateHandle(HandlePtr);
#else
      if(RetVal != CSM_E_OK)
      {
        /* Close the session only if the command acceptance is failed.
        * If the command is accepted successful, main function does
        * further processing and closes the session */
        Cry_lHsmDeinitiateHandle(HandlePtr);
      }
#endif
    }
  }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that FINISH service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDRndGen] = ASYNC_STATE_FINISH;
  /* Store the service return value.
  * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDRndGen] = RetVal;
#endif
  return RetVal;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 245] [$Satisfies $CDS_CDRV 579]   **
** Syntax          : Csm_ReturnType Cry_HsmTrueRandomGenerate(               **
**         const void *CfgPtr, uint8 *ResultPtr, uint32 ResultLength)        **
**                                                                           **
** Description     :  This function implements Cry_<Primitive> for           **
**                    Csm_ RandomGenerate service. It sends request to HSM to**
**                    generate a random number.                              **
**                                                                           **
** Service ID      : CRY_HSM_SID_TRUE_RND_GENERATE                           **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr       -Pointer to configuration structure of     **
**                                 Cry_HsmRandomGenerateConfigType           **
**                   ResultLength -The amount of random bytes which should   **
**                                 be generated. Value range [1 to 16]       **
**                                                                           **
** Parameters (out): ResultPtr    -Pointer to the memory location which will **
**                                 hold the result of the random number      **
**                                 generation                                **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                           **
**                   CSM_E_ENTROPY_EXHAUSTION - Request failed, entropy of   **
**                                random number generator is exhausted.      **
******************************************************************************/
Csm_ReturnType Cry_HsmTrueRandomGenerate(
        const void *CfgPtr, uint8 *ResultPtr, uint32 ResultLength)
{
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
  static const Cry_HsmPrimitiveIdType Cry_kPRMIDTrueRndGen =
                                CRY_HSM_TRUE_RANDOM_GENERATE;
#endif
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmTRNGConfigType *RndCfgPtr;
  HsmCom_RandomGenerateParams *ParamPtr;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_TRUE_RND_GENERATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
  * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_TRUE_RND_GENERATE, ResultPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    INIT_VALIDATION(CRY_HSM_SID_TRUE_RND_GENERATE,
                                  Cry_HsmInitStatus, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    if (ResultLength > CRY_HSM_BLOCK_SIZE)
    {
      DET_REPORT(CRY_HSM_SID_TRUE_RND_GENERATE,
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
    /* Initiate the handle for the session */
    RetVal = Cry_HsmPrimitiveStart(Cry_kPRMIDTrueRndGen);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      HandlePtr = Cry_lHsmGetActiveHandle(Cry_kPRMIDTrueRndGen);
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the
      * input config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the
      * input config pointer is of type void */
      RndCfgPtr = (const Cry_HsmTRNGConfigType *) CfgPtr;
      /* Get the shared buffer address */
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
      *aligned to the struture pointer containing the elements
      * for Random Number Generation */
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      ParamPtr->DestAddr = (HostAddr)ResultPtr;
      ParamPtr->RndLength = ResultLength;
      /* Store Key page value (dummy for this service) and
      * AES mode (dummy for this service) in session data */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                CRY_HSM_AES_MODE_DUMMY);
      /* send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                HSMCOM_CMD_TRNG_GEN,
                CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(RndCfgPtr,0U));
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
      /* close the session */
      Cry_lHsmDeinitiateHandle(HandlePtr);
#else
      if(RetVal != CSM_E_OK)
      {
        /* Close the session only if the command acceptance is failed.
        * If the command is accepted successful, main function does
        * further processing and closes the session */
        Cry_lHsmDeinitiateHandle(HandlePtr);
      }
#endif
    }
  }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that FINISH service is executed */
  Cry_PrimStatusAsync[Cry_kPRMIDTrueRndGen] = ASYNC_STATE_FINISH;
  /* Store the service return value.
  * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_kPRMIDTrueRndGen] = RetVal;
#endif
  return RetVal;
}
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 40] [$Satisfies $CDS_CDRV 579]    **
**                                                                           **
** Syntax          : void Cry_HsmRandomGenerateMainFunction(void)            **
**                                                                           **
** Description     :                                                         **
**                                                                           **
** [/cover]                                                                  **
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
void Cry_HsmRandomGenerateMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDRndGen,
                                    &Cry_HsmRandomGenerateFinishAction);
}

/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmTrueRandomGenerateMainFunction(void)        **
**                                                                           **
** Description     : This function implements Cry_<Primitive>MainFunction for**
**                   Csm_RandomGenerate service.                             **
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
void Cry_HsmTrueRandomGenerateMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_kPRMIDTrueRndGen, NULL_PTR);
}

#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_RANDOM_GENERATE_C*/
