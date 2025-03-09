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
**  FILENAME    : Cry_HsmAesXtsEncrypt.h                                      **
**                                                                            **
**  VERSION     : 1.0.0                                                       **
**                                                                            **
**  DATE        : 2017-01-13                                                  **
**                                                                            **
**  VARIANT     : NA                                                          **
**                                                                            **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                               **
**                [Refer Release Package for Supported Device]                **
**  AUTHOR      : Srinivasa Chakravarthi K                                    **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This is the header file corresponding to                    **
**                    Cry_HsmAesXtsEncrypt.c                                  **
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
#ifndef CRY_HSM_AES_XTS_ENCRYPT_H
#define CRY_HSM_AES_XTS_ENCRYPT_H
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
/** Traceability    : [$Satisfies $CDS_CDRV 716]                              **
*******************************************************************************/

typedef Cry_HsmBasicConfigType Cry_HsmAesXtsEncryptConfigType;

/*******************************************************************************
**                      Global Constant variable declarations                 **
*******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmAesXtsEncryptConfigType Cry_kHsmAesXtsEncryptConfig;

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
** Traceability    : [$Satisfies $CDS_CDRV 662] [$Satisfies $CDS_CDRV 663]    **
**                   [$Satisfies $CDS_CDRV 664] [$Satisfies $CDS_CDRV 665]    **
**                   [$Satisfies $CDS_CDRV 666] [$Satisfies $CDS_CDRV 667]    **
**                   [$Satisfies $CDS_CDRV 668] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : Csm_ReturnType Cry_HsmAesXtsEncryptStart(                **
**                                        const void *CfgPtr,                 **
**                                        const Csm_SymKeyType *KeyPtr1,      **
**                                        const Csm_SymKeyType *KeyPtr2,      **
**                                        const uint8 *InitVectorPtr,         **
**                                        uint32 InitVectorLength)            **
**                                                                            **
** Description     : This function implements Cry_HsmAesXtsEncryptStart which **
**                   reserves and initializes resources for AES XTS service   **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_XTS_ENCRYPT_START                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmAesXtsEncryptConfigType                  **
**                   KeyPtr1 - Pointer to key structure of Csm_SymKeyType.This**
**                             key has to be used during the symmetrical XTS  **
**                             encryption operation                           **
**                             1) KeyPtr->length shall be 1                   **
**                             2) KeyPtr->data[0] shall be a value taken from **
**                             Cry_HsmKeySlotIdType and is used to calculate  **
**                             global key address                             **
**                   KeyPtr2 - Pointer to key structure of Csm_SymKeyType.This**
**                             will be used only for XTS mode                 **
**                   InitVectorPtr - Pointer to initialization vector which   **
**                                   will be used during symmetrical XTS      **
**                                   encryption                               **
**                   InitVectorLength - Length of initialization vector       **
**                                      which will be used during symmetrical **
**                                      XTS encryption                        **
**                                      - InitVectorLength shall be 16        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType Cry_HsmAesXtsEncryptStart( const void *CfgPtr,
                                                 const Csm_SymKeyType *KeyPtr1,
                                                 const Csm_SymKeyType *KeyPtr2,
                                                 const uint8 *InitVectorPtr,
                                                 uint32 InitVectorLength);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 669] [$Satisfies $CDS_CDRV 670]    **
**                   [$Satisfies $CDS_CDRV 671] [$Satisfies $CDS_CDRV 672]    **
**                   [$Satisfies $CDS_CDRV 673] [$Satisfies $CDS_CDRV 674]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
**                                                                            **
** Syntax          : Csm_ReturnType  Cry_HsmAesXtsEncryptUpdate(              **
**                                            const void *CfgPtr,             **
**                                            const uint8 *PlainTextPtr,      **
**                                            uint32 PlainTextLength,         **
**                                            uint8 *CipherTextPtr,           **
**                                            uint32 *CipherTextLengthPtr)    **
**                                                                            **
** Description     : This function implements Cry_HsmAesXtsEncryptUpdate which**
**                   sends request to HSM for AES encryption using XTS mode   **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_XTS_ENCRYPT_UPDATE                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr              - Pointer to configuration structure **
**                                         of Cry_HsmAesXtsEncryptConfigType  **
**                   PlainTextPtr        - Pointer to the plain text that     **
**                                         shall be encrypted                 **
**                   PlainTextLength     - The length of the plain text in    **
**                                         bytes.                             **
**                                          - shall be multiple of 16         **
**                                          - last update shall be >=16       **
**                                          - shall be less than or equal to  **
**                                            cipherTextLengthPtr             **
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
extern Csm_ReturnType  Cry_HsmAesXtsEncryptUpdate(const void *CfgPtr,
                     const uint8 *PlainTextPtr, uint32 PlainTextLength,
                     uint8 *CipherTextPtr, uint32 *CipherTextLengthPtr);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 675] [$Satisfies $CDS_CDRV 676]    **
**                   [$Satisfies $CDS_CDRV 677] [$Satisfies $CDS_CDRV 678]    **
**                   [$Satisfies $CDS_CDRV 679] [$Satisfies $CDS_CDRV 680]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
**                                                                            **
** Syntax          : Csm_ReturnType  Cry_HsmAesXtsEncryptFinish(              **
**                                            const void *CfgPtr,             **
**                                            uint8 *CipherTextPtr,           **
**                                            uint32 *CipherTextLengthPtr)    **
**                                                                            **
** Description     : This function implements Cry_HsmAesXtsEncryptFinish which**
**                   releases resources used by AES XTS mode.                 **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_XTS_ENCRYPT_FINISH                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr              - Pointer to configuration structure **
**                                         of Cry_HsmAesXtsEncryptConfigType. **
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
extern Csm_ReturnType  Cry_HsmAesXtsEncryptFinish(const void *CfgPtr,
                     uint8 *CipherTextPtr, uint32 *CipherTextLengthPtr);

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 681]  [$Satisfies $CDS_CDRV 579]   **
**                                                                            **
** Syntax          : void Cry_HsmAesXtsEncryptMainFunction(void)              **
**                                                                            **
** Description     : This function doesnt exist in case of synchronous        **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON. In case **
**                   of asynchronous operation, this function checks the      **
**                   command response for XTS encryption commands and closes  **
**                   the session.                                             **
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
extern void  Cry_HsmAesXtsEncryptMainFunction(void);
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_AES_XTS_ENCRYPT_H */
