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
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"
TestHsm_cbc g_TestHsm_cbc = {0};
#if ITF
typedef enum{
CRY_CBC_IDLE=0,
CBC_ENCSTART_NULLCONFG,
CBC_ENCSTART_NULLKEYPTR,
CBC_ENCSTART_NULLINTVEC,
CBC_ENCSTART_CRYHSMUNINIT,
CBC_ENC_IPKEY_100,
CBC_ENC_INVALIDLENGTH,
CBC_ENCUPDATE_NULLCONFIG,
CBC_ENCUPDATE_NULLPLNTXTPTR,
CBC_ENCUPDATE_NULLCIPHTXTPTR,
CBC_ENCUPDATE_INVALIDOPLENGTH,
CBC_ENCUPDATE_SERVICENOTSTARTED,
CBC_ENCUPDATE_SMALLBUFFER,
CBC_ENCUPD_LENGTH_NONMUL16,
CBC_ENCFINISH_NULLCONFIG,
CBC_ENCFINISH_SERVICENOTSTARTED,
CBC_ENC_START_UPDATE_FINISH_VALIDIP,
CBC_ENC_DEC,
CBC_START_UPDATE_TILLDELAY,
CBC_FINISH_AFTERDELAY,
CBC_START_FINISH,
CBC_DEC_START_NULLCONFIG,
CBC_DEC_START_NULLKEYPTR,
CBC_DEC_START_NULL_INIT_VEC,
CBC_DEC_START_CRY_HSM_UNIINIT,
CBC_DEC_START_IPKEY100,
CBC_DEC_START_IV8,
CBC_DEC_UPDATE_NULLCFG,
CBC_DEC_UPDATE_NULLCIPHTXT,
CBC_DEC_UPDATE_NULLPLNTXT,
CBC_DEC_UPDATE_NULLPLNTXTLENGTH,
CBC_DEC_UPDATE_CRY_HSM_NOTINIT,
CBC_DEC_UPDATE_DIFFLENGTH,
CBC_DECUPD_LENGTH_NONMUL16,
CBC_DEC_FINISH_NULLCFGPTR,
CBC_DEC_FINISH_SERVICENOTSTARTED,
CBC_DEC_START_UPDATE_FINISH,
CBC_DEC_ENC,
CBC_DEC_LESSTIMEOUT_TILLDELAY,
CBC_DEC_LESSTIMEOUT_AFTERDELAY,
CBC_DEC_START_FINISH,
CRY_CBC_UPDATE_CANCEL,
CRY_CBC_FINISH_CANCEL_SESSIONCLOSEVER,
CRY_CBC_DEC_FINISH_CANCEL_SESSIONCLOSVER,
CRY_CBC_UPDATE_KEY_EMPTY,
CRY_CBC_MULTIPLE_UPD_KEY_EMPTY,
CRY_CBC_MULTIPLE_UPDATE_CANCEL_KEY_EMPTY,
CRY_CBC_UPD_KEYEMPTY_FIN_TIMEOUT,
CRY_CBC_UPDATEKEYEMPTY_FIN_CANCEL,
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
CBC_DEC_ENC_MUL_ASYNC,
CBC_START_UPDATE_FINISH_ASYNC,
CBC_START_UPDATE_FINISH_ASYNCTILLDELAY,
CBC_FINISH_ASYNCAFTERDELAY,
CBC_DEC_START_UPDATE_FINISH_ASYNC,
CBC_DEC_LESSTIMEOUT_ASYNCTILLDELAY,
CBC_DEC_LESSTIMEOUT_ASYNCAFTERDELAY,
CRY_CBC_UPDATE_CANCEL_ASYNC,
CRY_CBC_FINISH_CANCEL_SESSIONCLOSEVER_ASYNC,
CRY_CBC_DEC_FINISH_CANCEL_SESSIONCLOSEVER_ASYNC,
CRY_CBC_UPDATE_KEY_EMPTY_ASYNC,
CRY_CBC_UPD_KEYEMPTY_FIN_TIMEOUT_ASYNC,
CRY_CBC_UPDATEKEYEMPTY_FIN_CANCEL_ASYNC
#endif
}CBC_TC;

CBC_TC ITF_CBC_TC= CRY_CBC_IDLE;
Csm_ReturnType ITF_CBC_retVal ;
Csm_ReturnType ITF_CBC_retVal1;
Csm_ReturnType ITF_CBC_retVal2;
Csm_ReturnType ITF_CBC_retVal2_2;
Csm_ReturnType ITF_CBC_retVal2_3;
Csm_ReturnType ITF_CBC_retVal3;

Csm_ReturnType ITF_CBC_retVal4;
Csm_ReturnType ITF_CBC_retVal5;
Csm_ReturnType ITF_CBC_retVal5_2;
Csm_ReturnType ITF_CBC_retVal5_3;
Csm_ReturnType ITF_CBC_retVal6;

Csm_ReturnType CBCEncCallBackStartResult;
Csm_ReturnType CBCEncCallBackUpdateResult;
Csm_ReturnType CBCEncCallBackUpdateResult1;
Csm_ReturnType CBCEncCallBackFinishResult;
Csm_ReturnType CBCEncCallBackFinishResult1;
uint8 CBCEncFinishNotify;

Csm_ReturnType CBCDecCallBackStartResult;
Csm_ReturnType CBCDecCallBackUpdateResult;
Csm_ReturnType CBCDecCallBackFinishResult;
Csm_ReturnType CBCDecCallBackFinishResult1;
uint8 CBCDecFinishNotify;

uint8 CbcErrorCheck;
uint8 k;

uint8 BswMErrorId_Upd1;
uint8 BswMErrorId_Upd2;
uint8 BswMErrorId_Fin ;

uint8 TEST_PLAINTXT_16_1[16];
uint8 TEST_PLAINTXT_32[32];
uint8 TEST_PLAINTXT_16_2[16];
uint32 TEST_CIPHTEXT_16[16];

Csm_ReturnType RetKeyLoadCBC ;
#endif
#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
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

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymEncryptCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
    {
        g_TestHsm_cbc.callbackSet = 1;
    }
    else
    {
#if ITF
        g_TestHsm_cbc.callbackSet = 2;
#else
        g_TestHsm_cbc.callbackSet = 2;
        TEST_PRINTF("ECB function failed in mainloop with ret value %d \n ", result);
#endif
    }

