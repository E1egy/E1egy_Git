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
**  FILENAME     : Det.h                                                      **
**                                                                            **
**  VERSION      : 0.1.0                                                      **
**                                                                            **
**  DATE         : 2017-01-10                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Det Driver header definition file                          **
**                                                                            **
**  SPECIFICATION(S) : Specification of Det Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/

#ifndef _DET_H
#define _DET_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#if (APP_SW == TEST_APP)
#include "Test_Det.h"
#endif /*#if (APP_SW == TEST_APP)*/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define DET_AR_RELEASE_MAJOR_VERSION 4U
#define DET_AR_RELEASE_MINOR_VERSION 2U
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
extern void Det_ReportError(uint16 ModuleId, uint8 InstanceId, \
                            uint8 ApiId, uint8 ErrorId);

extern void Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, \
                                   uint8 ApiId, uint8 ErrorId);
#endif /* End of _DET_H */


