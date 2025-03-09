/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Lin_GeneralTypes.h                                         **
**                                                                            **
**  VERSION      : 3.0.0                                                      **
**                                                                            **
**  DATE         : 2018-07-24                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file exports Lin interface Type defnitions            **
**                                                                            **
**  SPECIFICATION(S) : Specification of Lin Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/

#ifndef LIN_GENERALTYPES_H
#define LIN_GENERALTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/*
Type : Lin_FramePidType  
Represents all valid protected Identifier used by Lin_SendFrame().  
*/
typedef uint8 Lin_FramePidType;

/*
Type : Lin_FrameCsModelType  
This type is used to specify the Checksum model to be used for the LIN Frame   
*/
typedef enum 
{
  LIN_ENHANCED_CS = 0, 
  LIN_CLASSIC_CS
}Lin_FrameCsModelType;

/*
Type : Lin_FrameResponseType  
This type is used to specify whether the frame processor is required to 
transmit the response part of the LIN frame   
*/
typedef enum 
{
  LIN_MASTER_RESPONSE = 0,
  LIN_SLAVE_RESPONSE,
  LIN_SLAVE_TO_SLAVE
}Lin_FrameResponseType;



/*
Type : Lin_FrameDlType   
This type is used to specify the number of SDU data bytes to copy    
*/
typedef uint8 Lin_FrameDlType;

/*
Type : Lin_PduType   
This Type is used to provide PID, checksum model, data length and SDU pointer 
from the LIN Interface to the LIN driver     
*/
typedef struct 
{
  Lin_FramePidType         Pid; 
  Lin_FrameCsModelType     Cs;         
  Lin_FrameResponseType    Drc;        
  Lin_FrameDlType          Dl;    
  uint8                    *SduPtr;
}Lin_PduType;

/*
Type : Lin_StatusType   
LIN operation states for a LIN channel or frame, as returned by the API 
service Lin_17_GetStatus().      
*/
typedef enum
{
  LIN_NOT_OK = 0,
  LIN_TX_OK,
  LIN_TX_BUSY,
  LIN_TX_HEADER_ERROR,
  LIN_TX_ERROR,
  LIN_RX_OK,
  LIN_RX_BUSY,
  LIN_RX_ERROR,
  LIN_RX_NO_RESPONSE,
  LIN_OPERATIONAL,
  LIN_CH_SLEEP,
}Lin_StatusType;


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#endif   /*  LIN_GENERALTYPES_H  */

