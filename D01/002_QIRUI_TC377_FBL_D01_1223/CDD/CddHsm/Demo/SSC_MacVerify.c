/*****************************************************************************************
**                                                                                      **
** Copyright (C) Infineon Technologies (2014)                                           **
**                                                                                      **
** All rights reserved.                                                                 **
**                                                                                      **
** This document contains proprietary information belonging to Infineon                 **
** Technologies. Passing on and copying of this document, and communication             **
** of its contents is not permitted without prior written authorization.                **
**                                                                                      **
** THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. INFINEON TECHNOLOGIES          **
** RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER          **
** REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR         **
** THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.                          **
**                                                                                      **
** INFINEON TECHNOLOGIES SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR                **
** CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR        **
** ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR              **
** PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE        **
** DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION         **
** WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR        **
** PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON        **
** WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.                                   **
**                                                                                      **
**************************************************************************************//**
*
*  \FILE      Ssc_MacVerify.c
*
*  \BRIEF     Sample implementation the safe Ssc_MacVerify functionality
*
*  \DATE      2014.11.11
*
*  \AUTHOR    Volker Elies [volker.elies@hitex.de]
*
*  \VENDOR    Infineon Technologies, A.G.
*
*  \REFERENCE <spec name, version>
*
*//**************************************************************************************/
#include "Std_Types.h"
#include "IfxStm_reg.h"
#include "Ssc_MacVerify.h"
#include "Csm_MacVerify.h"
#include "Cry_Hsm.h"
#include "TestHsmConst.h"
#include "TestHsm.h"

#define CRY_START_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/* Masks for padding MAC values with less than 32 valid bits in their last 32
 * bits block.
 * As the MAC values come MSB first, with also most significant bits first,
 * masking the most significant bits for padding the remaining bits with 0
 * must take this into account
 */
const uint32 Crypto_MacBitMasks[31] =
{
    0x00000080U, 0x000000C0U, 0x000000E0U, 0x000000F0U,
    0x000000F8U, 0x000000FCU, 0x000000FEU, 0x000000FFU,
    0x000080FFU, 0x0000C0FFU, 0x0000E0FFU, 0x0000F0FFU,
    0x0000F8FFU, 0x0000FCFFU, 0x0000FEFFU, 0x0000FFFFU,
    0x0080FFFFU, 0x00C0FFFFU, 0x00E0FFFFU, 0x00F0FFFFU,
    0x00F8FFFFU, 0x00FCFFFFU, 0x00FEFFFFU, 0x00FFFFFFU,
    0x80FFFFFFU, 0xC0FFFFFFU, 0xE0FFFFFFU, 0xF0FFFFFFU,
    0xF8FFFFFFU, 0xFCFFFFFFU, 0xFEFFFFFFU
};
#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include "Cry_MemMap.h"
/* This is only used if CryHsmPrototype is configured for safe verification */
#if (CRY_HSM_MAC_SAFE_VERIFY == 1)


#define SwapBytes(w) ((0x00FFU & ((uint16)(w)>>8)) | (0xFF00U & ((uint16)(w)<<8)))
#define ToDword(h,l) (((uint32)l) | (0xFFFF0000UL & ((uint32)h<<16)))

#define CRY_START_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"
uint32 Testcrc32;
uint32 TestCmacXor_u32;
uint32 Testmacver_a,Testmacver_b,Testmacver_c,Testmacver_d,Testmacver_e,Testmacver_f,Testmacver_g,Testmacver_h,Testmacver_i;
#define CRY_STOP_SEC_VAR_UNSPECIFIED
#include "Cry_MemMap.h"

_IFXEXTERN_ IFX_INLINE uint32 CalculateMacCrc (const void* macIn, uint32 verifyLength,uint32 crc)
{
	uint32 dwCount = verifyLength >> 5;					/* Full dwords */
	uint32 bitCnt  = (verifyLength & 0x00000001F);      /* Remaining bits: 0 .. 31 */
	uint32 mask = 0;
	uint32 i;
	const uint32* macPtr = (const uint32*)macIn;

	if (bitCnt > 0)
	{
		mask = 0xFFFFFFFFUL << (32U-bitCnt);
	}

	for (i = 0; i <= dwCount; i++)
	{
		uint32 value = *macPtr;
		/* value must be passed in big-endian byte order */
		/*value = ToDword(SwapBytes(value & 0xFFFFU), SwapBytes((value >> 16) & 0xFFFF));*/

		if (i < dwCount)
		{
			crc = crc ^ value;
		}
		else if (mask != 0UL)
		{
			/* Mask remaining bits, finish calculation */
			value = value & mask;
			crc = crc ^ value;
		}
		else
		{
			/* finished */
		}
		macPtr++;
	}
	crc = crc^0xffffffff;
	Testcrc32 = crc;
	return (crc);
}

_IFXEXTERN_ IFX_INLINE uint32 CalculateMacXor(const void* macIn,uint32 CompareBits,uint32 initXorValue)
{
    uint32 Count = (CompareBits >> 5U);
    const uint32* MacInData  = (const uint32*)macIn;
    uint32 CmacXor = initXorValue;

    while (Count != 0UL)
    {
         /* calculate XOR over *MacInData with CmacXor */
        CmacXor = (CmacXor ^ (*MacInData));
        /* next DWORD */
        MacInData++;
        Count--;
    }
    /* Compare remaining bits */
    Count = CompareBits & 0x0000001FUL;
    if (Count != 0UL)
    {
        uint32 BitMask = Crypto_MacBitMasks[Count-1];
        uint32 RemainingValue = (*MacInData & BitMask);
        /* calculate XOR over *MacInData with BitMask */
        CmacXor = (CmacXor ^ RemainingValue);
    }
    TestCmacXor_u32 = CmacXor;
    return CmacXor;
}



#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
boolean Ssc_SafeMacVerify( const Csm_SymKeyType* keyPtr, const uint8* dataPtr, uint32 dataLength, const uint8* MacPtr, uint32 MacLength)
{
	Csm_SafeVerifyResultType verifyResult = {CSM_E_VER_NOT_OK, 0U, 0U, 0U, 0U,0U,0U};
	boolean verified = FALSE;
	volatile Csm_ReturnType result;
    const Cry_HsmAesCMacVerifyConfigType* config;
    config = &Cry_kHsmAesCMacVerifyConfig;

    Testmacver_a = STM0_TIM0.U;
    result = Cry_HsmAesCMacVerifyStart(config, keyPtr);

    Testmacver_b = STM0_TIM0.U;
    Testmacver_c = Testmacver_b-Testmacver_a;

#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif


    if (result != CSM_E_BUSY)
    {
        Testmacver_d = STM0_TIM0.U;
        result = Cry_HsmAesCMacVerifyUpdate(config, (const uint8*)dataPtr, dataLength);

        Testmacver_e = STM0_TIM0.U;
        Testmacver_f = Testmacver_e-Testmacver_d;

#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

        Testmacver_g = STM0_TIM0.U;
        result = Cry_HsmAesCMacVerifyFinish(config, (const uint8*)MacPtr, MacLength, (Csm_VerifyResultType*)&verifyResult);

        Testmacver_h = STM0_TIM0.U;
        Testmacver_i = Testmacver_h-Testmacver_g;

#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

		if ((result == CSM_E_OK) && (verifyResult.Result == CSM_E_VER_OK))
	    {
	/*    	if (((MacLength * 2) == verifyResult.BitsCompared1) &&
				((verifyResult.BitsCompared1 << 1) == verifyResult.BitsCompared2)
				&& (verifyResult.TotalDataLength == (dataLength * 2)))              */
			{
				/* Check the CRCs */
				uint32 invertedMac[4];
				uint32* tempMacPtr = (uint32*) MacPtr;
				uint32 dwCount = (MacLength + 31U) >> 5;
				uint32 i;

				/* Create inverted MAC */
				for (i = 0; i < dwCount; i++)
				{
					invertedMac[i] = ~(*tempMacPtr);
					tempMacPtr++;
				}
				/* Now calculate the CRC values and compare them
				 * with the coded results returned by Csm_MacVerifyFinish
				 */
                if ((verifyResult.CodedResult1 == CalculateMacXor(MacPtr, MacLength,0xFFFFFFFF)) &&
                    (verifyResult.CodedResult2 == CalculateMacXor(invertedMac, MacLength,0xAAAAAAAA))&&
                    (verifyResult.BitsCompared1 == MacLength * 2) &&
                    (verifyResult.BitsCompared2 == MacLength * 4) &&
                    (verifyResult.DataPtr == (((uint32)dataPtr) ^ 0xFFFFFFFF))&&
                    (verifyResult.DataLength == (dataLength *2)))
 				{
					verified = TRUE;
				}
				else
				{
					/* verified is initialized to FALSE */
				}
			}
	/*		else
			{

			}  */
		}

	}
    else
    {
    	/* Do any necessary handling in case service is still busy */
    }

    TEST_PRINTF("\n %f start ,%f update ,%f finish \n", (Testmacver_c*TEST_TIME_CONSTANT),(Testmacver_f*TEST_TIME_CONSTANT),(Testmacver_i*TEST_TIME_CONSTANT));
    TEST_PRINTF("\n %f totaltime \n", ((Testmacver_c + Testmacver_f + Testmacver_i)*TEST_TIME_CONSTANT));

	return (verified);
}

