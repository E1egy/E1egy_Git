/*============================================================================*/
/*  Copyright (C) 2016, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Processor.c>
 *  @brief      <>
 *  
 * <Compiler: HighTec    MCU:TC275>
 *  
 *  @author     <bo.zeng>
 *  @date       <05-12-2014>
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2014-12-05  bo.zeng     Initial version.
 *  V0.2.0       2016-12-13  shi.shu     Multi-core Initial version.
 *  V0.3.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li     Functional safety version.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include <Os_Cfg.h>
#include "Os_Internal.h"
/*=======[M A C R O S]========================================================*/
extern void _START1(void);     /**< Pointer to the startup code */
extern void _START2(void);     /**< Pointer to the startup code */

#define __ALIGN_TRAP_TAB__                 ASM(" .align 32");
#define __ALIGN_INTI_TAB__                 ASM(" .align 32");

#define Trap_Vector_Handler(i)                                             				\
{                                                                                   	\
	__ALIGN_TRAP_TAB__;                                                             	\
	ASM("svlcx");																		\
	ASM("movh.a	a15, #@his(Tdisptab+4*"#i")");											\
	ASM("lea	a15, [a15]@los(Tdisptab+4*"#i")");										\
    ASM("ld.a   a14, [a15]");                 	 										\
    ASM("mov    d4, d15");                    											\
	ASM("ji     a14");																	\
}

#define Int_Vector_Handler(i)                                             				\
{                                                                                   	\
	__ALIGN_INTI_TAB__;                                                             	\
	ASM("svlcx");																		\
	ASM("movh.a	a15, #@his(Cdisptab+4*"#i")");											\
	ASM("lea	a15, [a15]@los(Cdisptab+4*"#i")");										\
    ASM("ld.a   a14, [a15]");                 	 										\
    ASM("mov    d5, #"#i);                    											\
	ASM("ji     a14");																	\
}

OS_ALIGN(8*32) void TriCore_trap_table(void)
{
	Trap_Vector_Handler(0);
	Trap_Vector_Handler(1);
	Trap_Vector_Handler(2);
	Trap_Vector_Handler(3);
	Trap_Vector_Handler(4);
	Trap_Vector_Handler(5);
	Trap_Vector_Handler(6);
	Trap_Vector_Handler(7);
}


OS_ALIGN(256*32) void TriCore_int_table(void)
{
	Int_Vector_Handler(0);
	Int_Vector_Handler(1);
	Int_Vector_Handler(2);
	Int_Vector_Handler(3);
	Int_Vector_Handler(4);
	Int_Vector_Handler(5);
	Int_Vector_Handler(6);
	Int_Vector_Handler(7);
	Int_Vector_Handler(8);
	Int_Vector_Handler(9);
	Int_Vector_Handler(10);
	Int_Vector_Handler(11);
	Int_Vector_Handler(12);
	Int_Vector_Handler(13);
	Int_Vector_Handler(14);
	Int_Vector_Handler(15);
	Int_Vector_Handler(16);
	Int_Vector_Handler(17);
	Int_Vector_Handler(18);
	Int_Vector_Handler(19);
	Int_Vector_Handler(20);
	Int_Vector_Handler(21);
	Int_Vector_Handler(22);
	Int_Vector_Handler(23);
	Int_Vector_Handler(24);
	Int_Vector_Handler(25);
	Int_Vector_Handler(26);
	Int_Vector_Handler(27);
	Int_Vector_Handler(28);
	Int_Vector_Handler(29);
	Int_Vector_Handler(30);
	Int_Vector_Handler(31);
#if (MAX_INTRS > 32)
	Int_Vector_Handler(32);
	Int_Vector_Handler(33);
	Int_Vector_Handler(34);
	Int_Vector_Handler(35);
	Int_Vector_Handler(36);
	Int_Vector_Handler(37);
	Int_Vector_Handler(38);
	Int_Vector_Handler(39);
	Int_Vector_Handler(40);
	Int_Vector_Handler(41);
	Int_Vector_Handler(42);
	Int_Vector_Handler(43);
	Int_Vector_Handler(44);
	Int_Vector_Handler(45);
	Int_Vector_Handler(46);
	Int_Vector_Handler(47);
	Int_Vector_Handler(48);
	Int_Vector_Handler(49);
	Int_Vector_Handler(50);
	Int_Vector_Handler(51);
	Int_Vector_Handler(52);
	Int_Vector_Handler(53);
	Int_Vector_Handler(54);
	Int_Vector_Handler(55);
	Int_Vector_Handler(56);
	Int_Vector_Handler(57);
	Int_Vector_Handler(58);
	Int_Vector_Handler(59);
	Int_Vector_Handler(60);
	Int_Vector_Handler(61);
	Int_Vector_Handler(62);
	Int_Vector_Handler(63);
	Int_Vector_Handler(64);
	Int_Vector_Handler(65);
	Int_Vector_Handler(66);
	Int_Vector_Handler(67);
	Int_Vector_Handler(68);
	Int_Vector_Handler(69);
	Int_Vector_Handler(70);
	Int_Vector_Handler(71);
	Int_Vector_Handler(72);
	Int_Vector_Handler(73);
	Int_Vector_Handler(74);
	Int_Vector_Handler(75);
	Int_Vector_Handler(76);
	Int_Vector_Handler(77);
	Int_Vector_Handler(78);
	Int_Vector_Handler(79);
	Int_Vector_Handler(80);
	Int_Vector_Handler(81);
	Int_Vector_Handler(82);
	Int_Vector_Handler(83);
	Int_Vector_Handler(84);
	Int_Vector_Handler(85);
	Int_Vector_Handler(86);
	Int_Vector_Handler(87);
	Int_Vector_Handler(88);
	Int_Vector_Handler(89);
	Int_Vector_Handler(90);
	Int_Vector_Handler(91);
	Int_Vector_Handler(92);
	Int_Vector_Handler(93);
	Int_Vector_Handler(94);
	Int_Vector_Handler(95);
	Int_Vector_Handler(96);
	Int_Vector_Handler(97);
	Int_Vector_Handler(98);
	Int_Vector_Handler(99);
	Int_Vector_Handler(100);
	Int_Vector_Handler(101);
	Int_Vector_Handler(102);
	Int_Vector_Handler(103);
	Int_Vector_Handler(104);
	Int_Vector_Handler(105);
	Int_Vector_Handler(106);
	Int_Vector_Handler(107);
	Int_Vector_Handler(108);
	Int_Vector_Handler(109);
	Int_Vector_Handler(110);
	Int_Vector_Handler(111);
	Int_Vector_Handler(112);
	Int_Vector_Handler(113);
	Int_Vector_Handler(114);
	Int_Vector_Handler(115);
	Int_Vector_Handler(116);
	Int_Vector_Handler(117);
	Int_Vector_Handler(118);
	Int_Vector_Handler(119);
	Int_Vector_Handler(120);
	Int_Vector_Handler(121);
	Int_Vector_Handler(122);
	Int_Vector_Handler(123);
	Int_Vector_Handler(124);
	Int_Vector_Handler(125);
	Int_Vector_Handler(126);
	Int_Vector_Handler(127);
	Int_Vector_Handler(128);
	Int_Vector_Handler(129);
	Int_Vector_Handler(130);
	Int_Vector_Handler(131);
	Int_Vector_Handler(132);
	Int_Vector_Handler(133);
	Int_Vector_Handler(134);
	Int_Vector_Handler(135);
	Int_Vector_Handler(136);
	Int_Vector_Handler(137);
	Int_Vector_Handler(138);
	Int_Vector_Handler(139);
	Int_Vector_Handler(140);
	Int_Vector_Handler(141);
	Int_Vector_Handler(142);
	Int_Vector_Handler(143);
	Int_Vector_Handler(144);
	Int_Vector_Handler(145);
	Int_Vector_Handler(146);
	Int_Vector_Handler(147);
	Int_Vector_Handler(148);
	Int_Vector_Handler(149);
	Int_Vector_Handler(150);
	Int_Vector_Handler(151);
	Int_Vector_Handler(152);
	Int_Vector_Handler(153);
	Int_Vector_Handler(154);
	Int_Vector_Handler(155);
	Int_Vector_Handler(156);
	Int_Vector_Handler(157);
	Int_Vector_Handler(158);
	Int_Vector_Handler(159);
	Int_Vector_Handler(160);
	Int_Vector_Handler(161);
	Int_Vector_Handler(162);
	Int_Vector_Handler(163);
	Int_Vector_Handler(164);
	Int_Vector_Handler(165);
	Int_Vector_Handler(166);
	Int_Vector_Handler(167);
	Int_Vector_Handler(168);
	Int_Vector_Handler(169);
	Int_Vector_Handler(170);
	Int_Vector_Handler(171);
	Int_Vector_Handler(172);
	Int_Vector_Handler(173);
	Int_Vector_Handler(174);
	Int_Vector_Handler(175);
	Int_Vector_Handler(176);
	Int_Vector_Handler(177);
	Int_Vector_Handler(178);
	Int_Vector_Handler(179);
	Int_Vector_Handler(180);
	Int_Vector_Handler(181);
	Int_Vector_Handler(182);
	Int_Vector_Handler(183);
	Int_Vector_Handler(184);
	Int_Vector_Handler(185);
	Int_Vector_Handler(186);
	Int_Vector_Handler(187);
	Int_Vector_Handler(188);
	Int_Vector_Handler(189);
	Int_Vector_Handler(190);
	Int_Vector_Handler(191);
	Int_Vector_Handler(192);
	Int_Vector_Handler(193);
	Int_Vector_Handler(194);
	Int_Vector_Handler(195);
	Int_Vector_Handler(196);
	Int_Vector_Handler(197);
	Int_Vector_Handler(198);
	Int_Vector_Handler(199);
	Int_Vector_Handler(200);
	Int_Vector_Handler(201);
	Int_Vector_Handler(202);
	Int_Vector_Handler(203);
	Int_Vector_Handler(204);
	Int_Vector_Handler(205);
	Int_Vector_Handler(206);
	Int_Vector_Handler(207);
	Int_Vector_Handler(208);
	Int_Vector_Handler(209);
	Int_Vector_Handler(210);
	Int_Vector_Handler(211);
	Int_Vector_Handler(212);
	Int_Vector_Handler(213);
	Int_Vector_Handler(214);
	Int_Vector_Handler(215);
	Int_Vector_Handler(216);
	Int_Vector_Handler(217);
	Int_Vector_Handler(218);
	Int_Vector_Handler(219);
	Int_Vector_Handler(220);
	Int_Vector_Handler(221);
	Int_Vector_Handler(222);
	Int_Vector_Handler(223);
	Int_Vector_Handler(224);
	Int_Vector_Handler(225);
	Int_Vector_Handler(226);
	Int_Vector_Handler(227);
	Int_Vector_Handler(228);
	Int_Vector_Handler(229);
	Int_Vector_Handler(230);
	Int_Vector_Handler(231);
	Int_Vector_Handler(232);
	Int_Vector_Handler(233);
	Int_Vector_Handler(234);
	Int_Vector_Handler(235);
	Int_Vector_Handler(236);
	Int_Vector_Handler(237);
	Int_Vector_Handler(238);
	Int_Vector_Handler(239);
	Int_Vector_Handler(240);
	Int_Vector_Handler(241);
	Int_Vector_Handler(242);
	Int_Vector_Handler(243);
	Int_Vector_Handler(244);
	Int_Vector_Handler(245);
	Int_Vector_Handler(246);
	Int_Vector_Handler(247);
	Int_Vector_Handler(248);
	Int_Vector_Handler(249);
	Int_Vector_Handler(250);
	Int_Vector_Handler(251);
	Int_Vector_Handler(252);
	Int_Vector_Handler(253);
	Int_Vector_Handler(254);
	Int_Vector_Handler(255);
#endif /* MAX_INTRS > 32 */
}



/*=======[E X T E R N A L   D A T A]==========================================*/
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(volatile Os_ArchCsaType, AUTOMATIC, OS_VAR)     Os_Csas       = NULL_PTR;
VAR(volatile uint32, OS_VAR)               Os_ArchSp                = 0U;
VAR(uint16, OS_VAR)                        Os_CfgCsaMax             = 0U;
P2VAR(Os_TaskCBExtType, AUTOMATIC, OS_VAR) Os_TaskCBExt             = NULL_PTR;
P2VAR(uint32, AUTOMATIC, OS_VAR)           Os_IsrNestPcxStack       = NULL_PTR;
P2CONST(OS_ISR_ADDR, AUTOMATIC, OS_VAR)    Os_IsrDAddr              = NULL_PTR;
P2CONST(OS_TASK_ADDR, AUTOMATIC, OS_VAR)   Os_TaskDAddr             = NULL_PTR;
VAR(uint32, OS_VAR) 	                   Os_SysTimerReloadVal     = 0U;
VAR(uint32, OS_VAR) 	                   Os_TprotTimerReloadVal   = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

/*=======[I N T E R N A L   D A T A]==========================================*/
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(volatile uint32, OS_VAR)    Os_TempPcx = 0U;
VAR(volatile uint32, OS_VAR)    Os_LoopPcx = 0U;
VAR(volatile uint32, OS_VAR)    Os_NextPcx = 0U;
VAR(volatile uint32, OS_VAR)    Os_TempPcxTermApp  = 0U;
VAR(volatile uint32, OS_VAR)    Os_LoopPcxTermApp  = 0U;
VAR(volatile uint32, OS_VAR)    Os_NextPcxTermApp  = 0U;
VAR(volatile uint32, OS_VAR)    Os_BeginPcxTermApp = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
VAR(Os_TaskCBExtType, OS_VAR)   Os_TaskCBExtCore0[CFG_TASK_MAX_CORE0] = {{0,0}};
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
VAR(Os_TaskCBExtType, OS_VAR)   Os_TaskCBExtCore1[CFG_TASK_MAX_CORE1] = {{0,0}};
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
VAR(Os_TaskCBExtType, OS_VAR)   Os_TaskCBExtCore2[CFG_TASK_MAX_CORE2] = {{0,0}};
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
VAR(Os_TaskCBExtType, OS_VAR)   Os_TaskCBExtCore3[CFG_TASK_MAX_CORE3] = {{0,0}};
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
VAR(Os_TaskCBExtType, OS_VAR)   Os_TaskCBExtCore4[CFG_TASK_MAX_CORE4] = {{0,0}};
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
VAR(Os_TaskCBExtType, OS_VAR)   Os_TaskCBExtCore5[CFG_TASK_MAX_CORE5] = {{0,0}};
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */

#if (CFG_ISR_MAX > 0U)
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
VAR(uint32, OS_VAR)             Os_IsrNestPcxStackCore0[CFG_ISR_MAX_CORE0] = {0};
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
VAR(uint32, OS_VAR)             Os_IsrNestPcxStackCore1[CFG_ISR_MAX_CORE1] = {0};
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
VAR(uint32, OS_VAR)             Os_IsrNestPcxStackCore2[CFG_ISR_MAX_CORE2] = {0};
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
VAR(uint32, OS_VAR)             Os_IsrNestPcxStackCore3[CFG_ISR_MAX_CORE3] = {0};
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
VAR(uint32, OS_VAR)             Os_IsrNestPcxStackCore4[CFG_ISR_MAX_CORE4] = {0};
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
VAR(uint32, OS_VAR)             Os_IsrNestPcxStackCore5[CFG_ISR_MAX_CORE5] = {0};
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint8, OS_VAR)              Os_IntNestISR1   = 0U;
VAR(uint8, OS_VAR)              Os_IntNestISR2   = 0U;
VAR(Os_CallLevelType, OS_VAR)   Os_SaveLevelISR1 = OS_LEVEL_ISR1;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#endif /* #if (CFG_ISR_MAX > 0U) */


/* DD_1_0318 */


#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
OS_ALIGN(64) VAR(volatile Os_ArchCsaType, OS_VAR) Os_Csas_Core0[CFG_CSA_MAX_CORE0] = {{{0}}};
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
OS_ALIGN(64) VAR(volatile Os_ArchCsaType, OS_VAR) Os_Csas_Core1[CFG_CSA_MAX_CORE1] = {{{0}}};
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
OS_ALIGN(64) VAR(volatile Os_ArchCsaType, OS_VAR) Os_Csas_Core2[CFG_CSA_MAX_CORE2] = {{{0}}};
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"


#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
VAR(volatile uint32, OS_VAR)                   Os_TprotTerminateIsr = FALSE;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
VAR(uint32, OS_VAR)                            Os_PSW_PRS = 0u;
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#if (TRUE == CFG_CPU_USAGE_ENABLE)

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
VAR(Os_TimeUsageType, OS_VAR)                      Os_TaskTimeUsageCore0[CFG_TASK_MAX_CORE0];
VAR(Os_TimeUsageType, OS_VAR)                      Os_IsrTimeUsageCore0[CFG_ISR2_MAX_CORE0];
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
VAR(Os_TimeUsageType, OS_VAR)                      Os_TaskTimeUsageCore1[CFG_TASK_MAX_CORE1];
VAR(Os_TimeUsageType, OS_VAR)                      Os_IsrTimeUsageCore1[CFG_ISR2_MAX_CORE1];
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
VAR(Os_TimeUsageType, OS_VAR)                      Os_TaskTimeUsageCore2[CFG_TASK_MAX_CORE2];
VAR(Os_TimeUsageType, OS_VAR)                      Os_IsrTimeUsageCore2[CFG_ISR2_MAX_CORE2];
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
VAR(Os_TimeUsageType, OS_VAR)                      Os_TaskTimeUsageCore3[CFG_TASK_MAX_CORE3];
VAR(Os_TimeUsageType, OS_VAR)                      Os_IsrTimeUsageCore3[CFG_ISR2_MAX_CORE3];
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#endif /* #if (TRUE == CFG_CPU_USAGE_ENABLE) */


#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
/* This array holds the functions to be called when a trap occurs. */
static VAR(Os_traphnd, OS_VAR)     Tdisptab[MAX_TRAPS];
static VAR(Os_isrhnd, OS_VAR)      Cdisptab[MAX_INTRS];
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"


/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#if (TRUE == CFG_SYSTEM_TIMER_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) Os_ArchInitSystemTimer(void);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (TRUE == CFG_SYSTEM_TIMER_ENABLE) */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) Os_ArchInitTimingProtTimer(void);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (TRUE == CFG_SYSTEM_TIMER_ENABLE) */

#if (((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) && (CFG_ISR_MAX > 0) && (TRUE == CFG_INT_NEST_ENABLE))
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(StatusType, OS_CODE) Os_ArchTerminateOneNestIsr(Os_IsrType OsIsrID);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* (CFG_OSAPPLICATION_MAX > 0) && (CFG_ISR_MAX > 0) && (TRUE == CFG_INT_NEST_ENABLE) */

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) Os_InterruptInit(void);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Initialize the multicore processor>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0713, DD_1_0714>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_MultiCoreInitProcessor(void)
{
    switch (Os_SCB.sysCore)
    {
        #if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
        case 0:
            Os_Csas                 = Os_Csas_Core0;
            Os_CfgCsaMax            = CFG_CSA_MAX_CORE0;
            Os_TaskCBExt            = Os_TaskCBExtCore0;
            Os_IsrNestPcxStack      = Os_IsrNestPcxStackCore0;
            #if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
            Os_IsrDAddr             = Os_Isr_DAddr_Core0;
            Os_TaskDAddr            = Os_Task_DAddr_Core0;
            #endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
			#if (TRUE == CFG_CPU_USAGE_ENABLE)
			Os_TaskTimeUsage = Os_TaskTimeUsageCore0;
			Os_IsrTimeUsage = Os_IsrTimeUsageCore0;
			#endif /* (TRUE == CFG_CPU_USAGE_ENABLE) */

            break;
        #endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */

        #if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
        case 1:
            Os_Csas                 = Os_Csas_Core1;
            Os_CfgCsaMax            = CFG_CSA_MAX_CORE1;
            Os_TaskCBExt            = Os_TaskCBExtCore1;
            Os_IsrNestPcxStack      = Os_IsrNestPcxStackCore1;
            #if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
            Os_IsrDAddr             = Os_Isr_DAddr_Core1;
            Os_TaskDAddr            = Os_Task_DAddr_Core1;
            #endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
			#if (TRUE == CFG_CPU_USAGE_ENABLE)
			Os_TaskTimeUsage = Os_TaskTimeUsageCore1;
			Os_IsrTimeUsage = Os_IsrTimeUsageCore1;
			#endif /* (TRUE == CFG_CPU_USAGE_ENABLE) */

            break;
        #endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */

        #if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
        case 2:
            Os_Csas                 = Os_Csas_Core2;
            Os_CfgCsaMax            = CFG_CSA_MAX_CORE2;
            Os_TaskCBExt            = Os_TaskCBExtCore2;
            Os_IsrNestPcxStack      = Os_IsrNestPcxStackCore2;
            #if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
            Os_IsrDAddr             = Os_Isr_DAddr_Core2;
            Os_TaskDAddr            = Os_Task_DAddr_Core2;
            #endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
			#if (TRUE == CFG_CPU_USAGE_ENABLE)
			Os_TaskTimeUsage = Os_TaskTimeUsageCore2;
			Os_IsrTimeUsage = Os_IsrTimeUsageCore2;
			#endif /* (TRUE == CFG_CPU_USAGE_ENABLE) */

            break;
        #endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */

        /*add comments to pass QAC.*/
        default:
            /* Nothing to do */
            break;
    }
}

/******************************************************************************/
/*
 * Brief                <Ipl greater than 0, disable interrupt otherwise enable
 *                       interrupt>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <ipl>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ResumeOSInterrupts and so on>
 * REQ ID               <DD_1_0715, DD_1_0716>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSetIpl(Os_IPLType ipl, Os_IsrDescriptionType isrdesc)
{
    uint32 temp = (Os_ArchMsrType)OS_ARCH_MFCR(OS_REG_ICR);
    (void)isrdesc;
    temp = temp & 0xFFFFFF00u;
    temp = temp | (uint32)ipl;
    OS_ARCH_MTCR(OS_REG_ICR, (uint32)temp);
}

/******************************************************************************/
/*
 * Brief                <get the IPL>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <0>
 * PreCondition         <None>
 * CallByAPI            <SuspendOSInterrupts and so on>
 * REQ ID               <DD_1_0717, DD_1_0718,DD_1_1299>
 */
/******************************************************************************/
FUNC(Os_IPLType, OS_CODE) Os_ArchGetIpl(void)
{
    uint32 temp = (uint32)OS_ARCH_MFCR(OS_REG_ICR);

    return (Os_IPLType)(temp & 0xFFu);
}

/******************************************************************************/
/*
 * Brief                <Save ccr to variable msr and disable maskable interrupt>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <SuspendAllInterrupts>
 * REQ ID               <DD_1_0719, DD_1_0720, DD_1_1300>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSuspendInt
(
    P2VAR(Os_ArchMsrType, AUTOMATIC, OS_VAR) msr
)
{
    *msr = (Os_ArchMsrType)OS_ARCH_MFCR(OS_REG_ICR) & (1 << 15);
    Os_ArchDisableInt();
}

/******************************************************************************/
/*
 * Brief                <transfer variable msr back to ccr>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ResumeAllInterrupts>
 * REQ ID               <DD_1_0721, DD_1_0722, DD_1_1301>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchRestoreInt(Os_ArchMsrType msr)
{
	Os_ArchMsrType temp = OS_ARCH_MFCR(OS_REG_ICR);
	temp = temp | msr;
    OS_ARCH_MTCR(OS_REG_ICR, (uint32)temp);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <first entry task>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_SwitchTask>
 * REQ ID               <DD_1_0723, DD_1_0724, DD_1_1306>
 */
/******************************************************************************/
#if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))
FUNC(void, OS_CODE) Os_ArchFirstEnterTask(void)
{
    P2VAR(Os_ArchCsaType, AUTOMATIC, OS_VAR) lowCsa;
    P2VAR(Os_ArchCsaType, AUTOMATIC, OS_VAR) upperCsa;
    P2VAR(Os_ArchCsaType, AUTOMATIC, OS_VAR) upperCsa1;

    lowCsa   = OS_PCX_TO_EA(OS_ARCH_MFCR(OS_REG_FCX));
    upperCsa = OS_CSA_PREV(lowCsa);
    upperCsa1  = OS_CSA_PREV(upperCsa);
    Os_TaskCBExt[Os_SCB.sysRunningTaskID].pcx     = OS_ARCH_MFCR(OS_REG_FCX);
    Os_TaskCBExt[Os_SCB.sysRunningTaskID].pcxLast = OS_EA_TO_PCX(upperCsa1);
    OS_ARCH_MTCR(OS_REG_FCX, OS_EA_TO_PCX(OS_CSA_PREV(upperCsa1)));

    lowCsa->reg[0]   |= 0x00300000u;    /* PCXI */
    lowCsa->reg[1]    = (uint32)Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskEntry;     /* A11(RA) */
    
    upperCsa->reg[0] |= 0x00100000u;    /* PCXI */
    upperCsa->reg[1]  = 0x00000981u;    /* PSW  */
    upperCsa->reg[2]  = OS_ARCH_STACK_ALIGN((uint32)Os_SCB.sysRunningTCB->taskTop);  /* A10(SP) */
    upperCsa->reg[3]  = (uint32)Os_TaskErrBack;                                      /* A11(RA) */
    upperCsa->reg[4]  = 0U;            /* D8   */
    upperCsa->reg[5]  = 0U;            /* D9   */
    upperCsa->reg[6]  = 0U;            /* D10  */
    upperCsa->reg[7]  = 0U;            /* D11  */
    upperCsa->reg[8]  = 0U;            /* A12  */
    upperCsa->reg[9]  = 0U;            /* A13  */
    upperCsa->reg[10] = 0U;            /* A14  */
    upperCsa->reg[11] = 0U;            /* A15  */
    upperCsa->reg[12] = 0U;            /* D12  */
    upperCsa->reg[13] = 0U;            /* D13  */
    upperCsa->reg[14] = 0U;            /* D14  */
    upperCsa->reg[15] = 0U;            /* D15  */

    upperCsa1->reg[0] = 0U;            /* PCXI */
    upperCsa1->reg[1] = 0x00000980u;    /* PSW  */
}
#else
FUNC(void, OS_CODE) Os_ArchFirstEnterTask(void)
{
    P2VAR(Os_ArchCsaType, AUTOMATIC, OS_VAR) lowcsa_1  = OS_PCX_TO_EA(OS_ARCH_MFCR(OS_REG_FCX));
    P2VAR(Os_ArchCsaType, AUTOMATIC, OS_VAR) lowCsa    = OS_CSA_PREV(lowcsa_1);
    P2VAR(Os_ArchCsaType, AUTOMATIC, OS_VAR) upperCsa  = OS_CSA_PREV(lowCsa);
    P2VAR(Os_ArchCsaType, AUTOMATIC, OS_VAR) upperCsa1 = OS_CSA_PREV(upperCsa);

    Os_TaskCBExt[Os_SCB.sysRunningTaskID].pcx     = OS_ARCH_MFCR(OS_REG_FCX);
    Os_TaskCBExt[Os_SCB.sysRunningTaskID].pcxLast = OS_EA_TO_PCX(upperCsa1);
    OS_ARCH_MTCR(OS_REG_FCX, OS_EA_TO_PCX(OS_CSA_PREV(upperCsa1)));

    lowcsa_1->reg[0] |= 0x00300000u;
    lowcsa_1->reg[1]    = (uint32)Os_ModeModify;

    lowCsa->reg[0]   |= 0x00100000u;    /* PCXI */
    lowCsa->reg[1]    = 0x00000981u;    /* PSW  */
    
    lowCsa->reg[2]  = (uint32)Os_SCB.sysRunningTCB->taskTop;/* A10(SP)  */
    lowCsa->reg[3]  = (uint32)Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskEntry;/* A11(RA) */
    
    upperCsa->reg[0] |= 0x00100000u;    /* PCXI */
    #if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
    upperCsa->reg[1]    = 0x00000981u | Os_PSW_PRS; /* PSW  */
    #else
    upperCsa->reg[1]    = 0x00000981u; /* PSW  */
    #endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

    upperCsa->reg[2]  = OS_ARCH_STACK_ALIGN((uint32)Os_SCB.sysRunningTCB->taskTop);/* A10(SP)  */
    upperCsa->reg[3]  = (uint32)Os_TaskErrBack;                 /* A11(RA)  */
    upperCsa->reg[4]  = 0U;            /* D8   */
    upperCsa->reg[5]  = 0U;            /* D9   */
    upperCsa->reg[6]  = 0U;            /* D10  */
    upperCsa->reg[7]  = 0U;            /* D11  */
    upperCsa->reg[8]  = 0U;            /* A12  */
    upperCsa->reg[9]  = 0U;            /* A13  */
    upperCsa->reg[10] = 0U;            /* A14  */
    upperCsa->reg[11] = 0U;            /* A15  */
    upperCsa->reg[12] = 0U;            /* D12  */
    upperCsa->reg[13] = 0U;            /* D13  */
    upperCsa->reg[14] = 0U;            /* D14  */
    upperCsa->reg[15] = 0U;            /* D15  */

    upperCsa1->reg[0] = 0U;            /* PCXI */
    #if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
    upperCsa1->reg[1]    = 0x00000A81U; /* PSW  */
    upperCsa1->reg[2]    = OS_ARCH_STACK_ALIGN((uint32)Os_SystemStack->stackTop);
    #else
    upperCsa1->reg[1]    = 0x00000980u; /* PSW  */
    #endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
}
#endif /* (OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC) */

/******************************************************************************/
/*
 * Brief                <Os_ArchDispatcher>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_SystemCallTrap>
 * REQ ID               <DD_1_0725, DD_1_0726, DD_1_1297, DD_1_1302, DD_1_1303>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchDispatcher(void)
{
    OS_ARCH_SAVE_CONTEXT();

    Os_ArchSwitch2System();
    OS_ARCH_MTCR(OS_REG_PCX, 0U);
    /* avoid switch to task self */
    if ((TASK_STATE_SUSPENDED == Os_SCB.sysRunningTCB->taskState)\
        || (TASK_STATE_START == Os_SCB.sysRunningTCB->taskState))
    {
        Os_ArchReclaimCsas(Os_SCB.sysRunningTaskID);
    }

    Os_SwitchTask();
    OS_ARCH_RESUME_CONTEXT();
}

/******************************************************************************/
/*
 * Brief                <Os_ArchStartScheduler>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0727, DD_1_0728>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchStartScheduler(void)
{
    uint32 temp = 0u; 
    Os_SwitchTask();

    /*clear CDC*/
    temp = (Os_ArchMsrType)OS_ARCH_MFCR(OS_REG_PSW);
    temp &= 0XFFFFFF80u;
    OS_ARCH_MTCR(OS_REG_PSW, temp);

    OS_ARCH_RESUME_CONTEXT();
}

/******************************************************************************/
/*
 * Brief                <Os_ArchInitCsas>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0729, DD_1_0730, DD_1_0731>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchInitCsas(void)
{
    uint32 i = 0U;

    Os_Csas[0].reg[0] = 0U;
    Os_Csas[0].reg[1] = 0U;

    for (i = 1U; i < Os_CfgCsaMax; i++)
    {
        Os_Csas[i].reg[0] = OS_EA_TO_PCX((uint32)&Os_Csas[i-1u]);
        Os_Csas[i].reg[1] = 0U;
    }
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Os_ArchInitCPU>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0732, DD_1_0733>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchInitCPU(void)
{
    Os_InterruptInit();
    Os_ArchInitIntPrio();

    #if (TRUE == CFG_SYSTEM_TIMER_ENABLE)
    Os_ArchInitSystemTimer();
    #endif /* #if (TRUE == CFG_SYSTEM_TIMER_ENABLE) */

    #if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    Os_ArchInitTimingProtTimer();
    #endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#if (TRUE == CFG_SYSTEM_TIMER_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Os_ArchInitSystemTimer>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 * REQ ID               <DD_1_0898, DD_1_1305>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ArchInitSystemTimer(void)
{
    /*only logic master core need Running this code.*/
    if (0u == Os_SCB.sysCore)
    {
        Os_ArchResetSafetyENDINIT();
//    	Os_ArchResetENDINIT(0);

        while (0U != (OS_SCU_CCUCON1 >> 31u))
        {
            /* Wait till ccucon registers can be written with new value */
            /* No "timeout" required, because if it hangs, Safety Endinit will
             * give a trap */
        }
        /* set .UP to 1,.INSEL to 1,fstm = fsource/2*/
        OS_SCU_CCUCON0 &= 0xFFFFFFF0u;//TODO Waiting EcuM_Init
        OS_SCU_CCUCON0 |= 0x50000003u;

//        Os_ArchSetENDINIT(0);
        Os_ArchSetSafetyENDINIT();
    }

    switch (Os_SCB.sysCore)
    {
        #if (TRUE == CFG_SYSTEM_TIMER_ENABLE_CORE0)
        case 0:
        	Os_SysTimerReloadVal = CFG_REG_OSTIMER_VALUE_CORE0;
            OS_STM0_CMP0  = OS_STM0_TIM0 + CFG_REG_OSTIMER_VALUE_CORE0;
            OS_STM0_CMCON |= 0x0000001Fu;
            OS_STM0_ICR   |= 0x00000001u;
            break;
        #endif /* TRUE == CFG_SYSTEM_TIMER_ENABLE_CORE0 */

        #if (TRUE == CFG_SYSTEM_TIMER_ENABLE_CORE1)
        case 1:
        	Os_SysTimerReloadVal = CFG_REG_OSTIMER_VALUE_CORE1;
            OS_STM1_CMP0  = OS_STM1_TIM0 + CFG_REG_OSTIMER_VALUE_CORE1;
            OS_STM1_CMCON |= 0x0000001Fu;
            OS_STM1_ICR   |= 0x00000001u;
            break;
        #endif /* TRUE == CFG_SYSTEM_TIMER_ENABLE_CORE1 */

        #if (TRUE == CFG_SYSTEM_TIMER_ENABLE_CORE2)
        case 2:
        	Os_SysTimerReloadVal = CFG_REG_OSTIMER_VALUE_CORE2;
            OS_STM2_CMP0  = OS_STM2_TIM0 + CFG_REG_OSTIMER_VALUE_CORE2;
            OS_STM2_CMCON |= 0x0000001Fu;
            OS_STM2_ICR   |= 0x00000001u;
            break;
        #endif /* TRUE == CFG_SYSTEM_TIMER_ENABLE_CORE2 */

        /*add comments to pass QAC.*/
        default:
            /* Nothing to do. */
            break;
    }
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* TRUE == CFG_SYSTEM_TIMER_ENABLE */


#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Initialize a time-protected clock for each CPU running OS>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_ArchInitCPU>
 * REQ ID               <DD_1_0900, DD_1_1304>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ArchInitTimingProtTimer(void)
{
    switch (Os_SCB.sysCore)
    {
        #if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0)
        case 0:
        	Os_TprotTimerReloadVal = CFG_REG_TP_TIMER_VALUE_CORE0;
            OS_STM0_CMP1  = OS_STM0_TIM0 + CFG_REG_TP_TIMER_VALUE_CORE0;
            OS_STM0_CMCON |= 0x001F0000u;
            OS_STM0_ICR   |= 0x00000050u;
            break;
        #endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0 */

        #if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1)
        case 1:
        	Os_TprotTimerReloadVal = CFG_REG_TP_TIMER_VALUE_CORE1;
            OS_STM1_CMP1  = OS_STM1_TIM0 + CFG_REG_TP_TIMER_VALUE_CORE1;
            OS_STM1_CMCON |= 0x001F0000u;
            OS_STM1_ICR   |= 0x00000050u;
            break;
        #endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1 */

        #if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2)
        case 2:
        	Os_TprotTimerReloadVal = CFG_REG_TP_TIMER_VALUE_CORE2;
            OS_STM2_CMP1  = OS_STM2_TIM0 + CFG_REG_TP_TIMER_VALUE_CORE2;
            OS_STM2_CMCON |= 0x001F0000u;
            OS_STM2_ICR   |= 0x00000050u;
            break;
        #endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2 */

        /*add comments to pass QAC.*/
        default:
            /* Nothing to do. */
            break;
    }
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE) */

/* OS447: Disable all interrupts in os_app during TerminateApplication. */
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (CFG_ISR_MAX > 0)
/******************************************************************************/
/*
 * Brief                <TryToGetSpinlock has the same functionality as GetSpinlock with the difference
                         that if the spinlock is already occupied by a TASK on a different core the function
                         sets the OUT parameter "Success" and returns with E_OK>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <TerminateApplication>
 * REQ ID               <DD_1_1076>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchDisableIntInApp
(
    P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) posCurAppCfg
)
{   
    uint16     i;
    uint16     osIsrRefCnt;
    Os_IsrType osIsrId;
    uint32     osIsrRegVal;
    
    osIsrRefCnt = posCurAppCfg->OsAppIsrRefCnt;

    for (i = 0u; i < osIsrRefCnt; i++)
    {
        osIsrId = posCurAppCfg->OsAppObjectRef[OBJECT_ISR][i];

        osIsrRegVal  = Os_IsrCfg[Os_GetObjLocalId(osIsrId)].OsIsrSrc;
        
        OS_INTERRUPT_DISABLEREQ(osIsrRegVal);
        OS_INTERRUPT_CLEARREQ(osIsrRegVal);
        OS_INTERRUPT_SET_SRPN_ZERO(osIsrRegVal);
    }
}

#if (TRUE == CFG_INT_NEST_ENABLE)
/******************************************************************************/
/*
 * Brief                <Terminate an interrupt>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]            <OsIsrID>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <StatusType>
 * CallByAPI            <Os_ArchAppTerminateIsrProc>
 * REQ ID               <DD_1_0901>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_ArchTerminateOneNestIsr(Os_IsrType OsIsrID)
{
    uint8 i;
    StatusType Status = E_OK;
    for (i = 0u; i < Os_IntNestISR2; i++)
    {
        /* find out the Isr nested position and reclaim its context saving area */
        if (OsIsrID == Os_SCB.sysIsrNestQueue[i])
        {
            /* Reclaim csa list used by this isr. */
            /* if OsIsrChkindex == Os_IntNestISR2, the isr is the innermost_isr,
             * can not reclaim csas here */
            Os_ArchReclaimIsrCsasTermApp(Os_IsrNestPcxStack[i + 1u], Os_IsrNestPcxStack[i]);

            break;
        }
    }

    /* Not find out the Isr Id in the IsrStack from the SCB,
        * not include outermost_isr. */
    if (i >= Os_IntNestISR2)
    {
        Status = E_NOT_OK;
    }
    else
    {
        /* Moving the following nested ISR2s to shift one position left */
        while (i < (Os_IntNestISR2 - 1u))
        {
            Os_SCB.sysIsrNestQueue[i] = Os_SCB.sysIsrNestQueue[i + 1u];

            if (i < (Os_IntNestISR2 - 2u))
            {
                Os_IsrNestPcxStack[i + 1u] = Os_IsrNestPcxStack[i + 2u];
            }

            i++;
        }
    }

    return Status;
}

