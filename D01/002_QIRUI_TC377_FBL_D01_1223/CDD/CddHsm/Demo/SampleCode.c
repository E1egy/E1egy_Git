/*****************************************************************************************
**                                                                                      **
** Copyright (C) Infineon Technologies (2014)                                           **
**                                                                                      **
** All rights reserved.                                                                 **
**                                                                                      **
** This document contains proprietary information belonging to Infineon                 **
** Technologies. Passing on and copying of this document, and communication             **
** of its contents is not permitted without prior written authorization.                **
**                                                                                      **
** THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. INFINEON TECHNOLOGIES          **
** RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER          **
** REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR         **
** THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.                          **
**                                                                                      **
** INFINEON TECHNOLOGIES SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR                **
** CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR        **
** ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR              **
** PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE        **
** DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION         **
** WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR        **
** PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON        **
** WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.                                   **
**                                                                                      **
**************************************************************************************//**
*
*  \FILE      SampleCode.c
*
*  \BRIEF     Sample code for handling the HSM SHE+ module using Cry
*
*  \DATE      2014.09.18
*
*  \AUTHOR    Volker Elies [volker.elies@hitex.de]
*
*  \VENDOR    Infineon Technologies, A.G.
*
*  \REFERENCE <spec name, version>
*
*//**************************************************************************************/

#include "HsmCom_Priv.h"
#include "TestHsm.h"
#include "SampleCode.h"
#include "Hsm_Mcal.h"
#include "McalLib.h"
#if ITF
#include "Cry_HsmKeyLoadPlain.h"
#include "Det.h"
#include "BswM.h"
#include "Cry_Hsm_Priv.h"
#endif

#if (1)
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
extern void print_f(const char *p_frm, ...);

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
#define TEST_PRINTF print_f
#else
#define TEST_PRINTF(...)
#endif

#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"
/* Table to map Cry_HsmKeySlotIdType values to the corresponding HsmCom_KeyAddr values */
static HsmCom_KeyAddr SampleCode_keyMap[] =
{
	HSMCOM_RAM_KEY,	    	/* CRY_HSM_RAM_KEY = 0,      */
	HSMCOM_KEY_1, 	    	/* CRY_HSM_KEY_1   = 1,      */
	HSMCOM_KEY_2, 	    	/* CRY_HSM_KEY_2   = 2,      */
	HSMCOM_KEY_3, 	    	/* CRY_HSM_KEY_3   = 3,      */
	HSMCOM_KEY_4, 	    	/* CRY_HSM_KEY_4   = 4,      */
	HSMCOM_KEY_5, 	    	/* CRY_HSM_KEY_5   = 5,      */
	HSMCOM_KEY_6, 	    	/* CRY_HSM_KEY_6   = 6,      */
	HSMCOM_KEY_7, 	    	/* CRY_HSM_KEY_7   = 7,      */
	HSMCOM_KEY_8, 	    	/* CRY_HSM_KEY_8   = 8,      */
	HSMCOM_KEY_9, 	    	/* CRY_HSM_KEY_9   = 9,      */
	HSMCOM_KEY_10,	    	/* CRY_HSM_KEY_10  = 10,     */
	HSMCOM_KEY_11,	    	/* CRY_HSM_KEY_11  = 11,     */
	HSMCOM_KEY_12,	    	/* CRY_HSM_KEY_12  = 12,     */
	HSMCOM_KEY_13,	    	/* CRY_HSM_KEY_13  = 13,     */
	HSMCOM_KEY_14,	    	/* CRY_HSM_KEY_14  = 14,     */
	HSMCOM_KEY_15,	    	/* CRY_HSM_KEY_15  = 15,     */
	HSMCOM_KEY_16,	    	/* CRY_HSM_KEY_16  = 16,     */
	HSMCOM_KEY_17,	    	/* CRY_HSM_KEY_17  = 17,     */
	HSMCOM_KEY_18,	    	/* CRY_HSM_KEY_18  = 18,     */
	HSMCOM_KEY_19,	    	/* CRY_HSM_KEY_19  = 19,     */
	HSMCOM_KEY_20,	    	/* CRY_HSM_KEY_20  = 20,     */
	HSMCOM_MASTER_ECU_KEY,	/* CRY_HSM_MASTER_ECU_KEY = 21,  */
	HSMCOM_BOOT_MAC_KEY,	/* CRY_HSM_BOOT_MAC_KEY   = 22,  */
	HSMCOM_BOOT_MAC,      	/* CRY_HSM_BOOT_MAC       = 23,  */
};

struct
{
    volatile uint8 callbackSet;
    Csm_ReturnType result;
} g_TestHsm_key =
{
    .callbackSet = 0,
    .result = CSM_E_OK
};
#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"


#if ITF
#define CRY_START_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
typedef enum{
    CRY_KEY_LOAD_PLAIN_IDLE = 0,
    CRY_KEY_LOAD_PLAIN_START_VALID_PARAMETERS_CRY_UNINIT,
    CRY_KEY_LOAD_PLAIN_UPDATE_CFG_PTR_NULL,
    CRY_KEY_LOAD_PLAIN_UPDATE_DATA_PTR_NULL,
    CRY_KEY_LOAD_PLAIN_UPDATE_WHEN_START_FAIL,
    CRY_KEY_LOAD_PLAIN_UPDATE_WHEN_DATA_LENGTH_8,
    CRY_KEY_LOAD_PLAIN_FINISH_WHEN_START_FAIL,
    CRY_KEY_LOAD_PLAIN_CANCEL,
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON)
    CRY_KEY_LOAD_PLAIN_SYNC_SUCCESS,
    CRY_KEY_LOAD_PLAIN_SYNC_TIMEOUT,
    CRY_KEY_LOAD_PLAIN_SESSION_HANDLING,
#else
    CRY_KEY_LOAD_PLAIN_ASYNC_SUCCESS,
    CRY_KEY_LOAD_PLAIN_ASYNC_TIMEOUT,
    CRY_KEY_LOAD_PLAIN_CANCEL_ASYNC,
#endif
    CRY_KEY_LOAD_PLAIN_FINISH_TIMEOUT
}Cry_KeyLoadPlain_Testcase;

typedef enum{
    CRY_KEY_EXPORT_IDLE = 0,
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON)
    CRY_KEY_EXPORT_SYNC_SUCCESS1,
    CRY_KEY_EXPORT_SYNC_SUCCESS2,
    CRY_KEY_EXPORT_SYNC_TIMEOUT,
    CRY_KEY_EXPORT_SYNC_SESSION_HANDLING,
    CRY_KEY_EXPORT_TIMEOUT_COMPLETE_SYNC,
    CRY_KEY_EXPORT_CANCEL,
#else
    CRY_KEY_EXPORT_ASYNC_SUCCESS1,
    CRY_KEY_EXPORT_ASYNC_SUCCESS2,
    CRY_KEY_EXPORT_ASYNC_TIMEOUT,
    CRY_KEY_EXPORT_TIMEOUT_COMPLETE_ASYNC,
    CRY_KEY_EXPORT_CANCEL_ASYNC,
#endif
    CRY_KEY_EXPORT_START_VALID_PARAMETERS_CRY_UNINIT,
    CRY_KEY_EXPORT_UPDATE_CFG_NULL,
    CRY_KEY_EXPORT_UPDATE_DATA_NULL,
    CRY_KEY_EXPORT_UPDATE_DATA_LENGTH_NULL,
    CRY_KEY_EXPORT_UPDATE_WHEN_START_NOT_STARTED,
    CRY_KEY_EXPORT_UPDATE_WHEN_DATA_LENGTH_60,
    CRY_KEY_EXPORT_FINISH_WHEN_START_NOT_STARTED
}Cry_KeyExport_Testcase;

typedef enum
{
    CRY_KEY_LOAD_IDLE =0,
    CRY_KEY_LOAD_CRYHSM_UNINIT,
    CRY_KEYLOAD_UPDATE_NULLCFG,
    CRY_KEYLOAD_UPDATE_NULLDATAPTR,
    CRY_KEYLOAD_UPDATE_SERVICENOTSTARTED,
    CRY_KEYLOAD_UPDATE_LENGTH60,
    CRY_KEYLOAD_FINISH_NULLCFGPTR,
    CRY_KEYLOAD_FINISH_SERVICENOTSTARTED,
    CRY_KEYLOAD_START_UPD_FIN,
    CRY_KEYLOAD_START_FINISH,
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
    CRY_KEYLOAD_START_UPD_FIN_ASYNC
#endif
}Cry_KeyLoad_TestCase;


Csm_ReturnType KeyLoadPlain_RetVal;
Csm_ReturnType KeyExport_RetVal;
Csm_ReturnType KeyLoad_RetVal;
Csm_ReturnType KeyLoad_RetVal2;
uint8 KeyLoadErrorCheck ;
boolean KeyLoadReturn;
uint8 KeyLoadPlainStatus;
Cry_PrimStatusVal KeyLoadPlainService;
Cry_PrimStatusVal KeyExportService;
Csm_ReturnType KeyLoadPlain_StartRetVal;
Csm_ReturnType KeyLoadPlain_UpdateRetVal;
Csm_ReturnType KeyLoadPlain_UpdateRetVal1;
Csm_ReturnType KeyLoadPlain_FinishRetVal;
Csm_ReturnType KeyExport_StartRetVal;
Csm_ReturnType KeyExport_UpdateRetVal;
Csm_ReturnType KeyExport_UpdateRetVal1;
Csm_ReturnType KeyExport_FinishRetVal;
Csm_ReturnType KeyLoadPlainCallBackStartResult;
Csm_ReturnType KeyLoadPlainCallBackUpdateResult;
Csm_ReturnType KeyLoadPlainCallBackUpdateResult1;
Csm_ReturnType KeyLoadPlainCallBackFinishResult;
uint8 KeyLoadPlainFinishNotify;
uint8 KeyExportFinishNotify;
Csm_ReturnType KeyExportCallBackStartResult;
Csm_ReturnType KeyExportCallBackUpdateResult;
Csm_ReturnType KeyExportCallBackUpdateResult1;
Csm_ReturnType KeyExportCallBackFinishResult;
uint32 *DummyPtr;
uint32 i_key;
uint8 KeyExportStatus;
uint8 ErrorCheck_Key;
ProtectedKey *KeyPtr ;



#define KEY_EXPORT_BUFFER_CHECK(longwordcount)      \
{                                                   \
    DummyPtr =(uint32 *)TEST_HSM_BUF_TEMP_A;        \
    ErrorCheck_Key = 0;                                 \
    for(i_key=0; i_key<longwordcount; i_key++)                  \
    {                                               \
        if (*DummyPtr != 0xFFFFFFFF)                \
        {                                           \
            ErrorCheck_Key = 1;                         \
            break;                                  \
        }                                           \
        DummyPtr++;                                 \
    }                                               \
    if(longwordcount != 28)                         \
    {                                               \
        DummyPtr =(uint32 *)TEST_HSM_BUF_TEMP_A;     \
        for(i_key=0; i_key<longwordcount; i_key++)              \
        {                                           \
            DummyPtr++;                             \
        }                                           \
        for(i_key=longwordcount; i_key<28; i_key++)             \
        {                                           \
            if (*DummyPtr != 0xFFFFFFFF)            \
            {                                       \
                ErrorCheck_Key = 0;                     \
                break;                              \
            }                                       \
            DummyPtr++;                            \
        }                                           \
    }                                               \
}
Cry_KeyLoadPlain_Testcase TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
Cry_KeyExport_Testcase TC_KeyExport = CRY_KEY_EXPORT_IDLE;
Cry_KeyLoad_TestCase TC_KeyLoad = CRY_KEY_LOAD_IDLE;
#define CRY_STOP_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"


#endif


#define CRY_START_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
struct
{
    HsmAes_Block M1[1];
    HsmAes_Block M2[2];
    HsmAes_Block M3[1];
    HsmAes_Block M4[2];
    HsmAes_Block M5[1];
} ExportedKey;


ProtectedKey protKey;
HsmAes_Block K1;
HsmAes_Block K2;
HsmAes_Block K3;
HsmAes_Block K4;
HsmAes_Block M4[2];
HsmAes_Block temp1;
HsmAes_Block temp2;
HsmAes_Block state;
HsmAes_Block inputM2[2];
#define CRY_STOP_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"

#define TEST_REVERSE_BYTES_WORD(w)   ((w << 8U) | (w >> 8U))
#define TEST_REVERSE_BYTES_DWORD(dw) ((((uint32)TEST_REVERSE_BYTES_WORD((uint16)(dw & 0xFFFFUL))) << 16U ) | ((uint32)TEST_REVERSE_BYTES_WORD((uint16)(dw >> 16U))))

#define CRY_START_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
/* Test data as implemented in HSM KeyMng module */
static  SampleCode_KeyType g_KeyStorage[32]; /* Filled with zeros by reset */
#define CRY_STOP_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

const HsmAes_Block RAM_Key =
        {{0x0c0d0e0ful, 0x08090a0bul, 0x04050607ul, 0x00010203ul}};

/*
 * constants as defined in SHE specification, chapter 12
 * SHE+ extension: 2 key pages are supported
 */