boolean Ssc_SafeMacVerifyNeg( const Csm_SymKeyType* keyPtr, const uint8* dataPtr, uint32 dataLength, const uint8* MacPtr, uint32 MacLength)
{
    Csm_SafeVerifyResultType verifyResult = {CSM_E_VER_NOT_OK, 0U, 0U, 0U, 0U,0U,0U};
    boolean verified = FALSE;
    volatile Csm_ReturnType result;

    result = Csm_MacVerifyStart(MyCsmApplication_MacVerify_Id, keyPtr);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif


    if (result != CSM_E_BUSY)
    {
        result = Csm_MacVerifyUpdate(MyCsmApplication_MacVerify_Id, (const uint8*)dataPtr, dataLength);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

        result = Csm_MacVerifyFinish(MyCsmApplication_MacVerify_Id, (const uint8*)MacPtr, MacLength, (Csm_VerifyResultType*)&verifyResult);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

        if ((result == CSM_E_OK) && (verifyResult.Result != CSM_E_VER_OK))
        {
    /*      if (((MacLength * 2) == verifyResult.BitsCompared1) &&
                ((verifyResult.BitsCompared1 << 1) == verifyResult.BitsCompared2)
                && (verifyResult.TotalDataLength == (dataLength * 2)))              */
            {
                /* Check the CRCs */

/*              uint32 invertedMac[4];
                uint32* tempMacPtr = (uint32*) MacPtr;
                uint32 dwCount = (MacLength + 31U) >> 5;
                uint32 i;

                for (i = 0; i < dwCount; i++)
                {
                    invertedMac[i] = ~(*tempMacPtr);
                    tempMacPtr++;
                } */

                /* Now calculate the CRC values and compare them
                 * with the coded results returned by Csm_MacVerifyFinish
                 */
                if ((verifyResult.CodedResult1 == 0U) &&
                    (verifyResult.CodedResult2 == 0U)&&
                    (verifyResult.BitsCompared1 == 0U) &&
                    (verifyResult.BitsCompared2 == 0U) &&
                    (verifyResult.DataPtr == 0U)&&
                    (verifyResult.DataLength == 0U))
                {
                    verified = TRUE;
                }
                else
                {
                    /* verified is initialized to FALSE */
                }
/*                UNUSED_PARAMETER(invertedMac) */
            }
    /*      else
            {

            }  */
        }

    }
    else
    {
        /* Do any necessary handling in case service is still busy */
    }

    return (verified);
}

