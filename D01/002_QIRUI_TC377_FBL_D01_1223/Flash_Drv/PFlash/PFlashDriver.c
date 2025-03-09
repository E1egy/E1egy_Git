/*!
***********************************************************************************
*
*  Copyright :2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   PFlashDriver.c
* \author  BL_zq
* \version 1.0
* \date    2022-05-27
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
    1.date  : 2022-05-27
         author: BL_zq
         change: create file

***********************************************************************************/

/***************************************Includes************************************/
#include "PFlashDriver.h"
#include "IfxFlash.h"
#include "IfxFlash_cfg.h"
#include "include_config.h"
#include "Ifx_Ssw_Infra.h"
#include "IfxScu_reg.h"
#include "IfxScu_regdef.h"

/***************************************Variables***********************************/
Function g_commandFromPSPR;

const unsigned int crc_1021_table[256] =
{
	0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,   //0x00-0x07
	0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,   //0x08-0x0f
	0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,   //0x10-0x17
	0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,   //0x18-0x1f
	0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,   //0x20-0x27
	0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,   //0x28-0x2f
	0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,   //0x30-0x37
	0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,   //0x38-0x3f

	0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,   //0x40-0x47
	0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,   //0x48-0x4F
	0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,   //0x50-0x57
	0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,   //0x58-0x5F
	0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,   //0x60-0x67
	0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,   //0x68-0x6F
	0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,   //0x70-0x77
	0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,   //0x78-0x7F

	0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,   //0x80-0x87
	0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,   //0x88-0x8F
	0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,   //0x90-0x97
	0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,   //0x98-0x9F
	0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,   //0xA0-0xA7
	0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,   //0xA8-0xAF
	0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,   //0xB0-0xB7
	0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,   //0xB8-0xBF

	0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,   //0xC0-0xC7
	0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,   //0xC8-0xCF
	0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,   //0xD0-0xD7
	0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,   //0xD8-0xDF
	0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,   //0xE0-0xE7
	0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,   //0xE8-0xEF
	0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,   //0xF0-0xF7
	0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0    //0xF8-0xFF
};

/***************************************Functions***********************************/
void PFlashDriver_maskPFlashUncorrectableEccBitErr(void);
void PFlashDriver_pflashCopyFunctionIntoPSPR(void);
uint8 PFlashDriver_pflashEraseSector(uint32 addr,uint32 sectorNumber);
uint32 PFlashDriver_pflashProgramPage(uint32 addr,uint8* p_data);
uint8 PFlashDriver_pflashReadDataFromPflash(uint32 addr, uint8 *p_data, uint16 len);
uint8 PFlashDriver_pflashWriteDataIntoPflash(uint32 addr, uint8 *p_data, uint32 len);
uint8 PFlashDriver_pflashCheckWriteData(uint32 addr, uint8 *p_data);
uint32 PFlashDriver_pflashCrcCcitt1021(uint32 initCrcValue,uint32 address,uint32 len);


void PFlashDriver_maskPFlashUncorrectableEccBitErr(void)
{
    Ifx_SCU_WDTCPU *wdt      = &MODULE_SCU.WDTCPU[0];
    unsigned short  cpuWdtPw = Ifx_Ssw_getCpuWatchdogPassword(wdt);
    Ifx_Ssw_clearCpuEndinit(wdt, cpuWdtPw);
    CPU0_FLASHCON1.U = 0x02010000u;
    CPU1_FLASHCON1.U = 0x02010000u;
    CPU2_FLASHCON1.U = 0x02010000u;
    DMU_HF_ECCC.B.TRAPDIS = 0u;
    Ifx_Ssw_setCpuEndinit(wdt, cpuWdtPw);
}

void PFlashDriver_pflashCopyFunctionIntoPSPR(void)
{
    g_commandFromPSPR.eraseSectors = (void (*)(uint32,uint32))IfxFlash_eraseMultipleSectors;

    g_commandFromPSPR.waitUnbusy = (uint8 (*)(uint32,IfxFlash_FlashType))IfxFlash_waitUnbusy;

    g_commandFromPSPR.enterPageMode = (uint8 (*)(uint32))IfxFlash_enterPageMode;

    g_commandFromPSPR.load2X32bits = (void (*)(uint32,uint32,uint32))IfxFlash_loadPage2X32;

    g_commandFromPSPR.writePage = (void (*)(uint32))IfxFlash_writePage;

    g_commandFromPSPR.eraseSector = (uint8 (*)(uint32,uint32))PFlashDriver_pflashEraseSector;

    g_commandFromPSPR.programPage = (uint32 (*)(uint32,uint8*))PFlashDriver_pflashProgramPage;

    g_commandFromPSPR.writeFlash = (uint8 (*)(uint32,uint8*,uint32))PFlashDriver_pflashWriteDataIntoPflash;
    
    g_commandFromPSPR.readFlash = (uint8 (*)(uint32,uint8*,uint16))PFlashDriver_pflashReadDataFromPflash;
}

