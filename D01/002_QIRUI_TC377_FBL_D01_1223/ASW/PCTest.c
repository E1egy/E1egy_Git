#include <string.h>
#include "Std_Types.h"

#include "Can_17_McmCan.h"
#include "Dio.h"

#include "Os.h"
#include "Com.h"
#include "Nm.h"

#include "SysVol.h"
#include "Rte_Type.h"
#include "Rte_Data.h"
#include "Rte_Main.h"
#include "Rte_UDS.h"

#include "PcTest.h"


#define 	SW_MAJOR_VERSION    1
#define 	SW_MINOR_VERSION    2
#define 	SW_PATCH_VERSION    3

PcCommandMsg  g_PcCommandMsgStruct;

uint8 g_sendMsgTrigFlag[6] ={FALSE,FALSE,FALSE,FALSE,FALSE,FALSE};
uint8 g_sendCanDataBuff[6][8];
Can_PduType g_sendCanPdu[6] =
{
    {Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_Height,8,0x6B1,g_sendCanDataBuff[0]},
    {Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_AccSensor_TEMP,8,0x6B2,g_sendCanDataBuff[1]},
    {Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_CDC_PRESS,8,0x6B3,g_sendCanDataBuff[2]},
    {Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_VALVE_VERSION,8,0x6B4,g_sendCanDataBuff[3]},
    {Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_VOLTAGE,8,0x6B5,g_sendCanDataBuff[4]},
    {Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_SYS,8,0x6B6,g_sendCanDataBuff[5]},
}; 
void SetPcCommandMsg(boolean flag ,uint8 *data,uint8 len)
{
    g_PcCommandMsgStruct.rxCmd = flag;
    g_PcCommandMsgStruct.magicNum   = data[0];
    memcpy(g_PcCommandMsgStruct.rxMsg,data,len);
}

boolean GetPcCommandIsActive(void)
{
    return g_PcCommandMsgStruct.pcCommandIsActive;
}


void OUtData(uint8 errId,uint32 adress)
{
	g_sendCanDataBuff[0][7] = errId;
	g_sendCanDataBuff[0][0] = (uint8)((adress >>24)&0xFF);
	g_sendCanDataBuff[0][1] = (uint8)((adress >>16)&0xFF);
	g_sendCanDataBuff[0][2] = (uint8)((adress >>8)&0xFF);
	g_sendCanDataBuff[0][3] = (uint8)(adress&0xFF);
	Can_17_McmCan_Write(g_sendCanPdu[0].swPduHandle,&g_sendCanPdu[0]);
}
/**
 * @brief 
 * @function
 */
void SendPcTestCanMsg(void)
{
    uint8 count  = 0;
    for(count = 0; count < 6; count++)
    {
        if(g_sendMsgTrigFlag[count])
        {
            Can_17_McmCan_Write(g_sendCanPdu[count].swPduHandle,&g_sendCanPdu[count]);
        }
    }
}

