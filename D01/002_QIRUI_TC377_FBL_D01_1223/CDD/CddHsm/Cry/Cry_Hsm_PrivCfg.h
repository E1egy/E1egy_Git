/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : Cry_Hsm_PrivCfg.h                                           **
**                                                                           **
**  VERSION    : 3.0.0                                                       **
**                                                                           **
**  DATE       : 2016-07-11                                                  **
**                                                                           **
**  VARIANT    : NA                                                          **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR    : Trivikram G                                                  **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the derived configuration               **
**                parameters for CRY module                                  **
**                                                                           **
**                                                                           **
**  SPECIFICATION(S) : Aurix_SHE+_TC-CDRV_DS.docx                            **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
#ifndef CRY_HSM_PRIVCFG_H
#define CRY_HSM_PRIVCFG_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Csm_Cfg.h"
#include "Cry_Hsm_Cfg.h"
#include "Hsm_Mcal.h"

/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 200] [$Satisfies $CDS_CDRV 571] **/
/* If enabled services operate synchronously, else asynchronously */
#define CRY_HSM_USE_SYNC_JOB_PROCESSING CSM_USE_SYNC_JOB_PROCESSING

/** Traceability    : [$Satisfies $CDS_CDRV 201]                            **/
/* If enabled services will report development errors,
           else no development errors reported */
#define CRY_HSM_DEV_ERROR_DETECT    CSM_DEV_ERROR_DETECT
/** Traceability    : [$Satisfies $CDS_CDRV 203]                            **/
#define CRY_HSM_E_POLICY_VIOLATION  CSM_E_POLICY_VIOLATION

#define CRY_HSM_INSTANCE_ID     ((uint8)0U)

#if CRY_HSM_USER_TIMEOUT_API == STD_OFF
/* Mapping of Cry timeout functions to AUTOSAR GPT API */
#include "Gpt.h"

#define CRY_HSM_TICK_TYPE Gpt_ValueType

/* The GPT timer channel used for the CRY_HSM timeout
 * must be configured in GPT_MODE_ONESHOT mode!
 */
/*GptConf_GptChannel_CryHsmTimeout has to be configure by user in
 * Gpt_cfg.h*/
#define CRY_HSM_GPT_CHANNEL GptConf_GptChannel_CryHsmTimeout
#define Cry_Hsm_StopTimer() Gpt_StopTimer(CRY_HSM_GPT_CHANNEL)

#else
/* Use customer defined API for timeout monitoring */
#define CRY_HSM_TICK_TYPE uint32
#define Cry_Hsm_StartTimer(Time) CRY_HSM_USER_START_TIMER_API_NAME()
#define Cry_Hsm_StopTimer() CRY_HSM_USER_STOP_TIMER_API_NAME()
#define Cry_Hsm_GetElapsedTime(StartRef)  \
                           CRY_HSM_USER_DELTA_TIMER_API_NAME(StartRef)

#endif


#if CRY_HSM_USER_TIMEOUT_API == STD_OFF
/******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE CRY_HSM_TICK_TYPE                       **
**                   Cry_Hsm_StartTimer(CRY_HSM_TICK_TYPE TimeOutValue)       **
**                                                                            **
** Description     :  This function calls Gpt interface to start the timer    **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : TimeOut Value in ticks                                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : NULL                                                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE CRY_HSM_TICK_TYPE Cry_Hsm_StartTimer
                                        (CRY_HSM_TICK_TYPE TimeOutValue)
{
  //Gpt_StartTimer(CRY_HSM_GPT_CHANNEL, TimeOutValue);
  return ((CRY_HSM_TICK_TYPE)0);
}

/******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : LOCAL_INLINE CRY_HSM_TICK_TYPE                       **
**                   Cry_Hsm_GetElapsedTime(CRY_HSM_TICK_TYPE St_Time)        **
**                                                                            **
** Description     :  This function calls Gpt interface to get elapsed time   **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non - Reentrant                                          **
**                                                                            **
** Parameters (in) : Reference time when the timer is started                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Elapsed time                                             **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE CRY_HSM_TICK_TYPE Cry_Hsm_GetElapsedTime
                                           (CRY_HSM_TICK_TYPE St_Time)
{
  CRY_HSM_TICK_TYPE  ElapsedTime;
  UNUSED_PARAMETER(St_Time)
  //ElapsedTime = Gpt_GetTimeElapsed(CRY_HSM_GPT_CHANNEL);
  return(ElapsedTime);
}
#endif

#endif/* End of CRY_HSM_PRIVCFG_H */