/*******************************************************************************
** Syntax          : uint8 PFlashDriver_pflashEraseSector(uint32 addr)					                                         
**                                                                              
** Description     : The smallest unit on which an erase operation can be performed is a Logical Sector:16KB/Sector                                                       
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : addr - The start address of the sector                                                       
**                                                                              
** Parameters (out): Return the result of the erase operation                                                       
**                                                                              
** Return value    : TRUE - Erase operation succeeded
**                   FALSE - Erase operation failed                                                       
**                                                                              
*******************************************************************************/
#pragma  section code  "FLASHDRVCODE"
uint8 PFlashDriver_pflashEraseSector(uint32 addr,uint32 sectorNumber)
{
	/**Step0:Whether the erase address is correct.  **/
    
    if(((addr>=PFLASH0_START_ADDR)&&(addr<=PFLASH0_END_ADDR))||\
       ((addr>=PFLASH1_START_ADDR)&&(addr<=PFLASH1_END_ADDR)))
    {
        
    }
    else
    {
        return FALSE;
    }
   
    /**Step1:Erase the sector  **/
    /**get th current password of Safety Watchdog module.  **/
    uint16 endInitSafetyPassword = Ifx_Ssw_getSafetyWatchdogPasswordInline();
    /** disable ENDINIT functionality provided by Safety WDT Hardware module  **/
    Ifx_Ssw_clearSafetyEndinitInline(endInitSafetyPassword); 
    /**Performs the erase sequence for 1 sectors in program or data flash.
     * Important note:the follow operation will cause the  erase operation to fail.
     * 1) The range of logical sectors is not contained in one physical sector.
     * 2) For PFLASH, if the range of logical sectors exceeds 512KByte.
     * 3) If SA does not align to the start address of a logical sector.
     * 4) If SA aligns to an unavailable sector.
     * 5) If the number of logical sectors is set to 0.  **/
     g_commandFromPSPR.eraseSectors(addr,sectorNumber);

    /**enable ENDINIT functionality provided by Safety WDT Hardware module  **/
    Ifx_Ssw_setSafetyEndinitInline(endInitSafetyPassword);

    /**Step3:wait until the sector is erased  **/
    if((addr>=PFLASH0_START_ADDR)&&(addr<=PFLASH0_END_ADDR))
    {
        /**wait until program or data flash X is unbusy  **/
        g_commandFromPSPR.waitUnbusy(PFLASH_0, (IfxFlash_FlashType)FLASH_TYPE_OF_PFLASH0);
    }
   else if((addr>=PFLASH1_START_ADDR)&&(addr<=PFLASH1_END_ADDR))
    {
        g_commandFromPSPR.waitUnbusy(PFLASH_1, (IfxFlash_FlashType)FLASH_TYPE_OF_PFLASH1);
    }
    return TRUE;
}
#pragma section code restore 
/*******************************************************************************
** Syntax          : void PFlashDriver_pflashProgramPage(uint32 addr,uint8* p_data)					                                         
**                                                                              
** Description     : The minimum amount of data that can be programmed in a flash memory is a page:
**                   Program Flash pages are made of 32 Bytes  1Page =32byte
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : addr - The start address of the page  
**                   p_data - the data of waiting for writing                                                     
**                                                                              
** Parameters (out): none                                                       
**                                                                              
** Return value    : none                                                       
**                                                                              
*******************************************************************************/
#pragma  section code  "FLASHDRVCODE"
uint32 PFlashDriver_pflashProgramPage(uint32 addr,uint8* p_data)
{
    uint8 j = 0,k = 0;
    uint32 wordL = 0, wordU = 0, writeEndAddr = 0;	
	uint16	WaitInnerCount = 0U;
	uint16 delaycnt;

    /**wait until program or data flash X is unbusy  **/
    if((addr>=PFLASH0_START_ADDR)&&(addr<=PFLASH0_END_ADDR))
    {
        /**wait until program or data flash X is unbusy  **/
        g_commandFromPSPR.waitUnbusy(PFLASH_0, IfxFlash_FlashType_P0);
    }
    else if((addr>=PFLASH1_START_ADDR)&&(addr<=PFLASH1_END_ADDR))
    {
        g_commandFromPSPR.waitUnbusy(PFLASH_1, IfxFlash_FlashType_P1);
    }

    /**Step1:Enter Page Mode  **/
    /**Performs the sequence for entering program page mode  **/
    g_commandFromPSPR.enterPageMode(addr);

	WaitInnerCount = 0U;

	while((DMU_HF_STATUS.B.PFPAGE != 1U) &&\
	        ((DMU_HF_ERRSR.B.SQER != 1U) && (DMU_HF_ERRSR.B.PROER != 1U)))
	{
		//WaitInnerCount++;
	}

	if(WaitInnerCount >= 10000u)//1000 TBD;
	{
		//return FALSE;
	}


    /**Step2:Wait until page mode is entered  **/
    /**wait until program or data flash X is unbusy  **/
    if((addr>=PFLASH0_START_ADDR)&&(addr<=PFLASH0_END_ADDR))
    {
        /**wait until program or data flash X is unbusy  **/
        g_commandFromPSPR.waitUnbusy(PFLASH_0, IfxFlash_FlashType_P0);
    }
    else if((addr>=PFLASH1_START_ADDR)&&(addr<=PFLASH1_END_ADDR))
    {
        g_commandFromPSPR.waitUnbusy(PFLASH_1, IfxFlash_FlashType_P1);
    }

    /**Step3:Load data to be written in the page
     * Fast programming of 32 byte pages for PFLASH  **/
    for(uint8 i=0; i<4; i++)
    {
        wordL = 0;
        wordU = 0;
        j = (i*2) * 4;
        k = (i*2+1) * 4;
        wordL = ((uint32)p_data[j+3]<<24) | ((uint32)p_data[j+2]<<16) | ((uint32)p_data[j+1]<<8) | (uint32)p_data[j];
        wordU = ((uint32)p_data[k+3]<<24) | ((uint32)p_data[k+2]<<16) | ((uint32)p_data[k+1]<<8) | (uint32)p_data[k];
        /**performs a load page sequence with two 32bit accesses,load 2*32bit into assembly buffer of data flash  **/
        g_commandFromPSPR.load2X32bits(addr,wordL,wordU);
    }
        /**wait until program or data flash X is unbusy  **/
    if((addr>=PFLASH0_START_ADDR)&&(addr<=PFLASH0_END_ADDR))
    {
        /**wait until program or data flash X is unbusy  **/
        g_commandFromPSPR.waitUnbusy(PFLASH_0, IfxFlash_FlashType_P0);
    }
    else if((addr>=PFLASH1_START_ADDR)&&(addr<=PFLASH1_END_ADDR))
    {
        g_commandFromPSPR.waitUnbusy(PFLASH_1, IfxFlash_FlashType_P1);
    }

    /**Step4:Write the loaded page  **/
    /**get the current password of Safety Watchdog module.  **/
    uint16 endInitSafetyPassword = Ifx_Ssw_getSafetyWatchdogPasswordInline();
    /** disable ENDINIT functionality provided by Safety WDT Hardware module  **/
    Ifx_Ssw_clearSafetyEndinitInline(endInitSafetyPassword); 
    /**Performs the "Write Page" sequence.  **/
    g_commandFromPSPR.writePage(addr);
    /**enable ENDINIT functionality provided by Safety WDT Hardware module  **/
    Ifx_Ssw_setSafetyEndinitInline(endInitSafetyPassword);


	WaitInnerCount = 0U;

    while((DMU_HF_OPERATION.B.PROG != 1U) &&    \
          ((DMU_HF_ERRSR.B.SQER != 1U) && (DMU_HF_ERRSR.B.PROER != 1U)))
    {
        //WaitInnerCount++;
    }

	if(WaitInnerCount >= 10000u)//1000 TBD;
	{
		//return FALSE;
	}

	 //8*1/fSRI ns (PFlash), fSRI = 3M hz ,main clock is 300m;
	for(delaycnt= 0;delaycnt <= 1000u;delaycnt++)
	{
		__asm("nop");
	}

    /**Step5:wait until the sector is erased  **/
    if((addr>=PFLASH0_START_ADDR)&&(addr<=PFLASH0_END_ADDR))
    {
        /**wait until program or data flash X is unbusy  **/
        g_commandFromPSPR.waitUnbusy(PFLASH_0, IfxFlash_FlashType_P0);
    }
    else if((addr>=PFLASH1_START_ADDR)&&(addr<=PFLASH1_END_ADDR))
    {
        g_commandFromPSPR.waitUnbusy(PFLASH_1, IfxFlash_FlashType_P1);
    }

    writeEndAddr = addr + 32;
    return writeEndAddr;
}
#pragma section code restore 
/*******************************************************************************
** Syntax          : uint8 PFlashDriver_pflashReadDataFromPflash(uint32 addr, uint8 *p_data, uint16 len)					                                         
**                                                                              
** Description     : Read the data from the PFlash                                                           
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : addr - The start address of the raed data  
**                   p_data - the buffer of saving the read data
**                   len - the length of the read data                                                     
**                                                                              
** Parameters (out): Return the result of the read data operation                                                       
**                                                                              
** Return value    : TRUE - Read data successed
**                   FALSE - Read data failed                                                       
**                                                                              
*******************************************************************************/
#pragma  section code  "FLASHDRVCODE"
uint8 PFlashDriver_pflashReadDataFromPflash(uint32 addr, uint8 *p_data, uint16 len)
{
    uint32 data = 0;
    /**Read data is not allowed in the following cases:
     * the source access address is not in the DFlash address range
     * the target address is NULL
     * the length of data is 0 **/
    if(((addr>=PFLASH0_START_ADDR)&&((addr+len-1)<=PFLASH0_END_ADDR))||\
       ((addr>=PFLASH1_START_ADDR)&&((addr+len-1)<=PFLASH1_END_ADDR)))
    {
        if((p_data==NULL)||(len==0))
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    while(len)
    {
        data = *(uint32*)addr;
        if(len>=4)
        {
            *p_data++ = (uint8)((data)&0xFF);
            *p_data++ = (uint8)((data>>8)&0xFF);
            *p_data++ = (uint8)((data>>16)&0xFF);
            *p_data++ = (uint8)((data>>24)&0xFF);
            len -= 4;
            addr += 4;
        }
        else
        {
            for(;len>0;len--)
            {
                *p_data++ = (uint8)((data>>(len*8))&0xFF);
            }
        }
    }
    return TRUE;
}
#pragma section code restore 
/*******************************************************************************
** Syntax          : uint8 PFlashDriver_pflashWriteDataIntoPflash(uint32 addr, uint8 *p_data, uint16 len)					                                         
**                                                                              
** Description     : Write data into the PFlash                                                           
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : addr - The start address of the write data  
**                   p_data - the buffer of write the read data
**                   len - the length of the write data                                                       
**                                                                              
** Parameters (out): Return the result of the write data operation                                                       
**                                                                              
** Return value    : TRUE - write data successed
**                   FALSE - write data failed                                                        
**                                                                              
*******************************************************************************/
#pragma  section code  "FLASHDRVCODE"
uint8 PFlashDriver_pflashWriteDataIntoPflash(uint32 addr, uint8 *p_data, uint32 len)
{
    uint32 i;
    uint32 offsetPageNumber;
    uint32 offsetAddr;
    uint32 startPageAddr;
    uint32 writePageAddr;
    uint8 pageBackup[32];
    uint8 dflashReadDataStatus;

    i = 0;
    offsetPageNumber = 0;
    offsetAddr = 0;
    startPageAddr = 0;
    writePageAddr = 0;
    dflashReadDataStatus = 0;
    offsetPageNumber = 0;

    /**Step1:Determine the function parameters.
     * Write data is not allowed in the following cases:
     * the source access address is not in the DFlash address range
     * the target address is NULL
     * the length of data is 0 **/
    if(((addr>=PFLASH0_START_ADDR)&&((addr+len-1)<=PFLASH0_END_ADDR))||\
       ((addr>=PFLASH1_START_ADDR)&&((addr+len-1)<=PFLASH1_END_ADDR)))
    {
        if((p_data==NULL)||(len==0))
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    /**Get the start address of the page programing  **/
    startPageAddr = addr - ((addr&0xFFFFFF)%32);
    /**The offset of the page written address relative to the start address of the sector  **/
    offsetAddr = addr - startPageAddr;

    /**Step2:Write data into PFlash which includes two case  **/
    /**Case 1: offsetAddr+len <=8 **/
    if((offsetAddr+len)<=32)
    {
        writePageAddr = startPageAddr;

        for(uint8 j=0;j<32;j++)
        {
            pageBackup[j] = 0x00;
        }
        
        for(;len>0;len--)
        {
            pageBackup[offsetAddr++] = *(uint8*)p_data++;
        }
        g_commandFromPSPR.programPage(writePageAddr,pageBackup);
    }
    /**Case 2: offsetAddr+len > 8 **/
    else
    {
        /**Get the offset page number which need to be written **/
        if((len+offsetAddr)%32)
        {
            offsetPageNumber = ((len+offsetAddr)/32) + 1;
        }
        else
        {
            offsetPageNumber = (len+offsetAddr) / 32;
        }

        for(uint16 page=0;page<offsetPageNumber;page++)
        {
            writePageAddr = startPageAddr + (uint32)(page*32);
            
            for(uint8 j=0;j<32;j++)
            {
                pageBackup[j] = 0x00;
            }
            
            if(page==0)
            {
                
                for(i=offsetAddr;i<32;i++)
                {
                    pageBackup[i] = *(uint8*)p_data++;
                    len--;
                }
            }
            else if((page==(offsetPageNumber-1))&&((len<32)))
            {
                for(i=0;len>0;)
                {
                    pageBackup[i++] = *(uint8*)p_data++;
                    len--;
                }
            }
            else
            {
                for(i=0;i<32;i++)
                {
                    pageBackup[i] = *(uint8*)p_data++;
                    len--;
                }
            }
            g_commandFromPSPR.programPage(writePageAddr,pageBackup);
        } 
    }
    return TRUE;
}
#pragma section code restore 
/*******************************************************************************
** Syntax          : uint8 PFlashDriver_pflashCheckWriteData(uint32 addr, uint8 *p_data)					                                         
**                                                                              
** Description     : Check whether the data of Written into the PFlash pge is correct.                                                           
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) : addr - The start address of the PFlash page
**                   p_data - the data of written into the PFlash page                                                       
**                                                                              
** Parameters (out): Return the result of the Check operation                                                       
**                                                                              
** Return value    : TRUE - Check correct
**                   FALSE - Check error                                                       
**                                                                              
*******************************************************************************/
uint8 PFlashDriver_pflashCheckWriteData(uint32 addr, uint8 *p_data)
{
    uint8 pageBackup[32]; 
    uint8 dflashReadDataStatus;
    dflashReadDataStatus = FALSE;

    dflashReadDataStatus = g_commandFromPSPR.readFlash(addr,pageBackup,32);
    if(dflashReadDataStatus==FALSE)
    {
        return FALSE;
    }

    for(uint8 i=0;i<32;i++)
    {
        if(pageBackup[i]!=*(uint8*)p_data)
        {
            return FALSE;
        }
        p_data++;
    }
    return TRUE;
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
uint32 PFlashDriver_pflashCrcCcitt1021(uint32 initCrcValue,uint32 address,uint32 len) 
{
    uint8 crc_H8 = 0,index = 0;
	uint32 crc = 0;
	uint32 *ptr = NULL;

	crc=initCrcValue;
	ptr=(uint32 *)address; 

	while(len)
	{
		crc_H8 = (unsigned char)(crc >> 8);
		crc = crc << 8;
        if(len<4)
        {
            switch(len)
            {
                case 1:
                    index = (uint8)(crc_H8 ^ (*ptr&0x000000FF));
                    break;
                case 2:
                    index = (uint8)(crc_H8 ^ (*ptr&0x0000FFFF));
                    break;
                case 3:
                    index = (uint8)(crc_H8 ^ (*ptr&0x00FFFFFF));
                    break;
            }
        }
        else
        {
            index = (uint8)(crc_H8 ^ *ptr);
        }
        
 
        switch(len)
        {
            case 1:
            case 2:
            case 3:
            case 4:
                len = 0;
                break;
            default:
                ptr++;
                len -= 4;
                break;
        }
		crc = crc ^ crc_1021_table[index];
	}

	return(crc);                              
}
