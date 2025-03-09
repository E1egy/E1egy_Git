/*============================================================================*/
/*  Copyright (C) 2016, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Processor.h>
 *  @brief      <>
 *  
 * <Compiler: Tasking    MCU:TC377>
 *  
 *  @author     <bo.zeng>
 *  @date       <05-12-2014>
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2014-12-05  bo.zeng       Initial version.
 *  V0.2.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li       Functional safety version.
 *  V2.0.0       2021-01-15  lizhi.huang   Ported to T377.
 */
/*============================================================================*/
#ifndef OS_PROCESSOR_H
#define OS_PROCESSOR_H

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/


/*=======[I N C L U D E S]====================================================*/
#include "Os.h"
#include "Ifx_Ssw_Infra.h"
/*------------------Compiler OS-------------------------*/
#define     ASM             						__asm                         		/* Embedded assembly. */
#define     OS_ALIGN(exp)    						__align(exp) 						/* DD_1_0318, Align by exp bytes. */
#define     OS_REG32(address)    					(*(volatile uint32*)(address)) /* DD_1_0325, Define 32-bit register. */
/*------------------End Compiler OS-------------------------*/

/*---------------------TC377-------------------------*/
/* Mask for OS_CORE_ID */
#define        OS_CORE_ID_MSK                     	(0x7u) /* DD_1_0168, Maximum value of core ID. */
/* Interrupt Service Provider */
#define        OS_ARCH_INT_CPU0                   	(0x00000000u)
#define        OS_ARCH_INT_CPU1                   	(0x00001000u)
#define        OS_ARCH_INT_CPU2                   	(0x00001800u)
#define        OS_ARCH_INT_DMA                    	(0x00000800u)

/*
 * CSFR
 */
/* Define macros to represent memory addresses or offsets. */
/*-----------------------------start of register address----------------------------*/
#define		   OS_REG_CUS_ID					   	0xFE50U
#define        OS_REG_CORE_ID                      	0xFE1CU
#define        OS_REG_ICR                          	0xFE2CU
#define        OS_REG_FCX                          	0xFE38U
#define        OS_REG_PCX                          	0xFE00U
#define        OS_REG_LCX                          	0xFE3CU
#define        OS_REG_PC                           	0xFE08U
#define        OS_REG_PSW                          	0xFE04U
#define        OS_REG_SYSCON                       	0xFE14U
#define        OS_REG_ISP                          	0xFE28U
#define        OS_REG_DBGSR                        	0xFD00U

#define 	   OS_REG_BIV							0xFE20
#define 	   OS_REG_BTV							0xFE24


#define        OS_CPU0_PC                          	OS_REG32(0xF881FE08u)
#define        OS_CPU1_PC                          	OS_REG32(0xF883FE08u)
#define        OS_CPU2_PC                          	OS_REG32(0xF885FE08u)

#define		   OS_CPU0_ISP						   	OS_REG32(0xF881FE28u)
#define		   OS_CPU1_ISP						   	OS_REG32(0xF883FE28u)
#define		   OS_CPU2_ISP						   	OS_REG32(0xF885FE28u)

#define        OS_CPU0_SYSCON						OS_REG32(0xF881FE14u)
#define        OS_CPU1_SYSCON                  		OS_REG32(0xF883FE14u)
#define        OS_CPU2_SYSCON                  		OS_REG32(0xF885FE14u)

#define        OS_CPU0_DBGSR_ADDR                  	(OS_REG_DBGSR)
#define        OS_CPU1_DBGSR_ADDR                  	(OS_REG_DBGSR)
#define        OS_CPU2_DBGSR_ADDR                  	(OS_REG_DBGSR)

/*
 * INT register
 */
/* Service Request Broadcast Register 0 */
#define        OS_INT_SRB0                          OS_REG32(0xF0037010u)
/* Service Request Broadcast Register 1 */
#define        OS_INT_SRB1                          OS_REG32(0xF0037014u)
/* Service Request Broadcast Register 2 */
#define        OS_INT_SRB2                          OS_REG32(0xF0037018u)

/*
 * SCU register
 */
#define       OS_SCU_PMCSR0                        	OS_REG32(0xF00360C8u)
#define       OS_SCU_PMCSR1                        	OS_REG32(0xF00360CCu)
#define       OS_SCU_PMCSR2                        	OS_REG32(0xF00360D0u)


#define       OS_SCU_CCUCON0                       	OS_REG32(0xF0036030u)
#define       OS_SCU_CCUCON1                       	OS_REG32(0xF0036034u)

/*
 * STM register
 */
#define        OS_MODULE_BASE_STM0                 	OS_REG32(0xF0001000u)
#define        OS_MODULE_BASE_STM1                 	OS_REG32(0xF0001100u)
#define        OS_MODULE_BASE_STM2                 	OS_REG32(0xF0001200u)

/* Compare Match Control Register */
#define        OS_STM0_CMCON                       	OS_REG32(0xF0001038u)
#define        OS_STM1_CMCON                       	OS_REG32(0xF0001138u)
#define        OS_STM2_CMCON                       	OS_REG32(0xF0001238u)

/* Compare Register */
#define        OS_STM0_CMP0                        	OS_REG32(0xF0001030u)
#define        OS_STM0_CMP1                        	OS_REG32(0xF0001034u)
#define        OS_STM1_CMP0                        	OS_REG32(0xF0001130u)
#define        OS_STM1_CMP1                        	OS_REG32(0xF0001134u)
#define        OS_STM2_CMP0                        	OS_REG32(0xF0001230u)
#define        OS_STM2_CMP1                        	OS_REG32(0xF0001234u)

/* Interrupt Control Register */
#define        OS_STM0_ICR                         	OS_REG32(0xF000103Cu)
#define        OS_STM1_ICR                         	OS_REG32(0xF000113Cu)
#define        OS_STM2_ICR                         	OS_REG32(0xF000123Cu)

#define        OS_STM0_TIM0                        	OS_REG32(0xF0001010u)
#define        OS_STM1_TIM0                        	OS_REG32(0xF0001110u)
#define        OS_STM2_TIM0                        	OS_REG32(0xF0001210u)

/* Interrupt Set/Clear Register */
#define        OS_STM0_ISCR                        	OS_REG32(0xF0001040u)
#define        OS_STM1_ISCR                        	OS_REG32(0xF0001140u)
#define        OS_STM2_ISCR                        	OS_REG32(0xF0001240u)

/*
 * Service Request Control Register Address. Used in os_app.
 */
#define OS_SRC_CPU0_SB_ADDR 						(0xF0038000u)
#define OS_SRC_CPU1_SB_ADDR 						(0xF0038004u)
#define OS_SRC_CPU2_SB_ADDR 						(0xF0038008u)
#define OS_SRC_SBCU_ADDR 							(0xF0038020u)
#define OS_SRC_EBCU_ADDR 							(0xF0038024u)
#define OS_SRC_AGBT0_SR_ADDR 						(0xF003802Cu)
#define OS_SRC_XBAR0_ADDR 							(0xF0038030u)
#define OS_SRC_XBAR2_ADDR 							(0xF0038038u)
#define OS_SRC_CERBERUS_SR0_ADDR 					(0xF0038040u)
#define OS_SRC_CERBERUS_SR1_ADDR 					(0xF0038044u)
#define OS_SRC_ASCLIN0_TX_ADDR 						(0xF0038050u)
#define OS_SRC_ASCLIN0_RX_ADDR 						(0xF0038054u)
#define OS_SRC_ASCLIN0_ERR_ADDR 					(0xF0038058u)
#define OS_SRC_ASCLIN1_TX_ADDR 						(0xF003805Cu)
#define OS_SRC_ASCLIN1_RX_ADDR 						(0xF0038060u)
#define OS_SRC_ASCLIN1_ERR_ADDR 					(0xF0038064u)
#define OS_SRC_ASCLIN2_TX_ADDR 						(0xF0038068u)
#define OS_SRC_ASCLIN2_RX_ADDR 						(0xF003806Cu)
#define OS_SRC_ASCLIN2_ERR_ADDR 					(0xF0038070u)
#define OS_SRC_ASCLIN3_TX_ADDR 						(0xF0038074u)
#define OS_SRC_ASCLIN3_RX_ADDR 						(0xF0038078u)
#define OS_SRC_ASCLIN3_ERR_ADDR 					(0xF003807Cu)
#define OS_SRC_ASCLIN4_TX_ADDR 						(0xF0038080u)
#define OS_SRC_ASCLIN4_RX_ADDR 						(0xF0038084u)
#define OS_SRC_ASCLIN4_ERR_ADDR 					(0xF0038088u)
#define OS_SRC_ASCLIN5_TX_ADDR 						(0xF003808Cu)
#define OS_SRC_ASCLIN5_RX_ADDR 						(0xF0038090u)
#define OS_SRC_ASCLIN5_ERR_ADDR 					(0xF0038094u)
#define OS_SRC_ASCLIN6_TX_ADDR 						(0xF0038098u)
#define OS_SRC_ASCLIN6_RX_ADDR 						(0xF003809Cu)
#define OS_SRC_ASCLIN6_ERR_ADDR					 	(0xF00380A0u)
#define OS_SRC_ASCLIN7_TX_ADDR 						(0xF00380A4u)
#define OS_SRC_ASCLIN7_RX_ADDR 						(0xF00380A8u)
#define OS_SRC_ASCLIN7_ERR_ADDR					 	(0xF00380ACu)
#define OS_SRC_ASCLIN8_TX_ADDR 						(0xF00380B0u)
#define OS_SRC_ASCLIN8_RX_ADDR 						(0xF00380B4u)
#define OS_SRC_ASCLIN8_ERR_ADDR					 	(0xF00380B8u)
#define OS_SRC_ASCLIN9_TX_ADDR 						(0xF00380BCu)
#define OS_SRC_ASCLIN9_RX_ADDR 						(0xF00380C0u)
#define OS_SRC_ASCLIN9_ERR_ADDR 					(0xF00380C4u)
#define OS_SRC_ASCLIN10_TX_ADDR 					(0xF00380C8u)
#define OS_SRC_ASCLIN10_RX_ADDR 					(0xF00380CCu)
#define OS_SRC_ASCLIN10_ERR_ADDR					(0xF00380D0u)
#define OS_SRC_ASCLIN11_TX_ADDR 					(0xF00380D4u)
#define OS_SRC_ASCLIN11_RX_ADDR 					(0xF00380D8u)
#define OS_SRC_ASCLIN11_ERR_ADDR					(0xF00380DCu)
#define OS_SRC_MTUDONE_ADDR 		                (0xF00380ECu)
#define OS_SRC_QSPI0_TX_ADDR 		                (0xF00380F0u)
#define OS_SRC_QSPI0_RX_ADDR 		                (0xF00380F4u)
#define OS_SRC_QSPI0_ERR_ADDR 		                (0xF00380F8u)
#define OS_SRC_QSPI0_PT_ADDR 		                (0xF00380FCu)
#define OS_SRC_QSPI0_U_ADDR 		                (0xF0038100u)
#define OS_SRC_QSPI1_TX_ADDR 		                (0xF0038104u)
#define OS_SRC_QSPI1_RX_ADDR 		                (0xF0038108u)
#define OS_SRC_QSPI1_ERR_ADDR 		                (0xF003810Cu)
#define OS_SRC_QSPI1_PT_ADDR 		                (0xF0038110u)
#define OS_SRC_QSPI1_U_ADDR 		                (0xF0038114u)
#define OS_SRC_QSPI2_TX_ADDR 		                (0xF0038118u)
#define OS_SRC_QSPI2_RX_ADDR 		                (0xF003811Cu)
#define OS_SRC_QSPI2_ERR_ADDR 		                (0xF0038120u)
#define OS_SRC_QSPI2_PT_ADDR 		                (0xF0038124u)
#define OS_SRC_QSPI2_U_ADDR 		                (0xF0038128u)
#define OS_SRC_QSPI3_TX_ADDR 		                (0xF003812Cu)
#define OS_SRC_QSPI3_RX_ADDR 		                (0xF0038130u)
#define OS_SRC_QSPI3_ERR_ADDR 		                (0xF0038134u)
#define OS_SRC_QSPI3_PT_ADDR 		                (0xF0038138u)
#define OS_SRC_QSPI3_U_ADDR 		                (0xF003813Cu)
#define OS_SRC_QSPI4_TX_ADDR 		                (0xF0038140u)
#define OS_SRC_QSPI4_RX_ADDR 		                (0xF0038144u)
#define OS_SRC_QSPI4_ERR_ADDR 		                (0xF0038148u)
#define OS_SRC_QSPI4_PT_ADDR 		                (0xF003814Cu)
#define OS_SRC_QSPI4_U_ADDR 		                (0xF0038150u)
#define OS_SRC_HSCT0_SR_ADDR 		                (0xF0038180u)
#define OS_SRC_HSSL0_CH0_COK_ADDR 	                (0xF0038190u)
#define OS_SRC_HSSL0_CH0_RDI_ADDR 	                (0xF0038194u)
#define OS_SRC_HSSL0_CH0_ERR_ADDR 	                (0xF0038198u)
#define OS_SRC_HSSL0_CH0_TRG_ADDR 	                (0xF003819Cu)
#define OS_SRC_HSSL0_CH1_COK_ADDR 	                (0xF00381A0u)
#define OS_SRC_HSSL0_CH1_RDI_ADDR                   (0xF00381A4u)
#define OS_SRC_HSSL0_CH1_ERR_ADDR                   (0xF00381A8u)
#define OS_SRC_HSSL0_CH1_TRG_ADDR                   (0xF00381ACu)
#define OS_SRC_HSSL0_CH2_COK_ADDR                   (0xF00381B0u)
#define OS_SRC_HSSL0_CH2_RDI_ADDR                   (0xF00381B4u)
#define OS_SRC_HSSL0_CH2_ERR_ADDR                   (0xF00381B8u)
#define OS_SRC_HSSL0_CH2_TRG_ADDR                   (0xF00381BCu)
#define OS_SRC_HSSL0_CH3_COK_ADDR                   (0xF00381C0u)
#define OS_SRC_HSSL0_CH3_RDI_ADDR                   (0xF00381C4u)
#define OS_SRC_HSSL0_CH3_ERR_ADDR                   (0xF00381C8u)
#define OS_SRC_HSSL0_CH3_TRG_ADDR                   (0xF00381CCu)
#define OS_SRC_HSSL0_EXI_ADDR 		                (0xF00381D0u)

//#define OS_SRC_GETH1_GETH0_SR0_ADDR                 (0xF00381D4u)
//#define OS_SRC_GETH1_GETH0_SR1_ADDR                 (0xF00381D8u)
//#define OS_SRC_GETH1_GETH0_SR2_ADDR                 (0xF00381DCu)
//#define OS_SRC_GETH1_GETH0_SR3_ADDR                 (0xF00381E0u)
//#define OS_SRC_GETH1_GETH0_SR4_ADDR                 (0xF00381E4u)
//#define OS_SRC_GETH1_GETH0_SR5_ADDR                 (0xF00381E8u)
//#define OS_SRC_GETH1_GETH0_SR6_ADDR                 (0xF00381ECu)
//#define OS_SRC_GETH1_GETH0_SR7_ADDR                 (0xF00381F0u)
//#define OS_SRC_GETH1_GETH0_SR8_ADDR                 (0xF00381F4u)
//#define OS_SRC_GETH1_GETH0_SR9_ADDR                 (0xF00381F8u)