/* Terminate Isr2 platform process in TerminateApplication */
/******************************************************************************/
/*
 * Brief                <Terminate the ISR objects of the calling application>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <OsIsrID>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_TerminateISRObjectHandler>
 * REQ ID               <DD_1_1077>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchAppTerminateIsrProc(Os_IsrType OsIsrID)
{
    uint32 ulRet = E_OK;

    /* Isr_nest process. */
    /* Just find out the nested corresponding ISR2s(excluding the running one) */
    if (OsIsrID != Os_SCB.sysRunningIsrCat2Id)
    {
        /* Terminate one isr */
        ulRet = Os_ArchTerminateOneNestIsr(OsIsrID);

        if ((uint32)E_OK == ulRet)
        {
            if (Os_IntNestISR2 > 0u)
            {
                Os_IntNestISR2--;
            }

            if (Os_SCB.sysDispatchLocker > 0u)
            {
                /*Os_SCB.sysDispatchLocker--*/
                Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker - 1u;
            }
        }
    }

    return;
}
#endif     /* TRUE == CFG_INT_NEST_ENABLE */
#endif     /* #if (CFG_ISR_MAX > 0) */

/* TerminateTask arch_process in TerminateApplication. */
/******************************************************************************/
/*
 * Brief                <TerminateTask arch_process in TerminateApplication>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_TerminateTaskObjectHandler>
 * REQ ID               <DD_1_1078>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchAppTerminateTaskProc(Os_TaskType OsTaskID)
{
    if ((OS_LEVEL_TASK == Os_SCB.sysOsLevel) ||
        ((OS_LEVEL_ERRORHOOK_APP == Os_SCB.sysOsLevel) && (TRUE != Os_SCB.sysInIsrCat2)))
    {
        /* If TerminateApplication is called by task or isr2 or app_error_hook,
         * the csa of running task is reclaimed in the dispatcher at the end of TerminateApplication. */
        if (OsTaskID != Os_SCB.sysRunningTaskID)
        {
            Os_ArchReclaimCsas(OsTaskID);
        }
    }
    else
    {
        Os_ArchReclaimCsas(OsTaskID);
    }

    return;
}

