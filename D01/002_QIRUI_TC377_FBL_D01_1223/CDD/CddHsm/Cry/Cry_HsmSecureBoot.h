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
**  FILENAME    : Cry_HsmSecureBoot.h                                        **
**                                                                           **
**  VERSION     :  1.0.0                                                     **
**                                                                           **
**  DATE        : 2016-12-07                                                 **
**                                                                           **
**  VARIANT     : NA                                                         **
**                                                                           **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                              **
**                [Refer Release Package for Supported Device]               **
**  AUTHOR      : Srinivasa Chakravarthi K                                   **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This is the corresponding header file for                  **
**                Cry_HsmSecureBoot.c file                                   **
**                                                                           **
**  SPECIFICATION(S) :  Aurix_SHE+_TC-CDRV_DS.docx                           **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
#ifndef CRY_HSM_SECURE_BOOT_H
#define CRY_HSM_SECURE_BOOT_H
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
#include "Cry_HsmTypes.h"
#if (CRY_HSM_SECURE_BOOT == STD_ON)
/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/

/******************************************************************************
**                     Global Type Definition                                **
******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 403]                              **
*******************************************************************************/

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/

/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/

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
extern Csm_ReturnType Cry_HsmSheBootFailure(void);
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
extern Csm_ReturnType Cry_HsmSheBootOk(void);

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
extern void Cry_HsmBootFailureMainFunction(void);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 731] [$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          : void Cry_HsmBootOkMainFunction(void)                    **
**                                                                           **
** Description     : In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_BOOT_OK command and **
**                   closes the session                                      **
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
extern void Cry_HsmBootOkMainFunction(void);
#endif
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
#endif
#endif
/* CRY_HSM_SECURE_BOOT_H */
