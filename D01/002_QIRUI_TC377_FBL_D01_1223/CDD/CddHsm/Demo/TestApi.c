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

#include "TestApi.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
#if 0

/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_doSendCommand(HsmCom_Session session, HsmCom_Command command)
{
    HsmCom_Error retVal = HsmCom_SendCommand(session, command);

    if (retVal == HSMCOM_ERC_NO_ERROR)
    {
        while (HsmCom_IsBusy(session) != FALSE) { //Sleep(1); }
        retVal = HsmCom_GetLastError(session);
    }

    return retVal;
}


/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_finalizeSession(HsmCom_Session session, HsmCom_Command command)
{
    HsmCom_Error retVal = TestApi_doSendCommand(session, command);
    HsmCom_CloseSession(session);

    return retVal;
}

/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_randomSetSeed(const void *seed)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        HsmCom_RandomSeedParams *params = HsmCom_GetParamsBuffer(session);
        params->SeedAddr = (HostAddr) seed;
        //retVal = TestApi_finalizeSession(session, HSMCOM_CMD_RND_SEED_SET);
    }

    return retVal;
}
#endif

#if (0)
/*
 *These functions not used any more
 */


/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_randomGenerate(void *output)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        HsmCom_RandomGenerateParams *params = HsmCom_GetParamsBuffer(session);
        params->destAddr = (HostAddr) output;
        retVal = TestApi_finalizeSession(session, HSMCOM_CMD_RND_GEN);
    }

    return retVal;
}

/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_aesEncrypt(HsmCom_KeyAddr keyAddr, HsmCom_AesMode mode, const void *initVect, const void *input, void *output, uint32 nBlocks)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        HsmCom_CryptParams *params = HsmCom_GetParamsBuffer(session);
        params->initialVarAddr = (HostAddr) initVect;
        params->sourceAddr = (HostAddr) input;
        params->destAddr = (HostAddr) output;
        params->nBlocks = nBlocks;

        HsmCom_setPackedParams(session, keyAddr, mode);
        retVal = TestApi_finalizeSession(session, HSMCOM_CMD_AES_ENCRYPT);
    }

    return retVal;
}


/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_aesDecrypt(HsmCom_KeyAddr keyAddr, HsmCom_AesMode mode, const void *initVect, const void *input, void *output, uint32 nBlocks)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        HsmCom_CryptParams *params = HsmCom_GetParamsBuffer(session);
        params->initialVarAddr = (HostAddr) initVect;
        params->sourceAddr = (HostAddr) input;
        params->destAddr = (HostAddr) output;
        params->nBlocks = nBlocks;

        HsmCom_setPackedParams(session, keyAddr, mode);
        retVal = TestApi_finalizeSession(session, HSMCOM_CMD_AES_DECRYPT);
    }

    return retVal;
}


/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_ecbEncrypt(HsmCom_KeyAddr keyAddr, const void *input, void *output)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        HsmCom_CryptParams *params = HsmCom_GetParamsBuffer(session);
        params->sourceAddr = (HostAddr) input;
        params->destAddr = (HostAddr) output;
        params->nBlocks = 1U;

        HsmCom_setPackedParams(session, keyAddr, 0);
        retVal = TestApi_finalizeSession(session, HSMCOM_CMD_ECB_ENCRYPT);
    }

    return retVal;
}

/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_ecbDecrypt(HsmCom_KeyAddr keyAddr, const void *input, void *output)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        HsmCom_CryptParams *params = HsmCom_GetParamsBuffer(session);
        params->sourceAddr = (HostAddr) input;
        params->destAddr = (HostAddr) output;
        params->nBlocks = 1U;

        HsmCom_setPackedParams(session, keyAddr, 0);
        retVal = TestApi_finalizeSession(session, HSMCOM_CMD_ECB_DECRYPT);
    }

    return retVal;
}


/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_exportKey(HsmCom_KeyAddr id, HsmCom_KeyAddr authId, void *m1, void *m2, void *m3, void *m4, void *m5)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        HsmCom_ExportKeyParams *params = HsmCom_GetParamsBuffer(session);
        HsmCom_setPackedParams(session, id, authId);
        params->M1Addr = (HostAddr)m1;
        params->M2Addr = (HostAddr)m2;
        params->M3Addr = (HostAddr)m3;
        params->M4Addr = (HostAddr)m4;
        params->M5Addr = (HostAddr)m5;
        retVal = TestApi_finalizeSession(session, HSMCOM_CMD_KEY_EXPORT);
    }

    return retVal;
}

/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_exportRamKey(void *m1, void *m2, void *m3, void *m4, void *m5)
{
    return TestApi_exportKey(HSMCOM_RAM_KEY, HSMCOM_SECRET_KEY, m1, m2, m3, m4, m5);
}