#endif /* #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*=======[E X C I P T I O N]==================================================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <trap 6>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0734, DD_1_0735, DD_1_1320>
 */
/******************************************************************************/
//static __trap(6)
static FUNC(void, OS_CODE) Os_SystemCallTrap(uint16 Os_Tin)
{
    #if (TRUE == CFG_SRV_SHELLOS)
    P2VAR(Os_ArchCsaType, AUTOMATIC, OS_VAR) lowCsa;
    P2VAR(Os_ArchCsaType, AUTOMATIC, OS_VAR) upperCsa;

    lowCsa = OS_PCX_TO_EA(OS_ARCH_MFCR(OS_REG_PCX));
    upperCsa = OS_CSA_PREV(lowCsa);
    #endif /* TRUE == CFG_SRV_SHELLOS */

    switch (Os_Tin)
    {
        case 0:
            /*Tasking should save lower csa, GNU save the lower csa before in the asm where regedit exception*/
            ASM("j Os_ArchDispatcher");
            break;

        #if (TRUE == CFG_SRV_SHELLOS)
        case 1:
            upperCsa->reg[1]  = 0x00000981u;    /* PSW  */
            OS_ARCH_DSYNC();
            ASM("rslcx");
            ASM("nop");
            ASM("rfe");
            break;
        #endif /* TRUE == CFG_SRV_SHELLOS */
        #if (TRUE == CFG_SRV_SHELLOS)
        case 2:
            upperCsa->reg[1]  &= 0xffffc3ffu;    /* PSW  */
            upperCsa->reg[1]  |= 0x000000800u;    /* PSW  */
            OS_ARCH_DSYNC();
            ASM("rslcx");
            ASM("nop");
            ASM("rfe");
            break;
        #endif /* TRUE == CFG_SRV_SHELLOS */
        /*add comments to pass QAC.*/
        default:
            /* Nothing to do. */
            break;
    }
}

