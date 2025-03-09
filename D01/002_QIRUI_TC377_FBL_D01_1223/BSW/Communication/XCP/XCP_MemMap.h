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
**  FILENAME    : XCP_MemMap.h                                                **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of XCP               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/
#define XCP_MEMMAP_VENDOR_ID        62
#define XCP_MEMMAP_MODULE_ID        195
#define XCP_MEMMAP_AR_MAJOR_VERSION  4
#define XCP_MEMMAP_AR_MINOR_VERSION  2
#define XCP_MEMMAP_AR_PATCH_VERSION  2
#define XCP_MEMMAP_SW_MAJOR_VERSION  1
#define XCP_MEMMAP_SW_MINOR_VERSION  0
#define XCP_MEMMAP_SW_PATCH_VERSION  0
#define XCP_MEMMAP_VENDOR_API_INFIX  0

/*=======[M E M M A P  S Y M B O L  D E F I N E]==============================*/
/*General function.*/
#if defined XCP_START_SEC_CODE
    #undef XCP_START_SEC_CODE
    #define START_SEC_CODE
#elif defined XCP_STOP_SEC_CODE
    #undef XCP_STOP_SEC_CODE
    #define STOP_SEC_CODE
/*Callback function.*/
#elif defined XCP_START_SEC_CANIFRXINDICATION_CALLBACK_CODE
    #undef XCP_START_SEC_CANIFRXINDICATION_CALLBACK_CODE
    #define  START_SEC_CALLBACK_CODE
#elif defined XCP_STOP_SEC_CANIFRXINDICATION_CALLBACK_CODE
    #undef XCP_STOP_SEC_CANIFRXINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE
#elif defined XCP_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
    #undef XCP_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
    #define  START_SEC_CALLBACK_CODE
#elif defined XCP_STOP_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
    #undef XCP_STOP_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined XCP_START_SEC_SOADIFRXINDICATION_CALLBACK_CODE
    #undef XCP_START_SEC_SOADIFRXINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined XCP_STOP_SEC_SOADIFRXINDICATION_CALLBACK_CODE
    #undef XCP_STOP_SEC_SOADIFRXINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE
#elif defined XCP_START_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE
    #undef XCP_START_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined XCP_STOP_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE
    #undef XCP_STOP_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

/*Bss data(clear)*/
#elif defined XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined XCP_START_SEC_VAR_CLEARED_PTR
    #undef XCP_START_SEC_VAR_CLEARED_PTR
    #define START_SEC_VAR_CLEARED_PTR
#elif defined XCP_STOP_SEC_VAR_CLEARED_PTR
    #undef XCP_STOP_SEC_VAR_CLEARED_PTR
    #define STOP_SEC_VAR_CLEARED_PTR

#elif defined XCP_START_SEC_VAR_CLEARED_32
    #undef XCP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32
#elif defined XCP_STOP_SEC_VAR_CLEARED_32
    #undef XCP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR_CLEARED_32

#elif defined XCP_START_SEC_VAR_CLEARED_16
    #undef XCP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16
#elif defined XCP_STOP_SEC_VAR_CLEARED_16
    #undef XCP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR_CLEARED_16

#elif defined XCP_START_SEC_VAR_CLEARED_8
    #undef XCP_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8
#elif defined XCP_STOP_SEC_VAR_CLEARED_8
    #undef XCP_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR_CLEARED_8

#elif defined XCP_START_SEC_VAR_CLEARED_BOOLEAN
    #undef XCP_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN
#elif defined XCP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef XCP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR_CLEARED_BOOLEAN
/*Init data(clear)*/
#elif defined XCP_START_SEC_VAR_INIT_UNSPECIFIED
    #undef XCP_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED
#elif defined XCP_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef XCP_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_INIT_UNSPECIFIED

#elif defined XCP_START_SEC_VAR_INIT_PTR
    #undef XCP_START_SEC_VAR_INIT_PTR
    #define START_SEC_VAR_INIT_PTR