const HsmAes_Block g_KeyUpdateEncC[2] = {			             /* KEY_UPDATE_ENC_C */
    {{0x48530101ul, 0x00800045ul, 0x00000000ul, 0xB0000000UL}},  /* Page 0 */
    {{0x48538101ul, 0x00800045ul, 0x00000000ul, 0xB0000000UL}},  /* Page 1 */
};

const HsmAes_Block g_KeyUpdateMacC[2] = {			             /* KEY_UPDATE_MAC_C */
    {{0x48530201ul, 0x00800045ul, 0x00000000ul, 0xB0000000UL}},  /* Page 0 */
    {{0x48538201ul, 0x00800045ul, 0x00000000ul, 0xB0000000UL}},  /* Page 1 */
};

const HsmAes_Block g_DebugKeyC = {                         /* DEBUG_KEY_C */
    {0x48530301ul, 0x00800045ul, 0x00000000ul, 0xB0000000UL}
};

static const HsmAes_Block SampleCode_Cmac_constZero     = {{0x00000000UL, 0x00000000UL, 0x00000000UL, 0x00000000UL}};
#if ITF
const uint8 TEST_KEY_LOAD_PLAIN_CONST_KEY[16] = {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};
#endif
#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"

static Csm_ReturnType SampleCode_LoadKey(ProtectedKey *key, const Cry_HsmKeyLoadConfigType* keyLoadCfg);

/*************************************************************************************//**
 * Returns the current key flag value of the key identified by keyId
 *
 * \param keyId ID of the key in question
 *
 * \retval Current key security flags
 ****************************************************************************************/
uint32 SampleCode_GetKeyFlags(Cry_HsmKeySlotIdType keySlotId)
{
	return (g_KeyStorage[SampleCode_keyMap[keySlotId]].flags);
}

/*************************************************************************************//**
 * Returns the next counter value for the key identified by keyId
 *
 * \param keyId ID of the key in question
 *
 * \retval Current current counter value +1
 ****************************************************************************************/
uint32 SampleCode_GetNextKeyCounter(Cry_HsmKeySlotIdType keySlotId)
{

	return (g_KeyStorage[SampleCode_keyMap[keySlotId]].counter+1);
}

/*************************************************************************************//**
 * Clears the key slot in local memory for the key identified by keyId
 *
 * \param keyId ID of the key in question
 *
 * \retval None
 ****************************************************************************************/
void SampleCode_ClearKeySlot(Cry_HsmKeySlotIdType keySlotId)
{
	HsmCom_KeyAddr keyId = SampleCode_keyMap[keySlotId];
	g_KeyStorage[keyId].key     = SampleCode_Cmac_constZero;
	g_KeyStorage[keyId].flags   = 0UL;
	g_KeyStorage[keyId].counter = 0UL;
}

/*************************************************************************************//**
 * Loads a new plain key into SHE.
 *
 * \param KeyAddr The key slot in memory
 * \param keyPtr  Pointer to the new key value to be loaded
 * \param KeyLength The new key length
 *
 * \retval CSM_E_OK     Request successful
 * \retval CSM_E_BUSY   Request failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK Request failed
 ****************************************************************************************/
Csm_ReturnType SampleCode_LoadPlainKey (HsmCom_KeyAddr KeyAddr,const HsmAes_Block *keyPtr,uint32 KeyLength)
{
    volatile Csm_ReturnType csmRes;
    const Cry_HsmLoadPlainConfigType* config = &Cry_kHsmLoadPlainConfig;
	
    csmRes = Cry_HsmKeyLoadPlainStart(config);

    TEST_VALIDATE(csmRes == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);
#endif
    	csmRes = Cry_HsmKeyLoadPlainUpdate(config,KeyAddr,(const uint8*)keyPtr, KeyLength);
    TEST_VALIDATE(csmRes == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);
#endif
    	csmRes = Cry_HsmKeyLoadPlainFinish(config, NULL_PTR);
    TEST_VALIDATE(csmRes == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);
#endif

    return (csmRes);
}

/*************************************************************************************//**
 * Does the AES ECB encryption of a single 16 byte block.
 *
 * \param keyPtr        Holds a pointer to the key to be used for the encryption
 * \param plainTextPtr  Holds a pointer to the plain text that shall be encrypted.
 * \param cipherTextPtr Holds a pointer to the memory location which will hold the
 *                      encrypted text.
 *
 * \retval CSM_E_OK             Request successful
 * \retval CSM_E_BUSY           Request failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK         Request failed
 ****************************************************************************************/
Csm_ReturnType SampleCode_HsmAesEcbEncrypt(const Csm_SymKeyType *symKeyPtr, const HsmAes_Block *plainTextPtr, HsmAes_Block* cipherTextPtr)
{
	const Cry_HsmAesEcbEncryptConfigType* config = &Cry_kHsmAesEcbEncryptConfig;
    uint32 outputLength = sizeof (HsmAes_Block);
    volatile Csm_ReturnType retVal;

    retVal = Cry_HsmAesEcbEncryptStart(config, symKeyPtr);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

    if (retVal != CSM_E_BUSY)
	{
        retVal = Cry_HsmAesEcbEncryptUpdate(config, (const uint8*)plainTextPtr, sizeof (HsmAes_Block), (uint8*)cipherTextPtr, &outputLength);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

        retVal = Cry_HsmAesEcbEncryptFinish(config, NULL_PTR, NULL_PTR);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
        if (((retVal == CSM_E_OK)) && (outputLength != sizeof (HsmAes_Block)))
        {
        	retVal = CSM_E_NOT_OK;
        }
	}
    else
    {
    	TEST_PRINTF("Cry_HsmAesEcbEncryptStart(): CSM_E_BUSY\n");
    }

    return (retVal);
}

/*************************************************************************************//**
 * Does the AES encryption of a plain text.
 *
 * \param configPtr Holds a pointer to the configuration defining the encryption mode.\n
 * \param symKeyPtr Holds a pointer to the key which has to be used for the encryption operation.\n
 * \param initVectPtr Holds a pointer to initialization vector which has to be used
 *      for the encryption operation.
 * \param initVectLength Length in bytes of the initialization vector.\n
 * \param plainTextPtr  Holds a pointer to the plain text that shall be encrypted.
 * \param inputLength   Contains the length of the plain text in bytes.
 * \param cipherTextPtr Holds a pointer to the memory location which will hold the
 *                      encrypted text.
 *
 * \note symKeyPtr->length shall be 1
 * \note symKeyPtr->data[0] shall contains the value taken from \ref Cry_HsmKeySlotIdType
 * \note initVectorLength shall be 16
 * \note The memory location receiving the cipher text must provide at least as
 *       much space as given by inputLength
 *
 * \retval CSM_E_OK             Request successful
 * \retval CSM_E_BUSY           Request failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK         Request failed
 ****************************************************************************************/
Csm_ReturnType SampleCode_HsmAesEncrypt(const Cry_HsmAesEncryptConfigType* configPtr, const Csm_SymKeyType* symKeyPtr,
                                        const uint8* initVectPtr, uint32 initVectLength,
                                        const uint8* plainTextPtr, uint32 inputLength, uint8* cipherTextPtr)
{
    uint32 outputLength = inputLength;
    volatile Csm_ReturnType retVal;

    retVal = Cry_HsmAesEncryptStart(configPtr, symKeyPtr, initVectPtr, initVectLength);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

    if (retVal != CSM_E_BUSY)
	{

    	retVal = Cry_HsmAesEncryptUpdate(configPtr, plainTextPtr, inputLength, cipherTextPtr, &outputLength);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

    	retVal = Cry_HsmAesEncryptFinish(configPtr, NULL_PTR, NULL_PTR);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

    	if ((retVal == CSM_E_OK) && (outputLength != inputLength))
    	{
    		retVal = CSM_E_NOT_OK;	/* Output length does not match: failed */
    	}
    }
    else
    {
    	TEST_PRINTF("Cry_HsmAesEncryptStart(): CSM_E_BUSY\n");
    }
    return (retVal);
}

/*************************************************************************************//**
 * Does MAC generation.
 *
 * \param symKeyPtr   Holds a pointer to the key which has to be used for the encryption operation.\n
 *                    keyPtr->length shall be 1\n
 *                    keyPtr->data[0] shall be a value taken from \ref Cry_HsmKeySlotIdType
 * \param inputPtr    Pointer to the data for which the MAC shall be computed
 * \param inputLength Contains the number of bytes for which the MAC shall be computed.
 * \param macPtr      Holds a pointer to the memory location which will hold the result of
 *      the MAC generation.\n
 * \param macLength   Contains the size of the buffer provided by macPtr.\n
 *
 * \retval CSM_E_OK             Request successful
 * \retval CSM_E_BUSY           Request failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK         Request failed
 ****************************************************************************************/
Csm_ReturnType SampleCode_CMacGenerate(const Csm_SymKeyType* symKeyPtr, const HsmAes_Block* inputPtr, uint32 inputLength,
		                               HsmAes_Block* macPtr, uint32 macLength)
{
	const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;
	/*uint32 realMacLength = macLength * 8; */
	uint32 realMacLength = macLength;
	volatile Csm_ReturnType retVal;

	retVal = Cry_HsmAesCMacGenerateStart(config, symKeyPtr);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
	if (retVal != CSM_E_BUSY)
	{
		retVal = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*) inputPtr, inputLength);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
		retVal = Cry_HsmAesCMacGenerateFinish(config, (uint8*)macPtr, &realMacLength, FALSE);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
	}
    else
    {
    	TEST_PRINTF("Cry_HsmAesCMacGenerateStart(): CSM_E_BUSY\n");
    }

	/*if ((retVal == CSM_E_OK) && (realMacLength != (macLength * 8)))*/
	if ((retVal == CSM_E_OK) && (realMacLength != (macLength )))
	{
		retVal = CSM_E_NOT_OK;	/* Output length does not match: failed */
	}

	return (retVal);
}
#if 1
Csm_ReturnType SampleCode_CMacGenerateB(const Csm_SymKeyType* symKeyPtr, const uint32* inputPtr, uint32 inputLength,
										HsmAes_Block* macPtr, const HsmAes_Block* headerPtr)
{
  const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;
  uint32 macLength = 16;
  uint32 realMacLength = macLength;
  volatile Csm_ReturnType retVal;
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  volatile Csm_ReturnType MacGen_retVal = CSM_E_OK;
#endif
  retVal = Cry_HsmAesCMacGenerateStart(config, symKeyPtr);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
  if (retVal != CSM_E_BUSY)
  {
    retVal = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*) headerPtr, 16);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
    if(RetTestHsm_MacGenerate == CSM_E_NOT_OK)
    {
      MacGen_retVal = CSM_E_NOT_OK;
    }
    TEST_PRINTF("RetTestHsm_MacGenerate return value for 1st update :%d\n",RetTestHsm_MacGenerate);
#endif
    retVal = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*) inputPtr, inputLength);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
    TEST_PRINTF("RetTestHsm_MacGenerate return value for 2nd update :%d\n",RetTestHsm_MacGenerate);
    if((RetTestHsm_MacGenerate == CSM_E_NOT_OK) ||
            (MacGen_retVal == CSM_E_NOT_OK))
    {
      MacGen_retVal = CSM_E_NOT_OK;
    }
    else
    {
      MacGen_retVal = CSM_E_OK;
    }
#endif
    retVal = Cry_HsmAesCMacGenerateFinish(config, (uint8*)macPtr, &realMacLength, FALSE);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
  }
    else
    {
      TEST_PRINTF("Cry_HsmAesCMacGenerateStart(): CSM_E_BUSY\n");
    }
  if (
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
          (MacGen_retVal == CSM_E_NOT_OK)||
#endif
          ( (retVal == CSM_E_OK)
          && (realMacLength != (macLength ))))
  {
    retVal = CSM_E_NOT_OK;  /* Output length does not match: failed */
  }
  return (retVal);
}
#endif
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"

#if (CRY_HSM_MAC_SAFE_VERIFY == 1)
#define SwapBytes(w) ((0x00FFU & ((uint16)(w)>>8)) | (0xFF00U & ((uint16)(w)<<8)))
#define ToDword(h,l) (((uint32)l) | (0xFFFF0000UL & ((uint32)h<<16)))

_IFXEXTERN_ IFX_INLINE uint32 CalculateMacCrc (const void* macIn, uint32 verifyLength)
{
	uint32 crc = 0x0UL;
	uint32 dwCount = verifyLength >> 5;					/* Full dwords */
	uint32 bitCnt  = (verifyLength & 0x00000001F);      /* Remaining bits: 0 .. 31 */
	uint32 mask = 0;
	uint32 i;
	const uint32* macPtr = (const uint32*)macIn;

	if (bitCnt > 0)
	{
		mask = 0xFFFFFFFFUL << (32U-bitCnt);
	}

	for (i = 0; i <= dwCount; i++)
	{
		uint32 value = *macPtr;
		/* value must be passed in big-endian byte order */
		value = ToDword(SwapBytes(value & 0xFFFFU), SwapBytes((value >> 16) & 0xFFFF));

		if (i < dwCount)
		{
			crc = __crc32(crc, value);
		}
		else if (mask != 0UL)
		{
			/* Mask remaining bits, finish calculation */
			value = value & mask;
			crc = __crc32(crc, value);
		}
		else
		{
			/* finished */
		}
		macPtr++;
	}

	return (crc);
}
#endif

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
/*************************************************************************************//**
 * Does MAC verification.
 *
 * \param symKeyPtr     Holds a pointer to the key which has to be used for the encryption operation.\n
 *                      keyPtr->length shall be 1
 *                      keyPtr->data[0] shall be a value taken from \ref Cry_HsmKeySlotIdType
 * \param messagePtr    Pointer to the data for which the MAC shall be verified
 * \param messageLength Contains the number of bytes for which the MAC shall be computed.
 * \param macInPtr      Pointer to the MAC to be verified
 * \param macLength     Contains the size of the MAC provided by macInPtr.\n
 *
 * \retval CSM_E_OK             Request successful
 * \retval CSM_E_BUSY           Request failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK         MAC could not be verified
 ****************************************************************************************/
