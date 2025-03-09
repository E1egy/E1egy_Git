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

/*#include "Bsp.h"*/
#include "Std_Types.h"
#include "Mcal_Compiler.h"
#include "IfxStm_reg.h"
#include "TestHsm.h"
#include "Ssc_MacVerify.h"
#include "SampleCode.h"
#include "McalLib.h"
#include <string.h>
#if ITF
#include "Det.h"
#include "BswM.h"
#include "Cry_Hsm_Priv.h"
#include "Cry_HsmAesCMacVerify.h"
#endif

/*
#define //UNUSED_PARAMETER(VariableName)   (void)(VariableName);
*/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

extern uint32 TakeTimeDelta(boolean reset);

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#define GET_START_TIME() TakeTimeDelta(TRUE)
/*#define STORE_TIME_DELTA(v) v = TakeTimeDelta(FALSE) */
#define STORE_TIME_DELTA(v)

typedef struct
{
	uint32 timeVerifyStart;
	uint32 timeVerifyUpdate;
	uint32 timeVerifyFinish;
	uint32 timeVerifyCheck;
	uint32 timeVerifyTotal;
	uint32 timeVerifyCrcCheck;

} storeSafeMacVerifyTimes;

#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
const uint8 TEST_CMAC_GEN_CONST_KEY[16] = {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};
#if ITF
const uint8 TEST_CONST_MAC10[16] = {
    0xdc, 0x87, 0xcd, 0xcf, 0x77, 0xA2, 0xF1, 0x82,
    0x9E, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const uint8 TEST_CONST_MAC26[16] = {
    0xd0, 0x65, 0xd2, 0xdd, 0x75, 0xAF, 0x0D, 0xB0,
    0x3F, 0xAB, 0x54, 0xF5, 0xA8, 0xB0, 0x9c, 0x1c
};
const uint8 TEST_CONST_MAC_MUL[16] = {
    0xdE, 0x8B, 0x05, 0x31, 0x08, 0xcb, 0x63, 0xCE,
    0xC1, 0xBF, 0x78, 0xB8, 0x01, 0xEA, 0xC2, 0xE3
};
const uint8 TEST_CONST_MAC_MUL2[16] = {
    0x53, 0x50, 0xD4, 0xA9, 0x54, 0x11, 0x57, 0x1F,
    0xFD, 0x52, 0xA7, 0xBB, 0xB9, 0x67, 0xA5, 0x9B
};
const uint8 TEST_CONST_MAC60[16] = {
    0xE9, 0xAA, 0x4F, 0x4B, 0x05, 0x3B, 0x99, 0x78,
    0xF4, 0xB4, 0xFF, 0x50, 0x9E, 0x66, 0xCE, 0x4A
};
const uint8 TEST_CONST_MAC_VER10[16] = {
    0xC1, 0x39, 0x0A, 0x10, 0xAD, 0x5A, 0xA6, 0x6D,
    0x13, 0xDD, 0x5D, 0x85, 0xF5, 0xEE, 0x04, 0xAE
};
#endif
#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
/* Pointer used by the Cry_HsmAesCMacVerify module to store detailed time measurement */
storeSafeMacVerifyTimes* currentVerifyTimeStore = NULL_PTR;
TestHsm_Mac g_TestHsm_mac = {0,{0,0,0,0},0,{0,0,0,0},0,0};
Csm_ReturnType RetTestHsm_MacGenerate;
uint32 TEST_HSM_BUF_TEMP_E[4] = {0};
static volatile void *p;

#if ITF
typedef enum{
    CRY_MAC_IDLE = 0,
    CRY_MAC_GEN_START_KEYPTR_NULL,
    CRY_MAC_GEN_START_VALID_PARAMETERS_CRY_UNINIT,
    CRY_MAC_GEN_START_VALID_PARAMETERS_KEY_100,
    CRY_MAC_GEN_UPDATE_CFG_NULL,
    CRY_MAC_GEN_UPDATE_DATA_NULL,
    CRY_MAC_GEN_UPDATE_WHEN_START_FAIL,
    CRY_MAC_GEN_FINISH_WHEN_START_NOT_STARTED,
    CRY_MAC_GEN_FINISH_RESULT_PTR_NULL,
    CRY_MAC_GEN_FINISH_RESULT_LENGTH_PTR_NULL,
    CRY_MAC_GEN_FINISH_START_NOT_INITIALIZED,
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON)
    CRY_MAC_GEN_FAILURE_TRUNCATION_OFF,
    CRY_MAC_GEN_SUCCESS1,
    CRY_MAC_GEN_SUCCESS2,
    CRY_MAC_GEN_SUCCESS3,
    CRY_MAC_GEN_SUCCESS4,
    CRY_MAC_GEN_SUCCESS5,
    CRY_MAC_GEN_SUCCESS6,
    CRY_MACGEN_UPDATE_CANCEL,
    CRY_MACGEN_FINISH_CANCEL,
    CRY_MAC_GEN_SUCCESS_MULTIPLE_UPDATES_CANCEL1,
    CRY_MAC_GEN_SUCCESS_MULTIPLE_UPDATES_CANCEL2,
    CRY_MACGEN_UPDATE_CANCEL_CHECK,
    CRY_MAC_GEN_SUCCESS_MULTIPLE_UPDATES,
    CRY_MAC_GEN_TIMEOUT,
#endif
    CRY_MAC_GEN_TIMEOUT_COMPLETE,
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
    CRY_MAC_GEN_SUCCESS_ASYNC1,
    CRY_MAC_GEN_SUCCESS_ASYNC2,
    CRY_MAC_GEN_SUCCESS_ASYNC3,
    CRY_MAC_GEN_SUCCESS_ASYNC4,
    CRY_MAC_GEN_TIMEOUT_ASYNC,
    CRY_MACGEN_UPDATE_CANCEL_ASYNC,
    CRY_MACGEN_FINISH_CANCEL_ASYNC,
#endif
    CRY_MAC_VER_START_KEYPTR_NULL,
    CRY_MAC_VER_START_VALID_PARAMETERS_CRY_UNINIT,
    CRY_MAC_VER_START_VALID_PARAMETERS_KEY_100,
    CRY_MAC_VER_UPDATE_CFG_NULL,
    CRY_MAC_VER_UPDATE_DATA_NULL,
    CRY_MAC_VER_UPDATE_WHEN_START_FAIL,
    CRY_MAC_VER_FINISH_CFG_NULL,
    CRY_MAC_VER_FINISH_MAC_PTR_NULL,
    CRY_MAC_VER_FINISH_RESULT_PTR_NULL,
    CRY_MAC_VER_FINISH_START_NOT_INITIALIZED,
#if ((CRY_HSM_MAC_SAFE_VERIFY == STD_OFF) && (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON))
    CRY_MAC_VER_SUCCESS1,
    CRY_MAC_VER_SUCCESS2,
    CRY_MAC_VER_SUCCESS_MULTI_UPDATES,
    CRY_MAC_VER_INVALIDMAC,
    CRY_MAC_VER_TIMEOUT,
    CRY_MACVER_MULTI_UPDATE_CANCEL,
    CRY_MACVER_UPDATE_CANCEL,
    CRY_MACVER_UPDKEYEMPTY_FINISH_TIMEOUT,
    CRY_MACVER_UPDKEYEMPTY_FINISH_CANCEL,
#endif
#if ((CRY_HSM_MAC_SAFE_VERIFY == STD_OFF) && (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    CRY_MAC_VER_SUCCESS1_ASYNC,
    CRY_MAC_VER_INVALID_MAC,
    CRY_MAC_VER_TIMEOUT_ASYNC,
    CRY_MAC_VER_MULTI_UPDATE_CANCEL_ASYNC,
    CRY_MAC_VER_FINISH_CANCEL_ASYNC,
    CRY_MACVER_SAFE_UPDKEYEMPTY_FINISH_TIMEOUT_ASYNC,
    CRY_MACVER_SAFE_UPDKEYEMPTY_FINISH_CANCEL_ASYNC,
#endif
#if ((CRY_HSM_MAC_SAFE_VERIFY == STD_ON) && (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON))
    CRY_MAC_VER_SUCCESS_SAFE_SYNC1,
    CRY_MAC_VER_SUCCESS_SAFE_SYNC2,
    CRY_MAC_VER_SUCCESS_SAFE_MULUP_SYNC3,
    CRY_MAC_VER_INVALIDMAC_SAFE_SYNC4,
    CRY_MAC_VER_TIMEOUT_SAFE_SYNC5,
    CRY_MACVER_SAFE_MULTI_UPDATE_CANCEL,
    CRY_MACVER_SAFE_FINISH_CANCEL,
    CRY_MACVER_SAFE_UPDKEYEMPTY_FINISH_TIMEOUT,
    CRY_MACVER_SAFE_UPDKEYEMPTY_FINISH_CANCEL,
    CRY_MAC_VER_RESERVED_INDATA_ADDR,
#endif
#if ((CRY_HSM_MAC_SAFE_VERIFY == STD_ON) && (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    CRY_MAC_VER_SUCCESS_SAFE_ASYNC1,
    CRY_MAC_VER_INVALID_SAFE_ASYNC2,
    CRY_MAC_VER_TIMEOUT_SAFE_ASYNC3,
    CRY_MAC_VER_SAFE_MULTI_UPDATE_CANCEL_ASYNC,
    CRY_MAC_VER_SAFE_FINISH_CANCEL_ASYNC,
#endif
    CRY_MAC_VER_TIMEOUT_COMPLETE_FINISH,
    CRY_MAC_VER_CANCEL_TIMEOUT,
    CRY_MAC_VER_CANCELTIMEOUT_CHK_UPDATE,
    CRY_MAC_VER_CANCEL_TIMEOUT_ASYNC,
    CRY_MAC_VER_CANCELTIMEOUT_CHK_UPDATE_ASYNC
}Cry_MAC_Testcase;
Cry_MAC_Testcase TC_MAC = CRY_MAC_IDLE;
uint32 MAC_Length =16;
Csm_ReturnType MAC_RetValStart;
Csm_ReturnType MAC_RetValUpdate;
Csm_ReturnType MAC_RetValFinish;
Csm_ReturnType MAC_RetValFinish2;
Csm_ReturnType MAC_RetValUpdate1;
Csm_ReturnType MAC_RetValUpdate2;
Csm_ReturnType MAC_RetValUpdate3;
Csm_ReturnType MAC_RetVal;
uint8 MacGenStatus;
uint8 MacVerStatus;
Cry_PrimStatusVal Status;
Csm_VerifyResultType MacVerResult;
uint8 LoadKeyDone =0;
uint8 Mac_BswMErrorIdUp;
uint8 Mac_BswMErrorIdFin;

#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
Csm_ReturnType MacCallBackStartResult;
Csm_ReturnType MacCallBackUpdateResult;
Csm_ReturnType MacCallBackFinishResult;
Csm_ReturnType MacCallBackUpdateResult2;
uint8 MacFinishNotify;
#endif

#if (CRY_HSM_MAC_SAFE_VERIFY == STD_ON)
Csm_SafeVerifyResultType MacSafeVerResult ;
#endif
#endif

#define CRY_STOP_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

void Csm_MacGenerateCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
    {
        g_TestHsm_mac.callbackSet = 1;
        RetTestHsm_MacGenerate = CSM_E_OK;
    }
    else
    {
        g_TestHsm_mac.callbackSet = 2;
        RetTestHsm_MacGenerate = CSM_E_NOT_OK;
#if ITF
        /*Removing below print statement to check for timeout */
#else
        TEST_PRINTF("\n MAC failed in mainfunc with err code %d \n", result);
#endif
    }