#elif defined XCP_STOP_SEC_VAR_INIT_PTR
    #undef XCP_STOP_SEC_VAR_INIT_PTR
    #define STOP_SEC_VAR_INIT_PTR

#elif defined XCP_START_SEC_VAR_INIT_32
    #undef XCP_START_SEC_VAR_INIT_32
    #define START_SEC_VAR_INIT_32
#elif defined XCP_STOP_SEC_VAR_INIT_32
    #undef XCP_STOP_SEC_VAR_INIT_32
    #define STOP_SEC_VAR_INIT_32

#elif defined XCP_START_SEC_VAR_INIT_16
    #undef XCP_START_SEC_VAR_INIT_16
    #define START_SEC_VAR_INIT_16
#elif defined XCP_STOP_SEC_VAR_INIT_16
    #undef XCP_STOP_SEC_VAR_INIT_16
    #define STOP_SEC_VAR_INIT_16

#elif defined XCP_START_SEC_VAR_INIT_8
    #undef XCP_START_SEC_VAR_INIT_8
    #define START_SEC_VAR_INIT_8
#elif defined XCP_STOP_SEC_VAR_INIT_8
    #undef XCP_STOP_SEC_VAR_INIT_8
    #define STOP_SEC_VAR_INIT_8

#elif defined XCP_START_SEC_VAR_INIT_BOOLEAN
    #undef XCP_START_SEC_VAR_INIT_BOOLEAN
    #define START_SEC_VAR_INIT_BOOLEAN
#elif defined XCP_STOP_SEC_VAR_INIT_BOOLEAN
    #undef XCP_STOP_SEC_VAR_INIT_BOOLEAN
    #define STOP_SEC_VAR_INIT_BOOLEAN
/*No-Init data(clear)*/
#elif defined XCP_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef XCP_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#elif defined XCP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef XCP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_NO_INIT_UNSPECIFIED

#elif defined XCP_START_SEC_VAR_NO_INIT_PTR
    #undef XCP_START_SEC_VAR_NO_INIT_PTR
    #define START_SEC_VAR_NO_INIT_PTR
#elif defined XCP_STOP_SEC_VAR_NO_INIT_PTR
    #undef XCP_STOP_SEC_VAR_NO_INIT_PTR
    #define STOP_SEC_VAR_NO_INIT_PTR

#elif defined XCP_START_SEC_VAR_NO_INIT_32
    #undef XCP_START_SEC_VAR_NO_INIT_32
    #define START_SEC_VAR_NO_INIT_32
#elif defined XCP_STOP_SEC_VAR_NO_INIT_32
    #undef XCP_STOP_SEC_VAR_NO_INIT_32
    #define STOP_SEC_VAR_NO_INIT_32

#elif defined XCP_START_SEC_VAR_NO_INIT_16
    #undef XCP_START_SEC_VAR_NO_INIT_16
    #define START_SEC_VAR_NO_INIT_16
#elif defined XCP_STOP_SEC_VAR_NO_INIT_16
    #undef XCP_STOP_SEC_VAR_NO_INIT_16
    #define STOP_SEC_VAR_NO_INIT_16

#elif defined XCP_START_SEC_VAR_NO_INIT_8
    #undef XCP_START_SEC_VAR_NO_INIT_8
    #define START_SEC_VAR_NO_INIT_8
#elif defined XCP_STOP_SEC_VAR_NO_INIT_8
    #undef XCP_STOP_SEC_VAR_NO_INIT_8
    #define STOP_SEC_VAR_NO_INIT_8

#elif defined XCP_START_SEC_VAR_NO_INIT_BOOLEAN
    #undef XCP_START_SEC_VAR_NO_INIT_BOOLEAN
    #define START_SEC_VAR_NO_INIT_BOOLEAN
