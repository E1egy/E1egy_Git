/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Cry_MemMap.h                                                **
**                                                                            **
**  VERSION     : 1.0.0                                                       **
**                                                                            **
**  DATE        : 2018-06-13                                                  **
**                                                                            **
**  VARIANT     : NA                                                          **
**                                                                            **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                               **
**                [Refer Release Package for Supported Device]                **
**  AUTHOR      : Prashant K                                                  **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION :                                                             **
**                                                                            **
**             This file allows to map variables, constants and code          **
**             of CRY module to memory sections.                              **
**                                                                            **
**             Important note 1: if specific variables and constants are      **
**             mapped to banked/paged memory, the related compiler            **
**             abstraction symbols must fit to these locations!               **
**                                                                            **
**             Important note 2: The section names passed via #pragmas must   **
**             be defined in the linker control and section map files!        **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
<IFX_RCH>
</IFX_RCH>
*/

#ifndef CRY_MEMMAP_H
#define CRY_MEMMAP_H
#endif
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/******************************************************************************
**                  CRY Module section mapping                               **
******************************************************************************/
/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */

#if defined (START_WITH_IF)
/*
 * The symbol 'START_WITH_IF' is undefined.
 *
 * Thus, the preprocessor continues searching for defined symbols
 */
#elif defined (CRY_START_SEC_CODE)
   #undef      CRY_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_CODE)
   #undef      CRY_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_CORE0_PRIVATE

#elif defined (CRY_START_SEC_RAMCODE)
   #undef      CRY_START_SEC_RAMCODE
   #define   CRY_START_SEC_RAMCODE_PRIVATE
#elif defined (CRY_STOP_SEC_RAMCODE)
   #undef      CRY_STOP_SEC_RAMCODE
   #define CRY_STOP_SEC_RAMCODE_PRIVATE

#elif defined (CRY_START_SEC_VAR_NOINIT_8BIT)
   #undef      CRY_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CRY_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_NOINIT_16BIT)
   #undef      CRY_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CRY_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_NOINIT_32BIT)
   #undef      CRY_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CRY_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CRY_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CRY_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CRY_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CRY_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CRY_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CRY_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CRY_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CRY_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CRY_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_FAST_8BIT)
   #undef      CRY_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_FAST_8BIT)
   #undef      CRY_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_FAST_16BIT)
   #undef      CRY_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_FAST_16BIT)
   #undef      CRY_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_FAST_32BIT)
   #undef      CRY_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_FAST_32BIT)
   #undef      CRY_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CRY_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CRY_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_8BIT)
   #undef      CRY_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_8BIT)
   #undef      CRY_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_16BIT)
   #undef      CRY_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_16BIT)
   #undef      CRY_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_32BIT)
   #undef      CRY_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_32BIT)
   #undef      CRY_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_UNSPECIFIED)
   #undef      CRY_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CRY_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_INIT_UNSPECIFIED)
   #undef      CRY_START_SEC_VAR_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_INIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #undef      CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_INIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_VAR_ALIGN16)
   #undef      CRY_START_SEC_VAR_ALIGN16
   #define   DEFAULT_START_SEC_VAR_ALIGN16_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_VAR_ALIGN16)
   #undef      CRY_STOP_SEC_VAR_ALIGN16
   #define DEFAULT_STOP_SEC_VAR_ALIGN16_CORE0_PRIVATE

#elif defined (CRY_START_SEC_CONST_8BIT)
   #undef      CRY_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_CONST_8BIT)
   #undef      CRY_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_CONST_16BIT)
   #undef      CRY_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_CONST_16BIT)
   #undef      CRY_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE


#elif defined (CRY_START_SEC_CONST_32BIT)
   #undef      CRY_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_CONST_32BIT)
   #undef      CRY_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE

#elif defined (CRY_START_SEC_CONST_UNSPECIFIED)
   #undef      CRY_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CRY_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE

#elif defined (CRY_START_SEC_POSTBUILDCFG)
   #undef      CRY_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
#elif defined (CRY_STOP_SEC_POSTBUILDCFG)
   #undef      CRY_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE

#elif defined (CRY_BL_SIZE_START_SEC_CONST)
   #undef      CRY_BL_SIZE_START_SEC_CONST
   #define DEFAULT_BL_SIZE_START_SEC_CONST
#elif defined (CRY_BL_SIZE_STOP_SEC_CONST)
   #undef      CRY_BL_SIZE_STOP_SEC_CONST
   #define DEFAULT_BL_SIZE_STOP_SEC_CONST

#else
  #error "Cry_MemMap.h: No valid section define found"
#endif

#if defined (START_WITH_IF)
#elif defined (CRY_START_SEC_RAMCODE_PRIVATE)
   #undef      CRY_START_SEC_RAMCODE_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CRYRAMCODE"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".CRYRAMCODE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".CRYRAMCODE" far-absolute RX
   #endif
   #endif
#elif defined (CRY_STOP_SEC_RAMCODE_PRIVATE)
   #undef      CRY_STOP_SEC_RAMCODE_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_ALIGN16_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_ALIGN16_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ALIGN16"
   #pragma align 16
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ALIGN16" aw 16
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ALIGN16" ".bss.CPU0.Private.DEFAULT_RAM_ALIGN16" far-absolute RW
   #pragma align_variables 16
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_ALIGN16_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_ALIGN16_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU0.Private.DEFAULT_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU0.Private.DEFAULT_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU0.Private.DEFAULT_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_8BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_16BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_32BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
      #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_8BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_16BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_16BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_32BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_INIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_INIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU0.Private.DEFAULT_RAM_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_INIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_INIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_16BIT" a 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_16BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_32BIT" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_32BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.CONFIGURATION_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.CONFIGURATION_PB" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.CONFIGURATION_PB" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif

#elif defined (DEFAULT_BL_SIZE_START_SEC_CONST)
   #undef DEFAULT_BL_SIZE_START_SEC_CONST
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="SHE_BL_SIZE"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.SHE_BL_SIZE" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".SHE_BL_SIZE" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_BL_SIZE_STOP_SEC_CONST)
   #undef DEFAULT_BL_SIZE_STOP_SEC_CONST
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif

#else
  #error "Cry_MemMap.h: No valid section define found"
#endif  /* START_WITH_IF */

