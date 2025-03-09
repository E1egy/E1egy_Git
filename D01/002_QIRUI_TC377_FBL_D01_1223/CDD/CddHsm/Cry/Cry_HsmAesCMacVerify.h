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
**  FILENAME   : Cry_HsmAesCMacVerify.h                                      **
**                                                                           **
**  VERSION    : 5.0.0                                                       **
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
**  SPECIFICATION(S) :  Aurix_SHE+_TC-CDRV_DS.docx                           **
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
#ifndef CRY_HSM_AES_CMAC_VERIFY_H
#define CRY_HSM_AES_CMAC_VERIFY_H
/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_HsmTypes.h"
#include "Cry_Hsm_PrivCfg.h"
/******************************************************************************
**                     Global Type Definition                                **
******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 405]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmAesCMacVerifyConfigType;

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"
extern Cry_HsmAesCMacVerifyConfigType Cry_kHsmAesCMacVerifyConfig;
#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"

/******************************************************************************
**                     Global Structure Definition                           **
******************************************************************************/
#if (CRY_HSM_MAC_SAFE_VERIFY == STD_ON)
/* Additional type for extended CMAC verification algorithm
 * A pointer to this structure must be passed as the resultPtr parameter
 * of the Cry_HsmAesCMacVerifyFinish() function
 * This is an extension/deviation to AUTOSAR
 */
typedef struct
{
     Csm_VerifyResultType   Result;
     uint32 CodedResult1;
     uint32 CodedResult2;
     uint32 DataPtr;
     uint32 DataLength;
     uint16 BitsCompared1;
     uint16 BitsCompared2;
} Csm_SafeVerifyResultType;
#endif

/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 60] [$Satisfies $CDS_CDRV 61]     **
**                   [$Satisfies $CDS_CDRV 62] [$Satisfies $CDS_CDRV 63]     **
**                   [$Satisfies $CDS_CDRV 64] [$Satisfies $CDS_CDRV 65]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType Cry_HsmAesCMacVerifyStart(               **
                        const void *CfgPtr, const Csm_SymKeyType *KeyPtr)    **
**                                                                           **
** Description     : This function implements Cry_HsmAesCMacVerifyStart for  **
**                   Csm_MacVerifyStart service. It reserves and initializes **
**                   resources for Csm_MacVerify service and sends request to**
**                    HSM to initiate CMAC verification.                     **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_VERIFY_START                            **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr- Pointer to configuration structure of           **
**                           Cry_HsmAesCMacVerifyConfigType. This parameter  **
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
**                                                                           **
******************************************************************************/
extern Csm_ReturnType Cry_HsmAesCMacVerifyStart(
        const void *CfgPtr , const Csm_SymKeyType *KeyPtr);

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 66] [$Satisfies $CDS_CDRV 67]     **
**                   [$Satisfies $CDS_CDRV 68] [$Satisfies $CDS_CDRV 69]     **
**                   [$Satisfies $CDS_CDRV 70] [$Satisfies $CDS_CDRV 71]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType Cry_HsmAesCMacVerifyUpdate(              **
**              const void *CfgPtr, const uint8 *DataPtr, uint32 DataLength) **
**                                                                           **
** Description     : This function implements Cry_HsmAesCMacVerifyUpdate for **
**                   Csm_MacVerifyUpdate service. It sends request to HSM to **
**                   update CMAC verification.                               **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_VERIFY_UPDATE                           **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Parameters (in) : CfgPtr-Pointer to configuration structure of            **
**                          Cry_HsmAesCMacVerifyConfigType                  **
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
**                                                                           **
******************************************************************************/
extern Csm_ReturnType Cry_HsmAesCMacVerifyUpdate(const void *CfgPtr,
                         const uint8 *DataPtr, uint32 DataLength);

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 72] [$Satisfies $CDS_CDRV 73]     **
**                   [$Satisfies $CDS_CDRV 74] [$Satisfies $CDS_CDRV 75]     **
**                   [$Satisfies $CDS_CDRV 76] [$Satisfies $CDS_CDRV 77]     **
**                   [$Satisfies $CDS_CDRV 78] [$Satisfies $CDS_CDRV 79]     **
**                   [$Satisfies $CDS_CDRV 80] [$Satisfies $CDS_CDRV 81]     **
**                   [$Satisfies $CDS_CDRV 82] [$Satisfies $CDS_CDRV 83]     **
**                   [$Satisfies $CDS_CDRV 84] [$Satisfies $CDS_CDRV 85]     **
**                   [$Satisfies $CDS_CDRV 86] [$Satisfies $CDS_CDRV 87]     **
**                   [$Satisfies $CDS_CDRV 579] [$Satisfies $CDS_CDRV 741]   **
** Syntax          : Csm_ReturnType  Cry_HsmAesCMacVerifyFinish(             **
**                         const void *CfgPtr, const uint8 *MacPtr,          **
**                         uint32 MacLength, Csm_VerifyResultType *ResultPtr)**
**                                                                           **
** Description     : This function sends request to HSM to finalize CMAC     **
**                   verification.                                           **
**                                                                           **
** Service ID      : CRY_HSM_SID_MAC_VERIFY_FINISH                           **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr- Pointer to configuration structure of           **
**                           Cry_HsmAesCMacVerifyConfigType                  **
**                   MacPtr- Pointer to the memory location which hold the   **
**                           MAC to verify.                                  **
**                   MacLength- The length (in bits) of the MAC to be        **
**                              verified                                     **
**                                                                           **
** Parameters (out): ResultPtr- Pointer to the memory location which will    **
**                    hold the result of the MAC verification.               **
**                    In a QM configuration the content is:                  **
**                    1. CSM_E_VER_OK: verification pass                     **
**                    2. CSM_E_VER_NOT_OK: verification fail                 **
                      In a safety configuration the content of the structure **
                      is enhanced to include additional data allowing the    **
                      upper layer to detect possible faults:                 **