#define OS_SRC_I2C0_DTR_ADDR 		                (0xF0038220u)
#define OS_SRC_I2C0_ERR_ADDR 		                (0xF0038224u)
#define OS_SRC_I2C0_P_ADDR 			                (0xF0038228u)
#define OS_SRC_SENT0_SR_ADDR 		                (0xF0038240u)
#define OS_SRC_SENT1_SR_ADDR                        (0xF0038244u)
#define OS_SRC_SENT2_SR_ADDR                        (0xF0038248u)
#define OS_SRC_SENT3_SR_ADDR                        (0xF003824Cu)
#define OS_SRC_SENT4_SR_ADDR                        (0xF0038250u)
#define OS_SRC_SENT5_SR_ADDR                        (0xF0038254u)
#define OS_SRC_SENT6_SR_ADDR                        (0xF0038258u)
#define OS_SRC_SENT7_SR_ADDR                        (0xF003825Cu)
#define OS_SRC_SENT8_SR_ADDR                        (0xF0038260u)
#define OS_SRC_SENT9_SR_ADDR                        (0xF0038264u)
#define OS_SRC_MSC0_SR0_ADDR                        (0xF0038270u)
#define OS_SRC_MSC0_SR1_ADDR                        (0xF0038274u)
#define OS_SRC_MSC0_SR2_ADDR                        (0xF0038278u)
#define OS_SRC_MSC0_SR3_ADDR                        (0xF003827Cu)
#define OS_SRC_MSC0_SR4_ADDR                        (0xF0038280u)
#define OS_SRC_MSC1_SR0_ADDR                        (0xF0038284u)
#define OS_SRC_MSC1_SR1_ADDR                        (0xF0038288u)
#define OS_SRC_MSC1_SR2_ADDR                        (0xF003828Cu)
#define OS_SRC_MSC1_SR3_ADDR                        (0xF0038290u)
#define OS_SRC_MSC1_SR4_ADDR                        (0xF0038294u)
#define OS_SRC_CCU6_CCU0_SR0_ADDR 					(0xF00382C0u)
#define OS_SRC_CCU6_CCU0_SR1_ADDR                   (0xF00382C4u)
#define OS_SRC_CCU6_CCU0_SR2_ADDR                   (0xF00382C8u)
#define OS_SRC_CCU6_CCU0_SR3_ADDR                   (0xF00382CCu)
#define OS_SRC_CCU6_CCU1_SR0_ADDR                   (0xF00382D0u)
#define OS_SRC_CCU6_CCU1_SR1_ADDR                   (0xF00382D4u)
#define OS_SRC_CCU6_CCU1_SR2_ADDR                   (0xF00382D8u)
#define OS_SRC_CCU6_CCU1_SR3_ADDR                   (0xF00382DCu)
#define OS_SRC_GPT120_CIRQ_ADDR                     (0xF00382E0u)
#define OS_SRC_GPT120_T2_ADDR                       (0xF00382E4u)
#define OS_SRC_GPT120_T3_ADDR                       (0xF00382E8u)
#define OS_SRC_GPT120_T4_ADDR                       (0xF00382ECu)
#define OS_SRC_GPT120_T5_ADDR                       (0xF00382F0u)
#define OS_SRC_GPT120_T6_ADDR                       (0xF00382F4u)
#define OS_SRC_STM0_SR0_ADDR                        (0xF0038300u)
#define OS_SRC_STM0_SR1_ADDR                        (0xF0038304u)
#define OS_SRC_STM1_SR0_ADDR                        (0xF0038308u)
#define OS_SRC_STM1_SR1_ADDR                        (0xF003830Cu)
#define OS_SRC_STM2_SR0_ADDR                        (0xF0038310u)
#define OS_SRC_STM2_SR1_ADDR                        (0xF0038314u)
#define OS_SRC_FCE0_SR_ADDR                         (0xF0038330u)
#define OS_SRC_DMA0_ERR0_ADDR                       (0xF0038340u)
#define OS_SRC_DMA0_ERR1_ADDR                       (0xF0038344u)
#define OS_SRC_DMA0_ERR2_ADDR                       (0xF0038348u)
#define OS_SRC_DMA0_ERR3_ADDR                       (0xF003834Cu)
#define OS_SRC_DMA0_CH0_ADDR                        (0xF0038370u)
#define OS_SRC_DMA0_CH1_ADDR                        (0xF0038374u)
#define OS_SRC_DMA0_CH2_ADDR                        (0xF0038378u)
#define OS_SRC_DMA0_CH3_ADDR                        (0xF003837Cu)
#define OS_SRC_DMA0_CH4_ADDR                        (0xF0038380u)
#define OS_SRC_DMA0_CH5_ADDR                        (0xF0038384u)
#define OS_SRC_DMA0_CH6_ADDR                        (0xF0038388u)
#define OS_SRC_DMA0_CH7_ADDR                        (0xF003838Cu)
#define OS_SRC_DMA0_CH8_ADDR                        (0xF0038390u)
#define OS_SRC_DMA0_CH9_ADDR                        (0xF0038394u)
#define OS_SRC_DMA0_CH10_ADDR                       (0xF0038398u)
#define OS_SRC_DMA0_CH11_ADDR                       (0xF003839Cu)
#define OS_SRC_DMA0_CH12_ADDR                       (0xF00383A0u)
#define OS_SRC_DMA0_CH13_ADDR                       (0xF00383A4u)
#define OS_SRC_DMA0_CH14_ADDR                       (0xF00383A8u)
#define OS_SRC_DMA0_CH15_ADDR                       (0xF00383ACu)
#define OS_SRC_DMA0_CH16_ADDR                       (0xF00383B0u)
#define OS_SRC_DMA0_CH17_ADDR                       (0xF00383B4u)
#define OS_SRC_DMA0_CH18_ADDR                       (0xF00383B8u)
#define OS_SRC_DMA0_CH19_ADDR                       (0xF00383BCu)
#define OS_SRC_DMA0_CH20_ADDR                       (0xF00383C0u)
#define OS_SRC_DMA0_CH21_ADDR                       (0xF00383C4u)
#define OS_SRC_DMA0_CH22_ADDR                       (0xF00383C8u)
#define OS_SRC_DMA0_CH23_ADDR                       (0xF00383CCu)
#define OS_SRC_DMA0_CH24_ADDR                       (0xF00383D0u)
#define OS_SRC_DMA0_CH25_ADDR                       (0xF00383D4u)
#define OS_SRC_DMA0_CH26_ADDR                       (0xF00383D8u)
#define OS_SRC_DMA0_CH27_ADDR                       (0xF00383DCu)
#define OS_SRC_DMA0_CH28_ADDR                       (0xF00383E0u)
#define OS_SRC_DMA0_CH29_ADDR                       (0xF00383E4u)
#define OS_SRC_DMA0_CH30_ADDR                       (0xF00383E8u)
#define OS_SRC_DMA0_CH31_ADDR                       (0xF00383ECu)
#define OS_SRC_DMA0_CH32_ADDR                       (0xF00383F0u)
#define OS_SRC_DMA0_CH33_ADDR                       (0xF00383F4u)
#define OS_SRC_DMA0_CH34_ADDR                       (0xF00383F8u)
#define OS_SRC_DMA0_CH35_ADDR                       (0xF00383FCu)
#define OS_SRC_DMA0_CH36_ADDR                       (0xF0038400u)
#define OS_SRC_DMA0_CH37_ADDR                       (0xF0038404u)
#define OS_SRC_DMA0_CH38_ADDR                       (0xF0038408u)
#define OS_SRC_DMA0_CH39_ADDR                       (0xF003840Cu)
#define OS_SRC_DMA0_CH40_ADDR                       (0xF0038410u)
#define OS_SRC_DMA0_CH41_ADDR                       (0xF0038414u)
#define OS_SRC_DMA0_CH42_ADDR                       (0xF0038418u)
#define OS_SRC_DMA0_CH43_ADDR                       (0xF003841Cu)
#define OS_SRC_DMA0_CH44_ADDR                       (0xF0038420u)
#define OS_SRC_DMA0_CH45_ADDR                       (0xF0038424u)
#define OS_SRC_DMA0_CH46_ADDR                       (0xF0038428u)
#define OS_SRC_DMA0_CH47_ADDR                       (0xF003842Cu)
#define OS_SRC_DMA0_CH48_ADDR                       (0xF0038430u)
#define OS_SRC_DMA0_CH49_ADDR                       (0xF0038434u)
#define OS_SRC_DMA0_CH50_ADDR                       (0xF0038438u)
#define OS_SRC_DMA0_CH51_ADDR                       (0xF003843Cu)
#define OS_SRC_DMA0_CH52_ADDR                       (0xF0038440u)
#define OS_SRC_DMA0_CH53_ADDR                       (0xF0038444u)
#define OS_SRC_DMA0_CH54_ADDR                       (0xF0038448u)
#define OS_SRC_DMA0_CH55_ADDR                       (0xF003844Cu)
#define OS_SRC_DMA0_CH56_ADDR                       (0xF0038450u)
#define OS_SRC_DMA0_CH57_ADDR                       (0xF0038454u)
#define OS_SRC_DMA0_CH58_ADDR                       (0xF0038458u)
#define OS_SRC_DMA0_CH59_ADDR                       (0xF003845Cu)
#define OS_SRC_DMA0_CH60_ADDR                       (0xF0038460u)
#define OS_SRC_DMA0_CH61_ADDR                       (0xF0038464u)
#define OS_SRC_DMA0_CH62_ADDR                       (0xF0038468u)
#define OS_SRC_DMA0_CH63_ADDR                       (0xF003846Cu)
#define OS_SRC_DMA0_CH64_ADDR                       (0xF0038470u)
#define OS_SRC_DMA0_CH65_ADDR                       (0xF0038474u)
#define OS_SRC_DMA0_CH66_ADDR                       (0xF0038478u)
#define OS_SRC_DMA0_CH67_ADDR                       (0xF003847Cu)
#define OS_SRC_DMA0_CH68_ADDR                       (0xF0038480u)
#define OS_SRC_DMA0_CH69_ADDR                       (0xF0038484u)
#define OS_SRC_DMA0_CH70_ADDR                       (0xF0038488u)
#define OS_SRC_DMA0_CH71_ADDR                       (0xF003848Cu)
#define OS_SRC_DMA0_CH72_ADDR                       (0xF0038490u)
#define OS_SRC_DMA0_CH73_ADDR                       (0xF0038494u)
#define OS_SRC_DMA0_CH74_ADDR                       (0xF0038498u)
#define OS_SRC_DMA0_CH75_ADDR                       (0xF003849Cu)
#define OS_SRC_DMA0_CH76_ADDR                       (0xF00384A0u)
#define OS_SRC_DMA0_CH77_ADDR                       (0xF00384A4u)
#define OS_SRC_DMA0_CH78_ADDR                       (0xF00384A8u)
#define OS_SRC_DMA0_CH79_ADDR                       (0xF00384ACu)
#define OS_SRC_DMA0_CH80_ADDR                       (0xF00384B0u)
#define OS_SRC_DMA0_CH81_ADDR                       (0xF00384B4u)
#define OS_SRC_DMA0_CH82_ADDR                       (0xF00384B8u)
#define OS_SRC_DMA0_CH83_ADDR                       (0xF00384BCu)
#define OS_SRC_DMA0_CH84_ADDR                       (0xF00384C0u)
#define OS_SRC_DMA0_CH85_ADDR                       (0xF00384C4u)
#define OS_SRC_DMA0_CH86_ADDR                       (0xF00384C8u)
#define OS_SRC_DMA0_CH87_ADDR                       (0xF00384CCu)
#define OS_SRC_DMA0_CH88_ADDR                       (0xF00384D0u)
#define OS_SRC_DMA0_CH89_ADDR                       (0xF00384D4u)
#define OS_SRC_DMA0_CH90_ADDR                       (0xF00384D8u)
#define OS_SRC_DMA0_CH91_ADDR                       (0xF00384DCu)
#define OS_SRC_DMA0_CH92_ADDR                       (0xF00384E0u)
#define OS_SRC_DMA0_CH93_ADDR                       (0xF00384E4u)
#define OS_SRC_DMA0_CH94_ADDR                       (0xF00384E8u)
#define OS_SRC_DMA0_CH95_ADDR                       (0xF00384ECu)
#define OS_SRC_DMA0_CH96_ADDR                       (0xF00384F0u)
#define OS_SRC_DMA0_CH97_ADDR                       (0xF00384F4u)
#define OS_SRC_DMA0_CH98_ADDR                       (0xF00384F8u)
#define OS_SRC_DMA0_CH99_ADDR                       (0xF00384FCu)
#define OS_SRC_DMA0_CH100_ADDR                      (0xF0038500u)
#define OS_SRC_DMA0_CH101_ADDR                      (0xF0038504u)
#define OS_SRC_DMA0_CH102_ADDR                      (0xF0038508u)
#define OS_SRC_DMA0_CH103_ADDR                      (0xF003850Cu)
#define OS_SRC_DMA0_CH104_ADDR                      (0xF0038510u)
#define OS_SRC_DMA0_CH105_ADDR                      (0xF0038514u)
#define OS_SRC_DMA0_CH106_ADDR                      (0xF0038518u)
#define OS_SRC_DMA0_CH107_ADDR                      (0xF003851Cu)
#define OS_SRC_DMA0_CH108_ADDR                      (0xF0038520u)
#define OS_SRC_DMA0_CH109_ADDR                      (0xF0038524u)
#define OS_SRC_DMA0_CH110_ADDR                      (0xF0038528u)
#define OS_SRC_DMA0_CH111_ADDR                      (0xF003852Cu)
#define OS_SRC_DMA0_CH112_ADDR                      (0xF0038530u)
#define OS_SRC_DMA0_CH113_ADDR                      (0xF0038534u)
#define OS_SRC_DMA0_CH114_ADDR                      (0xF0038538u)
#define OS_SRC_DMA0_CH115_ADDR                      (0xF003853Cu)
#define OS_SRC_DMA0_CH116_ADDR                      (0xF0038540u)
#define OS_SRC_DMA0_CH117_ADDR                      (0xF0038544u)
#define OS_SRC_DMA0_CH118_ADDR                      (0xF0038548u)
#define OS_SRC_DMA0_CH119_ADDR                      (0xF003854Cu)
#define OS_SRC_DMA0_CH120_ADDR                      (0xF0038550u)
#define OS_SRC_DMA0_CH121_ADDR                      (0xF0038554u)
#define OS_SRC_DMA0_CH122_ADDR                      (0xF0038558u)
#define OS_SRC_DMA0_CH123_ADDR                      (0xF003855Cu)
#define OS_SRC_DMA0_CH124_ADDR                      (0xF0038560u)
#define OS_SRC_DMA0_CH125_ADDR                      (0xF0038564u)
#define OS_SRC_DMA0_CH126_ADDR                      (0xF0038568u)
#define OS_SRC_DMA0_CH127_ADDR                      (0xF003856Cu)
#define OS_SRC_SDMMC0_ERR_ADDR                      (0xF0038570u)
#define OS_SRC_SDMMC0_DMA_ADDR                      (0xF0038574u)
#define OS_SRC_GETH0_SR0_ADDR                       (0xF0038580u)
#define OS_SRC_GETH0_SR1_ADDR                       (0xF0038584u)
#define OS_SRC_GETH0_SR2_ADDR                       (0xF0038588u)
#define OS_SRC_GETH0_SR3_ADDR                       (0xF003858Cu)
#define OS_SRC_GETH0_SR4_ADDR                       (0xF0038590u)
#define OS_SRC_GETH0_SR5_ADDR                       (0xF0038594u)
#define OS_SRC_GETH0_SR6_ADDR                       (0xF0038598u)
#define OS_SRC_GETH0_SR7_ADDR                       (0xF003859Cu)
#define OS_SRC_GETH0_SR8_ADDR                       (0xF00385A0u)
#define OS_SRC_GETH0_SR9_ADDR                       (0xF00385A4u)
#define OS_SRC_CAN0_INT0_ADDR                       (0xF00385B0u)
#define OS_SRC_CAN0_INT1_ADDR                       (0xF00385B4u)
#define OS_SRC_CAN0_INT2_ADDR                       (0xF00385B8u)
#define OS_SRC_CAN0_INT3_ADDR                       (0xF00385BCu)
#define OS_SRC_CAN0_INT4_ADDR                       (0xF00385C0u)
#define OS_SRC_CAN0_INT5_ADDR                       (0xF00385C4u)
#define OS_SRC_CAN0_INT6_ADDR                       (0xF00385C8u)
#define OS_SRC_CAN0_INT7_ADDR                       (0xF00385CCu)
#define OS_SRC_CAN0_INT8_ADDR                       (0xF00385D0u)
#define OS_SRC_CAN0_INT9_ADDR                       (0xF00385D4u)
#define OS_SRC_CAN0_INT10_ADDR                      (0xF00385D8u)
#define OS_SRC_CAN0_INT11_ADDR                      (0xF00385DCu)
#define OS_SRC_CAN0_INT12_ADDR                      (0xF00385E0u)
#define OS_SRC_CAN0_INT13_ADDR                      (0xF00385E4u)
#define OS_SRC_CAN0_INT14_ADDR                      (0xF00385E8u)
#define OS_SRC_CAN0_INT15_ADDR                      (0xF00385ECu)
#define OS_SRC_CAN1_INT0_ADDR                       (0xF00385F0u)
#define OS_SRC_CAN1_INT1_ADDR                       (0xF00385F4u)
#define OS_SRC_CAN1_INT2_ADDR                       (0xF00385F8u)
#define OS_SRC_CAN1_INT3_ADDR                       (0xF00385FCu)
#define OS_SRC_CAN1_INT4_ADDR                       (0xF0038600u)
#define OS_SRC_CAN1_INT5_ADDR                       (0xF0038604u)
#define OS_SRC_CAN1_INT6_ADDR                       (0xF0038608u)
#define OS_SRC_CAN1_INT7_ADDR                       (0xF003860Cu)
#define OS_SRC_CAN1_INT8_ADDR                       (0xF0038610u)
#define OS_SRC_CAN1_INT9_ADDR                       (0xF0038614u)
#define OS_SRC_CAN1_INT10_ADDR                      (0xF0038618u)
#define OS_SRC_CAN1_INT11_ADDR                      (0xF003861Cu)
#define OS_SRC_CAN1_INT12_ADDR                      (0xF0038620u)
#define OS_SRC_CAN1_INT13_ADDR                      (0xF0038624u)
#define OS_SRC_CAN1_INT14_ADDR                      (0xF0038628u)
#define OS_SRC_CAN1_INT15_ADDR                      (0xF003862Cu)
#define OS_SRC_CAN2_INT0_ADDR                       (0xF0038630u)
#define OS_SRC_CAN2_INT1_ADDR                       (0xF0038634u)
#define OS_SRC_CAN2_INT2_ADDR                       (0xF0038638u)
#define OS_SRC_CAN2_INT3_ADDR                       (0xF003863Cu)
#define OS_SRC_CAN2_INT4_ADDR                       (0xF0038640u)
#define OS_SRC_CAN2_INT5_ADDR                       (0xF0038644u)
#define OS_SRC_CAN2_INT6_ADDR                       (0xF0038648u)
#define OS_SRC_CAN2_INT7_ADDR                       (0xF003864Cu)
#define OS_SRC_CAN2_INT8_ADDR                       (0xF0038650u)
#define OS_SRC_CAN2_INT9_ADDR                       (0xF0038654u)
#define OS_SRC_CAN2_INT10_ADDR                      (0xF0038658u)
#define OS_SRC_CAN2_INT11_ADDR                      (0xF003865Cu)
#define OS_SRC_CAN2_INT12_ADDR                      (0xF0038660u)
#define OS_SRC_CAN2_INT13_ADDR                      (0xF0038664u)
#define OS_SRC_CAN2_INT14_ADDR                      (0xF0038668u)
#define OS_SRC_CAN2_INT15_ADDR                      (0xF003866Cu)
#define OS_SRC_VADC_G0_SR0_ADDR                     (0xF0038670u)
#define OS_SRC_VADC_G0_SR1_ADDR                     (0xF0038674u)
#define OS_SRC_VADC_G0_SR2_ADDR                     (0xF0038678u)
#define OS_SRC_VADC_G0_SR3_ADDR                     (0xF003867Cu)
#define OS_SRC_VADC_G1_SR0_ADDR                     (0xF0038680u)
#define OS_SRC_VADC_G1_SR1_ADDR                     (0xF0038684u)
#define OS_SRC_VADC_G1_SR2_ADDR                     (0xF0038688u)
#define OS_SRC_VADC_G1_SR3_ADDR                     (0xF003868Cu)
#define OS_SRC_VADC_G2_SR0_ADDR                     (0xF0038690u)
#define OS_SRC_VADC_G2_SR1_ADDR                     (0xF0038694u)
#define OS_SRC_VADC_G2_SR2_ADDR                     (0xF0038698u)
#define OS_SRC_VADC_G2_SR3_ADDR                     (0xF003869Cu)
#define OS_SRC_VADC_G3_SR0_ADDR                     (0xF00386A0u)
#define OS_SRC_VADC_G3_SR1_ADDR                     (0xF00386A4u)
#define OS_SRC_VADC_G3_SR2_ADDR                     (0xF00386A8u)
#define OS_SRC_VADC_G3_SR3_ADDR                     (0xF00386ACu)
#define OS_SRC_VADC_G8_SR0_SR_ADDR                  (0xF00386F0u)
#define OS_SRC_VADC_G8_SR1_SR_ADDR                  (0xF00386F4u)
#define OS_SRC_VADC_G8_SR2_SR_ADDR                  (0xF00386F8u)
#define OS_SRC_VADC_G8_SR3_SR_ADDR                  (0xF00386FCu)
#define OS_SRC_VADC_G9_SR0_SR_ADDR                  (0xF0038700u)
#define OS_SRC_VADC_G9_SR1_SR_ADDR                  (0xF0038704u)
#define OS_SRC_VADC_G9_SR2_SR_ADDR                  (0xF0038708u)
#define OS_SRC_VADC_G9_SR3_SR_ADDR                  (0xF003870Cu)
#define OS_SRC_VADC_G10_SR0_SR_ADDR                 (0xF0038710u)
#define OS_SRC_VADC_G10_SR1_SR_ADDR                 (0xF0038714u)
#define OS_SRC_VADC_G10_SR2_SR_ADDR                 (0xF0038718u)
#define OS_SRC_VADC_G10_SR3_SR_ADDR                 (0xF003871Cu)
#define OS_SRC_VADC_G11_SR0_SR_ADDR                 (0xF0038720u)
#define OS_SRC_VADC_G11_SR1_SR_ADDR                 (0xF0038724u)
#define OS_SRC_VADC_G11_SR2_SR_ADDR                 (0xF0038728u)
#define OS_SRC_VADC_G11_SR3_SR_ADDR                 (0xF003872Cu)
#define OS_SRC_VADC_FC0_SR0_ADDR                    (0xF0038730u)
#define OS_SRC_VADC_FC1_SR0_ADDR                    (0xF0038734u)
#define OS_SRC_VADC_FC2_SR0_ADDR                    (0xF0038738u)
#define OS_SRC_VADC_FC3_SR0_ADDR                    (0xF003873Cu)
#define OS_SRC_VADC_CG0_SR0_ADDR                    (0xF0038750u)
#define OS_SRC_VADC_CG0_SR1_ADDR                    (0xF0038754u)
#define OS_SRC_VADC_CG0_SR2_ADDR                    (0xF0038758u)
#define OS_SRC_VADC_CG0_SR3_ADDR                    (0xF003875Cu)
#define OS_SRC_VADC_CG1_SR0_ADDR                    (0xF0038760u)
#define OS_SRC_VADC_CG1_SR1_ADDR                    (0xF0038764u)
#define OS_SRC_VADC_CG1_SR2_ADDR                    (0xF0038768u)
#define OS_SRC_VADC_CG1_SR3_ADDR                    (0xF003876Cu)
#define OS_SRC_DSADC0_SRM_ADDR                      (0xF0038770u)
#define OS_SRC_DSADC0_SRA_ADDR                      (0xF0038774u)
#define OS_SRC_DSADC1_SRM_ADDR                      (0xF0038778u)
#define OS_SRC_DSADC1_SRA_ADDR                      (0xF003877Cu)
#define OS_SRC_DSADC2_SRM_ADDR                      (0xF0038780u)
#define OS_SRC_DSADC2_SRA_ADDR                      (0xF0038784u)
#define OS_SRC_DSADC3_SRM_ADDR                      (0xF0038788u)
#define OS_SRC_DSADC3_SRA_ADDR                      (0xF003878Cu)
#define OS_SRC_DSADC4_SRM_ADDR                      (0xF0038790u)
#define OS_SRC_DSADC4_SRA_ADDR                      (0xF0038794u)
#define OS_SRC_DSADC5_SRM_ADDR                      (0xF0038798u)
#define OS_SRC_DSADC5_SRA_ADDR                      (0xF003879Cu)
#define OS_SRC_ERAY0_INT0_ADDR                      (0xF0038800u)
#define OS_SRC_ERAY0_INT1_ADDR                      (0xF0038804u)
#define OS_SRC_ERAY0_TINT0_ADDR                     (0xF0038808u)
#define OS_SRC_ERAY0_TINT1_ADDR                     (0xF003880Cu)
#define OS_SRC_ERAY0_NDAT0_ADDR                     (0xF0038810u)
#define OS_SRC_ERAY0_NDAT1_ADDR                     (0xF0038814u)
#define OS_SRC_ERAY0_MBSC0_ADDR                     (0xF0038818u)
#define OS_SRC_ERAY0_MBSC1_ADDR                     (0xF003881Cu)
#define OS_SRC_ERAY0_OBUSY_ADDR                     (0xF0038820u)
#define OS_SRC_ERAY0_IBUSY_ADDR                     (0xF0038824u)
#define OS_SRC_DMUHOST_ADDR 						(0xF0038860u)
#define OS_SRC_DMUFSI_ADDR 							(0xF0038864u)
#define OS_SRC_HSM0_ADDR 							(0xF0038870u)
#define OS_SRC_HSM0_HSM1_ADDR 						(0xF0038874u)
#define OS_SRC_SCUERU0_ADDR 						(0xF0038880u)
#define OS_SRC_SCUERU1_ADDR                         (0xF0038884u)
#define OS_SRC_SCUERU2_ADDR                         (0xF0038888u)
#define OS_SRC_SCUERU3_ADDR                         (0xF003888Cu)
#define OS_SRC_PMSDTS_ADDR 	                        (0xF00388ACu)
#define OS_SRC_PMS0_SR_ADDR                         (0xF00388B0u)
#define OS_SRC_PMS1_SR_ADDR                         (0xF00388B4u)
#define OS_SRC_PMS2_SR_ADDR                         (0xF00388B8u)
#define OS_SRC_PMS3_SR_ADDR                         (0xF00388BCu)
#define OS_SRC_SCR_ADDR 	                        (0xF00388C0u)
#define OS_SRC_SMU0_SR0_ADDR                        (0xF00388D0u)
#define OS_SRC_SMU0_SR1_ADDR                        (0xF00388D4u)
#define OS_SRC_SMU0_SR2_ADDR                        (0xF00388D8u)
#define OS_SRC_PSI50_SR0_ADDR                       (0xF00388E0u)
#define OS_SRC_PSI50_SR1_ADDR                       (0xF00388E4u)
#define OS_SRC_PSI50_SR2_ADDR                       (0xF00388E8u)
#define OS_SRC_PSI50_SR3_ADDR                       (0xF00388ECu)
#define OS_SRC_PSI50_SR4_ADDR                       (0xF00388F0u)
#define OS_SRC_PSI50_SR5_ADDR                       (0xF00388F4u)
#define OS_SRC_PSI50_SR6_ADDR                       (0xF00388F8u)
#define OS_SRC_PSI50_SR7_ADDR                       (0xF00388FCu)
#define OS_SRC_DAM0_LI0_ADDR                        (0xF0038910u)
#define OS_SRC_DAM0_RI0_ADDR                        (0xF0038914u)
#define OS_SRC_DAM0_LI1_ADDR                        (0xF0038918u)
#define OS_SRC_DAM0_RI1_ADDR                        (0xF003891Cu)
#define OS_SRC_DAM0_DR_ADDR                         (0xF0038920u)
#define OS_SRC_DAM0_ERR_ADDR                        (0xF0038924u)
#define OS_SRC_CIF0_MI_ADDR                         (0xF0038940u)
#define OS_SRC_CIF0_MIEP_ADDR                       (0xF0038944u)
#define OS_SRC_CIF0_ISP_ADDR                        (0xF0038948u)
#define OS_SRC_CIF0_MJPEG_ADDR                      (0xF003894Cu)
#define OS_SRC_PSI5S0_SR0_ADDR                      (0xF0038950u)
#define OS_SRC_PSI5S0_SR1_ADDR                      (0xF0038954u)
#define OS_SRC_PSI5S0_SR2_ADDR                      (0xF0038958u)
#define OS_SRC_PSI5S0_SR3_ADDR                      (0xF003895Cu)
#define OS_SRC_PSI5S0_SR4_ADDR                      (0xF0038960u)
#define OS_SRC_PSI5S0_SR5_ADDR                      (0xF0038964u)
#define OS_SRC_PSI5S0_SR6_ADDR                      (0xF0038968u)
#define OS_SRC_PSI5S0_SR7_ADDR                      (0xF003896Cu)
#define OS_SRC_GPSR0_SR0_ADDR                       (0xF0038990u)
#define OS_SRC_GPSR0_SR1_ADDR                       (0xF0038994u)
#define OS_SRC_GPSR0_SR2_ADDR                       (0xF0038998u)
#define OS_SRC_GPSR0_SR3_ADDR                       (0xF003899Cu)
#define OS_SRC_GPSR0_SR4_ADDR                       (0xF00389A0u)
#define OS_SRC_GPSR0_SR5_ADDR                       (0xF00389A4u)
#define OS_SRC_GPSR0_SR6_ADDR                       (0xF00389A8u)
#define OS_SRC_GPSR0_SR7_ADDR                       (0xF00389ACu)
#define OS_SRC_GPSR1_SR0_ADDR                       (0xF00389B0u)
#define OS_SRC_GPSR1_SR1_ADDR                       (0xF00389B4u)
#define OS_SRC_GPSR1_SR2_ADDR                       (0xF00389B8u)
#define OS_SRC_GPSR1_SR3_ADDR                       (0xF00389BCu)
#define OS_SRC_GPSR1_SR4_ADDR                       (0xF00389C0u)
#define OS_SRC_GPSR1_SR5_ADDR                       (0xF00389C4u)
#define OS_SRC_GPSR1_SR6_ADDR                       (0xF00389C8u)
#define OS_SRC_GPSR1_SR7_ADDR                       (0xF00389CCu)
#define OS_SRC_GPSR2_SR0_ADDR                       (0xF00389D0u)
#define OS_SRC_GPSR2_SR1_ADDR                       (0xF00389D4u)
#define OS_SRC_GPSR2_SR2_ADDR                       (0xF00389D8u)
#define OS_SRC_GPSR2_SR3_ADDR                       (0xF00389DCu)
#define OS_SRC_GPSR2_SR4_ADDR                       (0xF00389E0u)
#define OS_SRC_GPSR2_SR5_ADDR                       (0xF00389E4u)
#define OS_SRC_GPSR2_SR6_ADDR                       (0xF00389E8u)
#define OS_SRC_GPSR2_SR7_ADDR                       (0xF00389ECu)
#define OS_SRC_GTM_AEIIRQ_ADDR                      (0xF0038A70u)
#define OS_SRC_GTM_ARUIRQ0_ADDR                     (0xF0038A74u)
#define OS_SRC_GTM_ARUIRQ1_ADDR                     (0xF0038A78u)
#define OS_SRC_GTM_ARUIRQ2_ADDR                     (0xF0038A7Cu)
#define OS_SRC_GTM_BRCIRQ_ADDR                      (0xF0038A80u)
#define OS_SRC_GTM_CMBIRQ_ADDR                      (0xF0038A84u)
#define OS_SRC_GTM_SPEIRQ0_ADDR                     (0xF0038A88u)
#define OS_SRC_GTM_SPEIRQ1_ADDR                     (0xF0038A8Cu)
#define OS_SRC_GTM_PSM0_0_ADDR                      (0xF0038AA0u)
#define OS_SRC_GTM_PSM0_1_ADDR                      (0xF0038AA4u)
#define OS_SRC_GTM_PSM0_2_ADDR                      (0xF0038AA8u)
#define OS_SRC_GTM_PSM0_3_ADDR                      (0xF0038AACu)
#define OS_SRC_GTM_PSM0_4_ADDR                      (0xF0038AB0u)
#define OS_SRC_GTM_PSM0_5_ADDR                      (0xF0038AB4u)
#define OS_SRC_GTM_PSM0_6_ADDR                      (0xF0038AB8u)
#define OS_SRC_GTM_PSM0_7_ADDR                      (0xF0038ABCu)
#define OS_SRC_GTM_DPLL0_ADDR                       (0xF0038B00u)
#define OS_SRC_GTM_DPLL1_ADDR                       (0xF0038B04u)
#define OS_SRC_GTM_DPLL2_ADDR                       (0xF0038B08u)
#define OS_SRC_GTM_DPLL3_ADDR                       (0xF0038B0Cu)
#define OS_SRC_GTM_DPLL4_ADDR                       (0xF0038B10u)
#define OS_SRC_GTM_DPLL5_ADDR                       (0xF0038B14u)
#define OS_SRC_GTM_DPLL6_ADDR                       (0xF0038B18u)
#define OS_SRC_GTM_DPLL7_ADDR                       (0xF0038B1Cu)
#define OS_SRC_GTM_DPLL8_ADDR                       (0xF0038B20u)
#define OS_SRC_GTM_DPLL9_ADDR                       (0xF0038B24u)
#define OS_SRC_GTM_DPLL10_ADDR                      (0xF0038B28u)
#define OS_SRC_GTM_DPLL11_ADDR                      (0xF0038B2Cu)
#define OS_SRC_GTM_DPLL12_ADDR                      (0xF0038B30u)
#define OS_SRC_GTM_DPLL13_ADDR                      (0xF0038B34u)
#define OS_SRC_GTM_DPLL14_ADDR                      (0xF0038B38u)
#define OS_SRC_GTM_DPLL15_ADDR                      (0xF0038B3Cu)
#define OS_SRC_GTM_DPLL16_ADDR                      (0xF0038B40u)
#define OS_SRC_GTM_DPLL17_ADDR                      (0xF0038B44u)
#define OS_SRC_GTM_DPLL18_ADDR                      (0xF0038B48u)
#define OS_SRC_GTM_DPLL19_ADDR                      (0xF0038B4Cu)
#define OS_SRC_GTM_DPLL20_ADDR                      (0xF0038B50u)
#define OS_SRC_GTM_DPLL21_ADDR                      (0xF0038B54u)
#define OS_SRC_GTM_DPLL22_ADDR                      (0xF0038B58u)
#define OS_SRC_GTM_DPLL23_ADDR                      (0xF0038B5Cu)
#define OS_SRC_GTM_DPLL24_ADDR                      (0xF0038B60u)
#define OS_SRC_GTM_DPLL25_ADDR                      (0xF0038B64u)
#define OS_SRC_GTM_DPLL26_ADDR                      (0xF0038B68u)
#define OS_SRC_GTM_ERR_ADDR 	                    (0xF0038B70u)
#define OS_SRC_GTM_TIM0_0_ADDR                      (0xF0038B90u)
#define OS_SRC_GTM_TIM0_1_ADDR                      (0xF0038B94u)
#define OS_SRC_GTM_TIM0_2_ADDR                      (0xF0038B98u)
#define OS_SRC_GTM_TIM0_3_ADDR                      (0xF0038B9Cu)
#define OS_SRC_GTM_TIM0_4_ADDR                      (0xF0038BA0u)
#define OS_SRC_GTM_TIM0_5_ADDR                      (0xF0038BA4u)
#define OS_SRC_GTM_TIM0_6_ADDR                      (0xF0038BA8u)
#define OS_SRC_GTM_TIM0_7_ADDR                      (0xF0038BACu)
#define OS_SRC_GTM_TIM1_0_ADDR                      (0xF0038BB0u)
#define OS_SRC_GTM_TIM1_1_ADDR                      (0xF0038BB4u)
#define OS_SRC_GTM_TIM1_2_ADDR                      (0xF0038BB8u)
#define OS_SRC_GTM_TIM1_3_ADDR                      (0xF0038BBCu)
#define OS_SRC_GTM_TIM1_4_ADDR                      (0xF0038BC0u)
#define OS_SRC_GTM_TIM1_5_ADDR                      (0xF0038BC4u)
#define OS_SRC_GTM_TIM1_6_ADDR                      (0xF0038BC8u)
#define OS_SRC_GTM_TIM1_7_ADDR                      (0xF0038BCCu)
#define OS_SRC_GTM_TIM2_0_ADDR                      (0xF0038BD0u)
#define OS_SRC_GTM_TIM2_1_ADDR                      (0xF0038BD4u)
#define OS_SRC_GTM_TIM2_2_ADDR                      (0xF0038BD8u)
#define OS_SRC_GTM_TIM2_3_ADDR                      (0xF0038BDCu)
#define OS_SRC_GTM_TIM2_4_ADDR                      (0xF0038BE0u)
#define OS_SRC_GTM_TIM2_5_ADDR                      (0xF0038BE4u)
#define OS_SRC_GTM_TIM2_6_ADDR                      (0xF0038BE8u)
#define OS_SRC_GTM_TIM2_7_ADDR                      (0xF0038BECu)
#define OS_SRC_GTM_TIM3_0_ADDR                      (0xF0038BF0u)
#define OS_SRC_GTM_TIM3_1_ADDR                      (0xF0038BF4u)
#define OS_SRC_GTM_TIM3_2_ADDR                      (0xF0038BF8u)
#define OS_SRC_GTM_TIM3_3_ADDR                      (0xF0038BFCu)
#define OS_SRC_GTM_TIM3_4_ADDR                      (0xF0038C00u)
#define OS_SRC_GTM_TIM3_5_ADDR                      (0xF0038C04u)
#define OS_SRC_GTM_TIM3_6_ADDR                      (0xF0038C08u)
#define OS_SRC_GTM_TIM3_7_ADDR                      (0xF0038C0Cu)
#define OS_SRC_GTM_TIM4_0_ADDR                      (0xF0038C10u)
#define OS_SRC_GTM_TIM4_1_ADDR                      (0xF0038C14u)
#define OS_SRC_GTM_TIM4_2_ADDR                      (0xF0038C18u)
#define OS_SRC_GTM_TIM4_3_ADDR                      (0xF0038C1Cu)
#define OS_SRC_GTM_TIM4_4_ADDR                      (0xF0038C20u)
#define OS_SRC_GTM_TIM4_5_ADDR                      (0xF0038C24u)
#define OS_SRC_GTM_TIM4_6_ADDR                      (0xF0038C28u)
#define OS_SRC_GTM_TIM4_7_ADDR                      (0xF0038C2Cu)
#define OS_SRC_GTM_TIM5_0_ADDR                      (0xF0038C30u)
#define OS_SRC_GTM_TIM5_1_ADDR                      (0xF0038C34u)
#define OS_SRC_GTM_TIM5_2_ADDR                      (0xF0038C38u)
#define OS_SRC_GTM_TIM5_3_ADDR                      (0xF0038C3Cu)
#define OS_SRC_GTM_TIM5_4_ADDR                      (0xF0038C40u)
#define OS_SRC_GTM_TIM5_5_ADDR                      (0xF0038C44u)
#define OS_SRC_GTM_TIM5_6_ADDR                      (0xF0038C48u)
#define OS_SRC_GTM_TIM5_7_ADDR                      (0xF0038C4Cu)
#define OS_SRC_GTM_MCS0_0_ADDR                      (0xF0038CB0u)
#define OS_SRC_GTM_MCS0_1_ADDR                      (0xF0038CB4u)
#define OS_SRC_GTM_MCS0_2_ADDR                      (0xF0038CB8u)
#define OS_SRC_GTM_MCS0_3_ADDR                      (0xF0038CBCu)
#define OS_SRC_GTM_MCS0_4_ADDR                      (0xF0038CC0u)
#define OS_SRC_GTM_MCS0_5_ADDR                      (0xF0038CC4u)
#define OS_SRC_GTM_MCS0_6_ADDR                      (0xF0038CC8u)
#define OS_SRC_GTM_MCS0_7_ADDR                      (0xF0038CCCu)
#define OS_SRC_GTM_MCS1_0_ADDR                      (0xF0038CD0u)
#define OS_SRC_GTM_MCS1_1_ADDR                      (0xF0038CD4u)
#define OS_SRC_GTM_MCS1_2_ADDR                      (0xF0038CD8u)
#define OS_SRC_GTM_MCS1_3_ADDR                      (0xF0038CDCu)
#define OS_SRC_GTM_MCS1_4_ADDR                      (0xF0038CE0u)
#define OS_SRC_GTM_MCS1_5_ADDR                      (0xF0038CE4u)
#define OS_SRC_GTM_MCS1_6_ADDR                      (0xF0038CE8u)
#define OS_SRC_GTM_MCS1_7_ADDR                      (0xF0038CECu)
#define OS_SRC_GTM_MCS2_0_ADDR                      (0xF0038CF0u)
#define OS_SRC_GTM_MCS2_1_ADDR                      (0xF0038CF4u)
#define OS_SRC_GTM_MCS2_2_ADDR                      (0xF0038CF8u)
#define OS_SRC_GTM_MCS2_3_ADDR                      (0xF0038CFCu)
#define OS_SRC_GTM_MCS2_4_ADDR                      (0xF0038D00u)
#define OS_SRC_GTM_MCS2_5_ADDR                      (0xF0038D04u)
#define OS_SRC_GTM_MCS2_6_ADDR                      (0xF0038D08u)
#define OS_SRC_GTM_MCS2_7_ADDR                      (0xF0038D0Cu)
#define OS_SRC_GTM_MCS3_0_ADDR                      (0xF0038D10u)
#define OS_SRC_GTM_MCS3_1_ADDR                      (0xF0038D14u)
#define OS_SRC_GTM_MCS3_2_ADDR                      (0xF0038D18u)
#define OS_SRC_GTM_MCS3_3_ADDR                      (0xF0038D1Cu)
#define OS_SRC_GTM_MCS3_4_ADDR                      (0xF0038D20u)
#define OS_SRC_GTM_MCS3_5_ADDR                      (0xF0038D24u)
#define OS_SRC_GTM_MCS3_6_ADDR                      (0xF0038D28u)
#define OS_SRC_GTM_MCS3_7_ADDR                      (0xF0038D2Cu)
#define OS_SRC_GTM_MCS4_0_ADDR                      (0xF0038D30u)
#define OS_SRC_GTM_MCS4_1_ADDR                      (0xF0038D34u)
#define OS_SRC_GTM_MCS4_2_ADDR                      (0xF0038D38u)
#define OS_SRC_GTM_MCS4_3_ADDR                      (0xF0038D3Cu)
#define OS_SRC_GTM_MCS4_4_ADDR                      (0xF0038D40u)
#define OS_SRC_GTM_MCS4_5_ADDR                      (0xF0038D44u)
#define OS_SRC_GTM_MCS4_6_ADDR                      (0xF0038D48u)
#define OS_SRC_GTM_MCS4_7_ADDR                      (0xF0038D4Cu)
#define OS_SRC_GTM_TOM0_0_ADDR                      (0xF0038E10u)
#define OS_SRC_GTM_TOM0_1_ADDR                      (0xF0038E14u)
#define OS_SRC_GTM_TOM0_2_ADDR                      (0xF0038E18u)
#define OS_SRC_GTM_TOM0_3_ADDR                      (0xF0038E1Cu)
#define OS_SRC_GTM_TOM0_4_ADDR                      (0xF0038E20u)
#define OS_SRC_GTM_TOM0_5_ADDR                      (0xF0038E24u)
#define OS_SRC_GTM_TOM0_6_ADDR                      (0xF0038E28u)
#define OS_SRC_GTM_TOM0_7_ADDR                      (0xF0038E2Cu)
#define OS_SRC_GTM_TOM1_0_ADDR                      (0xF0038E30u)
#define OS_SRC_GTM_TOM1_1_ADDR                      (0xF0038E34u)
#define OS_SRC_GTM_TOM1_2_ADDR                      (0xF0038E38u)
#define OS_SRC_GTM_TOM1_3_ADDR                      (0xF0038E3Cu)
#define OS_SRC_GTM_TOM1_4_ADDR                      (0xF0038E40u)
#define OS_SRC_GTM_TOM1_5_ADDR                      (0xF0038E44u)
#define OS_SRC_GTM_TOM1_6_ADDR                      (0xF0038E48u)
#define OS_SRC_GTM_TOM1_7_ADDR                      (0xF0038E4Cu)
#define OS_SRC_GTM_TOM2_0_ADDR                      (0xF0038E50u)
#define OS_SRC_GTM_TOM2_1_ADDR                      (0xF0038E54u)
#define OS_SRC_GTM_TOM2_2_ADDR                      (0xF0038E58u)
#define OS_SRC_GTM_TOM2_3_ADDR                      (0xF0038E5Cu)
#define OS_SRC_GTM_TOM2_4_ADDR                      (0xF0038E60u)
#define OS_SRC_GTM_TOM2_5_ADDR                      (0xF0038E64u)
#define OS_SRC_GTM_TOM2_6_ADDR                      (0xF0038E68u)
#define OS_SRC_GTM_TOM2_7_ADDR                      (0xF0038E6Cu)
#define OS_SRC_GTM_ATOM0_0_ADDR                     (0xF0038EF0u)
#define OS_SRC_GTM_ATOM0_1_ADDR                     (0xF0038EF4u)
#define OS_SRC_GTM_ATOM0_2_ADDR                     (0xF0038EF8u)
#define OS_SRC_GTM_ATOM0_3_ADDR                     (0xF0038EFCu)
#define OS_SRC_GTM_ATOM1_0_ADDR                     (0xF0038F00u)
#define OS_SRC_GTM_ATOM1_1_ADDR                     (0xF0038F04u)
#define OS_SRC_GTM_ATOM1_2_ADDR                     (0xF0038F08u)
#define OS_SRC_GTM_ATOM1_3_ADDR                     (0xF0038F0Cu)
#define OS_SRC_GTM_ATOM2_0_ADDR                     (0xF0038F10u)
#define OS_SRC_GTM_ATOM2_1_ADDR                     (0xF0038F14u)
#define OS_SRC_GTM_ATOM2_2_ADDR                     (0xF0038F18u)
#define OS_SRC_GTM_ATOM2_3_ADDR                     (0xF0038F1Cu)
#define OS_SRC_GTM_ATOM3_0_ADDR                     (0xF0038F20u)
#define OS_SRC_GTM_ATOM3_1_ADDR                     (0xF0038F24u)
#define OS_SRC_GTM_ATOM3_2_ADDR                     (0xF0038F28u)
#define OS_SRC_GTM_ATOM3_3_ADDR                     (0xF0038F2Cu)
#define OS_SRC_GTM_ATOM4_0_ADDR                     (0xF0038F30u)
#define OS_SRC_GTM_ATOM4_1_ADDR                     (0xF0038F34u)
#define OS_SRC_GTM_ATOM4_2_ADDR                     (0xF0038F38u)
#define OS_SRC_GTM_ATOM4_3_ADDR                     (0xF0038F3Cu)
#define OS_SRC_GTM_ATOM5_0_ADDR                     (0xF0038F40u)
#define OS_SRC_GTM_ATOM5_1_ADDR                     (0xF0038F44u)
#define OS_SRC_GTM_ATOM5_2_ADDR                     (0xF0038F48u)
#define OS_SRC_GTM_ATOM5_3_ADDR                     (0xF0038F4Cu)
#define OS_SRC_GTM_MCSW0_ADDR                       (0xF0038FD0u)
#define OS_SRC_GTM_MCSW1_ADDR                       (0xF0038FD4u)
#define OS_SRC_GTM_MCSW2_ADDR                       (0xF0038FD8u)
#define OS_SRC_GTM_MCSW3_ADDR                       (0xF0038FDCu)
#define OS_SRC_GTM_MCSW4_ADDR                       (0xF0038FE0u)
#define OS_SRC_GTM_MCSW5_ADDR                       (0xF0038FE4u)
#define OS_SRC_GTM_MCSW6_ADDR                       (0xF0038FE8u)
#define OS_SRC_GTM_MCSW7_ADDR                       (0xF0038FECu)
#define OS_SRC_GTM_MCSW8_ADDR                       (0xF0038FF0u)
#define OS_SRC_GTM_MCSW9_ADDR                       (0xF0038FF4u)



