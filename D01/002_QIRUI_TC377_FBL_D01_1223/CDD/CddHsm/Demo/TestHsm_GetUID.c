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
#include "Cry_HsmGetUID.h"
#if ITF
#include "Det.h"
#include "BswM.h"
#include "SampleCode.h"
#include "Cry_Hsm_priv.h"
#endif




#if ITF
#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

typedef enum{
CRY_GETUID_IDLE = 0,
CRY_GETUID_KEY_INIT,
CRY_GETUID_PARAM_CHALLENGEPTR_NULL,
CRY_GETUID_PARAM_UIDPTR_NULL,
CRY_GETUID_PARAM_SREGPTR_NULL,
CRY_GETUID_PARAM_MACPTR_NULL,
CRY_GETUID_UNINITIALIZED,
CRY_GETUID_TIMEOUT,
CRY_GETUID_CANCEL,
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
CRY_GETUID_SUCCESS1,
CRY_GETUID_INVSREG_SYNC,
CRY_GETUID_SUCCESS2,
#endif
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
CRY_GETUID_SUCCESS3,
CRY_GETUID_INVSREG_ASYNC,
CRY_GETUID_SUCCESS4,
CRY_GETUID_CANCEL_ASYNC,
#endif
CRY_GETUID_PARAM_CLEAR_OUTPUT_DATA
}Cry_GETUID_TestCase;

Cry_GETUID_TestCase CRY_GETUID_TC = CRY_GETUID_IDLE;
Csm_ReturnType TestHsm_error;
uint8 GetUIDStatus = 0;
Csm_ReturnType GetUID_RetVal;
Cry_PrimStatusVal GETUID_Status;
Csm_ReturnType GetUID_RetVal1;
uint8 Test_Statusreg = 0;

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

uint8 Test_Uid_Bytes[15] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint8 Test_Mac_Bytes[15] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif
typedef struct
{
    volatile uint8 callbackSet;
    uint32 length;
} TestHsm_Uid;

TestHsm_Uid g_TestHsm_uid = {0,0};

#define CRY_START_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
extern TestHsm_Uid g_TestHsm_uid;
#if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
Csm_ReturnType UidCallBackStartResult;
Csm_ReturnType UidCallBackUpdateResult;
Csm_ReturnType UidCallBackFinishResult;
Csm_ReturnType UidCallBackFinishResult1;
#endif
uint8 UidFinishNotify;
static uint8 MasterKeyInitFlag = 0;
#define CRY_STOP_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
const uint8 TEST_CMAC_GEN_CONST_MASTER[16] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};
const uint8 Test_Hsm_TempZeroMacBuf[16] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
const uint8 Test_Challenge_Bytes[16] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};
#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_GetUidCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
        {
            g_TestHsm_uid.callbackSet = 1;
        }
        else
        {
            g_TestHsm_uid.callbackSet = 2;
#if ITF
#else
            TEST_PRINTF("\n Uid failed in mainfunc with err code %d \n", result);
#endif
        }