#if ITF
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF

    switch(Cry_PrimStatusAsync[CRY_HSM_MAC_GENERATE])
    {
      case ASYNC_STATE_START:
      {
         MacCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
         MacCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
         MacCallBackFinishResult = result;
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
void Csm_MacGenerateServiceFinishNotification(void)
{
#if ITF
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
    MacFinishNotify = 1;
#endif
#endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_MacVerifyCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
        {
            g_TestHsm_mac.callbackSet = 1;
        }
        else
        {
            g_TestHsm_mac.callbackSet = 2;
#if ITF
#else
            TEST_PRINTF("\n MAC failed in mainfunc with err code %d \n", result);
#endif
        }
#if ITF
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF

    switch(Cry_PrimStatusAsync[CRY_HSM_MAC_VERIFY])
    {
      case ASYNC_STATE_START:
      {
         MacCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
         MacCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
         MacCallBackFinishResult = result;
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
void Csm_MacVerifyServiceFinishNotification(void)
{
#if ITF
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
    MacFinishNotify = 1;
#endif
#endif
}
#if 0
static uint64 STM_timer64_read (void)  /* 64 bit timer running 100MHz */
{
    uint64 result;

    /*  The capture register STMCAP always captures the
        STM bits [63:32] when one of the registers TIM0 to
        TIM5 and TIM0SV is read. This capture operation is
        performed in order to enable software to operate with
        a coherent value of all the 64 STM bits at one time
        stamp.This bit field contains bits [63:32] of the 64-bit
        STM.
    */
    /*
    Note that the PLS debugger does not display 64bit variables,
    for debugging the STM is first read into 2 32bit variables for
    debugger inspection.
    */
    uint32 time64_l;
    uint32 time64_h;
    time64_l = STM0_TIM0.U;
    time64_h = STM0_CAP.U;
    result = ((uint64)(time64_h) << 32) | time64_l;

    return result;
}
#endif
uint32 TakeTimeDelta(boolean reset)
{
    //UNUSED_PARAMETER(reset);
    /*static uint64 startTime = 0;
    static uint64 prevTime = 0;
    uint64 currentTime = STM_timer64_read();
    uint32 result = (uint32) currentTime;
    prevTime = startTime;
    if (reset != TRUE)
    {
        result = (uint32) (currentTime - prevTime);
    }

    startTime = currentTime;
    return (((result*10) + ((uint32)TimeConst_100ns>>1))/ (uint32)TimeConst_100ns);*/
    return 1;
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#define DETAILED_MEASUREMENTS 1

#define CRY_START_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
#if (DETAILED_MEASUREMENTS == 1)
/* No measurements here, these are done in the Cry_HsmAesCMacVerify module */
/*#define STORE_TIME_DELTA(v) */

static storeSafeMacVerifyTimes TimeMacVerify0;
static storeSafeMacVerifyTimes TimeMacVerify16;
static storeSafeMacVerifyTimes TimeMacVerify16_2;
static storeSafeMacVerifyTimes TimeMacVerify18;
static storeSafeMacVerifyTimes TimeMacVerify18_2;
static storeSafeMacVerifyTimes TimeMacVerify21;
static storeSafeMacVerifyTimes TimeMacVerify22;
static storeSafeMacVerifyTimes TimeMacVerify40;
static storeSafeMacVerifyTimes TimeMacVerify64;
#else
static uint32 TimeMacGenerate16;
static uint32 TimeMacVerify0;
static uint32 TimeMacVerify16;
static uint32 TimeMacVerify16_2;
static uint32 TimeMacVerify18;
static uint32 TimeMacVerify18_2;
static uint32 TimeMacVerify21;
static uint32 TimeMacVerify22;
static uint32 TimeMacVerify40;
static uint32 TimeMacVerify64;
#endif

uint32 Testmac_a,Testmac_b,Testmac_c,Testmac_d,Testmac_e,Testmac_f,Testmac_g,Testmac_h,Testmac_i;
uint32 TestNormalMacver_a, TestNormalMacver_b, TestNormalMacver_c, TestNormalMacver_d, TestNormalMacver_e, TestNormalMacver_f;
uint32 TestNormalMacver_g, TestNormalMacver_h, TestNormalMacver_i;

#define CRY_STOP_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void GenerateMac_MeasureTime(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{

    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;

    /*Dio_WriteChannel(DioConf_DioChannel_DioChannel_Performance,STD_HIGH);*/
    Testmac_a = STM0_TIM0.U;
    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    Testmac_b = STM0_TIM0.U;
    /*Dio_WriteChannel(DioConf_DioChannel_DioChannel_Performance,STD_LOW);*/
    Testmac_c = Testmac_b-Testmac_a;

    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
   /* Dio_WriteChannel(DioConf_DioChannel_DioChannel_Performance,STD_HIGH);*/
    Testmac_d = STM0_TIM0.U;
    result = Cry_HsmAesCMacGenerateUpdate(config, message, messageLength);
    /*result = Cry_HsmAesCMacGenerateUpdate(config, 0xA0080000, 0x400);*/
    Testmac_e = STM0_TIM0.U;
    /*Dio_WriteChannel(DioConf_DioChannel_DioChannel_Performance,STD_LOW);*/
    Testmac_f= Testmac_e-Testmac_d;

    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif

    /*Dio_WriteChannel(DioConf_DioChannel_DioChannel_Performance,STD_HIGH);*/
    Testmac_g = STM0_TIM0.U;
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    Testmac_h = STM0_TIM0.U;
    /*Dio_WriteChannel(DioConf_DioChannel_DioChannel_Performance,STD_LOW);*/
    Testmac_i = Testmac_h-Testmac_g;

    TEST_VALIDATE(result == CSM_E_OK)
    TEST_VALIDATE(realMacLength == macLength)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)

    TEST_PRINTF("\n %f start ,%f update ,%f finish \n", (Testmac_c*TEST_TIME_CONSTANT),(Testmac_f*TEST_TIME_CONSTANT),(Testmac_i*TEST_TIME_CONSTANT));
    TEST_PRINTF("\n %f totaltime \n", ((Testmac_c + Testmac_f + Testmac_i)*TEST_TIME_CONSTANT));

}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void GenerateMac(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{
    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;

    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, message, messageLength);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    TEST_VALIDATE(result == CSM_E_OK)
    TEST_VALIDATE(realMacLength == macLength)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
}

void GenerateMacFailTimeOut(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{
    const Cry_HsmAesCMacGenerateConfigType  Cry_kHsmAesCMacGenerateConfigLessTime =
            {.TimeOut =   {.TimeoutStart = 0,
                    .TimeoutUpdateConst = 3,
                    .TimeoutUpdateperByte = 0,
                    .TimeoutFinish = 3 }  };

    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_kHsmAesCMacGenerateConfigLessTime;

    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, message, messageLength);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    TEST_VALIDATE(result == CSM_E_OK)
    TEST_VALIDATE(realMacLength == macLength)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
}

void GenerateMacNeg(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{
    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;

    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, message, messageLength);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    TEST_VALIDATE(result == CSM_E_SMALL_BUFFER)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
}

void GenerateMac_MulUpd(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{
    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;

    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 0);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_2, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_3, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_4, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    TEST_VALIDATE(result == CSM_E_OK)
    TEST_VALIDATE(realMacLength == macLength)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
}

void GenerateMac_MulUpd11110(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{
    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;

    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_2, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_3, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_4, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 0);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    TEST_VALIDATE(result == CSM_E_OK)
    TEST_VALIDATE(realMacLength == macLength)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
}

void GenerateMac_MulUpd_11011(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{
    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;

    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_2, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 0);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_3, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_4, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    TEST_VALIDATE(result == CSM_E_OK)
    TEST_VALIDATE(realMacLength == macLength)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
}

void GenerateMac_MulUpd_NegUpd(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{
    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;

    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_2, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_3, 30);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_4, 8);
    TEST_VALIDATE(result != CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    TEST_VALIDATE(result == CSM_E_OK)
    TEST_VALIDATE(realMacLength == macLength)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
}

void GenerateMac_MulUpd2(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{
    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;

    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 0);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_48, 48);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    TEST_VALIDATE(result == CSM_E_OK)
    TEST_VALIDATE(realMacLength == macLength)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
}

void GenerateMac_MulUpd2_ZeroCase(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{
    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;

    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 0);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN, 64);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    TEST_VALIDATE(result == CSM_E_OK)
    TEST_VALIDATE(realMacLength == macLength)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
}

void GenerateMac_MulUpd3(const Csm_SymKeyType *keyPtr, const void* message, uint32 messageLength, void* macOut, uint32 macLength, boolean truncate)
{
    uint32 realMacLength = macLength;
    Csm_ReturnType result;
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;

    result = Cry_HsmAesCMacGenerateStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_32, 32);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_2, 0);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateUpdate(config, (const uint8*)TEST_CONST_PLAIN_4, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacGenerateFinish(config, macOut, &realMacLength, truncate);
    TEST_VALIDATE(result == CSM_E_OK)
    TEST_VALIDATE(realMacLength == macLength)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
}

/*************************************************************************************//**
 * Execution of CMAC generation test suite
*//**************************************************************************************/
void TestHsm_generate_mac(void)
{
#if 0
     boolean result;

     TEST_PRINTF("\nMAC generate #1: len = 16 bytes -------------------------------- \n");
     GenerateMac(KEY_MAC_GENERATE, TEST_CONST_PLAIN, 16, TEST_HSM_BUF_TEMP_D, 16, FALSE);
     TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,16);
     TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
     TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC16, 4)

     TEST_PRINTF("\nMAC verify #1: len = 16 bytes -------------------------------- \n");
     currentVerifyTimeStore = &TimeMacVerify0;
     result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_CONST_MAC16,  16 , 16*8);
     TEST_VALIDATE(result != FALSE);

     TEST_PRINTF("\nMAC generate #1: len = 16 bytes -------------------------------- \n");
     GenerateMac(KEY_ENCRYPTION, TEST_CONST_PLAIN, 16, TEST_HSM_BUF_TEMP_D, 16, FALSE);
     TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,16);
     TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
     TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC16, 4)

     TEST_PRINTF("\nMAC verify #1: len = 16 bytes -------------------------------- \n");
     currentVerifyTimeStore = &TimeMacVerify0;
     result = VerifyMac(KEY_ENCRYPTION, TEST_CONST_PLAIN, TEST_CONST_MAC16,  16 , 16*8);
     TEST_VALIDATE(result != FALSE);

     TEST_PRINTF("\nMAC generate #1: len = 16 bytes -------------------------------- \n");
     GenerateMac(KEY_MAC_GENERATE, TEST_CONST_PLAIN, 16, TEST_HSM_BUF_TEMP_D, 16, FALSE);
     TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,16);
     TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
     TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC16, 4)

     TEST_PRINTF("\nMAC verify #1: len = 16 bytes -------------------------------- \n");
     currentVerifyTimeStore = &TimeMacVerify0;
     result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_CONST_MAC16,  16 , 16*8);
     TEST_VALIDATE(result != FALSE);
#endif
#if (1)
    TEST_PRINTF("\nMAC generate #1: len = 0 bytes -------------------------------- \n");
    GenerateMac(KEY_MAC_GENERATE, TEST_CONST_PLAIN, 0, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTF("<empty string>\n");
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC0, 4)

    TEST_PRINTF("\nMAC generate #2: len = 16 bytes -------------------------------- \n");
    GET_START_TIME();
    GenerateMac(KEY_MAC_GENERATE, TEST_CONST_PLAIN, 16, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    STORE_TIME_DELTA(TimeMacGenerate16);

    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,16);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC16, 4)

    TEST_PRINTF("\nMAC generate #3: len = 40 bytes -------------------------------- \n");
    GenerateMac(KEY_MAC_GENERATE, TEST_CONST_PLAIN, 40, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,40);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC40, 4)

    TEST_PRINTF("\nMAC generate #4: len = 64 bytes -------------------------------- \n");
    GenerateMac(KEY_MAC_GENERATE, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 4)

    TEST_PRINTF("\nMAC generate #5: len = 64 bytes -> CMAC 11 bytes --------------- \n");
    p = memset(TEST_HSM_BUF_TEMP_C, 0x5AU, 16);
    p = memset(TEST_HSM_BUF_TEMP_D, 0x5AU, 16);
    p = memcpy(TEST_HSM_BUF_TEMP_C, TEST_CONST_MAC64, 11);
    GenerateMac(KEY_MAC_GENERATE, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 11, TRUE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN, 64);
    TEST_PRINTF("CMAC       "); TEST_PRINTHEX(TEST_HSM_BUF_TEMP_D,11); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_HSM_BUF_TEMP_C, 4)

    TEST_PRINTF("\nMAC generate #6: len = 21 bytes -------------------------------- \n");
    GenerateMac(KEY_MAC_GENERATE, TEST_CONST_PLAIN, 21, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,21);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC21, 4)

    TEST_PRINTF("\nMAC generate #7: len = 22 bytes -------------------------------- \n");
    GenerateMac(KEY_MAC_GENERATE, TEST_CONST_PLAIN, 22, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,22);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC22, 4)

    TEST_PRINTF("\nMAC generate #8: len = 18 bytes / 32 Bit MAC---------------------- \n");
    GenerateMac(KEY_MAC_GENERATE, TEST_CONST_PLAIN, 18, TEST_HSM_BUF_TEMP_D, 4, TRUE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,18);
    TEST_PRINTF("CMAC       "); TEST_PRINTHEX(TEST_HSM_BUF_TEMP_D,4); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC18, 1)