void PcTestMainFunction(void)
{
    uint8 count = 0;
    boolean dataBoolean[8] = {0};
    uint8 data8[4] = {0};
    uint8 data8Diags[8] = {0};
    uint16 data16[4] = {0};
    float32 datafloat[3] ={0.0};
    Nm_StateType    nmStatus = NM_STATE_NORMAL_OPERATION;
    Nm_ModeType     nmMode = NM_MODE_NETWORK;


    if(g_PcCommandMsgStruct.lossCmdCount < 10)
    {
        g_PcCommandMsgStruct.lossCmdCount++;
    }else
    {
        g_PcCommandMsgStruct.lossCmdCount = 10;
    }

    if(g_PcCommandMsgStruct.rxCmd)
    {
    	g_PcCommandMsgStruct.rxCmd = FALSE;
    	g_PcCommandMsgStruct.lossCmdCount = 0;
        g_sendMsgTrigFlag[0]  = (boolean)(g_PcCommandMsgStruct.rxMsg[1] & 0x01);
        g_sendMsgTrigFlag[1] =  (boolean)((g_PcCommandMsgStruct.rxMsg[1] >> 1)& 0x01);
        g_sendMsgTrigFlag[2] =  (boolean)((g_PcCommandMsgStruct.rxMsg[1] >> 2)& 0x01);
        g_sendMsgTrigFlag[3] =  (boolean)((g_PcCommandMsgStruct.rxMsg[1] >> 3)& 0x01);
        g_sendMsgTrigFlag[4] =  (boolean)((g_PcCommandMsgStruct.rxMsg[1] >> 4)& 0x01);
        g_sendMsgTrigFlag[5] =  (boolean)((g_PcCommandMsgStruct.rxMsg[1] >> 5)& 0x01);
        g_PcCommandMsgStruct.CDCEnableFlag =  (boolean)((g_PcCommandMsgStruct.rxMsg[1] >> 6)& 0x01);
        g_PcCommandMsgStruct.ValveEnableFlag =  (boolean)((g_PcCommandMsgStruct.rxMsg[1] >> 7)& 0x01);
        ///< Clear previous information
        memset(g_sendCanDataBuff,0,48);
    }else
    {
        for(count=0; count < 6; count++)
        {
            g_sendMsgTrigFlag[count] = FALSE;
        }
        g_PcCommandMsgStruct.CDCEnableFlag =  FALSE;
        g_PcCommandMsgStruct.ValveEnableFlag = FALSE;
    }

    if((g_PcCommandMsgStruct.lossCmdCount < 10)&&(g_PcCommandMsgStruct.magicNum == 0x55))
    {
    	g_PcCommandMsgStruct.pcCommandIsActive = TRUE;
    }else
    {
    	g_PcCommandMsgStruct.pcCommandIsActive = FALSE;
    }

    if(g_PcCommandMsgStruct.CDCEnableFlag && g_PcCommandMsgStruct.ValveEnableFlag)
    {
        for(count=0; count < 4; count++)
        {
            data16[count] = (uint16)g_PcCommandMsgStruct.rxMsg[2 + count] * 10;
        }

        for(count=0; count < 8; count++)
        {
            dataBoolean[count] = (boolean)(g_PcCommandMsgStruct.rxMsg[6] >> count) & 0x01;
        }

        if(dataBoolean[7])
        {
        	Dio_WriteChannel(DioConf_DioChannel_LED_EN,STD_HIGH);
        }else
        {
        	Dio_WriteChannel(DioConf_DioChannel_LED_EN,STD_LOW);
        }



    }else
    {
    	if((g_PcCommandMsgStruct.pcCommandIsActive)&&(g_PcCommandMsgStruct.lossCmdCount >= 5))
    	{

    	}
    }

    if(g_sendMsgTrigFlag[0])
    {


        for(count=0; count < 4; count++)
        {
             g_sendCanPdu[0].sdu[count] = data8[count];
        }
    }

    if(g_sendMsgTrigFlag[1])
    {

        for(count=0; count < 3; count++)
        {
             data8[count] = (uint8)((datafloat[count] +12) *10);
        }

        for(count=0; count < 3; count++)
        {
            g_sendCanPdu[1].sdu[count] = data8[count];
        }


        g_sendCanPdu[1].sdu[5] = (uint8)(data16[0] & 0xff);
        g_sendCanPdu[1].sdu[6] = (uint8)(data16[0] >> 8) & 0x1f;
    }

    if(g_sendMsgTrigFlag[2])
    {


        for(count=0; count < 4; count++)
        {
             data8[count] = (uint8)(data16[count] /7);
             //data8Diags[count] = GetCDCDriverDiagStatus(count);
             g_sendCanPdu[2].sdu[count] = data8[count];
        }
        
        g_sendCanPdu[2].sdu[4] =  data8Diags[0];
        g_sendCanPdu[2].sdu[4] |= (data8Diags[1] << 3) & 0x38;
        g_sendCanPdu[2].sdu[5] =  data8Diags[2];
        g_sendCanPdu[2].sdu[5] |= (data8Diags[3] << 3) & 0x38;


        g_sendCanPdu[2].sdu[6] = (uint8)(data16[0] & 0xff);
        g_sendCanPdu[2].sdu[7] = (uint8)(data16[0] >> 8) & 0x1f;
    }

    if(g_sendMsgTrigFlag[3])
    {


        for(count=0; count < 7; count++)
        {
            g_sendCanPdu[3].sdu[0] |= (dataBoolean[count] << count);
            //data8Diags[count] = GetValveDriverDiagStatus(count);
        }

        g_sendCanPdu[3].sdu[1] = data8Diags[0];
        g_sendCanPdu[3].sdu[1] |= (data8Diags[1] << 3) & 0x38;
        g_sendCanPdu[3].sdu[2] = data8Diags[2];
        g_sendCanPdu[3].sdu[2] |= (data8Diags[3] << 3) & 0x38;
        g_sendCanPdu[3].sdu[3] = data8Diags[4];
        g_sendCanPdu[3].sdu[3] |= (data8Diags[5] << 3) & 0x38;
        g_sendCanPdu[3].sdu[4] = data8Diags[6];

		g_sendCanPdu[3].sdu[6] =  (SW_MAJOR_VERSION) << 4;
		g_sendCanPdu[3].sdu[7] =  SW_MINOR_VERSION;
		g_sendCanPdu[3].sdu[7] |=  (SW_PATCH_VERSION << 4);
    }

    if(g_sendMsgTrigFlag[4])
    {
        data16[0] =  GetMonitorVoltage(VLOTAGE_ADC_5V8);
        g_sendCanPdu[4].sdu[0] = (uint8)(data16[0] /40) & 0xFF;
        //g_sendCanPdu[4].sdu[0] = Calib_A;
        for(count = 0; count < 4;count++)
        {
            data16[1] = GetMonitorVoltage(count+2);
            g_sendCanPdu[4].sdu[count+2] = (uint8)(data16[1] / 40) & 0xFF;
        }

        data16[2] =  GetMonitorVoltage(VLOTAGE_VQST_3V3);
        g_sendCanPdu[4].sdu[6] = (uint8)(data16[2] /20) & 0xFF; 

        data16[3] =  GetMonitorVoltage(VLOTAGE_LDO_3V3);
        g_sendCanPdu[4].sdu[7] = (uint8)(data16[3] /10) & 0xFF; 
    }

    if(g_sendMsgTrigFlag[5])
    {
        Nm_GetState(0,&nmStatus,&nmMode);

        data16[0] = datafloat[0] * 1000;

        g_sendCanPdu[5].sdu[0] = (uint8)(data16[0] & 0xff);
        g_sendCanPdu[5].sdu[1] = (uint8)(data16[0] >> 8) & 0xff;

        g_sendCanPdu[5].sdu[2] = nmStatus & 0x07;

        data8[2] = GetPowerStatus();
        g_sendCanPdu[5].sdu[2] |= (data8[2] << 4)&0x10;
    }

    SuspendAllInterrupts();
    SendPcTestCanMsg();
    ResumeAllInterrupts();
}



