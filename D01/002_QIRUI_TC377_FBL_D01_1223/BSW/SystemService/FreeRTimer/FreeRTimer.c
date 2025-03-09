/*============================================================================*/
/*  Copyright (C) 2009-2018, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  file       < FreeRTimer.c>
 *  brief      < FreeRTimer module file >
 *
 *
 *  author     < xxx >
 *  date       < 2018-12-12 >
 */
/*============================================================================*/
/******************************* references ************************************/
#include "FreeRTimer.h"
#include "os.h"
/****************************** implementations ********************************/
uint32 Frt_ReadOutMS(void)
{
	uint32  OSCurMs = 0;
	CoreIdType coreId;
    coreId = GetCoreID();
    switch (coreId)
    {
        #if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
        case OS_CORE_ID_0:
        {
            (void)GetCounterValue(SystemTimer_Core0, &OSCurMs);
            /*tick to ms*/
            OSCurMs = OS_TICKS2MS_SystemTimer_Core0(OSCurMs);
            break;
        }
        #endif
        #if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
        case OS_CORE_ID_1:
        {
            (void)GetCounterValue(SystemTimer_Core1, &OSCurMs);
            OSCurMs = OS_TICKS2MS_SystemTimer_Core1(OSCurMs);
            break;
        }
        #endif
        #if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
        case OS_CORE_ID_2:
        {
            (void)GetCounterValue(SystemTimer_Core2, &OSCurMs);
            OSCurMs = OS_TICKS2MS_SystemTimer_Core2(OSCurMs);
            break;
        }
        #endif
        default:
            break;
    }

    return(OSCurMs);
}

uint32 Frt_CalculateElapsedMS(uint32 OldCurMs)
{
	uint32  ElapsedMs = 0;
	CoreIdType coreId;
	coreId = GetCoreID();
    switch (coreId)
    {
        #if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
        case OS_CORE_ID_0:
        {
            /*ms to tick*/
            OldCurMs = OS_MS2TICKS_SystemTimer_Core0(OldCurMs);
            (void)GetElapsedValue(SystemTimer_Core0, &OldCurMs, &ElapsedMs);
            ElapsedMs = OS_TICKS2MS_SystemTimer_Core0(ElapsedMs);
            break;
        }
        #endif
        #if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
        case OS_CORE_ID_1:
        {
            OldCurMs = OS_MS2TICKS_SystemTimer_Core1(OldCurMs);
            (void)GetElapsedValue(SystemTimer_Core1, &OldCurMs, &ElapsedMs);
            ElapsedMs = OS_TICKS2MS_SystemTimer_Core1(ElapsedMs);
            break;
        }
        #endif
        #if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
        case OS_CORE_ID_2:
        {
            OldCurMs = OS_MS2TICKS_SystemTimer_Core2(OldCurMs);
            (void)GetElapsedValue(SystemTimer_Core2, &OldCurMs, &ElapsedMs);
            ElapsedMs = OS_TICKS2MS_SystemTimer_Core2(ElapsedMs);
            break;
        }
        #endif
        default:
            break;
    }

    return(ElapsedMs);
}



