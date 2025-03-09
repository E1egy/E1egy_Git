/***********************************************************************************************************************
**--------------------------------------------------------------------------------------------------------------------**
** Copyright (c) 2019 by G-Pulse.		All rights reserved.
** This software is copyright protected and proprietary to G-Pulse.
** G-Pulse grants to you only those rights as set out in the license conditions.
** All other rights remain with G-Pulse.
**--------------------------------------------------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \TestCode\UserTestTask$
* $Class_____: C$
* $Name______: UserTestTaskCore0.c$
* $Variant___: 1.0.1$
* $Revision__: 0$
* $Author____: YM$
**
**--------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**--------------------------------------------------------------------------------------------------------------------**
** DESCRIPTION:
** UserTestTask driver source code
***********************************************************************************************************************/

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "UserTestTask.h"
#include "Ifx_reg.h"
#include "Dio.h"
//#include "Gp_CsaMonitor.h"
//#include "Gp_StackMonitor.h"
//#include "Gp_TimeCal.h"
//#include "Gp_Pms2G.h"
//#include "Gp_GeneralLib.h"
//#include "Gp_CpuFunc2G.h"
//#include "Gp_Bus2G.h"
//#include "Gp_Aurix2GUcb.h"
//#include "Gp_SOTA.h"
//#include "Gp_Gtm.h"
#include "HsmCom_Priv.h"
#include "TestHsm.h"
#include "Cry_Hsm.h"
#include "HostCom_Test.h"
#include "PFlashDriver.h"
#include "DFlashDriver.h"

/***********************************************************************************************************************
**                        					  Macro Definition                        								  **
***********************************************************************************************************************/
#define HSM_BOOT_FULL_CHECK_ADDRESS (0xA0000000)
#define HSM_BOOT_FULL_CHECK_LENGTH 	(0x6FFF0)
#define HSM_BOOT_FULL_CMAC_ADDRESS	(0xA006FFF0)

#define FBL_HEAD_1K_CHECK_ADDRESS 	(0xA0070000)
#define FBL_HEAD_1K_CHECK_LENGTH 	(1024)
#define FBL_HEAD_1K_CMAC_ADDRESS	(0xA00CFFD0)

#define FBL_TAIL_1K_CHECK_ADDRESS	(0xA00CFBD0)
#define FBL_TAIL_1K_CHECK_LENGTH 	(1024)
#define FBL_TAIL_1K_CMAC_ADDRESS	(0xA00CFFE0)

#define FBL_FULL_CHECK_ADDRESS	(0xA0070000)
#define FBL_FULL_CHECK_LENGTH	(0x5FFD0)
#define FBL_FULL_CMAC_ADDRESS	(0xA00CFFF0)

#define APP_HEAD_1K_CHECK_ADDRESS 	(0xA00D0000)
#define APP_HEAD_1K_CHECK_LENGTH 	(1024)
#define APP_HEAD_1K_CMAC_ADDRESS	(0xA02FFFD0)

#define APP_TAIL_1K_CHECK_ADDRESS	(0xA02FFBD0)
#define APP_TAIL_1K_CHECK_LENGTH 	(1024)
#define APP_TAIL_1K_CMAC_ADDRESS	(0xA02FFFE0)

#define APP_FULL_CHECK_ADDRESS	(0xA00D0000)
#define APP_FULL_CHECK_LENGTH	(0x22FFD0)
#define APP_FULL_CMAC_ADDRESS	(0xA02FFFF0)

#define B_BANK_OFFSET_ADDRESS 	(0x300000)

#define FBL_IGNORE_DD01 		(0)	/*Ignore DD01*/

/***********************************************************************************************************************
**                        					 Typedef Definition                        								  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                   					Static Local Variables Definition    						          		  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                  					   Global Variables Definition            						  		      **
***********************************************************************************************************************/
#define USER_TEST_TASK_INIT_FAR_DATA_START
#include "UserTestTask_MemMap.h"
uint32	UserTestCodeCore0_InitFlag = 0U;
uint32	UserTestCodeCore0_10msCnt = 0U;
Csm_ReturnType test_RetVal=CSM_E_NOT_OK;
uint32 HSM_Enabled = 0; /*0:Disable 1:Enable*/
uint32 HSM_InitStatus = 0; /*0:UNINIT 1:INITED 2:ERROR*/
uint32 HSM_InitCnt = 0; /*0:UNINIT 1:INITED 2:ERROR*/
#define USER_TEST_TASK_INIT_FAR_DATA_STOP
#include "UserTestTask_MemMap.h"

