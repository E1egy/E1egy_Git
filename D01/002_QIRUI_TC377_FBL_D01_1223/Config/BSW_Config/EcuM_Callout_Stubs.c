/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : EcuM_Callout_Stubs.c                                        **
**                                                                            **
**  Created on  : 2023/02/22 20:06:20                                         **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :  Implementations for EcuM callouts                          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19_11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM_Internal.h"
#include "EcuM_Cbk.h"
#include "Port.h"
#include "Can_17_McmCan.h"
#include "Spi.h"
#include "Adc.h"
#include "Pwm_17_GtmCcu6.h"
#include "Icu_17_TimerIp.h"
#include "CanIf.h"
#include "Com.h"
#include "PduR.h"
#include "Nm.h"
#include "CanNm.h"
#include "CanSM.h"
#include "ComM.h"
#include "PowerDriver.h"
#include "CanTp.h"
#include "Dcm.h"
#include "Dem.h"
#include "Tlf35584_Driver.h"
#include "Dio.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static FUNC(void, ECUM_STARTCHECKWAKEUP_CODE) EcuM_InternalStartCheckWakeup(
    EcuM_WakeupSourceType WakeupSource
    );
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
extern uint8 EcuMWakeupSource_McuResetReason;
extern uint8 validNmMsgFlag;
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "EcuM_MemMap.h"
/**
 * The ECU State Manager will call the error hook if the error codes
 * "ECUM_E_RAM_CHECK_FAILED" or "ECUM_E_CONFIGURATION_DATA_INCONSISTENT" occur.
 * In this situation it is not possible to continue processing and the ECU must
 * be stopped. The integrator may choose the modality how the ECU is stopped,
 * i.e. reset, halt, restart, safe state etc.
 * EcuM_ErrorHook is integration code and the integrator is free to define
 * additional individual error codes to be passed as the reason parameter.
 * Service ID[hex]: 0x30
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): reason, Reason for calling the error hook
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ERRORHOOK_CODE) EcuM_ErrorHook
(
    uint16 reason
)
{
    /*todo*/
    (void)reason;
}

#if (ECUM_SET_PROGRAMMABLE_INTERRUPTS == STD_ON)
/**
 * If the configuration parameter EcuMSetProgrammableInterrupts is set to true,
 * this callout EcuM_AL_SetProgrammableInterrupts is executed and shall set the
 * interrupts on ECUs with programmable interrupts.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_SETPROGRAMMABLEINTERRUPTS_CODE) EcuM_AL_SetProgrammableInterrupts
(
    void
)
{
    /*todo*/
}
#endif /*#if (ECUM_SET_PROGRAMMABLE_INTERRUPTS == STD_ON)*/

#if (ECUM_DRIVER_INIT_LIST_ZERO == STD_ON)
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities for loading the post-build configuration data. Beware:
 * Here only pre-compile and link-time configurable modules may be used.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERINITZERO_CODE) EcuM_AL_DriverInitZero
(
    void
)
{
}
#endif /*#if (ECUM_DRIVER_INIT_LIST_ZERO == STD_ON)*/

/**
 * This callout should evaluate some condition, like port pin or NVRAM value,
 * to determine which post-build configuration shall be used in the remainder
 * of the startup process. It shall load this configuration data into a piece
 * of memory that is accessible by all BSW modules and shall return a pointer
 * to the EcuM post-build configuration as a base for all BSW module post-build
 * configurations.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: Pointer to the EcuM post-build configuration which contains
 *               pointers to all other BSW module post-build configurations.
 */
FUNC_P2CONST(EcuM_ConfigType, ECUM_CONFIG_DATA, ECUM_DETERMINEPBCONFIGURATION_CODE) EcuM_DeterminePbConfiguration
(
    void
)
{
    extern CONST(EcuM_ConfigType, ECUM_VAR_NO_INIT) EcuM_Config;

    return (&EcuM_Config);
}