#endif
    #if 0
        TEST_PRINTF("\nMAC generate #9: len = 64 bytes -------------------------------- \n");
        GenerateMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
        TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
        TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
        TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 4)
    #endif
}


/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
boolean VerifyMac(const Csm_SymKeyType *keyPtr, const void* message, const void* macIn, uint32 messageLength, uint32 verifyLength)
{
	boolean verified = FALSE;
#if (CRY_HSM_MAC_SAFE_VERIFY == 1)
	verified = Ssc_SafeMacVerify( keyPtr, (const uint8*) message, messageLength, (const uint8*) macIn, verifyLength);
	TEST_VALIDATE(verified == TRUE)
#else
    Csm_ReturnType result;
    const Cry_HsmAesCMacVerifyConfigType* config = &Cry_kHsmAesCMacVerifyConfig;
    Csm_VerifyResultType verifyResult;

    TestNormalMacver_a = STM0_TIM0.U;
    result = Cry_HsmAesCMacVerifyStart(config, keyPtr);
    TestNormalMacver_b = STM0_TIM0.U;
    TestNormalMacver_c = TestNormalMacver_b-TestNormalMacver_a;

    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

    TestNormalMacver_d = STM0_TIM0.U;
    result = Cry_HsmAesCMacVerifyUpdate(config, message, messageLength);
    TestNormalMacver_e = STM0_TIM0.U;
    TestNormalMacver_f = TestNormalMacver_e-TestNormalMacver_d;

    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

    TestNormalMacver_g = STM0_TIM0.U;
    result = Cry_HsmAesCMacVerifyFinish(config, macIn, verifyLength, &verifyResult);
    TestNormalMacver_h = STM0_TIM0.U;
    TestNormalMacver_i = TestNormalMacver_h-TestNormalMacver_g;

    TEST_VALIDATE(result == CSM_E_OK)

#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    verified = (verifyResult == CSM_E_VER_OK) ? TRUE : FALSE;
#if 0
    TEST_PRINTF(" \n Result %d ",verifyResult );
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
    TEST_PRINTF("\n %f start ,%f update ,%f finish \n", (TestNormalMacver_c*TEST_TIME_CONSTANT),(TestNormalMacver_f*TEST_TIME_CONSTANT),(TestNormalMacver_i*TEST_TIME_CONSTANT));
    TEST_PRINTF("\n %f totaltime \n", ((TestNormalMacver_c + TestNormalMacver_f + TestNormalMacver_i)*TEST_TIME_CONSTANT));
#endif
    return verified;
}

boolean VerifyMacMulUpd(const Csm_SymKeyType *keyPtr, const void* message, const void* macIn, uint32 messageLength, uint32 verifyLength)
{
    boolean verified = FALSE;
#if (CRY_HSM_MAC_SAFE_VERIFY == 1)
    verified = Ssc_SafeMacVerify( keyPtr, (const uint8*) message, messageLength, (const uint8*) macIn, verifyLength);
    TEST_VALIDATE(verified == TRUE)
#else
    Csm_ReturnType result;
    const Cry_HsmAesCMacVerifyConfigType* config = &Cry_kHsmAesCMacVerifyConfig;
    Csm_VerifyResultType verifyResult;

    result = Cry_HsmAesCMacVerifyStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_2, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 0);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_3, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_4, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyFinish(config, macIn, verifyLength, &verifyResult);
    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    verified = (verifyResult == CSM_E_VER_NOT_OK) ? TRUE : FALSE;
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
    return verified;
}

boolean VerifyMacMulUpdZero(const Csm_SymKeyType *keyPtr, const void* message, const void* macIn, uint32 messageLength, uint32 verifyLength)
{
    boolean verified = FALSE;
#if (CRY_HSM_MAC_SAFE_VERIFY == 1)
    verified = Ssc_SafeMacVerify( keyPtr, (const uint8*) message, messageLength, (const uint8*) macIn, verifyLength);
    TEST_VALIDATE(verified == TRUE)
#else
    Csm_ReturnType result;
    const Cry_HsmAesCMacVerifyConfigType* config = &Cry_kHsmAesCMacVerifyConfig;
    Csm_VerifyResultType verifyResult;

    result = Cry_HsmAesCMacVerifyStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 0);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_2, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_3, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_4, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyFinish(config, macIn, verifyLength, &verifyResult);
    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    verified = (verifyResult == CSM_E_VER_OK) ? TRUE : FALSE;
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
    return verified;
}

boolean VerifyMacMulUpdNeg(const Csm_SymKeyType *keyPtr, const void* message, const void* macIn, uint32 messageLength, uint32 verifyLength)
{
    boolean verified = FALSE;
#if (CRY_HSM_MAC_SAFE_VERIFY == 1)
    verified = Ssc_SafeMacVerify( keyPtr, (const uint8*) message, messageLength, (const uint8*) macIn, verifyLength);
    TEST_VALIDATE(verified != TRUE)
#else
    Csm_ReturnType result;
    const Cry_HsmAesCMacVerifyConfigType* config = &Cry_kHsmAesCMacVerifyConfig;
    Csm_VerifyResultType verifyResult;

    result = Cry_HsmAesCMacVerifyStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_1, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_2, 16);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_3, 30);
    TEST_VALIDATE(result == CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)TEST_CONST_PLAIN_4, 8);
    TEST_VALIDATE(result != CSM_E_OK)
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyFinish(config, macIn, verifyLength, &verifyResult);
    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    verified = (verifyResult == CSM_E_VER_NOT_OK) ? TRUE : FALSE;
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
    return verified;
}

boolean VerifyMacNeg(const Csm_SymKeyType *keyPtr, const void* message, const void* macIn, uint32 messageLength, uint32 verifyLength)
{
    boolean verified = FALSE;
#if (CRY_HSM_MAC_SAFE_VERIFY == 1)
    verified = Ssc_SafeMacVerifyNeg( keyPtr, (const uint8*) message, messageLength, (const uint8*) macIn, verifyLength);
    TEST_VALIDATE(verified == TRUE)
#else
    Csm_ReturnType result;
    const Cry_HsmAesCMacVerifyConfigType* config = &Cry_kHsmAesCMacVerifyConfig;
    Csm_VerifyResultType verifyResult;

    result = Cry_HsmAesCMacVerifyStart(config, keyPtr);
    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

    result = Cry_HsmAesCMacVerifyUpdate(config, message, messageLength);
    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    result = Cry_HsmAesCMacVerifyFinish(config, macIn, verifyLength, &verifyResult);
    TEST_VALIDATE(result == CSM_E_OK)
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif
    verified = (verifyResult == CSM_E_VER_NOT_OK) ? TRUE : FALSE;
#endif
    //UNUSED_PARAMETER(messageLength)
    //UNUSED_PARAMETER(message)
    return verified;
}

/*************************************************************************************//**
 * Execution of CMAC verify test suite
*//**************************************************************************************/
void TestHsm_verify_mac(void)
{
    volatile boolean result;

#if (1)
#if (CRY_HSM_MAC_SAFE_VERIFY == 1)
    TEST_PRINTF("\nCRY_HSM_MAC_SAFE_VERIFY is ON  ------------------------------- \n");
#else
    TEST_PRINTF("\nCRY_HSM_MAC_SAFE_VERIFY is OFF  ------------------------------- \n");
#endif
    TEST_PRINTF("\nMAC verify #1: len = 0 bytes -------------------------------- \n");
    currentVerifyTimeStore = &TimeMacVerify0;
    result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_CONST_MAC0,  0 , 16*8);
    TEST_VALIDATE(result != FALSE);

    TEST_PRINTF("\nMAC verify #2: len = 16 bytes / 16 byte MAC ----------------- \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify16;
    result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_CONST_MAC16, 16, 16*8);
    STORE_TIME_DELTA(TimeMacVerify16);

    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #3: len = 40 bytes / 16 byte MAC ------------------ \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify40;
    result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_CONST_MAC40, 40, 16*8);
    STORE_TIME_DELTA(TimeMacVerify40);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #4: len = 64 bytes / 16 byte MAC ------------------ \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify64;
    result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_CONST_MAC64, 64, 16*8);
    STORE_TIME_DELTA(TimeMacVerify64);
    TEST_VALIDATE(result != FALSE)
#endif
    TEST_PRINTF("\nMAC verify #5: len = 21 bytes / 11 byte MAC ------------------ \n");
    HsmCom_SetArrayValue((uint32*)TEST_HSM_BUF_TEMP_C, 0, 4);
    p = memcpy(TEST_HSM_BUF_TEMP_C, TEST_CONST_MAC21, 11);
    TEST_VALIDATE(p != NULL_PTR)
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify21;
    result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_C, 21, 11*8);
    STORE_TIME_DELTA(TimeMacVerify21);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #6: len = 22 bytes / 12 byte MAC ------------------ \n");
    /*HsmCom_SetArrayValue((uint32*)TEST_HSM_BUF_TEMP_C, 0, 4);
    p = memcpy(TEST_HSM_BUF_TEMP_C, TEST_CONST_MAC22, 12);
    TEST_VALIDATE(p != NULL_PTR)*/
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify22;
    result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_CONST_MAC22, 22, 12*8);
    STORE_TIME_DELTA(TimeMacVerify22);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #7: len = 18 bytes  / 27 bits MAC ----------------- \n");
    HsmCom_SetArrayValue((uint32*)TEST_HSM_BUF_TEMP_C, 0, 4);
    p = memcpy(TEST_HSM_BUF_TEMP_C, TEST_CONST_MAC18, 4);
    TEST_VALIDATE(p != NULL_PTR)
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify18;
    result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_C, 18, 4*8-5);
    STORE_TIME_DELTA(TimeMacVerify18);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #8: len = 16 bytes / 27 bits MAC -----------------  \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify16_2;
    result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_CONST_MAC16, 16, 4*8-5);
    STORE_TIME_DELTA(TimeMacVerify16_2);

    TEST_PRINTF("\nMAC verify #9: len = 18 bytes  / 32 bits MAC ----------------- \n");
    HsmCom_SetArrayValue((uint32*)TEST_HSM_BUF_TEMP_C, 0, 4);
    p = memcpy(TEST_HSM_BUF_TEMP_C, TEST_CONST_MAC18, 4);
    TEST_VALIDATE(p != NULL_PTR)
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify18_2;
    result = VerifyMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_C, 18, 4*8);
    STORE_TIME_DELTA(TimeMacVerify18_2);
    TEST_VALIDATE(result != FALSE)

}
/*************************************************************************************//**
 * MAC generation and verification ITF test suite
*//**************************************************************************************/
#if ITF
void Mac_ITF(void)
{
    const Cry_HsmAesCMacGenerateConfigType* config = &Cry_HsmAesCMacGenerateConfig;
    const Cry_HsmAesCMacVerifyConfigType* config3 = &Cry_kHsmAesCMacVerifyConfig;
    /*For less timeout requirement*/
    const Cry_HsmAesCMacGenerateConfigType  Cry_kHsmAesCMacGenerateConfigLessTime =
            {.TimeOut =   {.TimeoutStart = 0,
                    .TimeoutUpdateConst = 0,
                    .TimeoutUpdateperByte = 0,
                    .TimeoutFinish = 0 }  };
    const Cry_HsmAesCMacVerifyConfigType  Cry_kHsmAesCMacVerifyConfigLessTime =
            {.TimeOut =   {.TimeoutStart = 0,
                    .TimeoutUpdateConst = 0,
                    .TimeoutUpdateperByte = 0,
                    .TimeoutFinish = 0 }  };

    const Cry_HsmAesCMacGenerateConfigType* config2 = &Cry_kHsmAesCMacGenerateConfigLessTime;
    const Cry_HsmAesCMacVerifyConfigType* config4 = &Cry_kHsmAesCMacVerifyConfigLessTime;
    if (LoadKeyDone == 0)
    {
        SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)TEST_CMAC_GEN_CONST_KEY,16);
        LoadKeyDone = 1;
    }
    switch(TC_MAC)
      {
          case  CRY_MAC_GEN_START_KEYPTR_NULL:/*113-1*/
          {
              MacGenStatus = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = Cry_HsmAesCMacGenerateStart(config, NULL_PTR);

              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_GENERATE_START))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_START_VALID_PARAMETERS_CRY_UNINIT:/*114-2*/
          {
              /*Set Cry_HsmInitStatus to CRY_HSM_UNINITIALIZED in scripts*/
              MacGenStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_UNINIT) && (DetApiId == CRY_HSM_SID_MAC_GENERATE_START))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              /*Set Cry_HsmInitStatus to CRY_HSM_INITIALIZED at end of scripts*/
              break;
          }
          case  CRY_MAC_GEN_START_VALID_PARAMETERS_KEY_100:/*115-3*/
          {
              MacGenStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_KEY_100);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID) && (DetApiId == CRY_HSM_SID_MAC_GENERATE_START))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_UPDATE_CFG_NULL:/*116-4*/
          {
              MacGenStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacGenerateUpdate(NULL_PTR, TEST_CONST_PLAIN, 0);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_GENERATE_UPDATE))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_UPDATE_DATA_NULL:/*117-5*/
          {
              MacGenStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacGenerateUpdate(config, NULL_PTR, 0);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_GENERATE_UPDATE))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_UPDATE_WHEN_START_FAIL:/*118-6*/
          {
              MacGenStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              Status = Cry_PrimStatus[CRY_HSM_MAC_GENERATE];
              Cry_PrimStatus[CRY_HSM_MAC_GENERATE] = CRY_HSM_PRIM_NOT_STARTED;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED) && (DetApiId == CRY_HSM_SID_MAC_GENERATE_UPDATE))
              {
                  MacGenStatus = 1;
              }
              Cry_PrimStatus[CRY_HSM_MAC_GENERATE] = Status;
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_FINISH_WHEN_START_NOT_STARTED:/*119-7*//*Recheck*/
          {
              MacGenStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_Length = 16;
              Status = Cry_PrimStatus[CRY_HSM_MAC_GENERATE];
              Cry_PrimStatus[CRY_HSM_MAC_GENERATE] = CRY_HSM_PRIM_NOT_STARTED;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D, &MAC_Length, TRUE);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED) && (DetApiId == CRY_HSM_SID_MAC_GENERATE_FINISH))
              {
                  MacGenStatus = 1;
              }
              Cry_PrimStatus[CRY_HSM_MAC_GENERATE] = Status;
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_FINISH_RESULT_PTR_NULL:/*120-8*/
          {
              MacGenStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_Length = 16;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacGenerateFinish(config, NULL_PTR, &MAC_Length, FALSE);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_GENERATE_FINISH))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_FINISH_RESULT_LENGTH_PTR_NULL:/*121-9*/
          {
              MacGenStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D, NULL_PTR, FALSE);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_GENERATE_FINISH))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_FINISH_START_NOT_INITIALIZED:/*122-10*/
          {
              MacGenStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              Status = Cry_PrimStatus[CRY_HSM_MAC_GENERATE];
              Cry_PrimStatus[CRY_HSM_MAC_GENERATE] = CRY_HSM_PRIM_NOT_STARTED;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_Length = 16;
              MAC_RetVal = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED) && (DetApiId == CRY_HSM_SID_MAC_GENERATE_FINISH))
              {
                  MacGenStatus = 1;
              }
              Cry_PrimStatus[CRY_HSM_MAC_GENERATE] = Status;
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON)
          case CRY_MAC_GEN_FAILURE_TRUNCATION_OFF:/*-11*/
          {
              MacGenStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish2 = CSM_E_ENTROPY_EXHAUSTION;
              /*DataLength = 8, *ResultLengthPtr = 10*/
              MAC_Length = 10;
              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 8);
              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8*)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_SMALL_BUFFER) && (DetErrorId == CRY_HSM_E_BUFFER_TOO_SMALL)
                      && (DetApiId == CRY_HSM_SID_MAC_GENERATE_FINISH))
              {
                  MacGenStatus = 1;
              }
              /*To complete the session we need to call Finish service*/
              MAC_RetValFinish2 = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, TRUE);
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_SUCCESS1:/*123-12*/
          {
              /*DataLength = 0, *ResultLengthPtr = 16*/
              MacGenStatus = 0;
              MAC_Length = 16;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;
              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0);
              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC0),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_SUCCESS2:/*124-13*/
          {
              /*DataLength = 8, *ResultLengthPtr = 10*/
              MacGenStatus = 0;
              MAC_Length = 10;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;
              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 8);
              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, TRUE);
              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC10),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_SUCCESS3:/*125-14*/
          {
              /*DataLength = 26, *ResultLengthPtr = 16*/
              MacGenStatus = 0;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MAC_Length = 16;
              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 26);
              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;
              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC26),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_SUCCESS4:/*15*/
          {
              /*DataLength = 40, *ResultLengthPtr = 16*/
              MacGenStatus = 0;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MAC_Length = 16;
              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 40);
              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;
              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, TRUE);
              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC40),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_SUCCESS5:/*Testing Purpose*/
          {
              /*DataLength = 10, *ResultLengthPtr = 16*/
              MacGenStatus = 0;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MAC_Length = 16;
              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 10);
              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;
              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC_VER10),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_SUCCESS6:/*Testing Purpose*/
          {
              MacGenStatus = 0;
              MAC_Length = 16;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate1 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate2 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate3 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              MAC_RetValUpdate1 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);
              MAC_RetValUpdate2 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);
              MAC_RetValUpdate3 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 8);
              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;
              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC_MUL2),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate1 == CSM_E_OK) && (MAC_RetValUpdate2 == CSM_E_OK) &&
                      (MAC_RetValUpdate3 == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) )
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case CRY_MACGEN_UPDATE_CANCEL:
          {
              CancelRequired = 1;
              MacGenStatus = 0;
              MAC_Length = 16;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);

              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);
              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);
              Gpt_StopTimer(Gptch_CancelCommand);

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_NOT_OK) && (MAC_RetValFinish == CSM_E_NOT_OK))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_GEN_SUCCESS1 to check sesion is closed properly in last finish*/
          }
          case CRY_MACGEN_FINISH_CANCEL:
          {
              CancelRequired = 1;
              MacGenStatus = 0;
              MAC_Length = 16;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);

              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);

              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);
              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              Gpt_StopTimer(Gptch_CancelCommand);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_NOT_OK))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_GEN_SUCCESS1 to check sesion is closed properly in last finish*/
          }
          case  CRY_MAC_GEN_SUCCESS_MULTIPLE_UPDATES_CANCEL1:
          {
              CancelRequired = 1;
              MacGenStatus = 0;
              MAC_Length = 16;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate1 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate2 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate3 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);

              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);

              MAC_RetValUpdate1 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);
              Gpt_StopTimer(Gptch_CancelCommand);

              MAC_RetValUpdate2 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x20);
              MAC_RetValUpdate3 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 16);

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate1 == CSM_E_NOT_OK) && (MAC_RetValUpdate2 == CSM_E_NOT_OK) &&
                      (MAC_RetValUpdate3 == CSM_E_NOT_OK) && (MAC_RetValFinish == CSM_E_NOT_OK) )
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_GEN_SUCCESS1 to check sesion is closed properly in last finish*/
          }
          case  CRY_MAC_GEN_SUCCESS_MULTIPLE_UPDATES_CANCEL2:
          {
              CancelRequired = 1;
              MacGenStatus = 0;
              MAC_Length = 16;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate1 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate2 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate3 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);

              MAC_RetValUpdate1 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);

              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);
              MAC_RetValUpdate2 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x20);
              Gpt_StopTimer(Gptch_CancelCommand);

              MAC_RetValUpdate3 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 16);

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate1 == CSM_E_OK) && (MAC_RetValUpdate2 == CSM_E_NOT_OK) &&
                      (MAC_RetValUpdate3 == CSM_E_NOT_OK) && (MAC_RetValFinish == CSM_E_NOT_OK) )
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_GEN_SUCCESS1 to check sesion is closed properly in last finish*/
          }

          case CRY_MACGEN_UPDATE_CANCEL_CHECK:
          {
              CancelRequired = 1;
              MacGenStatus = 0;
              MAC_Length = 16;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);

              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);
              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              Gpt_StopTimer(Gptch_CancelCommand);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_NOT_OK) && (MAC_RetValFinish == CSM_E_NOT_OK))
              {
                  MacGenStatus = 1;
              }
              /*Call CRY_MAC_GEN_SUCCESS1 to check sesion is closed properly in last finish*/

              TC_MAC = CRY_MAC_IDLE;
          }
          break;
          case  CRY_MAC_GEN_SUCCESS_MULTIPLE_UPDATES:/*126-16*/
          {
              MacGenStatus = 0;
              MAC_Length = 16;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate1 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate2 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate3 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              MAC_RetValUpdate1 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);
              MAC_RetValUpdate2 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x20);
              MAC_RetValUpdate3 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 16);

              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);

              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC_MUL),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate1 == CSM_E_OK) && (MAC_RetValUpdate2 == CSM_E_OK) &&
                      (MAC_RetValUpdate3 == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) )
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_TIMEOUT:/*127-17*/
          {
              MacGenStatus = 1;
              BswMModuleId = 0x0;
              BswMErrorId = 0x0;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MAC_Length = 16;
              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config2, TEST_CONST_PLAIN, 16);
              if((MAC_RetValStart != CSM_E_OK) || (MAC_RetValUpdate != CSM_E_NOT_OK) ||
                                    (BswMModuleId != CRY_MODULE_ID) || (BswMErrorId != HSMCOM_ERC_TIMEOUT))
              {
                  MacGenStatus = 0;
              }
              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              if(MAC_RetValFinish != CSM_E_BUSY)
              {
                  MacGenStatus = 0;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#endif
          case  CRY_MAC_GEN_TIMEOUT_COMPLETE:/*Timeout finish*/
          {
              /*This function should be called after timeout service with some delay*/
              MAC_RetValFinish2 = CSM_E_ENTROPY_EXHAUSTION;
              MacGenStatus = 0;
              MAC_Length = 16;
              MAC_RetValFinish2 = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              #if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
              g_TestHsm_mac.callbackSet = 0;
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);
              #endif
              if(MAC_RetValFinish2 == CSM_E_OK)
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
          case  CRY_MAC_GEN_SUCCESS_ASYNC1:/*128 -18*/
          {
              MacGenStatus = 0;
              MacFinishNotify   = 0;
              MacCallBackStartResult  = CSM_E_NOT_OK;
              MacCallBackUpdateResult = CSM_E_NOT_OK;
              MacCallBackFinishResult = CSM_E_NOT_OK;

              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              g_TestHsm_mac.callbackSet = 0;
              MAC_Length = 16;

              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, TRUE);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC0),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) &&
                      (MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult == CSM_E_OK)&&
                      (MacFinishNotify == 1))
              {
                  MacGenStatus = 1;
              }
              /*check MacCallBack = 1 && MacCallBackResult = ok;MacFinishNotify =1*/
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_SUCCESS_ASYNC2:/*129-19*/
          {
              MacGenStatus = 0;
              MacFinishNotify   = 0;
              MacCallBackStartResult  = CSM_E_NOT_OK;
              MacCallBackUpdateResult = CSM_E_NOT_OK;
              MacCallBackFinishResult = CSM_E_NOT_OK;

              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              g_TestHsm_mac.callbackSet = 0;
              MAC_Length = 10;

              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 8);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, TRUE);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC10),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) &&
                      (MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult == CSM_E_OK)&&
                      (MacFinishNotify == 1))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_SUCCESS_ASYNC3:/*130-20*/
          {
              MacGenStatus = 0;
              MacFinishNotify   = 0;
              MacCallBackStartResult  = CSM_E_NOT_OK;
              MacCallBackUpdateResult = CSM_E_NOT_OK;
              MacCallBackFinishResult = CSM_E_NOT_OK;

              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              g_TestHsm_mac.callbackSet = 0;
              MAC_Length = 16;

              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 26);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC26),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) &&
                      (MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult == CSM_E_OK)&&
                      (MacFinishNotify == 1))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_SUCCESS_ASYNC4:/*131-21*/
          {
              MacGenStatus = 0;
              MacFinishNotify   = 0;

              MacCallBackStartResult  = CSM_E_NOT_OK;
              MacCallBackUpdateResult = CSM_E_NOT_OK;
              MacCallBackFinishResult = CSM_E_NOT_OK;

              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate1 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate2 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate3 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              g_TestHsm_mac.callbackSet = 0;
              MAC_Length = 16;
              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;


              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate1 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate2 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x20);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate3 = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 16);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              if((HsmCom_CompareArray((const uint32*)(TEST_HSM_BUF_TEMP_D),(const uint32*)(TEST_CONST_MAC_MUL),4) != FALSE) &&
                      (MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate1 == CSM_E_OK) &&(MAC_RetValUpdate2 == CSM_E_OK) &&(MAC_RetValUpdate3 == CSM_E_OK) &&
                      (MAC_RetValFinish == CSM_E_OK) && (MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult == CSM_E_OK) &&
                      (MacFinishNotify == 1))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_GEN_TIMEOUT_ASYNC:/*132-22*/
          {
              MacGenStatus = 1;
              BswMModuleId = 0x0;
              BswMErrorId = 0x0;
              MacFinishNotify   = 0;

              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;

              g_TestHsm_mac.callbackSet = 0;
              MAC_Length = 16;

              TEST_HSM_BUF_TEMP_D[0]=0x0;
              TEST_HSM_BUF_TEMP_D[1]=0x0;
              TEST_HSM_BUF_TEMP_D[2]=0x0;
              TEST_HSM_BUF_TEMP_D[3]=0x0;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config2, TEST_CONST_PLAIN, 26);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              if((MAC_RetValStart != CSM_E_OK) || (MAC_RetValUpdate != CSM_E_NOT_OK) ||
                 (MacCallBackStartResult != CSM_E_OK) || (MacCallBackUpdateResult != CSM_E_NOT_OK) ||
                 (BswMModuleId != CRY_MODULE_ID) || (BswMErrorId != HSMCOM_ERC_TIMEOUT))
              {
                  MacGenStatus = 0;
              }

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              if((MAC_RetValFinish != CSM_E_BUSY) || (MacFinishNotify != 1) || (MacCallBackFinishResult != CSM_E_BUSY))
              {
                  MacGenStatus = 0;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case CRY_MACGEN_UPDATE_CANCEL_ASYNC:
          {
              MacGenStatus = 0;
              MAC_Length = 16;
              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);
              Cry_HsmSheCancel();
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              if((MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_NOT_OK) && (MacCallBackFinishResult == CSM_E_NOT_OK))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_GEN_SUCCESS_ASYNC1 to check sesion is closed properly in last finish*/
          }
          case CRY_MACGEN_FINISH_CANCEL_ASYNC:
          {
              MacGenStatus = 0;
              MAC_Length = 16;
              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0x10);
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);
              Cry_HsmSheCancel();
              TEST_WAIT(&Cry_HsmAesCMacGenerateMainFunction, &g_TestHsm_mac.callbackSet);

              if((MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult == CSM_E_NOT_OK))
              {
                  MacGenStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_GEN_SUCCESS_ASYNC1 to check sesion is closed properly in last finish*/
          }
#endif
          case  CRY_MAC_VER_START_KEYPTR_NULL:/*133-23*/
          {
              MacVerStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetVal = Cry_HsmAesCMacVerifyStart(config3, NULL_PTR);

              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_VERIFY_START))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_START_VALID_PARAMETERS_CRY_UNINIT:/*134-24*/
          {
              MacVerStatus = 0;
              /*Set Cry_HsmInitStatus to CRY_HSM_UNINITIALIZED through scripts*/
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_UNINIT) && (DetApiId == CRY_HSM_SID_MAC_VERIFY_START))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_START_VALID_PARAMETERS_KEY_100:/*135-25*/
          {
              MacVerStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_KEY_100);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_KEY_TYPE_INVALID) && (DetApiId == CRY_HSM_SID_MAC_VERIFY_START))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_UPDATE_CFG_NULL:/*136-26*/
          {
              MacVerStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacVerifyUpdate(NULL_PTR, TEST_CONST_PLAIN, 0);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_VERIFY_UPDATE))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_UPDATE_DATA_NULL:/*137-27*/
          {
              MacVerStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacVerifyUpdate(config3, NULL_PTR, 0);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_VERIFY_UPDATE))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_UPDATE_WHEN_START_FAIL:/*138-28*/
          {
              MacVerStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              Status = Cry_PrimStatus[CRY_HSM_MAC_VERIFY];
              Cry_PrimStatus[CRY_HSM_MAC_VERIFY] = CRY_HSM_PRIM_NOT_STARTED;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED) && (DetApiId == CRY_HSM_SID_MAC_VERIFY_UPDATE))
              {
                  MacVerStatus = 1;
              }
              Cry_PrimStatus[CRY_HSM_MAC_VERIFY] = Status;
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_FINISH_CFG_NULL:/*139 -29*/
          {
              MacVerStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MacVerResult  = CSM_E_VER_NOT_OK;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacVerifyFinish(NULL_PTR, TEST_CONST_MAC0, 16*8, &MacVerResult);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_VERIFY_FINISH))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_FINISH_MAC_PTR_NULL:/*140 -30*/
          {
              MacVerStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MacVerResult  = CSM_E_VER_NOT_OK;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacVerifyFinish(config3, NULL_PTR,16*8, &MacVerResult);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_VERIFY_FINISH))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_FINISH_RESULT_PTR_NULL:/*141-31*/
          {
              MacVerStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 16*8, NULL_PTR);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID) && (DetApiId == CRY_HSM_SID_MAC_VERIFY_FINISH))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_FINISH_START_NOT_INITIALIZED:/*142-32*/
          {
              MacVerStatus = 0;
              DetErrorId =0;
              DetApiId = 0;
              MacVerResult  = CSM_E_VER_NOT_OK;
              Status = Cry_PrimStatus[CRY_HSM_MAC_VERIFY];
              Cry_PrimStatus[CRY_HSM_MAC_VERIFY] = CRY_HSM_PRIM_NOT_STARTED;
              MAC_RetVal = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetVal = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 16*8, &MacVerResult);
              if((MAC_RetVal == CSM_E_NOT_OK) && (DetErrorId == CRY_HSM_E_SERVICE_NOT_STARTED) && (DetApiId == CRY_HSM_SID_MAC_VERIFY_FINISH))
              {
                  MacVerStatus = 1;
              }
              Cry_PrimStatus[CRY_HSM_MAC_VERIFY] = Status;
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#if ((CRY_HSM_MAC_SAFE_VERIFY == STD_OFF) && (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON))
          case  CRY_MAC_VER_SUCCESS1:/*143-33*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacVerResult  = CSM_E_VER_NOT_OK;
              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, &MacVerResult);
              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacVerResult == CSM_E_VER_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_SUCCESS2:/*144 34*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacVerResult  = CSM_E_VER_NOT_OK;
              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 10);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC_VER10, 60, &MacVerResult);
              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacVerResult == CSM_E_VER_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_SUCCESS_MULTI_UPDATES:/*145-35*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate1 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate2 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate3 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacVerResult  = CSM_E_VER_NOT_OK;
              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate1 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 16);
              MAC_RetValUpdate2 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 16);
              MAC_RetValUpdate3 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 8);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC_MUL2, 128, &MacVerResult);
              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate1 == CSM_E_OK) && (MAC_RetValUpdate2 == CSM_E_OK) && (MAC_RetValUpdate3 == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacVerResult == CSM_E_VER_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_INVALIDMAC:/*146-36*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacVerResult = CSM_E_VER_OK;
              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC_MUL2, 60, &MacVerResult);
              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacVerResult == CSM_E_VER_NOT_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_TIMEOUT:/*147-37*/
          {
              MacVerStatus = 1;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              BswMModuleId = 0;
              BswMErrorId = 0x0;
              MacVerResult  = CSM_E_VER_NOT_OK;
              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config4, TEST_CONST_PLAIN, 0);
              if((MAC_RetValStart != CSM_E_OK) || (MAC_RetValUpdate != CSM_E_NOT_OK) ||
                                    (BswMModuleId != CRY_MODULE_ID) || (BswMErrorId != HSMCOM_ERC_TIMEOUT))
              {
                  MacVerStatus = 0;
              }
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC_MUL2, 60, &MacVerResult);
              if(MAC_RetValFinish != CSM_E_BUSY)
              {
                  MacVerStatus = 0;
              }
              /*Give some delay in scripts so that in HSM side command will completed*/
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case CRY_MACVER_MULTI_UPDATE_CANCEL:
          {
              CancelRequired = 1;
              MacVerStatus = 0;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate1 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate2 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate1 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);
              MAC_RetValUpdate2 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 8);
              Gpt_StopTimer(Gptch_CancelCommand);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, &MacVerResult);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate1 == CSM_E_OK) && (MAC_RetValUpdate2 == CSM_E_NOT_OK) && (MAC_RetValFinish == CSM_E_NOT_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_VER_SUCCESS1 to check sesion is closed properly in last finish*/
          }
          case CRY_MACVER_UPDATE_CANCEL:
          {
              CancelRequired = 1;
              MacVerStatus = 0;
              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);

              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0);
              Gpt_StopTimer(Gptch_CancelCommand);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, &MacVerResult);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_NOT_OK) && (MAC_RetValFinish == CSM_E_NOT_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_VER_SUCCESS1 to check sesion is closed properly in last finish*/
          }
          case CRY_MACVER_UPDKEYEMPTY_FINISH_TIMEOUT :
          {

              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              Mac_BswMErrorIdUp = BswMErrorId;
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config2, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacVerResult);
              Mac_BswMErrorIdFin = BswMErrorId;

              if((Mac_BswMErrorIdUp == HSMCOM_ERC_KEY_EMPTY) && (Mac_BswMErrorIdFin == HSMCOM_ERC_TIMEOUT))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;

          }
          case CRY_MACVER_UPDKEYEMPTY_FINISH_CANCEL :
          {
              MacVerStatus     = 0;
              CancelRequired = 1;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              Mac_BswMErrorIdUp = BswMErrorId;

              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 10);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacVerResult);
              Mac_BswMErrorIdFin = BswMErrorId;
              Gpt_StopTimer(Gptch_CancelCommand);


              if((Mac_BswMErrorIdUp == HSMCOM_ERC_KEY_EMPTY) && (Mac_BswMErrorIdFin == HSMCOM_ERC_TIMEOUT))
              {
                  MacVerStatus = 1;
              }

              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#endif
