/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_UserInf.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2022-10-20 11:45:45>
 */
/*============================================================================*/


/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>     <AUTHOR>      <REVISION LOG>
 *   V1.0.0       20141111     bo.zeng      Initial version
 *   V2.0.0       20170615     shi.shu      Multicore
 *   V3.0.0       20191121     shun.li      Functional safety version
 *	 V3.1.0       20200421     shun.li      Add IOC function
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "IfxScu_reg.h"
#include "Ifx_Ssw_Infra.h"
#include "IfxCpu_reg.h"

#include "Os.h"
#include "Os_Extend.h"
#include "Dio.h"
#include "Can_17_McmCan.h"
#include "Mcu_17_TimerIp.h"
#include "Fee.h"
#include "Fls_17_Dmu.h"
#include "Dma.h"


#include "CanIf.h"
#include "Com.h"
#include "PduR.h"
#include "CanSM.h"
#include "ComM.h"
#include "CanNm.h"
#include "Xcp.h"
#include "Xcp_Internal.h"
#include "NvM.h"

#include "ComM_BswM.h"
#include "SchM_EcuM.h"
#include "SchM_BswM.h"
#include "PowerDriver.h"
#include "Dem.h"
#include "Dcm.h"
#include "CanTp.h"
#include "CanIf.h"
#include "PFlashDriver.h"
#include "DFlashDriver.h"
#include "EcuM.h"
#include "UDS_0x31.h"

uint8 useDate[6] = {0,0,0,0,0,0};
uint8 WakeupByCAN = TRUE;
uint8 WakeupByLocal = TRUE;
uint8 WakeUpSrc = 0;
extern boolean AppReqProg;
extern boolean AppValid;
extern boolean FblRecvDD01;
extern boolean DD01StayInBoot;
extern boolean FblRecv1001;

void (*p_AppEnter)(void);
#define FBL_START_FUNCTION_ADDRESS_CORE0 0xA0070200
#define APP_START_FUNCTION_ADDRESS_CORE0 0xA00D0024

extern void PcTestMainFunction(void);

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_USERAPP_C_AR_MAJOR_VERSION     4U
#define OS_USERAPP_C_AR_MINOR_VERSION     2U
#define OS_USERAPP_C_AR_PATCH_VERSION     2U
#define OS_USERAPP_C_SW_MAJOR_VERSION     1U
#define OS_USERAPP_C_SW_MINOR_VERSION     0U
#define OS_USERAPP_C_SW_PATCH_VERSION     0U 

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_USERAPP_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Major Version"
#endif 
#if (OS_USERAPP_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Minor Version"
#endif
#if (OS_USERAPP_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Patch Version"
#endif
#if (OS_USERAPP_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Major Version"
#endif
#if (OS_USERAPP_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Minor Version"
#endif

/*=======[T A S K S]==========================================*/
//Can_PduType PduInfo_1[] =
//{
//  {8,  8, 0x123, tx_data_1[0] },
//  {12, 8, 0x111, tx_data_1[1] },
//  {9,  8, 0x456, tx_data_1[2] },
//  {13, 8, 0x222, tx_data_1[3] }
//};
void Mcu_PflashTrapDisable(void)
{

	Ifx_SCU_WDTCPU *wdt      = &MODULE_SCU.WDTCPU[0];
	unsigned short  cpuWdtPw = Ifx_Ssw_getCpuWatchdogPassword(wdt);

    Ifx_Ssw_clearCpuEndinit(wdt, cpuWdtPw);

    MODULE_CPU0.FLASHCON1.B.MASKUECC = 1u;
    MODULE_CPU0.FLASHCON2.B.ECCCORDIS = 1u;

    Ifx_Ssw_setCpuEndinit(wdt, cpuWdtPw);
}
void Mcu_PflashTrapEnable(void)
{

	Ifx_SCU_WDTCPU *wdt      = &MODULE_SCU.WDTCPU[0];
	unsigned short  cpuWdtPw = Ifx_Ssw_getCpuWatchdogPassword(wdt);

    Ifx_Ssw_clearCpuEndinit(wdt, cpuWdtPw);

    MODULE_CPU0.FLASHCON1.B.MASKUECC = 0u;
    MODULE_CPU0.FLASHCON2.B.ECCCORDIS = 0u;

    Ifx_Ssw_setCpuEndinit(wdt, cpuWdtPw);
}

