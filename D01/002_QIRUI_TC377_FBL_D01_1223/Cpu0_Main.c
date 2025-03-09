/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Cpu0_Main.c                                                **
**                                                                            **
**  VERSION      : 0.0.1                                                      **
**                                                                            **
**  DATE         : 2016-08-17                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Example Cpu0 Main startup file                             **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Ssw_Infra.h"
#include "IFX_Os.h"
#ifdef AURIX2G_MCAL_DEMOAPP
#include "DemoApp.h"
#endif
#include "Dio.h"
#include "EcuM.h"
#include "Mcu.h"
#include "Port.h"
#include "FlsLoader.h"
#include "Test_Print.h"
#include "PFlashDriver.h"
#include "DFlashDriver.h"
#include "McalLib.h"
#include "IfxSrc_reg.h"
#include "IfxDmu_reg.h"
#include "TestHsm.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/** MCU Software Version Number Modify Rule:
* Vxxxxxxxx.yy.zz:
*	xxxxxxxx	- Modify Time.
* 	yy 			- Projet Phase.
*	zz			- Software Version.
**/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

typedef struct
{
    unsigned long User_startAddr;
    unsigned long ABMHDID;
    unsigned long Check_StartAddr;
    unsigned long Check_EndAddr;
    unsigned long Crc_value;
    unsigned long Inverted_Crc_value;
    unsigned long ABMHD_Crc_value;
    unsigned long ABMHD_Inverted_Crc_value;
    unsigned long Boot_Mode_And_CheckLen;
}Alternate_BootModeHeader_st;

typedef struct
{
	unsigned long FblTailInfo_Reserved[2];
	unsigned long AppTailFlag;
	unsigned long Crc_Value;
    unsigned long App_HeadCmac[4];
	unsigned long App_TailCmac[4];
    unsigned long App_Cmac[4];
}FblTailInfo_st;
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
const Alternate_BootModeHeader_st  Alternate_BootModeHeader0  __attribute__((used,protect)) =
{
#if 0 // no HSM
    0x80000020,//0x800C0020
    0xFA7CB359,
    0x80000000,//0x800C0000
    0x80000000,//0x800C0000
    0xF77349EF,//0xFE69B08B
    0x088CB610,//0x01964F74
    0x1A4C3A7C,//0x34903484
    0xE5B3C583//0xCB6FCB7B
#else // add HSM
    0x80060020,
    0xFA7CB359,
    0x80060000,
    0x80060000,
    0xF3FE355D,
    0x0C01CAA2,
    0x86CFBE6F,
    0x79304190,
    0x0100000E
#endif
};

const FblTailInfo_st  FblTailInfo  __attribute__((used,protect)) =
{
	/*FblTailInfo_Reserved*/
	{
		0x20230626,
		0x00000000
	},
	/*AppTailFlag*/
	0xAA55AA55,
	/*Crc_Value (0xA007000-0xA02FFFCB)*/
	0xFFFFFFFF,
	/*App_HeadCmac (0xA0007000-0xA00703FF)*/
	{0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
	/*App_TailCmac (0xA02FFFBD0-0xA02FFFFCF)*/
	{0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
	/*App_Cmac (0xA0070000-0xA02FFFFCF)*/
    {0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF}
};

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Functon Definitions                            **
*******************************************************************************/

#include "Os.h"

volatile uint32 Debug_Count_Value = 0;
Std_ReturnType InitClockRetVal;
Mcu_PllStatusType Mcu_GetPllStatusRetVal = MCU_PLL_STATUS_UNDEFINED;

Mcu_ResetType resetReason;
unsigned short WatchdogPassword;
volatile uint32 Core0_Sync = 0;
volatile uint32 Core1_Sync = 0;
volatile uint32 Core2_Sync = 0;
void core0_main (void)
{

	volatile Mcu_ClockType ClockID = 0;
	StatusType status;

	unsigned short cpuWdtPassword;

	#if ((defined IFX_CFG_SSW_ENABLE_TRICORE0) && (IFX_CFG_SSW_ENABLE_TRICORE0 == 0))
	unsigned short safetyWdtPassword;
	#endif
	ENABLE();
	/*
	* !!WATCHDOG1 IS DISABLED HERE!!
	* Enable the watchdog in the demo if it is required and also service the watchdog periodically
	* */

	#if ((defined IFX_CFG_SSW_ENABLE_TRICORE0) && (IFX_CFG_SSW_ENABLE_TRICORE0 == 0))
	safetyWdtPassword = Ifx_Ssw_getSafetyWatchdogPassword();
	Ifx_Ssw_disableSafetyWatchdog(safetyWdtPassword);
	#endif

	cpuWdtPassword = Ifx_Ssw_getCpuWatchdogPassword(&MODULE_SCU.WDTCPU[0]);
	Ifx_Ssw_disableCpuWatchdog(&MODULE_SCU.WDTCPU[0], cpuWdtPassword);

	Mcu_Init(&Mcu_Config);
	InitClockRetVal = Mcu_InitClock(ClockID);
	Mcu_GetPllStatusRetVal = Mcu_GetPllStatus ();
	while (MCU_PLL_UNLOCKED == Mcu_GetPllStatus())
	{
		/* wait for PLL locked */
	}
	Mcu_DistributePllClock ();

	Port_Init(&Port_Config);
	WatchdogPassword =  Ifx_Ssw_getCpuWatchdogPassword(&MODULE_SCU.WDTCPU[0]);
	Ifx_Ssw_clearCpuEndinit(&MODULE_SCU.WDTCPU[0],WatchdogPassword);
	DMU_HF_PWAIT.B.RFLASH= 10;
	DMU_HF_PWAIT.B.CECC= 2;
	CPU0_FLASHCON1.B.MASKUECC=0x1;
	CPU1_FLASHCON1.B.MASKUECC=0x1;
	CPU2_FLASHCON1.B.MASKUECC=0x1;
	CPU0_FLASHCON2.B.DBABCLR=0x1;
	CPU0_FLASHCON2.B.ZBABCLR=0x1;
	WatchdogPassword =  Ifx_Ssw_getCpuWatchdogPassword(&MODULE_SCU.WDTCPU[0]);
	Ifx_Ssw_setCpuEndinit(&MODULE_SCU.WDTCPU[0],WatchdogPassword);

	/* Initialize the FLSLOADER driver */
	FlsLoader_Init(NULL_PTR);

#if(TEST_PRINT ==1)
	Test_InitPrint();
#endif

	StartCore(1, &status);
#if 0
	while((Core1_Sync != 0x55)|| (Core2_Sync != 0x55))
	{
		Core0_Sync = 0;
	}
	Core0_Sync = 0x55;
#endif
	EcuM_Init();
	for(;;)
	{
		;
	}

}
