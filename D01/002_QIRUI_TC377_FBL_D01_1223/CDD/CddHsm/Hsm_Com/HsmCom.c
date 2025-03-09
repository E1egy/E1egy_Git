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
**  FILENAME    : HsmCom.c                                                    **
**                                                                            **
**  VERSION     : 5.0.0                                                       **
**                                                                            **
**  DATE        : 2017-06-27                                                  **
**                                                                            **
**  VARIANT     :                                                             **
**                                                                            **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                               **
**                [Refer Release Package for Supported Device]                **
**  AUTHOR      : Sandeep H                                                   **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains functionality of HsmCom module           **
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

#include "HsmCom_Priv.h"
#include "HsmCom.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
** Private Constant Definitions (Local preprocessor # define constants)       **
*******************************************************************************/
#define HSMCOM_CMDSRCCLEAR 0x00U
#define HSMCOM_CMDCANCELSRCCLEAR 0x00U
#define HSMCOM_INITSHAREDBUFFER_WRITEVAL 0x5A5A5A5AU
#define HSMCOM_INITSHAREDBUFFER_READVAL 0x00000000U
#define HSMCOM_DATAARRAYSIZE 4U

/*******************************************************************************
** Private Variable Definitions (Local preprocessor # define macros)          **
*******************************************************************************/

/*******************************************************************************
**                      Local Type Declarations                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant variable Definitions                  **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/* [$Satisfies $CDS_CDRV 610] */
#define CRY_START_SEC_VAR_ALIGN16
#include "Cry_MemMap.h"

/* HsmCom_DataBuffers is the shared buffer between Host and HSM */
HsmCom_Buffers HsmCom_DataBuffers;

#define CRY_STOP_SEC_VAR_ALIGN16
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

/* HsmCom_Data contains the sessions */
HsmCom HsmCom_Data;

/* Variable to indicate the timeout. Will be updated in callback */
boolean HsmCom_CallbackNotify;

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/*Variable to store the command code for Async mode
  This variable will be referenced in main function  */
HsmCom_Command HsmCom_AsyncCommand;
#endif

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
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
**                      Global Function Definitions                           **
*******************************************************************************/
#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

/*******************************************************************************
**                                                                            **
** Syntax          : void HsmCom_TimerCallback(void)                          **
**                                                                            **
** Description     :  This is Timer callback function invoked in Gpt when the **
**                      time gets elapsed                                     **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non-Reentrant                                            **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
void HsmCom_TimerCallback(void)
{

    HsmCom_CallbackNotify = TRUE;

}

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 589]                               **
**                                                                            **
** Syntax          : boolean HsmCom_IsHsmRespRecieved(void)                   **
**                                                                            **
** Description     :  This function checks if the command  response is        **
**                      recieved from HSM                                     **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : TRUE- HSM Response recieved                              **
**                   FALSE- HSM Response not recieved                         **
**                                                                            **
*******************************************************************************/
boolean HsmCom_IsHsmRespRecieved(void)
{
  boolean HsmResp;
  uint32 HostFlag;
  uint32 StatusVal;

  HsmResp = FALSE;
  HostFlag = HsmMcal_GetHt2HsmFlag();
  StatusVal = HsmMcal_GetHsm2HtStatus();
  /* check if HT2HSM flag is cleared and BUSY flag is not set */
  if ( (HostFlag == HSMCOM_REGCLEAR) &&
     ( (StatusVal & (uint32)HSMCOM_STAT_BUSY) != (uint32)HSMCOM_STAT_BUSY))
  {
    HsmResp = TRUE;
  }
  return HsmResp;
}

/*******************************************************************************
** Traceability    : NA                                                       **
**                                                                            **
** Syntax          : void HsmCom_HsmResponseValidation(void)                  **
**                                                                            **
** Description     : This function unpacks the HSM2HT flag register.          **
**                   Validates the register contents and stores the result in **
**                   corresponding session data.                              **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
void HsmCom_HsmResponseValidation(void)
{
  HsmCom_Command CommandId;
  HsmCom_Error ErrorVal;
  uint8 CommandSrc;
  uint8 CommandCancelSrc;
  HsmCom_SessionId SessionId;
  HsmCom_Session SessionDataPtr;

  /* Unpack the response from HSM */
  /*IFX_MISRA_RULE_01_03_STATUS=Local variable is referenced*/
  /*IFX_MISRA_RULE_01_03_STATUS=Local variable is referenced*/
  /*IFX_MISRA_RULE_01_03_STATUS=Local variable is referenced*/
  /*IFX_MISRA_RULE_01_03_STATUS=Local variable is referenced*/
  SessionId = HsmCom_UnpackResponse(&CommandSrc, &CommandCancelSrc,
                                        &CommandId, &ErrorVal);

    SessionDataPtr = HsmCom_GetSession(SessionId);
    /* Check if Command bit is set in HSM2HTF register */
    if ((CommandSrc != HSMCOM_CMDSRCCLEAR) ||
        (CommandCancelSrc != HSMCOM_CMDCANCELSRCCLEAR))
    {
      /* Is the response recieved for the same command that was sent
       * before */
      if (SessionDataPtr->Command != CommandId)
      {
        SessionDataPtr->Error = HSMCOM_ERC_GENERAL_FAILURE;
      }
      else
      {
        /* Store the HSM response in session data */
        SessionDataPtr->Error = ErrorVal;
      }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
      HsmCom_AsyncCommand = SessionDataPtr->Command;
#endif
      /* SessionDataPtr->Command = HSMCOM_CMD_NOTHINGTODO indicates that
       * command is completed between Host and HSM */
      SessionDataPtr->Command = HSMCOM_CMD_NOTHINGTODO;
    }
}

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 554] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : Csm_ReturnType HsmCom_WaitForHsm (uint32 InitStatus)     **
**                                                                            **
** Description     : This function waits until the specific HSM state given   **
**                   as parameter is reached and then returns.                **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : InitStatus - Value of the expected HSM state.            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK: HSM reached the State                          **
**                   CSM_E_NOT_OK: HSM doesn't reach the State till the       **
**                    timeout occurs                                          **
*******************************************************************************/
Csm_ReturnType HsmCom_WaitForHsm (uint32 InitStatus)
{
  boolean CheckFinish;
  boolean CallbackNotifyTmp;
  Csm_ReturnType RetVal;
  uint32 HsmState;
  CRY_HSM_TICK_TYPE StartTime;
  CRY_HSM_TICK_TYPE ElapsedTime;
  CRY_HSM_TICK_TYPE TimeOutTicks;

  CheckFinish = FALSE;
  RetVal = CSM_E_NOT_OK;

  TimeOutTicks = HSMCOM_WAIT_STATE_TIMEOUT;
  HsmCom_CallbackNotify = FALSE;

  /* start the timer */
  StartTime = Cry_Hsm_StartTimer(TimeOutTicks);

#if CRY_HSM_USER_TIMEOUT_API == STD_OFF
  Gpt_EnableNotification(CRY_HSM_GPT_CHANNEL);
#endif
  do
  {
    ElapsedTime = Cry_Hsm_GetElapsedTime(StartTime);
    CallbackNotifyTmp = HsmCom_CallbackNotify;

    HsmState = HsmMcal_GetHsm2HtStatus();
    HsmState = HsmState & InitStatus;
    /* check if the state is reached */
    if(HsmState == InitStatus)
    {
      CheckFinish = TRUE;
      RetVal = CSM_E_OK;
    }
    else
    {
      /* check if timeout occurs */
      if ( (ElapsedTime >= TimeOutTicks) || (CallbackNotifyTmp == TRUE) )
      {
        CheckFinish = TRUE;
      }
    }
  }while(CheckFinish == FALSE);
  /*End of do while(CheckFinish == FALSE)*/
  /**/
  Cry_Hsm_StopTimer();
  return RetVal;
}
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 606] [$Satisfies $CDS_CDRV 555]    **
**                   [$Satisfies $CDS_CDRV 556] [$Satisfies $CDS_CDRV 607]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType HsmCom_RequestHsmInit (void)              **
**                                                                            **
** Description     : This function is requesting the initialization of the HSM**
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
** Return value    : CSM_E_OK: Request successful                             **
**                   CSM_E_NOT_OK: Request failed due to timeout              **
**                                                                            **
*******************************************************************************/
#if (CRY_HSM_TRIGGERED_INIT == STD_ON)
Csm_ReturnType HsmCom_RequestHsmInit (void)
{
  Csm_ReturnType RetVal;

  /* Set the Init bit in HT2HSM flag register */
  HsmMcal_SetHt2HsmFlag((uint32)(1U << HSMCOM_INIT_INTR_BIT_POS));
#if (CRY_HSM_USE_SYNC_INIT == STD_ON)
  /* Check if the initialization is completed by HSM */
  RetVal = HsmCom_WaitForHsm((uint32)HSMCOM_STAT_WAIT_COMMAND);
#else
  RetVal = CSM_E_OK;
#endif
  return RetVal;
}
#endif

