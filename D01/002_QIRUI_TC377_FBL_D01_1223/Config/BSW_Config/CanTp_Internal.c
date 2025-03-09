/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2016)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
**************************************************************************** **
**                                                                           **
**  FILENAME    : CanTp_Internal.c                                           **
**                                                                           **
**  Created on  : 2021/7/30 14:29:43                                         **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION : Internal Source file of CanTp module.                      **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                           **
**************************************************************************** */

/*=======[I N C L U D E S]====================================================*/
#include "CanTp_Internal.h"

#define CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTp_MemMap.h"
/*CANTP global variable for runtime channel controlling information*/
static VAR(CanTp_ConnectionChannelType, CANTP_VAR_NOINIT) CanTp_Channels[CANTP_CHANNEL_NUMBER];
#define CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTp_MemMap.h"

/*=============Module Internal Function Implementation====================*/

#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
/*
 * Brief               get the Rx specific channel
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(P2VAR(CanTp_ConnectionType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
CanTp_GetRxChannel(uint8 ChannelIdx)
{
    return &CanTp_Channels[ChannelIdx].RxConnection;
}

/*
 * Brief               get the Tx specific channel
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(P2VAR(CanTp_ConnectionType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
CanTp_GetTxChannel(uint8 ChannelIdx)
{
    return &CanTp_Channels[ChannelIdx].TxConnection;
}

/*
 * Brief               Get RX-SDU configuration by received NPDU information.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE) CanTp_GetRxSduCfgByNpdu(
    PduIdType CanTpRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) CanTpRxPduPtr,
    P2VAR(CanTp_FramePCIType, AUTOMATIC, AUTOMATIC) SduFrameType,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) channelIdx)
{
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) result = NULL_PTR;
    P2CONST(CanTp_ChannelType, AUTOMATIC, CANTP_VAR) channelPtr;
    uint8 rxNSduIdx;
    uint8 chnIdx;
    CanTp_FramePCIType frameType;

    for (chnIdx = 0; (NULL_PTR == result) && (chnIdx < CanTp_ConfigPtr->ChannelNum); chnIdx++)
    {
        channelPtr = &CanTp_ConfigPtr->CanTpChannel[chnIdx];
        for (rxNSduIdx = 0; (NULL_PTR == result) && (rxNSduIdx < channelPtr->RxNSduNum); rxNSduIdx++)
        {
            switch (channelPtr->RxNSdus[rxNSduIdx].AddressingFormat)
            {
            case CANTP_STANDARD:
            case CANTP_NORMALFIXED:
                frameType = CanTpRxPduPtr->SduDataPtr[CANTP_PCI_OFFSET_STD] & CANTP_FTYPE_MASK;
                if ((channelPtr->RxNSdus[rxNSduIdx].RxNPduId == CanTpRxPduId) &&
                ((CANTP_FTYPE_CF == frameType) || (CANTP_FTYPE_SF == frameType) || (CANTP_FTYPE_FF == frameType)))
                {
                    result = &channelPtr->RxNSdus[rxNSduIdx];
                    *SduFrameType = frameType;
                    *channelIdx = chnIdx;
                }
                break;
            default:
                /*idle*/
                break;
            }
        }
    }
    return result;
}

/*
 * Brief               Get SFF_DL information from the data content of SF.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(PduLengthType, CANTP_CODE)
    CanTp_RxGetSFDl(
        P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
        P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
        P2VAR(uint8, AUTOMATIC, CANTP_CONST) dataoffset,
        P2VAR(uint8, AUTOMATIC, CANTP_CONST) totaloffset)
{
    uint8 sfDl;
    uint8 offset = 0xFF;

    /*check SF DL*/
    switch (RxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        /*PCI is byte[0]*/
        offset = CANTP_PCI_OFFSET_STD;
        *totaloffset = 1;
        break;
    default:
        /*No further deal*/
        break;
    }
    sfDl = PduInfoPtr->SduDataPtr[offset] & CANTP_SF_DL_MASK;
    if ((0x0u == sfDl) && (8u < PduInfoPtr->SduLength))
    {
        /*CanFD only*/
        if (CAN_FD == RxNSduCfgPtr->CanFrameType)
        {
            sfDl = PduInfoPtr->SduDataPtr[offset + 1u];
            *totaloffset += 1u;
        }
    }
    *dataoffset = offset;
    return sfDl;
}

