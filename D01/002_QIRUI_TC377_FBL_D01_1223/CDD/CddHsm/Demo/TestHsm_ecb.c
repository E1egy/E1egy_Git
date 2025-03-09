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

#if 1

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

TestHsm_ecb g_TestHsm_ecb = {0};
#if ITF
uint32 input_time;
Csm_ReturnType retVal;
Csm_ReturnType retVal1;
Csm_ReturnType retVal2;
Csm_ReturnType retVal3;
Csm_ReturnType retVal4;
Csm_ReturnType retVal5;
Csm_ReturnType retVal6;
Csm_ReturnType RetkeyLoad;
uint8 TEST_HSM_BUF_TEMP_ITF[TEST_CRYPT_SIZE/4];
uint32 outputLength;

Csm_ReturnType EcbEncCallBackStartResult;
Csm_ReturnType EcbEncCallBackUpdateResult;
Csm_ReturnType EcbEncCallBackUpdateResult1;
Csm_ReturnType EcbEncCallBackFinishResult;
uint8 EcbEncFinishNotify;

Csm_ReturnType EcbDecCallBackStartResult;
Csm_ReturnType EcbDecCallBackUpdateResult;
Csm_ReturnType EcbDecCallBackUpdateResult1;
Csm_ReturnType EcbDecCallBackFinishResult;
uint8 EcbDecFinishNotify;

uint8 EcbErrorCheck =0;
uint8 j_test =0;

