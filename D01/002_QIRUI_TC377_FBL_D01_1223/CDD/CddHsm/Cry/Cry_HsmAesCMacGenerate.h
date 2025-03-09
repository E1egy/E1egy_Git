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
**  FILENAME   : Cry_HsmAesCMacGenerate.h                                    **
**                                                                           **
**  VERSION    : 3.0.0                                                       **
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
**  DESCRIPTION : This file contains                                         **
**                functionality of Cry module                                **
**                                                                           **
**  SPECIFICATION(S) : Aurix_SHE+_TC-CDRV_DS.docx                            **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
<IFX_RCH>
</IFX_RCH>
*/
#ifndef CRY_HSM_AES_CMAC_GENERATE_H
#define CRY_HSM_AES_CMAC_GENERATE_H
/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_HsmTypes.h"
#include "Cry_Hsm_PrivCfg.h"

/******************************************************************************
**                     Global Type Definition                                **
******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 404]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmAesCMacGenerateConfigType;

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
extern Cry_HsmAesCMacGenerateConfigType Cry_HsmAesCMacGenerateConfig;
#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 41] [$Satisfies $CDS_CDRV 42]     **
**                   [$Satisfies $CDS_CDRV 43] [$Satisfies $CDS_CDRV 44]     **
**                   [$Satisfies $CDS_CDRV 45] [$Satisfies $CDS_CDRV 46]     **
**                   [$Satisfies $CDS_CDRV 579][$Satisfies $CDS_CDRV 600]    **
** Syntax          : Csm_ReturnType Cry_HsmAesCMacGenerateStart(             **
                        const void *CfgPtr, const Csm_SymKeyType *KeyPtr)    **
**                                                                           **
** Description     : This function implements Cry_HsmAesCMacGenerateStart for**
**                 Csm_MacGenerateStart service. It reserves and initializes **
**                 resources for Csm_MacGenerate service and sends request to**
**                  HSM to initiate CMAC generation.                         **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_GENERATE_START                           **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr- Pointer to configuration structure of           **
**                           Cry_HsmAesCMacGenerateConfigType. This parameter**
**                           is ignored.                                     **
**                   KeyPtr-Pointer to key structure of Csm_SymKeyType       **
**                          1. KeyPtr->length shall be 1                     **
**                          2. KeyPtr->data[0] shall be a value taken from   **
**                          Cry_HsmKeySlotIdType and is used to calculate    **
**                          global key address                               **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK- Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK- Request failed                            **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType Cry_HsmAesCMacGenerateStart(
        const void *CfgPtr, const Csm_SymKeyType *KeyPtr);

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 47] [$Satisfies $CDS_CDRV 48]     **
**                   [$Satisfies $CDS_CDRV 49] [$Satisfies $CDS_CDRV 50]     **
**                   [$Satisfies $CDS_CDRV 51] [$Satisfies $CDS_CDRV 52]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType  Cry_HsmAesCMacGenerateUpdate(           **
**              const void *CfgPtr, const uint8 *DataPtr, uint32 DataLength) **
**                                                                           **
** Description     :This function implements Cry_HsmAesCMacGenerateUpdate for**
**                  Csm_MacGenerateUpdate service. It sends request to HSM to**
**                   update CMAC generation.                                 **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_GENERATE_UPDATE                         **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr-Pointer to configuration structure of            **
**                          Cry_HsmAesCMacGenerateConfigType                 **
**                   DataPtr- Pointer to the data for which the MAC shall be **
**                            computed                                       **
**                   DataLength- Number of bytes for which the MAC shall be  **
**                   computed                                                **
**                     1. Only multiple of 16 allowed, for non-final input   **
**                     2. Non-multiple of 16 also allowed, for final input   **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK- Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK- Request failed                            **
**                                                                           **
******************************************************************************/

extern Csm_ReturnType Cry_HsmAesCMacGenerateUpdate(
                const void *CfgPtr,const uint8 *DataPtr, uint32 DataLength);


/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 53] [$Satisfies $CDS_CDRV 54]     **
**                   [$Satisfies $CDS_CDRV 55] [$Satisfies $CDS_CDRV 56]     **
**                   [$Satisfies $CDS_CDRV 57] [$Satisfies $CDS_CDRV 58]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType  Cry_HsmAesCMacGenerateFinish(           **
**                   const void *CfgPtr, uint8 *ResultPtr,                   **
**                   uint32 *ResultLengthPtr, boolean TruncationIsAllowed)   **
**                                                                           **
** Description     : This function implements Cry_HsmAesCMacGenerateFinish   **
                     for Csm_MacGenerateFinish service. It sends request to  **
                     HSM to finalize CMAC generation.                        **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_GENERATE_FINISH                         **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr-Pointer to configuration structure of            **
                            Cry_HsmAesCMacGenerateConfigType                 **
**                   ResultLengthPtr- Pointer to the memory location in which**
**                   the length in byte of the MAC to be returned is stored. **
**                   On calling this function this parameter shall contain a **
**                   size lower or equal to the buffer provided by ResultPtr **
**                   TruncationIsAllowed- Specifies whether a truncation of  **
**                   the result is allowed or not                            **
**                    1. TRUE: truncation is allowed                         **
**                    2. FALSE: truncation is not allowed                    **
**                                                                           **
** Parameters (out): ResultPtr- Pointer to the memory location which will    **
**                    hold the result of the MAC generation. If the generated**
**                    MAC does not fit into the given ResultLength, and      **
**                    truncation is allowed, the result will be truncated.   **
**                   ResultLengthPtr- Pointer to the memory location in which**
**                    the length information is stored.                      **
**                    When the request has finished, the actual length of the**
**                    returned MAC shall be stored. In case of error         **
**                    CSM_E_SMALL_BUFFER the pointer do not need to be       **
**                    updated                                                **
**                                                                           **
** Return value    : CSM_E_OK- Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_SMALL_BUFFER- Request failed due to too small     **
**                                       buffer provided                     **
**                   CSM_E_NOT_OK- Request failed                            **
**                                                                           **
*******************************************************************************/
extern Csm_ReturnType Cry_HsmAesCMacGenerateFinish(
        const void *CfgPtr, uint8 *ResultPtr,
        uint32 *ResultLengthPtr, boolean TruncationIsAllowed);

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 59] [$Satisfies $CDS_CDRV 579]    **
**                                                                           **
** Syntax          : void Cry_HsmAesCMacGenerateMainFunction(void)           **
**                                                                           **
** Description     : This function doesn’t exist in case of synchronous      **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_MAC_GEN_UPDATE and  **
**                   HSMCOM_CMD_MAC_GEN_FINISH commands and closes the       **
**                   session.                                                **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
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
extern void Cry_HsmAesCMacGenerateMainFunction(void);
#endif

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_AES_MAC_GENERATE_H */
