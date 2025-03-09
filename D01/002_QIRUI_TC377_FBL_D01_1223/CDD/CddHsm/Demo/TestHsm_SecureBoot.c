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
#include <string.h>
#include "Cry_HsmSecureBoot.h"
#if ITF
#include "Det.h"
#include "BswM.h"
#include "SampleCode.h"
#include "Cry_Hsm_priv.h"
#endif
#if (CRY_HSM_SECURE_BOOT == STD_ON)
#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#if ITF
typedef enum{
CRY_SECUREBOOT_IDLE = 0,
CRY_SECBOOT_FAILURE_UNINITIALIZED,
CRY_SECBOOT_OK_UNINITIALIZED,
CRY_SECBOOT_EMPTYKEY,
CRY_SECBOOT_FAILURE_LOADKEY_SBPENABLED,
CRY_SECBOOT_OK_LOADKEY_SBPENABLED,
CRY_SECBOOT_LOAD_BOOTMACKEY,
CRY_SECBOOT_RESET1,
CRY_SECBOOT_RESET2,
CRY_SECBOOT_AFTER_FIRSTRESET,
CRY_SECBOOT_ENC_SECUREBOOTENABLE,
CRY_SECBOOT_FAILURE,
CRY_SECBOOT_OK
}Cry_SecureBoot_TestCase;
Cry_SecureBoot_TestCase CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
#endif


typedef struct
{
    volatile uint8 callbackSet;
    uint32 length;
} TestHsm_SecBoot;
TestHsm_SecBoot g_TestHsm_BootFailure = {0,0};
TestHsm_SecBoot g_TestHsm_BootOk = {0,0};
Csm_ReturnType BootCallBackStartResult;
Csm_ReturnType BootCallBackUpdateResult;
Csm_ReturnType BootCallBackFinishResult;
Csm_ReturnType BootOkCallBackStartResult;
Csm_ReturnType BootOkCallBackUpdateResult;
Csm_ReturnType BootOkCallBackFinishResult;
uint8 BootFailureFinishNotify;
uint8 BootOkFinishNotify;
uint32 GetHSM2HTSStatus = 0;
uint32 GetSecBootStatus = 0;
Csm_ReturnType ITF_SecBoot_retVal = 0 ;
Csm_ReturnType ITF_SecBoot_retVal1 = 0 ;
Csm_ReturnType  SecBoot_EncretVal1 = 0;
Csm_ReturnType  SecBoot_EncretVal2 = 0;
Csm_ReturnType  SecBoot_EncretVal3 = 0;
uint32 SecBoot_EncoutputLength;
Csm_ReturnType RetBootFailure;
Csm_ReturnType RetBootOk;
#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/


/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Test_SheBootOk(void)
{
  Csm_ReturnType Test_error;
  Test_error = Cry_HsmSheBootOk();
  TEST_VALIDATE(Test_error == CSM_E_OK)
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  TEST_WAIT(&Cry_HsmBootOkMainFunction, &g_TestHsm_BootOk.callbackSet);
  Test_error = RetBootOk;
  #endif
  if(Test_error == CSM_E_OK)
  {
      TEST_PRINTF("\n\nCry_HsmSheBootOk function return value is CSM_E_OK\n\n");
  }
}
void Test_SheBootFailure(void)
{
  Csm_ReturnType Test_error;
  Test_error = Cry_HsmSheBootFailure();
  TEST_VALIDATE(Test_error == CSM_E_OK)
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  TEST_WAIT(&Cry_HsmBootFailureMainFunction, &g_TestHsm_BootFailure.callbackSet);
  Test_error = RetBootFailure;
  #endif
  if(Test_error == CSM_E_OK)

  {
      TEST_PRINTF("\n\nCry_HsmSheBootFailure function return value is CSM_E_OK\n\n");
  }
}



