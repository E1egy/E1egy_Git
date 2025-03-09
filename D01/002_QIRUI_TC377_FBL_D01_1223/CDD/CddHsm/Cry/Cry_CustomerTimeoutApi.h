/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : Cry_CustomerTimeoutApi.h                                    **
**                                                                           **
**  VERSION :     1.0.0                                                      **
**                                                                           **
**  DATE       : 2016-03-07                                                  **
**                                                                           **
**  AUTHOR      :  Trivikram G                                               **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the timer functions implementation.     **
**                These functions are developed for testing the timer        **
**                functionality in CRY + CD. These functions should not be   **
**                used by other modules / application sw.                    **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef CRY_CUSTOMERTIMEOUTAPI_H
#define CRY_CUSTOMERTIMEOUTAPI_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Mcal_Compiler.h"
#include "IfxStm_reg.h"

/******************************************************************************
**                      Global Macro Definition                              **
******************************************************************************/
#define SwFrt_TickType uint32


/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : LOCAL_INLINE uint32 STM_Tim0_Timer_Read (void)            **
**                                                                           **
** Description     :                                                         **
**                                                                           **
** [/cover]                                                                  **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
LOCAL_INLINE uint32 STM_Tim0_Timer_Read (void);


/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : LOCAL_INLINE uint32 STM_Tim0_Timer_Read (void)            **
**                                                                           **
** Description     :                                                         **
**                                                                           **
** [/cover]                                                                  **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
LOCAL_INLINE uint32 STM_Tim0_Timer_Read (void)  /* 64 bit timer running 100MHz*/
{
    uint32 Result_Value;

    /*  The capture register STMCAP always captures the
        STM bits [63:32] when one of the registers TIM0 to
        TIM5 and TIM0SV is read. This capture operation is
        performed in order to enable software to operate with
        a coherent value of all the 64 STM bits at one time
        stamp.This bit field contains bits [63:32] of the 64-bit
        STM.
    */
    /*
    Note that the PLS debugger does not display 64bit variables,
    for debugging the STM is first read into 2 32bit variables for
    debugger inspection.
    */
    uint32 Time64_l;
/*    uint32 Time64_h;*/
    /*Previously Time is used, as it is not defined, Time64_l is used*/
    Time64_l = STM0_TIM0.U;

    Result_Value = Time64_l;

    return Result_Value;
}


/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 583]                              **
**                                                                           **
** Syntax          : LOCAL_INLINE SwFrt_TickType SwFrt_GetRawCount(void)       **
**                                                                           **
** Description     :                                                         **
**                                                                           **
** [/cover]                                                                  **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
LOCAL_INLINE SwFrt_TickType SwFrt_GetRawCount(void)
{
    uint32 TimeoutStartTime;
    TimeoutStartTime = STM_Tim0_Timer_Read();
    return ((SwFrt_TickType) TimeoutStartTime);
}

/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 583]                              **
**                                                                           **
** Syntax          : LOCAL_INLINE SwFrt_TickType SwFrt_GetRawDelta             **
**                                  (uint32 Start_Ref)                       **
**                                                                           **
** Description     :                                                         **
**                                                                           **
** [/cover]                                                                  **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
LOCAL_INLINE SwFrt_TickType SwFrt_GetRawDelta(uint32 Start_Ref)
{
    return ((SwFrt_TickType)(STM_Tim0_Timer_Read() - Start_Ref));
}
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 583]                              **
**                                                                           **
** Syntax          : extern LOCAL_INLINE void SwFrt_StopTimer()           **
**                                                                           **
** Description     :                                                         **
**                                                                           **
** [/cover]                                                                  **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
LOCAL_INLINE void SwFrt_StopTimer()
{
    /*
Dummy code to remove MISRA warnings

    */
#if defined(_GNU_C_TRICORE_) || defined(_DIABDATA_C_TRICORE_)
    uint32 Time64_l;
#endif

#if defined(_TASKING_C_TRICORE_)
    static uint32 Time64_l;
#endif
    Time64_l = STM0_TIM0.U;
    Time64_l++;
}
/* End of  CRY_CUSTOMERTIMEOUTAPI_H */
#endif
