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
#include "SampleCode.h"
#define KEYMNG_CFG_FEATURE_KEYFLG_VERIFY_ONLY  (0)
/* Predefined initial keys for certain tests */
/* The following keys must always be inserted at the beginning of the test cycle
 * by the CBC / ECB / MAC / RNG tests
 */
#define CRY_START_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

static const SampleCode_KeyType Testkey_2  = {{{0x16157e2bul, 0xa6d2ae28ul, 0x8815f7abul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_2  */
static const SampleCode_KeyType Testkey_3  = {{{0x13167e2bul, 0xa3d6ae38ul, 0x8817f7abul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_3  */
static const SampleCode_KeyType Testkey_4  = {{{0x13167c2bul, 0xa3d6ac38ul, 0x8817f5abul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_4  */
#if (KEYMNG_CFG_FEATURE_KEYFLG_VERIFY_ONLY == 0)
/* Used for Mac Verification (Do not change the key value) */
static const SampleCode_KeyType Testkey_5  = {{{0x16157e2bul, 0xa6d2ae28ul, 0x8815f7abul, 0x3c4fcf09ul}}, 16U , 1U}; /* KEY_5  */ //key usage set
/* Used for Mac generation (Do not change the key value) */
static const SampleCode_KeyType Testkey_12 = {{{0x16157e2bul, 0xa6d2ae28ul, 0x8815f7abul, 0x3c4fcf09ul}}, 16U , 1U}; /* KEY_12 */ //key usage set
#else
/* Used for Mac Verification (Do not change the key value) */
static const SampleCode_KeyType Testkey_5  = {{{0x16157e2bul, 0xa6d2ae28ul, 0x8815f7abul, 0x3c4fcf09ul}}, 16U , 1U}; /* KEY_5  */
/* Used for Mac generation (Do not change the key value) */
static const SampleCode_KeyType Testkey_12 = {{{0x16157e2bul, 0xa6d2ae28ul, 0x8815f7abul, 0x3c4fcf09ul}}, 20U , 1U}; /* KEY_12 */
#endif
static const SampleCode_KeyType Testkey_6  = {{{0x13265c2bul, 0xa2d6bc38ul, 0x8837f5cbul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_6  */
/* Used for Encrption and Decryption (Do not change the key value)*/
static const SampleCode_KeyType Testkey_7  = {{{0x16157e2bul, 0xa6d2ae28ul, 0x8815f7abul, 0x3c4fcf09ul}}, 0x40U , 1U}; /* KEY_7  */ //boot protection set
static const SampleCode_KeyType Testkey_8  = {{{0x15147e2bul, 0xa5d4ae38ul, 0x8815f7abul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_8  */
static const SampleCode_KeyType Testkey_9  = {{{0x14156e2bul, 0xa4c4be38ul, 0x8715e7bbul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_9  */
static const SampleCode_KeyType Testkey_10  = {{{0x17146e2bul, 0xa7c4ae38ul, 0x8317eebbul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_10  */
static const SampleCode_KeyType Testkey_11  = {{{0x18156e2bul, 0xa8c42e38ul, 0x7416eeabul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_11  */
/* Used for Mac generation (Do not change the key value) */
/*static const SampleCode_KeyType Testkey_12 = {{{0x16157e2bul, 0xa6d2ae28ul, 0x8815f7abul, 0x3c4fcf09ul}}, 16U , 1U};*/ /* KEY_12 */
static const SampleCode_KeyType Testkey_14  = {{{0x15167e2bul, 0xa2d6ae28ul, 0x8816f7abul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_14  */
static const SampleCode_KeyType Testkey_15 = {{{0x16157e2bul, 0xa6d2ae28ul, 0x8815f7abul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_15 */
static const SampleCode_KeyType Testkey_16  = {{{0x13364c2bul, 0xa2c6dc38ul, 0x7827f7cbul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_16  */
static const SampleCode_KeyType Testkey_17  = {{{0x17168e2bul, 0xa5d4ae38ul, 0x8717f4abul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_17  */
static const SampleCode_KeyType Testkey_18  = {{{0x14158d2bul, 0xa4d5aa38ul, 0x7845f8abul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_18  */
static const SampleCode_KeyType Testkey_19  = {{{0x13146e2bul, 0xa4a4be28ul, 0x7714e7baul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_19  */
static const SampleCode_KeyType Testkey_20  = {{{0x12246e2bul, 0xa7c33e38ul, 0x8317bbbbul, 0x3c4fcf09ul}}, 0U , 1U}; /* KEY_20  */

/* These keys are a prerequisite for TestHsm_loadKeyTests(0) */
static const SampleCode_KeyType Testkey_masterECU = {{{0x03020100ul, 0x07060504ul, 0x0b0a0908ul, 0x0f0e0d0cul}}, 0U           , 1U}; /* MASTER_ECU_KEY*/
static const SampleCode_KeyType Testkey_1   = {{{0x0c0d0e0ful, 0x08090a0bul, 0x04050607ul, 0x00010203ul}}, 0U                 , 1U}; /* KEY_1  */
static const SampleCode_KeyType Testkey_13  = {{{0x0c0d0e0ful, 0x08090a0bul, 0x04050607ul, 0x00010203ul}}, 0U                 , 1U}; /* KEY_13 */
static const SampleCode_KeyType Testbootmackey = {{{0x03020100ul, 0x07060504ul, 0x0b0a0908ul, 0x0f0e0d0cul}}, 0U , 2U}; /* BOOT_MAC_KEY*/
static const SampleCode_KeyType TestInvaildbootmac = {{{0xa5a5a5a5ul, 0xa5a5a5a5ul, 0xa5a5a5a5ul, 0xa5a5a5a5ul}}, 0U , 3U};
static const SampleCode_KeyType Testkey_BootProtFlag  = {{{0x16157e2bul, 0xa6d2ae28ul, 0x8815f7abul, 0x3c4fcf09ul}}, 0x40U , 3U}; /* KEY_7  */
static const SampleCode_KeyType Testkey_XTS_Key1  = {{{0x88974c39ul, 0x9d98bd1aul ,0xe403c729ul, 0x97b3728aul}}, 0U , 2U}; /* KEY_2  */
static const SampleCode_KeyType Testkey_XTS_Key2  = {{{0x1bf5aca7ul, 0xee9e6459ul, 0x7432b3a9ul, 0xf41d54d8ul}}, 0U , 2U}; /* KEY_3  */
#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

#define NUM_BLOCKS 4
#define NUM_UINT32 ((NUM_BLOCKS * sizeof(HsmAes_Block)) / 4)
#define KEYFLAG_BOOT_PROTECTION             (0x40U)

/* Data blocks in this RAM structure are used to store encrypted data */
typedef struct
{
    HsmAes_Block ciph1[NUM_BLOCKS];
    HsmAes_Block ciph2[NUM_BLOCKS];
    HsmAes_Block ciph3[NUM_BLOCKS];
} TestKeyEncryptData;


#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
const uint32 TEST_CONST_LOAD_RAM_KEY_Mx[7*4] =
{
    /*M1*/
    0x00000000 , 0x00000000 , 0x00000000 , 0xE0010000 ,
    /*M2*/
    0xf2762815 , 0x8dcac79d , 0x708de318 , 0xb0924437 ,
    0x1ad756ac , 0x4fe98b1b , 0xf0d384b3 , 0x343a1045 ,
    /*M3*/
    0x6bef21b8 , 0xfabb6f60 , 0x873eb20d , 0x3a70cbbd ,
    /*M4*/
    0x00000000 , 0x00000000 , 0x00000000 , 0xE0010000 ,
    0x19c3355d , 0x0f517d3e , 0x88335540 , 0x69f663ce ,
    /*M5*/
    0x78d508d6 , 0xb3a186b0 , 0xcb429f16 , 0xadaf9ce3
};

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

extern void EncryptWithRamKey(const void *input, void *output, uint32 inputLength, char* Mode);
extern void DecryptWithRamKey(const void *input, void *output, uint32 inputLength, char* Mode);
extern void EncryptWithRamKeyMultipleUpdate(void *output, char* Mode);
extern void DecryptWithRamKeyMultipleUpdate(const void *input, void *output, char* Mode);

extern void XtsEncryptWithRamKey(const void *input, void *output, uint32 inputLength);
extern void XtsDecryptWithRamKey(const void *input, void *output, uint32 inputLength);
extern void XtsEncryptWithRamKeyMultipleUpdate(void *output);
extern void XtsDecryptWithRamKeyMultipleUpdate(const void *input, void *output);

void TestHsm_loadRamKey(void)
{
    boolean cmpResult;
    /*HsmCom_Error comErr = HSMCOM_ERC_NO_ERROR;*/
    ProtectedKey *load = (void*) TEST_HSM_BUF_TEMP_A;
    TestKeyEncryptData *ciph = (void*) TEST_HSM_BUF_TEMP_B;

    TEST_PRINTF("\nTest load RAM key ---------------------------------- \n");

    TEST_VALIDATE(sizeof(ProtectedKey) <= sizeof(TEST_HSM_BUF_TEMP_A))
    TEST_VALIDATE(sizeof(TestKeyEncryptData) <= sizeof(TEST_HSM_BUF_TEMP_B))

    TEST_PRINTF(" - Initialize test data\n");
    {
        /* Fill target RAM locations with unique-, dummy- but non-zero data */
        HsmCom_SetArrayValue((uint32*) load, 0x5A5A5A5AUL, sizeof(ProtectedKey) / 4);

        HsmCom_SetArrayValue((uint32*) ciph->ciph1, 0xA5A5A5A5UL, NUM_UINT32);
        TEST_VALIDATE(ciph->ciph1[0].Data[0] == 0xA5A5A5A5UL)
        TEST_VALIDATE(ciph->ciph1[NUM_BLOCKS-1].Data[0] == 0xA5A5A5A5UL)

        HsmCom_SetArrayValue((uint32*) ciph->ciph2, 0x12345678UL, NUM_UINT32);
        TEST_VALIDATE(ciph->ciph2[0].Data[0] == 0x12345678UL)
        TEST_VALIDATE(ciph->ciph2[NUM_BLOCKS-1].Data[0] == 0x12345678UL)

        HsmCom_SetArrayValue((uint32*) ciph->ciph3, 0xDEADBEEFUL, NUM_UINT32);
        TEST_VALIDATE(ciph->ciph3[0].Data[0] == 0xDEADBEEFUL)
        TEST_VALIDATE(ciph->ciph3[NUM_BLOCKS-1].Data[0] == 0xDEADBEEFUL)
    }
    TEST_PRINTF(" - Load plain key #1\n");
    {
        SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)TEST_CONST_KEY1,16);
    }
    TEST_PRINTF(" - Encrypt data #1 with key #1\n");
    {
        EncryptWithRamKey( TEST_CONST_PLAIN, ciph->ciph1, sizeof (TEST_CONST_PLAIN),(char *)'1');

        /* check that the RAM contains encrypted Data */
        TEST_VALIDATE(ciph->ciph1[0].Data[0] != 0xA5A5A5A5UL)
        TEST_VALIDATE(ciph->ciph1[NUM_BLOCKS-1].Data[0] != 0xA5A5A5A5UL)
    }
    TEST_PRINTF(" - Encrypt data #2 with key #1\n");
    {
        EncryptWithRamKey( TEST_CONST_PLAIN, ciph->ciph2, sizeof (TEST_CONST_PLAIN),(char *)'1');

        /* check that the RAM contains encrypted data */
        TEST_VALIDATE(ciph->ciph2[0].Data[0] != 0x12345678UL)
        TEST_VALIDATE(ciph->ciph2[NUM_BLOCKS-1].Data[0] != 0x12345678UL)
    }
    TEST_PRINTF(" - Compare encrypted data\n");
    {
        cmpResult = HsmCom_CompareArray((uint32*) ciph->ciph1, (uint32*) ciph->ciph2, NUM_UINT32);
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" - Export key #1\n");
    {
        SampleCode_ExportKey(load);
        cmpResult = HsmCom_CompareArray((uint32*) load, (uint32*) TEST_CONST_LOAD_RAM_KEY_Mx, sizeof(ProtectedKey)/sizeof(uint32));
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" - Load plain key #2\n");
    {
        SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)TEST_CONST_KEY2,16);
    }
    TEST_PRINTF(" - Encrypt data with loaded key\n");
    {
        EncryptWithRamKey( TEST_CONST_PLAIN, ciph->ciph3, sizeof (TEST_CONST_PLAIN),(char *)'1');

         /*TEST_VALIDATE(comErr == HSMCOM_ERC_NO_ERROR);*/

        /* check that the RAM contains encrypted data */
        TEST_VALIDATE(ciph->ciph3[0].Data[0] != 0xDEADBEEFUL)
        TEST_VALIDATE(ciph->ciph3[NUM_BLOCKS-1].Data[0] != 0xDEADBEEFUL)
    }
    TEST_PRINTF(" - Expecting wrong comparison due to unequal keys\n");
    {
        cmpResult = HsmCom_CompareArray((uint32*) ciph->ciph1, (uint32*) ciph->ciph3, NUM_UINT32);
        TEST_VALIDATE(cmpResult == FALSE)
    }
    TEST_PRINTF(" - Reimport the exported key\n");
    {
        HsmCom_SetArrayValue((uint32*)load->M4, 0, sizeof(load->M4) / sizeof(uint32));
        HsmCom_SetArrayValue((uint32*)load->M5, 0, sizeof(load->M5) / sizeof(uint32));
        SampleCode_LoadRamKey(load);
        cmpResult = HsmCom_CompareArray((uint32*)load, (uint32*)TEST_CONST_LOAD_RAM_KEY_Mx, sizeof(ProtectedKey) / sizeof(uint32));
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" - Decrypt data #1 with reimported key\n");
    {
        DecryptWithRamKey( ciph->ciph1, ciph->ciph2, sizeof (ciph->ciph1),(char *)'1');

        cmpResult = HsmCom_CompareArray((const uint32*) TEST_CONST_PLAIN, (uint32*) ciph->ciph2, NUM_UINT32);
        TEST_VALIDATE(cmpResult != FALSE)
    }
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
/* memory update protocol sample from SHE specification, 13.7:
 *
 * For KEY_1
    KEYNEW              0f0e0d0c0b0a09080706050403020100
    KEYAuthID           000102030405060708090a0b0c0d0e0f
    KEY_UPDATE_ENC_C    010153484500800000000000000000b0
    KEY_UPDATE_MAC_C    010253484500800000000000000000b0
    UID               000000000000000000000000000001
    ID                  4 (KEY_1)
    AuthID              1 (MASTER_ECU_KEY)
    CID               0000001 (28 bits)
    FID               00      (5 bits)
    K1                  118a46447a770d87828a69c222e2d17e
    K2                  2ebb2a3da62dbd64b18ba6493e9fbe22
    M1                  00000000000000000000000000000141
    M2                  2b111e2d93f486566bcbba1d7f7a9797
                        c94643b050fc5d4d7de14cff682203c3
    M3                  b9d745e5ace7d41860bc63c2b9f5bb46
    K3                  ed2de7864a47f6bac319a9dc496a788f
    K4                  ec9386fefaa1c598246144343de5f26a
    M4                  00000000000000000000000000000141
                        b472e8d8727d70d57295e74849a27917
    M5                  820d8d95dc11b4668878160cb2a4e23e
*/
const uint8 TEST_CONST_KEY_UPDATE_Mx[7 * 16] =
{
    /*M1*/
    0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x01,0x41,
    /*M2*/
    0x2b,0x11,0x1e,0x2d, 0x93,0xf4,0x86,0x56, 0x6b,0xcb,0xba,0x1d, 0x7f,0x7a,0x97,0x97,
    0xc9,0x46,0x43,0xb0, 0x50,0xfc,0x5d,0x4d, 0x7d,0xe1,0x4c,0xff, 0x68,0x22,0x03,0xc3,
    /*M3*/
    0xb9,0xd7,0x45,0xe5, 0xac,0xe7,0xd4,0x18, 0x60,0xbc,0x63,0xc2, 0xb9,0xf5,0xbb,0x46,
    /*M4*/
    0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x01,0x41,
    0xb4,0x72,0xe8,0xd8, 0x72,0x7d,0x70,0xd5, 0x72,0x95,0xe7,0x48, 0x49,0xa2,0x79,0x17,
    /*M5*/
    0x82,0x0d,0x8d,0x95, 0xdc,0x11,0xb4,0x66, 0x88,0x78,0x16,0x0c, 0xb2,0xa4,0xe2,0x3e
};


const uint8 TEST_CONST_KEY_UPDA13_Mx[7 * 16] =
{
    /*M1*/
    0x00,0x00,0x00,0x00 ,0x00,0x00,0x00,0x00 ,0x00,0x00,0x00,0x00 ,0x00,0x00,0x01,0x61,
    /*M2*/
    0xa6,0xc4,0xd8,0xf6 ,0x32,0xfa,0xed,0x10 ,0x3d,0x8e,0x3e,0xef ,0x2b,0x76,0x94,0xa9,
    0x2b,0x21,0x4b,0x1e ,0xfa,0xd1,0x6a,0x4c ,0x32,0x96,0x4a,0xfa ,0x37,0xdd,0xad,0xef,
    /*M3*/
    0x95,0x4c,0xd2,0x46 ,0x55,0x20,0x72,0x93 ,0xf2,0x21,0xa6,0x45 ,0xea,0x03,0xcb,0x9d,
    /*M4*/
    0x00,0x00,0x00,0x00 ,0x00,0x00,0x00,0x00 ,0x00,0x00,0x00,0x00 ,0x00,0x00,0x01,0x61,
    0xb0,0x59,0xc2,0x1a ,0xdb,0xcb,0x93,0x80 ,0x00,0xc9,0x80,0x54 ,0x34,0x85,0x26,0x37,
    /*M5*/
    0x6c,0xb2,0xbe,0xd8 ,0x40,0x8c,0x33,0x2e ,0x9c,0x8e,0x29,0x69 ,0xc1,0x29,0xce,0x31
};

#define CRY_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
boolean TestHsm_loadSingleKey(Cry_HsmKeySlotIdType keySlotId, 
							  Cry_HsmKeySlotIdType authSlotId, 
							  const uint8* newKey, 
							  uint32 flags, 
							  uint32 counter, 
							  boolean uidWildCard,
                             const uint8 * testBuffer, 
							 const uint8* text)
{
    boolean cmpResult = TRUE;
    Csm_ReturnType csmRes;
    ProtectedKey protKey;
    ProtectedKey* protKeyPtr = NULL_PTR;

    if (testBuffer != NULL_PTR) /* We want to get back the protected key contents */
    {
        protKeyPtr = &protKey;
    }

    TEST_PRINTF("===============================================\n - Start load key ");
    TEST_PRINTF((char*)text);

    csmRes = SampleCode_LoadEncryptedKey (keySlotId, authSlotId, (const HsmAes_Block*)newKey, flags, counter, uidWildCard, protKeyPtr);
    TEST_VALIDATE(csmRes == CSM_E_OK)

    /* If a test buffer is specified compare the protected key resulting from the load
     * (including M4, M5 messages) to the contents of the test buffer.
     */
    if ((csmRes == CSM_E_OK) && (testBuffer != NULL_PTR))
    {
        TEST_PRINTF(" - Compare with given protected key: ");
        cmpResult = HsmCom_CompareArray((uint32*)&protKey, (uint32*) testBuffer, sizeof(ProtectedKey) / sizeof(uint32));
        if (cmpResult != FALSE)
        {
            TEST_PRINTF("OK\n");
        }
        else
        {
            TEST_PRINTF("Failed\n");
        }
    }
    return ((csmRes == CSM_E_OK) && (cmpResult != FALSE));
}
#if ITF

boolean TestHsm_initializeTestKey_ITF(Cry_HsmKeySlotIdType keySlotId, const SampleCode_KeyType* testKey, const uint8* text)
{
    boolean LoadSingleKeyReturn;
    LoadSingleKeyReturn = TestHsm_loadSingleKey (keySlotId,  keySlotId, (const uint8*)&(testKey->key), testKey->flags, testKey->counter, FALSE, NULL_PTR, text);
    return LoadSingleKeyReturn;
}

boolean TestHsm_initializeOneStandardKeys_ITF()
{
    boolean InitTestKeyReturn;
    InitTestKeyReturn = TestHsm_initializeTestKey_ITF(CRY_HSM_KEY_3  ,&Testkey_3, (uint8*)"KEY_3\n");
    return InitTestKeyReturn;
}
#endif

static void TestHsm_initializeTestKey(Cry_HsmKeySlotIdType keySlotId, const SampleCode_KeyType* testKey, const uint8* text)
{
    TestHsm_loadSingleKey (keySlotId,  keySlotId, (const uint8*)&(testKey->key), testKey->flags, testKey->counter, FALSE, NULL_PTR, text);
}

static void TestHsm_loadKeyTests(boolean initBaseKeys)
{
    TEST_PRINTF("\nTest load key slot -------------------------------- \n");

            /* Initialize prerequisites */
            if (initBaseKeys)
            {
                TestHsm_initializeTestKey(CRY_HSM_MASTER_ECU_KEY, &Testkey_masterECU, (uint8*)"MASTER_ECU_KEY\n");
            }
            /* Execute test */
            TestHsm_loadSingleKey (CRY_HSM_KEY_1,  CRY_HSM_MASTER_ECU_KEY, (const uint8*) &(Testkey_1.key), Testkey_1.flags, Testkey_1.counter,  FALSE, TEST_CONST_KEY_UPDATE_Mx, (uint8*)"KEY_1:\n");
            TestHsm_loadSingleKey (CRY_HSM_KEY_13, CRY_HSM_MASTER_ECU_KEY, (const uint8*) &(Testkey_13.key),Testkey_13.flags,Testkey_13.counter, FALSE, TEST_CONST_KEY_UPDA13_Mx, (uint8*)"KEY_13:\n");
}

void TestHsm_initializeStandardKeys()
{
    TestHsm_initializeTestKey(CRY_HSM_KEY_1  ,&Testkey_1, (uint8*)"KEY_1\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_2  ,&Testkey_2, (uint8*)"KEY_2\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_3  ,&Testkey_3, (uint8*)"KEY_3\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_4 ,&Testkey_4,(uint8*)"KEY_4\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_5 ,&Testkey_5,(uint8*)"KEY_5\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_6  ,&Testkey_6, (uint8*)"KEY_6\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_7  ,&Testkey_7, (uint8*)"KEY_7\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_8  ,&Testkey_8, (uint8*)"KEY_8\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_9 ,&Testkey_9,(uint8*)"KEY_9\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_10 ,&Testkey_10,(uint8*)"KEY_10\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_11  ,&Testkey_11, (uint8*)"KEY_11\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_12  ,&Testkey_12, (uint8*)"KEY_12\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_13  ,&Testkey_13, (uint8*)"KEY_13\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_14 ,&Testkey_14,(uint8*)"KEY_14\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_15 ,&Testkey_15,(uint8*)"KEY_15\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_16  ,&Testkey_16, (uint8*)"KEY_16\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_17  ,&Testkey_17, (uint8*)"KEY_17\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_18  ,&Testkey_18, (uint8*)"KEY_18\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_19 ,&Testkey_19,(uint8*)"KEY_19\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_20 ,&Testkey_20,(uint8*)"KEY_20\n");
}

void TestHsm_SecBootinitializeStandardKeys()
{
  TestHsm_initializeTestKey(CRY_HSM_KEY_7  ,&Testkey_BootProtFlag, (uint8*)"KEY_7\n");
}
void TestHsm_UIDinitializeMasterKeys()
{
  /* it is CRY_HSM_MASTER_ECU_KEY is added for Get testing purpose */
  TestHsm_initializeTestKey(CRY_HSM_MASTER_ECU_KEY, &Testkey_masterECU, (uint8*)"MASTER_ECU_KEY\n");
}

void TestHsm_initializeBootMacKey(void)
{
  TestHsm_initializeTestKey(CRY_HSM_BOOT_MAC_KEY, &Testbootmackey, (uint8*)"BOOT_MAC_KEY\n");
}
void TestHsm_initializeInvalidBootMac(void)
{
  TestHsm_initializeTestKey(CRY_HSM_BOOT_MAC, &TestInvaildbootmac, (uint8*)"BOOT_MAC\n");
}
void TestHsm_initializeXtsKeys(void)
{
  TestHsm_initializeTestKey(CRY_HSM_KEY_3, &Testkey_XTS_Key1, (uint8*)"KEY_3\n");
  TestHsm_initializeTestKey(CRY_HSM_KEY_4, &Testkey_XTS_Key2, (uint8*)"KEY_4\n");
}

#if 0
#define SHE_BL_SIZE 0x1000
#ifndef __WIN32__
extern void _START(void);
#define SHE_BL_START ((void*)&_START)
#else
extern uint32 SHE_BL_START;
#endif
#endif
static SampleCode_KeyType BootMac;
void TestHsm_initializeBootMac(uint8 BootMacStatus)
{
  Csm_ReturnType csmRes = CSM_E_ENTROPY_EXHAUSTION;
  HsmAes_Block Temp_Key;
  if(BootMacStatus == 1)
  {
    csmRes = SampleCode_ComputeBootMac(&(Testbootmackey.key), &(BootMac.key));
    BootMac.flags = 0;
    BootMac.counter = 2;
  }
  else
  {
    SampleCode_InvalidBootMac(&(TestInvaildbootmac.key), &(BootMac.key));
    BootMac.flags = TestInvaildbootmac.flags;
    BootMac.counter = TestInvaildbootmac.counter;
    csmRes = CSM_E_OK;
  }
  if (csmRes == CSM_E_OK )
  {
    Cry_HsmKeySlotIdType keySlotId = CRY_HSM_BOOT_MAC;
    const HsmAes_Block* newKey = &(BootMac.key);
    Cry_HsmKeySlotIdType authSlotId = CRY_HSM_BOOT_MAC_KEY;
    uint32 flags = BootMac.flags;
    uint32 counter = BootMac.counter;
    boolean uidWildCard = FALSE;
    ProtectedKey protKey;
    ProtectedKey* protKeyPtr = &protKey;
    TEST_PRINTF("===============================================\n - Start load key ");
    TEST_PRINTF("BOOT_MAC\n");
    Read_g_KeyStorageFunc(authSlotId, &Temp_Key);
    Update_g_KeyStorageFunc(authSlotId, &(Testbootmackey.key));
    csmRes =  SampleCode_LoadEncryptedKey(keySlotId, authSlotId, newKey, flags, counter, uidWildCard, protKeyPtr);
    TEST_VALIDATE(csmRes == CSM_E_OK)
    Update_g_KeyStorageFunc(authSlotId, &Temp_Key);
  }
}
void TestHsm_initializeOneStandardKeys()
{
    TestHsm_initializeTestKey(CRY_HSM_KEY_3  ,&Testkey_3, (uint8*)"KEY_3\n");
}

/*
void TestHsm_KeyMng_Keys_RW()
{
    TestHsm_initializeTestKey(CRY_HSM_KEY_1  ,&Testkey_1, (uint8*)"KEY_1\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_2  ,&Testkey_2, (uint8*)"KEY_2\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_3  ,&Testkey_3, (uint8*)"KEY_3\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_4 ,&Testkey_4,(uint8*)"KEY_4\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_5 ,&Testkey_5,(uint8*)"KEY_5\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_6  ,&Testkey_6, (uint8*)"KEY_6\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_7  ,&Testkey_7, (uint8*)"KEY_7\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_8  ,&Testkey_8, (uint8*)"KEY_8\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_9 ,&Testkey_9,(uint8*)"KEY_9\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_10 ,&Testkey_10,(uint8*)"KEY_10\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_11  ,&Testkey_11, (uint8*)"KEY_11\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_12  ,&Testkey_12, (uint8*)"KEY_12\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_13  ,&Testkey_13, (uint8*)"KEY_13\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_14 ,&Testkey_14,(uint8*)"KEY_14\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_15 ,&Testkey_15,(uint8*)"KEY_15\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_16  ,&Testkey_16, (uint8*)"KEY_16\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_17  ,&Testkey_17, (uint8*)"KEY_17\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_18  ,&Testkey_18, (uint8*)"KEY_18\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_19 ,&Testkey_19,(uint8*)"KEY_19\n");
    TestHsm_initializeTestKey(CRY_HSM_KEY_20 ,&Testkey_20,(uint8*)"KEY_20\n");
}
*/

/*************************************************************************************//**
 * Execution of Key functions (Load key, export key)
*//**************************************************************************************/
void TestHsm_key(boolean initBaseKeys)
{
    static boolean firstCall = TRUE;

    /* Execute TestHsm_loadKey() only once,
     * because subsequent calls will fail because the
     * key counter value is identical
     */
    if (firstCall == TRUE)
    {
        firstCall = FALSE;

        TestHsm_loadKeyTests(initBaseKeys);
    }

    TestHsm_loadRamKey();
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
