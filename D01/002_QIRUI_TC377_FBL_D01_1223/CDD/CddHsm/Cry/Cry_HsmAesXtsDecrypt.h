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
**  FILENAME    : Cry_HsmAesXtsDecrypt.h                                      **
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
**                    Cry_HsmAesXtsDecrypt.c                                  **
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
#ifndef CRY_HSM_AES_XTS_DECRYPT_H
#define CRY_HSM_AES_XTS_DECRYPT_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Cry_HsmTypes.h"

/*******************************************************************************
**                     Global Type Definition                                 **
*******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 717]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmAesXtsDecryptConfigType;
/*******************************************************************************
**                      Global Constant variable declarations                 **
*******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmAesXtsDecryptConfigType Cry_kHsmAesXtsDecryptConfig;

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
** Traceability    : [$Satisfies $CDS_CDRV 682] [$Satisfies $CDS_CDRV 683]    **
**                   [$Satisfies $CDS_CDRV 684] [$Satisfies $CDS_CDRV 685]    **
**                   [$Satisfies $CDS_CDRV 686] [$Satisfies $CDS_CDRV 687]    **
**                   [$Satisfies $CDS_CDRV 688] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : Csm_ReturnType Cry_HsmAesXtsDecryptStart(                **
**                                        const void *CfgPtr,                 **
**                                        const Csm_SymKeyType *KeyPtr1,      **
**                                        const Csm_SymKeyType *KeyPtr2,      **
**                                        const uint8 *InitVectorPtr,         **
**                                        uint32 InitVectorLength)            **
**                                                                            **
** Description     : This function implements Cry_HsmAesXtsDecryptStart which **
**                   reserves and initializes resources for XTS service       **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_XTS_DECRYPT_START                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmAesXtsDecryptConfigType                  **
**                   KeyPtr1 - Pointer to key structure of Csm_SymKeyType.This**
**                             key has to be used during the symmetrical XTS  **
**                             Decryption operation                           **
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
**                                      XTS Decryption                        **
**                                      - InitVectorLength shall be 16        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType Cry_HsmAesXtsDecryptStart( const void *CfgPtr,
                                                 const Csm_SymKeyType *KeyPtr1,
                                                 const Csm_SymKeyType *KeyPtr2,
                                                 const uint8 *InitVectorPtr,
                                                 uint32 InitVectorLength);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 689] [$Satisfies $CDS_CDRV 690]    **
**                   [$Satisfies $CDS_CDRV 691] [$Satisfies $CDS_CDRV 692]    **
**                   [$Satisfies $CDS_CDRV 693] [$Satisfies $CDS_CDRV 694]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
**                                                                            **
** Syntax          : Csm_ReturnType  Cry_HsmAesXtsDecryptUpdate(              **
**                                              const void *CfgPtr,           **
**                                              const uint8 *CipherTextPtr,   **
**                                              uint32 CipherTextLength,      **
**                                              uint8 *PlainTextPtr,          **
**                                              uint32 *PlainTextLengthPtr)   **
**                                                                            **
** Description     : This function implements Cry_HsmAesXtsDecryptUpdate which**
**                   sends request to HSM for AES decryption using XTS mode   **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr             - Pointer to configuration structure  **
**                                        of Cry_HsmAesXtsDecryptConfigType   **
**                   CipherTextPtr      - Pointer to the cipher text that     **
**                                        shall be decrypted                  **
**                   CipherTextLength   - The length of the cipher text in    **
**                                        bytes                               **
**                                          - shall be multiple of 16         **
**                                          - last update shall be >=16       **
**                                          - shall be less than or equal to  **
**                                            PlainTextLengthPtr              **
**                   PlainTextLengthPtr - Pointer to the memory location in   **
**                                        which the length information is     **
**                                        stored.On calling this function this**
**                                        parameter shall contain the size of **
**                                        the provided buffer which should be **
**                                        greater than or equal to the        **
**                                        CipherTextLength parameter.         **
**                                                                            **
** Parameters (out): PlainTextPtr       - Pointer to the memory location which**
**                                        will hold the decrypted text        **
**                   PlainTextLengthPtr - Pointer to the memory location in   **
**                                        which the length information is     **
**                                        stored. When the request has        **
**                                        finished, the actual length of the  **
**                                        returned decrypted text shall be    **
**                                        stored                              **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_SMALL_BUFFER - Request failed due to too small     **
**                                         buffer provided                    **
**                   CSM_E_NOT_OK - Request failed                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesXtsDecryptUpdate(const void *CfgPtr,
                       const uint8 *CipherTextPtr, uint32 CipherTextLength,
                       uint8 *PlainTextPtr, uint32 *PlainTextLengthPtr);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 695] [$Satisfies $CDS_CDRV 696]    **
**                   [$Satisfies $CDS_CDRV 697] [$Satisfies $CDS_CDRV 698]    **
**                   [$Satisfies $CDS_CDRV 699] [$Satisfies $CDS_CDRV 700]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
**                                                                            **
** Syntax          : Csm_ReturnType  Cry_HsmAesXtsDecryptFinish(              **
**                                          const void *CfgPtr,               **
**                                          uint8 *PlainTextPtr,              **
**                                          uint32 *PlainTextLengthPtr)       **
**                                                                            **
** Description     : This function implements Cry_HsmAesXtsDecryptFinish which**
**                   releases resources used by AES XTS mode.                 **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_XTS_DECRYPT_FINISH                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr             - Pointer to configuration structure  **
**                                        of Cry_HsmAesXtsDecryptConfigType.  **
**                   PlainTextPtr       - PlainTextPtr is ignored             **
**                   PlainTextLengthPtr - PlainTextLengthPtr is ignored       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM         **
**                               communication is busy                        **
**                   CSM_E_NOT_OK - Request failed                            **
**                                                                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesXtsDecryptFinish(const void *CfgPtr,
                        uint8 *PlainTextPtr, uint32 *PlainTextLengthPtr);

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 701]  [$Satisfies $CDS_CDRV 579]   **
**                                                                            **
** Syntax          : void Cry_HsmAesXtsDecryptMainFunction(void)              **
**                                                                            **
** Description     : This function doesnt exist in case of synchronous        **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON. In case **
**                   of asynchronous operation, this function checks the      **
**                   command response for XTS decryption commands and         **
**                   closes the session                                       **
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
extern void Cry_HsmAesXtsDecryptMainFunction(void);
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_AES_XTS_DECRYPT_H */