#define USER_TEST_TASK_CLEAR_FAR_DATA_START
#include "UserTestTask_MemMap.h"
float32 UserTestCodeCore0_dts;
//GpGeneralLib_ChipIdType GpGeneralLib_ChipIdData_st;
//GpGeneralLib_StartUpInfoType	GpGeneralLib_StartUpInfoData_st;
uint8	pflashEccTrap_set_u8;
uint32	pflashEccTrap_test_u32;

boolean AppReqProg = FALSE;
boolean AppValid = FALSE;
boolean FblRecvDD01 = FALSE;
boolean DD01StayInBoot = FALSE; 
boolean FblRecv1001 = FALSE;
extern const uint8 CMAC_TEST_CONST_KEY[16];

#define USER_TEST_TASK_CLEAR_FAR_DATA_STOP
#include "UserTestTask_MemMap.h"

/***********************************************************************************************************************
**                						Static Local Function Declaration    					        		      **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                 							  Function Source Code          					  		              **
***********************************************************************************************************************/
extern void Mcu_PflashTrapDisable(void);
#define USER_TEST_TASK_CODE_START
#include "UserTestTask_MemMap.h"
void AppReqProg_Check(void)
{
	uint32 ProgFlag = 0;
	AppReqProg = FALSE;


    IfxCpu_disableInterrupts();
    /* wait flash ready */
    DFlashDriver_IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);
    /* check empty */
    IfxFlash_verifyErasedWordLine(0xAF03F000); /*DFLASH: 512 bytes in single ended mode and 256 bytes in complement sensing mode.*/
    /* wait flash ready */
    DFlashDriver_IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);
	
    /*Not empty */
    if(DMU_HF_ERRSR.B.EVER== 1)
    {
        /* read addr */
		ProgFlag = *((uint32 *)(0xAF03F000));
        /* clear */
        DMU_HF_CLRE.B.CEVER = 1;
    }
    else     
    {
        /*empty */
		ProgFlag = 0x00000000;
    }
    IfxCpu_enableInterrupts();

	/* Check if the program flag in the Data Flash is Set */
	if(ProgFlag== 0xAA55AA55)
	{
		/*Stay In Boot*/
		AppReqProg = TRUE;

	}
	else
	{
		AppReqProg = FALSE;
	}

}

void AppVaild_Check(void)
{
	uint32 ProgFlag = 0;
	uint32 She_StatusRegister = 0U;
	uint32 HSMCfgRegister = 0;
	Csm_ReturnType test_RetVal = CSM_E_NOT_OK;
	boolean interruptState;	
	boolean Check_Result = 1;
	boolean Ret_HsmBootVerifyMac = FALSE;
	boolean Ret_FblHeadVerifyMac = FALSE;
	boolean Ret_FblTailVerifyMac = FALSE;
	boolean Ret_FblFullVerifyMac = FALSE;	
	boolean Ret_AppHeadVerifyMac = FALSE;
	boolean Ret_AppTailVerifyMac = FALSE;
	boolean Ret_AppFullVerifyMac = FALSE;

	HSMCfgRegister = (*( uint32 *) 0xAF402818);
	if((HSMCfgRegister & 0x00000003) == 0x00000003 && (1 == HSM_InitStatus)) /*HSM Enabled*/
	{
		SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(HsmAes_Block *)CMAC_TEST_CONST_KEY,16);
		Ret_AppHeadVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)APP_HEAD_1K_CHECK_ADDRESS, (const void*)APP_HEAD_1K_CMAC_ADDRESS, APP_HEAD_1K_CHECK_LENGTH, 16*8);
		Ret_AppTailVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)APP_TAIL_1K_CHECK_ADDRESS, (const void*)APP_TAIL_1K_CMAC_ADDRESS, APP_TAIL_1K_CHECK_LENGTH, 16*8);
		if((Ret_AppHeadVerifyMac == TRUE) && (Ret_AppTailVerifyMac == TRUE))
		{
			print_f("APP Check OK.\n");
			/*APP Check OK*/
			AppValid = TRUE;
		}
		else
		{
			print_f("APP Check NOT OK.\n");
			/*APP Check NOT OK*/
			Ret_HsmBootVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(HSM_BOOT_FULL_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(HSM_BOOT_FULL_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), HSM_BOOT_FULL_CHECK_LENGTH, 16*8);
			Ret_FblHeadVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(FBL_HEAD_1K_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(FBL_HEAD_1K_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), FBL_HEAD_1K_CHECK_LENGTH, 16*8);
			Ret_FblTailVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(FBL_TAIL_1K_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(FBL_TAIL_1K_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), FBL_TAIL_1K_CHECK_LENGTH, 16*8);
			Ret_FblFullVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(FBL_FULL_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(FBL_FULL_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), FBL_FULL_CHECK_LENGTH, 16*8);

			Ret_AppHeadVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(APP_HEAD_1K_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(APP_HEAD_1K_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), APP_HEAD_1K_CHECK_LENGTH, 16*8);
			Ret_AppTailVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(APP_TAIL_1K_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(APP_TAIL_1K_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), APP_TAIL_1K_CHECK_LENGTH, 16*8);
			Ret_AppFullVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(APP_FULL_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(APP_FULL_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), APP_FULL_CHECK_LENGTH, 16*8);

			if((Ret_HsmBootVerifyMac == FALSE) || (Ret_FblHeadVerifyMac == FALSE) || (Ret_FblTailVerifyMac == FALSE) || (Ret_FblFullVerifyMac == FALSE) 
			||(Ret_AppHeadVerifyMac == FALSE) || (Ret_AppTailVerifyMac == FALSE) || (Ret_AppFullVerifyMac == FALSE))
			{
				/*B Bank Check not ok, Stay in Fbl*/
				print_f("B Bank Not OK, Stay In Fbl.\n");
				AppValid = FALSE;
			}
			else
			{
				print_f("B Bank HsmBoot FBL APP OK\n");
				/*AB SWAP*/
				interruptState = IfxCpu_disableInterrupts(); /* Get the current state of the interrupts and disable them*/
				Check_Result = configure_swap_MainFunc(0xFFu);
				Check_Result = Enable_Swap_Config();
				IfxCpu_restoreInterrupts(interruptState);			/* Restore the interrupts state 	 */
				if(1u == Check_Result)
				{
					print_f("Swap OK, PerformReset\n");
					/*Reset*/
					Mcu_PerformReset();
					while (1);
				}
				else
				{
					/*Swap Failure*/
					AppValid = FALSE;
				}
			}
		}
	}
	else
	{
		print_f("HSM Disabled or State Error\n");
		Mcu_PflashTrapDisable();
		/*HSM Disabled or Stat Error*/
		/*Check APP head and Tail*/
		//APP head Addr 0xA00D0000 Data 0x80060020
        //APP tail Addr 0xA02FFFC8 Data 0xAA55AA55
		if((0x80060020 == (*(uint32 *)0xA00D0000)) && (0xAA55AA55 == (*(uint32 *)0xA02FFFC8)))
        {
			AppValid = TRUE;
        }
		else
		{
			AppValid = FALSE;
		}
	}

