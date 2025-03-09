/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_ModeHandling.h>
 *  @brief      <>
 *  
 *  <MCU:TC233>
 *  
 *  @author     <>
 *  @date       <2021-12-24 16:09:14>
 */
/*============================================================================*/

/* Rte_ModeHandling.h */

#ifndef RTE_MODEHANDLING_H
#define RTE_MODEHANDLING_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "cirq_buffer.h"
#include "Rte_Type.h"

#define MODE_QUEUE_SIZE_CURRENTMODE_ECUM_ECUM_CURRENTMODE 1

extern Rte_ModeType_EcuM_Mode currentMode_EcuM_EcuM_CurrentMode_buffer[MODE_QUEUE_SIZE_CURRENTMODE_ECUM_ECUM_CURRENTMODE];

typedef struct 
{
	Rte_ModeType_EcuM_Mode currentMode;
	Rte_ModeType_EcuM_Mode nextMode;
	Rte_ModeType_EcuM_Mode fromMode;
	CirqBufferType queue;
	uint8 inTransition;
} ModeMachine_EcuM_Mode;

extern ModeMachine_EcuM_Mode modeMachine_currentMode_EcuM_EcuM_CurrentMode;

extern ModeMachine_EcuM_Mode modeMachine_currentMode_EcuM_EcuM_CurrentMode;

Rte_ModeType_EcuM_Mode modeStep_EcuM_Mode(ModeMachine_EcuM_Mode* modeMachine);

void initModeGroup_currentMode_EcuM_EcuM_CurrentMode(void);



#endif