void Csm_BootFailureCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
        {
          g_TestHsm_BootFailure.callbackSet = 1;
          RetBootFailure = CSM_E_OK;
        }
        else
        {
          g_TestHsm_BootFailure.callbackSet = 2;
          RetBootFailure = CSM_E_NOT_OK;
#if ITF
#else
            TEST_PRINTF("\n BootFailure failed in mainfunc with err code %d \n", result);
#endif
        }
#if ITF
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF

    switch(Cry_PrimStatusAsync[CRY_HSM_BOOT_FAILURE])
    {
      case ASYNC_STATE_START:
      {
         BootCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
         BootCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
         BootCallBackFinishResult = result;
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

void Csm_BootOkCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
        {
          g_TestHsm_BootOk.callbackSet = 1;
          RetBootOk = CSM_E_OK;
        }
        else
        {
          g_TestHsm_BootOk.callbackSet = 2;
          RetBootOk = CSM_E_NOT_OK;
#if ITF
#else
            TEST_PRINTF("\n BootFailure failed in mainfunc with err code %d \n", result);
#endif
        }
#if ITF
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF

    switch(Cry_PrimStatusAsync[CRY_HSM_BOOT_FAILURE])
    {
      case ASYNC_STATE_START:
      {
         BootOkCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
         BootOkCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
         BootOkCallBackFinishResult = result;
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

void Csm_BootFailureServiceFinishNotification(void)
{
  #if ITF
  #if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
  BootFailureFinishNotify = 1;
  #endif
  #endif
}

void Csm_BootOkServiceFinishNotification(void)
{
  #if ITF
  #if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
  BootOkFinishNotify = 1;
  #endif
  #endif
}
void SecBootParameter_Init(void);
void SecBootParameter_Init(void)
{
    GetSecBootStatus = 0;
    ITF_SecBoot_retVal = CSM_E_ENTROPY_EXHAUSTION ;
    ITF_SecBoot_retVal1 = CSM_E_ENTROPY_EXHAUSTION ;
    GetHSM2HTSStatus = 0xFF;
    SecBoot_EncretVal1 = CSM_E_ENTROPY_EXHAUSTION;
    SecBoot_EncretVal2 = CSM_E_ENTROPY_EXHAUSTION;
    SecBoot_EncretVal3 = CSM_E_ENTROPY_EXHAUSTION;
}

#if ITF
void ITF_SECUREBOOT(void)
{
  const void *input;
  void *output ;
  uint32 inputLength;
  const Cry_HsmAesEcbEncryptConfigType* config;
  config = &Cry_kHsmAesEcbEncryptConfig;
  inputLength = sizeof(TEST_CONST_ECB_CIPH);
  SecBoot_EncoutputLength = inputLength;
  input=TEST_CONST_PLAIN;
  output =TEST_HSM_BUF_TEMP_A;
  switch(CRY_SECUREBOOT_TC)
  {
      /**/
    case CRY_SECBOOT_FAILURE_UNINITIALIZED:
      SecBootParameter_Init();
      Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
      ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
      if((DetErrorId == CRY_HSM_E_UNINIT ) && (DetApiId == CRY_HSM_SID_BOOT_FAILURE) && (DetModuleId ==CSM_MODULE_ID))
      {
          GetSecBootStatus = 1;
      }
      else
      {
          GetSecBootStatus = 0;
      }
      Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    case CRY_SECBOOT_OK_UNINITIALIZED:
      SecBootParameter_Init();
      Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
      ITF_SecBoot_retVal = Cry_HsmSheBootOk();
      if((DetErrorId == CRY_HSM_E_UNINIT ) && (DetApiId == CRY_HSM_SID_BOOT_OK) && (DetModuleId ==CSM_MODULE_ID))
      {
          GetSecBootStatus = 1;
      }
      else
      {
          GetSecBootStatus = 0;
      }
      Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    case CRY_SECBOOT_EMPTYKEY:
      SecBootParameter_Init();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
      if(GetHSM2HTSStatus == 0x00 )
      {
          GetSecBootStatus = 1;
      }
      else
      {
          GetSecBootStatus = 0;
      }
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    case CRY_SECBOOT_FAILURE_LOADKEY_SBPENABLED:
      SecBootParameter_Init();
      TestHsm_SecBootinitializeStandardKeys();
      #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
      ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
      SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
      SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
      SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
      #else
      ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
      SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

      SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

      SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
      #endif
      if((SecBoot_EncretVal1==CSM_E_OK) && (SecBoot_EncretVal2==CSM_E_OK) && (SecBoot_EncretVal3 ==CSM_E_OK) &&
           (GetHSM2HTSStatus == 0x00 )&&(ITF_SecBoot_retVal != CSM_E_OK ))
      {
          GetSecBootStatus = 1;
      }
      else
      {
          GetSecBootStatus = 0;
      }
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    case CRY_SECBOOT_OK_LOADKEY_SBPENABLED:
      SecBootParameter_Init();
      TestHsm_SecBootinitializeStandardKeys();
      #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
      ITF_SecBoot_retVal = Cry_HsmSheBootOk();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
      SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
      SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
      SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
      #else
      ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

      SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

      SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
      #endif
      if((SecBoot_EncretVal1==CSM_E_OK) && (SecBoot_EncretVal2==CSM_E_OK) && (SecBoot_EncretVal3 ==CSM_E_OK) &&
           (GetHSM2HTSStatus == 0x00 )&&(ITF_SecBoot_retVal != CSM_E_OK ))
      {
          GetSecBootStatus = 1;
      }
      else
      {
          GetSecBootStatus = 0;
      }
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    case CRY_SECBOOT_LOAD_BOOTMACKEY:
      SecBootParameter_Init();
      TestHsm_SecBootinitializeStandardKeys();
      TestHsm_initializeBootMacKey();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
      if(GetHSM2HTSStatus == 0x00 )
      {
          GetSecBootStatus = 1;
      }
      else
      {
          GetSecBootStatus = 0;
      }
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    case CRY_SECBOOT_RESET1:
      SecBootParameter_Init();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
      if(GetHSM2HTSStatus == 0x0E )
      {
          GetSecBootStatus = 1;
      }
      else
      {
          GetSecBootStatus = 0;
      }
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    case CRY_SECBOOT_RESET2:
      SecBootParameter_Init();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
      if(GetHSM2HTSStatus == 0x12 )
      {
          GetSecBootStatus = 1;
      }
      else
      {
          GetSecBootStatus = 0;
      }
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    case CRY_SECBOOT_AFTER_FIRSTRESET:
      SecBootParameter_Init();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
      #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
      ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
      ITF_SecBoot_retVal1 = Cry_HsmSheBootOk();
      SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
      SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
      SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
      #else
      ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
      ITF_SecBoot_retVal1 = Cry_HsmSheBootOk();
      SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

      SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

      SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
      #endif
      if((SecBoot_EncretVal1 != CSM_E_OK) && (SecBoot_EncretVal2 != CSM_E_OK) && (SecBoot_EncretVal3 != CSM_E_OK) &&
           (GetHSM2HTSStatus == 0x0E )&&(ITF_SecBoot_retVal != CSM_E_OK )&&(ITF_SecBoot_retVal1 != CSM_E_OK ))
      {
          GetSecBootStatus = 1;
      }
      else
      {
          GetSecBootStatus = 0;
      }
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
      break;
    case CRY_SECBOOT_ENC_SECUREBOOTENABLE:
      SecBootParameter_Init();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
      #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
      SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
      SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
      SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
      #else
      SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

      SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);

      SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
      TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
      #endif
      if((SecBoot_EncretVal1==CSM_E_OK) && (SecBoot_EncretVal2==CSM_E_OK) && (SecBoot_EncretVal3 ==CSM_E_OK) &&
           (GetHSM2HTSStatus == 0x12 ))
      {
          GetSecBootStatus = 1;
      }
      else
      {
          GetSecBootStatus = 0;
      }
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    case CRY_SECBOOT_FAILURE:
      SecBootParameter_Init();
      GetHSM2HTSStatus = Cry_HsmGetStatus();
      GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
      if (GetHSM2HTSStatus == 0x12)
      {
        #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
        ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
        if(ITF_SecBoot_retVal == CSM_E_OK )
        {
          GetSecBootStatus = 1;
          ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
        }
        ITF_SecBoot_retVal1 = Cry_HsmSheBootOk();
        SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
        SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
        SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
        #else
        ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
        if(ITF_SecBoot_retVal == CSM_E_OK )
        {
          GetSecBootStatus = 1;
          ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
        }
        ITF_SecBoot_retVal1 = Cry_HsmSheBootOk();
        SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
        TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
        SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
        TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
        SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
        TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
        #endif
        GetHSM2HTSStatus = Cry_HsmGetStatus();
        GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
        if((SecBoot_EncretVal1 ==CSM_E_OK) && (SecBoot_EncretVal2 != CSM_E_OK) && (SecBoot_EncretVal3 == CSM_E_OK) &&
           (GetSecBootStatus == 0x01 )&& (ITF_SecBoot_retVal != CSM_E_OK)&& (ITF_SecBoot_retVal1 != CSM_E_OK) &&
           (GetHSM2HTSStatus == 0x0a))
        {
            GetSecBootStatus = 1;
        }
        else
        {
          GetSecBootStatus = 0;
        }
      }
      else
      {
          GetSecBootStatus = 0;
      }
      CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    case CRY_SECBOOT_OK:
          SecBootParameter_Init();
          GetHSM2HTSStatus = Cry_HsmGetStatus();
          GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
          if (GetHSM2HTSStatus == 0x12)
          {
            #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
            ITF_SecBoot_retVal = Cry_HsmSheBootOk();
            if(ITF_SecBoot_retVal == CSM_E_OK )
            {
              GetSecBootStatus = 1;
              ITF_SecBoot_retVal = Cry_HsmSheBootOk();
            }
            ITF_SecBoot_retVal1 = Cry_HsmSheBootFailure();
            SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
            SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
            SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
            #else
            ITF_SecBoot_retVal = Cry_HsmSheBootFailure();
            GetHSM2HTSStatus = Cry_HsmGetStatus();
            SecBoot_EncretVal1 = Cry_HsmAesEcbEncryptStart(config, KEY_ENCRYPTION_SBPENABLE);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
            SecBoot_EncretVal2 = Cry_HsmAesEcbEncryptUpdate(config, input, inputLength, output, &SecBoot_EncoutputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
            SecBoot_EncretVal3 = Cry_HsmAesEcbEncryptFinish(config, output, &SecBoot_EncoutputLength);
            TEST_WAIT(&Cry_HsmAesEcbEncryptMainFunction, &g_TestHsm_ecb.callbackSet);
            #endif
            GetHSM2HTSStatus = Cry_HsmGetStatus();
            GetHSM2HTSStatus = 0x40 ^ GetHSM2HTSStatus;
            if((SecBoot_EncretVal1 ==CSM_E_OK) && (SecBoot_EncretVal2 == CSM_E_OK) && (SecBoot_EncretVal3 == CSM_E_OK) &&
               (GetSecBootStatus == 0x01 )&& (ITF_SecBoot_retVal != CSM_E_OK)&& (ITF_SecBoot_retVal1 != CSM_E_OK) &&
               (GetHSM2HTSStatus == 0x1a))
            {
                GetSecBootStatus = 1;
            }
            else
            {
              GetSecBootStatus = 0;
            }
          }
          else
          {
              GetSecBootStatus = 0;
          }
          CRY_SECUREBOOT_TC = CRY_SECUREBOOT_IDLE;
    break;
    default:
    {

    }
    break;
  }
}
#endif
/*************************************************************************************//**
 * Execution of random number generator test suite
*//**************************************************************************************/
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
#endif
