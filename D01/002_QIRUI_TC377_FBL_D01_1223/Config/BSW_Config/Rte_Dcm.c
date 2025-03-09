/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dcm.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2023-03-25 21:01:14>
 */
/*============================================================================*/

#include "Rte_Dcm.h"
#include "NvM.h"
#include "Dcm.h"
#include "Fee.h"
#include "Fls_17_Dmu.h"
#include "Dem.h"
#include "Mcu.h"
#include "PFlashDriver.h"
#include "DFlashDriver.h"
#include "IfxFlash.h"
#include "swap.h"
#include "Os.h"
#include "TestHsm.h"
#include "SampleCode.h"
#include "HsmCom_Priv.h"
#include "FlsLoader.h"
#include "UDS_0x22_2E.h"


#define HSM_BOOT_FULL_CHECK_ADDRESS (0xA0000000)
#define HSM_BOOT_FULL_CHECK_LENGTH 	(0x6FFF0)
#define HSM_BOOT_FULL_CMAC_ADDRESS	(0xA006FFF0)

#define FBL_HEAD_1K_CHECK_ADDRESS 	(0xA0070000)
#define FBL_HEAD_1K_CHECK_LENGTH 	(1024)
#define FBL_HEAD_1K_CMAC_ADDRESS	(0xA00CFFD0)

#define FBL_TAIL_1K_CHECK_ADDRESS	(0xA00CFBD0)
#define FBL_TAIL_1K_CHECK_LENGTH 	(1024)
#define FBL_TAIL_1K_CMAC_ADDRESS	(0xA00CFFE0)

#define FBL_FULL_CHECK_ADDRESS	(0xA0070000)
#define FBL_FULL_CHECK_LENGTH	(0x5FFD0)
#define FBL_FULL_CMAC_ADDRESS	(0xA00CFFF0)

#define APP_HEAD_1K_CHECK_ADDRESS 	(0xA00D0000)
#define APP_HEAD_1K_CHECK_LENGTH 	(1024)
#define APP_HEAD_1K_CMAC_ADDRESS	(0xA02FFFD0)

#define APP_TAIL_1K_CHECK_ADDRESS	(0xA02FFBD0)
#define APP_TAIL_1K_CHECK_LENGTH 	(1024)
#define APP_TAIL_1K_CMAC_ADDRESS	(0xA02FFFE0)

#define APP_FULL_CHECK_ADDRESS	(0xA00D0000)
#define APP_FULL_CHECK_LENGTH	(0x22FFD0)
#define APP_FULL_CMAC_ADDRESS	(0xA02FFFF0)

#define B_BANK_OFFSET_ADDRESS 	(0x300000)

#define DiagnoseSpeedLimit		50
#define DiagnoseVol_LowLimit	6000u
#define DiagnoseVol_HighLimit	18000u
#define DiagnoseEngStateRuning	3u
#define DiagnoseGear_P			0u

#define DiagnoseConditionOk		0u
#define DiagnoseOther_Error		1u
#define DiagnoseVol_Error		2u
#define DiagnoseSpeed_Error		3u
#define DiagnoseEngState_Error	4u
#define DiagnoseGear_Error		5u

/* flash sector size type */
#define CFLASH_SECTOR_SIZE_16K (uint32)(0x00004000u)
#define CFLASH_SECTOR_EraseNum (uint32)(4u)//(uint32)(32u)

/*Signature Verify*/
#define SIGNATURE_VERIFY_SIZE (uint32)0x80000

#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
extern uint32 HashSize;
extern uint32 HashAddr;
extern uint32 HashHeadSize;
extern uint32 HashHeadAddr;
extern float g_input12vVoltage;
extern float Rte_Buf_DicTotalModelCDCASV3QR0104_VehSpd_VehSpd;
extern boolean Rte_Buf_DicTotalModelCDCASV3QR0104_VSpeedValid_VSpeedValid;
extern uint8 Rte_Buf_DicTotalModelCDCASV3QR0104_VCUActGear_VCUActGear;
extern boolean  Rte_Buf_DicTotalModelCDCASV3QR0104_VCUActGearValid_VCUActGearValid;
extern uint8 TrngSeed[16];
extern uint8 RSA3072_publicExponent_1[16];
extern uint8 RSA3072_modulusExponent_1[384];
extern Csm_PlainKeyType PlainKey[21];

static uint8 Routine_DD02_NRC78_Flag = 0;
static uint8 Routine_DD02_Sign_Verify_Step = 0;
static uint8 RSA_VerifyResult = 0;
static uint32 rc_size_to_be_Verify = 0;
static uint32 rc_addr_to_be_Verify = 0;
static uint8 DigestData_DD02[32] = {0};
static uint32 DigestLength_DD02 = 32;

const uint8 SECUREACCESS_2701_CONST_KEY[16] = {
    0x30,0xDF,0xF5,0x46,0x36,0x2C,0x6A,0x78,
    0x9C,0x07,0xE8,0x06,0xAB,0x29,0x43,0x7A
};

const uint8 SECUREACCESS_2711_CONST_KEY[16] = {
    0x60,0x28,0xD2,0x29,0x36,0x45,0x7E,0x88,
    0x29,0xDF,0x06,0x23,0x9C,0x12,0xFA,0x98
};

static uint8 Routine_FF00_NRC78_Flag = 0;
static uint8 Routine_FF00_Flash_Erase_Step = 0;
static uint8 Routine_FF00_Flash_Erase_Result = 0;
static uint32 rc_size_to_be_erase = 0;
static uint32 rc_addr_to_be_erase = 0;

