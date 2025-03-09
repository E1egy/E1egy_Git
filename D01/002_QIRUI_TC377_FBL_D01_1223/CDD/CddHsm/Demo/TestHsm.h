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

/**
 * \file TestHsm.h
 *
 * \defgroup TestHsm
 */

#ifndef HSM_TEST_DEF_H_
#define HSM_TEST_DEF_H_ 1

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/

#include "TestApi.h"
#include "HsmCom_Priv.h"
#include "Cry_Hsm.h"
#include "TestHsmConst.h"
#include "Test_Print.h"

#define ITF 0
#define SHE_TESTCANCEL 0
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

extern const Csm_SymKeyType TestKey_2;
extern const Csm_SymKeyType TestKey_3;
extern const Csm_SymKeyType TestKey_4;
extern const Csm_SymKeyType TestKey_12;
extern const Csm_SymKeyType TestKey_5;
extern const Csm_SymKeyType TestKey_7;
extern const Csm_SymKeyType TestKey_RAM;

#if ITF
extern const Csm_SymKeyType TestKey_100;
#endif

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

extern HsmAes_Block UidData;
extern Csm_ReturnType RetTestHsm_MacGenerate;
extern uint32 HsmSheCancelFlag ;
extern boolean CancelRequired;
extern uint32 ISR_HsmStatus;
extern Csm_VerifyResultType AuthTagResultPtr;
extern uint8 Test_Hsm_TempGcmAuthTag[16];
extern uint8 Test_XTSEncOutput25Bytes[25];
extern uint8 Test_XTSDecOutput25Bytes[25];
extern uint32 TEST_CONST_GCM_CIPHER_TXT[15];
extern uint32 TEST_GCM_DEC_PLAIN_TXT[15];
extern uint32 TEST_CONST_GCM_CIPHER_TXT_32BYTES[8];
extern uint32 TEST_CONST_GCM_CIPHER_TXT_28BYTES[7];
extern uint32 TEST_CONST_GCM_PLN_32BYTES[8];
extern uint32 TEST_CONST_GCM_PLN_28BYTES[7];
#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define KEY_MAC_GENERATE            (&TestKey_12)
#define KEY_MAC_VERIFY              (&TestKey_5)
#define KEY_ENCRYPTION              (&TestKey_7)
#define KEY_ENCRYPTION_XTS_KEY1     (&TestKey_3)
#define KEY_ENCRYPTION_XTS_KEY2     (&TestKey_4)
#define KEY_ENCRYPT_RAM_KEY         (&TestKey_RAM)
#define KEY_MAC_GENERATE_RAM_KEY    (&TestKey_RAM)
#define KEY_MAC_VERIFY_RAM_KEY      (&TestKey_RAM)
#define KEY_BOOT_MAC_RAM_KEY        (&TestKey_RAM)
#define KEY_XTS_ENCRYPT_RAM_KEY     (&TestKey_RAM)
#define KEY_ENCRYPTION_SBPENABLE    (&TestKey_7)

#if SHE_TESTCANCEL
#define Gptch_CancelCommand  GptConf_GptChannel_Cry_HsmSheCancelTimer
#endif

#define CRY_HSMBOOTEN_CHK 0x01
#ifdef CONTROLLER_TC23x
#define CRY_HSMBOOTEN_VAL 0xc783
#else
#define CRY_HSMBOOTEN_VAL 0x783
#endif

#if ITF
#define KEY_MAC_GENERATE_KEY_100    (&TestKey_100)
#define KEY_MAC_VERIFY_KEY_100    (&TestKey_100)
#endif
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/

/** \addtogroup TestHsm
 * \{ */
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"

_EXTERN_ void TestHsm_aes(char* Mode);
_EXTERN_ void TestHsm_aes_ecb(void);
_EXTERN_ void TestHsm_random(void);

extern Csm_ReturnType GenerateTrngSeed(void);
extern void TestHsm_random_init(void);
extern void TestHsm_random_generate(void);
_EXTERN_ void TestHsm_runAll(void);

_EXTERN_ void TestHsm_generate_mac(void);
_EXTERN_ void TestHsm_verify_mac(void);
_EXTERN_ void TestHsm_key(boolean initBaseKeys);
_EXTERN_ void TestHsm_mac_timing(void);
_EXTERN_ void TestHsm_initializeStandardKeys(void);
_EXTERN_ void TestHsm_SecBootinitializeStandardKeys(void);
_EXTERN_ void TestHsm_initializeOneStandardKeys(void);
extern void TestHsm_aes_cbc_RamKey(char* ModeOption);
extern void TestHsm_initializeOneStandardKeys();
extern void TestHsm_verify_mac_Ram(void);
extern boolean VerifyCmac(uint8* key,const uint8* SecurityKey);
extern void TestHsm_generate_mac_Ram(void);
extern void GenerateMac_MeasureTime(const Csm_SymKeyType *keyPtr, const void* message,
          uint32 messageLength, void* macOut, uint32 macLength, boolean truncate);
extern boolean VerifyMac(const Csm_SymKeyType *keyPtr, const void* message,
              const void* macIn, uint32 messageLength, uint32 verifyLength);