/*
 * Brief               Get FF_DL information from the data content of FF.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(PduLengthType, CANTP_CODE)
CanTp_RxGetFFDl(
    P2CONST(uint8, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_CONST) offset,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr)
{
    /*because PduLengthType is uint16, so FFDL can not bigger than 65535*/
    uint32 ffDl;
    uint8 pcioffest = 0xFF;

    switch (RxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        pcioffest = CANTP_PCI_OFFSET_STD;
        *offset = CANTP_FF_DATA_OFFSET_LT4095_STD;
        break;
    default:
        /*idle*/
        break;
    }
    ffDl = (uint32)PduInfoPtr[pcioffest] & (uint32)CANTP_FF_DL_MASK;
    ffDl <<= CANTP_OFFSET_BYTE_PART;
    ffDl = ffDl + PduInfoPtr[pcioffest + 1u];
    /*FFDL > 4095*/
    if (0x0u == ffDl)
    {
        ffDl = PduInfoPtr[pcioffest + 2u];
        ffDl <<= CANTP_OFFSET_BYTE_PART;
        ffDl = ffDl + PduInfoPtr[pcioffest + 3u];
        ffDl <<= CANTP_OFFSET_BYTE_PART;
        ffDl = ffDl + PduInfoPtr[pcioffest + 4u];
        ffDl <<= CANTP_OFFSET_BYTE_PART;
        ffDl = ffDl + PduInfoPtr[pcioffest + 5u];
        if (ffDl <= CANTP_FF_DL_12bit_LENGTH)
        {
            ffDl = 0;
        }
        else
        {
            *offset += 4u;
        }
    }
    return (PduLengthType)ffDl;
}

/*
 * Brief               Calculate the BS value according to
 *  the buffer length and remain data length.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(void, CANTP_CODE) CanTp_CalcBS(
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 ChannelIdx)
{
    PduLengthType blockDataLen;
    uint8 length = 0xFF;uint8 offset = 0xFF;
    uint8 bs;
    P2VAR(CanTp_ConnectionType, AUTOMATIC, CANTP_VAR_POWER_ON_INIT) RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);

    /*check changParameter of BS is done or not*/
    if ((RxchannelPtr->EventFlags & CANTP_CHANNEL_EVENT_RXBSCHANGED) != 0u)
    {
        bs = RxchannelPtr->ChangedBs;
    }
    else
    {
        /*bs is not changed by api*/
        if (RxNSduCfgPtr->Bs != NULL_PTR)
        {
            bs = *(RxNSduCfgPtr->Bs);
        }
        else
        {
            bs = 0xFF;
        }
    }

    if (0u == bs)
    {
        /*BS is 0, no more FC need from now on*/
        SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
        RxchannelPtr->CurrentBs = 0;
        SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
    }
    else
    {
        /*get the data length of this block using the minimum value between PDUR buffer length and SDU remain 
        data length. If the minimum value is zero, I.E. the PDUR remain buffer is 0, use 1 as the BS*/
        blockDataLen = RxchannelPtr->SduDataRemaining;

        if (0u == blockDataLen)
        {
            /*no more upper buffer space left */
            SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
            RxchannelPtr->CurrentBs = 1U;
            SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
        }
        else
        {
            switch (RxNSduCfgPtr->AddressingFormat)
            {
            case CANTP_STANDARD:
            case CANTP_NORMALFIXED:
                length = CANTP_CF_DATALEN_STD;offset = CANTP_CF_DATA_OFFSET_STD;
                break;
            default:
                /*idle*/
                break;
            }

            /*calculate CF block,CAN2.0 and CANFD is the same format,just different with length*/
            SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
            if (CAN20 == RxNSduCfgPtr->CanFrameType)
            {
                RxchannelPtr->CurrentBs = (uint8)((blockDataLen + length) / length);
            }
            else
            {
                /*CAN_FD*/
                RxchannelPtr->CurrentBs = (uint8)((blockDataLen + RxchannelPtr->FDDlc - offset) / RxchannelPtr->FDDlc);
            }
            /*use the minimum value between calculated and the configured maximum value*/
            if (RxchannelPtr->CurrentBs > bs)
            {
                RxchannelPtr->CurrentBs = bs;
            }
            SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
        }
    } /*END OF BS needed*/
}

