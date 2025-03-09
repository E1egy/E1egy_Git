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
**  FILENAME   : Cry_HsmRandomSeedExtend.h                                   **
**                                                                           **
**  VERSION :    3.0.0                                                       **
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
**                Cry_HsmRandomSeedExtend.c                                  **
**                                                                           **
**  SPECIFICATION(S) : Aurix_SHE+_TC-CDRV_DS.docx                            **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
#ifndef CRY_HSM_RANDOM_SEED_EXTEND_H
#define CRY_HSM_RANDOM_SEED_EXTEND_H
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
/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/

/******************************************************************************
**                     Global Type Definition                                **
******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 401]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmRandomSeedExtendConfigType;

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmRandomSeedExtendConfigType Cry_kHsmRandomSeedExtendConfig;

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
** Traceability    : [$Satisfies $CDS_CDRV 18] [$Satisfies $CDS_CDRV 19]     **
**                   [$Satisfies $CDS_CDRV 20] [$Satisfies $CDS_CDRV 21]     **
**                   [$Satisfies $CDS_CDRV 22] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType Cry_HsmRandomSeedExtendStart             **
**                                              (const void *CfgPtr)         **
**                                                                           **
** Description     : This functionimplements Cry_HsmRandomSeedExtendStart for**
**                   Csm_RandomSeedStart service. It reserves and initializes**
**                    resources for Csm_RandomSeed service                   **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_EXTEND_START                       **
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
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmRandomSeedExtendStart(
                       const void *CfgPtr);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 24]                               **
**                   [$Satisfies $CDS_CDRV 25] [$Satisfies $CDS_CDRV 26]     **
**                   [$Satisfies $CDS_CDRV 27] [$Satisfies $CDS_CDRV 28]     **
**                   [$Satisfies $CDS_CDRV 579]                              **
** Syntax          : Csm_ReturnType  Cry_HsmRandomSeedExtendUpdate(          **
**              const void *CfgPtr, const uint8 *SeedPtr, uint32 SeedLength) **
**                                                                           **
** Description     : This functionimplements Cry_HsmRandomSeedExtendUpdate   **
**                   for Csm_RandomSeedUpdate service. It sends request to   **
**                   HSM to extend the RNG seed.                             **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_EXTEND_UPDATE                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) :CfgPtr   -Pointer to configuration structure of          **
**                            Cry_HsmRandomSeedExtendConfigType              **
**                  SeedPtr  -Pointer to data which will be used as ENTROPY  **
**                            of CMD_EXTEND_SEED                             **
**                  seedLength-Only 16 bytes block size is supported. So     **
**                             this parameter is unused.                     **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmRandomSeedExtendUpdate(
                       const void *CfgPtr,
                       const uint8 *SeedPtr, uint32 SeedLength);
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 29] [$Satisfies $CDS_CDRV 30]     **
**                   [$Satisfies $CDS_CDRV 31] [$Satisfies $CDS_CDRV 32]     **
**                   [$Satisfies $CDS_CDRV 33] [$Satisfies $CDS_CDRV 579]    **
** Syntax          : Csm_ReturnType  Cry_HsmRandomSeedExtendFinish           **
**                                              (const void *CfgPtr)         **
**                                                                           **
** Description     : This functionimplements Cry_HsmRandomSeedExtendFinishfor**
**                   Csm_RandomSeedFinish service. It releases resources used**
**                   by Csm_RandomSeed service                               **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_SEED_EXTEND_FINISH                      **
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
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmRandomSeedExtendFinish(
                       const void *CfgPtr);

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 34] [$Satisfies $CDS_CDRV 579]    **
**                                                                           **
** Syntax          : void Cry_HsmRandomSeedExtendMainFunction(void)          **
**                                                                           **
** Description     : This function implements Cry_MainFunction for           **
**                    Csm_RandomSeed... service                              **
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
extern void Cry_HsmRandomSeedExtendMainFunction(void);
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_RANDOM_SEED_EXTEND_H */