/******************************************************************************/
/*
 * Brief                <trap 0>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0736, DD_1_0737, DD_1_1314>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_Trap0(uint16 Os_Tin)
{
    #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    uint32 WhoHook = OS_TMPROT_HOOK_OSAPP;

    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_TASK;
    }
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_ISR;
    }
    else
    {
        /* Do nothing. */
    }
    #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

    switch (Os_Tin)
    {
        /* Virtual Address Fill */
        case 1:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Virtual_Address_Fill);
            #endif /* TRUE == CFG_ERRORHOOK */
            #if (TRUE == CFG_PROTECTIONHOOK)
            /* OS245:  protection exception hook. */
            (void)Os_CallProtectionHook(E_OS_Virtual_Address_Fill, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Virtual_Address_Fill);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
                    * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Virtual Address Protection */
        case 2:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Virtual_Address_Protection);
            #endif /* TRUE == CFG_ERRORHOOK */
            #if (TRUE == CFG_PROTECTIONHOOK)
            /* OS245:  protection exception hook. */
            (void)Os_CallProtectionHook(E_OS_Virtual_Address_Protection, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Virtual_Address_Protection);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif/* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
                   * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        default:
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_PROTECTION_EXCEPTION);
            #endif /* TRUE == CFG_ERRORHOOK */

            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
    }
}

