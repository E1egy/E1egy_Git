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
******************************************************************************************/

#include "HostCom_Test.h"
#include "TestHsm.h"

#if (HOSTCOM_TESTAPP == 1)
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
void HostCom_Test_InitSharedBuffer(void)
{
    /*Get address of global buffer*/
    HsmAes_Block *HostComDemo_Buffers = &(g_HsmComBuffers.ht2hsm[0].blocks[0]);
    /*Send addres of global buffer to HSM*/
    HSM_HT2HSMS.U = (uint32)HostComDemo_Buffers;
    /*On HSM Side verify the memory address is correct*/
    /*On HSM Side verify the memory address is Set to Zero*/
}

void HostCom_Test_WriteValue(void)
{
    /*Get address of global buffer*/
    HsmAes_Block *HostComDemo_Buffers = &(g_HsmComBuffers.ht2hsm[0].blocks[0]);
    /*Send addres of global buffer to HSM*/
    if((HostComDemo_Buffers->data[0] == 0xAFAFA5A5))
    {
        TEST_PRINTF("WriteValue PASSED\n");
    }
    else
    {
        TEST_PRINTF("WriteValue FAILED\n");
    }
    /*On HSM Side verify the memory address is correct*/
    /*On HSM Side verify the memory address is Set to Zero*/
}

void HostCom_Test_WriteBlock(void)
{
    HsmAes_Block *HostComDemo_Buffers = &(g_HsmComBuffers.ht2hsm[0].blocks[0]);
    HsmAes_Block HostComDemo_ReadPattern = {
            {0xAAAAAAAA, 0xBBBBBBBB, 0xCCCCCCCC, 0xDDDDDDDD}
    };
    if((HostComDemo_Buffers->data[0] == HostComDemo_ReadPattern.data[0]) && \
       (HostComDemo_Buffers->data[1] == HostComDemo_ReadPattern.data[1]) && \
       (HostComDemo_Buffers->data[2] == HostComDemo_ReadPattern.data[2]) && \
       (HostComDemo_Buffers->data[3] == HostComDemo_ReadPattern.data[3]))
    {
        TEST_PRINTF("WriteBlock PASSED\n");
    }
    else
    {
        TEST_PRINTF("WriteBlock FAILED\n");
    }
}

void HostCom_Test_ReadBlock(void)
{
    HsmAes_Block HostComDemo_ReadPattern = { {0xAFAFAFAF,0x54545454,0x68686868,0x12121212}};
    /*Get address of global buffer*/
    HsmAes_Block *HostComDemo_Buffers = &(g_HsmComBuffers.ht2hsm[0].blocks[0]);
    /*Send addrres of global buffer to HSM*/
    HostComDemo_Buffers->data[0] = HostComDemo_ReadPattern.data[0];
    HostComDemo_Buffers->data[1] = HostComDemo_ReadPattern.data[1];
    HostComDemo_Buffers->data[2] = HostComDemo_ReadPattern.data[2];
    HostComDemo_Buffers->data[3] = HostComDemo_ReadPattern.data[3];
    /*On HSM Side verify the memory address is correct*/
    /*On HSM Side verify the memory address is Set to Zero*/
}

void HostCom_Test_UpdateCommand(void)
{
    /*Load a command in sample data type*/
    HsmCom_PackedCommand HostComDemo_TestCommand;
    HostComDemo_TestCommand.B.command = HSMCOM_BOOT_MAC;
    /*Write command in HSM_HT2HSMF */
    HSM_HT2HSMF.U = HostComDemo_TestCommand.U;
}

void HostCom_Test_SetHsm2HtStatus(void)
{
    /*Write Status in HSM_HT2HSMS */
    if(((uint32)HSM_HSM2HTS.U == 0xAA55BB22))
    {
        TEST_PRINTF("SetHsm2HtStatus PASSED\n");
    }
    else
    {
        TEST_PRINTF("SetHsm2HtStatus FAILED\n");
    }
}

void HostCom_Test_GetHt2HsmStatus(void)
{
    /*Write Status in HSM_HT2HSMS */
    HSM_HT2HSMS.U = 0xAABBCCDD;
}

void HostCom_Test_GetKeyAddress(void)
{
    /*Write Status in HSM_HT2HSMS */
    HsmCom_PackedParams HostComDemo_TestKeyAddress;
    HostComDemo_TestKeyAddress.B.keyAddr = HSMCOM_KEY_4;
    HSM_HT2HSMS.U = HostComDemo_TestKeyAddress.U;
}

void HostCom_Test_GetAesMode(void)
{
    /*Write Status in HSM_HT2HSMS */
    HsmCom_PackedParams HostComDemo_TestKeyAddress;
    HostComDemo_TestKeyAddress.B.aesMode = HSMCOM_AES_MODE_CTR;
    HSM_HT2HSMS.U = HostComDemo_TestKeyAddress.U;
}

void HostCom_Test_UpdateParams_SizeEqualAes(void)
{
    /*clear buffer */
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[0] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[1] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[2] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[3] = 0;

    g_HsmComBuffers.ht2hsm[0].blocks[1].data[0] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[1].data[1] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[1].data[2] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[1].data[3] = 0;

    /*Write pattern*/
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[0] = 0x11223344;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[1] = 0x55667788;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[2] = 0x99AABBCC;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[3] = 0xDDEEFF11;

}

void HostCom_Test_UpdateParams_SizeMoreAes(void)
{
    /*clear buffer */
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[0] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[1] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[2] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[3] = 0;

    g_HsmComBuffers.ht2hsm[0].blocks[1].data[0] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[1].data[1] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[1].data[2] = 0;
    g_HsmComBuffers.ht2hsm[0].blocks[1].data[3] = 0;

    /*Write pattern*/
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[0] = 0x11223344;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[1] = 0x55667788;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[2] = 0x99AABBCC;
    g_HsmComBuffers.ht2hsm[0].blocks[0].data[3] = 0xDDEEFF11;

    g_HsmComBuffers.ht2hsm[0].blocks[1].data[0] = 0x11223344;
    g_HsmComBuffers.ht2hsm[0].blocks[1].data[1] = 0x55667788;
    g_HsmComBuffers.ht2hsm[0].blocks[1].data[2] = 0x99AABBCC;
    g_HsmComBuffers.ht2hsm[0].blocks[1].data[3] = 0xDDEEFF11;
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
#endif /*HOSTCOM_TESTAPP*/
