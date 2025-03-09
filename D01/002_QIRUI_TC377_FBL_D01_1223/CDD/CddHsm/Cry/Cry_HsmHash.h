#ifndef CRY_HSM_HASH_H
#define CRY_HSM_HASH_H

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
typedef Cry_HsmBasicConfigType Cry_HsmHashConfigType;

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Cry_HsmHashConfigType Cry_kHsmHashConfig;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"


extern Csm_ReturnType  Cry_HsmHash(const void *CfgPtr,
									Hsm_HashAlgorithmType HashAlgorithm,
                                    const uint8 *MessagePtr,
                                    uint32 MessageLength,
                                    uint8 *DigestPtr,
                                    uint32 *DigestLengthPtr,
                                    Hsm_CryptoOperationMode OperationMode);
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif

