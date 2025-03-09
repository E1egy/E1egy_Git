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
#include "DFlashDriver.h"
#include "IfxFlash.h"
#include "IfxFlash_cfg.h"
#include "include_config.h"
#include "Ifx_Ssw_Infra.h"
#include "IfxScu_reg.h"
#include "IfxScu_regdef.h"
/***************************************Macros****************************************/

/***************************************Variables***********************************/
const uint8 DCM_Block_ROM_Buf[DFLASH_DCM_ALL_LENGTH] = 
{
    /*F184 HEAD*/
    0xF1, 0x84, 
    /*F184 DATA*/
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    /*F184 PADDING*/
    0x00, 0x00,  0x00, 0x00,  0x00, 0x00,  0x00, 0x00,  0x00, 
    /*F184 CheckSum*/
    0x75, 0x01, 

    /*F0F1 HEAD*/
    0xF0, 0xF1, 
    /*F0F1 DATA*/
    0x00, 0x00, 0x00, 0x00, 
    /*F0F1 PADDING*/
    0x00, 0x00,  0x00, 0x00,  0x00, 0x00,  0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    /*F0F1 CheckSum*/
    0xE1, 0x01, 

    /*F0F3 HEAD*/
    0xF0, 0xF3, 
    /*F0F3 DATA*/
    0x00, 0x00, 0x00, 0x00, 
    /*F0F3 PADDING*/
    0x00, 0x00,  0x00, 0x00,  0x00, 0x00,  0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    /*F0F3 CheckSum*/
    0xE3, 0x01, 

    /*F162 HEAD*/
    0xF1, 0x62, 
    /*F162 DATA*/
    0x01, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    /*F162 PADDING*/
    0x00, 
    /*F162 CheckSum*/
    0x08, 0x0F, 
};

uint8 DCM_Block_RAM_Buf[DFLASH_DCM_ALL_LENGTH] = {0};
uint8 DCM_Block_RAM_Read_Buf[DFLASH_DCM_ALL_LENGTH] = {0};

/***************************************Functions***********************************/


/*******************************************************************************
** Syntax          : void DFlashDriver_ClearProgFlag(void)					                                         
**                                                                              
** Description     :                                 
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) :                                   
**                                                                              
** Parameters (out):                        
**                                                                              
** Return value    : 
**                                   
**                                                                              
*******************************************************************************/
void DFlashDriver_ClearProgFlag(void)
{
    uint32 page;                                                /* Variable to cycle over all the pages             */

    boolean interruptState;	
    interruptState = IfxCpu_disableInterrupts(); /* Get the current state of the interrupts and disable them*/

    /* --------------- ERASE PROCESS --------------- */
    /* Get the current password of the Safety WatchDog module */
    uint16 endInitSafetyPassword = Ifx_Ssw_getSafetyWatchdogPassword();//IfxScuWdt_getSafetyWatchdogPasswordInline();

    /* Erase the sector */
    Ifx_Ssw_clearSafetyEndinit(endInitSafetyPassword);//IfxScuWdt_clearSafetyEndinit(endInitSafetyPassword);        /* Disable EndInit protection                       */
    DFlashDriver_IfxFlash_eraseMultipleSectors(DFLASH_PROG_FLAG_ADDR, 1); /* Erase the given sector           */
    Ifx_Ssw_setSafetyEndinit(endInitSafetyPassword);//IfxScuWdt_setSafetyEndinit(endInitSafetyPassword);          /* Enable EndInit protection                        */

    /* Wait until the sector is erased */
    DFlashDriver_IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);

    /* --------------- WRITE PROCESS --------------- */
    //for(page = 0; page < DFLASH_NUM_PAGE_TO_FLASH; page++)      /* Loop over all the pages                          */
    {
        uint32 pageAddr = DFLASH_PROG_FLAG_ADDR ; /* Get the address of the page     */

        /* Enter in page mode */
        DFlashDriver_IfxFlash_enterPageMode(pageAddr);

        /* Wait until page mode is entered */
        DFlashDriver_IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);

        /* Load data to be written in the page */
        DFlashDriver_IfxFlash_loadPage2X32(pageAddr, 0x00000000, 0x00000000); /* Load two words of 32 bits each            */

        /* Write the loaded page */
        Ifx_Ssw_clearSafetyEndinit(endInitSafetyPassword);//IfxScuWdt_clearSafetyEndinit(endInitSafetyPassword);    /* Disable EndInit protection                       */
        DFlashDriver_IfxFlash_writePage(pageAddr);                           /* Write the page                                   */
        Ifx_Ssw_setSafetyEndinit(endInitSafetyPassword);//IfxScuWdt_setSafetyEndinit(endInitSafetyPassword);      /* Enable EndInit protection                        */

        /* Wait until the data is written in the Data Flash memory */
        DFlashDriver_IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);
    }

    IfxCpu_restoreInterrupts(interruptState);			/* Restore the interrupts state 	 */


}