#if ITF
    #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF

    switch(Cry_PrimStatusAsync[CRY_HSM_UID])
    {
      case ASYNC_STATE_START:
      {
         UidCallBackStartResult = result;
         break;
      }
      case ASYNC_STATE_UPDATE:
      {
         UidCallBackUpdateResult = result;
         break;
      }
      case ASYNC_STATE_FINISH:
      {
         UidCallBackFinishResult = result;
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
void Csm_GetUidServiceFinishNotification(void)
{
  #if ITF
  #if (CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF)
  UidFinishNotify = 1;
  #endif
  #endif
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
#if ITF == 0
extern void SampleCode_LoadPlainKey (HsmCom_KeyAddr KeyAddr,const HsmAes_Block *keyPtr,uint32 KeyLength);
#endif
extern void GenerateMac(const Csm_SymKeyType *keyPtr, const void* message,
        uint32 messageLength, void* macOut, uint32 macLength, boolean truncate);
void TestHsm_UIDGenerateMac()
{
  #if ITF
  SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(const HsmAes_Block *)TEST_CMAC_GEN_CONST_MASTER,16);
  #else
  SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,TEST_CMAC_GEN_CONST_MASTER,16);
  #endif
  GenerateMac(KEY_MAC_GENERATE_RAM_KEY, Test_Hsm_TempMacBuf, 32,
                                 Test_Hsm_TempGenMacBuf, 16, TRUE);
  #if ITF == 0
  TEST_PRINTF(" MERGED CHALLENGE, UID and SREG MESSAGES BYTES : \n");
  TEST_PRINTF("===============================================\n ");
  TEST_PRINTF("\n");
  TEST_PRINTHEX(Test_Hsm_TempMacBuf,32);
  TEST_PRINTF("\n");
  TEST_PRINTF(" RECEIVED MAC NUMBER:\n ");
  TEST_PRINTF("=====================\n ");
  TEST_PRINTHEX(Test_Hsm_TempMainMacBuf,16); TEST_PRINTF("\n");
  TEST_PRINTF(" GENERATED MAC NUMBER:\n ");
  TEST_PRINTF("======================\n ");
  TEST_PRINTHEX(Test_Hsm_TempGenMacBuf,16); TEST_PRINTF("\n");
  #endif

}

void TestHsm_GetUID()
{
  if(MasterKeyInitFlag == 0x00)
  {
    TEST_PRINTF("\n");
    TEST_PRINTF("When MASTER_ECU_KEY is Empty : ");
    TestHsm_GetUID_func();
    TestHsm_UIDinitializeMasterKeys();
    MasterKeyInitFlag = 0x99;
  }
  TEST_PRINTF("\n");
  TEST_PRINTF("When MASTER_ECU_KEY is loaded : ");
  TestHsm_GetUID_func();
  TestHsm_UIDGenerateMac();
}

void Merge_ChalUIDrSreg()
{
  uint8 Count1, Count2;
  for(Count1 = 0; Count1 < 16; Count1++ )
  {
    Test_Hsm_TempMacBuf[Count1] = TEST_CONST_CHALLENGE_BYTES[Count1];
  }
  Count2 = Count1;
  for(Count1 = 0; Count1 < 15; Count1++,Count2++ )
  {
    Test_Hsm_TempMacBuf[Count2] = Test_Hsm_TempUIDBuf[Count1];
  }
  Test_Hsm_TempMacBuf[Count2] = Test_Hsm_TempSregBuf[0];
}

void TestHsm_GetUID_func()
{
  Csm_ReturnType Test_error;
 /* static uint8 Sreg;
  static HsmAes_Block Mac;
  static HsmAes_Block UidReceived;*/
  /*HsmCom_Error comErr;*/
  /*Mac Data 16 bytes*/
  memset(Test_Hsm_TempMainMacBuf, 0xAA, 16);
  /*UID 15 bytes */
  memset(Test_Hsm_TempUIDBuf, 0xAA, 15);
    /*STATUS REGISTER 1 byte */
  memset(Test_Hsm_TempSregBuf, 0xAA, 1);
  TEST_PRINTF("Test GET UID -------------------------------\n");
  /*
  Test_error = Cry_HsmGetSheUID((uint8*)TEST_CONST_CHALLENGE_BYTES,(uint8*)&UidReceived,
                             (uint8*)&Sreg, (uint8*)&Mac);*/
  Test_error = Cry_HsmGetSheUID((uint8*)TEST_CONST_CHALLENGE_BYTES,(uint8*)Test_Hsm_TempUIDBuf,
                           (uint8*)Test_Hsm_TempSregBuf, (uint8*)Test_Hsm_TempMainMacBuf);

  TEST_VALIDATE(Test_error == CSM_E_OK)
  #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  TEST_WAIT(&Cry_HsmGetUIDMainFunction, &g_TestHsm_uid.callbackSet);
  #endif
  Merge_ChalUIDrSreg();
  TEST_PRINTF("\n");
  TEST_PRINTF("UID Data : ");
  TEST_PRINTHEX(Test_Hsm_TempUIDBuf, 15);
  TEST_PRINTF("\n");
  TEST_PRINTF("RECEIVED MAC NUMBER : ");
  TEST_PRINTHEX(Test_Hsm_TempMainMacBuf, 16);
  TEST_PRINTF("\n");
  TEST_PRINTF("STATUS REGISTER : ");
  TEST_PRINTHEX(Test_Hsm_TempSregBuf, 1);
  TEST_PRINTF("\n");
  TEST_PRINTF("ALLDATA : ");
  TEST_PRINTHEX(Test_Hsm_TempMacBuf, 32);
}

#if ITF
void GetUID_Parameter_Init(void);
static uint8 TestGetUID_testcd_VerifyData(uint8 *Actual, uint8 *TestData,uint32 Len);
static uint8 TestGetUID_testcd_VerifyData(uint8 *Actual, uint8 *TestData,uint32 Len)
{
    uint8 Result = 1;
    while(Len > 0)
    {
        if(*Actual != *TestData)
        {
            Result = 0;
            break;
        }
        Actual++;
        TestData++;
        Len--;
    }
    return Result;
}

void GetUID_Parameter_Init()
{
  uint8 Count1;
  GetUIDStatus = 0;
  GetUID_RetVal = CSM_E_ENTROPY_EXHAUSTION;
  GetUID_RetVal1 = CSM_E_ENTROPY_EXHAUSTION;
  DetErrorId = 99;
  DetApiId = 99;
  DetModuleId = 99;
  BswMErrorId =99;
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
  UidCallBackFinishResult1 = CSM_E_ENTROPY_EXHAUSTION;
#endif

  for(Count1 = 0; Count1 < 16; Count1++ )
  {
    Test_Hsm_TempUIDBuf[Count1] = 0x00;
    Test_Hsm_TempMainMacBuf[Count1] = 0x00;
  }
  for(Count1 = 0; Count1 < 4; Count1++ )
  {
    Test_Hsm_TempSregBuf[Count1] = 0x00;
  }

}
void ITF_GETUID()
{
  switch(CRY_GETUID_TC)
  {
      /**/
   case CRY_GETUID_KEY_INIT:
   {
     GetUID_Parameter_Init();
     if(MasterKeyInitFlag == 0x00)
     {
       TestHsm_UIDinitializeMasterKeys();
       MasterKeyInitFlag = 0x99;
     }
     CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
      break;
    case CRY_GETUID_PARAM_CHALLENGEPTR_NULL: /*CRY_UID_TC_01*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID(NULL_PTR, (uint8*)Test_Hsm_TempUIDBuf,
                  (uint8*)Test_Hsm_TempSregBuf,(uint8*)Test_Hsm_TempMainMacBuf);

      if((GetUID_RetVal == CSM_E_NOT_OK)
        && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)
        && (DetApiId == CRY_HSM_SID_GETUID))
      {
        GetUIDStatus = 1;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
    case CRY_GETUID_PARAM_UIDPTR_NULL: /*CRY_UID_TC_02*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)Test_Challenge_Bytes, NULL_PTR,
                  (uint8*)Test_Hsm_TempSregBuf, (uint8*)Test_Hsm_TempMainMacBuf);
      if((GetUID_RetVal == CSM_E_NOT_OK)
        && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)
        && (DetApiId == CRY_HSM_SID_GETUID))
      {
        GetUIDStatus = 1;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
    case CRY_GETUID_PARAM_SREGPTR_NULL: /*CRY_UID_TC_03*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)Test_Challenge_Bytes,
                      (uint8*)Test_Hsm_TempUIDBuf, NULL_PTR,
                      (uint8*)Test_Hsm_TempMainMacBuf);
      if((GetUID_RetVal == CSM_E_NOT_OK)
        && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)
        && (DetApiId == CRY_HSM_SID_GETUID))
      {
        GetUIDStatus = 1;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
    case CRY_GETUID_PARAM_MACPTR_NULL: /*CRY_UID_TC_04*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)Test_Challenge_Bytes,
                      (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                      NULL_PTR);
      if((GetUID_RetVal == CSM_E_NOT_OK)
        && (DetErrorId == CRY_HSM_E_PARAM_PTR_INVALID)
        && (DetApiId == CRY_HSM_SID_GETUID))
      {
        GetUIDStatus = 1;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
    case CRY_GETUID_UNINITIALIZED: /*CRY_UID_TC_05*/
    {
      GetUID_Parameter_Init();
      Cry_HsmInitStatus = CRY_HSM_UNINITIALIZED;
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)Test_Challenge_Bytes,
                      (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                      (uint8*)Test_Hsm_TempMainMacBuf);
      if((GetUID_RetVal == CSM_E_NOT_OK)
        && (DetErrorId == CRY_HSM_E_UNINIT)
        && (DetApiId == CRY_HSM_SID_GETUID))
      {
        GetUIDStatus = 1;
      }
      Cry_HsmInitStatus = CRY_HSM_INITIALIZED;
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;

    /* This Testcase is not applicable for this GETUID Functionality */
    case CRY_GETUID_TIMEOUT: /*CRY_UID_TC_06*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)Test_Challenge_Bytes,
                      (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                      (uint8*)Test_Hsm_TempMainMacBuf);
      if((GetUID_RetVal == CSM_E_NOT_OK)&&
              (BswMErrorId == HSMCOM_ERC_TIMEOUT))
      {
        GetUIDStatus = 1;
      }
      Cry_PrimStatus[CRY_HSM_UID] = GETUID_Status;
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
    /*CRY_SC_TC_24*/
    case CRY_GETUID_CANCEL :
    {
        GetUID_Parameter_Init();
        CancelRequired = 1;

        TestHsm_UIDinitializeMasterKeys();

        Gpt_EnableNotification(Gptch_CancelCommand);
        Gpt_StartTimer(Gptch_CancelCommand, 200);

       GetUID_RetVal = Cry_HsmGetSheUID((uint8*)Test_Challenge_Bytes,
                        (uint8*)Test_Uid_Bytes, &Test_Statusreg,
                        (uint8*)Test_Mac_Bytes);

        Gpt_StopTimer(Gptch_CancelCommand);

        GetUID_RetVal1 = Cry_HsmGetSheUID((uint8*)Test_Challenge_Bytes,
                        (uint8*)Test_Uid_Bytes, &Test_Statusreg,
                        (uint8*)Test_Mac_Bytes);
        if((GetUID_RetVal == CSM_E_NOT_OK) && (GetUID_RetVal1 == CSM_E_OK))
        {
            GetUIDStatus = 1;
        }
        CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_ON
    case CRY_GETUID_SUCCESS1: /*CRY_UID_TC_07*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)TEST_CONST_CHALLENGE_BYTES,
                      (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                      (uint8*)Test_Hsm_TempMainMacBuf);
      Merge_ChalUIDrSreg();
      TestHsm_UIDGenerateMac();
      GetUIDStatus = TestGetUID_testcd_VerifyData((uint8*)&Test_Hsm_TempGenMacBuf,
                                                  (uint8*)&Test_Hsm_TempMainMacBuf,
                                                      16);
      if((GetUID_RetVal == CSM_E_OK)
        && (GetUIDStatus == 1))
      {
        GetUIDStatus = 1;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
    case CRY_GETUID_INVSREG_SYNC: /*CRY_UID_TC_08*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)TEST_CONST_CHALLENGE_BYTES,
                      (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                      (uint8*)Test_Hsm_TempMainMacBuf);
      /* Invalid Sreg value */
      Test_Hsm_TempSregBuf[0] = 0x99;
      Merge_ChalUIDrSreg();
      TestHsm_UIDGenerateMac();
      GetUIDStatus = TestGetUID_testcd_VerifyData((uint8*)&Test_Hsm_TempGenMacBuf,
                                                  (uint8*)&Test_Hsm_TempMainMacBuf,
                                                      16);
      if((GetUID_RetVal == CSM_E_OK)
        && (GetUIDStatus == 0))
      {
        GetUIDStatus = 1;
      }
      else
      {
        GetUIDStatus = 0;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
    case CRY_GETUID_SUCCESS2: /*CRY_UID_TC_09*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)TEST_CONST_CHALLENGE_BYTES,
                      (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                      (uint8*)Test_Hsm_TempMainMacBuf);
      GetUIDStatus = TestGetUID_testcd_VerifyData((uint8*)&Test_Hsm_TempZeroMacBuf,
                                                  (uint8*)&Test_Hsm_TempMainMacBuf,
                                                      16);
      if((GetUID_RetVal == CSM_E_OK)
        && (GetUIDStatus == 1))
      {
        GetUIDStatus = 1;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
#endif
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    case CRY_GETUID_SUCCESS3: /*CRY_UID_TC_10*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)TEST_CONST_CHALLENGE_BYTES,
                      (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                      (uint8*)Test_Hsm_TempMainMacBuf);

        TEST_WAIT(&Cry_HsmGetUIDMainFunction, &g_TestHsm_uid.callbackSet);

      Merge_ChalUIDrSreg();
      TestHsm_UIDGenerateMac();
      GetUIDStatus = TestGetUID_testcd_VerifyData((uint8*)&Test_Hsm_TempGenMacBuf,
                                                  (uint8*)&Test_Hsm_TempMainMacBuf,
                                                      16);
      if((GetUID_RetVal == CSM_E_OK)
        && (GetUIDStatus == 1)&& (UidCallBackFinishResult == CSM_E_OK))
      {
        GetUIDStatus = 1;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;

    case CRY_GETUID_INVSREG_ASYNC: /*CRY_UID_TC_11*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)TEST_CONST_CHALLENGE_BYTES,
                      (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                      (uint8*)Test_Hsm_TempMainMacBuf);
      #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
        TEST_WAIT(&Cry_HsmGetUIDMainFunction, &g_TestHsm_uid.callbackSet);
      #endif
      /* Invalid Sreg value */
      Test_Hsm_TempSregBuf[0] = 0x99;
      Merge_ChalUIDrSreg();
      TestHsm_UIDGenerateMac();
      GetUIDStatus = TestGetUID_testcd_VerifyData((uint8*)&Test_Hsm_TempGenMacBuf,
                                                  (uint8*)&Test_Hsm_TempMainMacBuf,
                                                      16);
      if((GetUID_RetVal == CSM_E_OK)
        && (GetUIDStatus == 0)&& (UidCallBackFinishResult == CSM_E_OK))
      {
        GetUIDStatus = 1;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
    case CRY_GETUID_SUCCESS4: /*CRY_UID_TC_12*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID((uint8*)TEST_CONST_CHALLENGE_BYTES,
                      (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                      (uint8*)Test_Hsm_TempMainMacBuf);
      #if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
        TEST_WAIT(&Cry_HsmGetUIDMainFunction, &g_TestHsm_uid.callbackSet);
      #endif
      GetUIDStatus = TestGetUID_testcd_VerifyData((uint8*)&Test_Hsm_TempZeroMacBuf,
                                                 (uint8*)&Test_Hsm_TempMainMacBuf,
                                                        16);
      if((GetUID_RetVal == CSM_E_OK)
        && (GetUIDStatus == 1)&& (UidCallBackFinishResult == CSM_E_OK))
      {
        GetUIDStatus = 1;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
    /*CRY_SC_TC_25*/
    case CRY_GETUID_CANCEL_ASYNC :
    {
        GetUID_Parameter_Init();

        TestHsm_UIDinitializeMasterKeys();

        GetUID_RetVal = Cry_HsmGetSheUID((uint8*)TEST_CONST_CHALLENGE_BYTES,
                        (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                        (uint8*)Test_Hsm_TempMainMacBuf);

        Cry_HsmSheCancel();

        TEST_WAIT(&Cry_HsmGetUIDMainFunction, &g_TestHsm_uid.callbackSet);

        UidCallBackFinishResult1 = UidCallBackFinishResult;

        GetUID_RetVal = Cry_HsmGetSheUID((uint8*)TEST_CONST_CHALLENGE_BYTES,
                        (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                        (uint8*)Test_Hsm_TempMainMacBuf);
        TEST_WAIT(&Cry_HsmGetUIDMainFunction, &g_TestHsm_uid.callbackSet);

        if((UidCallBackFinishResult1 == CSM_E_NOT_OK) &&(UidCallBackFinishResult == CSM_E_OK))
        {
            GetUIDStatus = 1;
        }
        CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
    break;
#endif
    case CRY_GETUID_PARAM_CLEAR_OUTPUT_DATA: /*CRY_UID_TC_13*/
    {
      GetUID_Parameter_Init();
      GetUID_RetVal = Cry_HsmGetSheUID(NULL_PTR,
                      (uint8*)Test_Hsm_TempUIDBuf,(uint8*)Test_Hsm_TempSregBuf,
                      (uint8*)Test_Hsm_TempMainMacBuf);
      GetUIDStatus = TestGetUID_testcd_VerifyData((uint8*)&Test_Hsm_TempZeroMacBuf,
                                                  (uint8*)&Test_Hsm_TempUIDBuf,
                                                      15);
      if((GetUID_RetVal == CSM_E_NOT_OK)
        && (GetUIDStatus == 1))
      {
        GetUIDStatus = 1;
      }
      CRY_GETUID_TC = CRY_GETUID_IDLE;
    }
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
