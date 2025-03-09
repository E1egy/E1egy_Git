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
**  FILENAME    : Xcp_Ram.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Defined array variables for XCP                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*=======[I N C L U D E S]====================================================*/
#include "Xcp_Internal.h"
#define XCP_START_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"
VAR(uint8, XCP_VAR_NO_INIT_8) Xcp_CmdBuffer[XCP_MAX_CTO];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"
VAR(uint8, XCP_VAR_NO_INIT_8) Xcp_RespBuffer[XCP_MAX_CTO];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"
VAR(uint8, XCP_VAR) Xcp_EvBuffer[XCP_CTO_BUFFER_SIZE];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"
VAR(uint8, XCP_VAR) Xcp_ServBuffer[XCP_CTO_BUFFER_SIZE];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"

#if (XCP_PL_DAQ == (XCP_PL_DAQ & XCP_RESOURCE))
#define XCP_START_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"
VAR(uint8, XCP_VAR) Xcp_DaqBuffer[XCP_DTO_BUFFER_SIZE];
VAR(uint8, XCP_VAR_NO_INIT_8) Xcp_EvChActivCnt[XCP_MAX_EVENT_CHANNEL]; /* counts of running daq in eventchannel */
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"

#if (XCP_DAQ_CONFIG_TYPE == XCP_DAQ_DYNAMIC)
#define XCP_START_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"
VAR(uint8, XCP_VAR) Xcp_DynDaqBuffer[XCP_DYNAMIC_DAQ_BUFFER_SIZE]; /* Dynamic : size of allocArry[]  */
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"
#endif /* (XCP_DAQ_CONFIG_TYPE == XCP_DAQ_DYNAMIC) */

#define XCP_START_SEC_VAR_CLEARED_16
#include "XCP_MemMap.h"
VAR(Xcp_DaqNumType, XCP_VAR) Xcp_DaqListQueue[XCP_MAX_DAQ];
#define XCP_STOP_SEC_VAR_CLEARED_16
#include "XCP_MemMap.h"

#define XCP_START_SEC_VAR_SAVED_ZONE_16
#include "XCP_MemMap.h"
VAR(Xcp_DaqType, XCP_VAR) Xcp_Daq[XCP_MAX_DAQ];
#define XCP_STOP_SEC_VAR_SAVED_ZONE_16
#include "XCP_MemMap.h"

#if (XCP_DAQ_CONFIG_TYPE == XCP_DAQ_DYNAMIC)
#define XCP_START_SEC_VAR_INIT_UNSPECIFIED
#include "XCP_MemMap.h"
VAR(Xcp_DynamicalDaqQueueType, XCP_VAR) Xcp_DynamicalDaqQueue =
{
        XCP_DYNAMIC_DAQ_BUFFER_SIZE,
        0
};
#define XCP_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "XCP_MemMap.h"
#endif /* (XCP_DAQ_CONFIG_TYPE == XCP_DAQ_DYNAMIC) */

#define XCP_START_SEC_VAR_CLEARED_32
#include "XCP_MemMap.h"
VAR(uint32, XCP_VAR) Xcp_EvChBufferUsage[XCP_MAX_EVENT_CHANNEL];
#define XCP_STOP_SEC_VAR_CLEARED_32
#include "XCP_MemMap.h"
#endif /* (XCP_PL_DAQ == (XCP_PL_DAQ & XCP_RESOURCE)) */
/*
 * Block transfer
 * */
#if (XCP_MASTER_BLOCK_MODE == STD_ON)
#define XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "XCP_MemMap.h"
VAR(Xcp_AGType, XCP_VAR) Xcp_BlockBuffer[XCP_BLOCK_BUFFER_SIZE];
#define XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "XCP_MemMap.h"
#endif

/*
 * CAL
 * */
#if (XCP_PL_CAL == (XCP_PL_CAL&XCP_RESOURCE))
#if (XCP_PAG_SUPPORT == STD_ON)
#define XCP_START_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"
VAR(uint8, XCP_VAR) Xcp_ActivPagNum[XCP_MAX_SEGMENT];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "XCP_MemMap.h"
#endif
#endif

/*
 * Build_checksum
 * */
#if (XCP_BUILD_CHECKSUM == STD_ON)
#define XCP_START_SEC_VAR_CLEARED_16
#include "XCP_MemMap.h"
VAR(uint16, XCP_VAR) Xcp_Crc16CittTable[256u];
#define XCP_STOP_SEC_VAR_CLEARED_16
#include "XCP_MemMap.h"
#endif
