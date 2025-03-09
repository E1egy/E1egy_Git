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
**  FILENAME   : Cry_HsmRandomGenerate.h                                     **
**                                                                           **
**  VERSION    : 4.0.0                                                       **
**                                                                           **
**  DATE       : 2017-10-31                                                  **
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
**                Cry_HsmRandomGenerate.c file                               **
**                                                                           **
**  SPECIFICATION(S) :  Aurix_SHE+_TC-CDRV_DS.docx                           **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
#ifndef CRY_HSM_RANDOM_GENERATE_H
#define CRY_HSM_RANDOM_GENERATE_H
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
******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 403]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmRandomGenerateConfigType;
/** Traceability    : [$Satisfies $CDS_CDRV 402]                              **
*******************************************************************************/
typedef Cry_HsmBasicConfigType Cry_HsmTRNGConfigType;

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmRandomGenerateConfigType Cry_kHsmRandomGenerateConfig;
extern const Cry_HsmTRNGConfigType Cry_kHsmTRNGConfig;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmRandomGenerateFinishAction(void)            **
**                                                                           **
** Description     : This function is used to copy the generated random      **
**                  number into destination pointer                          **
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
extern void Cry_HsmRandomGenerateFinishAction(void);

/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmRandomGenerateClearBuffer(void)             **
**                                                                           **
** Description     : This function is used to clear the input buffer         **
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
extern void Cry_HsmRandomGenerateClearBuffer(void);

/******************************************************************************
** Traceability    :  [$Satisfies $CDS_CDRV 35]  [$Satisfies $CDS_CDRV 36]   **
**                    [$Satisfies $CDS_CDRV 37]                              **
**                    [$Satisfies $CDS_CDRV 39][$Satisfies $CDS_CDRV 590]    **
**                    [$Satisfies $CDS_CDRV 579]                             **
** Syntax          : Csm_ReturnType Cry_HsmRandomGenerate(                   **
**                   const void *CfgPtr, uint8 *ResultPtr,                   **
**                     uint32 ResultLength)                                  **
**                                                                           **
** Description     :  This function implements Cry_<Primitive> for           **
**                    Csm_ RandomGenerate service. It sends request to HSM to**
**                    generate a random number.                              **
**                                                                           **
** Service ID      : CRY_HSM_SID_RND_GENERATE                                **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr       -Pointer to configuration structure of     **
**                                 Cry_HsmRandomGenerateConfigType           **
**                   ResultLength -The amount of random bytes which should   **
**                                 be generated. Value range [1…16]          **
**                                                                           **
** Parameters (out): ResultPtr    -Pointer to the memory location which will **
**                                 hold the result of the random number      **
**                                 generation                                **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmRandomGenerate(
                    const void *CfgPtr,
                    uint8 *ResultPtr, uint32 ResultLength);

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 245] [$Satisfies $CDS_CDRV 579]   **
** Syntax          : Csm_ReturnType Cry_HsmTrueRandomGenerate(               **
**         const void *CfgPtr, uint8 *ResultPtr, uint32 ResultLength)        **
**                                                                           **
** Description     :  This function implements Cry_<Primitive> for           **
**                    Csm_ RandomGenerate service. It sends request to HSM to**
**                    generate a random number.                              **
**                                                                           **
** Service ID      : CRY_HSM_SID_TRUE_RND_GENERATE                           **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : CfgPtr       -Pointer to configuration structure of     **
**                                 Cry_HsmRandomGenerateConfigType           **
**                   ResultLength -The amount of random bytes which should   **
**                                 be generated. Value range [1…16]          **
**                                                                           **
** Parameters (out): ResultPtr    -Pointer to the memory location which will **
**                                 hold the result of the random number      **
**                                 generation                                **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                communication is busy                      **
**                   CSM_E_NOT_OK - Request failed                           **
**                   CSM_E_ENTROPY_EXHAUSTION - Request failed, entropy of   **
**                                random number generator is exhausted.      **
******************************************************************************/
extern Csm_ReturnType  Cry_HsmTrueRandomGenerate(
                    const void *CfgPtr,
                    uint8 *ResultPtr, uint32 ResultLength);

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 40] [$Satisfies $CDS_CDRV 579]    **
**                                                                           **
** Syntax          : void Cry_HsmRandomGenerateMainFunction(void)            **
**                                                                           **
** Description     :                                                         **
**                                                                           **
** [/cover]                                                                  **
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
extern void Cry_HsmRandomGenerateMainFunction(void);
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmTrueRandomGenerateMainFunction(void)        **
**                                                                           **
** Description     :                                                         **
**                                                                           **
** [/cover]                                                                  **
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
extern void Cry_HsmTrueRandomGenerateMainFunction(void);
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif
/* CRY_HSM_RANDOM_GENERATE_H */
