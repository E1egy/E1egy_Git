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
**  FILENAME    : Cry_HsmKeyLoad.h                                            **
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
**  DESCRIPTION : This is the corresponding header file for Cry_HsmKeyLoad.c  **
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
#ifndef CRY_HSM_KEY_LOAD_H
#define CRY_HSM_KEY_LOAD_H
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
/** Traceability    : [$Satisfies $CDS_CDRV 416]                              **
*******************************************************************************/
typedef enum
{
  CRY_HSM_KEY_PAGE_0,
  CRY_HSM_KEY_PAGE_1
} Cry_HsmKeyPageType;
/** Traceability    : [$Satisfies $CDS_CDRV 411]                              **
*******************************************************************************/
typedef struct
{
  Cry_HsmKeyPageType KeyPage;   /**< \brief Page of key storage   */
  Cry_HsmTimeoutType TimeOut;   /**< \brief Timeout configuration */
} Cry_HsmKeyLoadConfigType;

/*******************************************************************************
**                      Global Constant variable declarations                 **
*******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/* Configuration for accessing CRY_MASTER_ECU_KEY, CRY_BOOT_MAC_KEY,
 * CRY_BOOT_MAC, CRY_HSM_KEY_1,..., CRY_HSM_KEY_10 */
extern const Cry_HsmKeyLoadConfigType Cry_kHsmKeyLoadConfigPage0;

/* Configuration for accessing CRY_HSM_KEY_11,..., CRY_HSM_KEY_20 */
extern const Cry_HsmKeyLoadConfigType Cry_kHsmKeyLoadConfigPage1;

/* Configuration for accessing CRY_HSM_RAM_KEY */
extern const Cry_HsmKeyLoadConfigType Cry_kHsmKeyLoadConfigRamKey;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                     Global Function Declaration                            **
*******************************************************************************/
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 183] [$Satisfies $CDS_CDRV 184]    **
**                   [$Satisfies $CDS_CDRV 185] [$Satisfies $CDS_CDRV 186]    **
**                   [$Satisfies $CDS_CDRV 187] [$Satisfies $CDS_CDRV 293]    **
**                   [$Satisfies $CDS_CDRV 294] [$Satisfies $CDS_CDRV 295]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType Cry_HsmKeyLoadStart(const void *CfgPtr)   **
**                                                                            **
** Description     : This function implements Cry_HsmKeyLoadStart for         **
**                   Csm_KeyExtractStart service. It reserves and             **
**                   initializes resources for Csm_SymKeyExtract service      **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_START                               **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmKeyLoadConfigType                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmKeyLoadStart(const void *CfgPtr);

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 195] [$Satisfies $CDS_CDRV 196]    **
**                   [$Satisfies $CDS_CDRV 197] [$Satisfies $CDS_CDRV 198]    **
**                   [$Satisfies $CDS_CDRV 199] [$Satisfies $CDS_CDRV 220]    **
**                   [$Satisfies $CDS_CDRV 221] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType Cry_HsmKeyLoadFinish(                     **
**                           const void *CfgPtr, Csm_SymKeyType *KeyPtr)      **
**                                                                            **
** Description     :This function implements Cry_HsmKeyLoadFinish for         **
**                  Csm_KeyExtractFinish service. It releases resources used  **
**                  by Csm_SymKeyExtract service.This function copies M4 and  **
**                  M5 data to KeyPtr->data parameter. Cry_HsmKeyLoadFinish   **
**                  function then invokes the function that closes the HSM    **
**                  communication session                                     **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_FINISH                              **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmKeyLoadConfigType                        **
**                   KeyPtr - Pointer to key structure of Csm_SymKeyType.     **
**                            This pointer is used for storing M4 and M5      **
**                            data. Upon successful operation:                **
**                            1. KeyPtr->length will be set to 48 (bytes)     **
**                            2. KeyPtr->data will contain M4 and M5          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM         **
**                               communication is busy                        **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType Cry_HsmKeyLoadFinish(
        const void *CfgPtr, Csm_SymKeyType *KeyPtr);

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Inclusion of MemMap.h is allowed
 after code segment*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 189]                               **
**                   [$Satisfies $CDS_CDRV 190] [$Satisfies $CDS_CDRV 191]    **
**                   [$Satisfies $CDS_CDRV 192] [$Satisfies $CDS_CDRV 193]    **
**                   [$Satisfies $CDS_CDRV 194] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType  Cry_HsmKeyLoadUpdate(                    **
**                                                  const void *CfgPtr,       **
**                                                  const uint8 *DataPtr,     **
**                                                  uint32 DataLength)        **
**                                                                            **
** Description     : This function implements Cry_HsmKeyLoadUpdate for        **
**                   Csm_KeyExtractUpdate service. It sends request to HSM    **
**                   to load a protected key into one of the key slots of     **
**                   the HSM SHE                                              **
**                                                                            **
** Service ID      : CRY_HSM_SID_KEY_LOAD_UPDATE                              **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr     -  Pointer to configuration structure of      **
**                                 Cry_HsmKeyLoadConfigType                   **
**                   DataPtr    -  Pointer to data block, which represents the**
**                                 protected key that will be loaded into the **
**                                 volatile or non-volatile key slot of the   **
**                                 HSM SHE. It contains M1, M2 and M3 data,   **
**                                 as per SHE specification. The M1, M2 and   **
**                                 M3 are stored sequentially                 **
**                    DataLength - The length of M1, M2 and M3 in bytes.      **
**                                 This value shall be 64                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmKeyLoadUpdate(const void *CfgPtr,
                       const uint8 *DataPtr, uint32 DataLength);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 222][$Satisfies $CDS_CDRV 579]     **
**                                                                            **
** Syntax          : void Cry_HsmKeyLoadMainFunction(void)                    **
**                                                                            **
** Description     : This function doesn’t exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.         **
**                   In case of asynchronous operation, this function checks  **
**                   the command response for HSMCOM_CMD_KEY_LOAD command     **
**                   and closes the session                                   **
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
extern void Cry_HsmKeyLoadMainFunction(void);
#endif

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
#endif /* CRY_HSM_KEY_LOAD_H */
