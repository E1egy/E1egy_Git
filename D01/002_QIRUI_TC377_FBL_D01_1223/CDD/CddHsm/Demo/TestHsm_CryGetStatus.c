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
#if ITF


#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

boolean GetStaus_ErrorCheck =0;
uint8 GetStatusDebugStartChallenge ;
uint32 Ret;
HsmAes_Block GetStatusUidData;
Csm_ReturnType GetStatus_error1;
Csm_ReturnType GetStatus_error2;
Csm_ReturnType GetStatus_error3;
Csm_ReturnType CryDebugStartRet;
Csm_ReturnType CryDebugFinishRet;
uint32 Cry_MAC_Length =16;

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
typedef enum{
GET_STATUS_EXTDEBUGGER_SET,
GET_STATUS_EXTDEBUGGER_RESET,
GET_STATUS_INTDEBUGGER_SET,
GET_STATUS_INTDEBUGGER_RESET,
GET_STATUS_RND_INIT_BIT_RESET,
GET_STATUS_RND_INIT_BIT_SET,
GET_STATUS_BUSY_BIT_SET,
GET_STATUS_BUSY_BIT_RESET,
CRY_GET_STATUS_IDLE
}Cry_GetStatus_TestCase;
Cry_GetStatus_TestCase CRY_GTSTATUS_TC = CRY_GET_STATUS_IDLE;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#endif
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
void TestHsm_Get_Status()
{
  /*HsmCom_Error comErr;*/
  /*Mac Data 16 bytes*/
  memset(TEST_HSM_BUF_TEMP_A, 0xAA, 4);
  TEST_PRINTF("\n---------------------Test GET Status -------------------------------\n");
  TEST_HSM_BUF_TEMP_A[0] = Cry_HsmGetStatus();
  TEST_PRINTF("\n");
  TEST_PRINTF("GET Status: ");
  TEST_PRINTHEX(TEST_HSM_BUF_TEMP_A, 1);
}




#if ITF
void GetStatusParameter_Init()
{
  GetStaus_ErrorCheck =0;
  Ret = 0 ;
  GetStatus_error1 = CSM_E_OK;
  GetStatus_error2 = CSM_E_OK;
  GetStatus_error3 = CSM_E_OK;
}

