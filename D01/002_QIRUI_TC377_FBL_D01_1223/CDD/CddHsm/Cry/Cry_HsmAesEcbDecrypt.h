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
**  FILENAME    : Cry_HsmAesEcbDecrypt.h                                      **
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
**                    Cry_HsmAesEcbDecrypt.c                                  **
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
#ifndef CRY_HSM_AES_ECB_DECRYPT_H
#define CRY_HSM_AES_ECB_DECRYPT_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Cry_HsmTypes.h"

/*******************************************************************************
**                     Global Type Definition                                 **
*******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 409]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmAesEcbDecryptConfigType;

/*******************************************************************************
**                      Global Constant variable declarations                 **
*******************************************************************************/
#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmAesEcbDecryptConfigType Cry_kHsmAesEcbDecryptConfig;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
#else
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"

extern Cry_HsmAesEcbDecryptConfigType Cry_kHsmAesEcbDecryptConfig;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"
#endif
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                     Global Function Declaration                            **
*******************************************************************************/
#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_CODE
#else
#define CRY_START_SEC_RAMCODE
#endif
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 146] [$Satisfies $CDS_CDRV 147]    **
**                   [$Satisfies $CDS_CDRV 148] [$Satisfies $CDS_CDRV 149]    **
**                   [$Satisfies $CDS_CDRV 150] [$Satisfies $CDS_CDRV 579]    **
** Syntax          :   Csm_ReturnType Cry_HsmAesEcbDecryptStart(              **
**                                             const void *CfgPtr,            **
**                                             const Csm_SymKeyType *KeyPtr)  **
**                                                                            **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbDecryptStart for   **
**                   Csm_SymBlockDecryptStart service. It reserves and        **
**                   initializes resources for Csm_SymBlockDecrypt service    **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_DECRYPT_START                        **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr - Pointer to configuration structure of           **
**                            Cry_HsmAesEcbDecryptConfigType.                 **
**                   KeyPtr - Pointer to key structure of Csm_SymKeyType.     **
**                            This key has to be used during the symmetrical  **
**                            ECB decryption operation                        **
**                            1. KeyPtr->length shall be 1                    **
**                            2. KeyPtr->data[0] shall be a value taken from  **
**                            Cry_HsmKeySlotIdType and is used to calculate   **
**                            global key address                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : CSM_E_OK - Request successful                            **
**                   CSM_E_BUSY - Request failed as underlying HSM            **
**                                 communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                            **
**                                                                            **
*******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesEcbDecryptStart(const void *CfgPtr,
                      const Csm_SymKeyType *KeyPtr);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 151] [$Satisfies $CDS_CDRV 152]    **
**                   [$Satisfies $CDS_CDRV 153] [$Satisfies $CDS_CDRV 154]    **
**                   [$Satisfies $CDS_CDRV 155] [$Satisfies $CDS_CDRV 156]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesEcbDecryptUpdate(              **
**                                              const void *CfgPtr,           **
**                                              const uint8 *CipherTextPtr,   **
**                                              uint32 CipherTextLength,      **
**                                              uint8 *PlainTextPtr,          **
**                                              uint32 *PlainTextLengthPtr)   **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbDecryptUpdate for  **
**                    Csm_SymBlockDecryptUpdate service. It sends request to  **
**                    HSM for AES ECB mode decryption.                        **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr             - Pointer to configuration structure  **
**                                        of Cry_HsmAesEcbDecryptConfigType   **
**                   CipherTextPtr      - Pointer to the cipher text that     **
**                                        shall be decrypted                  **
**                   CipherTextLength   - The length of the cipher text in    **
**                                        bytes that should be 16             **
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
extern Csm_ReturnType  Cry_HsmAesEcbDecryptUpdate(const void *CfgPtr,
                       const uint8 *CipherTextPtr, uint32 CipherTextLength,
                       uint8 *PlainTextPtr, uint32 *PlainTextLengthPtr);
/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 157] [$Satisfies $CDS_CDRV 158]    **
**                   [$Satisfies $CDS_CDRV 159] [$Satisfies $CDS_CDRV 160]    **
**                   [$Satisfies $CDS_CDRV 161] [$Satisfies $CDS_CDRV 162]    **
**                   [$Satisfies $CDS_CDRV 579]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesEcbDecryptFinish(              **
**                                          const void *CfgPtr,               **
**                                          uint8 *PlainTextPtr,              **
**                                          uint32 *PlainTextLengthPtr)       **
**                                                                            **
** Description     : This function implements Cry_HsmAesEcbDecryptFinish for  **
**                   Csm_SymBlockDecryptFinish service. It releases resources **
**                   used by Csm_SymBlockDecrypt service. This function       **
**                   invokes function that closes the HSM communication       **
**                   session                                                  **
**                                                                            **
** Service ID      : CRY_HSM_SID_AES_ECB_DECRYPT_FINISH                       **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : CfgPtr             - Pointer to configuration structure  **
**                                        of Cry_HsmAesEcbDecryptConfigType.  **
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
extern Csm_ReturnType  Cry_HsmAesEcbDecryptFinish(const void *CfgPtr,
                        uint8 *PlainTextPtr, uint32 *PlainTextLengthPtr);

/*******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 163] [$Satisfies $CDS_CDRV 579]    **
**                                                                            **
** Syntax          : void Cry_HsmAesEcbDecryptMainFunction(void)              **
**                                                                            **
** Description     : This function doesnt exist in case of synchronous        **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON. In case **
**                   of asynchronous operation, this function checks the      **
**                   command response for HSMCOM_CMD_ECB_DECRYPT command and  **
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
extern void Cry_HsmAesEcbDecryptMainFunction(void);
#endif

#ifdef CONTROLLER_TC23x
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
#else
#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
#endif

#endif /* CRY_HSM_AES_ECB_DECRYPT_H */
