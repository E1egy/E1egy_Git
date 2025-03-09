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
 * @file HscXcp.c
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

#include "NvM.h"
#include "PowerDriver.h"
#include "BswM_Ext.h"
#include "Rte_UDS.h"
#include "HscXcp.h"

uint8 *g_cdcModeRam =      (uint8 *)0xB0026D90;///< Mapping ram space of vehicle mode memory
uint8 *g_heightMsgRam =      (uint8 *)0xB0026D9A;///< Mapping ram space of height sensor calibration information
uint8 g_cdcInitReadCount = 0; ///< Avoid unreadable first burning program
uint8 g_hscInitReadCount = 0; ///< Avoid unreadable first burning program


boolean g_ReadCdcMsgOk = FALSE;///< Used to identify whether cdc data in NVM is read successfully
boolean g_ReadHeightMsgOk = FALSE;///< Used to identify whether height data in NVM is read successfully

NVM_WRITE_STATUS g_writeNvMCdcMsgStartFlag = NVM_NO_OPERATION; ///< the Status indication of CDC Msg NVM operation
uint8 g_cdcErrorCount = 0;///< Time count of cdc Msg Writing pending 
boolean g_writeNvMSucessFlag = FALSE; ///< Flag of whether NVM is successfully written
extern boolean g_bswMisGoingToSleep ;

NVM_WRITE_STATUS g_writeNvMHeightMsgStartFlag = NVM_NO_OPERATION;///< the Status indication of height Msg NVM operation
uint8 g_HeightErrorCount = 0; ///< Time count of Height Msg Writing pending 

/**
 * @brief Read initialization operation of NVM
 * @function	RE_MemModeBSW_Init
 */
void RE_MemModeBSW_Init(void)
{
#if 0
	Std_ReturnType readActRes =E_NOT_OK;
	readActRes = NvM_ReadBlock(NvMBlock_CddMode,g_cdcModeRam);
	readActRes = NvM_ReadBlock(NvMBlock_Height,g_heightMsgRam);
	Rte_IWrite_RE_UDS_pPort_CDCMemMode_CDCMemMode(0);
	Rte_IWrite_RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod(0);
	Rte_IWrite_RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts(0);
	Rte_IWrite_RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM(0);
    Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM(0);
	Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM(0);
	Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM(0);
	Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM(0);
#endif
}



/**
 * @brief Reading and writing stored information in CDC mode
 * @function	Mem_CdcModeBsw
 */
void Mem_CdcModeBsw(void)
{
#if 0
	NvM_RequestResultType readNvmStatsuOfcdc = NVM_REQ_NOT_OK;
	
	if(!g_ReadCdcMsgOk)
	{
		NvM_GetErrorStatus(NvMBlock_CddMode,&readNvmStatsuOfcdc);
		if(readNvmStatsuOfcdc == NVM_REQ_OK)
		{
			Rte_IWrite_RE_UDS_pPort_CDCMemMode_CDCMemMode(g_cdcModeRam[0]);
			Rte_IWrite_RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod(g_cdcModeRam[1]);
			g_ReadCdcMsgOk = TRUE;
		}

		g_cdcInitReadCount++;
		if(g_cdcInitReadCount >= 150)
		{
			Rte_IWrite_RE_UDS_pPort_CDCMemMode_CDCMemMode(0);
			Rte_IWrite_RE_UDS_pPort_VehLvlMemMod_VehLvlMemMod(0);
			g_ReadCdcMsgOk = TRUE;
		}
	}

	if((g_ReadCdcMsgOk)&&(g_writeNvMCdcMsgStartFlag == 0))
	{
		g_cdcModeRam[0] =  Rte_IRead_RE_UDS_rPort_CDCCurrentMode_CDCCurrentMode();
		g_cdcModeRam[1] =  Rte_IRead_RE_UDS_rPort_VehTarPosnSt_VehTarPosnSt();
	}

	if((g_bswMisGoingToSleep == TRUE)&&(g_writeNvMCdcMsgStartFlag == 0))
	{
		NvM_WriteBlock(NvMBlock_CddMode,g_cdcModeRam);
		g_writeNvMCdcMsgStartFlag = NVM_PENDING;
	}

	if(g_writeNvMCdcMsgStartFlag == NVM_PENDING)
	{
		NvM_GetErrorStatus(NvMBlock_CddMode,&readNvmStatsuOfcdc);
		g_cdcErrorCount ++;
		if(readNvmStatsuOfcdc == NVM_REQ_OK)
		{
			g_writeNvMSucessFlag = TRUE;
			g_writeNvMCdcMsgStartFlag = NVM_SUCESS;
			BswM_AllowECU_Sleep();
		}

		if(g_cdcErrorCount >= 100)
		{
			g_writeNvMSucessFlag = TRUE; ///< Avoid ECU not sleeping
			g_writeNvMCdcMsgStartFlag = NVM_FAULT;
			BswM_AllowECU_Sleep();
		}
	}
#endif
}


/**
 * @brief 	Reading and Writing of Height Sensor Calibration Information
 * @function 	HeightMsgCalibrationBsw
 */