void DFlashDriver_SetProgFlag(uint32 ProgFlag, uint32 ResponseFlag)
{
    uint32 page;                                                /* Variable to cycle over all the pages             */

    /* --------------- ERASE PROCESS --------------- */
    /* Get the current password of the Safety WatchDog module */
    uint16 endInitSafetyPassword = Ifx_Ssw_getSafetyWatchdogPassword();//IfxScuWdt_getSafetyWatchdogPasswordInline();

    /* Erase the sector */
    Ifx_Ssw_clearSafetyEndinit(endInitSafetyPassword);//IfxScuWdt_clearSafetyEndinit(endInitSafetyPassword);        /* Disable EndInit protection                       */
    DFlashDriver_IfxFlash_eraseMultipleSectors(0xAF03F000, 1); /* Erase the given sector           */
    Ifx_Ssw_setSafetyEndinit(endInitSafetyPassword);//IfxScuWdt_setSafetyEndinit(endInitSafetyPassword);          /* Enable EndInit protection                        */

    /* Wait until the sector is erased */
    DFlashDriver_IfxFlash_waitUnbusy(0, 0);

    /* --------------- WRITE PROCESS --------------- */
    //for(page = 0; page < DFLASH_NUM_PAGE_TO_FLASH; page++)      /* Loop over all the pages                          */
    {
        uint32 pageAddr = 0xAF03F000 ; /* Get the address of the page     */

        /* Enter in page mode */
        DFlashDriver_IfxFlash_enterPageMode(pageAddr);

        /* Wait until page mode is entered */
        DFlashDriver_IfxFlash_waitUnbusy(0, 0);

        /* Load data to be written in the page */
        DFlashDriver_IfxFlash_loadPage2X32(pageAddr, ProgFlag, ResponseFlag); /* Load two words of 32 bits each            */

        /* Write the loaded page */
        Ifx_Ssw_clearSafetyEndinit(endInitSafetyPassword);//IfxScuWdt_clearSafetyEndinit(endInitSafetyPassword);    /* Disable EndInit protection                       */
        DFlashDriver_IfxFlash_writePage(pageAddr);                           /* Write the page                                   */
        Ifx_Ssw_setSafetyEndinit(endInitSafetyPassword);//IfxScuWdt_setSafetyEndinit(endInitSafetyPassword);      /* Enable EndInit protection                        */

        /* Wait until the data is written in the Data Flash memory */
        DFlashDriver_IfxFlash_waitUnbusy(0, 0);
    }
}
/*******************************************************************************
** Syntax          : void DFlashDriver_ReadDID_F184(void)					                                         
**                                                                              
** Description     :                                 
**                                                                              
** Sync/Async      : Synchronous                                                
**                                                                              
** Reentrancy      : Non Reentrant                                              
**                                                                              
** Parameters (in) :                                   
**                                                                              
** Parameters (out):                        
**                                                                              
** Return value    : 
**                                   
**                                                                              
*******************************************************************************/
void DFlashDriver_ReadDID_F184(void)
{
    boolean interruptState;	
    interruptState = IfxCpu_disableInterrupts(); /* Get the current state of the interrupts and disable them*/

    IfxCpu_restoreInterrupts(interruptState);			/* Restore the interrupts state 	 */
}

void DFlashDriver_ReadDID_F0F1(void)
{

}

void DFlashDriver_ReadDID_F0F3(void)
{

}