boolean SampleCode_CMacVerify(const Csm_SymKeyType *keyPtr, const HsmAes_Block* messagePtr, uint32 messageLength,
		                      const HsmAes_Block* macInPtr, uint32 verifyLength)
{
    boolean verified = FALSE;
    Csm_VerifyResultType* resPtr;
    volatile Csm_ReturnType result;
    const Cry_HsmAesCMacVerifyConfigType* configPtr = &Cry_kHsmAesCMacVerifyConfig;
#if (CRY_HSM_MAC_SAFE_VERIFY == 0)
    Csm_VerifyResultType verifyResult;
    resPtr = &verifyResult;
#else
    Csm_SafeVerifyResultType verifyResult;
    resPtr = &(verifyResult.Result);
#endif

    *resPtr = CSM_E_VER_NOT_OK;

    result = Cry_HsmAesCMacVerifyStart(configPtr, keyPtr);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif


    if (result != CSM_E_BUSY)
    {
    	result = Cry_HsmAesCMacVerifyUpdate(configPtr, (const uint8*)messagePtr, messageLength);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

		result = Cry_HsmAesCMacVerifyFinish(configPtr, (const uint8*) macInPtr->Data, verifyLength * 8, (Csm_VerifyResultType*)&verifyResult);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
	    if ((result == CSM_E_OK) && (*resPtr == CSM_E_VER_OK))
	    {
	    	verified = TRUE;
	    }
#if (CRY_HSM_MAC_SAFE_VERIFY == 1)
		if (verified)
		{
			TEST_VALIDATE(verifyLength <= 16);

			if ((CSM_E_VER_OK == verifyResult.Result) &&
				((verifyLength * 8) == verifyResult.BitsCompared1) &&
				((verifyResult.BitsCompared1 << 1) == verifyResult.BitsCompared2))
			{
				/* Check the CRCs */
				uint32 invertedMac[4];
				uint32* macPtr = (uint32*) macInPtr->Data;
				uint32 dwCount = (verifyLength + 31U) >> 5;
				uint32 i;
				for (i = 0; i < dwCount; i++)
				{
					invertedMac[i] = ~(*macPtr);
					macPtr++;
				}
				if (verifyResult.CodedResult1 != CalculateMacCrc(macInPtr->Data, verifyLength) ||
					verifyResult.CodedResult2 != CalculateMacCrc(invertedMac, verifyLength))
				{
					verified = FALSE;
				}
			}
			else
			{
				verified = FALSE;
			}
		}
		TEST_VALIDATE(verified == TRUE);
#endif
	}
    else
    {
    	TEST_PRINTF("Cry_HsmAesCMacVerifyStart(): CSM_E_BUSY\n");
    }

    return verified;
}

/*************************************************************************************//**
 * Generates the M1 message needed to load a key into SHE.
 * Also used for the first part of M4 in the verification message
 *
 * \param keyId        ID of the key that is to be loaded
 * \param authId       ID of the authentication key
 * \param uidWildCard  TRUE:  empty UID' shall be used
 *                     FALSE: the real UID of the chip shall be used
 * \param resultPtr    Holds a pointer to the HsmAes_Block structure where
 *                     the resulting message will be stored.
 *
 * \retval None
 ****************************************************************************************/
static void SampleCode_GenerateM1_M40(HsmCom_KeyAddr keyId, HsmCom_KeyAddr authId, boolean uidWildCard, HsmAes_Block* resultPtr)
{
	uint8* dataPtr;
	volatile Csm_ReturnType ResultVal;

	/* First copy UID */
	if (uidWildCard == FALSE)
	{
	    ResultVal = CSM_E_OK;
	    resultPtr->Data[0] =  UidData.Data[0];
	    resultPtr->Data[1] =  UidData.Data[1];
	    resultPtr->Data[2] =  UidData.Data[2];
	    resultPtr->Data[3] =  UidData.Data[3];
	}
	else
	{
		*resultPtr = SampleCode_Cmac_constZero;
	}

	dataPtr = (uint8*) (&(resultPtr->Data[3]));	  /* keyId and authId go into the last byte of data[3] */
	dataPtr[3] = ((keyId & 0x0F) << 4) | (authId & 0x0F);
	UNUSED_PARAMETER(ResultVal);
}

/*************************************************************************************//**
 * Generates the M2 message needed to load a key into SHE.
 *
 * \param keyPtr           Holds a pointer to the key to be used for the AES CBC encryption
 * \param inputPtr         Holds a pointer to two 16 Byte blocks containing the
 *                         concatenation of the new key counter value CID�
 *                         the according flags FID� a pattern to fill the first block
 *                         with ��bits and the new key value
 * \param protKeyPtr       Holds a pointer to the ProtectedKey structure
 *                         the resulting M2 message will be stored in protectedKeyPtr->M2[]
 *
 * \retval CSM_E_OK             Request successful
 * \retval CSM_E_BUSY           Request failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK         Request failed
 ****************************************************************************************/
static Csm_ReturnType SampleCode_GenerateM2(const HsmAes_Block *keyPtr, const HsmAes_Block *newKey,
		                                    uint32 counter, uint32 flags, ProtectedKey* protKeyPtr)
{
    const Cry_HsmAesEncryptConfigType* config = &Cry_kHsmAesEncryptConfigModeCbc;
    const Csm_SymKeyType ramKey = {1, {CRY_HSM_RAM_KEY}};
	uint32 inputLength = sizeof(inputM2);
	uint32 tempData;
	Csm_ReturnType retVal;

	inputM2[0] = SampleCode_Cmac_constZero;                  /* Initialize with zeros */
	tempData  =  counter << 4;	                             /* Upper 28 bits: new counter */
	tempData |= ((uint8)(flags)) >> 4;                       /* Upper four flag bits go into lower bits   */
	inputM2[0].Data[0] = TEST_REVERSE_BYTES_DWORD(tempData);

	inputM2[0].Data[1] = (uint32)((uint8)(flags & 0x0FUL)) << 4; /* Lowest flag bits are low bits in next dword */
	inputM2[1] = *newKey;

    retVal = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,keyPtr,16);

    if (retVal == CSM_E_OK)
    {
    	retVal = SampleCode_HsmAesEncrypt(config, &ramKey, (const uint8*)&SampleCode_Cmac_constZero, sizeof(SampleCode_Cmac_constZero),
    			                         (const uint8*) inputM2, inputLength, (uint8*) &(protKeyPtr->M2));
    }

    return (retVal);
}

/*************************************************************************************//**
 * Generates the M3 verification message needed to load a key into SHE.
 *
 * \param keyPtr        Holds a pointer to the key to be used for the MAC generation
 * \param m1m2Ptr       Holds a pointer to three 16 Byte blocks containing the
 *                      M1 and M2 messages for which a MAC is generated
 * \param protKeyPtr    Holds a pointer to the ProtectedKey structure to be filled out
 *                      the resulting MAC will be stored in protectedKeyPtr->M3
 *
 * \retval CSM_E_OK             Request successful
 * \retval CSM_E_BUSY           Request failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK         Request failed
 ****************************************************************************************/
static Csm_ReturnType SampleCode_GenerateM3(const HsmAes_Block *keyPtr, const void* m1m2Ptr, ProtectedKey* protKeyPtr)
{
	uint32 macLength     = sizeof(HsmAes_Block);
	uint32 inputLength   = 3*sizeof(HsmAes_Block);

    const Csm_SymKeyType ramKey = {1, {CRY_HSM_RAM_KEY}};

    Csm_ReturnType retVal;

    retVal = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,keyPtr,16);

    if (retVal == CSM_E_OK)
    {
    	retVal = SampleCode_CMacGenerate(&ramKey, m1m2Ptr, inputLength,&(protKeyPtr->M3[0]), macLength);
    }

    return (retVal);
}

/*************************************************************************************//**
 * XORs the values of two input HsmAes_Blocks into an output block as needed
 * for the key derivation function (KDF)
 *
 * \param inBlockAPtr  Pointer to first input block
 * \param inBlockBPtr  Pointer to second input block
 * \param outBlockPtr  Pointer to output block
 *
 * \retval None
 ****************************************************************************************/
static void SampleCode_xorLocal(const HsmAes_Block *inBlockAPtr, const volatile HsmAes_Block *inBlockBPtr, volatile HsmAes_Block *outBlockPtr)
{
	outBlockPtr->Data[0] = inBlockAPtr->Data[0] ^ inBlockBPtr->Data[0];
	outBlockPtr->Data[1] = inBlockAPtr->Data[1] ^ inBlockBPtr->Data[1];
	outBlockPtr->Data[2] = inBlockAPtr->Data[2] ^ inBlockBPtr->Data[2];
	outBlockPtr->Data[3] = inBlockAPtr->Data[3] ^ inBlockBPtr->Data[3];
}

/*************************************************************************************//**
 * Compares the values of two input HsmAes_Blocks
 *
 * \param inBlockAPtr  Pointer to first input block
 * \param inBlockBPtr  Pointer to second input block
 *
 * \retval TRUE  Block Data are equal
 *         FALSE Block Data are not equal
 ****************************************************************************************/
static boolean SampleCode_EqualBlocks(const HsmAes_Block *inBlockAPtr, const HsmAes_Block *inBlockBPtr)
{
	boolean isEqual = TRUE;
	uint32 i;
	for (i = 0; (i < 4U) && (isEqual == TRUE); i++)
	{
		if (inBlockAPtr->Data[i] != inBlockBPtr->Data[i])
		{
			isEqual = FALSE;
		}
	}
	return (isEqual);
}

/*************************************************************************************//**
 * Implements the key derivation function using the Miyaguchi-Preneel compression algorithm
 *
 * \param keyPtr          Key to be used for the key derivation
 * \param updateConstPtr  Pointer the update constant to be used
 * \param derivedKeyPtr   Pointer where the derived key will be stored
 *
 * \retval CSM_E_OK       Key derivation successful
 * \retval CSM_E_BUSY     Key derivation failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK   Key derivation failed
 ****************************************************************************************/
static Csm_ReturnType SampleCode_Kdf(const HsmAes_Block *keyPtr, const HsmAes_Block *updateConstPtr, HsmAes_Block *derivedKeyPtr)
{
	/*HsmAes_Block temp1;
	HsmAes_Block temp2;*/
	Csm_ReturnType csmRes;
    const Csm_SymKeyType ramKey = {1, {CRY_HSM_RAM_KEY}};
	/*HsmAes_Block state = SampleCode_Cmac_constZero;*/
    state = SampleCode_Cmac_constZero;

    /* Load the key for first encoding */
    csmRes = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,&state,16);

	if (csmRes == CSM_E_OK)
	{
		csmRes = SampleCode_HsmAesEcbEncrypt(&ramKey, keyPtr, &temp1);
		if (csmRes == CSM_E_OK)
		{
			SampleCode_xorLocal(keyPtr, &temp1, &temp2);
			SampleCode_xorLocal(&temp2, &state, &state);

			/* Current state is key for first encoding */
			csmRes = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,&state,16);
			if (csmRes == CSM_E_OK)
			{
				csmRes = SampleCode_HsmAesEcbEncrypt(&ramKey, updateConstPtr, &temp1);
				SampleCode_xorLocal(updateConstPtr, &temp1, &temp2);
				SampleCode_xorLocal(&temp2, &state, derivedKeyPtr);
			}
		}
	}
	return (csmRes);
}

void Read_g_KeyStorageFunc(Cry_HsmKeySlotIdType authId, HsmAes_Block *keyPtr)
{
    HsmCom_KeyAddr KeyauthId = SampleCode_keyMap[authId];
    HsmAes_Block *TempkeyPtr = (HsmAes_Block *) &g_KeyStorage[KeyauthId].key;
    keyPtr->Data[0] = TempkeyPtr->Data[0];
    keyPtr->Data[1] = TempkeyPtr->Data[1];
    keyPtr->Data[2] = TempkeyPtr->Data[2];
    keyPtr->Data[3] = TempkeyPtr->Data[3];
}
void Update_g_KeyStorageFunc(Cry_HsmKeySlotIdType authId, const HsmAes_Block *keyPtr)
{
    HsmCom_KeyAddr KeyauthId = SampleCode_keyMap[authId];
    HsmAes_Block *TempkeyPtr = (HsmAes_Block *) &g_KeyStorage[KeyauthId].key;
    TempkeyPtr->Data[0] = keyPtr->Data[0];
    TempkeyPtr->Data[1] = keyPtr->Data[1];
    TempkeyPtr->Data[2] = keyPtr->Data[2];
    TempkeyPtr->Data[3] = keyPtr->Data[3];
}
/*************************************************************************************//**
 * Creates the protected key needed for key loading, by filling the M1, M2 and M3 messages
 *
 * \param keyId         ID of the key that is to be loaded
 * \param authId        ID of the authentication key
 * \param newKeyPtr     Pointer the new key value
 * \param flags         Security flags for this key
 * \param counter       New counter value for this key
 * \param uidWildCard   TRUE:  empty UID' shall be used
 *                      FALSE: the real UID of the chip shall be used
 * \param protKeyPtr    Pointer to the ProtectedKey structure to be filled
 *
 * \retval CSM_E_OK     M1, M2 and M3 were successfully generated and stored in the
 *         corresponding members of *protectedKey
 * \retval CSM_E_BUSY     Operation failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK   Operation failed
 ****************************************************************************************/
