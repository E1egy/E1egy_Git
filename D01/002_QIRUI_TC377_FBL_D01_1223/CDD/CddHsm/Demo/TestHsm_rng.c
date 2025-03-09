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
#include <string.h>
#include "TestHsm.h"
#include "McalLib.h"

#if ITF
#include "Det.h"
#include "BswM.h"
#include "Cry_Hsm_priv.h"

#define RNG_BUFFER_CHECK(bytecount)                \
{                                                  \
    dummyptr =(uint8 *)&TEST_HSM_BUF_TEMP_A;       \
    ErrorCheck = 0;                                \
    for(i_test=0; i_test<bytecount; i_test++)      \
    {                                              \
        if (*dummyptr != 0xFF)                     \
        {                                          \
            ErrorCheck = 1;                        \
            break;                                 \
        }                                          \
        dummyptr++;                                \
    }                                              \
    if(bytecount != 16)                            \
    {                                              \
        dummyptr =(uint8 *)&TEST_HSM_BUF_TEMP_A;   \
        for(i_test=0; i_test<bytecount; i_test++)  \
        {                                          \
            dummyptr++;                            \
        }                                          \
        for(i_test=bytecount; i_test<16; i_test++) \
        {                                          \
            if (*dummyptr != 0xFF)                 \
            {                                      \
                ErrorCheck = 0;                    \
                break;                             \
            }                                      \
            dummyptr++;                            \
        }                                          \
    }                                              \
}
#endif

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"

HsmCom_Error TestApi_randomSetSeed(const void *seed);

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
struct
{
    volatile uint8 callbackSet;
} g_TestHsm_rng =
{
    .callbackSet = 0
};


#if ITF
typedef enum{
SEEDINITSTART_CRYHSM_UNINT,
SEEDINITUPDATE_CRYHSM_NULLCONFIG,
SEEDINIT_UPDATE_SERVICE_NOT_STARTED,
SEEDINIT_FINISH_SERVICE_NOT_STARTED,
SEEDINIT_START_UPDATE_FINISH_SYNC,
SEEDINIT_START_UPDATE_FINISH_TILLDELAY,
SEEDINIT_START_UPDATE_FINISH_AFTERDELAY,
SEEDEXTENDSTART_UNINT,
SEEDEXTENDSTART_SEEDNOTINITIALIZED,
SEEDEXTENDUPDATE_NULLCONFIG,
SEEDEXTENDUPDATE_NULLSEEDPTR,
SEEDEXTENDUPDATE_SERVICENOTSTARTED,
SEEDEXTENDFINISH_SERVICENOTSTARTED,
SEEDEXTEND_VALIDIP,
SEEDEXTEND_LESSTIMEOUT_TILLDELAY,
SEEDEXTEND_LESSTIMEOUT_AFTERDELAY,
RNGGEN_NULLCONFIG,
RNGGEN_NULLRESULTPTR,
RNGGEN_CRYHSM_UNINIT,
RNGGEN_SEEDUNINIT,
RNGGEN_LENGTH20,
RNGGEN_LENGTH10,
RNGGEN_TILLDELAY,
RNGGEN_AFTERDELAY,
TRUERANDOM_NULLCONFIG,
TRUERANDOM_NULLRESULTPTR,
TRUERANDOM_CRYHSM_UNINIT,
TRUERANOM_SEEDUNIT,
TRUERANDOM_LENGTH20,
TRUERANDOM_LENGTH16,
TRUERANDOM_LESSCONFIG_TILLDELAY,
TRUERANDOM_LESSCONFIG_AFTERDELAY,
TRUERND_ENTROPY_EXAHAUSTION,
CRY_RND_INIT_CANCEL,
CRY_RNG_EXTEND_CANCEL,
CRY_RND_CANCEL,
CRY_TRNG_CANCEL,
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
SEEDINIT_START_UPDATE_FINISH_ASYNC,
SEEDINIT_START_UPDATE_FINISH_ASYNCTILLDELAY,
SEEDINIT_START_UPDATE_FINISH_ASYNCAFTERDELAY,
SEEDEXTEND_ASYNC,
SEEDEXTEND_LESSTIMEOUT_ASYNCTILLDELAY,
SEEDEXTEND_LESSTIMEOUT_ASYNCAFTERDELAY,
RNGGEN_LENGTH10_ASYNC,
RNGGEN_TILLDELAY_ASYNC,
RNGGEN_AFTERDELAY_ASYNC,
TRUERANDOM_LENGHT16_ASYNC,
TRUERANDOM_LESSCONFIG_TILLDELAY_ASYNC,
TRUERANDOM_LESSCONFIG_AFTERDELAY_ASYNC,
CRY_RND_INIT_CANCEL_ASYNC,
CRY_RNG_EXTEND_CANCEL_ASYNC,
CRY_RND_CANCEL_ASYNC,
CRY_TRNG_CANCEL_ASYNC,
#endif
CRY_RNG_IDLE
}Cry_RNG_TestCase;

Cry_RNG_TestCase CRY_RNG_TC = CRY_RNG_IDLE;

Csm_ReturnType error;
Csm_ReturnType error1;
Csm_ReturnType error2;
Csm_ReturnType error3;
Csm_ReturnType error4;
Csm_ReturnType error5;
Csm_ReturnType error6;
Cry_PrimStatusVal SeedInitStatus;
Csm_ReturnType RngCallBackStartResult;
Csm_ReturnType RngCallBackUpdateResult;
Csm_ReturnType RngCallBackUpdateResult1;
Csm_ReturnType RngCallBackFinishResult;
Csm_ReturnType RngCallBackFinishResult1;

uint8 RngFinishNotify =0;
uint8 ErrorCheck =0;

