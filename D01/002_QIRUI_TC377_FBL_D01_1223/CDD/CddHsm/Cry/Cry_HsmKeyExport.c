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
**  FILENAME    : Cry_HsmKeyExport.c                                          **
**                                                                            **
**  VERSION     : 3.0.0                                                       **
**                                                                            **
**  DATE        : 2016-07-11                                                  **
**                                                                            **
**  VARIANT     : NA                                                          **
**                                                                            **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                               **
**                [Refer Release Package for Supported Device]                **
**  AUTHOR      : Trivikram G                                                 **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains the services related to KEY export       **
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
#include "Cry_HsmKeyExport.h"

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

const Cry_HsmKeyExportConfigType        Cry_kHsmKeyExportConfig =
        {.TimeOut = CRY_HSM_KEY_EXPORT_ALL_TIMEOUT};

static const Cry_HsmPrimitiveIdType Cry_PRMIDKeyWrap = CRY_HSM_KEY_WRAP;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
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
static struct
{
    HsmAes_Block M4[2];
    HsmAes_Block M5;
} Cry_HsmKeyExport;
#define CRY_STOP_SEC_VAR_ALIGN16
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Function Definition                            **
******************************************************************************/

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 223] [$Satisfies $CDS_CDRV 224]    **
**                   [$Satisfies $CDS_CDRV 225] [$Satisfies $CDS_CDRV 226]    **
**                   [$Satisfies $CDS_CDRV 227] [$Satisfies $CDS_CDRV 228]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType Cry_HsmKeyExportStart(                    **
**                                      const void *CfgPtr,                   **
**                                      const Csm_SymKeyType *KeyPtr,         **
**                                      const Csm_SymKeyType *WrappingKeyPtr) **
**                                                                            **
** Description     :This function implements Cry_HsmKeyExportStart for        **
**                  Csm_KeyWrapStart service. It reserves and initializes     **
**                  resources for Csm_SymKeyWrap service                      **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_EXPORT_START                             **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr         - Pointer to configuration structure of   **
**                                    Cry_HsmKeyExportConfigType              **
**                   KeyPtr         - KeyPtr parameter is ignored             **
**                   WrappingKeyPtr - WrappingKeyPtr parameter is ignored     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
**                                                                            **
*******************************************************************************/
Csm_ReturnType Cry_HsmKeyExportStart(
                                      const void *CfgPtr,
                                      const Csm_SymKeyType *KeyPtr,
                                      const Csm_SymKeyType *WrappingKeyPtr)
{
  Csm_ReturnType RetVal;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  #endif

  UNUSED_POINTER (CfgPtr)
  UNUSED_POINTER (KeyPtr)
  UNUSED_POINTER (WrappingKeyPtr)

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  INIT_VALIDATION(CRY_HSM_SID_KEY_EXPORT_START, Cry_HsmInitStatus, DetErr)
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
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDKeyWrap);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      /* Set the indication that START service is successful. To be used by
       * UPDATE and FINISH services to check the DET
       * "CSM_E_SERVICE_NOT_STARTED" */
      Cry_PrimStatus[Cry_PRMIDKeyWrap] = CRY_HSM_PRIM_STARTED;
      #endif
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that START service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDKeyWrap] = ASYNC_STATE_START;
  /* Store the service return value. To be used by the main function to report
   * the status to upper layer */
  Cry_PrimErr[Cry_PRMIDKeyWrap] = RetVal;
  #endif

  /* Following code is used to avoid the misra warning 8.9
   * If the global variable Cry_HsmKeyExport is used only in
   * Cry_HsmKeyExportUpdate
   * then misra 8.9 is generated suggesting to declare the variable local to
   * Cry_HsmKeyExportUpdate */
  Cry_HsmKeyExport.M4[0].Data[0] = 0;
  Cry_HsmKeyExport.M5.Data[0] = 0;

  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 229] [$Satisfies $CDS_CDRV 230]    **
