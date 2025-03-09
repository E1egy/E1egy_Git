
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2019)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Dio_Lcfg.c                                                    **
**                                                                            **
**  VERSION   : 1.30.0_6.0.0                                                  **
**                                                                            **
**  DATE, TIME: 2023-03-22, 13:06:08       !!!IGNORE-LINE!!!                  **
**                                                                            **
**  GENERATOR : Build b170330-0431           !!!IGNORE-LINE!!!                **
**                                                                            **
**  BSW MODULE DECRIPTION : Dio.bmd                                           **
**                                                                            **
**  VARIANT   : Variant LT                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Dio configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Dio Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


    
  /*******************************************************************************
  **                             Includes                                       **
  *******************************************************************************/

  /* Include Port Module File */
  #include "Dio.h"

  /*******************************************************************************
  **                      Private Macro Definitions                             **
  *******************************************************************************/

  /*******************************************************************************
  **                      Global Constant Definitions                           **
  *******************************************************************************/
  
  /* Memory mapping of the DIO configuration */
  #define DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  /* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines 
  Dio_Memmap.h header is included without safegaurd.*/
  #include "Dio_MemMap.h"
  /*
      Configuration of DIO Channel groups 
  */
          
    
/* No Groups are configured */

    
  static const Dio_PortChannelIdType Dio_kPortChannelConfig[] =
  { 
    {
    /* Port0*/
      DIO_PORT_CONFIGURED,
      (0x0048U)
    },
    {
    /* Port1*/
      DIO_PORT_CONFIGURED,
      (0x0018U)
    },
    {
    /* Port2*/
      DIO_PORT_CONFIGURED,
      (0x0e00U)
    },
    {
    /* Port10*/
      DIO_PORT_CONFIGURED,
      (0x0005U)
    },
    {
    /* Port11*/
      DIO_PORT_CONFIGURED,
      (0x1e00U)
    },
    {
    /* Port12*/
      DIO_PORT_CONFIGURED,
      (0x0003U)
    },
    {
    /* Port13*/
      DIO_PORT_CONFIGURED,
      (0x000fU)
    },
    {
    /* Port14*/
      DIO_PORT_CONFIGURED,
      (0x0540U)
    },
    {
    /* Port15*/
      DIO_PORT_CONFIGURED,
      (0x0010U)
    },
    {
    /* Port20*/
      DIO_PORT_CONFIGURED,
      (0x0200U)
    },
    {
    /* Port21*/
      DIO_PORT_CONFIGURED,
      (0x0013U)
    },
    {
    /* Port22*/
      DIO_PORT_CONFIGURED,
      (0x0005U)
    },
    {
    /* Port23*/
      DIO_PORT_CONFIGURED,
      (0x00fcU)
    },
    {
    /* Port32*/
      DIO_PORT_CONFIGURED,
      (0x00fcU)
    },
    {
    /* Port33*/
      DIO_PORT_CONFIGURED,
      (0x3fefU)
    },
    {
    /* Port34*/
      DIO_PORT_NOT_CONFIGURED,
      (0x0000U)
    },
    {
    /* Port40*/
      DIO_PORT_NOT_CONFIGURED,
      (0x0000U)
    }
  };
    const Dio_ConfigType Dio_Config =
    {
                
      /* Dio Port and Channelconfiguration */
            &Dio_kPortChannelConfig[0],
      /* Dio Channelgroup configuration */
      
      NULL_PTR,
      /* Configured number of Dio Channelgroups for configuration */
      DIO_CHANNELGROUPCOUNT
    };
  #define DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    /* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines 
    Dio_Memmap.h header is included without safegaurd.*/
    /* MISRA2012_RULE_20_1_JUSTIFICATION: Dio_Memmap.h header included as per Autosar 
    guidelines. */
  #include "Dio_MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
