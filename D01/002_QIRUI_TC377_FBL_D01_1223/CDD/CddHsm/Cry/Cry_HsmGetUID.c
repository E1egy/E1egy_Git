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
**  FILENAME    : Cry_HsmGetUID.c                                            **
**                                                                           **
**  VERSION     : 1.0.0                                                      **
**                                                                           **
**  DATE        : 2018-06-13                                                 **
**                                                                           **
**  VARIANT     : NA                                                         **
**                                                                           **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                              **
**                [Refer Release Package for Supported Device]               **
**  AUTHOR      : Prashant K                                                 **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the services related to Get ID          **
**                Information                                                **
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
#include "Cry_HsmGetUID.h"

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
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"


#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
static const Cry_HsmPrimitiveIdType Cry_PRMIDUid = CRY_HSM_UID;
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
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/* structure for storing the intermediate data during get UID */
static struct
{
  uint8 Uid[15];
  uint8 Sreg;
}Cry_GetUidSregBlockData;

#define CRY_STOP_SEC_VAR_ALIGN16
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"
/* structure for holding the UID pointer and Sreg pointer
 * to store Get UID data and status register from HSM */
static struct
{
  uint8 *UidPtr;
  uint8 *SregPtr;
}Cry_GetUidDataPtr;

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
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
** Syntax          : void Cry_HsmGetUIDFinishAction(void)                    **
**                                                                           **
** Description     : This function is used to copy the UID and Sreg          **
**                  into destination pointer                                 **
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
void Cry_HsmGetUIDFinishAction(void)
{
  uint8 *DstPtr; /* Destination pointer */
  uint8 *SrcPtr; /* Source pointer */
  uint8 LoopVal;
  DstPtr = Cry_GetUidDataPtr.UidPtr;
  SrcPtr = (uint8*)&Cry_GetUidSregBlockData.Uid;
  /* Copy Uid to destination */
  for (LoopVal = CRY_HSM_ZERO ; LoopVal < CRY_UID_LEN; LoopVal++)
  {
    *DstPtr = *SrcPtr;
    DstPtr = &DstPtr[1];
    SrcPtr = &SrcPtr[1];
  }

  *Cry_GetUidDataPtr.SregPtr = Cry_GetUidSregBlockData.Sreg;
}

/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmGetUIDClearBuffer(void)                     **
**                                                                           **
** Description     : This function is used to Clear the Destination buffer   **
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
void Cry_HsmGetUIDClearBuffer(void)
{
  uint8 *DstPtr; /* Destination pointer */
  uint8 LoopVal;
  DstPtr = Cry_GetUidDataPtr.UidPtr;
  /* Copy Uid to destination */
  for (LoopVal = CRY_HSM_ZERO ; LoopVal < CRY_UID_LEN; LoopVal++)
  {
    *DstPtr = 0x00;
    DstPtr = &DstPtr[1];
  }
  *Cry_GetUidDataPtr.SregPtr = 0x00;
}
/******************************************************************************
** Traceability    :  [$Satisfies $CDS_CDRV 612]  [$Satisfies $CDS_CDRV 613] **
**                    [$Satisfies $CDS_CDRV 614]  [$Satisfies $CDS_CDRV 615] **
**                    [$Satisfies $CDS_CDRV 616]  [$Satisfies $CDS_CDRV 617] **
**                    [$Satisfies $CDS_CDRV 579]                             **
** Syntax          : Cry_HsmGetSheUID(const uint8 *Challenge,                **
**                   uint8* She_UidPtr, uint8 *She_SregPtr, uint8 *MacPtr)   **
**                                                                           **
** Description     :  The function returns the identity (UID) and the value  **
**                    of the status register protected by a MAC over         **
**                    a challenge and the data.                              **
**                                                                           **
** Service ID      : CRY_HSM_SID_GETUID                                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : Challenge    - Pointer to Challenge for MAC(16 bytes)   **
**                                                                           **
** Parameters (out): She_UidPtr   - Pointer to the SHE UID (15 bytes)        **
**                   She_SregPtr  - Pointer to the value of the SHE          **
**                                  status register                          **
**                   MacPtr       - Pointer to the MAC value over            **
**                                  the challenge, id and sreg.              **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
Csm_ReturnType Cry_HsmGetSheUID(const uint8 *Challenge, uint8* She_UidPtr,
                                uint8 *She_SregPtr, uint8 *MacPtr)
{

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
  static const Cry_HsmPrimitiveIdType Cry_PRMIDUid = CRY_HSM_UID;
#endif

  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  HsmCom_GetUidParams *ParamPtr;
  uint32 Timeout;

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
  boolean DetErr;

  DetErr = DEV_NO_ERROR;
  PTR_VALIDATION(CRY_HSM_SID_GETUID, Challenge, DetErr)
  /* Check the next DET only if the DET error doesn't occur.
  * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_GETUID, She_UidPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_GETUID, She_SregPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    PTR_VALIDATION(CRY_HSM_SID_GETUID, MacPtr, DetErr)
  }
  if(DetErr == DEV_NO_ERROR)
  {
    INIT_VALIDATION(CRY_HSM_SID_GETUID, Cry_HsmInitStatus, DetErr)
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
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDUid);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      HandlePtr = Cry_lHsmGetActiveHandle(Cry_PRMIDUid);
      /* Get the shared buffer address */
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
       * aligned to the struture pointer containing the elements
       * for GetUID */
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      ParamPtr->ChalleangeAddr =(HostAddr)Challenge;
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      ParamPtr->UidSregAddr = (HostAddr)&Cry_GetUidSregBlockData.Uid;
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      ParamPtr->MacAddr = (HostAddr)MacPtr;
      /* Store Key page value (dummy for this service) and
      * AES mode (dummy for this service) in session data */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                   CRY_HSM_AES_MODE_DUMMY);
      Cry_GetUidDataPtr.UidPtr = She_UidPtr;
      Cry_GetUidDataPtr.SregPtr = She_SregPtr;
      Timeout = CRY_HSM_GET_UID_TIMEOUT;

      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,HSMCOM_CMD_GET_ID,
                                                            Timeout);

      if(CSM_E_OK == RetVal)
      {
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING != STD_OFF)
        /* Copy the result if the service is executed successfully */
        Cry_HsmGetUIDFinishAction();
#endif
      }
      else
      {
        Cry_HsmGetUIDClearBuffer();
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
  Cry_PrimStatusAsync[Cry_PRMIDUid] = ASYNC_STATE_FINISH;
  /* Store the service return value.
  * To be used by the main function to do further processing */
  Cry_PrimErr[Cry_PRMIDUid] = RetVal;
#endif
  return RetVal;
}

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 618] [$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          : void Cry_HsmGetUIDMainFunction(void)                    **
**                                                                           **
** Description     : In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_GET_ID command and  **
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
void Cry_HsmGetUIDMainFunction(void)
{
  Cry_HsmPrimitiveMainFunction(Cry_PRMIDUid,
                                    &Cry_HsmGetUIDFinishAction);
}
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_RANDOM_GENERATE_C*/