typedef enum{
    CRY_ECB_IDLE,
    CRY_ECB_ENCRYPT_KEYPTR_NULL,
    CRY_ECB_ENCRYPT_VALID_IP,
    CRY_ECB_ENCRYPT_IP_KEY_100,
    CRY_ECB_ENC_UPDATE_CFG_NULL,
    CRY_ECB_ENC_UPDATE_PLTXT_NULL,
    CRY_ECB_ENC_UPDATE_CIPHTXT_NULL,
    CRY_ECB_ENC_UPDATE_CIPHTXTLENGTH_NULL,
    CRY_ECB_ENC_UPDATE_STARTFUNC_FAILED,
    CRY_ECB_ENC_UPDATE_DIFFLENGTH,
    CRY_ECB_ENC_FINISH_FAIL,
    CRY_HSM_START_UPDATE_FINISH_VALIDIP,
    CRY_HSM_ENC_AND_DEC_SYNC,
    CRY_HSM_ENC_AND_DEC_SYNC_VALIDIP,
    CRY_HSM_START_UPDATE_FINISH_TILLDELAY,
    CRY_HSM_START_UPDATE_FINISH_AFTERDELAY,
    CRY_START_FINISH_PASS,
    CRY_ECB_DECRYPT_KEYPTR_NULL,
    CRY_ECB_DEC_CRYHSM_UNINIT,
    CRY_ECB_DEC_IPKEY100,
    CRY_ECB_DEC_NULLCONFIG,
    CRY_ECB_DEC_NULLCIPHTXT,
    CRY_ECB_DEC_NULLPLNTXT,
    CRY_ECB_DEC_NULLPLNTXTLENGTH,
    CRY_ECB_DEC_SERVICENOTSTARTED,
    CRY_ECB_DEC_SMALL_BUFFER,
    CRY_ECB_DEC_FIN_SERVICENOTSTARTED,
    CRY_ECB_DEC_START_UPDATE_FINISH_SYNC,
    CRY_ECB_DEC_ENC_SYNC,
    CRY_ECB_DEC_LESSTIMEOUT_TILLDELAY,
    CRY_ECB_DEC_LESSTIMEOUT_AFTERDELAY,
    CRY_ECB_DEC_START_FINISH,
    CRY_ECB_UPDATE_CANCEL,
    CRY_ECB_UPDATE_CANCEL_UPDATE,
    CRY_ECB_CANCEL_LESS_TIMEOUT,
    CRY_ECB_CANCEL_LESS_TIMEOUT_AFTER_DELAY,
    CRY_ECB_DEC_UPDATE_CANCEL_UPDATE,
    CRY_DEC_CANCEL_DUMMY,
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    CRY_HSM_START_UPDATE_FINISH_VALIDIP_ASYNC,
    CRY_ECB_ENC_DEC_ASYNC,
    CRY_HSM_START_UPDATE_FINISH_ASYNCTILLDELAY,
    CRY_HSM_START_UPDATE_FINISH_ASYNCAFTERDELAY,
    CRY_ECB_DEC_START_UPDATE_FINISH_ASYNC,
    CRY_ECB_DEC_ENC_ASYNC,
    CRY_ECB_DEC_LESSTIMEOUT_TILLDELAY_ASYNC,
    CRY_ECB_DEC_LESSTIMEOUT_AFTERDELAY_ASYNC,
    CRY_ECB_UPDATE_CANCEL_ASYNC,
    CRY_ECB_UPDATE_CANCEL_UPDATE_ASYNC,
    CRY_ECB_CANCEL_LESSTIMEOUT_ASYNC,
    CRY_ECB_CANCEL_LESSTIMEOUT_ASYNC_AFTERDELAY,
    CRY_ECB_DEC_UPDATE_CANCEL_UPDATE_ASYNC,
    CRY_ECB_DEC_CANCEL_DUMMY_ASYNC
#endif
}Cry_ECB_Testcase;
Cry_ECB_Testcase TC_ECB = CRY_ECB_IDLE;
#endif

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
#if ITF
void EcbParameter_Init()
{
    retVal  =CSM_E_ENTROPY_EXHAUSTION;
    retVal1 =CSM_E_ENTROPY_EXHAUSTION;
    retVal2 =CSM_E_ENTROPY_EXHAUSTION;
    retVal3 =CSM_E_ENTROPY_EXHAUSTION;
    retVal4 =CSM_E_ENTROPY_EXHAUSTION;
    retVal5 =CSM_E_ENTROPY_EXHAUSTION;
    retVal6 =CSM_E_ENTROPY_EXHAUSTION;
    RetkeyLoad = CSM_E_ENTROPY_EXHAUSTION;
    EcbErrorCheck =0;
    DetErrorId = 99;
    DetApiId = 99;
    DetModuleId = 99;
    BswMErrorId =99;

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
     g_TestHsm_ecb.callbackSet = 0;
     EcbEncCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
     EcbEncCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
     EcbEncCallBackUpdateResult1 = CSM_E_ENTROPY_EXHAUSTION;
     EcbEncCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
     EcbEncFinishNotify =0;

     EcbDecCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
     EcbDecCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
     EcbDecCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
     EcbDecCallBackUpdateResult1 = CSM_E_ENTROPY_EXHAUSTION;
     EcbDecFinishNotify =0;
#endif
}
void ITF_ECB_Enc_Dec()
{
    const void *input;
    void *output ;
    uint32 inputLength;
    const Cry_HsmAesEcbEncryptConfigType* config;
    const Cry_HsmAesEcbEncryptConfigType* config2;
    const Cry_HsmAesEcbDecryptConfigType* Decconfig;
    const Cry_HsmAesEcbDecryptConfigType* Decconfig1;
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    const Cry_HsmAesEcbEncryptConfigType* config1;
    Cry_HsmAesEcbEncryptConfigType Cry_kHsmAesEcbEncryptConfigDelay;
#endif
    Cry_HsmAesEcbEncryptConfigType Cry_kHsmAesEcbEncryptConfigDelayGpt;
    Cry_HsmAesEcbDecryptConfigType Cry_kHsmAesEcbDecryptConfigDelay;
    uint32 outputLength10 ;

    const Csm_SymKeyType TestKey_100 ={1,{100U}};

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    Cry_kHsmAesEcbEncryptConfigDelay.TimeOut.TimeoutStart = 0U;
    Cry_kHsmAesEcbEncryptConfigDelay.TimeOut.TimeoutUpdateConst = 0U;
    Cry_kHsmAesEcbEncryptConfigDelay.TimeOut.TimeoutUpdateperByte = 0U;
    Cry_kHsmAesEcbEncryptConfigDelay.TimeOut.TimeoutFinish = 0U;
#endif

    Cry_kHsmAesEcbDecryptConfigDelay.TimeOut.TimeoutStart = 0U;
    Cry_kHsmAesEcbDecryptConfigDelay.TimeOut.TimeoutUpdateConst = 0U;
    Cry_kHsmAesEcbDecryptConfigDelay.TimeOut.TimeoutUpdateperByte = 0U;
    Cry_kHsmAesEcbDecryptConfigDelay.TimeOut.TimeoutFinish = 0U;

    Cry_kHsmAesEcbEncryptConfigDelayGpt.TimeOut.TimeoutStart = 0U;
    Cry_kHsmAesEcbEncryptConfigDelayGpt.TimeOut.TimeoutUpdateConst = 8U;
    Cry_kHsmAesEcbEncryptConfigDelayGpt.TimeOut.TimeoutUpdateperByte = 0U;
    Cry_kHsmAesEcbEncryptConfigDelayGpt.TimeOut.TimeoutFinish = 0U;

    config = &Cry_kHsmAesEcbEncryptConfig;
    config2= &Cry_kHsmAesEcbEncryptConfigDelayGpt;
    Decconfig = &Cry_kHsmAesEcbDecryptConfig;
    Decconfig1 =&Cry_kHsmAesEcbDecryptConfigDelay;
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    config1= &Cry_kHsmAesEcbEncryptConfigDelay;
#endif

    inputLength = sizeof(TEST_CONST_ECB_CIPH);
    outputLength = inputLength;
    input=TEST_CONST_PLAIN;
    output =TEST_HSM_BUF_TEMP_A;
    outputLength10= 10;

    switch(TC_ECB)
    {
        /*CRY+ Test case 1*/
        case  CRY_ECB_ENCRYPT_KEYPTR_NULL:
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbEncryptStart(config, NULL_PTR);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ECB_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 2*/
        case CRY_ECB_ENCRYPT_VALID_IP:
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            if((DetErrorId == CRY_HSM_E_UNINIT ) && (DetApiId ==CRY_HSM_SID_AES_ECB_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 3*/
        case CRY_ECB_ENCRYPT_IP_KEY_100 :
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbEncryptStart(config, &TestKey_100);
            if((DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_ECB_ENCRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 4*/
        case CRY_ECB_ENC_UPDATE_CFG_NULL:
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbEncryptUpdate(NULL_PTR, input, inputLength, output, &outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 5*/
        case CRY_ECB_ENC_UPDATE_PLTXT_NULL:
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbEncryptUpdate(config, NULL_PTR, inputLength, output, &outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId ==CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE )&& ( DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
             break;
        }
        /*CRY+ Test case 6*/
        case CRY_ECB_ENC_UPDATE_CIPHTXT_NULL:
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, NULL_PTR, &outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
              EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 7*/
        case CRY_ECB_ENC_UPDATE_CIPHTXTLENGTH_NULL:
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, NULL_PTR);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID ) && (DetApiId == CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE )&& (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;

            }
            else
            {
                EcbErrorCheck = 0;

            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 8*/
        case CRY_ECB_ENC_UPDATE_STARTFUNC_FAILED:
        {
            EcbParameter_Init();
            Cry_PrimStatus[CRY_HSM_SYM_ECB_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            retVal = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)  &&(DetApiId == CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 9*/
        case CRY_ECB_ENC_UPDATE_DIFFLENGTH:
        {
            EcbParameter_Init();
            Cry_PrimStatus[CRY_HSM_SYM_ECB_ENCRYPT] = CRY_HSM_PRIM_STARTED;
            retVal = Cry_HsmAesEcbEncryptUpdate(config, input, 16, output, &outputLength10);
            if((DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL)  && (DetApiId == CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            Cry_PrimStatus[CRY_HSM_SYM_ECB_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            break;
        }
        /*CRY+ Test case 10*/
        case CRY_ECB_ENC_FINISH_FAIL:
        {
            EcbParameter_Init();
            Cry_PrimStatus[CRY_HSM_SYM_ECB_ENCRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            retVal = Cry_HsmAesEcbEncryptFinish(config,NULL_PTR,NULL_PTR );
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED) && (DetApiId == CRY_HSM_SID_AES_ECB_ENCRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 11*/
        case CRY_HSM_START_UPDATE_FINISH_VALIDIP:
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            retVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
            retVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 12*/
        case CRY_HSM_ENC_AND_DEC_SYNC_VALIDIP:
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            retVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
            retVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);
            retVal4 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            retVal5 = Cry_HsmAesEcbDecryptUpdate(Decconfig, output, inputLength, TEST_HSM_BUF_TEMP_ITF, &outputLength);
            retVal6 = Cry_HsmAesEcbDecryptFinish(Decconfig, TEST_HSM_BUF_TEMP_ITF,&outputLength);

            EcbErrorCheck =1;
            for(j_test=0;j_test<16;j_test++)
            {
                if(TEST_HSM_BUF_TEMP_ITF[j_test] != TEST_CONST_PLAIN[j_test])
                {
                    EcbErrorCheck =0;
                    break;
                }
            }
            if((retVal1==CSM_E_OK) && (retVal2==CSM_E_OK) && (retVal3 ==CSM_E_OK) &&
                   ( retVal4 ==CSM_E_OK) && (retVal5==CSM_E_OK) && (retVal6 ==CSM_E_OK)
                    && (EcbErrorCheck == 1))
            {
                EcbErrorCheck =1;
            }
            else
            {
                EcbErrorCheck =0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 13*/
        case CRY_HSM_START_UPDATE_FINISH_TILLDELAY:
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            retVal2 = Cry_HsmAesEcbEncryptUpdate(config2, input, inputLength, output, &outputLength);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            retVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);

            TC_ECB = CRY_ECB_IDLE;
            break;
       }

        case CRY_HSM_START_UPDATE_FINISH_AFTERDELAY:
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 14*/
        case CRY_START_FINISH_PASS:
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            retVal2 = Cry_HsmAesEcbEncryptFinish(config, NULL_PTR, NULL_PTR);

            TC_ECB = CRY_ECB_IDLE;
            break;
        }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
        /*CRY+ Test case 15*/
        case CRY_HSM_START_UPDATE_FINISH_VALIDIP_ASYNC:
        {

            EcbParameter_Init();

            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 16*/
        case CRY_ECB_ENC_DEC_ASYNC:
        {

            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal4 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal5 = Cry_HsmAesEcbDecryptUpdate(Decconfig, output, inputLength, TEST_HSM_BUF_TEMP_ITF, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal6 = Cry_HsmAesEcbDecryptFinish(Decconfig, TEST_HSM_BUF_TEMP_ITF,&outputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);

            EcbErrorCheck =1;
            for(j_test=0;j_test<16;j_test++)
            {
              if(TEST_HSM_BUF_TEMP_ITF[j_test] != TEST_CONST_PLAIN[j_test])
              {
                EcbErrorCheck =0;
                break;
              }
            }
            if((retVal1==CSM_E_OK )&& (retVal2==CSM_E_OK) && (retVal3 ==CSM_E_OK )&&
                (retVal4 ==CSM_E_OK )&&( retVal5==CSM_E_OK )&& (retVal6 ==CSM_E_OK)
                && (EcbErrorCheck == 1))
            {
                  EcbErrorCheck =1;
            }
            else
            {
                EcbErrorCheck =0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;

        }
        /*CRY+ Test case 17*/
        case CRY_HSM_START_UPDATE_FINISH_ASYNCTILLDELAY:
        {

            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal2 = Cry_HsmAesEcbEncryptUpdate(config1, input, inputLength, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);
           TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

           if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
           {
               EcbErrorCheck = 1;
           }
           else
           {
               EcbErrorCheck = 0;
           }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        case CRY_HSM_START_UPDATE_FINISH_ASYNCAFTERDELAY:
        {

            EcbParameter_Init();
            retVal = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            TC_ECB = CRY_ECB_IDLE;
            break;
        }
#endif
        /*CRY+ Test case 18*/
        case CRY_ECB_DECRYPT_KEYPTR_NULL:
        {
            EcbParameter_Init();
            retVal =  Cry_HsmAesEcbDecryptStart(Decconfig, NULL_PTR);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId ==CRY_HSM_SID_AES_ECB_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 19*/
        case CRY_ECB_DEC_CRYHSM_UNINIT:
        {
            EcbParameter_Init();
            Cry_HsmInitStatus  = CRY_HSM_UNINITIALIZED;
            retVal =  Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            if((DetErrorId == CRY_HSM_E_UNINIT)  && (DetApiId ==CRY_HSM_SID_AES_ECB_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            Cry_HsmInitStatus  = CRY_HSM_INITIALIZED;
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 20*/
        case CRY_ECB_DEC_IPKEY100 :
        {
            EcbParameter_Init();
            retVal =  Cry_HsmAesEcbDecryptStart(Decconfig, &TestKey_100);
            if((DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID)  && (DetApiId ==CRY_HSM_SID_AES_ECB_DECRYPT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 21*/
        case CRY_ECB_DEC_NULLCONFIG:
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbDecryptUpdate(NULL_PTR, input, inputLength, output, &outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 22*/
        case CRY_ECB_DEC_NULLCIPHTXT :
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbDecryptUpdate(Decconfig, NULL_PTR, inputLength, output, &outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId == CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 23*/
        case CRY_ECB_DEC_NULLPLNTXT :
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, NULL_PTR, &outputLength);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId == CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 24*/
        case CRY_ECB_DEC_NULLPLNTXTLENGTH :
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, NULL_PTR);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId == CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 25*/
        case CRY_ECB_DEC_SERVICENOTSTARTED :
        {
            EcbParameter_Init();
            Cry_PrimStatus [CRY_HSM_SYM_ECB_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            retVal = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, &outputLength);
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED ) && (DetApiId == CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 26*/
        case CRY_ECB_DEC_SMALL_BUFFER :
        {
            EcbParameter_Init();
            Cry_PrimStatus [CRY_HSM_SYM_ECB_DECRYPT] = CRY_HSM_PRIM_STARTED;
            retVal = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, 16, output, &outputLength10);
            if((DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL)  &&(DetApiId == CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE) &&( DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            Cry_PrimStatus [CRY_HSM_SYM_ECB_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 27*/
        case CRY_ECB_DEC_FIN_SERVICENOTSTARTED :
        {
            EcbParameter_Init();
            Cry_PrimStatus [CRY_HSM_SYM_ECB_DECRYPT] = CRY_HSM_PRIM_NOT_STARTED;
            retVal = Cry_HsmAesEcbDecryptFinish(Decconfig, NULL_PTR, NULL_PTR);
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId == CRY_HSM_SID_AES_ECB_DECRYPT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;

        }
        /*CRY+ Test case 28*/
        case CRY_ECB_DEC_START_UPDATE_FINISH_SYNC :
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            retVal2 = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, &outputLength);
            retVal3 = Cry_HsmAesEcbDecryptFinish(Decconfig, output, &outputLength);
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 29*/
        case CRY_ECB_DEC_ENC_SYNC :
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            retVal2 = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, &outputLength);
            retVal3 = Cry_HsmAesEcbDecryptFinish(Decconfig, output, &outputLength);
            retVal4 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            retVal5 = Cry_HsmAesEcbEncryptUpdate(config, output, outputLength, TEST_HSM_BUF_TEMP_ITF, &inputLength);
            retVal6 = Cry_HsmAesEcbEncryptFinish(config, TEST_HSM_BUF_TEMP_ITF, &inputLength);

            EcbErrorCheck =1;
            for(j_test=0;j_test<16;j_test++)
            {
                if(TEST_HSM_BUF_TEMP_ITF[j_test] != TEST_CONST_PLAIN[j_test])
                {
                    EcbErrorCheck =0;
                    break;
                }
            }
            if((retVal1==CSM_E_OK) && (retVal2==CSM_E_OK) && (retVal3 ==CSM_E_OK) &&
                    (retVal4 ==CSM_E_OK) && (retVal5==CSM_E_OK) && (retVal6 ==CSM_E_OK)
                    && (EcbErrorCheck == 1))
            {
                EcbErrorCheck =1;
            }
            else
            {
                EcbErrorCheck =0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 30*/
        case CRY_ECB_DEC_LESSTIMEOUT_TILLDELAY :
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            retVal2 = Cry_HsmAesEcbDecryptUpdate(Decconfig1, input, inputLength, output, &outputLength);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            retVal3 = Cry_HsmAesEcbDecryptFinish(Decconfig, output, &outputLength);

            TC_ECB = CRY_ECB_IDLE;
            break;
        }

        case CRY_ECB_DEC_LESSTIMEOUT_AFTERDELAY :
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbDecryptFinish(Decconfig, TEST_HSM_BUF_TEMP_ITF, &inputLength);
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 31*/
        case CRY_ECB_DEC_START_FINISH :
        {
            retVal1 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            retVal2 = Cry_HsmAesEcbDecryptFinish(Decconfig, output, &outputLength);
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY_SC_TC_01*/
        case CRY_ECB_UPDATE_CANCEL :
        {
            EcbParameter_Init();
            CancelRequired = 1;

            for(j_test=0;j_test<4;j_test++)
            {
                 TEST_HSM_BUF_TEMP_A[j_test]=0x00000000;
            }
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            retVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);

            Gpt_StopTimer(Gptch_CancelCommand);

            retVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);

            for(j_test=0;j_test<4;j_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[j_test]!= 0x00000000)
                {
                    EcbErrorCheck = 0;
                    break;
                }
                else
                {
                    EcbErrorCheck = 1;
                }
            }

            if((retVal1 == CSM_E_OK) && (retVal2 == CSM_E_NOT_OK) && (retVal3 == CSM_E_OK)
                    && (EcbErrorCheck == 1))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY_SC_TC_02*/
        case CRY_ECB_UPDATE_CANCEL_UPDATE :
        {
            EcbParameter_Init();
            CancelRequired = 1;

            for(j_test=0;j_test<4;j_test++)
            {
                 TEST_HSM_BUF_TEMP_A[j_test]=0x00000000;
            }
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            retVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);

            Gpt_StopTimer(Gptch_CancelCommand);

            retVal3 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);

            retVal4 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);

            for(j_test=0;j_test<4;j_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[j_test]!= 0x00000000)
                {
                    EcbErrorCheck = 1;

                }
                else
                {
                    EcbErrorCheck = 0;
                    break;
                }
            }

            if((retVal1 == CSM_E_OK) && (retVal2 == CSM_E_NOT_OK) && (retVal3 == CSM_E_OK)
                    && (retVal4 == CSM_E_OK) && (EcbErrorCheck == 1))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
        }
        break;
        /*CRY_SC_TC_03*/
        case CRY_ECB_CANCEL_LESS_TIMEOUT:
        {
            EcbParameter_Init();
            CancelRequired = 1;

            for(j_test=0;j_test<4;j_test++)
            {
                 TEST_HSM_BUF_TEMP_A[j_test]=0x00000000;
            }
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            retVal2 = Cry_HsmAesEcbEncryptUpdate(config2, input, inputLength, output, &outputLength);

            Cry_HsmSheCancel();

            if((retVal1 == CSM_E_OK) && (retVal2 == CSM_E_NOT_OK)
                    && (BswMErrorId == 0xE0))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;

        }
        case CRY_ECB_CANCEL_LESS_TIMEOUT_AFTER_DELAY :
        {
            EcbParameter_Init();

            retVal3 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
            retVal4 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);

            for(j_test=0;j_test<4;j_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[j_test]!= 0x00000000)
                {
                    EcbErrorCheck = 1;

                }
                else
                {
                    EcbErrorCheck = 0;
                    break;
                }
            }

            if((retVal3 == CSM_E_OK) && (retVal4 == CSM_E_OK)
                    && (EcbErrorCheck == 1))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
        }
        break;
        /*CRY_SC_TC_04*/
        case CRY_ECB_DEC_UPDATE_CANCEL_UPDATE :
        {
            EcbParameter_Init();
            CancelRequired = 1;

            for(j_test=0;j_test<4;j_test++)
            {
                 TEST_HSM_BUF_TEMP_A[j_test]=0x00000000;
            }
            retVal1 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            retVal2 = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, &outputLength);

            Gpt_StopTimer(Gptch_CancelCommand);

            retVal3 = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, &outputLength);

            retVal4 = Cry_HsmAesEcbDecryptFinish(Decconfig, output, &outputLength);

            for(j_test=0;j_test<4;j_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[j_test]!= 0x00000000)
                {
                    EcbErrorCheck = 1;

                }
                else
                {
                    EcbErrorCheck = 0;
                    break;
                }
            }
            if((retVal1 == CSM_E_OK) && (retVal2 == CSM_E_NOT_OK) && (retVal3 == CSM_E_OK)
                    && (retVal4 == CSM_E_OK) && (EcbErrorCheck == 1))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
        }
        break;
        /*CRY_SC_TC_05*/
        case CRY_DEC_CANCEL_DUMMY:
        {
            EcbParameter_Init();
            CancelRequired = 1;

            for(j_test=0;j_test<4;j_test++)
            {
                 TEST_HSM_BUF_TEMP_A[j_test]=0xFFFFFFFF;
            }

            retVal1 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            retVal2 = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, &outputLength);

            Cry_HsmSheCancel();

            retVal3 = Cry_HsmAesEcbDecryptFinish(Decconfig, output, &outputLength);

            for(j_test=0;j_test<4;j_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[j_test]!= 0xFFFFFFFF)
                {
                    EcbErrorCheck = 1;


                }
                else
                {
                    EcbErrorCheck = 0;
                    break;

                }
            }
            if((retVal1 == CSM_E_OK) && (retVal2 == CSM_E_OK) && (retVal3 == CSM_E_OK)
                    && (EcbErrorCheck == 1))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
        }
        break;
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
        /*CRY+ Test case 32*/
        case CRY_ECB_DEC_START_UPDATE_FINISH_ASYNC :
        {
            EcbParameter_Init();
            retVal1 =  Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
            retVal2 = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
            retVal3 = Cry_HsmAesEcbDecryptFinish(config, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);

            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 33*/
        case CRY_ECB_DEC_ENC_ASYNC :
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
            retVal2 = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
            retVal3 = Cry_HsmAesEcbDecryptFinish(Decconfig, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
            retVal4 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
            retVal5 = Cry_HsmAesEcbEncryptUpdate(config, output, outputLength, TEST_HSM_BUF_TEMP_ITF, &inputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
            retVal6 = Cry_HsmAesEcbEncryptFinish(config, TEST_HSM_BUF_TEMP_ITF, &inputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            EcbErrorCheck =1;
            for(j_test=0;j_test<16;j_test++)
            {
                if(TEST_HSM_BUF_TEMP_ITF[j_test] != TEST_CONST_PLAIN[j_test])
                {
                    EcbErrorCheck =0;
                    break;
                }
            }
            if((retVal1==CSM_E_OK) && (retVal2==CSM_E_OK) && (retVal3 ==CSM_E_OK) &&
                    (retVal4 ==CSM_E_OK) && (retVal5==CSM_E_OK) && (retVal6 ==CSM_E_OK)
                    && (EcbErrorCheck == 1))
            {
                EcbErrorCheck =1;
            }
            else
            {
                EcbErrorCheck =0;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY+ Test case 34*/
        case CRY_ECB_DEC_LESSTIMEOUT_TILLDELAY_ASYNC :
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
            retVal2 = Cry_HsmAesEcbDecryptUpdate(Decconfig1, input, inputLength, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                EcbErrorCheck = 1;
            }
            else
            {
                EcbErrorCheck = 0;
            }
            retVal3 = Cry_HsmAesEcbDecryptFinish(Decconfig, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        case CRY_ECB_DEC_LESSTIMEOUT_AFTERDELAY_ASYNC :
        {
            EcbParameter_Init();
            retVal = Cry_HsmAesEcbDecryptFinish(Decconfig, TEST_HSM_BUF_TEMP_ITF, &inputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY_SC_TC_06*/
        case CRY_ECB_UPDATE_CANCEL_ASYNC :
        {
            EcbParameter_Init();
            for(j_test=0;j_test<4;j_test++)
            {
                 TEST_HSM_BUF_TEMP_A[j_test]=0x00000000;
            }
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
            Cry_HsmSheCancel();
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            for(j_test=0;j_test<4;j_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[j_test]!= 0x00000000)
                {
                    EcbErrorCheck = 0;
                    break;

                }
                else
                {
                    EcbErrorCheck = 1;

                }
            }
            if((EcbEncCallBackStartResult == CSM_E_OK) && (EcbEncCallBackUpdateResult == CSM_E_NOT_OK) &&
                    (EcbEncCallBackFinishResult == CSM_E_OK)
                    &&(EcbErrorCheck == 1))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
            break;
        }
        /*CRY_SC_TC_07*/
        case CRY_ECB_UPDATE_CANCEL_UPDATE_ASYNC:
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
            Cry_HsmSheCancel();
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            EcbEncCallBackUpdateResult1 = EcbEncCallBackUpdateResult;

            retVal3 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal4 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            if((EcbEncCallBackStartResult == CSM_E_OK)&&
                    (EcbEncCallBackUpdateResult1 == CSM_E_NOT_OK)
                    &&(EcbEncCallBackUpdateResult == CSM_E_OK)
                    &&(EcbEncCallBackFinishResult == CSM_E_OK))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
        }
        break;
        /*CRY_SC_TC_08*/
        case CRY_ECB_CANCEL_LESSTIMEOUT_ASYNC :
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal2 = Cry_HsmAesEcbEncryptUpdate(config2, input, inputLength, output, &outputLength);
            Cry_HsmSheCancel();
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            if((EcbEncCallBackUpdateResult == CSM_E_NOT_OK))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
        }
        break;
        case CRY_ECB_CANCEL_LESSTIMEOUT_ASYNC_AFTERDELAY :
        {
            EcbParameter_Init();
            retVal3 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal4 = Cry_HsmAesEcbEncryptFinish(config, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

            if((EcbEncCallBackUpdateResult == CSM_E_OK) && (EcbEncCallBackFinishResult == CSM_E_OK))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
        }
        break;
        /*CRY_SC_TC_09*/
        case CRY_ECB_DEC_UPDATE_CANCEL_UPDATE_ASYNC:
        {
            EcbParameter_Init();
            retVal1 = Cry_HsmAesEcbDecryptStart(Decconfig, KEY_ENCRYPT_RAM_KEY);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal2 = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, &outputLength);
            Cry_HsmSheCancel();
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);

            EcbDecCallBackUpdateResult1 = EcbDecCallBackUpdateResult;

            retVal3 = Cry_HsmAesEcbDecryptUpdate(Decconfig, input, inputLength, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);

            retVal4 = Cry_HsmAesEcbDecryptFinish(Decconfig, output, &outputLength);
            TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);

            if( (EcbDecCallBackUpdateResult1== CSM_E_NOT_OK) &&( EcbDecCallBackUpdateResult== CSM_E_OK))
            {
                EcbErrorCheck = 1;
            }
            TC_ECB = CRY_ECB_IDLE;
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
void EcbEncryptWithRamKey(const void *input, void *output, uint32 inputLength)
{
    const Cry_HsmAesEcbEncryptConfigType* config = &Cry_kHsmAesEcbEncryptConfig;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
    retVal = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesEcbEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
	
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/

void EcbDecryptWithRamKey(const void *input, void *output, uint32 inputLength)
{
	const Cry_HsmAesEcbDecryptConfigType* config = &Cry_kHsmAesEcbDecryptConfig;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

    retVal = Cry_HsmAesEcbDecryptStart(config, KEY_ENCRYPT_RAM_KEY);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

    retVal = Cry_HsmAesEcbDecryptUpdate(config, input, inputLength, output, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesEcbDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
extern void SampleCode_LoadPlainKey (HsmCom_KeyAddr KeyAddr,const HsmAes_Block *keyPtr,uint32 KeyLength);

void TestHsm_aes_ecb_reference(void)
{
    uint32 length = sizeof(TEST_CONST_ECB_CIPH);

    SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,TEST_CONST_KEY,16);

    /*  ECB ENCRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nECB encryption: len = %d bytes\n", length);
    EcbEncryptWithRamKey(TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_A, length);
    TEST_COMPARE(TEST_HSM_BUF_TEMP_A, TEST_CONST_ECB_CIPH, length / 4)
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Encryption Plain text : \n");
    TEST_PRINT128(TEST_CONST_PLAIN);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Received Cipher Text : \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_A);
    TEST_PRINTF("\n");


    /*  ECB DECRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nECB decryption: len = %d bytes\n", length);
    EcbDecryptWithRamKey(TEST_CONST_ECB_CIPH, TEST_HSM_BUF_TEMP_A, length);
    TEST_COMPARE(TEST_HSM_BUF_TEMP_A, TEST_CONST_PLAIN, length / 4)
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Cipher text : \n");
    TEST_PRINT128(TEST_CONST_ECB_CIPH);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Received Plain Text : \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_A);
    TEST_PRINTF("\n");
}
void TestHsm_aes_ecb_reference_FlashKey(void)
{
    uint32 length = sizeof(TEST_CONST_ECB_CIPH);

    const Cry_HsmAesEcbEncryptConfigType* config = &Cry_kHsmAesEcbEncryptConfig;
    uint32 inputLength = length;
    uint32 outputLength = inputLength;
    Csm_ReturnType retVal;

#if 1
    retVal = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

    retVal = Cry_HsmAesEcbEncryptUpdate(config, TEST_CONST_PLAIN, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesEcbEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

    /*  ECB ENCRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nECB encryption: len = %d bytes\n", length);
    /*EcbEncryptWithRamKey(TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_A, length);*/
    TEST_COMPARE(TEST_HSM_BUF_TEMP_A, TEST_CONST_ECB_CIPH, length / 4)
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Encryption Plain text : \n");
    TEST_PRINT128(TEST_CONST_PLAIN);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Received Cipher Text : \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_A);
    TEST_PRINTF("\n");
#endif
#if 0
    /*Pass invalid key*/
    retVal = Cry_HsmAesEcbEncryptStart(config, KEY_MAC_GENERATE);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

    retVal = Cry_HsmAesEcbEncryptUpdate(config, TEST_CONST_PLAIN, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesEcbEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

    /*  ECB ENCRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nECB encryption: len = %d bytes\n", length);
    /*EcbEncryptWithRamKey(TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_A, length);*/
    TEST_COMPARE(TEST_HSM_BUF_TEMP_A, TEST_CONST_ECB_CIPH, length / 4)
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Encryption Plain text : \n");
    TEST_PRINT128(TEST_CONST_PLAIN);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Received Cipher Text : \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_A);
    TEST_PRINTF("\n");

    /*Pass invalid key again*/
    retVal = Cry_HsmAesEcbEncryptStart(config, KEY_MAC_GENERATE);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

    retVal = Cry_HsmAesEcbEncryptUpdate(config, TEST_CONST_PLAIN, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesEcbEncryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

    /*  ECB ENCRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nECB encryption: len = %d bytes\n", length);
    /*EcbEncryptWithRamKey(TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_A, length);*/
    TEST_COMPARE(TEST_HSM_BUF_TEMP_A, TEST_CONST_ECB_CIPH, length / 4)
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Encryption Plain text : \n");
    TEST_PRINT128(TEST_CONST_PLAIN);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Received Cipher Text : \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_A);
    TEST_PRINTF("\n");
#endif
#if 1
    retVal = Cry_HsmAesEcbDecryptStart(config, KEY_ENCRYPTION);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
    retVal = Cry_HsmAesEcbDecryptUpdate(config, TEST_CONST_ECB_CIPH, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesEcbDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

    /*  ECB DECRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nECB decryption: len = %d bytes\n", length);
   /* EcbDecryptWithRamKey(TEST_CONST_ECB_CIPH, TEST_HSM_BUF_TEMP_A, length);*/
    TEST_COMPARE(TEST_HSM_BUF_TEMP_A, TEST_CONST_PLAIN, length / 4)
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Cipher text : \n");
    TEST_PRINT128(TEST_CONST_ECB_CIPH);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Received Plain Text : \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_A);
    TEST_PRINTF("\n");

#if 0
    /*Pass invalid key*/
    retVal = Cry_HsmAesEcbDecryptStart(config, KEY_MAC_GENERATE);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
    retVal = Cry_HsmAesEcbDecryptUpdate(config, TEST_CONST_ECB_CIPH, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif
    TEST_VALIDATE(outputLength == inputLength)

    retVal = Cry_HsmAesEcbDecryptFinish(config, NULL_PTR, NULL_PTR);
    TEST_VALIDATE(retVal == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesEcbDecryptMainFunction, &g_TestHsm_ecb.callbackSet);
#endif

    /*  ECB DECRYPTION TEST WITH REFERENCE DATA */
    TEST_PRINTF("\nECB decryption: len = %d bytes\n", length);
   /* EcbDecryptWithRamKey(TEST_CONST_ECB_CIPH, TEST_HSM_BUF_TEMP_A, length);*/
    TEST_COMPARE(TEST_HSM_BUF_TEMP_A, TEST_CONST_PLAIN, length / 4)
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Cipher text : \n");
    TEST_PRINT128(TEST_CONST_ECB_CIPH);
    TEST_PRINTF("\n");
    TEST_PRINTF("Key used : \n");
    TEST_PRINT128(TEST_CONST_KEY);
    TEST_PRINTF("\n");
    TEST_PRINTF("ECB Received Plain Text : \n");
    TEST_PRINT128(TEST_HSM_BUF_TEMP_A);
    TEST_PRINTF("\n");
#endif
#endif
}

/*************************************************************************************//**
 * Execution of EBC test suite
*//**************************************************************************************/
void TestHsm_aes_ecb(void)
{
    TestHsm_aes_ecb_reference();
}
#if SHE_TESTCANCEL
void TestHsm_CancelCommand(void)
{
    TestHsm_CryCancel();
}

void TestHsm_CryCancel()
{
    const Cry_HsmAesEcbEncryptConfigType* config = &Cry_kHsmAesEcbEncryptConfig;
    Csm_ReturnType retVal;

    uint32 inputLength = sizeof(TEST_CONST_ECB_CIPH);
    uint32 outputLength = inputLength;

    CancelRequired = 1;

    SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,TEST_CONST_KEY,16);

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
    retVal = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPT_RAM_KEY);
    TEST_VALIDATE(retVal == CSM_E_OK)

    Gpt_EnableNotification(Gptch_CancelCommand);
    Gpt_StartTimer(Gptch_CancelCommand, 200);

    retVal = Cry_HsmAesEcbEncryptUpdate(config, TEST_CONST_PLAIN, inputLength, (uint8 *)TEST_HSM_BUF_TEMP_A, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_NOT_OK)

    Gpt_StopTimer(Gptch_CancelCommand);
    retVal = Cry_HsmAesEcbEncryptFinish(config,(uint8 *) TEST_HSM_BUF_TEMP_A, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)

#else

    retVal = Cry_HsmAesEcbEncryptStart(config, (const Csm_SymKeyType *)KEY_ENCRYPT_RAM_KEY);
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

    retVal = Cry_HsmAesEcbEncryptUpdate(config, TEST_CONST_PLAIN, inputLength,(uint8 *) TEST_HSM_BUF_TEMP_A, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
    Cry_HsmSheCancel();
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

    retVal = Cry_HsmAesEcbEncryptFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_A, &outputLength);
    TEST_VALIDATE(retVal == CSM_E_OK)
    TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

#endif

}
#endif

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymBlockEncryptCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
    {
        g_TestHsm_ecb.callbackSet = 1;
    }
    else
    {
        g_TestHsm_ecb.callbackSet = 2;

#ifndef ITF
        TEST_PRINTF("ECB function failed in mainloop with ret value %d \n ", result);
#endif
    }

#if ITF
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF

    switch(Cry_PrimStatusAsync[CRY_HSM_SYM_ECB_ENCRYPT])
    {
      case ASYNC_STATE_START:
      {
         EcbEncCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
          EcbEncCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
          EcbEncCallBackFinishResult = result;
         break;
      }
      default:
      {
            break;
      }
    }
    switch(Cry_PrimStatusAsync[CRY_HSM_SYM_ECB_DECRYPT])
    {
      case ASYNC_STATE_START:
      {
         EcbDecCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
          EcbDecCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
          EcbDecCallBackFinishResult = result;
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
void Csm_SymBlockEncryptServiceFinishNotification(void)
{
#if ITF
    EcbEncFinishNotify =1;
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymBlockDecryptCallbackNotification(Csm_ReturnType result)
{
    Csm_SymBlockEncryptCallbackNotification(result);
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_SymBlockDecryptServiceFinishNotification(void)
{
#if ITF
    EcbDecFinishNotify =1;
#else
    Csm_SymBlockEncryptServiceFinishNotification();
#endif
}

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif


