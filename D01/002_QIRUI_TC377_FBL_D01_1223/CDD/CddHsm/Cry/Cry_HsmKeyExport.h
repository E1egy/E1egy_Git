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
**  FILENAME    : Cry_HsmKeyExport.h                                          **
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
**  DESCRIPTION : This is the corresponding header file for Cry_HsmKeyExport.c**
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
#ifndef CRY_HSM_KEY_EXPORT_H
#define CRY_HSM_KEY_EXPORT_H
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
/** Traceability    : [$Satisfies $CDS_CDRV 412]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmKeyExportConfigType;

/*******************************************************************************
**                      Global Constant variable declarations                 **
*******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmKeyExportConfigType Cry_kHsmKeyExportConfig;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                     Global Function Declaration                            **
*******************************************************************************/
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
extern Csm_ReturnType  Cry_HsmKeyExportStart(const void *CfgPtr,
                           const Csm_SymKeyType *KeyPtr,
                           const Csm_SymKeyType *WrappingKeyPtr);
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
extern Csm_ReturnType  Cry_HsmKeyExportUpdate(const void *CfgPtr,
                           uint8 *DataPtr, uint32 *DataLengthPtr);
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
extern Csm_ReturnType  Cry_HsmKeyExportFinish(const void *CfgPtr);

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 242] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : void Cry_HsmKeyExportMainFunction(void)                  **
**                                                                            **
** Description     : This function doesnt exist in case of synchronous        **
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
extern void Cry_HsmKeyExportMainFunction(void);
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_KEY_EXPORT_H*/
