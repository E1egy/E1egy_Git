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
**  FILENAME    : Cry_HsmKeyLoadPlain.h                                       **
**                                                                            **
**  VERSION     : 3.0.0                                                       **
**                                                                            **
**  DATE        : 2016-07-11                                                  **
**                                                                            **
**  VARIANT     : NA                                                          **
**                                                                            **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                               **
**                [Refer Release Package for Supported Device]                **
**  AUTHOR      :  Trivikram G                                                **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This is the corresponding header file for                   **
**                                      Cry_HsmKeyLoadPlain.c                 **
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
#ifndef CRY_HSM_KEY_LOAD_PLAIN_H
#define CRY_HSM_KEY_LOAD_PLAIN_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Cry_HsmTypes.h"
#include "HsmCom_def.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                     Global Type Definition                                 **
*******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 410]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmLoadPlainConfigType;

/*******************************************************************************
**                      Global Constant variable declarations                 **
*******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmLoadPlainConfigType Cry_kHsmLoadPlainConfig;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                     Global Function Declaration                            **
*******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 164] [$Satisfies $CDS_CDRV 165]    **
**                   [$Satisfies $CDS_CDRV 166] [$Satisfies $CDS_CDRV 167]    **
**                   [$Satisfies $CDS_CDRV 168] [$Satisfies $CDS_CDRV 579]    **
** Syntax          :Csm_ReturnType Cry_HsmKeyLoadPlainStart                   **
**                                                  (const void *CfgPtr)      **
**                                                                            **
** Description     : This function implements Cry_HsmKeyLoadPlainStart for    **
**                   Csm_KeyExtractStart service. It reserves and             **
**                   initializes resources for Csm_SymKeyExtract service      **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_PLAIN_START                         **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmLoadPlainConfigType.                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmKeyLoadPlainStart(
                              const void *CfgPtr);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 169] [$Satisfies $CDS_CDRV 170]    **
**                   [$Satisfies $CDS_CDRV 171] [$Satisfies $CDS_CDRV 172]    **
**                   [$Satisfies $CDS_CDRV 173] [$Satisfies $CDS_CDRV 174]    **
**                   [$Satisfies $CDS_CDRV 175] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType Cry_HsmKeyLoadPlainUpdate(                **
**                                                     const void *CfgPtr,    **
**                                                     const uint8 *DataPtr,  **
**                                                     uint32 DataLength)     **
**                                                                            **
** Description     : This function implements Cry_HsmKeyLoadPlainUpdate for   **
**                   Csm_KeyExtractUpdate service. It sends request to HSM    **
**                   to load a plain key into HSMCOM_RAM_KEY slot             **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr     - Pointer to configuration structure of       **
**                                Cry_HsmLoadPlainConfigType                  **
**                   DataPtr    - Pointer to data block, which represents the **
**                                plain key that will be loaded into the      **
**                                RAM_KEY slot of the HSM SHE                 **
**                   DataLength - The length of the key (data block) in       **
**                                bytes. This value shall be 16               **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmKeyLoadPlainUpdate(
                             const void *CfgPtr,
                             HsmCom_KeyAddr KeyAddr,
                             const uint8 *DataPtr, uint32 DataLength);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 176] [$Satisfies $CDS_CDRV 177]    **
**                   [$Satisfies $CDS_CDRV 178] [$Satisfies $CDS_CDRV 179]    **
**                   [$Satisfies $CDS_CDRV 180] [$Satisfies $CDS_CDRV 181]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType  Cry_HsmKeyLoadPlainFinish(               **
**                                                 const void *CfgPtr,        **
**                                                 Csm_SymKeyType *KeyPtr)    **
**                                                                            **
** Description     : This function implements Cry_HsmKeyLoadPlainFinish for   **
**                   Csm_KeyExtractFinish service. It releases resources      **
**                   used by Csm_SymKeyExtract service. This function         **
**                   invokes function that closes the HSM communication       **
**                   session.                                                 **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_PLAIN_FINISH                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmLoadPlainConfigType                      **
**                   KeyPtr - KeyPtr parameter is ignored                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM         **
**                               communication is busy                        **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmKeyLoadPlainFinish(
                            const void *CfgPtr,
                            Csm_SymKeyType *KeyPtr);

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 182][$Satisfies $CDS_CDRV 579]     **
**                                                                            **
** Syntax          : void Cry_HsmKeyLoadPlainMainFunction(void)               **
**                                                                            **
** Description     : This function doesn’t exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.         **
**                   In case of asynchronous operation, this function checks  **
**                   the command response for HSMCOM_CMD_KEY_LOAD_PLAIN       **
**                   command and closes the session                           **
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
extern void Cry_HsmKeyLoadPlainMainFunction(void);
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_KEY_LOAD_PLAIN_H */