static uint8	u8_DisableSwapReq = 0u;
static uint8	u8_AppUpdatecheck = 0u;
static uint8	u8_FlashDrvcheck = 0u;
uint8	u8_FlashErasecheck = 0u;
boolean b_0203_ConditionOk = FALSE;
const uint8 CMAC_TEST_CONST_KEY[16] =
{
        167, 230, 68, 247, 185, 149, 201, 29, 166, 13, 123, 62, 125, 250, 135, 232
};
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
extern uint32 HSM_InitStatus; /*0:UNINIT 1:INITED 2:ERROR*/
extern boolean HSM_Enabled;
/***************************Security Part****************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    Std_ReturnType retValue = E_COMPARE_KEY_FAILED;
    boolean error;

	if(1 == HSM_InitStatus)
    {
        if(Key != NULL_PTR)
        {
            if(HSM_InitStatus == 0)
            {
                retValue = DCM_E_PENDING;
            }
            else if(HSM_InitStatus == 1)
            {
                error = VerifyCmac(Key,SECUREACCESS_2701_CONST_KEY);

                if(TRUE == error)
                {
                    retValue = E_OK;
                }
                else
                {
                    retValue = E_COMPARE_KEY_FAILED;
                }
            }
            else
            {
                retValue = E_COMPARE_KEY_FAILED;
            }
        }
        else
        {
            retValue = E_COMPARE_KEY_FAILED;
        }
    }
    else
    {
        retValue = E_OK;
    }

    return retValue;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{

    Std_ReturnType retValue = E_COMPARE_KEY_FAILED;
    boolean error;
	if(TRUE == HSM_Enabled)
    {
        if(Key != NULL_PTR)
        {
            if(HSM_InitStatus == 0)
            {
                retValue = DCM_E_PENDING;
            }
            else if(HSM_InitStatus == 1)
            {
                error = VerifyCmac(Key,SECUREACCESS_2711_CONST_KEY);

                if(TRUE == error)
                {
                        retValue = E_OK;
                }
                else
                {
                        retValue = E_COMPARE_KEY_FAILED;
                }
            }
            else
            {
                retValue = E_COMPARE_KEY_FAILED;
            }
        }
        else
        {
            retValue = E_COMPARE_KEY_FAILED;
        }
    
    }
    else
    {
        retValue = E_OK;
    }

    return retValue;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_GetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,uint8*  AttemptCounter )
{
    (*AttemptCounter) = *(NvM_BlockDescriptor[NvMBlockNvm_Block_DCM - 1].NvmRamBlockDataAddress);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_GetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,uint8*  AttemptCounter )
{
    (*AttemptCounter) = *(NvM_BlockDescriptor[NvMBlockNvm_Block_DCM - 1].NvmRamBlockDataAddress);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_GetSeed(
        Dcm_OpStatusType OpStatus,uint8* Seed,Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType retValue = E_NOT_OK;
    Csm_ReturnType error;
	if(TRUE == HSM_Enabled)
    {
        if(HSM_InitStatus == 0)
        {
            retValue = DCM_E_PENDING;
        }
        else if(1 == HSM_InitStatus)
        {
            error = GenerateTrngSeed();

            if(CSM_E_OK == error)
            {
                memcpy(Seed,TrngSeed,16);
                retValue = DCM_E_OK;
            }
            else if (CSM_E_BUSY == error)
            {
                retValue = DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                retValue = E_NOT_OK;
            }
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            retValue = E_NOT_OK;
        }
    }
    else
    {
        retValue = E_OK;
    }

    return retValue;

}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_GetSeed(
        Dcm_OpStatusType OpStatus,uint8* Seed,Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType retValue = E_NOT_OK;
    Csm_ReturnType error;

	if(TRUE == HSM_Enabled)
    {
        if(HSM_InitStatus == 0)
        {
            retValue = DCM_E_PENDING;
        }
        else if(HSM_InitStatus == 1)
        {
            error = GenerateTrngSeed();

            if(CSM_E_OK == error)
            {
                memcpy(Seed,TrngSeed,16);
                retValue = DCM_E_OK;
            }
            else if (CSM_E_BUSY == error)
            {
                retValue = DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                retValue = E_NOT_OK;
            }
            
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            retValue = E_NOT_OK;
        }
    }
    else
    {
        retValue = E_OK;
    }

    return retValue;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0304_GetSeed(
        Dcm_OpStatusType OpStatus,uint8* Seed,Dcm_NegativeResponseCodeType* ErrorCode)
{
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_0102_SetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter )
{
    *(NvM_BlockDescriptor[NvMBlockNvm_Block_DCM - 1].NvmRamBlockDataAddress) = AttemptCounter;
    //NvM_WriteBlock(NvMBlockNvm_Block_DCM, NULL_PTR);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_1112_SetSecurityAttemptCounter( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter )
{
    *(NvM_BlockDescriptor[NvMBlockNvm_Block_DCM - 1].NvmRamBlockDataAddress) = AttemptCounter;
    //NvM_WriteBlock(NvMBlockNvm_Block_DCM, NULL_PTR);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/***************************Did Part****************************************/