uint8 DFlashDriver_ReadDcmBlock(void)
{
    uint8 Err = 0; /*bit0:EmptyErr bit1:F184Err bit2:F0F1Err bit3:F0F3Err*/
    uint16 i = 0;
    uint32 pageAddr;
    uint8 * addr = NULL;
    static uint16 ReadCheckSum = 0;
    uint16 CalcCheckSum = 0;
    IfxCpu_disableInterrupts();
    /* wait flash ready */
    DFlashDriver_IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);
    /* check empty */
    pageAddr =  DFLASH_DCM_BLOCK_ADDR;
    IfxFlash_verifyErasedWordLine(pageAddr); /*DFLASH: 512 bytes in single ended mode and 256 bytes in complement sensing mode.*/
    /* wait flash ready */
    DFlashDriver_IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);
    /*Not empty */
    if(DMU_HF_ERRSR.B.EVER== 1)
    {
        /* read addr */
        addr = DFLASH_DCM_BLOCK_ADDR;
        for(i = 0; i < DFLASH_DCM_ALL_LENGTH ;i++)
        {
            DCM_Block_RAM_Read_Buf[i] = *addr;
            addr++;
        }
        /* clear */
        DMU_HF_CLRE.B.CEVER = 1;
        Err = 0;
    }
    else     
    {
        /*Use Default Value*/
        for(i = 0; i < DFLASH_DCM_ALL_LENGTH ;i++)
        {
            DCM_Block_RAM_Buf[i] = DCM_Block_ROM_Buf[i];
        }
        Err = 1; /*empty */
    }
    IfxCpu_enableInterrupts();

    /*Check F184*/
    if(Err == 0)
    {
        
        CalcCheckSum = 0;
        for(i = 0; i < 30; i++)
        {
            CalcCheckSum = CalcCheckSum + DCM_Block_RAM_Read_Buf[DFLASH_DCM_F184_OFFSET+i];
        }

        ReadCheckSum = (uint16)((uint16)DCM_Block_RAM_Read_Buf[DFLASH_DCM_F184_OFFSET+30] + (((uint16)DCM_Block_RAM_Read_Buf[DFLASH_DCM_F184_OFFSET+31]) << 8));
        if((DCM_Block_RAM_Read_Buf[DFLASH_DCM_F184_OFFSET] == 0xF1) &&
            (DCM_Block_RAM_Read_Buf[DFLASH_DCM_F184_OFFSET+1] == 0x84) &&
            (CalcCheckSum == ReadCheckSum))
        {
            for(i = 0; i < 32 ;i++)
            {
                DCM_Block_RAM_Buf[DFLASH_DCM_F184_OFFSET + i] = DCM_Block_RAM_Read_Buf[DFLASH_DCM_F184_OFFSET + i];
            }
        }
        else
        {
            /*Use Default Value*/
            for(i = 0; i < 32 ;i++)
            {
                DCM_Block_RAM_Buf[DFLASH_DCM_F184_OFFSET + i] = DCM_Block_ROM_Buf[DFLASH_DCM_F184_OFFSET + i];
            }
            Err = Err | 0x02; /*F184 Error*/
        }
        /*Check F0F1*/
        CalcCheckSum = 0;
        for(i = 0; i < 30; i++)
        {
            CalcCheckSum = CalcCheckSum + DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F1_OFFSET+i];
        }

        ReadCheckSum = (uint16)((uint16)DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F1_OFFSET+30] + (((uint16)DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F1_OFFSET+31]) << 8));
        if((DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F1_OFFSET] == 0xF0) &&
            (DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F1_OFFSET+1] == 0xF1) &&
            (CalcCheckSum == ReadCheckSum))
        {
            for(i = 0; i < 32 ;i++)
            {
                DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET + i] = DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F1_OFFSET + i];
            }
        }
        else
        {

            /*Use Default Value*/
            for(i = 0; i < 32 ;i++)
            {
                DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET + i] = DCM_Block_ROM_Buf[DFLASH_DCM_F0F1_OFFSET + i];
            }
            Err = Err | 0x04; /*F0F1 Error*/
        }

        /*Check F0F3*/
        CalcCheckSum = 0;
        for(i = 0; i < 30; i++)
        {
            CalcCheckSum = CalcCheckSum + DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F3_OFFSET+i];
        }

        ReadCheckSum = (uint16)((uint16)DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F3_OFFSET+30] + (((uint16)DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F3_OFFSET+31]) << 8));
        if((DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F3_OFFSET] == 0xF0) &&
            (DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F3_OFFSET+1] == 0xF3) &&
            (CalcCheckSum == ReadCheckSum))
        {
            for(i = 0; i < 32 ;i++)
            {
                DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET + i] = DCM_Block_RAM_Read_Buf[DFLASH_DCM_F0F3_OFFSET + i];
            }
        }
        else
        {
            /*Use Default Value*/
            for(i = 0; i < 32 ;i++)
            {
                DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET + i] = DCM_Block_ROM_Buf[DFLASH_DCM_F0F3_OFFSET + i];
            }
            Err = Err | 0x08; /*F0F3 Error*/
        }

        /*Check F162*/
        CalcCheckSum = 0;
        for(i = 0; i < 38; i++)
        {
            CalcCheckSum = CalcCheckSum + DCM_Block_RAM_Read_Buf[DFLASH_DCM_F162_OFFSET+i];
        }

        ReadCheckSum = (uint16)((uint16)DCM_Block_RAM_Read_Buf[DFLASH_DCM_F162_OFFSET+38] + (((uint16)DCM_Block_RAM_Read_Buf[DFLASH_DCM_F162_OFFSET+39]) << 8));
        if((DCM_Block_RAM_Read_Buf[DFLASH_DCM_F162_OFFSET] == 0xF1) &&
            (DCM_Block_RAM_Read_Buf[DFLASH_DCM_F162_OFFSET+1] == 0x62) &&
            (CalcCheckSum == ReadCheckSum))
        {
            for(i = 0; i < 40 ;i++)
            {
                DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET + i] = DCM_Block_RAM_Read_Buf[DFLASH_DCM_F162_OFFSET + i];
            }
        }
        else
        {
            /*Use Default Value*/
            for(i = 0; i < 40 ;i++)
            {
                DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET + i] = DCM_Block_ROM_Buf[DFLASH_DCM_F162_OFFSET + i];
            }
            Err = Err | 0x10; /*F162 Error*/
        }

    }

    return Err;
}