void HeightMsgCalibrationBsw(void)
{
#if 0
	float32 readData[4];
	sint16  writeData[4];
	boolean HSCEna = FALSE;
	boolean HSCReq = FALSE;
	NvM_RequestResultType readNvmStatsuOfHeight = NVM_REQ_NOT_OK;
	if(!g_ReadHeightMsgOk)
	{
		NvM_GetErrorStatus(NvMBlock_Height,&readNvmStatsuOfHeight);
		if(readNvmStatsuOfHeight == NVM_REQ_OK)
		{
			readData[0] = (float32)(*(sint16 *)&g_heightMsgRam[2]) / 10;
			readData[1] = (float32)(*(sint16 *)&g_heightMsgRam[4]) / 10;
			readData[2] = (float32)(*(sint16 *)&g_heightMsgRam[6]) / 10;
			readData[3] = (float32)(*(sint16 *)&g_heightMsgRam[8]) / 10;

			Rte_IWrite_RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM(g_heightMsgRam[0]);
			Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM(readData[0]);
			Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM(readData[1]);
			Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM(readData[2]);
			Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM(readData[3]);
			g_ReadHeightMsgOk = TRUE;

		}

		g_hscInitReadCount++;
		if(g_hscInitReadCount >= 150)
		{
			g_ReadHeightMsgOk = TRUE;
		}
	}

	HSCEna = Rte_IRead_RE_UDS_rPort_HSCEna_HSCEna();
	HSCReq = Rte_IRead_RE_UDS_rPort_HSCReq_HSCReq();
	if((HSCEna == 1) &&(HSCReq == 1)&&(g_writeNvMHeightMsgStartFlag == NVM_NO_OPERATION))
	{
		writeData[0] = (sint16)(Rte_IRead_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFL() * 10);
		writeData[1] = (sint16)(Rte_IRead_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevFR() * 10);
		writeData[2] = (sint16)(Rte_IRead_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRL() * 10);
		writeData[3] = (sint16)(Rte_IRead_RE_UDS_rPort_HSCWheelPosDev_HSCWheelPosDevRR() * 10);

		for(uint8 i = 0; i < 4; i++)
		{
			if(writeData[i] > 1000)
			{
				writeData[i] = 1000;
			}else if(writeData[i] < -1000)
			{
				writeData[i] = -1000;
			}
		}
		g_heightMsgRam[0]  = 1;
		g_heightMsgRam[2]  = *(uint16 *)&writeData[0] & 0xFF;
		g_heightMsgRam[3]  = (*(uint16 *)&writeData[0] >>8) & 0xFF;
		g_heightMsgRam[4]  = *(uint16 *)&writeData[1] & 0xFF;
		g_heightMsgRam[5]  = (*(uint16 *)&writeData[1] >>8) & 0xFF;
		g_heightMsgRam[6]  = *(uint16 *)&writeData[2] & 0xFF;
		g_heightMsgRam[7]  = (*(uint16 *)&writeData[2] >>8) & 0xFF;
		g_heightMsgRam[8]  = *(uint16 *)&writeData[3] & 0xFF;
		g_heightMsgRam[9]  = (*(uint16 *)&writeData[3] >>8) & 0xFF;
		NvM_WriteBlock(NvMBlock_Height,g_heightMsgRam);
		g_writeNvMHeightMsgStartFlag = NVM_PENDING;
		Rte_IWrite_RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts(0);
	}

	if(g_writeNvMHeightMsgStartFlag == NVM_PENDING)
	{
		NvM_GetErrorStatus(NvMBlock_Height,&readNvmStatsuOfHeight);
		g_HeightErrorCount ++;
		if(readNvmStatsuOfHeight == NVM_REQ_OK)
		{
			g_writeNvMHeightMsgStartFlag = NVM_SUCESS;
			Rte_IWrite_RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts(1);

			///<Update and write successful data to the application layer
			readData[0] = (float32)(*(sint16 *)&g_heightMsgRam[2]) / 10;
			readData[1] = (float32)(*(sint16 *)&g_heightMsgRam[4]) / 10;
			readData[2] = (float32)(*(sint16 *)&g_heightMsgRam[6]) / 10;
			readData[3] = (float32)(*(sint16 *)&g_heightMsgRam[8]) / 10;

			Rte_IWrite_RE_UDS_pPort_HSCSts_EEM_HSCSts_EEM(g_heightMsgRam[0]);
			Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFL_EEM(readData[0]);
			Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevFR_EEM(readData[1]);
			Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRL_EEM(readData[2]);
			Rte_IWrite_RE_UDS_pPort_HSCWheelPosDev_EEM_HSCWheelPosDevRR_EEM(readData[3]);
		}

		if(g_HeightErrorCount >= 100)
		{
			//g_writeNvMHeightMsgStartFlag = NVM_FAULT; ///Prevent ECU from failing to perform the second height calibration
			Rte_IWrite_RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts(2);
		}
	}

	if((HSCEna == 0) &&(HSCReq == 0))
	{
		//g_writeNvMHeightMsgStartFlag = NVM_NO_OPERATION;
		Rte_IWrite_RE_UDS_pPort_HSCNVMWrtSts_HSCNVMWrtSts(0);
	}
#endif
}
