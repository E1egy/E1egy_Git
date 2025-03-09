/***********************************************************************************************************************
**--------------------------------------------------------------------------------------------------------------------**
** Copyright (c) 2020 by G-Pulse.		All rights reserved.
** This software is copyright protected and proprietary to G-Pulse.
** G-Pulse grants to you only those rights as set out in the license conditions.
** All other rights remain with G-Pulse.
**--------------------------------------------------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: ..\UserTestTask$
* $Class_____: C$
* $Name______: UserTestTask_MemMap.c$
* $Variant___: 1.0.1$
* $Revision__: 0$
* $Author____: YM$
*
* $Configuration or generate Date,Time: 15:00, 23.04.2020$
**
**--------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: Yes
**--------------------------------------------------------------------------------------------------------------------**
** DESCRIPTION:
** UserTestTask driver MemMap header
***********************************************************************************************************************/
#ifndef USER_TEST_TASK_MEMMAP_H_
#define USER_TEST_TASK_MEMMAP_H_
/**
 * 									G-Pulse	memory layout standard
 *
 * 	Type		Tasking				Hightec		Definition							Section
 *	.text		code 				ax			_CODE_(START/STOP)					Code.(*).(*)
 * 	.bss		farbss(farnoclear)	awB			CLEAR_FAR_DATA(NO_CLEAR_FAR_DATA)	ClearFarData.(NoClearFarData.)
 *	.zbss		nearbss(nearnoclear)awBz		CLEAR_NEAR_DATA(NO_CLEAR_NEAR_DATA)	ClearNearData.(NoClearNearData.)
 *	.sbss		a0bss				awBs		CLEAR_A0_DATA						ClearA0Data.
 *	.data		fardata				aw			INIT_FAR_DATA						InitFarData.
 *	.zdata		neardata			awz			INIT_NEAR_DATA						InitNearData.
 *	.sdata		a0data				aws			INIT_A0_DATA						InitA0Data.
 *	.rodata		farrom				a			CONST_FAR_DATA						ConstFarData.
 *	.zrodata	nearrom				az			CONST_NEAR_DATA						ConstNearData.
 *
 *	Example use:
 *	Variable (uint32 Gp_TestData_u32); at "Gp_Cdd.c";
 *	C file:
 *	#define GP_CDD_CLEAR_FAR_DATA_START
 *	#include "Gp_Cdd_MemMap.h"
 *	uint32 Gp_TestData_u32
 *	#define GP_CDD_CLEAR_FAR_DATA_STOP
 *	#include "Gp_Cdd_MemMap.h"
 *
 *	MemMap:
 *	start:
 *	#elif defined GP_CDD_CLEAR_FAR_DATA_START
 *	#if defined __TASKING__
 *	#pragma default_near_size 0
 *	#pragma section farbss "ClearFarData.Gp_Cdd.Core0"
 *	#elif defined __HIGHTEC__
 *	#pragma section "ClearFarData.Gp_Cdd.Core0" awB
 *	#endif
 *	#undef GP_CDD_CLEAR_FAR_DATA_START
 *
 *	stop:
 *	#elif defined GP_CDD_CLEAR_FAR_DATA_STOP
 *	#if defined __TASKING__
 *	#pragma default_near_size restore
 *	#pragma section farbss restore
 *	#elif defined __HIGHTEC__
 *	#pragma section
 *	#endif
 *	#undef GP_CDD_CLEAR_FAR_DATA_STOP
 *
 *	LINK:
 *	TASKING -> Section name is ".bss.ClearFarData.Gp_Cdd.Core0"
 *	HIGHTEC -> Section name is ".ClearFarData.Gp_Cdd.Core0"
 **/
#define USER_TEST_TASK_MEMMAP_ERROR