boolean Ssc_SafeMacVerifyMultipleUpdate( const Csm_SymKeyType* keyPtr, const uint8* dataPtr, uint32 dataLength, const uint8* MacPtr, uint32 MacLength)
{
    Csm_SafeVerifyResultType verifyResult = {CSM_E_VER_NOT_OK, 0U, 0U, 0U, 0U,0U,0U};
    boolean verified = FALSE;
    volatile Csm_ReturnType result;
    uint32  DataXorvalue;

    DataXorvalue = 0xFFFFFFFFU;

    result = Csm_MacVerifyStart(MyCsmApplication_MacVerify_Id, keyPtr);

#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif


    if (result != CSM_E_BUSY)
    {
        result = Csm_MacVerifyUpdate(MyCsmApplication_MacVerify_Id, (const uint8*)TEST_CONST_PLAIN_1, 16);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

    DataXorvalue = ((uint32)TEST_CONST_PLAIN_1 ^ DataXorvalue);

        result = Csm_MacVerifyUpdate(MyCsmApplication_MacVerify_Id, (const uint8*)TEST_CONST_PLAIN_2, 16);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

    DataXorvalue = ((uint32)TEST_CONST_PLAIN_2 ^ DataXorvalue);

        result = Csm_MacVerifyUpdate(MyCsmApplication_MacVerify_Id, (const uint8*)TEST_CONST_PLAIN_3, 16);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

    DataXorvalue = ((uint32)TEST_CONST_PLAIN_3 ^ DataXorvalue);

        result = Csm_MacVerifyUpdate(MyCsmApplication_MacVerify_Id, (const uint8*)TEST_CONST_PLAIN_4, 16);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif

    DataXorvalue = ((uint32)TEST_CONST_PLAIN_4 ^ DataXorvalue);

        result = Csm_MacVerifyFinish(MyCsmApplication_MacVerify_Id, (const uint8*)MacPtr, MacLength, (Csm_VerifyResultType*)&verifyResult);
#if ((CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF))
    TEST_WAIT(&Cry_HsmAesCMacVerifyMainFunction, &g_TestHsm_mac.callbackSet);
#endif


        if ((result == CSM_E_OK) && (verifyResult.Result == CSM_E_VER_OK))
        {
            if (((MacLength * 2) == verifyResult.BitsCompared1) &&
                ((verifyResult.BitsCompared1 << 1) == verifyResult.BitsCompared2)
                )
            {
                /* Check the CRCs */
                uint32 invertedMac[4];
                uint32* tempMacPtr = (uint32*) MacPtr;
                uint32 dwCount = (MacLength + 31U) >> 5;
                uint32 i;

               /* Create inverted MAC */
                for (i = 0; i < dwCount; i++)
                {
                    invertedMac[i] = ~(*tempMacPtr);
                    tempMacPtr++;
                }

                /* Now calculate the CRC values and compare them
                 * with the coded results returned by Csm_MacVerifyFinish
                 */
                /*if ((verifyResult.CodedResult1 == CalculateMacCrc(MacPtr, MacLength,0xFFFFFFFF)) &&
                    (verifyResult.CodedResult2 == CalculateMacCrc(invertedMac, MacLength,0xAAAAAAAA)))*/
                if ((verifyResult.CodedResult1 == CalculateMacXor(MacPtr, MacLength,0xFFFFFFFF)) &&
                    (verifyResult.CodedResult2 == CalculateMacXor(invertedMac, MacLength,0xAAAAAAAA)) &&
                    (verifyResult.DataPtr == DataXorvalue)&&
                    (verifyResult.DataLength == 128))
                {
                    verified = TRUE;
                }
                else
                {
                    /* verified is initialized to FALSE */
                }
            }
            else
            {
                /* verified is initialized to FALSE */
            }
        }

    }
    else
    {
        /* Do any necessary handling in case service is still busy */
    }
    UNUSED_PARAMETER(dataPtr)
    UNUSED_PARAMETER(dataLength)
    return (verified);
}

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
#endif