**                   [$Satisfies $CDS_CDRV 231] [$Satisfies $CDS_CDRV 232]    **
**                   [$Satisfies $CDS_CDRV 233] [$Satisfies $CDS_CDRV 234]    **
**                   [$Satisfies $CDS_CDRV 235] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType  Cry_HsmKeyExportUpdate(                  **
**                                        const void *CfgPtr,                 **
**                                        uint8 *DataPtr,                     **
**                                        uint32 *DataLengthPtr)              **
**                                                                            **
** Description     : This function implements CryHsmKeyExportUpdate for       **
**                   Csm_KeyWrapUpdate service. It sends request to HSM to    **
**                   export protected HSMCOM_RAM_KEY                          **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_EXPORT_UPDATE                            **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr        - Pointer to configuration structure of    **
**                                   Cry_HsmKeyExportConfigType               **
**                                                                            **
** Parameters (out): DataPtr       - Pointer to the memory location which     **
**                                   will hold the protected RAM_KEY of the   **
**                                   HSM SHE. It will contain M1, M2, M3, M4, **
**                                   M5 data as per SHE specification. The    **
**                                   M1, M2, M3, M4 and M5 data are stored    **
**                                   sequentially                             **
**                   DataLengthPtr - Pointer to the memory location in which  **
**                                   the length information (in bytes) is     **
**                                   stored. When the request has finished    **
**                                   the actual length of the protected key,  **
**                                   exported by this function, shall be      **
**                                   stored                                   **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
**                                                                            **
*******************************************************************************/
Csm_ReturnType  Cry_HsmKeyExportUpdate(
        const void *CfgPtr, uint8 *DataPtr, uint32 *DataLengthPtr)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  uint32 DataAddr;
  HsmCom_ExportKeyParams *ParamPtr; /*Pointer to the structure that defines
                                  the parameters to be stored in shared
                                  buffer */
  const Cry_HsmKeyExportConfigType* ExpCfgPtr;



#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_KEY_EXPORT_UPDATE, CfgPtr, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
   * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_KEY_EXPORT_UPDATE, DataPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_KEY_EXPORT_UPDATE, DataLengthPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    START_VALIDATION(CRY_HSM_SID_KEY_EXPORT_UPDATE,
                     Cry_PrimStatus[Cry_PRMIDKeyWrap], DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    if (*DataLengthPtr < CRY_HSM_KEY_EXTRACT_SIZE)
    {
      /* LIMITATION: M1, M2, M3 shall be minimum 64 bytes total */
      DET_REPORT(CRY_HSM_SID_KEY_EXPORT_UPDATE,
                 CRY_HSM_E_PARAM_METHOD_INVALID, DetErr)
    }
  }
  /* If any DET error occurs, return CSM_E_NOT_OK. Further processing is not
      required */
  if(DetErr != DEV_NO_ERROR)
  {
    RetVal = CSM_E_NOT_OK;
  }
  else
  #endif
  {
    /* Check the HSM status. COmmand is sent only if the HSM is not busy */
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDKeyWrap);
    if(RetVal == CSM_E_OK)
    {
      HandlePtr = &(Cry_HsmData[Cry_PRMIDKeyWrap]);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
       * sharing between Host and HSM through shared buffer*/
      DataAddr = (uint32)DataPtr;
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the input
       * config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the input
       * config pointer is of type void */
      ExpCfgPtr = (const Cry_HsmKeyExportConfigType*) CfgPtr;
      /* Get the shared buffer address */
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be aligned to
       * the struture pointer containing the elements for Key Export */
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);

      /* Update the prameters in shared buffer */
      ParamPtr->M1Addr = (HostAddr)(DataAddr);
      ParamPtr->M2Addr = (HostAddr)(DataAddr + CRY_HSM_KEY_M2OFFSET);
      ParamPtr->M3Addr = (HostAddr)(DataAddr + CRY_HSM_KEY_M3OFFSET);

      if (*DataLengthPtr < (CRY_HSM_KEY_EXTRACT_SIZE + CRY_HSM_KEY_M4M5_SIZE))
      {
        /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        ParamPtr->M4Addr = (HostAddr)Cry_HsmKeyExport.M4;
        /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle data
         * sharing between Host and HSM through shared buffer*/
        ParamPtr->M5Addr = (HostAddr)&Cry_HsmKeyExport.M5;
        *DataLengthPtr = CRY_HSM_KEY_EXTRACT_SIZE;
      }
      else
      {
        ParamPtr->M4Addr = (HostAddr)DataAddr + CRY_HSM_KEY_M4OFFSET;
        ParamPtr->M5Addr = (HostAddr)DataAddr + CRY_HSM_KEY_M5OFFSET;
        *DataLengthPtr = CRY_HSM_KEY_EXTRACT_SIZE + CRY_HSM_KEY_M4M5_SIZE;
      }
      /* Store KEY and MODE in session data KEY and MODE are dummy for this
       * primitive */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                             CRY_HSM_AES_MODE_DUMMY);

      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                              HSMCOM_CMD_KEY_EXPORT,
                              CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(ExpCfgPtr,0U));
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that UPDATE service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDKeyWrap] = ASYNC_STATE_UPDATE;
  /* Store the service return value. To be used by the main function to do
   * further processing */
  Cry_PrimErr[Cry_PRMIDKeyWrap] = RetVal;
  #endif

  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 236] [$Satisfies $CDS_CDRV 237]    **
