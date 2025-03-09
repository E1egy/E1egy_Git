/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dcm_Callout.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-01-26 15:23:04>
 */
/*============================================================================*/

#include "Dcm_Internal.h"
#include "UDS.h"
#include "Fls_17_Dmu.h"
#include "DcmDsl_MsgManage.h"
#include "Dcm_CalloutBoot.h"
#include "PFlashDriver.h"
#include "IfxFlash.h"
#include "Os.h"
#include "FlsLoader.h"
#include "Ifx_reg.h"
#if (DCM_TM == STD_ON)
#include "Tm.h"
#endif /* (DCM_TM == STD_ON) */

/* Remained Download Length for 0x34, 0x36, 0x37 */
#define DCM_START_SEC_VAR_NOINIT_32
#include "Dcm_MemMap.h"
uint32 DcmDownloadSizeRemain;
uint32 DcmLastDownloadSize;
volatile uint32 Test_MemoryAddress;
volatile uint32 Test_MemorySize;
uint32 HashSize;
uint32 HashAddr;
uint32 HashHeadSize;
uint32 HashHeadAddr;
uint32 Dcm_36_Processing;/*0:IDLE 1:Processing*/
extern boolean b_0203_ConditionOk;
#define  DCM_STOP_SEC_VAR_NOINIT_32
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern boolean AppValid;
extern boolean  DD01StayInBoot;
void DcmDspSessionCallback(Dcm_SesCtrlType formerState, Dcm_SesCtrlType newState)
{

    if((newState == DCM_DEFAULT_SESSION) && ((formerState == DCM_PROGRAMMING_SESSION) || (formerState == DCM_EXTENDED_DIAGNOSTIC_SESSION)))
    {
        if(TRUE == AppValid)
        {
            Mcu_PerformReset();
            while(1);
        }
        else
        {
            /*Do nothing*/
        }
    }

    if((newState == DCM_DEFAULT_SESSION) && (formerState == DCM_DEFAULT_SESSION))
    {
        if(TRUE == DD01StayInBoot)/*DD01 Start S3*/
        {
            if(TRUE == AppValid)
            {
                Mcu_PerformReset();
                while(1);
            }
            else
            {
                /*Do nothing*/
            }
        }
        else
        {
            /*Do nothing*/
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/* BL_AppFlagType* BL_AppFlag = (BL_AppFlagType*) BL_APP_FLAG_ADDRESS; */

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Dcm_SetProgConditions(
Dcm_OpStatusType OpStatus,
Dcm_ProgConditionsType * ProgConditions
)
{
    /*TODO: Set ReProgramingRequest Flag*/
    /*e.g*/
    /*    BL_AppFlag->FlBootMode = (uint32)FL_EXT_PROG_REQUEST_RECEIVED;
    BL_AppFlag->Busmode = BUS_MODE_ETH;*/
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern boolean AppReqProg;
Dcm_EcuStartModeType Dcm_GetProgConditions(
Dcm_ProgConditionsType * ProgConditions
)
{
    Dcm_EcuStartModeType  StartMode = DCM_COLD_START;
    /*TODO: check ApplUpdated*/
    /*e.g*/
    /*    if (BL_AppFlag->FlApplUpdate == (uint32)FL_APPL_UPDATED)
    {
        ProgConditions->ApplUpdated = TRUE;
        BL_AppFlag->FlApplUpdate = (uint32)0;
        return DCM_WARM_START;
    }*/
    if(TRUE == AppReqProg)
    {
        StartMode = DCM_WARM_START;
    }
    else
    {
        StartMode = DCM_COLD_START;
    }

    return StartMode;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*for 0x23 service to read data by memory address*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Dcm_ReturnReadMemoryType Dcm_ReadMemory(Dcm_OpStatusType OpStatus,
        uint8 MemoryIdentifier,
        uint32 MemoryAddress,
        uint32* MemorySize,
        uint8* MemoryData,
        Dcm_NegativeResponseCodeType* ErrorCode)
{
    return DCM_READ_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*for 0x3D service to write data by memory address*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

uint8 Dcm_memoryTypeCheck(uint32 addr, uint32 size)
{
  uint8 memoryType = MEMORY_TYPE_NULL;

  uint32 endAddr = ((addr + size) - 1u);

  if (addr <= endAddr)
  {
    if ((addr >= FLASHDRV_START_ADDR) && (endAddr <= FLASHDRV_END_ADDR))
    {
      memoryType = MEMORY_TYPE_RAM;
    }
    else if ((addr >= FLASH_BANK_A_START_ADDR) && (endAddr <= FLASH_BANK_A_END_ADDR))
    {
        memoryType = MEMORY_TYPE_FLASH_BANK_A;
    }
    else if ((addr >= FLASH_BANK_B_START_ADDR) && (endAddr <= FLASH_BANK_B_END_ADDR))
    {
        memoryType = MEMORY_TYPE_FLASH_BANK_B;
    }
    else
    {
        memoryType = MEMORY_TYPE_NULL;
    }
  }
  return (memoryType);
}
uint32 Dcm_memcmp(void *str1, void *str2, size_t count) 
{
    uint32 Rte = 0;
	char *pstr1 = (char*)str1;
	char *pstr2 = (char*)str2;
	
	while (count--) 
    {
	    if (*pstr1 == *pstr2)
        {
		    continue;
	    } 
        else 
        {
            Rte = 1;
		    break;
	    }
	}
	return Rte;
}

extern void OUtData(uint8 errId,uint32 adress);
Dcm_ReturnWriteMemoryType Dcm_WriteMemory(Dcm_OpStatusType OpStatus,
                                            uint8 MemoryIdentifier,
                                            uint32 MemoryAddress,
                                            uint32 MemorySize,
                                            uint8* MemoryData,
                                            Dcm_NegativeResponseCodeType* ErrorCode)
{
    Dcm_ReturnWriteMemoryType ret = DCM_WRITE_FAILED;
    boolean sameBlockId = FALSE;
    uint8 tempBlockId;
    FlsLoader_ReturnType  FlsLoaderResult;
    uint8 BeadBackResult;
    uint8 MemoryType;
    MemIf_StatusType FlashStatus = MEMIF_IDLE;
    StatusType AlarmStatus = E_OK;
    TickType Tick = 0;
    uint32 EccSt = 0;
    uint32 MemoryReadAddress;
    uint8 Bank_ID = 0;

	/* Bank_ID:
    SWAP configuration
    00B no SWAP configured by SSW (full PFlash address space active with the default map)
    01B SWAP A configured (PFlash Bank A active, B inactive)
    10B SWAP B configured (PFlash Bank B active, A inactive)
    11Breserved
    */
	Bank_ID = ((SCU_STMEM1.U & 0x00030000) >> 16u);
    
    if(OpStatus != DCM_FORCE_RCRRP_OK)
    {
        ret = DCM_WRITE_FORCE_RCRRP;
    }
    else
    {
        /* check if in process of 34, 36, 37 */
        if (DCM_UDS0X36_TO_DOWNLOAD == Dcm_DspProgram.Status)
        {
            if(Dcm_36_Processing == 0)
            {
                tempBlockId = Dcm_DspProgram.blockId;
                if (0xFF == tempBlockId)
                {
                    tempBlockId = 0u;
                }
                else
                {
                    tempBlockId++;
                }

                if ((Dcm_DspProgram.blockId == Dcm_DspProgram.reqBlockId) &&
                    (Dcm_DspProgram.FirstFlag == FALSE))
                {
                    sameBlockId = TRUE;
                }
                /* Download Process is over, send NRC 0x24 */
                if ((0u == DcmDownloadSizeRemain) &&
                    (FALSE == sameBlockId))
                {
                    Dcm_36_Processing = 0;
                    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                }
                /* Downloaed Data Size goes over Required Length, send NRC 0x71 */
                else if (((MemorySize > DcmDownloadSizeRemain) &&
                        (0u != DcmDownloadSizeRemain)) ||
                        ((0u == DcmDownloadSizeRemain) &&
                        (MemorySize > DcmLastDownloadSize)))
                {
                    Dcm_36_Processing = 0;
                    *ErrorCode = DCM_E_TRANSFERDATASUSPENDED;
                }
                else if (((tempBlockId != Dcm_DspProgram.reqBlockId) &&
                        (Dcm_DspProgram.FirstFlag == TRUE)) ||
                        ((tempBlockId != Dcm_DspProgram.reqBlockId) &&
                        (Dcm_DspProgram.blockId != Dcm_DspProgram.reqBlockId) &&
                        (Dcm_DspProgram.FirstFlag == FALSE)))
                {
                    Dcm_36_Processing = 0;
                    *ErrorCode = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
                }
                else if ((MemorySize+2) > Dcm_DspProgram.BlockLength)
                {
                    Dcm_36_Processing = 0;
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                }
                else if (FALSE == sameBlockId)
                {
                    DcmDownloadSizeRemain -= MemorySize;
                    DcmLastDownloadSize = MemorySize;
                    Dcm_36_Processing = 1;
                    ret = DCM_WRITE_OK;
                }
                else
                {
                    Dcm_36_Processing = 1;
                    ret = DCM_WRITE_OK;
                }
            }
            else
            {
                Dcm_36_Processing = 1;
                ret = DCM_WRITE_OK;
            }

        }
        else
        {
            Dcm_36_Processing = 1;
            ret = DCM_WRITE_OK;
        }

        Test_MemoryAddress = MemoryAddress;
        Test_MemorySize = MemorySize;

        if (DCM_WRITE_OK == ret)
        {

            MemoryType = Dcm_memoryTypeCheck(MemoryAddress,MemorySize);
            switch(MemoryType)
            {
                case MEMORY_TYPE_RAM:
                    memcpy((void *)MemoryAddress, (const void *)MemoryData, MemorySize);
                    Dcm_36_Processing = 0;
                break;
                case MEMORY_TYPE_FLASH_BANK_A:
                case MEMORY_TYPE_FLASH_BANK_B:
                    MemoryReadAddress = MemoryAddress;
                    if (Bank_ID == 2)
                    {
                        MemoryAddress = MemoryAddress - 0x300000;
                    }
                    else
                    {
                        /*Do nothing*/
                    }
                    //FlashStatus =  Fls_17_Dmu_GetStatus();
                    FlashStatus = MEMIF_IDLE;
                    if((FlashStatus == MEMIF_IDLE) || (FlashStatus == MEMIF_UNINIT))
                    {
                        FlsLoaderResult = FlsLoader_Write((uint32)MemoryAddress, MemorySize, MemoryData);

                        if(FlsLoaderResult ==  FLSLOADER_E_OK)
                        {

                            BeadBackResult = 1;
                            if(0 != Dcm_memcmp(MemoryReadAddress,MemoryData,MemorySize))
                            {
                                BeadBackResult = 0;
                            }

                            if(MemoryAddress < 0xA0300000)
                            {
                                EccSt = (*(volatile uint32*)0xA8080020u);
                                if(0 != (EccSt & 0x00080000))
                                {
                                    //OUtData(0x41,MemoryAddress);
                                    //Result0 = FALSE;
                                }
                            }
                            else
                            {
                                EccSt = (*(volatile uint32*)0xA8380020u);
                                if(0 != (EccSt & 0x00080000))
                                {
                                    //OUtData(0x51,MemoryAddress);
                                    //Result0 = FALSE;
                                }
                            }

                            if(BeadBackResult == 0)
                            {
                                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                                Dcm_36_Processing = 0;
                                ret = DCM_WRITE_FAILED;
                            }
                            else
                            {
                                Dcm_36_Processing = 0;
                                ret = DCM_WRITE_OK;
                            }
                        }
                        else
                        {
                                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                                Dcm_36_Processing = 0;
                                ret = DCM_WRITE_FAILED;
                        }

                    }
                    else
                    {
                        ret = DCM_WRITE_PENDING;
                    }
                break;
                default:
                    Dcm_36_Processing = 0;
                    ret = DCM_WRITE_FAILED;
                break;

            }
        }
    }
    return ret;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*for 0x34 service to request download*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern uint8 u8_FlashErasecheck;
Std_ReturnType Dcm_ProcessRequestDownload(Dcm_OpStatusType OpStatus,
                                            uint8 DataFormatIdentifier,
                                            uint32 MemoryAddress,
                                            uint32 MemorySize,
                                            uint32* BlockLength,
                                            Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType Ret = E_OK;
    uint8 Bank_ID = 0;

	/* Bank_ID:
    SWAP configuration
    00B no SWAP configured by SSW (full PFlash address space active with the default map)
    01B SWAP A configured (PFlash Bank A active, B inactive)
    10B SWAP B configured (PFlash Bank B active, A inactive)
    11Breserved
    */
	Bank_ID = ((SCU_STMEM1.U & 0x00030000) >> 16u);

    if((MemoryAddress >= 0xA0300000) && (MemoryAddress <= 0xA05FFFFF)) /*APP*/
    {
        if(1 != u8_FlashErasecheck)
        {
            *ErrorCode = 0x22;
            Ret = E_NOT_OK;
        }
        else
        {
            if (Bank_ID == 2)
            {
                HashAddr = MemoryAddress- 0x300000;
                HashSize = MemorySize;
            }
            else
            {
                HashAddr = MemoryAddress;
                HashSize = MemorySize;
            }
            HashHeadAddr = MemoryAddress;
            HashHeadSize = MemorySize;

            DcmDownloadSizeRemain = MemorySize;
            DcmLastDownloadSize = 0;
            *BlockLength = 0x1002;
            Dcm_36_Processing = 0;
            Ret = E_OK;
        }
    }
    else/*FlashDrv*/
    {
        HashHeadAddr = MemoryAddress;
        HashHeadSize = MemorySize;
        HashAddr = MemoryAddress;
        HashSize = MemorySize;
        DcmDownloadSizeRemain = MemorySize;
        DcmLastDownloadSize = 0;
        *BlockLength = 0x1002;
        Dcm_36_Processing = 0;
        Ret = E_OK;
    }

    return Ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*for 0x37 service to request transfer exit*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Dcm_ProcessRequestTransferExit(Dcm_OpStatusType OpStatus,
                                                uint8* transferRequestParameterRecord,
                                                uint32 transferRequestParameterRecordSize,
                                                uint8* transferResponseParameterRecord,
                                                uint32* transferResponseParameterRecordSize,
                                                Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType ret = E_OK;

    if (DCM_UDS0X36_TO_DOWNLOAD == Dcm_DspProgram.Status)
    {
        /* process not finished yet, send NRC 0x24 */
        if (DcmDownloadSizeRemain != 0)
        {
            *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            ret = E_NOT_OK;
        }
    }
    else
    {
        /* Not in progress of any, send NRC 0x24 */
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        ret = E_NOT_OK;
    }

    if ((E_OK == ret) &&
        (0u != transferRequestParameterRecordSize))
    {
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }

    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
void Rte_EnableAllDtcsRecord(void)
{
   /*The update of the DTC status bit information shall continue once a ControlDTCSetting request is performed
     with sub-function set to on or a session layer timeout occurs (server transitions to defaultSession. */
#if 0 /*FBL does not support DTC*/
    (void)Dem_DcmEnableDTCSetting(DEM_DTC_GROUP_ALL_DTCS,DEM_DTC_KIND_ALL_DTCS);
#else

#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* Showing TM solution as an example */
/* if not having TM, need to implement other methods for timing functionality */
FUNC(void, DCM_CODE) Dcm_ResetTime(P2VAR(uint32, AUTOMATIC, DCM_VAR) TimerPtr)
{
#if (DCM_TM == STD_ON)
    Tm_PredefTimer100us32bitType Timer;

    Timer.ui32RefTime = 0;
    (void)Tm_ResetTimer100us32bit(&Timer);
    *TimerPtr = Timer.ui32RefTime / (uint32)10;
#endif

#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
	CoreIdType coreId;
    coreId = GetCoreID();
    switch (coreId)
    {
        case OS_CORE_ID_0:
        {
            (void)GetCounterValue(SystemTimer_Core0, TimerPtr);
            /*tick to ms*/

            *TimerPtr = OS_TICKS2MS_SystemTimer_Core0(*TimerPtr);
            break;
        }
        default:
            break;
    }
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* Showing TM solution as an example */
/* if not having TM, need to implement other methods for timing functionality */
FUNC(void, DCM_CODE) Dcm_GetTimeSpan(uint32 TimerPtr,P2VAR(uint32, AUTOMATIC, DCM_VAR) TimeSpanPtr)
{
#if (DCM_TM == STD_ON)
    Tm_PredefTimer100us32bitType Timer;

    Timer.ui32RefTime = TimerPtr * (uint32)10;
    (void)Tm_GetTimeSpan100us32bit(&Timer,TimeSpanPtr);
    *TimeSpanPtr = *TimeSpanPtr / (uint32)10;
#endif
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
	CoreIdType coreId;
	coreId = GetCoreID();
    switch (coreId)
    {
        case OS_CORE_ID_0:
        {
            /*ms to tick*/
        	TimerPtr = OS_MS2TICKS_SystemTimer_Core0(TimerPtr);
            (void)GetElapsedValue(SystemTimer_Core0, &TimerPtr, TimeSpanPtr);
            *TimeSpanPtr = OS_TICKS2MS_SystemTimer_Core0(*TimeSpanPtr);
            break;
        }
        default:
            break;
    }
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