_EXTERN_ void TestHsm_GetUID(void);
_EXTERN_ void TestHsm_Gcm(void);
_EXTERN_ void TestHsm_GetUID_func(void);
_EXTERN_ void TestHsm_UIDGenerateMac(void);
_EXTERN_ void TestHsm_Get_Status(void);
_EXTERN_ void Test_SheBootOk(void);
_EXTERN_ void Test_SheBootFailure(void);
extern void ITF_SECUREBOOT(void);
extern void ITF_GCM(void);
extern void TestHsm_aes_xts_Bytes(void);
extern void TestHsm_aes_xts(void);
#if SHE_TESTCANCEL
_EXTERN_ void TestHsm_CancelCommand(void);
_EXTERN_ void TestHsm_CryCancel(void);
#endif
_EXTERN_ void TestHsm_UIDinitializeMasterKeys(void);
_EXTERN_ void TestHsm_initializeBootMacKey(void);
_EXTERN_ void TestHsm_initializeInvalidBootMac(void);
_EXTERN_ void TestHsm_initializeXtsKeys(void);
_EXTERN_ void TestHsm_initializeBootMac(uint8 BootMacStatus);
#if ITF
extern void Mac_ITF(void);
#endif
extern boolean VerifyMac(const Csm_SymKeyType *keyPtr, const void* message, const void* macIn, uint32 messageLength, uint32 verifyLength);
extern void TestHsm_aes_ecb_reference_FlashKey(void);
_EXTERN_ void Test_HsmMcal(void);
_EXTERN_ void Test_HsmCom(void);
_EXTERN_ void Test_HsmDebug(void);
void TestHsm_step(void);
extern void TestCd_KeyMng_GetUid(uint8 *UidPtr);
extern void TestHsm_aes_gcm_reference(void);
extern void TestHsm_aes_gcm_reference_InvalidAuth(void);
extern void TestHsm_aes_gcm_nonmul16(void);
extern void TestHsm_aes_gcm_MultipleUpdate(void);
extern void GcmEncryptWithRamKey(const void *input,void *output, uint32 inputLength);
extern void GcmDecryptWithRamKey(const void *input, void *output, uint32 inputLength);
extern void GcmDecryptWithRamKey_InvalidAuthTag(const void *input, void *output, uint32 inputLength);
extern void GcmEncryptMultiupdate(const void *input1,const void* input2, void *output, uint32 inputLength);
extern void GcmDecryptMultiUpdate(const void *input1,const void* input2, void *output, uint32 inputLength);
extern void GcmEncryptMultiupdate_NonMul16(const void *input1,const void* input2, void *output, uint32 inputLength);
extern void GcmDecryptMultiUpdate_NonMul16(const void *input1,const void* input2, void *output, uint32 inputLength);
#if ITF
void ITF_RandomNumberGenerator(void);
void ITF_ECB_Enc_Dec(void);
void ITF_CBC_Enc_Dec(uint8 Aes_Mode);
boolean TestHsm_initializeOneStandardKeys_ITF(void);
_EXTERN_ void ITF_GetStatus(void);
_EXTERN_ void ITF_GETUID(void);
_EXTERN_ void ITF_Xts_Enc_Dec(void);
void ITF_CancelStatus(void);
#endif
#if  SHE_TESTCANCEL
void HsmSheCancelCallbackNotify(void);
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
#define DUR_COUNT 4

typedef struct
{
    volatile uint8 callbackSet;
    uint32 ver_duration[DUR_COUNT];
    float32 ver_speed;
    uint32 gen_duration[DUR_COUNT];
    float32 gen_speed;
    uint32 length;
} TestHsm_Mac;

typedef struct
{
    volatile uint8 callbackSet;
} TestHsm_ecb;

typedef struct
{
    volatile uint8 callbackSet;
} TestHsm_cbc;

typedef struct
{
    volatile uint8 callbackSet;
} TestHsm_xts;

typedef struct
{
    volatile uint8 callbackSet;
} TestHsm_gcm;

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

extern TestHsm_Mac g_TestHsm_mac;
extern TestHsm_ecb g_TestHsm_ecb;
extern TestHsm_cbc g_TestHsm_cbc;
#define CRY_STOP_SEC_VAR_UNSPECIFIED

/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/** \} */

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
void print_hex(const char *str, const void *data, int len);
void print128(const void *data);
void print96(const void *data);
void print200(const void *data);
void print480(const void *data);
void print160(const void *data);
void print256(const void *data);
void print224(const void *data);
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
#endif /* HSM_TEST_DEF_H_ */

#define TEST_TIME_CONSTANT ((float32)1.0 / 100 )
#if 1

#define TEST_PRINTF          print_f
#define TEST_PRINTHEX(m,len) print_hex("           ", m, len)
#define TEST_PRINT128(bytes) print128(bytes)
#define TEST_PRINT96(bytes)  print96(bytes)
#define TEST_PRINT200(bytes) print200(bytes)
#define TEST_PRINT480(bytes) print480(bytes)
#define TEST_PRINT160(bytes) print160(bytes)
#define TEST_PRINT256(bytes) print256(bytes)
#define TEST_PRINT224(bytes) print224(bytes)

#else

#define TEST_PRINTF(...)
#define TEST_PRINTHEX(...)
#define TEST_PRINT128(...)
#define TEST_PRINT96(...)

#endif

#define TEST_COMPARE(a,b,u32count) \
    TEST_VALIDATE(HsmCom_CompareArray((const uint32*)(a),(const uint32*)(b),u32count) != FALSE)

/*TEST_PRINTF("    .. PASSED: %s:%d\n", __FILE__, __LINE__);  \ */
#if (1)
#define TEST_VALIDATE(condition)                                    \
    if (condition)                                                  \
    {                                                               \
    }                                                               \
    else                                                            \
    {                                                               \
        TEST_PRINTF("    .. FAILED: \n");                           \
    }
#else
#define TEST_VALIDATE(condition)
#endif
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
_IFXEXTERN_ IFX_INLINE void TEST_WAIT(void (*MainFunction)(void), volatile uint8 *callbackSet)
{

    do
    {
        MainFunction();
        //Sleep(1);
    } while (*callbackSet == 0);
    *callbackSet = 0;

}
#endif


