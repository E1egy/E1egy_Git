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
**  FILENAME    : HsmCom.h                                                    **
**                                                                            **
**  VERSION     : 3.0.0                                                       **
**                                                                            **
**  DATE        : 2016-07-11                                                  **
**                                                                            **
**  VARIANT     :                                                             **
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
#ifndef HSMCOM_H
#define HSMCOM_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Csm_Types.h"
#include "Cry_Hsm_Cfg.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

extern boolean HsmCom_CallbackNotify;

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

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
void HsmCom_TimerCallback(void);
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
** Return value    : Request successful or failed due to timeout              **
**                                                                            **
*******************************************************************************/
extern Csm_ReturnType HsmCom_WaitForHsm (uint32 InitStatus);

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 555]                               **
**                   [$Satisfies $CDS_CDRV 556] [$Satisfies $CDS_CDRV 557]    **
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
** Return value    : Request successful or failed due to timeout              **
**                                                                            **
*******************************************************************************/
#if (CRY_HSM_TRIGGERED_INIT == STD_ON)
extern Csm_ReturnType HsmCom_RequestHsmInit (void);
#endif

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"
/* end of HSMCOM_H */
#endif
