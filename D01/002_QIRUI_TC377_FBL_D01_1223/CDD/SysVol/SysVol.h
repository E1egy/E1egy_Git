/*!
****************************************************************************************
*
*  Copyright: 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   SysVol.h
* \author  BL_zq
* \version 1.0
* \date    2022-10-20
* \btief  The header file of SysVol.c
*
*---------------------------------------------------------------------------------------
* \attention
*
*
****************************************************************************************
*/

/***************************************************************************************
    change history:
        1.date  : 2022-10-20
         author: BL_zq
         change: create file

***************************************************************************************/

#ifndef  SYSVOL_H
#define  SYSVOL_H

/***************************************Includes***************************************/
#include "Platform_Types.h"

/***************************************Macros****************************************/
#define     VLOTAGE_VIN_ADC         0
#define     VLOTAGE_ADC_5V8         1
#define     VLOTAGE_ADC_VQCO_5V     2
#define     VLOTAGE_ADC_VQVR_5V     3
#define     VLOTAGE_ADC_VQT1_5V     4
#define     VLOTAGE_ADC_VQT2_5V     5
#define     VLOTAGE_VQST_3V3        6
#define     VLOTAGE_LDO_3V3         7

/***************************************Enum*****************************************/

/***************************************Union****************************************/

/***************************************Struct***************************************/
typedef struct
{
    uint16 VIN_ADC;
    uint16 ADC_5V8;
    uint16 ADC_VQCO_5V;
    uint16 ADC_VQVR_5V;
    uint16 ADC_VQT1_5V;
    uint16 ADC_VQT2_5V;
    uint16 VQST_3V3;
    uint16 LDO_3V3;
} SysVolType;
/***************************************Variables*************************************/
extern float g_input12vVoltage;
extern SysVolType g_SysVol;
/***************************************Functions************************************/
extern void SysVolInit(void);
extern void GetSysVolData(void);
extern uint16 GetMonitorVoltage(uint8 channel);
#endif
/*  END OF FILE */