#if ((CRY_HSM_MAC_SAFE_VERIFY == STD_OFF) && (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
          case  CRY_MAC_VER_SUCCESS1_ASYNC:/*148-38*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MacFinishNotify   = 0;
              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;
              MacVerResult  = CSM_E_VER_NOT_OK;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, &MacVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacVerResult == CSM_E_VER_OK)
                      && (MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult == CSM_E_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_INVALID_MAC:/*149-39*/
          {
              MacVerStatus     = 0;
              MacFinishNotify   = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;
              MacVerResult = CSM_E_VER_OK;

              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 10);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, &MacVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacVerResult == CSM_E_VER_NOT_OK)
                      && (MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult == CSM_E_OK) && (MacFinishNotify == 1))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_TIMEOUT_ASYNC:/*150-40*/
          {
              MacVerStatus = 1;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MacFinishNotify   = 0;
              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;
              MacVerResult = CSM_E_VER_NOT_OK;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config4, TEST_CONST_PLAIN, 10);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              if((MAC_RetValStart != CSM_E_OK) || (MAC_RetValUpdate != CSM_E_NOT_OK) ||
                      (MacCallBackStartResult != CSM_E_OK) || (MacCallBackUpdateResult != CSM_E_NOT_OK) ||
                                    (BswMModuleId != CRY_MODULE_ID) || (BswMErrorId != HSMCOM_ERC_TIMEOUT))
              {
                  MacVerStatus = 0;
              }
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, &MacVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              if((MAC_RetValFinish != CSM_E_BUSY) || (MacCallBackFinishResult != CSM_E_BUSY) || (MacFinishNotify != 1))
              {
                  MacVerStatus = 0;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_MULTI_UPDATE_CANCEL_ASYNC:
          {
              MacVerStatus     = 0;
              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult2 = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate1 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0x10);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MacCallBackUpdateResult2 = MacCallBackUpdateResult;

              MAC_RetValUpdate2 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              Cry_HsmSheCancel();
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, &MacVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if((MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult2 == CSM_E_OK) &&
                      (MacCallBackUpdateResult == CSM_E_NOT_OK) && (MacCallBackFinishResult == CSM_E_NOT_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_VER_SUCCESS1_ASYNC to check sesion is closed properly in last finish*/
          }
          case  CRY_MAC_VER_FINISH_CANCEL_ASYNC:
          {
              MacVerStatus     = 0;
              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, &MacVerResult);
              Cry_HsmSheCancel();
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if((MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult == CSM_E_NOT_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_VER_SUCCESS1_ASYNC to check sesion is closed properly in last finish*/
          }
          case CRY_MACVER_SAFE_UPDKEYEMPTY_FINISH_TIMEOUT_ASYNC :
          {

              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;


              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              Mac_BswMErrorIdUp = BswMErrorId;
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config2, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              Mac_BswMErrorIdFin = BswMErrorId;

              if((Mac_BswMErrorIdUp == HSMCOM_ERC_KEY_EMPTY) && (Mac_BswMErrorIdFin == HSMCOM_ERC_TIMEOUT))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;

          }
          case CRY_MACVER_SAFE_UPDKEYEMPTY_FINISH_CANCEL_ASYNC :
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              Mac_BswMErrorIdUp = BswMErrorId;

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              Mac_BswMErrorIdFin = BswMErrorId;

              if((Mac_BswMErrorIdUp == HSMCOM_ERC_KEY_EMPTY) && (Mac_BswMErrorIdFin == HSMCOM_ERC_TIMEOUT))
              {
                  MacVerStatus = 1;
              }

              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#endif
#if ((CRY_HSM_MAC_SAFE_VERIFY == STD_ON) && (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON))
          case  CRY_MAC_VER_SUCCESS_SAFE_SYNC1:/*151-41*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacSafeVerResult.Result = CSM_E_VER_NOT_OK;
              MacSafeVerResult.BitsCompared1 = 0;
              MacSafeVerResult.BitsCompared2 = 0;
              MacSafeVerResult.CodedResult1 = 0;
              MacSafeVerResult.CodedResult2 = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacSafeVerResult);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacSafeVerResult.Result == CSM_E_VER_OK)&&
                      (MacSafeVerResult.BitsCompared1 == 0x50) && (MacSafeVerResult.BitsCompared2 ==0xA0) && (MacSafeVerResult.CodedResult1 == 0xD696E2AD) &&
                      (MacSafeVerResult.CodedResult2 == 0x7C3C48F8) && (MacSafeVerResult.DataPtr == ((uint32)TEST_CONST_PLAIN ^ 0xFFFFFFFF)) &&
                      (MacSafeVerResult.DataLength == 0))
              {
                  MacVerStatus = 1;
              }
              /*Check CodedResult1 = 0xD696E2AD && CodedResult2 = 0x7C3C48F8 && BitsCompared1= 0x50 && BitsCompared2 = 0xA0 && MacVerStatus =1 through scripts*/
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_SUCCESS_SAFE_SYNC2:/*152-42*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacSafeVerResult.Result = CSM_E_VER_NOT_OK;
              MacSafeVerResult.BitsCompared1 = 0;
              MacSafeVerResult.BitsCompared2 = 0;
              MacSafeVerResult.CodedResult1 = 0;
              MacSafeVerResult.CodedResult2 = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 10);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC_VER10, 60, (Csm_VerifyResultType *)&MacSafeVerResult);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacSafeVerResult.Result == CSM_E_VER_OK)&&
                      (MacSafeVerResult.BitsCompared1 == 0x78) && (MacSafeVerResult.BitsCompared2 ==0xF0) && (MacSafeVerResult.CodedResult1 == 0x8F539C93) &&
                      (MacSafeVerResult.CodedResult2 ==0xD506C9C6)&& (MacSafeVerResult.DataPtr == ((uint32)TEST_CONST_PLAIN ^ 0xFFFFFFFF)) &&
                      (MacSafeVerResult.DataLength == 10*2))
              {
                  MacVerStatus = 1;
              }
              /*Check CodedResult1 = 0x8F539C93 && CodedResult2 = 0xD506C9C6 && BitsCompared1= 0x78 && BitsCompared2 = 0xF0 && MacVerStatus =1 through scripts*/
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_SUCCESS_SAFE_MULUP_SYNC3:/*153-43*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate1 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate2 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate3 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacSafeVerResult.Result = CSM_E_VER_NOT_OK;
              MacSafeVerResult.BitsCompared1 = 0;
              MacSafeVerResult.BitsCompared2 = 0;
              MacSafeVerResult.CodedResult1 = 0;
              MacSafeVerResult.CodedResult2 = 0;
              uint32 DataXorvalue;

              DataXorvalue = 0xFFFFFFFF;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate1 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0x10);
              DataXorvalue = (uint32)TEST_CONST_PLAIN ^ DataXorvalue;
              MAC_RetValUpdate2 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0x20);
              DataXorvalue = (uint32)TEST_CONST_PLAIN ^ DataXorvalue;
              MAC_RetValUpdate3 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 16);
              DataXorvalue = (uint32)TEST_CONST_PLAIN ^ DataXorvalue;
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC_MUL, 128, (Csm_VerifyResultType *)&MacSafeVerResult);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate1 == CSM_E_OK)&& (MAC_RetValUpdate2 == CSM_E_OK)&&
               (MAC_RetValUpdate3 == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacSafeVerResult.Result == CSM_E_VER_OK)&&
               (MacSafeVerResult.BitsCompared1 == 0x100) && (MacSafeVerResult.BitsCompared2 ==0x200) && (MacSafeVerResult.CodedResult1 == 0x5B23EAE9) &&
               (MacSafeVerResult.CodedResult2 ==0xE76BFBC)&& (MacSafeVerResult.DataPtr == DataXorvalue) &&
               (MacSafeVerResult.DataLength == (0x10+0x20+16)*2))
              {
                  MacVerStatus = 1;
              }
              /*Check CodedResult1 = 0x5B23EAE9 && CodedResult2 = 0xE76BFBC && BitsCompared1= 0x100 && BitsCompared2 = 0x200 && MacVerStatus =1 through scripts*/
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_INVALIDMAC_SAFE_SYNC4:/*154-44*//*Need to check by tri*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacSafeVerResult.Result = CSM_E_VER_OK;
              MacSafeVerResult.BitsCompared1 = 0;
              MacSafeVerResult.BitsCompared2 = 0;
              MacSafeVerResult.CodedResult1 = 0;
              MacSafeVerResult.CodedResult2 = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 10);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, (Csm_VerifyResultType *)&MacSafeVerResult);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacSafeVerResult.Result == CSM_E_VER_NOT_OK) &&
                      (MacSafeVerResult.BitsCompared1 == 0x0) && (MacSafeVerResult.BitsCompared2 ==0x0) && (MacSafeVerResult.CodedResult1 == 0x0) &&
                      (MacSafeVerResult.CodedResult2 ==0x0)&& (MacSafeVerResult.DataPtr == 0x0) &&
                      (MacSafeVerResult.DataLength == 0x0))

              {
                  MacVerStatus = 1;
              }
              /*Check CodedResult1 = 0x0?? && CodedResult2 = 0x0?? && BitsCompared1= 0x0?? && BitsCompared2 = 0x0?? && MacVerStatus =1 through scripts*/
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_TIMEOUT_SAFE_SYNC5:/*155-45*/
          {
              MacVerStatus     = 1;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config4, TEST_CONST_PLAIN, 0);
              if((MAC_RetValStart != CSM_E_OK) || (MAC_RetValUpdate != CSM_E_NOT_OK) ||
                                    (BswMModuleId != CRY_MODULE_ID) || (BswMErrorId != HSMCOM_ERC_TIMEOUT))
              {
                  MacVerStatus = 0;
              }
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 128, (Csm_VerifyResultType *)&MacSafeVerResult);
              if(MAC_RetValFinish != CSM_E_BUSY)
              {
                  MacVerStatus = 0;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MACVER_SAFE_MULTI_UPDATE_CANCEL:
          {
              CancelRequired = 1;
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate1 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate2 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate1 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 16);

              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);
              MAC_RetValUpdate2 = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 8);
              Gpt_StopTimer(Gptch_CancelCommand);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacSafeVerResult);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate1 == CSM_E_OK) && (MAC_RetValUpdate2 == CSM_E_NOT_OK) && (MAC_RetValFinish == CSM_E_NOT_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_VER_SUCCESS1_ASYNC to check sesion is closed properly in last finish*/
          }
          case  CRY_MACVER_SAFE_FINISH_CANCEL:
          {
              CancelRequired = 1;
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);

              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacSafeVerResult);
              Gpt_StopTimer(Gptch_CancelCommand);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_NOT_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_VER_SUCCESS1_ASYNC to check sesion is closed properly in last finish*/
          }
          case CRY_MACVER_SAFE_UPDKEYEMPTY_FINISH_TIMEOUT :
          {

              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacSafeVerResult.Result = CSM_E_VER_OK;
              MacSafeVerResult.BitsCompared1 = 0;
              MacSafeVerResult.BitsCompared2 = 0;
              MacSafeVerResult.CodedResult1 = 0;
              MacSafeVerResult.CodedResult2 = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              Mac_BswMErrorIdUp = BswMErrorId;
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config2, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacSafeVerResult);
              Mac_BswMErrorIdFin = BswMErrorId;

              if((Mac_BswMErrorIdUp == HSMCOM_ERC_KEY_EMPTY) && (Mac_BswMErrorIdFin == HSMCOM_ERC_TIMEOUT))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;

          }
          case CRY_MACVER_SAFE_UPDKEYEMPTY_FINISH_CANCEL :
          {
              MacVerStatus     = 0;
              CancelRequired = 1;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacSafeVerResult.Result = CSM_E_VER_OK;
              MacSafeVerResult.BitsCompared1 = 0;
              MacSafeVerResult.BitsCompared2 = 0;
              MacSafeVerResult.CodedResult1 = 0;
              MacSafeVerResult.CodedResult2 = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              Mac_BswMErrorIdUp = BswMErrorId;

              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacSafeVerResult);
              Mac_BswMErrorIdFin = BswMErrorId;
              Gpt_StopTimer(Gptch_CancelCommand);


              if((Mac_BswMErrorIdUp == HSMCOM_ERC_KEY_EMPTY) && (Mac_BswMErrorIdFin == HSMCOM_ERC_TIMEOUT))
              {
                  MacVerStatus = 1;
              }

              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#endif
          case  CRY_MAC_VER_TIMEOUT_COMPLETE_FINISH:
          {
              MacVerStatus = 0;
              MAC_RetValFinish2 = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish2 = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 128, &MacVerResult);
              #if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
              g_TestHsm_mac.callbackSet = 0;
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              #endif
              if(MAC_RetValFinish2 == CSM_E_OK)
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#if ((CRY_HSM_MAC_SAFE_VERIFY == STD_ON) && (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
          case  CRY_MAC_VER_SUCCESS_SAFE_ASYNC1:/*156-46*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MacFinishNotify   = 0;
              MacCallBackStartResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MacSafeVerResult.Result = CSM_E_VER_NOT_OK;
              MacSafeVerResult.BitsCompared1 = 0;
              MacSafeVerResult.BitsCompared2 = 0;
              MacSafeVerResult.CodedResult1 = 0;
              MacSafeVerResult.CodedResult2 = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 10);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC_VER10, 60, (Csm_VerifyResultType *)&MacSafeVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacSafeVerResult.Result == CSM_E_VER_OK)&&
                      (MacCallBackStartResult ==CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult ==CSM_E_OK )&& (MacFinishNotify == 1) &&
                      (MacSafeVerResult.BitsCompared1 == 0x78) && (MacSafeVerResult.BitsCompared2 == 0xF0) && (MacSafeVerResult.CodedResult1 == 0x8F539C93) &&
                      (MacSafeVerResult.CodedResult2 == 0xD506C9C6)&& (MacSafeVerResult.DataPtr == ((uint32)TEST_CONST_PLAIN ^ 0xFFFFFFFF)) &&
                      (MacSafeVerResult.DataLength == 10*2))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_INVALID_SAFE_ASYNC2:/*157-47*/
          {
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacFinishNotify   = 0;
              MacCallBackStartResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;

              MacSafeVerResult.Result = CSM_E_VER_OK;
              MacSafeVerResult.BitsCompared1 = 0;
              MacSafeVerResult.BitsCompared2 = 0;
              MacSafeVerResult.CodedResult1 = 0;
              MacSafeVerResult.CodedResult2 = 0;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 10);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, (Csm_VerifyResultType *)&MacSafeVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_OK) && (MAC_RetValFinish == CSM_E_OK) && (MacSafeVerResult.Result == CSM_E_VER_NOT_OK)&&
                      (MacCallBackStartResult ==CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult ==CSM_E_OK )&& (MacFinishNotify == 1) &&
                      (MacSafeVerResult.BitsCompared1 == 0x0) && (MacSafeVerResult.BitsCompared2 == 0x0) && (MacSafeVerResult.CodedResult1 == 0x0) &&
                      (MacSafeVerResult.CodedResult2 == 0x0)&& (MacSafeVerResult.DataPtr == 0x0) &&
                      (MacSafeVerResult.DataLength == 0x0))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_TIMEOUT_SAFE_ASYNC3:/*158-48*/
          {
              MacVerStatus     = 1;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacFinishNotify   = 0;
              MacCallBackStartResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config4, TEST_CONST_PLAIN, 64);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if((MAC_RetValStart != CSM_E_OK) || (MAC_RetValUpdate != CSM_E_NOT_OK) ||
                                    (BswMModuleId != CRY_MODULE_ID) || (BswMErrorId != HSMCOM_ERC_TIMEOUT))
              {
                  MacVerStatus = 0;
              }
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, (Csm_VerifyResultType *)&MacSafeVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              if((MAC_RetValFinish != CSM_E_BUSY) || (MacVerStatus != 1) || (MacFinishNotify != 1)|| (MacCallBackStartResult != CSM_E_OK) ||
                      (MacCallBackUpdateResult != CSM_E_NOT_OK) || (MacCallBackFinishResult != CSM_E_BUSY))
              {
                  MacVerStatus = 0;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
          case  CRY_MAC_VER_SAFE_MULTI_UPDATE_CANCEL_ASYNC:
          {
              MacVerStatus     = 0;
              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult2 = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 16);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
              MacCallBackUpdateResult2 = MacCallBackUpdateResult;

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              Cry_HsmSheCancel();
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, (Csm_VerifyResultType *)&MacSafeVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if((MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult2 == CSM_E_OK) &&
                      (MacCallBackUpdateResult == CSM_E_NOT_OK) && (MacCallBackFinishResult == CSM_E_NOT_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_VER_SUCCESS1_ASYNC to check sesion is closed properly in last finish*/
          }
          case  CRY_MAC_VER_SAFE_FINISH_CANCEL_ASYNC:
          {
              MacVerStatus     = 0;
              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, (Csm_VerifyResultType *)&MacSafeVerResult);
              Cry_HsmSheCancel();
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if((MacCallBackStartResult == CSM_E_OK) && (MacCallBackUpdateResult == CSM_E_OK) && (MacCallBackFinishResult == CSM_E_NOT_OK))
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
              /*Call CRY_MAC_VER_SUCCESS1_ASYNC to check sesion is closed properly in last finish*/
          }

          case  CRY_MAC_VER_CANCEL_TIMEOUT_ASYNC:
          {
              MacVerStatus     = 0;
              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0);
              Cry_HsmSheCancel();
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, (Csm_VerifyResultType *)&MacSafeVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_NOT_OK) && (MAC_RetValFinish == CSM_E_NOT_OK)
                      && BswMErrorId == HSMCOM_ERC_TIMEOUT )
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }

          case CRY_MAC_VER_CANCELTIMEOUT_CHK_UPDATE_ASYNC :
          {
              MacVerStatus     = 0;
              MacCallBackStartResult  = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackUpdateResult = CSM_E_ENTROPY_EXHAUSTION;
              MacCallBackFinishResult = CSM_E_ENTROPY_EXHAUSTION;
              g_TestHsm_mac.callbackSet = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 0);
              Cry_HsmSheCancel();
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 60, (Csm_VerifyResultType *)&MacSafeVerResult);
              TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);

              if(BswMErrorId == HSMCOM_ERC_GENERAL_FAILURE || BswMErrorId == HSMCOM_ERC_NO_ERROR)
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#endif
          case CRY_MAC_VER_CANCEL_TIMEOUT:
          {
              CancelRequired = 1;
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);

              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              Gpt_StopTimer(Gptch_CancelCommand);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacVerResult);

              if((MAC_RetValStart == CSM_E_OK) && (MAC_RetValUpdate == CSM_E_NOT_OK) && (MAC_RetValFinish == CSM_E_NOT_OK)
                      && BswMErrorId == HSMCOM_ERC_TIMEOUT )
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }

          case CRY_MAC_VER_CANCELTIMEOUT_CHK_UPDATE:
          {
              CancelRequired = 1;
              MacVerStatus     = 0;
              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_VERIFY_RAM_KEY);

              /*Start GPT timer */
              Gpt_EnableNotification(Gptch_CancelCommand);
              Gpt_StartTimer(Gptch_CancelCommand, 200);

              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, TEST_CONST_PLAIN, 64);
              Gpt_StopTimer(Gptch_CancelCommand);

              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3, TEST_CONST_MAC0, 40, (Csm_VerifyResultType *)&MacVerResult);

              if(BswMErrorId == HSMCOM_ERC_GENERAL_FAILURE || BswMErrorId == HSMCOM_ERC_NO_ERROR)
              {
                  MacVerStatus = 1;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#if ((CRY_HSM_MAC_SAFE_VERIFY == STD_ON) && (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON))
          case CRY_MAC_VER_RESERVED_INDATA_ADDR :
          {
              MacVerStatus = 1;

              MAC_RetValStart = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;

              MAC_RetValStart  = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValUpdate = CSM_E_ENTROPY_EXHAUSTION;
              MAC_RetValFinish = CSM_E_ENTROPY_EXHAUSTION;
              MacSafeVerResult.Result = CSM_E_VER_NOT_OK;
              MacSafeVerResult.BitsCompared1 = 0;
              MacSafeVerResult.BitsCompared2 = 0;
              MacSafeVerResult.CodedResult1 = 0;
              MacSafeVerResult.CodedResult2 = 0;
              MacSafeVerResult.DataPtr = 0;
              MacSafeVerResult.DataLength = 0;

              MAC_RetValStart = Cry_HsmAesCMacVerifyStart(config3, KEY_MAC_GENERATE_RAM_KEY);
              MAC_RetValUpdate = Cry_HsmAesCMacVerifyUpdate(config3, (uint8 *)0x80800000, 10);
              MAC_RetValFinish = Cry_HsmAesCMacVerifyFinish(config3,TEST_CONST_MAC_VER10,
                                                                    60, (Csm_VerifyResultType *)&MacSafeVerResult);

              if((MAC_RetValStart != CSM_E_OK) || (MAC_RetValUpdate != CSM_E_NOT_OK) || (MAC_RetValFinish != CSM_E_OK)
                  || (MacSafeVerResult.Result != CSM_E_VER_NOT_OK)|| (BswMErrorId != 0xFF)
                  || (MacSafeVerResult.BitsCompared1 != 0x0) || (MacSafeVerResult.BitsCompared2 != 0x0)||
                  MacSafeVerResult.DataPtr != 0x0 ||MacSafeVerResult.DataLength != 0x0)
              {
                  MacVerStatus = 0;
              }
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
#endif
          default:
          {
              TC_MAC = CRY_MAC_IDLE;
              break;
          }
      }
}
#endif