void ITF_GetStatus()
{
  static uint8 CRY_GTSTATUS_TC_status = 0;
  const Cry_HsmRandomSeedInitConfigType* GetStatusSeedInitconfig;
  const Cry_HsmAesCMacGenerateConfigType* MacGenconfig;
  const Cry_HsmAesCMacGenerateConfigType  Cry_kHsmAesCMacGenerateConfigLessTime =
               {.TimeOut =   {.TimeoutStart = 0,
                       .TimeoutUpdateConst = 0,
                       .TimeoutUpdateperByte = 0,
                       .TimeoutFinish = 0 }  };
  const Cry_HsmAesCMacGenerateConfigType* MacGenconfig1 = &Cry_kHsmAesCMacGenerateConfigLessTime;
  MacGenconfig = &Cry_HsmAesCMacGenerateConfig;
  GetStatusSeedInitconfig = &Cry_kHsmRandomSeedInitConfig;
  switch(CRY_GTSTATUS_TC)
  {
    /* on the power on reset . Test case to check if the busy bit is reset*/
    case GET_STATUS_BUSY_BIT_RESET :
    {
      GetStatusParameter_Init();
      Ret = Cry_HsmGetStatus();

      if((Ret & 0x01) == 0x00)
      {
          GetStaus_ErrorCheck = 1;
      }
      CRY_GTSTATUS_TC = CRY_GET_STATUS_IDLE;
    }
    break;
     /*test case to check if the busy bit is set */
    case GET_STATUS_BUSY_BIT_SET :
    {
      if (CRY_GTSTATUS_TC_status == 0)
      {
        GetStatusParameter_Init();
        GetStatus_error1 = Cry_HsmAesCMacGenerateStart(MacGenconfig, KEY_MAC_GENERATE_RAM_KEY);
        GetStatus_error2 = Cry_HsmAesCMacGenerateUpdate(MacGenconfig1, TEST_CONST_PLAIN, 16);
        GetStatus_error3 = Cry_HsmAesCMacGenerateFinish(MacGenconfig, (uint8 *)TEST_HSM_BUF_TEMP_D,&Cry_MAC_Length, FALSE);
        Ret = Cry_HsmGetStatus();
        CRY_GTSTATUS_TC_status = 0x01;
      }
      else
      {
        if(GetStatus_error3 == CSM_E_BUSY)
        {
          GetStatus_error3 = Cry_HsmAesCMacGenerateFinish(MacGenconfig, (uint8 *)TEST_HSM_BUF_TEMP_D,&Cry_MAC_Length, FALSE);
        }
        else
        {
          if((Ret & 0x01) == 0x01)
          {
            GetStaus_ErrorCheck = 1;
          }
          CRY_GTSTATUS_TC = CRY_GET_STATUS_IDLE;
          CRY_GTSTATUS_TC_status = 0x00;
        }
      }
    }
    break;
    /*test case to check if the 5th bit is reset */
    case GET_STATUS_RND_INIT_BIT_RESET:
    {
      GetStatusParameter_Init();
      Ret = Cry_HsmGetStatus();
      if((Ret & 0x20) == 0x00)
      {
          GetStaus_ErrorCheck = 1;
      }
      CRY_GTSTATUS_TC = CRY_GET_STATUS_IDLE;
    }
    break;
    /*test case to check if the rnd init bit is set */
    case GET_STATUS_RND_INIT_BIT_SET:
    {
      GetStatusParameter_Init();
      GetStatus_error1 = Cry_HsmRandomSeedInitStart(GetStatusSeedInitconfig);
      GetStatus_error2 = Cry_HsmRandomSeedInitUpdate(GetStatusSeedInitconfig, NULL_PTR, 0);
      Ret = Cry_HsmGetStatus();
      GetStatus_error3 = Cry_HsmRandomSeedInitFinish(GetStatusSeedInitconfig);
      if((Ret & 0x20) == 0x20)
      {
        GetStaus_ErrorCheck = 1;
      }
      CRY_GTSTATUS_TC = CRY_GET_STATUS_IDLE;
    }
    break;
    /* To be tested when debugger is not connected*/
    case GET_STATUS_EXTDEBUGGER_RESET:
    {
      GetStatusParameter_Init();
      /* Manually change the status register bit 6 to zero by calling HsmMcal_SetHsm2HtFlag to zero*/
      /*get status and read 6th bit*/
      Ret = Cry_HsmGetStatus();
      if((Ret & 0x40) == 0x00)
      {
        GetStaus_ErrorCheck = 1;
      }
      CRY_GTSTATUS_TC = CRY_GET_STATUS_IDLE;
    }
    break;
    /* To be tested when the debugger is connected */
    case GET_STATUS_EXTDEBUGGER_SET:
    {
      GetStatusParameter_Init();
      Ret = Cry_HsmGetStatus();
      if((Ret & 0x40) == 0x40)
      {
          GetStaus_ErrorCheck = 1;
      }
      CRY_GTSTATUS_TC = CRY_GET_STATUS_IDLE;
    }
    break;
    /*test case to check if the 7th bit is reset*/
    case GET_STATUS_INTDEBUGGER_RESET :
    {
      GetStatusParameter_Init();
      Ret = Cry_HsmGetStatus();
      if((Ret & 0x80) == 0x00)
      {
          GetStaus_ErrorCheck = 1;
      }
      CRY_GTSTATUS_TC = CRY_GET_STATUS_IDLE;
    }
    break;
    /*test case to check is the 7th bit is set*/
    case GET_STATUS_INTDEBUGGER_SET :
    {
      GetStatusParameter_Init();
      /*Get challenge by calling Cry_debugstart function */
      /*CryDebugStartRet = Cry_HsmDebugStart(&GetStatusDebugStartChallenge); */
      /*get uid */
      TestCd_KeyMng_GetUid((uint8*)&GetStatusUidData);
      /*using Master ECU key and Debug_key_constant , KDF function has to be called to get secret key*/
      /*pass uid,GetStatusDebugStartChallenge and secret key for mac generation by calling Cry mac gen functions*/
      /*MAC_RetValStart  = Cry_HsmAesCMacGenerateStart(config, KEY_MAC_GENERATE_RAM_KEY);
      MAC_RetValUpdate = Cry_HsmAesCMacGenerateUpdate(config, TEST_CONST_PLAIN, 0);
      MAC_RetValFinish = Cry_HsmAesCMacGenerateFinish(config, (uint8 *)TEST_HSM_BUF_TEMP_D,&MAC_Length, FALSE);*/
      /*the generated mac has to be passed to CryDebugFinish for Authorization*/
      /*CryDebugFinishRet = Cry_HsmDebugFinish(TEST_HSM_BUF_TEMP_D); */
      /*If the generated mac is validated by Debug finish , the function returns CSM_E_OK , and the 7th bit will be set*/
      Ret = Cry_HsmGetStatus();
      if((CryDebugStartRet == CSM_E_OK) && (CryDebugFinishRet == CSM_E_OK))
      {
          if((Ret & 0x80) == 0x80)
          {
              GetStaus_ErrorCheck = 1;
          }
      }
      CRY_GTSTATUS_TC = CRY_GET_STATUS_IDLE;
    }
    break;

    default:
          break;

    }
}
#endif
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
