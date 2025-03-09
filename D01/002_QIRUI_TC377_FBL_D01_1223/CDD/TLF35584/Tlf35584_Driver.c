/*!
***********************************************************************************
*
*  Copyright © 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   Tlf35584_Driver.c
* \author  BL_zq
* \version 1.0
* \date    2022-03-23
* \btief   Tlf35584 driver
*
*----------------------------------------------------------------------------------
* \attention
*
*
***********************************************************************************
*/

/**********************************************************************************
	change history:
		1.date  : 2022-03-23
		 author: BL_zq
		 change: create file

***********************************************************************************/

/***************************************Includes***********************************/
#include "IfxSrc_reg.h"
#include "Std_Types.h"

#include "Irq.h"
#include "Spi.h"
#include "IfxStm_reg.h"
#include "Tlf35584_Driver.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "Test_Print.h"
#include "PowerDriver.h"

/***************************************Variables**********************************/
Tlf35584Reg g_TlfDeviceReg;
uint16  Tlf35584SpiWrite_Data_Buffer[SPI_DATA_BUFFER_SIZE];
uint16  Tlf35584SpiRead_Data_Buffer[SPI_DATA_BUFFER_SIZE];
Tlf35584DevInfo g_TlfDeviceInfo[1] =
{
    {
        SpiConf_SpiChannel_SpiChannel_PMIC,
        SpiConf_SpiSequence_SpiSequence_PMIC,
        Tlf35584SpiWrite_Data_Buffer,
        SPI_DATA_BUFFER_SIZE,
        Tlf35584SpiRead_Data_Buffer,
        SPI_DATA_BUFFER_SIZE,
    }
};
/***************************************Functions***********************************/
Spi_DataBufferType Tlf35584DataTransfer(SpiCommandType cmd, Tlf35584RegAddr addr, uint8 data);
void Tlf35584UnlockRegister(void);
void Tlf35584LockRegister(void);
void Tlf35584DisableWindowWatchdog(Tlf35584Reg *tlfDevice);
void Tlf35584EnableWindowWatchdog(Tlf35584Reg *tlfDevice);
void Tlf35584DisableErrPinMonitor(Tlf35584Reg *tlfDevice);
void Tlf35584EnableErrPinMonitor(Tlf35584Reg *tlfDevice);
void Tlf35584EnableVoltageSupplyRails(Tlf35584Reg *tlfDevice);
void Tlf35584SetStateTransition(Tlf35584Reg *tlfDevice, DeviceStateTranType requestedStateTransition);
uint8 Tlf35584SetStateTransition_To_Normal(void);
uint8 Tlf35584GetInitErrortatusFlags(Tlf35584Reg *tlfDevice);

uint8 g_count = 0;
void PMIC_AsyncEnd(void)
{
    g_count ++;
}

/*******************************************************************************
** Syntax          : Spi_DataBufferType Tlf35584DataTransfer(SpiCommandType cmd, Tlf35584RegAddr addr, uint8 data) **
**                                                                            **
** Description     : This function starts the data transfer to the TLF35584 device **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : cmd - Write/Read                                         **
**                   addr - Register Address                                  **
**                   date - Data that needs to be transferred.                **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : Data read by SPI.                                        **
**                                                                            **
*******************************************************************************/
Spi_DataBufferType Tlf35584DataTransfer(SpiCommandType cmd, Tlf35584RegAddr addr, uint8 data)
{
	uint8 evenParity = 0;
	unsigned int   stmCountBegin = 0,stmCountEnd = 0;
	Std_ReturnType returnVal = E_NOT_OK;//E_NOT_OK
	Tlf35584SpiFrameType spiFrame = {0};

	/* Prepare the SPI frame that should be transfered to the TLF35584 device */
	spiFrame.B.cmd = cmd;
	spiFrame.B.addr = addr;
	spiFrame.B.data = data;
	for(uint8 i=1;i<16;i++)
	{
		if((spiFrame.U>>i)&0x00000001)
		{
			evenParity+=1;
		}
		if(i==15)
		{
			if((evenParity%2)==0)
			{
				spiFrame.B.evenParityBit = 0;
			}
			else
			{
				spiFrame.B.evenParityBit = 1;
			}
		}
	}
	

	returnVal = Spi_SetupEB(g_TlfDeviceInfo[0].spiChananelId,  (uint8 *)g_TlfDeviceInfo[0].writeBuff, (uint8 *)g_TlfDeviceInfo[0].readBuff,SPI_DATA_BUFFER_SIZE);
	if(returnVal==E_OK)
	{
		/* Wait until the previous communication has finished, if any */
		stmCountBegin = STM0_TIM0.U;
		stmCountEnd = (unsigned int)(Ifx_Ssw_getStmFrequency() * 0.005f);
		while((Spi_GetSequenceResult(g_TlfDeviceInfo[0].spiSequenceId) == SPI_SEQ_PENDING)&&\
			  ((unsigned int)(STM0_TIM0.U - stmCountBegin) < stmCountEnd))
		{
			/*If the last data transfer is not completed within 5 milliseconds, the data transfer is stopped */
		}

		for(uint8 i =0;i<SPI_DATA_BUFFER_SIZE;i++)
		{
			g_TlfDeviceInfo[0].readBuff[i] = 0;
			g_TlfDeviceInfo[0].writeBuff[i] = 0;
		}

		/* Store the prepared SPI frame to Master Tx Buffer */
		g_TlfDeviceInfo[0].writeBuff[0] = spiFrame.U;

		/* Send a data stream through the SPI Master */
		Spi_SyncTransmit(g_TlfDeviceInfo[0].spiSequenceId);

		/* Wait until the values are read from the TLF device */
		stmCountBegin = STM0_TIM0.U;
		stmCountEnd = (unsigned int)(Ifx_Ssw_getStmFrequency() * 0.005f);
		while((Spi_GetSequenceResult(g_TlfDeviceInfo[0].spiSequenceId) != SPI_SEQ_OK)&&\
			  ((unsigned int)(STM0_TIM0.U - stmCountBegin) < stmCountEnd))
		{
			/* Wait till write is finished */
		}
	}
		return (uint8)(g_TlfDeviceInfo[0].readBuff[0] & 0xFF);
}

