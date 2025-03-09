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
**  FILENAME    : Cry_HsmAesEcbEncrypt.h                                      **
**                                                                            **
**  VERSION     : 3.0.0                                                       **
**                                                                            **
**  DATE        : 2018-06-13                                                  **
**                                                                            **
**  VARIANT     : NA                                                          **
**                                                                            **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                               **
**                [Refer Release Package for Supported Device]                **
**  AUTHOR      : Prashant K                                                  **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This is the header file corresponding to                    **
**                    Cry_HsmAesEcbEncrypt.c                                  **
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
#ifndef CRY_HSM_AES_ECB_ENCRYPT_H
#define CRY_HSM_AES_ECB_ENCRYPT_H
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
/** Traceability    : [$Satisfies $CDS_CDRV 408]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmAesEcbEncryptConfigType;

/*******************************************************************************
**                      Global Constant variable declarations                 **
*******************************************************************************/
#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmAesEcbEncryptConfigType Cry_kHsmAesEcbEncryptConfig;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
#else
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"

extern Cry_HsmAesEcbEncryptConfigType Cry_kHsmAesEcbEncryptConfig;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"
#endif

#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_CODE
#else
#define CRY_START_SEC_RAMCODE
#endif
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 129] [$Satisfies $CDS_CDRV 130]    **
**                   [$Satisfies $CDS_CDRV 131] [$Satisfies $CDS_CDRV 132]    **
**                   [$Satisfies $CDS_CDRV 133] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType Cry_HsmAesEcbEncryptStart(                **
**                                            const void *CfgPtr,             **
**                                            const Csm_SymKeyType *KeyPtr)   **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbEncryptStart for   **
**                   Csm_SymBlockEncryptStart service. It reserves and        **
**                   initializes resources for Csm_SymBlockEncrypt service    **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_ENCRYPT_START                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmAesEcbEncryptConfigType                  **
**                   KeyPtr - Pointer to key structure of Csm_SymKeyType. This**
**                            key has to be used during the symmetrical ECB   **
**                            encryption operation                            **
**                            1. KeyPtr->length shall be 1                    **
**                            2. KeyPtr->data[0] shall be a value taken       **
**                            from Cry_HsmKeySlotIdType and is used to        **
**                            calculate global key address                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesEcbEncryptStart(const void *CfgPtr,
                     const Csm_SymKeyType *KeyPtr);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 134] [$Satisfies $CDS_CDRV 135]    **
**                   [$Satisfies $CDS_CDRV 136] [$Satisfies $CDS_CDRV 137]    **
**                   [$Satisfies $CDS_CDRV 138] [$Satisfies $CDS_CDRV 139]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesEcbEncryptUpdate(              **
**                                            const void *CfgPtr,             **
**                                            const uint8 *PlainTextPtr,      **
**                                            uint32 PlainTextLength,         **
**                                            uint8 *CipherTextPtr,           **
**                                            uint32 *CipherTextLengthPtr)    **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbEncryptUpdate for  **
**                   Csm_SymBlockEncryptUpdate service. It sends request to   **
**                   HSM for AES ECB mode encryption.                         **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr              - Pointer to configuration structure **
**                                         of Cry_HsmAesEcbEncryptConfigType  **
**                   PlainTextPtr        - Pointer to the plain text that     **
**                                         shall be encrypted                 **
**                   PlainTextLength     - The length of the plain text in    **
**                                         bytes. It should be 16             **
**                   CipherTextLengthPtr - Pointer to the memory location in  **
**                                         which the length information is    **
**                                         stored.On calling this function    **
**                                         this parameter shall contain the   **
**                                         size of the provided buffer which  **
**                                         should be greater than or equal to **
**                                         the PlainTextLength parameter.     **
**                                                                            **
** Parameters (out): CipherTextPtr       - Pointer to the memory location     **
**                                         which will hold the encrypted text **
**                   CipherTextLengthPtr - Pointer to the memory location in  **
**                                         which the length information is    **
**                                         stored. When the request has       **
**                                         finished, the actual length of the **
**                                         returned encrypted text shall be   **
**                                         stored.                            **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_SMALL_BUFFER - Request failed due to too small     **
**                                         buffer provided                    **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesEcbEncryptUpdate(const void *CfgPtr,
                     const uint8 *PlainTextPtr, uint32 PlainTextLength,
                     uint8 *CipherTextPtr, uint32 *CipherTextLengthPtr);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 140] [$Satisfies $CDS_CDRV 141]    **
**                   [$Satisfies $CDS_CDRV 142] [$Satisfies $CDS_CDRV 143]    **
**                   [$Satisfies $CDS_CDRV 144] [$Satisfies $CDS_CDRV 573]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesEcbEncryptFinish(              **
**                                            const void *CfgPtr,             **
**                                            uint8 *CipherTextPtr,           **
**                                            uint32 *CipherTextLengthPtr)    **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbEncryptFinish for  **
**                   Csm_SymBlockEncryptFinish service. It releases resources **
**                   used by Csm_SymBlockEncrypt service. This function       **
**                   invokes function that closes the HSM communication       **
**                   session.                                                 **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_ENCRYPT_FINISH                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr              - Pointer to configuration structure **
**                                         of Cry_HsmAesEcbEncryptConfigType. **
**                                         This parameter is ignored.         **
**                   CipherTextPtr       - CipherTextPtr is ignored           **
**                   CipherTextLengthPtr - CipherTextLengthPtr is ignored     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM         **
**                               communication is busy                        **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesEcbEncryptFinish(const void *CfgPtr,
                     uint8 *CipherTextPtr, uint32 *CipherTextLengthPtr);

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 145]  [$Satisfies $CDS_CDRV 579]   **
**                                                                            **
** Syntax          : void Cry_HsmAesEcbEncryptMainFunction(void)              **
**                                                                            **
** Description     : This function doesnt exist in case of synchronous        **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON. In case **
**                   of asynchronous operation, this function checks the      **
**                   command response for HSMCOM_CMD_ECB_ENCRYPT command and  **
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
extern void  Cry_HsmAesEcbEncryptMainFunction(void);
#endif
#ifdef CONTROLLER_TC23x
#define CRY_STOP_SEC_CODE
#else
#define CRY_STOP_SEC_RAMCODE
#endif
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h" /* CRY_HSM_AES_ECB_ENCRYPT_H */
#endif