/******************************************************************************/
/*
 * Brief                <trap 1>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0738, DD_1_0739, DD_1_1307, DD_1_1315, DD_1_1322>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_Trap1(uint16 Os_Tin)
{
    #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    #if (TRUE == CFG_PROTECTIONHOOK)
    uint32 WhoHook = OS_TMPROT_HOOK_OSAPP;

    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_TASK;
    }
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_ISR;
    }
    else
    {
        /* Do nothing. */
    }
    #endif /* TRUE == CFG_PROTECTIONHOOK */
    #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

    switch (Os_Tin)
    {
        case 1:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_PROTECTION_EXCEPTION);
            #endif /* TRUE == CFG_ERRORHOOK */
            #if (TRUE == CFG_PROTECTIONHOOK)
            /* OS245:  protection exception hook. */
            (void)Os_CallProtectionHook(E_OS_PROTECTION_EXCEPTION, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_PROTECTION_EXCEPTION);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        case 2:          /* Memory Protection Read */
        case 3:          /* Memory Protection Write */
        case 4:          /* Memory Protection Execution */
        case 5:          /* Memory Protection Peripheral Access */
        case 6:          /* Memory Protection Peripheral Null Access */
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_PROTECTION_MEMORY);
            #endif /* TRUE == CFG_ERRORHOOK */
            #if (TRUE == CFG_PROTECTIONHOOK)
            /* OS044: Memory protection hook. */
            (void)Os_CallProtectionHook(E_OS_PROTECTION_MEMORY, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_PROTECTION_EXCEPTION);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        case 7:          /* Global Register Write Protection */
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_PROTECTION_EXCEPTION);
            #endif /* TRUE == CFG_ERRORHOOK */
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        default:
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_PROTECTION_EXCEPTION);
            #endif /* TRUE == CFG_ERRORHOOK */
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
    }
}

/******************************************************************************/
/*
 * Brief                <trap 2>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0740, DD_1_0741, DD_1_1316>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_Trap2(uint16 Os_Tin)
{
    #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    #if (TRUE == CFG_PROTECTIONHOOK)
    uint32 WhoHook = OS_TMPROT_HOOK_OSAPP;

    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_TASK;
    }
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_ISR;
    }
    else
    {
        /* Do nothing. */
    }
    #endif /* TRUE == CFG_PROTECTIONHOOK */
    #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

    switch (Os_Tin)
    {
        /* Illegal Opcode */
        case 1:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Illegal_Opcode);
            #endif /* TRUE == CFG_ERRORHOOK */
            #if (TRUE == CFG_PROTECTIONHOOK)
            /* OS245:  protection exception hook. */
            (void)Os_CallProtectionHook(E_OS_Illegal_Opcode, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Illegal_Opcode);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Unimplemented Opcode */
        case 2:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Unimplemented_Opcode);
            #endif /* TRUE == CFG_ERRORHOOK */
            #if (TRUE == CFG_PROTECTIONHOOK)
            /* OS245:  protection exception hook. */
            (void)Os_CallProtectionHook(E_OS_Unimplemented_Opcode, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Unimplemented_Opcode);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Invalid Operand specification */
        case 3:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Invalid_Operand);
            #endif /* TRUE == CFG_ERRORHOOK */
            #if (TRUE == CFG_PROTECTIONHOOK)
            /* OS245:  protection exception hook. */
            (void)Os_CallProtectionHook(E_OS_Invalid_Operand, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Invalid_Operand);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Data Address Alignment */
        case 4:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Data_Address_Align);
            #endif /* TRUE == CFG_ERRORHOOK */
            #if (TRUE == CFG_PROTECTIONHOOK)
            /* OS245:  protection exception hook. */
            (void)Os_CallProtectionHook(E_OS_Data_Address_Align, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Data_Address_Align);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Invalid Local Memory Address */
        case 5:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Invalid_Local_Memory);
            #endif /* TRUE == CFG_ERRORHOOK */
            #if (TRUE == CFG_PROTECTIONHOOK)
            /* OS245:  protection exception hook. */
            (void)Os_CallProtectionHook(E_OS_Invalid_Local_Memory, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Invalid_Local_Memory);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        default:
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
    }
}

/******************************************************************************/
/*
 * Brief                <trap 3>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0742, DD_1_0743, DD_1_1317>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_Trap3(uint16 Os_Tin)
{
    #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    #if (TRUE == CFG_PROTECTIONHOOK)
    uint32 WhoHook = OS_TMPROT_HOOK_OSAPP;

    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_TASK;
    }
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_ISR;
    }
    else
    {
        /* Do nothing. */
    }
    #endif /* TRUE == CFG_PROTECTIONHOOK */
    #endif  /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

    switch (Os_Tin)
    {
        /* Free Context List Depletion(FCX = LCX)*/
        case 1:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Free_Context_List_Depletion);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Free_Context_List_Depletion, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Free_Context_List_Depletion);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Call Depth Overflow */
        case 2:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Call_Depth_Overflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Call_Depth_Overflow, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Call_Depth_Overflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Call Depth Underflow */
        case 3:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Call_Depth_Underflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Call_Depth_Underflow, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Call_Depth_Underflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Free Context List Underflow(FCX = 0) */
        case 4:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Free_Context_List_Underflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Free_Context_List_Underflow, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Free_Context_List_Underflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Call Stack Underflow(PCX = 0) */
        case 5:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Call_Stack_Underflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Call_Stack_Underflow, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Call_Stack_Underflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Context Type(PCXI.UL wrong) */
        case 6:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Context_Type);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Context_Type, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Context_Type);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Nesting Error: RFE with non-zero call depth */
        case 7:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Nesting_Error);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Nesting_Error, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Nesting_Error);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        default:
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
    }
}

/******************************************************************************/
/*
 * Brief                <trap 4>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0744, DD_1_0745, DD_1_1318>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_Trap4(uint16 Os_Tin)
{
    #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    #if (TRUE == CFG_PROTECTIONHOOK)
    uint32 WhoHook = OS_TMPROT_HOOK_OSAPP;

    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_TASK;
    }
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_ISR;
    }
    else
    {
        /* Do nothing. */
    }
    #endif /* TRUE == CFG_PROTECTIONHOOK */
    #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

    switch (Os_Tin)
    {
        /* Program Fetch Synchronous Error */
        case 1:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Program_Fetch_Synchronous);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Program_Fetch_Synchronous, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Program_Fetch_Synchronous);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif  /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Data Access Synchronous Error */
        case 2:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Data_Access_Synchronous);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Data_Access_Synchronous, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Data_Access_Synchronous);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Data Acess Asynchronous Error */
        case 3:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Data_Acess_Asynchronous);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Data_Acess_Asynchronous, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Data_Acess_Asynchronous);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* nothing to do. */
            }
            break;

        /* Coprocessor Trap Asynchronous Error. (TriCore 1.3.1)*/
        case 4:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Coprocessor_Trap_Asynchronous);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Coprocessor_Trap_Asynchronous, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Coprocessor_Trap_Asynchronous);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Program Memory Integrity Error. (TriCore 1.3.1) */
        case 5:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Program_Memory_Integrity);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Program_Memory_Integrity, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Program_Memory_Integrity);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Data Memory Integrity Error. (TriCore 1.3.1) */
        case 6:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Data_Memory_Integrity);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Data_Memory_Integrity, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Data_Memory_Integrity);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Temporal Asynchronous Error. (TriCore 1.6)*/
        case 7:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Temporal_Asynchronous);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Temporal_Asynchronous, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */

            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Temporal_Asynchronous);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        default:
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
    }
}

/******************************************************************************/
/*
 * Brief                <trap 5>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0746, DD_1_0747, DD_1_1319>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_Trap5(uint16 Os_Tin)
{
    #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    #if (TRUE == CFG_PROTECTIONHOOK)
    uint32 WhoHook = OS_TMPROT_HOOK_OSAPP;

    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_TASK;
    }
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_ISR;
    }
    else
    {
        /* Do nothing. */
    }
    #endif /* TRUE == CFG_PROTECTIONHOOK */
    #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

    switch (Os_Tin)
    {
        /* Arithmetic Overflow */
        case 1:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Arithmetic_Overflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Arithmetic_Overflow, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Arithmetic_Overflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        /* Sticky Arithmetic Overflow */
        case 2:
           #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Sticky_Arithmetic_Overflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_Sticky_Arithmetic_Overflow, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_Sticky_Arithmetic_Overflow);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        default:
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
    }
}

/******************************************************************************/
/*
 * Brief                <trap 7>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0748, DD_1_0749, DD_1_1321>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_Trap7(uint16 Os_Tin)  /* Non-Maskable Interrupt */
{
    #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    #if (TRUE == CFG_PROTECTIONHOOK)
    uint32 WhoHook = OS_TMPROT_HOOK_OSAPP;

    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_TASK;
    }
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_ISR;
    }
    else
    {
        /* Do nothing. */
    }
    #endif /* TRUE == CFG_PROTECTIONHOOK */
    #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

    switch (Os_Tin)
    {
        /* NMI - Non-Maskable Interrupt (TIN 0) */
        case 1:
            #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_NMI);
            #endif /* TRUE == CFG_ERRORHOOK */
            /* OS245:  protection exception hook. */
            #if (TRUE == CFG_PROTECTIONHOOK)
            (void)Os_CallProtectionHook(E_OS_NMI, WhoHook);
            #endif /* TRUE == CFG_PROTECTIONHOOK */
            #else
            #if (TRUE == CFG_ERRORHOOK)
            (void)ErrorHook(E_OS_NMI);
            #endif /* TRUE == CFG_ERRORHOOK */
            #endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) ||
             * (OS_SC4 == CFG_SC)*/
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
            break;

        default:
            while (Os_TrapWait)
            {
                /* Nothing to do. */
            }
    }
}

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
/******************************************************************************/
/*
 * Brief                <Change csa PSW.IO bits to User-1 Mode>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <DD_1_0750, DD_1_0751>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ModeModify(void)
{
    #if (TRUE == CFG_SRV_SHELLOS)
    uint32 temp = 0u;
    P2VAR(Os_ArchCsaType, AUTOMATIC, OS_VAR) Csa1;

    /*make sure current app is trusted or not*/
    if (TRUE != Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted)
    {
        /*get the address of the PCX point to*/
        Csa1 = OS_PCX_TO_EA((Os_ArchMsrType)OS_ARCH_MFCR(OS_REG_PCX));

        /*change csa PSW.IO bits to User-1 Mode*/
        Csa1->reg[1] &= 0xfffff7ffu;
        Csa1->reg[1] = Csa1->reg[1] | 0x00000400u;

        /*change csa PSW.IO bits to User-1 Mode*/
        temp = (Os_ArchMsrType)OS_ARCH_MFCR(OS_REG_PSW);
        temp = temp&0xfffff7ffu;
        temp = temp | 0x00000400u;

        OS_ARCH_MTCR(OS_REG_PSW, temp);
    }
    #endif /* TRUE == CFG_SRV_SHELLOS */

    return;
}
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

