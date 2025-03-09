
#include "HsmCom.h"
#include "HsmCom_Priv.h"
#include "HsmCom_def.h"
#include "Cry_Hsm.h"

#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"

typedef enum
{
    HSMCOM_TEST_PASSED,
    HSMCOM_TEST_FAILED
}HsmComTestStatus;

HsmComTestStatus HsmCom_TestStatus = HSMCOM_TEST_FAILED;
boolean HsmCom_Loop = 1;
uint32 HsmCom_Count =4;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
typedef enum
{
  HSMCOM_TEST_ID_DEFAULT            = 0x0,
  HSMCOM_TEST_ISCOMBUSY             = 0x1,
  HSMCOM_TEST_ISHSMRESPRECEIVED     = 0x2,
  HSMCOM_TEST_HSMRESPVALIDATION     = 0x3,
  HSMCOM_TEST_SENDCOMMAND           = 0x4,
  HSMCOM_TEST_WAITFORHSM            = 0x5,
  HSMCOM_TEST_INIT                  = 0x6,
  HSMCOM_TEST_INITSHAREDBUFFER      = 0x7,
  HSMCOM_TEST_CLEARHSMRESP          = 0x8,
  HSMCOM_TEST_SETPACKEDPARAMS       = 0x9,
  HSMCOM_TEST_ISCMDACCPETED         = 0xA,
  HSMCOM_TEST_GETPARAMSBUFFER       = 0xB,
  HSMCOM_TEST_COMPAREARRAY          = 0xC,
  HSMCOM_TEST_COMPAREVALUE          = 0xD,
  HSMCOM_TEST_COPYARRAY             = 0xE,
  HSMCOM_TEST_SETARRAYVALUE         = 0xF

}HsmComTest_Type;
HsmComTest_Type HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
HsmCom_MacUpdateParams *HsmCom_ParamPtr;
boolean HsmCom_ReturnVal;
HsmCom_Error HsmCom_ErrorVal;
Csm_ReturnType HsmCom_CSMRetVal;
uint32 HsmCom_SrcData[4];
uint32 HsmCom_DstData[4];
uint32 HsmCom_Value;

#define CRY_STOP_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"

void Test_HsmCom_reference(void)
{
	HsmCom_Session SessionDataPtr;
	switch(HsmCom_Test)
	{
      case HSMCOM_TEST_ISCOMBUSY:
      {
    	  HsmCom_ReturnVal = HsmCom_IsComBusy();
    	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
        break;
      }
      case HSMCOM_TEST_ISHSMRESPRECEIVED:
      {
    	  HsmCom_ReturnVal= HsmCom_IsHsmRespRecieved();
    	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
        break;
      }
      case HSMCOM_TEST_HSMRESPVALIDATION:
      {
    	  SessionDataPtr = HsmCom_OpenSession();
    	  HsmCom_HsmResponseValidation();
    	  HsmCom_CloseSession(SessionDataPtr);
    	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
        break;
      }
      case HSMCOM_TEST_SENDCOMMAND:
      {
    	 /* HsmCom_ErrorVal = HsmCom_SendCommand(NULL_PTR, HSMCOM_CMD_ECB_ENCRYPT);*/
    	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
        break;
      }
      case HSMCOM_TEST_WAITFORHSM:
      {
    	  HsmCom_CSMRetVal = HsmCom_WaitForHsm(HSMCOM_STAT_WAIT_COMMAND);
    	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
        break;
      }
      case HSMCOM_TEST_INIT:
      {
    	  HsmCom_Init();
    	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
        break;
      }
      case HSMCOM_TEST_INITSHAREDBUFFER:
      {
    	  Cry_HsmInit();
    	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
        break;
      }
      case HSMCOM_TEST_CLEARHSMRESP:
       {
    	   HsmCom_ClearHsmResp();
     	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
         break;
       }
       case HSMCOM_TEST_SETPACKEDPARAMS:
       {
     	  SessionDataPtr = HsmCom_OpenSession();
     	  HsmCom_SetPackedParams(SessionDataPtr,HSMCOM_KEY_1,CRY_HSM_AES_MODE_CTR);
     	  HsmCom_CloseSession(SessionDataPtr);
     	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
         break;
       }
       case HSMCOM_TEST_ISCMDACCPETED:
        {
        	HsmCom_ReturnVal = HsmCom_IsCmdAccepted();
      	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
          break;
        }
       case HSMCOM_TEST_GETPARAMSBUFFER:
        {
        	HsmCom_ParamPtr = NULL_PTR;
       	  SessionDataPtr = HsmCom_OpenSession();
       	HsmCom_ParamPtr = HsmCom_GetParamsBuffer(SessionDataPtr);
       	  HsmCom_CloseSession(SessionDataPtr);
      	  HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
          break;
        }
       case HSMCOM_TEST_COMPAREARRAY:
        {
           HsmCom_ReturnVal = HsmCom_CompareArray(HsmCom_DstData,HsmCom_SrcData,HsmCom_Count);
      	   HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
          break;
        }
       case HSMCOM_TEST_COMPAREVALUE:
         {
           HsmCom_ReturnVal = HsmCom_CompareValue(HsmCom_DstData, HsmCom_Value, HsmCom_Count);
       	   HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
           break;
         }
       case HSMCOM_TEST_COPYARRAY:
         {
        	HsmCom_CopyArray(HsmCom_DstData, HsmCom_SrcData, HsmCom_Count);
       	    HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
           break;
         }
       case HSMCOM_TEST_SETARRAYVALUE:
         {
           HsmCom_SetArrayValue(HsmCom_DstData, HsmCom_Value, HsmCom_Count);
       	   HsmCom_Test = HSMCOM_TEST_ID_DEFAULT;
           break;
         }


      default:
          break;
	}
}

/*************************************************************************************//**
 * Execution of HsmCom test suite
*//**************************************************************************************/
void Test_HsmCom(void)
{
    while(HsmCom_Loop)
    {
	Test_HsmCom_reference();
    }
}

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
