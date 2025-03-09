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
******************************************************************************************/
#include "TestHsm.h"
#if ITF
#include "Det.h"
#include "BswM.h"
#include "Cry_Hsm_Priv.h"
#endif

#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/*Key used for GCM Envc & Dec */
const uint32 TEST_GCM_CONST_KEY[4] =
{0x92e9fffe, 0x1c736586, 0x948f6a6d, 0x08833067};

const uint32 TEST_DEMO_GCM_IV[3]=
{0xBEBAFECA,0xADDBCEFA,0x88F8CADE};

const uint32 TEST_DEMO_GCM_AAD[5]=
{0xCEFAEDFE,0xEFBEADDE,0xCEFAEDFE,0xEFBEADDE,0xD2DAADAB};


#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
#if ITF
typedef enum
{
  CRY_GCM_IDLE=0,
  GCM_ENCSTART_NULLKEY,
  GCM_ENCSTART_NULLIV,
  GCM_ENCSTART_CRYUNIINIT,
  GCM_ENC_IPKEY_100,
  GCM_ENC_INVALIDLENGTH,
  GCM_ENCUPDATE_NULLCONFIG,
  GCM_ENCUPDATE_NULLPLNTXTPTR,
  GCM_ENCUPDATE_NULLCIPHTXTPTR,
  GCM_ENCUPDATE_INVALIDCIPHLENGTH,
  GCM_ENCUPDATE_NULLAADPTR,
  GCM_ENCUPDATE_SERVICENOTSTARTED,
  GCM_ENCUPDATE_SMALLBUFFER,
  GCM_ENCFINISH_NULLCONFIG,
  GCM_ENCFINISH_NULLAUTHTAGPTR,
  GCM_ENCFINISH_NULLAUTHTAGLENPTR,
  GCM_ENCFINISH_SERVICENOTSTARTED,
  GCM_ENC_START_UPDATE_FINISH_VALIDIP,
  GCM_ENC_START_UPDATE_FINISH_DIFFAUTHTAG,
  GCM_ENC_MUL_UPDATE,
  GCM_START_UPDATE_TILLDELAY,
  GCM_FINISH_AFTERDELAY,
  GCM_START_FINISH,
  GCM_DECSTART_NULLKEY,
  GCM_DECSTART_NULLIV,
  GCM_DECSTART_CRYUNIINIT,
  GCM_DEC_IPKEY_100,
  GCM_DEC_INVALIDLENGTH,
  GCM_DECUPDATE_NULLCONFIG,
  GCM_DECUPDATE_NULLCIPHTXTPTR,
  GCM_DECUPDATE_NULLPLNTXTPTR,
  GCM_ENCUPDATE_INVALIDPLAINLENGTH,
  GCM_DECUPDATE_NULLAADPTR,
  GCM_DECUPDATE_SERVICENOTSTARTED,
  GCM_DECUPDATE_SMALLBUFFER,
  GCM_DECFINISH_NULLCONFIG,
  GCM_DECFINISH_NULLAUTHTRESPTR,
  GCM_DECFINISH_NULLAUTHTAGPTR,
  GCM_DECFINISH_SERVICENOTSTARTED,
  GCM_DEC_MUL_UPDATE,
  GCM_DEC_START_UPDATE_TILLDELAY,
  GCM_DEC_FINISH_AFTERDELAY,
  GCM_DEC_START_FINISH,
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  GCM_START_UPDATE_TILLDELAY_ASYNC,
  GCM_FINISH_AFTERDELAY_ASYNC,
  GCM_ENC_START_UPDATE_FINISH_VALIDIP_ASYNC,
  GCM_DEC_START_UPDATE_TILLDELAY_ASYNC,
  GCM_DEC_FINISH_AFTERDELAY_ASYNC,
  GCM_ENC_MUL_UPDATE_ASYNC,
  GCM_DEC_MUL_UPDATE_ASYNC
#endif
}GCM_TC;
/*uint8 GcmBswMErrorId_Upd1;
uint8 GcmBswMErrorId_Upd2;
uint8 GcmBswMErrorId_Fin;*/

GCM_TC CRY_GCM_TC = CRY_GCM_IDLE;

Csm_ReturnType ITF_GCM_retVal ;
Csm_ReturnType ITF_GCM_retVal1;
Csm_ReturnType ITF_GCM_retVal2;
Csm_ReturnType ITF_GCM_retVal2_2;
Csm_ReturnType ITF_GCM_retVal2_3;
Csm_ReturnType ITF_GCM_retVal3;

Csm_ReturnType ITF_GCM_retVal4;
Csm_ReturnType ITF_GCM_retVal5;
Csm_ReturnType ITF_GCM_retVal5_2;
Csm_ReturnType ITF_GCM_retVal5_3;
Csm_ReturnType ITF_GCM_retVal6;
Csm_ReturnType RetKeyLoadGCM;
uint32 ITF_AuthTagLength;
uint32 GCM_LongOutput;
uint8 GcmErrorCheck;

#endif
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
Csm_ReturnType GCMEncCallBackStartResult;
Csm_ReturnType GCMEncCallBackUpdateResult;
Csm_ReturnType GCMEncCallBackUpdateResult1;
Csm_ReturnType GCMEncCallBackFinishResult;
Csm_ReturnType GCMEncCallBackFinishResult1;
uint8 GCMEncFinishNotify;

Csm_ReturnType GCMDecCallBackStartResult;
Csm_ReturnType GCMDecCallBackUpdateResult;
Csm_ReturnType GCMDecCallBackFinishResult;
Csm_ReturnType GCMDecCallBackFinishResult1;
uint8 GCMDecFinishNotify;

#endif
TestHsm_gcm g_TestHsm_gcm = {0};

#define CRY_STOP_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"

