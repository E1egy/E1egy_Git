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
**  FILENAME    : Hsm_Mcal.h                                                  **
**                                                                            **
**  VERSION     : 5.0.0                                                       **
**                                                                            **
**  DATE        : 2017-06-22                                                  **
**                                                                            **
**  VARIANT     : NA                                                          **
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
#ifndef HSM_MCAL_H
#define HSM_MCAL_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
/* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Automic write function */
#include "Registers_Hsm.h"
#include "IfxStm_reg.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant variable declarations                 **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**          Global Function Declarations (exported function prototypes)       **
*******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/

/*******************************************************************************
**                                                                            **
** Traceability    : [$Satisfies $CDS_CDRV 746]                               **
**                                                                            **
** Syntax          : LOCAL_INLINE uint32 HsmMcal_GetStmValue(void)        **
**                                                                            **
** Description     : This function reads the current value of the STM timer   **
**                   register.                                                **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non reentrant                                            **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : STM timer value                                          **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 HsmMcal_GetStmValue(void)
{
  /*IFX_MISRA_RULE_11_04_STATUS=Accessing value of a SFR*/
  return (uint32)STM0_TIM0.U;
}
/*******************************************************************************
**                                                                            **
** Traceability    : [$Satisfies $CDS_CDRV 562] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : LOCAL_INLINE void HsmMcal_SetHt2HsmStatus(           **
**                                                      uint32 Status)        **
**                                                                            **
** Description     : This function writes the status to the HT2HSM status     **
**                   register.                                                **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non reentrant                                            **
**                                                                            **
** Parameters (in) : Status - Status to be written to HSM                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void HsmMcal_SetHt2HsmStatus(uint32 Status)
{
  /*IFX_MISRA_RULE_11_04_STATUS=Assigment of value to a SFR*/
  /*IFX_MISRA_RULE_11_06_STATUS=Assigment of value to a SFR*/
  HSM_HT2HSMS.U = Status;
}
/*******************************************************************************
**                                                                            **
** Traceability    : [$Satisfies $CDS_CDRV 561] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : LOCAL_INLINE uint32 HsmMcal_GetHsm2HtStatus(         **
**                                                               void)        **
**                                                                            **
** Description     : This function returns the HSM2HT status register value   **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non reentrant                                            **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Status read from HSM                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 HsmMcal_GetHsm2HtStatus(void)
{
  /*IFX_MISRA_RULE_11_04_STATUS=Accessing value of a SFR*/
  /*IFX_MISRA_RULE_11_06_STATUS=Accessing value of a SFR*/
  return (uint32)HSM_HSM2HTS.U;
}
/*******************************************************************************
**                                                                            **
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE void HsmMcal_SetHsm2HtFlag(             **
**                                                      uint32 FlagVal)       **
**                                                                            **
** Description     : This function writes Flag value to Hsm2Ht flag register  **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non reentrant                                            **
**                                                                            **
** Parameters (in) : FlagVal - Value to be written to HSM2HTF                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void HsmMcal_SetHsm2HtFlag(uint32 FlagVal)
{
  /*IFX_MISRA_RULE_11_04_STATUS=Assigment of value to a SFR*/
  /*IFX_MISRA_RULE_11_06_STATUS=Assigment of value to a SFR*/
  HSM_HSM2HTF.U = FlagVal;
}
/*******************************************************************************
**                                                                            **
** Traceability    : [$Satisfies $CDS_CDRV 564] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : LOCAL_INLINE uint32 HsmMcal_GetHsm2HtFlag(void)      **
**                                                                            **
** Description     : This function writes Flag value to Hsm2Ht flag register  **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non reentrant                                            **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Flag register value from HSM to Host                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 HsmMcal_GetHsm2HtFlag(void)
{
  /*IFX_MISRA_RULE_11_04_STATUS=Accessing value of a SFR*/
  /*IFX_MISRA_RULE_11_06_STATUS=Accessing value of a SFR*/
  return (uint32)HSM_HSM2HTF.U;
}
/*******************************************************************************
**                                                                            **
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE uint32 HsmMcal_GetHt2HsmFlag(void)      **
**                                                                            **
** Description     : This function returns Ht2Hsm flag register               **
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
** Return value    : Flag register value from Host to HSM                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 HsmMcal_GetHt2HsmFlag(void)
{
  /*IFX_MISRA_RULE_11_04_STATUS=Accessing value of a SFR*/
  /*IFX_MISRA_RULE_11_06_STATUS=Accessing value of a SFR*/
  return (uint32)HSM_HT2HSMF.U;
}
/*******************************************************************************
**                                                                            **
** Traceability    : [$Satisfies $CDS_CDRV 563] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : LOCAL_INLINE void HsmMcal_SetHt2HsmFlag(             **
**                                                           uint32 FlagVal)  **
**                                                                            **
** Description     : This function sets the flags for HT2HSM flags register.  **
**                   All 32 bits will be written with the input value         **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : FlagVal - Value to be update in Host to HSM flag register**
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void HsmMcal_SetHt2HsmFlag(uint32 FlagVal)
{
  /*IFX_MISRA_RULE_11_04_STATUS=Assigment of value to a SFR*/
  /*IFX_MISRA_RULE_11_06_STATUS=Assigment of value to a SFR*/
  HSM_HT2HSMF.U = FlagVal;
}