/* Memory protection register. CPU Data Protection Range */
#define       OS_DPR_0L                            (0xC000U)
#define       OS_DPR_0U                            (0xC004U)
#define       OS_DPR_1L                            (0xC008U)
#define       OS_DPR_1U                            (0xC00CU)
#define       OS_DPR_2L                            (0xC010U)
#define       OS_DPR_2U                            (0xC014U)
#define       OS_DPR_3L                            (0xC018U)
#define       OS_DPR_3U                            (0xC01CU)
#define       OS_DPR_4L                            (0xC020U)
#define       OS_DPR_4U                            (0xC024U)
#define       OS_DPR_5L                            (0xC028U)
#define       OS_DPR_5U                            (0xC02CU)
#define       OS_DPR_6L                            (0xC030U)
#define       OS_DPR_6U                            (0xC034U)
#define       OS_DPR_7L                            (0xC038U)
#define       OS_DPR_7U                            (0xC03CU)
#define       OS_DPR_8L                            (0xC040U)
#define       OS_DPR_8U                            (0xC044U)
#define       OS_DPR_9L                            (0xC048U)
#define       OS_DPR_9U                            (0xC04CU)
#define       OS_DPR_10L                           (0xC050U)
#define       OS_DPR_10U                           (0xC054U)
#define       OS_DPR_11L                           (0xC058U)
#define       OS_DPR_11U                           (0xC05CU)
#define       OS_DPR_12L                           (0xC060U)
#define       OS_DPR_12U                           (0xC064U)
#define       OS_DPR_13L                           (0xC068U)
#define       OS_DPR_13U                           (0xC06CU)
#define       OS_DPR_14L                           (0xC070U)
#define       OS_DPR_14U                           (0xC074U)
#define       OS_DPR_15L                           (0xC078U)
#define       OS_DPR_15U                           (0xC07CU)
#define       OS_DPR_16L                           (0xC080U)
#define       OS_DPR_16U                           (0xC084U)
#define       OS_DPR_17L                           (0xC088U)
#define       OS_DPR_17U                           (0xC08CU)

