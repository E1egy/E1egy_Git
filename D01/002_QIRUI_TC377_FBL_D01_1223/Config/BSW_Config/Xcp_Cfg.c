/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Xcp_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2022-11-24 17:36:06>
 */
/*============================================================================*/

#include "Xcp.h"
/*
 *  GetId CMD Config
 */
#define XCP_START_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"
static CONST(uint8, XCP_CONST_PBCFG) IdInfo1[5] = {"test"};
#define XCP_STOP_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(Xcp_IdInfoType, XCP_CONST_PBCFG) Xcp_IdInfo[XCP_NUM_OF_ID] =
{
    {
        1, 0, sizeof(IdInfo1), &IdInfo1[0]
    }
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(XcpDtoType, XCP_CONST_PBCFG) Xcp_Dto[1] =
{
    {
        0,/*XcpFirstPid*/
        &Xcp_Daq_Pdu[0] /*XcpDto2PduMapping*/    
    },
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"                                                                        
static CONST(Xcp_DaqListConfigType, XCP_CONST_PBCFG) Xcp_DaqConfig[XCP_MAX_DAQ] =
{
    {
        0,/*XcpDaqListNumber*/
        DAQ, /* XcpDaqListtype */
        0,  /* XcpDaqSize */
        &Xcp_Dto[0],  /* XcpDto */ 
        NULL_PTR   /* XcpOdt */                                             
    }                                                                
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
static VAR(Xcp_AGType, XCP_VAR) Xcp_EvCh0Buffer[XCP_EVCHBUFFER_0_DEPTH]; 
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"
static CONST(uint8, XCP_CONST_PBCFG) Xcp_Evch_0[MAX_EVCH_NAME_LENGTH] = { "EventChannel_0" };
#define XCP_STOP_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_16
#include "Xcp_MemMap.h"
static CONST(Xcp_DaqNumType, XCP_CONST_PBCFG) Xcp_EvCh0DaqList[1] = {0 };
#define XCP_STOP_SEC_CONFIG_DATA_16
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"                                                                                                    
static CONST(Xcp_EvChConfigType, XCP_CONST_PBCFG) Xcp_EvChConfig[XCP_MAX_EVENT_CHANNEL] =
{
    {
        Xcp_Evch_0,
        sizeof(Xcp_Evch_0),
        XCP_EVENT_CONSIST_ODT,    
        1, /*XcpEvChMaxDaqList*/
        0,/*XcpEvChNumber*/    
        1,/*XcpEvChPriority*/                
        100,/*XcpEvChTimeCycle*/                
        TIMESTAMP_UNIT_1MS,/*XcpEvChTimeUnit*/        
        DAQ,/*XcpEvChType*/        
        XCP_EVCHBUFFER_0_DEPTH,
        &Xcp_EvCh0Buffer[0],
        &Xcp_EvCh0DaqList[0]            
    }
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
static VAR(uint8, XCP_VAR) Xcp_PageBuffer0[XCP_PAGE_BUF0_SIZE]; 
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_32
#include "Xcp_MemMap.h"
CONST(uint32, XCP_CONST) Xcp_MeaStartAddr = 0x60038800;
#define XCP_STOP_SEC_CONFIG_DATA_32
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"    
static CONST(Xcp_PageInfoType, XCP_CONST_PBCFG) Xcp_PageInfo[XCP_MAX_SEGMENT] = 
{
    {    
        0x10000,
        0x60028800,
        0x600387ff,    
        0xa02f0000,
        0xa02fffff,
        (uint32)Xcp_PageBuffer0,
    }    
};

CONST(Xcp_SegmentInfoType,XCP_CONST_PBCFG) Xcp_SegmentInfo = 
{
    XCP_MAX_SEGMENT,
    Xcp_PageInfo, 
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"


#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
CONST(Xcp_PCConfigType, XCP_CONST_PBCFG) Xcp_PConfig =
{
    &Xcp_DaqConfig[0],
    &Xcp_EvChConfig[0],
    XCP_NUM_OF_ID,
    &Xcp_IdInfo[0]
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
