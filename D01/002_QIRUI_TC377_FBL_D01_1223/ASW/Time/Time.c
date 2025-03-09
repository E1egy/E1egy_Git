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
**  FILENAME    : Time.c                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yongxing.jia                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : alarm manager                                               **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>      <AUTHOR>       <REVISION LOG>
 *    V0.1.0       2020-05-20  yongxing.jia   Initial version.
 */
/*============================================================================*/


#include "Time.h"

#define  Time_5ms_MAXCnt        5
#define  Time_10ms_MAXCnt       10
#define  Time_50ms_MAXCnt       50
#define  Time_100ms_MAXCnt      100
#define  Time_500ms_MAXCnt      500
#define  Time_1000ms_MAXCnt     1000

static volatile boolean Time1msFlag    = 0;
static volatile boolean Time5msFlag    = 0;
static volatile boolean Time10msFlag   = 0;
static volatile boolean Time50msFlag   = 0;
static volatile boolean Time100msFlag  = 0;
static volatile boolean Time500msFlag  = 0;
static volatile boolean Time1000msFlag = 0;

static uint32 Time5msCnt   = 0;
static uint32 Time10msCnt  = 0;
static uint32 Time50msCnt  = 0;
static uint32 Time100msCnt = 0;
static uint32 Time500msCnt = 0;
static uint32 Time1000msCnt = 0;

void Gpt_1ms_Notification(void)
{
	Time_Tick_Mainfunction();
}

void Time_Tick_Mainfunction(void)
{
	Time1msFlag = TRUE;

	Time5msCnt++;

	if(Time5msCnt >= Time_5ms_MAXCnt)
	{
		Time5msCnt = 0;
		Time5msFlag = TRUE;
	}

	Time10msCnt++;
	if(Time10msCnt >= Time_10ms_MAXCnt)
	{
		Time10msCnt = 0;
		Time10msFlag = TRUE;
	}

	Time50msCnt++;
	if(Time50msCnt >= Time_50ms_MAXCnt)
	{
		Time50msCnt = 0;
		Time50msFlag = TRUE;
	}

	Time100msCnt++;
	if(Time100msCnt >= Time_100ms_MAXCnt)
	{
		Time100msCnt = 0;
		Time100msFlag = TRUE;
	}

	Time500msCnt++;
	if(Time500msCnt >= Time_500ms_MAXCnt)
	{
		Time500msCnt = 0;
		Time500msFlag = TRUE;
	}

	Time1000msCnt++;
	if(Time1000msCnt >= Time_1000ms_MAXCnt)
	{
		Time1000msCnt = 0;
		Time1000msFlag = TRUE;
	}

}

boolean GetTime_1ms_Status(void)
{
	boolean Ms_1ms_FlagStatus;

	Ms_1ms_FlagStatus = Time1msFlag;
	Time1msFlag = FALSE;

	return Ms_1ms_FlagStatus;
}

boolean GetTime_5ms_Status(void)
{
	boolean Ms_5ms_FlagStatus;

	Ms_5ms_FlagStatus = Time5msFlag;

	Time5msFlag = FALSE;

	return Ms_5ms_FlagStatus;
}

boolean GetTime_10ms_Status(void)
{
	boolean Ms_10ms_FlagStatus;

	Ms_10ms_FlagStatus = Time10msFlag;
	if(Time10msFlag == TRUE)
	{
		Time10msFlag = FALSE;
	}
	return Ms_10ms_FlagStatus;
}

boolean GetTime_50ms_Status(void)
{
	boolean Ms_50ms_FlagStatus;

	Ms_50ms_FlagStatus = Time50msFlag;

	if(Time50msFlag == TRUE)
	{
		Time50msFlag = FALSE;
	}

	return Ms_50ms_FlagStatus;
}

boolean GetTime_100ms_Status(void)
{
	boolean Ms_100ms_FlagStatus;

	Ms_100ms_FlagStatus = Time100msFlag;
	if(Time100msFlag == TRUE)
	{
		Time100msFlag = FALSE;
	}
	return Ms_100ms_FlagStatus;
}

boolean GetTime_500ms_Status(void)
{
	boolean Ms_500ms_FlagStatus;

	Ms_500ms_FlagStatus = Time500msFlag;
	Time500msFlag = FALSE;

	return Ms_500ms_FlagStatus;
}

boolean GetTime_1000ms_Status(void)
{
	boolean Ms_1000ms_FlagStatus;

	Ms_1000ms_FlagStatus = Time1000msFlag;
	Time1000msFlag = FALSE;

	return Ms_1000ms_FlagStatus;
}