#elif defined XCP_STOP_SEC_VAR_NO_INIT_BOOLEAN
    #undef XCP_STOP_SEC_VAR_NO_INIT_BOOLEAN
    #define STOP_SEC_VAR_NO_INIT_BOOLEAN
/*Resume memory.*/
#elif defined XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #undef XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #define START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#elif defined XCP_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #undef XCP_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #define STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#elif defined XCP_START_SEC_VAR_SAVED_ZONE_PTR
    #undef XCP_START_SEC_VAR_SAVED_ZONE_PTR
    #define START_SEC_VAR_SAVED_ZONE_PTR
#elif defined XCP_STOP_SEC_VAR_SAVED_ZONE_PTR
    #undef XCP_STOP_SEC_VAR_SAVED_ZONE_PTR
    #define STOP_SEC_VAR_SAVED_ZONE_PTR
#elif defined XCP_START_SEC_VAR_SAVED_ZONE_32
    #undef XCP_START_SEC_VAR_SAVED_ZONE_32
    #define START_SEC_VAR_SAVED_ZONE_32
#elif defined XCP_STOP_SEC_VAR_SAVED_ZONE_32
    #undef XCP_STOP_SEC_VAR_SAVED_ZONE_32
    #define STOP_SEC_VAR_SAVED_ZONE_32
#elif defined XCP_START_SEC_VAR_SAVED_ZONE_16
    #undef XCP_START_SEC_VAR_SAVED_ZONE_16
    #define START_SEC_VAR_SAVED_ZONE_16
#elif defined XCP_STOP_SEC_VAR_SAVED_ZONE_16
    #undef XCP_STOP_SEC_VAR_SAVED_ZONE_16
    #define STOP_SEC_VAR_SAVED_ZONE_16
#elif defined XCP_START_SEC_VAR_SAVED_ZONE_8
    #undef XCP_START_SEC_VAR_SAVED_ZONE_8
    #define START_SEC_VAR_SAVED_ZONE_8
#elif defined XCP_STOP_SEC_VAR_SAVED_ZONE_8
    #undef XCP_STOP_SEC_VAR_SAVED_ZONE_8
    #define STOP_SEC_VAR_SAVED_ZONE_8
#elif defined XCP_START_SEC_VAR_SAVED_ZONE_BOOLEAN
    #undef XCP_START_SEC_VAR_SAVED_ZONE_BOOLEAN
    #define START_SEC_VAR_SAVED_ZONE_BOOLEAN
#elif defined XCP_STOP_SEC_VAR_SAVED_ZONE_BOOLEAN
    #undef XCP_STOP_SEC_VAR_SAVED_ZONE_BOOLEAN
    #define STOP_SEC_VAR_SAVED_ZONE_BOOLEAN

/*For calibration data*/
#elif defined XCP_START_SEC_INTERNAL_CALVAR_32
    #undef XCP_START_SEC_INTERNAL_CALVAR_32
    #define START_SEC_INTERNAL_CALVAR_32
#elif defined XCP_STOP_SEC_INTERNAL_CALVAR_32
    #undef XCP_STOP_SEC_INTERNAL_CALVAR_32
    #define STOP_SEC_INTERNAL_CALVAR_32
#elif defined XCP_START_SEC_INTERNAL_CALVAR_16
    #undef XCP_START_SEC_INTERNAL_CALVAR_16
    #define START_SEC_INTERNAL_CALVAR_16
#elif defined XCP_STOP_SEC_INTERNAL_CALVAR_16
    #undef XCP_STOP_SEC_INTERNAL_CALVAR_16
    #define STOP_SEC_INTERNAL_CALVAR_16
#elif defined XCP_START_SEC_INTERNAL_CALVAR_8
    #undef XCP_START_SEC_INTERNAL_CALVAR_8
    #define START_SEC_INTERNAL_CALVAR_8
#elif defined XCP_STOP_SEC_INTERNAL_CALVAR_8
    #undef XCP_STOP_SEC_INTERNAL_CALVAR_8
    #define STOP_SEC_INTERNAL_CALVAR_8
