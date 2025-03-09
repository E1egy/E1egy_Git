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
**  FILENAME    : HsmCom_Priv.h                                               **
**                                                                            **
**  VERSION     : 5.0.0                                                       **
**                                                                            **
**  DATE        : 2017-06-27                                                  **
**                                                                            **
**  VARIANT     : VariantPreCompile                                           **
**                                                                            **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                               **
**                [Refer Release Package for Supported Device]                **
**  AUTHOR      : Trivikram G                                                 **
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
#ifndef HSMCOM_PRIV_H
#define HSMCOM_PRIV_H
/*******************************************************************************
**                      Includes                                             **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "HsmCom_def.h"
#include "Hsm_Mcal.h"
#include "Cry_Hsm_PrivCfg.h"
#include "Cry_HsmTypes.h"

/*******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/

#define HSMCOM_REGCLEAR 0x00U

#define HSMCOM_INVALID_SESSION  ((void*)0)

/*******************************************************************************
**                      Global Type Definition                                **
*******************************************************************************/

typedef struct
{
  boolean                 Locked;
  uint32                  Index;
  volatile
  HsmCom_Command          Command;
  HsmCom_Error            Error;
  HsmCom_PackedParams     PackedParams;
} HsmCom_SessionData;

/* Handle to a session of HSM communication */
typedef HsmCom_SessionData *HsmCom_Session;

typedef struct
{
  uint32 Start;
  uint32 Duration;
  HsmCom_Command Command;
} HsmCom_Timing;

typedef struct
{
  boolean                 Initialized;
  HsmCom_SessionData      Session[HSMCOM_MAX_SESSIONS];
} HsmCom;

/*******************************************************************************
**                      Global Constant variable declarations                 **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Declarations                         **
*******************************************************************************/
#define CRY_START_SEC_VAR_ALIGN16
#include "Cry_MemMap.h"

extern HsmCom_Buffers HsmCom_DataBuffers;

#define CRY_STOP_SEC_VAR_ALIGN16
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

extern HsmCom HsmCom_Data;

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/*Variable to store the command code for Async mode
  This variable will be referenced in main function  */
extern HsmCom_Command HsmCom_AsyncCommand;
#endif

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define CRY_START_SEC_RAMCODE
#include "Cry_MemMap.h"
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
extern boolean HsmCom_IsHsmRespRecieved(void);

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
extern void HsmCom_HsmResponseValidation(void);

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
extern uint32 HsmCom_GetStatus(void);

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
extern HsmCom_Error HsmCom_SheCancel(void);
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
extern void *HsmCom_GetParamsBuffer(HsmCom_Session  SessionDataPtr);

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
extern void HsmCom_CloseSession(HsmCom_Session SessionDataPtr);
#define CRY_STOP_SEC_RAMCODE
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
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
extern void HsmCom_ClearErr(HsmCom_Session SessionDataPtr);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 579]                               **
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
extern HsmCom_Error HsmCom_InitSharedBuffer(HsmAes_Block* BufPtr);

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
extern void HsmCom_Init(void);
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
extern boolean HsmCom_CompareArray(const uint32* DestPtr,
        const uint32* SrcPtr, uint32 Count);
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
extern boolean HsmCom_CompareValue(const uint32* DestPtr, uint32 Value,
            uint32 Count);
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
extern void HsmCom_CopyArray(uint32* DestPtr, const uint32* SrcPtr,
            uint32 Count);

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
extern void HsmCom_SetArrayValue(uint32* DestPtr,uint32 Value, uint32 Count);

#define CRY_STOP_SEC_CODE
#include "Cry_MemMap.h"

