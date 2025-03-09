/*****************************************************************************
*
* Copyright (C) 2019 Infineon Technologies AG. All rights reserved.
*
* Infineon Technologies AG (INFINEON) is supplying this file for use
* exclusively with Infineon's microcontroller products. This file can be freely
* distributed within development tools and software supporting such microcontroller
* products.
*
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
******************************************************************************/

#include "swap.h"


#define DISABLE 0
#define ENABLE 1


#define UCB_OTP0_ORIG   0xAF404000
#define UCB_OTP0_COPY   0xAF405000
#define SWAP_EN_CODE    0x00030000
#define UCB_SWAP_ORIG   0xAF402E00
#define UCB_SWAP_COPY   0xAF403E00
#define UNLOCKCODE      0x43211234
#define CONFIRMEDCODE   0x57b5327f
#define ZEROS           0x00000000


/*===========================[M A C R O S]========================================================*/
/*===========================[T Y P E   D E F I N I T I O N S]====================================*/
/*===========================[I N T E R N A L   D A T A]==========================================*/
/*===========================[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
uint8 UCB_SWAP_ORIG_buff_Marker[16][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};


uint8 UCB_SWAP_ORIG_buff_Confirm[16][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};

uint8 UCB_SWAP_COPY_buff_Marker[16][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};

uint8 UCB_SWAP_COPY_buff_Confirm[16][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};

/**************************************************************************************************/
/*===========================[F U N C T I O N	I M P L E M E N T A T I O N S]====================
/**************************************************************************************************
 * Brief               <Service for switches the  into the mode>
 * ServiceId           0x01
 * Sync/Async          <Synchronous>
 * Return              <Std_ReturnType: E_NOT_OK, or E_OK>
 * PreCondition        <The    must not be initialled>
 */
/**************************************************************************************************/
void configure_swap_Init_Once(uint8 BankNum)
{
	uint8 Init_Rst;

	if(0x0 == ((SCU_STMEM1.U & 0x00030000) >> 16))
	{
		Init_Rst = Disable_Swap_Config();

		if(0xFE == Init_Rst)
		{
			(void)configure_swap(0x55);
		}
	}
}
/**************************************************************************************************/
/* name
 * Brief               <Service for switches the  into the mode>
 * ServiceId           0x01
 * Sync/Async          <Synchronous>
 * Return              <Std_ReturnType: E_NOT_OK, or E_OK>
 * PreCondition        <The    must not be initialled>
 */
/**************************************************************************************************/
//uint8 flaf_swap;
uint8 configure_swap_MainFunc(uint8 BankNum)
{
	uint8 Bank_Swap;
	uint8 Config_Rst = 0u;
	uint8 Swap_Rst = 0u;
	
#if 0//for code test
	if(flaf_swap == 0u)
	{
		Config_Rst = configure_swap(0xAA);
		flaf_swap = 0x1;
	}
	else
	{
		Config_Rst =configure_swap(0x55);
		flaf_swap = 0x0;
	}
#endif

#if 1
	Bank_Swap = ((SCU_STMEM1.U & 0x00030000) >> 16u);

    /* Toggle SWAP configuration that shall become active after next system reset */
	switch((SCU_STMEM1.U & 0x00030000) >> 16u)
	{
		case 0u: // Coming from SWAP disabled state - the function 'enable_swap()' enables SWAP and SWAP becomes active after the next SystemReset.
			    // This case installs a initial SWAP configuration to prevent the device from getting locked. See App Note for further details.
			if(Bank_Switch == BankNum)
			{
				Config_Rst =configure_swap(0xAA);
			}
			else if(Bank_Keep == BankNum)
			{
				Config_Rst =configure_swap(0x55);
			}
			else
			{
				Config_Rst =configure_swap(0xAA);
			}
			break;
		
		case 1u: // In case group of A-Banks are installed by SSW, config B-Banks to become active after next system reset.
			if(Bank_Switch == BankNum)
			{
				Config_Rst =configure_swap(0xAA);
			}
			else if(Bank_Keep == BankNum)
			{
				Config_Rst =configure_swap(0x55);
			}
			break;
			
		case 2u: // In case group of B banks are installed by SSW, config A-Banks to become active after next system reset.
			if(Bank_Switch == BankNum)
			{
				Config_Rst =configure_swap(0x55);
			}
			else if(Bank_Keep == BankNum)
			{
				Config_Rst =configure_swap(0xAA);
			}
			break;
			
		default:
			Config_Rst = configure_swap(0x55);
			break;
	}
#endif

	if(0xFE == Config_Rst)
	{
		/* Enable SWAP if not already enabled */
		//Swap_Rst = Enable_Swap_Config();
		Swap_Rst = 1;
	}
	else
	{
		Disable_Swap_Config();		
		Swap_Rst = 0u;
	}

	if(1u == Swap_Rst)
	{
		if((0xFE == Read_ORIG_Swap_Info())||(0xFE == Read_COPY_Swap_Info()))
		{

		}
		else
		{
			(void)Disable_Swap_Config();
			Swap_Rst = 0u;
		}
	}

	return Swap_Rst;
}
/**************************************************************************************************/
/* name
 * Brief               <Service for switches the  into the mode>
 * ServiceId           0x01
 * Sync/Async          <Synchronous>
 * Return              <Std_ReturnType: E_NOT_OK, or E_OK>
 * PreCondition        <The    must not be initialled>
 */
