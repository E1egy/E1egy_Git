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
**  FILENAME    : NvM_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2023/03/25 21:01:11                                 **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile configuration parameter of NvM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef NVM_CFG_H
#define NVM_CFG_H
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#define NVM_CFG_H_AR_MAJOR_VERSION 4U
#define NVM_CFG_H_AR_MINOR_VERSION 2U
#define NVM_CFG_H_AR_PATCH_VERSION 2U

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define NVM_API_CONFIG_CLASS                            NVM_API_CONFIG_CLASS_3
#define NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION        STD_ON
#define NVM_BSWM_SINGLEBLOCK_JOBSTATUS_INFORMATION      STD_OFF
#define NVM_COMPILED_CONFIG_ID                          (0xaabbu)
#define NVM_CRC_NUM_OF_BYTES                              (0x80u)
#define NVM_DATASET_SELECTION_BITS                      (0x8u)
#define NVM_DEV_ERROR_DETECT                            STD_OFF
#define NVM_DRV_MODE_SWITCH                                 STD_OFF
#define NVM_DYNAMIC_CONFIGURATION                         STD_OFF
#define NVM_JOB_PRIORITIZATION                            STD_OFF
#define NVM_POLLING_MODE                                STD_OFF
#define NVM_REPEAT_MIRROR_OPERATIONS                      (0x5u)
#define NVM_SET_RAM_BLOCK_STATUS_API                    STD_OFF
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE                    (0x0u)
#define NVM_SIZE_STANDARD_JOB_QUEUE                        (0x16u)
#define NVM_VERSION_INFO_API                            STD_OFF
#define NVM_INCLUDE_CRC                                 STD_ON
#define NVM_CRC_TYPE_8                                  STD_OFF
#define NVM_CRC_TYPE_16                                 STD_ON
#define NVM_CRC_TYPE_32                                 STD_OFF
#define NVM_DEM_PRODUCTION_ERROR_DETECT                    STD_OFF

/*The following definitions used to index NVM block for SW */
#define NvMBlockNvm_Block_DCM               2
#define NvMBlockNvm_Block_DEM_1               3
#define NvMBlockNvm_Block_DEM_2               4
#define NvMBlock_CddMode               5
#define NvMBlock_Height               6
#define NvMBlockNvm_Block_F184               7
#define NvMBlockNvm_Block_F18B               8
#define NvMBlockNvm_Block_F190               9
#define NvMBlockNvm_Block_F0F1               10
#define NvMBlockNvm_Block_F0F3               11
#define NvMBlockNvm_Block_394A               12
#define NvMBlockNvm_Block_3907               13
#define NvMBlockNvm_Block_396E               14
#define NvMBlockNvm_Block_F18C               15
#define NvMBlockNvm_Block_F025               16
#define NvMBlockNvm_Block_390A               17
#define NvMBlockNvm_Block_3976               18

/*The total number of user configured*/
#define NVM_BLOCK_NUM_ALL                                 18
#define NVM_REDUNDANT_ALL                                  1

#define NVM_MAX_LENGTH_CONFIGED_RAM_MIRROR                0U

#define NVM_MAX_LENGTH_NV_BLOCK                            10324U
#define NVM_MAX_LENGTH_REDUNDANT_BLOCK                    2U

#if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON == NVM_JOB_PRIORITIZATION))
/*The total number of different priority*/
#define NVM_TOTAL_NUM_DIFF_PRI                             NVM_TABLE_SIZE_PRIORITY
#endif

#if (STD_ON==NVM_JOB_PRIORITIZATION)
/* The priority table size*/
#define NVM_TABLE_SIZE_PRIORITY                          2U
#endif

#endif /* End of NVM_CFG_H*/
/*******************************************************************************
**                           End Of File                                      **
*******************************************************************************/

