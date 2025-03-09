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
#if ITF
#include "Det.h"
#include "BswM.h"
#include "Cry_Hsm_Priv.h"
#endif

#if 1

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
Csm_ReturnType TestHsm_xtsMainResult;
Csm_ReturnType AesXtsEncrypt_retVal;
TestHsm_xts g_TestHsm_xts = {0};
#if ITF
typedef enum{
CRY_XTS_IDLE=0,
XTS_ENCSTART_NULLKEYPTR1,
XTS_ENCSTART_NULLKEYPTR2,
XTS_ENCSTART_NULLINTVEC,
XTS_ENCSTART_CRYHSMUNINIT,
XTS_ENC_IPKEY_100_KEYPTR1,
XTS_ENC_IPKEY_100_KEYPTR2,
XTS_ENC_INVALIDLENGTH,
XTS_ENCUPDATE_NULLCONFIG,
XTS_ENCUPDATE_NULLPLNTXTPTR,
XTS_ENCUPDATE_NULLCIPHTXTPTR,
XTS_ENCUPDATE_INVALIDOPLENGTH,
XTS_ENCUPDATE_SERVICENOTSTARTED,
XTS_ENCUPDATE_SMALLBUFFER,
XTS_ENCFINISH_NULLCONFIG,
XTS_ENCFINISH_SERVICENOTSTARTED,
XTS_ENC_START_UPDATE_FINISH_VALIDIP,
XTS_ENC_DEC,
XTS_START_UPDATE_TILLDELAY,
XTS_FINISH_AFTERDELAY,
XTS_START_FINISH,
XTS_DEC_START_NULLCONFIG,
XTS_DEC_START_NULLKEYPTR1,
XTS_DEC_START_NULLKEYPTR2,
XTS_DEC_START_NULL_INIT_VEC,
XTS_DEC_START_CRY_HSM_UNIINIT,
XTS_DEC_START_IPKEY100_KEYPRT1,
XTS_DEC_START_IPKEY100_KEYPRT2,
XTS_DEC_START_IV8,
XTS_DEC_UPDATE_NULLCFG,
XTS_DEC_UPDATE_NULLCIPHTXT,
XTS_DEC_UPDATE_NULLPLNTXT,
XTS_DEC_UPDATE_NULLPLNTXTLENGTH,
XTS_DEC_UPDATE_CRY_HSM_NOTINIT,
XTS_DEC_UPDATE_DIFFLENGTH,
XTS_DEC_FINISH_NULLCFGPTR,
XTS_DEC_FINISH_SERVICENOTSTARTED,
XTS_DEC_START_UPDATE_FINISH,
XTS_DEC_ENC,
XTS_DEC_LESSTIMEOUT_TILLDELAY,
XTS_DEC_LESSTIMEOUT_AFTERDELAY,
XTS_DEC_START_FINISH,
CRY_XTS_UPDATE_CANCEL,
CRY_XTS_FINISH_CANCEL_SESSIONCLOSEVER,
CRY_XTS_DEC_FINISH_CANCEL_SESSIONCLOSVER,
CRY_XTS_ENC_DEC_NONMUL16,
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
XTS_START_UPDATE_FINISH_ASYNC,
XTS_START_UPDATE_FINISH_ASYNCTILLDELAY,
XTS_FINISH_ASYNCAFTERDELAY,
XTS_DEC_START_UPDATE_FINISH_ASYNC,
XTS_DEC_LESSTIMEOUT_ASYNCTILLDELAY,
XTS_DEC_LESSTIMEOUT_ASYNCAFTERDELAY,
CRY_XTS_UPDATE_CANCEL_ASYNC,
CRY_XTS_FINISH_CANCEL_SESSIONCLOSEVER_ASYNC,
CRY_XTS_DEC_FINISH_CANCEL_SESSIONCLOSEVER_ASYNC,
CRY_XTS_ENC_DEC_NONMUL16_ASYNC,
#endif
}XTS_TC;

XTS_TC ITF_XTS_TC= CRY_XTS_IDLE;
Csm_ReturnType ITF_XTS_retVal ;
Csm_ReturnType ITF_XTS_retVal1;
Csm_ReturnType ITF_XTS_retVal2;
Csm_ReturnType ITF_XTS_retVal2_2;
Csm_ReturnType ITF_XTS_retVal2_3;
Csm_ReturnType ITF_XTS_retVal3;

Csm_ReturnType ITF_XTS_retVal4;
Csm_ReturnType ITF_XTS_retVal5;
Csm_ReturnType ITF_XTS_retVal5_2;
Csm_ReturnType ITF_XTS_retVal5_3;
Csm_ReturnType ITF_XTS_retVal6;

Csm_ReturnType XTSEncCallBackStartResult;
Csm_ReturnType XTSEncCallBackUpdateResult;
Csm_ReturnType XTSEncCallBackUpdateResult1;
Csm_ReturnType XTSEncCallBackFinishResult;
Csm_ReturnType XTSEncCallBackFinishResult1;
uint8 XTSEncFinishNotify;

Csm_ReturnType XTSDecCallBackStartResult;
Csm_ReturnType XTSDecCallBackUpdateResult;
Csm_ReturnType XTSDecCallBackFinishResult;
Csm_ReturnType XTSDecCallBackFinishResult1;
uint8 XTSDecFinishNotify;

uint8 XtsErrorCheck;
uint8 XTS_Index;

uint8 XTS_TEST_PLAINTXT_16_1[16];
uint8 XTS_TEST_PLAINTXT_32[32];
uint8 XTS_TEST_PLAINTXT_16_2[16];
uint32 XTS_TEST_CIPHTEXT_16[16];

Csm_ReturnType RetKeyLoadXTS ;
#endif
#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
/* Data blocks in this RAM structure are used to store encrypted data */
#define NUM_BLOCKS 4
#define NUM_UINT32 ((NUM_BLOCKS * sizeof(HsmAes_Block)) / 4)
typedef struct
{
    HsmAes_Block ciph1[NUM_BLOCKS];
    HsmAes_Block ciph2[NUM_BLOCKS];
    HsmAes_Block ciph3[NUM_BLOCKS];
} TestKeyEncryptData;

#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

const uint8 XTS_Key1_1[16] =
{
  0x39,0x4c,0x97,0x88,0x1a,0xbd,0x98,0x9d,0x29,0xc7,0x03,0xe4,0x8a,0x72,0xb3,0x97
};
const uint8 XTS_Key2_2[16] =
{
  0xa7,0xac,0xf5,0x1b,0x59,0x64,0x9e,0xee,0xa9,0xb3,0x32,0x74,0xd8,0x54,0x1d,0xf4
};
const uint8 XTS_IV_2[16U] =
{
  0x4b,0x15,0xc6,0x84,0xa1,0x52,0xd4,0x85,0xfe,0x99,0x37,0xd3,0x9b,0x16,0x8c,0x29
};
const uint8 XTS_PT_25Bytes[25U] =
{    0x2f,0x3b,0x9d,0xcf,0xba,0xe7,0x29,0x58,0x3b,0x1d,0x1f,0xfd,0xd1,0x6b,0xb6,
     0xfe,0x27,0x57,0x32,0x94,0x35,0x66,0x2a,0x78,0xf0
};
const uint8 XTS_CT_25Bytes[25U] =
{     0xf3,0x47,0x38,0x02,0xe3,0x8a,0x3f,0xfe,0xf4,0xd4,0xfb,0x8e,0x6a,0xa2,0x66,
      0xeb,0xde,0x55,0x3a,0x64,0x52,0x8a,0x06,0x46,0x3e
};

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/

void Csm_SymXtsEncryptCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
    {
        TestHsm_xtsMainResult = CSM_E_OK;
        g_TestHsm_xts.callbackSet = 1;
    }
    else
    {
#if ITF
        g_TestHsm_xts.callbackSet = 2;
#else
        TestHsm_xtsMainResult = CSM_E_NOT_OK;
        g_TestHsm_xts.callbackSet = 2;
        TEST_PRINTF("XTS function failed in mainloop with ret value %d \n ", result);
#endif
    }

