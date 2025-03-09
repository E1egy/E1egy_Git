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
**  FILENAME    : XcpOnCan.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Transport Layer:XCP on CAN                                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-02-12  qinchun.yang    Initial version.Distinguish between
 *                                              different transport layers
 *  V2.0.0       2021-04-08  qinchun.yang    R1911 stable version.
 */
/*============================================================================*/
/*=======[I N C L U D E S]====================================================*/
#include "Xcp_Internal.h"

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#if (XCP_ON_CAN_ENABLE == STD_ON)
#define XCP_START_SEC_CANIFRXINDICATION_CALLBACK_CODE
#include "XCP_MemMap.h"
/******************************************************************************/
/*
 * @brief               <Xcp callback Function>
 *
 * <Indication of a received PDU from a lower layer communication interface module.> .
 * Service ID   :       <(0x42)>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant for different PduIds. Non reentrant for the same PduId.>
 * @param[in]           <RxPduId>/<PduInfoPtr>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 */
/******************************************************************************/
FUNC(void, XCP_CANIFRXINDICATION_CODE)
Xcp_CanIfRxIndication(
    PduIdType XcpRxPduId,
    P2CONST(PduInfoType,AUTOMATIC,XCP_APPL_DATA) XcpRxPduPtr
)
{
    #if (XCP_DEV_ERROR_DETECT == STD_ON)
    if ((boolean)TRUE != Xcp_RxIndCheckDetErr(XcpRxPduId, XcpRxPduPtr))
    #else
    XCP_AVOID_WARNNING(XcpRxPduId);
    #endif /* XCP_DEV_ERROR_DETECT == STD_ON */
    {
        #if (XCP_CAN_MAX_DLC_REQUIRED == STD_ON)
        if (XCP_CAN_MAX_DLC == XcpRxPduPtr->SduLength)
        #endif /*XCP_CAN_MAX_DLC_REQUIRED == STD_ON*/
        {
            /* for CAN there is no header or tail that shall be removed
             * so call the Xcp_RxIndication() directly
             */
            #if (XCP_PID_OFF_SUPPORT  == STD_ON)
            Xcp_RxIndication(XcpRxPduId, XcpRxPduPtr->SduLength, XcpRxPduPtr->SduDataPtr);
            #else
            Xcp_RxIndication(XcpRxPduPtr->SduLength, XcpRxPduPtr->SduDataPtr);
            #endif /*XCP_PID_OFF_SUPPORT  == STD_ON*/
        }
    }
    return;
}
#define XCP_STOP_SEC_CANIFRXINDICATION_CALLBACK_CODE
#include "XCP_MemMap.h"


#define XCP_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#include "XCP_MemMap.h"
/******************************************************************************/
/*
 * @brief               <Xcp callback Function>
 *
 * <The lower layer communication interface module confirms the transmission of a PDU, or the failure to transmit a PD.> .
 * Service ID   :       <(0x40)>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant for different PduIds. Non reentrant for the same PduId.>
 * @param[in]           <TxPduId>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 */
/******************************************************************************/
FUNC(void, XCP_CANIFTXCONFIRMATION_CODE)
Xcp_CanIfTxConfirmation(
    PduIdType XcpTxPduId
)
{
    #if (XCP_DEV_ERROR_DETECT == STD_ON)
    if ((boolean)FALSE == Xcp_TxIndCheckDetErr())
    #endif /* (XCP_DEV_ERROR_DETECT == STD_ON) */
    {
        Xcp_TxConfirmation(XcpTxPduId);
    }
    return;
}
#define XCP_STOP_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#include "XCP_MemMap.h"
#endif /*XCP_ON_CAN_ENABLE == STD_ON*/