/*
 * Brief               Compare Buffer With Bs
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(Std_ReturnType, CANTP_CODE) CanTp_CompareBufferWithBs(
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 ChannelIdx,
    PduLengthType bufferSize)
{
    PduLengthType blockDataLen;
    PduLengthType offset = 0xFF;
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(CanTp_ConnectionType, AUTOMATIC, CANTP_VAR_POWER_ON_INIT) RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);

    switch (RxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        offset = CANTP_CF_DATA_OFFSET_STD;
        break;
    default:
        /*idle*/
        break;
    }

    /*CF composed of this block,CAN2.0 and CANFD is the same format,just different with length*/
    if (CAN20 == RxNSduCfgPtr->CanFrameType)
    {
        blockDataLen = (PduLengthType)RxchannelPtr->CurrentBs * offset;
    }
    else
    {
        /*CAN_FD*/
        blockDataLen = (PduLengthType)RxchannelPtr->CurrentBs * (CANTP_CAN20_FRAME_LEN_MAX - offset);
    }
    if (bufferSize > blockDataLen)
    {
        ret = E_OK;
    }
    else
    {
        if (bufferSize >= RxchannelPtr->SduDataRemaining)
        {
            ret = E_OK;
        }
    }

    return ret;
}

/*
 * Brief               send FC
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(Std_ReturnType, CANTP_CODE) CanTp_SendFC(
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 ChannelIdx,
    CanTp_FCInfoType CanTp_FC)
{
    PduInfoType pduInfo;
    PduLengthType offset = 0xFF;
    uint16 fcFrameLen = 0u;
    Std_ReturnType ret;
    uint8 FcBuf[CANTP_CANFD_FRAME_LEN_MAX];
    switch (RxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        offset = CANTP_PCI_OFFSET_STD;
        fcFrameLen = (uint16)CANTP_FC_LEN_STD;
        break;
    default:
        /*idle*/
        break;
    }
    if (offset != (PduLengthType)0xFF)
    {
        FcBuf[offset] = CANTP_FTYPE_FC | CanTp_FC.FcFs;
        FcBuf[offset + 1u] = CanTp_FC.FcBS;
        FcBuf[offset + 2u] = (uint8)CanTp_FC.FcSTMin;
    }
    if (RxNSduCfgPtr->CanFrameType == CAN20)
    {
        if (CANTP_PADDING_ON == RxNSduCfgPtr->RxPaddingActivation)
        {
            CanTp_MemorySet(&FcBuf[fcFrameLen], CANTP_PADDING_BYTE, ((uint16)CANTP_CAN20_FRAME_LEN_MAX - fcFrameLen));
            fcFrameLen = (uint16)CANTP_CAN20_FRAME_LEN_MAX;
        }
    }
    else
    {
        CanTp_MemorySet(&FcBuf[fcFrameLen],CANTP_PADDING_BYTE,(8u - fcFrameLen));
        fcFrameLen = 8u;
    }
    pduInfo.SduLength = (PduLengthType)fcFrameLen;
    pduInfo.SduDataPtr = FcBuf;
    ret = CanIf_Transmit(RxNSduCfgPtr->TxFcLPduId, &pduInfo);
    return ret;
}

/*
 * Brief               Utility function: Set memory with specific value.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(void, CANTP_CODE)
CanTp_MemorySet(
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) Address,
    uint8 Value,
    uint16 Length)
{
    uint16 DL;
    for (DL = 0; DL < Length; DL++)
    {
        Address[DL] = Value;
    }
}

/*
 * Brief               Get CF Offset
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(void, CANTP_CODE) CanTp_RxGetCFOffset(
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) dataoffset,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) pcioffset)
{
    switch (RxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        *pcioffset = CANTP_PCI_OFFSET_STD;
        *dataoffset = CANTP_CF_DATA_OFFSET_STD;
        break;
    default:
        /*idle*/
        break;
    }
}