#if (ECUM_DRIVER_INIT_LIST_ONE == STD_ON)
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities in case of a power on reset.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr, pointer to the EcuM post-build configuration which
 *                             contains pointers to all other BSW module post-build
 *                             configurations.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERINITONE_CODE) EcuM_AL_DriverInitOne
(
    void
)
{
    P2CONST(EcuM_GenBSWPbCfgType, AUTOMATIC, CANIF_APPL_DATA) pbCfg = EcuM_ConfigPtr->modulePBCfg;
    Can_17_McmCan_Init(pbCfg->canPbCfg);
    Spi_Init(pbCfg->spiPbCfg);
    Adc_Init(pbCfg->adcPbCfg);
    Pwm_17_GtmCcu6_Init(pbCfg->pwmPbCfg);
    Icu_17_TimerIp_Init(pbCfg->icuPbCfg);
}
#endif /*#if (ECUM_DRIVER_INIT_LIST_ONE == STD_ON)*/

FUNC(void, ECUM_AL_DRIVERINITBSWM_0_CODE)
EcuM_AL_DriverInitBswM
(
    uint8 drvInitIdx
)
{
     P2CONST(EcuM_GenBSWPbCfgType, AUTOMATIC, CANIF_APPL_DATA) pbCfg = EcuM_ConfigPtr->modulePBCfg;
    if (EcuMDriverInitListBswM_bsw == drvInitIdx)
    {
       CanIf_Init(pbCfg->canIfPbCfg);
       Com_Init(pbCfg->comPbCfg);
       PduR_Init(pbCfg->pduRPbCfg);
       Nm_Init(pbCfg->nmPbCfg);
       CanNm_Init(pbCfg->canNmPbCfg);
       CanSM_Init(pbCfg->canSmPbCfg);
       ComM_Init(pbCfg->comMPbCfg);
       CanTp_Init(pbCfg->canTpPbCfg);   
       Dcm_Init(pbCfg->dcmPbCfg);
       Dem_PreInit();
       //Dem_Init(pbCfg->demPbCfg);
    }
    /*Enter in RUN after initialized all BSW mode.*/
    EcuMRunData.State = ECUM_STATE_RUN;
    BswM_EcuM_CurrentState(ECUM_STATE_RUN);

}

#if (ECUM_RESET_LOOP_DETECTION == STD_ON)
/**
 * If the configuration parameter EcuMResetLoopDetection is set to true,
 * this callout EcuM_LoopDetection is called on every startup.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: FALSE: no reset loop is detected
 *               TRUE: reset loop is detected
 */
FUNC(boolean, ECUM_LOOPDETECTION_CODE) EcuM_LoopDetection
(
    void
)
{
    /*todo*/
    return FALSE;
}
#endif /*#if (ECUM_RESET_LOOP_DETECTION == STD_ON)*/

/**
 * This call allows the system designer to notify that the GO OFF I state is
 * about to be entered.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ONGOOFFONE_CODE) EcuM_OnGoOffOne
(
    void
)
{
    /*todo*/
    PowerDrv_SetModulePowerOff();
}

/**
 * This call allows the system designer to notify that the GO OFF II state is
 * about to be entered.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ONGOOFFTWO_CODE) EcuM_OnGoOffTwo
(
    void
)
{
    /*todo*/
}

/**
 * This callout shall take the code for shutting off the power supply of the ECU.
 * If the ECU cannot unpower itself, a reset may be an adequate reaction.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_SWITCHOFF_CODE) EcuM_AL_SwitchOff
(
    void
)
{
    /*todo*/
    Tlf35584SetStateTransition_NormalToStandby();
}

