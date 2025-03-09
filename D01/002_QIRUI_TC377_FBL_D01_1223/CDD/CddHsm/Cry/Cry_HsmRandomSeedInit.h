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
**  FILENAME   : Cry_HsmRandomSeedInit.h                                     **
**                                                                           **
**  VERSION :   3.0.0                                                        **
**                                                                           **
**  DATE       : 2016-07-11                                                  **
**                                                                           **
**  VARIANT   : NA                                                           **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR      : Trivikram G                                                **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This is the corresponding header file for                  **
**                Cry_HsmRandomSeedInit.c                                    **
**                                                                           **
**  SPECIFICATION(S) :  Aurix_SHE+_TC-CDRV_DS.docx                           **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
#ifndef CRY_HSM_RANDOM_SEED_INIT_H
#define CRY_HSM_RANDOM_SEED_INIT_H
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*
<IFX_RCH>
</IFX_RCH>
*/
/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_HsmTypes.h"
#include "Cry_Hsm_PrivCfg.h"
/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/

/******************************************************************************
**                     Global Type Definition                                **
******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 400]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmRandomSeedInitConfigType;

/******************************************************************************
**                     Global Constant Declarations                          **
******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmRandomSeedInitConfigType Cry_kHsmRandomSeedInitConfig;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 1] [$Satisfies $CDS_CDRV 2]       **
**                   [$Satisfies $CDS_CDRV 3] [$Satisfies $CDS_CDRV 4]       **
**                   [$Satisfies $CDS_CDRV 5] [$Satisfies $CDS_CDRV 579]     **
** Syntax          : Csm_ReturnType Cry_HsmRandomSeedInitStart               **
**                                                      (const void *CfgPtr) **
**                                                                           **
** Description     : This function implements Cry_HsmRandomSeedInitStart for **
**                   Csm_RandomSeedStart service. It reserves and initializes**
**                   resources for Csm_RandomSeed service                    **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_INIT_START                         **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr   -Pointer to configuration structure of         **
**                             Cry_HsmRandomSeedExtendConfigType This        **
**                             parameter is ignored                          **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmRandomSeedInitStart(
                       const void *CfgPtr);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 6] [$Satisfies $CDS_CDRV 7]       **
**                   [$Satisfies $CDS_CDRV 8] [$Satisfies $CDS_CDRV 9]       **
**                   [$Satisfies $CDS_CDRV 10] [$Satisfies $CDS_CDRV 11]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType  Cry_HsmRandomSeedInitUpdate(            **
**                            const void *CfgPtr, const uint8 *SeedPtr,      **
**                            uint32 SeedLength)                             **
**                                                                           **
** Description     : This function implements Cry_HsmRandomSeedInitUpdate for**
**                   Csm_RandomSeedUpdate service. It sends request to HSM   **
**                   to initialize the RNG                                   **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_INIT_UPDATE                        **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr   -Pointer to configuration structure of         **
                                Cry_HsmRandomSeedInitConfigType.             **
                    SeedPtr   -This parameter is ignored                     **
                    SeedLength-This parameter is ignored                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmRandomSeedInitUpdate(
                       const void *CfgPtr,
                       const uint8 *SeedPtr, uint32 SeedLength);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 12] [$Satisfies $CDS_CDRV 13]     **
**                   [$Satisfies $CDS_CDRV 14] [$Satisfies $CDS_CDRV 15]     **
**                   [$Satisfies $CDS_CDRV 16] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType  Cry_HsmRandomSeedInitFinish             **
**                                                  (const void *CfgPtr)     **
**                                                                           **
** Description     : This function implements Cry_HsmRandomSeedInitFinish    **
**                   for Csm_RandomSeedFinish service. It releases resources **
**                    used by Csm_RandomSeed service                         **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_INIT_FINISH                        **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr                                                  **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK - Request failed                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmRandomSeedInitFinish(
                       const void *CfgPtr);

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 17] [$Satisfies $CDS_CDRV 579]    **
**                                                                           **
** Syntax          : void Cry_HsmRandomSeedInitMainFunction(void)            **
**                                                                           **
** Description     : This function implements                                **
**                     Cry_HsmRandomSeedInitMainFunction                     **
**                     for Csm_RandomSeed... service                         **
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
extern void Cry_HsmRandomSeedInitMainFunction(void);
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_RANDOM_SEED_INIT_H */