/*******************************************************************************
** Syntax          : void Tlf35584UnlockRegister(void)                        **
**                                                                            **
** Description     : Unlock protect register                                  **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584UnlockRegister(void)
{
	Tlf35584DataTransfer(SpiCmd_Write, ProtcfgRegAddr, UnlockKey0);
	Tlf35584DataTransfer(SpiCmd_Write, ProtcfgRegAddr, UnlockKey1);
	Tlf35584DataTransfer(SpiCmd_Write, ProtcfgRegAddr, UnlockKey2);
	Tlf35584DataTransfer(SpiCmd_Write, ProtcfgRegAddr, UnlockKey3);
}

/*******************************************************************************
** Syntax          : void Tlf35584LockRegister(void)                          **
**                                                                            **
** Description     : lock protect register                                    **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584LockRegister(void)
{
	Tlf35584DataTransfer(SpiCmd_Write, ProtcfgRegAddr, LockKey0);
	Tlf35584DataTransfer(SpiCmd_Write, ProtcfgRegAddr, LockKey1);
	Tlf35584DataTransfer(SpiCmd_Write, ProtcfgRegAddr, LockKey2);
	Tlf35584DataTransfer(SpiCmd_Write, ProtcfgRegAddr, LockKey3);
}

/*******************************************************************************
** Syntax          : void Tlf35584DisableWindowWatchdog(Tlf35584Reg *tlfDevice) **
**                                                                            **
** Description     : Disable window watchdog                                  **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584DisableWindowWatchdog(Tlf35584Reg *tlfDevice)
{ 
	Tlf35584SpiFrameType spiFrame;

	/* Get the value of WDCFG0 to check the current window watchdog setting */
	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, Rwdcfg0RegAddr, (uint8)DUMMY_DATA);

	/* Refresh local value of TLF register */
	tlfDevice->WDCFG0.U = spiFrame.B.data;

	if(tlfDevice->WDCFG0.B.WWDEN == WindowWatchdog_enabled)
	{
		tlfDevice->WDCFG0.B.WWDEN = WindowWatchdog_disabled;
		Tlf35584DataTransfer(SpiCmd_Write, Wdcfg0RegAddr, tlfDevice->WDCFG0.U);
	}
}

/*******************************************************************************
** Syntax          : void Tlf35584EnableWindowWatchdog(Tlf35584Reg *tlfDevice)**
**                                                                            **
** Description     : Enable window watchdog                                   **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584EnableWindowWatchdog(Tlf35584Reg *tlfDevice)
{
	Tlf35584SpiFrameType spiFrame;

	/* Get the value of RWDCFG0 to check the current window watchdog setting */
	spiFrame.U  = Tlf35584DataTransfer(SpiCommand_read, Rwdcfg0RegAddr, (uint8)DUMMY_DATA);

	/* Refresh local value of TLF register */
	tlfDevice->RWDCFG0.U = spiFrame.B.data;

	if(tlfDevice->RWDCFG0.B.WWDEN == WindowWatchdog_disabled)
	{
		tlfDevice->WDCFG0.B.WWDEN = WindowWatchdog_enabled;
		Tlf35584DataTransfer(SpiCmd_Write, Wdcfg0RegAddr, tlfDevice->WDCFG0.U);
	}
}

/*******************************************************************************
** Syntax          : void Tlf35584DisableErrPinMonitor(Tlf35584Reg *tlfDevice)**
**                                                                            **
** Description     : Disable error pin monitoring                             **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584DisableErrPinMonitor(Tlf35584Reg *tlfDevice)
{
	Tlf35584SpiFrameType spiFrame;

	/* Get the value of RSYSPCFG1 to check the current error pin monitoring setting */
	spiFrame.U  = Tlf35584DataTransfer(SpiCommand_read, Rsyspcfg1RegAddr, (uint8)DUMMY_DATA);

	/* Refresh local value of TLF register */
	tlfDevice->SYSPCFG1.U = spiFrame.B.data;

	if(tlfDevice->SYSPCFG1.B.ERREN == ErrPinMonitor_enabled)
	{
		tlfDevice->SYSPCFG1.B.ERREN = ErrPinMonitor_disabled;
		Tlf35584DataTransfer(SpiCmd_Write, Syspcfg1RegAddr, tlfDevice->SYSPCFG1.U);
	}  
}

void Tlf35584DisableStandbyRegulatorQST(Tlf35584Reg *tlfDevice)
{
	Tlf35584SpiFrameType spiFrame;

	/* Get the value of RSYSPCFG1 to check the current error pin monitoring setting */
	spiFrame.U  = Tlf35584DataTransfer(SpiCommand_read, Rsyspcfg0RegAddr, (uint8)DUMMY_DATA);

	/* Refresh local value of TLF register */
	tlfDevice->SYSPCFG0.U = spiFrame.B.data;

	if(tlfDevice->SYSPCFG0.B.STBYEN == StandbyRegulatorQST_enable)
	{
		tlfDevice->SYSPCFG0.B.STBYEN = StandbyRegulatorQST_disable;
		Tlf35584DataTransfer(SpiCmd_Write, Syspcfg0RegAddr, tlfDevice->SYSPCFG0.U);
	}  
}
/*******************************************************************************
** Syntax          : void Tlf35584EnableErrPinMonitor(Tlf35584Reg *tlfDevice) **
**                                                                            **
** Description     : Enable error pin monitoring                              **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584EnableErrPinMonitor(Tlf35584Reg *tlfDevice)
{
	Tlf35584SpiFrameType spiFrame;

	/* Get the value of RSYSPCFG1 to check the current error pin monitoring setting */
	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, Rsyspcfg1RegAddr, (uint8)DUMMY_DATA);

	/* Refresh local value of TLF register */
	tlfDevice->SYSPCFG1.U = spiFrame.B.data;

	if(tlfDevice->SYSPCFG1.B.ERREN == ErrPinMonitor_disabled)
	{
		tlfDevice->SYSPCFG1.B.ERREN = ErrPinMonitor_enabled;
		Tlf35584DataTransfer(SpiCmd_Write, Syspcfg1RegAddr, tlfDevice->SYSPCFG1.U);
	}
}