extern void SampleCode_LoadPlainKey (HsmCom_KeyAddr KeyAddr,const HsmAes_Block *keyPtr,uint32 KeyLength);
/*************************************************************************************//**
 * Execution of GCM test suite
*//**************************************************************************************/
void TestHsm_Gcm(void)
{
    /*Single update with RAM key */
    TestHsm_aes_gcm_reference();
    /*Single update with Invalid Auth tag*/
    TestHsm_aes_gcm_reference_InvalidAuth();
    /*Multiple update with length in last update non multiple of 16 */
    TestHsm_aes_gcm_nonmul16();
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/

void TestHsm_aes_gcm_reference(void)
{
    uint32 length = sizeof(TEST_CONST_GCM_PLAIN_TEXT);

    SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const uint8 *)TEST_GCM_CONST_KEY,16);

    /* GCM ENCRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nGCM Encryption & Decryption: Single update\n");
    TEST_PRINTF("\nGCM encryption: len = %d bytes\n", length);
    GcmEncryptWithRamKey(TEST_CONST_GCM_PLAIN_TEXT, TEST_CONST_GCM_CIPHER_TXT, length);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_GCM_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Plain text : \n");
    TEST_PRINT480(TEST_CONST_GCM_PLAIN_TEXT);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Additional Authenticated data : \n");
    TEST_PRINT160(TEST_DEMO_GCM_AAD);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received Cipher Text : \n");
    TEST_PRINT480(TEST_CONST_GCM_CIPHER_TXT);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Authentication Tag Recieved: \n");
    TEST_PRINT128(Test_Hsm_TempGcmAuthTag);
    TEST_PRINTF("\n");

    /*GCM DECRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nGCM decryption: len = %d bytes\n", length);
    GcmDecryptWithRamKey(TEST_CONST_GCM_CIPHER_TXT, TEST_GCM_DEC_PLAIN_TXT, length);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Cipher text : \n");
    TEST_PRINT480(TEST_CONST_GCM_CIPHER_TXT);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Decryption Additional Authenticated data : \n");
    TEST_PRINT160(TEST_DEMO_GCM_AAD);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received Plain Text : \n");
    TEST_PRINT480(TEST_GCM_DEC_PLAIN_TXT);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Authentication Tag Sent: \n");
    TEST_PRINT128(Test_Hsm_TempGcmAuthTag);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Authentication Tag Result: %d\n",AuthTagResultPtr);
    TEST_PRINTF("\n");

    TEST_VALIDATE(AuthTagResultPtr == CSM_E_VER_OK);

}
/*****************************************************************************************
*****************************************************************************************
**                                                                                      **
*****************************************************************************************/