/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_loadKey(const void *m1, const void *m2, const void *m3, void *m4, void *m5)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        HsmCom_ExportKeyParams *params = HsmCom_GetParamsBuffer(session);
        params->M1Addr = (HostAddr) m1;
        params->M2Addr = (HostAddr) m2;
        params->M3Addr = (HostAddr) m3;
        params->M4Addr = (HostAddr) m4;
        params->M5Addr = (HostAddr) m5;
        retVal = TestApi_finalizeSession(session, HSMCOM_CMD_KEY_LOAD);
    }

    return retVal;
}


/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_loadPlainKey(const void *key)
{
    HsmCom_Error retVal = HSMCOM_ERC_NO_ERROR;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session == HSMCOM_INVALID_SESSION)
    {
        retVal = HSMCOM_ERC_BUSY;
    }
    else
    {
        HsmCom_LoadPlainKeyParams *params = HsmCom_GetParamsBuffer(session);
        params->keyAddr = (HostAddr)key;

        retVal = HsmCom_sendCommand(session, HSMCOM_CMD_KEY_LOAD_PLAIN);

        if (retVal == HSMCOM_ERC_NO_ERROR)
        {
            while (HsmCom_isBusy(session) != FALSE) { //Sleep(1); }
        }

        retVal = HsmCom_getLastError(session);
        HsmCom_closeSession(session);
    }

    return retVal;
}


/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_generateMac(HsmCom_KeyAddr keyAddr, const void *msg, uint32 msgBits, void *mac)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        HsmCom_setPackedParams(session, keyAddr, 0);
        retVal = TestApi_doSendCommand(session, HSMCOM_CMD_MAC_GEN_START);
    }

    if (retVal == HSMCOM_ERC_NO_ERROR)
    {
        HsmCom_MacUpdateParams *params = HsmCom_GetParamsBuffer(session);
        params->sourceAddr = (HostAddr)msg;
        params->sizeBits = msgBits;

        retVal = TestApi_doSendCommand(session, HSMCOM_CMD_MAC_UPDATE);
    }

    if (retVal == HSMCOM_ERC_NO_ERROR)
    {
        HsmCom_MacGenerateParams *params = HsmCom_GetParamsBuffer(session);
        params->macOutputAddr = (HostAddr) mac;

        retVal = TestApi_finalizeSession(session, HSMCOM_CMD_MAC_GEN_FINISH);
    }

    return retVal;
}

/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_verifyMac(HsmCom_KeyAddr keyAddr, const void *msg, uint32 msgBits, const void *mac, uint32 macBits, boolean *result)
{
    HsmCom_Error retVal = HSMCOM_ERC_NO_ERROR;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session == HSMCOM_INVALID_SESSION)
    {
        retVal = HSMCOM_ERC_BUSY;
    }
    else
    {
        HsmCom_setPackedParams(session, keyAddr, 0);
        retVal = TestApi_doSendCommand(session, HSMCOM_CMD_MAC_VER_START);
    }

    if (retVal == HSMCOM_ERC_NO_ERROR)
    {
        HsmCom_MacUpdateParams *params = HsmCom_GetParamsBuffer(session);
        params->sourceAddr = (HostAddr)msg;
        params->sizeBits = msgBits;

        retVal = TestApi_doSendCommand(session, HSMCOM_CMD_MAC_UPDATE);
    }

    if (retVal == HSMCOM_ERC_NO_ERROR)
    {
        HsmCom_MacVerifyParams *params = HsmCom_GetParamsBuffer(session);
        params->macInputAddr = (HostAddr) mac;
        params->verifyBits = macBits;

        retVal = TestApi_doSendCommand(session, HSMCOM_CMD_MAC_VER_FINISH);
    }

    if (retVal == HSMCOM_ERC_NO_ERROR)
    {
        *result = HsmCom_isMacVerifyOk(session);
        HsmCom_closeSession(session);
    }

    return retVal;
}

/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_randomInit(void)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        retVal = TestApi_finalizeSession(session, HSMCOM_CMD_RND_INIT);
    }

    return retVal;
}


/*************************************************************************************//**
 *
 ****************************************************************************************/
HsmCom_Error TestApi_randomExtendSeed(const void *entropy)
{
    HsmCom_Error retVal = HSMCOM_ERC_BUSY;
    HsmCom_Session session = HsmCom_OpenSession();

    if (session != HSMCOM_INVALID_SESSION)
    {
        HsmCom_RandomSeedParams *params = HsmCom_GetParamsBuffer(session);
        params->seedAddr = (HostAddr) entropy;
        retVal = TestApi_finalizeSession(session, HSMCOM_CMD_RND_SEED_EXTEND);
    }

    return retVal;
}
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