/*For mea data*/
#elif defined XCP_START_SEC_INTERNAL_MEAMEAVAR_32
    #undef XCP_START_SEC_INTERNAL_MEAVAR_32
    #define START_SEC_INTERNAL_MEAVAR_32
#elif defined XCP_STOP_SEC_INTERNAL_MEAVAR_32
    #undef XCP_STOP_SEC_INTERNAL_MEAVAR_32
    #define STOP_SEC_INTERNAL_MEAVAR_32
#elif defined XCP_START_SEC_INTERNAL_MEAVAR_16
    #undef XCP_START_SEC_INTERNAL_MEAVAR_16
    #define START_SEC_INTERNAL_MEAVAR_16
#elif defined XCP_STOP_SEC_INTERNAL_MEAVAR_16
    #undef XCP_STOP_SEC_INTERNAL_MEAVAR_16
    #define STOP_SEC_INTERNAL_MEAVAR_16
#elif defined XCP_START_SEC_INTERNAL_MEAVAR_8
    #undef XCP_START_SEC_INTERNAL_MEAVAR_8
    #define START_SEC_INTERNAL_MEAVAR_8
#elif defined XCP_STOP_SEC_INTERNAL_MEAVAR_8
    #undef XCP_STOP_SEC_INTERNAL_MEAVAR_8
    #define STOP_SEC_INTERNAL_MEAVAR_8

/*Const data.*/
#elif defined XCP_START_SEC_CONST_UNSPECIFIED
    #undef XCP_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined XCP_STOP_SEC_CONST_UNSPECIFIED
    #undef XCP_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST_UNSPECIFIED

#elif defined XCP_START_SEC_CONST_PTR
    #undef XCP_START_SEC_CONST_PTR
    #define START_SEC_CONST_PTR
#elif defined XCP_STOP_SEC_CONST_PTR
    #undef XCP_STOP_SEC_CONST_PTR
    #define STOP_SEC_CONST_PTR

#elif defined XCP_START_SEC_CONST_32
    #undef XCP_START_SEC_CONST_32
    #define START_SEC_CONST_32
#elif defined XCP_STOP_SEC_CONST_32
    #undef XCP_STOP_SEC_CONST_32
    #define STOP_SEC_CONST_32

#elif defined XCP_START_SEC_CONST_16
    #undef XCP_START_SEC_CONST_16
    #define START_SEC_CONST_16
#elif defined XCP_STOP_SEC_CONST_16
    #undef XCP_STOP_SEC_CONST_16
    #define STOP_SEC_CONST_16

#elif defined XCP_START_SEC_CONST_8
    #undef XCP_START_SEC_CONST_8
    #define START_SEC_CONST_8
#elif defined XCP_STOP_SEC_CONST_8
    #undef XCP_STOP_SEC_CONST_8
    #define STOP_SEC_CONST_8

#elif defined XCP_START_SEC_CONST_BOOLEAN
    #undef XCP_START_SEC_CONST_BOOLEAN
    #define START_SEC_CONST_BOOLEAN
#elif defined XCP_STOP_SEC_CONST_BOOLEAN
    #undef XCP_STOP_SEC_CONST_BOOLEAN
    #define STOP_SEC_CONST_BOOLEAN
/*Config data(PB,for other BSW module.).*/
#elif defined XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
    #undef XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
    #define START_SEC_CONST_PBCFG_UNSPECIFIED
#elif defined XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
    #undef XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
    #define STOP_SEC_CONST_PBCFG_UNSPECIFIED

#elif defined XCP_START_SEC_CONST_PBCFG_PTR
    #undef XCP_START_SEC_CONST_PBCFG_PTR
    #define START_SEC_CONST_PBCFG_PTR
#elif defined XCP_STOP_SEC_CONST_PBCFG_PTR
    #undef XCP_STOP_SEC_CONST_PBCFG_PTR
    #define STOP_SEC_CONST_PBCFG_PTR