/*******************************************************************************
** Syntax          : void Tlf35584EnableVoltageSupplyRails(Tlf35584Reg *tlfDevice)**
**                                                                            **
** Description     : Enable all voltage supply rails                          **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584EnableVoltageSupplyRails(Tlf35584Reg *tlfDevice)
{
    Tlf35584SpiFrameType spiFrame;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevctrlRegAddr, (uint8)DUMMY_DATA);

    /* Refresh local value of TLF register */
    tlfDevice->DEVCTRL.U = spiFrame.B.data;

	if((tlfDevice->DEVCTRL.B.COMEN == CommunicationLdoVoltage_disabled)||\
	   (tlfDevice->DEVCTRL.B.VREFEN == OutputVoltageReferenceQVR_disabled)||\
	   (tlfDevice->DEVCTRL.B.TRK1EN == Tracker1QT_disabled)||\
	   (tlfDevice->DEVCTRL.B.TRK2EN == Tracker2QT_disabled))
	   {
		   	/* Enable all voltage supply rails */
			tlfDevice->DEVCTRL.B.STATEREQ = Tlf35584GetCurrentStateTransition(&g_TlfDeviceReg);
			tlfDevice->DEVCTRL.B.COMEN = CommunicationLdoVoltage_enabled;
			tlfDevice->DEVCTRL.B.VREFEN = OutputVoltageReferenceQVR_enabled;
			tlfDevice->DEVCTRL.B.TRK1EN = Tracker1QT_enabled;
			tlfDevice->DEVCTRL.B.TRK2EN = Tracker2QT_enabled;

			/* Update device register values */
			Tlf35584DataTransfer(SpiCmd_Write, DevctrlRegAddr, tlfDevice->DEVCTRL.U);
			Tlf35584DataTransfer(SpiCmd_Write, DevctrlnRegAddr, ~tlfDevice->DEVCTRL.U);
	   }
}
/*******************************************************************************
** Syntax          : void Tlf35584DisableVoltageSupplyRails(Tlf35584Reg *tlfDevice)**
**                                                                            **
** Description     : Disable all voltage supply rails                          **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584DisableVoltageSupplyRails(Tlf35584Reg *tlfDevice)
{
    Tlf35584SpiFrameType spiFrame;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevctrlRegAddr, (uint8)DUMMY_DATA);

    /* Refresh local value of TLF register */
    tlfDevice->DEVCTRL.U = spiFrame.B.data;

    /* Enable all voltage supply rails */
    tlfDevice->DEVCTRL.B.STATEREQ = Tlf35584GetCurrentStateTransition(&g_TlfDeviceReg);
	tlfDevice->DEVCTRL.B.VREFEN = OutputVoltageReferenceQVR_disabled;
    tlfDevice->DEVCTRL.B.COMEN = CommunicationLdoVoltage_disabled;
	tlfDevice->DEVCTRL.B.TRK1EN = Tracker1QT_enabled;
    tlfDevice->DEVCTRL.B.TRK2EN = Tracker2QT_enabled;
	
    /* Update device register values */
    Tlf35584DataTransfer(SpiCmd_Write, DevctrlRegAddr, tlfDevice->DEVCTRL.U);
    Tlf35584DataTransfer(SpiCmd_Write, DevctrlnRegAddr, ~tlfDevice->DEVCTRL.U);
}
/*******************************************************************************
** Syntax          : void Tlf35584SetStateTransition(Tlf35584Reg *tlfDevice, DeviceStateTranType requestedStateTransition) **
**                                                                            **
** Description     : Switch TLF35584 Transition state                         **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                   requestedStateTransition - the transition state should be switched **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584SetStateTransition(Tlf35584Reg *tlfDevice, DeviceStateTranType requestedStateTransition)
{
	Tlf35584SpiFrameType spiFrame;

	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevctrlRegAddr, (uint8)DUMMY_DATA);

	/* Refresh local value of TLF register */
	tlfDevice->DEVCTRL.U = spiFrame.B.data;
	/* Set the requested state transition of TLF device locally */
	tlfDevice->DEVCTRL.B.STATEREQ = requestedStateTransition;

	/* Update device register values */
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlRegAddr, tlfDevice->DEVCTRL.U);
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlnRegAddr, ~tlfDevice->DEVCTRL.U);
}

/*******************************************************************************
** Syntax          : DeviceStateTranType Tlf35584GetCurrentStateTransition(Tlf35584Reg *tlfDevice) **
**                                                                            **
** Description     : Get TLF35584 Transition state                            **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : tlfDevice->DEVSTAT.B.STATE - The transition State of device. **
**                                                                            **
*******************************************************************************/
DeviceStateType Tlf35584GetCurrentStateTransition(Tlf35584Reg *tlfDevice)
{
    Tlf35584SpiFrameType spiFrame;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevstatRegAddr, (uint8)DUMMY_DATA);
    tlfDevice->DEVSTAT.U = spiFrame.B.data;

    return tlfDevice->DEVSTAT.B.STATE;
}


/*******************************************************************************
** Syntax          :  uint8 Tlf35584GetWakeupFlag(void) 			                     
**                                                                              
** Description     :  Get the reason of Wakeup                                       					 
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : none                                                       
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : g_TlfDeviceReg.WKSF.U - The value of Wakeup status flags register                                                       
**                                                                              
*******************************************************************************/
uint8 Tlf35584GetWakeupFlag(void)
{
	Tlf35584SpiFrameType spiFrame;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, WakeupstatusflagRegAddr, (uint8)DUMMY_DATA);
    g_TlfDeviceReg.WKSF.U = spiFrame.B.data;

    return g_TlfDeviceReg.WKSF.U;
}