/*CPU Data Protection Read Enable*/
#define       OS_DPRE0                             (0xE010u)
#define       OS_DPRE1                             (0xE014u)
#define       OS_DPRE2                             (0xE018u)
#define       OS_DPRE3                             (0xE01Cu)
#define       OS_DPRE4                             (0xE050u)
#define       OS_DPRE5                             (0xE054u)


/*CPU Data Protection Write Enable*/
#define       OS_DPWE0                             (0xE020u)
#define       OS_DPWE1                             (0xE024u)
#define       OS_DPWE2                             (0xE028u)
#define       OS_DPWE3                             (0xE02Cu)
#define       OS_DPWE4                             (0xE060u)
#define       OS_DPWE5                             (0xE064u)

/*CPU Code Protection Range */
#define       OS_CPR_0L                            (0xD000U)
#define       OS_CPR_0U                            (0xD004U)
#define       OS_CPR_1L                            (0xD008U)
#define       OS_CPR_1U                            (0xD00CU)
#define       OS_CPR_2L                            (0xD010U)
#define       OS_CPR_2U                            (0xD014U)
#define       OS_CPR_3L                            (0xD018U)
#define       OS_CPR_3U                            (0xD01CU)
#define       OS_CPR_4L                            (0xD020U)
#define       OS_CPR_4U                            (0xD024U)
#define       OS_CPR_5L                            (0xD028U)
#define       OS_CPR_5U                            (0xD02CU)
#define       OS_CPR_6L                            (0xD030U)
#define       OS_CPR_6U                            (0xD034U)
#define       OS_CPR_7L                            (0xD038U)
#define       OS_CPR_7U                            (0xD03CU)
#define       OS_CPR_8L                            (0xD040U)
#define       OS_CPR_8U                            (0xD044U)
#define       OS_CPR_9L                            (0xD048U)
#define       OS_CPR_9U                            (0xD04CU)