/*
 * Brief               Get TX-SDU configuration by received FC NPDU information.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE) CanTp_GetTxSduCfgByFCNpdu(
    PduIdType CanTpRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) CanTpRxPduPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) channelIdx)
{
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) result = NULL_PTR;
    P2CONST(CanTp_ChannelType, AUTOMATIC, CANTP_VAR) channelPtr;
    uint8 txNSduIdx;
    uint8 chnIdx;
    CanTp_FramePCIType frameType;

    for (chnIdx = 0; (NULL_PTR == result) && (chnIdx < CanTp_ConfigPtr->ChannelNum); chnIdx++)
    {
        channelPtr = &CanTp_ConfigPtr->CanTpChannel[chnIdx];
        for (txNSduIdx = 0; (NULL_PTR == result) && (txNSduIdx < channelPtr->TxNsduNum); txNSduIdx++)
        {
            /*only physical TX NSDU need configure RX FCNPDUID*/
            if ((CANTP_PHYSICAL_TX == channelPtr->TxNSdus[txNSduIdx].TxTaType) && (channelPtr->TxNSdus[txNSduIdx].RxFcNPduId == CanTpRxPduId))
            {
                switch (channelPtr->TxNSdus[txNSduIdx].AddressingFormat)
                {
                case CANTP_STANDARD:
                case CANTP_NORMALFIXED:
                    /*check the standard addressing TX-NSDU, only FC accepted*/
                    frameType = CanTpRxPduPtr->SduDataPtr[CANTP_PCI_OFFSET_STD] & CANTP_FTYPE_MASK;
                    if (CANTP_FTYPE_FC == frameType)
                    {
                        result = &channelPtr->TxNSdus[txNSduIdx];
                        *channelIdx = chnIdx;
                    }
                    break;
                default:
                    /*idle*/
                    break;
                }/*END OF switch*/
            }/*END OF if (CANTP_PHYSICAL == CanTp_CfgData.TxNSdus[txNSduIdx].TxTaType)*/
        } /*END OF for loop*/
    }/*END OF for loop*/
    return result;
}

/*
 * Brief               Get the information of received FC frame.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(void, CANTP_CODE)
CanTp_GetChannelFCInfo(
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2VAR(CanTp_FCInfoType, AUTOMATIC, AUTOMATIC) FcInfoPtr)
{
    uint32 stMinUs;
    PduLengthType offset = 0;
    uint8 stMinRaw;

    switch (TxNSduCfgPtr->AddressingFormat)
    {
        case CANTP_STANDARD:
        case CANTP_NORMALFIXED:
            offset = CANTP_PCI_OFFSET_STD;
            break;
        default:
            /*idle*/
            break;
    }
    FcInfoPtr->FcFs = PduInfoPtr->SduDataPtr[offset] & CANTP_FC_FS_MASK;
    FcInfoPtr->FcBS = PduInfoPtr->SduDataPtr[offset + 1u];
    /*calculate the STMin in tick unit. Round the value to the nearest integer, that is
     * if it is 0.49, then the integer will be 0, 0.50 will be 1.*/
    stMinRaw = PduInfoPtr->SduDataPtr[offset + 2u];
    if (CANTP_FC_STMIN_MS_LIMIT >= stMinRaw)
    {
        /*ms per bit*/
        stMinUs = (uint32)stMinRaw * CANTP_FC_STMIN_MS_UNIT;
    }
    else if ((CANTP_FC_STMIN_US_LOW <= stMinRaw) && (CANTP_FC_STMIN_US_UPPER >= stMinRaw))
    {
        /*F1-F9 100us per step*/
        stMinUs = ((uint32)((uint32)stMinRaw - 0xF0UL)) * CANTP_FC_STMIN_US_UNIT;
    }
    else
    {
        /*invalid value, use 7F*/
        stMinUs = (uint32)CANTP_FC_STMIN_MS_LIMIT * CANTP_FC_STMIN_MS_UNIT;
    }
    /*transit to value in unit tick*/
    FcInfoPtr->FcSTMin = (stMinUs + (uint32)((uint32)1000 >> (uint32)1)) / (uint32)1000;
}

/*
 * Brief               check Tx Length In Address Mode.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(Std_ReturnType, CANTP_CODE) CanTp_CheckTxLengthInAddressMode(
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    PduLengthType len;

    switch (TxNSduCfgPtr->TxTaType)
    {
        /*functional addressing mode can only use SF*/
    case CANTP_FUNCTIONAL_TX:
        switch (TxNSduCfgPtr->AddressingFormat)
        {
        case CANTP_STANDARD:
        case CANTP_NORMALFIXED:
            if (CANTP_SF_LEN_MAX_STD >= PduInfoPtr->SduLength)
            {
                /*CAN2.0 or small CAN FD can send this single frame*/
                ret = E_OK;
            }
            else
            {
                /*large CAN FD only*/
                len = TxNSduCfgPtr->TxNPduDLC - CANTP_SF_DATA_OFFSET_CANFD_STD;
                if (CAN_FD == TxNSduCfgPtr->CanFrameType)
                {
                    if (len > PduInfoPtr->SduLength)
                    {
                        /*transmit each sdu length should less than DLC which configuration in Canif module*/
                        ret = E_OK;
                    }
                }
            }
            break;
        default:
            /*idle*/
            break;
        }
        break;
    case CANTP_PHYSICAL_TX:
        ret = E_OK;
        break;
    default:
        /*idle*/
        break;
    }
    return ret;
}

