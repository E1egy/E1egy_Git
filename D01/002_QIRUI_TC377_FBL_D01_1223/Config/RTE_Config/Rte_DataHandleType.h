/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_DataHandleType.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2022-10-24 20:40:22>
 */
/*============================================================================*/

/* Rte_Data_Handle_Type.h */

#ifndef RTE_DATA_HANDLE_TYPE_H
#define RTE_DATA_HANDLE_TYPE_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte_Type.h"

typedef struct 
{
	Float value;
} Rte_DE_Float;

typedef struct 
{
	Boolean value;
} Rte_DE_Boolean;

typedef struct 
{
	UInt16 value;
} Rte_DE_UInt16;

typedef struct 
{
	UInt8 value;
} Rte_DE_UInt8;

typedef struct 
{
	SInt16 value;
} Rte_DE_SInt16;



#endif