/*CPU Code Protection Execute Enable*/
#define       OS_CPXE0                             (0xE000u)
#define       OS_CPXE1                             (0xE004u)
#define       OS_CPXE2                             (0xE008u)
#define       OS_CPXE3                             (0xE00Cu)
#define       OS_CPXE4                             (0xE040u)
#define       OS_CPXE5                             (0xE044u)
/*-----------------------------end of register address---------------------------*/

/*=======[Porting Macro]======================================================*/
#ifndef MAX_INTRS
  #define MAX_INTRS            256u /* DD_1_0171, Maximum number of interrupt requests. */
#endif /* No Define MAX_INTRS */

#ifndef MAX_TRAPS
  #define MAX_TRAPS            8u /* DD_1_0172, The maximum number of trap requests. */
#endif /* No Define MAX_TRAPS */

#define CHECK_STACK_USAGE             1u
#define OS_ARCH_INT_ENABLE_BIT        0x00000100u           /* DD_1_0173,  */
#define OS_ARCH_STACK_ALIGN(addr)    ((addr) & 0xFFFFFFFCU) /* DD_1_0327, Align stack space to 4 bytes. */
/* All preceding instructions are executed by the CPU. Then the pipeline is flushed 
before the next instruction is executed */
/* DD_1_0329 */
#define OS_ARCH_ISYNC()              ASM("isync")
#define OS_ARCH_DSYNC()              ASM("dsync")  /* DD_1_0330, All data access is served before the next data access. */
#define OS_ARCH_MFCR(addr)           (Os_ArchMsrType)__mfcr((addr)) /* DD_1_0331, Move from core register. Move the contents of the core SFR register to adata register. */
/* Move to core register. Move the value from a data register to the coreSFR */
/* DD_1_0332 */
#define OS_ARCH_MTCR(addr, reg)     \
{                                   \
    __mtcr((addr), (reg));    		\
    OS_ARCH_ISYNC();                \
}

/* Save the context. */
/* DD_1_0333 */
#define OS_ARCH_SAVE_CONTEXT()      \
{                                   \
    Os_TaskCBExt[Os_SCB.sysRunningTaskID].pcx = OS_ARCH_MFCR(OS_REG_PCX);    \
}

#if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))
#define OS_ARCH_RESUME_CONTEXT()                                         \
    OS_ARCH_MTCR(OS_REG_PCX, Os_TaskCBExt[Os_SCB.sysRunningTaskID].pcx); \
    OS_ARCH_DSYNC();                                                     \
    ASM("rslcx");                                                        \
    ASM("nop");                                                          \
    ASM("rfe")
#else /* #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */
/* Resume the context. */
/* DD_1_0334 */
#define OS_ARCH_RESUME_CONTEXT()                 \
    uint32 startpcx = 0u;                        \
    startpcx = OS_ARCH_MFCR(OS_REG_PCX);         \
    if(0U != startpcx)                           \
    {                                            \
        uint32 endpcx = 0u;                      \
        endpcx = startpcx;                       \
        while(0U != (endpcx & 0x00100000u))      \
        {                                        \
            endpcx = PCX_TO_PCXI(endpcx);        \
        }                                        \
        Os_ArchReclaimIsrCsas(startpcx, endpcx); \
    }                                            \
    OS_ARCH_MTCR(OS_REG_PCX, Os_TaskCBExt[Os_SCB.sysRunningTaskID].pcx);\
    OS_ARCH_DSYNC();                             \
    ASM("rslcx");                                \
    ASM("nop");                                  \
    ASM("rfe")
#endif /* (OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC) */


#define Os_ArchDisableInt()          (void)__disable()        /* DD_1_0335, Disables global interrupt. */
#define Os_ArchEnableInt()           (void)__enable()         /* DD_1_0336, Enables global interrupt. */
#define Os_ArchDispatch()            (void)__syscall(0u)       /* DD_1_0337, Generates a system call, this means generating a system trap */
#define OS_ARCH_DECLEAR_CRITICAL()   Os_ArchMsrType msr      /* DD_1_0338, Declares the variables that hold the interrupt control register. */
#define OS_ARCH_ENTRY_CRITICAL()     Os_ArchSuspendInt(&msr) /* DD_1_0339, Save the variables that hold the interrupt control register. */
#define OS_ARCH_EXIT_CRITICAL()      Os_ArchRestoreInt(msr)  /* DD_1_0340, Resume the variables that hold the interrupt control register. */

#if ((TRUE == CFG_SYSTEM_TIMER_ENABLE) || (TRUE == CFG_TIMING_PROTECTION_ENABLE))

/* DD_1_0341, Lock the safety watchdog. */
#define Os_ArchSetSafetyENDINIT()    	\
	Ifx_Ssw_setSafetyEndinit(Ifx_Ssw_getSafetyWatchdogPassword())

/* DD_1_0342, Unlock the safety watchdog. */
#define Os_ArchResetSafetyENDINIT()    	\
		Ifx_Ssw_clearSafetyEndinit(Ifx_Ssw_getSafetyWatchdogPassword())

#define Os_ArchSetENDINIT(core_id)    	\
		Ifx_Ssw_setCpuEndinit(&(MODULE_SCU.WDTCPU[core_id]), Ifx_Ssw_getCpuWatchdogPassword(&(MODULE_SCU.WDTCPU[core_id])))

#define Os_ArchResetENDINIT(core_id)           \
	Ifx_Ssw_clearCpuEndinit(&(MODULE_SCU.WDTCPU[core_id]), Ifx_Ssw_getCpuWatchdogPassword(&(MODULE_SCU.WDTCPU[core_id])))

#endif /* (TRUE == CFG_SYSTEM_TIMER_ENABLE) || (TRUE == CFG_TIMING_PROTECTION_ENABLE) */

/**
 * control the specific interrupt source, based on the service request control register
 */
/* Install interrupt on tc275. If set prio to 0, this interrupt is disabled. */

#define OS_INTERRUPT_INSTALL(src, prio, srcType)    (*(uint32 volatile *)src)\
    = (((*(uint32 volatile *)src) & 0xFFFFFF00u) | 0x00000400u | srcType) + (prio)

/* Clear the bit10 SRE(source request enable) */
/* DD_1_0344 */
#define OS_INTERRUPT_DISABLEREQ(src)    (*(uint32 volatile *)src) = \
                                        ((*(uint32 volatile *)src) & 0xFFFFFBFFu)

/* Write 1 to the bit25 CLRR(clear request) */
/* DD_1_0345 */
#define OS_INTERRUPT_CLEARREQ(src)      (*(uint32 volatile *)src) = \
                                        ((*(uint32 volatile *)src) | 0x02000000u)

/* Check the bit24 SRR(service request flag) */

#define OS_INTERRUPT_CHKREQ(src)           (((*(uint32 volatile *)src) >> 24u) & 0x01u)

/* Set SRPN to 0 in src */
/* DD_1_0347 */
#define OS_INTERRUPT_SET_SRPN_ZERO(src)    (*(uint32 volatile *)src) = \
                                           ((*(uint32 volatile *)src) & 0xFFFFFF00u)

#if (TRUE == CFG_SRV_SHELLOS)
/* Macro definition of CPU mode set,*/
/* Choose user mode for the Tricore platform, User0/1*/
/* Indicates which user mode the CPU uses. */
/* DD_1_0174 */
#define    OS_CPUMODE_USER        OS_CPUMODE_USER1
/*to change to the user or supervisor mode*/
/* DD_1_0348 */
#define OS_SAVE_CPUMODE()
#define OS_RESTORE_CPUMODE()

#define OS_CHANGCPUMODE(mode)                                                                  \
{                                                                                              \
    if((uint32)OS_CPUMODE_SUPERVISOR == ((OS_ARCH_MFCR(OS_REG_PSW) & 0x00000c00u) >> 10u))     \
    {                                                                                          \
        if(OS_CPUMODE_USER == mode)                                                            \
        {                                                                                      \
            ASM("isync");                                                                      \
            OS_ARCH_MTCR(OS_REG_PSW, ((OS_ARCH_MFCR(OS_REG_PSW) & 0xfffff3ffu) | 0x00000400u));\
        }                                                                                      \
        else                                                                                   \
        {                                                                                      \
            ASM("isync");                                                                      \
            OS_ARCH_MTCR(OS_REG_PSW, (OS_ARCH_MFCR(OS_REG_PSW) & 0xffffcfffu));                \
        }                                                                                      \
    }                                                                                          \
    else                                                                                       \
    {                                                                                          \
        if(OS_CPUMODE_SUPERVISOR == mode)                                                      \
        {                                                                                      \
            (void)__syscall(1u);                                                                \
        }                                                                                      \
    }                                                                                          \
}

/* Change to the user or supervisor mode */

#define OS_GETCPUMODE() \
       ((OS_CPUMODE_SUPERVISOR == ((OS_ARCH_MFCR(OS_REG_PSW) & 0x00000c00u) >> 10u))\
               ? OS_CPUMODE_SUPERVISOR:OS_CPUMODE_USER)
#endif /* TRUE == CFG_SRV_SHELLOS */

/**
 * trigger the specific interrupt source by setting the request bit, just for debug.
 * write 1 to the bit26 SETR(set request)
 */

#if (TRUE == CFG_SRV_SHELLOS)
#define OS_INTERRUPT_SETREQ(src)                                                 \
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);                                      \
    (*(uint32 volatile *)src) = ((*(uint32 volatile *)src) | 0x04000000u);       \
    OS_CHANGCPUMODE(OS_CPUMODE_USER)
#else /* #if (FALSE == CFG_SRV_SHELLOS) */
#define OS_INTERRUPT_SETREQ(src)  (*(uint32 volatile *)src) \
    = ((*(uint32 volatile *)src) | 0x04000000u)
#endif /* TRUE == CFG_SRV_SHELLOS */