#ifdef CONTROLLER_TC23x
/*******************************************************************************
**                                                                            **
** Traceability    : [$Satisfies $CDS_CDRV 560] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : LOCAL_INLINE void HsmMcal_DisableEccErrors(          **
**                                                                    void)   **
**                                                                            **
** Description     : This function is disabling the generation of TriCore     **
**                   Traps in case of PFLash ECC error.                       **
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
LOCAL_INLINE void HsmMcal_DisableEccErrors(void)
{
  /* PF0 traps must be disabled
   * because of ECC errors that may occur during FEE/FLS initialization
   * or write operations
   */
  Mcal_ResetENDINIT();
  /* Disable PF0 Traps */
  /*IFX_MISRA_RULE_11_04_STATUS=Assigment of value to a SFR*/
  FLASH0_MARP.B.TRAPDIS = 1U;
  Mcal_SetENDINIT();
}
/*******************************************************************************
**                                                                            **
** Traceability    : [$Satisfies $CDS_CDRV 559] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : LOCAL_INLINE void HsmMcal_EnableEccErrors(uint32     **
**                                                            TrapDisStatus)  **
**                                                                            **
**                                                                            **
** Description     : This function restores the "Trap Disable" bit state in   **
**                    Margin Control Register PFLASH                          **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : TrapDisStatus - "Trap Disable" bit value                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void HsmMcal_EnableEccErrors(uint32 TrapDisStatus)
{
  /* Re-enable PF0 traps */
  Mcal_ResetENDINIT();
  /*IFX_MISRA_RULE_10_03_STATUS=Accessing SFR*/
  /*IFX_MISRA_RULE_11_04_STATUS=Accessing value of a SFR*/
  FLASH0_MARP.B.TRAPDIS = TrapDisStatus;
  Mcal_SetENDINIT();
}
#endif

/*******************************************************************************
**                                                                            **
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE void HsmMcal_DbgBaseUpdate(             **
**                                                     uint32 DbgValue)       **
**                                                                            **
** Description     : This function writes Debug value to debug base register  **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : DbgValue -                                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void HsmMcal_DbgBaseUpdate(uint32 DbgValue)
{
  /*IFX_MISRA_RULE_11_04_STATUS=Assigment of value to a SFR*/
  /*IFX_MISRA_RULE_11_06_STATUS=Assigment of value to a SFR*/
  HSM_DBGBASE.U = DbgValue;
}
#ifdef CONTROLLER_TC23x
/*******************************************************************************
**                                                                            **
** Traceability    : [$Satisfies $CDS_CDRV 565] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : LOCAL_INLINE void HsmMcal_GetTrapDisableStatus(void) **
**                                                                            **
**                                                                            **
** Description     : This function is returns the value of "Trap Disable"     **
**                   bit in Margin Control Register PFLASH                    **
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
** Return value    : "Trap Disable" bit in Margin Control Register PFLASH     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 HsmMcal_GetTrapDisableStatus(void)
{
  /*IFX_MISRA_RULE_11_04_STATUS=Accessing value of a SFR*/
  return (FLASH0_MARP.B.TRAPDIS);
}
#endif
#endif /* End of HSM_MCAL_H */