static Csm_ReturnType SampleCode_CreateProtectedKey (HsmCom_KeyAddr keyId, HsmCom_KeyAddr authId, const HsmAes_Block* newKeyPtr,
		                                             uint32 flags, uint32 counter, boolean uidWildCard, ProtectedKey* protKeyPtr)
{
	const HsmAes_Block *keyPtr = (const HsmAes_Block *) &g_KeyStorage[authId].key;
	uint16 keyPage;
	Csm_ReturnType csmRes;

	if (keyId < HSMCOM_KEY_11)
	{
		keyPage = 0;
	}
	else
	{
		keyPage = 1;
	}

	SampleCode_GenerateM1_M40(keyId, authId, uidWildCard, &(protKeyPtr->M1[0]));

	/* Derive the Keys K1 and K2 needed for M2 and M3 generation */
	csmRes = SampleCode_Kdf (keyPtr, &g_KeyUpdateEncC[keyPage],&K1);

	if (csmRes == CSM_E_OK)
	{
		csmRes = SampleCode_Kdf (keyPtr, &g_KeyUpdateMacC[keyPage],&K2);
	}

	if (csmRes == CSM_E_OK)
	{
		csmRes = SampleCode_GenerateM2(&K1, newKeyPtr, counter, flags, protKeyPtr);
		if (csmRes == CSM_E_OK)
		{
			csmRes = SampleCode_GenerateM3(&K2, &(protKeyPtr->M1), protKeyPtr);
		}
	}
	if (csmRes == CSM_E_OK)
	{
		/* Invalidate M4, M5 */
		int i;
		for (i = 0; i < 4; i++)
		{
			protKeyPtr->M4[0].Data[i] = 0x5A5A5A5AU;
			protKeyPtr->M4[1].Data[i] = 0x5A5A5A5AU;
			protKeyPtr->M5[0].Data[i] = 0xA5A5A5A5u;
		}
	}

    return (csmRes);
}

/*************************************************************************************//**
 *  Checks the validity of the update verification messages M4 and M5
 *
 * \param keyId         ID of the key that has been loaded
 * \param authId        ID of the authentication key
 * \param newKeyPtr     Pointer the new key value
 * \param counter       New counter value for this key
 * \param uidWildCard   TRUE:  empty UID' shall be used
 *                      FALSE: the real UID of the chip shall be used
 * \param protKeyPtr    Pointer to the ProtectedKey structure returned by SHE
 *
 * \retval CSM_E_OK     M1, M2 and M3 were successfully generated and stored in the
 *         corresponding members of *protectedKey
 * \retval CSM_E_BUSY     Operation failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK   Operation failed
 ****************************************************************************************/
static Csm_ReturnType SampleCode_CheckVerificationMessages(HsmCom_KeyAddr keyId, HsmCom_KeyAddr authId, const HsmAes_Block* newKeyPtr,
		                                                   uint32 counter, boolean uidWildCard, const ProtectedKey* protKeyPtr)
{
	uint16 keyPage;
	Csm_ReturnType csmRes;
	const Csm_SymKeyType ramKey = {1, {CRY_HSM_RAM_KEY}};
	if (keyId < HSMCOM_KEY_11)
	{
		keyPage = 0;
	}
	else
	{
		keyPage = 1;
	}

	/* Derive the Keys K3 and K4 needed for M4 and M5 verification */

    /* K3 = KDF(keyID, g_KeyUpdateEncC) */
	csmRes = SampleCode_Kdf (newKeyPtr, &g_KeyUpdateEncC[keyPage],&K3);

	if (csmRes == CSM_E_OK)
	{
		/* K4 = KDF(keyID, g_KeyUpdateMacC) */
		csmRes = SampleCode_Kdf (newKeyPtr, &g_KeyUpdateMacC[keyPage],&K4);
	}

	if (csmRes == CSM_E_OK)
	{
		uint32 cid;
		/* generate the expected M4 message */
		/* UID|ID|AuthID */
		SampleCode_GenerateM1_M40(keyId, authId, uidWildCard, &(M4[0]));

		/* M4' = ECB(K3, CID) */
		cid = (counter << 4ul) | 0x08ul;
		M4[1].Data[0] = TEST_REVERSE_BYTES_DWORD(cid);
		M4[1].Data[1] = 0;
		M4[1].Data[2] = 0;
		M4[1].Data[3] = 0;

		/* Load the key for encoding */
		csmRes = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block*)&K3,16);

		if (csmRes == CSM_E_OK)
		{
			csmRes = SampleCode_HsmAesEcbEncrypt(&ramKey, (const HsmAes_Block*)&(M4[1]), &(M4[1]));
		}
		if (csmRes == CSM_E_OK)
		{
			/* Compare expected M4 blocks with M4 verification message */
			if ((SampleCode_EqualBlocks((const HsmAes_Block*)&(M4[0]), &(protKeyPtr->M4[0])) != TRUE) ||
				(SampleCode_EqualBlocks((const HsmAes_Block*)&(M4[1]), &(protKeyPtr->M4[1])) != TRUE))
			{
				/* Blocks are different: fail */
				csmRes = CSM_E_NOT_OK;
			}
		}
	}
	/* Verify M5: must be valid CMAC(K4, M4) */
	if (csmRes == CSM_E_OK)
	{
		uint32 macLength     = sizeof(HsmAes_Block);
		uint32 messageLength  = 2*sizeof(HsmAes_Block);

		/* Load the key for MAC verification */
		csmRes = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block*) &K4,16);

	    if (csmRes == CSM_E_OK)
	    {
	        if (VerifyMac(&ramKey, &(M4[0]),&(protKeyPtr->M5[0]), messageLength, macLength) == FALSE)
	    	{
	    		csmRes = CSM_E_NOT_OK;
	    	}
	    }
	}
	return (csmRes);
}

/*************************************************************************************//**
 * Function that does finally the loading of a key into SHE
 *
 * \param protKeyPtr    Pointer to the protected key, M1, M2 and M3 are filled out
 * \param keyLoadCfgPtr Pointer to the load configuration to be used
 *                      This defines whether the key is to be loaded in
 *                      Page 0 or Page 1 (SHE+ extension)
 *
 * \retval CSM_E_OK     Key could be loaded successfully
 * \retval CSM_E_BUSY   Operation failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK Operation failed
 ****************************************************************************************/
static Csm_ReturnType SampleCode_LoadKey(ProtectedKey *protKeyPtr, const Cry_HsmKeyLoadConfigType* keyLoadCfgPtr)
{
    volatile Csm_ReturnType csmRes;
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    volatile uint32 DelayCount = 0xffff;
#ifdef CONTROLLER_TC23x
    uint32 TrapDisStat_tst;
#endif
#endif

    Csm_SymKeyType tmp;
    csmRes = Cry_HsmKeyLoadStart(keyLoadCfgPtr);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmKeyLoadMainFunction, &g_TestHsm_key.callbackSet);
#endif


	if (csmRes != CSM_E_BUSY)
	{
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
#ifdef CONTROLLER_TC23x
	    TrapDisStat_tst = HsmMcal_GetTrapDisableStatus();
	    HsmMcal_DisableEccErrors();
#endif
#endif
	    csmRes = Cry_HsmKeyLoadUpdate(keyLoadCfgPtr, (const uint8*)protKeyPtr, 64U);

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
	    while(DelayCount != 0x00)
	    {
	        DelayCount--;
	    }
	    TEST_WAIT(&Cry_HsmKeyLoadMainFunction, &g_TestHsm_key.callbackSet);
#ifdef CONTROLLER_TC23x
        HsmMcal_EnableEccErrors(TrapDisStat_tst);
#endif
#endif

		csmRes = Cry_HsmKeyLoadFinish(keyLoadCfgPtr, &tmp);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmKeyLoadMainFunction, &g_TestHsm_key.callbackSet);
#endif

	}
    else
    {
    	TEST_PRINTF("Cry_HsmKeyLoadStart(): CSM_E_BUSY\n");
    }

	if (( csmRes == CSM_E_OK) && (tmp.length == 48))
	{
		HsmCom_CopyArray(protKeyPtr->M4[0].Data, (uint32*)tmp.data, 48/sizeof(uint32));
	}
	else
	{
		csmRes = CSM_E_NOT_OK;	/* Output length does not match: failed */
	}
    return (csmRes);
}

/*************************************************************************************//**
 * Interface function to load an encrypted (NVM or RAM) key into SHE
 *
 * \param keySlotId     ID of the key slot that is to be loaded
 * \param authId        ID of the authentication key
 *                      HSMCOM_SECRET_KEY is not allowed as authId
 * \param newKeyPtr     Pointer the new key value
 * \param flags         Security flags for this key
 * \param counter       New counter value for this key
 * \param uidWildCard   TRUE:  empty UID' shall be used
 *                      FALSE: the real UID of the chip shall be used
 * \param protKeyPtr    Optional, may be NULL_PTR
 *                      This parameter can be used for testing the function
 *                      against a known test vector.
 *                      If it is != NULL_PTR the generated protected key is returned to the caller,
 *                      that was passed to SHE and filled with the verification messages M4 and M5.
 *
 * \retval CSM_E_OK     Key could be loaded successfully
 * \retval CSM_E_BUSY   Operation failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK Operation failed
 ****************************************************************************************/
Csm_ReturnType SampleCode_LoadEncryptedKey (Cry_HsmKeySlotIdType keySlotId, Cry_HsmKeySlotIdType authSlotId, const HsmAes_Block* newKey,
		                                    uint32 flags, uint32 counter, boolean guiWildCard, ProtectedKey* protKeyPtr)
{
	HsmCom_KeyAddr keyId  = SampleCode_keyMap[keySlotId];
	HsmCom_KeyAddr authId = SampleCode_keyMap[authSlotId];
    const Cry_HsmKeyLoadConfigType* keyLoadCfgPtr = &Cry_kHsmKeyLoadConfigPage0;
    Csm_ReturnType csmRes;

    if (protKeyPtr == NULL_PTR)
    {
    	protKeyPtr = &protKey;
    }
    TestCd_KeyMng_GetUid((uint8*)&UidData);
    /* Create M1, M2, M3 messages */
    csmRes = SampleCode_CreateProtectedKey (keyId, authId, (const HsmAes_Block*) newKey, flags, counter, guiWildCard, protKeyPtr);

	/* Now load the key */
    if (keyId >= HSMCOM_KEY_11)
	{
		keyLoadCfgPtr = &Cry_kHsmKeyLoadConfigPage1;
	}


    if (csmRes == CSM_E_OK)
    {
    	csmRes = SampleCode_LoadKey(protKeyPtr, keyLoadCfgPtr);
    }

    if (csmRes == CSM_E_OK)
    {
    	/* Check the update verification messages M4/M5 generated by SHE */
    	/* If OK, update new key in local buffer */
    	csmRes = SampleCode_CheckVerificationMessages(keyId, authId, (const HsmAes_Block*) newKey, counter, guiWildCard, protKeyPtr);
    	if (csmRes == CSM_E_OK)
    	{
    		g_KeyStorage[keyId].key     = *((const HsmAes_Block*) newKey);
    		g_KeyStorage[keyId].counter = counter;
    		g_KeyStorage[keyId].flags   = flags;
    	}
    }
    return (csmRes);
}

/*************************************************************************************//**
 * Interface function to export the RAM key from SHE
 * The RAM key must have been loaded before using SampleCode_LoadPlainKey()
 * The key is returned in encrypted format and can not be decrypted outside SHE
 * It can only be used to be loaded again later using SampleCode_LoadRamKey()
 *
 * \param protKeyPtr    Holds a pointer to the memory location where the
 *                      encrypted RAM key will be stored.
 *                      This parameter can be used for testing the function.
 *
 * \retval CSM_E_OK     Key was successfully exported
 * \retval CSM_E_BUSY   Operation failed due to underlying HSM communication is busy
 * \retval CSM_E_NOT_OK Export failed
 ****************************************************************************************/
Csm_ReturnType SampleCode_ExportKey(ProtectedKey *protKeyPtr)
{
    volatile Csm_ReturnType csmRes;
    uint32 keyLength;
    const Cry_HsmKeyExportConfigType* config = &Cry_kHsmKeyExportConfig;

    csmRes = Cry_HsmKeyExportStart(config, NULL_PTR, NULL_PTR);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
#endif
	if ( csmRes != CSM_E_BUSY )
	{
#if 1
		keyLength = sizeof(ProtectedKey);
#else
		keyLength = 64U;
#endif
/*    csmRes = Cry_HsmKeyExportUpdate(config, (uint8*) protKeyPtr, &keyLength);*/
        csmRes = Cry_HsmKeyExportUpdate(config, (uint8*) protKeyPtr, &keyLength);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
#endif
		csmRes = Cry_HsmKeyExportFinish(config);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
#endif
	}
    else
    {
    	TEST_PRINTF("Cry_HsmKeyExportStart(): CSM_E_BUSY\n");
    }
    return (csmRes);
}