/* Get the value of the ISRid's status register */

#define OS_GETISRSTR(isrId)    OS_INTERRUPT_CHKREQ(Os_IsrCfg[isrId].OsIsrSrc)

/* Clear the status register of the ISR id */

#define OS_CLRISRSTR(isrId)    OS_INTERRUPT_CLEARREQ(Os_IsrCfg[isrId].OsIsrSrc)

/* cpu0 = bit0 set to 1, ..., DMA = bit3 set to 1 */
/* Request an interrupt service to the specified core. */
/* DD_1_0353 */
#define OS_INTERRUPT_SRB_SETREQ(core) OS_INT_SRB0 = ((uint32)1u << (uint32)(core))

/* Request an interrupt service to the specified core. */
/* DD_1_0354 */
#define Os_ArchRemoteCall(coreId)                \
{                                                \
	Os_InterCore[Os_SCB.sysCore].callCoreRequest[coreId] = TRUE;			\
    OS_INTERRUPT_SRB_SETREQ(coreId);             \
}

/* Pre-switch to system stack. */
/* DD_1_0357 */
#define Os_ArchPreSwitch2System()                                                \
{                                                                                \
    Os_ArchInitCsas();                                                           \
    OS_ARCH_MTCR(OS_REG_LCX, OS_EA_TO_PCX((uint32)&Os_Csas[1]));                 \
    OS_ARCH_MTCR(OS_REG_FCX, OS_EA_TO_PCX((uint32)&Os_Csas[Os_CfgCsaMax-1u]));   \
    OS_ARCH_MTCR(OS_REG_PCX, (uint32)0u);                                        \
}

/* Switch to system stack */
/* DD_1_0358 */
#define Os_ArchSwitch2System()                                              \
{                                                                           \
    Os_ArchSp = OS_ARCH_STACK_ALIGN((uint32)Os_SystemStack->stackTop);      \
    ASM("movh.a a10, #@HIS(Os_ArchSp)");                                    \
    ASM("ld.a a10, [a10]@LOS(Os_ArchSp)");                                  \
}

/* Switch to ISR2 stack */
/* DD_1_0359 */
#if (CFG_ISR2_MAX > 0U)
#define Os_ArchSwitch2ISR2Stk(isrId)                                       \
{                                                                          \
    Os_ArchSp = OS_ARCH_STACK_ALIGN((uint32)Os_ISR2Stack[isrId].stackTop); \
    ASM("movh.a a10, #@HIS(Os_ArchSp)");                                      \
    ASM("ld.a a10, [a10]@LOS(Os_ArchSp)");                                  \
}
#else /* #if (CFG_ISR2_MAX == 0U) */
#define Os_ArchSwitch2ISR2Stk(isrId) 
#endif /* CFG_ISR2_MAX > 0U */


/* get effective address from register of PCX  */
#define  OS_PCX_PCXUL(pcx)           __extru((pcx), 22u, 1u)

/* Get effective address from register of PCX */
/* DD_1_0361 */
#define  OS_PCX_TO_EA(pcx)           ((Os_ArchCsaType *)\
                                     ((__extru((pcx),16u,4u)<<28u)  | (__extru((pcx),0u,16u)<<6u)))

/* Get register of PCX from effective address */
/* DD_1_0362 */
#define  OS_EA_TO_PCX(addr)          ((__extru((uint32)(addr),28u,4u)<<16u) \
                                         | (__extru((uint32)(addr),6u,16u)))

/* Get register of PCXI from PCX */
/* DD_1_0363 */
#define  PCX_TO_PCXI(pcx)             (*((volatile uint32 *)OS_PCX_TO_EA((pcx))))

/* Point to the CSA precursor. */
/* DD_1_0364 */
#define  OS_CSA_PREV(csa)            (Os_ArchCsaType *)OS_PCX_TO_EA(csa->reg[0])

/* Point to the PCX precursor. */

#define  OS_PCX_PREV(pcx)            (((Os_ArchCsaType *)OS_PCX_TO_EA(pcx))->reg[0]&0x000FFFFFU)

/* Get the PCXprecursor. */
/* DD_1_0366 */
#define  GET_PREV_PCX(nextPcx, pcx)               \
{                                                 \
    OS_ARCH_DSYNC();                              \
    (nextPcx) = PCX_TO_PCXI(pcx) & 0x000FFFFFU;   \
}

/* Set the PCX precursor. */
/* DD_1_0367 */
#define  SET_PREV_PCX(pcx, nextPcx)   PCX_TO_PCXI((pcx)) = (nextPcx)

/* Recycle the task's CSA. */
/* DD_1_0368 */
#define Os_ArchReclaimCsas(taskId)                                                          \
{                                                                                           \
    OS_PCX_TO_EA(Os_TaskCBExt[taskId].pcxLast)->reg[0] = (uint32)OS_ARCH_MFCR(OS_REG_FCX);  \
    OS_ARCH_MTCR(OS_REG_FCX, Os_TaskCBExt[taskId].pcx);                                     \
}

/* Isr reclaim csa list */
/* DD_1_0369 */
#define Os_ArchReclaimIsrCsas(pcx, endPcx)                              \
{                                                                       \
        Os_TempPcx = (uint32)(pcx);                                     \
        if((0U != Os_TempPcx) && ((pcx) != (endPcx)))                   \
        {                                                               \
            Os_LoopPcx = Os_TempPcx;                                    \
            GET_PREV_PCX(Os_NextPcx, Os_LoopPcx);                       \
            while ((((endPcx)&0x000FFFFFu) != Os_NextPcx) && (0U != Os_NextPcx)) \
            {                                                           \
                Os_LoopPcx = Os_NextPcx;                                \
                GET_PREV_PCX(Os_NextPcx, Os_LoopPcx);                   \
            }                                                           \
            SET_PREV_PCX(Os_LoopPcx, (uint32)OS_ARCH_MFCR(OS_REG_FCX)); \
            OS_ARCH_MTCR(OS_REG_FCX, Os_TempPcx);                       \
        }                                                               \
}   

/* Reclaim isr_csa in TerminateApplication. */
/* DD_1_0370 */
#define Os_ArchReclaimIsrCsasTermApp(pcx, endPcx)                    \
{                                                                    \
    Os_TempPcxTermApp = (uint32)OS_ARCH_MFCR(OS_REG_PCX);            \
    if (0U != Os_TempPcxTermApp)                                     \
    {                                                                \
        Os_LoopPcxTermApp = Os_TempPcxTermApp;                       \
        GET_PREV_PCX(Os_NextPcxTermApp, Os_LoopPcxTermApp);          \
        while (((endPcx) & 0x000FFFFFu) != Os_NextPcxTermApp)         \
        {                                                            \
            Os_LoopPcxTermApp = Os_NextPcxTermApp;                   \
            GET_PREV_PCX(Os_NextPcxTermApp, Os_LoopPcxTermApp);      \
            if (((pcx) & 0x000FFFFFu) == Os_NextPcxTermApp)           \
            {                                                        \
                Os_BeginPcxTermApp = Os_LoopPcxTermApp;              \
            }                                                        \
        }                                                            \
        Os_TempPcxTermApp = (uint32)(pcx);                             \
        SET_PREV_PCX(Os_LoopPcxTermApp, (uint32)OS_ARCH_MFCR(OS_REG_FCX));  \
        OS_ARCH_MTCR(OS_REG_FCX, Os_TempPcxTermApp);                 \
        SET_PREV_PCX(Os_BeginPcxTermApp, Os_NextPcxTermApp);         \
    }                                                                \
}

#if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))
/* Some operations that need to be performed when exiting the ISR. */
/* DD_1_0371 */
#define OS_ARCH_ISR2_EPILOGUE()               OS_ARCH_ISR2_EPILOGUE_1()

/* Clear Call Depth Count Enable bit. */
/* DD_1_0372 */
#define Os_CLEAR_CDC_ISR2_EPILOGUE()

/* Update PSW for memory protection and user mode 1 */

#define Os_ISR_UPDATE_PSW()
#else /* #if ((OS_SC4 == CFG_SC) || (OS_SC3 == CFG_SC)) */
/* Clear Call Depth Count Enable bit. */
/* DD_1_0372 */
#define Os_CLEAR_CDC_ISR2_EPILOGUE()     \
{                                       \
    uint32 temp = 0u;                    \
    temp = OS_ARCH_MFCR(OS_REG_PSW);    \
    temp &= 0XFFFFFF80u;                    \
    OS_ARCH_MTCR(OS_REG_PSW, temp);        \
}

#if (TRUE == CFG_SRV_SHELLOS)
/* Some operations that need to be performed when exiting the ISR. */
/* DD_1_0371 */
#define OS_ARCH_ISR2_EPILOGUE()        \
{                                      \
    (void)__syscall(2u);                \
    OS_ARCH_ISR2_EPILOGUE_1();         \
}
#else /* #if (FALSE == CFG_SRV_SHELLOS) */
/* Some operations that need to be performed when exiting the ISR. */
/* DD_1_0371 */
#define OS_ARCH_ISR2_EPILOGUE()        \
{                                      \
    OS_ARCH_ISR2_EPILOGUE_1();         \
}
#endif /* TRUE == CFG_SRV_SHELLOS */
/*update PSW for memory protection and user mode 1*/
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
#define Os_ISR_UPDATE_PSW()                                        \
{                                                                  \
    uint32 temp = 0u;                                             \
    temp = OS_ARCH_MFCR(OS_REG_PSW);                               \
    temp &= 0xFFFFCFFFu;                                           \
    temp |= Os_PSW_PRS;                                          \
    if(TRUE != Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted)     \
    {                                                            \
        temp = temp & 0xfffff7ffu;                                \
        temp = temp | 0x00000400u;                                \
    }                                                            \
    OS_ARCH_MTCR(OS_REG_PSW, temp);                                \
}
#else /* #if (FALSE == CFG_MEMORY_PROTECTION_ENABLE) */
#define Os_ISR_UPDATE_PSW()                                        \
{                                                                \
    if(TRUE != Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted)       \
    {                                                            \
        uint32 temp = 0u;                                        \
        temp = OS_ARCH_MFCR(OS_REG_PSW);                        \
        temp = temp & 0xfffff7ffu;                                \
        temp = temp | 0x00000400u;                                \
        OS_ARCH_MTCR(OS_REG_PSW, temp);                            \
    }                                                            \
}
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
#endif /* (OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC) */



/*=======[I N T E R N A L   M A C R O]========================================*/
#if (TRUE == CFG_INT_NEST_ENABLE)
/* Some operations to be performed when ISR1 enters an interrupt. */
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
#define OS_ARCH_ISR1_PROLOGUE(isrId)                        \
{                                                           \
    Os_ArchSetMemProtSet(0x00UL);                           \
    Os_IntCfgIsrId = isrId;                                 \
    if (0U == Os_IntNestISR1)                               \
    {                                                       \
    	Os_Switch2System();                                 \
        Os_SaveLevelISR1 = Os_SCB.sysOsLevel;               \
        Os_SCB.sysOsLevel = OS_LEVEL_ISR1;                  \
    }                                                       \
    Os_EnterISR1();                                         \
    Os_IntNestISR1++;                                       \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)   \
    {                                                       \
        Os_ArchEnableInt();                                 \
    }                                                       \
    Os_ISR_UPDATE_PSW();									\
}

#else
#define OS_ARCH_ISR1_PROLOGUE(isrId)                        \
{                                                           \
    Os_IntCfgIsrId = isrId;                                 \
    if (0U == Os_IntNestISR1)                               \
    {                                                       \
    	Os_Switch2System();                                	\
        Os_SaveLevelISR1 = Os_SCB.sysOsLevel;               \
        Os_SCB.sysOsLevel = OS_LEVEL_ISR1;                  \
    }                                                       \
    Os_EnterISR1();                                         \
    Os_IntNestISR1++;                                       \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)   \
    {                                                       \
        Os_ArchEnableInt();                                 \
    }                                                       \
}
#endif
/* Some operations to be performed when ISR1 exits an interrupt. */

#define OS_ARCH_ISR1_EPILOGUE()                             \
{                                                           \
    Os_ArchDisableInt();                                    \
    Os_ExitISR1();                                          \
    Os_IntNestISR1--;                                      \
    if(0U == Os_IntNestISR1)                                \
    {                                                       \
        Os_SCB.sysOsLevel = Os_SaveLevelISR1;               \
    }                                                       \
    OS_ARCH_DSYNC();                                        \
    ASM("rslcx");                                           \
    ASM("nop");                                             \
    ASM("rfe");                                             \
}

#else /* #if (FALSE == CFG_INT_NEST_ENABLE) */
/* Some operations to be performed when ISR1 enters an interrupt. */
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
#define OS_ARCH_ISR1_PROLOGUE(isrId)                        \
{                                                           \
    Os_ArchSetMemProtSet(0x00UL);                           \
    Os_Switch2System();                                     \
    Os_IntCfgIsrId = isrId;                                 \
    Os_SaveLevelISR1 = Os_SCB.sysOsLevel;                   \
    Os_SCB.sysOsLevel = OS_LEVEL_ISR1;                      \
    Os_EnterISR1();                                         \
    Os_ISR_UPDATE_PSW();                                    \
}
#else
#define OS_ARCH_ISR1_PROLOGUE(isrId)                        \
{                                                           \
    Os_Switch2System();                                     \
    Os_IntCfgIsrId = isrId;                                 \
    Os_SaveLevelISR1 = Os_SCB.sysOsLevel;                   \
    Os_SCB.sysOsLevel = OS_LEVEL_ISR1;                      \
    Os_EnterISR1();                                         \
}
#endif
/* Some operations to be performed when ISR1 exits an interrupt. */