**                   [$Satisfies $CDS_CDRV 238] [$Satisfies $CDS_CDRV 239]    **
**                   [$Satisfies $CDS_CDRV 240] [$Satisfies $CDS_CDRV 241]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType Cry_HsmKeyExportFinish                    **
**                                                   (const void *CfgPtr)     **
**                                                                            **
** Description     : This function implements Cry_HsmKeyExportFinish for      **
**                   Csm_KeyWrapFinish service. It releases resources used by **
**                   Csm_SymKeyWrap service.This function invokes function    **
**                   that closes the HSM communication session                **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_EXPORT_FINISH                            **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmKeyExportConfigType                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM         **
**                               communication is busy                        **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
Csm_ReturnType Cry_HsmKeyExportFinish(const void *CfgPtr)
{
  Csm_ReturnType RetVal;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  #endif

  UNUSED_POINTER (CfgPtr)

  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  DetErr = DEV_NO_ERROR;
  START_VALIDATION(CRY_HSM_SID_KEY_EXPORT_FINISH,
                   Cry_PrimStatus[Cry_PRMIDKeyWrap], DetErr)
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
    RetVal = Cry_HsmStatusCheck(Cry_PRMIDKeyWrap);
    if(RetVal == CSM_E_OK)
    {
      /* Finish the primitive by closing the session */
      RetVal = Cry_HsmPrimitiveFinish(Cry_PRMIDKeyWrap);
      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      if(RetVal == CSM_E_OK)
      {
        /* Set the primitive status to FINISHED. Status will be changed again
         * if the START is executed successfully */
        Cry_PrimStatus[Cry_PRMIDKeyWrap] = CRY_HSM_PRIM_FINISHED;
      }
      #endif
    }
  }

  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  /* Set the indication to main function that FINISH service is executed */
  Cry_PrimStatusAsync[Cry_PRMIDKeyWrap] = ASYNC_STATE_FINISH;
  /* Store the service return value. To be used by the main function to do
   * further processing */
  Cry_PrimErr[Cry_PRMIDKeyWrap] = RetVal;
  #endif

  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 242] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : void Cry_HsmKeyExportMainFunction(void)                  **
**                                                                            **
** Description     : This function doesnt exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON. In case **
**                   of asynchronous operation, this function checks the      **
**                   command response for HSMCOM_CMD_KEY_EXPORT command and   **
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
void Cry_HsmKeyExportMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDKeyWrap, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