/*******************************************************************************
** Syntax          :  void Tlf35584SetDeviceConfigurationOfStandby(void) 			                     
**                                                                              
** Description     :  Set Device Device Configuration Register                                      					 
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : none                                                       
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : none                                                       
**                                                                              
*******************************************************************************/
void Tlf35584SetDeviceConfigurationOfStandby(void)
{
	Tlf35584SpiFrameType spiFrame;
#if 0
	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, Devcfg0RegAddr, (uint8)DUMMY_DATA);
	/* Refresh local value of TLF register */
	g_TlfDeviceReg.DEVCFG0.U = spiFrame.B.data;
	g_TlfDeviceReg.DEVCFG0.B.TRDEL = TransitionDelayTime_1600us;
#endif
	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, Devcfg2RegAddr, (uint8)DUMMY_DATA);
	/* Refresh local value of TLF register */
	g_TlfDeviceReg.DEVCFG2.U = spiFrame.B.data;
	g_TlfDeviceReg.DEVCFG2.B.CMONEN = QucCurrentMonitor_disable;
	//g_TlfDeviceReg.DEVCFG2.B.CTHR = QucCurrentMonitorThresholdValue_100mA;

	/* Update device register values */
	//Tlf35584DataTransfer(SpiCmd_Write, Devcfg0RegAddr, g_TlfDeviceReg.DEVCFG0.U);
	Tlf35584DataTransfer(SpiCmd_Write, Devcfg2RegAddr, g_TlfDeviceReg.DEVCFG2.U);

	//spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, Devcfg0RegAddr, (uint8)DUMMY_DATA);
	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, Devcfg2RegAddr, (uint8)DUMMY_DATA);
}
/*******************************************************************************
** Syntax          : uint8 Tlf35584SetStateTransition_To_Normal(void) 		  **
**                                                                            **
** Description     : Switch TLF to normal state                               **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : none						  .                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : Switch normal state success:0.                         **
**                   Switch normal state fail:		                          **
						1:System Status Flag != 0;
						2:TLF35584 work state != NORMAL;
						3:System Status Flag != 0 && TLF35584 work state != NORMAL
**                                                                            **
*******************************************************************************/
uint8 Tlf35584SetStateTransition_To_Normal(void)
{
	uint8 ret = 0;
	uint32 stmCountBegin,stmCountEnd;	

#if 1
	/* we must wait 60uS before we can go to normal state */
	stmCountBegin = STM0_TIM0.U;
	stmCountEnd = (unsigned int)(Ifx_Ssw_getStmFrequency() * 0.00007f);
    while ((unsigned int)(STM0_TIM0.U - stmCountBegin) < stmCountEnd)
    {
        /* There is no need to check overflow of the STM timer.
         * When counter after overflow subtracted with counter before overflow,
         * the subtraction result will be as expected, as long as both are unsigned 32 bits
         * eg: stmCountBegin= 0xFFFFFFFE (before overflow)
         *     stmCountNow = 0x00000002 (before overflow)
         *     diff= stmCountNow - stmCountBegin = 4 as expected.*/
    }
#endif

	for(uint8 i=0;i<10;i++)
	{
		if(Tlf35584GetCurrentStateTransition(&g_TlfDeviceReg)== DeviceStateTransition_normal)
        {
            break;
        }

	    if(Tlf35584GetSystemStatusFlags(&g_TlfDeviceReg)!=0)
        {
            Tlf35584ClearSystemStatusFlags(&g_TlfDeviceReg);
        }

	    /* Switch TLF to normal state */
        Tlf35584SetStateTransition(&g_TlfDeviceReg, DeviceStateTransition_normal);  
	}

	if(Tlf35584GetCurrentStateTransition(&g_TlfDeviceReg)== DeviceStateTransition_normal)
    {
        ret = 0;/* Switch TLF to normal state success */
    }
	else if((Tlf35584GetCurrentStateTransition(&g_TlfDeviceReg)== DeviceStateTransition_normal)&&\
	        (Tlf35584GetSystemStatusFlags(&g_TlfDeviceReg)!=0))
	{
	    ret = 1;/* Switch TLF to normal state success */
	}
	else
	{
        ret = 2;/* Switch TLF to normal state success */
	}

    return ret;
}

/*******************************************************************************
** Syntax          : uint8 Tlf35584SetStateTransition_NormalToSleep(void) **
**                                                                            **
** Description     : Switch TLF normal state to Sleep state                   **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : void						                              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : Switch normal state to sleep state success:0.            **
**                   Switch normal state to sleep state fail:		          **
						1:System Status Flag != 0;
						2:TLF35584 work state != SLEEP;
						3:System Status Flag != 0 && TLF35584 work state != SLEEP
**                                                                            **
*******************************************************************************/
uint8 Tlf35584SetStateTransition_NormalToSleep(void)
{
	uint8 ret = 0;

	//Dio_WriteChannel(DioConf_DioChannel_MCU_PMIC_EN, STD_LOW);
	//Dio_WriteChannel(DioConf_DioChannel_PMIC_WAKE, STD_HIGH);
	/* Switch TLF to normal state */
	Tlf35584SetStateTransition(&g_TlfDeviceReg, DeviceStateTransition_sleep);
	//Tlf35584DisableVoltageSupplyRails(&g_TlfDeviceReg);

	if(Tlf35584GetSystemStatusFlags(&g_TlfDeviceReg)!=0)
	{
		ret = 1;/* Switch TLF to normal state fail */
	}

    if(Tlf35584GetCurrentStateTransition(&g_TlfDeviceReg)!= DeviceStateTransition_sleep)
    {
		if(ret!=0)
		{
			ret = 3;
		}
		else
		{
			ret = 2;/* Switch TLF to normal state fail */
		}
    }
    else
    {

        ret = 0;/* Switch TLF to normal state success */
    }
    if(ret)
    {
        Tlf35584GetWakeupFlag();
    }
    return ret;
}