/******************************************************************************
**                      Global Inline Function Definition                    **
******************************************************************************/

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE HsmCom_SessionId                        **
**                   HsmCom_UnpackResponse(HsmCom_Flags *flags,               **
**                                         HsmCom_Command *Command,           **
**                                         HsmCom_Error *Error)               **
**                                                                            **
** Description     :  This inline unpacks the HSM2HT flag register and stores **
**                    the result in corresponding session data.               **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): CommandSrcPtr: Pointer to the location where the value   **
**                                  of command source bit value has to        **
**                                  be updated                                **
**                   CommandCancelSrcPtr: Pointer to the location where the   **
**                                        value of command cancel bit value   **
**                                        has to be updated                   **
**                   CommandPtr: Pointer to the location where the value of   **
**                                       command value has to be updated      **
**                   ErrorPtr: Pointer to the location where HSM error        **
**                   response has to be updated                               **
**                                                                            **
** Return value    : Session ID returned by HSM                               **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE HsmCom_SessionId HsmCom_UnpackResponse(
                           uint8 *CommandSrcPtr, uint8 *CommandCancelSrcPtr,
                           HsmCom_Command *CommandPtr, HsmCom_Error *ErrorPtr)
{
  /*IFX_MISRA_RULE_19_02_STATUS=Union Used. Required as the response
      read from HSM is to be unpacked */
  HsmCom_PackedResponse PackedVal;

  PackedVal.U = (uint32)HsmMcal_GetHsm2HtFlag();
  HsmMcal_SetHsm2HtFlag(PackedVal.U);

  *CommandSrcPtr = (uint8)PackedVal.B.CmdSrc;
  *CommandCancelSrcPtr = (uint8)PackedVal.B.CmdCancelSrc;

  /*IFX_MISRA_RULE_10_03_STATUS=Type casting is required to convert
  the value read from HSM2HTF register*/
  /*IFX_MISRA_RULE_10_05_STATUS=Type casting is required to convert
     the value read from HSM2HTF register*/
  *CommandPtr = (HsmCom_Command)PackedVal.B.Command;
  /*IFX_MISRA_RULE_10_03_STATUS=Type casting is required to convert
   the value read from HSM2HTF register*/
  /*IFX_MISRA_RULE_10_05_STATUS=Type casting is required to convert
    the value read from HSM2HTF register*/
  *ErrorPtr = (HsmCom_Error)PackedVal.B.Error;
  return (HsmCom_SessionId) PackedVal.B.Session;
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE HsmCom_Session HsmCom_GetSession        **
**                                              (HsmCom_SessionId SessionId)  **
**                                                                            **
** Description     :  This inline returns the session address for the input   **
**                    session ID                                              **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : SessionId                                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : session address                                          **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE HsmCom_Session HsmCom_GetSession
                                    (HsmCom_SessionId SessionId)
{
  return &(HsmCom_Data.Session[SessionId]);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE void HsmCom_SetPackedParams             **
**                                         (HsmCom_Session SessionDataPtr,    **
**                                          HsmCom_KeyAddr KeyAddr,           **
**                                          HsmCom_AesMode ModeValue)         **
**                                                                            **
** Description     : This inline updates the element PackedParams with        **
**                    Key address and mode value. PackedParams is part of     **
**                   session data.                                            **
**                   PackedParams is used in "HsmCom_SendCommand" function    **
**                   to update the HT2HSM flag register.                      **
**                                                                            **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : SessionDataPtr - session data pointer                    **
**                   KeyAddr    -  Key ID                                     **
**                   ModeValue  - AES mode                                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void HsmCom_SetPackedParams(HsmCom_Session SessionDataPtr,
        HsmCom_KeyAddr KeyAddr, Cry_HsmAesModeType ModeValue)
{
  uint32 Mode;
  uint32 Key;
  Mode = (uint32)((uint32)ModeValue << HSMCOM_AES_MODE_BIT_POS);
  Key = (uint32)((uint32)KeyAddr << HSMCOM_KEYADDR_BIT_POS);
  SessionDataPtr->PackedParams.U = Mode | Key;
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE void HsmCom_ClearHsmResp(void)          **
**                                                                            **
** Description     :  This function clears old response from HSM by clearing  **
**                     HT2HSMF register                                       **
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
LOCAL_INLINE void HsmCom_ClearHsmResp(void)
{
  uint32 RegVal;

  RegVal = HsmMcal_GetHsm2HtFlag();
  HsmMcal_SetHsm2HtFlag(RegVal);
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE boolean HsmCom_IsCmdAccepted(void)      **
**                                                                            **
** Description     :  This inline checks if the command is accepted by HSM    **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value    : TRUE - command accepted                                  **
                   : FALSE - command not accepted                             **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE boolean HsmCom_IsCmdAccepted(void)
{
  uint32 FlagReg;
  boolean RetVal;

  RetVal = TRUE;
  FlagReg = HsmMcal_GetHt2HsmFlag();
  /* is HT2HSMF register cleared ? */
  if(FlagReg != HSMCOM_REGCLEAR)
  {
    RetVal = FALSE;
  }

  return RetVal;
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE boolean HsmCom_IsCmdExecuted(void)      **
**                                                                            **
** Description     :  This inline checks the command response from HSM.       **
**                    If the response is recieved, thi function validates the **
**                    response.                                               **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value    : TRUE - command execution in progress between Host and HSM**
**                 : FALSE - command execution completed between Host and HSM **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE boolean HsmCom_IsCmdExecuted(void)
{
  boolean RetVal;

  RetVal = FALSE;
  if (HsmCom_IsHsmRespRecieved() != FALSE)
  {
    HsmCom_HsmResponseValidation();
    RetVal = TRUE;
  }

  return RetVal;
}

/*******************************************************************************
**                                                                            **
** Traceability    : NA                                                       **
**                                                                            **
** Syntax          : LOCAL_INLINE boolean HsmCom_IsComBusy(void)          **
**                                                                            **
** Description     : This inline checks if HSM is busy processing the         **
**                    command.                                                **
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
** Return value    : TRUE- Busy                                               **
**                   FALSE- Not busy                                          **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE boolean HsmCom_IsComBusy(void)
{
  uint32 HostFlag;
  uint32 HsmStatus;
  boolean ComBusy;

  ComBusy = FALSE;

  /* Read Host to HSM flag register */
  HostFlag = HsmMcal_GetHt2HsmFlag();
  /* Read HSM to Host status register */
  HsmStatus = HsmMcal_GetHsm2HtStatus();
  /* HT2HSMF register != 0 (or) BUSY !=0 indicates that HSM is busy processing
   * the command  */
  if ((HostFlag != HSMCOM_REGCLEAR) ||
        ((HsmStatus & (uint32)HSMCOM_STAT_BUSY) == (uint32)HSMCOM_STAT_BUSY) )
  {
    ComBusy = TRUE;
  }
  return ComBusy;
}

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 553] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : LOCAL_INLINE void HsmCom_SendCommand(HsmCom_Session, **
**                                               HsmCom_Command CommandVal)   **
**                                                                            **
** Description     : This inline sends the requested command from CRY         **
**                   module to the HSM and returns the result whether the     **
**                   command is sent successfully or not.                     **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) :  - Valid session to process the command                  **
**                   CommandVal - Command to be sent to HSM                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void HsmCom_SendCommand(HsmCom_Session SessionDataPtr,
                                              HsmCom_Command CommandVal)
{
  uint32 Command;
  uint32 Session;
  uint32 CommandInt;
  uint32 Regval;

  /* Store the command in Session data.
   * This will be used later by "HsmCom_HsmResponseValidation" function
   * to validate the recieved HSM response */
  SessionDataPtr->Command = CommandVal;

  /* Send the command to HSM */
  Command =(uint32)((uint32)SessionDataPtr->Command <<
                                            HSMCOM_COMMAND_BIT_POS);
  Session =(uint32)((uint32)SessionDataPtr->Index << HSMCOM_SESSION_BIT_POS);
  CommandInt = (uint32)(1UL << HSMCOM_COMMAND_INTR_BIT_POS);

  Regval = ( (SessionDataPtr->PackedParams.U) | Command | Session |
                                                          CommandInt );

  HsmMcal_SetHt2HsmFlag(Regval);
}

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 551] [$Satisfies $CDS_CDRV 579]    **
**                   [$Satisfies $CDS_CDRV 587]                               **
** Syntax          : LOCAL_INLINE HsmCom_Session HsmCom_OpenSession(void) **
**                                                                            **
** Description     : This inline opens a session to process the requested     **
**                   command from CRY module                                  **
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
** Return value    : Session Id of the successfully created session.          **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE HsmCom_Session HsmCom_OpenSession(void)
{
  uint32 LoopValue;
  uint32 LoopSize;
  HsmCom_Session SessionDataPtr;

  LoopSize = HSMCOM_MAX_SESSIONS;
  SessionDataPtr = HSMCOM_INVALID_SESSION;
  for (LoopValue = 0U; LoopValue < LoopSize; LoopValue++)
  {
    /* Check the any session is available */

    if (HsmCom_Data.Session[LoopValue].Locked == FALSE)
    {

      SessionDataPtr = &HsmCom_Data.Session[LoopValue];
      /* Set the indication that session is occupied */
      SessionDataPtr->Locked = TRUE;
      break;
    }
  }/*End of "for(LoopValue = 0U; LoopValue < LoopSize; LoopValue++)"*/

  return SessionDataPtr;
}
/* end of HSMCOM_PRIV_H */
#endif