#define OS_ARCH_ISR1_EPILOGUE()                             \
{                                                           \
    Os_SCB.sysOsLevel = Os_SaveLevelISR1;                   \
    Os_ExitISR1();                                          \
    OS_ARCH_DSYNC();                                        \
    ASM("rslcx");                                           \
    ASM("nop");                                             \
    ASM("rfe");                                             \
}
#endif /* #if (TRUE == CFG_INT_NEST_ENABLE) */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
/* Some operations to be performed when ISR2 enters an interrupt. */
/* DD_1_0376 */
#if (OS_SC4 == CFG_SC)
#define OS_ARCH_ISR2_PROLOGUE(isrId)                          \
{                                                             \
    Os_IsrNestPcxStack[Os_IntNestISR2] = OS_ARCH_MFCR(OS_REG_PCX);\
    Os_IntCfgIsrId = isrId;                                   \
    if (0U == Os_IntNestISR2)                                 \
    {                                                         \
        OS_ARCH_SAVE_CONTEXT();                               \
    }                                                         \
    Os_ArchSwitch2ISR2Stk(isrId)                              \
    Os_EnterISR2();                                           \
    if (E_OK != Os_TmProtIsrFrameChk(Os_IntCfgIsrId))         \
    {                                                         \
        Os_ExitISR2();                                        \
        OS_ARCH_DSYNC();                                      \
        ASM("rslcx");                                         \
        ASM("nop");                                           \
        ASM("rfe");                                           \
    }                                                         \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)     \
    {                                                         \
        Os_ArchEnableInt();                                   \
    }                                                         \
	Os_ISR_UPDATE_PSW();									  \
}
#else /* #if (OS_SC4 != CFG_SC) */
#define OS_ARCH_ISR2_PROLOGUE(isrId)                          \
{                                                             \
    Os_IsrNestPcxStack[Os_IntNestISR2] = OS_ARCH_MFCR(OS_REG_PCX);\
    Os_IntCfgIsrId = isrId;                                   \
    if (0U == Os_IntNestISR2)                                 \
    {                                                         \
        OS_ARCH_SAVE_CONTEXT();                               \
    }                                                         \
    Os_ArchSwitch2ISR2Stk(isrId)                              \
    Os_EnterISR2();                                           \
    if (E_OK != Os_TmProtIsrFrameChk(Os_IntCfgIsrId))         \
    {                                                         \
        Os_ExitISR2();                                        \
        OS_ARCH_DSYNC();                                      \
        ASM("rslcx");                                         \
        ASM("nop");                                           \
        ASM("rfe");                                           \
    }                                                         \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)     \
    {                                                         \
        Os_ArchEnableInt();                                   \
    }                                                         \
}
#endif /* #if (OS_SC4 == CFG_SC) */
/* Some operations to be performed when ISR2 exits an interrupt. */
/* DD_1_0377 */
#define OS_ARCH_ISR2_EPILOGUE_1()                           \
{                                                           \
    OS_ISR2OCCUPYINTRES();                                  \
    Os_ArchDisableInt();                                    \
    if (TASK_STATE_SUSPENDED == Os_SCB.sysRunningTCB->taskState) \
    {                                                       \
        Os_ArchReclaimCsas(Os_SCB.sysRunningTaskID);        \
    }                                                       \
    Os_ArchMemProtSwithToSystem();                          \
    Os_ExitISR2();                                          \
    if (0U == Os_IntNestISR2)                               \
    {                                                       \
        Os_TprotTerminateIsr = FALSE;                       \
        Os_CLEAR_CDC_ISR2_EPILOGUE();                       \
        OS_ARCH_RESUME_CONTEXT();                           \
    }                                                       \
    else                                                    \
    {                                                       \
        if (TRUE == Os_TprotTerminateIsr)                   \
        {                                                   \
            Os_IntNestISR2--;                               \
            Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker -1u;     \
            Os_TprotTerminateIsr = FALSE;                   \
            if (0U == Os_IntNestISR2)                        \
            {                                               \
                Os_SCB.sysOsLevel=OS_LEVEL_TASK;            \
            }                                               \
            Os_ArchReclaimIsrCsas(Os_IsrNestPcxStack[Os_IntNestISR2 + 1u],\
                    Os_IsrNestPcxStack[Os_IntNestISR2]);    \
            OS_ARCH_MTCR(OS_REG_PCX, Os_IsrNestPcxStack[Os_IntNestISR2]);\
        }                                                   \
    }                                                       \
    OS_ARCH_DSYNC();                                        \
    ASM("rslcx");                                           \
    ASM("nop");                                             \
    ASM("rfe");                                             \
}

#elif (TRUE == CFG_INT_NEST_ENABLE)
/* Some operations to be performed when ISR2 enters an interrupt. */
/* DD_1_0376 */
#if ((OS_SC4 == CFG_SC) || (OS_SC3 == CFG_SC))
#define OS_ARCH_ISR2_PROLOGUE(isrId)                             \
{                                                                \
    Os_IsrNestPcxStack[Os_IntNestISR2] = OS_ARCH_MFCR(OS_REG_PCX);   \
    if (0U == Os_IntNestISR2)                                    \
    {                                                            \
        OS_ARCH_SAVE_CONTEXT();                                  \
    }                                                            \
    Os_ArchSwitch2ISR2Stk(isrId);                                \
    Os_IntCfgIsrId = isrId;                                      \
    Os_EnterISR2();                                              \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)        \
    {                                                            \
        Os_ArchEnableInt();                                      \
    }                                                            \
    Os_ISR_UPDATE_PSW();                                     	 \
}
#else /* #if ((OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC)) */
#define OS_ARCH_ISR2_PROLOGUE(isrId)                             \
{                                                                \
    Os_IsrNestPcxStack[Os_IntNestISR2] = OS_ARCH_MFCR(OS_REG_PCX);   \
    if (0U == Os_IntNestISR2)                                    \
    {                                                            \
        OS_ARCH_SAVE_CONTEXT();                                  \
    }                                                            \
    Os_ArchSwitch2ISR2Stk(isrId);                                \
    Os_IntCfgIsrId = isrId;                                      \
    Os_EnterISR2();                                              \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)        \
    {                                                            \
        Os_ArchEnableInt();                                      \
    }                                                            \
}
#endif /* #if ((OS_SC4 == CFG_SC) || (OS_SC3 == CFG_SC)) */
/* Some operations to be performed when ISR2 exits an interrupt. */
/* DD_1_0377 */
#define OS_ARCH_ISR2_EPILOGUE_1()                               \
{                                                               \
    OS_ISR2OCCUPYINTRES();                                      \
    Os_ArchDisableInt();                                        \
    Os_ArchMemProtSwithToSystem();                              \
    Os_ExitISR2();                                              \
    if (0U == Os_IntNestISR2)                                   \
    {                                                           \
        Os_CLEAR_CDC_ISR2_EPILOGUE();                           \
        OS_ARCH_RESUME_CONTEXT();                               \
    }                                                           \
    OS_ARCH_DSYNC();                                            \
    ASM("rslcx");                                               \
    ASM("nop");                                                 \
    ASM("rfe");                                                 \
}
/* FALSE == CFG_INT_NEST_ENABLE */
#else

/* Some operations to be performed when ISR2 enters an interrupt. */
/* DD_1_0376 */
#if ((OS_SC4 == CFG_SC) || (OS_SC3 == CFG_SC))
#define OS_ARCH_ISR2_PROLOGUE(isrId)                          \
{                                                             \
    OS_ARCH_SAVE_CONTEXT();                                   \
    Os_ArchSwitch2ISR2Stk(isrId);                             \
    Os_IntCfgIsrId = isrId;                                   \
    Os_EnterISR2();                                           \
    Os_ISR_UPDATE_PSW();                                      \
}
#else /* #if ((OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC)) */
#define OS_ARCH_ISR2_PROLOGUE(isrId)                          \
{                                                             \
    OS_ARCH_SAVE_CONTEXT();                                   \
    Os_ArchSwitch2ISR2Stk(isrId);                             \
    Os_IntCfgIsrId = isrId;                                   \
    Os_EnterISR2();                                           \
}
#endif /* #if ((OS_SC4 == CFG_SC) || (OS_SC3 == CFG_SC)) */
/* Some operations to be performed when ISR2 exits an interrupt. */
/* DD_1_0377 */
#define OS_ARCH_ISR2_EPILOGUE_1()                             \
{                                                             \
    OS_ISR2OCCUPYINTRES();                                    \
    Os_ExitISR2();                                            \
    Os_CLEAR_CDC_ISR2_EPILOGUE();                             \
    OS_ARCH_RESUME_CONTEXT();                                 \
}
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
FUNC(void, OS_CODE)  Os_ArchSetMemProtSet(uint32 MpSetIdx);
FUNC(uint32, OS_CODE) Os_ArchGetMemProtSet(void);
/* Set access rights for memory protection. */
/* DD_1_0378 */
#define OS_ARCH_SET_MP_ACCESS_RIGHT(rights, offset)           (((uint32)rights) << (offset))

/* Set up areas that can be accessed by a trusted APP. */
/* DD_1_0379 */
#define Os_ArchSetTruReg(D_Addrbase,C_Addrbase,DBitPos,CBitPos,D_RModeAddr,D_WModeAddr,C_ModeAddr)        \
{                                                                                                         \
    OS_ARCH_MTCR(D_Addrbase + 0x00U, (uint32)0x50000000);    									  		  \
    OS_ARCH_MTCR(D_Addrbase + 0x04U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pPeripheralEnd);            \
    OS_ARCH_MTCR(C_Addrbase + 0x00U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomStart);                 \
    OS_ARCH_MTCR(C_Addrbase + 0x04U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomEnd);                   \
    OS_ARCH_MTCR(D_RModeAddr, OS_ARCH_SET_MP_ACCESS_RIGHT(0x1U, DBitPos));                                \
    OS_ARCH_MTCR(D_WModeAddr, OS_ARCH_SET_MP_ACCESS_RIGHT(0x1U, DBitPos));                                \
    OS_ARCH_MTCR(C_ModeAddr, OS_ARCH_SET_MP_ACCESS_RIGHT(0x1U, CBitPos));                                 \
}



/* Set memory protection map for isr of non-trusted app */
/* DD_1_0380 */
#define Os_ArchSetNonTruIsrReg(D_Addrbase, C_Addrbase, DBitPos, CBitPos, D_RModeAddr, 					  \
        D_WModeAddr, C_ModeAddr, Isr, HostApp, CoreId)                                                    \
{                                                                                                         \
    OS_ARCH_MTCR(D_Addrbase + 0x00U, (uint32)0x50000000);                                                 \
    OS_ARCH_MTCR(D_Addrbase + 0x04U, (uint32)Os_Core_App_DAddr[CoreId].APP_ADDR_START);                   \
    OS_ARCH_MTCR(D_Addrbase + 0x08U, (uint32)Os_Core_App_DAddr[CoreId].APP_ADDR_END);                     \
    OS_ARCH_MTCR(D_Addrbase + 0x0CU, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pPeripheralEnd);            \
    OS_ARCH_MTCR(D_Addrbase + 0x10U, (uint32)Os_App_DAddr[HostApp].APP_ADDR_START);                       \
    OS_ARCH_MTCR(D_Addrbase + 0x14U, (uint32)Os_App_DAddr[HostApp].APP_ADDR_END);                         \
    OS_ARCH_MTCR(D_Addrbase + 0x18U, (uint32)Os_AppPriDataAddr[HostApp].APP_ADDR_START);                  \
    OS_ARCH_MTCR(D_Addrbase + 0x1CU, (uint32)Os_AppPriDataAddr[HostApp].APP_ADDR_END);                    \
    OS_ARCH_MTCR(D_Addrbase + 0x20U, (uint32)Os_IsrDAddr[Isr].ISR_ADDR_START);                            \
    OS_ARCH_MTCR(D_Addrbase + 0x24U, (uint32)Os_IsrDAddr[Isr].ISR_ADDR_END);                              \
    OS_ARCH_MTCR(D_Addrbase + 0x28U,                                                                      \
            (uint32)Os_AppCfg[HostApp].OsAppAssignedPeripheralAddr.APP_ADDR_START);                       \
    OS_ARCH_MTCR(D_Addrbase + 0x2CU,                                                                      \
            (uint32)Os_AppCfg[HostApp].OsAppAssignedPeripheralAddr.APP_ADDR_END);                         \
    OS_ARCH_MTCR(C_Addrbase + 0x00U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomStart);                 \
    OS_ARCH_MTCR(C_Addrbase + 0x04U, (uint32)Os_Core_App_CAddr[CoreId].APP_ADDR_START);                   \
    OS_ARCH_MTCR(C_Addrbase + 0x08U, (uint32)Os_Core_App_CAddr[CoreId].APP_ADDR_END);                     \
    OS_ARCH_MTCR(C_Addrbase + 0x0CU, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomEnd);                   \
    OS_ARCH_MTCR(C_Addrbase + 0x10U, (uint32)Os_App_CAddr[HostApp].APP_ADDR_START);                       \
    OS_ARCH_MTCR(C_Addrbase + 0x14U, (uint32)Os_App_CAddr[HostApp].APP_ADDR_END);                         \
    OS_ARCH_MTCR(D_RModeAddr, (uint32)OS_ARCH_SET_MP_ACCESS_RIGHT(0x18U, DBitPos));                       \
    OS_ARCH_MTCR(D_WModeAddr, (uint32)OS_ARCH_SET_MP_ACCESS_RIGHT(0x18U, DBitPos));                       \
    OS_ARCH_MTCR(C_ModeAddr, (uint32)OS_ARCH_SET_MP_ACCESS_RIGHT(0x7U, CBitPos));                         \
}


/* Set memory protection map for isr of trusted app */
/* DD_1_0381 */
#define Os_ArchSetTruIsrProtReg(D_Addrbase, C_Addrbase, DBitPos, CBitPos, D_RModeAddr,                    \
        D_WModeAddr, C_ModeAddr, Isr, HostApp)                                                            \
{                                                                                                         \
    OS_ARCH_MTCR((D_Addrbase) + 0x00U, (uint32)0x50000000);                           			          \
    OS_ARCH_MTCR((D_Addrbase) + 0x04U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pPeripheralEnd);          \
    OS_ARCH_MTCR((D_Addrbase) + 0x08U, (uint32)Os_AppPriDataAddr[HostApp].APP_ADDR_START);                \
    OS_ARCH_MTCR((D_Addrbase) + 0x0CU, (uint32)Os_AppPriDataAddr[HostApp].APP_ADDR_END);                  \
    OS_ARCH_MTCR((D_Addrbase) + 0x10U, (uint32)Os_IsrDAddr[Isr].ISR_ADDR_START);                          \
    OS_ARCH_MTCR((D_Addrbase) + 0x14U, (uint32)Os_IsrDAddr[Isr].ISR_ADDR_END);                            \
    OS_ARCH_MTCR((C_Addrbase) + 0x00U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomStart);               \
    OS_ARCH_MTCR((C_Addrbase) + 0x04U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomEnd);                 \
    OS_ARCH_MTCR((D_RModeAddr), OS_ARCH_SET_MP_ACCESS_RIGHT(0x7U, (DBitPos)));                            \
    OS_ARCH_MTCR((D_WModeAddr), OS_ARCH_SET_MP_ACCESS_RIGHT(0x6U, (DBitPos)));                       	  \
    OS_ARCH_MTCR((C_ModeAddr), OS_ARCH_SET_MP_ACCESS_RIGHT(0x1U, (CBitPos)));                             \
}


/* Set memory protection map for task of non-trusted app. */
/* DD_1_0382 */
#define Os_ArchSetNonTruTskReg(D_Addrbase, C_Addrbase, DBitPos, CBitPos, D_RModeAddr,                     \
        D_WModeAddr, C_ModeAddr, Task, HostApp, CoreId)                                                   \
{                                                                                                         \
    OS_ARCH_MTCR(D_Addrbase,         (uint32)0x50000000);                                                 \
    OS_ARCH_MTCR(D_Addrbase + 0x04U, (uint32)Os_Core_App_DAddr[CoreId].APP_ADDR_START);                   \
    OS_ARCH_MTCR(D_Addrbase + 0x08U, (uint32)Os_Core_App_DAddr[CoreId].APP_ADDR_END);                     \
    OS_ARCH_MTCR(D_Addrbase + 0x0CU, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pPeripheralEnd);            \
    OS_ARCH_MTCR(D_Addrbase + 0x10U, (uint32)Os_App_DAddr[HostApp].APP_ADDR_START);                       \
    OS_ARCH_MTCR(D_Addrbase + 0x14U, (uint32)Os_App_DAddr[HostApp].APP_ADDR_END);                         \
    OS_ARCH_MTCR(D_Addrbase + 0x18U, (uint32)Os_AppPriDataAddr[HostApp].APP_ADDR_START);                  \
    OS_ARCH_MTCR(D_Addrbase + 0x1CU, (uint32)Os_AppPriDataAddr[HostApp].APP_ADDR_END);                    \
    OS_ARCH_MTCR(D_Addrbase + 0x20U, (uint32)Os_TaskDAddr[Task].Task_ADDR_START);                         \
    OS_ARCH_MTCR(D_Addrbase + 0x24U, (uint32)Os_TaskDAddr[Task].Task_ADDR_END);                           \
    OS_ARCH_MTCR(D_Addrbase + 0x28U,                                                                      \
            (uint32)Os_AppCfg[HostApp].OsAppAssignedPeripheralAddr.APP_ADDR_START);                       \
    OS_ARCH_MTCR(D_Addrbase + 0x2CU,                                                                      \
            (uint32)Os_AppCfg[HostApp].OsAppAssignedPeripheralAddr.APP_ADDR_END);                         \
    OS_ARCH_MTCR(C_Addrbase + 0x00U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomStart);                 \
    OS_ARCH_MTCR(C_Addrbase + 0x04U, (uint32)Os_Core_App_CAddr[CoreId].APP_ADDR_START);                   \
    OS_ARCH_MTCR(C_Addrbase + 0x08U, (uint32)Os_Core_App_CAddr[CoreId].APP_ADDR_END);                     \
    OS_ARCH_MTCR(C_Addrbase + 0x0CU, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomEnd);                   \
    OS_ARCH_MTCR(C_Addrbase + 0x10U, (uint32)Os_App_CAddr[HostApp].APP_ADDR_START);                       \
    OS_ARCH_MTCR(C_Addrbase + 0x14U, (uint32)Os_App_CAddr[HostApp].APP_ADDR_END);                         \
    OS_ARCH_MTCR(D_RModeAddr, (uint32)OS_ARCH_SET_MP_ACCESS_RIGHT(0x18U, DBitPos));                       \
    OS_ARCH_MTCR(D_WModeAddr, (uint32)OS_ARCH_SET_MP_ACCESS_RIGHT(0x18U, DBitPos));                       \
    OS_ARCH_MTCR(C_ModeAddr, OS_ARCH_SET_MP_ACCESS_RIGHT(0x7U, CBitPos));                                 \
}