void DFlashDriver_WriteDcmBlock(void)
{
    uint32 page;                                /* Variable to cycle over all the pages             */
    boolean interruptState;	
    uint32 wordL;
    uint32 wordU;

    interruptState = IfxCpu_disableInterrupts(); /* Get the current state of the interrupts and disable them*/
                        
    /* --------------- ERASE PROCESS --------------- */
    /* Get the current password of the Safety WatchDog module */
    uint16 endInitSafetyPassword = Ifx_Ssw_getSafetyWatchdogPassword();
    /* Erase the sector */
    Ifx_Ssw_clearSafetyEndinit(endInitSafetyPassword);        /* Disable EndInit protection                       */
    DFlashDriver_IfxFlash_eraseMultipleSectors(DFLASH_DCM_BLOCK_ADDR, 1); /* Erase the given sector           */
    Ifx_Ssw_setSafetyEndinit(endInitSafetyPassword);          /* Enable EndInit protection                        */

    /* Wait until the sector is erased */
    DFlashDriver_IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);
    /* --------------- WRITE PROCESS --------------- */
    for(page = 0; page < DFLASH_DCM_PAGE_NUM; page++)      /* Loop over all the pages                          */
    {
        uint32 pageAddr = DFLASH_DCM_BLOCK_ADDR + (page * IFXFLASH_DFLASH_PAGE_LENGTH); /* Get the address of the page     */

        /* Enter in page mode */
        DFlashDriver_IfxFlash_enterPageMode(pageAddr);

        /* Wait until page mode is entered */
        DFlashDriver_IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);

        wordL = *(uint32 *)&DCM_Block_RAM_Buf[(0+(page * IFXFLASH_DFLASH_PAGE_LENGTH))];
        wordU = *(uint32 *)&DCM_Block_RAM_Buf[(4+(page * IFXFLASH_DFLASH_PAGE_LENGTH))];
        /* Load data to be written in the page */
        DFlashDriver_IfxFlash_loadPage2X32(pageAddr, wordL, wordU); /* Load two words of 32 bits each            */

        /* Write the loaded page */
        Ifx_Ssw_clearSafetyEndinit(endInitSafetyPassword);    /* Disable EndInit protection                       */
        DFlashDriver_IfxFlash_writePage(pageAddr);            /* Write the page                                   */
        Ifx_Ssw_setSafetyEndinit(endInitSafetyPassword);      /* Enable EndInit protection                        */

        /* Wait until the data is written in the Data Flash memory */
        DFlashDriver_IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);
    }

    IfxCpu_restoreInterrupts(interruptState);			/* Restore the interrupts state 	 */
}