/* For memory protection. */
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
/******************************************************************************/
/*
 * Brief                <Set the memory protection properties>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <MpSetIdx>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_ArchInitKnMemMap and so on>
 * REQ ID               <DD_1_0752, DD_1_0753>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSetMemProtSet(uint32 MpSetIdx)
{
    Os_PSW_PRS = MpSetIdx << 12u;
}
/******************************************************************************/
/*
 * Brief                <Gets the memory protection property>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_ArchSetIsrMemMap,Os_ArchSetTaskMemMap>
 * REQ ID               <DD_1_0754, DD_1_0755>
 */
/******************************************************************************/
FUNC(uint32, OS_CODE) Os_ArchGetMemProtSet(void)
{
    return Os_PSW_PRS;
}
/******************************************************************************/
/*
 * Brief                <Initialize memory protection related registers>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_SwitchTask,Os_InitMemProt>
 * REQ ID               <DD_1_0756, DD_1_0757>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchInitKnMemMap(void)
{
    /*P2CONST(Os_MemProtKnCfgType, AUTOMATIC, OS_VAR) pKnMemMap;

    Os_Kernel default protect whole ram and rom.
    pKnMemMap = &Os_MemProtKnAddrCfg;*/

    /* Set tc275 reg_set, use set_0 */
    /* Set-up the Data regions for the Os_Kernel. */
    OS_ARCH_MTCR(OS_DPR_0L, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pCPU2DataRamStart);
    OS_ARCH_MTCR(OS_DPR_0U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pPeripheralEnd);

    /* Set-up the Code regions for the Kernel. */
    OS_ARCH_MTCR(OS_CPR_0L, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomStart);
    OS_ARCH_MTCR(OS_CPR_0U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomEnd);

    /* Set privileges of data and code sections. */
    OS_ARCH_MTCR(OS_DPRE0, 0x0001u);  /* All data regions are R */
    OS_ARCH_MTCR(OS_DPWE0, 0x0001u);  /* All data regions are W*/
    OS_ARCH_MTCR(OS_CPXE0, 0x0001u);  /* All code regions are E */

    Os_ArchSetMemProtSet(0x00UL);
    return;
}

/******************************************************************************/
/*
 * Brief                <Os_ArchSetIsrMemMap>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_EnterISR2,Os_ExitISR2>
 * REQ ID               <DD_1_0758, DD_1_0759, DD_1_1308, DD_1_1309, DD_1_1310>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSetIsrMemMap
(
    ISRType         IsrId, 
    ApplicationType HostAppId, 
    uint32          isTrusted
)
{
    CoreIdType coreId;
    uint32 temp = (Os_ArchGetMemProtSet() & 0x00003000U) >> 12u;
    uint8 OsDPRStart;
    uint8 OsCPRStart;

    coreId = Os_SCB.sysCore;

    /* Find out which register set in use  register 0 should not be used here */
    if (0x02U == temp)
    {
        /*set 2: OS_DPR_7~OS_DPR_12, OS_CPR_4~OS_CPR_6*/
        OsDPRStart = 7u;
        OsCPRStart = 4u;
        if (TRUE != isTrusted) /* Non-trusted app running. */
        {
            Os_ArchSetNonTruIsrReg(OS_DPR_7L, OS_CPR_4L, OsDPRStart,\
                    OsCPRStart, OS_DPRE2, OS_DPWE2, OS_CPXE2, \
                    IsrId, HostAppId, coreId);
        }
        else  /* Trusted app or os_kernel running. */
        {
            /*OSTrustedApplicationWithProtection != TRUE*/
            if (Os_AppCfg[HostAppId].OsTrustedAppWithProtection != TRUE)
            {
                Os_ArchSetTruReg(OS_DPR_7L, OS_CPR_4L, OsDPRStart, OsCPRStart,\
                        OS_DPRE2, OS_DPWE2, OS_CPXE2);
            }
            else
            {
                Os_ArchSetTruIsrProtReg(OS_DPR_7L, OS_CPR_4L, OsDPRStart,\
                        OsCPRStart, OS_DPRE2, OS_DPWE2, OS_CPXE2, IsrId,\
                        HostAppId);
            }
        }
    }
    else
    {
        #if (TRUE == CFG_PROTECTIONHOOK)
        (void)Os_CallProtectionHook(E_OS_PROTECTION_MEMORY, \
                OS_TMPROT_HOOK_OSAPP);
        #endif /* TRUE == CFG_PROTECTIONHOOK */
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <MemMap for Memory Protection Settings Task>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ExitISR2, Os_SwitchTask>
 * REQ ID               <DD_1_0760, DD_1_0761, DD_1_1311, DD_1_1312, DD_1_1313>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSetTaskMemMap
(
    TaskType        TaskId, 
    ApplicationType HostAppId, 
    uint32          isTrusted
)
{
    CoreIdType coreId;
    uint32 temp = (Os_ArchGetMemProtSet() & 0x00003000U) >> 12u;
    uint8 OsDPRStart;
    uint8 OsCPRStart;

    coreId = Os_SCB.sysCore;

    /* Find out which register set in use  register 0 should not be used here */
    if (0x01U == temp)
    {
        /*set 1: OS_DPR_1~OS_DPR_6, OS_CPR_1~OS_CPR_3*/
        OsDPRStart = 1u;
        OsCPRStart = 1u;
        if (TRUE != isTrusted) /* Non-trusted app running. */
        {
            Os_ArchSetNonTruTskReg(OS_DPR_1L, OS_CPR_1L, OsDPRStart, \
                    OsCPRStart, OS_DPRE1, OS_DPWE1, OS_CPXE1, TaskId, \
                    HostAppId, coreId);
        }
        else  /* Trusted app or os_kernel running. */
        {
            /*OSTrustedApplicationWithProtection != TRUE*/
            if (Os_AppCfg[HostAppId].OsTrustedAppWithProtection != TRUE)
            {
                Os_ArchSetTruReg(OS_DPR_1L, OS_CPR_1L, OsDPRStart, OsCPRStart,\
                        OS_DPRE1, OS_DPWE1, OS_CPXE1);
            }
            else
            {
                Os_ArchSetTruTskProtReg(OS_DPR_1L, OS_CPR_1L, OsDPRStart, \
                        OsCPRStart, OS_DPRE1, OS_DPWE1, OS_CPXE1, TaskId, \
                        HostAppId);
            }
        }
    }
    else
    {
        #if (TRUE == CFG_PROTECTIONHOOK)
        (void)Os_CallProtectionHook(E_OS_PROTECTION_MEMORY, OS_TMPROT_HOOK_OSAPP);
        #endif /* TRUE == CFG_PROTECTIONHOOK */
    }

    return;
}
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */



/******************************************************************************/
/*
 * Brief                <OS_ShutdownAllCores is not provide user>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <GetSpinlock and so on>
 * REQ ID               <DD_1_1079>
 */
/******************************************************************************/
INLINE uint32 Os_CmpSwapW(uint32* address, uint32 compareVal, uint32 exchangedVal)
{
    uint32 tmp = __cmpswapw((unsigned int *)address, exchangedVal, compareVal);
    return tmp;
}

/******************************************************************************/
/*
 * Brief                <Set interrupt priority>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <srcAddr,prio,srcType,isrProc>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0762>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InterruptInstall
(
    uint32 srcAddr,
    uint8 prio,
    uint32 srcType,
    Os_isrhnd isrProc
)
{

    (*((uint32 volatile *) srcAddr)) = (((*((uint32 volatile *) srcAddr))
                                        & 0xFFFFFF00u) | 0x00000400u | srcType) + (prio);

    Cdisptab[prio] = isrProc;
}

/******************************************************************************/
/*
 * Brief                <Initialize interrupts and traps>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_ArchInitCPU>
 * REQ ID               <DD_1_0902, DD_1_1298>
 */
/******************************************************************************/

static FUNC(void, OS_CODE) Os_InterruptInit(void)
{
    uint32 *vptr;
    uint32 vecno;
    Os_CoreIdType  coreId = Os_SCB.sysCore;

    Os_IntNestISR1 = 0;
    Os_IntNestISR2 = 0;
    Os_SaveLevelISR1 = OS_LEVEL_TASK;

	/* Set BTV and BIV registers.  */
	Os_ArchResetENDINIT(coreId);
    //TriCore_trap_table
	vptr = (uint32 *)TriCore_trap_table;
	__mtcr(OS_REG_BTV,  (unsigned int)vptr);
	vptr = (uint32 *)TriCore_int_table;
	__mtcr(OS_REG_BIV,  (unsigned int)vptr);
	Os_ArchSetENDINIT(coreId);

	/* Initialize the trap handlers.  */
	Tdisptab[0] = Os_Trap0;
	Tdisptab[1] = Os_Trap1;
	Tdisptab[2] = Os_Trap2;
	Tdisptab[3] = Os_Trap3;
	Tdisptab[4] = Os_Trap4;
	Tdisptab[5] = Os_Trap5;
	Tdisptab[6] = Os_SystemCallTrap;
	Tdisptab[7] = Os_Trap7;


    /* Initialize the interrupt handlers.  */
	for (vecno = 0u; vecno < MAX_INTRS; vecno++)
	{
		Cdisptab[vecno] = Os_IntHandler;
	}

	(void)coreId;
    return;
}

/******************************************************************************/
/*
 * Brief                <Os_ArchGetCoreID>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * Return               <CoreId>
 * PreCondition         <None>
 * CallByAPI            <GetCoreID>
 * REQ ID               <DD_1_0763, DD_1_0764>
 */
/******************************************************************************/
FUNC(Os_CoreIdType, OS_CODE) Os_ArchGetCoreID(void)
{
    return ((Os_CoreIdType)OS_ARCH_MFCR(OS_REG_CUS_ID) & OS_CORE_ID_MSK);
}

/******************************************************************************/
/*
 * Brief                <Os_ArchStartCore>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-coreId[in]     <selects the core which to start>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartCore>
 * REQ ID               <DD_1_0765, DD_1_0766>
 */
/******************************************************************************/


#define MODULE_CPU0 /*lint --e(923, 9078)*/ ((*(Ifx_CPU*)0xF8800000u))
#define MODULE_CPU1 /*lint --e(923, 9078)*/ ((*(Ifx_CPU*)0xF8820000u))
#define MODULE_CPU2 /*lint --e(923, 9078)*/ ((*(Ifx_CPU*)0xF8840000u))

FUNC(void, OS_CODE) Os_ArchStartCore(Os_CoreIdType coreId)
{
	if (1u == coreId)
    {
		Ifx_Ssw_startCore(&MODULE_CPU1, (unsigned int)_START1);
//    	OS_CPU1_PC = (uint32)CFG_CORE1_START_ADDRESS;
//    	Os_ArchResetENDINIT(coreId);
//    	OS_CPU1_SYSCON = OS_CPU1_SYSCON & (~(1<<24));
//    	Os_ArchSetENDINIT(coreId);
    }
    else if (2u == coreId)
    {
    	Ifx_Ssw_startCore(&MODULE_CPU2, (unsigned int)_START2);
//    	OS_CPU2_PC = (uint32)CFG_CORE2_START_ADDRESS;
//    	Os_ArchResetENDINIT(coreId);
//    	OS_CPU2_SYSCON = OS_CPU2_SYSCON & (~(1<<24));
//    	Os_ArchSetENDINIT(coreId);
    }
    else
    {
        /* Nothing to do. */
    }
}

/******************************************************************************/
/*
 * Brief                <Get the Core Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <selects the core which to get mode>
 * Return               <Os_CoreModeType,the core mode>
 * PreCondition         <None>
 * CallByAPI            <Os_SetCoreMode>
 * REQ ID               <DD_1_0767, DD_1_0768>
 */
/******************************************************************************/
FUNC(Os_CoreModeType, OS_CODE) Os_GetCoreMode(Os_CoreIdType core)
{
    Os_CoreModeType    coreMode = OS_CORE_MODE_UNKNOWN;
    StatusType Status = E_OK;
    volatile uint32*  pmcsr;
    uint32             tempRegValue;

    if (core != Os_ArchGetCoreID())
    {
        switch (core)
        {
            case 0:
                tempRegValue = OS_REG32(OS_CPU0_DBGSR_ADDR);
                pmcsr = &OS_SCU_PMCSR0;
                break;

            case 1:
                tempRegValue = OS_REG32(OS_CPU1_DBGSR_ADDR);
                pmcsr = &OS_SCU_PMCSR1;
                break;

            case 2:
                tempRegValue = OS_REG32(OS_CPU2_DBGSR_ADDR);
                pmcsr = &OS_SCU_PMCSR2;
                break;

				/*add comments to pass QAC.*/
            default:
                Status = E_NOT_OK;
                break;
        }
    }
    else
    {
        switch (core)
        {
            case 0:
                tempRegValue = OS_ARCH_MFCR(OS_CPU0_DBGSR_ADDR);
                pmcsr = &OS_SCU_PMCSR0;
                break;

            case 1:
                tempRegValue = OS_ARCH_MFCR(OS_CPU1_DBGSR_ADDR);
                pmcsr = &OS_SCU_PMCSR1;
                break;

            case 2:
                tempRegValue = OS_ARCH_MFCR(OS_CPU2_DBGSR_ADDR);
                pmcsr = &OS_SCU_PMCSR2;
                break;

                /*add comments to pass QAC.*/
            default:
                Status = E_NOT_OK;
                break;
        }
    }

    if ((StatusType)E_OK == Status)
    {
        /*get the DBGSR.HALT status */
        tempRegValue &= 0x00000006u;

        /*Check if the requested CPU is in DBGSR HALT mode */
        if (0x00000002U == tempRegValue)
        {
            coreMode = OS_CORE_MODE_HALT;
        }
        else if (0x00000000U == tempRegValue)/*CPU is in DBGSR RUNNING mode*/
        {
            /* Get PMCSR.PMST status */
            tempRegValue = *pmcsr;
            tempRegValue &= 0x00000700U;

            if (0x00000100U == tempRegValue)
            {
                coreMode = OS_CORE_MODE_RUN;
            }
            else if (0x00000300U == tempRegValue)
            {
                coreMode = OS_CORE_MODE_IDLE;
            }
            else
            {
                coreMode = OS_CORE_MODE_UNKNOWN;
            }
        }
        else
        {
            coreMode = OS_CORE_MODE_UNKNOWN;
        }
    }
    return coreMode;
}

/******************************************************************************/
/*
 * Brief                <Set the Core Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <Selects the core which mode is set>
 * Return               <boolean,the result of setting>
 * PreCondition         <None>
 * CallByAPI            <ControlIdle>
 * REQ ID               <DD_1_0769, DD_1_0770>
 */
/******************************************************************************/
FUNC(boolean, OS_CODE) Os_SetCoreMode(Os_CoreIdType core,  Os_CoreModeType coreMode)
{
    boolean             RetVal = TRUE;
    Os_CoreModeType     curCoreMode = OS_CORE_MODE_UNKNOWN;
    volatile uint32*   pmcsr;
    volatile uint32    Temp;
    /* Check the mode the Core is in */
    curCoreMode = Os_GetCoreMode(core);

    if (coreMode != curCoreMode)
    {
        switch (core)
        {
            case 0:
                pmcsr = &OS_SCU_PMCSR0;
                break;
            case 1:
                pmcsr = &OS_SCU_PMCSR1;
                break;
            case 2:
                pmcsr = &OS_SCU_PMCSR2;
                break;

            /*add comments to pass QAC.*/
            default:
                RetVal = FALSE;
                break;
        }

        if ((boolean)TRUE == RetVal)
        {
            /* transition from halt to Run */
            if (OS_CORE_MODE_HALT == curCoreMode)
            {
                if (OS_CORE_MODE_RUN == coreMode)
                {
                    Os_ArchStartCore(core);
                }
                else
                {
                    /* cannot go to any other mode e.g. IfxCpu_CoreMode_idle */
                    RetVal = FALSE;
                }
            }
            /* From Run to Idle */
            else if (OS_CORE_MODE_RUN == curCoreMode)
            {
                if (OS_CORE_MODE_IDLE == coreMode)
                {
                	Os_ArchResetENDINIT(core);
                    Temp = *pmcsr;
                    Temp &= 0xfffffffcu;
                    Temp |= 0x00000001u;
                    *pmcsr = Temp;
                    Os_ArchSetENDINIT(core);
                }
                else
                {
                    RetVal = FALSE;
                }
            }
            /* idle to Run */
            else if (OS_CORE_MODE_IDLE == curCoreMode)
            {
                if (OS_CORE_MODE_RUN == coreMode)
                {
                	Os_ArchResetENDINIT(core);
                    *pmcsr &= 0xfffffffcu;
                    Os_ArchSetENDINIT(core);
                }
                else
                {
                    RetVal = FALSE;
                }
            }
            else
            {
                RetVal = FALSE;
            }
        }
    }

    return RetVal;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
