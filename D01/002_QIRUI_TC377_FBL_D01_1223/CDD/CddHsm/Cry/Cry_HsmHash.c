
/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_Hsm_Priv.h"
#include "Cry_HsmHash.h"
#include <string.h>

/******************************************************************************
**                      Imported Compiler Switch Check                       **
******************************************************************************/

/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/
/******************************************************************************
** Private Constant Definitions (Local preprocessor # define constants)      **
******************************************************************************/
/******************************************************************************
** Private Variable Definitions (Local preprocessor # define macros)         **
******************************************************************************/

/******************************************************************************
**                      Local Type Declarations                              **
******************************************************************************/

/******************************************************************************
**                      Local Object Definitions                             **
******************************************************************************/
/******************************************************************************
** Local function prototypes                                                 **
******************************************************************************/

/******************************************************************************
** Local Inline function definitions and #define function like macros        **
******************************************************************************/

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
const Cry_HsmHashConfigType   Cry_kHsmHashConfig =
                              {.TimeOut = CRY_HSM_HASH_ALL_TIMEOUT};

static const Cry_HsmPrimitiveIdType Cry_PRMIDHashGen = CRY_HSM_SYM_HASH;

#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Variable Definitions                           **
******************************************************************************/

/******************************************************************************
**                     Global Structure Definition                           **
******************************************************************************/

/******************************************************************************
**                     Global Function Definition                            **
******************************************************************************/

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*******************************************************************************
**                                                                            **
** Traceability    :                                                          **
**                                                                            **
** Syntax          :Csm_ReturnType Cry_HsmHash                                **
**                  (const void *CfgPtr,Hsm_HashAlgorithmType HashAlgorithm,  **
**                   const uint8 *MessagePtr, uint32 MessageLength ,          **
**                   uint8 *DigestPtr, uint32 *DigestLengthPtr,               **
**                   Hsm_CryptoOperationMode OperationMode)                   **
**                                                                            **
** Description     : hash interface                                           **
**                                                                            **
**                                                                            **
** Service ID      : CRY_HSM_SID_HASH                                         **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : CfgPtr                                                   **
**                   HashAlgorithm                                            **
**                   MessagePtr                                               **
**                   MessageLength                                            **
**                   OperationMode                                            **
**                                                                            **
** Parameters (out): DigestPtr                                                **
**                  DigestLengthPtr                                           **
**                                                                            **
** Return value    :CSM_E_OK          :Request successful                     **
**                  CSM_E_BUSY        :Request failed due to underlying HSM   **
**                                      communication is busy                 **
**                  CSM_E_SMALL_BUFFER:Request failed due to too small        **
**                                      buffer provided                       **
**                  CSM_E_NOT_OK      :Request failed                         **
**                                                                            **
*******************************************************************************/
Csm_ReturnType  Cry_HsmHash(  const void *CfgPtr,
									Hsm_HashAlgorithmType HashAlgorithm,
                                    const uint8 *MessagePtr,
                                    uint32 MessageLength,
                                    uint8 *DigestPtr,
                                    uint32 *DigestLengthPtr,
                                    Hsm_CryptoOperationMode OperationMode)
{
  Csm_ReturnType RetVal;
  Cry_Hsm *HandlePtr;
  const Cry_HsmHashConfigType *HashCfgPtr;
  HsmCom_HashGenerateParamsType *ParamPtr;
    /* Initiate the handle for the session */
    RetVal = Cry_HsmPrimitiveStart(Cry_PRMIDHashGen);
    /* Check if the session opened successfully */
    if(RetVal != CSM_E_BUSY)
    {
      HandlePtr = Cry_lHsmGetActiveHandle(Cry_PRMIDHashGen);
      /*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the
      * input config pointer is of type void*/
      /*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the
      * input config pointer is of type void */
      HashCfgPtr = (const Cry_HsmHashConfigType *) CfgPtr;
      /* Get the shared buffer address */
      /*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
      aligned to the struture pointer containing the elements
      for Random Number Generation*/
      ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
      /*IFX_MISRA_RULE_11_04_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      /*IFX_MISRA_RULE_11_06_STATUS=Typecasting is required as to handle
      *data sharing between Host and HSM through shared buffer*/
      ParamPtr->SourceAddr = (HostAddr)MessagePtr;
	  ParamPtr->DestAddr = (HostAddr)DigestPtr;
	  ParamPtr->MessageLength = MessageLength;
	  /*copy the digest length*/
	  if(DigestLengthPtr != NULL_PTR)
	  {
	      ParamPtr->DigestLength = *DigestLengthPtr;
	  }
	  else
	  {
      	  ParamPtr->DigestLength = 0u;
	  }
	  ParamPtr->OperationMode = (uint32)OperationMode;
	  ParamPtr->AlgorithmType = (uint32)HashAlgorithm;
      /* Store Key page value (dummy for this service) and
      * AES mode (dummy for this service) in session data */
      HsmCom_SetPackedParams(HandlePtr->Session, HSMCOM_KEY_DUMMY,
                   CRY_HSM_AES_MODE_DUMMY);
      /* Send the command to HSM */
      RetVal = Cry_HsmSendCommandCommon(HandlePtr,
                   HSMCOM_CMD_HASH,
                   CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(HashCfgPtr,MessageLength));

        /* If the command is accepted successful, main function does
        * further processing and closes the session */
        Cry_lHsmDeinitiateHandle(HandlePtr);
      }

      #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
      if(RetVal == CSM_E_OK)
      {
        /* Set the primitive status to FINISHED.Status will be changed again if
         * the START is executed successfully */
        Cry_PrimStatus[Cry_PRMIDHashGen] = CRY_HSM_PRIM_FINISHED;
      }
      #endif
    
  return RetVal;
}

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_RANDOM_GENERATE_C*/
