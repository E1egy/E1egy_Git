/*!
***********************************************************************************
*
*  Copyright: 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   Wdg_17_Scu_Driver.c
* \author  BL_zq
* \version 1.0
* \date    2022-09-27
* \btief   Wdg_17_Scu_Driver Program Code
*
*----------------------------------------------------------------------------------
* \attention
*
*
***********************************************************************************
*/

/**********************************************************************************
    change history:
        1.date  : 2022-09-27
         author: BL_zq
         change: create file

***********************************************************************************/

/***************************************Includes************************************/
#include "Wdg_17_Scu_Driver.h"
#include "Wdg_17_Scu.h"
#include "IfxSrc_reg.h"
#include "Test_Print.h"
#include "Irq.h"

/***************************************Variables***********************************/
uint8 wdg0InitSuccessFlag = FALSE;
/***************************************Functions***********************************/
void Wdg17ScuDriver_Init(void)
{
    Std_ReturnType initRet;

    Mcal_WriteSafetyEndInitProtReg((uint32*)0xF0036834, 0xbc); /*KEYS*/
    Mcal_WriteSafetyEndInitProtReg((uint32*)0xF0036820, 0x00); /*SMU_CMD*/
    Mcal_WriteSafetyEndInitProtReg((uint32*)0xF0036960, 0x00); /*SMU_AGCF8_0*/
    Mcal_WriteSafetyEndInitProtReg((uint32*)0xF0036964, 0x0003fc00); /*SMU_AGCF8_1*/
    Mcal_WriteSafetyEndInitProtReg((uint32*)0xF0036968, 0x0003fc00); /*SMU_AGCF8_2*/
    Mcal_WriteSafetyEndInitProtReg((uint32*)0xF0036058u, 0x00000040); /*SCU_RSTCON.SMU need to be set to 1 for reset to occur*/
    Mcal_WriteSafetyEndInitProtReg((uint32*)0xF0036834, 0x00); /*KEYS*/
    if(wdg0InitSuccessFlag==FALSE)
    {
        Wdg_17_Scu_ConfigType *wdgConfig0 = &Wdg_17_Scu_Config_0;
        for(uint8 i = 0;i<10;i++)
        {
            initRet = Wdg_17_Scu_InitCheck(wdgConfig0);
            if(initRet == E_NOT_OK)
            {
                Wdg_17_Scu_Init(wdgConfig0);
                #if 1//(IRQ_OSEK_ENABLE == STD_OFF)
                SRC_GTMTOM10.B.IOVCLR = 1U;
                SRC_GTMTOM10.B.CLRR = 1U;
                SRC_GTMTOM10.B.SWSCLR = 1U;
                /* Enable the interrupt */
                SRC_GTMTOM10.B.SRE = 1;
                #endif
                Wdg_17_Scu_SetMode(WDGIF_SLOW_MODE);
                Wdg_17_Scu_SetTriggerCondition(5000);
            }
            else
            {
                break;
            }
        }
        wdg0InitSuccessFlag = TRUE;
        print_f("Wdg Init Success!\r\n");
    }
    return;
}
/*  END OF FILE */