/**************************************************************************************************/
uint8 Enable_Swap_Config(void)
{
	uint8	Enable_Pagebuff_ORIG[8] = {0u};
	uint32	Enable_PageData_ORIG 	= 0u;
	uint8	Enable_Pagebuff_COPY[8] = {0u};
	uint32	Enable_PageData_COPY 	= 0u;
	uint8	Enable_Rst = 0u;

	if((0xFE == Read_ORIG_Swap_Info())||(0xFE == Read_COPY_Swap_Info()))
	{
		// If Swap is off then enable
		if(!(SCU_STMEM1.U & 0x00030000))
		{
			//Origin;
			UCBDriver_ucbProgramPage(UCB_OTP0_ORIG + 0x1E8, SWAP_EN_CODE, ZEROS); ///Write the CFG into UCB_OTP.PROCONTP register,
			                                                                     ///then be copied to DMU_HF_PROCONTP by SSW when startup

			UCBDriver_ucbReadDataFromUcb(UCB_OTP0_ORIG + 0x1E8, &Enable_Pagebuff_ORIG[0], 8u, DISABLE);

			Enable_PageData_ORIG = ((Enable_Pagebuff_ORIG[3]<<24) +\
					   		  	   (Enable_Pagebuff_ORIG[2]<<16) +\
					   		  	   (Enable_Pagebuff_ORIG[1]<<8) +\
					   		  	   (Enable_Pagebuff_ORIG[0]));

			if(SWAP_EN_CODE == Enable_PageData_ORIG)
			{
				//Copy;
				UCBDriver_ucbProgramPage(UCB_OTP0_COPY + 0x1E8, SWAP_EN_CODE, ZEROS); ///Write the CFG into UCB_OTP.PROCONTP register,
																					 ///then be copied to DMU_HF_PROCONTP by SSW when startup
				
				UCBDriver_ucbReadDataFromUcb(UCB_OTP0_COPY + 0x1E8, &Enable_Pagebuff_COPY[0], 8u, DISABLE);

				Enable_PageData_COPY = ((Enable_Pagebuff_COPY[3]<<24) +\
									   (Enable_Pagebuff_COPY[2]<<16) +\
									   (Enable_Pagebuff_COPY[1]<<8) +\
									   (Enable_Pagebuff_COPY[0]));

				if(SWAP_EN_CODE == Enable_PageData_COPY)
				{
					Enable_Rst = 0x1;
				}
				else
				{
					(void)Disable_Swap_Config();
					Enable_Rst = 0x0;
				}
			}
			else
			{
				(void)Disable_Swap_Config();
				Enable_Rst = 0x0;
			}
		}
		else
		{

			UCBDriver_ucbReadDataFromUcb(UCB_OTP0_ORIG + 0x1E8, &Enable_Pagebuff_ORIG[0], 8u, DISABLE);
				
			Enable_PageData_ORIG = ((Enable_Pagebuff_ORIG[3]<<24) +\
								   (Enable_Pagebuff_ORIG[2]<<16) +\
								   (Enable_Pagebuff_ORIG[1]<<8) +\
								   (Enable_Pagebuff_ORIG[0]));

			UCBDriver_ucbReadDataFromUcb(UCB_OTP0_COPY + 0x1E8, &Enable_Pagebuff_COPY[0], 8u, DISABLE);
								   
			Enable_PageData_COPY = ((Enable_Pagebuff_COPY[3]<<24) +\
									(Enable_Pagebuff_COPY[2]<<16) +\
									(Enable_Pagebuff_COPY[1]<<8) +\
									(Enable_Pagebuff_COPY[0]));

			if((SWAP_EN_CODE == Enable_PageData_ORIG)||(SWAP_EN_CODE == Enable_PageData_COPY))
			{
				Enable_Rst = 0x1;
			}
			else
			{
				(void)Disable_Swap_Config();
				Enable_Rst = 0x0;
			}
		}
	}
	else
	{
		(void)Disable_Swap_Config();
		Enable_Rst = 0x0;
	}
	
	return Enable_Rst;
}
/**************************************************************************************************/
/* name
 * Brief               <Service for switches the  into the mode>
 * ServiceId           0x01
 * Sync/Async          <Synchronous>
 * Return              <Std_ReturnType: E_NOT_OK, or E_OK>
 * PreCondition        <The    must not be initialled>
 */
