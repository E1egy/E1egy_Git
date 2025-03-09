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
**  FILENAME   : Cry_HsmGcmEncrypt.h                                         **
**                                                                           **
**  VERSION :   1.0.0                                                        **
**                                                                           **
**  DATE       : 2016-12-27                                                  **
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
**                Cry_HsmAesGcmEncrypt.c file                                **
**                                                                           **
**  SPECIFICATION(S) :  Aurix_SHE+_TC-CDRV_DS.docx                           **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
/******************************************************************************
**                      Revision Control History                              *
******************************************************************************/
/*
<IFX_RCH>
</IFX_RCH>
*/
#ifndef CRY_HSM_GCM_ENCRYPT_H
#define CRY_HSM_GCM_ENCRYPT_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_HsmTypes.h"
#include "Cry_Hsm_PrivCfg.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 654] [$Satisfies $CDS_CDRV 655]   **
 **                   [$Satisfies $CDS_CDRV 656] [$Satisfies $CDS_CDRV 657]   **
 **                   [$Satisfies $CDS_CDRV 742]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmAesGcmEncryptConfigType;
/******************************************************************************
**                     Global Structure Definition                           **
*****************************************************************************/

/*****************************************************************************
**                     Global Constant variable declarations                **
*****************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmAesGcmEncryptConfigType Cry_kHsmAesGcmEncryptConfig;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 646]                               **
** Syntax          :Csm_ReturnType Cry_HsmAesGcmEncryptStart(                **
**                      const void *CfgPtr,const Csm_SymKeyType *KeyPtr,     **
**                      const uint8 *InitVectorPtr,uint32 InitVectorLength)  **
**                                                                           **
** Description     :This function reserves and initializes resources for     **
**                  GCM encryption                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_GCM_ENCRYPT_START                       **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr           :Pointer to configuration structure of **
**                                     Cry_HsmAesGcmEncryptConfigType        **
**                   KeyPtr           :Pointer to key structure of           **
                                       Csm_SymKeyType                        **
**                   InitVectorPtr    :Pointer to initialization vector      **
**                                     which will be used during symmetrical **
**                                     encryption                            **
**                   InitVectorLength : Length of initialization vector      **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK    :Request successful                         **
**                   CSM_E_BUSY  :Request failed due to underlying HSM       **
**                                communication is busy                      **
**                   CSM_E_NOT_OK:Request failed                             **
******************************************************************************/
extern Csm_ReturnType Cry_HsmAesGcmEncryptStart(
                                       const void *CfgPtr,
                                       const Csm_SymKeyType *KeyPtr,
                                       const uint8 *InitVectorPtr,
                                       uint32 InitVectorLength);
/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 647]                               **
** Syntax          : Csm_ReturnType  Cry_HsmAesGcmEncryptUpdate(             **
**                      const void *CfgPtr, const uint8 *PlainTextPtr,       **
**                      uint32 PlainTextLength, uint8 *CipherTextPtr,        **
**                      uint32 *CipherTextLengthPtr, const uint8 *AadPtr,    **
**                      uint32 AadLength)                                    **
**                                                                           **
** Description     :This function sends request to HSM for GCM encryption    **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_GCM_ENCRYPT_UPDATE                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr             :Pointer to configuration structure  **
**                                       of Cry_HsmAesGcmEncryptConfigType   **
**                   PlainTextPtr       :Pointer to the plain text that shall**
**                                       be encrypted                        **
**                   PlainTextLength    :The length of the plain text in     **
**                                       bytes                               **
**                   CipherTextLengthPtr:Pointer to the memory location in   **
**                                       which the length information is     **
**                                       stored                              **
**                   AadPtr             :Pointer to initialization additional**
**                                       authenticated data which will be    **
**                                       used during symmetrical encryption  **
**                   AadLength          :Length of additional authenticated  **
**                                       data vector (in bytes) which will be**
**                                       used during symmetrical encryption  **
**                                                                           **
** Parameters (out): CipherTextPtr      :Pointer to the memory location      **
**                                       which will hold the encrypted text  **
**                   CipherTextLengthPtr:Pointer to the memory location      **
**                                       in which the length information is  **
**                                       stored. When the request has        **
**                                       finished, the actual length of the  **
**                                       returned encrypted text will be     **
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
extern Csm_ReturnType  Cry_HsmAesGcmEncryptUpdate(
                                         const void *CfgPtr,
                                         const uint8 *PlainTextPtr,
                                         uint32 PlainTextLength,
                                         uint8 *CipherTextPtr,
                                         uint32 *CipherTextLengthPtr,
                                         const uint8* AadPtr,
                                         uint32 AadLength);
/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 648]                               **
** Syntax          :  Csm_ReturnType  Cry_HsmAesGcmEncryptFinish(            **
**                      const void *CfgPtr, uint8 *AuthTagPtr,               **
**                              uint32 *AuthTagLengthPtr)                    **
**                                                                           **
** Description     : This function sends a request to HSM to finalize        **
**                   calculation by passing Authentication tag length and    **
**                   returns the output parameters the calcualted            **
**                   authenticated tag and actual tag length                 **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_GCM_ENCRYPT_FINISH                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr             :Pointer to configuration structure  **
**                                       of Cry_HsmAesGcmEncryptConfigType   **
**                   AuthTagLengthPtr   :This parameter shall contain the    **
**                                       required length of authentication   **
**                                       tag.                                **
**                                                                           **
** Parameters (out): AuthTagPtr         :Calculated authentication tag       **
**                   AuthTagLengthPtr   :When the request has finished,      **
**                                       the actual length of the            **
**                                       authentication tag shall be         **
**                                       returned.                           **
**                                                                           **
** Return value    : CSM_E_OK     :Request successful                        **
**                   CSM_E_BUSY   :Request failed as underlying HSM          **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK :Request failed                            **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesGcmEncryptFinish(
                                        const void *CfgPtr,
                                        uint8 *AuthTagPtr,
                                        uint32 *AuthTagLengthPtr);

/******************************************************************************
** Traceability    :[$Satisfies $CDS_CDRV 649]                               **
**                                                                           **
** Syntax          : void Cry_HsmAesGcmEncryptMainFunction(void)             **
**                                                                           **
** Description     : This function doesn't exist in case of synchronous      **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_GCM_ENCRYPT_UPDATE  **
**                   and HSMCOM_CMD_GCM_ENCRYPT_FINISH commands and closes   **
**                   the session.                                            **
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
extern void Cry_HsmAesGcmEncryptMainFunction(void);
#endif
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_AES_GCM_ENCRYPT_H */