/*************************************************************************************//**
 * Execution of CMAC generation test suite
*//**************************************************************************************/
void TestHsm_generate_mac_Ram(void)
{
    TEST_PRINTF(" - Load plain key \n");
    {
        SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)TEST_CMAC_GEN_CONST_KEY,16);
    }
    TEST_PRINTF(" - Load plain key \n");
    {
        SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(HsmAes_Block *)TEST_CONST_KEY,16);
    }
#if (1)

    TEST_PRINTF("\nMAC generate #1: len = 0 bytes ----------------------- \n");
    GenerateMac(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 0, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTF("<empty string>\n");
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC0, 4)

    TEST_PRINTF("\nMAC generate #1: len = 0 bytes ---------------------- \n");
    GenerateMac(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 0, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTF("<empty string>\n");
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC0, 4)

    TEST_PRINTF("\nMAC generate #1: len = 64 bytes / (16+16+16+16+0) --- \n");
    GenerateMac_MulUpd11110(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 4)

    TEST_PRINTF("\nMAC generate #2: len = 16 bytes -------------------- \n");
    GenerateMac_MeasureTime(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 16, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,16);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC16, 4)

    TEST_PRINTF("\nMAC generate #3: len = 40 bytes ----------------------- \n");
    GenerateMac(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 40, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,40);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC40, 4)

    TEST_PRINTF("\nMAC generate #10: len = 64 bytes /(0+16+16+16+16) -- \n");
    GenerateMac_MulUpd(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 4)

    TEST_PRINTF("\nMAC generate #4: len = 64 bytes ------------------------- \n");
    GenerateMac(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 4)

    TEST_PRINTF("\nMAC generate #5: len = 64 bytes -> CMAC 11 bytes --------- \n");
    p = memset(TEST_HSM_BUF_TEMP_C, 0x5AU, 16);
    p = memset(TEST_HSM_BUF_TEMP_D, 0x5AU, 16);
    p = memcpy(TEST_HSM_BUF_TEMP_C, TEST_CONST_MAC64, 11);
    GenerateMac(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 11, TRUE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN, 64);
    TEST_PRINTF("CMAC       "); TEST_PRINTHEX(TEST_HSM_BUF_TEMP_D,11); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_HSM_BUF_TEMP_C, 4)

    TEST_PRINTF("\nMAC generate #6: len = 21 bytes ---------------------------- \n");
    GenerateMac(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 21, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,21);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC21, 4)

    TEST_PRINTF("\nMAC generate #3: len = 64 bytes /(16+16+0+16+16) ----------- \n");
    GenerateMac_MulUpd_11011(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 4)

    TEST_PRINTF("\nMAC generate #7: len = 22 bytes ---------------------------- \n");
    GenerateMac(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 22, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,22);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC22, 4)

    TEST_PRINTF("\nMAC generate #3: len = 64 bytes /(16+16+0+16+16) ------------- \n");
    GenerateMac_MulUpd_11011(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 4)

    TEST_PRINTF("\nMAC generate #8: len = 18 bytes / 32 Bit MAC------------------ \n");
    GenerateMac(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 18, TEST_HSM_BUF_TEMP_D, 4, TRUE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,18);
    TEST_PRINTF("CMAC       "); TEST_PRINTHEX(TEST_HSM_BUF_TEMP_D,4); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC18, 1)

    TEST_PRINTF("\nMAC generate #6: len = 64 bytes /(16+0+48)------------------- \n");
    GenerateMac_MulUpd2(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 4)

    TEST_PRINTF("\nMAC generate #14: len = 64 bytes / (16+32+0+16)------------ \n");
    GenerateMac_MulUpd3(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 12, TRUE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINTHEX(TEST_HSM_BUF_TEMP_D,12); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 3)

    TEST_PRINTF("\nMAC generate #15: Multiple updates / 0 +64 \n");
    GenerateMac_MulUpd2_ZeroCase(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 4)

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
    TEST_PRINTF("\nMAC generate #17: len = 64 bytes / Negative Test case ----- \n");
    GenerateMac_MulUpd_NegUpd(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_HSM_BUF_TEMP_E, 4)
