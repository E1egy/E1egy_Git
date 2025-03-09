/*!
***********************************************************************************
*
*  Copyright: 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   SysVol.c
* \author  BL_zq
* \version 1.0
* \date    2022-10-20
* \btief   SysVol Program Code
*
*----------------------------------------------------------------------------------
* \attention
*
*
***********************************************************************************
*/

/**********************************************************************************
    change history:
        1.date  : 2022-10-20
         author: BL_zq
         change: create file

***********************************************************************************/

/***************************************Includes************************************/
#include "SysVol.h"
#include "Std_Types.h"
#include "Adc.h"
#include "IfxSrc_reg.h"
#include "Dma.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "Irq.h"
#include "Adc_Cfg.h"
/***************************************Variables***********************************/
__align(256) uint16 g_Adc_Hw_SysVol[128];
SysVolType g_SysVol;

float g_input12vVoltage = 0.0;
/***************************************Functions***********************************/
void SysVolInit(void)
{
    Dma_ConfigUpdateType ChannelUpdateStruct;

    if(Adc_GetStartupCalStatus() == E_OK)
    {
        while(Dma_IsInitDone() == TRUE)
        {}

        IRQ_SFR_MODIFY32 (SRC_VADCG0SR3.U,  IRQ_CLEAR_MASK, \
                            ((uint32)IRQ_ADC0_SR3_TOS | (uint32) IRQ_ADC0_SR3_PRIO));
        SRC_VADCG0SR3.U |= 0x400;
        /*!< 4 channel  16 FIFO Deep  uint16 By: BL_xtx 2022.4.14 */
        memset(&g_Adc_Hw_SysVol[0],0,128);
        ChannelUpdateStruct.DestAddress = (uint32)&g_Adc_Hw_SysVol[0];
        ChannelUpdateStruct.UpdateDestAddress = TRUE;
        ChannelUpdateStruct.UpdateDataCrc = FALSE;
        ChannelUpdateStruct.UpdateAddressCrc = FALSE;
        ChannelUpdateStruct.UpdateShadowConfig = FALSE;
        ChannelUpdateStruct.UpdateConfig = FALSE;
        ChannelUpdateStruct.UpdateControlAdicr = FALSE;
        ChannelUpdateStruct.UpdateControlChcsr = FALSE;
        ChannelUpdateStruct.UpdateSourceAddress = FALSE;

        /* Update the source address to SFR address of result register and destination
        address to RAM buffer */
        Dma_ChUpdate(26U, &ChannelUpdateStruct, NULL_PTR);
        /* Enable HW trigger for the DMA Channel used */

        Dma_ChEnableHardwareTrigger(26U);

        Adc_EnableHardwareTrigger(AdcConf_AdcGroup_SysVoltage);
    }
}

void GetSysVolData(void)
{
    uint8  Count = 0;
    uint16 AdcSum[8];
    uint32 data = 0;
    memset(AdcSum,0,8);

    Adc_DisableHardwareTrigger(AdcConf_AdcGroup_SysVoltage);
    for(Count =0 ; Count < 8; Count++)
    {
        AdcSum[0] += g_Adc_Hw_SysVol[Count*8];
        AdcSum[1] += g_Adc_Hw_SysVol[Count*8 + 1];
        AdcSum[2] += g_Adc_Hw_SysVol[Count*8 + 2];
        AdcSum[3] += g_Adc_Hw_SysVol[Count*8 + 3];
        AdcSum[4] += g_Adc_Hw_SysVol[Count*8 + 4];
        AdcSum[5] += g_Adc_Hw_SysVol[Count*8 + 5];
        AdcSum[6] += g_Adc_Hw_SysVol[Count*8 + 6];
        AdcSum[7] += g_Adc_Hw_SysVol[Count*8 + 7];
    }
    Adc_EnableHardwareTrigger(AdcConf_AdcGroup_SysVoltage);
    
    g_SysVol.VIN_ADC = AdcSum[0]/8;
    g_SysVol.ADC_5V8 = AdcSum[1]/8;
    g_SysVol.ADC_VQCO_5V = AdcSum[2]/8;
    g_SysVol.ADC_VQVR_5V = AdcSum[3]/8;
    g_SysVol.ADC_VQT1_5V = AdcSum[4]/8;
    g_SysVol.ADC_VQT2_5V = AdcSum[5]/8;
    g_SysVol.VQST_3V3 = AdcSum[6]/8;
    g_SysVol.LDO_3V3 = AdcSum[7]/8;

    g_input12vVoltage = (float)g_SysVol.VIN_ADC *4 /4095 *5  + 0.4;
}

uint16 GetMonitorVoltage(uint8 channel)
{
    uint16 voltage = 0;
    uint32 datacal = 0;

    switch (channel)
    {
        case VLOTAGE_VIN_ADC :
            datacal  = g_SysVol.VIN_ADC;
            voltage = datacal * 5000 * 4 / 4095  + 400;
            break;
        case VLOTAGE_ADC_5V8 :
            datacal  = g_SysVol.ADC_5V8;
            voltage = datacal * 5000 * 2 / 4095 ;
            break;
        case VLOTAGE_ADC_VQCO_5V :
            datacal  = g_SysVol.ADC_VQCO_5V;
            voltage = datacal * 5000 *2 / 4095;
            break;
        case VLOTAGE_ADC_VQVR_5V :
            datacal  = g_SysVol.ADC_VQVR_5V;
            voltage = datacal * 5000 *2 / 4095 ;
            break;
        case VLOTAGE_ADC_VQT1_5V :
            datacal  = g_SysVol.ADC_VQT1_5V;
            voltage = datacal * 5000 *2 / 4095 ;
            break;
        case VLOTAGE_ADC_VQT2_5V :
            datacal  = g_SysVol.ADC_VQT2_5V;
            voltage = datacal * 5000 *2 / 4095 ;
            break;
        case VLOTAGE_VQST_3V3 :
            datacal  = g_SysVol.VQST_3V3;
            voltage = datacal * 5000 / 4095 ;
            break;
        case VLOTAGE_LDO_3V3 :
            datacal  = g_SysVol.LDO_3V3;
            voltage = datacal * 5000 / 4095 ;
            break;
        default:
            break;
    }

    return voltage;
}
/*  END OF FILE */
