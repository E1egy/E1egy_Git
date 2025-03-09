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
**  FILENAME    : Cry_HsmSecureBoot.c                                        **
**                                                                           **
**  VERSION     : 1.0.0                                                      **
**                                                                           **
**  DATE        : 2016-12-08                                                 **
**                                                                           **
**  VARIANT     : NA                                                         **
**                                                                           **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                              **
**                [Refer Release Package for Supported Device]               **
**  AUTHOR      : Srinivasa Chakravarthi K                                   **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the services related to Secure Boot     **
**                Functionality                                              **
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
#include "Cry_HsmSecureBoot.h"
#if (CRY_HSM_SECURE_BOOT == STD_ON)
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
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
static const Cry_HsmPrimitiveIdType Cry_PRMIDBootFailure =
                                            CRY_HSM_BOOT_FAILURE;
static const Cry_HsmPrimitiveIdType Cry_PRMIDBootOk =
                                              CRY_HSM_BOOT_OK;
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

/******************************************************************************
**                     Global Function Definition                            **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 718] [$Satisfies $CDS_CDRV 719]   **
**                   [$Satisfies $CDS_CDRV 720] [$Satisfies $CDS_CDRV 721]   **
**                   [$Satisfies $CDS_CDRV 722] [$Satisfies $CDS_CDRV 723]   **
**                   [$Satisfies $CDS_CDRV 579]                              **
**                                                                           **
** Syntax          :  Cry_HsmSheBootFailure(void)                            **
**                                                                           **
** Description     : Command CMD_BOOT_FAILURE is sent to HSM. This function  **
**                   imposes the same sanctions as if secure boot would      **
**                   detect a failure.                                       **
**                                                                           **
** Service ID      : CRY_HSM_SID_BOOT_FAILURE                                **
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
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmSheBootFailure(void)
{
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
  static const Cry_HsmPrimitiveIdType Cry_PRMIDBootFailure =
                                              CRY_HSM_BOOT_FAILURE;
  #endif
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  uint32 Timeout;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  DetErr = DEV_NO_ERROR;
  INIT_VALIDATION(CRY_HSM_SID_BOOT_FAILURE, Cry_HsmInitStatus, DetErr)
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
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDBootFailure);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      HandlePtr = Cry_lHsmGetActiveHandle(Cry_PRMIDBootFailure);
      /* Store Key page value (dummy for this service) and
      * AES mode (dummy for this service) in session data */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                   CRY_HSM_AES_MODE_DUMMY);
      Timeout = CRY_HSM_BOOT_FAILURE_TIMEOUT;

      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,HSMCOM_CMD_BOOT_FAILURE,
                                                           Timeout);

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
  Cry_PrimStatusAsync[Cry_PRMIDBootFailure] = ASYNC_STATE_FINISH;
  /* Store the service return value.
  * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDBootFailure] = RetVal;
  #endif
  return RetVal;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 724] [$Satisfies $CDS_CDRV 725]   **
**                   [$Satisfies $CDS_CDRV 726] [$Satisfies $CDS_CDRV 727]   **
**                   [$Satisfies $CDS_CDRV 728] [$Satisfies $CDS_CDRV 729]   **
**                   [$Satisfies $CDS_CDRV 579]                              **
**                                                                           **
** Syntax          : Cry_HsmSheBootOk(void)                                  **
**                                                                           **
** Description     : Command CMD_BOOT_OK is sent to HSM. This function is    **
**                   used to mark successful boot verification               **
**                                                                           **
** Service ID      : CRY_HSM_SID_BOOT_OK                                     **
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
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmSheBootOk(void)
{
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
  static const Cry_HsmPrimitiveIdType Cry_PRMIDBootOk = CRY_HSM_BOOT_OK;
  #endif
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  uint32 Timeout;
  #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;
  DetErr = DEV_NO_ERROR;
  INIT_VALIDATION(CRY_HSM_SID_BOOT_OK, Cry_HsmInitStatus, DetErr)
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
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDBootOk);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      HandlePtr = Cry_lHsmGetActiveHandle(Cry_PRMIDBootOk);
      /* Store Key page value (dummy for this service) and
      * AES mode (dummy for this service) in session data */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                   CRY_HSM_AES_MODE_DUMMY);
      Timeout = CRY_HSM_BOOT_OK_TIMEOUT;

      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,HSMCOM_CMD_BOOT_OK,
                                                           Timeout);

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
  Cry_PrimStatusAsync[Cry_PRMIDBootOk] = ASYNC_STATE_FINISH;
  /* Store the service return value.
  * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDBootOk] = RetVal;
  #endif
  return RetVal;
}
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 730] [$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          : void Cry_HsmBootFailureMainFunction(void)               **
**                                                                           **
** Description     : In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_BOOT_FAILURE command**
**                   and closes the session                                  **
**                                                                           **
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
void Cry_HsmBootFailureMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDBootFailure, NULL_PTR);
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 731] [$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          : void Cry_HsmBootOkMainFunction(void)                    **
**                                                                           **
** Description     : In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_BOOT_OK command and **
**                   closes the session                                      **
**                                                                           **
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
void Cry_HsmBootOkMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDBootOk, NULL_PTR);
}
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_SECURE_BOOT*/
#endif