/*
 * Brief               Handle transmit request.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(void, CANTP_CODE) CanTp_TxHandleTransmitReq(
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr)
{
    PduLengthType len;
    uint8 offset = 0xFF;
    P2VAR(CanTp_ConnectionType, AUTOMATIC, CANTP_VAR_POWER_ON_INIT) TxchannelPtr = CanTp_GetTxChannel(ChannelIdx);

    switch (TxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        /*Can2.0 or small Can Fd*/
        offset = CANTP_SF_DATA_OFFSET_STD;
        if (CAN_FD == TxNSduCfgPtr->CanFrameType)
        {
            /*small CanFD data offset same as Can 2.0,CANTP_SF_DATA_OFFSET_STD,small 
            Can FD data field length less than large Can FD, so len = bigger one*/
            if (TxchannelPtr->SduDataTotalCount > 7u)
            {
                offset = CANTP_SF_DATA_OFFSET_CANFD_STD;
            }
        }
        break;
    default:
        /*idle*/
        break;
    }
    if (offset != 0xFFu)
    {
        len = TxNSduCfgPtr->TxNPduDLC - offset;
        if (len < TxchannelPtr->SduDataTotalCount)
        {
            /*larger SDU transmit request*/
            TxchannelPtr->HandleType = CANTP_FTYPE_FF;
            TxchannelPtr->RootState = CANTP_LARGE_TRANSMITTING;
            TxchannelPtr->Substate = CANTP_TX_LARGE_START;
        }
        else
        {
            /*SF transmit request*/
            TxchannelPtr->HandleType = CANTP_FTYPE_SF;
            TxchannelPtr->RootState = CANTP_SF_TRANSIMITTING;
            TxchannelPtr->Substate = CANTP_TX_SF_START;
        }
    }
}
/*
 * Brief               construct FF PCI information in local buffer for channel.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(void, CANTP_CODE) CanTp_ConstructFFPci(
        uint8 ChannelIdx,
        P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) txNSduCfgPtr,
        P2VAR(uint8, AUTOMATIC, CANTP_CONST) dataPtr,
        P2VAR(uint8, AUTOMATIC, CANTP_CONST) totalOffset)
{
    uint32 pciDl;
    uint8 offset = 0xFF;
    P2CONST(CanTp_ConnectionType, AUTOMATIC, CANTP_VAR_POWER_ON_INIT) TxchannelPtr = CanTp_GetTxChannel(ChannelIdx);

    pciDl = TxchannelPtr->SduDataTotalCount;
    switch (txNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        /*Can2.0 or small Can Fd*/
        offset = CANTP_PCI_OFFSET_STD;
        break;
    default:
        /*idle*/
        break;
    }

    if (pciDl <= CANTP_FF_DL_12bit_LENGTH)
    {
        /*FF_DL less than or equal to 4095*/
        /*SDU length high nibble and Frame type*/
        dataPtr[offset] = CANTP_FTYPE_FF | (uint8)(pciDl >> 8u);
        offset++;
        /*SDU length low nibble*/
        dataPtr[offset] = (uint8)pciDl;
        offset++;
        *totalOffset = offset;
    }
    else
    {
        /*FF_DL bigger than 4095*/
        /*SDU length from high to low nibble*/
        dataPtr[offset] = CANTP_FTYPE_FF;
        offset++;
        dataPtr[offset] = 0x00;
        offset++;
        dataPtr[offset] = (uint8)(pciDl >> 24u);
        offset++;
        dataPtr[offset] = (uint8)(pciDl >> 16u);
        offset++;
        dataPtr[offset] = (uint8)(pciDl >> 8u);
        offset++;
        dataPtr[offset] = (uint8)pciDl;
        offset++;
        *totalOffset = offset;
    }
}
/*
 * Brief               construct CF PCI information in local buffer for channel.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(void, CANTP_CODE) CanTp_ConstructCFPci(
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) txNSduCfgPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) dataPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) totalOffset)
{
    uint8 offset = 0xFF;
    P2CONST(CanTp_ConnectionType, AUTOMATIC, CANTP_VAR_POWER_ON_INIT) TxchannelPtr = CanTp_GetTxChannel(ChannelIdx);

    switch (txNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        /*Can2.0 or small Can Fd*/
        offset = CANTP_PCI_OFFSET_STD;
        break;
    default:
        /*idle*/
        break;
    }
    dataPtr[offset] = CANTP_FTYPE_CF | TxchannelPtr->CurrentCfSn;
    offset++;
    *totalOffset = offset;
}

