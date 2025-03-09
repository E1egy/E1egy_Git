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
**  FILENAME   : Cry_HsmAesEncrypt.h                                         **
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
**                Cry_HsmAesEncrypt.c file                                   **
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
#ifndef CRY_HSM_AES_ENCRYPT_H
#define CRY_HSM_AES_ENCRYPT_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_HsmTypes.h"
#include "Cry_Hsm_PrivCfg.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*****************************************************************************
**                     Global Structure Definition                          **
*****************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 406]                              **
*******************************************************************************/
typedef struct
{
  Cry_HsmAesModeType Mode;      /* \brief Specifies the AES operation mode */
  Cry_HsmTimeoutType TimeOut;   /* \brief Timeout configuration */
}Cry_HsmAesEncryptConfigType;

/*****************************************************************************
**                     Global Constant variable declarations                **
*****************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/* Only Mode CBC is currently supported */
#ifdef CONTROLLER_TC23x
extern const Cry_HsmAesEncryptConfigType Cry_kHsmAesEncryptConfigModeCbc;
extern const Cry_HsmAesEncryptConfigType Cry_kHsmAesEncryptConfigModeCtr;
extern const Cry_HsmAesEncryptConfigType Cry_kHsmAesEncryptConfigModeOfb;
extern const Cry_HsmAesEncryptConfigType Cry_kHsmAesEncryptConfigModeCfb;
#endif
extern const Cry_HsmAesEncryptConfigType Cry_kHsmAesEncryptConfigModeXts;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#ifndef CONTROLLER_TC23x
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"

/* Only Mode CBC is currently supported */
extern Cry_HsmAesEncryptConfigType Cry_kHsmAesEncryptConfigModeCbc;
extern Cry_HsmAesEncryptConfigType Cry_kHsmAesEncryptConfigModeCtr;
extern Cry_HsmAesEncryptConfigType Cry_kHsmAesEncryptConfigModeOfb;
extern Cry_HsmAesEncryptConfigType Cry_kHsmAesEncryptConfigModeCfb;

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
** Traceability    : [$Satisfies $CDS_CDRV 89] [$Satisfies $CDS_CDRV 90]     **
**                   [$Satisfies $CDS_CDRV 91] [$Satisfies $CDS_CDRV 92]     **
**                   [$Satisfies $CDS_CDRV 93] [$Satisfies $CDS_CDRV 94]     **
**                   [$Satisfies $CDS_CDRV 95] [$Satisfies $CDS_CDRV 579]    **
** Syntax          :Csm_ReturnType Cry_HsmAesEncryptStart(                   **
**                      const void *CfgPtr,const Csm_SymKeyType *KeyPtr,     **
**                       const uint8 *InitVectorPtr,uint32 InitVectorLength) **
**                                                                           **
** Description     :This function implements Cry_HsmAesEncryptStart for      **
**                  Csm_SymEncryptStart service. It reserves and initializes **
**                  resources for Csm_SymEncrypt service.                    **
**                                                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_ENCRYPT_START                           **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr           :Pointer to configuration structure of **
**                                     Cry_HsmAesEncryptConfigType           **
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
**                                                                           **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesEncryptStart(const void *CfgPtr,
                    const Csm_SymKeyType *KeyPtr, const uint8 *InitVectorPtr,
                    uint32 InitVectorLength);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 96] [$Satisfies $CDS_CDRV 97]     **
**                   [$Satisfies $CDS_CDRV 98] [$Satisfies $CDS_CDRV 99]     **
**                   [$Satisfies $CDS_CDRV 100] [$Satisfies $CDS_CDRV 101]   **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType  Cry_HsmAesEncryptUpdate(                **
**                      const void *CfgPtr,const uint8 *PlainTextPtr,        **
**                            uint32 PlainTextLength, uint8 *CipherTextPtr,  **
**                                        uint32 *CipherTextLengthPtr)       **
**                                                                           **
** Description     :This function implements Cry_HsmAesEncryptUpdate for     **
**                   Csm_SymEncryptUpdate service. It sends request to HSM   **
**                  for AES encryption using mode specified by HsmCom_AesMode**
**                  enum type.                                               **
**                                                                           **
**                                                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_ENCRYPT_UPDATE                          **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr             :Pointer to configuration structure  **
**                                       of Cry_HsmAesEncryptConfigType      **
**                   PlainTextPtr       :Pointer to the plain text that shall**
**                                       be encrypted                        **
**                   PlainTextLength    :The length of the plain text in     **
**                                       bytes                               **
**                   CipherTextLengthPtr:Pointer to the memory location in   **
**                                       which the length information is     **
**                                       stored                              **
**                                                                           **
** Parameters (out): CipherTextPtr      :Pointer to the memory location      **
**                                       which will hold the encrypted text. **
**                   CipherTextLengthPtr:Pointer to the memory location      **
**                                       in which the length information is  **
**                                       stored                              **
**                                                                           **
** Return value    : CSM_E_OK          :Request successful                   **
**                   CSM_E_BUSY        :Request failed due to underlying HSM **
**                                      communication is busy                **
**                   CSM_E_SMALL_BUFFER:Request failed due to too small      **
**                                      buffer provided                      **
**                   CSM_E_NOT_OK      :Request failed                       **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesEncryptUpdate(const void *CfgPtr,
                     const uint8 *PlainTextPtr, uint32 PlainTextLength,
                     uint8 *CipherTextPtr, uint32 *CipherTextLengthPtr);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 102] [$Satisfies $CDS_CDRV 103]   **
**                   [$Satisfies $CDS_CDRV 104] [$Satisfies $CDS_CDRV 105]   **
**                   [$Satisfies $CDS_CDRV 106] [$Satisfies $CDS_CDRV 107]   **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          :  Csm_ReturnType  Cry_HsmAesEncryptFinish(               **
**                      const void *CfgPtr, uint8 *CipherTextPtr,            **
**                              uint32 *CipherTextLengthPtr)                 **
**                                                                           **
** Description     : This function implements Cry_HsmAesEncryptFinish for    **
**                   Csm_ SymEncryptFinish service. It releases resources    **
**                   used by Csm_SymEncrypt service.                         **
**                                                                           **
**                                                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_AES_ENCRYPT_FINISH                          **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr             :Pointer to configuration structure  **
**                                       of Cry_HsmAesEncryptConfigType      **
**                   CipherTextPtr      :This parameter is ignored           **
**                   CipherTextLengthPtr:This parameter is ignored           **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK     :Request successful                        **
**                    CSM_E_BUSY - Request failed as underlying HSM          **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK :Request failed                            **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesEncryptFinish(const void *CfgPtr,
                    uint8 *CipherTextPtr, uint32 *CipherTextLengthPtr);


/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 108] [$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          : void Cry_HsmAesEncryptMainFunction(void)                **
**                                                                           **
** Description     : This function doesnt exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_AES_ENCRYPT_UPDATE  **
**                   and HSMCOM_CMD_AES_ENCRYPT_FINISH commands and closes   **
**                   the session.                                            **
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
extern void  Cry_HsmAesEncryptMainFunction(void);
#endif

#ifdef CONTROLLER_TC23x
#define CRY_STOP_SEC_CODE
#else
#define CRY_STOP_SEC_RAMCODE
#endif
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_AES_ENCRYPT_H */
