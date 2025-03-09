/**
 * *******************************************************************************
 *                                     BAOLONG
 *                            -------------------------
 *                            Details to create profits
 * 
 * @copyright Copyright (c) 2023  ShangHai BAOLONG Electronics Stock Co., Ltd. All rights reserved.
 * 
 * Contact information:
 * web site:    https://www.baolong.biz/
 * e-mail:      sbic@baolong.biz
 * *******************************************************************************
 * 
 * @file RemoteDia.c
 * 
 * @brief 
 * 
 * @author xiatianxiong (xiatianxiong@chinabaolong.net)
 * 
 * @version v1.0
 * 
 * @date 2023-03-30
 * 
 * @par modification history:
 * <table>
 * <tr><th>Date       <th>Version <th>Author       <th>Description
 * <tr><td>2023-03-30 <td>1.0     <td>zhangqin     <td>内容
 * </table>
 */

#include "Com.h"

#include "ReadDTCInformation_0x19.h"

#define REMOTE_DIAG_MAX_COUNT       20

STATIC uint8 g_LastSendEndAddress = 0;
STATIC uint8 g_RemoteDiagFrameCount = 0; 

extern uint8 DtcStatus[DTC_NUMBER_MAX];

const g_uint8RemoteDiagNum[191]= 
{
    0x0,	0x1,	0x2,	0x5,	0x7,	0x8,	0x9,	0xA,	0xB,	0xC,	0xD,	0xE,	0xF,	0x10,	0x11,	0x12,	0x13,
    0x14,	0x15,	0x16,	0x17,	0x18,	0x19,	0x1A,	0x1B,	0x1C,	0x1D,	0x1E,	0x1F,	0x20,	0x21,	0x22,	0x23,	0x24,	
    0x25,	0x26,	0x27,	0x28,	0x29,	0x2B,	0x2C,	0x2D,	0x0,	0x2F,	0x30,	0x0,	0x31,	0x32,	0x33,	0x34,	0x35,	
    0x36,	0x37,	0x38,	0x39,	0x3A,	0x3B,	0x3C,	0x3D,	0x3E,	0x3F,	0x40,	0x41,	0x42,	0x43,	0x44,	0x45,	0x46,	
    0x4B,	0x4D,	0x4F,	0x0,	0x54,	0x57,	0x0,	0x0,	0x0,	0x0,	0x5D,	0x5E,	0x5F,	0x60,	0x61,	0x62,	0x63,	
    0x64,	0x65,	0x66,	0x67,	0x68,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
    0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
    0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
    0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
    0xA8,	0xA9,	0xAA,	0xAB,	0xB0,	0xB1,	0xB2,	0xB3,	0xB4,	0xB5,	0xB6,	0xB7,	0x2A,	0x2E,	0x47,	0x48,	0x49,	
    0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x56,	0xAC,	0xAD,	0xAE,	0x4E,	
    0x4C,	0x4A,	0x0,	0x53,
};
// BUGID 	xtx**2023-03-30:
//Errors    copy singal name 
// #define ECAS_FaultNum20_IPDU_COM_ECAS_RemoteDiag               47u
// #define ECAS_FaultNum19_IPDU_COM_ECAS_RemoteDiag               48u
// #define ECAS_FaultNum18_IPDU_COM_ECAS_RemoteDiag               49u
// #define ECAS_FaultNum17_IPDU_COM_ECAS_RemoteDiag               50u
// #define ECAS_FaultNum16_IPDU_COM_ECAS_RemoteDiag               51u
// #define ECAS_FaultNum15_IPDU_COM_ECAS_RemoteDiag               52u
// #define ECAS_FaultNum14_IPDU_COM_ECAS_RemoteDiag               53u
// #define ECAS_FaultNum13_IPDU_COM_ECAS_RemoteDiag               54u
// #define ECAS_FaultNum12_IPDU_COM_ECAS_RemoteDiag               55u
// #define ECAS_FaultNum11_IPDU_COM_ECAS_RemoteDiag               56u
// #define ECAS_FaultNum10_IPDU_COM_ECAS_RemoteDiag               57u
// #define ECAS_FaultNum9_IPDU_COM_ECAS_RemoteDiag               58u
// #define ECAS_FaultNum8_IPDU_COM_ECAS_RemoteDiag               59u
// #define ECAS_FaultNum7_IPDU_COM_ECAS_RemoteDiag               60u
// #define ECAS_FaultNum6_IPDU_COM_ECAS_RemoteDiag               61u
// #define ECAS_FaultNum5_IPDU_COM_ECAS_RemoteDiag               62u
// #define ECAS_FaultNum4_IPDU_COM_ECAS_RemoteDiag               63u
// #define ECAS_FaultNum3_IPDU_COM_ECAS_RemoteDiag               64u
// #define ECAS_FaultNum2_IPDU_COM_ECAS_RemoteDiag               65u
// #define ECAS_FaultNum1_IPDU_COM_ECAS_RemoteDiag               66u
// #define ECAS_SupplierNum_IPDU_COM_ECAS_RemoteDiag               67u
// #define ECAS_FrameIndex_IPDU_COM_ECAS_RemoteDiag               68u
// #define ECAS_TotalFaultNum_IPDU_COM_ECAS_RemoteDiag               69u