/************************************************* Data Section *******************************************************/
/*Clear near data(.zbss)*/
#if defined USER_TEST_TASK_CLEAR_NEAR_DATA_START
#if defined __TASKING__
#pragma section nearbss "ClearNearData.UserTestTask"
#pragma default_near_size 1024
#pragma align 4
#elif defined __HIGHTEC__
#pragma section "ClearNearData.UserTestTask" awBz 4
#endif
#undef USER_TEST_TASK_CLEAR_NEAR_DATA_START
#undef USER_TEST_TASK_MEMMAP_ERROR

#elif defined USER_TEST_TASK_CLEAR_NEAR_DATA_STOP
#if defined __TASKING__
#pragma align restore
#pragma default_near_size restore
#pragma section nearbss restore
#elif defined __HIGHTEC__
#pragma section
#endif
#undef USER_TEST_TASK_CLEAR_NEAR_DATA_STOP
#undef USER_TEST_TASK_MEMMAP_ERROR

/*Initialize near data(.zdata)*/
#elif defined USER_TEST_TASK_INIT_NEAR_DATA_START
#if defined __TASKING__
#pragma section neardata "InitNearData.UserTestTask"
#pragma default_near_size 1024
#pragma align 4
#elif defined __HIGHTEC__
#pragma section "InitNearData.UserTestTask" awz 4
#endif
#undef USER_TEST_TASK_INIT_NEAR_DATA_START
#undef USER_TEST_TASK_MEMMAP_ERROR

#elif defined USER_TEST_TASK_INIT_NEAR_DATA_STOP
#if defined __TASKING__
#pragma align restore
#pragma default_near_size restore
#pragma section neardata restore
#elif defined __HIGHTEC__
#pragma section
#endif
#undef USER_TEST_TASK_INIT_NEAR_DATA_STOP
#undef USER_TEST_TASK_MEMMAP_ERROR

/*Clear far data(.bss)*/
#elif defined USER_TEST_TASK_CLEAR_FAR_DATA_START
#if defined __TASKING__
#pragma section farbss "ClearFarData.UserTestTask"
#pragma default_near_size 0
#pragma align 4
#elif defined __HIGHTEC__
#pragma section "ClearFarData.UserTestTask" awB 4
#endif
#undef USER_TEST_TASK_CLEAR_FAR_DATA_START
#undef USER_TEST_TASK_MEMMAP_ERROR

#elif defined USER_TEST_TASK_CLEAR_FAR_DATA_STOP
#if defined __TASKING__
#pragma align restore
#pragma default_near_size restore
#pragma section farbss restore
#elif defined __HIGHTEC__
#pragma section
#endif
#undef USER_TEST_TASK_CLEAR_FAR_DATA_STOP
#undef USER_TEST_TASK_MEMMAP_ERROR

/*No clear far data(.bss)*/
#elif defined USER_TEST_TASK_NO_CLEAR_FAR_DATA_START
#if defined __TASKING__
#pragma section farnoclear "NoClearFarData.UserTestTask"
#pragma noclear
#pragma default_near_size 0
#pragma align 4
#elif defined __HIGHTEC__
#pragma section "NoClearFarData.UserTestTask" awB 4
#endif
#undef USER_TEST_TASK_NO_CLEAR_FAR_DATA_START
#undef USER_TEST_TASK_MEMMAP_ERROR

#elif defined USER_TEST_TASK_NO_CLEAR_FAR_DATA_STOP
#if defined __TASKING__
#pragma align restore
#pragma default_near_size restore
#pragma clear
#pragma section farnoclear restore
#elif defined __HIGHTEC__
#pragma section
#endif
#undef USER_TEST_TASK_NO_CLEAR_FAR_DATA_STOP
#undef USER_TEST_TASK_MEMMAP_ERROR

/*Initialize far data(.data)*/
#elif defined USER_TEST_TASK_INIT_FAR_DATA_START
#if defined __TASKING__
#pragma section fardata "InitFarData.UserTestTask"
#pragma default_near_size 0
#pragma align 4
#elif defined __HIGHTEC__
#pragma section "InitFarData.UserTestTask" aw 4
#endif
#undef USER_TEST_TASK_INIT_FAR_DATA_START
#undef USER_TEST_TASK_MEMMAP_ERROR

