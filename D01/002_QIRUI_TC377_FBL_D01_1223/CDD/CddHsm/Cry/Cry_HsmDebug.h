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
**  FILENAME    : Cry_HsmDebug.h                                              **
**                                                                            **
**  VERSION     : 2.0.0                                                       **
**                                                                            **
**  DATE        : 2016-10-06                                                  **
**                                                                            **
**  VARIANT     : NA                                                          **
**                                                                            **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                               **
**                [Refer Release Package for Supported Device]                **
**  AUTHOR      : Borg A                                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This is the corresponding header file for Cry_HsmDebug.c    **
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
#ifndef CRY_HSM_DEBUG_H
#define CRY_HSM_DEBUG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Cry_HsmTypes.h"

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

/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    :  [$Satisfies $CDS_CDRV 620], [$Satisfies $CDS_CDRV 621] **
**                    [$Satisfies $CDS_CDRV 622], [$Satisfies $CDS_CDRV 623] **
**                    [$Satisfies $CDS_CDRV 624], [$Satisfies $CDS_CDRV 625] **
**                    [$Satisfies $CDS_CDRV 579], [$Satisfies $CDS_CDRV 636] **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmDebugStart(uint8* Cry_Challenge)  **
**                                                                           **
** Description     : This function implements Cry_HsmDebugStart. It requests **
**                   debugger activation  on the HSM side.                   **
**                                                                           **
** Service ID      : CRY_HSM_SID_DEBUG_START                                 **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): Cry_Challenge  - Random number of length 128 bits       **
**                                    that is input for calculating the      **
**                                    debugger activation.                   **
**                                                                           **
** Return value    : CSM_E_OK       - Request successful                     **
**                   CSM_E_BUSY     - Request failed as underlying HSM       **
**                                    communication is busy                  **
**                   CSM_E_NOT_OK   - Request failed                         **
******************************************************************************/
extern Csm_ReturnType Cry_HsmDebugStart(uint8* Cry_Challenge);

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/******************************************************************************
** Traceability    :  [$Satisfies $CDS_CDRV 626], [$Satisfies $CDS_CDRV 627] **
**                    [$Satisfies $CDS_CDRV 628], [$Satisfies $CDS_CDRV 629] **
**                    [$Satisfies $CDS_CDRV 630], [$Satisfies $CDS_CDRV 631] **
**                    [$Satisfies $CDS_CDRV 579]  [$Satisfies $CDS_CDRV 637] **
**                    [$Satisfies $CDS_CDRV 638]                             **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmDebugFinish(                      **
**                        uint8* Cry_Authorization)                          **
**                                                                           **
** Description     : This function sends the authorization value for         **
**                   activation of debugger to the HSM                       **
**                                                                           **
** Service ID      : CRY_HSM_SID_DEBUG_FINISH                                **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : Cry_Authorization - Authorization value for activation  **
**                                      of debugger to the HSM               **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK       - Request successful                     **
**                   CSM_E_NOT_OK   - Request failed                         **
**                   CSM_E_BUSY     - Request failed due to underlying HSM   **
**                                    communication is busy                  **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType Cry_HsmDebugFinish (uint8* Cry_Authorization);

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 619] [$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          : void Cry_HsmDebugMainFunction(void)                     **
**                                                                           **
** Description     : This function doesn't exist in case of synchronous      **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_DEBUG command       **
**                   and closes the session                                  **
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
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
extern void Cry_HsmDebugMainFunction(void);
#endif

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif
/* CRY_HSM_DEBUG_H */