#if ITF
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF

    switch(Cry_PrimStatusAsync[CRY_HSM_SYM_XTS_ENCRYPT])
    {
      case ASYNC_STATE_START:
      {
         XTSEncCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
          XTSEncCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
          XTSEncCallBackFinishResult = result;
         break;
      }
      default:
      {
            break;
      }
    }

    switch(Cry_PrimStatusAsync[CRY_HSM_SYM_XTS_DECRYPT])
        {
          case ASYNC_STATE_START:
          {
             XTSDecCallBackStartResult = result;
             break;
          }
          case ASYNC_STATE_UPDATE:
          {
              XTSDecCallBackUpdateResult = result;
             break;
          }
          case ASYNC_STATE_FINISH:
          {
              XTSDecCallBackFinishResult = result;
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
void Csm_SymXtsEncryptServiceFinishNotification(void)
{
#if ITF
    XTSEncFinishNotify = 1;
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymXtsDecryptCallbackNotification(Csm_ReturnType result)
{
    Csm_SymXtsEncryptCallbackNotification(result);
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymXtsDecryptServiceFinishNotification(void)
{
#if ITF
    XTSDecFinishNotify = 1;
#else
    Csm_SymXtsEncryptServiceFinishNotification();
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
static boolean Xts_CompareBytes(const uint8* DestPtr,const uint8* SrcPtr,
                                    uint32 Count)
{
  boolean ResultVal;
  uint32 Index;

  ResultVal = TRUE;
  for (Index = 0U; Index < (Count); Index++)
  {
    if(DestPtr[Index] != SrcPtr[Index])
    {
      ResultVal = FALSE;
    }
  }
  return ResultVal;
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void XtsEncryptWithRamKey(const void *input, void *output, uint32 inputLength)
{
    const Cry_HsmAesXtsEncryptConfigType* config = &Cry_kHsmAesXtsEncryptConfig;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesXtsEncryptStart(config, KEY_ENCRYPTION_XTS_KEY1,KEY_ENCRYPTION_XTS_KEY2,
                                       XTS_IV_2, sizeof(XTS_IV_2));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsEncryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesXtsEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif

}
void XtsEncryptTimeout(const void *input, void *output, uint32 inputLength)
{
    const Cry_HsmAesXtsEncryptConfigType ConfigXTSLessTime =
    {.TimeOut =   {.TimeoutStart = 0,
                   .TimeoutUpdateConst = 3,
                   .TimeoutUpdateperByte = 0,
                   .TimeoutFinish = 3 }  };

    const Cry_HsmAesXtsEncryptConfigType* config = &ConfigXTSLessTime;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesXtsEncryptStart(config, KEY_ENCRYPTION_XTS_KEY1, KEY_ENCRYPTION_XTS_KEY2,
            XTS_IV_2, sizeof(XTS_IV_2));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsEncryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesXtsEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif

}

void XtsEncryptWithRamKeyMultipleUpdate(void *output)
{
    const Cry_HsmAesXtsEncryptConfigType* config = &Cry_kHsmAesXtsEncryptConfig;
    Csm_ReturnType retVal;
    uint8 *TempOutputPtr;
    uint32 outputLength = 16U;
    TempOutputPtr = output;
    retVal = Cry_HsmAesXtsEncryptStart(config, KEY_ENCRYPTION_XTS_KEY1, KEY_ENCRYPTION_XTS_KEY2,
            XTS_IV_2, sizeof(XTS_IV_2));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsEncryptUpdate(config, TEST_CONST_PLAIN_1, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsEncryptUpdate(config, TEST_CONST_PLAIN_2, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsEncryptUpdate(config, TEST_CONST_PLAIN_3, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsEncryptUpdate(config, TEST_CONST_PLAIN_4, 16U, TempOutputPtr, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif

}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void XtsDecryptWithRamKey(const void *input, void *output, uint32 inputLength)
{
	const Cry_HsmAesXtsDecryptConfigType* config = &Cry_kHsmAesXtsDecryptConfig;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesXtsDecryptStart(config, KEY_ENCRYPTION_XTS_KEY1, KEY_ENCRYPTION_XTS_KEY2,
            XTS_IV_2, sizeof(XTS_IV_2));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsDecryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesXtsDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif

}
void XtsDecryptTimeout(const void *input, void *output, uint32 inputLength)
{
    const Cry_HsmAesXtsEncryptConfigType ConfigXTSLessTime =
    {.TimeOut =   {.TimeoutStart = 0,
                   .TimeoutUpdateConst = 3,
                   .TimeoutUpdateperByte = 0,
                   .TimeoutFinish = 3 }  };

    const Cry_HsmAesXtsEncryptConfigType* config = &ConfigXTSLessTime;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesXtsDecryptStart(config, KEY_ENCRYPTION_XTS_KEY1,
            KEY_ENCRYPTION_XTS_KEY2, XTS_IV_2, sizeof(XTS_IV_2));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsDecryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesXtsDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif

}

void XtsDecryptWithRamKeyMultipleUpdate(const void *input, void *output)
{
    const Cry_HsmAesXtsDecryptConfigType* config = &Cry_kHsmAesXtsDecryptConfig;
    uint32 outputLength = 16U;
    Csm_ReturnType retVal;
    uint8 *TempOutputPtr;
    const uint8 *TempInputputPtr;
    TempOutputPtr = output;
    TempInputputPtr = input;
    retVal = Cry_HsmAesXtsDecryptStart(config, KEY_ENCRYPTION_XTS_KEY1, KEY_ENCRYPTION_XTS_KEY2,
            XTS_IV_2, sizeof(XTS_IV_2));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsDecryptUpdate(config, TempInputputPtr, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TempInputputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsDecryptUpdate(config, TempInputputPtr, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TempInputputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsDecryptUpdate(config, TempInputputPtr, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TempInputputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsDecryptUpdate(config, TempInputputPtr, 16U, TempOutputPtr, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif

}

static void AesXtsEncrypt_Bytes(const Cry_HsmAesXtsEncryptConfigType* config, const void *input, void *output, uint32 inputLength)
{
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;
    uint8 Index;
    for(Index=0; Index<25; Index++)
    {
      Test_XTSEncOutput25Bytes[Index] = 0x00;
    }
    retVal = Cry_HsmAesXtsEncryptStart(config, KEY_ENCRYPTION_XTS_KEY1,
             KEY_ENCRYPTION_XTS_KEY2, XTS_IV_2, sizeof(XTS_IV_2));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsEncryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesXtsEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
}
static void AesXtsDecrypt_Bytes(const Cry_HsmAesXtsDecryptConfigType* config, const void *input, void *output, uint32 inputLength)
{
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;
    uint8 Index;
    for(Index=0; Index<25; Index++)
    {
         Test_XTSDecOutput25Bytes[Index] = 0x00;
    }
    retVal = Cry_HsmAesXtsDecryptStart(config, KEY_ENCRYPTION_XTS_KEY1,
            KEY_ENCRYPTION_XTS_KEY2, XTS_IV_2, sizeof(XTS_IV_2));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    retVal = Cry_HsmAesXtsDecryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesXtsDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif

}

static void AesXtsEncrypt_InvLen(const Cry_HsmAesXtsEncryptConfigType* config, const void *input, void *output, uint32 inputLength)
{
    uint32 outputLength = inputLength;
    uint8 Index;
    for(Index=0; Index<25; Index++)
    {
      Test_XTSEncOutput25Bytes[Index] = 0x00;
    }
    AesXtsEncrypt_retVal = Cry_HsmAesXtsEncryptStart(config, KEY_ENCRYPTION_XTS_KEY1,
             KEY_ENCRYPTION_XTS_KEY2, XTS_IV_2, sizeof(XTS_IV_2));
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(AesXtsEncrypt_retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_VALIDATE(TestHsm_xtsMainResult == CSM_E_OK)
#endif
    AesXtsEncrypt_retVal = Cry_HsmAesXtsEncryptUpdate(config, input, inputLength, output, &outputLength);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_VALIDATE(TestHsm_xtsMainResult == CSM_E_NOT_OK)
#else
    TEST_VALIDATE(AesXtsEncrypt_retVal == CSM_E_NOT_OK)
#endif
    TEST_VALIDATE(outputLength == inputLength)

    AesXtsEncrypt_retVal = Cry_HsmAesXtsEncryptFinish(config, NULL_PTR, NULL_PTR);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_VALIDATE(TestHsm_xtsMainResult == CSM_E_NOT_OK)
#else
    TEST_VALIDATE(AesXtsEncrypt_retVal == CSM_E_NOT_OK)
#endif
}
static void AesXtsDecrypt_InvLen(const Cry_HsmAesXtsDecryptConfigType* config, const void *input, void *output, uint32 inputLength)
{
    uint32 outputLength = inputLength;

    uint8 Index;
    for(Index=0; Index<25; Index++)
    {
         Test_XTSDecOutput25Bytes[Index] = 0x00;
    }
    AesXtsEncrypt_retVal = Cry_HsmAesXtsDecryptStart(config, KEY_ENCRYPTION_XTS_KEY1,
            KEY_ENCRYPTION_XTS_KEY2, XTS_IV_2, sizeof(XTS_IV_2));
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(AesXtsEncrypt_retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_VALIDATE(TestHsm_xtsMainResult == CSM_E_OK)
#endif

    AesXtsEncrypt_retVal = Cry_HsmAesXtsDecryptUpdate(config, input, inputLength, output, &outputLength);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_VALIDATE(TestHsm_xtsMainResult == CSM_E_NOT_OK)
#else
    TEST_VALIDATE(AesXtsEncrypt_retVal == CSM_E_NOT_OK)
#endif
    TEST_VALIDATE(outputLength == inputLength)

    AesXtsEncrypt_retVal = Cry_HsmAesXtsDecryptFinish(config, NULL_PTR, NULL_PTR);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_VALIDATE(TestHsm_xtsMainResult == CSM_E_NOT_OK)
#else
    TEST_VALIDATE(AesXtsEncrypt_retVal == CSM_E_NOT_OK)
#endif

}
static void AesXtsEncrypt_MultiUpdates(const Cry_HsmAesXtsEncryptConfigType* config)
{
    uint32 outputLength;
    uint32 InputLength;
    Csm_ReturnType retVal;
    uint8 Index;
    for(Index=0; Index<25; Index++)
    {
         Test_XTSEncOutput25Bytes[Index] = 0x00;
    }

    retVal = Cry_HsmAesXtsEncryptStart(config, KEY_ENCRYPTION_XTS_KEY1,
             KEY_ENCRYPTION_XTS_KEY2, XTS_IV_2, sizeof(XTS_IV_2));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    InputLength = 16;
    outputLength = InputLength;
    retVal = Cry_HsmAesXtsEncryptUpdate(config, &XTS_PT_25Bytes[0], InputLength, &Test_XTSEncOutput25Bytes[0], &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(outputLength == InputLength)
    InputLength = 9;
    outputLength = InputLength;
    retVal = Cry_HsmAesXtsEncryptUpdate(config, &XTS_PT_25Bytes[16], InputLength, &Test_XTSEncOutput25Bytes[16], &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(outputLength == InputLength)
    retVal = Cry_HsmAesXtsEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
}
static void AesXtsDecrypt_MultiUpdates(const Cry_HsmAesXtsDecryptConfigType* config)
{
    uint32 outputLength;
    uint32 InputLength;
    Csm_ReturnType retVal;
    uint8 Index;
    for(Index=0; Index<25; Index++)
    {
         Test_XTSDecOutput25Bytes[Index] = 0x00;
    }

    retVal = Cry_HsmAesXtsDecryptStart(config, KEY_ENCRYPTION_XTS_KEY1,
            KEY_ENCRYPTION_XTS_KEY2, XTS_IV_2, sizeof(XTS_IV_2));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    InputLength = 16;
    outputLength = InputLength;
    retVal = Cry_HsmAesXtsDecryptUpdate(config, &XTS_CT_25Bytes[0], InputLength, &Test_XTSDecOutput25Bytes[0], &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(outputLength == InputLength)

    InputLength = 9;
    outputLength = InputLength;
    retVal = Cry_HsmAesXtsDecryptUpdate(config, &XTS_CT_25Bytes[16], InputLength, &Test_XTSDecOutput25Bytes[16], &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif
    TEST_VALIDATE(outputLength == InputLength)

    retVal = Cry_HsmAesXtsDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
#endif

}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/

static void TestHsm_aesXts_reference_Bytes(const Cry_HsmAesXtsEncryptConfigType* encConfig,const Cry_HsmAesXtsDecryptConfigType* decConfig)
{
    uint32 length = sizeof(XTS_PT_25Bytes);
   boolean result;

    /*  ENCRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\n\nXTS Encryption for non-multiple of 16 bytes: len = %d bytes", length);
    TEST_PRINTF("\n====================================================================\n");
    AesXtsEncrypt_Bytes(encConfig, XTS_PT_25Bytes, Test_XTSEncOutput25Bytes, length);
    TEST_PRINTF("XTS Encryption Plain text:\n");
    TEST_PRINT200(XTS_PT_25Bytes);
    TEST_PRINTF("\nInit Vector :\n");
    TEST_PRINT128(XTS_IV_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("XTS Key1 :\n");
    TEST_PRINT128(XTS_Key1_1);
    TEST_PRINTF("\n");
    TEST_PRINTF("XTS Key2 :\n");
    TEST_PRINT128(XTS_Key2_2);
    TEST_PRINTF("\n");
    result = Xts_CompareBytes((const uint8*)Test_XTSEncOutput25Bytes,(const uint8*)XTS_CT_25Bytes,length);
    TEST_VALIDATE(result != FALSE)
    TEST_PRINTF("XTS Received Cipher Text :\n");
    TEST_PRINT200(Test_XTSEncOutput25Bytes);

    TEST_PRINTF("\n\nXTS Decryption for non-multiple of 16 bytes: len = %d bytes", length);
    TEST_PRINTF("\n====================================================================\n");
    AesXtsDecrypt_Bytes(decConfig, XTS_CT_25Bytes, Test_XTSDecOutput25Bytes, length);
    TEST_PRINTF("XTS Decryption Cipher text:\n");
    TEST_PRINT200(XTS_CT_25Bytes);
    TEST_PRINTF("\nInit Vector :\n");
    TEST_PRINT128(XTS_IV_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("XTS Key1 :\n");
    TEST_PRINT128(XTS_Key1_1);
    TEST_PRINTF("\n");
    TEST_PRINTF("XTS Key2 :\n");
    TEST_PRINT128(XTS_Key2_2);
    TEST_PRINTF("\n");
    result = Xts_CompareBytes((const uint8*)Test_XTSDecOutput25Bytes,(const uint8*)XTS_PT_25Bytes,length);
    TEST_VALIDATE(result != FALSE)
    TEST_PRINTF("XTS Received Plain Text :\n");
    TEST_PRINT200(Test_XTSDecOutput25Bytes);

    /*  ENCRYPTION TEST WITH REFERENCE DATA */
     TEST_PRINTF("\n\nXTS Encryption for Multiple updates 1st update len = 16 bytes and 2nd update len = 9 bytes");
     TEST_PRINTF("\n============================================================================================\n");
     AesXtsEncrypt_MultiUpdates(encConfig);
     TEST_PRINTF("XTS Encryption Plain text:\n");
     TEST_PRINT200(XTS_PT_25Bytes);
     TEST_PRINTF("\nInit Vector :\n");
     TEST_PRINT128(XTS_IV_2);
     TEST_PRINTF("\n");
     TEST_PRINTF("XTS Key1 :\n");
     TEST_PRINT128(XTS_Key1_1);
     TEST_PRINTF("\n");
     TEST_PRINTF("XTS Key2 :\n");
     TEST_PRINT128(XTS_Key2_2);
     TEST_PRINTF("\n");
     result = Xts_CompareBytes((const uint8*)Test_XTSEncOutput25Bytes,(const uint8*)XTS_CT_25Bytes,length);
     TEST_VALIDATE(result != FALSE)
     TEST_PRINTF("XTS Received Cipher Text :\n");
     TEST_PRINT200(Test_XTSEncOutput25Bytes);

     TEST_PRINTF("\n\nXTS Decryption for Multiple updates 1st update len = 16 bytes and 2nd update len = 9 bytes");
     TEST_PRINTF("\n=============================================================================================\n");
     AesXtsDecrypt_MultiUpdates(decConfig);
     TEST_PRINTF("XTS Decryption Cipher text:\n");
     TEST_PRINT200(XTS_CT_25Bytes);
     TEST_PRINTF("\nInit Vector :\n");
     TEST_PRINT128(XTS_IV_2);
     TEST_PRINTF("\n");
     TEST_PRINTF("XTS Key1 :\n");
     TEST_PRINT128(XTS_Key1_1);
     TEST_PRINTF("\n");
     TEST_PRINTF("XTS Key2 :\n");
     TEST_PRINT128(XTS_Key2_2);
     TEST_PRINTF("\n");
     result = Xts_CompareBytes((const uint8*)Test_XTSDecOutput25Bytes,(const uint8*)XTS_PT_25Bytes,length);
     TEST_VALIDATE(result != FALSE)
     TEST_PRINTF("XTS Received Plain Text :\n");
     TEST_PRINT200(Test_XTSDecOutput25Bytes);


     /*  ENCRYPTION TEST WITH REFERENCE DATA */
     TEST_PRINTF("\n\nNegative Testcase: XTS Encryption for Length less than 16 bytes");
     TEST_PRINTF("\n==================================================================\n");
     AesXtsEncrypt_InvLen(encConfig, XTS_PT_25Bytes, Test_XTSEncOutput25Bytes, 15);
     TEST_PRINTF("XTS Decryption Cipher text:\n");
     TEST_PRINT200(XTS_PT_25Bytes);
     TEST_PRINTF("\nInit Vector :\n");
     TEST_PRINT128(XTS_IV_2);
     TEST_PRINTF("\n");
     TEST_PRINTF("XTS Key1 :\n");
     TEST_PRINT128(XTS_Key1_1);
     TEST_PRINTF("\n");
     TEST_PRINTF("XTS Key2 :\n");
     TEST_PRINT128(XTS_Key2_2);
     TEST_PRINTF("\n");
     TEST_PRINTF("Length :15");
     TEST_PRINTF("\n");
     TEST_PRINTF("XTS Received Plain Text :\n");
     TEST_PRINT200(Test_XTSEncOutput25Bytes);

     TEST_PRINTF("\n\nNegative Testcase: XTS Decryption for Length less than 16 bytes");
     TEST_PRINTF("\n==================================================================\n");
     /*  DECRYPTION TEST WITH REFERENCE DATA */
     AesXtsDecrypt_InvLen(decConfig, XTS_CT_25Bytes, Test_XTSDecOutput25Bytes, 15);
     TEST_PRINTF("XTS Decryption Cipher text:\n");
     TEST_PRINT200(XTS_CT_25Bytes);
     TEST_PRINTF("\nInit Vector :\n");
     TEST_PRINT128(XTS_IV_2);
     TEST_PRINTF("\n");
     TEST_PRINTF("XTS Key1 :\n");
     TEST_PRINT128(XTS_Key1_1);
     TEST_PRINTF("\n");
     TEST_PRINTF("XTS Key2 :\n");
     TEST_PRINT128(XTS_Key2_2);
     TEST_PRINTF("\n");
     TEST_PRINTF("Length :15");
     TEST_PRINTF("\n");
     TEST_PRINTF("XTS Received Plain Text :\n");
     TEST_PRINT200(Test_XTSDecOutput25Bytes);

}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/

#if ITF
void XtsParameter_Init()
{
    ITF_XTS_retVal  =CSM_E_ENTROPY_EXHAUSTION;
    ITF_XTS_retVal1 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_XTS_retVal2 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_XTS_retVal3 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_XTS_retVal4 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_XTS_retVal5 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_XTS_retVal6 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_XTS_retVal2_2 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_XTS_retVal2_3 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_XTS_retVal5_2 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_XTS_retVal5_3 =CSM_E_ENTROPY_EXHAUSTION;
    RetKeyLoadXTS = CSM_E_ENTROPY_EXHAUSTION;
    XtsErrorCheck =0;
    XTS_Index=0;
    DetErrorId = 99;
    DetApiId = 99;
    DetModuleId = 99;
    BswMErrorId =99;
    XTSEncCallBackUpdateResult1 = CSM_E_ENTROPY_EXHAUSTION;
    XTSEncCallBackFinishResult1 = CSM_E_ENTROPY_EXHAUSTION;
    XTSDecCallBackFinishResult1 = CSM_E_ENTROPY_EXHAUSTION;

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    g_TestHsm_xts.callbackSet = 0;
    XTSEncCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
    XTSEncCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
    XTSEncCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
    XTSEncFinishNotify =0;

    XTSDecCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
    XTSDecCallBackUpdateResult  = CSM_E_ENTROPY_EXHAUSTION;
    XTSDecCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
    XTSDecFinishNotify =0;
#endif
}
void ITF_Xts_Enc_Dec()
{
#if 1
  const Cry_HsmAesXtsEncryptConfigType* encConfig;
  const Cry_HsmAesXtsDecryptConfigType* decConfig;
  const Cry_HsmAesXtsEncryptConfigType* config1;
  const Cry_HsmAesXtsDecryptConfigType* decConfig1;
  Cry_HsmAesXtsEncryptConfigType Cry_kHsmAesXtsEncryptConfigDelay;
  Cry_HsmAesXtsDecryptConfigType Cry_kHsmAesXtsDeryptConfigDelay ;
  uint32 inputLength;
  uint32 outputLength ;
  uint32 Outputlenght16;
  uint32 Outputlenght32;
  uint32 inputlength32;
  uint8 XTS_Index;

  const Csm_SymKeyType TestKey_100 = {1, {100U}};

  Cry_kHsmAesXtsEncryptConfigDelay.TimeOut.TimeoutStart = 0U;
  Cry_kHsmAesXtsEncryptConfigDelay.TimeOut.TimeoutUpdateConst = 0U;
  Cry_kHsmAesXtsEncryptConfigDelay.TimeOut.TimeoutUpdateperByte = 0U;
  Cry_kHsmAesXtsEncryptConfigDelay.TimeOut.TimeoutFinish = 0U;


  Cry_kHsmAesXtsDeryptConfigDelay.TimeOut.TimeoutStart = 0U;
  Cry_kHsmAesXtsDeryptConfigDelay.TimeOut.TimeoutUpdateConst = 0U;
  Cry_kHsmAesXtsDeryptConfigDelay.TimeOut.TimeoutUpdateperByte = 0U;
  Cry_kHsmAesXtsDeryptConfigDelay.TimeOut.TimeoutFinish = 0U;

  decConfig1 = &Cry_kHsmAesXtsDeryptConfigDelay;
  encConfig  = &Cry_kHsmAesXtsEncryptConfig;
  decConfig  = &Cry_kHsmAesXtsDecryptConfig;
  config1    = &Cry_kHsmAesXtsEncryptConfigDelay;


   inputLength = sizeof(TEST_CONST_PLAIN);
   outputLength = inputLength;

   Outputlenght16 = 16;
   Outputlenght32 = 32;
   inputlength32 = 32;

   switch(ITF_XTS_TC)
       {
          #if 0
          /*CRY+ XTS Test case 01*/
           case XTS_ENCSTART_NULLCONFG:
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsEncryptStart(NULL_PTR, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
          #endif
           /*CRY+ XTS Test case 01*/
           case XTS_ENCSTART_NULLKEYPTR1:
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsEncryptStart(encConfig, NULL_PTR,KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ XTS Test case 02*/
           case XTS_ENCSTART_NULLKEYPTR2:
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, NULL_PTR, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ XTS Test case 03*/
           case XTS_ENCSTART_NULLINTVEC:
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, NULL_PTR, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 38*/
           case XTS_ENCSTART_CRYHSMUNINIT:
           {
               XtsParameter_Init();
               Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
               ITF_XTS_retVal = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPTION, KEY_ENCRYPT_RAM_KEY,TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_UNINIT ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 39*/
           case XTS_ENC_IPKEY_100_KEYPTR1 :
           {
               XtsParameter_Init();
               Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
               ITF_XTS_retVal = Cry_HsmAesXtsEncryptStart(encConfig, &TestKey_100, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 39*/
           case XTS_ENC_IPKEY_100_KEYPTR2 :
           {
               XtsParameter_Init();
               Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
               ITF_XTS_retVal = Cry_HsmAesXtsEncryptStart(encConfig,KEY_ENCRYPT_RAM_KEY, &TestKey_100,  TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 40*/
           case XTS_ENC_INVALIDLENGTH :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, 8);
               if((DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 41*/
           case XTS_ENCUPDATE_NULLCONFIG :
           {
               XtsParameter_Init();
               ITF_XTS_retVal =  Cry_HsmAesXtsEncryptUpdate(NULL_PTR, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN),(uint8 *) TEST_HSM_BUF_TEMP_A, &outputLength);
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;

           }
           /*CRY+ Test case 42*/
           case XTS_ENCUPDATE_NULLPLNTXTPTR:
           {
               XtsParameter_Init();
               ITF_XTS_retVal =  Cry_HsmAesXtsEncryptUpdate(encConfig, NULL_PTR, sizeof(TEST_CONST_PLAIN),(uint8 *) TEST_HSM_BUF_TEMP_A, &outputLength);
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 43*/
           case XTS_ENCUPDATE_NULLCIPHTXTPTR:
           {
              XtsParameter_Init();
              ITF_XTS_retVal =  Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN), NULL_PTR, &outputLength);
              if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
              {
                  XtsErrorCheck = 1;
              }
              else
              {
                  XtsErrorCheck = 0;
              }
              ITF_XTS_TC = CRY_XTS_IDLE;
              break;
           }
           /*CRY+ Test case 44*/
           case XTS_ENCUPDATE_INVALIDOPLENGTH :
           {
               XtsParameter_Init();
              ITF_XTS_retVal =  Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN),(uint8 *) TEST_HSM_BUF_TEMP_A, NULL_PTR);
              if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
              {
                  XtsErrorCheck = 1;
              }
              else
              {
                  XtsErrorCheck = 0;
              }
              ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 45*/
           case XTS_ENCUPDATE_SERVICENOTSTARTED:
           {
               XtsParameter_Init();
               Cry_PrimStatus[CRY_HSM_SYM_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED;
               ITF_XTS_retVal =  Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN),(uint8 *) TEST_HSM_BUF_TEMP_A, &outputLength);
               if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
                break;
           }
           /*CRY+ Test case 46*/
           case XTS_ENCUPDATE_SMALLBUFFER :
           {
               XtsParameter_Init();
               Cry_PrimStatus[CRY_HSM_SYM_XTS_ENCRYPT] = CRY_HSM_PRIM_STARTED;
               ITF_XTS_retVal =  Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN, 32, (uint8 *)TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               if((DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_UPDATE) && (DetModuleId == CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               Cry_PrimStatus[CRY_HSM_SYM_XTS_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED;
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 47*/
           case XTS_ENCFINISH_NULLCONFIG :
           {
              XtsParameter_Init();
              ITF_XTS_retVal =Cry_HsmAesXtsEncryptFinish(NULL_PTR, NULL_PTR, NULL_PTR);
              if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
              {
                  XtsErrorCheck = 1;
              }
              else
              {
                  XtsErrorCheck = 0;
              }
              ITF_XTS_TC = CRY_XTS_IDLE;
              break;
           }
           /*CRY+ Test case 48*/
           case XTS_ENCFINISH_SERVICENOTSTARTED:
           {
               XtsParameter_Init();
               Cry_PrimStatus[CRY_HSM_SYM_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED;
               ITF_XTS_retVal =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED ) && (DetApiId ==CRY_HSM_SID_AES_XTS_ENCRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 49*/
           case XTS_ENC_START_UPDATE_FINISH_VALIDIP :
           {
               XtsParameter_Init();
               RetKeyLoadXTS = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 = Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               ITF_XTS_retVal3 = Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

               ITF_XTS_retVal4 = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY,  KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal5 = Cry_HsmAesXtsDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_A, Outputlenght16, XTS_TEST_PLAINTXT_16_1, &inputLength);
               ITF_XTS_retVal6 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

               if( (HsmCom_CompareArray((const uint32*)XTS_TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4))!= FALSE )
               {
                   XtsErrorCheck =1;
               }
               else
               {
                   XtsErrorCheck =0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 50*/
           case XTS_ENC_DEC:
           {
               XtsParameter_Init();
               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY,  KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 =Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               ITF_XTS_retVal2_2 =Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_32, sizeof(TEST_CONST_PLAIN_32), (uint8 *)TEST_HSM_BUF_TEMP_B, &Outputlenght32);
               ITF_XTS_retVal2_3 =Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_3, sizeof(TEST_CONST_PLAIN_3),(uint8 *) XTS_TEST_CIPHTEXT_16, &Outputlenght16);
               ITF_XTS_retVal3 =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

               ITF_XTS_retVal4 = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal5 = Cry_HsmAesXtsDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_A, Outputlenght16, XTS_TEST_PLAINTXT_16_1, &inputLength);
               ITF_XTS_retVal5_2 = Cry_HsmAesXtsDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_B, Outputlenght32, XTS_TEST_PLAINTXT_32, &inputlength32);
               ITF_XTS_retVal5_3 = Cry_HsmAesXtsDecryptUpdate(decConfig,(uint8 *) XTS_TEST_CIPHTEXT_16, Outputlenght16, XTS_TEST_PLAINTXT_16_2, &inputLength);
               ITF_XTS_retVal6 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

               if((HsmCom_CompareArray((const uint32*)XTS_TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4)!= FALSE) &&
                  (HsmCom_CompareArray((const uint32*)XTS_TEST_PLAINTXT_32, (const uint32*)TEST_CONST_PLAIN_32, 8)!= FALSE) &&
                  (HsmCom_CompareArray((const uint32*)XTS_TEST_PLAINTXT_16_2, (const uint32*)TEST_CONST_PLAIN_3, 4)!= FALSE))
                   {
                       XtsErrorCheck =1;
                   }
               else
               {
                   XtsErrorCheck =0;
               }
               if((ITF_XTS_retVal1 == CSM_E_OK) && (ITF_XTS_retVal2 == CSM_E_OK) && (ITF_XTS_retVal2_2 == CSM_E_OK) && (ITF_XTS_retVal2_3 == CSM_E_OK) &&
                  (ITF_XTS_retVal3 == CSM_E_OK) && (ITF_XTS_retVal4 == CSM_E_OK) && (ITF_XTS_retVal5 == CSM_E_OK) &&
                  (ITF_XTS_retVal5_2 == CSM_E_OK) && (ITF_XTS_retVal5_3 == CSM_E_OK) && (ITF_XTS_retVal6 == CSM_E_OK) && (XtsErrorCheck ==1))
               {
                   XtsErrorCheck =1;
               }
               else
               {
                   XtsErrorCheck =0;
               }

               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 51*/
           case XTS_START_UPDATE_TILLDELAY :
           {
               XtsParameter_Init();
               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 =Cry_HsmAesXtsEncryptUpdate(config1, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_retVal3 =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           case XTS_FINISH_AFTERDELAY :
           {
               XtsParameter_Init();
               ITF_XTS_retVal3 =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 52*/
           case XTS_START_FINISH :
           {
               XtsParameter_Init();
               RetKeyLoadXTS = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

               if((ITF_XTS_retVal1 == CSM_E_OK) && (ITF_XTS_retVal2 == CSM_E_NOT_OK))
               {
                   ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
                   ITF_XTS_retVal2 =Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
                   ITF_XTS_retVal3 =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
                   if((ITF_XTS_retVal1 == CSM_E_OK) && (ITF_XTS_retVal2 == CSM_E_OK) && (ITF_XTS_retVal3 == CSM_E_OK))
                   {
                       XtsErrorCheck = 1;
                   }
                   else
                   {
                       XtsErrorCheck = 0;
                   }
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
   #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
           /*CRY+ Test case 53*/
           case XTS_START_UPDATE_FINISH_ASYNC :
           {
               XtsParameter_Init();
               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal2 =Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal3 =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_retVal4 = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal5 = Cry_HsmAesXtsDecryptUpdate(decConfig,(uint8 *)TEST_HSM_BUF_TEMP_A, Outputlenght16, XTS_TEST_PLAINTXT_16_1, &inputLength);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal6 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);

               if( (HsmCom_CompareArray((const uint32*)XTS_TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4)) != FALSE)
               {
                   XtsErrorCheck =1;
               }
               else
               {
                   XtsErrorCheck =0;
               }

               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 55*/
           case XTS_START_UPDATE_FINISH_ASYNCTILLDELAY :
           {
               XtsParameter_Init();
               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_retVal2 =Cry_HsmAesXtsEncryptUpdate(config1, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
               if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_retVal3 =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           case XTS_FINISH_ASYNCAFTERDELAY :
           {
               XtsParameter_Init();
               ITF_XTS_retVal3 =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
   #endif
           /*CRY+ Test case 56*/
           case XTS_DEC_START_NULLCONFIG :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(NULL_PTR, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) &&( DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_START )&&( DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 57*/
           case XTS_DEC_START_NULLKEYPTR1 :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, NULL_PTR, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_START) && (DetModuleId == CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 57*/
           case XTS_DEC_START_NULLKEYPTR2 :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, NULL_PTR, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_START) && (DetModuleId == CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 58*/
           case XTS_DEC_START_NULL_INIT_VEC :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, NULL_PTR, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  &&( DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 59*/
           case XTS_DEC_START_CRY_HSM_UNIINIT :
           {
               XtsParameter_Init();
               Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_UNINIT)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 60*/
           case XTS_DEC_START_IPKEY100_KEYPRT1 :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, &TestKey_100, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           case XTS_DEC_START_IPKEY100_KEYPRT2 :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, &TestKey_100, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               if((DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 61*/
           case XTS_DEC_START_IV8 :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, 8);
               if((DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 62*/
           case XTS_DEC_UPDATE_NULLCFG :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptUpdate(NULL_PTR, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 63*/
           case XTS_DEC_UPDATE_NULLCIPHTXT :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptUpdate(decConfig, NULL_PTR, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 64*/
           case XTS_DEC_UPDATE_NULLPLNTXT :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, inputLength, NULL_PTR,&outputLength);
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 65*/
           case XTS_DEC_UPDATE_NULLPLNTXTLENGTH :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,NULL_PTR);
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 66*/
           case XTS_DEC_UPDATE_CRY_HSM_NOTINIT :
           {
               XtsParameter_Init();
               Cry_PrimStatus [CRY_HSM_SYM_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED;
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
               if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }

           /*CRY+ Test case 67*/
           case XTS_DEC_UPDATE_DIFFLENGTH :
           {
               Cry_PrimStatus [CRY_HSM_SYM_XTS_DECRYPT] = CRY_HSM_PRIM_STARTED;
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, 32, (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
               if((DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               Cry_PrimStatus [CRY_HSM_SYM_XTS_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED;
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 68*/
           case XTS_DEC_FINISH_NULLCFGPTR :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptFinish(NULL_PTR, NULL_PTR, NULL_PTR);
               if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 69*/
           case XTS_DEC_FINISH_SERVICENOTSTARTED :
           {
               XtsParameter_Init();
               Cry_PrimStatus [CRY_HSM_SYM_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED ;
               ITF_XTS_retVal =  Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
               if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId ==CRY_HSM_SID_AES_XTS_DECRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
               {
                   XtsErrorCheck = 1;
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ Test case 70*/
           case XTS_DEC_START_UPDATE_FINISH :
           {
               XtsParameter_Init();
               RetKeyLoadXTS = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 = Cry_HsmAesXtsDecryptUpdate(decConfig, TEST_CONST_PLAIN_1,  sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
               ITF_XTS_retVal3 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

               ITF_XTS_retVal4 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal5 = Cry_HsmAesXtsEncryptUpdate(encConfig, (uint8 *)TEST_HSM_BUF_TEMP_A, Outputlenght16,XTS_TEST_PLAINTXT_16_1, &inputLength);
               ITF_XTS_retVal6 = Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

               if( (HsmCom_CompareArray((const uint32*)XTS_TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4))!= FALSE )
               {
                   XtsErrorCheck =1;
               }
               else
               {
                   XtsErrorCheck =0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ test case 71*/
           case XTS_DEC_ENC :
           {
               XtsParameter_Init();

               ITF_XTS_retVal1 = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 = Cry_HsmAesXtsDecryptUpdate(decConfig,TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               ITF_XTS_retVal2_2 = Cry_HsmAesXtsDecryptUpdate(decConfig,TEST_CONST_PLAIN_32, sizeof(TEST_CONST_PLAIN_32), XTS_TEST_PLAINTXT_32, &Outputlenght32);
               ITF_XTS_retVal2_3 = Cry_HsmAesXtsDecryptUpdate(decConfig,TEST_CONST_PLAIN_3, sizeof(TEST_CONST_PLAIN_3), XTS_TEST_PLAINTXT_16_2, &Outputlenght16);
               ITF_XTS_retVal3 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

               ITF_XTS_retVal4 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal5 =Cry_HsmAesXtsEncryptUpdate(encConfig, (uint8 *) TEST_HSM_BUF_TEMP_A, Outputlenght16,XTS_TEST_PLAINTXT_16_1, &inputLength);
               ITF_XTS_retVal5_2 =Cry_HsmAesXtsEncryptUpdate(encConfig, XTS_TEST_PLAINTXT_32, sizeof(TEST_CONST_PLAIN_32), (uint8 *)TEST_HSM_BUF_TEMP_B, &inputlength32);
               ITF_XTS_retVal5_3 =Cry_HsmAesXtsEncryptUpdate(encConfig, XTS_TEST_PLAINTXT_16_2, sizeof(TEST_CONST_PLAIN_3),(uint8 *) XTS_TEST_CIPHTEXT_16, &inputLength);
               ITF_XTS_retVal6 =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

               if((HsmCom_CompareArray((const uint32*)XTS_TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4)!= FALSE) &&
                  (HsmCom_CompareArray(TEST_HSM_BUF_TEMP_B, (const uint32*)TEST_CONST_PLAIN_32, 8)!= FALSE) &&
                  (HsmCom_CompareArray(XTS_TEST_CIPHTEXT_16, (const uint32*)TEST_CONST_PLAIN_3, 4)!= FALSE))
                   {
                       XtsErrorCheck =1;
                   }
               else
               {
                   XtsErrorCheck =0;
               }
               if((ITF_XTS_retVal1 == CSM_E_OK) && (ITF_XTS_retVal2 == CSM_E_OK) && (ITF_XTS_retVal2_2 == CSM_E_OK) && (ITF_XTS_retVal2_3 == CSM_E_OK) &&
                  (ITF_XTS_retVal3 == CSM_E_OK) && (ITF_XTS_retVal4 == CSM_E_OK) && (ITF_XTS_retVal5 == CSM_E_OK) &&
                  (ITF_XTS_retVal5_2 == CSM_E_OK) && (ITF_XTS_retVal5_3 == CSM_E_OK) && (ITF_XTS_retVal6 == CSM_E_OK) && (XtsErrorCheck ==1))
               {
                   XtsErrorCheck =1;
               }
               else
               {
                   XtsErrorCheck =0;
               }

               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ test case 72*/
           case XTS_DEC_LESSTIMEOUT_TILLDELAY :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 = Cry_HsmAesXtsDecryptUpdate(decConfig1, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
               if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
               {
                   XtsErrorCheck =1;
               }
               else
               {
                   XtsErrorCheck =0;
               }
               ITF_XTS_retVal3 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }

           case XTS_DEC_LESSTIMEOUT_AFTERDELAY :
           {
               XtsParameter_Init();
               ITF_XTS_retVal3 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ test case 73*/
           case XTS_DEC_START_FINISH :
           {
               XtsParameter_Init();
               RetKeyLoadXTS = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

               if((ITF_XTS_retVal == CSM_E_OK) && (ITF_XTS_retVal2 == CSM_E_NOT_OK))
               {
                   ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
                   ITF_XTS_retVal2 = Cry_HsmAesXtsDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
                   ITF_XTS_retVal3 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
                   if((ITF_XTS_retVal == CSM_E_OK) && (ITF_XTS_retVal2 == CSM_E_OK) && (ITF_XTS_retVal3 == CSM_E_OK))
                   {
                       XtsErrorCheck = 1;
                   }
                   else
                   {
                       XtsErrorCheck = 0;
                   }
               }
               else
               {
                   XtsErrorCheck = 0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY_SC_TC_10*/
           case CRY_XTS_UPDATE_CANCEL :
           {
               XtsParameter_Init();
               CancelRequired = 1;
               for(XTS_Index=0;XTS_Index<4;XTS_Index++)
               {
                   TEST_HSM_BUF_TEMP_A[XTS_Index]=0x00000000;
               }
               RetKeyLoadXTS = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));

               Gpt_EnableNotification(Gptch_CancelCommand);
               Gpt_StartTimer(Gptch_CancelCommand, 200);

               ITF_XTS_retVal2 =Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);

               Gpt_StopTimer(Gptch_CancelCommand);

               ITF_XTS_retVal3 =Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

               for(XTS_Index=0;XTS_Index<4;XTS_Index++)
               {
                   if(TEST_HSM_BUF_TEMP_A[XTS_Index]!= 0x00000000)
                   {
                       XtsErrorCheck = 0;
                       break;
                   }
                   else
                   {
                       XtsErrorCheck = 1;
                   }
               }
               if((ITF_XTS_retVal1 == CSM_E_OK) && (ITF_XTS_retVal2 == CSM_E_NOT_OK) && (ITF_XTS_retVal3 == CSM_E_NOT_OK)
                       && (XtsErrorCheck == 1))
               {
                   XtsErrorCheck = 1;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY_SC_TC_11*/
           case CRY_XTS_FINISH_CANCEL_SESSIONCLOSEVER :
           {
               XtsParameter_Init();
               CancelRequired = 1;
               RetKeyLoadXTS = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);

               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 = Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);

               Gpt_EnableNotification(Gptch_CancelCommand);
               Gpt_StartTimer(Gptch_CancelCommand, 200);

               ITF_XTS_retVal3 = Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

               Gpt_StopTimer(Gptch_CancelCommand);

               ITF_XTS_retVal4 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal5 = Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               ITF_XTS_retVal6 = Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

               if((ITF_XTS_retVal1 == CSM_E_OK) && (ITF_XTS_retVal2 == CSM_E_OK) && (ITF_XTS_retVal3 == CSM_E_NOT_OK)
                       &&(ITF_XTS_retVal4 == CSM_E_OK) && (ITF_XTS_retVal5 == CSM_E_OK) && (ITF_XTS_retVal6 == CSM_E_OK))

               {
                   XtsErrorCheck = 1;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
           }
           break;
           /*CRY_SC_TC_12*/
           case CRY_XTS_DEC_FINISH_CANCEL_SESSIONCLOSVER :
           {
               XtsParameter_Init();
               CancelRequired = 1;

               ITF_XTS_retVal1 = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 = Cry_HsmAesXtsDecryptUpdate(decConfig,TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);

               Gpt_EnableNotification(Gptch_CancelCommand);
               Gpt_StartTimer(Gptch_CancelCommand, 200);

               ITF_XTS_retVal3 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

               Gpt_StopTimer(Gptch_CancelCommand);

               ITF_XTS_retVal4 = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal5 = Cry_HsmAesXtsDecryptUpdate(decConfig,TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               ITF_XTS_retVal6 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

               if((ITF_XTS_retVal1 == CSM_E_OK) && (ITF_XTS_retVal2 == CSM_E_OK) && (ITF_XTS_retVal3 == CSM_E_NOT_OK) &&
                       (ITF_XTS_retVal4 == CSM_E_OK) && (ITF_XTS_retVal5 == CSM_E_OK) && (ITF_XTS_retVal6 == CSM_E_OK))
               {
                   XtsErrorCheck = 1;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
   #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
           /*CRY+ test case 74*/
           case XTS_DEC_START_UPDATE_FINISH_ASYNC :
           {
               XtsParameter_Init();
               RetKeyLoadXTS = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal2 = Cry_HsmAesXtsDecryptUpdate(decConfig, TEST_CONST_PLAIN_1,  sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal3 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_retVal4 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal5 = Cry_HsmAesXtsEncryptUpdate(encConfig, (uint8 *)TEST_HSM_BUF_TEMP_A, Outputlenght16,XTS_TEST_PLAINTXT_16_1, &inputLength);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal6 = Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               if( (HsmCom_CompareArray((const uint32*)XTS_TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4))!= FALSE )
               {
                   XtsErrorCheck =1;
               }
               else
               {
                   XtsErrorCheck =0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY+ test case 75*/
           /*CRY+ test case 76*/
           case XTS_DEC_LESSTIMEOUT_ASYNCTILLDELAY :
           {
               XtsParameter_Init();
               ITF_XTS_retVal = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal2 = Cry_HsmAesXtsDecryptUpdate(decConfig1, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
               {
                   XtsErrorCheck =1;
               }
               else
               {
                   XtsErrorCheck =0;
               }
               ITF_XTS_retVal3 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_TC = CRY_XTS_IDLE;
               break;

           }
           case XTS_DEC_LESSTIMEOUT_ASYNCAFTERDELAY :
           {
               XtsParameter_Init();
               ITF_XTS_retVal3 =  Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY_SC_TC_13*/
           case CRY_XTS_UPDATE_CANCEL_ASYNC :
           {
               XtsParameter_Init();
               RetKeyLoadXTS = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal2 = Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               Cry_HsmSheCancel();
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal3 = Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               if((XTSEncCallBackStartResult == CSM_E_OK) && (XTSEncCallBackUpdateResult == CSM_E_NOT_OK) && (XTSEncCallBackFinishResult == CSM_E_NOT_OK))
               {
                   XtsErrorCheck = 1;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY_SC_TC_14*/
           case CRY_XTS_FINISH_CANCEL_SESSIONCLOSEVER_ASYNC :
           {
               XtsParameter_Init();
               RetKeyLoadXTS = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);

               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_retVal2 = Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_retVal3 = Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               Cry_HsmSheCancel();
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);


               if((XTSEncCallBackStartResult != CSM_E_OK) || (XTSEncCallBackUpdateResult != CSM_E_OK) || (XTSEncCallBackFinishResult != CSM_E_NOT_OK))
                {
                    XtsErrorCheck = 1;
                }

               ITF_XTS_retVal4 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_retVal5 = Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_retVal6 = Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               if((XTSEncCallBackStartResult != CSM_E_OK) || (XTSEncCallBackUpdateResult != CSM_E_OK) || (XTSEncCallBackFinishResult != CSM_E_OK))
                {
                    XtsErrorCheck = 1;
                }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           /*CRY_SC_TC_15*/
           case CRY_XTS_DEC_FINISH_CANCEL_SESSIONCLOSEVER_ASYNC :
           {
               XtsParameter_Init();
               ITF_XTS_retVal1 = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_retVal2 = Cry_HsmAesXtsDecryptUpdate(decConfig, TEST_CONST_PLAIN_1,  sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_retVal3 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

               Cry_HsmSheCancel();

               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);

               if((XTSDecCallBackStartResult != CSM_E_OK) || (XTSDecCallBackUpdateResult != CSM_E_OK) ||
                       (XTSDecCallBackFinishResult != CSM_E_NOT_OK))
               {
                   XtsErrorCheck = 1;
               }

               ITF_XTS_retVal1 = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal2 = Cry_HsmAesXtsDecryptUpdate(decConfig, TEST_CONST_PLAIN_1,  sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal3 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);

               if((XTSDecCallBackStartResult != CSM_E_OK) || (XTSDecCallBackUpdateResult != CSM_E_OK) ||
                       (XTSDecCallBackFinishResult != CSM_E_OK))
               {
                   XtsErrorCheck = 1;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           case CRY_XTS_ENC_DEC_NONMUL16_ASYNC :
           {

               XtsParameter_Init();
               uint32 inputLength =  sizeof(XTS_PT_25Bytes);
               uint32 outputLength = sizeof(Test_XTSEncOutput25Bytes);
               uint8 Index;
               for(Index=0; Index<25; Index++)
               {
                 Test_XTSEncOutput25Bytes[Index] = 0x00;
               }
               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               ITF_XTS_retVal2 = Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_32, inputLength, (uint8 *)Test_XTSEncOutput25Bytes, &outputLength);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal3 = Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsEncryptMainFunction, &g_TestHsm_xts.callbackSet);

               for(Index=0; Index<25; Index++)
               {
                    Test_XTSDecOutput25Bytes[Index] = 0x00;
               }

               ITF_XTS_retVal4 = Cry_HsmAesXtsDecryptStart(decConfig, KEY_XTS_ENCRYPT_RAM_KEY,KEY_XTS_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal5 = Cry_HsmAesXtsDecryptUpdate(decConfig, (uint8 *)Test_XTSEncOutput25Bytes, inputLength, Test_XTSDecOutput25Bytes, &outputLength);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);
               ITF_XTS_retVal6 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
               TEST_WAIT(&Cry_HsmAesXtsDecryptMainFunction, &g_TestHsm_xts.callbackSet);

               if( (Xts_CompareBytes((const uint8*)Test_XTSDecOutput25Bytes, (const uint8*)TEST_CONST_PLAIN_32, 25)) != FALSE)
               {
                   XtsErrorCheck =1;
               }
               else
               {
                   XtsErrorCheck =0;
               }
               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
   #endif
           case CRY_XTS_ENC_DEC_NONMUL16 :
           {

               XtsParameter_Init();
               uint32 inputLength =  sizeof(XTS_PT_25Bytes);
               uint32 outputLength = sizeof(Test_XTSEncOutput25Bytes);;
               uint8 Index;
               for(Index=0; Index<25; Index++)
               {
                 Test_XTSEncOutput25Bytes[Index] = 0x00;
               }
               ITF_XTS_retVal1 = Cry_HsmAesXtsEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal2 = Cry_HsmAesXtsEncryptUpdate(encConfig, TEST_CONST_PLAIN_32, inputLength, (uint8 *)Test_XTSEncOutput25Bytes, &outputLength);
               ITF_XTS_retVal3 = Cry_HsmAesXtsEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

               for(Index=0; Index<25; Index++)
               {
                    Test_XTSDecOutput25Bytes[Index] = 0x00;
               }
               ITF_XTS_retVal4 = Cry_HsmAesXtsDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY,KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
               ITF_XTS_retVal5 = Cry_HsmAesXtsDecryptUpdate(decConfig, (uint8 *)Test_XTSEncOutput25Bytes, inputLength, Test_XTSDecOutput25Bytes, &outputLength);
               ITF_XTS_retVal6 = Cry_HsmAesXtsDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

               if( (Xts_CompareBytes((const uint8*)Test_XTSDecOutput25Bytes, (const uint8*)TEST_CONST_PLAIN_32, 25)) != FALSE)
               {
                   XtsErrorCheck =1;
               }
               else
               {
                   XtsErrorCheck =0;
               }

               ITF_XTS_TC = CRY_XTS_IDLE;
               break;
           }
           default :
           {
               break;
           }
       }
#endif
}
#endif
/*************************************************************************************//**
 * Execution of XTS test suite
*//**************************************************************************************/

void TestHsm_aes_xts_Bytes(void)
{
    TestHsm_aesXts_reference_Bytes(&Cry_kHsmAesXtsEncryptConfig, &Cry_kHsmAesXtsDecryptConfig);
}
void TestHsm_aes_xts(void)
{
    boolean cmpResult;

    ProtectedKey *load = (void*) TEST_HSM_BUF_TEMP_A;
    TestKeyEncryptData *ciph = (void*) TEST_HSM_BUF_TEMP_B;

    TEST_PRINTF("\nTest Xts Encryption with Flash Key  ---------------------------------- \n");

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
    TEST_PRINTF(" - Encrypt data with key \n");
    {
        XtsEncryptWithRamKey( TEST_CONST_PLAIN, ciph->ciph1, sizeof (TEST_CONST_PLAIN));

        /* check that the RAM contains encrypted Data */
        TEST_VALIDATE(ciph->ciph1[0].Data[0] != 0xA5A5A5A5UL)
        TEST_VALIDATE(ciph->ciph1[NUM_BLOCKS-1].Data[0] != 0xA5A5A5A5UL)
    }
    TEST_PRINTF(" - Encrypt data #2 with key #1\n");
    {
        XtsEncryptWithRamKey( TEST_CONST_PLAIN, ciph->ciph2, sizeof (TEST_CONST_PLAIN));

        /* check that the RAM contains encrypted data */
        TEST_VALIDATE(ciph->ciph2[0].Data[0] != 0x12345678UL)
        TEST_VALIDATE(ciph->ciph2[NUM_BLOCKS-1].Data[0] != 0x12345678UL)
    }
    TEST_PRINTF(" - Compare encrypted data\n");
    {
        cmpResult = HsmCom_CompareArray((uint32*) ciph->ciph1, (uint32*) ciph->ciph2, NUM_UINT32);
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" \n");
    TEST_PRINTF("Key1 used :\n");
    TEST_PRINT128(XTS_Key1_1);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key2 used :\n");
    TEST_PRINT128(XTS_Key2_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("Init Vector :\n");
    TEST_PRINT128(XTS_IV_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("Plain Text :\n");
    TEST_PRINT128(&TEST_CONST_PLAIN);
    TEST_PRINTF("\n");
    TEST_PRINT128((TEST_CONST_PLAIN + 16));
    TEST_PRINTF("\n");
    TEST_PRINT128((TEST_CONST_PLAIN + 32));
    TEST_PRINTF("\n");
    TEST_PRINT128((TEST_CONST_PLAIN + 48));
    TEST_PRINTF("\n");
    TEST_PRINTF("Cipher Text :\n");
    TEST_PRINT128(&ciph->ciph1[0].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[1].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[2].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[3].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINTF(" - Decrypt data \n");
    {
        XtsDecryptWithRamKey( ciph->ciph1, ciph->ciph2, sizeof (ciph->ciph1));

        cmpResult = HsmCom_CompareArray((const uint32*) TEST_CONST_PLAIN, (uint32*) ciph->ciph2, NUM_UINT32);
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" \n");
    TEST_PRINTF("Key1 used :\n");
    TEST_PRINT128(XTS_Key1_1);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key2 used :\n");
    TEST_PRINT128(XTS_Key2_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("Init Vector :\n");
    TEST_PRINT128(XTS_IV_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("Cipher Text :\n");
    TEST_PRINT128(&ciph->ciph1[0].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[1].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[2].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[3].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINTF("Plain Text :\n");
    TEST_PRINT128(&ciph->ciph2[0].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph2[1].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph2[2].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph2[3].Data[0]);
    TEST_PRINTF("\n");

/********************XTS Encryption/Decryption with Multiple updates********************************/
    TEST_PRINTF("\n XTS encryption and decryption with multiple updates \n");
    TEST_PRINTF(" - Encrypt data with key \n");
    {
        XtsEncryptWithRamKeyMultipleUpdate(ciph->ciph1);
    }
    TEST_PRINTF(" - Encrypt data #2 with key #1\n");
    {
        XtsEncryptWithRamKeyMultipleUpdate(ciph->ciph2);

    }
    TEST_PRINTF(" - Compare encrypted data\n");
    {
        cmpResult = HsmCom_CompareArray((uint32*) ciph->ciph1, (uint32*) ciph->ciph2, NUM_UINT32);
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" \n");
    TEST_PRINTF("Key1 used :\n");
    TEST_PRINT128(XTS_Key1_1);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key2 used :\n");
    TEST_PRINT128(XTS_Key2_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("Init Vector :\n");
    TEST_PRINT128(XTS_IV_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("Plain Text :\n");
    TEST_PRINT128(&TEST_CONST_PLAIN);
    TEST_PRINTF("\n");
    TEST_PRINT128((TEST_CONST_PLAIN + 16));
    TEST_PRINTF("\n");
    TEST_PRINT128((TEST_CONST_PLAIN + 32));
    TEST_PRINTF("\n");
    TEST_PRINT128((TEST_CONST_PLAIN + 48));
    TEST_PRINTF("\n");
    TEST_PRINTF("Cipher Text :\n");
    TEST_PRINT128(&ciph->ciph1[0].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[1].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[2].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[3].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINTF(" - Decrypt data \n");
    {
        XtsDecryptWithRamKeyMultipleUpdate( ciph->ciph1, ciph->ciph2);

        cmpResult = HsmCom_CompareArray((const uint32*) TEST_CONST_PLAIN, (uint32*) ciph->ciph2, NUM_UINT32);
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" \n");
    TEST_PRINTF("Key1 used :\n");
    TEST_PRINT128(XTS_Key1_1);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key2 used :\n");
    TEST_PRINT128(XTS_Key2_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("Init Vector :\n");
    TEST_PRINT128(XTS_IV_2);
    TEST_PRINTF("\n");
    TEST_PRINTF("Cipher Text :\n");
    TEST_PRINT128(&ciph->ciph1[0].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[1].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[2].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph1[3].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINTF("Plain Text :\n");
    TEST_PRINT128(&ciph->ciph2[0].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph2[1].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph2[2].Data[0]);
    TEST_PRINTF("\n");
    TEST_PRINT128(&ciph->ciph2[3].Data[0]);
    TEST_PRINTF("\n");
/**************************End of Multiple update test**********************************/
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif

