/*!
***********************************************************************************
*
*  Copyright: 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   EepromDriver.c
* \author  BL_zq
* \version 1.0
* \date    2022-05-26
* \btief   xxx driver
*
*----------------------------------------------------------------------------------
* \attention
*
*
***********************************************************************************
*/

/**********************************************************************************
  change history:
    1.date  : 2022-05-26
         author: BL_zq
         change: create file

***********************************************************************************/

/***************************************Includes************************************/
#include "UCB_DataFlashDriver.h"
#include <stdio.h>
#include <string.h>
#include "IfxFlash_cfg.h"
#include "UCB_IfxFlash.h"
//#include "IfxScuWdt.h"
#include "Ifx_Ssw_Infra.h"
/***************************************Variables***********************************/

/***************************************Functions***********************************/
void UCBDriver_ucbEraseSector(uint32 Addr);
void UCBDriver_ucbProgramPage(uint32 Addr, uint32 lword, uint32 hword);
uint8 UCBDriver_ucbReadDataFromUcb(uint32 startAddr,uint8 *p_data,uint16 len, uint32 checksumEnable);
uint8 UCBDriver_ucbWriteDataIntoUcb(uint32 startAddr,uint8 *p_data,uint16 len, uint32 checksumEnable);

/*******************************************************************************
** Syntax          : void EepromDriver_eepromEraseSector(uint32 Addr)					                                         
**                                                                              
** Description     : DFlash Sector Erase - DFlash erasure must be done in sectors                                                          
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : Addr - Sector address                                                       
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : none                                                       
**                                                                              
*******************************************************************************/
void UCBDriver_ucbEraseSector(uint32 Addr)
{
    /**Step1:Erase the sector  **/
    /**get th current password of Safety Watchdog module.  **/
    uint16 endInitSafetyPassword = 0;
	
    //endInitSafetyPassword = Ifx_Ssw_getSafetyWatchdogPassword();
	
    /** disable ENDINIT functionality provided by Safety WDT Hardware module  **/
    //Ifx_Ssw_clearSafetyEndinitInline(endInitSafetyPassword);
	
    /**Performs the erase sequence for 1 sectors in program or data flash.  **/
	
    /**wait until program or data flash X is unbusy  **/
    UCB_IfxFlash_waitUnbusy(DFLASH_0, IfxFlash_FlashType_D0);
	
    UCB_IfxFlash_eraseMultipleSectors(Addr,1);
	
    /**enable ENDINIT functionality provided by Safety WDT Hardware module  **/
    //Ifx_Ssw_setSafetyEndinitInline(endInitSafetyPassword);

    /**Step3:wait until the sector is erased  **/
    /**wait until program or data flash X is unbusy  **/
    UCB_IfxFlash_waitUnbusy(DFLASH_0, IfxFlash_FlashType_D0);
}
/*******************************************************************************
** Syntax          : void EepromDriver_eepromProgramPage(uint32 Addr, uint32 lword, uint32 hword)			                                         
**                                                                              
** Description     : The minimum amount of data that can be programmed in a flash memory is a page:
**                   -- Data Flash pages are made of 8 Bytes - 1Page = 8byte                                                          
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : Addr -- start address of page which should be programmed 
**                   data -- 8 byte Page write data                                                        
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : none                                                       
**                                                                              
*******************************************************************************/
void UCBDriver_ucbProgramPage(uint32 Addr, uint32 lword, uint32 hword)
{
    uint32 wordL, wordU;
    //wordL = ((uint32)data[3]<<24) | ((uint32)data[2]<<16) | ((uint32)data[1]<<8) | (uint32)data[0];
    //wordU = ((uint32)data[7]<<24) | ((uint32)data[6]<<16) | ((uint32)data[5]<<8) | (uint32)data[4];

	wordL = lword;
	wordU = hword;
	
    /**Step1:Enter Page Mode  **/
    /**Performs the sequence for entering program page mode  **/
    UCB_IfxFlash_enterPageMode(Addr);

    /**Step2:Wait until page mode is entered  **/
    /**wait until program or data flash X is unbusy  **/
    UCB_IfxFlash_waitUnbusy(DFLASH_0, IfxFlash_FlashType_D0);

    /**Step3:Load data to be written in the page
     * Fast programming of 8 byte pages for DFLASH  **/
    /**performs a load page sequence with two 32bit accesses,load 2*32bit into assembly buffer of data flash  **/
    UCB_IfxFlash_loadPage2X32(Addr,wordL,wordU);

    /**Step4:Write the loaded page  **/
    /**get th current password of Safety Watchdog module.  **/
    //uint16 endInitSafetyPassword = Ifx_Ssw_getSafetyWatchdogPassword();
	
    /** disable ENDINIT functionality provided by Safety WDT Hardware module  **/
    //Ifx_Ssw_clearSafetyEndinitInline(endInitSafetyPassword);
	
    /**Performs the "Write Page" sequence.  **/
    UCB_IfxFlash_writePage(Addr);
	
    /**enable ENDINIT functionality provided by Safety WDT Hardware module  **/
    //Ifx_Ssw_setSafetyEndinitInline(endInitSafetyPassword);

    /**Step5:wait until the sector is erased  **/
    /**wait until program or data flash X is unbusy  **/
    UCB_IfxFlash_waitUnbusy(DFLASH_0, IfxFlash_FlashType_D0);
}

/*******************************************************************************
** Syntax          : uint8 EepromDriver_eepromReadDataFromEeprom(uint32 startAddr,uint8 *p_data,uint16 len, uint32 checksumEnable)					                                         
**                                                                              
** Description     : Read data into Eeprom                                                           
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : startAddr - Start address
**                   p_data - Pointer to data Buffer of saving the data
**  				 len - Length of data to be read
**                   checksumEnable - Whether enable checksum                                                       
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : none                                                       
**                                                                              
*******************************************************************************/
uint8 UCBDriver_ucbReadDataFromUcb(uint32 startAddr,uint8 *p_data,uint16 len, uint32 checksumEnable)
{
    uint8 checksum = 0;

    /**Read data is not allowed in the following cases:
     * the source access address is not in the DFlash address range
     * the target address is NULL
     * the length of data is 0 **/
    if((startAddr<DFLASH0_START_ADDR)||((startAddr+len-1)>DFLASH0_END_ADDR)||(p_data==NULL)||(len==0))
    {
        return FALSE;
    }

    /**if there is a check byte, the data length needs to be increased by one  **/
    if(checksumEnable==ENABLE)
    {
        len++;
    }

    while(len)
    {
       if(len==1)
        {
            if(checksumEnable==ENABLE)
            {
                checksum = ~checksum + 1;
                if(checksum==(*(uint8*)startAddr))
                {
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
            }
        }
        *p_data = *(uint8*)startAddr++;
        checksum += *p_data++;
        len--;
        
    }
    return TRUE;
}

/*******************************************************************************
** Syntax          : uint8 EepromDriver_eepromWriteDataIntoEeprom(uint32 startAddr,uint8 *p_data,uint16 len, uint32 checksumEnable)					                                         
**                                                                              
** Description     : Write data into Eeprom                                                           
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : startAddr - Start address
**                   p_data - Pointer to data to be written
**  				 len - Length of data to be written
**                   checksumEnable - Whether enable checksum                                                       
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : none                                                       
**                                                                              
*******************************************************************************/
uint8 UCBDriver_ucbWriteDataIntoUcb(uint32 startAddr,uint8 *p_data,uint16 len, uint32 checksumEnable)
{
    uint8 checksum = 0;
    uint32 offsetPageNumber = 0, offsetAddr = 0,startPageAddr = 0,writePageAddr = 0, i = 0;
    uint8 pageBackup[8] = {0};
    uint8 eepromReadDataStatus = FALSE;

    /**Step1:Determine the function parameters.
     * Write data is not allowed in the following cases:
     * the source access address is not in the DFlash address range
     * the target address is NULL
     * the length of data is 0 **/
    if((p_data==NULL)||(len==0))
    {
        return FALSE;
    }

    if(checksumEnable==ENABLE)
    {
        len++;
    }

    if((startAddr<DFLASH0_START_ADDR)||((startAddr+len-1)>DFLASH0_END_ADDR))
    {
        return FALSE;
    }

    /**Step2:Determine chencksum whether need to be performed.
     * If it needs, the data length needs to be increased by one.
     * The check sum is equal to the sum of all the data invert plus one.  **/
    if(checksumEnable==ENABLE)
    {
        for(i=0;i<len-1;i++)
        {
            checksum += *(uint8*)(p_data+i);
        }
        checksum = ~checksum + 1;
    }

    
    /**Get the start address of the page programing  **/
    startPageAddr = startAddr - ((startAddr&0x000FFFFF)%8);
    /**The offset of the page written address relative to the start address of the sector  **/
    offsetAddr = startAddr - startPageAddr;

    /**Step3:Write data into DFlash which includes two case  **/
    /**Case 1: offsetAddr+len <=8 **/
    if((offsetAddr+len)<=8)
    {
        writePageAddr = startPageAddr;

        /**Read one page data(8byte) from the current sector.  **/
        eepromReadDataStatus = UCBDriver_ucbReadDataFromUcb(writePageAddr,pageBackup,8, DISABLE);
        if(eepromReadDataStatus==FALSE)
        {
            return FALSE;
        }

        for(;len>0;len--)
        {
            if(len==1)
            {
                if(checksumEnable==ENABLE)
                {
                    pageBackup[offsetAddr] = checksum;
                }
                else
                {
                    pageBackup[offsetAddr] = *(uint8*)p_data;
                }
                len--;
                break;
            }
            pageBackup[offsetAddr++] = *(uint8*)p_data++;
        }
        //EepromDriver_eepromProgramPage(writePageAddr,pageBackup);
    }
    /**Case 2: offsetAddr+len > 8 **/
    else
    {
        /**Get the offset page number which need to be written **/
        if((len+offsetAddr)%8)
        {
            offsetPageNumber = ((len+offsetAddr)/8) + 1;
        }
        else
        {
            offsetPageNumber = (len+offsetAddr) / 8;
        }

        for(uint16 page=0;page<offsetPageNumber;page++)
        {
            writePageAddr = startPageAddr + (page*8);
            for(i=0;i<8;i++)
            {
                pageBackup[i] = 0;
            }
            
            if(page==0)
            {
                eepromReadDataStatus = UCBDriver_ucbReadDataFromUcb(writePageAddr,pageBackup,8, DISABLE);
                if(eepromReadDataStatus==FALSE)
                {
                    return FALSE;
                }
                for(i=offsetAddr;i<8;i++)
                {
                    pageBackup[i] = *(uint8*)p_data++;
                    len--;
                }
            }
            else if((page==(offsetPageNumber-1))&&(len<8))
            {
                eepromReadDataStatus = UCBDriver_ucbReadDataFromUcb(writePageAddr,pageBackup,8, DISABLE);
                if(eepromReadDataStatus==FALSE)
                {
                    return FALSE;
                }

                for(i=0;len>0;)
                {
                    if(len==1)
                    {
                        if(checksumEnable==ENABLE)
                        {
                            pageBackup[offsetAddr] = checksum;
                        }
                        else
                        {
                            pageBackup[offsetAddr] = *(uint8*)p_data;
                        }
                        len--;
                        break;
                    }
                    pageBackup[i++] = *(uint8*)p_data++;
                    len--;
                }
            }
            else
            {
                memset((uint8*)pageBackup,0,8);
                for(i=0;i<8;i++)
                {
                    pageBackup[i] = *(uint8*)p_data++;
                    len--;
                }
            }
            //EepromDriver_eepromProgramPage(writePageAddr,pageBackup);
        } 
    }
    return TRUE;
}

/**********************************************END***************************************************/ 
 

 