/*******************************************************************************
** Syntax          : uint8 Tlf35584SetStateTransition_NormalToStandby(void) **
**                                                                            **
** Description     : Switch TLF normal state to Standby state                   **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : void						                              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : Switch normal state to Standby state success:0.            **
**                   Switch normal state to Standby state fail:		          **
						1:System Status Flag != 0;
						2:TLF35584 work state != STANDBY;
						3:System Status Flag != 0 && TLF35584 work state != STANDBY
**                                                                            **
*******************************************************************************/
uint8 Tlf35584SetStateTransition_NormalToStandby(void)
{
	uint8 ret = 0;

	//Dio_WriteChannel(DioConf_DioChannel_MCU_PMIC_EN, STD_LOW);
	//Dio_WriteChannel(DioConf_DioChannel_PMIC_WAKE, STD_LOW);
	/* Switch TLF to normal state */
	//Tlf35584DisableVoltageSupplyRails(&g_TlfDeviceReg);
	//Tlf35584SetDeviceConfigurationOfStandby();
	if(Tlf35584GetCurrentStateTransition(&g_TlfDeviceReg)== DeviceStateTransition_standby)
	{
		return 0;
	}
	else
	{
#if 1
	    Tlf35584UnlockRegister();
	    Tlf35584DisableStandbyRegulatorQST(&g_TlfDeviceReg);
	    Tlf35584LockRegister();
#endif
		Tlf35584SetStateTransition(&g_TlfDeviceReg, DeviceStateTransition_standby);
	}
	
	if(Tlf35584GetSystemStatusFlags(&g_TlfDeviceReg)!=0)
	{
		ret = 1;/* Switch TLF to normal state fail */
	}

    if(Tlf35584GetCurrentStateTransition(&g_TlfDeviceReg)!= DeviceStateTransition_standby)
    {
		if(ret!=0)
		{
			ret = 3;
		}
		else
		{
			ret = 2;/* Switch TLF to normal state fail */
		}
    }
    else
    {

        ret = 0;/* Switch TLF to normal state success */
    }
    if(ret)
    {
        Tlf35584GetWakeupFlag();
    }
    return ret;
}
/*******************************************************************************
** Syntax          : uint8 Tlf35584GetSystemStatusFlags(Tlf35584Reg *tlfDevice) **
**                                                                            **
** Description     : Get System Status Flag.                                  **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : tlfDevice->SYSSF.U - System Status Flag Value            **
**                                                                            **
*******************************************************************************/
uint8 Tlf35584GetSystemStatusFlags(Tlf35584Reg *tlfDevice)
{
    Tlf35584SpiFrameType spiFrame;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, SyssfRegAddr, (uint8)DUMMY_DATA);

    tlfDevice->SYSSF.U = spiFrame.B.data;

    return tlfDevice->SYSSF.U;
}

/*******************************************************************************
** Syntax          : void Tlf35584ClearSystemStatusFlags(Tlf35584Reg *tlfDevice) **
**                                                                            **
** Description     : Clear System Status Flag.                                **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584ClearSystemStatusFlags(Tlf35584Reg *tlfDevice)
{
	tlfDevice->SYSSF.U = CLEAR_STATUS_FLAGS;
	Tlf35584DataTransfer(SpiCmd_Write, SyssfRegAddr, tlfDevice->SYSSF.U);
}

/*******************************************************************************
** Syntax          : 					                                         
**                                                                              
** Description     :                                                            
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : none                                                       
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : none                                                       
**                                                                              
*******************************************************************************/
uint8 Tlf35584GetInitErrortatusFlags(Tlf35584Reg *tlfDevice)
{
	Tlf35584SpiFrameType spiFrame;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, IniterrorRegAddr, (uint8)DUMMY_DATA);

    tlfDevice->INITERR.U = spiFrame.B.data;

    return (uint8)(tlfDevice->INITERR.U & 0xFF);
}
/*******************************************************************************
** Syntax          : void Tlf35584StartSpiSequence(void)                      **
**                                                                            **
** Description     : This routine will start the SPI configured for sequence ID 0 **
**                   Transmit mode     : Synchronous                          **
**                   LevelDelivered    : 00                                   **
**                   External Devices  : QSPI2                                **
**                   CS Selection      : CS_VIA_PERIPHERAL_ENGINE             **
**                   QSPI2 Pins used   : P14.02(CS-0),P15.03(SCLK),P15.06(MTSR) **
**                                       P15.07(MRTS)                         **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
void Tlf35584StartSpiSequence(void)
{
	Spi_SetupEB(g_TlfDeviceInfo[0].spiChananelId, (uint8 *)g_TlfDeviceInfo[0].writeBuff,(uint8 *)g_TlfDeviceInfo[0].readBuff,SPI_DATA_BUFFER_SIZE);

	for(uint8 i =0;i<SPI_DATA_BUFFER_SIZE;i++)
	{
		g_TlfDeviceInfo[0].readBuff[i] = 0;
		g_TlfDeviceInfo[0].writeBuff[i] = 0x30+i;
	}

	Spi_SyncTransmit(g_TlfDeviceInfo[0].spiSequenceId);
  
	while(Spi_GetSequenceResult(g_TlfDeviceInfo[0].spiSequenceId) != SPI_SEQ_OK)
	{
	/* Wait till write is finished */
	}
}

/*******************************************************************************
** Syntax          : 					                                         
**                                                                              
** Description     :                                                            
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : none                                                       
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : none                                                       
**                                                                              
*******************************************************************************/
uint8 Tlf35584GetSpiStatusFlags(void)
{
	uint8 clearRegister = 0x1F;
	Tlf35584SpiFrameType spiFrame;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, SpisfRegAddr, (uint8)DUMMY_DATA);

    g_TlfDeviceReg.SPISF.U = spiFrame.B.data;
	if((g_TlfDeviceReg.SPISF.U & 0x1F) != 0)
	{
		Tlf35584DataTransfer(SpiCmd_Write, SpisfRegAddr, clearRegister);
		return FALSE;
	}

    return TRUE;
}