/**************************************************************************************************/
uint8 Disable_Swap_Config(void)
{
	uint8	Dis_Rst = 0x0;

	uint32	Dis_PageData_Copy = 0u;
	uint8	Dis_Pagebuff_Copy[8] = {0u};
	
	uint32	Dis_PageData_Orig = 0u;
	uint8	Dis_Pagebuff_Orig[8] = {0u};

	//Copy
    UCBDriver_ucbEraseSector(UCB_OTP0_COPY);
    UCBDriver_ucbProgramPage(UCB_OTP0_COPY + 0x1f0, UNLOCKCODE   , ZEROS);

	UCBDriver_ucbReadDataFromUcb(UCB_OTP0_COPY + 0x1f0, &Dis_Pagebuff_Copy[0], 8, DISABLE);

	Dis_PageData_Copy = ((uint32)Dis_Pagebuff_Copy[3]<<24)+((uint32)Dis_Pagebuff_Copy[2]<<16)+((uint32)Dis_Pagebuff_Copy[1]<<8)+((uint32)Dis_Pagebuff_Copy[0]);
	
	if(UNLOCKCODE == Dis_PageData_Copy)
	{
		//Origin
		UCBDriver_ucbEraseSector(UCB_OTP0_ORIG);
		UCBDriver_ucbProgramPage(UCB_OTP0_ORIG + 0x1f0, UNLOCKCODE   , ZEROS);

		UCBDriver_ucbReadDataFromUcb(UCB_OTP0_ORIG + 0x1f0, &Dis_Pagebuff_Orig[0], 8, DISABLE);

		Dis_PageData_Orig = ((uint32)Dis_Pagebuff_Orig[3]<<24)+((uint32)Dis_Pagebuff_Orig[2]<<16)+((uint32)Dis_Pagebuff_Orig[1]<<8)+((uint32)Dis_Pagebuff_Orig[0]);		

		if(UNLOCKCODE == Dis_PageData_Orig)
		{
			Dis_Rst = 0xFE;
		}
	}
	else
	{
		Dis_Rst = 0x0;
	}

	return Dis_Rst;
}
/**************************************************************************************************/
/* name
 * Brief               <Service for switches the  into the mode>
 * ServiceId           0x01
 * Sync/Async          <Synchronous>
 * Return              <Std_ReturnType: E_NOT_OK, or E_OK>
 * PreCondition        <The    must not be initialled>
 */
/**************************************************************************************************/
//uint8 index = 0;
uint8 configure_swap(uint32 map)
{
	uint8 Ret = 0;
	uint32 nxtfreeswapidx;
	uint32 nxtfreeswapadr;
    uint32 OldSwap_CopyID;
    uint32 OldSwap_OrigID;

	// If SWAP is off OR a swap config on pos 15 exists evaluating SCU_STMEM1 register
	if((SCU_STMEM1.U & 0x00030000) == 0 || ((SCU_STMEM1.U & 0x00f80000) >> 3) == 0x001e0000)
	{
#if 1
		// Erase and write initial swap config to _COPY
	    UCBDriver_ucbEraseSector(UCB_SWAP_COPY);
	    UCBDriver_ucbProgramPage(UCB_SWAP_COPY        , map          , UCB_SWAP_COPY);
	    UCBDriver_ucbProgramPage(UCB_SWAP_COPY + 8    , CONFIRMEDCODE, UCB_SWAP_COPY + 8);
	    UCBDriver_ucbProgramPage(UCB_SWAP_COPY + 0x1f0, UNLOCKCODE   , ZEROS);

		if(0xFE == Read_COPY_Swap_Info())
		{
		    // Erase and write initial swap config to _ORIG
		    UCBDriver_ucbEraseSector(UCB_SWAP_ORIG);
		    UCBDriver_ucbProgramPage(UCB_SWAP_ORIG        , map          , UCB_SWAP_ORIG);
		    UCBDriver_ucbProgramPage(UCB_SWAP_ORIG + 8    , CONFIRMEDCODE, UCB_SWAP_ORIG + 8);
		    UCBDriver_ucbProgramPage(UCB_SWAP_ORIG + 0x1f0, UNLOCKCODE   , ZEROS);

			if(0xFE == Read_ORIG_Swap_Info())
			{
				Ret = 0xFE;
			}
			else
			{
				Ret = 0u;
			}
		}
		else
		{
			//do nothing,keep origin value;
			Ret = 0u;
		}
#endif
	}
	// add a new swap config to next free index
	else
	{
		// Compute next free index based on SCU_STMEM1 register
		nxtfreeswapidx = (((SCU_STMEM1.U & 0x00f80000) >> 20) + 1) * 0x10;
#if 0
		//for test code;
		nxtfreeswapidx = ((index) + 1) * 0x10;
		index++;
		if(nxtfreeswapidx >= 0xF0)
		{
			index = 0x0;
			nxtfreeswapidx = 0xF0;
		}
#endif

		nxtfreeswapadr = UCB_SWAP_COPY + nxtfreeswapidx;

		 OldSwap_CopyID=UCB_SWAP_COPY +nxtfreeswapidx-0x10;
		 OldSwap_OrigID=UCB_SWAP_ORIG +nxtfreeswapidx-0x10;


		//overprogram old SWAP ID address
		UCBDriver_ucbProgramPage(OldSwap_CopyID + 8, 0xFFFFFFFF, 0xFFFFFFFF);
		// Add swap config to UCB_SWAP_COPY
	    UCBDriver_ucbProgramPage(nxtfreeswapadr, map, nxtfreeswapadr);
	    UCBDriver_ucbProgramPage(nxtfreeswapadr + 8, CONFIRMEDCODE, nxtfreeswapadr + 8);

		if(0xFE == Read_COPY_Swap_Info())
		{
			//overprogram old SWAP ID address
			UCBDriver_ucbProgramPage( OldSwap_OrigID + 8, 0xFFFFFFFF, 0xFFFFFFFF);
			// Add swap config to UCB_SWAP_ORIG
			nxtfreeswapadr = UCB_SWAP_ORIG + nxtfreeswapidx;
			UCBDriver_ucbProgramPage(nxtfreeswapadr, map, nxtfreeswapadr);
			UCBDriver_ucbProgramPage(nxtfreeswapadr + 8, CONFIRMEDCODE, nxtfreeswapadr + 8);

			if(0xFE == Read_ORIG_Swap_Info())
			{
				Ret = 0xFE;
			}
			else
			{
				Ret = 0u;
			}
		}
		else
		{
			//do nothing, keep origin value;
			Ret = 0u;
		}
	}

	return Ret;
}
/**************************************************************************************************/
/* name
 * Brief               <Service for switches the  into the mode>
 * ServiceId           0x01
 * Sync/Async          <Synchronous>
 * Return              <Std_ReturnType: E_NOT_OK, or E_OK>
 * PreCondition        <The    must not be initialled>
 */
/**************************************************************************************************/
uint8 Read_ORIG_Swap_Info(void)
{
	uint8 Ret = 0;
	uint8 i = 0;
	uint32 ORIG_MarkerLx_Addr = 0x0;
	uint32 ORIG_MarkerHx_Addr = 0x0;
	uint32 ORIG_MarkerLx_Value = 0x0;
	uint32 ORIG_MarkerHx_Value = 0x0;
	
	uint32 ORIG_ConfirmationLx_Addr = 0x0;
	uint32 ORIG_ConfirmationHx_Addr = 0x0;
	uint32 ORIG_ConfirmationLx_Value = 0x0;
	uint32 ORIG_ConfirmationHx_Value = 0x0;

	uint32 ORIG_ConfirmationCode_Addr = 0x0;
	uint32 ORIG_ConfirmationCode_Value = 0x0;
	
	for(i=0u; i<16u; i++)
	{
		ORIG_ConfirmationLx_Addr = UCB_SWAP_ORIG + i*(0x10) + 0x8;
		
		UCBDriver_ucbReadDataFromUcb(ORIG_ConfirmationLx_Addr, &UCB_SWAP_ORIG_buff_Confirm[i][0], 8, DISABLE);

		ORIG_ConfirmationLx_Value = ((UCB_SWAP_ORIG_buff_Confirm[i][3]<<24) +\
									(UCB_SWAP_ORIG_buff_Confirm[i][2]<<16) +\
									(UCB_SWAP_ORIG_buff_Confirm[i][1]<<8) +\
									(UCB_SWAP_ORIG_buff_Confirm[i][0]));

		ORIG_ConfirmationHx_Value = ((UCB_SWAP_ORIG_buff_Confirm[i][7]<<24) +\
									(UCB_SWAP_ORIG_buff_Confirm[i][6]<<16) +\
									(UCB_SWAP_ORIG_buff_Confirm[i][5]<<8) +\
									(UCB_SWAP_ORIG_buff_Confirm[i][4]));

		//Marker
		ORIG_MarkerLx_Addr = UCB_SWAP_ORIG + i*(0x10);
		
		UCBDriver_ucbReadDataFromUcb(ORIG_MarkerLx_Addr, &UCB_SWAP_ORIG_buff_Marker[i][0], 8, DISABLE);

		ORIG_MarkerLx_Value = ((UCB_SWAP_ORIG_buff_Marker[i][3]<<24) +\
							  (UCB_SWAP_ORIG_buff_Marker[i][2]<<16) +\
							  (UCB_SWAP_ORIG_buff_Marker[i][1]<<8) +\
							  (UCB_SWAP_ORIG_buff_Marker[i][0]));

		ORIG_MarkerHx_Value = ((UCB_SWAP_ORIG_buff_Marker[i][7]<<24) +\
							  (UCB_SWAP_ORIG_buff_Marker[i][6]<<16) +\
							  (UCB_SWAP_ORIG_buff_Marker[i][5]<<8) +\
							  (UCB_SWAP_ORIG_buff_Marker[i][4]));
		
		if((CONFIRMEDCODE == ORIG_ConfirmationLx_Value)&&(ORIG_ConfirmationLx_Addr == ORIG_ConfirmationHx_Value))
		{		//value is the same;
			if((ORIG_MarkerLx_Addr == ORIG_MarkerHx_Value)&&\
			  ((0xAA == ORIG_MarkerLx_Value)||(0x55 == ORIG_MarkerLx_Value)))
			{				
				Ret = 0xFE;
			}
		}
		else
		{
			//do nothing;
		}
	}

	return Ret;
}
/**************************************************************************************************/
/* name
 * Brief               <Service for switches the  into the mode>
 * ServiceId           0x01
 * Sync/Async          <Synchronous>
 * Return              <Std_ReturnType: E_NOT_OK, or E_OK>
 * PreCondition        <The    must not be initialled>
 */