#if (FBL_IGNORE_DD01 == 1) /*Ignore DD01*/
	if((FALSE == AppReqProg) && (TRUE == AppValid))
	{
		p_AppEnter = (void(*)())APP_START_FUNCTION_ADDRESS_CORE0;
		(*p_AppEnter)();
		while (1);
	}
#endif

}

/***********************************************************************************************************************
** Function Name	: UserTestTaskCore0_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore0_Init
***********************************************************************************************************************/
void UserTestTaskCore0_Init(void)
{
	uint32 HSMCfgRegister = 0;
	HSMCfgRegister = (*( uint32 *) 0xAF402818);

	if((HSMCfgRegister & 0x00000003) == 0x00000003) /*HSM Enbaled*/
	{
		//Test_InitPrint();
		HSM_Enabled = TRUE;
	}
	else
	{
		HSM_Enabled = FALSE;
	}
	UserTestCodeCore0_InitFlag = 1U;
	HSM_InitStatus = 0;
	HSM_InitCnt = 0;

}

/***********************************************************************************************************************
** Function Name	: UserTestTaskCore0_10Ms
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore0_10Ms
***********************************************************************************************************************/
void UserTestTaskCore0_1Ms(void)
{
	uint32 HsmCurrentSt;
	if(TRUE == HSM_Enabled)
	{
		UserTestCodeCore0_10msCnt++;
		if(HSM_InitStatus == 0)
		{

			HsmCurrentSt = HsmMcal_GetHsm2HtStatus();
			HsmCurrentSt = HsmCurrentSt & HSMCOM_STAT_WAIT_COMMAND;
			if(HsmCurrentSt == HSMCOM_STAT_WAIT_COMMAND)
			{
				Cry_HsmInit();
				HSM_InitStatus = 1;
			}
			else
			{
				HSM_InitCnt++;
				if(HSM_InitCnt > 18)
				{
					HSM_InitStatus = 2;
				}
				else
				{
					/*Do nothing*/
				}
			}
		}
	}

}

#define USER_TEST_TASK_CODE_STOP
#include "UserTestTask_MemMap.h"

/***********************************************************************************************************************
* $History__:$
* V1.0.0; 0     04.11.2019 YM
*  N: new created
* V1.0.1; 0 	16.06.2020 YM
*  I:  Update MemMap
***********************************************************************************************************************/

