/*!
***********************************************************************************
*
*  Copyright: 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   PowerDriver.c
* \author  BL_zq
* \version 1.0
* \date    2022-10-09
* \btief   PowerDriver Program Code
*
*----------------------------------------------------------------------------------
* \attention
*
*
***********************************************************************************
*/

/**********************************************************************************
    change history:
        1.date  : 2022-10-09
         author: BL_zq
         change: create file

***********************************************************************************/

/***************************************Includes************************************/
#include "PowerDriver.h"
#include "Std_Types.h"
#include "Dio_Cfg.h"
#include "Dio.h"
#include "Com_Cfg.h"
#include "CanIf_Cfg.h"
#include "IfxStm_reg.h"
#include "CanNm.h"
#include "CanIf.h"
#include "Com.h"
#include "Test_Print.h"
#include "ComM.h"
#include "SysVol.h"
//#include ""
/***************************************Variables***********************************/
extern boolean g_writeNvMSucessFlag;

POWER_MANAGER_STRUCT Power;
uint8 g_CanBusSleepStatus = FALSE;
/***************************************Functions***********************************/

/*******************************************************************************
** Syntax          :  uint8 Can_GetAccPowerStatus(void) 			                     
**                                                                              
** Description     :  Get get the status of CAN ACC                                       					 
**                                                                              
** Parameters (in) : none                                                       
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : none                                                       
**                                                                              
*******************************************************************************/
uint8 Can_GetAccPowerStatus(void)
{
    uint8 Viu_PowerMode = OFF;
    Std_ReturnType comStatus;

    comStatus = Com_ReceiveSignal(VIU_PowerMode_IPDU_COM_VIU_Info, &Viu_PowerMode);
    if (comStatus == E_OK)
    {
       if(Viu_PowerMode == ON)
       {
           return TRUE;
       }
       else if(Viu_PowerMode == OFF)
       {
           return FALSE;
       }
    }
    else
    {
        return FALSE;
    }
}