uint8 i_test =0;
uint8 Count =0;
uint8* dummyptr;
#endif

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
HsmCom_Error TestApi_randomSetSeed(const void *seed)
{
    UNUSED_PARAMETER(seed);
    return HSMCOM_ERC_BUSY;
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_RandomSeedCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
    {
        g_TestHsm_rng.callbackSet = 1;
    }
    else
    {
#if ITF
        g_TestHsm_rng.callbackSet = 2;
#else
        g_TestHsm_rng.callbackSet = 2;
        TEST_PRINTF("\n failed in mainfunc with err code %d \n", result);
#endif
    }

#if ITF
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
     switch(Cry_PrimStatusAsync[CRY_HSM_RANDOM_SEED_INIT])
    {
      case ASYNC_STATE_START:
      {
         RngCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
         RngCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
         RngCallBackFinishResult = result;
         break;
      }
      default:
      {
            break;
      }
    }

    switch(Cry_PrimStatusAsync[CRY_HSM_RANDOM_SEED_EXTEND])
    {
      case ASYNC_STATE_START:
      {
         RngCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
         RngCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
         RngCallBackFinishResult = result;
         break;
      }
      default:
      {
            break;
      }

    }
    switch(Cry_PrimStatusAsync[CRY_HSM_RANDOM_GENERATE])
    {
      case ASYNC_STATE_FINISH:
      {
         RngCallBackFinishResult = result;
         break;
      }

      default:
      {
            break;
      }
    }
    switch(Cry_PrimStatusAsync[CRY_HSM_TRUE_RANDOM_GENERATE])
    {
      case ASYNC_STATE_FINISH:
      {
         RngCallBackFinishResult = result;
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
void Csm_RandomSeedServiceFinishNotification(void)
{
#if ITF
    RngFinishNotify = 1;
#endif

}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_RandomGenerateCallbackNotification(Csm_ReturnType result)
{
    Csm_RandomSeedCallbackNotification(result);
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_RandomGenerateServiceFinishNotification(void)
{
    Csm_RandomSeedServiceFinishNotification();
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void RandomSeedInit(void)
{
    Csm_ReturnType error;
    const Cry_HsmRandomSeedInitConfigType* config = &Cry_kHsmRandomSeedInitConfig;

    error = Cry_HsmRandomSeedInitStart(config);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    error = Cry_HsmRandomSeedInitUpdate(config, NULL_PTR, 0);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    error = Cry_HsmRandomSeedInitFinish(config);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
#endif
}
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void RandomSeedInitFailTimeOut(void)
{
    const Cry_HsmRandomSeedInitConfigType  Cry_kHsmRandomSeedInitConfigFailTimeout =
                {.TimeOut =   {.TimeoutStart = 0,
                        .TimeoutUpdateConst = 3,
                        .TimeoutUpdateperByte = 0,
                        .TimeoutFinish = 3 }  };

    Csm_ReturnType error;
    const Cry_HsmRandomSeedInitConfigType* config = &Cry_kHsmRandomSeedInitConfigFailTimeout;

    error = Cry_HsmRandomSeedInitStart(config);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    error = Cry_HsmRandomSeedInitUpdate(config, NULL_PTR, 0);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    error = Cry_HsmRandomSeedInitFinish(config);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void RandomSeedExtend(void)
{
    Csm_ReturnType error;
    const Cry_HsmRandomSeedExtendConfigType* config = &Cry_kHsmRandomSeedExtendConfig;

    error = Cry_HsmRandomSeedExtendStart(config);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);
#endif

    error = Cry_HsmRandomSeedExtendUpdate(config, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);
#endif

    error = Cry_HsmRandomSeedExtendFinish(config);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void TestHsm_random_generate(void)
{
    Csm_ReturnType error;
    /*HsmCom_Error comErr;*/
    const Cry_HsmRandomGenerateConfigType* config = &Cry_kHsmRandomGenerateConfig;

    memset(TEST_HSM_BUF_TEMP_A, 0xAA, 16);
    /*TEST_VALIDATE(p != NULL_PTR)*/

     TEST_PRINTF("Test random generate #1 -------------------------------\n");
    error = Cry_HsmRandomGenerate(config, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
    TEST_VALIDATE(error == CSM_E_OK)

	#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
#endif

    TEST_PRINTF("\n");
    TEST_PRINTF("RANDOMNUM  "); TEST_PRINTHEX(TEST_HSM_BUF_TEMP_A, 16);

   memset(TEST_HSM_BUF_TEMP_A, 0xAA, 16);
    /*TEST_VALIDATE(p != NULL_PTR)*/
    memset(TEST_HSM_BUF_TEMP_B, 0xAA, 16);
    /*TEST_VALIDATE(p != NULL_PTR)*/
    memcpy(TEST_HSM_BUF_TEMP_B, TEST_CONST_RANDOM_NUMBER, 8);
    /*TEST_VALIDATE(p != NULL_PTR)*/

    TEST_PRINTF("Test random generate #2 -------------------------------\n");
    error = Cry_HsmRandomGenerate(config, (uint8*)TEST_HSM_BUF_TEMP_A, 8);
    TEST_VALIDATE(error == CSM_E_OK)
	#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    TEST_PRINTF("\n");
    TEST_PRINTF("RANDOMNUM  "); TEST_PRINTHEX(TEST_HSM_BUF_TEMP_A, 8);
}

Csm_ReturnType GenerateTrngSeed(void)
{
    Csm_ReturnType error;
    const Cry_HsmRandomGenerateConfigType* config = &Cry_kHsmRandomGenerateConfig;
    const Cry_HsmTRNGConfigType* configTrng = &Cry_kHsmTRNGConfig;

    RandomSeedInit();
    RandomSeedExtend();

    error = Cry_HsmRandomGenerate(config, (uint8*)TrngSeed, 16);
    //error = Cry_HsmTrueRandomGenerate(configTrng, (uint8*)TrngSeed, 16);

    return error;
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void TestHsm_random_init(void)
{
    Csm_ReturnType error;
    HsmAes_Block *randomNumber = (HsmAes_Block*)TEST_HSM_BUF_TEMP_A;
    HsmAes_Block *truerandomNumber = (HsmAes_Block *)TEST_HSM_BUF_TEMP_B;
    const Cry_HsmRandomGenerateConfigType* config = &Cry_kHsmRandomGenerateConfig;
    const Cry_HsmTRNGConfigType* configTrng = &Cry_kHsmTRNGConfig;

    TEST_PRINTF("\n");
    TEST_PRINTF("Test random seed init ---------------------------------\n");
    RandomSeedInit();

    TEST_PRINTF("\n");
    TEST_PRINTF("Test random seed extend  ------------------------------\n");
    RandomSeedExtend();

    TEST_PRINTF("\n");
    TEST_PRINTF("Generate 3 random numbers------------------------------\n");

#if 0
    TEST_PRINTF("Generate random number with length 16--------------\n");
    error = Cry_HsmRandomGenerate(config, (uint8*)randomNumber, 16);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    TEST_PRINTF("\n");
    TEST_PRINTF("RANDOMNUM  "); TEST_PRINTHEX(randomNumber, 16);

    TEST_PRINTF("\n");
    TEST_PRINTF("Generate random number with length 8--------------\n");
    error = Cry_HsmRandomGenerate(config, (uint8*)randomNumber, 8);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    TEST_PRINTF("\n");
    TEST_PRINTF("RANDOMNUM  "); TEST_PRINTHEX(randomNumber, 8);

    TEST_PRINTF("\n");
    TEST_PRINTF("Generate True random number with length 4--------------\n");
    error = Cry_HsmTrueRandomGenerate(configTrng, (uint8*)truerandomNumber, 4);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmTrueRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    TEST_PRINTF("\n");
    TEST_PRINTF("TRUE RANDOMNUM  "); TEST_PRINTHEX(truerandomNumber, 4);

    TEST_PRINTF("\n");
    TEST_PRINTF("Generate True random number with length 08--------------\n");
    error = Cry_HsmTrueRandomGenerate(configTrng, (uint8*)truerandomNumber, 8);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmTrueRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    TEST_PRINTF("\n");
    TEST_PRINTF("TRUE RANDOMNUM  "); TEST_PRINTHEX(truerandomNumber, 8);

    TEST_PRINTF("\n");
    TEST_PRINTF("Generate True random number with length 12--------------\n");
    error = Cry_HsmTrueRandomGenerate(configTrng, (uint8*)truerandomNumber, 12);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmTrueRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    TEST_PRINTF("\n");
    TEST_PRINTF("TRUE RANDOMNUM  "); TEST_PRINTHEX(truerandomNumber, 12);

    TEST_PRINTF("\n");
    TEST_PRINTF("Generate True random number with length 16--------------\n");
    error = Cry_HsmTrueRandomGenerate(configTrng, (uint8*)truerandomNumber, 16);
    TEST_VALIDATE(error == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmTrueRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
#endif
    TEST_PRINTF("\n");
    TEST_PRINTF("TRUE RANDOMNUM  "); TEST_PRINTHEX(truerandomNumber, 16);
#else
    TEST_PRINTF("\n");
    TEST_PRINTF("Generate True random number with length 16--------------\n");
    error = Cry_HsmTrueRandomGenerate(configTrng, (uint8*)TrngSeed, 16);
    TEST_VALIDATE(error == CSM_E_OK)
    TEST_PRINTF("\n");
    TEST_PRINTF("TRUE RANDOMNUM  "); TEST_PRINTHEX(TrngSeed, 16);
#endif
}
#if ITF
void Parameter_Init()
{
     error  =CSM_E_ENTROPY_EXHAUSTION;
     error1 =CSM_E_ENTROPY_EXHAUSTION;
     error2 =CSM_E_ENTROPY_EXHAUSTION;
     error3 =CSM_E_ENTROPY_EXHAUSTION;
     ErrorCheck =0;
     DetErrorId = 99;
     DetApiId = 99;
     DetModuleId = 99;
     BswMErrorId =99;
     i_test=0;
     Count = 0;
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
     g_TestHsm_rng.callbackSet = 0;
     RngCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
     RngCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
     RngCallBackUpdateResult1 = CSM_E_ENTROPY_EXHAUSTION;
     RngCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
     RngCallBackFinishResult1 =  CSM_E_ENTROPY_EXHAUSTION;
     RngFinishNotify =0;
#endif
}
void ITF_RandomNumberGenerator()
{
    Cry_HsmRandomSeedInitConfigType  Cry_kHsmRandomSeedInitConfigDelay ;
    Cry_HsmRandomSeedExtendConfigType Cry_kHsmRandomSeedExtendConfigDelay ;
    Cry_HsmRandomGenerateConfigType  Cry_kHsmAesRNGConfigDelay ;
    Cry_HsmTRNGConfigType Cry_kHsmAesTRNGConfigDelay;

    const Cry_HsmRandomSeedInitConfigType* SeedInitconfig;
    const Cry_HsmRandomSeedExtendConfigType* SeedExtendconfig;
    const Cry_HsmRandomGenerateConfigType* Rngconfig;
    const Cry_HsmTRNGConfigType* TRngconfig;

    const Cry_HsmRandomSeedInitConfigType* SeedInitconfig1;
    const Cry_HsmRandomSeedExtendConfigType* SeedExtendconfig1;
    const Cry_HsmRandomGenerateConfigType* Rngconfig1;
    const Cry_HsmTRNGConfigType* TRngconfig1;

    Cry_kHsmRandomSeedInitConfigDelay.TimeOut.TimeoutStart  = 0U;
    Cry_kHsmRandomSeedInitConfigDelay.TimeOut.TimeoutUpdateConst = 0U;
    Cry_kHsmRandomSeedInitConfigDelay.TimeOut.TimeoutUpdateperByte = 0U;
    Cry_kHsmRandomSeedInitConfigDelay.TimeOut.TimeoutFinish =0U ;

    Cry_kHsmRandomSeedExtendConfigDelay.TimeOut.TimeoutStart  = 0U;
    Cry_kHsmRandomSeedExtendConfigDelay.TimeOut.TimeoutUpdateConst = 0U;
    Cry_kHsmRandomSeedExtendConfigDelay.TimeOut.TimeoutUpdateperByte = 0U;
    Cry_kHsmRandomSeedExtendConfigDelay.TimeOut.TimeoutFinish =0U ;

    Cry_kHsmAesRNGConfigDelay.TimeOut.TimeoutStart  = 0U;
    Cry_kHsmAesRNGConfigDelay.TimeOut.TimeoutUpdateConst = 0U;
    Cry_kHsmAesRNGConfigDelay.TimeOut.TimeoutUpdateperByte = 0U;
    Cry_kHsmAesRNGConfigDelay.TimeOut.TimeoutFinish =0U ;

    Cry_kHsmAesTRNGConfigDelay.TimeOut.TimeoutStart  = 0U;
    Cry_kHsmAesTRNGConfigDelay.TimeOut.TimeoutUpdateConst = 0U;
    Cry_kHsmAesTRNGConfigDelay.TimeOut.TimeoutUpdateperByte = 0U;
    Cry_kHsmAesTRNGConfigDelay.TimeOut.TimeoutFinish =0U ;



    SeedInitconfig = &Cry_kHsmRandomSeedInitConfig;
    SeedExtendconfig = &Cry_kHsmRandomSeedExtendConfig;
    Rngconfig = &Cry_kHsmRandomGenerateConfig;
    TRngconfig = &Cry_kHsmTRNGConfig;

    SeedInitconfig1 = &Cry_kHsmRandomSeedInitConfigDelay;
    SeedExtendconfig1 = &Cry_kHsmRandomSeedExtendConfigDelay;
    Rngconfig1  =  &Cry_kHsmAesRNGConfigDelay;
    TRngconfig1 = &Cry_kHsmAesTRNGConfigDelay;

    switch(CRY_RNG_TC)
    {
        /*CRY+ Test case 77*/
        case SEEDINITSTART_CRYHSM_UNINT:
        {
            Parameter_Init();
            Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
            error = Cry_HsmRandomSeedInitStart(SeedInitconfig);
            if((DetErrorId ==CRY_HSM_E_UNINIT)  && (DetApiId ==CRY_HSM_SID_RND_SEED_INIT_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 78*/
        case SEEDINITUPDATE_CRYHSM_NULLCONFIG:
        {
            Parameter_Init();
            error = Cry_HsmRandomSeedInitUpdate(NULL_PTR, NULL_PTR, 0);
            if((DetErrorId ==CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_RND_SEED_INIT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 79*/
        case SEEDINIT_UPDATE_SERVICE_NOT_STARTED:
        {
            Parameter_Init();
            Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT] = CRY_HSM_PRIM_NOT_STARTED;
            error = Cry_HsmRandomSeedInitUpdate(SeedInitconfig, NULL_PTR, 0);
            if((DetErrorId ==CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId ==CRY_HSM_SID_RND_SEED_INIT_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 80*/
        case SEEDINIT_FINISH_SERVICE_NOT_STARTED:
        {
            Parameter_Init();
            Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT] = CRY_HSM_PRIM_NOT_STARTED;
            error = Cry_HsmRandomSeedInitFinish(SeedInitconfig);
            if((DetErrorId ==CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId ==CRY_HSM_SID_RND_SEED_INIT_FINISH) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 81*/
        case SEEDINIT_START_UPDATE_FINISH_SYNC:
        {
            Parameter_Init();
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            error1 = Cry_HsmRandomSeedInitStart(SeedInitconfig);
            error2 = Cry_HsmRandomSeedInitUpdate(SeedInitconfig, NULL_PTR, 0);
            error3 = Cry_HsmRandomSeedInitFinish(SeedInitconfig);

            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 82*/
        case SEEDINIT_START_UPDATE_FINISH_TILLDELAY:
        {
            Parameter_Init();
            error1 = Cry_HsmRandomSeedInitStart(SeedInitconfig);
            error2 = Cry_HsmRandomSeedInitUpdate(SeedInitconfig1, NULL_PTR, 0);
            error3 = Cry_HsmRandomSeedInitFinish(SeedInitconfig);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
             break;
        }
        case SEEDINIT_START_UPDATE_FINISH_AFTERDELAY:
        {
            error3 = CSM_E_ENTROPY_EXHAUSTION;
            error3 = Cry_HsmRandomSeedInitFinish(SeedInitconfig);
            CRY_RNG_TC=CRY_RNG_IDLE;
             break;
        }

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
        /*CRY+ Test case 83*/
        case SEEDINIT_START_UPDATE_FINISH_ASYNC:
        {
            Parameter_Init();

            error1 = Cry_HsmRandomSeedInitStart(SeedInitconfig);
            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
            error2 = Cry_HsmRandomSeedInitUpdate(SeedInitconfig, NULL_PTR, 0);
            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
            error3 = Cry_HsmRandomSeedInitFinish(SeedInitconfig);
            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 84*/
        case SEEDINIT_START_UPDATE_FINISH_ASYNCTILLDELAY:
        {
            Parameter_Init();
            error1 = Cry_HsmRandomSeedInitStart(SeedInitconfig);
            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
            error2 = Cry_HsmRandomSeedInitUpdate(SeedInitconfig1, NULL_PTR, 0);
            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
            error3 = Cry_HsmRandomSeedInitFinish(SeedInitconfig);
            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        case SEEDINIT_START_UPDATE_FINISH_ASYNCAFTERDELAY:
        {
            Parameter_Init();
            error = Cry_HsmRandomSeedInitFinish(SeedInitconfig);
            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
#endif
        /*CRY+ Test case 85*/
        case SEEDEXTENDSTART_UNINT:
        {
            Parameter_Init();
            Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
            error = Cry_HsmRandomSeedExtendStart(SeedExtendconfig);
            if((DetErrorId == CRY_HSM_E_UNINIT)  && (DetApiId ==CRY_HSM_SID_RND_SEED_EXTEND_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 86*/
        case SEEDEXTENDSTART_SEEDNOTINITIALIZED:
        {
            Parameter_Init();
            SeedInitStatus = Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT];
            Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT] = CRY_HSM_PRIM_NOT_STARTED;

            error = Cry_HsmRandomSeedExtendStart(SeedExtendconfig);
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId ==CRY_HSM_SID_RND_SEED_EXTEND_START) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT] = SeedInitStatus;
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 87*/
        case SEEDEXTENDUPDATE_NULLCONFIG :
        {
            Parameter_Init();
            error = Cry_HsmRandomSeedExtendUpdate(NULL_PTR, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_RND_SEED_EXTEND_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 88*/
        case SEEDEXTENDUPDATE_NULLSEEDPTR:
        {
            Parameter_Init();
            error = Cry_HsmRandomSeedExtendUpdate(SeedExtendconfig, NULL_PTR, sizeof(TEST_CONST_RANDOM_ENTROPY));
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_RND_SEED_EXTEND_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 89*/
        case SEEDEXTENDUPDATE_SERVICENOTSTARTED:
        {
            Parameter_Init();
            Cry_PrimStatus[CRY_HSM_RANDOM_SEED_EXTEND] = CRY_HSM_PRIM_NOT_STARTED;
            error =  Cry_HsmRandomSeedExtendUpdate(SeedExtendconfig, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId ==CRY_HSM_SID_RND_SEED_EXTEND_UPDATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 90*/
        case SEEDEXTENDFINISH_SERVICENOTSTARTED:
        {
            Parameter_Init();
            Cry_PrimStatus[CRY_HSM_RANDOM_SEED_EXTEND] = CRY_HSM_PRIM_NOT_STARTED;
            error = Cry_HsmRandomSeedExtendFinish(SeedExtendconfig);
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId ==CRY_HSM_SID_RND_SEED_EXTEND_FINISH) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 91*/
        case SEEDEXTEND_VALIDIP :
        {
            Parameter_Init();
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            error1 = Cry_HsmRandomSeedExtendStart(SeedExtendconfig);
            error2 = Cry_HsmRandomSeedExtendUpdate(SeedExtendconfig, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));
            error3 = Cry_HsmRandomSeedExtendFinish(SeedExtendconfig);
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 92*/
        case SEEDEXTEND_LESSTIMEOUT_TILLDELAY :
        {
            Parameter_Init();
            error1 = Cry_HsmRandomSeedExtendStart(SeedExtendconfig);
            error2 = Cry_HsmRandomSeedExtendUpdate(SeedExtendconfig1, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));
            error3 = Cry_HsmRandomSeedExtendFinish(SeedExtendconfig);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;

        }
        case SEEDEXTEND_LESSTIMEOUT_AFTERDELAY :
        {
            Parameter_Init();
            error3 = Cry_HsmRandomSeedExtendFinish(SeedExtendconfig);
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
        /*CRY+ Test case 93*/
        case SEEDEXTEND_ASYNC :
        {
            Parameter_Init();
            error1 = Cry_HsmRandomSeedExtendStart(SeedExtendconfig);
            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);
            error2 = Cry_HsmRandomSeedExtendUpdate(SeedExtendconfig, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));
            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);
            error3 = Cry_HsmRandomSeedExtendFinish(SeedExtendconfig);
            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 94*/
        case SEEDEXTEND_LESSTIMEOUT_ASYNCTILLDELAY:
        {
            Parameter_Init();
            error1 = Cry_HsmRandomSeedExtendStart(SeedExtendconfig);
            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);
            error2 = Cry_HsmRandomSeedExtendUpdate(SeedExtendconfig1, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));
            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);
            error3 = Cry_HsmRandomSeedExtendFinish(SeedExtendconfig);
            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        case SEEDEXTEND_LESSTIMEOUT_ASYNCAFTERDELAY:
        {
            Parameter_Init();
            error3 = Cry_HsmRandomSeedExtendFinish(SeedExtendconfig);
            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
#endif
        /*CRY+ Test case 95*/
        case RNGGEN_NULLCONFIG :
        {
            Parameter_Init();
            error = Cry_HsmRandomGenerate(NULL_PTR, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId ==CRY_HSM_SID_RND_GENERATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 96*/
        case RNGGEN_NULLRESULTPTR :
        {
            Parameter_Init();
            error = Cry_HsmRandomGenerate(Rngconfig, NULL_PTR, 16);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)   && (DetApiId ==CRY_HSM_SID_RND_GENERATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 97*/
        case RNGGEN_CRYHSM_UNINIT :
        {
            Parameter_Init();
            Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
            error = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            if((DetErrorId == CRY_HSM_E_UNINIT)  && (DetApiId ==CRY_HSM_SID_RND_GENERATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 98*/
        case RNGGEN_SEEDUNINIT :
        {
            Parameter_Init();
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            SeedInitStatus = Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT];
            Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT]=CRY_HSM_PRIM_NOT_STARTED;
            error = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            if((DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED)  && (DetApiId == CRY_HSM_SID_RND_GENERATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT] = SeedInitStatus;
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 99*/
        case RNGGEN_LENGTH20 :
        {
            Parameter_Init();
            error = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 20);
            if((DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID)  && (DetApiId == CRY_HSM_SID_RND_GENERATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 100*/
        case RNGGEN_LENGTH10 :
        {
           Parameter_Init();
           for(i_test=0;i_test<4;i_test++)
           {
                TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
           }
           error1 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_B, 12);
           for(i_test=0;i_test<4;i_test++)
           {
                TEST_HSM_BUF_TEMP_B[i_test]=0xFFFFFFFF;
           }
           error = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 10);
           RNG_BUFFER_CHECK(10)
           /* To check the prob reported by IFX. Prob: RNG is written into the buffer of
              previous call due to cache clean problem */
           for(i_test=0;i_test<4;i_test++)
           {
               if(TEST_HSM_BUF_TEMP_B[i_test] != 0xFFFFFFFF)
               {
                   ErrorCheck = 0;
               }
           }
           CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 101*/
        case RNGGEN_TILLDELAY :
        {
            Parameter_Init();
            error1= Cry_HsmRandomGenerate(Rngconfig1, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            error2 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        case RNGGEN_AFTERDELAY :
        {
            Parameter_Init();
            for(i_test=0;i_test<4;i_test++)
             {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
             }
            error3 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            RNG_BUFFER_CHECK(16)
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
        /*CRY+ Test case 102*/
        case RNGGEN_LENGTH10_ASYNC :
        {
            Parameter_Init();
            for(i_test=0;i_test<4;i_test++)
             {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
             }
            error = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 10);
            TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
            RNG_BUFFER_CHECK(10)
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 103*/
        case RNGGEN_TILLDELAY_ASYNC :
        {
            Parameter_Init();
            error1= Cry_HsmRandomGenerate(Rngconfig1, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            error2 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);

            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        case RNGGEN_AFTERDELAY_ASYNC :
        {
            Parameter_Init();
            for(i_test=0;i_test<4;i_test++)
             {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
             }
            error3 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
            RNG_BUFFER_CHECK(16)
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
#endif
        /*CRY+ Test case 104*/
        case TRUERANDOM_NULLCONFIG :
        {
            Parameter_Init();
            error = Cry_HsmTrueRandomGenerate(NULL_PTR,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId == CRY_HSM_SID_TRUE_RND_GENERATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;

        }
        /*CRY+ Test case 105*/
        case TRUERANDOM_NULLRESULTPTR:
        {
            Parameter_Init();
            error = Cry_HsmTrueRandomGenerate(TRngconfig,NULL_PTR, 16);
            if((DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)  && (DetApiId == CRY_HSM_SID_TRUE_RND_GENERATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 106*/
        case TRUERANDOM_CRYHSM_UNINIT :
        {
            Parameter_Init();
            Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
            error = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            if((DetErrorId == CRY_HSM_E_UNINIT)  && (DetApiId == CRY_HSM_SID_TRUE_RND_GENERATE) && (DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            break;
        }
        /*CRY+ Test case 107*/
        case TRUERANOM_SEEDUNIT :
        {
            Parameter_Init();
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
            SeedInitStatus = Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT];
            Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT]=CRY_HSM_PRIM_NOT_STARTED;
            for(i_test=0;i_test<4;i_test++)
            {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
            }
            error = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            RNG_BUFFER_CHECK(4)
            /* To check the prob reported by IFX. Prob: RNG is written into the buffer of
               previous call due to cache clean problem */
            for(i_test=0;i_test<4;i_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[i_test] != 0xFFFFFFFF)
                {
                    ErrorCheck = 1;
                }
            }
            Cry_PrimStatus[CRY_HSM_RANDOM_SEED_INIT] = SeedInitStatus;
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 108*/
        case TRUERANDOM_LENGTH20 :
        {
            Parameter_Init();
            error = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 20);
            if((DetErrorId == CRY_HSM_E_PARAM_METHOD_INVALID)  && (DetApiId == CRY_HSM_SID_TRUE_RND_GENERATE && DetModuleId ==CSM_MODULE_ID))
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break ;
        }
        /*CRY+ Test case 109*/
        case TRUERANDOM_LENGTH16:
        {
            Parameter_Init();
            for(i_test=0;i_test<4;i_test++)
            {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
            }
            error1 = Cry_HsmTrueRandomGenerate(TRngconfig, (uint8*)TEST_HSM_BUF_TEMP_B, 8);
            for(i_test=0;i_test<4;i_test++)
            {
                 TEST_HSM_BUF_TEMP_B[i_test]=0xFFFFFFFF;
            }
            error = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 4);
            RNG_BUFFER_CHECK(4)
            /* To check the prob reported by IFX. Prob: RNG is written into the buffer of
               previous call due to cache clean problem */
            for(i_test=0;i_test<4;i_test++)
            {
                if(TEST_HSM_BUF_TEMP_B[i_test] != 0xFFFFFFFF)
                {
                    ErrorCheck = 0;
                }
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
            break ;
        }
        /*CRY+ Test case 110*/
        case TRUERANDOM_LESSCONFIG_TILLDELAY :
        {
            Parameter_Init();
            error1 = Cry_HsmTrueRandomGenerate(TRngconfig1,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            error2 = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        case TRUERANDOM_LESSCONFIG_AFTERDELAY :
        {
            Parameter_Init();
            for(i_test=0;i_test<4;i_test++)
             {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
             }
            error3 = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            RNG_BUFFER_CHECK(16)
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 199*/
        case TRUERND_ENTROPY_EXAHAUSTION :
        {
            Parameter_Init();
            for(i_test=0;i_test<4;i_test++)
             {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
             }
            error1 = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            error2 = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 12);
            if(error2 == CSM_E_ENTROPY_EXHAUSTION)
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
        }
        break;
        /*CRY_SC_TC_16*/
        case CRY_RND_INIT_CANCEL:
        {
            Parameter_Init();
            CancelRequired = 1;

            for(i_test=0;i_test<4;i_test++)
            {
                TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
            }

            error1 = Cry_HsmRandomSeedInitStart(SeedInitconfig);

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            error2 = Cry_HsmRandomSeedInitUpdate(SeedInitconfig, NULL_PTR, 0);

            Gpt_StopTimer(Gptch_CancelCommand);

            error3 = Cry_HsmRandomSeedInitUpdate(SeedInitconfig, NULL_PTR, 0);
            error4 = Cry_HsmRandomSeedInitFinish(SeedInitconfig);
            error5 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);

            for(i_test=0;i_test<4;i_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[i_test] != 0xFFFFFFFF)
                {
                    ErrorCheck = 1;

                }
                else
                {
                    ErrorCheck = 0;
                    break;
                }
            }
            if((error1 == CSM_E_OK) && (error2 == CSM_E_NOT_OK) && (error3 == CSM_E_OK)
                &&(error4 == CSM_E_OK) && (error5 == CSM_E_OK) &&(ErrorCheck == 1))
            {
                ErrorCheck = 1;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
        }
        break;
        /*CRY_SC_TC_17*/
        case CRY_RNG_EXTEND_CANCEL :
        {
            Parameter_Init();
            CancelRequired = 1;

            for(i_test=0;i_test<4;i_test++)
            {
                TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
            }

            error1 = Cry_HsmRandomSeedExtendStart(SeedExtendconfig);

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            error2 = Cry_HsmRandomSeedExtendUpdate(SeedExtendconfig, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));

            Gpt_StopTimer(Gptch_CancelCommand);

            error3 = Cry_HsmRandomSeedExtendUpdate(SeedExtendconfig, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));
            error4 = Cry_HsmRandomSeedExtendFinish(SeedExtendconfig);
            error5 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);

            for(i_test=0;i_test<4;i_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[i_test] != 0xFFFFFFFF)
                {
                    ErrorCheck = 1;

                }
                else
                {
                    ErrorCheck = 0;
                    break;
                }
            }
            if((error1 == CSM_E_OK) && (error2 == CSM_E_NOT_OK) && (error3 == CSM_E_OK)
                &&(error4 == CSM_E_OK) && (error5 == CSM_E_OK) &&(ErrorCheck == 1))
            {
                ErrorCheck = 1;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
        }
        break;
        /*CRY_SC_TC_18*/
        case CRY_RND_CANCEL :
        {
            Parameter_Init();
            CancelRequired = 1;

            for(i_test=0;i_test<4;i_test++)
            {
                TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
            }
            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            error1 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);

            Gpt_StopTimer(Gptch_CancelCommand);

            error2 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);

            for(i_test=0;i_test<4;i_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[i_test] != 0xFFFFFFFF)
                {
                    ErrorCheck = 1;
                }
                else
                {
                    ErrorCheck = 0;
                    break;
                }
            }
           if((error1 == CSM_E_NOT_OK)  && (error2 == CSM_E_OK)  &&
                   (ErrorCheck == 1))
           {
               ErrorCheck = 1;
           }
           CRY_RNG_TC=CRY_RNG_IDLE;
        }
        break;
        /*CRY_SC_TC_19*/
        case CRY_TRNG_CANCEL :
        {
            Parameter_Init();
            CancelRequired = 1;
            for(i_test=0;i_test<4;i_test++)
            {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
            }

            Gpt_EnableNotification(Gptch_CancelCommand);
            Gpt_StartTimer(Gptch_CancelCommand, 200);

            error1 = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);

            Gpt_StopTimer(Gptch_CancelCommand);

            error2 = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);

            for(i_test=0;i_test<4;i_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[i_test] != 0xFFFFFFFF)
                {
                    ErrorCheck = 1;
                }
                else
                {
                    ErrorCheck = 0;
                    break;
                }
            }
            if((error1 == CSM_E_NOT_OK)  && (error2 == CSM_E_OK)  &&
                    (ErrorCheck == 1))
            {
                ErrorCheck = 1;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
        }
        break;

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
        /*CRY+ Test case 111*/
        case TRUERANDOM_LENGHT16_ASYNC :
        {
            Parameter_Init();
            for(i_test=0;i_test<4;i_test++)
             {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
             }
            error = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmTrueRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
            RNG_BUFFER_CHECK(16)
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY+ Test case 112*/
        case TRUERANDOM_LESSCONFIG_TILLDELAY_ASYNC :
        {
            Parameter_Init();
            error1 = Cry_HsmTrueRandomGenerate(TRngconfig1,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmTrueRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
            if(BswMErrorId == HSMCOM_ERC_TIMEOUT)
            {
                ErrorCheck = 1;
            }
            else
            {
                ErrorCheck = 0;
            }
            error2 =Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmTrueRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        case TRUERANDOM_LESSCONFIG_AFTERDELAY_ASYNC :
        {
            Parameter_Init();
            for(i_test=0;i_test<4;i_test++)
             {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
             }
            error = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmTrueRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);
            RNG_BUFFER_CHECK(16)
            CRY_RNG_TC=CRY_RNG_IDLE;
            break;
        }
        /*CRY_SC_TC_20*/
        case CRY_RND_INIT_CANCEL_ASYNC :
        {
            Parameter_Init();
            Cry_HsmInitStatus = CRY_HSM_INITIALIZED;

            for(i_test=0;i_test<4;i_test++)
            {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
            }

            error1 = Cry_HsmRandomSeedInitStart(SeedInitconfig);
            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);

            error2 = Cry_HsmRandomSeedInitUpdate(SeedInitconfig, NULL_PTR, 0);
            Cry_HsmSheCancel();

            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);

            RngCallBackUpdateResult1 = RngCallBackUpdateResult;

            error3 = Cry_HsmRandomSeedInitUpdate(SeedInitconfig, NULL_PTR, 0);
            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);

            error4 = Cry_HsmRandomSeedInitFinish(SeedInitconfig);
            TEST_WAIT(&Cry_HsmRandomSeedInitMainFunction, &g_TestHsm_rng.callbackSet);

            error5 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);

            for(i_test=0;i_test<4;i_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[i_test] != 0xFFFFFFFF)
                {
                    ErrorCheck = 1;
                }
                else
                {
                    ErrorCheck = 0;
                    break;
                }
            }

            if((RngCallBackUpdateResult1 == CSM_E_NOT_OK)&&(RngCallBackUpdateResult == CSM_E_OK)
                    && (ErrorCheck == 1))
            {
                ErrorCheck = 1;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
        }
        break;
        /*CRY_SC_TC_21*/
        case CRY_RNG_EXTEND_CANCEL_ASYNC:
        {
            Parameter_Init();

            for(i_test=0;i_test<4;i_test++)
            {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
            }

            error1 = Cry_HsmRandomSeedExtendStart(SeedExtendconfig);
            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);

            error2 = Cry_HsmRandomSeedExtendUpdate(SeedExtendconfig, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));
            Cry_HsmSheCancel();

            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);

            RngCallBackUpdateResult1 = RngCallBackUpdateResult;

            error3 = Cry_HsmRandomSeedExtendUpdate(SeedExtendconfig, TEST_CONST_RANDOM_ENTROPY, sizeof(TEST_CONST_RANDOM_ENTROPY));
            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);

            error4 = Cry_HsmRandomSeedExtendFinish(SeedExtendconfig);
            TEST_WAIT(&Cry_HsmRandomSeedExtendMainFunction, &g_TestHsm_rng.callbackSet);

            error5 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);

            for(i_test=0;i_test<4;i_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[i_test] != 0xFFFFFFFF)
                {
                    ErrorCheck = 1;

                }
                else
                {
                    ErrorCheck = 0;
                    break;
                }
            }

            if((RngCallBackUpdateResult1 == CSM_E_NOT_OK)&&(RngCallBackUpdateResult == CSM_E_OK)
                    && (RngCallBackFinishResult == CSM_E_OK)&& (ErrorCheck == 1))
            {
                ErrorCheck = 1;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
        }
        break;
        /*CRY_SC_TC_22*/
        case CRY_RND_CANCEL_ASYNC :
        {
            Parameter_Init();
             for(i_test=0;i_test<4;i_test++)
             {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
             }
            error1 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            Cry_HsmSheCancel();

            TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);

            RngCallBackFinishResult1 = RngCallBackFinishResult;

            error2 = Cry_HsmRandomGenerate(Rngconfig, (uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);

            for(i_test=0;i_test<4;i_test++)
            {
                if(TEST_HSM_BUF_TEMP_B[i_test] != 0xFFFFFFFF)
                {
                    ErrorCheck = 1;

                }
                else
                {
                    ErrorCheck = 0;
                    break;
                }
            }

            if((RngCallBackFinishResult1 == CSM_E_NOT_OK)&&(RngCallBackFinishResult == CSM_E_OK)
                    && (ErrorCheck == 1))
            {
                ErrorCheck = 1;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
        }
        break;
        /*CRY_SC_TC_23*/
        case CRY_TRNG_CANCEL_ASYNC :
        {
            Parameter_Init();
            for(i_test=0;i_test<4;i_test++)
            {
                 TEST_HSM_BUF_TEMP_A[i_test]=0xFFFFFFFF;
            }
            error1 = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            Cry_HsmSheCancel();
            TEST_WAIT(&Cry_HsmTrueRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);

            RngCallBackFinishResult1 = RngCallBackFinishResult;

            error2 = Cry_HsmTrueRandomGenerate(TRngconfig,(uint8*)TEST_HSM_BUF_TEMP_A, 16);
            TEST_WAIT(&Cry_HsmTrueRandomGenerateMainFunction, &g_TestHsm_rng.callbackSet);


            for(i_test=0;i_test<4;i_test++)
            {
                if(TEST_HSM_BUF_TEMP_A[i_test] != 0xFFFFFFFF)
                {
                    ErrorCheck = 1;

                }
                else
                {
                    ErrorCheck = 0;
                    break;
                }
            }
            if((RngCallBackFinishResult1 == CSM_E_NOT_OK)&&(RngCallBackFinishResult == CSM_E_OK)
                    && (ErrorCheck == 1))
            {
                ErrorCheck = 1;
            }
            CRY_RNG_TC=CRY_RNG_IDLE;
        }
        break;
#endif
        case CRY_RNG_IDLE :
        {
            break;
        }
        default:
        {
            break;
        }
    }
}
#endif
/*************************************************************************************//**
 * Execution of random number generator test suite
*//**************************************************************************************/
void TestHsm_random(void)
{
    TestHsm_random_init();
    TestHsm_random_generate();
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