void DFlashDriver_WriteDID_F184(uint8 * DidData)
{
    uint8 i;
    uint8 * F184Data;
    uint16 CheckSum;
    F184Data = DidData;
    DCM_Block_RAM_Buf[DFLASH_DCM_F184_OFFSET] = 0xF1;
    DCM_Block_RAM_Buf[DFLASH_DCM_F184_OFFSET+1] = 0x84;

    for(i = 2; i < 21; i++)
    {
        DCM_Block_RAM_Buf[DFLASH_DCM_F184_OFFSET+i] = *F184Data;
        F184Data++;
    }

    for(i = 21; i < 30; i++)
    {
        DCM_Block_RAM_Buf[DFLASH_DCM_F184_OFFSET+i] = 0x00;
    }

    CheckSum = 0;
    for(i = 0; i < 30; i++)
    {
        CheckSum = CheckSum + DCM_Block_RAM_Buf[DFLASH_DCM_F184_OFFSET+i];
    }

    DCM_Block_RAM_Buf[DFLASH_DCM_F184_OFFSET+30] = (uint8)(CheckSum & 0x00FF);
    DCM_Block_RAM_Buf[DFLASH_DCM_F184_OFFSET+31] = (uint8)((CheckSum >> 8) & 0x00FF);

    //DFlashDriver_WriteDcmBlock();
}

void DFlashDriver_WriteDID_F162(uint8 * DidData)
{
    uint8 i;
    uint8 * F162Data;
    uint16 CheckSum;
    F162Data = DidData;
    DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET] = 0xF1;
    DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET+1] = 0x62;
    DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET+2] = 0x01; //Number of applications
    DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET+3] = 0x01; //Application number #1
    DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET+4] = 0x20; //Application Number #1 hash length
    for(i = 5; i < 37; i++)
    {
        DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET+i] = *F162Data;
        F162Data++;
    }

    for(i = 37; i < 38; i++)
    {
        DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET+i] = 0x00;
    }

    CheckSum = 0;
    for(i = 0; i < 38; i++)
    {
        CheckSum = CheckSum + DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET+i];
    }

    DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET+38] = (uint8)(CheckSum & 0x00FF);
    DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET+39] = (uint8)((CheckSum >> 8) & 0x00FF);

    DFlashDriver_WriteDcmBlock();
}

void DFlashDriver_WriteDID_F0F1(uint8 * DidData)
{
    uint8 i;
    uint8 * F0F1Data;
    uint16 CheckSum;
    F0F1Data = DidData;
    DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET] = 0xF0;
    DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET+1] = 0xF1;

    for(i = 2; i < 6; i++)
    {
        DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET+i] = *F0F1Data;
        F0F1Data++;
    }

    for(i = 6; i < 30; i++)
    {
        DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET+i] = 0x00;
    }

    CheckSum = 0;
    for(i = 0; i < 30; i++)
    {
        CheckSum = CheckSum + DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET+i];
    }

    DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET+30] = (uint8)(CheckSum & 0x00FF);
    DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET+31] = (uint8)((CheckSum >> 8) & 0x00FF);
    //DFlashDriver_WriteDcmBlock();
}

void DFlashDriver_WriteDID_F0F3(uint8 * DidData)
{
    uint8 i;
    uint8 * F0F3Data;
    uint16 CheckSum;
    F0F3Data = DidData;
    DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET] = 0xF0;
    DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET+1] = 0xF3;

    for(i = 2; i < 6; i++)
    {
        DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET+i] = *F0F3Data;
        F0F3Data++;
    }

    for(i = 6; i < 30; i++)
    {
        DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET+i] = 0x00;
    }

    CheckSum = 0;
    for(i = 0; i < 30; i++)
    {
        CheckSum = CheckSum + DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET+i];
    }

    DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET+30] = (uint8)(CheckSum & 0x00FF);
    DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET+31] = (uint8)((CheckSum >> 8) & 0x00FF);
    //DFlashDriver_WriteDcmBlock();
}
