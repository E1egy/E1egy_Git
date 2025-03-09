#include "TestHsm.h"

volatile uint8 callbackSet = 0;

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_DebugCallbackNotification(Csm_ReturnType result)
{
    if (result == CSM_E_OK)
    {
        callbackSet = 1;
    }
    else
    {
        callbackSet = 2;
        TEST_PRINTF("Debug start function failed in mainloop with ret value %d \n ", result);
    }
}

/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Csm_DebugServiceFinishNotification(void)
{

}


uint32 challenge[4];
uint32 authorization[4];



  
void Test_HsmDebug(void)
{
  Csm_ReturnType retVal;

  /* Init the challenge value */  
  TEST_PRINTF("Value of challenge before request:");
  TEST_PRINTHEX(challenge, 16); 
  TEST_PRINTF("\n");
  
  challenge[0] = 0xAAAAAAAAUL;
  challenge[1] = 0xBBBBBBBBUL;
  challenge[2] = 0xCCCCCCCCUL;
  challenge[3] = 0xDDDDDDDDUL;

 
  TEST_PRINTF("Value of challenge before request: ");
  TEST_PRINTHEX(challenge, 16); 
  TEST_PRINTF("\n");

  /* Call to get challenge */
  retVal = Cry_HsmDebugStart ((uint8*)challenge);
  TEST_VALIDATE(retVal == CSM_E_OK);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmDebugMainFunction, &callbackSet);
#endif
  TEST_PRINTF("Value of received challenge is: ");
  TEST_PRINTHEX(challenge, 16); 
  TEST_PRINTF("\n");

  /*---- Calculate authorization value ----*/
/* This still needs to be done for customer sample code
  retVal = SampleCode_GetAuthorization ((uint32*)challenge ,(uint32*) authorization); 
  TEST_VALIDATE(retVal == CSM_E_OK);
*/

  /* Send the calculated authorization value, activating the debugger */
    TEST_HSM_BUF_TEMP_B[0] = 0x032c3d0bUL;
  TEST_HSM_BUF_TEMP_B[1] = 0xb0ba81f9UL;
  TEST_HSM_BUF_TEMP_B[2] = 0xc07e4ec7UL;
  TEST_HSM_BUF_TEMP_B[3] = 0x8f8bc3c7UL;
    
    TEST_PRINTF("Sending authorization: ");
  TEST_PRINTHEX(TEST_HSM_BUF_TEMP_B, 16);
  TEST_PRINTF("\n");
    
  retVal = Cry_HsmDebugFinish ((uint8*) &TEST_HSM_BUF_TEMP_B[0]);
  TEST_VALIDATE(retVal == CSM_E_OK);
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
    TEST_WAIT(&Cry_HsmDebugMainFunction, &callbackSet);
#endif


}