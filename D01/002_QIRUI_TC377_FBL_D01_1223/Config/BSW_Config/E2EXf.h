/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : E2EXf.h                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION>     <DATE>       <AUTHOR>       <REVISION LOG>
 *  V1.0.0       20200610     Wanglili       Initial version
 ******************************************************************************/
#ifndef E2EXF_H_
#define E2EXF_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "E2EXf_Cfg.h"
#include "E2EXf_LCfg.h"
#include "Xf_Cfg.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define E2EXF_MODULE_ID                     176u
#define E2EXF_VENDOR_ID                     62u
#define E2EXF_H_AR_RELEASE_MAJOR_VERSION    19u
#define E2EXF_H_AR_RELEASE_MINOR_VERSION    11u
#define E2EXF_H_AR_RELEASE_PATCH_VERSION    0u
#define E2EXF_H_SW_MAJOR_VERSION            2u
#define E2EXF_H_SW_MINOR_VERSION            0u
#define E2EXF_H_SW_PATCH_VERSION            3u
#define E2EXf_INSTANCE_ID   0u
#define E2EXF_GETVERSIONINFO_ID   5u
/* E2EXf service ID */
#define E2EXF_INIT_SERVICEID 0x01u
#define E2EXF_DEINIT_SERVICEID 0x02u
#define E2EXF_TRANSFORMERID_SERVICEID 0x03u
#define E2EXF_INV_TRANSFORMERID_SERVICEID 0x04u
#define E2EXF_GETVERSIONINFO_SERVICEID 0x05u
/* E2EXf error code, Req<SWS_E2EXf_00137> */
#define E2EXF_E_UNINIT            1u
#define E2EXF_E_INIT_FAILED       2u
#define E2EXF_E_PARAM             3u
#define E2EXF_E_PARAM_POINTER     4u
#define E_SAFETY_SOFT_RUNTIMEERROR 0x77
#define E_SAFETY_HARD_RUNTIMEERROR 0xFF
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#if (STD_ON == E2EXF_VERSION_INFO_API)
/******************************************************************************/
/*
 * Brief               This service returns the version information of
 *                     this module
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Versioninfo: Pointer to where to store the version
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* Req<SWS_E2EXf_00036> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(void, E2EXF_CODE)E2EXf_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
#endif/* STD_ON == E2EXF_VERSION_INFO_API */
/******************************************************************************/
/*
 * Brief               This service initializes  the state of  the E2E
 *                     Transformer
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* <SWS_E2EXf_00035> */
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(void, E2EXF_CODE)
E2EXf_Init
(
    P2CONST(E2EXf_ConfigType, AUTOMATIC, E2EXF_CONST) config
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
/******************************************************************************/
/*
 * Brief               This service deinitializes  the state of  the E2E
 *                     Transformer
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(void, E2EXF_CODE)
E2EXf_DeInit(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x119_ABM_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x134_ADS_ECAS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x32a_ADS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x11d_ECAS_EDC_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x342_ECAS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x196_EPB_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x114_EPS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x195_IPB_ADS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x192_IPB_State1
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x116_IPB_Tq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x112_IPB_Wheel
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x3f0_VDC_CDCSet
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x115_VDC_FMtTq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x11b_VDC_PTSt
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x113_VDC_RMtTq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x3b5_VDC_VIU_BodyInfo
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x39a_VIU_Config
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x2b0_VIU_DoorLock
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x1d2_VIU_Info
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_0x34b_VIU_Route_SUS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x119_ABM_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x134_ADS_ECAS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x32a_ADS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x11d_ECAS_EDC_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x342_ECAS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x196_EPB_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x114_EPS_State
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x195_IPB_ADS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x192_IPB_State1
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x116_IPB_Tq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x112_IPB_Wheel
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x3f0_VDC_CDCSet
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x115_VDC_FMtTq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x11b_VDC_PTSt
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x113_VDC_RMtTq
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x3b5_VDC_VIU_BodyInfo
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x39a_VIU_Config
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x2b0_VIU_DoorLock
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x1d2_VIU_Info
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_0x34b_VIU_Route_SUS
(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32  inputBufferLength
);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

#endif/* E2EXF_H_ */

