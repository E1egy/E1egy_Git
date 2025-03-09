/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : DemoApp_FctCall.h                                             **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE      : 2012-03-12                                                    **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Aurix                                                         **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains the type defitions required for Demoapp **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
*******************************************************************************/
/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
**  VS          Vinod Shankar                                                 **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
********************************************************************************
**  V0.0.1: 2012-03-12,  VS:  Initial Version - AI00064361                    **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef  DEMOAPP_FCT_H
#define  DEMOAPP_FCT_H


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
typedef void (*demo_fct_type) (void);

/* definition of "any fct" types */
typedef  struct DemoApp_AnyFctListType
{
  const char    *fct_name;
  demo_fct_type fct_p;
  uint8         out_par;
  uint8         num_in_par;
  const uint8   *fct_in_par;
} DemoApp_AnyFctListType;

/* Definition of menu type */
typedef  struct DemoApp_FctListType
{
  const char    *fct_name;
  demo_fct_type fct_p;
  const char    *fct_desc;
} DemoApp_FctListType;

typedef  struct DemoApp_MenuType
{
  uint32    size;
  DemoApp_FctListType const *list;
} DemoApp_MenuType;

extern void DemoApp(void);
extern const DemoApp_AnyFctListType DemoApp_AllFctList[];
extern const uint32 DemoApp_AnyFctListSize;
 
#endif /* DEMOAPP_FCT_H */