#endif
#else
    TEST_PRINTF("\nMAC generate #2: len = 16 bytes -------------------- \n");
    GenerateMac_MeasureTime(KEY_MAC_GENERATE_RAM_KEY, TrngSeed, 16, TrngSeedCmac, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TrngSeed,16);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TrngSeedCmac); TEST_PRINTF("\n");
#endif
#if 0
    TEST_PRINTF("\nMAC generate #13: len = 64 bytes / Negative Test \n");
    GenerateMacNeg(KEY_MAC_GENERATE_RAM_KEY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_F, 13, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINTHEX(TEST_HSM_BUF_TEMP_F,8); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_F, TEST_CONST_MAC64, 2)

    TEST_PRINTF("\nMAC generate #9: len = 64 bytes -------------------------------- \n");
    GenerateMac(KEY_MAC_VERIFY, TEST_CONST_PLAIN, 64, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    TEST_PRINTF("M          "); TEST_PRINTHEX(TEST_CONST_PLAIN,64);
    TEST_PRINTF("CMAC       "); TEST_PRINT128(TEST_HSM_BUF_TEMP_D); TEST_PRINTF("\n");
    TEST_COMPARE(TEST_HSM_BUF_TEMP_D, TEST_CONST_MAC64, 4)
    #endif

}

boolean VerifyCmac(uint8 * key,const uint8 * SecurityKey)
{
    boolean result;

    SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(HsmAes_Block *)SecurityKey,16);

    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TrngSeed, key, 16, 16*8);

    return result;
}
/*************************************************************************************//**
 * Execution of CMAC verify test suite
*//**************************************************************************************/
void TestHsm_verify_mac_Ram(void)
{
    volatile boolean result;
    TEST_PRINTF(" - Load plain key \n");
    {
        SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(HsmAes_Block *)TEST_CONST_KEY,16);
    }

#if (CRY_HSM_MAC_SAFE_VERIFY == 1)
    TEST_PRINTF("\nCRY_HSM_MAC_SAFE_VERIFY is ON  ------------------------------- \n");
#else
    TEST_PRINTF("\nCRY_HSM_MAC_SAFE_VERIFY is OFF  ------------------------------- \n");
#endif

#if 1
    TEST_PRINTF("\nMAC verify #1: len = 0 bytes -------------------------------- \n");
    currentVerifyTimeStore = &TimeMacVerify0;
    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_CONST_MAC0,  0 , 16*8);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #2: len = 16 bytes / 16 byte MAC ----------------- \n");
/*    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify16; */
	/*Dio_WriteChannel(DioConf_DioChannel_DioChannel_Performance,STD_HIGH);*/
    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_CONST_MAC16, 16, 16*8);
	/*Dio_WriteChannel(DioConf_DioChannel_DioChannel_Performance,STD_LOW);*/
/*    STORE_TIME_DELTA(TimeMacVerify16); */
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #4: len = 40 bytes / 16 byte MAC ------------------ \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify40;
    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_CONST_MAC40, 40, 16*8);
    STORE_TIME_DELTA(TimeMacVerify40);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #4: len = 40 bytes / Incorrect Ref Mac ------------------ \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify40;
    result = VerifyMacNeg(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_CONST_MAC21, 40, 16*8);
    STORE_TIME_DELTA(TimeMacVerify40);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #5: len = 64 bytes / 16 byte MAC ------------------ \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify64;
    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_CONST_MAC64, 64, 16*8);
    STORE_TIME_DELTA(TimeMacVerify64);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #6: len = 21 bytes / 11 byte MAC ------------------ \n");
    HsmCom_SetArrayValue((uint32*)TEST_HSM_BUF_TEMP_C, 0, 4);
    p = memcpy(TEST_HSM_BUF_TEMP_C, TEST_CONST_MAC21, 11);
    TEST_VALIDATE(p != NULL_PTR)
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify21;
    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_C, 21, 11*8);
    STORE_TIME_DELTA(TimeMacVerify21);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #7: len = 22 bytes / 12 byte MAC ------------------ \n");
    /*HsmCom_SetArrayValue((uint32*)TEST_HSM_BUF_TEMP_C, 0, 4);
    p = memcpy(TEST_HSM_BUF_TEMP_C, TEST_CONST_MAC22, 12);
    TEST_VALIDATE(p != NULL_PTR)*/
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify22;
    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_CONST_MAC22, 22, 12*8);
    STORE_TIME_DELTA(TimeMacVerify22);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #8: len = 18 bytes  / 27 bits MAC ----------------- \n");
    HsmCom_SetArrayValue((uint32*)TEST_HSM_BUF_TEMP_C, 0, 4);
    p = memcpy(TEST_HSM_BUF_TEMP_C, TEST_CONST_MAC18, 4);
    TEST_VALIDATE(p != NULL_PTR)
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify18;
    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_C, 18, 4*8-5);
    STORE_TIME_DELTA(TimeMacVerify18);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #9: len = 16 bytes / 27 bits MAC -----------------  \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify16_2;
    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_CONST_MAC16, 16, 4*8-5);
    STORE_TIME_DELTA(TimeMacVerify16_2);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC verify #10: len = 18 bytes  / 32 bits MAC ----------------- \n");
    HsmCom_SetArrayValue((uint32*)TEST_HSM_BUF_TEMP_C, 0, 4);
    p = memcpy(TEST_HSM_BUF_TEMP_C, TEST_CONST_MAC18, 4);
    TEST_VALIDATE(p != NULL_PTR)
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify18_2;
    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_C, 18, 4*8);
    STORE_TIME_DELTA(TimeMacVerify18_2);
    TEST_VALIDATE(result != FALSE)

#if ( (CRY_HSM_MAC_SAFE_VERIFY == 0))
    TEST_PRINTF("\nMAC verify #3: len = 40 bytes/Incorrect Mac ----------- \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify40;
    result = VerifyMacNeg(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_CONST_MAC16, 40, 16*8);
    STORE_TIME_DELTA(TimeMacVerify40);
    TEST_VALIDATE(result != FALSE)

    TEST_PRINTF("\nMAC Verify #12: len = 64 bytes / (0+16+16++16+16)/---\n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify16_2;
    result = VerifyMacMulUpdZero(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_CONST_MAC64, 16, 69);
    STORE_TIME_DELTA(TimeMacVerify16_2);
    TEST_VALIDATE(result != FALSE)

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
    TEST_PRINTF("\nMAC Verify #13: len = 64 bytes / (16+16+30+8)---- \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify16_2;
    result = VerifyMacMulUpdNeg(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_CONST_MAC64, 16, 57);
    STORE_TIME_DELTA(TimeMacVerify16_2);
    TEST_VALIDATE(result != FALSE)
#endif

    TEST_PRINTF("\nMAC Verify #11: len = 64 bytes / (16+16+0+16+16)----- \n");
    GET_START_TIME();
    currentVerifyTimeStore = &TimeMacVerify16_2;
    result = VerifyMacMulUpd(KEY_MAC_VERIFY_RAM_KEY, TEST_CONST_PLAIN, TEST_HSM_BUF_TEMP_D, 16, 57);
    STORE_TIME_DELTA(TimeMacVerify16_2);
    TEST_VALIDATE(result != FALSE)
#endif

#if (CRY_HSM_MAC_SAFE_VERIFY == 1)
    TEST_PRINTF("\nMAC verify #10: len = 64 bytes  / 16 byte MAC ----------------- \n");
    TEST_PRINTF("\nCMAC update is called 4 times \n");
    result = Ssc_SafeMacVerifyMultipleUpdate(KEY_MAC_VERIFY_RAM_KEY,TEST_CONST_PLAIN,64,TEST_CONST_MAC64,16*8);
    TEST_VALIDATE(result != FALSE)
#endif
#else
    TEST_PRINTF("\nMAC verify #2: len = 16 bytes / 16 byte MAC ----------------- \n");
    result = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, TrngSeed, TrngSeedCmac, 16, 16*8);
    TEST_VALIDATE(result != FALSE)
#endif
}




#ifndef __WIN32__
#include "IfxStm_reg.h"

_IFXEXTERN_ IFX_INLINE uint32 HsmCom_getStmTick(void)
{
#if 0
    uint32 result;
    Ifx_STM *stm = &MODULE_STM0;

    result  = (uint32)stm->TIM0.U;
    //result |= ((uint64)stm->CAP.U) << 32;

    return result;
#endif
    return 0;
}


/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void TestHsm_mac_timing(void)
{
    int i;
    volatile boolean result;
    uint32 duration;
    if (g_TestHsm_mac.length == 0) {g_TestHsm_mac.length = 0x4000UL;}

    duration = HsmCom_getStmTick();
    GenerateMac(KEY_MAC_GENERATE, (void*)0x80000000, g_TestHsm_mac.length, TEST_HSM_BUF_TEMP_D, 16, FALSE);
    duration = HsmCom_getStmTick() - duration;
    g_TestHsm_mac.gen_duration[0] = duration;
    g_TestHsm_mac.gen_speed = 1.0 / (((float32)g_TestHsm_mac.gen_duration[0] / (float32)g_TestHsm_mac.length) / 100e-6);

    duration = HsmCom_getStmTick();
    result = VerifyMac(KEY_MAC_VERIFY, (void*)0x80000000, TEST_HSM_BUF_TEMP_D, g_TestHsm_mac.length, 16*8);
    duration = HsmCom_getStmTick() - duration;
    g_TestHsm_mac.ver_duration[0] = duration;
    g_TestHsm_mac.ver_speed = 1.0 / (((float32)g_TestHsm_mac.ver_duration[0] / (float32)g_TestHsm_mac.length) / 100e-6);



    for (i = 0; i < DUR_COUNT; i++)
    {
        g_TestHsm_mac.gen_duration[i] = HsmCom_getStmTick();
        GenerateMac(KEY_MAC_GENERATE, (void*)0x80000000, 8, TEST_HSM_BUF_TEMP_D, 8, TRUE);
        g_TestHsm_mac.gen_duration[i] = HsmCom_getStmTick() - g_TestHsm_mac.gen_duration[i];
    }
    for (i = 0; i < DUR_COUNT; i++)
    {
        g_TestHsm_mac.ver_duration[i] = HsmCom_getStmTick();
        result = VerifyMac(KEY_MAC_VERIFY, (void*)0x80000000, TEST_HSM_BUF_TEMP_D, 8, 8*8);
        g_TestHsm_mac.ver_duration[i] = HsmCom_getStmTick() - g_TestHsm_mac.ver_duration[i];
    }
    //UNUSED_PARAMETER(result);
}

#else
void TestHsm_mac_timing(void) {}
#endif
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
