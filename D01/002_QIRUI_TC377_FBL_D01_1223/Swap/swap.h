/*****************************************************************************
*
* Copyright (C) 2019 Infineon Technologies AG. All rights reserved.
*
* Infineon Technologies AG (INFINEON) is supplying this file for use
* exclusively with Infineon's microcontroller products. This file can be freely
* distributed within development tools and software supporting such microcontroller
* products.
*
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
******************************************************************************/

#ifndef SRC_APPSW_TRICORE_SOTA_H_
#define SRC_APPSW_TRICORE_SOTA_H_

#include "Ifx_Types.h"
#include "Ifx_reg.h"

#define Bank_Keep				0xEEu
#define Bank_Switch				0xFFu

/*!
 * \brief Writes enable Swap configuration if off.
 */
extern uint8 Enable_Swap_Config(void);

/*!
 * \brief Writes disable Swap configuration.
 */
extern uint8 Disable_Swap_Config(void);

/*!
 * \brief Configures UCB_SWAP_COPY and UCB_SWAP_COPY accordingly.
 */
extern uint8 configure_swap(uint32 map);

extern uint8 configure_swap_MainFunc(uint8 BankNum);

uint8 Read_ORIG_Swap_Info(void);
uint8 Read_COPY_Swap_Info(void);


#endif /* SRC_APPSW_TRICORE_SOTA_H_ */