/**
 * This callout shall take the code for resetting the ECU.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): reset, type of reset to be performed.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_RESET_CODE) EcuM_AL_Reset
(
    EcuM_ResetType reset
)
{
    (void)reset;
}

/**
 * The ECU Manager Module calls EcuM_EnableWakeupSource to allow the system
 * designer to notify wakeup sources defined in the wakeupSource bitfield that
 * SLEEP will be entered and to adjust their source accordingly.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ENABLEWAKEUPSOURCES_CODE) EcuM_EnableWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
)
{
   switch (wakeupSource)
   {
    case EcuMWakeupSource_Can:
            /*TODO*/
            break;
    case EcuMWakeupSource_Local:
            /*TODO*/
            break;
   }

   if (TRUE == validNmMsgFlag)
   {
            validNmMsgFlag = FALSE;
   }
}

/**
 * Generate code for RAM integrity test.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_GENERATERAMHASH_CODE) EcuM_GenerateRamHash
(
    void
)
{
    /*todo*/
}

/**
 * This callout is invoked periodically in all reduced clock sleep modes.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_SLEEPACTIVITY_CODE) EcuM_SleepActivity
(
    void
)
{
    /*todo*/
}

/**
 * This API is called by the ECU Firmware to start the CheckWakeupTimer for the
 * corresponding WakeupSource. If EcuMCheckWakeupTimeout > 0 the CheckWakeupTimer
 * for the WakeupSource is started. If EcuMCheckWakeupTimeout ?? 0 the API call
 * is ignored by the EcuM.
 * Service ID[hex]: 0x28
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource, For this wakeup source the corresponding
 *                                CheckWakeupTimer shall be started.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STARTCHECKWAKEUP_CODE) EcuM_StartCheckWakeup
(
    EcuM_WakeupSourceType wakeupSource
)
{
    switch(wakeupSource)
    {
    case EcuMWakeupSource_Can:
        EcuM_InternalStartCheckWakeup(EcuMWakeupSource_Can);
        break;
    case EcuMWakeupSource_Local:
        EcuM_InternalStartCheckWakeup(EcuMWakeupSource_Local);
        break;
    }
}

/**
 * This API is called by any SW Module whose wakeup source is checked
 * asynchronously (e.g. asynchronous Can Trcv Driver) and the Check of the Wakeup
 * returns a negative Result (no Wakeup by this Source). The API cancels the
 * CheckWakeupTimer for the WakeupSource. If the correponding CheckWakeupTimer is
 * canceled the check of this wakeup source is finished.
 * Service ID[hex]: 0x29
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource, For this wakeup source the corresponding
 *                                CheckWakeupTimer shall be canceled.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ENDCHECKWAKEUP_CODE) EcuM_EndCheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
)
{
    (void)WakeupSource;
}

/**
 * This callout is intended to provide a RAM integrity test. The goal of this
 * test is to ensure that after a long SLEEP duration, RAM contents is still
 * consistent. The check does not need to be exhaustive since this would consume
 * quite some processing time during wakeups. A well designed check will execute
 * quickly and detect RAM integrity defects with a sufficient probability.
 * The areas of RAM which will be checked have to be chosen carefully. It depends
 * on the check algorithm itself and the task structure. Stack contents of the
 * task executing the RAM check e.g. very likely cannot be checked. It is good
 * practice to have the hash generation and checking in the same task and that this
 * task is not preemptible and that there is only little activity between hash
 * generation and hash check. The RAM check itself is provided by the system
 * designer. In case of applied multi core and existence of Satellite-EcuM(s):
 * this API will be called by the Master-EcuM only.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: 0: RAM integrity test failed else: RAM integrity test passed
 */
FUNC(uint8, ECUM_CHECKRAMHASH_CODE) EcuM_CheckRamHash
(
    void
)
{
    /*todo*/
    return 1;
}

/**
 * The ECU Manager Module calls EcuM_DisableWakeupSources to set the wakeup
 * source(s) defined in the wakeupSource bitfield so that they are not able to
 * wake the ECU up.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_DISABLEWAKEUPSOURCES_CODE) EcuM_DisableWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
)
{
    if ((wakeupSource & EcuMWakeupSource_Can)
      == EcuMWakeupSource_Can)
    {
        /*TODO*/
    }
    else if ((wakeupSource & EcuMWakeupSource_Local)
      == EcuMWakeupSource_Local)
    {
        /*TODO*/
    }
	if(TRUE == EcuMWakeupSource_McuResetReason)
    {
        EcuMWakeupSource_McuResetReason = FALSE;
    }
}   

