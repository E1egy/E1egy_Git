/*!
****************************************************************************************
*
*  Copyright: 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   PowerDriver.h
* \author  BL_zq
* \version 1.0
* \date    2022-10-09
* \btief  The header file of PowerDriver.c
*
*---------------------------------------------------------------------------------------
* \attention
*
*
****************************************************************************************
*/

/***************************************************************************************
    change history:
        1.date  : 2022-10-09
         author: BL_zq
         change: create file

***************************************************************************************/

#ifndef  POWERDRIVER_H
#define  POWERDRIVER_H

/***************************************Includes***************************************/
#include "Platform_Types.h"

/***************************************Macros****************************************/
#define CANIF_RXPDU_ESP_NM_CH 417u
//#define
#define OFF 0
#define ON  1

/**Shaking time elimination  **/
#define MAX_IGNITION_TIME  1/**Ignition shake time  **/
#define T_ACC_OFF_TIME     3/**ACC detects OFF shake time  **/
#define T_ACC_ON_TIME      3/**ACC detects ON shake time  **/

/**Shutdown factor:
* 0:ACC OFF True shutdown
* 1:B+ abnormally shuts down  **/
#define SetBit(Var,Place) ((Var)|=(uint8)(1<<(Place)))
#define ClrBit(Var,Place) ((Var) = (uint8)((Var)&((1<<(Place))^255)))
#define ValBit(Var,Place) ((Var)& (1<<(Place)))

#define  F_ACC_OFF_REQ 0
#define  F_ACC_Off_Req_Set         SetBit(Power.PowerOffFactor,F_ACC_OFF_REQ)
#define  F_ACC_Off_Req_Clr         ClrBit(Power.PowerOffFactor,F_ACC_OFF_REQ)
#define  F_ACC_Off_Req_Val         ValBit(Power.PowerOffFactor,F_ACC_OFF_REQ)
#define  F_ACC_On_Req_Set         SetBit(Power.PowerOnFactor,F_ACC_OFF_REQ)
#define  F_ACC_On_Req_Clr         ClrBit(Power.PowerOnFactor,F_ACC_OFF_REQ)
#define  F_ACC_On_Req_Val         ValBit(Power.PowerOnFactor,F_ACC_OFF_REQ)

#define  F_CANINH_On_REQ 1
#define  F_CANINH_On_Req_Set         SetBit(Power.PowerOnFactor,F_CANINH_On_REQ)
#define  F_CANINH_On_Req_Clr         ClrBit(Power.PowerOnFactor,F_CANINH_On_REQ)
#define  F_CANINH_On_Req_Val         ValBit(Power.PowerOnFactor,F_CANINH_On_REQ)

#define BATTERY_VOLTAGE_16V5 (16.5 *1000)
#define BATTERY_VOLTAGE_16V  (16 *1000)
#define BATTERY_VOLTAGE_12V  (12 *1000)
#define BATTERY_VOLTAGE_6V  (6*1000)
#define BATTERY_VOLTAGE_5V8   (5.8  *1000)
#define BATTERY_VOLTAGE_NORMAL   0
#define BATTERY_VOLTAGE_LOW_VOLTAGE 1
#define BATTERY_VOLTAGE_HIGH_VOLTAGE  2

#define T_BATTERY_VOLTAGE_NORMAL_DETECT_TIME   5
#define T_BATTERY_VOLTAGE_ABNORMAL_DETECT_TIME 20


/***************************************Enum*****************************************/
/**ACC State  **/
typedef enum
{
    ACC_STATE_INIT=0,
    ACC_STATE_OFF,
    ACC_STATE_ON
} ACC_STATE;

/**Main power State  **/
typedef enum
{
    POWER_ON_OPEN_MODULE=0,
    POWER_SYS_RUNNING,
    POWER_OFF_CLOSE_MODULE,
    POWER_SLEEP,
#if 0
    POWER_OFF_PRE_SLEEP,
    POWER_OFF_SYS_DEEP_SLEEP
#endif
}POWER_STATUS;
/***************************************Union****************************************/

/***************************************Struct***************************************/
/**Power management architecture  **/
typedef struct
{
    POWER_STATUS MainPowerState;        /**Main power state  **/
    uint16 WaitTimer;                   /**Delay time  **/

#if 0    
    uint8  BatteryState;                /**B+ state  **/
    uint16 IgnitionBatteryLowVolTimer;  /**B+ ignition low voltage shake time **/
    uint16 BatteryVoltage;              /**B+ voltage value  **/
    uint8  BattQuickScan;               /**B+ Quick detection function  **/
#endif

    uint8 AccState;                     /**ACC state  **/
    uint16 AccTimer;                    /**ACC OFF True shutdown detection of shake time **/
    uint8 AccDetectFactor;              /**ACC OFF/ON Pin state **/
    
    uint8 PowerOffFactor;               /**True shutdown factor  **/
    uint8 PowerOnFactor;                /**Power on factor  **/

    uint8 PowerOffStep;
}POWER_MANAGER_STRUCT;


/***************************************Variables*************************************/
//extern 
extern POWER_MANAGER_STRUCT Power;
extern uint8 g_CanBusSleepStatus;
/***************************************Functions************************************/
//extern 
extern void PowerDrv_AccDetect(void);
extern void PowerOff_BatteryDectet(void);
extern uint8 GetPowerStatus(void);
extern void PowerDrv_Tasking(void);
extern void PowerDrv_SetModulePowerOff(void);
extern uint8 SetTja1463ToSleep(void);
#endif
/*  END OF FILE */