**                    1. Result: same as AUTOSAR standard                    **
**                    2. CodedResult1: Coded result (CMAC) if the check is   **
**                    successful (cf. safety concept). Otherwise 0           **
**                    3. CodedResult2: Coded result (~CMAC) if the check is  **
**                      successful (cf. safety concept). Otherwise 0         **
**                    4. BitsCompared1 according to safety concept           **
**                    5. BitsCompared2 according to safety concept           **
**                    6. DataLength: data length value according to safety   **
**                       concept                                             **
**                    7. Coding of data pointer for verified                 **
**                       message, cf. safety concept                         **
**                                                                           **
** Return value    : CSM_E_OK- Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK- Request failed                            **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmAesCMacVerifyFinish(
        const void *CfgPtr, const uint8 *MacPtr,
        uint32 MacLength, Csm_VerifyResultType *ResultPtr);

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 88] [$Satisfies $CDS_CDRV 579]    **
**                                                                           **
** Syntax          : void Cry_HsmAesCMacVerifyMainFunction(void)             **
**                                                                           **
** Description     : This function doesnt exist in case of synchronous       **
**                   operation CRY_HSM_USE_SYNC_PROCESSING == STD_ON.        **
**                   In case of asynchronous operation:                      **
**                   This function checks the command response for           **
**                   HSMCOM_CMD_MAC_VER_UPDATE command.                      **
**                   If CryHsmSafeMacVerify == FALSE (safety concept not     **
**                   required to be supported), the function checks the      **
**                   command response for HSMCOM_CMD_MAC_VER_FINISH command  **
**                   and closes the session.                                 **
**                   If CryHsmSafeMacVerify == TRUE (safety concept is       **
**                   required to be supported), the function checks the      **
**                  command response for HSMCOM_CMD_SAFE_MAC_VER_FINISH_CHECK**
**                   command and closes the session.                         **
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
extern void Cry_HsmAesCMacVerifyMainFunction(void);
#endif

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
**                                                                           **
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmAesCMacVarInit(void)                        **
**                                                                           **
** Description     : This function is  used to initialize MacVerify          **
**                   variables                                               **
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
void Cry_HsmAesCMacVarInit(void);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 243]                              **
**                                                                           **
** Syntax          : void Cry_HsmAesCMacDummyMacVerification(void)           **
**                                                                           **
** Description     : This function is used for updating parameters for       **
**                   dummy MAC verification                                  **
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
extern void Cry_HsmAesCMacDummyMacVerification(void);
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_AES_CMAC_VERIFY_H */