void TestHsm_aes_gcm_reference_InvalidAuth(void)
{
    uint32 length = sizeof(TEST_CONST_GCM_PLAIN_TEXT);

    SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const uint8 *)TEST_GCM_CONST_KEY,16);

    /* GCM ENCRYPTION TEST WITH INVALID AUTH FOR DECRYPTION */
    TEST_PRINTF("\nGCM Encryption & Decryption:Invalid Auth Tag\n");
    TEST_PRINTF("\nGCM encryption: len = %d bytes\n", length);
    GcmEncryptWithRamKey(TEST_CONST_GCM_PLAIN_TEXT, TEST_CONST_GCM_CIPHER_TXT, length);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_GCM_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Plain text : \n");
    TEST_PRINT480(TEST_CONST_GCM_PLAIN_TEXT);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Additional Authenticated data : \n");
    TEST_PRINT160(TEST_DEMO_GCM_AAD);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received Cipher Text : \n");
    TEST_PRINT480(TEST_CONST_GCM_CIPHER_TXT);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Authentication Tag Recieved: \n");
    TEST_PRINT128(Test_Hsm_TempGcmAuthTag);
    TEST_PRINTF("\n");

    /*GCM DECRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nGCM decryption: len = %d bytes\n", length);
    GcmDecryptWithRamKey_InvalidAuthTag(TEST_CONST_GCM_CIPHER_TXT, TEST_GCM_DEC_PLAIN_TXT, length);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Cipher text : \n");
    TEST_PRINT480(TEST_CONST_GCM_CIPHER_TXT);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Decryption Additional Authenticated data : \n");
    TEST_PRINT160(TEST_DEMO_GCM_AAD);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received Plain Text : \n");
    TEST_PRINT480(TEST_GCM_DEC_PLAIN_TXT);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Authentication Tag Sent: \n");
    TEST_PRINT128(TEST_CONST_RANDOM_NUMBER);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Authentication Tag Result: %d\n",AuthTagResultPtr);
    TEST_PRINTF("\n");

    TEST_VALIDATE(AuthTagResultPtr == CSM_E_VER_NOT_OK);

}
/*****************************************************************************************
*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void TestHsm_aes_gcm_nonmul16(void)
{
    uint32 length = 32;

    SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const uint8 *)TEST_GCM_CONST_KEY,16);

    /* GCM ENCRYPTION TEST WITH legnth non multiple of 16 */
    TEST_PRINTF("\nGCM Encryption & Decryption: Length non multiple of 16\n");
    TEST_PRINTF("\nGCM encryption: len = %d bytes\n", length);
    GcmEncryptMultiupdate_NonMul16(TEST_CONST_GCM_PLAIN_TEXT_32BYTES,TEST_CONST_GCM_PLAIN_TEXT_28BYTES,TEST_CONST_GCM_CIPHER_TXT_32BYTES, length);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Plain text 1: \n");
    TEST_PRINT256(TEST_CONST_GCM_PLAIN_TEXT_32BYTES);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Addition Authenticated Data 1: \n");
    TEST_PRINT160(TEST_DEMO_GCM_AAD);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Plain text 2: \n");
    TEST_PRINT224(TEST_CONST_GCM_PLAIN_TEXT_28BYTES);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Addition Authenticated Data 2: \n");
    TEST_PRINT160(TEST_DEMO_GCM_AAD);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_GCM_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received Cipher Text 1 : \n");
    TEST_PRINT256(TEST_CONST_GCM_CIPHER_TXT_32BYTES);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received Cipher Text 2 : \n");
    TEST_PRINT224(TEST_CONST_GCM_CIPHER_TXT_28BYTES);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received AuthenticationTag: \n");
    TEST_PRINT128(Test_Hsm_TempGcmAuthTag);
    TEST_PRINTF("\n");
    /*GCM DECRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nGCM decryption: len = %d bytes\n", length);
    GcmDecryptMultiUpdate_NonMul16(TEST_CONST_GCM_CIPHER_TXT_32BYTES,TEST_CONST_GCM_CIPHER_TXT_28BYTES,TEST_CONST_GCM_PLN_32BYTES, length);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Cipher text 1: \n");
    TEST_PRINT256(TEST_CONST_GCM_CIPHER_TXT_32BYTES);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Addition Authenticated Data 1: \n");
    TEST_PRINT160(TEST_DEMO_GCM_AAD);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Cipher text 2: \n");
    TEST_PRINT224(TEST_CONST_GCM_CIPHER_TXT_28BYTES);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Addition Authenticated Data 2: \n");
    TEST_PRINT160(TEST_DEMO_GCM_AAD);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_GCM_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received plain Text 1: \n");
    TEST_PRINT256(TEST_CONST_GCM_PLN_32BYTES);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received plain Text 2: \n");
    TEST_PRINT224(TEST_CONST_GCM_PLN_28BYTES);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Authentication Tag Sent: \n");
    TEST_PRINT128(Test_Hsm_TempGcmAuthTag);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Authentication Tag Result: %d\n", AuthTagResultPtr);
    TEST_PRINTF("\n");

    TEST_VALIDATE(AuthTagResultPtr == CSM_E_VER_OK);
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void TestHsm_aes_gcm_MultipleUpdate (void)
{
    uint32 length = sizeof(TEST_CONST_PLAIN_1);

    /*SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)TEST_GCM_CONST_KEY,16);*/

    /* GCM ENCRYPTION WITH Multiple updates */
    TEST_PRINTF("\nGCM Encryption & Decryption: Multiple update\n");
    TEST_PRINTF("\nGCM encryption: len = %d bytes\n", length);
    GcmEncryptMultiupdate(TEST_CONST_PLAIN_1,TEST_CONST_PLAIN_2,TEST_HSM_BUF_TEMP_C, length);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Plain text 1: \n");
    TEST_PRINT128(TEST_CONST_PLAIN_1);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Addition Authenticated Data 1: \n");
    TEST_PRINT128(TEST_CONST_PLAIN_3);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Plain text 2: \n");
    TEST_PRINT128(TEST_CONST_PLAIN_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Addition Authenticated Data 2: \n");
    TEST_PRINT128(TEST_CONST_PLAIN_4);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received Cipher Text 1: \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_C);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received Cipher Text 2: \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_D);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received AuthenticationTag: %d\n");
    TEST_PRINT128(Test_Hsm_TempGcmAuthTag);
    TEST_PRINTF("\n");

    /*GCM DECRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nGCM decryption: len = %d bytes\n", length);
    GcmDecryptMultiUpdate(TEST_HSM_BUF_TEMP_C, TEST_HSM_BUF_TEMP_D,TEST_HSM_BUF_TEMP_F, length);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Cipher text 1: \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_C);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Addition Authenticated Data 1: \n");
    TEST_PRINT128(TEST_CONST_PLAIN_3);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Cipher text 2: \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_D);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Encryption Addition Authenticated Data 2: \n");
    TEST_PRINT128(TEST_CONST_PLAIN_4);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received Plain Text 1: \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_F);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Received Plain Text 2: \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_G);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Authentication Tag Sent: \n");
    TEST_PRINT128(Test_Hsm_TempGcmAuthTag);
    TEST_PRINTF("\n");
    TEST_PRINTF("GCM Authentication Tag Result: %d\n", AuthTagResultPtr);
    TEST_PRINTF("\n");

    TEST_VALIDATE(AuthTagResultPtr == CSM_E_VER_OK);
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void GcmEncryptWithRamKey(const void *input, void *output, uint32 inputLength)
{
    uint32 AuthTagLength = 16;
    const Cry_HsmAesGcmEncryptConfigType* config = &Cry_kHsmAesGcmEncryptConfig;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesGcmEncryptStart(config, KEY_ENCRYPT_RAM_KEY,(uint8 *)TEST_DEMO_GCM_IV,sizeof(TEST_DEMO_GCM_IV));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    retVal = Cry_HsmAesGcmEncryptUpdate(config, input, inputLength, output, &outputLength,(const uint8 *)TEST_DEMO_GCM_AAD,sizeof(TEST_DEMO_GCM_AAD));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesGcmEncryptFinish(config, Test_Hsm_TempGcmAuthTag, &AuthTagLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void GcmDecryptWithRamKey(const void *input, void *output, uint32 inputLength)
{
    uint32 AuthTagLength = 16;
    const Cry_HsmAesGcmEncryptConfigType* config = &Cry_kHsmAesGcmDecryptConfig;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesGcmDecryptStart(config, KEY_ENCRYPT_RAM_KEY,(uint8 *)TEST_DEMO_GCM_IV,sizeof(TEST_DEMO_GCM_IV));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    retVal = Cry_HsmAesGcmDecryptUpdate(config, input, inputLength, output, &outputLength,(const uint8 *)TEST_DEMO_GCM_AAD,sizeof(TEST_DEMO_GCM_AAD));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)
    retVal = Cry_HsmAesGcmDecryptFinish(config,&AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, AuthTagLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void GcmDecryptWithRamKey_InvalidAuthTag(const void *input, void *output, uint32 inputLength)
{
    uint32 AuthTagLength = 16;
    const Cry_HsmAesGcmEncryptConfigType* config = &Cry_kHsmAesGcmDecryptConfig;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesGcmDecryptStart(config, KEY_ENCRYPT_RAM_KEY,(uint8 *)TEST_DEMO_GCM_IV,sizeof(TEST_DEMO_GCM_IV));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    retVal = Cry_HsmAesGcmDecryptUpdate(config, input, inputLength, output, &outputLength,(const uint8 *)TEST_DEMO_GCM_AAD,sizeof(TEST_DEMO_GCM_AAD));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)
    retVal = Cry_HsmAesGcmDecryptFinish(config,&AuthTagResultPtr,TEST_CONST_RANDOM_NUMBER, AuthTagLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void GcmEncryptMultiupdate(const void *input1,const void* input2, void *output, uint32 inputLength)
{
    uint32 AuthTagLength = 16;
    const Cry_HsmAesGcmEncryptConfigType* config = &Cry_kHsmAesGcmEncryptConfig;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesGcmEncryptStart(config, KEY_ENCRYPTION,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    retVal = Cry_HsmAesGcmEncryptUpdate(config, input1, inputLength, output, &outputLength,TEST_CONST_PLAIN_3,sizeof(TEST_CONST_PLAIN_3));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesGcmEncryptUpdate(config, input2, inputLength,(uint8 *) TEST_HSM_BUF_TEMP_D, &outputLength,TEST_CONST_PLAIN_4,sizeof(TEST_CONST_PLAIN_4));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesGcmEncryptFinish(config, Test_Hsm_TempGcmAuthTag, &AuthTagLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void GcmDecryptMultiUpdate(const void *input1,const void* input2, void *output, uint32 inputLength)
{
    uint32 AuthTagLength = 16;
    const Cry_HsmAesGcmEncryptConfigType* config = &Cry_kHsmAesGcmDecryptConfig;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesGcmDecryptStart(config, KEY_ENCRYPTION,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    retVal = Cry_HsmAesGcmDecryptUpdate(config, input1, inputLength, output, &outputLength,TEST_CONST_PLAIN_3,sizeof(TEST_CONST_PLAIN_3));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesGcmDecryptUpdate(config, input2, inputLength,(uint8 *) TEST_HSM_BUF_TEMP_G, &outputLength,TEST_CONST_PLAIN_4,sizeof(TEST_CONST_PLAIN_4));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesGcmDecryptFinish(config,&AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, AuthTagLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void GcmEncryptMultiupdate_NonMul16(const void *input1,const void* input2, void *output, uint32 inputLength)
{
    uint32 AuthTagLength = 16;
    const Cry_HsmAesGcmEncryptConfigType* config = &Cry_kHsmAesGcmEncryptConfig;
    uint32 outputLength = inputLength;
    uint32 outputLength2 ;
    Csm_ReturnType retVal;

    outputLength2 = 28;

    retVal = Cry_HsmAesGcmEncryptStart(config, KEY_ENCRYPT_RAM_KEY,(uint8  *)TEST_DEMO_GCM_IV,sizeof(TEST_DEMO_GCM_IV));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    retVal = Cry_HsmAesGcmEncryptUpdate(config, input1, inputLength, output, &outputLength,(const uint8 *)TEST_DEMO_GCM_AAD,sizeof(TEST_DEMO_GCM_AAD));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesGcmEncryptUpdate(config, input2, 28,(uint8 *) TEST_CONST_GCM_CIPHER_TXT_28BYTES, &outputLength2,(const uint8 *)TEST_DEMO_GCM_AAD,sizeof(TEST_DEMO_GCM_AAD));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesGcmEncryptFinish(config, Test_Hsm_TempGcmAuthTag, &AuthTagLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void GcmDecryptMultiUpdate_NonMul16(const void *input1,const void* input2, void *output, uint32 inputLength)
{
    uint32 AuthTagLength = 16;
    const Cry_HsmAesGcmEncryptConfigType* config = &Cry_kHsmAesGcmDecryptConfig;
    uint32 outputLength = inputLength;
    uint32 outputLength2 ;
    Csm_ReturnType retVal;

    outputLength2 = 28;

    retVal = Cry_HsmAesGcmDecryptStart(config, KEY_ENCRYPT_RAM_KEY,(uint8  *)TEST_DEMO_GCM_IV,sizeof(TEST_DEMO_GCM_IV));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    retVal = Cry_HsmAesGcmDecryptUpdate(config, input1, inputLength, output, &outputLength,(const uint8 *)TEST_DEMO_GCM_AAD,sizeof(TEST_DEMO_GCM_AAD));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesGcmDecryptUpdate(config, input2, sizeof(TEST_CONST_GCM_CIPHER_TXT_28BYTES),(uint8 *) TEST_CONST_GCM_PLN_28BYTES, &outputLength2,(const uint8 *)TEST_DEMO_GCM_AAD,sizeof(TEST_DEMO_GCM_AAD));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesGcmDecryptFinish(config,&AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, AuthTagLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
#endif
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymGcmEncryptCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
    {
        g_TestHsm_gcm.callbackSet = 1;
    }
    else
    {
#if ITF
        g_TestHsm_cbc.callbackSet = 2;
#else
        g_TestHsm_gcm.callbackSet = 2;
        TEST_PRINTF("GCM function failed in mainloop with ret value %d \n ", result);
#endif
    }

#if ITF
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF

    switch(Cry_PrimStatusAsync[CRY_HSM_SYM_ENCRYPT])
    {
      case ASYNC_STATE_START:
      {
          GCMEncCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
          GCMEncCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
          GCMEncCallBackFinishResult = result;
         break;
      }
      default:
      {
            break;
      }
    }

    switch(Cry_PrimStatusAsync[CRY_HSM_SYM_DECRYPT])
        {
          case ASYNC_STATE_START:
          {
             GCMDecCallBackStartResult = result;
             break;
          }
          case ASYNC_STATE_UPDATE:
          {
              GCMDecCallBackUpdateResult = result;
             break;
          }
          case ASYNC_STATE_FINISH:
          {
              GCMDecCallBackFinishResult = result;
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
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymGcmEncryptServiceFinishNotification(void)
{
#if ITF
    GCMEncFinishNotify = 1;
#endif
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymGcmDecryptCallbackNotification(Csm_ReturnType result)
{
    Csm_SymGcmEncryptCallbackNotification(result);
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymGcmDecryptServiceFinishNotification(void)
{
#if ITF
    GCMDecFinishNotify = 1;
#else
    Csm_SymGcmEncryptServiceFinishNotification();
#endif
}
#endif
#if ITF
void GcmParameter_Init()
{
    ITF_GCM_retVal  =CSM_E_ENTROPY_EXHAUSTION;
    ITF_GCM_retVal1 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_GCM_retVal2 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_GCM_retVal3 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_GCM_retVal4 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_GCM_retVal5 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_GCM_retVal6 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_GCM_retVal2_2 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_GCM_retVal2_3 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_GCM_retVal5_2 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_GCM_retVal5_3 =CSM_E_ENTROPY_EXHAUSTION;
    RetKeyLoadGCM = CSM_E_ENTROPY_EXHAUSTION;
    GcmErrorCheck =0;
    DetErrorId = 99;
    DetApiId = 99;
    DetModuleId = 99;
    BswMErrorId =99;
    GCM_LongOutput = 0;
    /*GcmBswMErrorId_Upd1 = 99;
    GcmBswMErrorId_Upd2 = 99;
    GcmBswMErrorId_Fin = 99;*/
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    GCMEncCallBackUpdateResult1 = CSM_E_ENTROPY_EXHAUSTION;
    GCMEncCallBackFinishResult1 = CSM_E_ENTROPY_EXHAUSTION;
    GCMDecCallBackFinishResult1 = CSM_E_ENTROPY_EXHAUSTION;
