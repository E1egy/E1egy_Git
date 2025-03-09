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
**  FILENAME  : Schm_Crc.c                                                    **
**                                                                            **
**  VERSION   : 1.0.0                                                         **
**                                                                            **
**  DATE      : 2018.10.15                                                    **
**                                                                            **
**  VARIANT   : Post-Build                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                 - Schm sections of CRC module - To be updated by user      **
**                                                                            **
**  SPECIFICATION(S) : Specification of CRC Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
#include "IFX_Os.h"
#include "Schm_Crc.h"

#ifdef LATENCY_CALC_CRC
#if(LATENCY_CALC_CRC==1U)
#include "Test_Latency.h"
#endif
#endif
void SchM_Enter_Crc_CriticalSection(void)
{
  SuspendAllInterrupts();
  #ifdef LATENCY_CALC_CRC
  #if(LATENCY_CALC_CRC==1U)
  Measure_Start_Value(0);
  #endif
  #endif
}

void SchM_Exit_Crc_CriticalSection(void)
{
  #ifdef LATENCY_CALC_CRC
  #if(LATENCY_CALC_CRC==1U)
  Measure_End_Value(0);
  #endif
  #endif
  ResumeAllInterrupts();
}