uint8 Can_GetCanfdInhStatus(void)
{
    Dio_LevelType canfdInhPinState = Dio_ReadChannel(DioConf_DioChannel_CANFD_INH_MCU);

    if(canfdInhPinState == STD_HIGH)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

uint8 SetTja1463ToSleep(void)
{
    Dio_WriteChannel(DioConf_DioChannel_CANFD_STB,STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_CANFD_EN,STD_HIGH);
}

uint8 SetTja1463ToNormal(void)
{
    #if 0
    Dio_WriteChannel(DioConf_DioChannel_CANFD_STB, STD_HIGH);
	Dio_WriteChannel(DioConf_DioChannel_CANFD_EN, STD_HIGH);
    #endif
}
/*******************************************************************************
** Syntax          :  void PowerDrv_AccDetect(void) 			                     
**                                                                              
** Description     :  Detect ACC state                                       					 
**                                                                              
** Parameters (in) : none                                                       
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : none                                                       
**                                                                              
*******************************************************************************/
void PowerDrv_AccDetect(void)
{
    uint8 accState=0;
    
#if 1
    Dio_LevelType accPinState = Dio_ReadChannel(DioConf_DioChannel_MCU_IGN_DET);
#else
    Dio_LevelType accPinState = STD_HIGH;
#endif
    uint8 accCanState = Can_GetAccPowerStatus();

    accPinState = STD_LOW;
    if((accPinState == STD_LOW) || (accCanState == TRUE))
    {
        accState = ACC_STATE_ON;
    }
    else
    {
        accState = ACC_STATE_OFF; 
    }

    if(Power.AccTimer<0xffff)
    {
        Power.AccTimer++;
    }
    
    if(accState == ACC_STATE_ON)
    {
        /**The shake time of ACC ON detect  **/
		if (Power.AccTimer >= T_ACC_ON_TIME)
        {
            Power.AccTimer = 0;
            Power.AccDetectFactor = ACC_STATE_ON;
        }
    }
    else
    {
        /**The shake time of ACC OFF detect  **/
        if(Power.AccTimer >= T_ACC_OFF_TIME)
        {
            Power.AccTimer = 0;
            Power.AccDetectFactor = ACC_STATE_OFF;
        }
    }

    if(((accState == ACC_STATE_ON)&&(Power.AccDetectFactor == ACC_STATE_ON))||
        ((accState == ACC_STATE_OFF)&&(Power.AccDetectFactor == ACC_STATE_OFF)))
    {
        Power.AccTimer = 0;
    }

    if(Power.AccDetectFactor == ACC_STATE_ON)
    {
        if(Power.AccState != ACC_STATE_ON)
        {
            Power.AccState = ACC_STATE_ON;
            F_ACC_Off_Req_Clr;
            print_f("ACC ON!\r\n");
        }

        if ((accPinState == STD_LOW)&&(!F_ACC_On_Req_Val))
        {
            F_ACC_On_Req_Set;
        }
        else if ((accCanState == TRUE)&&(!F_CANINH_On_Req_Val))
        {
            F_CANINH_On_Req_Set;
        }
    }
    else if(Power.AccDetectFactor == ACC_STATE_OFF)
    {
        if(Power.AccState != ACC_STATE_OFF)
        {
            Power.AccState = ACC_STATE_OFF;
            F_ACC_Off_Req_Set;
            print_f("ACC OFF!\r\n");
        }

        if ((accPinState == STD_HIGH)&&(F_ACC_On_Req_Val))
        {
            F_ACC_On_Req_Clr;
        }
        else if ((accCanState == FALSE)&&(F_CANINH_On_Req_Val))
        {
            F_CANINH_On_Req_Clr;
        }
    }
}

void PowerDrv_SetModulePowerOn(void)
{
#if 0
    Dio_WriteChannel(DioConf_DioChannel_LDO_3V3_EN,STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_IDET2_POW_EN,STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_ASENS_VCC_EN,STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_HSENS_VCC_EN,STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_TSENS_VCC_EN,STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_PSENS_VCC_EN,STD_HIGH);
#endif
}

void PowerDrv_SetModulePowerOff(void)
{
#if 0
    Dio_WriteChannel(DioConf_DioChannel_CANFD_STB,STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_CANFD_EN,STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_LDO_3V3_EN,STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_IDET2_POW_EN,STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_ASENS_VCC_EN,STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_HSENS_VCC_EN,STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_TSENS_VCC_EN,STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_PSENS_VCC_EN,STD_LOW);
#endif
}
uint8 g_PowerDownDelayCounter = 0;
void PowerDrv_ManageProcess(void)
{
    Nm_StateType cur_nmstate;
    Nm_ModeType cur_nmmode;

    if(ACC_STATE_ON == Power.AccState)
    {
        ComM_RequestComMode(ComMUser_Ch1,COMM_FULL_COMMUNICATION);
        //ComM_CommunicationAllowed(1, TRUE);
    }
    else if(ACC_STATE_OFF == Power.AccState)
    {
		ComM_RequestComMode(ComMUser_Ch1,COMM_NO_COMMUNICATION);
		//ComM_CommunicationAllowed(1, 0);
    }

#if 0
    switch (Power.MainPowerState)
    {
        case POWER_ON_OPEN_MODULE:
            print_f("Enter Power On Open Module!\r\n");
            /**After a cold startup or reset, wait for the true status of ACC  **/
            if(Power.AccState == ACC_STATE_INIT)
            {
                break;
            }
            /**Determine whether there is a shutdown factor  **/
            if(F_ACC_Off_Req_Val)
            {
                Power.MainPowerState = POWER_OFF_CLOSE_MODULE;
                break;
            }
            /**Turn on the peripheral power supply switch  **/
            PowerDrv_SetModulePowerOn();

            Power.MainPowerState = POWER_SYS_RUNNING;
            print_f("Exit Power On Open Module!\r\n");
            break;

        case POWER_SYS_RUNNING:
            if(F_ACC_Off_Req_Val)
            {
                Power.MainPowerState = POWER_OFF_CLOSE_MODULE;
            }
            break;
        
        case POWER_OFF_CLOSE_MODULE:
#if  1
            if ((g_CanBusSleepStatus == TRUE)&&(g_writeNvMSucessFlag))
            {
                print_f("Enter Power Off Close Module!\r\n");
                PowerDrv_SetModulePowerOff();
                SetTja1463ToSleep();
                Power.MainPowerState = POWER_SLEEP;
                print_f("Exit Power Off Close Module!\r\n");
            }
            else
            {
                if(Power.AccState == ACC_STATE_ON)
                {
                    Power.MainPowerState = POWER_ON_OPEN_MODULE;
                    break;
                }
                print_f(" CAN Active!\r\n");
            }
#else
            PowerDrv_SetModulePowerOff();
#endif
            break;
        
        case POWER_SLEEP:
            if(Power.AccState == ACC_STATE_ON)
            {
                g_PowerDownDelayCounter = 0;
                SetTja1463ToNormal();
                Power.MainPowerState = POWER_ON_OPEN_MODULE;
                print_f("Exit POWER SLEEP!\r\n");
                break;
            }

            if(Can_GetCanfdInhStatus() == TRUE)
            {
                print_f("Enter Power Sleep Delay 5 ms!\r\n");
#if 0
                if(g_PowerDownDelayCounter == 10)
                {
                    Dio_FlipChannel(DioConf_DioChannel_MCU_LED);
                    Tlf35584SetStateTransition_NormalToStandby();
                }  
                else if(g_PowerDownDelayCounter < 10)
                {
                    Dio_FlipChannel(DioConf_DioChannel_MCU_LED);
                    g_PowerDownDelayCounter++;
                }
#else
                Tlf35584SetStateTransition_NormalToStandby();
#endif
                print_f("Enter Power Sleep!\r\n");
                //Tlf35584SetStateTransition_NormalToStandby();
            }
            
            break;
        
        default:
            break;
    }
#endif
}

void PowerDrv_PrintfPowerMainStatus(void)
{
    switch (Power.MainPowerState)
    {
        case POWER_ON_OPEN_MODULE:
            print_f("Power On Open Module!\r\n");
            break;

        case POWER_SYS_RUNNING:
            print_f("Power Sys Runing!\r\n");
            break;
        
        case POWER_OFF_CLOSE_MODULE:
            print_f("Power Off Close Module!\r\n");
            break;
        
        case POWER_SLEEP:
            print_f("Power Enter Sleep!\r\n");
            break;
        
        default:
            break;
    }
}

uint8 g_batteryVoltageDetectTime = 0;
uint8 g_batteryVoltageStatus = BATTERY_VOLTAGE_NORMAL;
void PowerOff_BatteryDectet(void)
{
    uint8 batteryVoltageState = BATTERY_VOLTAGE_NORMAL, retVal = 0;
    uint16 sys12vValue = 0;

    sys12vValue = g_input12vVoltage * 1000;
    if(sys12vValue<=BATTERY_VOLTAGE_5V8)
    {
        batteryVoltageState = BATTERY_VOLTAGE_LOW_VOLTAGE;
    }
    if(sys12vValue>=BATTERY_VOLTAGE_16V5)
    {
        batteryVoltageState = BATTERY_VOLTAGE_HIGH_VOLTAGE;
    }
    else if((sys12vValue>=BATTERY_VOLTAGE_6V)&&(sys12vValue<=BATTERY_VOLTAGE_16V))
    {
        batteryVoltageState = BATTERY_VOLTAGE_NORMAL;
    }

    if(((batteryVoltageState==BATTERY_VOLTAGE_NORMAL)&&(g_batteryVoltageStatus==BATTERY_VOLTAGE_NORMAL))||
       ((batteryVoltageState==BATTERY_VOLTAGE_LOW_VOLTAGE)&&(g_batteryVoltageStatus==BATTERY_VOLTAGE_LOW_VOLTAGE))||
       ((batteryVoltageState==BATTERY_VOLTAGE_HIGH_VOLTAGE)&&(g_batteryVoltageStatus==BATTERY_VOLTAGE_HIGH_VOLTAGE)))
    {
        g_batteryVoltageDetectTime = 0;
    }
    else
    {
        g_batteryVoltageDetectTime++;
    }
    
    if(batteryVoltageState == BATTERY_VOLTAGE_NORMAL)
    {
        /**The shake time of ACC ON detect  **/
		if (g_batteryVoltageDetectTime >= T_BATTERY_VOLTAGE_NORMAL_DETECT_TIME)
        {
            g_batteryVoltageDetectTime = 0;
            g_batteryVoltageStatus = BATTERY_VOLTAGE_NORMAL;
        }
    }
    else if(batteryVoltageState == BATTERY_VOLTAGE_LOW_VOLTAGE)
    {
        /**The shake time of ACC OFF detect  **/
        if(g_batteryVoltageDetectTime >= T_BATTERY_VOLTAGE_ABNORMAL_DETECT_TIME)
        {
            g_batteryVoltageDetectTime = 0;
            g_batteryVoltageStatus = BATTERY_VOLTAGE_LOW_VOLTAGE;
        }
    }
    else if(batteryVoltageState == BATTERY_VOLTAGE_HIGH_VOLTAGE)
    {
        /**The shake time of ACC OFF detect  **/
        if(g_batteryVoltageDetectTime >= T_BATTERY_VOLTAGE_ABNORMAL_DETECT_TIME)
        {
            g_batteryVoltageDetectTime = 0;
            g_batteryVoltageStatus = BATTERY_VOLTAGE_HIGH_VOLTAGE;
        }
    }
}

/**
 * @brief Get the Sys Battery Voltage Status object
 * @function uint8 GetSysBatteryVoltageStatus(void)
 * @return uint8 
 * BATTERY_VOLTAGE_NORMAL - 0: 6.5V <= B+ <=18V,Supply voltage is normal.
 * BATTERY_VOLTAGE_LOW_VOLTAGE - 1: B+ <= 6V, Supply voltage is lower than the min of normal voltage.
 * BATTERY_VOLTAGE_HIGH_VOLTAGE - 2: B+>= 18.5V, Supply voltage is higher than the max of normal voltage.
 */
uint8 GetPowerStatus(void)
{
    return g_batteryVoltageStatus;
}


#define T_100MS 5
uint8 g_100msDetCount = 0;
void PowerDrv_Tasking(void)
{
    //if(g_CanNmSleepFlag == FALSE)
    {
        if(g_CanNmDetCounter > 3)
        {
            if(g_CanNmActiveCounter>0)
            {
                g_CanNmSleepFlag = FALSE;
                g_CanNmActiveCounter = 0;
                g_CanNmDetCounter = 0;
            }
            else
            {
                g_CanNmSleepFlag = TRUE;
                g_CanNmActiveCounter = 0;
                g_CanNmDetCounter = 0;
            }
        }
    }

    //if(g_CanIfSleepFlag == FALSE)
    {
        if(g_CanIfDetCounter > 3)
        {
            if(g_CanIfActiveCounter>0)
            {
                g_CanIfSleepFlag = FALSE;
                g_CanIfActiveCounter = 0;
                g_CanIfDetCounter = 0;
            }
            else
            {
                g_CanIfSleepFlag = TRUE;
                g_CanIfActiveCounter = 0;
                g_CanIfDetCounter = 0;
            }
        }
    }

    if ((g_CanNmSleepFlag == TRUE)&&(g_CanIfSleepFlag == TRUE))
    {
        g_CanBusSleepStatus = TRUE;
    }

    g_100msDetCount++;
    PowerOff_BatteryDectet();
    if(g_100msDetCount == T_100MS)
    {
        g_100msDetCount = 0;
    	PowerDrv_ManageProcess();
        GetVQT1ErrorStatus();
        GetVQT2ErrorStatus();
        GetVQCOErrorStatus();
    }
}

void PowerDrv_Init(void)
{
	Power.AccDetectFactor = ACC_STATE_INIT;
	Power.AccState = ACC_STATE_INIT;
	Power.AccTimer = 0;
	Power.MainPowerState = POWER_ON_OPEN_MODULE;
	Power.WaitTimer = 0;
	Power.PowerOffFactor = 0;

}
/*  END OF FILE */