/*******************************************************************************
** Syntax          : void Tlf35584Init(Tlf35584Reg *tlfDevice)                **
**                                                                            **
** Description     : This function initializes the TLF35584 device            **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : tlfDevice - TLF35584 Register.                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
uint8 g_Tlf35584SpiBusStatus = SPI_BUS_NOT_START_COMMUNICATION;
void Tlf35584Init(void)
{
	uint8 retVal0 = 0xFF, retVal1 = 0xFF;
	/*TLF35584 init function before call Spi_Init()*/
	//Spi_Init(&Spi_Config);
	Power.AccState = ACC_STATE_INIT;

    IRQ_SFR_MODIFY32 (SRC_QSPI2RX.U,  IRQ_CLEAR_MASK, \
                      ((uint32)IRQ_QSPI2_RX_TOS | (uint32) IRQ_QSPI2_RX_PRIO));
    IRQ_SFR_MODIFY32 (SRC_QSPI2TX.U,  IRQ_CLEAR_MASK, \
                      ((uint32)IRQ_QSPI2_TX_TOS | (uint32) IRQ_QSPI2_TX_PRIO));
#if 0
    SRC_QSPI2TX.U |= 0x400;//SRE_ENABLE
    SRC_QSPI2RX.U |= 0x400;//SRE_ENABLE
    SRC_QSPI2PT.U |= 0x400;//SRE_ENABLE
    SRC_DMACH34.U |= 0x400;//SRE_ENABLE
#endif
	Tlf35584UnlockRegister();
	Tlf35584DisableWindowWatchdog(&g_TlfDeviceReg);
	Tlf35584DisableErrPinMonitor(&g_TlfDeviceReg);
	Tlf35584LockRegister();

	retVal0 = Tlf35584SetStateTransition_To_Normal();
	Tlf35584EnableVoltageSupplyRails(&g_TlfDeviceReg);
	retVal1 = Tlf35584GetSpiStatusFlags();

	if(retVal1 == FALSE)
	{
		g_Tlf35584SpiBusStatus = SPI_BUS_COMMUNICATION_FALSE;
	}
	else
	{

		g_Tlf35584SpiBusStatus = SPI_BUS_COMMUNICATION_TRUE;
	}
}

uint8 GetTlf35584ChipStatus(void)
{
	return g_Tlf35584SpiBusStatus;
}

#include "SysVol.h"

#define TLF35584_5V_SHORTOUT_TO_GND_MIN_VOLTAGE_0V    0
#define TLF35584_5V_SHORTOUT_TO_GND_MAX_VOLTAGE_0V5   500
#define TLF35584_5V_SHORTOUT_TO_POWER_MAX_VOLTAGE_6V  6000
#define TLF35584_5V_VOLTAGE_OUTPUT_DETECT_TIME   10
#define TLF35584_VQT_RECOVERY_TIME 200


void EnableVQT1Recovery(void)
{
	Tlf35584SpiFrameType spiFrame;

	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevstatRegAddr, (uint8)DUMMY_DATA);
    g_TlfDeviceReg.DEVSTAT.U = spiFrame.B.data;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevctrlRegAddr, (uint8)DUMMY_DATA);

    /* Refresh local value of TLF register */
    g_TlfDeviceReg.DEVCTRL.U = spiFrame.B.data;
	g_TlfDeviceReg.DEVCTRL.B.STATEREQ = g_TlfDeviceReg.DEVSTAT.B.STATE;
	g_TlfDeviceReg.DEVCTRL.B.TRK1EN = Tracker1QT_enabled;
	g_TlfDeviceReg.DEVCTRL.B.TRK2EN = Tracker2QT_enabled;
	g_TlfDeviceReg.DEVCTRLN.U = ~g_TlfDeviceReg.DEVCTRL.U;
	/* Update device register values */
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlRegAddr, g_TlfDeviceReg.DEVCTRL.U);
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlnRegAddr, g_TlfDeviceReg.DEVCTRLN.U);
}

void DisableVQT1(void)
{
	Tlf35584SpiFrameType spiFrame;

	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevstatRegAddr, (uint8)DUMMY_DATA);
    g_TlfDeviceReg.DEVSTAT.U = spiFrame.B.data;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevctrlRegAddr, (uint8)DUMMY_DATA);

    /* Refresh local value of TLF register */
    g_TlfDeviceReg.DEVCTRL.U = spiFrame.B.data;
	g_TlfDeviceReg.DEVCTRL.B.STATEREQ = g_TlfDeviceReg.DEVSTAT.B.STATE;
	g_TlfDeviceReg.DEVCTRL.B.TRK1EN = Tracker1QT_disabled;
	g_TlfDeviceReg.DEVCTRLN.U = ~g_TlfDeviceReg.DEVCTRL.U;
	/* Update device register values */
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlRegAddr, g_TlfDeviceReg.DEVCTRL.U);
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlnRegAddr, g_TlfDeviceReg.DEVCTRLN.U);
}