/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : uint32 HsmCom_GetStatus(void)                           **
**                                                                           **
** Description     : This API returns the status of the HSM by reading       **
**                   SHE status bits (lowest 8 bits) from the                **
**                   HSM_BRIDGE_HSM2HTS register.                            **
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
uint32 HsmCom_GetStatus(void)
{
  uint32 HsmStatus;
  uint32 RetStatus;
  /* HsmMcal_GetHsm2HtStatus function returns the lowest 8 bits of
   * HSM2HTS status register value */
  HsmStatus = HsmMcal_GetHsm2HtStatus();
  /* Mask the status with HSMCOM_STATUS_MASK */
  RetStatus = (HsmStatus & HSMCOM_STATUS_MASK);
  return RetStatus;
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 645] [$Satisfies $CDS_CDRV 744]   **
**                                                                           **
** Syntax          : HsmCom_Error HsmCom_SheCancel(void)                     **
**                                                                           **
** Description     : This API sets the cancel interrupt bit on Ht2HsmF reg   **
**                   to cancel the ongoing command , waits till the timeout  **
**                   period and returns HSMCOM_ERC_TIMEOUT if the cancel     **
*                    command is not acknwoledged.                            **
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
** Return value    : HSMCOM_ERC_NO_ERROR: Cancel command acknowledged        **
**                                        or Cancel request not sent to HSM  **
**                   HSMCOM_ERC_TIMEOUT : Timeout occured While Host         **
**                                        waiting for acknowledgemnt         **
**                                        from HSM for Cancel command        **
******************************************************************************/
HsmCom_Error HsmCom_SheCancel(void)
{
  uint32 RegVal ;
  uint32 HsmStatus;
  uint32 CancelStatus;
  uint32 StartTime;
  uint32 ElapsedTime;
  HsmCom_Error ErrorVal;
  uint8 CancelWait;

  ErrorVal = HSMCOM_ERC_NO_ERROR;
  CancelWait = TRUE;
  /* Read the status from HSM2HT staus register */
  HsmStatus = HsmMcal_GetHsm2HtStatus();
  /*Check if the busy bit is set */
  if((HsmStatus & (uint32)HSMCOM_STAT_BUSY) == (uint32)HSMCOM_STAT_BUSY)
  {
    /*Set the Commnad Cancel bit when the HSM status is busy */
    RegVal = (uint32)(1UL << HSMCOM_CANCEL_INTR_BIT_POS);
    HsmMcal_SetHt2HsmFlag(RegVal);

    /*Start timer*/
    StartTime = HsmMcal_GetStmValue();

    CancelStatus = (uint32)(1UL << HSMCOM_CANCEL_INTR_BIT_POS);
    do
    {
      ElapsedTime = HsmMcal_GetStmValue() - StartTime;

      /* read the condition of the interrupt flags */
      RegVal = HsmMcal_GetHt2HsmFlag();
      RegVal = RegVal & CancelStatus;

      /* check if the command has been acknowledged */
      if(RegVal != CancelStatus)
      {
        CancelWait = FALSE;
      }
      else
      {
        /* check if time out has occurred */
        if(ElapsedTime > HSMCOM_CANCEL_TIMEOUT)
        {
          CancelWait = FALSE;
          ErrorVal = HSMCOM_ERC_TIMEOUT;
        }
      }
    /* wait for the cancel to be acknowledged or timeout to occur*/
    }while(CancelWait == TRUE);
  }
  return ErrorVal;
}

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 552] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : void HsmCom_CloseSession(HsmCom_Session )                **
**                                                                            **
** Description     : This function closes a session after requested command   **
**                   from CRY module has been processed                       **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : SessionDataPtr - Pointer to the session to be closed     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
void HsmCom_CloseSession(HsmCom_Session SessionDataPtr)
{
  /* Check if session is valid */
  if (SessionDataPtr != HSMCOM_INVALID_SESSION)
  {
    /* Set the indication that session is closed (free) */
    SessionDataPtr->Locked = FALSE;
  }
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void *HsmCom_GetParamsBuffer
**                                   (HsmCom_Session SessionDataPtr)          **
**                                                                            **
** Description     : This function returns the pointer to shared buffer       **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : Pointer to the session                                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Pointer to shared buffer                                 **
**                                                                            **
*******************************************************************************/
void *HsmCom_GetParamsBuffer(HsmCom_Session  SessionDataPtr)
{
  /*IFX_MISRA_RULE_11_03_STATUS=Typecasting is required as shared buffer
   *alignment changes with each service*/
  return ((void*)&(HsmCom_DataBuffers.Ht2Hsm[SessionDataPtr->Index]));
  /*IFX_MISRA_RULE_08_13_STATUS=SessionDataPtr can't be declared as const*/
}
#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void HsmCom_ClearErr(HsmCom_Session SessionDataPtr)      **
**                                                                            **
** Description     : This function  clears the previous command error status  **
**                   in session data                                          **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : SessionDataPtr - Pointer to input session                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
void HsmCom_ClearErr(HsmCom_Session SessionDataPtr)
{
  if (SessionDataPtr != HSMCOM_INVALID_SESSION)
  {
    SessionDataPtr->Error = HSMCOM_ERC_NO_ERROR;
  }
}

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 550] [$Satisfies $CDS_CDRV 579]    **
**                   [$Satisfies $CDS_CDRV 586]                               **
** Syntax          : void HsmCom_Init(void)                                   **
**                                                                            **
** Description     : This function initializes the HsmCom module              **
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
void HsmCom_Init(void)
{
  HsmCom *DataPtr;
  uint32 LoopSize;
  uint32 LoopValue;
  HsmCom_Session SessionDataPtr;

  LoopSize = HSMCOM_MAX_SESSIONS;
  DataPtr = &HsmCom_Data;
  /* Check if initialization is not done already */
  if (DataPtr->Initialized == FALSE)
  {
    /* Initialize all sessions will default values */
    for (LoopValue = 0U; LoopValue < LoopSize; LoopValue++)
    {
      SessionDataPtr = &(DataPtr->Session[LoopValue]);
      /* Initialize session indexes */
      SessionDataPtr->Index = LoopValue;
      /**/
      SessionDataPtr->Command = HSMCOM_CMD_NOTHINGTODO;
      SessionDataPtr->Locked = FALSE;
    }
    /* Clear the HSM2HTF register */
    HsmCom_ClearHsmResp();
    /* Set the indication that initialization is completed */
    DataPtr->Initialized = TRUE;
  }
}

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 557] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax         : HsmCom_Error HsmCom_InitSharedBuffer(HsmAes_Block* BufPtr)**
**                                                                            **
** Description     : This function sends the start address of the shared      **
**                   memory buffer to the HSM and returns the result. It      **
**                   also includes a check on the memory buffer               **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : BufPtr - Pointer to the shared memory buffer             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Error Returned from HSM                                  **
**                                                                            **
*******************************************************************************/
HsmCom_Error HsmCom_InitSharedBuffer(HsmAes_Block* BufPtr)
{
  HsmAes_Block *BuffersPtr;
  boolean CmpResult;
  boolean CheckFinish;
  boolean CallbackNotifyTmp;
  HsmCom_Error ErrorVal;
  HsmCom_Session SessionDataPtr;
  CRY_HSM_TICK_TYPE StartTime;
  CRY_HSM_TICK_TYPE ElapsedTime;
  CRY_HSM_TICK_TYPE TimeoutTicks;

  BuffersPtr = BufPtr;
  CheckFinish = FALSE;
  ErrorVal = HSMCOM_ERC_NO_ERROR;
  TimeoutTicks = CRY_HSM_INIT_TIMEOUT;
  HsmCom_CallbackNotify = FALSE;
  /* open the Session to send the HSMCOM_INIT_SET_BUFFER command */
  SessionDataPtr = HsmCom_OpenSession();

  /* Check if session is opened successfully */
  if (SessionDataPtr == HSMCOM_INVALID_SESSION)
  {
    ErrorVal = HSMCOM_ERC_GENERAL_FAILURE;
  }

  if (ErrorVal == HSMCOM_ERC_NO_ERROR)
  {
    /* Write the first 16 bytes of shared buffer with value 0x5A */
    HsmCom_SetArrayValue(BuffersPtr->Data, HSMCOM_INITSHAREDBUFFER_WRITEVAL,
                                       HSMCOM_DATAARRAYSIZE);
    /* Cross check that the value 0x5A is written properly in the buffer */
    CmpResult = HsmCom_CompareValue(BuffersPtr->Data,
                                    HSMCOM_INITSHAREDBUFFER_WRITEVAL,
                                    HSMCOM_DATAARRAYSIZE);

    if (CmpResult == FALSE)
    {
      ErrorVal = HSMCOM_ERC_GENERAL_FAILURE;
    }
  }

  if (ErrorVal == HSMCOM_ERC_NO_ERROR)
  {
    /* Write the shared buffer address in HT2HSMS register */
    /*IFX_MISRA_RULE_11_04_STATUS=Type casting required as Mcal interface
     * expects uint32 input */
    /*IFX_MISRA_RULE_11_06_STATUS=Type casting required as Mcal interface
     * expects uint32 input */
    HsmMcal_SetHt2HsmStatus((uint32)BufPtr);
    /* Clear the variable "PackedParams" in session data */
    SessionDataPtr->PackedParams.U = 0x00;
    /* Send the command to HSM */
    HsmCom_SendCommand(SessionDataPtr, HSMCOM_INIT_SET_BUFFER);
    StartTime = Cry_Hsm_StartTimer(TimeoutTicks);
    #if CRY_HSM_USER_TIMEOUT_API == STD_OFF
    Gpt_EnableNotification(CRY_HSM_GPT_CHANNEL);
    #endif
    do
    {
      ElapsedTime = Cry_Hsm_GetElapsedTime(StartTime);
      CallbackNotifyTmp = HsmCom_CallbackNotify;
      /* Check if HSMCOM_INIT_SET_BUFFER is executed by HSM
       * and the response is received */
      if (HsmCom_IsCmdExecuted() != FALSE)
      {
        CheckFinish = TRUE;
        /* Read the HSM error response that is stored in session
         * data */
        ErrorVal = SessionDataPtr->Error;
      }
      /* Check if timeout occurs */
      else if ( (ElapsedTime >= TimeoutTicks) || (CallbackNotifyTmp == TRUE) )
      {
        CheckFinish = TRUE;
        ErrorVal = HSMCOM_ERC_TIMEOUT;
      }
      else
      {
        /*Dummy*/
      }
    }while(CheckFinish == FALSE);
    if (ErrorVal == HSMCOM_ERC_NO_ERROR)
    {
      /* Read the first 16 bytes of shared buffer for the vlue 0x00 */
      CmpResult = HsmCom_CompareValue(BuffersPtr->Data,
                  HSMCOM_INITSHAREDBUFFER_READVAL, HSMCOM_DATAARRAYSIZE);
      if (CmpResult == FALSE)
      {
        ErrorVal = HSMCOM_ERC_GENERAL_FAILURE;
      }
    }
  }
  /* stop the timer */
  Cry_Hsm_StopTimer();
  /* close the session */
  HsmCom_CloseSession(SessionDataPtr);
  return (ErrorVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : boolean HsmCom_CompareArray(const uint32* DestPtr,       **
**                                               const uint32* SrcPtr,        **
**                                               uint32 Count)                **
**                                                                            **
** Description     : Function compares the values pointed by                  **
**                  source and destination pointers                           **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : DestPtr - destination pointer                            **
**                   SrcPtr  - source pointer                                 **
**                   Count   - number of long words to be compared            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  TRUE: comparison successful                             **
**                    FALSE: comparison failed                                **
*******************************************************************************/
boolean HsmCom_CompareArray(const uint32* DestPtr,const uint32* SrcPtr,
                                    uint32 Count)
{
  boolean ResultVal;
  uint32 Index;

  ResultVal = TRUE;
  for (Index = 0U; Index < (Count); Index++)
  {
    if(DestPtr[Index] != SrcPtr[Index])
    {
      ResultVal = FALSE;
    }
  }
  return ResultVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : boolean HsmCom_CompareValue(const uint32* DestPtr,       **
**                                               uint32 Value,                **
**                                               uint32 Count)                **
**                                                                            **
** Description     : Function compares the values pointed by                  **
**                   destination pointer with the input Value                 **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : DestPtr - destination pointer                            **
**                   Value   - value to be compared                           **
**                   Count   - number of longwords to be compared             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  TRUE: comparison successful                             **
**                    FALSE: comparison failed                                **
*******************************************************************************/
boolean HsmCom_CompareValue(const uint32* DestPtr, uint32 Value, uint32 Count)
{
  boolean ResultVal;
  uint32 Index;

  ResultVal = TRUE;
  for (Index = 0U; Index < (Count); Index++)
  {
    if(DestPtr[Index] != Value)
    {
      ResultVal = FALSE;
    }
  }
  return ResultVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void HsmCom_CopyArray(uint32* DestPtr,                   **
**                                         const uint32* SrcPtr,              **
**                                         uint32 Count)                      **
**                                                                            **
** Description     : Function copies the values from souce pointer to         **
**                   destimation pointer                                      **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : DestPtr - destination pointer                            **
**                   SrcPtr  - source pointer                                 **
**                   Count   -  Number of long words to be copied             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
void HsmCom_CopyArray(uint32* DestPtr, const uint32* SrcPtr, uint32 Count)
{
  uint32 Index;

  for (Index = 0U; Index < Count; Index++)
  {
    DestPtr[Index] = SrcPtr[Index];
  }
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void HsmCom_SetArrayValue(uint32* DestPtr,               **
**                                             uint32 Value,                  **
**                                             uint32 Count)                  **
**                                                                            **
** Description     : Function copies the input value into the location pointed**
**                 by destination pointer                                     **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : DestPtr - Destination pointer                            **
**                   Value   - input value                                    **
**                   Count   - number of longwords to be copied               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
void HsmCom_SetArrayValue(uint32* DestPtr, uint32 Value, uint32 Count)
{
  uint32 Index;
  for (Index = 0U; Index < Count; Index++)
  {
    DestPtr[Index] = Value;
  }
}

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"
/*End of HSM_COM_C*/
