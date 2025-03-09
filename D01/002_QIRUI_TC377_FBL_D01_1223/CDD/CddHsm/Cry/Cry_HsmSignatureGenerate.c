
/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_Hsm_Priv.h"
#include "Cry_HsmSignatureGenerate.h"

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/
#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

Cry_HsmSignatureGenerateConfigType  Cry_HsmSignatureGenerateConfig =
        {.TimeOut = CRY_HSM_SIGNATURE_GENERATE_ALL_TIMEOUT};

static Cry_HsmPrimitiveIdType Cry_PRMIDSignatureGen = CRY_HSM_SYM_SIGNATURE_GENERATE;



#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/

/******************************************************************************
**                      Global Structure Declaration                         **
******************************************************************************/
#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

static struct
{
   HsmCom_KeyAddr KeyAddr;
} Cry_HsmSignatureGenerateData;


#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/******************************************************************************
**                      Global Function Decleartion                          **
******************************************************************************/
#define CRY_START_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*******************************************************************************
**                                                                            **
** Traceability    :                                                          **
**                                                                            **
** Syntax          :Csm_ReturnType Cry_HsmSignatureGenerate                   **
**                  (const void *CfgPtr,const Csm_SymKeyType *KeyPtr,         **
**                   Hsm_CipherAlgorithmType Algorithm_Type,  **
**                   const  uint8 * UserId, uint32 UserIdLen,const uint8 *DataPtr, **
**                   uint32 DataLength ,  uint8 *ResultPtr, uint32 *ResultLength, **
**                   Hsm_CryptoOperationMode OperationMode)                   **
**                                                                            **
** Description     : signature generate interface                             **
**                                                                            **
**                                                                            **
** Service ID      : CRY_HSM_SID_SIGNATURE_GENERATE                           **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : CfgPtr                                                   **
**                   KeyPtr                                                   **
**                   Algorithm_Type                                           **
**                   UserId                                                   **
**                   UserIdLen                                                **
**                   DataPtr                                                  **
**                   DataLength                                               **
**                   ResultLength                                             **
**                   OperationMode                                            **
**                                                                            **
** Parameters (out): ResultPtr                                                **
**                  ResultLength                                              **
**                                                                            **
** Return value    :CSM_E_OK          :Request successful                     **
**                  CSM_E_BUSY        :Request failed due to underlying HSM   **
**                                      communication is busy                 **
**                  CSM_E_SMALL_BUFFER:Request failed due to too small        **
**                                      buffer provided                       **
**                  CSM_E_NOT_OK      :Request failed                         **
**                                                                            **
*******************************************************************************/
Csm_ReturnType  Cry_HsmSignatureGenerate(const void *CfgPtr,const Csm_PlainKeyType *KeyPtr,Hsm_SignatureAlgorithmType Algorithm_Type,
                                                const uint8 *UserId,uint32 UserIdLen,const uint8 *DataPtr, uint32 DataLength, uint8 *ResultPtr,
                                                uint32 *ResultLength,Hsm_CryptoOperationMode OperationMode)
{
	/*To store Return value from Cey Api's*/
	Csm_ReturnType ErrorVal;
	/*To store the handler for session*/
	Cry_Hsm *HandlePtr;
	/*Pointer containing elements for SignatureGen */
	Hsm_SignatureParamsType *ParamPtr;
	const Cry_HsmSignatureGenerateConfigType *SignatureCfgPtr;
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
	/*To store DET errors*/
	boolean DetErr;
#endif
  
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
	DetErr = DEV_NO_ERROR;
	PTR_VALIDATION(CRY_HSM_SID_SIGNATURE_GENERATE, CfgPtr ,DetErr)
		
	if(DEV_NO_ERROR == DetErr)
	{
	    PTR_VALIDATION(CRY_HSM_SID_SIGNATURE_GENERATE, KeyPtr , DetErr)
	}
	if(DEV_NO_ERROR == DetErr)
	{
	    PTR_VALIDATION(CRY_HSM_SID_SIGNATURE_GENERATE, DataPtr , DetErr)
	}
	if(DEV_NO_ERROR == DetErr)
	{
	    PTR_VALIDATION(CRY_HSM_SID_SIGNATURE_GENERATE, ResultPtr, DetErr)
	}
	/* Check the next DET only if the DET error doesn't occur.
	 * DetErr == DEV_NO_ERROR indicates that DET error doesn't occur */
	if(DEV_NO_ERROR == DetErr)
	{
	    INIT_VALIDATION(CRY_HSM_SID_SIGNATURE_GENERATE, Cry_HsmInitStatus ,
																	   DetErr)
	}
	if(DEV_NO_ERROR == DetErr)
	{
	    KEY_VALIDATION(CRY_HSM_SID_SIGNATURE_GENERATE,Cry_lCalcKeyAddr(KeyPtr)
																  , DetErr)
	}
	/* If any DET error occurs, return CSM_E_NOT_OK. Further processing
														  is not required */
	if(DEV_NO_ERROR != DetErr)
	{
	    ErrorVal = CSM_E_NOT_OK;
	}
	else
#endif
	{
		/* Initiate the handle for the session */
		ErrorVal = Cry_HsmPrimitiveStart(Cry_PRMIDSignatureGen);
		/* Check the HSM status. COmmand is sent only if the
				   * HSM is not busy */
		if(CSM_E_BUSY != ErrorVal)
		{
			/*Store the key*/
			Cry_HsmSignatureGenerateData.KeyAddr = Cry_lCalcKeyAddr(KeyPtr);
        #if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
			/* Set the indication that START service is successful.
			 * To be used by UPDATE and FINISH services to check the
			 * DET "CSM_E_SERVICE_NOT_STARTED" */
			Cry_PrimStatus[Cry_PRMIDSignatureGen] = CRY_HSM_PRIM_STARTED;
        #endif

		    HandlePtr = Cry_lHsmGetActiveHandle(Cry_PRMIDSignatureGen);
			/*IFX_MISRA_RULE_11_03_STATUS=Type casting is required as the
			 * input config pointer is of type void*/
			/*IFX_MISRA_RULE_11_05_STATUS=Type casting is required as the
			 * input config pointer is of type void */
			SignatureCfgPtr = (const Cry_HsmSignatureGenerateConfigType *)CfgPtr;
			/* Get the shared buffer address */
			/*IFX_MISRA_RULE_11_05_STATUS=Shared buffer address has to be
			 * aligned to the struture pointer containing the elements
			 * for MacGeneration */
			ParamPtr = HsmCom_GetParamsBuffer(HandlePtr->Session);
			/* Update the prameters in shared buffer */
			/*IFX_MISRA_RULE_11_04_STATUS=Type casting is required as the
			 * input DataPtr is of type uint8*/
			/*IFX_MISRA_RULE_11_06_STATUS=Type casting is required as the
			 * input DataPtr is of type uint8*/
			ParamPtr->SourceAddr = (HostAddr)DataPtr;
			ParamPtr->MessageSize  =	DataLength;
			ParamPtr->SignatureOutputAddr = (HostAddr) ResultPtr;
			ParamPtr->SignatureResultLenAddr = (HostAddr)ResultLength;
			ParamPtr->Algorithm_type = (uint32)Algorithm_Type;
			ParamPtr->UserIdAddr = (HostAddr)UserId;
			ParamPtr->UserIdLen = UserIdLen;
			ParamPtr->OperationMode = (uint32)OperationMode;
			/*Store key address in Session data*/
			HsmCom_SetPackedParams(HandlePtr->Session,
									  Cry_HsmSignatureGenerateData.KeyAddr,
									  CRY_HSM_AES_MODE_DUMMY);
			/* Send the command to HSM */
			ErrorVal = Cry_HsmSendCommandCommon(HandlePtr,
							 HSMCOM_CMD_SIGNATURE_GEN,
							 CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(SignatureCfgPtr,DataLength));
			/* Make the KEY as invalid as valid KEY has to be
								   sent only for the first UPDATE command */
			Cry_HsmSignatureGenerateData.KeyAddr = HSMCOM_INVALID_KEY;
			#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
			Cry_lHsmDeinitiateHandle(HandlePtr);
            #endif
		}
	}


#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
	  Cry_PrimStatus[CRY_HSM_SYM_SIGNATURE_GENERATE] = CRY_HSM_PRIM_FINISHED;
#endif

	return ErrorVal;
}
                                                     

#define CRY_STOP_SEC_RAMCODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/*End of CRY_HSM_MAC_GENERATE_C*/
