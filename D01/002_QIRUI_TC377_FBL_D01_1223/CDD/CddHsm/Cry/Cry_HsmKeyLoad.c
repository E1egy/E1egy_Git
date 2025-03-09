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
**  FILENAME    : Cry_HsmKeyLoad.c                                            **
**                                                                            **
**  VERSION     : 4.0.0                                                       **
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
**  DESCRIPTION : This file contains the services related to KEY load         **
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
#include "Cry_HsmKeyLoad.h"

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
#include "Cry_MemMap.h"

const Cry_HsmKeyLoadConfigType          Cry_kHsmKeyLoadConfigPage0  =
                            {.KeyPage = CRY_HSM_KEY_PAGE_0,
                            .TimeOut = CRY_HSM_KEY_LOAD_ALL_TIMEOUT};

const Cry_HsmKeyLoadConfigType          Cry_kHsmKeyLoadConfigPage1  =
                            {.KeyPage = CRY_HSM_KEY_PAGE_1,
                            .TimeOut = CRY_HSM_KEY_LOAD_ALL_TIMEOUT};

const Cry_HsmKeyLoadConfigType          Cry_kHsmKeyLoadConfigRamKey =
                            {.KeyPage = CRY_HSM_KEY_PAGE_0,
                            .TimeOut = CRY_HSM_KEY_LOAD_RAMKEY_ALL_TIMEOUT};
#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

static Cry_HsmPrimitiveIdType Cry_PRMIDKeyLoad = CRY_HSM_KEY_LOAD;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
#else
#define CRY_START_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

static const Cry_HsmPrimitiveIdType Cry_PRMIDKeyLoad = CRY_HSM_KEY_LOAD;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
#endif
/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/

/******************************************************************************
**                     Global Structure Definition                           **
******************************************************************************/
/* [$Satisfies $CDS_CDRV 610] */
#define CRY_START_SEC_VAR_ALIGN16
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
static struct {
    HsmAes_Block M4[2];
    HsmAes_Block M5;
} Cry_HsmKeyLoadResult;
#define CRY_STOP_SEC_VAR_ALIGN16
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
/*******************************************************************************
**                     Global Function Definition                             **
*******************************************************************************/

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 183] [$Satisfies $CDS_CDRV 184]    **
**                   [$Satisfies $CDS_CDRV 185] [$Satisfies $CDS_CDRV 186]    **
**                   [$Satisfies $CDS_CDRV 187] [$Satisfies $CDS_CDRV 293]    **
**                   [$Satisfies $CDS_CDRV 294] [$Satisfies $CDS_CDRV 295]    **
**                   [$Satisfies $CDS_CDRV 579] [$Satisfies $CDS_CDRV 608]    **
**                   [$Satisfies $CDS_CDRV 609]                               **
** Syntax          : Csm_ReturnType Cry_HsmKeyLoadStart(const void *CfgPtr)   **
**                                                                            **
** Description     : This function implements Cry_HsmKeyLoadStart for         **
**                   Csm_KeyExtractStart service. It reserves and             **
**                   initializes resources for Csm_SymKeyExtract service      **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_START                               **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmKeyLoadConfigType                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType Cry_HsmKeyLoadStart(const void *CfgPtr)
{
  Csm_ReturnType RetVal;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
#endif

  UNUSED_POINTER (CfgPtr)

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  INIT_VALIDATION(CRY_HSM_SID_KEY_LOAD_START, Cry_HsmInitStatus, DetErr)
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
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDKeyLoad);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the indication that START service is successful.
      * To be used by UPDATE and FINISH services to check the
      * DET "CSM_E_SERVICE_NOT_STARTED" */
      Cry_PrimStatus[Cry_PRMIDKeyLoad] = CRY_HSM_PRIM_STARTED;
#endif
    }
  }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that START service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDKeyLoad] = ASYNC_STATE_START;
  /* Store the service return value.
  * To be used by the main function to report the status to upper layer */
  Cry_PrimErr[Cry_PRMIDKeyLoad] = RetVal;
#endif
  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 195] [$Satisfies $CDS_CDRV 196]    **