uint8 g_vqt1ErrorStatus = TLF35584_5V_NORMAL;
boolean GetVQT1ErrorStatus(void)
{
	static uint16 VQT1RecoveryTime = 0;
	boolean ret = FALSE;
	uint8 vqt1ErrorStatus = FALSE;
	uint16 voltageQT1 = 0;
	static uint8 detVQT1Time = 0;

	voltageQT1 = g_SysVol.ADC_VQT1_5V *2 *5000 /4095;

	if((voltageQT1>=TLF35584_5V_SHORTOUT_TO_GND_MIN_VOLTAGE_0V)&&(voltageQT1<=TLF35584_5V_SHORTOUT_TO_GND_MAX_VOLTAGE_0V5))
    {
        vqt1ErrorStatus = TLF35584_5V_SHORTOUT_TO_GND;
    }
	else if(voltageQT1 >= TLF35584_5V_SHORTOUT_TO_POWER_MAX_VOLTAGE_6V)
	{
		vqt1ErrorStatus = TLF35584_5V_SHORTOUT_TO_POWER;
	}
	else
	{
		vqt1ErrorStatus = TLF35584_5V_NORMAL;
	}

	if(((vqt1ErrorStatus == TLF35584_5V_NORMAL)&&(g_vqt1ErrorStatus == TLF35584_5V_NORMAL))||
	   ((vqt1ErrorStatus == TLF35584_5V_SHORTOUT_TO_GND)&&(g_vqt1ErrorStatus == TLF35584_5V_SHORTOUT_TO_GND))||
	   ((vqt1ErrorStatus == TLF35584_5V_SHORTOUT_TO_POWER)&&(g_vqt1ErrorStatus == TLF35584_5V_SHORTOUT_TO_POWER)))
	{
		detVQT1Time = 0;
	}
	else
	{
		detVQT1Time++;
	}

	if(detVQT1Time >= TLF35584_5V_VOLTAGE_OUTPUT_DETECT_TIME)
	{
		if(g_vqt1ErrorStatus != vqt1ErrorStatus)
		{
			g_vqt1ErrorStatus = vqt1ErrorStatus;
			if(g_vqt1ErrorStatus != TLF35584_5V_NORMAL)
			{
				//DisableVQT1();
			}
		}
	}

	if(g_vqt1ErrorStatus != TLF35584_5V_NORMAL)
	{
		VQT1RecoveryTime++;
		if(VQT1RecoveryTime >= TLF35584_VQT_RECOVERY_TIME)
		{
			EnableVQT1Recovery();
			VQT1RecoveryTime = 0;
		}
	}
	else
	{
		if(VQT1RecoveryTime != 0)
		{
			VQT1RecoveryTime = 0;
		}
	}
    
	ret = g_vqt1ErrorStatus;
	return ret;
}

uint8 GetVQT1DiagStatus(void)
{
	return g_vqt1ErrorStatus;
}

void EnableVQT2Recovery(void)
{
	Tlf35584SpiFrameType spiFrame;

	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevstatRegAddr, (uint8)DUMMY_DATA);
    g_TlfDeviceReg.DEVSTAT.U = spiFrame.B.data;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevctrlRegAddr, (uint8)DUMMY_DATA);

    /* Refresh local value of TLF register */
    g_TlfDeviceReg.DEVCTRL.U = spiFrame.B.data;
	g_TlfDeviceReg.DEVCTRL.B.STATEREQ = g_TlfDeviceReg.DEVSTAT.B.STATE;
	g_TlfDeviceReg.DEVCTRL.B.TRK1EN = Tracker1QT_enabled;
	g_TlfDeviceReg.DEVCTRL.B.TRK2EN = Tracker2QT_enabled;
	g_TlfDeviceReg.DEVCTRLN.U = ~g_TlfDeviceReg.DEVCTRL.U;
	/* Update device register values */
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlRegAddr, g_TlfDeviceReg.DEVCTRL.U);
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlnRegAddr, g_TlfDeviceReg.DEVCTRLN.U);
	Tlf35584DataTransfer(SpiCommand_read, DevstatRegAddr, (uint8)DUMMY_DATA);
}

void DisableVQT2(void)
{
	Tlf35584SpiFrameType spiFrame;

	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevstatRegAddr, (uint8)DUMMY_DATA);
    g_TlfDeviceReg.DEVSTAT.U = spiFrame.B.data;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevctrlRegAddr, (uint8)DUMMY_DATA);

    /* Refresh local value of TLF register */
    g_TlfDeviceReg.DEVCTRL.U = spiFrame.B.data;
	g_TlfDeviceReg.DEVCTRL.B.STATEREQ = g_TlfDeviceReg.DEVSTAT.B.STATE;
	g_TlfDeviceReg.DEVCTRL.B.TRK2EN = Tracker2QT_disabled;
	g_TlfDeviceReg.DEVCTRLN.U = ~g_TlfDeviceReg.DEVCTRL.U;
	/* Update device register values */
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlRegAddr, g_TlfDeviceReg.DEVCTRL.U);
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlnRegAddr, g_TlfDeviceReg.DEVCTRLN.U);
}
#include "SysVol.h"
uint8 g_vqt2ErrorStatus = TLF35584_5V_NORMAL;
boolean GetVQT2ErrorStatus(void)
{
	static uint16 VQT2RecoveryTime = 0;
	boolean ret = FALSE;
	uint8 vqt2ErrorStatus = FALSE;
	uint16 voltageQT2 = 0;
	static uint8 detVQT2Time = 0;

	voltageQT2 = g_SysVol.ADC_VQT2_5V *2 *5000 /4095;//GetMonitorVoltage(VLOTAGE_ADC_VQT2_5V);

	if((voltageQT2>=TLF35584_5V_SHORTOUT_TO_GND_MIN_VOLTAGE_0V)&&(voltageQT2<=TLF35584_5V_SHORTOUT_TO_GND_MAX_VOLTAGE_0V5))
    {
        vqt2ErrorStatus = TLF35584_5V_SHORTOUT_TO_GND;
    }
	else if(voltageQT2 >= TLF35584_5V_SHORTOUT_TO_POWER_MAX_VOLTAGE_6V)
	{
		vqt2ErrorStatus = TLF35584_5V_SHORTOUT_TO_POWER;
	}
	else
	{
		vqt2ErrorStatus = TLF35584_5V_NORMAL;
	}

	if(((vqt2ErrorStatus == TLF35584_5V_NORMAL)&&(g_vqt2ErrorStatus == TLF35584_5V_NORMAL))||
	   ((vqt2ErrorStatus == TLF35584_5V_SHORTOUT_TO_GND)&&(g_vqt2ErrorStatus == TLF35584_5V_SHORTOUT_TO_GND))||
	   ((vqt2ErrorStatus == TLF35584_5V_SHORTOUT_TO_POWER)&&(g_vqt2ErrorStatus == TLF35584_5V_SHORTOUT_TO_POWER)))
	{
		detVQT2Time = 0;
	}
	else
	{
		detVQT2Time++;
	}

	if(detVQT2Time >= TLF35584_5V_VOLTAGE_OUTPUT_DETECT_TIME)
	{
		if(g_vqt2ErrorStatus != vqt2ErrorStatus)
		{
			g_vqt2ErrorStatus = vqt2ErrorStatus;
			if(g_vqt2ErrorStatus != TLF35584_5V_NORMAL)
			{
				//DisableVQT2();
			}
		}
	}

	if(g_vqt2ErrorStatus != TLF35584_5V_NORMAL)
	{
		VQT2RecoveryTime++;
		if(VQT2RecoveryTime >= TLF35584_VQT_RECOVERY_TIME)
		{
			VQT2RecoveryTime = 0;
			EnableVQT2Recovery();
		}
	}
	else
	{
		if(VQT2RecoveryTime != 0)
		{
			VQT2RecoveryTime = 0;
		}
	}
    
	ret = g_vqt2ErrorStatus;
	return ret;
}