/*************************************************************************************//**
 * Load the RAM key, preliminary function
 ****************************************************************************************/
Csm_ReturnType SampleCode_LoadRamKey(ProtectedKey *protKeyPtr)
{
	Csm_ReturnType csmRes;
	ProtectedKey savedProtKey = *protKeyPtr;

	/* Clear the verification messages in the input structure */
	protKeyPtr->M4[0] = SampleCode_Cmac_constZero;
	protKeyPtr->M4[1] = SampleCode_Cmac_constZero;
	protKeyPtr->M5[0] = SampleCode_Cmac_constZero;

	csmRes = SampleCode_LoadKey(protKeyPtr, &Cry_kHsmKeyLoadConfigRamKey);

	/* Verify that the expected verification messages were returned */
	if ((csmRes != CSM_E_OK) &&
		((SampleCode_EqualBlocks((const HsmAes_Block*)&(savedProtKey.M4[0]), &(protKeyPtr->M4[0])) != TRUE) ||
		 (SampleCode_EqualBlocks((const HsmAes_Block*)&(savedProtKey.M4[1]), &(protKeyPtr->M4[1])) != TRUE) ||
		 (SampleCode_EqualBlocks((const HsmAes_Block*)&(savedProtKey.M5[0]), &(protKeyPtr->M5[0])) != TRUE)))
	{
		csmRes = CSM_E_NOT_OK;
	}

	return (csmRes);
}
#define BMI_HDR_ADDR 0xAF400004

void SampleCode_InvalidBootMac(const HsmAes_Block *keyPtr , HsmAes_Block *bootMacPtr)
{
    bootMacPtr->Data[0] = keyPtr->Data[0];
    bootMacPtr->Data[1] = keyPtr->Data[1];
    bootMacPtr->Data[2] = keyPtr->Data[2];
    bootMacPtr->Data[3] = keyPtr->Data[3];
}

Csm_ReturnType SampleCode_ComputeBootMac(const HsmAes_Block *keyPtr , HsmAes_Block *bootMacPtr)
{
  Csm_ReturnType csmRes;
  uint32 BL_SIZE, BL_CFG;
  uint32 BL_STAD ,*BL_START;
  HsmAes_Block sizeBlock;
  BL_STAD = *(uint32 *)BMI_HDR_ADDR;
  BL_START = (uint32 *)(BL_STAD-4);
  BL_CFG = *BL_START;
  BL_SIZE = (BL_CFG & 0x00FFFFFF);
  sizeBlock.Data[0] = 0;
  sizeBlock.Data[1] = 0;
  sizeBlock.Data[2] = 0;
  sizeBlock.Data[3] = __REV(BL_SIZE);
  print_f("\n");
  print_f("BL_SART: 0x%08x\n", BL_START);
  print_f("BL_SIZE : 0x%06x\n", BL_SIZE);
  csmRes = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,keyPtr,16);
  if (CSM_E_OK == csmRes)
  {
    csmRes = SampleCode_CMacGenerateB(KEY_BOOT_MAC_RAM_KEY, (uint32 *)(BL_STAD - 4),
    									BL_SIZE, bootMacPtr, &sizeBlock);
  }
  if (CSM_E_OK == csmRes)
  {
    print_f("Computed BOOT MAC : ");print128(bootMacPtr);print_f("\n");
  }
  else
  {
    print_f("Computed BOOT MAC is failed\n");
  }
  return csmRes;
}
void TestCd_KeyMng_GetUid(uint8 *UidPtr)
{
    Csm_ReturnType CsmRes;
    uint8* UIDPtr ;
    uint16 LoopValue;
    CsmRes = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,&RAM_Key,16);

   if(CsmRes == CSM_E_OK)
   {
       CsmRes = SampleCode_ExportKey((ProtectedKey*)&ExportedKey);
   }
   /* Get M1 from the exported key, byte 15 contains the RAM key id /
    * secret key id, must be set to 0
    * This is then the UID' for key load operations
    */
   if ( CsmRes == CSM_E_OK)
   {
       UIDPtr = (uint8 *) &ExportedKey.M1[0];

       for (LoopValue = 0U; LoopValue < 15U; LoopValue++)
       {
           UidPtr[LoopValue] = UIDPtr[LoopValue];
       }
   }
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymKeyExtractCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
    {
        g_TestHsm_key.callbackSet = 1;
        g_TestHsm_key.result = result;
    }
    else
    {
        g_TestHsm_key.callbackSet = 2;
#if ITF
#else
        TEST_PRINTF("Key function failed in mainloop with ret value %d \n ", result);
#endif
    }
#if ITF
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF

    switch(Cry_PrimStatusAsync[CRY_HSM_KEY_LOAD_PLAIN])
    {
      case ASYNC_STATE_START:
      {
         KeyLoadPlainCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
          KeyLoadPlainCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
          KeyLoadPlainCallBackFinishResult = result;
         break;
      }
      default:
      {
            break;
      }
    }
    switch(Cry_PrimStatusAsync[CRY_HSM_KEY_WRAP])
    {
      case ASYNC_STATE_START:
      {
         KeyExportCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
          KeyExportCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
          KeyExportCallBackFinishResult = result;
         break;
      }
      default:
      {
            break;
      }
    }
    #endif
#endif

}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymKeyExtractServiceFinishNotification(void)
{
#if ((ITF) && (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    if(Cry_PrimStatusAsync[CRY_HSM_KEY_LOAD_PLAIN] == ASYNC_STATE_FINISH)
    {
        KeyLoadPlainFinishNotify = 1;
    }
    else
    {
        KeyExportFinishNotify = 1;
    }

#endif
}

void Csm_SymKeyWrapSymCallbackNotification(Csm_ReturnType result)
{
    Csm_SymKeyExtractCallbackNotification(result);
}

void Csm_SymKeyWrapSymServiceFinishNotification(void)
{
    Csm_SymKeyExtractServiceFinishNotification();
}


Csm_ReturnType SampleCode_Hash (Hsm_HashAlgorithmType HashAlgorithm,const uint8 *MessagePtr,uint32 MessageLength, uint8 *DigestPtr,uint32 *DigestLengthPtr,
							Hsm_CryptoOperationMode OperationMode)
{
    Csm_ReturnType retVal;
	const Cry_HsmHashConfigType* config = &Cry_kHsmHashConfig;

    retVal = Cry_HsmHash(config, HashAlgorithm,MessagePtr,MessageLength,DigestPtr,DigestLengthPtr,OperationMode);

    return retVal;
}

/*******************************************************************************
**                                                                            **
** Description     : This function implements signature generate              **
**                                                                            **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Parameters (in) : symKeyPtr                                                **
**                   input                                                    **
                     inputLength

**                                                                            **
** Parameters (out): SignatureDataPtr                                         **
                     SignatureLenthPtr
**                                                                            **
**                                                                            **
**                                                                            **
** Return value    : CSM_E_OK             Request successful                  **
**                   CSM_E_BUSY           Request failed due to underlying    **
**                                        HSM communication is busy           **
**                   CSM_E_NOT_OK         Request failed                      **
**                                                                            **
*******************************************************************************/
Csm_ReturnType SampleCode_SignatureGenerate(const Csm_PlainKeyType *symKeyPtr,Hsm_SignatureAlgorithmType SignatureAlgorithm,const uint8 *UserId,uint32 UserIdLen,
                                               const uint8 *input, uint32 inputLength,uint8 *SignatureDataPtr,uint32 *SignatureLenth,Hsm_CryptoOperationMode OperationMode)
{
	Csm_ReturnType retVal;
	Cry_HsmKeySlotIdType SlotId;

	const Cry_HsmSignatureGenerateConfigType* config = &Cry_HsmSignatureGenerateConfig;

    /*input key slot from CSM is of typt uint8 */
    SlotId = (Cry_HsmKeySlotIdType)symKeyPtr->data[0];
    if(((SignatureAlgorithm == HSM_SIGNATURE_ALGORITHM_ECDSA)&&(SlotId == CRY_HSM_PLAIN_KEY_2))||
		((SignatureAlgorithm == HSM_SIGNATURE_ALGORITHM_RSA_v15)&&((SlotId == CRY_HSM_PLAIN_KEY_3)||(SlotId == CRY_HSM_PLAIN_KEY_12)||(SlotId == CRY_HSM_PLAIN_KEY_17)))||
		((SignatureAlgorithm == HSM_SIGNATURE_ALGORITHM_RSA_v21)&&((SlotId == CRY_HSM_PLAIN_KEY_3)||(SlotId == CRY_HSM_PLAIN_KEY_12)||(SlotId == CRY_HSM_PLAIN_KEY_17)))||
		((SignatureAlgorithm == HSM_SIGNATURE_ALGORITHM_SM2)&&(SlotId == CRY_HSM_PLAIN_KEY_9)))
    {
	    retVal = Cry_HsmSignatureGenerate(config, symKeyPtr,SignatureAlgorithm,UserId,UserIdLen, input, inputLength,SignatureDataPtr,SignatureLenth,OperationMode);
    }
	else
	{
        retVal = CSM_E_NOT_OK;
	}

	return retVal;
}
/*******************************************************************************
**                                                                            **
** Description     : This function implements signature verify                **
**                                                                            **
**                                                                            **
** Sync/Async      : Synchronous or Asynchronous depending on configuration   **
**                   CSM_USE_SYNC_JOB_PROCESSING                              **
**                                                                            **
** Parameters (in) : symKeyPtr                                                **
**                   input                                                    **
                     inputLength
                     SignatureDataPtr
                     SignatureLenthPtr

**                                                                            **
** Parameters (out): ResultPtr                                                **
                    
**                                                                            **
**                                                                            **
**                                                                            **
** Return value    : CSM_E_OK             Request successful                  **
**                   CSM_E_BUSY           Request failed due to underlying    **
**                                        HSM communication is busy           **
**                   CSM_E_NOT_OK         Request failed                      **
**                                                                            **
*******************************************************************************/
Csm_ReturnType SampleCode_SignatureVerify(const Csm_PlainKeyType *symKeyPtr,Hsm_SignatureAlgorithmType SignatureAlgorithm,const uint8 *UserId,uint32 UserIdLen,
                                            const uint8 *input, uint32 inputLength,uint8 *SignatureDataPtr,uint32 SignatureLenth,Csm_VerifyResultType *ResultPtr,
                                            Hsm_CryptoOperationMode OperationMode)
{
	const Cry_HsmSignatureVerifyConfigType* config = &Cry_HsmSignatureVerifyConfig;
	Csm_ReturnType retVal;
	Cry_HsmKeySlotIdType SlotId;

	/*input key slot from CSM is of typt uint8 */
    SlotId = (Cry_HsmKeySlotIdType)symKeyPtr->data[0];
    if(((SignatureAlgorithm == HSM_SIGNATURE_ALGORITHM_ECDSA)&&(SlotId == CRY_HSM_PLAIN_KEY_1))||
		((SignatureAlgorithm == HSM_SIGNATURE_ALGORITHM_RSA_v15)&&((SlotId == CRY_HSM_PLAIN_KEY_4)||(SlotId == CRY_HSM_PLAIN_KEY_13)||(SlotId == CRY_HSM_PLAIN_KEY_18)))||
		((SignatureAlgorithm == HSM_SIGNATURE_ALGORITHM_RSA_v21)&&((SlotId == CRY_HSM_PLAIN_KEY_4)||(SlotId == CRY_HSM_PLAIN_KEY_13)||(SlotId == CRY_HSM_PLAIN_KEY_18)))||
		((SignatureAlgorithm == HSM_SIGNATURE_ALGORITHM_SM2)&&(SlotId == CRY_HSM_PLAIN_KEY_8)))
    {
    	retVal = Cry_HsmSignatureVerify(config, symKeyPtr,SignatureAlgorithm,UserId,UserIdLen, input, inputLength,SignatureDataPtr,SignatureLenth,ResultPtr,OperationMode);
	}
	else
	{
		retVal = CSM_E_NOT_OK;
	}

	return retVal;

}

Csm_ReturnType SampleCode_Encrypt(const Csm_SymKeyType *symKeyPtr,const uint8 *IV,Hsm_CipherAlgorithmType EncryptAlgorithm,Crypto_AlgorithmModeType mode,
							  const uint8 *input, uint32 inputLength,uint8 *OutPutDataPtr,uint32 *OutPutDataLenPtr,Hsm_CryptoOperationMode OperationMode)
{
	Csm_ReturnType retVal;
	Cry_HsmKeySlotIdType SlotId;

	const Cry_HsmEncryptConfigType* config = &Cry_HsmEncryptConfig;
	/*input key slot from CSM is of typt uint8 */
    SlotId = (Cry_HsmKeySlotIdType)symKeyPtr->data[0];
    if((EncryptAlgorithm == HSM_CIPHER_ALGORITHM_AES256)&&(SlotId != CRY_HSM_PLAIN_KEY_10))
    {
		retVal = CSM_E_NOT_OK;
	}
	else
	{
    	retVal = Cry_HsmEncrypt(config,symKeyPtr,IV,EncryptAlgorithm,mode,input,inputLength,OutPutDataPtr,OutPutDataLenPtr,OperationMode);
	}
	
	
	return retVal;
}

