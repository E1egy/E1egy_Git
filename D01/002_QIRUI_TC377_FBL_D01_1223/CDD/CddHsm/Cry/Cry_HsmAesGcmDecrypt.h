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
**  FILENAME   : Cry_HsmAesGcmDecrypt.h                                      **
**                                                                           **
**  VERSION :   1.0.0                                                        **
**                                                                           **
**  DATE       : 2016-12-28                                                  **
**                                                                           **
**  VARIANT   : NA                                                           **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR      : Sandeep H                                                  **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This is the corresponding header file for                  **
**                Cry_HsmAesGcmDecrypt.c file                                **
**                                                                           **
**  SPECIFICATION(S) :  Aurix_SHE+_TC-CDRV_DS.docx                           **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*
<IFX_RCH>
</IFX_RCH>
*/
#ifndef CRY_HSM_GCM_DECRYPT_H
#define CRY_HSM_GCM_DECRYPT_H

/*****************************************************************************
**                      Includes                                            **
*****************************************************************************/
#include "Cry_HsmTypes.h"
#include "Cry_Hsm_PrivCfg.h"
/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 658] [$Satisfies $CDS_CDRV 659]  **
 **                   [$Satisfies $CDS_CDRV 660] [$Satisfies $CDS_CDRV 661]  **
 **                   [$Satisfies $CDS_CDRV 743]                             **
******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmAesGcmDecryptConfigType;
/****************************************************************************
**                     Global Structure Definition                         **
*****************************************************************************/
/** Traceability    :                                                       **
*****************************************************************************/

/*****************************************************************************
**                     Global Constant variable declarations                **
******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmAesGcmDecryptConfigType Cry_kHsmAesGcmDecryptConfig;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 650]                               **
** Syntax          : Csm_ReturnType Cry_HsmAesGcmDecryptStart(               **
**                      const void *CfgPtr, const Csm_SymKeyType *KeyPtr,    **
**                      const uint8 *InitVectorPtr, uint32 InitVectorLength) **
**                                                                           **
** Description     :This function opens a session on CRY for GCM Decryption  **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_GCM_DECRYPT_START                       **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr          :Pointer to configuration structure of  **
**                                    Cry_HsmAesGcmDecryptConfigType         **
**                   KeyPtr          :Pointer to key structure of            **
**                                    Csm_SymKeyType                         **
**                   InitVectorPtr   :Pointer to initialization vector which **
**                                    will be used during GCM                **
**                                    decryption                             **
**                   InitVectorLength:Length of initialization vector        **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK    :Request successful                         **
**                   CSM_E_BUSY  :Request failed due to underlying HSM       **
**                                communication is busy                      **
**                   CSM_E_NOT_OK:Request failed                             **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType Cry_HsmAesGcmDecryptStart(
                                       const void *CfgPtr,
                                       const Csm_SymKeyType *KeyPtr,
                                       const uint8 *InitVectorPtr,
                                       uint32 InitVectorLength);
/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 651]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesGcmDecryptUpdate(             **
**                          const void *CfgPtr, const uint8 *CipherTextPtr,  **
**                          uint32 CipherTextLength, uint8 *PlainTextPtr,    **
**                          uint32 *PlainTextLengthPtr, const uint8* AadPtr, **
**                          uint32 AadLength)                                **
**                                                                           **
** Description     :This function sends request to HSM for GCM decryption    **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr             :Pointer to configuration structure  **
**                                       of Cry_HsmAesGcmDecryptConfigType   **
**                   CipherTextPtr      :Pointer to the cipher text that     **
**                                       shall be decrypted                  **
**                   CipherTextLength   :The length of the Cipher text in    **
**                                       bytes                               **
**                   PlainTextLengthPtr :Pointer to the memory location in   **
**                                       which the length information is     **
**                                       stored                              **
**                   AadPtr             :Pointer to initialization additional**
**                                       authenticated data which will be    **
**                                       used during GCM decryption          **
**                   AadLength          :Length of additional authenticated  **
**                                       data vector (in bytes) which will be**
**                                       used during GCM decryption.         **
**                                                                           **
** Parameters (out): PlainTextPtr       :Pointer to the memory location      **
**                                       which will hold the decrypted text. **
**                   PlainTextLengthPtr:Pointer to the memory location       **
**                                       in which the length information is  **
**                                       stored. When the request has        **
**                                       finished, the actual length of the  **
**                                       returned decrypted text will be     **
**                                       stored.                             **
**                                                                           **
** Return value    : CSM_E_OK          :Request successful                   **
**                   CSM_E_BUSY        :Request failed due to underlying HSM **
**                                      communication is busy                **
**                   CSM_E_SMALL_BUFFER:Request failed due to too small      **
**                                      buffer provided                      **
**                   CSM_E_NOT_OK      :Request failed                       **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesGcmDecryptUpdate(
                             const void *CfgPtr, const uint8 *CipherTextPtr,
                             uint32 CipherTextLength, uint8 *PlainTextPtr,
                             uint32  *PlainTextLengthPtr, const uint8* AadPtr,
                             uint32 AadLength);
/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 652]                               **
** Syntax          : Csm_ReturnType Cry_HsmAesGcmDecryptFinish(              **
**                                  const void *CfgPtr,                      **
**                                  Csm_VerifyResultType *AuthTagResultPtr,  **
**                                  const uint8 *AuthTagPtr,                 **
**                                  uint32 AuthTagLen)                       **
**                                                                           **
** Description     : This function finalizes calculation and closes the      **
**                   session that was called for GCM decryption              **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_GCM_DECRYPT_FINISH                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr             :Pointer to configuration structure  **
**                                       of Cry_HsmAesGcmDecryptConfigType   **
**                   AuthTagPtr         :This parameter shall contain the    **
**                                       input authentication tag to be      **
**                                       compared                            **
**                   AuthtagLen         :Number of authetication tag bytes   **
**                                       to be compared                      **
** Parameters (out): AuthTagResultPtr   :Result of authentication tag        **
**                                       comparison                          **
**                                                                           **
** Return value    : CSM_E_OK     :Request successful                        **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK :Request failed                            **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesGcmDecryptFinish( const void *CfgPtr,
                                     Csm_VerifyResultType *AuthTagResultPtr,
                                     const uint8 *AuthTagPtr,
                                     uint32 AuthTagLen);
/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 653]                               **
**                                                                           **
** Syntax          :  void Cry_HsmAesGcmDecryptMainFunction(void)            **
**                                                                           **
** Description     : This function doesnt exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_AES_DECRYPT_UPDATE  **
**                   and HSMCOM_CMD_AES_GCM_DECRYPT_FINISH commands          **
**                   and closes the session.                                 **
**                                                                           **
** Service ID      : NA                                                      **
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
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
extern void Cry_HsmAesGcmDecryptMainFunction(void);
#endif


#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_AES_GCM_DECRYPT_H */