#elif defined USER_TEST_TASK_INIT_FAR_DATA_STOP
#if defined __TASKING__
#pragma align restore
#pragma default_near_size restore
#pragma section fardata restore
#elif defined __HIGHTEC__
#pragma section
#endif
#undef USER_TEST_TASK_INIT_FAR_DATA_STOP
#undef USER_TEST_TASK_MEMMAP_ERROR

/*Const far data(.rodata)*/
#elif defined USER_TEST_TASK_CONST_FAR_DATA_START
#if defined __TASKING__
#pragma section farrom "ConstFarData.UserTestTask"
#pragma default_near_size 0
#pragma align 4
#elif defined __HIGHTEC__
#pragma section "ConstFarData.UserTestTask" a 4
#endif
#undef USER_TEST_TASK_CONST_FAR_DATA_START
#undef USER_TEST_TASK_MEMMAP_ERROR

#elif defined USER_TEST_TASK_CONST_FAR_DATA_STOP
#if defined __TASKING__
#pragma align restore
#pragma default_near_size restore
#pragma section farrom restore
#elif defined __HIGHTEC__
#pragma section
#endif
#undef USER_TEST_TASK_CONST_FAR_DATA_STOP
#undef USER_TEST_TASK_MEMMAP_ERROR

/************************************************* Code Section *******************************************************/
#elif defined USER_TEST_TASK_CODE_START
#if defined __TASKING__
#pragma section code "Code.UserTestTask"
#elif defined __HIGHTEC__
#pragma section "Code.UserTestTask" ax
#endif
#undef USER_TEST_TASK_CODE_START
#undef USER_TEST_TASK_MEMMAP_ERROR

#elif defined USER_TEST_TASK_CODE_STOP
#if defined __TASKING__
#pragma section code restore
#elif defined __HIGHTEC__
#pragma section
#endif
#undef USER_TEST_TASK_CODE_STOP
#undef USER_TEST_TASK_MEMMAP_ERROR

/************************************************ compiler optimize ***************************************************/
#elif defined USER_TEST_TASK_COMPILER_OPTIMIZE_START
#if defined __TASKING__
#pragma optimize O0		/*no optimize for ssw code*/
#pragma profiling off	/*prevent profiling information*/
#pragma tradeoff 2		/*tradeoff 2 for balance size and speed*/
#elif defined __HIGHTEC__
#pragma GCC optimize ("-O2")
#endif
#undef USER_TEST_TASK_COMPILER_OPTIMIZE_START
#undef USER_TEST_TASK_MEMMAP_ERROR

#elif defined USER_TEST_TASK_COMPILER_OPTIMIZE_STOP
#if defined __TASKING__
#pragma endoptimize			/*#pragma optimize O0*/
#pragma profiling restore	/*#pragma profiling off*/
#pragma tradeoff restore	/*#pragma tradeoff 2*/
#elif defined __HIGHTEC__
#pragma GCC reset_options
#endif
#undef USER_TEST_TASK_COMPILER_OPTIMIZE_STOP
#undef USER_TEST_TASK_MEMMAP_ERROR

#endif

#if defined USER_TEST_TASK_MEMMAP_ERROR
#error "UserTestTask_MemMap.h,Wrong pragma command"
#endif

#undef USER_TEST_TASK_MEMMAP_H_	/*Must be #undef here*/
#endif /*USER_TEST_TASK_MEMMAP_H_*/

/***********************************************************************************************************************
* $History__:$
* V1.0.0; 0     04.11.2019 YM
*  N: new created
* V1.0.1; 0 	16.06.2020 YM
*  I:  Update MemMap
***********************************************************************************************************************/

