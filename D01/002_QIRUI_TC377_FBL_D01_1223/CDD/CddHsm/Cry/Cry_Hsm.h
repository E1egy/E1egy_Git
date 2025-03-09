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
**  FILENAME   : Cry_Hsm.h                                                   **
**                                                                           **
**  VERSION    : 5.0.0                                                       **
**                                                                           **
**  DATE       : 2017-06-27                                                  **
**                                                                           **
**  VARIANT    : NA                                                          **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR    : Trivikram G                                                  **
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
#ifndef CRY_HSM_H
#define CRY_HSM_H
/******************************************************************************
**                      Includes                                             **
******************************************************************************/

#include "Cry_Hsm_Cfg.h"
#include "Cry_HsmTypes.h"

#include "Cry_HsmRandomSeedInit.h"
#include "Cry_HsmRandomSeedExtend.h"
#include "Cry_HsmRandomGenerate.h"
#include "Cry_HsmAesEncrypt.h"
#include "Cry_HsmAesDecrypt.h"
#include "Cry_HsmAesEcbEncrypt.h"
#include "Cry_HsmAesEcbDecrypt.h"
#include "Cry_HsmAesCMacGenerate.h"
#include "Cry_HsmAesCMacVerify.h"
#include "Cry_HsmKeyLoadPlain.h"
#include "Cry_HsmKeyExport.h"
#include "Cry_HsmKeyLoad.h"
#include "Cry_HsmDebug.h"
#include "Cry_HsmGetUID.h"
#include "Cry_HsmSecureBoot.h"
#include "HsmCom.h"
#include "Cry_HsmAesXtsEncrypt.h"
#include "Cry_HsmAesXtsDecrypt.h"
#include "Cry_HsmAesGcmEncrypt.h"
#include "Cry_HsmAesGcmDecrypt.h"
#include "Cry_HsmHash.h"
#include "Cry_HsmSignatureGenerate.h"
#include "Cry_HsmSignatureVerify.h"
#include "Cry_HsmEncrypt.h"
#include "Cry_HsmDecrypt.h"



/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/

/******************************************************************************
**                     Global Function Definitions                           **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 243] [$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          : void Cry_HsmInit(void)                                  **
**                                                                           **
** Description     : This function initializes the CRY module                **
**                   and the communication to HSM                            **
**                                                                           **
** Service ID      : CRY_HSM_SID_INIT                                        **
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
extern void Cry_HsmInit(void);

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"


/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 611]                              **
**                                                                           **
** Syntax          : uint32 Cry_HsmGetStatus(void)                           **
**                                                                           **
** Description     : This API returns the status of the HSM by calling       **
**                   HsmCom_GetStatus                                        **
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
** Return value    : The status of the HSM                                   **
**                                                                           **
******************************************************************************/
extern uint32 Cry_HsmGetStatus(void);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 645]  [$Satisfies $CDS_CDRV 744]  **
**                                                                           **
** Syntax          : void Cry_HsmSheCancel(void)                             **
**                                                                           **
** Description     : This API Cacnels the ongoing command by calling         **
**                   HsmCom_SheCancel()                                      **
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
extern void Cry_HsmSheCancel(void);
#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif/* End of CRY_HSM_H */