**                   [$Satisfies $CDS_CDRV 197] [$Satisfies $CDS_CDRV 198]    **
**                   [$Satisfies $CDS_CDRV 199] [$Satisfies $CDS_CDRV 220]    **
**                   [$Satisfies $CDS_CDRV 221] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType Cry_HsmKeyLoadFinish(                     **
**                           const void *CfgPtr, Csm_SymKeyType *KeyPtr)      **
**                                                                            **
** Description     :This function implements Cry_HsmKeyLoadFinish for         **
**                  Csm_KeyExtractFinish service. It releases resources used  **
**                  by Csm_SymKeyExtract service.This function copies M4 and  **
**                  M5 data to KeyPtr->data parameter. Cry_HsmKeyLoadFinish   **
**                  function then invokes the function that closes the HSM    **
**                  communication session                                     **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_FINISH                              **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmKeyLoadConfigType                        **
**                   KeyPtr - Pointer to key structure of Csm_SymKeyType.     **
**                            This pointer is used for storing M4 and M5      **
**                            data. Upon successful operation:                **
**                            1. KeyPtr->length will be set to 48 (bytes)     **
**                            2. KeyPtr->data will contain M4 and M5          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM         **
**                               communication is busy                        **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType Cry_HsmKeyLoadFinish(
        const void *CfgPtr, Csm_SymKeyType *KeyPtr)
{
  Csm_ReturnType RetVal;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
#endif

  UNUSED_POINTER (CfgPtr)

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_KEY_LOAD_FINISH, KeyPtr, DetErr)

  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_KEY_LOAD_FINISH,
                     Cry_PrimStatus[Cry_PRMIDKeyLoad], DetErr)
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
    /* Check the HSM status. Session is not closed if HSM is BUSY */
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDKeyLoad);
    if(RetVal == CSM_E_OK)
    {
      /* Finish the primitive by closing the session */
      RetVal = Cry_HsmPrimitiveFinish(Cry_PRMIDKeyLoad);
      if(RetVal == CSM_E_OK)
      {
        /*IFX_MISRA_RULE_01_03_STATUS=Typecasting is required to
        *convert into uint32 pointer */
        /*IFX_MISRA_RULE_11_03_STATUS=Typecasting is required to
        *convert into uint32 pointer*/
        /*IFX_MISRA_RULE_11_03_STATUS=Typecasting is required to
        *convert into uint32 pointer*/
        HsmCom_CopyArray((uint32*)KeyPtr->data,
                         (uint32*)&Cry_HsmKeyLoadResult,
                         (CRY_HSM_KEY_M4M5_SIZE/sizeof(uint32)));
        KeyPtr->length = CRY_HSM_KEY_M4M5_SIZE;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
        /* Set the primitive status to FINISHED.
        * Status will be changed again if the START
        * is executed successfully */
        Cry_PrimStatus[Cry_PRMIDKeyLoad] = CRY_HSM_PRIM_FINISHED;
#endif
      }
    }
  }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that FINISH service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDKeyLoad] = ASYNC_STATE_FINISH;
  /* Store the service return value.
  * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDKeyLoad] = RetVal;
#endif

  return RetVal;
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"
#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 189]                               **
**                   [$Satisfies $CDS_CDRV 190] [$Satisfies $CDS_CDRV 191]    **
**                   [$Satisfies $CDS_CDRV 192] [$Satisfies $CDS_CDRV 193]    **
**                   [$Satisfies $CDS_CDRV 194] [$Satisfies $CDS_CDRV 579]    **
**                   [$Satisfies $CDS_CDRV 601]                               **
** Syntax          : Csm_ReturnType  Cry_HsmKeyLoadUpdate(                    **
**                                                  const void *CfgPtr,       **
**                                                  const uint8 *DataPtr,     **
**                                                  uint32 DataLength)        **
**                                                                            **
** Description     : This function implements Cry_HsmKeyLoadUpdate for        **
**                   Csm_KeyExtractUpdate service. It sends request to HSM    **
**                   to load a protected key into one of the key slots of     **
**                   the HSM SHE                                              **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_UPDATE                              **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr     -  Pointer to configuration structure of      **
**                                 Cry_HsmKeyLoadConfigType                   **
**                   DataPtr    -  Pointer to data block, which represents the**
**                                 protected key that will be loaded into the **
**                                 volatile or non-volatile key slot of the   **
**                                 HSM SHE. It contains M1, M2 and M3 data,   **
**                                 as per SHE specification. The M1, M2 and   **
**                                 M3 are stored sequentially                 **
**                    DataLength - The length of M1, M2 and M3 in bytes.      **
**                                 This value shall be 64                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType  Cry_HsmKeyLoadUpdate(
        const void *CfgPtr, const uint8 *DataPtr, uint32 DataLength)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  uint32 DataAddr;
#ifdef CONTROLLER_TC23x
  uint32 TrapDisStat;
#endif
  Cry_HsmKeyPageType KeyPageVal;
  HsmCom_LoadKeyParams *ParamPtr; /*Pointer to the structure that defines
                                    the parameters to be stored in shared
                                    buffer */

  const Cry_HsmKeyLoadConfigType* LoadCfgPtr;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_KEY_LOAD_UPDATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_KEY_LOAD_UPDATE, DataPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_KEY_LOAD_UPDATE,
                     Cry_PrimStatus[Cry_PRMIDKeyLoad], DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    if (DataLength != CRY_HSM_KEY_EXTRACT_SIZE)
    {
      DET_REPORT(CRY_HSM_SID_KEY_LOAD_UPDATE,
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
#else
  UNUSED_PARAMETER(DataLength);
#endif
  {
    /* Check the HSM status. COmmand is sent only if the
    * HSM is not busy */
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDKeyLoad);
    if(RetVal == CSM_E_OK)
    {
      HandlePtr = &(Cry_HsmData[Cry_PRMIDKeyLoad]);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle
       *data sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
       *data sharing between Host and HSM through shared buffer*/
      DataAddr = (uint32)DataPtr;
      /* Get the shared buffer address */
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
      *aligned to the structure pointer containing the elements
      *for MacGeneration */
       ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
       /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the
       * input config pointer is of type void*/
       /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the
       * input config pointer is of type void */
       LoadCfgPtr = (const Cry_HsmKeyLoadConfigType*) CfgPtr;
       KeyPageVal = LoadCfgPtr->KeyPage;
       /* Update the prameters in shared buffer */
       ParamPtr->M1Addr = (HostAddr)(DataAddr);
       ParamPtr->M2Addr = (HostAddr)(DataAddr + CRY_HSM_KEY_M2OFFSET);
       ParamPtr->M3Addr = (HostAddr)(DataAddr + CRY_HSM_KEY_M3OFFSET);
       /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
        *sharing between Host and HSM through shared buffer*/
       /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
        *sharing between Host and HSM through shared buffer*/
       ParamPtr->M4Addr = (HostAddr)Cry_HsmKeyLoadResult.M4;
       /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
        *sharing between Host and HSM through shared buffer*/
       /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
        *sharing between Host and HSM through shared buffer*/
       ParamPtr->M5Addr = (HostAddr)&Cry_HsmKeyLoadResult.M5;
       /* Store Key page value (as key address) in session data
       * AES mode parameter is dummy for this primitive */
       /*IFX_MISRA_RULE_10_03_STATUS=Type casting to HsmCom_KeyAddr
       is required as keyPage value is required to be passed to
       HSM in HT2HSMF register*/
      /*IFX_MISRA_RULE_10_05_STATUS=Type casting to HsmCom_KeyAddr
      is required as keyPage value is required to be passed to
      HSM in HT2HSMF register*/
      HsmCom_SetPackedParams(HandlePtr->Session,
                  (HsmCom_KeyAddr)KeyPageVal, CRY_HSM_AES_MODE_DUMMY);
#ifdef CONTROLLER_TC23x
      TrapDisStat = HsmMcal_GetTrapDisableStatus();
      /* PF0 traps must be disabled
       * because of ECC errors that may occur during
       * FEE/FLS initialization
       * or write operations
       */
      HsmMcal_DisableEccErrors();
#endif

      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
               HSMCOM_CMD_KEY_LOAD,
               CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(LoadCfgPtr, 0U));

#ifdef CONTROLLER_TC23x
      HsmMcal_EnableEccErrors(TrapDisStat);
#endif

    }
  }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    /* Set the indication to main function that UPDATE service is executed */
    Cry_PrimStatusAsync[Cry_PRMIDKeyLoad] = ASYNC_STATE_UPDATE;
    /* Store the service return value.
     * To be used by the main function to do further processing */
    Cry_PrimErr[Cry_PRMIDKeyLoad] = RetVal;
#endif

  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 222][$Satisfies $CDS_CDRV 579]     **
**                                                                            **
** Syntax          : void Cry_HsmKeyLoadMainFunction(void)                    **
**                                                                            **
** Description     : This function does not exist in case of synchronous      **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.         **
**                   In case of asynchronous operation, this function checks  **
**                   the command response for HSMCOM_CMD_KEY_LOAD command     **
**                   and closes the session                                   **
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
void Cry_HsmKeyLoadMainFunction(void)
{

  Cry_HsmPrimitiveMainFunction(Cry_PRMIDKeyLoad, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/*End of CRY_HSM_KEY_LOAD_C*/