#elif defined XCP_START_SEC_CONST_PBCFG_32
    #undef XCP_START_SEC_CONST_PBCFG_32
    #define START_SEC_CONST_PBCFG_32
#elif defined XCP_STOP_SEC_CONST_PBCFG_32
    #undef XCP_STOP_SEC_CONST_PBCFG_32
    #define STOP_SEC_CONST_PBCFG_32

#elif defined XCP_START_SEC_CONST_PBCFG_16
    #undef XCP_START_SEC_CONST_PBCFG_16
    #define START_SEC_CONST_PBCFG_16
#elif defined XCP_STOP_SEC_CONST_PBCFG_16
    #undef XCP_STOP_SEC_CONST_PBCFG_16
    #define STOP_SEC_CONST_PBCFG_16

#elif defined XCP_START_SEC_CONST_PBCFG_8
    #undef XCP_START_SEC_CONST_PBCFG_8
    #define START_SEC_CONST_PBCFG_8
#elif defined XCP_STOP_SEC_CONST_PBCFG_8
    #undef XCP_STOP_SEC_CONST_PBCFG_8
    #define STOP_SEC_CONST_PBCFG_8

#elif defined XCP_START_SEC_CONST_PBCFG_BOOLEAN
    #undef XCP_START_SEC_CONST_PBCFG_BOOLEAN
    #define START_SEC_CONST_PBCFG_BOOLEAN
#elif defined XCP_STOP_SEC_CONST_PBCFG_BOOLEAN
    #undef XCP_STOP_SEC_CONST_PBCFG_BOOLEAN
    #define STOP_SEC_CONST_PBCFG_BOOLEAN
/*Config data(PC/LC).*/
#elif defined XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define STOP_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined XCP_START_SEC_CONFIG_DATA_PTR
    #undef XCP_START_SEC_CONFIG_DATA_PTR
    #define START_SEC_CONFIG_DATA_PTR
#elif defined XCP_STOP_SEC_CONFIG_DATA_PTR
    #undef XCP_STOP_SEC_CONFIG_DATA_PTR
    #define STOP_SEC_CONFIG_DATA_PTR

#elif defined XCP_START_SEC_CONFIG_DATA_32
    #undef XCP_START_SEC_CONFIG_DATA_32
    #define START_SEC_CONFIG_DATA_32
#elif defined XCP_STOP_SEC_CONFIG_DATA_32
    #undef XCP_STOP_SEC_CONFIG_DATA_32
    #define STOP_SEC_CONFIG_DATA_32

#elif defined XCP_START_SEC_CONFIG_DATA_16
    #undef XCP_START_SEC_CONFIG_DATA_16
    #define START_SEC_CONFIG_DATA_16
#elif defined XCP_STOP_SEC_CONFIG_DATA_16
    #undef XCP_STOP_SEC_CONFIG_DATA_16
    #define STOP_SEC_CONFIG_DATA_16

#elif defined XCP_START_SEC_CONFIG_DATA_8
    #undef XCP_START_SEC_CONFIG_DATA_8
    #define START_SEC_CONFIG_DATA_8
#elif defined XCP_STOP_SEC_CONFIG_DATA_8
    #undef XCP_STOP_SEC_CONFIG_DATA_8
    #define STOP_SEC_CONFIG_DATA_8

#elif defined XCP_START_SEC_CONFIG_DATA_BOOLEAN
    #undef XCP_START_SEC_CONFIG_DATA_BOOLEAN
    #define START_SEC_CONFIG_DATA_BOOLEAN
#elif defined XCP_STOP_SEC_CONFIG_DATA_BOOLEAN
    #undef XCP_STOP_SEC_CONFIG_DATA_BOOLEAN
    #define STOP_SEC_CONFIG_DATA_BOOLEAN
#else
    #error "No valid section define found"
#endif
#include "MemMap.h"