#if ITF
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF

    switch(Cry_PrimStatusAsync[CRY_HSM_SYM_ENCRYPT])
    {
      case ASYNC_STATE_START:
      {
         CBCEncCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
          CBCEncCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
          CBCEncCallBackFinishResult = result;
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
             CBCDecCallBackStartResult = result;
             break;
          }
          case ASYNC_STATE_UPDATE:
          {
              CBCDecCallBackUpdateResult = result;
             break;
          }
          case ASYNC_STATE_FINISH:
          {
              CBCDecCallBackFinishResult = result;
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
void Csm_SymEncryptServiceFinishNotification(void)
{
#if ITF
    CBCEncFinishNotify = 1;
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymDecryptCallbackNotification(Csm_ReturnType result)
{
    Csm_SymEncryptCallbackNotification(result);
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymDecryptServiceFinishNotification(void)
{
#if ITF
    CBCDecFinishNotify = 1;
#else
    Csm_SymEncryptServiceFinishNotification();
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
static void AesEncrypt(const Cry_HsmAesEncryptConfigType* config, const void *input, void *output, uint32 inputLength)
{
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesEncryptStart(config, KEY_ENCRYPTION, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesEncryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void EncryptWithRamKey(const void *input, void *output, uint32 inputLength, char* Mode)
{
    const Cry_HsmAesEncryptConfigType* config = CRY_HSM_AES_MODE_DUMMY;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    switch (*Mode)
    {
        case '1' :
        {
            config = &Cry_kHsmAesEncryptConfigModeCbc;
        }
        break;
        case '2' :
        {
            config = &Cry_kHsmAesEncryptConfigModeCtr;
        }
        break;
        case '3' :
        {
            config = &Cry_kHsmAesEncryptConfigModeOfb;
        }
        break;
        case '4' :
        {
            config = &Cry_kHsmAesEncryptConfigModeCfb;
        }
        break;
        default :
            break;
    }

    retVal = Cry_HsmAesEncryptStart(config, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesEncryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

}
void CbcEncryptTimeout(const void *input, void *output, uint32 inputLength)
{
    const Cry_HsmAesEncryptConfigType ConfigCBCLessTime =
    {.TimeOut =   {.TimeoutStart = 0,
                   .TimeoutUpdateConst = 3,
                   .TimeoutUpdateperByte = 0,
                   .TimeoutFinish = 3 }  };

    const Cry_HsmAesEncryptConfigType* config = &ConfigCBCLessTime;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesEncryptStart(config, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesEncryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

}

void EncryptWithRamKeyMultipleUpdate(void *output, char* Mode)
{
    const Cry_HsmAesEncryptConfigType* config = CRY_HSM_AES_MODE_DUMMY;
    Csm_ReturnType retVal;
    uint8 *TempOutputPtr;
    uint32 outputLength = 16U;
    TempOutputPtr = output;

    switch (*Mode)
    {
        case '1' :
        {
             config = &Cry_kHsmAesEncryptConfigModeCbc;
        }
        break;
        case '2' :
        {
            config = &Cry_kHsmAesEncryptConfigModeCtr;
        }
        break;
        case '3' :
        {
            config = &Cry_kHsmAesEncryptConfigModeOfb;
        }
        break;
        case '4' :
        {
            config = &Cry_kHsmAesEncryptConfigModeCfb;
        }
        break;
        default :
            break;
    }
    retVal = Cry_HsmAesEncryptStart(config, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesEncryptUpdate(config, TEST_CONST_PLAIN_1, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesEncryptUpdate(config, TEST_CONST_PLAIN_2, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesEncryptUpdate(config, TEST_CONST_PLAIN_3, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesEncryptUpdate(config, TEST_CONST_PLAIN_4, 16U, TempOutputPtr, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void DecryptWithRamKey(const void *input, void *output, uint32 inputLength, char* Mode)
{
    const Cry_HsmAesDecryptConfigType* config = CRY_HSM_AES_MODE_DUMMY;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    switch (*Mode)
    {
        case '1' :
        {
           config = &Cry_kHsmAesDecryptConfigModeCbc;
        }
        break;
        case '2' :
        {
            config = &Cry_kHsmAesDecryptConfigModeCtr;
        }
        break;
        case '3' :
        {
            config = &Cry_kHsmAesDecryptConfigModeOfb;
        }
        break;
        case '4' :
        {
            config = &Cry_kHsmAesDecryptConfigModeCfb;
        }
        break;
        default :
            break;
    }

    retVal = Cry_HsmAesDecryptStart(config, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesDecryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

}
void CbcDecryptTimeout(const void *input, void *output, uint32 inputLength)
{
    const Cry_HsmAesEncryptConfigType ConfigCBCLessTime =
    {.TimeOut =   {.TimeoutStart = 0,
                   .TimeoutUpdateConst = 3,
                   .TimeoutUpdateperByte = 0,
                   .TimeoutFinish = 3 }  };

    const Cry_HsmAesEncryptConfigType* config = &ConfigCBCLessTime;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesDecryptStart(config, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesDecryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

}

void DecryptWithRamKeyMultipleUpdate(const void *input, void *output, char* Mode)
{
    const Cry_HsmAesDecryptConfigType* config = CRY_HSM_AES_MODE_DUMMY;
    uint32 outputLength = 16U;
    Csm_ReturnType retVal;
    uint8 *TempOutputPtr;
    const uint8 *TempInputputPtr;
    TempOutputPtr = output;
    TempInputputPtr = input;
    switch (*Mode)
    {
        case '1' :
        {
            config = &Cry_kHsmAesDecryptConfigModeCbc;
        }
        break;
        case '2' :
        {
            config = &Cry_kHsmAesDecryptConfigModeCtr;
        }
        break;
        case '3' :
        {
            config = &Cry_kHsmAesDecryptConfigModeOfb;
        }
        break;
        case '4' :
        {
            config = &Cry_kHsmAesDecryptConfigModeCfb;
        }
        break;
        default :
            break;
    }
    retVal = Cry_HsmAesDecryptStart(config, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesDecryptUpdate(config, TempInputputPtr, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TempInputputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesDecryptUpdate(config, TempInputputPtr, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TempInputputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesDecryptUpdate(config, TempInputputPtr, 16U, TempOutputPtr, &outputLength);
    TempOutputPtr += 16;
    TempInputputPtr += 16;
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesDecryptUpdate(config, TempInputputPtr, 16U, TempOutputPtr, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_VALIDATE(outputLength == 16)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    retVal = Cry_HsmAesDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
static void AesDecrypt(const Cry_HsmAesDecryptConfigType* config, const void *input, void *output, uint32 inputLength)
{
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesDecryptStart(config, KEY_ENCRYPTION, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

    retVal = Cry_HsmAesDecryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
#endif

}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
static void TestHsm_aes_reference(const char* mode, const Cry_HsmAesEncryptConfigType* encConfig, const Cry_HsmAesDecryptConfigType* decConfig, const uint8* expResult)
{
    uint32 length = sizeof(TEST_CONST_PLAIN);
    boolean result;


    /*  ENCRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\n%s encryption: len = %d bytes\n", mode, length);
    AesEncrypt(encConfig, TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_A, sizeof(TEST_CONST_PLAIN));
    result = HsmCom_CompareArray((const uint32*)TEST_HSM_BUF_TEMP_A, (const uint32*)expResult, length / 4);
    TEST_PRINTF("CIPHERTEXT "); TEST_PRINTHEX(TEST_HSM_BUF_TEMP_A, length);
    TEST_VALIDATE(result != FALSE)


    /*  DECRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\n%s decryption: len = %d bytes\n", mode, length);
    AesDecrypt(decConfig, TEST_HSM_BUF_TEMP_A, TEST_HSM_BUF_TEMP_B, sizeof(TEST_CONST_PLAIN));
    result = HsmCom_CompareArray((const uint32*)TEST_HSM_BUF_TEMP_B, (const uint32*)TEST_CONST_PLAIN, length / 4);
    TEST_VALIDATE(result != FALSE)
}


/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
static void TestHsm_aes_bulk(const char* mode, const Cry_HsmAesEncryptConfigType* encConfig, const Cry_HsmAesDecryptConfigType* decConfig)
{
    uint32 i;
    boolean result;
    result = FALSE;
    /*  CBC ENCRYPTION TEST WITH BULK DATA */
    for (i = 0; i < (TEST_CRYPT_SIZE/4); i++)
    {
        TEST_HSM_BUF_TEMP_A[i] = 0x0010000 + i;
    }

    TEST_PRINTF("\n%s encryption: len = %d x 4 bytes.\n", mode, i);
    AesEncrypt(encConfig, TEST_HSM_BUF_TEMP_A, TEST_HSM_BUF_TEMP_B, TEST_CRYPT_SIZE);
    HsmCom_SetArrayValue(TEST_HSM_BUF_TEMP_A, 0, TEST_CRYPT_SIZE/4);

    /*  CBC DECRYPTION TEST WITH BULK DATA */
    TEST_PRINTF("\n%s decryption: len = %d x 4 bytes\n", mode, i);
    AesDecrypt(decConfig, TEST_HSM_BUF_TEMP_B, TEST_HSM_BUF_TEMP_A, TEST_CRYPT_SIZE);

    for (i = 0; i < (TEST_CRYPT_SIZE/4); i++)
    {
        result = (TEST_HSM_BUF_TEMP_A[i] == (0x0010000U + i));
        if (result == FALSE)
        {
            break;
        }
    }

    if (result == FALSE) { TEST_PRINTF("%x", TEST_HSM_BUF_TEMP_A[i]); }
    TEST_VALIDATE(result != FALSE)
}
#if ITF
void CbcParameter_Init()
{
    ITF_CBC_retVal  =CSM_E_ENTROPY_EXHAUSTION;
    ITF_CBC_retVal1 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_CBC_retVal2 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_CBC_retVal3 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_CBC_retVal4 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_CBC_retVal5 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_CBC_retVal6 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_CBC_retVal2_2 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_CBC_retVal2_3 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_CBC_retVal5_2 =CSM_E_ENTROPY_EXHAUSTION;
    ITF_CBC_retVal5_3 =CSM_E_ENTROPY_EXHAUSTION;
    RetKeyLoadCBC = CSM_E_ENTROPY_EXHAUSTION;
    CbcErrorCheck =0;
    k=0;
    DetErrorId = 99;
    DetApiId = 99;
    DetModuleId = 99;
    BswMErrorId =99;
    BswMErrorId_Upd1 = 99;
    BswMErrorId_Upd2 = 99;
    BswMErrorId_Fin = 99;
    CBCEncCallBackUpdateResult1 = CSM_E_ENTROPY_EXHAUSTION;
    CBCEncCallBackFinishResult1 = CSM_E_ENTROPY_EXHAUSTION;
    CBCDecCallBackFinishResult1 = CSM_E_ENTROPY_EXHAUSTION;

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
     g_TestHsm_cbc.callbackSet = 0;
     CBCEncCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
     CBCEncCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
     CBCEncCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
     CBCEncFinishNotify =0;

     CBCDecCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
     CBCDecCallBackUpdateResult  = CSM_E_ENTROPY_EXHAUSTION;
     CBCDecCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
     CBCDecFinishNotify =0;
#endif
}
void ITF_CBC_Enc_Dec(uint8 Aes_Mode)
{
    const Cry_HsmAesEncryptConfigType* encConfig;
    const Cry_HsmAesDecryptConfigType* decConfig;
    const Cry_HsmAesEncryptConfigType* config1;
    const Cry_HsmAesDecryptConfigType* decConfig1;
    Cry_HsmAesEncryptConfigType Cry_kHsmAesEncryptConfigModeCbcDelay;
    Cry_HsmAesDecryptConfigType Cry_kHsmAesDeryptConfigModeCbcDelay ;
    uint32 inputLength;
    uint32 outputLength ;
    uint32 Outputlenght16;
    uint32 Outputlenght32;
    uint32 inputlength32;
    uint8 k;

    const Csm_SymKeyType TestKey_100 = {1, {100U}};
    Cry_kHsmAesEncryptConfigModeCbcDelay.TimeOut.TimeoutStart = 0U;
    Cry_kHsmAesEncryptConfigModeCbcDelay.TimeOut.TimeoutUpdateConst = 0U;
    Cry_kHsmAesEncryptConfigModeCbcDelay.TimeOut.TimeoutUpdateperByte = 0U;
    Cry_kHsmAesEncryptConfigModeCbcDelay.TimeOut.TimeoutFinish = 0U;

    Cry_kHsmAesDeryptConfigModeCbcDelay.TimeOut.TimeoutStart = 0U;
    Cry_kHsmAesDeryptConfigModeCbcDelay.TimeOut.TimeoutUpdateConst = 0U;
    Cry_kHsmAesDeryptConfigModeCbcDelay.TimeOut.TimeoutUpdateperByte = 0U;
    Cry_kHsmAesDeryptConfigModeCbcDelay.TimeOut.TimeoutFinish = 0U;

    decConfig1 = &Cry_kHsmAesDeryptConfigModeCbcDelay;
    config1    = &Cry_kHsmAesEncryptConfigModeCbcDelay;

    decConfig = NULL_PTR;
    encConfig = NULL_PTR;

    switch (Aes_Mode)
    {
        case 1 :
        {
            encConfig  = &Cry_kHsmAesEncryptConfigModeCbc;
            decConfig  = &Cry_kHsmAesDecryptConfigModeCbc;
            Cry_kHsmAesEncryptConfigModeCbcDelay.Mode = CRY_HSM_AES_MODE_CBC;
            Cry_kHsmAesDeryptConfigModeCbcDelay.Mode = CRY_HSM_AES_MODE_CBC;
        }
        break;

        case 2 :
        {
            encConfig  = &Cry_kHsmAesEncryptConfigModeCtr;
            decConfig  = &Cry_kHsmAesDecryptConfigModeCtr;
            Cry_kHsmAesEncryptConfigModeCbcDelay.Mode = CRY_HSM_AES_MODE_CTR;
            Cry_kHsmAesDeryptConfigModeCbcDelay.Mode = CRY_HSM_AES_MODE_CTR;
        }
        break;

        case 3 :
        {
            encConfig  = &Cry_kHsmAesEncryptConfigModeOfb;
            decConfig  = &Cry_kHsmAesDecryptConfigModeOfb;
            Cry_kHsmAesEncryptConfigModeCbcDelay.Mode = CRY_HSM_AES_MODE_OFB;
            Cry_kHsmAesDeryptConfigModeCbcDelay.Mode = CRY_HSM_AES_MODE_OFB;
        }
        break;

        case 4 :
        {
            encConfig  = &Cry_kHsmAesEncryptConfigModeCfb;
            decConfig  = &Cry_kHsmAesDecryptConfigModeCfb;
            Cry_kHsmAesEncryptConfigModeCbcDelay.Mode = CRY_HSM_AES_MODE_CFB;
            Cry_kHsmAesDeryptConfigModeCbcDelay.Mode = CRY_HSM_AES_MODE_CFB;
        }
        break;

        default :
        {
            break;
        }

    }
    inputLength = sizeof(TEST_CONST_PLAIN);
    outputLength = inputLength;

    Outputlenght16 = 16;
    Outputlenght32 = 32;
    inputlength32 = 32;

    switch(ITF_CBC_TC)
    {
        /*CRY+ Test case 35*/
        case CBC_ENCSTART_NULLCONFG:
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesEncryptStart(NULL_PTR, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 36*/
        case CBC_ENCSTART_NULLKEYPTR:
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesEncryptStart(encConfig, NULL_PTR, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 37*/
        case CBC_ENCSTART_NULLINTVEC:
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, NULL_PTR, sizeof(TEST_CONST_INIT_VEC));
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 38*/
        case CBC_ENCSTART_CRYHSMUNINIT:
        {
            CbcParameter_Init();
            Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
            ITF_CBC_retVal = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPTION, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            if((DetErrorId == CRY_HSM_E_UNINIT ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 39*/
        case CBC_ENC_IPKEY_100 :
        {
            CbcParameter_Init();
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            ITF_CBC_retVal = Cry_HsmAesEncryptStart(encConfig, &TestKey_100, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            if((DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 40*/
        case CBC_ENC_INVALIDLENGTH :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, 8);
            if((DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 41*/
        case CBC_ENCUPDATE_NULLCONFIG :
        {
            CbcParameter_Init();
            ITF_CBC_retVal =  Cry_HsmAesEncryptUpdate(NULL_PTR, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN),(uint8 *) TEST_HSM_BUF_TEMP_A, &outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;

        }
        /*CRY+ Test case 42*/
        case CBC_ENCUPDATE_NULLPLNTXTPTR:
        {
            CbcParameter_Init();
            ITF_CBC_retVal =  Cry_HsmAesEncryptUpdate(encConfig, NULL_PTR, sizeof(TEST_CONST_PLAIN),(uint8 *) TEST_HSM_BUF_TEMP_A, &outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 43*/
        case CBC_ENCUPDATE_NULLCIPHTXTPTR:
        {
           CbcParameter_Init();
           ITF_CBC_retVal =  Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN), NULL_PTR, &outputLength);
           if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
           {
               CbcErrorCheck = 1;
           }
           else
           {
               CbcErrorCheck = 0;
           }
           ITF_CBC_TC = CRY_CBC_IDLE;
           break;
        }
        /*CRY+ Test case 44*/
        case CBC_ENCUPDATE_INVALIDOPLENGTH :
        {
            CbcParameter_Init();
           ITF_CBC_retVal =  Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN),(uint8 *) TEST_HSM_BUF_TEMP_A, NULL_PTR);
           if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
           {
               CbcErrorCheck = 1;
           }
           else
           {
               CbcErrorCheck = 0;
           }
           ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 45*/
        case CBC_ENCUPDATE_SERVICENOTSTARTED:
        {
            CbcParameter_Init();
            Cry_PrimStatus[CRY_HSM_SYM_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            ITF_CBC_retVal =  Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN, sizeof(TEST_CONST_PLAIN),(uint8 *) TEST_HSM_BUF_TEMP_A, &outputLength);
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
             break;
        }
        /*CRY+ Test case 46*/
        case CBC_ENCUPDATE_SMALLBUFFER :
        {
            CbcParameter_Init();
            Cry_PrimStatus[CRY_HSM_SYM_ENCRYPT] = CRY_HSM_PRIM_STARTED;
            ITF_CBC_retVal =  Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN, 32, (uint8 *)TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            if((DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            Cry_PrimStatus[CRY_HSM_SYM_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        case CBC_ENCUPD_LENGTH_NONMUL16 :
        {
            CbcParameter_Init();
            RetKeyLoadCBC = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_GCM, sizeof(TEST_CONST_PLAIN_GCM),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            if((DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;

        }
        /*CRY+ Test case 47*/
        case CBC_ENCFINISH_NULLCONFIG :
        {
           CbcParameter_Init();
           ITF_CBC_retVal =Cry_HsmAesEncryptFinish(NULL_PTR, NULL_PTR, NULL_PTR);
           if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
           {
               CbcErrorCheck = 1;
           }
           else
           {
               CbcErrorCheck = 0;
           }
           ITF_CBC_TC = CRY_CBC_IDLE;
           break;
        }
        /*CRY+ Test case 48*/
        case CBC_ENCFINISH_SERVICENOTSTARTED:
        {
            CbcParameter_Init();
            Cry_PrimStatus[CRY_HSM_SYM_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            ITF_CBC_retVal =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED ) && (DetApiId ==CRY_HSM_SID_AES_ENCRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 49*/
        case CBC_ENC_START_UPDATE_FINISH_VALIDIP :
        {
            CbcParameter_Init();
            RetKeyLoadCBC = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

            ITF_CBC_retVal4 = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal5 = Cry_HsmAesDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_A, Outputlenght16, TEST_PLAINTXT_16_1, &inputLength);
            ITF_CBC_retVal6 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

            if( (HsmCom_CompareArray((const uint32*)TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4))!= FALSE )
            {
                CbcErrorCheck =1;
            }
            else
            {
                CbcErrorCheck =0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 50*/
        case CBC_ENC_DEC:
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 =Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            ITF_CBC_retVal2_2 =Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_32, sizeof(TEST_CONST_PLAIN_32), (uint8 *)TEST_HSM_BUF_TEMP_B, &Outputlenght32);
            ITF_CBC_retVal2_3 =Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_3, sizeof(TEST_CONST_PLAIN_3),(uint8 *) TEST_CIPHTEXT_16, &Outputlenght16);
            ITF_CBC_retVal3 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

            ITF_CBC_retVal4 = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal5 = Cry_HsmAesDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_A, Outputlenght16, TEST_PLAINTXT_16_1, &inputLength);
            ITF_CBC_retVal5_2 = Cry_HsmAesDecryptUpdate(decConfig,(uint8 *) TEST_HSM_BUF_TEMP_B, Outputlenght32, TEST_PLAINTXT_32, &inputlength32);
            ITF_CBC_retVal5_3 = Cry_HsmAesDecryptUpdate(decConfig,(uint8 *) TEST_CIPHTEXT_16, Outputlenght16, TEST_PLAINTXT_16_2, &inputLength);
            ITF_CBC_retVal6 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

            if((HsmCom_CompareArray((const uint32*)TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4)!= FALSE) &&
               (HsmCom_CompareArray((const uint32*)TEST_PLAINTXT_32, (const uint32*)TEST_CONST_PLAIN_32, 8)!= FALSE) &&
               (HsmCom_CompareArray((const uint32*)TEST_PLAINTXT_16_2, (const uint32*)TEST_CONST_PLAIN_3, 4)!= FALSE))
                {
                    CbcErrorCheck =1;
                }
            else
            {
                CbcErrorCheck =0;
            }
            if((ITF_CBC_retVal1 == CSM_E_OK) && (ITF_CBC_retVal2 == CSM_E_OK) && (ITF_CBC_retVal2_2 == CSM_E_OK) && (ITF_CBC_retVal2_3 == CSM_E_OK) &&
               (ITF_CBC_retVal3 == CSM_E_OK) && (ITF_CBC_retVal4 == CSM_E_OK) && (ITF_CBC_retVal5 == CSM_E_OK) &&
               (ITF_CBC_retVal5_2 == CSM_E_OK) && (ITF_CBC_retVal5_3 == CSM_E_OK) && (ITF_CBC_retVal6 == CSM_E_OK) && (CbcErrorCheck ==1))
            {
                CbcErrorCheck =1;
            }
            else
            {
                CbcErrorCheck =0;
            }

            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 51*/
        case CBC_START_UPDATE_TILLDELAY :
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 =Cry_HsmAesEncryptUpdate(config1, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_retVal3 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        case CBC_FINISH_AFTERDELAY :
        {
            CbcParameter_Init();
            ITF_CBC_retVal3 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 52*/
        case CBC_START_FINISH :
        {
            CbcParameter_Init();
            RetKeyLoadCBC = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

            if((ITF_CBC_retVal1 == CSM_E_OK) && (ITF_CBC_retVal2 == CSM_E_NOT_OK))
            {
                ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
                ITF_CBC_retVal2 =Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
                ITF_CBC_retVal3 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
                if((ITF_CBC_retVal1 == CSM_E_OK) && (ITF_CBC_retVal2 == CSM_E_OK) && (ITF_CBC_retVal3 == CSM_E_OK))
                {
                    CbcErrorCheck = 1;
                }
                else
                {
                    CbcErrorCheck = 0;
                }
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
        /*CRY+ Test case 53*/
        case CBC_START_UPDATE_FINISH_ASYNC :
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2 =Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal3 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_retVal4 = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal5 = Cry_HsmAesDecryptUpdate(decConfig,(uint8 *)TEST_HSM_BUF_TEMP_A, Outputlenght16, TEST_PLAINTXT_16_1, &inputLength);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal6 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);

            if( (HsmCom_CompareArray((const uint32*)TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4)) != FALSE)
            {
                CbcErrorCheck =1;
            }
            else
            {
                CbcErrorCheck =0;
            }

            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 55*/
        case CBC_START_UPDATE_FINISH_ASYNCTILLDELAY :
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_retVal2 =Cry_HsmAesEncryptUpdate(config1, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_retVal3 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        case CBC_FINISH_ASYNCAFTERDELAY :
        {
            CbcParameter_Init();
            ITF_CBC_retVal3 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
#endif
        /*CRY+ Test case 56*/
        case CBC_DEC_START_NULLCONFIG :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(NULL_PTR, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) &&( DetApiId ==CRY_HSM_SID_AES_DECRYPT_START )&&( DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 57*/
        case CBC_DEC_START_NULLKEYPTR :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, NULL_PTR, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_START) && (DetModuleId == CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 58*/
        case CBC_DEC_START_NULL_INIT_VEC :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, NULL_PTR, sizeof(TEST_CONST_INIT_VEC));
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  &&( DetApiId ==CRY_HSM_SID_AES_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 59*/
        case CBC_DEC_START_CRY_HSM_UNIINIT :
        {
            CbcParameter_Init();
            Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            if((DetErrorId == CRY_HSM_E_UNINIT)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 60*/
        case CBC_DEC_START_IPKEY100 :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, &TestKey_100, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            if((DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 61*/
        case CBC_DEC_START_IV8 :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, 8);
            if((DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 62*/
        case CBC_DEC_UPDATE_NULLCFG :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptUpdate(NULL_PTR, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 63*/
        case CBC_DEC_UPDATE_NULLCIPHTXT :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptUpdate(decConfig, NULL_PTR, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 64*/
        case CBC_DEC_UPDATE_NULLPLNTXT :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, inputLength, NULL_PTR,&outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 65*/
        case CBC_DEC_UPDATE_NULLPLNTXTLENGTH :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,NULL_PTR);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 66*/
        case CBC_DEC_UPDATE_CRY_HSM_NOTINIT :
        {
            CbcParameter_Init();
            Cry_PrimStatus [CRY_HSM_SYM_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            ITF_CBC_retVal = Cry_HsmAesDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }

        /*CRY+ Test case 67*/
        case CBC_DEC_UPDATE_DIFFLENGTH :
        {
            Cry_PrimStatus [CRY_HSM_SYM_DECRYPT] = CRY_HSM_PRIM_STARTED;
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, 32, (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
            if((DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            Cry_PrimStatus [CRY_HSM_SYM_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        case CBC_DECUPD_LENGTH_NONMUL16 :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig, TEST_CONST_PLAIN_GCM,  sizeof(TEST_CONST_PLAIN_GCM), (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
            if((DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 68*/
        case CBC_DEC_FINISH_NULLCFGPTR :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptFinish(NULL_PTR, NULL_PTR, NULL_PTR);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 69*/
        case CBC_DEC_FINISH_SERVICENOTSTARTED :
        {
            CbcParameter_Init();
            Cry_PrimStatus [CRY_HSM_SYM_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED ;
            ITF_CBC_retVal =  Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId ==CRY_HSM_SID_AES_DECRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
            {
                CbcErrorCheck = 1;
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ Test case 70*/
        case CBC_DEC_START_UPDATE_FINISH :
        {
            CbcParameter_Init();
            RetKeyLoadCBC = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig, TEST_CONST_PLAIN_1,  sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

            ITF_CBC_retVal4 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal5 = Cry_HsmAesEncryptUpdate(encConfig, (uint8 *)TEST_HSM_BUF_TEMP_A, Outputlenght16,TEST_PLAINTXT_16_1, &inputLength);
            ITF_CBC_retVal6 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

            if( (HsmCom_CompareArray((const uint32*)TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4))!= FALSE )
            {
                CbcErrorCheck =1;
            }
            else
            {
                CbcErrorCheck =0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ test case 71*/
        case CBC_DEC_ENC :
        {
            CbcParameter_Init();

            ITF_CBC_retVal1 = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig,TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            ITF_CBC_retVal2_2 = Cry_HsmAesDecryptUpdate(decConfig,TEST_CONST_PLAIN_32, sizeof(TEST_CONST_PLAIN_32), TEST_PLAINTXT_32, &Outputlenght32);
            ITF_CBC_retVal2_3 = Cry_HsmAesDecryptUpdate(decConfig,TEST_CONST_PLAIN_3, sizeof(TEST_CONST_PLAIN_3), TEST_PLAINTXT_16_2, &Outputlenght16);
            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

            ITF_CBC_retVal4 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal5 =Cry_HsmAesEncryptUpdate(encConfig, (uint8 *) TEST_HSM_BUF_TEMP_A, Outputlenght16,TEST_PLAINTXT_16_1, &inputLength);
            ITF_CBC_retVal5_2 =Cry_HsmAesEncryptUpdate(encConfig, TEST_PLAINTXT_32, sizeof(TEST_CONST_PLAIN_32), (uint8 *)TEST_HSM_BUF_TEMP_B, &inputlength32);
            ITF_CBC_retVal5_3 =Cry_HsmAesEncryptUpdate(encConfig, TEST_PLAINTXT_16_2, sizeof(TEST_CONST_PLAIN_3),(uint8 *) TEST_CIPHTEXT_16, &inputLength);
            ITF_CBC_retVal6 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

            if((HsmCom_CompareArray((const uint32*)TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4)!= FALSE) &&
               (HsmCom_CompareArray(TEST_HSM_BUF_TEMP_B, (const uint32*)TEST_CONST_PLAIN_32, 8)!= FALSE) &&
               (HsmCom_CompareArray(TEST_CIPHTEXT_16, (const uint32*)TEST_CONST_PLAIN_3, 4)!= FALSE))
                {
                    CbcErrorCheck =1;
                }
            else
            {
                CbcErrorCheck =0;
            }
            if((ITF_CBC_retVal1 == CSM_E_OK) && (ITF_CBC_retVal2 == CSM_E_OK) && (ITF_CBC_retVal2_2 == CSM_E_OK) && (ITF_CBC_retVal2_3 == CSM_E_OK) &&
               (ITF_CBC_retVal3 == CSM_E_OK) && (ITF_CBC_retVal4 == CSM_E_OK) && (ITF_CBC_retVal5 == CSM_E_OK) &&
               (ITF_CBC_retVal5_2 == CSM_E_OK) && (ITF_CBC_retVal5_3 == CSM_E_OK) && (ITF_CBC_retVal6 == CSM_E_OK) && (CbcErrorCheck ==1))
            {
                CbcErrorCheck =1;
            }
            else
            {
                CbcErrorCheck =0;
            }

            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ test case 72*/
        case CBC_DEC_LESSTIMEOUT_TILLDELAY :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig1, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                CbcErrorCheck =1;
            }
            else
            {
                CbcErrorCheck =0;
            }
            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }

        case CBC_DEC_LESSTIMEOUT_AFTERDELAY :
        {
            CbcParameter_Init();
            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ test case 73*/
        case CBC_DEC_START_FINISH :
        {
            CbcParameter_Init();
            RetKeyLoadCBC = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

            if((ITF_CBC_retVal == CSM_E_OK) && (ITF_CBC_retVal2 == CSM_E_NOT_OK))
            {
                ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
                ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
                ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
                if((ITF_CBC_retVal == CSM_E_OK) && (ITF_CBC_retVal2 == CSM_E_OK) && (ITF_CBC_retVal3 == CSM_E_OK))
                {
                    CbcErrorCheck = 1;
                }
                else
                {
                    CbcErrorCheck = 0;
                }
            }
            else
            {
                CbcErrorCheck = 0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY_SC_TC_10*/
        case CRY_CBC_UPDATE_CANCEL :
        {
            CbcParameter_Init();
            CancelRequired = 1;
            for(k=0;k<4;k++)
            {
                TEST_HSM_BUF_TEMP_A[k]=0x00000000;
            }
            RetKeyLoadCBC = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            ITF_CBC_retVal2 =Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);

            Gpt_StopTimer(Gptch_CancelCommand);

            ITF_CBC_retVal3 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

            for(k=0;k<4;k++)
            {
                if(TEST_HSM_BUF_TEMP_A[k]!= 0x00000000)
                {
                    CbcErrorCheck = 0;
                    break;
                }
                else
                {
                    CbcErrorCheck = 1;
                }
            }
            if((ITF_CBC_retVal1 == CSM_E_OK) && (ITF_CBC_retVal2 == CSM_E_NOT_OK) && (ITF_CBC_retVal3 == CSM_E_NOT_OK)
                    && (CbcErrorCheck == 1))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY_SC_TC_11*/
        case CRY_CBC_FINISH_CANCEL_SESSIONCLOSEVER :
        {
            CbcParameter_Init();
            CancelRequired = 1;
            RetKeyLoadCBC = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);

            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

            Gpt_StopTimer(Gptch_CancelCommand);

            ITF_CBC_retVal4 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal5 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            ITF_CBC_retVal6 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);

            if((ITF_CBC_retVal1 == CSM_E_OK) && (ITF_CBC_retVal2 == CSM_E_OK) && (ITF_CBC_retVal3 == CSM_E_NOT_OK)
                    &&(ITF_CBC_retVal4 == CSM_E_OK) && (ITF_CBC_retVal5 == CSM_E_OK) && (ITF_CBC_retVal6 == CSM_E_OK))

            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
        }
        break;
        /*CRY_SC_TC_12*/
        case CRY_CBC_DEC_FINISH_CANCEL_SESSIONCLOSVER :
        {
            CbcParameter_Init();
            CancelRequired = 1;

            ITF_CBC_retVal1 = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig,TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

            Gpt_StopTimer(Gptch_CancelCommand);

            ITF_CBC_retVal4 = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal5 = Cry_HsmAesDecryptUpdate(decConfig,TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            ITF_CBC_retVal6 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

            if((ITF_CBC_retVal1 == CSM_E_OK) && (ITF_CBC_retVal2 == CSM_E_OK) && (ITF_CBC_retVal3 == CSM_E_NOT_OK) &&
                    (ITF_CBC_retVal4 == CSM_E_OK) && (ITF_CBC_retVal5 == CSM_E_OK) && (ITF_CBC_retVal6 == CSM_E_OK))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }

        case CRY_CBC_UPDATE_KEY_EMPTY :
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig,&TestKey_7, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            BswMErrorId_Upd1 = BswMErrorId;
            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            BswMErrorId_Fin = BswMErrorId;

            if((BswMErrorId_Upd1 == HSMCOM_ERC_KEY_EMPTY)&&(BswMErrorId_Fin == HSMCOM_ERC_KEY_EMPTY))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        case  CRY_CBC_MULTIPLE_UPD_KEY_EMPTY :
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig,&TestKey_7, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            BswMErrorId_Upd1 = BswMErrorId;
            ITF_CBC_retVal3 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            BswMErrorId_Upd2 = BswMErrorId;
            ITF_CBC_retVal4 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            BswMErrorId_Fin = BswMErrorId;

            if((BswMErrorId_Upd1 == HSMCOM_ERC_KEY_EMPTY)&& (BswMErrorId_Upd2 == HSMCOM_ERC_GENERAL_FAILURE)&&
                    (BswMErrorId_Fin == HSMCOM_ERC_KEY_EMPTY))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        case CRY_CBC_MULTIPLE_UPDATE_CANCEL_KEY_EMPTY :
        {
            CbcParameter_Init();
            CancelRequired = 1;

            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, &TestKey_7, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            BswMErrorId_Upd1 = BswMErrorId;

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            ITF_CBC_retVal3 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);

            Gpt_StopTimer(Gptch_CancelCommand);
            BswMErrorId_Upd2 = BswMErrorId;

            ITF_CBC_retVal4 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            BswMErrorId_Fin = BswMErrorId;

            if((BswMErrorId_Upd1 == HSMCOM_ERC_KEY_EMPTY)&& (BswMErrorId_Upd2 == HSMCOM_ERC_GENERAL_FAILURE)&&
                    (BswMErrorId_Fin == HSMCOM_ERC_KEY_EMPTY))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        case CRY_CBC_UPD_KEYEMPTY_FIN_TIMEOUT :
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPTION, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            BswMErrorId_Upd1 = BswMErrorId;
            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(config1, NULL_PTR, NULL_PTR);
            BswMErrorId_Fin = BswMErrorId;
            if((BswMErrorId_Upd1 == HSMCOM_ERC_KEY_EMPTY)&& (BswMErrorId_Fin == HSMCOM_ERC_TIMEOUT))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        case CRY_CBC_UPDATEKEYEMPTY_FIN_CANCEL :
        {
            CbcParameter_Init();
            CancelRequired = 1;
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPTION, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            BswMErrorId_Upd1 = BswMErrorId;

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            BswMErrorId_Fin = BswMErrorId;

            Gpt_StopTimer(Gptch_CancelCommand);


            if((BswMErrorId_Upd1 == HSMCOM_ERC_KEY_EMPTY)&& (BswMErrorId_Fin == HSMCOM_ERC_GENERAL_FAILURE))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
        /*CRY+ test case 74*/
        case CBC_DEC_START_UPDATE_FINISH_ASYNC :
        {
            CbcParameter_Init();
            RetKeyLoadCBC = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig, TEST_CONST_PLAIN_1,  sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_retVal4 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal5 = Cry_HsmAesEncryptUpdate(encConfig, (uint8 *)TEST_HSM_BUF_TEMP_A, Outputlenght16,TEST_PLAINTXT_16_1, &inputLength);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal6 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            if( (HsmCom_CompareArray((const uint32*)TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4))!= FALSE )
            {
                CbcErrorCheck =1;
            }
            else
            {
                CbcErrorCheck =0;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ test case 75*/
        /*CRY+ test case 76*/
        case CBC_DEC_LESSTIMEOUT_ASYNCTILLDELAY :
        {
            CbcParameter_Init();
            ITF_CBC_retVal = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig1, TEST_CONST_PLAIN_1, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A,&outputLength);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                CbcErrorCheck =1;
            }
            else
            {
                CbcErrorCheck =0;
            }
            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_TC = CRY_CBC_IDLE;
            break;

        }
        case CBC_DEC_LESSTIMEOUT_ASYNCAFTERDELAY :
        {
            CbcParameter_Init();
            ITF_CBC_retVal3 =  Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY_SC_TC_13*/
        case CRY_CBC_UPDATE_CANCEL_ASYNC :
        {
            CbcParameter_Init();
            RetKeyLoadCBC = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            Cry_HsmSheCancel();
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            if((CBCEncCallBackStartResult == CSM_E_OK) && (CBCEncCallBackUpdateResult == CSM_E_NOT_OK) && (CBCEncCallBackFinishResult == CSM_E_NOT_OK))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY_SC_TC_14*/
        case CRY_CBC_FINISH_CANCEL_SESSIONCLOSEVER_ASYNC :
        {
            CbcParameter_Init();
            RetKeyLoadCBC = SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)KEY_ENCRYPT_RAM_KEY,16);

            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            Cry_HsmSheCancel();
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);


            if((CBCEncCallBackStartResult != CSM_E_OK) || (CBCEncCallBackUpdateResult != CSM_E_OK) || (CBCEncCallBackFinishResult != CSM_E_NOT_OK))
             {
                 CbcErrorCheck = 1;
             }

            ITF_CBC_retVal4 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_retVal5 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_retVal6 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            if((CBCEncCallBackStartResult != CSM_E_OK) || (CBCEncCallBackUpdateResult != CSM_E_OK) || (CBCEncCallBackFinishResult != CSM_E_OK))
             {
                 CbcErrorCheck = 1;
             }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY_SC_TC_15*/
        case CRY_CBC_DEC_FINISH_CANCEL_SESSIONCLOSEVER_ASYNC :
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig, TEST_CONST_PLAIN_1,  sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);

            Cry_HsmSheCancel();

            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);

            if((CBCDecCallBackStartResult != CSM_E_OK) || (CBCDecCallBackUpdateResult != CSM_E_OK) ||
                    (CBCDecCallBackFinishResult != CSM_E_NOT_OK))
            {
                CbcErrorCheck = 1;
            }

            ITF_CBC_retVal1 = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig, TEST_CONST_PLAIN_1,  sizeof(TEST_CONST_PLAIN_1), (uint8 *)TEST_HSM_BUF_TEMP_A,&Outputlenght16);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);

            if((CBCDecCallBackStartResult != CSM_E_OK) || (CBCDecCallBackUpdateResult != CSM_E_OK) ||
                    (CBCDecCallBackFinishResult != CSM_E_OK))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }

        case CRY_CBC_UPDATE_KEY_EMPTY_ASYNC :
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, &TestKey_7, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            BswMErrorId_Upd1 = BswMErrorId;
            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            BswMErrorId_Fin = BswMErrorId;

            if((BswMErrorId_Upd1 == HSMCOM_ERC_KEY_EMPTY)&&(BswMErrorId_Fin == HSMCOM_ERC_KEY_EMPTY))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }

        /*Jira 30 */
        case CRY_CBC_UPD_KEYEMPTY_FIN_TIMEOUT_ASYNC :
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPTION, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            BswMErrorId_Upd1 = BswMErrorId;
            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(config1, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            BswMErrorId_Fin = BswMErrorId;
            if((BswMErrorId_Upd1 == HSMCOM_ERC_KEY_EMPTY)&& (BswMErrorId_Fin == HSMCOM_ERC_TIMEOUT))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        case CRY_CBC_UPDATEKEYEMPTY_FIN_CANCEL_ASYNC :
        {
            CbcParameter_Init();
            ITF_CBC_retVal1 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPTION, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2 = Cry_HsmAesEncryptUpdate(encConfig, TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1),(uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            BswMErrorId_Upd1 = BswMErrorId;
            ITF_CBC_retVal3 = Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            Cry_HsmSheCancel();
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            BswMErrorId_Fin = BswMErrorId;

            if((BswMErrorId_Upd1 == HSMCOM_ERC_KEY_EMPTY)&& (BswMErrorId_Fin == HSMCOM_ERC_GENERAL_FAILURE))
            {
                CbcErrorCheck = 1;
            }
            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }
        /*CRY+ test case 75*/
        case CBC_DEC_ENC_MUL_ASYNC :
        {
            CbcParameter_Init();

            ITF_CBC_retVal1 = Cry_HsmAesDecryptStart(decConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2 = Cry_HsmAesDecryptUpdate(decConfig,TEST_CONST_PLAIN_1, sizeof(TEST_CONST_PLAIN_1), (uint8 *) TEST_HSM_BUF_TEMP_A, &Outputlenght16);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2_2 = Cry_HsmAesDecryptUpdate(decConfig,TEST_CONST_PLAIN_32, sizeof(TEST_CONST_PLAIN_32), TEST_PLAINTXT_32, &Outputlenght32);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal2_3 = Cry_HsmAesDecryptUpdate(decConfig,TEST_CONST_PLAIN_3, sizeof(TEST_CONST_PLAIN_3), TEST_PLAINTXT_16_2, &Outputlenght16);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal3 = Cry_HsmAesDecryptFinish(decConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesDecryptMainFunction, &g_TestHsm_cbc.callbackSet);

            ITF_CBC_retVal4 = Cry_HsmAesEncryptStart(encConfig, KEY_ENCRYPT_RAM_KEY, TEST_CONST_INIT_VEC, sizeof(TEST_CONST_INIT_VEC));
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal5 =Cry_HsmAesEncryptUpdate(encConfig, (uint8 *) TEST_HSM_BUF_TEMP_A, Outputlenght16,TEST_PLAINTXT_16_1, &inputLength);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal5_2 =Cry_HsmAesEncryptUpdate(encConfig, TEST_PLAINTXT_32, sizeof(TEST_CONST_PLAIN_32), (uint8 *)TEST_HSM_BUF_TEMP_B, &inputlength32);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal5_3 =Cry_HsmAesEncryptUpdate(encConfig, TEST_PLAINTXT_16_2, sizeof(TEST_CONST_PLAIN_3),(uint8 *) TEST_CIPHTEXT_16, &inputLength);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);
            ITF_CBC_retVal6 =Cry_HsmAesEncryptFinish(encConfig, NULL_PTR, NULL_PTR);
            TEST_WAIT(&Cry_HsmAesEncryptMainFunction, &g_TestHsm_cbc.callbackSet);

            if((HsmCom_CompareArray((const uint32*)TEST_PLAINTXT_16_1, (const uint32*)TEST_CONST_PLAIN_1, 4)!= FALSE) &&
               (HsmCom_CompareArray(TEST_HSM_BUF_TEMP_B, (const uint32*)TEST_CONST_PLAIN_32, 8)!= FALSE) &&
               (HsmCom_CompareArray(TEST_CIPHTEXT_16, (const uint32*)TEST_CONST_PLAIN_3, 4)!= FALSE))
            {
                CbcErrorCheck =1;
            }
            else
            {
                CbcErrorCheck =0;
            }
            if((ITF_CBC_retVal1 == CSM_E_OK) && (ITF_CBC_retVal2 == CSM_E_OK) && (ITF_CBC_retVal2_2 == CSM_E_OK) && (ITF_CBC_retVal2_3 == CSM_E_OK) &&
               (ITF_CBC_retVal3 == CSM_E_OK) && (ITF_CBC_retVal4 == CSM_E_OK) && (ITF_CBC_retVal5 == CSM_E_OK) &&
               (ITF_CBC_retVal5_2 == CSM_E_OK) && (ITF_CBC_retVal5_3 == CSM_E_OK) && (ITF_CBC_retVal6 == CSM_E_OK) && (CbcErrorCheck ==1))
            {
                CbcErrorCheck =1;
            }
            else
            {
                CbcErrorCheck =0;
            }

            ITF_CBC_TC = CRY_CBC_IDLE;
            break;
        }

#endif
        default :
        {
            break;
        }
    }
}
#endif
/*************************************************************************************//**
 * Execution of CBC,CTR,OFB,CFB test suite
*//**************************************************************************************/
void TestHsm_aes(char* Mode)
{
    switch (*Mode)
    {
        case '1' :
        {
            TestHsm_aes_reference("CBC", &Cry_kHsmAesEncryptConfigModeCbc, &Cry_kHsmAesDecryptConfigModeCbc, TEST_CONST_CBC_CIPH);
            TestHsm_aes_bulk("CBC", &Cry_kHsmAesEncryptConfigModeCbc, &Cry_kHsmAesDecryptConfigModeCbc);

        }
        break;

        case '2' :
        {
            TestHsm_aes_reference("CTR", &Cry_kHsmAesEncryptConfigModeCtr, &Cry_kHsmAesDecryptConfigModeCtr, TEST_CONST_CTR_CIPH);
            TestHsm_aes_bulk("CTR", &Cry_kHsmAesEncryptConfigModeCtr, &Cry_kHsmAesDecryptConfigModeCtr);
        }
        break;

        case '3' :
        {
            TestHsm_aes_reference("OFB", &Cry_kHsmAesEncryptConfigModeOfb, &Cry_kHsmAesDecryptConfigModeOfb, TEST_CONST_OFB_CIPH);
            TestHsm_aes_bulk("OFB", &Cry_kHsmAesEncryptConfigModeOfb, &Cry_kHsmAesDecryptConfigModeOfb);
        }
        break;

        case '4' :
        {
            TestHsm_aes_reference("CFB", &Cry_kHsmAesEncryptConfigModeCfb, &Cry_kHsmAesDecryptConfigModeCfb, TEST_CONST_CFB_CIPH);
            TestHsm_aes_bulk("CFB", &Cry_kHsmAesEncryptConfigModeCfb, &Cry_kHsmAesDecryptConfigModeCfb);
        }
        break;

        default :
            break;
    }
}
void TestHsm_aes_cbc_RamKey(char* ModeOption)
{
    boolean cmpResult;

    ProtectedKey *load = (void*) TEST_HSM_BUF_TEMP_A;
    TestKeyEncryptData *ciph = (void*) TEST_HSM_BUF_TEMP_B;

    TEST_PRINTF("\nTest Encryption with Ram Key  ---------------------------------- \n");

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
    TEST_PRINTF(" - Load plain key \n");
    {
        SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)TEST_CONST_KEY,16);
    }
    TEST_PRINTF(" - Encrypt data with key \n");
    {
        EncryptWithRamKey( TEST_CONST_PLAIN, ciph->ciph1, sizeof (TEST_CONST_PLAIN), ModeOption);

        /* check that the RAM contains encrypted Data */
        TEST_VALIDATE(ciph->ciph1[0].Data[0] != 0xA5A5A5A5UL)
        TEST_VALIDATE(ciph->ciph1[NUM_BLOCKS-1].Data[0] != 0xA5A5A5A5UL)
    }
    TEST_PRINTF(" - Encrypt data #2 with key #1\n");
    {
        EncryptWithRamKey( TEST_CONST_PLAIN, ciph->ciph2, sizeof (TEST_CONST_PLAIN), ModeOption);

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
    TEST_PRINTF("Key used :\n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("Init Vector :\n");
    TEST_PRINT128(TEST_CONST_INIT_VEC);
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
        DecryptWithRamKey( ciph->ciph1, ciph->ciph2, sizeof (ciph->ciph1), ModeOption);

        cmpResult = HsmCom_CompareArray((const uint32*) TEST_CONST_PLAIN, (uint32*) ciph->ciph2, NUM_UINT32);
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" \n");
    TEST_PRINTF("Key used :\n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("Init Vector :\n");
    TEST_PRINT128(TEST_CONST_INIT_VEC);
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

/********************CBC Encryption/Decryption with Multiple updates********************************/
    TEST_PRINTF("\n encryption and decryption with multiple updates \n");
    TEST_PRINTF(" - Encrypt data with key \n");
    {
        EncryptWithRamKeyMultipleUpdate(ciph->ciph1, ModeOption);
    }
    TEST_PRINTF(" - Encrypt data #2 with key #1\n");
    {
        EncryptWithRamKeyMultipleUpdate(ciph->ciph2, ModeOption);

    }
    TEST_PRINTF(" - Compare encrypted data\n");
    {
        cmpResult = HsmCom_CompareArray((uint32*) ciph->ciph1, (uint32*) ciph->ciph2, NUM_UINT32);
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" \n");
    TEST_PRINTF("Key used :\n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("Init Vector :\n");
    TEST_PRINT128(TEST_CONST_INIT_VEC);
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
        DecryptWithRamKeyMultipleUpdate( ciph->ciph1, ciph->ciph2, ModeOption);

        cmpResult = HsmCom_CompareArray((const uint32*) TEST_CONST_PLAIN, (uint32*) ciph->ciph2, NUM_UINT32);
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" \n");
    TEST_PRINTF("Key used :\n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("Init Vector :\n");
    TEST_PRINT128(TEST_CONST_INIT_VEC);
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
#if 0
/***************************Timeout test************************************************/

    TEST_PRINTF("\n CBC Encrypt Timeout test \n");
    CbcEncryptTimeout( TEST_CONST_PLAIN, ciph->ciph1, sizeof (TEST_CONST_PLAIN));

    TEST_PRINTF("\n CBC Decrypt Timeout test \n");
    CbcDecryptTimeout(ciph->ciph1, ciph->ciph2, sizeof (ciph->ciph1));
/***************************End of timeout test********************************************/

/********************************Resynchonistaion******************************************/
    TEST_PRINTF(" - Encrypt data #2 with key #1\n");
    {
        CbcEncryptWithRamKey( TEST_CONST_PLAIN, ciph->ciph2, sizeof (TEST_CONST_PLAIN));

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
    TEST_PRINTF("Key used :\n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("Init Vector :\n");
    TEST_PRINT128(TEST_CONST_INIT_VEC);
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
        CbcDecryptWithRamKey( ciph->ciph1, ciph->ciph2, sizeof (ciph->ciph1));

        cmpResult = HsmCom_CompareArray((const uint32*) TEST_CONST_PLAIN, (uint32*) ciph->ciph2, NUM_UINT32);
        TEST_VALIDATE(cmpResult != FALSE)
    }
    TEST_PRINTF(" \n");
    TEST_PRINTF("Key used :\n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("Init Vector :\n");
    TEST_PRINT128(TEST_CONST_INIT_VEC);
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
/***********************************************************************************************/
#endif
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif

