/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Intvet.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-07-05 11:18:43>
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>     <AUTHOR>      <REVISION LOG>
 *   V1.0.0       20141111     bo.zeng      Initial version
 *   V2.0.0       20170503     zuxiong.ding Multicore
 *   V3.0.0       20191121     shun.li      Functional safety version
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Cfg.h"
#include "Os_Internal.h"
#include "Os_Processor.h"

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_VECTOR_C_AR_MAJOR_VERSION     4U
#define OS_VECTOR_C_AR_MINOR_VERSION     2U
#define OS_VECTOR_C_AR_PATCH_VERSION     2U
#define OS_VECTOR_C_SW_MAJOR_VERSION     1U
#define OS_VECTOR_C_SW_MINOR_VERSION     0U
#define OS_VECTOR_C_SW_PATCH_VERSION     0U

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_VECTOR_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Major Version"
#endif
#if (OS_VECTOR_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Minor Version"
#endif
#if (OS_VECTOR_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Patch Version"
#endif
#if (OS_VECTOR_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Major Version"
#endif
#if (OS_VECTOR_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Minor Version"
#endif

/*=======[M A C R O S]========================================================*/
#define     OS_ARCH_INT_CORE0                  OS_ARCH_INT_CPU0

/*==========[I S R]===========================================================*/
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
/* --------------------CORE0-------------------- */
FUNC(void, OS_CODE_FAST) Os_ISR_STM0_SR0(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_SYS_TIMER_CORE0_ID));
    if (0x02 == (OS_STM0_ICR & 0x00000002))
    {
        OS_STM0_ISCR = OS_STM0_ISCR | 0x00000001;
        OS_STM0_CMP0 = CFG_REG_OSTIMER_VALUE_CORE0 + OS_STM0_CMP0;
        if(OS_STM0_CMP0 - OS_STM0_TIM0 > CFG_REG_OSTIMER_VALUE_CORE0)
        {
            OS_STM0_CMP0 = CFG_REG_OSTIMER_VALUE_CORE0 + OS_STM0_TIM0 ;
        }
    }
    Os_ArchSystemTimerCore0();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CAN0_INT4(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CAN0_INT4_ID));
    ISR_CAN0_INT4();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CAN0_INT5(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CAN0_INT5_ID));
    ISR_CAN0_INT5();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CAN0_INT6(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CAN0_INT6_ID));
    ISR_CAN0_INT6();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CAN0_INT7(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CAN0_INT7_ID));
    ISR_CAN0_INT7();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CAN1_INT0(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CAN1_INT0_ID));
    ISR_CAN1_INT0();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CAN1_INT1(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CAN1_INT1_ID));
    ISR_CAN1_INT1();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CAN1_INT2(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CAN1_INT2_ID));
    ISR_CAN1_INT2();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CAN1_INT3(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CAN1_INT3_ID));
    ISR_CAN1_INT3();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_GTM_TOM0_2(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_GTM_TOM0_2_ID));
    ISR_GTM_TOM0_2();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_GTM_TOM1_0(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_GTM_TOM1_0_ID));
    ISR_GTM_TOM1_0();
    OS_ARCH_ISR2_EPILOGUE();
}
/* ------------------Interrupt install-------------------- */
FUNC(void, OS_CODE) Os_IntHandler(void)
{
    /* Just ignore this interrupt.  */
    while(1){}
}
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_ArchInitIntPrio(void)
{
    Os_CoreIdType coreID = Os_SCB.sysCore;
    switch(coreID)
    {
        case 0:
                Os_InterruptInstall(OS_SRC_STM0_SR0_ADDR, 199U, OS_ARCH_INT_CORE0, Os_ISR_STM0_SR0);
                Os_InterruptInstall(OS_SRC_CAN0_INT4_ADDR, 40U, OS_ARCH_INT_CORE0, Os_ISR_CAN0_INT4);
                Os_InterruptInstall(OS_SRC_CAN0_INT5_ADDR, 41U, OS_ARCH_INT_CORE0, Os_ISR_CAN0_INT5);
                Os_InterruptInstall(OS_SRC_CAN0_INT6_ADDR, 42U, OS_ARCH_INT_CORE0, Os_ISR_CAN0_INT6);
                Os_InterruptInstall(OS_SRC_CAN0_INT7_ADDR, 43U, OS_ARCH_INT_CORE0, Os_ISR_CAN0_INT7);
                Os_InterruptInstall(OS_SRC_CAN1_INT0_ADDR, 51U, OS_ARCH_INT_CORE0, Os_ISR_CAN1_INT0);
                Os_InterruptInstall(OS_SRC_CAN1_INT1_ADDR, 52U, OS_ARCH_INT_CORE0, Os_ISR_CAN1_INT1);
                Os_InterruptInstall(OS_SRC_CAN1_INT2_ADDR, 53U, OS_ARCH_INT_CORE0, Os_ISR_CAN1_INT2);
                Os_InterruptInstall(OS_SRC_CAN1_INT3_ADDR, 54U, OS_ARCH_INT_CORE0, Os_ISR_CAN1_INT3);
                Os_InterruptInstall(OS_SRC_GTM_TOM0_2_ADDR, 30U, OS_ARCH_INT_CORE0, Os_ISR_GTM_TOM0_2);
                Os_InterruptInstall(OS_SRC_GTM_TOM1_0_ADDR, 28U, OS_ARCH_INT_CORE0, Os_ISR_GTM_TOM1_0);
        break;
        default:
        break;
    }
    return;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/