void DTCSendFaultMsg(void)
{
    uint8 count = 0;
    uint8 address = 0;
    uint8 dtcTotalSendNum = 0;
    uint8 dtcSendNum = 0;
    uint8 totalFrameCount = 0;
    uint8 framePositon[10];
    uint16 dtcNum[20];

    uint8 *dataPtr = DtcStatus;

    memset(dtcNum,0,40);
    memset(framePositon,0,10);

    for(count = 0; count < DTC_NUMBER_MAX; count++)
    {
        if(dataPtr[count] == FALSE)
        {
            dtcTotalSendNum++;
            if((dtcTotalSendNum % REMOTE_DIAG_MAX_COUNT) == 0)
            {
                // BUGID 	xtx**2023-03-30:
                //Errors 与诊断的帧计数进行匹配
                framePositon[++address] = count;
            }
        }
    }

    // BUGID 	xtx**2023-03-30:
    //Errors  Repeat the calculation above
    if((dtcTotalSendNum % REMOTE_DIAG_MAX_COUNT) == 0)
    {
        totalFrameCount =  dtcTotalSendNum / REMOTE_DIAG_MAX_COUNT;
    }else
    {
        totalFrameCount =  dtcTotalSendNum / REMOTE_DIAG_MAX_COUNT + 1;
    }


    if(totalFrameCount != 0)
    {
        //帧序号： 占 5bit，范围 0 ~ 31，指示需要多帧才能发送完一组故障的帧序号，无故障时发“0”，有故障时从“1”开始并循环递增；
        if(g_RemoteDiagFrameCount > totalFrameCount)
        {
            if(g_RemoteDiagFrameCount == 0)
            {
                 g_RemoteDiagFrameCount = 1;
            }
        }
           

        count = framePositon[g_RemoteDiagFrameCount -1];

        for(; count < DTC_NUMBER_MAX; count++)
        {
            if (dataPtr[count] == FALSE)
            {
               
                dtcNum[dtcSendNum] = g_uint8RemoteDiagNum[count];
                dtcSendNum++;
                if(dtcSendNum >= 20)
                {
                    break;
                }
            }
        }
    }else
    {
        g_RemoteDiagFrameCount  = 0;
    }

    SuspendAllInterrupts();
    Com_SendSignal(ECAS_TotalFaultNum_IPDU_COM_ECAS_RemoteDiag,&dtcTotalSendNum);
    Com_SendSignal(ECAS_FrameIndex_IPDU_COM_ECAS_RemoteDiag,&g_RemoteDiagFrameCount);
    ///<Com_SendSignal(ECAS_SupplierNum_IPDU_COM_ECAS_RemoteDiag,&unusedData);

    for(count = 0; count < REMOTE_DIAG_MAX_COUNT; count++)
    {
        Com_SendSignal(66 - count,&dtcNum[count]);
    }
    g_RemoteDiagFrameCount ++;
    ResumeAllInterrupts();
}
