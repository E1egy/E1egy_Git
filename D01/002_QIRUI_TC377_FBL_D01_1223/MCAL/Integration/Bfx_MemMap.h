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
**  FILENAME     : Bfx_MemMap.h                                               **
**                                                                            **
**  VERSION   :  <to be filled>                                               **
**                                                                            **
**  DATE         : 2018-06-28                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  TRACEABILITY :                                                            **
**                                                                            **
**  DESCRIPTION  : This file contains the mapping of Memory Section           **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) : Specification of BFX Driver,                           **
**                     AUTOSAR Release <4.2.2>                                **
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

/********************************CODE SECTION ********************************/
/*
To be used for mapping code to application block, boot block, external flash
etc.
{codePeriod} is the typical period time value and unit of the ExecutableEntitys
in this MemorySection. The name part _{codePeriod} is optional. Units are:
- US microseconds
- MS milli second
- S second
For example: 100US, 400US, 1MS, 5MS, 10MS, 20MS, 100MS, 1S
*/
#if defined BFX_START_SEC_CODE_ASIL_B_GLOBAL
/* your Pragma start here */
#ifdef _TASKING_C_TRICORE_
#pragma section code "Code.Cpu0"
#elif defined _GNU_C_TRICORE_
#pragma section "Code.Cpu0" ax
#elif defined _GHS_C_TRICORE_
#pragma ghs section text = ".Code.Cpu0"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CODE "Code.Cpu0" RX
#endif
/* your Pragma here */
#undef BFX_START_SEC_CODE_ASIL_B_GLOBAL
#undef MEMMAP_ERROR

#elif defined BFX_STOP_SEC_CODE_ASIL_B_GLOBAL
/* your Pragma start here */
#ifdef _TASKING_C_TRICORE_
#pragma section code restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section
#endif
/* your Pragma end here */
#undef BFX_STOP_SEC_CODE_ASIL_B_GLOBAL
#undef MEMMAP_ERROR

#endif

#else /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/

/************************EMPTY SECTIONS***************************************/
/*
To be used for mapping code to application block, boot block, external flash
etc.
{codePeriod} is the typical period time value and unit of the ExecutableEntitys
in this MemorySection. The name part _{codePeriod} is optional. Units are:
- US microseconds
- MS milli second
- S second
For example: 100US, 400US, 1MS, 5MS, 10MS, 20MS, 100MS, 1S
*/
#if defined BFX_START_SEC_CODE_ASIL_B_GLOBAL

#undef BFX_START_SEC_CODE_ASIL_B_GLOBAL
#undef MEMMAP_ERROR

#elif defined BFX_STOP_SEC_CODE_ASIL_B_GLOBAL

#undef BFX_STOP_SEC_CODE_ASIL_B_GLOBAL
#undef MEMMAP_ERROR

#endif

#endif /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/

#if defined MEMMAP_ERROR
#error "BFX_MemMap.h, wrong pragma command"
#endif
