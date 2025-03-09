/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2016)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Xcp_Interface.c                                             **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Interface functions with other modules                      **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*=======[I N C L U D E S]====================================================*/
#include "Xcp_Interface.h"
#include "Xcp_Internal.h"

#if (XCP_BUILD_CHECKSUM == STD_ON)
#define XCP_START_SEC_CODE
#include "XCP_MemMap.h"
static uint16 XcpCrc16Ccitt(const uint16* pu1data, uint16 u2Crc);
static uint16 Xcp_GetCrc16Citt(uint8* data, uint16 crc);
#define XCP_STOP_SEC_CODE
#include "XCP_MemMap.h"
#endif
#if (STD_ON == XCP_SEED_AND_UNLOCK )
#define XCP_START_SEC_CODE
#include "XCP_MemMap.h"
Std_ReturnType Xcp_CreateSeed(uint8* length, uint8* seed, const uint8 resource)
{
    uint8 i;
    *length = resource;
    for (i = 0; i < *length; i++)
    {
        seed[i] = i;
    }

    return E_OK;
}

boolean Xcp_IsKeyRight(
        const Xcp_SeedVerifyType seedVerify,
        const Xcp_KeyVerifyType keyVerify,
        const uint8 resource
)
{
    uint8 i;
    if ((keyVerify.lengthK == resource)
    && (seedVerify.lengthS == resource))
    {
        for (i = 0; i < keyVerify.lengthK; i++)
        {
            if (keyVerify.key[i] != (seedVerify.seed[i] + seedVerify.seed[i/2u]))
            {
                break;
            }
        }
        if (resource != i)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    else
    {
        return FALSE;
    }
}
#define XCP_STOP_SEC_CODE
#include "XCP_MemMap.h"
#endif /* (STD_ON == XCP_SEED_AND_UNLOCK ) */

#if (STD_ON == XCP_BUILD_CHECKSUM)
#define XCP_START_SEC_CODE
#include "XCP_MemMap.h"
static uint16 XcpCrc16Ccitt(const uint16* pu1data, uint16 u2Crc)
{
    uint8 CrCCounter;
    uint16 t_u2_ccitt16 = (uint16)0x1021u;
    u2Crc ^= ((uint16)(*pu1data) << 8u);
    for (CrCCounter = 0u; CrCCounter < 8u; CrCCounter++)
    {
        if ((u2Crc & (uint16)0x8000u) == (uint16)0x8000u)
        {
            u2Crc <<= 1;
            u2Crc ^= t_u2_ccitt16;
        }
        else
        {
            u2Crc <<= 1;
        }
    }
    return u2Crc;
}

/* Init the Xcp_Crc16CittTable */
void Xcp_InitCrc16CcittTable(void)
{
    uint16 i;
    for (i=0u; i<256u; i++)
    {
        Xcp_Crc16CittTable[i] = XcpCrc16Ccitt(&i, 0);
    }
}

static uint16 Xcp_GetCrc16Citt(uint8* data, uint16 crc)
{
    uint8 c;
    c = crc >> 8;
    crc <<= 8;
    crc ^= Xcp_Crc16CittTable[(*data) ^ c];
    return crc;
}

FUNC(void, XCP_CODE) Xcp_ChecksumCompute(const uint32 checksumStartAddress, const uint32 blockSize, uint32* crcResult)
{
    uint32 i;
    uint16 t_u2Result;
    t_u2Result = (uint16)0xffffu;

    for (i = 0; i < blockSize; i++)
    {
        t_u2Result = Xcp_GetCrc16Citt((uint8 *)(checksumStartAddress + i), t_u2Result);
    }
    *crcResult = (uint32)t_u2Result;

    return ;
}
#define XCP_STOP_SEC_CODE
#include "XCP_MemMap.h"
#endif /* (STD_ON == XCP_BUILD_CHECKSUM) */

#if (STD_ON == XCP_PAG_SUPPORT)
#define XCP_START_SEC_CODE
#include "XCP_MemMap.h"
void Xcp_InitCalMem(void)
{
    /*Overlay or MMU init.*/
    return;
}
#define XCP_STOP_SEC_CODE
#include "XCP_MemMap.h"
#endif /*(STD_ON == XCP_PAG_SUPPORT)*/
