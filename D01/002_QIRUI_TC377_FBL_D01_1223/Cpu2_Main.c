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
**  FILENAME     : Cpu2_Main.c                                                **
**                                                                            **
**  VERSION      : 0.0.2                                                      **
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
**  DESCRIPTION  : Example Cpu2 Main startup file                             **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/

#include "Os.h"
#include "Mcal_Compiler.h"
#include "Ifx_Ssw_Infra.h"

void core2_main (void)
{
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

	cpuWdtPassword = Ifx_Ssw_getCpuWatchdogPassword(&MODULE_SCU.WDTCPU[2]);
	Ifx_Ssw_disableCpuWatchdog(&MODULE_SCU.WDTCPU[2], cpuWdtPassword);


	StartOS(OSDEFAULTAPPMODE);

	while(1)
	{
		;
	}

}