/*
 * Brief               construct SF PCI information in local buffer for channel.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(void, CANTP_CODE) CanTp_ConstructSFPci(
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) txNSduCfgPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) dataPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) totalOffset)
{
    PduLengthType pciDl;
    PduLengthType CANDL;
    P2CONST(CanTp_ConnectionType, AUTOMATIC, CANTP_VAR_POWER_ON_INIT) TxchannelPtr = CanTp_GetTxChannel(ChannelIdx);
    uint8 offset = 0xFF;

    pciDl = TxchannelPtr->SduDataTotalCount;
    if ((pciDl >= 8u) && (pciDl <= 10u))
    {
        CANDL = 12;
    }
    else if ((pciDl >= 11u) && (pciDl <= 14u))
    {
        CANDL = 16;
    }
    else if ((pciDl >= 15u) && (pciDl <= 18u))
    {
        CANDL = 20;
    }
    else if ((pciDl >= 19u) && (pciDl <= 22u))
    {
        CANDL = 24;
    }
    else if ((pciDl >= 23u) && (pciDl <= 30u))
    {
        CANDL = 32;
    }
    else if ((pciDl >= 31u) && (pciDl <= 46u))
    {
        CANDL = 48;
    }
    else if ((pciDl >= 47u) && (pciDl <= 62u))
    {
        CANDL = 64;
    }
    else
    {
        CANDL = 8;
    }

    switch (txNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        /*Can2.0 or small Can Fd*/
        offset = CANTP_PCI_OFFSET_STD;
        break;
    default:
        /*idle*/
        break;
    }

    if (CANDL <= 8u)
    {
        /*SF_DL less than or equal to 7, Frame type and SF DL*/
        dataPtr[offset] = ((uint8)pciDl & CANTP_SF_DL_MASK); /*CANTP_FTYPE_SF*/
        offset++;
        *totalOffset = offset;
    }
    else
    {
        /*SF_DL bigger than 7, Frame type and SF DL*/
        dataPtr[offset] = CANTP_FTYPE_SF;
        offset++;
        dataPtr[offset] = (uint8)pciDl;
        offset++;
        *totalOffset = offset;
    }
}

/*
 * Brief               Tx SF Padding.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(void, CANTP_CODE) CanTp_TxSFPadding(
        uint8 ChannelIdx,
        P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) txSduCfgPtr,
        P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) pduInfoPtr)
{
    PduLengthType frameDL;
    PduLengthType can20DataFieldLen = 0;
    PduLengthType canFdDataOffset = 0;
    P2CONST(CanTp_ConnectionType, AUTOMATIC, CANTP_VAR_POWER_ON_INIT) TxchannelPtr = CanTp_GetTxChannel(ChannelIdx);

    switch (txSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        can20DataFieldLen = CANTP_SF_LEN_MAX_STD;
        canFdDataOffset = CANTP_SF_DATA_OFFSET_CANFD_STD;
        break;
    default:
        /*idle*/
        break;
    }

    if ((TxchannelPtr->SduDataTotalCount > can20DataFieldLen) && (CAN_FD == txSduCfgPtr->CanFrameType))
    {
        /*CANFD frame length >8*/
        frameDL = TxchannelPtr->SduDataTotalCount + canFdDataOffset;
        /*frameDL here is less than or equal to the DLC which configuration in the CANFI module*/
        frameDL = CanTp_MatchDLC(frameDL);
        CanTp_MemorySet(&pduInfoPtr->SduDataPtr[pduInfoPtr->SduLength], CANTP_PADDING_BYTE, (frameDL - pduInfoPtr->SduLength));
        pduInfoPtr->SduLength = frameDL;
    }
    else
    {
        if (CANTP_PADDING_ON == txSduCfgPtr->TxPaddingActivation)
        {
            /*CAN2.0 or small CAN FD*/
            if (txSduCfgPtr->TxNPduDLC > CANTP_CAN20_FRAME_LEN_MAX)
            {
                frameDL = CANTP_CAN20_FRAME_LEN_MAX;
            }
            else
            {
                frameDL = txSduCfgPtr->TxNPduDLC;
            }
            CanTp_MemorySet(&pduInfoPtr->SduDataPtr[pduInfoPtr->SduLength], CANTP_PADDING_BYTE, (frameDL - pduInfoPtr->SduLength));
            pduInfoPtr->SduLength = frameDL;
        }
    }
}

#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"
    /*=======[E N D   O F   F I L E]==============================================*/
