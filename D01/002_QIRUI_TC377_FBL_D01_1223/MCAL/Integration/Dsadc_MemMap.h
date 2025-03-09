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
**  FILENAME  : Dsadc_MemMap.h                                                      **
**                                                                            **
**  VERSION      : 0.0.2                                                      **
**                                                                            **
**  DATE         : 2019-07-25                                                 **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY :                                                            **
**                                                                            **
**  DESCRIPTION  : This file contains the mapping of Memory Section           **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) : Specification of DSADC Driver,                      **
**   AUTOSAR Release <4.2.2>                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/

/*
The name part {_safety} shall contain the safety integrity level with at most
one of the strings QM, ASIL_A, ASIL_B, ASIL_C, ASIL_D. In case of QM the
name part may be omitted.
The name part {_coreScope} shall contain the core scope qualification with at
most one of the strings GLOBAL, LOCAL. In case of GLOBAL the name part
may be omitted.
*/

#define MEMMAP_ERROR
#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))
/*DATA Section*/
/*To be used for all global or static variables.*/
/*Variable to be cleared at startup or reset is palced here - .bss*/
#if defined DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu0.32bit"
#pragma align 4
#elif defined _GNU_C_TRICORE_
#pragma section  "ClearedData.Cpu0.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu0.32bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.32bit" "ClearedData.Cpu0.32bit" far-absolute RW
#endif
#undef  DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR

#elif defined DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu0.8bit"
#elif defined _GNU_C_TRICORE_
#pragma section  "ClearedData.Cpu0.8bit" aw
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu0.8bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.8bit" "ClearedData.Cpu0.8bit" far-absolute RW
#endif
#undef  DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section farbss restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR

/******************* Config Data Sections *************************/
#elif defined DSADC_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#ifdef _TASKING_C_TRICORE_
#pragma section farrom "Config.Cpu0.Unspecified"
#pragma align 4
#elif defined _GNU_C_TRICORE_
#pragma section "Config.Cpu0.Unspecified" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Config.Cpu0.Unspecified"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Config.Cpu0.Unspecified" far-absolute R
#endif
#undef  DSADC_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined DSADC_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  DSADC_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR

/* Code Sections */
/*
To be used for mapping code to application block, boot block, external flash etc.
codePeriod is the typical period time value and unit of the ExecutableEntitys in this MemorySection.
The name part _{codePeriod} is optional. Units are:
- US microseconds
- MS milli second
- S second
*/
#elif defined DSADC_START_SEC_CODE_ASIL_B_LOCAL
#ifdef _TASKING_C_TRICORE_
#pragma section code "Code.Cpu0"
#elif defined _GNU_C_TRICORE_
#pragma section "Code.Cpu0" ax
#elif defined _GHS_C_TRICORE_
#pragma ghs section text  = ".Code.Cpu0"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CODE "Code.Cpu0" RX
#endif
#undef  DSADC_START_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR
#elif defined DSADC_STOP_SEC_CODE_ASIL_B_LOCAL
#ifdef _TASKING_C_TRICORE_
#pragma section code restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  DSADC_STOP_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR

#endif

#else  /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/ 
/***********************************EMPTY SECTIONS***********************************/
#if defined DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef  DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef  DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef  DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef  DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined DSADC_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef  DSADC_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined DSADC_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef  DSADC_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined DSADC_START_SEC_CODE_ASIL_B_LOCAL
#undef  DSADC_START_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR
#elif defined DSADC_STOP_SEC_CODE_ASIL_B_LOCAL
#undef  DSADC_STOP_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR
#endif

#endif /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/ 

#if defined MEMMAP_ERROR
#error "Dsadc_MemMap.h, wrong pragma command"
#endif
