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
**  FILENAME   : Cry_HsmAesDecrypt.h                                         **
**                                                                           **
**  VERSION :   3.0.0                                                        **
**                                                                           **
**  DATE       : 2018-06-13                                                  **
**                                                                           **
**  VARIANT   : NA                                                           **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR      : Prashant K                                                 **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This is the corresponding header file for                  **
**                Cry_HsmAesDecrypt.c file                                   **
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
#ifndef CRY_HSM_AES_DECRYPT_H
#define CRY_HSM_AES_DECRYPT_H

/*****************************************************************************
**                      Includes                                            **
*****************************************************************************/
#include "Cry_HsmTypes.h"
#include "Cry_Hsm_PrivCfg.h"
/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/

/****************************************************************************
**                     Global Structure Definition                         **
*****************************************************************************/
/** Traceability    :                                                       **
*****************************************************************************/
typedef struct
{
    Cry_HsmAesModeType Mode;    /**< \brief Specifies the AES operation mode */
    Cry_HsmTimeoutType TimeOut; /**< \brief Timeout configuration */
} Cry_HsmAesDecryptConfigType;

/*****************************************************************************
**                     Global Constant variable declarations                **
******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
#ifdef CONTROLLER_TC23x
extern const Cry_HsmAesDecryptConfigType Cry_kHsmAesDecryptConfigModeCbc;
extern const Cry_HsmAesDecryptConfigType Cry_kHsmAesDecryptConfigModeCtr;
extern const Cry_HsmAesDecryptConfigType Cry_kHsmAesDecryptConfigModeOfb;
extern const Cry_HsmAesDecryptConfigType Cry_kHsmAesDecryptConfigModeCfb;
#endif
extern const Cry_HsmAesDecryptConfigType Cry_kHsmAesDecryptConfigModeXts;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/
#ifndef CONTROLLER_TC23x
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"
extern Cry_HsmAesDecryptConfigType Cry_kHsmAesDecryptConfigModeCbc;
extern Cry_HsmAesDecryptConfigType Cry_kHsmAesDecryptConfigModeCtr;
extern Cry_HsmAesDecryptConfigType Cry_kHsmAesDecryptConfigModeOfb;
extern Cry_HsmAesDecryptConfigType Cry_kHsmAesDecryptConfigModeCfb;
#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"
#endif
/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/

#ifdef CONTROLLER_TC23x
#define CRY_START_SEC_CODE
#else
#define CRY_START_SEC_RAMCODE
#endif
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 109] [$Satisfies $CDS_CDRV 110]   **
**                   [$Satisfies $CDS_CDRV 111] [$Satisfies $CDS_CDRV 112]   **
**                   [$Satisfies $CDS_CDRV 113] [$Satisfies $CDS_CDRV 114]   **
**                   [$Satisfies $CDS_CDRV 115] [$Satisfies $CDS_CDRV 579]   **
** Syntax          : Csm_ReturnType Cry_HsmAesDecryptStart(                  **
**                      const void *CfgPtr, const Csm_SymKeyType *KeyPtr,    **
**                      const uint8 *InitVectorPtr, uint32 InitVectorLength) **
**                                                                           **
** Description     :This function implements Cry_HsmAesDecryptStart for      **
**                  Csm_SymDecryptStart service. It reserves and initializes **
**                  resources for Csm_SymDecrypt service.                    **
**                                                                           **
**                                                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_DECRYPT_START                           **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr          :Pointer to configuration structure of  **
**                                    Cry_HsmAesDecryptConfigType            **
**                   KeyPtr          :Pointer to key structure of            **
**                                    Csm_SymKeyType                         **
**                   InitVectorPtr   :Pointer to initialization vector which **
**                                    will be used during symmetrical        **
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
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesDecryptStart(const void *CfgPtr,
                     const Csm_SymKeyType *KeyPtr, const uint8 *InitVectorPtr,
                     uint32 InitVectorLength);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 116] [$Satisfies $CDS_CDRV 117]   **
**                   [$Satisfies $CDS_CDRV 118] [$Satisfies $CDS_CDRV 119]   **
**                   [$Satisfies $CDS_CDRV 120] [$Satisfies $CDS_CDRV 121]   **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType  Cry_HsmAesDecryptUpdate(                **
**                          const void *CfgPtr, const uint8 *CipherTextPtr,  **
**                          uint32 CipherTextLength, uint8 *PlainTextPtr,    **
**                          uint32 *PlainTextLengthPtr)                      **
**                                                                           **
** Description     : This function implements Cry_HsmAesDecryptUpdate for    **
**                   Csm_SymDecryptUpdate service. It sends request to HSM   **
**                  for AES decryption using mode specified by HsmCom_AesMode**
**                   enum type.                                              **
**                                                                           **
**                                                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_DECRYPT_UPDATE                          **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr            :Pointer to configuration structure of**
**                                      Cry_HsmAesDecryptConfigType          **
**                   CipherTextPtr     :Pointer to the cipher text that shall**
**                                      be decrypted                         **
**                   CipherTextLength  :The length of cipher text in bytes   **
**                   PlainTextLengthPtr:Pointer to the memory location in    **
**                                   which the length information is stored. **
**                                                                           **
** Parameters (out): PlainTextPtr      :Pointer to the memory location which **
**                                      will hold the decrypted text         **
**                   PlainTextLengthPtr:Pointer to the memory location in    **
**                                      which the length information is      **
**                                      stored.                              **
**                                                                           **
** Return value    : CSM_E_OK          :Request successful                   **
**                   CSM_E_BUSY        :Request failed due to underlying HSM **
**                                      communication is busy                **
**                   CSM_E_SMALL_BUFFER:Request failed due to too small      **
**                                      buffer provided                      **
**                   CSM_E_NOT_OK      :Request failed                       **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesDecryptUpdate(const void *CfgPtr,
                     const uint8 *CipherTextPtr, uint32 CipherTextLength,
                     uint8 *PlainTextPtr, uint32 *PlainTextLengthPtr);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 122] [$Satisfies $CDS_CDRV 123]   **
**                   [$Satisfies $CDS_CDRV 124] [$Satisfies $CDS_CDRV 125]   **
**                   [$Satisfies $CDS_CDRV 126] [$Satisfies $CDS_CDRV 127]   **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType Cry_HsmAesDecryptFinish(                 **
**      const void *CfgPtr, uint8 *PlainTextPtr, uint32 *PlainTextLengthPtr) **
**                                                                           **
** Description     : This function implements Cry_HsmAesDecryptFinish for    **
**                   Csm_ SymDecryptFinish service. It releases resources    **
**                   used by Csm_SymDecrypt service.                         **
**                                                                           **
**                                                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_DECRYPT_FINISH                          **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr            :Pointer to configuration structure of**
**                                      Cry_HsmAesEncryptConfigType          **
**                   PlainTextPtr      :This parameter is ignored            **
**                   PlainTextLengthPtr:This parameter is ignored            **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK     :Request successful                        **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK :Request failed                            **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesDecryptFinish(const void *CfgPtr,
                      uint8 *PlainTextPtr, uint32 *PlainTextLengthPtr);


/******************************************************************************
** Traceability    :  [$Satisfies $CDS_CDRV 128][$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          :  void Cry_HsmAesDecryptMainFunction(void)               **
**                                                                           **
** Description     : This function doesnt exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_AES_DECRYPT_UPDATE  **
**                   and HSMCOM_CMD_AES_DECRYPT_FINISH commands and closes   **
**                   the session.                                            **
**                                                                           **
**                                                                           **
**                                                                           **
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
extern void  Cry_HsmAesDecryptMainFunction(void);
#endif

#ifdef CONTROLLER_TC23x
#define CRY_STOP_SEC_CODE
#else
#define CRY_STOP_SEC_RAMCODE
#endif
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_AES_DECRYPT_H */