uint8 GetVQT2DiagStatus(void)
{
	return g_vqt2ErrorStatus;
}

void EnableVQCORecovery(void)
{
	Tlf35584SpiFrameType spiFrame;

	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevstatRegAddr, (uint8)DUMMY_DATA);
    g_TlfDeviceReg.DEVSTAT.U = spiFrame.B.data;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevctrlRegAddr, (uint8)DUMMY_DATA);

    /* Refresh local value of TLF register */
    g_TlfDeviceReg.DEVCTRL.U = spiFrame.B.data;
	g_TlfDeviceReg.DEVCTRL.B.STATEREQ = g_TlfDeviceReg.DEVSTAT.B.STATE;
	g_TlfDeviceReg.DEVCTRL.B.COMEN = CommunicationLdoQCO_enabled;
	g_TlfDeviceReg.DEVCTRLN.U = ~g_TlfDeviceReg.DEVCTRL.U;
	/* Update device register values */
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlRegAddr, g_TlfDeviceReg.DEVCTRL.U);
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlnRegAddr, g_TlfDeviceReg.DEVCTRLN.U);
	Tlf35584DataTransfer(SpiCommand_read, DevstatRegAddr, (uint8)DUMMY_DATA);
}

void DisableVQCO(void)
{
	Tlf35584SpiFrameType spiFrame;

	spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevstatRegAddr, (uint8)DUMMY_DATA);
    g_TlfDeviceReg.DEVSTAT.U = spiFrame.B.data;

    spiFrame.U = Tlf35584DataTransfer(SpiCommand_read, DevctrlRegAddr, (uint8)DUMMY_DATA);

    /* Refresh local value of TLF register */
    g_TlfDeviceReg.DEVCTRL.U = spiFrame.B.data;
	g_TlfDeviceReg.DEVCTRL.B.STATEREQ = g_TlfDeviceReg.DEVSTAT.B.STATE;
	g_TlfDeviceReg.DEVCTRL.B.COMEN = CommunicationLdoQCO_disabled;
	g_TlfDeviceReg.DEVCTRLN.U = ~g_TlfDeviceReg.DEVCTRL.U;
	/* Update device register values */
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlRegAddr, g_TlfDeviceReg.DEVCTRL.U);
	Tlf35584DataTransfer(SpiCmd_Write, DevctrlnRegAddr, g_TlfDeviceReg.DEVCTRLN.U);
}

uint8 g_vqcoErrorStatus = TLF35584_5V_NORMAL;
boolean GetVQCOErrorStatus(void)
{
	static uint16 VQCORecoveryTime = 0;
	boolean ret = FALSE;
	uint8 vqcoErrorStatus = FALSE;
	uint16 voltageQCO = 0;
	static uint8 detVQCOTime = 0;

	voltageQCO = GetMonitorVoltage(VLOTAGE_ADC_VQCO_5V);

	if((voltageQCO>=TLF35584_5V_SHORTOUT_TO_GND_MIN_VOLTAGE_0V)&&(voltageQCO<=TLF35584_5V_SHORTOUT_TO_GND_MAX_VOLTAGE_0V5))
    {
        vqcoErrorStatus = TLF35584_5V_SHORTOUT_TO_GND;
    }
	else if(voltageQCO >= TLF35584_5V_SHORTOUT_TO_POWER_MAX_VOLTAGE_6V)
	{
		vqcoErrorStatus = TLF35584_5V_SHORTOUT_TO_POWER;
	}
	else
	{
		vqcoErrorStatus = TLF35584_5V_NORMAL;
	}

	if(((vqcoErrorStatus == TLF35584_5V_NORMAL)&&(g_vqcoErrorStatus == TLF35584_5V_NORMAL))||
	   ((vqcoErrorStatus == TLF35584_5V_SHORTOUT_TO_GND)&&(g_vqcoErrorStatus == TLF35584_5V_SHORTOUT_TO_GND))||
	   ((vqcoErrorStatus == TLF35584_5V_SHORTOUT_TO_POWER)&&(g_vqcoErrorStatus == TLF35584_5V_SHORTOUT_TO_POWER)))
	{
		detVQCOTime = 0;
	}
	else
	{
		detVQCOTime++;
	}

	if(detVQCOTime >= TLF35584_5V_VOLTAGE_OUTPUT_DETECT_TIME)
	{
		if(g_vqt2ErrorStatus != vqcoErrorStatus)
		{
			g_vqt2ErrorStatus = vqcoErrorStatus;
			if(g_vqcoErrorStatus != TLF35584_5V_NORMAL)
			{
				//DisableVQT2();
			}
		}
	}

	if(g_vqcoErrorStatus != TLF35584_5V_NORMAL)
	{
		VQCORecoveryTime++;
		if(VQCORecoveryTime >= TLF35584_VQT_RECOVERY_TIME)
		{
			VQCORecoveryTime = 0;
			EnableVQCORecovery();
		}
	}
	else
	{
		if(VQCORecoveryTime != 0)
		{
			VQCORecoveryTime = 0;
		}
	}
    
	ret = g_vqcoErrorStatus;
	return ret;
}

uint8 GetVQCODiagStatus(void)
{
	return g_vqcoErrorStatus;
}