#if (ECUM_DRIVER_RESTART_LIST == STD_ON)
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities in the wakeup case.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr, pointer to the EcuM post-build configuration which
 *                             contains pointers to all other BSW module post-build
 *                             configurations.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERRESTART_CODE) EcuM_AL_DriverRestart
(
    void
)
{
}
#endif /*#if (ECUM_DRIVER_RESTART_LIST == STD_ON)*/

/**
 * The callout shall start the given wakeup source(s) so that they are ready to
 * perform wakeup validation.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STARTWAKEUPSOURCES_CODE) EcuM_StartWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
)
{
    CanSM_StartWakeupSource(1); //add for wakeup
}

/**
 * This callout is called by the EcuM to validate a wakeup source. If a valid
 * wakeup has been detected, it shall be reported to EcuM via EcuM_ValidateWakeupEvent().
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_CHECKVALIDATION_CODE) EcuM_CheckValidation
(
    EcuM_WakeupSourceType wakeupSource
)
{
    switch(wakeupSource)
    {
    case EcuMWakeupSource_Can:
		 	if((TRUE != EcuMWakeupSource_McuResetReason) && (TRUE == validNmMsgFlag))
	 	{
			EcuM_ValidateWakeupEvent(wakeupSource);
	 	}		
        break;
    case EcuMWakeupSource_Local:
        /*todo*/
        EcuM_ValidateWakeupEvent(wakeupSource);
        break;
    }
}

/**
 * The callout shall stop the given wakeup source(s) after unsuccessful wakeup
 * validation.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STOPWAKEUPSOURCES_CODE) EcuM_StopWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
)
{ 
    CanSM_StopWakeupSource(1);
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CHECKWAKEUP_CALLBACK_CODE
#include "EcuM_MemMap.h"
/**
 * This callout is called by the EcuM to poll a wakeup source.
 * It shall also be called by the ISR of a wakeup source to set up the PLL and
 * check other wakeup sources that may be connected to the same interrupt.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_CHECKWAKEUP_CODE) EcuM_CheckWakeup
(
    EcuM_WakeupSourceType wakeupSource
)
{
    switch(wakeupSource)
    {
    case EcuMWakeupSource_Can:
        EcuM_StartCheckWakeup(EcuMWakeupSource_Can);
        /*todo*/
        break;
    case EcuMWakeupSource_Local:
        EcuM_StartCheckWakeup(EcuMWakeupSource_Local);
        /*todo*/
        break;
    }
}
#define ECUM_STOP_SEC_CHECKWAKEUP_CALLBACK_CODE
#include "EcuM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
static FUNC(void, ECUM_INTERNALSTARTCHECKWAKEUP_CODE)
EcuM_InternalStartCheckWakeup
(
EcuM_WakeupSourceType WakeupSource
)
{
    P2CONST(EcuM_WakeupSourceCfgType, AUTOMATIC, ECUM_CONST)pWks;
    uint8 wksIdx;

    wksIdx = EcuM_WkSrcMap2CfgWkIdx(WakeupSource);
    pWks = &(EcuM_WkSourceCfgs[wksIdx]);
    if (pWks->checkWkupTimeout != 0u)
    {
    #if (ECUM_USE_TIMER == ECUM_TIMER_USE_GPT)
        (void)Tm_ResetTimer100us32bit
                (&(EcuMRunData.Wks.wkTime[wksIdx]));
    #else/*Use Os counter.*/
        EcuMRunData.Wks.wkTime[wksIdx] = Frt_ReadOutMS();
    #endif/*(ECUM_USE_TIMER == ECUM_TIMER_USE_GPT)*/
    }
}

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/
