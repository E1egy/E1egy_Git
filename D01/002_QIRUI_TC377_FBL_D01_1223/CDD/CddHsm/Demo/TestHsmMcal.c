
#include "Hsm_Mcal.h"

#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

 boolean HsmMcal_Loop = 1;

#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"


#define CRY_START_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
 typedef enum
 {
   HSMMCAL_TEST_ID_DEFAULT               = 0x0,
   HSMMCAL_TEST_SET_HT2HSMS              = 0x1,
   HSMMCAL_TEST_GET_HSM2HTS      = 0x2,
   HSMMCAL_TEST_SET_HSM2HTF      = 0x3,
   HSMMCAL_TEST_GET_HSM2HTF          = 0x4,
   HSMMCAL_TEST_GET_HT2HSMF          = 0x5,
   HSMMCAL_TEST_SET_HT2HSMF                  = 0x6,
   HSMMCAL_TEST_DISABLE_ECCERR       = 0x7,
 #ifdef CONTROLLER_TC23x
   HSMMCAL_TEST_ENABLE_ECCERR          = 0x8,
   HSMMCAL_TEST_GET_TRAPDISABLESTATUS       = 0x9
 #endif
  }HsmMcalTest_Type;

HsmMcalTest_Type HsmMcal_Test = HSMMCAL_TEST_ID_DEFAULT;
uint32 HsmMcal_Status;
uint32 HsmMcal_FlagVal;

#define CRY_STOP_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"

void Test_HsmMcal_reference(void)
{
	switch(HsmMcal_Test)
	{
      case HSMMCAL_TEST_SET_HT2HSMS:
      {
    	  HsmMcal_SetHt2HsmStatus(HsmMcal_Status);
		  HsmMcal_Test = HSMMCAL_TEST_ID_DEFAULT;
        break;
      }
      case HSMMCAL_TEST_GET_HSM2HTS:
      {
    	  HsmMcal_Status = HsmMcal_GetHsm2HtStatus();
          HsmMcal_Test = HSMMCAL_TEST_ID_DEFAULT;
        break;
      }
      case HSMMCAL_TEST_SET_HSM2HTF:
      {
    	  HsmMcal_FlagVal = HsmMcal_GetHsm2HtFlag();
		  HsmMcal_SetHsm2HtFlag(HsmMcal_FlagVal);
		  HsmMcal_Test = HSMMCAL_TEST_ID_DEFAULT;
        break;
      }
      case HSMMCAL_TEST_GET_HSM2HTF:
      {
    	  HsmMcal_FlagVal = HsmMcal_GetHsm2HtFlag();
          HsmMcal_Test = HSMMCAL_TEST_ID_DEFAULT;
        break;
      }
      case HSMMCAL_TEST_GET_HT2HSMF:
      {
    	  HsmMcal_FlagVal = HsmMcal_GetHt2HsmFlag();
          HsmMcal_Test = HSMMCAL_TEST_ID_DEFAULT;
        break;
      }
      case HSMMCAL_TEST_SET_HT2HSMF:
      {
    	  HsmMcal_SetHt2HsmFlag(HsmMcal_FlagVal);
		  HsmMcal_Test = HSMMCAL_TEST_ID_DEFAULT;
        break;
      }
      case HSMMCAL_TEST_DISABLE_ECCERR:
#ifdef CONTROLLER_TC23x
      case HSMMCAL_TEST_ENABLE_ECCERR:
      {
    	  HsmMcal_Status = HsmMcal_GetTrapDisableStatus();
    	  HsmMcal_DisableEccErrors();
    	  HsmMcal_EnableEccErrors(HsmMcal_Status);
		  HsmMcal_Test = HSMMCAL_TEST_ID_DEFAULT;
        break;
      }
	  case HSMMCAL_TEST_GET_TRAPDISABLESTATUS:
      {
    	  HsmMcal_Status = HsmMcal_GetTrapDisableStatus();
		  HsmMcal_Test = HSMMCAL_TEST_ID_DEFAULT;
        break;
      }
#endif
       default:
         break;
	}
}

/*************************************************************************************//**
 * Execution of HsmCom test suite
*//**************************************************************************************/
void Test_HsmMcal(void)
{
    while(HsmMcal_Loop)
    {
	Test_HsmMcal_reference();
    }
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