/* Set memory protection map for task of trusted app. */
/* DD_1_0383 */
#define Os_ArchSetTruTskProtReg(D_Addrbase,C_Addrbase,DBitPos,CBitPos,D_RModeAddr,                        \
                                              D_WModeAddr,C_ModeAddr,Task,HostApp)                        \
{                                                                                                         \
    OS_ARCH_MTCR(D_Addrbase + 0x00U, (uint32)0x50000000);                                                 \
    OS_ARCH_MTCR(D_Addrbase + 0x04U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pPeripheralEnd);            \
    OS_ARCH_MTCR(D_Addrbase + 0x08U, (uint32)Os_AppPriDataAddr[HostApp].APP_ADDR_START);                  \
    OS_ARCH_MTCR(D_Addrbase + 0x0CU, (uint32)Os_AppPriDataAddr[HostApp].APP_ADDR_END);                    \
    OS_ARCH_MTCR(D_Addrbase + 0x10U, (uint32)Os_TaskDAddr[Task].Task_ADDR_START);                         \
    OS_ARCH_MTCR(D_Addrbase + 0x14U, (uint32)Os_TaskDAddr[Task].Task_ADDR_END);                           \
    OS_ARCH_MTCR(C_Addrbase + 0x00U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomStart);                 \
    OS_ARCH_MTCR(C_Addrbase + 0x04U, (uint32)Os_MemProtKnAddrCfg.OsKernelAddr.pRomEnd);                   \
    OS_ARCH_MTCR(D_RModeAddr, OS_ARCH_SET_MP_ACCESS_RIGHT(0x7U, DBitPos));                                \
    OS_ARCH_MTCR(D_WModeAddr, OS_ARCH_SET_MP_ACCESS_RIGHT(0x6U, DBitPos));                                \
    OS_ARCH_MTCR(C_ModeAddr, OS_ARCH_SET_MP_ACCESS_RIGHT(0x1U, CBitPos));                                 \
}

/* Enable the enable bits for memory protection in PSW and SYSCON. */
/* DD_1_0384 */
#define Os_ArchMemProtEnable()                                                \
{                                                                             \
    uint32 temp = 0u;                                                         \
    temp = OS_ARCH_MFCR(OS_REG_PSW);                                          \
    temp &= 0xFFFFCFFFu;                                                      \
    OS_ARCH_MTCR(OS_REG_PSW, temp);                                           \
    temp = OS_ARCH_MFCR(OS_REG_SYSCON);                                       \
    temp |= 0x00000002u;                                                      \
    OS_ARCH_MTCR(OS_REG_SYSCON, temp);                                        \
}

/* Enable the enable bits for memory protection in PSW. */
/* DD_1_0385 */
#define Os_ArchMemProtSwithToSystem()     \
{                                         \
    uint32 temp = 0u;                     \
    temp = OS_ARCH_MFCR(OS_REG_PSW);      \
    temp &= 0xFFFFCFFFu;                  \
    OS_ARCH_MTCR(OS_REG_PSW, temp);       \
}

#else /* FALSE == CFG_MEMORY_PROTECTION_ENABLE */
/* Enable the enable bits for memory protection in PSW. */
/* DD_1_0385 */
#define Os_ArchMemProtSwithToSystem()
#define Os_ArchPrintRegisters()
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

/* The interrupt occupies interrupt resources. */
/* DD_1_0387 */
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
#define OS_ISR2OCCUPYINTRES() Os_Isr2OccupyIntRes()
#else /* #if (FALSE == CFG_SERVICE_PROTECTION_ENABLE) */
#define OS_ISR2OCCUPYINTRES()
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */

#if (TRUE == CFG_CPU_USAGE_ENABLE)

#define CPU_USARG_TIMER_VALUE(coreId)			OS_REG32(0xF0001010u + 0x100 * coreId)

#define CPU_USARG_TIMER_VALUE_MAX				0xFFFFFFFF

#endif

/*============[STACK CHECK]=====================*/
#define IF_STACK_CHECK_ENTER_ISR1_FROM_TASK()                        \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                         \
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_ENTER_ISR1_FROM_ISR2()                        \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                         \
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_ENTER_ISR1_FROM_ISR1()                        \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_EXIT_ISR1()                                   \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                         \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_ENTER_ISR2_FORM_TASK()                                \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                                 \
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_ENTER_ISR2_FORM_ISR2()                                \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                                 \
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_EXIT_ISR2()                                           \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                                 \
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))        \
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))        \
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))        \
   )
#define IF_STACK_CHECK_SWITCH_TASK()                                         \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                                 \
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define OS_FILL_SAFET_STACK()                                                \
{                                                                            \
    *ptr = OS_STACK_FILL_PATTERN;                                            \
    *(ptr + (Os_StackDataType)1) = OS_STACK_FILL_PATTERN;                    \
    *(ptr + (Os_StackDataType)2) = OS_STACK_FILL_PATTERN;                    \
    *(ptr + (Os_StackDataType)3) = OS_STACK_FILL_PATTERN;                    \
}
/*=======[T Y P E   D E F I N I T I O N S]====================================*/
/* Type of the variable to save the mcu status registration. */
/* DD_1_0051 */
typedef uint32 Os_ArchMsrType;

/* Type of the variable to save the task control block extension. */
/* DD_1_0052 */
typedef struct
{
    uint32 pcx;
    uint32 pcxLast;
}Os_TaskCBExtType;

/* Type of the variable to save data. */
/* DD_1_0053 */
typedef struct
{
    uint32 reg[16];
}Os_ArchCsaType;

/* Type of the trap. */
/* DD_1_0054 */
typedef void (*Os_traphnd)(uint16 Os_Tin);

/* Type of the interrupt service routine (ISR). */
/* DD_1_0055 */
typedef void (*Os_isrhnd)(void);

/* Type of the core mode. */
/* DD_1_0056 */
typedef enum
{
    OS_CORE_MODE_HALT       = 0U,
    OS_CORE_MODE_RUN        = 1U,
    OS_CORE_MODE_IDLE       = 2U,
    OS_CORE_MODE_SLEEP      = 3U,
    OS_CORE_MODE_STANDBY    = 4U,
    OS_CORE_MODE_UNKNOWN    = 5U
}Os_CoreModeType;


/*=======[E X T E R N A L   D A T A]==========================================*/
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
extern VAR(Os_TaskCBExtType, OS_VAR) Os_TaskCBExtCore0[CFG_TASK_MAX_CORE0];
#endif
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
extern VAR(Os_TaskCBExtType, OS_VAR) Os_TaskCBExtCore1[CFG_TASK_MAX_CORE1];
#endif
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
extern VAR(Os_TaskCBExtType, OS_VAR) Os_TaskCBExtCore2[CFG_TASK_MAX_CORE2];
#endif

extern VAR(volatile uint32, OS_VAR) Os_TempPcx;
extern VAR(volatile uint32, OS_VAR) Os_LoopPcx;
extern VAR(volatile uint32, OS_VAR) Os_NextPcx;
extern VAR(volatile uint32, OS_VAR) Os_TempPcxTermApp;
extern VAR(volatile uint32, OS_VAR) Os_LoopPcxTermApp;
extern VAR(volatile uint32, OS_VAR) Os_NextPcxTermApp;
extern VAR(volatile uint32, OS_VAR) Os_BeginPcxTermApp;

#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
extern OS_ALIGN(64) VAR(volatile Os_ArchCsaType, OS_VAR) Os_Csas_Core0[CFG_CSA_MAX_CORE0];
#endif
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
extern OS_ALIGN(64) VAR(volatile Os_ArchCsaType, OS_VAR) Os_Csas_Core1[CFG_CSA_MAX_CORE1];
#endif
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
extern OS_ALIGN(64) VAR(volatile Os_ArchCsaType, OS_VAR) Os_Csas_Core2[CFG_CSA_MAX_CORE2];
#endif



#if (TRUE == CFG_CPU_USAGE_ENABLE)

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern P2VAR(Os_TimeUsageType, AUTOMATIC, OS_VAR)         Os_TaskTimeUsage;
extern P2VAR(Os_TimeUsageType, AUTOMATIC, OS_VAR)         Os_IsrTimeUsage;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
extern VAR(Os_TimeUsageType, OS_VAR)                      Os_TaskTimeUsageCore0[CFG_TASK_MAX_CORE0];
extern VAR(Os_TimeUsageType, OS_VAR)                      Os_IsrTimeUsageCore0[CFG_ISR2_MAX_CORE0];
#endif /* (TRUE == CFG_CORE0_AUTOSAROS_ENABLE) */
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
extern VAR(Os_TimeUsageType, OS_VAR)                      Os_TaskTimeUsageCore1[CFG_TASK_MAX_CORE1];
extern VAR(Os_TimeUsageType, OS_VAR)                      Os_IsrTimeUsageCore1[CFG_ISR2_MAX_CORE1];
#endif /* (TRUE == CFG_CORE1_AUTOSAROS_ENABLE) */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
extern VAR(Os_TimeUsageType, OS_VAR)                      Os_TaskTimeUsageCore2[CFG_TASK_MAX_CORE2];
extern VAR(Os_TimeUsageType, OS_VAR)                      Os_IsrTimeUsageCore2[CFG_ISR2_MAX_CORE2];
#endif /* (TRUE == CFG_CORE2_AUTOSAROS_ENABLE) */

#endif /* #if (TRUE == CFG_CPU_USAGE_ENABLE) */


extern P2VAR(volatile Os_ArchCsaType, AUTOMATIC, OS_VAR)	Os_Csas;
extern VAR(volatile uint32, OS_VAR)                 		Os_ArchSp;
extern VAR(uint16, OS_VAR)                          		Os_CfgCsaMax;
extern P2VAR(Os_TaskCBExtType, AUTOMATIC, OS_VAR)   		Os_TaskCBExt;
extern P2VAR(uint32, AUTOMATIC, OS_VAR)             		Os_IsrNestPcxStack;
extern P2CONST(OS_ISR_ADDR, AUTOMATIC, OS_VAR)      		Os_IsrDAddr;
extern P2CONST(OS_TASK_ADDR, AUTOMATIC, OS_VAR)     		Os_TaskDAddr;
extern VAR(uint32, OS_VAR) 	                                Os_SysTimerReloadVal;
extern VAR(uint32, OS_VAR) 	                                Os_TprotTimerReloadVal;

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
extern VAR(uint32, OS_VAR) Os_PSW_PRS;
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
extern VAR(volatile uint32, OS_VAR) Os_TprotTerminateIsr;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

#if (CFG_ISR_MAX > 0U)
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
extern VAR(uint32, OS_VAR) Os_IsrNestPcxStackCore0[CFG_ISR_MAX_CORE0];
#endif
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
extern VAR(uint32, OS_VAR) Os_IsrNestPcxStackCore1[CFG_ISR_MAX_CORE1];
#endif
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
extern VAR(uint32, OS_VAR) Os_IsrNestPcxStackCore2[CFG_ISR_MAX_CORE2];
#endif

extern VAR(Os_CallLevelType, OS_VAR) Os_SaveLevelISR1;
#endif /* CFG_ISR_MAX > 0U */

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
extern FUNC(Os_IPLType, OS_CODE) Os_ArchGetIpl(void);
extern FUNC(void, OS_CODE) Os_ArchSetIpl(Os_IPLType ipl,Os_IsrDescriptionType isrdesc);
extern FUNC(void, OS_CODE) Os_ArchSuspendInt(P2VAR(Os_ArchMsrType, AUTOMATIC, OS_VAR) msr);
extern FUNC(void, OS_CODE) Os_ArchRestoreInt(Os_ArchMsrType msr);
extern FUNC(void, OS_CODE) Os_ArchInitCPU(void);
extern FUNC(void, OS_CODE) Os_ArchFirstEnterTask(void);
extern FUNC(void, OS_CODE) Os_ArchStartScheduler(void);
extern FUNC(void, OS_CODE) Os_ArchInitCsas(void);
extern FUNC(void, OS_CODE) Os_ModeModify(void);

/* Memory protection. */
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
extern FUNC(void,OS_CODE) Os_ArchInitKnMemMap(void);
extern FUNC(void,OS_CODE) Os_ArchSetTaskMemMap(TaskType TaskId, ApplicationType HostAppId, \
                                               uint32 isTrusted);
extern FUNC(void, OS_CODE) Os_ArchSetIsrMemMap
(
    ISRType         IsrId, 
    ApplicationType HostAppId, 
    uint32          isTrusted
);
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
extern FUNC(void, OS_CODE) Os_ArchDisableAllInt_ButTimingProtInt(void);
extern FUNC(void, OS_CODE) Os_ArchEnableAllInt_ButTimingProtInt(void);
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE) */

extern FUNC(void, OS_CODE) Os_ArchDispatcher(void);
extern FUNC(void, OS_CODE) Os_ArchInitIntPrio(void);

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (CFG_ISR_MAX > 0)
extern FUNC(void, OS_CODE) Os_ArchDisableIntInApp
(
    P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) posCurAppCfg
);
extern FUNC(void, OS_CODE) Os_ArchAppTerminateIsrProc(Os_IsrType OsIsrID);
#endif /* CFG_ISR_MAX > 0 */
extern FUNC(void, OS_CODE) Os_ArchAppTerminateTaskProc(Os_TaskType OsTaskID);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

extern INLINE uint32 Os_Extru(uint32 a, uint32 p, uint32 w);
extern INLINE uint32 Os_CmpSwapW(uint32* address, uint32 compareVal, uint32 exchangedVal);
extern FUNC(void, OS_CODE) Os_InterruptInstall(uint32 srcAddr, uint8 prio, uint32 srcType,\
                                               Os_isrhnd isrProc);
extern FUNC(void, OS_CODE) Os_IntHandler(void);

extern FUNC(Os_CoreIdType,OS_CODE)         Os_ArchGetCoreID(void);
extern FUNC(void, OS_CODE)                 Os_ArchStartCore(Os_CoreIdType coreId);
extern FUNC(Os_CoreModeType, OS_CODE)     Os_GetCoreMode(Os_CoreIdType core);
extern FUNC(boolean, OS_CODE)             Os_SetCoreMode(Os_CoreIdType core, \
                                                         Os_CoreModeType coreMode);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif  /* #ifndef OS_PROCESSOR_H */
/*=======[E N D   O F   F I L E]==============================================*/