/**************************************************************************************************/
uint8 Read_COPY_Swap_Info(void)
{
	uint8 Ret = 0;
	uint8 i = 0;
	uint32 COPY_MarkerLx_Addr = 0x0;
	uint32 COPY_MarkerHx_Addr = 0x0;
	uint32 COPY_MarkerLx_Value = 0x0;
	uint32 COPY_MarkerHx_Value = 0x0;
	
	uint32 COPY_ConfirmationLx_Addr = 0x0;
	uint32 COPY_ConfirmationHx_Addr = 0x0;
	uint32 COPY_ConfirmationLx_Value = 0x0;
	uint32 COPY_ConfirmationHx_Value = 0x0;

	uint32 COPY_ConfirmationCode_Addr = 0x0;
	uint32 COPY_ConfirmationCode_Value = 0x0;
	
	for(i=0u; i<16u; i++)
	{
		COPY_ConfirmationLx_Addr = (UCB_SWAP_COPY + i*(0x10) + 0x8);
		
		UCBDriver_ucbReadDataFromUcb(COPY_ConfirmationLx_Addr, &UCB_SWAP_COPY_buff_Confirm[i][0], 8, DISABLE);

		COPY_ConfirmationLx_Value = ((UCB_SWAP_COPY_buff_Confirm[i][3]<<24) +\
									(UCB_SWAP_COPY_buff_Confirm[i][2]<<16) +\
									(UCB_SWAP_COPY_buff_Confirm[i][1]<<8) +\
									(UCB_SWAP_COPY_buff_Confirm[i][0]));

		COPY_ConfirmationHx_Value = ((UCB_SWAP_COPY_buff_Confirm[i][7]<<24) +\
									(UCB_SWAP_COPY_buff_Confirm[i][6]<<16) +\
									(UCB_SWAP_COPY_buff_Confirm[i][5]<<8) +\
									(UCB_SWAP_COPY_buff_Confirm[i][4]));

		//Marker
		COPY_MarkerLx_Addr = (UCB_SWAP_COPY + i*(0x10));
		
		UCBDriver_ucbReadDataFromUcb(COPY_MarkerLx_Addr, &UCB_SWAP_COPY_buff_Marker[i][0], 8, DISABLE);

		COPY_MarkerLx_Value = ((UCB_SWAP_COPY_buff_Marker[i][3]<<24) +\
							  (UCB_SWAP_COPY_buff_Marker[i][2]<<16) +\
							  (UCB_SWAP_COPY_buff_Marker[i][1]<<8) +\
							  (UCB_SWAP_COPY_buff_Marker[i][0]));

		COPY_MarkerHx_Value = ((UCB_SWAP_COPY_buff_Marker[i][7]<<24) +\
							  (UCB_SWAP_COPY_buff_Marker[i][6]<<16) +\
							  (UCB_SWAP_COPY_buff_Marker[i][5]<<8) +\
							  (UCB_SWAP_COPY_buff_Marker[i][4]));
		
		if((CONFIRMEDCODE == COPY_ConfirmationLx_Value)&&(COPY_ConfirmationLx_Addr == COPY_ConfirmationHx_Value))
		{		//value is the same;
			if((COPY_MarkerLx_Addr == COPY_MarkerHx_Value)&&\
			((0xAA == COPY_MarkerLx_Value)||(0x55 == COPY_MarkerLx_Value)))
			{				
				Ret = 0xFE;
			}
		}
		else
		{
			//do nothing;
		}
	}

	return Ret;
}
/*===========================[E N D   O F   F I L E]==============================================*/