Csm_ReturnType SampleCode_Decrypt(const Csm_SymKeyType *symKeyPtr,const uint8 *IV,Hsm_CipherAlgorithmType EncryptAlgorithm,Crypto_AlgorithmModeType mode,
							  const uint8 *input, uint32 inputLength,uint8 *OutPutDataPtr,uint32 *OutPutDataLenPtr,Hsm_CryptoOperationMode OperationMode)
{
	Csm_ReturnType retVal;
    Cry_HsmKeySlotIdType SlotId;

	const Cry_HsmDecryptConfigType* config = &Cry_HsmDecryptConfig;
	/*input key slot from CSM is of typt uint8 */
    SlotId = (Cry_HsmKeySlotIdType)symKeyPtr->data[0];
    if((EncryptAlgorithm == HSM_CIPHER_ALGORITHM_AES256)&&(SlotId != CRY_HSM_PLAIN_KEY_10))
    {
		retVal = CSM_E_NOT_OK;
	}
	else
	{
    	retVal = Cry_HsmDecrypt(config,symKeyPtr,IV,EncryptAlgorithm,mode,input,inputLength,OutPutDataPtr,OutPutDataLenPtr,OperationMode);
	}
	return retVal;
}
/*************************************************************************************//**
 * Key Load Plain ITF test suite
*//**************************************************************************************/
#if ITF
void KeyLoadPlain_PreInitVariables(void)
{
    KeyLoadPlainStatus = 0;
    KeyLoadPlain_RetVal = CSM_E_ENTROPY_EXHAUSTION;
    DetErrorId =0;
    DetApiId = 0;
    KeyLoadPlain_StartRetVal = CSM_E_ENTROPY_EXHAUSTION;
    KeyLoadPlain_UpdateRetVal = CSM_E_ENTROPY_EXHAUSTION;
    KeyLoadPlain_UpdateRetVal1 = CSM_E_ENTROPY_EXHAUSTION;
    KeyLoadPlain_FinishRetVal = CSM_E_ENTROPY_EXHAUSTION;
    BswMModuleId = 0;
    BswMErrorId = 0;
    #if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
    KeyLoadPlainCallBackStartResult = CSM_E_ENTROPY_EXHAUSTION;
    KeyLoadPlainCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
    KeyLoadPlainCallBackUpdateResult1 = CSM_E_ENTROPY_EXHAUSTION;
    KeyLoadPlainCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
    KeyLoadPlainFinishNotify = 0;
    g_TestHsm_key.callbackSet = 0;
    #endif
}
void KeyExport_PreInitVariables(void)
{
    KeyExportStatus = 0;
    KeyExport_RetVal = CSM_E_ENTROPY_EXHAUSTION;
    DetErrorId =0;
    DetApiId = 0;
    KeyExport_StartRetVal = CSM_E_ENTROPY_EXHAUSTION;
    KeyExport_UpdateRetVal = CSM_E_ENTROPY_EXHAUSTION;
    KeyExport_UpdateRetVal1 = CSM_E_ENTROPY_EXHAUSTION;
    KeyExport_FinishRetVal = CSM_E_ENTROPY_EXHAUSTION;
    BswMModuleId = 0;
    BswMErrorId = 0;
    #if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
    KeyExportCallBackStartResult = CSM_E_ENTROPY_EXHAUSTION;
    KeyExportCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
    KeyExportCallBackUpdateResult1 = CSM_E_ENTROPY_EXHAUSTION;
    KeyExportCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
    KeyExportFinishNotify = 0;
    g_TestHsm_key.callbackSet = 0;
    #endif
}
void KeyLoadPlain_ITF(void)
{
    const Cry_HsmLoadPlainConfigType* config = &Cry_kHsmLoadPlainConfig;
    /*For less timeout requirement*/
    const Cry_HsmLoadPlainConfigType  Cry_kHsmLoadPlainConfigLessTime =
            {.TimeOut =   {.TimeoutStart = 0,
                    .TimeoutUpdateConst = 0,
                    .TimeoutUpdateperByte = 0,
                    .TimeoutFinish = 0 }  };
    const Cry_HsmLoadPlainConfigType* config2 = &Cry_kHsmLoadPlainConfigLessTime;


    switch(TC_KeyLoadPlain)
       {
           case  CRY_KEY_LOAD_PLAIN_START_VALID_PARAMETERS_CRY_UNINIT:/*159-1*/
           {
               /*Set Cry_HsmInitStatus  to CRY_HSM_UNINITIALIZED through scripts*/
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlain_RetVal = Cry_HsmKeyLoadPlainStart(config);
               if((KeyLoadPlain_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_UNINIT) && (DetApiId == CRY_HSM_SID_KEY_LOAD_PLAIN_START))
               {
                   KeyLoadPlainStatus = 1;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
               /*Set Cry_HsmInitStatus  to CRY_HSM_INITIALIZED through scripts*/
           }
           case  CRY_KEY_LOAD_PLAIN_UPDATE_CFG_PTR_NULL:/*160-2*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlain_RetVal = Cry_HsmKeyLoadPlainUpdate(NULL_PTR,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),16U);

               if((KeyLoadPlain_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE))
               {
                   KeyLoadPlainStatus = 1;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
           case  CRY_KEY_LOAD_PLAIN_UPDATE_DATA_PTR_NULL:/*161-3*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlain_RetVal = Cry_HsmKeyLoadPlainUpdate(config,NULL_PTR,16U);

               if((KeyLoadPlain_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE))
               {
                   KeyLoadPlainStatus = 1;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
           case  CRY_KEY_LOAD_PLAIN_UPDATE_WHEN_START_FAIL:/*162-4*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlainService = Cry_PrimStatus[CRY_HSM_KEY_LOAD_PLAIN];
               Cry_PrimStatus[CRY_HSM_KEY_LOAD_PLAIN] = CRY_HSM_PRIM_NOT_STARTED;
               KeyLoadPlain_RetVal = Cry_HsmKeyLoadPlainUpdate(config,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),16U);

               if((KeyLoadPlain_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED) && (DetApiId == CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE))
               {
                   KeyLoadPlainStatus = 1;
               }
               Cry_PrimStatus[CRY_HSM_KEY_LOAD_PLAIN] = KeyLoadPlainService;
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
           case  CRY_KEY_LOAD_PLAIN_UPDATE_WHEN_DATA_LENGTH_8:/*163-5*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlainService = Cry_PrimStatus[CRY_HSM_KEY_LOAD_PLAIN];
               Cry_PrimStatus[CRY_HSM_KEY_LOAD_PLAIN] = CRY_HSM_PRIM_STARTED;
               KeyLoadPlain_RetVal = Cry_HsmKeyLoadPlainUpdate(config,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),8U);
               if((KeyLoadPlain_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID) && (DetApiId == CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE))
               {
                   KeyLoadPlainStatus = 1;
               }
               Cry_PrimStatus[CRY_HSM_KEY_LOAD_PLAIN] = KeyLoadPlainService;
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
           case  CRY_KEY_LOAD_PLAIN_FINISH_WHEN_START_FAIL:/*164-6*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlainService = Cry_PrimStatus[CRY_HSM_KEY_LOAD_PLAIN];
               Cry_PrimStatus[CRY_HSM_KEY_LOAD_PLAIN] = CRY_HSM_PRIM_NOT_STARTED;
               KeyLoadPlain_RetVal = Cry_HsmKeyLoadPlainFinish(config,((Csm_SymKeyType *)TEST_KEY_LOAD_PLAIN_CONST_KEY));
               if((KeyLoadPlain_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED) && (DetApiId == CRY_HSM_SID_KEY_LOAD_PLAIN_FINISH))
               {
                   KeyLoadPlainStatus = 1;
               }
               Cry_PrimStatus[CRY_HSM_KEY_LOAD_PLAIN] = KeyLoadPlainService;
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
           /*CRY_SC_TC_26*/
           case CRY_KEY_LOAD_PLAIN_CANCEL:
           {
               KeyLoadPlain_PreInitVariables();
               CancelRequired = 1;

               KeyLoadPlain_StartRetVal = Cry_HsmKeyLoadPlainStart(config);

               Gpt_EnableNotification(Gptch_CancelCommand);
               Gpt_StartTimer(Gptch_CancelCommand, 200);

               KeyLoadPlain_UpdateRetVal1 = Cry_HsmKeyLoadPlainUpdate(config,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),16U);

               Gpt_StopTimer(Gptch_CancelCommand);

               KeyLoadPlain_UpdateRetVal = Cry_HsmKeyLoadPlainUpdate(config,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),16U);

               KeyLoadPlain_FinishRetVal = Cry_HsmKeyLoadPlainFinish(config,((Csm_SymKeyType *)TEST_KEY_LOAD_PLAIN_CONST_KEY));

               if((KeyLoadPlain_StartRetVal == CSM_E_OK) && (KeyLoadPlain_UpdateRetVal1 ==CSM_E_NOT_OK)
                       && (KeyLoadPlain_UpdateRetVal == CSM_E_OK)&& (KeyLoadPlain_FinishRetVal == CSM_E_OK))
               {
                   KeyLoadPlainStatus = 1;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON)
           case  CRY_KEY_LOAD_PLAIN_SYNC_SUCCESS:/*165-7*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlain_StartRetVal = Cry_HsmKeyLoadPlainStart(config);
               KeyLoadPlain_UpdateRetVal = Cry_HsmKeyLoadPlainUpdate(config,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),16U);
               KeyLoadPlain_FinishRetVal = Cry_HsmKeyLoadPlainFinish(config,((Csm_SymKeyType *)TEST_KEY_LOAD_PLAIN_CONST_KEY));
               if((KeyLoadPlain_StartRetVal == CSM_E_OK) &&(KeyLoadPlain_UpdateRetVal == CSM_E_OK) &&(KeyLoadPlain_FinishRetVal == CSM_E_OK))
               {
                   KeyLoadPlainStatus = 1;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
           case  CRY_KEY_LOAD_PLAIN_SYNC_TIMEOUT:/*166-8*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlainStatus = 1;
               KeyLoadPlain_StartRetVal = Cry_HsmKeyLoadPlainStart(config);
               KeyLoadPlain_UpdateRetVal = Cry_HsmKeyLoadPlainUpdate(config2,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),16U);
               if((KeyLoadPlain_StartRetVal != CSM_E_OK) || (KeyLoadPlain_UpdateRetVal != CSM_E_NOT_OK) ||
                       (BswMModuleId != CRY_MODULE_ID) || (BswMErrorId != HSMCOM_ERC_TIMEOUT))
               {
                   KeyLoadPlainStatus = 0;
               }
               KeyLoadPlain_FinishRetVal = Cry_HsmKeyLoadPlainFinish(config,((Csm_SymKeyType *)TEST_KEY_LOAD_PLAIN_CONST_KEY));
               if(KeyLoadPlain_FinishRetVal != CSM_E_BUSY)
               {
                   KeyLoadPlainStatus = 0;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
           case  CRY_KEY_LOAD_PLAIN_SESSION_HANDLING:/*167-9*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlain_StartRetVal = Cry_HsmKeyLoadPlainStart(config);
               KeyLoadPlain_FinishRetVal = Cry_HsmKeyLoadPlainFinish(config,((Csm_SymKeyType *)TEST_KEY_LOAD_PLAIN_CONST_KEY));
               if((KeyLoadPlain_StartRetVal == CSM_E_OK) &&(KeyLoadPlain_FinishRetVal == CSM_E_OK))
               {
                   KeyLoadPlainStatus = 1;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
#endif
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
           case  CRY_KEY_LOAD_PLAIN_ASYNC_SUCCESS:/*168-10*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlain_StartRetVal = Cry_HsmKeyLoadPlainStart(config);
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);
               KeyLoadPlain_UpdateRetVal = Cry_HsmKeyLoadPlainUpdate(config,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),16U);
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);
               KeyLoadPlain_FinishRetVal = Cry_HsmKeyLoadPlainFinish(config,((Csm_SymKeyType *)TEST_KEY_LOAD_PLAIN_CONST_KEY));
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);
               if((KeyLoadPlain_StartRetVal == CSM_E_OK) &&(KeyLoadPlain_UpdateRetVal == CSM_E_OK) &&(KeyLoadPlain_FinishRetVal == CSM_E_OK) &&
                       (KeyLoadPlainCallBackStartResult == CSM_E_OK) && (KeyLoadPlainCallBackUpdateResult == CSM_E_OK) && (KeyLoadPlainCallBackFinishResult == CSM_E_OK)&&
                       (KeyLoadPlainFinishNotify == 1))
               {
                   KeyLoadPlainStatus = 1;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
           case  CRY_KEY_LOAD_PLAIN_ASYNC_TIMEOUT:/*169-11*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlainStatus = 1;
               KeyLoadPlain_StartRetVal = Cry_HsmKeyLoadPlainStart(config);
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);
               KeyLoadPlain_UpdateRetVal = Cry_HsmKeyLoadPlainUpdate(config2,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),16U);
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);
               if((KeyLoadPlain_StartRetVal != CSM_E_OK) || (KeyLoadPlain_UpdateRetVal != CSM_E_NOT_OK) ||
                       (BswMModuleId != CRY_MODULE_ID) || (BswMErrorId != HSMCOM_ERC_TIMEOUT)||
                       (KeyLoadPlainCallBackStartResult != CSM_E_OK) || (KeyLoadPlainCallBackUpdateResult != CSM_E_NOT_OK))
               {
                   KeyLoadPlainStatus = 0;
               }
               KeyLoadPlain_FinishRetVal = Cry_HsmKeyLoadPlainFinish(config,((Csm_SymKeyType *)TEST_KEY_LOAD_PLAIN_CONST_KEY));
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);
               if((KeyLoadPlain_FinishRetVal != CSM_E_BUSY) || (KeyLoadPlainCallBackFinishResult != CSM_E_BUSY) || (KeyLoadPlainFinishNotify != 0x1))
               {
                   KeyLoadPlainStatus = 0;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
           /*CRY_SC_TC_27*/
           case CRY_KEY_LOAD_PLAIN_CANCEL_ASYNC :
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlain_StartRetVal = Cry_HsmKeyLoadPlainStart(config);
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);

               KeyLoadPlain_UpdateRetVal = Cry_HsmKeyLoadPlainUpdate(config,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),16U);
               Cry_HsmSheCancel();
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);

               KeyLoadPlainCallBackUpdateResult1 = KeyLoadPlainCallBackUpdateResult;

               KeyLoadPlain_UpdateRetVal = Cry_HsmKeyLoadPlainUpdate(config,((const uint8 *)TEST_KEY_LOAD_PLAIN_CONST_KEY),16U);
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);

               KeyLoadPlain_FinishRetVal = Cry_HsmKeyLoadPlainFinish(config,((Csm_SymKeyType *)TEST_KEY_LOAD_PLAIN_CONST_KEY));
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);

               if((KeyLoadPlainCallBackStartResult == CSM_E_OK) && (KeyLoadPlainCallBackUpdateResult1 == CSM_E_NOT_OK) &&
                       (KeyLoadPlainCallBackUpdateResult == CSM_E_OK) && (KeyLoadPlain_FinishRetVal == CSM_E_OK))
               {
                   KeyLoadPlainStatus = 1;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
#endif
           case  CRY_KEY_LOAD_PLAIN_FINISH_TIMEOUT:/*This is required to release handle when timeout*/
           {
               KeyLoadPlain_PreInitVariables();
               KeyLoadPlain_FinishRetVal = Cry_HsmKeyLoadPlainFinish(config,((Csm_SymKeyType *)TEST_KEY_LOAD_PLAIN_CONST_KEY));
               #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
               TEST_WAIT(&Cry_HsmKeyLoadPlainMainFunction, &g_TestHsm_key.callbackSet);
               #endif
               if(KeyLoadPlain_FinishRetVal == CSM_E_OK)
               {
                   KeyLoadPlainStatus = 1;
               }
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }
           default:
           {
               TC_KeyLoadPlain = CRY_KEY_LOAD_PLAIN_IDLE;
               break;
           }

       }
}
/*************************************************************************************//**
 * Key Export ITF test suite
*//**************************************************************************************/
void KeyExport_ITF(void)
{
    const Cry_HsmKeyExportConfigType* config3 = &Cry_kHsmKeyExportConfig;
    /*For less timeout requirement*/
    const Cry_HsmKeyExportConfigType  Cry_kHsmExportConfigLessTime =
            {.TimeOut =   {.TimeoutStart = 0,
                    .TimeoutUpdateConst = 0,
                    .TimeoutUpdateperByte = 0,
                    .TimeoutFinish = 0 }  };
    const Cry_HsmKeyExportConfigType* config4 = &Cry_kHsmExportConfigLessTime;
    uint32 keyLength;

    switch(TC_KeyExport)
       {
           case  CRY_KEY_EXPORT_START_VALID_PARAMETERS_CRY_UNINIT:/*182-1*/
           {
               /*Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED from script*/
               KeyExport_PreInitVariables();
               KeyExport_RetVal = Cry_HsmKeyExportStart(config3, NULL_PTR, NULL_PTR);
               if((KeyExport_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_UNINIT)&& (DetApiId == CRY_HSM_SID_KEY_EXPORT_START))
               {
                   KeyExportStatus = 1;
               }
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               /*Cry_HsmInitStatus = CRY_HSM_INITIALIZED from script*/
               break;
           }
           case  CRY_KEY_EXPORT_UPDATE_CFG_NULL:/*183-2*/
           {
               KeyExport_PreInitVariables();
               keyLength = sizeof(ProtectedKey);
               KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
               KeyExport_RetVal = Cry_HsmKeyExportUpdate(NULL_PTR, (uint8*) KeyPtr, &keyLength);
               if((KeyExport_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)&& (DetApiId == CRY_HSM_SID_KEY_EXPORT_UPDATE))
               {
                   KeyExportStatus = 1;
               }
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
           case  CRY_KEY_EXPORT_UPDATE_DATA_NULL:/*184-3*/
           {
               KeyExport_PreInitVariables();
               keyLength = sizeof(ProtectedKey);
               KeyExport_RetVal = Cry_HsmKeyExportUpdate(config3, NULL_PTR, &keyLength);
               if((KeyExport_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)&& (DetApiId == CRY_HSM_SID_KEY_EXPORT_UPDATE))
               {
                   KeyExportStatus = 1;
               }
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
           case  CRY_KEY_EXPORT_UPDATE_DATA_LENGTH_NULL:/*185-4*/
           {
               KeyExport_PreInitVariables();
               KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
               KeyExport_RetVal = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, NULL_PTR);
               if((KeyExport_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)&& (DetApiId == CRY_HSM_SID_KEY_EXPORT_UPDATE))
               {
                   KeyExportStatus = 1;
               }
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
           case  CRY_KEY_EXPORT_UPDATE_WHEN_START_NOT_STARTED:/*186-5*/
           {
               KeyExport_PreInitVariables();
               keyLength = sizeof(ProtectedKey);
               KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
               KeyExportService = Cry_PrimStatus[CRY_HSM_KEY_WRAP];
               Cry_PrimStatus[CRY_HSM_KEY_WRAP] = CRY_HSM_PRIM_NOT_STARTED;
               KeyExport_RetVal = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, &keyLength);
               if((KeyExport_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)&& (DetApiId == CRY_HSM_SID_KEY_EXPORT_UPDATE))
               {
                   KeyExportStatus = 1;
               }
               Cry_PrimStatus[CRY_HSM_KEY_WRAP] = KeyExportService;
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
           case  CRY_KEY_EXPORT_UPDATE_WHEN_DATA_LENGTH_60:/*187-6*/
           {
               KeyExport_PreInitVariables();
               keyLength = 60;
               KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
               KeyExportService = Cry_PrimStatus[CRY_HSM_KEY_WRAP];
               Cry_PrimStatus[CRY_HSM_KEY_WRAP] = CRY_HSM_PRIM_STARTED;
               KeyExport_RetVal = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, &keyLength);
               if((KeyExport_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID)&& (DetApiId == CRY_HSM_SID_KEY_EXPORT_UPDATE))
               {
                   KeyExportStatus = 1;
               }
               Cry_PrimStatus[CRY_HSM_KEY_WRAP] = KeyExportService;
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
           case  CRY_KEY_EXPORT_FINISH_WHEN_START_NOT_STARTED:/*188-7*/
           {
               KeyExport_PreInitVariables();
               keyLength = sizeof(ProtectedKey);
               KeyExportService = Cry_PrimStatus[CRY_HSM_KEY_WRAP];
               Cry_PrimStatus[CRY_HSM_KEY_WRAP] = CRY_HSM_PRIM_NOT_STARTED;
               KeyExport_RetVal = Cry_HsmKeyExportFinish(config3);
               if((KeyExport_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)&& (DetApiId == CRY_HSM_SID_KEY_EXPORT_FINISH))
               {
                   KeyExportStatus = 1;
               }
               Cry_PrimStatus[CRY_HSM_KEY_WRAP] = KeyExportService;
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON)
           case  CRY_KEY_EXPORT_SYNC_SUCCESS1:/*189-8*/
           {
               KeyExport_PreInitVariables();
               keyLength = 120;
               KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
               DummyPtr = (uint32 *)TEST_HSM_BUF_TEMP_A;
               for (i_key=0;i_key<28;i_key++)
               {
                   *DummyPtr = 0xFFFFFFFF;
                   DummyPtr++;
               }
               KeyExport_StartRetVal = Cry_HsmKeyExportStart(config3, NULL_PTR, NULL_PTR);
               KeyExport_UpdateRetVal = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, &keyLength);
               KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);
               KEY_EXPORT_BUFFER_CHECK(28);
               if((KeyExport_StartRetVal == CSM_E_OK) && (KeyExport_UpdateRetVal == CSM_E_OK) && (KeyExport_FinishRetVal == CSM_E_OK) &&
                       (ErrorCheck_Key == 1))
               {
                   KeyExportStatus = 1;
               }
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
           case  CRY_KEY_EXPORT_SYNC_SUCCESS2:/*190-9*/
           {
               KeyExport_PreInitVariables();
               keyLength = 80;
               KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
               DummyPtr = (uint32 *)TEST_HSM_BUF_TEMP_A;
               for (i_key=0;i_key<28;i_key++)
               {
                   *DummyPtr = 0xFFFFFFFF;
                   DummyPtr++;
               }
               KeyExport_StartRetVal = Cry_HsmKeyExportStart(config3, NULL_PTR, NULL_PTR);
               KeyExport_UpdateRetVal = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, &keyLength);
               KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);
               KEY_EXPORT_BUFFER_CHECK(16);
               if((KeyExport_StartRetVal == CSM_E_OK) && (KeyExport_UpdateRetVal == CSM_E_OK) && (KeyExport_FinishRetVal == CSM_E_OK) &&
                       (ErrorCheck_Key == 1))
               {
                   KeyExportStatus = 1;
               }
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
           case  CRY_KEY_EXPORT_SYNC_TIMEOUT:/*191-10*/
           {
               KeyExport_PreInitVariables();
               KeyExportStatus = 1;
               keyLength = 80;
               KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
               DummyPtr = (uint32 *)TEST_HSM_BUF_TEMP_A;
               for (i_key = 0;i_key < 28;i_key++)
               {
                   *DummyPtr = 0xFFFFFFFF;
                   DummyPtr++;
               }
               KeyExport_StartRetVal = Cry_HsmKeyExportStart(config3, NULL_PTR, NULL_PTR);
               KeyExport_UpdateRetVal = Cry_HsmKeyExportUpdate(config4, (uint8*) KeyPtr, &keyLength);
               if((KeyExport_StartRetVal != CSM_E_OK) || (KeyExport_UpdateRetVal != CSM_E_NOT_OK) ||
                       (BswMModuleId != CRY_MODULE_ID) || (BswMErrorId != HSMCOM_ERC_TIMEOUT))
               {
                   KeyExportStatus = 0;
               }
               KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);
               if(KeyExport_FinishRetVal != CSM_E_BUSY)
               {
                   KeyExportStatus = 0;
               }
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
           case  CRY_KEY_EXPORT_SYNC_SESSION_HANDLING:/*192-11*/
           {
               KeyExport_PreInitVariables();
               KeyExport_StartRetVal = Cry_HsmKeyExportStart(config3, NULL_PTR, NULL_PTR);
               KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);
               if((KeyExport_StartRetVal == CSM_E_OK) && (KeyExport_FinishRetVal == CSM_E_OK))
               {
                   KeyExportStatus = 1;
               }
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
           case  CRY_KEY_EXPORT_TIMEOUT_COMPLETE_SYNC:/*To complete Finish action in sync mode*/
           {
               KeyExport_FinishRetVal = CSM_E_ENTROPY_EXHAUSTION;
               KeyExportStatus = 1;
               KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);
               if(KeyExport_FinishRetVal != CSM_E_OK)
               {
                   KeyExportStatus = 0;
               }
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
           /*CRY_SC_TC_28*/
           case CRY_KEY_EXPORT_CANCEL :
           {
               KeyExport_PreInitVariables();
               CancelRequired =1;
               keyLength = 120;
               KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
               DummyPtr = (uint32 *)TEST_HSM_BUF_TEMP_A;
               for (i_key=0;i_key<28;i_key++)
               {
                   *DummyPtr = 0xFFFFFFFF;
                   DummyPtr++;
               }
               KeyExport_StartRetVal = Cry_HsmKeyExportStart(config3, NULL_PTR, NULL_PTR);

               Gpt_EnableNotification(Gptch_CancelCommand);
               Gpt_StartTimer(Gptch_CancelCommand, 200);

               KeyExport_UpdateRetVal1 = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, &keyLength);

               Gpt_StopTimer(Gptch_CancelCommand);

               KeyExport_UpdateRetVal = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, &keyLength);

               KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);

               KEY_EXPORT_BUFFER_CHECK(28);
               if((KeyExport_StartRetVal == CSM_E_OK) && (KeyExport_UpdateRetVal1 == CSM_E_NOT_OK) &&
                       (KeyExport_UpdateRetVal == CSM_E_OK)&&(KeyExport_FinishRetVal == CSM_E_OK) &&
                       (ErrorCheck_Key == 1))
               {
                   KeyExportStatus = 1;
               }
               TC_KeyExport = CRY_KEY_EXPORT_IDLE;
               break;
           }
