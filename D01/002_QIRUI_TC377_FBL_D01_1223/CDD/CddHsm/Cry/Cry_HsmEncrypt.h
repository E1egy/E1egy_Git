
#ifndef CRY_HSM_ENCRYPT_H
#define CRY_HSM_ENCRYPT_H
/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_HsmTypes.h"
#include "Cry_Hsm_PrivCfg.h"

/******************************************************************************
**                     Global Type Definition                                **
******************************************************************************/


/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

typedef Cry_HsmBasicConfigType Cry_HsmEncryptConfigType;

extern Cry_HsmEncryptConfigType  Cry_HsmEncryptConfig;


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

extern Csm_ReturnType  Cry_HsmEncrypt(const void *CfgPtr,const Csm_SymKeyType *KeyPtr,const uint8 *IV,Hsm_CipherAlgorithmType Algorithm_Type,
                                   Crypto_AlgorithmModeType mode,const uint8 *DataPtr, uint32 DataLength, uint8 *ResultPtr,uint32 *ResultLength,Hsm_CryptoOperationMode OperationMode);

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif /* CRY_HSM_AES_MAC_GENERATE_H */