#define  DataLength_DcmDspData_0xF187 16
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF187[ DataLength_DcmDspData_0xF187 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF187_Default[ DataLength_DcmDspData_0xF187 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF18A 10
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF18A[ DataLength_DcmDspData_0xF18A ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF18A_Default[ DataLength_DcmDspData_0xF18A ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF197 10
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF197[ DataLength_DcmDspData_0xF197 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF197_Default[ DataLength_DcmDspData_0xF197 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF18C 41
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF18C[ DataLength_DcmDspData_0xF18C ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF18C_Default[ DataLength_DcmDspData_0xF18C ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF190 17
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF190[ DataLength_DcmDspData_0xF190 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF190_Default[ DataLength_DcmDspData_0xF190 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  Offset_DcmDspData_0xF190
#define  DataLength_DcmDspData_0xF18B 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF18B[ DataLength_DcmDspData_0xF18B ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF18B_Default[ DataLength_DcmDspData_0xF18B ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF0F0 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF0F0[ DataLength_DcmDspData_0xF0F0 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF0F0_Default[ DataLength_DcmDspData_0xF0F0 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF184 19
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF184[ DataLength_DcmDspData_0xF184 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF184_Default[ DataLength_DcmDspData_0xF184 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  Offset_DcmDspData_0xF184
#define  DataLength_DcmDspData_0xF189 24
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF189[ DataLength_DcmDspData_0xF189 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF189_Default[ DataLength_DcmDspData_0xF189 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF0F1 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF0F1[ DataLength_DcmDspData_0xF0F1 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF0F1_Default[ DataLength_DcmDspData_0xF0F1 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF0F3 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF0F3[ DataLength_DcmDspData_0xF0F3 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF0F3_Default[ DataLength_DcmDspData_0xF0F3 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3900 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3900[ DataLength_DcmDspData_0x3900 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3900_Default[ DataLength_DcmDspData_0x3900 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3901 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3901[ DataLength_DcmDspData_0x3901 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3901_Default[ DataLength_DcmDspData_0x3901 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3902 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3902[ DataLength_DcmDspData_0x3902 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3902_Default[ DataLength_DcmDspData_0x3902 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3903 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3903[ DataLength_DcmDspData_0x3903 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3903_Default[ DataLength_DcmDspData_0x3903 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3905 9
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3905[ DataLength_DcmDspData_0x3905 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3905_Default[ DataLength_DcmDspData_0x3905 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x390B 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x390B[ DataLength_DcmDspData_0x390B ] = {0x20} ;
uint8 Buffer_DcmDspData_0x390B_Default[ DataLength_DcmDspData_0x390B ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x390C 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x390C[ DataLength_DcmDspData_0x390C ] = {0x20} ;
uint8 Buffer_DcmDspData_0x390C_Default[ DataLength_DcmDspData_0x390C ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x390E 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x390E[ DataLength_DcmDspData_0x390E ] = {0x20} ;
uint8 Buffer_DcmDspData_0x390E_Default[ DataLength_DcmDspData_0x390E ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x390F 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x390F[ DataLength_DcmDspData_0x390F ] = {0x20} ;
uint8 Buffer_DcmDspData_0x390F_Default[ DataLength_DcmDspData_0x390F ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3910 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3910[ DataLength_DcmDspData_0x3910 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3910_Default[ DataLength_DcmDspData_0x3910 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3911 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3911[ DataLength_DcmDspData_0x3911 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3911_Default[ DataLength_DcmDspData_0x3911 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3912 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3912[ DataLength_DcmDspData_0x3912 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3912_Default[ DataLength_DcmDspData_0x3912 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x391B 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x391B[ DataLength_DcmDspData_0x391B ] = {0x20} ;
uint8 Buffer_DcmDspData_0x391B_Default[ DataLength_DcmDspData_0x391B ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x391C 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x391C[ DataLength_DcmDspData_0x391C ] = {0x20} ;
uint8 Buffer_DcmDspData_0x391C_Default[ DataLength_DcmDspData_0x391C ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x391D 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x391D[ DataLength_DcmDspData_0x391D ] = {0x20} ;
uint8 Buffer_DcmDspData_0x391D_Default[ DataLength_DcmDspData_0x391D ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x391E 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x391E[ DataLength_DcmDspData_0x391E ] = {0x20} ;
uint8 Buffer_DcmDspData_0x391E_Default[ DataLength_DcmDspData_0x391E ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x391F 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x391F[ DataLength_DcmDspData_0x391F ] = {0x20} ;
uint8 Buffer_DcmDspData_0x391F_Default[ DataLength_DcmDspData_0x391F ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3920 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3920[ DataLength_DcmDspData_0x3920 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3920_Default[ DataLength_DcmDspData_0x3920 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3922 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3922[ DataLength_DcmDspData_0x3922 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3922_Default[ DataLength_DcmDspData_0x3922 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3923 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3923[ DataLength_DcmDspData_0x3923 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3923_Default[ DataLength_DcmDspData_0x3923 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3924 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3924[ DataLength_DcmDspData_0x3924 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3924_Default[ DataLength_DcmDspData_0x3924 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3925 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3925[ DataLength_DcmDspData_0x3925 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3925_Default[ DataLength_DcmDspData_0x3925 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3926 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3926[ DataLength_DcmDspData_0x3926 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3926_Default[ DataLength_DcmDspData_0x3926 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3927 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3927[ DataLength_DcmDspData_0x3927 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3927_Default[ DataLength_DcmDspData_0x3927 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x394A 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x394A[ DataLength_DcmDspData_0x394A ] = {0x20} ;
uint8 Buffer_DcmDspData_0x394A_Default[ DataLength_DcmDspData_0x394A ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  Offset_DcmDspData_0x394A
#define  DataLength_DcmDspData_0x3907 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3907[ DataLength_DcmDspData_0x3907 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3907_Default[ DataLength_DcmDspData_0x3907 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3940 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3940[ DataLength_DcmDspData_0x3940 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3940_Default[ DataLength_DcmDspData_0x3940 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3960 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3960[ DataLength_DcmDspData_0x3960 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3960_Default[ DataLength_DcmDspData_0x3960 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF013 16
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF013[ DataLength_DcmDspData_0xF013 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF013_Default[ DataLength_DcmDspData_0xF013 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF031 16
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF031[ DataLength_DcmDspData_0xF031 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF031_Default[ DataLength_DcmDspData_0xF031 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF089 24
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF089[ DataLength_DcmDspData_0xF089 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF089_Default[ DataLength_DcmDspData_0xF089 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF032 24
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF032[ DataLength_DcmDspData_0xF032 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF032_Default[ DataLength_DcmDspData_0xF032 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF180 32
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF180[ DataLength_DcmDspData_0xF180 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF180_Default[ DataLength_DcmDspData_0xF180 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF186 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF186[ DataLength_DcmDspData_0xF186 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF186_Default[ DataLength_DcmDspData_0xF186 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF0F2 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF0F2[ DataLength_DcmDspData_0xF0F2 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF0F2_Default[ DataLength_DcmDspData_0xF0F2 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF025 16
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF025[ DataLength_DcmDspData_0xF025 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF025_Default[ DataLength_DcmDspData_0xF025 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF091 581
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF091[ DataLength_DcmDspData_0xF091 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF091_Default[ DataLength_DcmDspData_0xF091 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3906 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3906[ DataLength_DcmDspData_0x3906 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3906_Default[ DataLength_DcmDspData_0x3906 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x396D 2
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x396D[ DataLength_DcmDspData_0x396D ] = {0x20} ;
uint8 Buffer_DcmDspData_0x396D_Default[ DataLength_DcmDspData_0x396D ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x396E 10
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x396E[ DataLength_DcmDspData_0x396E ] = {0x20} ;
uint8 Buffer_DcmDspData_0x396E_Default[ DataLength_DcmDspData_0x396E ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  Offset_DcmDspData_0x396E
#define  DataLength_DcmDspData_0x396F 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x396F[ DataLength_DcmDspData_0x396F ] = {0x20} ;
uint8 Buffer_DcmDspData_0x396F_Default[ DataLength_DcmDspData_0x396F ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3970 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3970[ DataLength_DcmDspData_0x3970 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3970_Default[ DataLength_DcmDspData_0x3970 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3971 3
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3971[ DataLength_DcmDspData_0x3971 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3971_Default[ DataLength_DcmDspData_0x3971 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3972 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3972[ DataLength_DcmDspData_0x3972 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3972_Default[ DataLength_DcmDspData_0x3972 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3973 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3973[ DataLength_DcmDspData_0x3973 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3973_Default[ DataLength_DcmDspData_0x3973 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3974 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3974[ DataLength_DcmDspData_0x3974 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3974_Default[ DataLength_DcmDspData_0x3974 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3975 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3975[ DataLength_DcmDspData_0x3975 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3975_Default[ DataLength_DcmDspData_0x3975 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3976 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3976[ DataLength_DcmDspData_0x3976 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3976_Default[ DataLength_DcmDspData_0x3976 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x3977 4
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3977[ DataLength_DcmDspData_0x3977 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3977_Default[ DataLength_DcmDspData_0x3977 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0x390A 8
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x390A[ DataLength_DcmDspData_0x390A ] = {0x20} ;
uint8 Buffer_DcmDspData_0x390A_Default[ DataLength_DcmDspData_0x390A ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  Offset_DcmDspData_0x390A
#define  DataLength_DcmDspData_0x3929 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0x3929[ DataLength_DcmDspData_0x3929 ] = {0x20} ;
uint8 Buffer_DcmDspData_0x3929_Default[ DataLength_DcmDspData_0x3929 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF090 24
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF090[ DataLength_DcmDspData_0xF090 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF090_Default[ DataLength_DcmDspData_0xF090 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF160 1
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF160[ DataLength_DcmDspData_0xF160 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF160_Default[ DataLength_DcmDspData_0xF160 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_DcmDspData_0xF162 35
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_DcmDspData_0xF162[ DataLength_DcmDspData_0xF162 ] = {0x20} ;
uint8 Buffer_DcmDspData_0xF162_Default[ DataLength_DcmDspData_0xF162 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_FreezeCurrentState(
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_FreezeCurrentState(
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF160_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF160;index++)
    {
        #ifdef  DCM_DDDID_STORAGE_BLOCKID
        #ifdef  Offset_DcmDspData_0xF160
                Data[index] = *(NvM_BlockDescriptor[DCM_DDDID_STORAGE_BLOCKID - 1].NvmRamBlockDataAddress + Offset_DcmDspData_0xF160 + index);
        #else
                Data[index] = 1;//Buffer_DcmDspData_0xF160[index];
        #endif
        #endif
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF162_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF162;index++)
    {
        Data[index] = DCM_Block_RAM_Buf[DFLASH_DCM_F162_OFFSET + 2 + index ];
    }

    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF187_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
	ReadBuffer_DcmDspData_0xF187(&Buffer_DcmDspData_0xF187[0]);
    for(index = 0;index < DataLength_DcmDspData_0xF187;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF187[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
	ReadBuffer_DcmDspData_0xF18A(&Buffer_DcmDspData_0xF18A[0]);
    for(index = 0;index < DataLength_DcmDspData_0xF18A;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF18A[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF197_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF190_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF18B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F0_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
	uint8 Bank_ID;
	Bank_ID = ((SCU_STMEM1.U & 0x00030000) >> 16u);
	if(1u == Bank_ID)//A bank;
	{
		Data[0] = 0x41;
	}
	else if(2u == Bank_ID)
	{
		Data[0] = 0x42;
	}
	else
	{
		Data[0] = 0x41;
	}

    Routine_FF00_NRC78_Flag = 0;
    Routine_FF00_Flash_Erase_Step = 0;
    Routine_FF00_Flash_Erase_Result = 0;
    rc_size_to_be_erase = 0;
    rc_addr_to_be_erase = 0;
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF184_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF184;index++)
    {
        Data[index] = DCM_Block_RAM_Buf[DFLASH_DCM_F184_OFFSET + 2 + index ];
    }

    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF189_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F1_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF0F1;index++)
    {
        Data[index] = DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET + 2 + index ];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F3_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    for(index = 0;index < DataLength_DcmDspData_0xF0F3;index++)
    {
        Data[index] = DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET + 2 + index ];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3900_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3901_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3902_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3903_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3905_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390F_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3910_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3911_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3912_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x391B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x391C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x391D_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x391E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x391F_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3920_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3922_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3923_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3924_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3925_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3926_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3927_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x394A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3907_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3940_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3960_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF013_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF031_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF089_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
	ReadBuffer_DcmDspData_0xF089(&Buffer_DcmDspData_0xF089[0]);
    for(index = 0;index < DataLength_DcmDspData_0xF089;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF089[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF032_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF180_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
	ReadBuffer_DcmDspData_0xF180(&Buffer_DcmDspData_0xF180[0]);
    for(index = 0;index < DataLength_DcmDspData_0xF180;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF180[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF186_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
	ReadBuffer_DcmDspData_0xF186(&Buffer_DcmDspData_0xF186[0]);
    for(index = 0;index < DataLength_DcmDspData_0xF186;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF186[index];
    }

    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF0F2_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    uint8  index;
    //*ErrorCode =  DCM_E_REQUESTOUTOFRANGE;
    Buffer_DcmDspData_0xF0F2[0] = 0;
    Buffer_DcmDspData_0xF0F2[1] = 0;
    for(index = 0;index < DataLength_DcmDspData_0xF0F2;index++)
    {
        Data[index] = Buffer_DcmDspData_0xF0F2[index];
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF025_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF091_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3906_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x396D_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x396E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x396F_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3970_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3971_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3972_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3973_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3974_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3975_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3976_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF090_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ResetToDefault(
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ResetToDefault(
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ReturnControlToECU(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ReturnControlToECU(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3929_ShortTermAdjustment(
            P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
            uint16 DataLength,
            Dcm_OpStatusType OpStatus,
            P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
            P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x3977_ShortTermAdjustment(
            P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
            uint16 DataLength,
            Dcm_OpStatusType OpStatus,
            P2VAR(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
            P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{

    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF190_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0xF184_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    Std_ReturnType ret = E_OK;
    uint8 F0F1Data[4];
    uint32 ProgAttemptCnt = 0;
    if(OpStatus != DCM_FORCE_RCRRP_OK)
    {
        ret = DCM_E_FORCE_RCRRP;
    }
    else
    {
        DFlashDriver_WriteDID_F184(Data);

        ProgAttemptCnt = ((((uint32)(DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET + 2]))<<24) & 0xFF000000) + 
        ((((uint32)(DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET + 3]))<<16) & 0x00FF0000)  + 
        ((((uint32)(DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET + 4]))<<8) & 0x0000FF00) + 
        ((((uint32)(DCM_Block_RAM_Buf[DFLASH_DCM_F0F1_OFFSET + 5])))& 0x000000FF);

        ProgAttemptCnt = ProgAttemptCnt + 1;

        F0F1Data[0] = (uint8)((ProgAttemptCnt>>24) & 0x000000FF); 
        F0F1Data[1] = (uint8)((ProgAttemptCnt>>16) & 0x000000FF);
        F0F1Data[2] = (uint8)((ProgAttemptCnt>>8) & 0x000000FF);
        F0F1Data[3] = (uint8)(ProgAttemptCnt & 0x000000FF);

        DFlashDriver_WriteDID_F0F1(F0F1Data);
        DFlashDriver_WriteDcmBlock();
        ret = E_OK;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x396E_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x394A_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_0x390A_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode )
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/***************************Routine Part****************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD04_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{

    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
 #if 0   
	if((0xFE == Read_ORIG_Swap_Info())||(0xFE == Read_COPY_Swap_Info()))
	{
		*OutBuffer = 0x0;
	}
	else
	{
		(void)Disable_Swap_Config();
		*OutBuffer = 0x1;
	}

    return E_OK;
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392A_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392C_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392D_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392E_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392F_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3930_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3956_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395B_RequestResults(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD0F_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
	uint8 Ret = 1u;	
	
	//Ret = configure_swap_MainFunc(Bank_Keep);
	//Ret = Enable_Swap_Config();
	
	if(0x1 == Ret)
	{
		u8_DisableSwapReq = 1u;
		*OutBuffer = 0x0;
	}
	else
	{
		*OutBuffer = 0x1;
	}
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xFF01_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
	boolean Check_Result = 1;
    MemIf_StatusType FlashStatus = MEMIF_IDLE;
    StatusType AlarmStatus = E_OK;
    TickType Tick = 0;
    boolean interruptState;	
	uint32 Ret = E_OK;
    uint32 ProgrammingDependencyCheckSuccessCnt = 0;
    uint8 NvMWriteStatus;
    static uint8 ProgrammingDependencyCheckStep = 0;
    static uint32 NvMWriteStatusTimer = 0;
    uint8 F0F3Data[4];
    uint8 *PartNODataPtr = (uint8 *)0x805FFF60;

   boolean Ret_HsmBootVerifyMac = FALSE;
   boolean Ret_FblHeadVerifyMac = FALSE;
   boolean Ret_FblTailVerifyMac = FALSE;
   boolean Ret_FblFullVerifyMac = FALSE;
   boolean Ret_AppHeadVerifyMac = FALSE;
   boolean Ret_AppTailVerifyMac = FALSE;
   boolean Ret_AppFullVerifyMac = FALSE;

    switch (ProgrammingDependencyCheckStep)
    {
    case 0:
        if(1u == u8_AppUpdatecheck)
        {
            if(0u == u8_DisableSwapReq)
            {
                ProgrammingDependencyCheckStep = 1;
                Ret = DCM_E_FORCE_RCRRP;
            }
            else
            {
                ProgrammingDependencyCheckStep = 0;
                *OutBuffer = 0x0;
                Ret = E_OK;
            }
        }
        else
        {
            *ErrorCode = 0x22;
            Ret = E_NOT_OK;
        }
        break;

    case 1:
        if(1 == HSM_InitStatus)
        {
            /*Check B Bank HSM and BootManager*/
            SampleCode_LoadPlainKey(HSMCOM_RAM_KEY,(HsmAes_Block *)CMAC_TEST_CONST_KEY,16);
            Ret_HsmBootVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(HSM_BOOT_FULL_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(HSM_BOOT_FULL_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), HSM_BOOT_FULL_CHECK_LENGTH, 16*8);
            Ret_FblHeadVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(FBL_HEAD_1K_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(FBL_HEAD_1K_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), FBL_HEAD_1K_CHECK_LENGTH, 16*8);
            Ret_FblTailVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(FBL_TAIL_1K_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(FBL_TAIL_1K_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), FBL_TAIL_1K_CHECK_LENGTH, 16*8);
            Ret_FblFullVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(FBL_FULL_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(FBL_FULL_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), FBL_FULL_CHECK_LENGTH, 16*8);
            Ret_AppHeadVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(APP_HEAD_1K_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(APP_HEAD_1K_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), APP_HEAD_1K_CHECK_LENGTH, 16*8);
            Ret_AppTailVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(APP_TAIL_1K_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(APP_TAIL_1K_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), APP_TAIL_1K_CHECK_LENGTH, 16*8);
            Ret_AppFullVerifyMac = VerifyMac(KEY_MAC_VERIFY_RAM_KEY, (const void*)(APP_FULL_CHECK_ADDRESS + B_BANK_OFFSET_ADDRESS), (const void*)(APP_FULL_CMAC_ADDRESS + B_BANK_OFFSET_ADDRESS), APP_FULL_CHECK_LENGTH, 16*8);
        }
        else
        {
            Ret_HsmBootVerifyMac = TRUE;
            Ret_FblHeadVerifyMac = TRUE;
            Ret_FblTailVerifyMac = TRUE;
            Ret_FblFullVerifyMac = TRUE;
            Ret_AppHeadVerifyMac = TRUE;
            Ret_AppTailVerifyMac = TRUE;
            Ret_AppFullVerifyMac = TRUE;
        }

        if((Ret_HsmBootVerifyMac == FALSE) || (Ret_FblHeadVerifyMac == FALSE) || (Ret_FblTailVerifyMac == FALSE) || (Ret_FblFullVerifyMac == FALSE) ||
            (Ret_AppHeadVerifyMac == FALSE) || (Ret_AppTailVerifyMac == FALSE) || (Ret_AppFullVerifyMac == FALSE))
        {
            ProgrammingDependencyCheckStep = 0;
            *OutBuffer = 0x1;
            Ret = E_OK;
        }
        else if(strncmp(PartNODataPtr, g_F187ManufactureEcuPartNODataIdentifier, strlen(g_F187ManufactureEcuPartNODataIdentifier)) != 0)
        {
            ProgrammingDependencyCheckStep = 0;
            *OutBuffer = 0x1;
            Ret = E_OK;
        }
        else
        {
            ProgrammingDependencyCheckSuccessCnt = ((((uint32)(DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET + 2]))<<24) & 0xFF000000) + 
            ((((uint32)(DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET + 3]))<<16) & 0x00FF0000)  + 
            ((((uint32)(DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET + 4]))<<8) & 0x0000FF00) + 
            ((((uint32)(DCM_Block_RAM_Buf[DFLASH_DCM_F0F3_OFFSET + 5])))& 0x000000FF);
            ProgrammingDependencyCheckSuccessCnt = ProgrammingDependencyCheckSuccessCnt + 1;
            F0F3Data[0] = (uint8)((ProgrammingDependencyCheckSuccessCnt>>24) & 0x000000FF);
            F0F3Data[1] = (uint8)((ProgrammingDependencyCheckSuccessCnt>>16) & 0x000000FF);
            F0F3Data[2] = (uint8)((ProgrammingDependencyCheckSuccessCnt>>8) & 0x000000FF);
            F0F3Data[3] = (uint8)(ProgrammingDependencyCheckSuccessCnt & 0x000000FF);
            DFlashDriver_WriteDID_F0F3(F0F3Data);
            DFlashDriver_WriteDcmBlock();

            interruptState = IfxCpu_disableInterrupts(); /* Get the current state of the interrupts and disable them*/
            Check_Result = configure_swap_MainFunc(Bank_Switch);
            Check_Result = Enable_Swap_Config();
            IfxCpu_restoreInterrupts(interruptState);			/* Restore the interrupts state 	 */
            if(1u == Check_Result)
            {

                ProgrammingDependencyCheckStep = 2;
                Ret = DCM_E_FORCE_RCRRP;
            }
            else
            {
                ProgrammingDependencyCheckStep = 0;
                *OutBuffer = 0x1;
                Ret = E_OK;
            }
        }
        break;
    case 2:
        ProgrammingDependencyCheckStep = 0;
        *OutBuffer = 0x0;
        Ret = E_OK;
        break;
    default:
        ProgrammingDependencyCheckStep = 0;
        *OutBuffer = 0x1;
        Ret = E_OK;
        break;
    }


    return Ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x0203_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
	uint16 	u16_CAN_Speed = 0u;
	boolean b_CAN_SpeedValid = FALSE;
	uint16 	u16_SystemVol = 0u;
	uint8 	u8_EngineState = 0u;
	uint8 	u8_VehicleGear = 0u;
    boolean b_VehicleGearValid = FALSE;

	u16_CAN_Speed = 0u;
	u16_SystemVol = 1350u;
	u8_EngineState = 0u;
	u8_VehicleGear = DiagnoseGear_P;

    u16_CAN_Speed = Rte_Buf_DicTotalModelCDCASV3QR0104_VehSpd_VehSpd * 10;
    b_CAN_SpeedValid = Rte_Buf_DicTotalModelCDCASV3QR0104_VSpeedValid_VSpeedValid;
    u16_SystemVol = g_input12vVoltage * 1000;
    u8_VehicleGear = Rte_Buf_DicTotalModelCDCASV3QR0104_VCUActGear_VCUActGear;
    b_VehicleGearValid = Rte_Buf_DicTotalModelCDCASV3QR0104_VCUActGearValid_VCUActGearValid;
#if 0
	if((DiagnoseVol_HighLimit < u16_SystemVol)||(DiagnoseVol_LowLimit > u16_SystemVol))
	{
		*OutBuffer = DiagnoseVol_Error;
	}
	else if((DiagnoseSpeedLimit <= u16_CAN_Speed) && (b_CAN_SpeedValid == TRUE))
	{
		*OutBuffer = DiagnoseSpeed_Error;
	}
	else if(DiagnoseEngStateRuning == u8_EngineState)
	{
		*OutBuffer = DiagnoseEngState_Error;
	}
	else if((DiagnoseGear_P != u8_VehicleGear && b_VehicleGearValid == TRUE))
	{
		*OutBuffer = DiagnoseGear_Error;
	}
	else
	{
		*OutBuffer = DiagnoseConditionOk;
		b_0203_ConditionOk = TRUE;

	}
#else
		*OutBuffer = DiagnoseConditionOk;
		b_0203_ConditionOk = TRUE;
#endif
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xFF00_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
   uint32 SectorNum;
    //uint32 LastSectorBlockCounter;
    uint32 SectorBlockNum;
    uint32 RemainSectorBlockNum;
    uint8 req_memSize_len = 0;
    uint8 req_memAddr_len = 0;
    uint32 rc_memory_size = 0;
    uint32 rc_memory_addr = 0;
    uint8 rc_memory_type = 0xFF;
    Std_ReturnType Ret = DCM_E_PENDING;
    MemIf_StatusType FlashStatus = MEMIF_IDLE;
    StatusType AlarmStatus = E_OK;
    TickType Tick = 0;
    uint8 Bank_ID = 0;
	/* Bank_ID:
    SWAP configuration
    00B no SWAP configured by SSW (full PFlash address space active with the default map)
    01B SWAP A configured (PFlash Bank A active, B inactive)
    10B SWAP B configured (PFlash Bank B active, A inactive)
    11Breserved
    */
	Bank_ID = ((SCU_STMEM1.U & 0x00030000) >> 16u);
    
    req_memAddr_len = (*(InBuffer)) & 0x0fu;
    req_memSize_len = (uint8)((*(InBuffer)&0xf0u) >> 4u);

    if ((4u == req_memSize_len) && (4u == req_memAddr_len))
    {
        rc_memory_addr = ( ((uint32)InBuffer[1])<< 24) | ( ((uint32)InBuffer[2])<< 16) | ( ((uint32)InBuffer[3])<< 8) |( ((uint32)InBuffer[4])<< 0);
        rc_memory_size = ( ((uint32)InBuffer[5])<< 24) | ( ((uint32)InBuffer[6])<< 16) | ( ((uint32)InBuffer[7])<< 8) |( ((uint32)InBuffer[8])<< 0);
        SectorNum = rc_memory_size/1024/16;  /*One Sector = 16KB*/

        /* check whether the rd address and size  meet  requirement of the physic flash*/
        rc_memory_type = Dcm_memoryTypeCheck(rc_memory_addr, rc_memory_size);

        //if (((rc_memory_type == MEMORY_TYPE_FLASH_BANK_A) && (Bank_ID == 2)) || ((rc_memory_type == MEMORY_TYPE_FLASH_BANK_B) && ((Bank_ID == 1) || (Bank_ID == 0))))
        if(rc_memory_type == MEMORY_TYPE_FLASH_BANK_B)
        {
            if (Bank_ID == 2)
            {
                rc_memory_addr = rc_memory_addr - 0x300000;
            }
            else
            {
                /* Do nothing*/
            }

            /*Check Flash Drv In RAM*/
            if (u8_FlashDrvcheck != 1)
            {
                *ErrorCode = 0x22;
                Ret = E_NOT_OK;
            }
            else
            {
                if(Routine_FF00_NRC78_Flag == 0)
                {
                    Routine_FF00_NRC78_Flag = 1u;
					Routine_FF00_Flash_Erase_Step = 0u;
					
                    Ret = DCM_E_FORCE_RCRRP;
                }
                else
                {
                    //FlashStatus =  Fls_17_Dmu_GetStatus();
					FlashStatus = MEMIF_IDLE;
					
                    if((FlashStatus == MEMIF_IDLE) || (FlashStatus == MEMIF_UNINIT))
                    {
                        SectorBlockNum = SectorNum / CFLASH_SECTOR_EraseNum;
							
                        switch (Routine_FF00_Flash_Erase_Step)
                        {
                            case 0: /* Erase First Sector*/
								if(SectorBlockNum >= 1u)
								{
									rc_size_to_be_erase = rc_memory_size;
									rc_addr_to_be_erase = rc_memory_addr;

                                    Ret = FlsLoader_Erase((uint32)rc_addr_to_be_erase, CFLASH_SECTOR_EraseNum);
                                    /* Check if sectors erased successfully */
                                    if(Ret == FLSLOADER_E_OK)
                                    {
                                        if(rc_size_to_be_erase >= CFLASH_SECTOR_SIZE_16K*CFLASH_SECTOR_EraseNum)
                                        {
                                            rc_size_to_be_erase -= CFLASH_SECTOR_SIZE_16K*CFLASH_SECTOR_EraseNum; 
                                        }
                                        
                                        rc_addr_to_be_erase += CFLASH_SECTOR_SIZE_16K*CFLASH_SECTOR_EraseNum;
                                        
                                        Routine_FF00_Flash_Erase_Step = 1;
                                        Routine_FF00_Flash_Erase_Result = TRUE;
                                        Ret = DCM_E_PENDING;
                                    }
                                    else
                                    {
                                        *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                                        Ret = E_NOT_OK;
                                    }

								}
								else
								{
                                    RemainSectorBlockNum = SectorNum % CFLASH_SECTOR_EraseNum;
                                    Ret = FlsLoader_Erase((uint32)rc_addr_to_be_erase, RemainSectorBlockNum + 1);
                                    /* Check if sectors erased successfully */
                                    if(Ret == FLSLOADER_E_OK)
                                    {
                                        Routine_FF00_Flash_Erase_Result = TRUE;
                                        *OutBuffer = 0;
                                        Ret = DCM_E_OK;
                                    }
                                    else
                                    {
                                        *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                                        Ret = E_NOT_OK;
                                    }
								}
                            break;
							
                            case 1:
                                if (Routine_FF00_Flash_Erase_Result == TRUE)
                                {
                                    if (CFLASH_SECTOR_SIZE_16K*CFLASH_SECTOR_EraseNum >= rc_size_to_be_erase)
                                    {
                                        if(0 != rc_size_to_be_erase)
                                        {
											if((rc_size_to_be_erase/CFLASH_SECTOR_SIZE_16K) == CFLASH_SECTOR_EraseNum)
											{
												Ret = FlsLoader_Erase(rc_addr_to_be_erase, rc_size_to_be_erase/CFLASH_SECTOR_SIZE_16K);/*one sector is 16KB*/
											}
											else
											{
												Ret = FlsLoader_Erase(rc_addr_to_be_erase, (rc_size_to_be_erase/CFLASH_SECTOR_SIZE_16K)+1);/*one sector is 16KB*/
											}

                                            /* Check if sectors erased successfully */
                                            if(Ret == FLSLOADER_E_OK)
                                            {
                                                Routine_FF00_Flash_Erase_Step = 1;
                                                rc_size_to_be_erase = 0;
                                                Routine_FF00_Flash_Erase_Result = TRUE;
                                                Ret = DCM_E_PENDING;
                                            }
                                            else
                                            {
                                                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                                                Ret = E_NOT_OK;
                                            }
                                        }
                                        else
                                        {
                                            Routine_FF00_Flash_Erase_Step = 0;
                                            Routine_FF00_NRC78_Flag = 0;
                                            u8_FlashErasecheck = 1;
                                            *OutBuffer = 0;
                                            Ret = DCM_E_OK;
                                        }
                                    }
                                    else
                                    {
                                        Ret = FlsLoader_Erase((uint32)rc_addr_to_be_erase, CFLASH_SECTOR_EraseNum);
                                        /* Check if sectors erased successfully */
                                        if(Ret == FLSLOADER_E_OK)
                                        {
                                            if(rc_size_to_be_erase >= CFLASH_SECTOR_SIZE_16K*CFLASH_SECTOR_EraseNum)
                                            {
                                                rc_size_to_be_erase -= CFLASH_SECTOR_SIZE_16K*CFLASH_SECTOR_EraseNum; 
                                            }
                                            rc_addr_to_be_erase += CFLASH_SECTOR_SIZE_16K*CFLASH_SECTOR_EraseNum;
                                            Routine_FF00_Flash_Erase_Step = 1;
                                            Routine_FF00_Flash_Erase_Result = TRUE;
                                            Ret = DCM_E_FORCE_RCRRP;
                                            //Ret = DCM_E_PENDING;
                                        }
                                        else
                                        {
                                            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                                            Ret = E_NOT_OK;
                                        }
                                    }
                                }
                                else
                                {
                                    *OutBuffer = 1;
                                    Routine_FF00_Flash_Erase_Step = 0;
                                    Routine_FF00_NRC78_Flag = 0;
                            		Ret = E_OK;
                                }
                            break;
								
                            default:
                            break;
                        }
                    }
                    else
                    {
                        Ret = DCM_E_PENDING;
                    }
                }
            }
        }
        else
        {
            Routine_FF00_NRC78_Flag = 0;
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Ret = E_NOT_OK;
        }
    }
    else
    {
        Routine_FF00_NRC78_Flag = 0;
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Ret = E_NOT_OK;
    }

    return Ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern boolean FblRecvDD01;
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD01_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    /*Stay in boot*/
    FblRecvDD01 = TRUE;
    DslInternal_S3ServerStart();
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD02_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{

    Std_ReturnType Ret = DCM_E_PENDING;
    Csm_ReturnType test_RetVal=CSM_E_NOT_OK;
    static Csm_ReturnType test_RetVal_hash=CSM_E_NOT_OK;
    uint8 Signature_Buffer_DD02[384] = {0};
    uint8 Head[8] = {0};
    uint8 Head_Hash[8] = {0};
    uint8 HashData[32] ={0x11,0x22,0x33,0x4,0x5,0x6,0x7,0x8,0x91,0x43,0x4,0x3,0x14,0x4,0x34,
    		0x4,0x34,0x8,0x56,0x76,0x8,0x68,0x68,0x6,0x68,0x6,0x68,0x7,0x6,0x7,0x6,0x4};//for test

    memcpy(Signature_Buffer_DD02, InBuffer, sizeof(Signature_Buffer_DD02));   

    if(Dcm_UDS_UDS0x31_37Flag == Unperform)
    {
        /*if not 37 positive response,send NRC 0x22*/
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        Ret = E_NOT_OK;
    }
    else
    {
        if(1 == HSM_InitStatus)
        {
            //Reserve for Signature Check;
            *OutBuffer = 0x0;
            if(Routine_DD02_NRC78_Flag == 0)
            {
                Routine_DD02_NRC78_Flag = 1u;
                Routine_DD02_Sign_Verify_Step = 0u; 
                Ret = DCM_E_FORCE_RCRRP;
            }
            else
            {
                switch (Routine_DD02_Sign_Verify_Step)
                {
                    case 0:
                        /*load key*/
                        test_RetVal = SampleCode_LoadPlainKey(PLAIN_KEY_13,RSA3072_publicExponent_1,4); /*rsa3072 public key*/
                        test_RetVal = SampleCode_LoadPlainKey(PLAIN_KEY_14,RSA3072_modulusExponent_1,384); /*rsa3072 modulus key*/

                        Routine_DD02_Sign_Verify_Step = 1;
                        Ret = DCM_E_PENDING;
                    break;
                    case 1:
                        /*add Head*/
                        Head[0] = HashHeadAddr >> 24;
                        Head[1] = (HashHeadAddr >> 16) & 0xFF;
                        Head[2] = (HashHeadAddr >> 8) & 0xFF;
                        Head[3] = HashHeadAddr & 0xFF;
                        Head[4] = HashHeadSize >> 24;
                        Head[5] = (HashHeadSize >> 16) & 0xFF;
                        Head[6] = (HashHeadSize >> 8) & 0xFF;
                        Head[7] = HashHeadSize & 0xFF;

                        memcpy(Head_Hash, Head, sizeof(Head_Hash));


                        /*RSA update Head*/
                        test_RetVal = SampleCode_SignatureVerify(&PlainKey[12],HSM_SIGNATURE_ALGORITHM_RSA_v21,NULL_PTR,0,NULL_PTR, 0,
                                                                                Signature_Buffer_DD02,384,&RSA_VerifyResult,CRYPTO_OPERATIONMODE_START);
                        test_RetVal = SampleCode_SignatureVerify(&PlainKey[12],HSM_SIGNATURE_ALGORITHM_RSA_v21,NULL_PTR,0,Head, 8,
                                                                                Signature_Buffer_DD02,384,&RSA_VerifyResult,CRYPTO_OPERATIONMODE_UPDATE);
                        if((HashHeadAddr >= 0xA0000000) && (HashHeadAddr <= 0xA05FFFFF))
                        {
                            test_RetVal_hash = SampleCode_Hash(HSM_HASH_ALGORITHM_SHA256,NULL_PTR,0,DigestData_DD02,&DigestLength_DD02,CRYPTO_OPERATIONMODE_START);
                            test_RetVal_hash = SampleCode_Hash(HSM_HASH_ALGORITHM_SHA256,Head_Hash,8,DigestData_DD02,&DigestLength_DD02,CRYPTO_OPERATIONMODE_UPDATE);
                            test_RetVal_hash = SampleCode_Hash(HSM_HASH_ALGORITHM_SHA256,(uint8 *)HashHeadAddr,HashHeadSize,DigestData_DD02,&DigestLength_DD02,CRYPTO_OPERATIONMODE_UPDATE);
                            test_RetVal_hash = SampleCode_Hash(HSM_HASH_ALGORITHM_SHA256,NULL_PTR,0,DigestData_DD02,&DigestLength_DD02,CRYPTO_OPERATIONMODE_FINISH); 
                        }
                        else
                        {
                            test_RetVal_hash = DCM_E_OK;
                        }

                        Routine_DD02_Sign_Verify_Step = 2;
                        Ret = DCM_E_PENDING;
                    break;
                    case 2:
                        /*Verify First Block*/
                        if(HashSize >= SIGNATURE_VERIFY_SIZE)
                        {
                            rc_size_to_be_Verify = HashSize;
                            rc_addr_to_be_Verify = HashAddr;

                            if((rc_addr_to_be_Verify>=0xA0000000)&&(rc_addr_to_be_Verify<=0xA02FFFFF))
                            {
                                rc_addr_to_be_Verify = rc_addr_to_be_Verify +  0x300000;
                            }
                            else
                            {
                                /*Do nothing*/
                            }
                            test_RetVal = SampleCode_SignatureVerify(&PlainKey[12],HSM_SIGNATURE_ALGORITHM_RSA_v21,NULL_PTR,0,(uint8 *)rc_addr_to_be_Verify, SIGNATURE_VERIFY_SIZE,
                                                                    Signature_Buffer_DD02,384,&RSA_VerifyResult,CRYPTO_OPERATIONMODE_UPDATE);

                            rc_size_to_be_Verify -= SIGNATURE_VERIFY_SIZE;
                            rc_addr_to_be_Verify += SIGNATURE_VERIFY_SIZE;
                            Routine_DD02_Sign_Verify_Step = 3;
                            Ret = DCM_E_PENDING;
                            
                        }
                        else
                        {
                            rc_size_to_be_Verify = HashSize;
                            rc_addr_to_be_Verify = HashAddr;

                            if((rc_addr_to_be_Verify>=0xA0000000)&&(rc_addr_to_be_Verify<=0xA02FFFFF))
                            {
                                rc_addr_to_be_Verify = rc_addr_to_be_Verify +  0x300000;
                            }
                            else
                            {
                                /*Do nothing*/
                            }
                            test_RetVal = SampleCode_SignatureVerify(&PlainKey[12],HSM_SIGNATURE_ALGORITHM_RSA_v21,NULL_PTR,0,(uint8 *)rc_addr_to_be_Verify, rc_size_to_be_Verify,
                                                                    Signature_Buffer_DD02,384,&RSA_VerifyResult,CRYPTO_OPERATIONMODE_UPDATE);

                            test_RetVal = SampleCode_SignatureVerify(&PlainKey[12],HSM_SIGNATURE_ALGORITHM_RSA_v21,NULL_PTR,0,NULL_PTR, 0,
                                                                    Signature_Buffer_DD02,384,&RSA_VerifyResult,CRYPTO_OPERATIONMODE_FINISH);

                            if(test_RetVal == CSM_E_OK&&RSA_VerifyResult==0)
                            {
                                Routine_DD02_NRC78_Flag = 0;
                                *OutBuffer = 0;
                                Ret = DCM_E_OK;
                            }
                            else
                            {
                                Routine_DD02_NRC78_Flag = 0;
                                *OutBuffer = 2;
                                Ret = DCM_E_OK;
                            }
                        }

                    break;
                    case 3:
                        if(SIGNATURE_VERIFY_SIZE >=rc_size_to_be_Verify)
                        {
                            if(0 != rc_size_to_be_Verify)
                            {
                                test_RetVal = SampleCode_SignatureVerify(&PlainKey[12],HSM_SIGNATURE_ALGORITHM_RSA_v21,NULL_PTR,0,(uint8 *)rc_addr_to_be_Verify, rc_size_to_be_Verify,
                                                                    Signature_Buffer_DD02,384,&RSA_VerifyResult,CRYPTO_OPERATIONMODE_UPDATE);
                                Routine_DD02_Sign_Verify_Step = 3;
                                rc_size_to_be_Verify = 0;
                                Ret = DCM_E_PENDING;                           
                            }
                            else
                            {
                                /*the last one Block*/
                                test_RetVal = SampleCode_SignatureVerify(&PlainKey[12],HSM_SIGNATURE_ALGORITHM_RSA_v21,NULL_PTR,0,NULL_PTR, 0,
                                                                    Signature_Buffer_DD02,384,&RSA_VerifyResult,CRYPTO_OPERATIONMODE_FINISH);

                                if((test_RetVal == CSM_E_OK) && (RSA_VerifyResult==0) && (test_RetVal_hash == CSM_E_OK))
                                {
                                    Routine_DD02_NRC78_Flag = 0;
                                    *OutBuffer = 0;
                                    Ret = DCM_E_OK;
                                }
                                else
                                {
                                    Routine_DD02_NRC78_Flag = 0;
                                    *OutBuffer = 2;
                                    Ret = DCM_E_OK;
                                }

                            }
                        }
                        else
                        {
                            test_RetVal = SampleCode_SignatureVerify(&PlainKey[12],HSM_SIGNATURE_ALGORITHM_RSA_v21,NULL_PTR,0,(uint8 *)rc_addr_to_be_Verify, SIGNATURE_VERIFY_SIZE,
                                                                    Signature_Buffer_DD02,384,&RSA_VerifyResult,CRYPTO_OPERATIONMODE_UPDATE);

                            rc_size_to_be_Verify -= SIGNATURE_VERIFY_SIZE;
                            rc_addr_to_be_Verify +=SIGNATURE_VERIFY_SIZE;
                            Routine_DD02_Sign_Verify_Step = 3;
                            Ret = DCM_E_FORCE_RCRRP;
                        }
                    break;    
                    default:
                    break;
                }
            }

            if((Ret == DCM_E_OK) && (*OutBuffer == 0) && (HashAddr >= FLASHDRV_START_ADDR) && (HashAddr <= FLASHDRV_END_ADDR))
            {
                u8_FlashDrvcheck = 0x1;
            }
            else
            {
                u8_FlashDrvcheck = 0x0;
            }
            if((Ret == DCM_E_OK) && (*OutBuffer == 0) && (HashAddr >= 0xA0000000) && (HashAddr <= 0xA05FFFFF))
            {
                u8_AppUpdatecheck = 0x1;
                DFlashDriver_WriteDID_F162(DigestData_DD02);   //for test
            }
            else
            {
                u8_AppUpdatecheck = 0x0;
            }

        }
        else
        {
            //Reserve for Signature Check;
            *OutBuffer = 0x0;

            if((HashAddr >= FLASHDRV_START_ADDR) && (HashAddr <= FLASHDRV_END_ADDR))
            {
                u8_FlashDrvcheck = 0x1;
            }
            else
            {
                u8_FlashDrvcheck = 0x0;
            }
            if((HashAddr >= 0xA0000000) && (HashAddr <= 0xA05FFFFF))
            {
                u8_AppUpdatecheck = 0x1;
            }
            else
            {
                u8_AppUpdatecheck = 0x0;
            }
            Ret =  E_OK;
        }
    }

    return Ret;

}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD04_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
#if 0
	boolean Result = 1;
	uint8 Ret;
    boolean interruptState;
    MemIf_StatusType FlashStatus = MEMIF_IDLE;
    StatusType AlarmStatus = E_OK;
    TickType Tick = 0;

	Ret = E_OK;
	if(1 == HSM_InitStatus)
    {
        //FlashStatus =  Fls_17_Dmu_GetStatus();
        FlashStatus = MEMIF_IDLE;
        if((FlashStatus == MEMIF_IDLE) || (FlashStatus == MEMIF_UNINIT))
        {
            interruptState = IfxCpu_disableInterrupts(); /* Get the current state of the interrupts and disable them*/
            Result = configure_swap_MainFunc(Bank_Switch);
            Result = Enable_Swap_Config();
            IfxCpu_restoreInterrupts(interruptState);			/* Restore the interrupts state 	 */
        }
        else
        {
            Ret = DCM_E_FORCE_RCRRP;
        }

        if(1u == Result)
        {
            *OutBuffer = 0x0;
        }
        else
        {
            *OutBuffer = 0x1;
        }
    }
    else
    {
        //FlashStatus =  Fls_17_Dmu_GetStatus();
        FlashStatus = MEMIF_IDLE;
        if((FlashStatus == MEMIF_IDLE) || (FlashStatus == MEMIF_UNINIT))
        {
            interruptState = IfxCpu_disableInterrupts(); /* Get the current state of the interrupts and disable them*/
            Result = configure_swap_MainFunc(Bank_Switch);
            Result = Enable_Swap_Config();
            IfxCpu_restoreInterrupts(interruptState);			/* Restore the interrupts state 	 */
        }
        else
        {
            Ret = DCM_E_FORCE_RCRRP;
        }

        if(1u == Result)
        {
            *OutBuffer = 0x0;
        }
        else
        {
            *OutBuffer = 0x1;
        }
    }


    return Ret;
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD03_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392A_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392B_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392C_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392D_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392E_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392F_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3930_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3955_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3956_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395A_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395B_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD30_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD31_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD32_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD35_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD36_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD37_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD38_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD39_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xDD3A_Start(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392C_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392D_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392E_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x392F_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3930_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x3955_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395A_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0x395B_Stop(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/*PreConditon Check*/
Std_ReturnType  Dcm_Rte_PreConditonCheck = E_OK;
Std_ReturnType RTE_PreConditonCheck(void)
{
    return Dcm_Rte_PreConditonCheck;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*DcmDsdServiceRequestSupplierNotification*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern boolean AppValid;
extern boolean FblRecv1001;
Std_ReturnType  Rte_Call_Dcm_ServiceRequestSupplierNotification_DcmDsdServiceRequestSupplierNotification_0_Indication(
        uint8 SID,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)RequestData,
        uint16 DataSize,
        uint8 ReqType,
        uint16 SourceAddress,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR) ErrorCode)
{
    Std_ReturnType Ret = E_OK;

    if((DataSize == 2) && (SID == 0x10) && ((RequestData[1] == 0x01) || (RequestData[1] == 0x81)))
    {
        FblRecv1001 = TRUE;
    }

    return Ret;
}

Std_ReturnType  Rte_Call_Dcm_ServiceRequestSupplierNotification_DcmDsdServiceRequestSupplierNotification_0_Confirmation(
        uint8 SID,
        uint8 ReqType,
        uint16 SourceAddress,
        Dcm_ConfirmationStatusType ConfirmationStatus)
{
    if ((SID == 0x10) && ( ConfirmationStatus == DCM_RES_POS_OK) && (TRUE == FblRecv1001))
    {
        if(TRUE == AppValid)
        {
            Mcu_PerformReset();
            while(1);
        }
    }
    else
    {
        FblRecv1001 = FALSE;
    }

    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"



uint32 RESET_NVM_USE_TIME = 0;
uint8 ResetInitNvMReadAllStatus_DEM_1;
uint8 ResetInitNvMReadAllStatus_DEM_2;
uint8 ResetInitNvMReadAllStatus_DCM;
#define RESET_INIT_READALL_TIMEOUT  200000
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType SchM_PerformReset(Rte_ModeType_DcmEcuReset Reset)
{
    if (Reset == RTE_MODE_DcmEcuReset_EXECUTE)
    {
#if 0

     NvM_WriteBlock(DCM_DDDID_STORAGE_BLOCKID, NULL_PTR);
     Dem_Shutdown();

	  do
	  {
	     RESET_NVM_USE_TIME++;

	     Fls_17_Dmu_MainFunction();
	     Fee_MainFunction();
	     NvM_MainFunction();
	     NvM_GetErrorStatus(NvMBlockNvm_Block_DEM_1,&ResetInitNvMReadAllStatus_DEM_1);
	     NvM_GetErrorStatus(NvMBlockNvm_Block_DEM_2,&ResetInitNvMReadAllStatus_DEM_2);
	     NvM_GetErrorStatus(NvMBlockNvm_Block_DCM,&ResetInitNvMReadAllStatus_DCM);

	     if(RESET_INIT_READALL_TIMEOUT < RESET_NVM_USE_TIME)
         {
            RESET_NVM_USE_TIME = 0;
	     break;
         }
	  }while((ResetInitNvMReadAllStatus_DEM_1 == NVM_REQ_PENDING)||(ResetInitNvMReadAllStatus_DEM_2 == NVM_REQ_PENDING)||(ResetInitNvMReadAllStatus_DCM == NVM_REQ_PENDING));
#endif

        Mcu_PerformReset();
        while (1);
    }
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