#else
        case  CRY_KEY_EXPORT_ASYNC_SUCCESS1:/*193-12*/
        {
            KeyExport_PreInitVariables();
            keyLength = 120;
            KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
            DummyPtr = (uint32 *)TEST_HSM_BUF_TEMP_A;
            for (i_key=0;i_key<28;i_key++)
            {
                *DummyPtr = 0xFFFFFFFF;
                DummyPtr++;
            }
            KeyExport_StartRetVal = Cry_HsmKeyExportStart(config3, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
            KeyExport_UpdateRetVal = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, &keyLength);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
            KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
            KEY_EXPORT_BUFFER_CHECK(28);
            if((KeyExport_StartRetVal == CSM_E_OK) && (KeyExport_UpdateRetVal == CSM_E_OK) && (KeyExport_FinishRetVal == CSM_E_OK) &&
                    (ErrorCheck_Key == 1) && (KeyExportCallBackStartResult == CSM_E_OK) &&(KeyExportCallBackUpdateResult == CSM_E_OK) &&
                    (KeyExportCallBackFinishResult == CSM_E_OK) && (KeyExportFinishNotify == 0x1))
            {
                KeyExportStatus = 1;
            }
            TC_KeyExport = CRY_KEY_EXPORT_IDLE;
            break;
        }
        case  CRY_KEY_EXPORT_ASYNC_SUCCESS2:/*194-13*/
        {
            KeyExport_PreInitVariables();
            keyLength = 80;
            KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
            DummyPtr = (uint32 *)TEST_HSM_BUF_TEMP_A;
            for (i_key=0;i_key<28;i_key++)
            {
                *DummyPtr = 0xFFFFFFFF;
                DummyPtr++;
            }
            KeyExport_StartRetVal = Cry_HsmKeyExportStart(config3, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
            KeyExport_UpdateRetVal = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, &keyLength);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
            KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);

            KEY_EXPORT_BUFFER_CHECK(16);

            if((KeyExport_StartRetVal == CSM_E_OK) && (KeyExport_UpdateRetVal == CSM_E_OK) && (KeyExport_FinishRetVal == CSM_E_OK) &&
                    (ErrorCheck_Key == 1) && (KeyExportCallBackStartResult == CSM_E_OK) &&(KeyExportCallBackUpdateResult == CSM_E_OK) &&
                    (KeyExportCallBackFinishResult == CSM_E_OK) && (KeyExportFinishNotify == 0x1))
            {
                KeyExportStatus = 1;
            }
            TC_KeyExport = CRY_KEY_EXPORT_IDLE;
            break;
        }
        case  CRY_KEY_EXPORT_ASYNC_TIMEOUT:/*195-14*/
        {
            KeyExport_PreInitVariables();
            KeyExportStatus = 1;
            keyLength = 80;
            KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
            DummyPtr = (uint32 *)TEST_HSM_BUF_TEMP_A;
            for (i_key = 0;i_key < 28;i_key++)
            {
                *DummyPtr = 0xFFFFFFFF;
                DummyPtr++;
            }

            KeyExport_StartRetVal = Cry_HsmKeyExportStart(config3, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
            KeyExport_UpdateRetVal = Cry_HsmKeyExportUpdate(config4, (uint8*) KeyPtr, &keyLength);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
            if((KeyExport_StartRetVal != CSM_E_OK) || (KeyExport_UpdateRetVal != CSM_E_NOT_OK) ||
                    (KeyExportCallBackStartResult != CSM_E_OK) ||(KeyExportCallBackUpdateResult != CSM_E_NOT_OK))
            {
                KeyExportStatus = 0;
            }
            KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);

            if((KeyExport_FinishRetVal != CSM_E_BUSY) ||
                    (KeyExportCallBackFinishResult != CSM_E_BUSY) || (KeyExportFinishNotify != 0x1))
            {
                KeyExportStatus = 0;
            }
            TC_KeyExport = CRY_KEY_EXPORT_IDLE;
            break;
        }
        case  CRY_KEY_EXPORT_TIMEOUT_COMPLETE_ASYNC:/*To complete Finish action in async mode*/
        {
            KeyExport_FinishRetVal = CSM_E_ENTROPY_EXHAUSTION;
            KeyExportStatus = 1;
            KeyExportFinishNotify = 0;
            KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
            if((KeyExport_FinishRetVal != CSM_E_OK) && (KeyExportFinishNotify != 0x1))
            {
                KeyExportStatus = 0;
            }
            TC_KeyExport = CRY_KEY_EXPORT_IDLE;
            break;
        }
        /*CRY_SC_TC_29*/
        case CRY_KEY_EXPORT_CANCEL_ASYNC :
        {
            KeyExport_PreInitVariables();
            keyLength = 120;
            KeyPtr = (void *)TEST_HSM_BUF_TEMP_A;
            DummyPtr = (uint32 *)TEST_HSM_BUF_TEMP_A;
            for (i_key=0;i_key<28;i_key++)
            {
                *DummyPtr = 0xFFFFFFFF;
                DummyPtr++;
            }
            KeyExport_StartRetVal = Cry_HsmKeyExportStart(config3, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);

            KeyExport_UpdateRetVal1 = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, &keyLength);
            Cry_HsmSheCancel();
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);

            KeyExportCallBackUpdateResult1 = KeyExportCallBackUpdateResult;

            KeyExport_UpdateRetVal = Cry_HsmKeyExportUpdate(config3, (uint8*) KeyPtr, &keyLength);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);

            KeyExport_FinishRetVal = Cry_HsmKeyExportFinish(config3);
            TEST_WAIT(&Cry_HsmKeyExportMainFunction, &g_TestHsm_key.callbackSet);
            KEY_EXPORT_BUFFER_CHECK(28);

            if((ErrorCheck_Key == 1) && (KeyExportCallBackStartResult == CSM_E_OK) &&(KeyExportCallBackUpdateResult1 == CSM_E_NOT_OK) &&
                    (KeyExportCallBackUpdateResult == CSM_E_OK) &&(KeyExportCallBackFinishResult == CSM_E_OK))
            {
                KeyExportStatus = 1;
            }
            TC_KeyExport = CRY_KEY_EXPORT_IDLE;
            break;
        }
