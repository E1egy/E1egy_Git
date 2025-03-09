/*
 * BswM_Ext.c
 *
 *  Created on: 2019年3月7日
 *      Author: Administrator
 */
#include "BswM.h"
#include "EcuM.h"
#include "EcuM_Externals.h"
#include "FreeRTimer.h"
//#include "Rte_Dcm.h"
#include "Rte_EcuM.h"
//#include "CanTrcv_Tja1145.h"
#include "Can_GeneralTypes.h"
#include "Dio.h"
#include "NvM.h"
#define SHUTDOWN_WRITEALL_TIMEOUT  200000 /*Test Value:66236*/
static uint32  NvMWriteAllCnt = 0;
static uint8 NvMWriteAllStatus;
static boolean EcuMRunTrigFlag = FALSE;
boolean g_bswMisGoingToSleep = FALSE;
void Communication_ON(void)
{
    BswM_RequestMode(66u, 1);
}

void Communication_OFF(void)
{
    BswM_RequestMode(66u, 0);
}

void BswM_CanTrcv_ModeShiftToNormal(void)
{
	Dio_WriteChannel(DioConf_DioChannel_CANFD_STB, STD_HIGH);
	Dio_WriteChannel(DioConf_DioChannel_CANFD_EN, STD_HIGH);
}

void BswM_CanTrcv_ModeShiftToStandBy(void)
{
	Dio_WriteChannel(DioConf_DioChannel_CANFD_STB, STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_CANFD_EN, STD_HIGH);
}

void BswM_AllowECU_Sleep(void)
{
	BswM_RequestMode(95u, 1);
}

void BswM_NotAllowECU_Sleep(void)
{
	BswM_RequestMode(95u, 0);
}


void WakeupSource_Disable(void)
{
	EcuM_DisableWakeupSources(EcuMWakeupSource_Can);

}

void WakeupSource_Enable(void)
{
	EcuM_EnableWakeupSources(EcuMWakeupSource_Can);
	/*comment because the whole circle needs to keep Trcv normal,except going to sleep*/
	/*CanTrcv_SetOpMode(0, CANTRCV_TRCVMODE_STANDBY);*/
}


void GenericSwitch_CanSmBusOff_NoCom_Ch0(void)
{
     BswM_RequestMode(240u, 0);
}

void GenericSwitch_CanSmBusOff_BusOffSilent_Ch0(void)
{
    BswM_RequestMode(240u, 1);
}
void GenericSwitch_CanSmBusOff_NoCom_Ch1(void)
{
	BswM_RequestMode(88u, 0);
}

void GenericSwitch_CanSmBusOff_BusOffSilent_Ch1(void)
{
	BswM_RequestMode(88u, 1);
}

void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_Ch1(void)
{
    EcuM_ClearWakeupEvent(EcuMWakeupSource_Can);
}

void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_Local(void)
{
    EcuM_ClearWakeupEvent(EcuMWakeupSource_Local);
}

void User_Dem_Init(void)
{

     /*Dem_Init(&DemPbCfg);*/
}

void BSW_User_Shutdown(void)
{
#if 0
	//Dcm_DiagStorageRequiredBeforeReset(FALSE);
    Dem_Shutdown();
	NvM_WriteAll();
	NvMWriteAllCnt = 0;
	do
	{
		NvMWriteAllCnt++;
		Fls_17_Dmu_MainFunction();
		Fee_MainFunction();
		NvM_MainFunction();
		NvM_GetErrorStatus(0,&NvMWriteAllStatus);
		if(SHUTDOWN_WRITEALL_TIMEOUT < NvMWriteAllCnt)
		{
		NvMWriteAllCnt = 0; 
		break;
		}
	}while (NvMWriteAllStatus == NVM_REQ_PENDING);
#endif
}


void BswM_EcuM_RequestRun(void)
{
    if(TRUE != EcuMRunTrigFlag)
    {
    	EcuMRunTrigFlag = TRUE;
        EcuM_RequestRUN(0u);
    }
}

void BswM_EcuM_ReleaseRun(void)
{
	g_bswMisGoingToSleep = TRUE;
    if(FALSE != EcuMRunTrigFlag)
    {
    	EcuMRunTrigFlag = FALSE;
        EcuM_ReleaseRUN(0u);
    }
}


void BswM_EcuM_RequestPostRun(void)
{
	EcuM_RequestPOST_RUN(0u);

	/*BswM_AllowECU_Sleep();*/
}

void BswM_EcuM_ReleasePostRun(void)
{
	EcuM_ReleasePOST_RUN(0u);
}