Com_IpduGroupVector ipduGroupVector;

uint8 g_100msCounter = 0;///< to achieve 1s cycle LED level flip, 100ms counter
uint32 Counter_100ms = 0;
uint32 Counter_10ms = 0;
uint32 Counter_2ms = 0;
uint32 Counter_1ms = 0;
uint8 CanWakeupEvent = 0;
uint8 IgWakeupEvent = 1;
uint8 g_hwVersion  = 0;

TASK(OsTask_CORE0_100MS)
{
    g_CanNmDetCounter++;
    g_CanIfDetCounter++;
    PcTestMainFunction();
    /* please insert your code here ... */
	Counter_100ms++;
	g_100msCounter++;
	if(g_100msCounter==1)
	{
		g_100msCounter = 0;
		Dio_FlipChannel(DioConf_DioChannel_MCU_LED);
	}

    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
uint8 g_20msFlag = 0;
uint8 g_10msCount = 0;
TASK(OsTask_CORE0_10MS)
{
    /* please insert your code here ... */
    PowerDrv_AccDetect();
    g_10msCount++;
    if(g_10msCount==2)
    {
        g_20msFlag = TRUE;
        g_10msCount = 0;
    }

    if(g_20msFlag == TRUE)
    {
        g_20msFlag = FALSE;
        PowerDrv_Tasking();
    }
	
    ComM_MainFunction(Channel_CanController_CAN1_FD);
    ComM_MainFunction(Channel_CanController_TEST_CAN);
	EcuM_MainFunction();
	BswM_MainFunction();
    GetSysVolData();
	Os_TaskEntry_Rte_OsTask_CORE0_10MS();

	CanTp_MainFunction();
	Dcm_MainFunction();

    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}


TASK(OsTask_CORE0_1MS)
{
    /* please insert your code here ... */
	Counter_1ms++;
    UserTestTaskCore0_1Ms();
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

TASK(OsTask_CORE0_2MS)
{
    /* please insert your code here ... */
    
#if 1//(FBL_IGNORE_DD01 == 1) /*Ignore DD01*/
	//Dio_FlipChannel(DioConf_DioChannel_ASENS_VCC_EN);
    if(Counter_2ms < 9)
    {
        Counter_2ms++;
    }
    else if(Counter_2ms == 9)
    {
        // AppVaild_Check();
        // if((FALSE == AppReqProg) && (TRUE == AppValid) && (FALSE == FblRecvDD01))
        // {
        //     print_f("Jump to APP.\n");
        //     //Dio_WriteChannel(DioConf_DioChannel_ASENS_VCC_EN,STD_HIGH);
        //     CanIf_SetControllerMode(0, CANIF_CS_STOPPED);
        //     CanIf_SetControllerMode(1, CANIF_CS_STOPPED);
        //     (*(volatile uint32*)(0xF000103Cu)) &= 0xFFFFFFFEu; //STM0_ICR   &= 0xFFFFFFFEu;
        //     (*(volatile uint32*)(0xF0108820u)) = 0; //GTM_TOM1_CH0_IRQ_EN = 0;
        //     (*(volatile uint32*)(0xF01080A0u)) = 0; //GTM_TOM0_CH2_IRQ_EN = 0;
        //     IfxCpu_disableInterrupts();
        //     p_AppEnter = (void(*)())APP_START_FUNCTION_ADDRESS_CORE0;
        //     (*p_AppEnter)();
        //     while (1);
        // }
        // else
        {
            print_f("Stay In FBL.\n");
            /*Stay In Boot*/
            DD01StayInBoot = TRUE;
            //Mcu_PflashTrapDisable();
        }
        Counter_2ms++;
    }
    else
    {
        /*Do nothing*/
    }
#endif
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}                     

TASK(OsTask_CORE0_5MS)
{
    /* please insert your code here ... */
    uint8 useDate[6] = {0,0,0,0,0,0};
    uint8 status = 0x08;

	CanSM_MainFunction();

    status = Tlf35584GetWakeupFlag();

	//if(((ACC_STATE_ON == Power.AccState) || ((status & 0x08) != 0)) && (TRUE == WakeupByLocal))
	if((ACC_STATE_ON == Power.AccState) && (TRUE == WakeupByLocal))
    {
       WakeUpSrc = 1;
       WakeupByLocal = FALSE;
       EcuM_SetWakeupEvent(EcuMWakeupSource_Local);
       useDate[0] = useDate[0] | 0x80;
    }
    else if(WakeupByCAN == TRUE)
    {
       WakeUpSrc = 2;
       WakeupByCAN = FALSE;
       EcuM_SetWakeupEvent(EcuMWakeupSource_Can);
    }
    if(2 == WakeUpSrc)
    {
        useDate[0] = useDate[0] | 0x20;
    }

    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

TASK(OsTask_CORE0_INIT)
{
    /* please insert your code here ... */
	uint8 hwVersionbit0 = 0;
	uint8 hwVersionbit1 = 0;
	uint8 hwVersionbit2 = 0;
	uint8 hwVersionbit3 = 0;
    uint8 Ret = 0;
    Counter_2ms = 0;
	AppReqProg = FALSE;
	AppValid = FALSE;
	FblRecvDD01 = FALSE;
	DD01StayInBoot = FALSE;
	FblRecv1001 = FALSE;
	print_f(" FBL OsTask_CORE0_INIT \n");

    AppReqProg_Check();
	Dma_Init(&Dma_Config);
	Tlf35584Init();
    PowerDrv_Init();
    hwVersionbit0 = (uint8)Dio_ReadChannel(DioConf_DioChannel_HW_BIT0);
    hwVersionbit1 = (uint8)Dio_ReadChannel(DioConf_DioChannel_HW_BIT1);
    hwVersionbit2 = (uint8)Dio_ReadChannel(DioConf_DioChannel_HW_BIT2);
    hwVersionbit3 = (uint8)Dio_ReadChannel(DioConf_DioChannel_HW_BIT3);
    g_hwVersion = hwVersionbit0 + (hwVersionbit1 << 1) + (hwVersionbit2 << 2) +(hwVersionbit3 << 3);

	Dio_WriteChannel(DioConf_DioChannel_LDO_3V3_EN,STD_HIGH);
	Dio_WriteChannel(DioConf_DioChannel_PMIC_MPS, STD_HIGH);

	if(g_hwVersion >= 4)
	{
		Dio_WriteChannel(DioConf_DioChannel_CAN2_EN,STD_HIGH);
		Dio_WriteChannel(DioConf_DioChannel_CAN2_STB,STD_HIGH);
	}else
	{
		Dio_WriteChannel(DioConf_DioChannel_CAN2_EN,STD_LOW);
		Dio_WriteChannel(DioConf_DioChannel_CAN2_STB,STD_HIGH);
	}

    EcuM_StartupTwo();
    //Dio_WriteChannel(DioConf_DioChannel_ASENS_VCC_EN,STD_HIGH);
#if 1
    Dio_WriteChannel(DioConf_DioChannel_IDT_ECAS_VB_SEN,STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_IDT_ECAS_CON_EXV,STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_IDT_ECAS_VB_CON,STD_HIGH);
#endif

    Ret = DFlashDriver_ReadDcmBlock();
    if(Ret != 0)
    {
        DFlashDriver_WriteDcmBlock();
    }

	PFlashDriver_maskPFlashUncorrectableEccBitErr();
	PFlashDriver_pflashCopyFunctionIntoPSPR();
    Mcu_PflashTrapDisable();
//	Mcu_PflashTrapEnable();
	UserTestTaskCore0_Init();
	DslInternal_InitSecCtrl();
	Os_TaskEntry_Rte_OsTask_CORE0_INIT();
    SetRelAlarm(OsAlarm_CORE0_1MS, 1, 1);
    SetRelAlarm(OsAlarm_CORE0_2MS, 1, 2);
    SetRelAlarm(OsAlarm_CORE0_5MS, 2, 5);
    //SetRelAlarm(OsAlarm_CORE0_NVM_5MS, 10, 5);
    SetRelAlarm(OsAlarm_CORE0_10MS, 6, 10);
    SetRelAlarm(OsAlarm_CORE0_100MS, 12, 100);
    //Dio_WriteChannel(DioConf_DioChannel_ASENS_VCC_EN,STD_LOW);

    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}   
                  
TASK(OsTask_CORE0_NVM_5MS)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}


/*=======[ALARM CALL BACK]==========================================*/

/*=======[H O O K S]================================================*/


FUNC(void, OS_APPL_CODE) IdleHook_Core0(void)
{
    /* please insert your code here ... */
}
void ErrorHook(StatusType Error)
{
   	/***The code below is just for deleting the complier warning.***
	 ***Please remove it and use your own code****/
	(void)Error;
	/***The code above is just for deleting the complier warning*/

    /* please insert your code here ... */
}

void StartupHook(void)
{
    /* please insert your code here ... */
}

void ShutdownHook(StatusType Error)
{
   	/***The code below is just for deleting the complier warning.***
	 ***Please remove it and use your own code****/
	(void)Error;
	/***The code above is just for deleting the complier warning*/

    /* please insert your code here ... */
    EcuM_Shutdown();
}



ISR(ISR_CAN0_INT4)
{
	/* please insert your code here ... */
	 Can_17_McmCan_IsrReceiveHandler(CAN_17_MCMCAN_HWMCMKERNEL0_ID, \
	                                  CAN_17_MCMCAN_HWMCMCONTROLLER01_ID);
}
/* ISR_CAN0_INT5: Core0(CPU0) */
ISR(ISR_CAN0_INT5)
{
	/* please insert your code here ... */
	  Can_17_McmCan_IsrTransmitHandler(CAN_17_MCMCAN_HWMCMKERNEL0_ID, \
	                                   CAN_17_MCMCAN_HWMCMCONTROLLER01_ID);
}
/* ISR_CAN0_INT6: Core0(CPU0) */
ISR(ISR_CAN0_INT6)
{
	/* please insert your code here ... */
	Can_17_McmCan_IsrBusOffHandler(CAN_17_MCMCAN_HWMCMKERNEL0_ID, \
	                                 CAN_17_MCMCAN_HWMCMCONTROLLER01_ID);
}
/* ISR_CAN0_INT7: Core0(CPU0) */
ISR(ISR_CAN0_INT7)
{
	/* please insert your code here ... */
	Can_17_McmCan_IsrRxFIFOHandler(CAN_17_MCMCAN_HWMCMKERNEL0_ID, \
	                                 CAN_17_MCMCAN_HWMCMCONTROLLER01_ID);
}


/* ISR_CAN1_INT0: Core0(CPU0) */
ISR(ISR_CAN1_INT0)
{
	/* please insert your code here ... */
	Can_17_McmCan_IsrReceiveHandler(CAN_17_MCMCAN_HWMCMKERNEL1_ID, \
	                                  CAN_17_MCMCAN_HWMCMCONTROLLER10_ID);
}
/* ISR_CAN1_INT1: Core0(CPU0) */
ISR(ISR_CAN1_INT1)
{
	/* please insert your code here ... */
	Can_17_McmCan_IsrTransmitHandler(CAN_17_MCMCAN_HWMCMKERNEL1_ID, \
	                                   CAN_17_MCMCAN_HWMCMCONTROLLER10_ID);
}
/* ISR_CAN1_INT2: Core0(CPU0) */
ISR(ISR_CAN1_INT2)
{
	/* please insert your code here ... */
	Can_17_McmCan_IsrBusOffHandler(CAN_17_MCMCAN_HWMCMKERNEL1_ID, \
	                                 CAN_17_MCMCAN_HWMCMCONTROLLER10_ID);
}
/* ISR_CAN1_INT3: Core0(CPU0) */
ISR(ISR_CAN1_INT3)
{
	/* please insert your code here ... */
	Can_17_McmCan_IsrRxFIFOHandler(CAN_17_MCMCAN_HWMCMKERNEL1_ID, \
	                                 CAN_17_MCMCAN_HWMCMCONTROLLER10_ID);
}


/* ISR_GTM_TOM0_2: Core0(CPU0) */
ISR(ISR_GTM_TOM0_2)
{
	/* please insert your code here ... */
	Mcu_17_Gtm_TomChannelIsr(0, 4);
}

/* ISR_GTM_TOM1_0: Core0(CPU0) */
ISR(ISR_GTM_TOM1_0)
{
	/* please insert your code here ... */
	Mcu_17_Gtm_TomChannelIsr(1, 0);
}

/*=======[E N D   O F   F I L E]==============================================*/