#endif
    ITF_AuthTagLength = 0;

}
void ITF_GCM()
{
  const Cry_HsmAesGcmEncryptConfigType* encConfig;
  const Cry_HsmAesGcmDecryptConfigType* decConfig;
  const Cry_HsmAesGcmEncryptConfigType* config1;
  const Cry_HsmAesGcmDecryptConfigType* decConfig1;
  Cry_HsmAesGcmEncryptConfigType Cry_kHsmAesGcmEncryptDelay;
  Cry_HsmAesGcmDecryptConfigType Cry_kHsmAesGcmDecryptDelay ;

  Cry_kHsmAesGcmEncryptDelay.TimeOut.TimeoutStart = 0U;
  Cry_kHsmAesGcmEncryptDelay.TimeOut.TimeoutUpdateConst = 0U;
  Cry_kHsmAesGcmEncryptDelay.TimeOut.TimeoutUpdateperByte = 0U;
  Cry_kHsmAesGcmEncryptDelay.TimeOut.TimeoutFinish = 0U;

  Cry_kHsmAesGcmDecryptDelay.TimeOut.TimeoutStart = 0U;
  Cry_kHsmAesGcmDecryptDelay.TimeOut.TimeoutUpdateConst = 0U;
  Cry_kHsmAesGcmDecryptDelay.TimeOut.TimeoutUpdateperByte = 0U;
  Cry_kHsmAesGcmDecryptDelay.TimeOut.TimeoutFinish = 0U;

  encConfig = &Cry_kHsmAesGcmEncryptConfig;
  decConfig = &Cry_kHsmAesGcmDecryptConfig;
  config1 = &Cry_kHsmAesGcmEncryptDelay;
  decConfig1 = &Cry_kHsmAesGcmDecryptDelay;

  uint32 outputLength;
  uint32 outputLength1;
  uint32 inputLength;
  uint32 inputLength1;

  switch(CRY_GCM_TC)
  {
      /*CRY_GCM_TC_01*/
      case GCM_ENCSTART_NULLKEY:
      {
          GcmParameter_Init();
          ITF_GCM_retVal= Cry_HsmAesGcmEncryptStart(encConfig,NULL_PTR,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) &&
             (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID) &&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_02*/
      case GCM_ENCSTART_NULLIV :
      {
          GcmParameter_Init();
          ITF_GCM_retVal= Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,NULL_PTR,sizeof(TEST_GCM_CONST_INIT_VEC));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) &&
             (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_03*/
      case GCM_ENCSTART_CRYUNIINIT :
      {
          GcmParameter_Init();
          Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
          ITF_GCM_retVal = Cry_HsmAesGcmEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
          if((DetErrorId == CRY_HSM_E_UNINIT ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_04*/
      case GCM_ENC_IPKEY_100 :
      {
          GcmParameter_Init();
          Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
          ITF_GCM_retVal = Cry_HsmAesGcmEncryptStart(encConfig, &TestKey_100, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
          if((DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_05*/
      case GCM_ENC_INVALIDLENGTH :
      {
          GcmParameter_Init();
          ITF_GCM_retVal = Cry_HsmAesGcmEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, 8);
          if((DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_06*/
      case GCM_ENCUPDATE_NULLCONFIG :
      {
          GcmParameter_Init();
          ITF_GCM_retVal =  Cry_HsmAesGcmEncryptUpdate(NULL_PTR, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_07*/
      case GCM_ENCUPDATE_NULLPLNTXTPTR :
      {
          GcmParameter_Init();
          ITF_GCM_retVal =  Cry_HsmAesGcmEncryptUpdate(encConfig, NULL_PTR, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_08*/
      case GCM_ENCUPDATE_NULLCIPHTXTPTR:
      {
          GcmParameter_Init();
          ITF_GCM_retVal =  Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), NULL_PTR, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_09*/
      case GCM_ENCUPDATE_INVALIDCIPHLENGTH:
      {
          GcmParameter_Init();
          ITF_GCM_retVal =  Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, NULL_PTR,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_10*/
      case GCM_ENCUPDATE_NULLAADPTR :
      {
          GcmParameter_Init();
          ITF_GCM_retVal =  Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *)TEST_HSM_BUF_TEMP_C, &outputLength,NULL_PTR,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_11*/
      case GCM_ENCUPDATE_SERVICENOTSTARTED:
      {
          GcmParameter_Init();
          Cry_PrimStatus [CRY_HSM_SYM_GCM_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED ;
          ITF_GCM_retVal =  Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_12*/
      case GCM_ENCUPDATE_SMALLBUFFER :
      {
          GcmParameter_Init();
          Cry_PrimStatus [CRY_HSM_SYM_GCM_ENCRYPT] = CRY_HSM_PRIM_STARTED ;
          GCM_LongOutput = 8;
          ITF_GCM_retVal =  Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &GCM_LongOutput,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_SMALL_BUFFER))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_13*/
      case GCM_ENCFINISH_NULLCONFIG :
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          ITF_GCM_retVal = Cry_HsmAesGcmEncryptFinish(NULL_PTR,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_14*/
      case GCM_ENCFINISH_NULLAUTHTAGPTR :
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          ITF_GCM_retVal = Cry_HsmAesGcmEncryptFinish(encConfig,NULL_PTR,&ITF_AuthTagLength);
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_15*/
      case GCM_ENCFINISH_NULLAUTHTAGLENPTR :
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          ITF_GCM_retVal = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,NULL_PTR);
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
      }
      break;
      /*CRY_GCM_TC_16*/
      case GCM_ENCFINISH_SERVICENOTSTARTED :
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          Cry_PrimStatus[CRY_HSM_SYM_GCM_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED;
          ITF_GCM_retVal = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
          if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED ) && (DetApiId ==CRY_HSM_SID_AES_GCM_ENCRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          Cry_PrimStatus[CRY_HSM_SYM_GCM_ENCRYPT] = CRY_HSM_PRIM_STARTED;
          CRY_GCM_TC = CRY_GCM_IDLE;

      }
      break;
      /*CRY_GCM_TC_17*/
      case GCM_ENC_START_UPDATE_FINISH_VALIDIP:
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          outputLength = sizeof(TEST_CONST_PLAIN_1);
          ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
          inputLength = sizeof(TEST_HSM_BUF_TEMP_C);
          ITF_GCM_retVal4 = Cry_HsmAesGcmDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
          ITF_GCM_retVal5 = Cry_HsmAesGcmDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_C, sizeof(TEST_HSM_BUF_TEMP_C),(uint8 *) TEST_HSM_BUF_TEMP_D, &inputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          ITF_GCM_retVal6 = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);

          if( (HsmCom_CompareArray((const uint32*)TEST_HSM_BUF_TEMP_D, (const uint32*)TEST_CONST_PLAIN_1, 4))!= FALSE )
          {
              GcmErrorCheck =1;
          }
          else
          {
              GcmErrorCheck =0;

          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      case GCM_ENC_START_UPDATE_FINISH_DIFFAUTHTAG:
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          outputLength = sizeof(TEST_CONST_PLAIN_1);
          ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
          inputLength = sizeof(TEST_HSM_BUF_TEMP_C);
          ITF_GCM_retVal4 = Cry_HsmAesGcmDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
          ITF_GCM_retVal5 = Cry_HsmAesGcmDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_C, sizeof(TEST_HSM_BUF_TEMP_C),(uint8 *) TEST_HSM_BUF_TEMP_D, &inputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          ITF_GCM_retVal6 = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,TEST_CONST_PLAIN_4, ITF_AuthTagLength);

          if(((HsmCom_CompareArray((const uint32*)TEST_HSM_BUF_TEMP_D, (const uint32*)TEST_CONST_PLAIN_1, 4))== FALSE )&&
                  (AuthTagResultPtr == CSM_E_VER_NOT_OK))
          {
              GcmErrorCheck =1;
          }
          else
          {
              GcmErrorCheck =0;

          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_18*/
      case GCM_ENC_MUL_UPDATE :
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          outputLength = sizeof(TEST_CONST_PLAIN_1);
          outputLength1 = 10;
          ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          ITF_GCM_retVal2_2 = Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_GCM, sizeof(TEST_CONST_PLAIN_GCM), (uint8 *)TEST_HSM_BUF_TEMP_D, &outputLength1,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          ITF_GCM_retVal2_3 = Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_F, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);

          if((ITF_GCM_retVal1 == CSM_E_OK )&& (ITF_GCM_retVal2 == CSM_E_OK )&&
                  (ITF_GCM_retVal2_2 == CSM_E_OK) &&
                  (ITF_GCM_retVal2_3 == CSM_E_NOT_OK) &&
                   (ITF_GCM_retVal3 == CSM_E_OK))
          {
              GcmErrorCheck =1;
          }
          else
          {
              GcmErrorCheck =0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_19*/
      case GCM_START_UPDATE_TILLDELAY :
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          outputLength = 16;
          ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptUpdate(config1, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));


          if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
          {
              GcmErrorCheck =1;
          }
          else
          {
              GcmErrorCheck =0;
          }
          ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);

          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }

      case GCM_FINISH_AFTERDELAY :
      {
          GcmParameter_Init();
          ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_20*/
      case GCM_START_FINISH:
      {
          GcmParameter_Init();
          outputLength = 16;
          ITF_AuthTagLength = 16 ;
          ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);

          if((ITF_GCM_retVal1 == CSM_E_OK) && (ITF_GCM_retVal2 == CSM_E_NOT_OK))
          {
              ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
              ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
              ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
              if((ITF_GCM_retVal1 == CSM_E_OK) && (ITF_GCM_retVal2 == CSM_E_OK) && (ITF_GCM_retVal3 == CSM_E_OK))
              {
                  GcmErrorCheck = 1;
              }
              else
              {
                  GcmErrorCheck = 0;
              }
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }

      /*CRY_GCM_TC_42*/
      case GCM_DEC_START_FINISH:
      {
          GcmParameter_Init();
          outputLength = 16;
          ITF_AuthTagLength = 16;
          ITF_GCM_retVal1=  Cry_HsmAesGcmDecryptStart(decConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          ITF_GCM_retVal2 = Cry_HsmAesGcmDecryptFinish(decConfig,&AuthTagResultPtr,Test_Hsm_TempGcmAuthTag,ITF_AuthTagLength);

          if((ITF_GCM_retVal1 == CSM_E_OK) && (ITF_GCM_retVal2 == CSM_E_NOT_OK))
          {
              ITF_GCM_retVal1=  Cry_HsmAesGcmDecryptStart(decConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
              ITF_GCM_retVal2 = Cry_HsmAesGcmDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
              ITF_GCM_retVal3 = Cry_HsmAesGcmDecryptFinish(decConfig,&AuthTagResultPtr,Test_Hsm_TempGcmAuthTag,ITF_AuthTagLength);
              if((ITF_GCM_retVal1 == CSM_E_OK) && (ITF_GCM_retVal2 == CSM_E_OK) && (ITF_GCM_retVal3 == CSM_E_OK))
              {
                  GcmErrorCheck = 1;
              }
              else
              {
                  GcmErrorCheck = 0;
              }
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
      /*CRY_GCM_TC_21*/
      case GCM_ENC_START_UPDATE_FINISH_VALIDIP_ASYNC:
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          outputLength = sizeof(TEST_CONST_PLAIN_1);
          ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
          ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
          ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
          inputLength = sizeof(TEST_HSM_BUF_TEMP_C);
          ITF_GCM_retVal4 = Cry_HsmAesGcmDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
          TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
          ITF_GCM_retVal5 = Cry_HsmAesGcmDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_C, sizeof(TEST_HSM_BUF_TEMP_C),(uint8 *) TEST_HSM_BUF_TEMP_D, &inputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
          ITF_GCM_retVal6 = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);
          TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);

          if( (HsmCom_CompareArray((const uint32*)TEST_HSM_BUF_TEMP_D, (const uint32*)TEST_CONST_PLAIN_1, 4))!= FALSE )
          {
              GcmErrorCheck =1;
          }
          else
          {
              GcmErrorCheck =0;

          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_22*/
      case GCM_ENC_MUL_UPDATE_ASYNC :
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          outputLength = sizeof(TEST_CONST_PLAIN_1);
          outputLength1 = 32;
          ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
          ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
          ITF_GCM_retVal2_2 = Cry_HsmAesGcmEncryptUpdate(encConfig, (TEST_CONST_PLAIN+16), 32, (uint8 *)TEST_HSM_BUF_TEMP_H, &outputLength1,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
          ITF_GCM_retVal2_3 = Cry_HsmAesGcmEncryptUpdate(encConfig, (TEST_CONST_PLAIN+48), sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_F, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
          ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);

          if((ITF_GCM_retVal1 == CSM_E_OK )&& (ITF_GCM_retVal2 == CSM_E_OK )&&
                  (ITF_GCM_retVal2_2 == CSM_E_OK) &&
                  (ITF_GCM_retVal2_3 == CSM_E_OK) &&
                   (ITF_GCM_retVal3 == CSM_E_OK))
          {
              GcmErrorCheck =1;
          }
          else
          {
              GcmErrorCheck =0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }

      /*CRY_GCM_TC_23*/
      case GCM_START_UPDATE_TILLDELAY_ASYNC :
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          outputLength = 16;

          ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
          ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptUpdate(config1, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));

          if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
          {
              GcmErrorCheck =1;
          }
          else
          {
              GcmErrorCheck =0;
          }
          /* ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet); */

          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }

      case GCM_FINISH_AFTERDELAY_ASYNC :
      {
          GcmParameter_Init();
          ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
          TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_45*/
     case GCM_DEC_START_UPDATE_TILLDELAY_ASYNC :
     {
         GcmParameter_Init();
         inputLength = sizeof(TEST_CONST_PLAIN_1);
         ITF_GCM_retVal1 = Cry_HsmAesGcmDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
         TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
         ITF_GCM_retVal2 = Cry_HsmAesGcmDecryptUpdate(decConfig1,(uint8 *) TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &inputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));

         if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
         {
             GcmErrorCheck =1;
         }
         else
         {
             GcmErrorCheck =0;
         }
        /* ITF_GCM_retVal3 = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);
         TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet); */
         CRY_GCM_TC = CRY_GCM_IDLE;
         break;
     }
     case GCM_DEC_FINISH_AFTERDELAY_ASYNC :
     {
         GcmParameter_Init();
         ITF_GCM_retVal3 = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);
         TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
         CRY_GCM_TC = CRY_GCM_IDLE;
         break;
     }
         /*CRY_GCM_TC_44*/
     case GCM_DEC_MUL_UPDATE_ASYNC :
     {
         GcmParameter_Init();
         ITF_AuthTagLength = 16 ;
         outputLength = sizeof(TEST_CONST_PLAIN_1);
         outputLength1 = 32;
         ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
         TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
         ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
         TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
         ITF_GCM_retVal2_2 = Cry_HsmAesGcmEncryptUpdate(encConfig, (TEST_CONST_PLAIN+16), 32, (uint8 *)TEST_HSM_BUF_TEMP_H, &outputLength1,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
         TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
         ITF_GCM_retVal2_3 = Cry_HsmAesGcmEncryptUpdate(encConfig, (TEST_CONST_PLAIN+48), sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_F, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
         TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);
         ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);
         TEST_WAIT(&Cry_HsmAesGcmEncryptMainFunction, &g_TestHsm_gcm.callbackSet);


           inputLength = sizeof(TEST_CONST_PLAIN_1);
           inputLength1 = 32;
           ITF_GCM_retVal1 = Cry_HsmAesGcmDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
           TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
           ITF_GCM_retVal2 = Cry_HsmAesGcmDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_C, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_I, &inputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
           TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
           ITF_GCM_retVal2 = Cry_HsmAesGcmDecryptUpdate(decConfig,(uint8 *)TEST_HSM_BUF_TEMP_H, 32,(uint8 *) (TEST_HSM_BUF_TEMP_I+16), &inputLength1, TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
           TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
           ITF_GCM_retVal2 = Cry_HsmAesGcmDecryptUpdate(decConfig,(uint8 *)TEST_HSM_BUF_TEMP_F, sizeof(TEST_CONST_PLAIN_1),(uint8 *)(TEST_HSM_BUF_TEMP_I+48), &inputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
           TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);
           ITF_GCM_retVal3 = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);
           TEST_WAIT(&Cry_HsmAesGcmDecryptMainFunction, &g_TestHsm_gcm.callbackSet);


           if((ITF_GCM_retVal1 == CSM_E_OK )&& (ITF_GCM_retVal2 == CSM_E_OK )&&
                   (ITF_GCM_retVal2_2 == CSM_E_OK) &&
                   (ITF_GCM_retVal2_3 == CSM_E_OK) &&
                    (ITF_GCM_retVal3 == CSM_E_OK))
           {
               GcmErrorCheck =1;
           }
           else
           {
               GcmErrorCheck =0;
           }
           CRY_GCM_TC = CRY_GCM_IDLE;
           break;
     }

#endif

      /*CRY_GCM_TC_24*/
      case GCM_DECSTART_NULLKEY:
      {
          GcmParameter_Init();
          ITF_GCM_retVal1=  Cry_HsmAesGcmDecryptStart(decConfig,NULL_PTR,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) &&
             (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
          {
              GcmErrorCheck = 1;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_25*/
      case  GCM_DECSTART_NULLIV:
      {
          GcmParameter_Init();
          ITF_GCM_retVal1=  Cry_HsmAesGcmDecryptStart(decConfig,KEY_ENCRYPT_RAM_KEY,NULL_PTR,sizeof(TEST_GCM_CONST_INIT_VEC));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) &&
             (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
          {
              GcmErrorCheck = 1;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_26*/
      case GCM_DECSTART_CRYUNIINIT :
      {
          GcmParameter_Init();
          Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
          ITF_GCM_retVal = Cry_HsmAesGcmDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
          if((DetErrorId == CRY_HSM_E_UNINIT ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_27*/
      case GCM_DEC_IPKEY_100 :
      {
          GcmParameter_Init();
          Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
          ITF_GCM_retVal = Cry_HsmAesGcmDecryptStart(decConfig, &TestKey_100, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
          if((DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_28*/
      case GCM_DEC_INVALIDLENGTH :
      {
          GcmParameter_Init();
          ITF_GCM_retVal = Cry_HsmAesGcmDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, 8);
          if((DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_29*/
      case GCM_DECUPDATE_NULLCONFIG :
      {
          GcmParameter_Init();
          ITF_GCM_retVal =  Cry_HsmAesGcmDecryptUpdate(NULL_PTR, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_30*/
      case GCM_DECUPDATE_NULLCIPHTXTPTR :
      {
          GcmParameter_Init();
          ITF_GCM_retVal =  Cry_HsmAesGcmDecryptUpdate(decConfig, NULL_PTR, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_31*/
      case GCM_DECUPDATE_NULLPLNTXTPTR:
      {
          GcmParameter_Init();
          ITF_GCM_retVal =  Cry_HsmAesGcmDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), NULL_PTR, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_32*/
      case GCM_ENCUPDATE_INVALIDPLAINLENGTH :
      {
          GcmParameter_Init();
          ITF_GCM_retVal =  Cry_HsmAesGcmDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, NULL_PTR,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_33*/
      case GCM_DECUPDATE_NULLAADPTR :
      {
          GcmParameter_Init();
          ITF_GCM_retVal =  Cry_HsmAesGcmDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C,  &outputLength,NULL_PTR,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_34*/
      case GCM_DECUPDATE_SERVICENOTSTARTED :
      {
          GcmParameter_Init();
          Cry_PrimStatus [CRY_HSM_SYM_GCM_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED ;
          ITF_GCM_retVal =  Cry_HsmAesGcmDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_C,  &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_35*/
      case GCM_DECUPDATE_SMALLBUFFER :
      {
          GcmParameter_Init();
          Cry_PrimStatus [CRY_HSM_SYM_GCM_DECRYPT] = CRY_HSM_PRIM_STARTED ;
          outputLength = 8 ;
          ITF_GCM_retVal =  Cry_HsmAesGcmDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if((DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_SMALL_BUFFER))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_36*/
      case GCM_DECFINISH_NULLCONFIG :
      {
          GcmParameter_Init();
          ITF_GCM_retVal = Cry_HsmAesGcmDecryptFinish(NULL_PTR, &AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_37*/
      case GCM_DECFINISH_NULLAUTHTRESPTR :
      {
          GcmParameter_Init();
          ITF_GCM_retVal = Cry_HsmAesGcmDecryptFinish(decConfig, NULL_PTR,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_38*/
      case GCM_DECFINISH_NULLAUTHTAGPTR :
      {
          GcmParameter_Init();
          ITF_GCM_retVal = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,NULL_PTR, ITF_AuthTagLength);
          if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_39*/
      case GCM_DECFINISH_SERVICENOTSTARTED :
      {
          GcmParameter_Init();
          Cry_PrimStatus [CRY_HSM_SYM_GCM_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED ;
          ITF_GCM_retVal = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);
          if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED ) && (DetApiId ==CRY_HSM_SID_AES_GCM_DECRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID)&&(ITF_GCM_retVal == CSM_E_NOT_OK))
          {
              GcmErrorCheck = 1;
          }
          else
          {
              GcmErrorCheck = 0;
          }
          Cry_PrimStatus [CRY_HSM_SYM_GCM_DECRYPT] = CRY_HSM_PRIM_STARTED ;
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_40*/
      case GCM_DEC_MUL_UPDATE :
      {
          GcmParameter_Init();
          ITF_AuthTagLength = 16 ;
          outputLength = sizeof(TEST_CONST_PLAIN_1);
          outputLength1 = 32;
          ITF_GCM_retVal1=  Cry_HsmAesGcmEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY,TEST_GCM_CONST_INIT_VEC,sizeof(TEST_GCM_CONST_INIT_VEC));
          ITF_GCM_retVal2 = Cry_HsmAesGcmEncryptUpdate(encConfig, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          ITF_GCM_retVal2_2 = Cry_HsmAesGcmEncryptUpdate(encConfig, (TEST_CONST_PLAIN+16), 32, (uint8 *)TEST_HSM_BUF_TEMP_H, &outputLength1,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          ITF_GCM_retVal2_3 = Cry_HsmAesGcmEncryptUpdate(encConfig, (TEST_CONST_PLAIN+48), sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_F, &outputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          ITF_GCM_retVal3 = Cry_HsmAesGcmEncryptFinish(encConfig,Test_Hsm_TempGcmAuthTag,&ITF_AuthTagLength);


            inputLength = sizeof(TEST_CONST_PLAIN_1);
            inputLength1 = 32;
            ITF_GCM_retVal1 = Cry_HsmAesGcmDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
            ITF_GCM_retVal2 = Cry_HsmAesGcmDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_C, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_I, &inputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
            ITF_GCM_retVal2 = Cry_HsmAesGcmDecryptUpdate(decConfig,(uint8 *)TEST_HSM_BUF_TEMP_H, 32,(uint8 *) (TEST_HSM_BUF_TEMP_I+16), &inputLength1, TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
            ITF_GCM_retVal2 = Cry_HsmAesGcmDecryptUpdate(decConfig,(uint8 *)TEST_HSM_BUF_TEMP_F, sizeof(TEST_CONST_PLAIN_1),(uint8 *)(TEST_HSM_BUF_TEMP_I+48), &inputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
            ITF_GCM_retVal3 = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);

            if((ITF_GCM_retVal1 == CSM_E_OK )&& (ITF_GCM_retVal2 == CSM_E_OK )&&
                    (ITF_GCM_retVal2_2 == CSM_E_OK) &&
                    (ITF_GCM_retVal2_3 == CSM_E_OK) &&
                     (ITF_GCM_retVal3 == CSM_E_OK))
            {
                GcmErrorCheck =1;
            }
            else
            {
                GcmErrorCheck =0;
            }
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      /*CRY_GCM_TC_41*/
      case GCM_DEC_START_UPDATE_TILLDELAY :
      {
          GcmParameter_Init();
          inputLength = sizeof(TEST_CONST_PLAIN_1);
          ITF_GCM_retVal1 = Cry_HsmAesGcmDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_GCM_CONST_INIT_VEC, sizeof(TEST_GCM_CONST_INIT_VEC));
          ITF_GCM_retVal2 = Cry_HsmAesGcmDecryptUpdate(decConfig1,(uint8 *) TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_C, &inputLength,TEST_CONST_PLAIN_2,sizeof(TEST_CONST_PLAIN_2));
          if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
          {
              GcmErrorCheck =1;
          }
          else
          {
              GcmErrorCheck =0;
          }
          ITF_GCM_retVal3 = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);

          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }
      case GCM_DEC_FINISH_AFTERDELAY :
      {
          GcmParameter_Init();
          ITF_GCM_retVal3 = Cry_HsmAesGcmDecryptFinish(decConfig, &AuthTagResultPtr,Test_Hsm_TempGcmAuthTag, ITF_AuthTagLength);
          CRY_GCM_TC = CRY_GCM_IDLE;
          break;
      }

      default :
      {
          break;
      }
  }
}
#endif