#endif
        default:
        {
            TC_KeyExport = CRY_KEY_EXPORT_IDLE;
            break;
        }
    }
}
void KeyLoadParamInit()
{
    KeyLoad_RetVal = CSM_E_ENTROPY_EXHAUSTION;
    KeyLoad_RetVal2= CSM_E_ENTROPY_EXHAUSTION;
    DetErrorId =0;
    DetApiId = 0;
    BswMModuleId = 0;
    BswMErrorId = 0;
    KeyLoadErrorCheck = 0;
    KeyLoadReturn = FALSE;
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
g_TestHsm_key.callbackSet = 0;
#endif
}
extern void KeyLoad_ITF()
{
    const Cry_HsmKeyLoadConfigType* keyLoadCfgPtr ;
    ProtectedKey* KeyLoadprotKeyPtr;
    uint32 KeyLoadkeyLength;
    uint32 KeyLoadkeyLength60;
    Csm_SymKeyType keytmp;

    keyLoadCfgPtr = &Cry_kHsmKeyLoadConfigPage0;
    KeyLoadkeyLength = sizeof(ProtectedKey);
    KeyLoadkeyLength60 = 60;
    KeyLoadprotKeyPtr = &protKey;

    switch(TC_KeyLoad)
    {
        /*CRY+ Test case 170 */
        case CRY_KEY_LOAD_CRYHSM_UNINIT :
        {
            KeyLoadParamInit();
            Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
            KeyLoad_RetVal = Cry_HsmKeyLoadStart(keyLoadCfgPtr);
            if((KeyLoad_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_UNINIT)&& (DetApiId == CRY_HSM_SID_KEY_LOAD_START))
            {
                KeyLoadErrorCheck = 1;
            }
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            TC_KeyLoad = CRY_KEY_LOAD_IDLE;
            break;
        }
        /*CRY+ Test case 171*/
        case CRY_KEYLOAD_UPDATE_NULLCFG :
        {
            KeyLoadParamInit();
            KeyLoad_RetVal = Cry_HsmKeyLoadUpdate(NULL_PTR,(uint8 *)KeyLoadprotKeyPtr,KeyLoadkeyLength);
            if((KeyLoad_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID  )&& (DetApiId == CRY_HSM_SID_KEY_LOAD_UPDATE))
            {
                KeyLoadErrorCheck = 1;
            }
            TC_KeyLoad = CRY_KEY_LOAD_IDLE;
            break;
        }
        /*CRY+ Test case 172*/
        case CRY_KEYLOAD_UPDATE_NULLDATAPTR :
        {
            KeyLoadParamInit();
            KeyLoad_RetVal = Cry_HsmKeyLoadUpdate(keyLoadCfgPtr,(uint8 *)NULL_PTR,KeyLoadkeyLength);
            if((KeyLoad_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID  )&& (DetApiId == CRY_HSM_SID_KEY_LOAD_UPDATE))
            {
                KeyLoadErrorCheck = 1;
            }
            TC_KeyLoad = CRY_KEY_LOAD_IDLE;
            break;
        }
        /*CRY+ Test case 173*/
        case CRY_KEYLOAD_UPDATE_SERVICENOTSTARTED :
        {
            KeyLoadParamInit();
            Cry_PrimStatus[CRY_HSM_KEY_LOAD] = CRY_HSM_PRIM_NOT_STARTED;
            KeyLoad_RetVal = Cry_HsmKeyLoadUpdate(keyLoadCfgPtr,(uint8 *)KeyLoadprotKeyPtr,KeyLoadkeyLength);
            if((KeyLoad_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED )&& (DetApiId == CRY_HSM_SID_KEY_LOAD_UPDATE))
            {
                KeyLoadErrorCheck = 1;
            }
            TC_KeyLoad = CRY_KEY_LOAD_IDLE;
            break;
        }
        /*CRY+ Test case 174*/
        case CRY_KEYLOAD_UPDATE_LENGTH60 :
        {
            KeyLoadParamInit();
            Cry_PrimStatus[CRY_HSM_KEY_LOAD] = CRY_HSM_PRIM_STARTED;
            KeyLoad_RetVal = Cry_HsmKeyLoadUpdate(keyLoadCfgPtr,(uint8 *)KeyLoadprotKeyPtr,KeyLoadkeyLength60);
            if((KeyLoad_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID )&& (DetApiId == CRY_HSM_SID_KEY_LOAD_UPDATE))
            {
                KeyLoadErrorCheck = 1;
            }
            Cry_PrimStatus[CRY_HSM_KEY_LOAD] = CRY_HSM_PRIM_NOT_STARTED;
            TC_KeyLoad = CRY_KEY_LOAD_IDLE;
            break;
        }
        /*CRY+ Test case 175*/
        case CRY_KEYLOAD_FINISH_NULLCFGPTR :
        {
            KeyLoadParamInit();
            KeyLoad_RetVal = Cry_HsmKeyLoadFinish(keyLoadCfgPtr, NULL_PTR);
            if((KeyLoad_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID )&& (DetApiId == CRY_HSM_SID_KEY_LOAD_FINISH))
            {
                KeyLoadErrorCheck = 1;
            }
            TC_KeyLoad = CRY_KEY_LOAD_IDLE;
            break;

        }
        /*CRY+ Test case 176*/
        case CRY_KEYLOAD_FINISH_SERVICENOTSTARTED :
        {
            KeyLoadParamInit();
            Cry_PrimStatus[CRY_HSM_KEY_LOAD] = CRY_HSM_PRIM_NOT_STARTED;
            KeyLoad_RetVal = Cry_HsmKeyLoadFinish(keyLoadCfgPtr, &keytmp);
            if((KeyLoad_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED )&& (DetApiId == CRY_HSM_SID_KEY_LOAD_FINISH))
            {
                KeyLoadErrorCheck = 1;
            }
            TC_KeyLoad = CRY_KEY_LOAD_IDLE;
            break;
        }
        /*CRY+ Test case 177*/
        case CRY_KEYLOAD_START_UPD_FIN :
        {
            KeyLoadParamInit();
            KeyLoadReturn = TestHsm_initializeOneStandardKeys_ITF();
            if(KeyLoadReturn == TRUE)
            {
                KeyLoadErrorCheck = 1;
            }
            TC_KeyLoad = CRY_KEY_LOAD_IDLE;
            break;
        }
        /*CRY+ Test case 179*/
        case CRY_KEYLOAD_START_FINISH :
        {
            KeyLoadParamInit();
            KeyLoad_RetVal = Cry_HsmKeyLoadStart(keyLoadCfgPtr);
            KeyLoad_RetVal2 = Cry_HsmKeyLoadFinish(keyLoadCfgPtr, &keytmp);
            TC_KeyLoad = CRY_KEY_LOAD_IDLE;
            break;
        }
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
        /*CRY+ Test case 180*/
        case CRY_KEYLOAD_START_UPD_FIN_ASYNC :
        {
            KeyLoadParamInit();
            KeyLoadReturn = TestHsm_initializeOneStandardKeys_ITF();
            if(KeyLoadReturn == TRUE)
            {
                KeyLoadErrorCheck = 1;
            }
            TC_KeyLoad = CRY_KEY_LOAD_IDLE;
            break;
        }
#endif
        default:
        {
            break;
        }
    }
}

#endif
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"

