
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
**  FILENAME  : Can_17_McmCan_PBCfg.c                                         **
**                                                                            **
**  VERSION   : 1.40.0_21.0.0                                                 **
**                                                                            **
**  DATE, TIME: 2023-02-27, 18:30:19          !!!IGNORE-LINE!!!               **
**                                                                            **
**  GENERATOR : Build b170330-0431            !!!IGNORE-LINE!!!               **
**                                                                            **
**  BSW MODULE DECRIPTION : Can_17_McmCan.bmd                                 **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Can configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Can Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include CAN Driver Header File */
#include "Can_17_McmCan.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
               Can Controller Configurations for Core0
********************************************************************************
    { Can node Base Address,Combination value of Rx pin select and
    Loopback mode Support,{First Tx Hardware Object, No.of Tx Hardware Objects,
    First Rx Standard Hardware Object, No.of Rx Standard Hardware Objects,
    First Rx Extended Hardware Object, No.of Rx Extended Hardware Objects},
    Default baudrate Config index,First baudrate index for the controller,
    No.of baudrate configuration,Associated kernel Id, Controller Hw Id,
    Logical controller Id,[FD support status] }
********************************************************************************
       Note: [1] The configuration shall be generated only for the activated
                 controller
             [2] The Generation of FD support status Shall be enabled only if
             atleast one of the baudrates configured in the configuration set is
             FD.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerConfigType \
  Can_17_McmCan_kControllerConfigCore0[2] =
{
  {
    /* Can controller Base Node address */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Node structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN_N*)0xf0208500U,
    /* combination of Loopback and receive input pin selection setting */
    0x1U,
    /* The controller Hw object configuration mapping information */
    {
      /* Tx Message storage start Index */
      0x0U,
      /* Total no of Tx Message configured */
      0x3U,
      /* Rx Message SID filter mask start Index */
      0x0U,
      /* Total no of SID filter mask configured */
      0x3U,
      /* Rx Message XID filter mask start Index */
      0x0U,
      /* Total no of XID filter mask configured */
      0x0U
    },
    /* Default baudrate configuration Index */
    0x0U,
    /* Start index value of Baudrate configuration */
    0x0U,
    /* Total no of Baudrate configuration */
    0x1U,
    /* The controller Associated Kernel configuration Index */
    0x0U,
    /* The CAN controller Hw Index */
    0x01U,
    /* The CAN controller Logical Hw Index - Controller ID defined by user */
    0,
    /* FD support status of the controller */
    TRUE
  },
  {
    /* Can controller Base Node address */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Node structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN_N*)0xf0218100U,
    /* combination of Loopback and receive input pin selection setting */
    0x2U,
    /* The controller Hw object configuration mapping information */
    {
      /* Tx Message storage start Index */
      0x3U,
      /* Total no of Tx Message configured */
      0xdU,
      /* Rx Message SID filter mask start Index */
      0x3U,
      /* Total no of SID filter mask configured */
      0x18U,
      /* Rx Message XID filter mask start Index */
      0x0U,
      /* Total no of XID filter mask configured */
      0x0U
    },
    /* Default baudrate configuration Index */
    0x1U,
    /* Start index value of Baudrate configuration */
    0x1U,
    /* Total no of Baudrate configuration */
    0x1U,
    /* The controller Associated Kernel configuration Index */
    0x1U,
    /* The CAN controller Hw Index */
    0x00U,
    /* The CAN controller Logical Hw Index - Controller ID defined by user */
    1,
    /* FD support status of the controller */
    TRUE
  }
};

/*******************************************************************************
              Controller Id to Index Map configuration for Core0
********************************************************************************
    {Array holding the respective logical Controller ID at the core specific
    controller index }
********************************************************************************
           Note: This shall be generated only for the controllers allocated
           for the current core.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerIndexType \
  Can_17_McmCan_kControllerIndexingCore0[2] =
{0,1};

/*******************************************************************************
              Message RAM partition configuration for Core0
********************************************************************************
      {{start address of SID section,start address of XID section,
      start address of FIFO0 section,start address of FIFO1 section,start
      address of Rx dedicated buffer section,start address of Tx Event section,
      start address of Tx dedicated buffer section},Tx_ded_Buff size,
      Tx_Evnt size,[Rx_FIFO0 size],[Rx_FIFO0 Threshold],[Rx_FIFO1 size],
      [Rx_FIFO1 Threshold],[Tx_Queue size],[Tx_Queue Enable Status]}
********************************************************************************
           Note: This shall be generated only for the activated controller
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerMsgRAMConfigType \
  Can_17_McmCan_kControllerMsgRAMMapConfigCore0[2] =
{
  {
    /* Start Address of each section within the Message RAM */
    {
      0xf0200000UL,
      0x00000000UL,
      0x00000000UL,
      0x00000000UL,
      0xf020000cUL,
      0xf02000e4UL,
      0xf02000fcUL
    },
    0x3U,
    0x3U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
    FALSE
  },
  {
    /* Start Address of each section within the Message RAM */
    {
      0xf0210000UL,
      0x00000000UL,
      0xf0210060UL,
      0xf0210180UL,
      0xf02102a0UL,
      0xf02108d0UL,
      0xf0210938UL
    },
    0xdU,
    0xdU,
    0x4U,
    0x1U,
    0x4U,
    0x1U,
    0x0U,
    FALSE
  }
};

/*******************************************************************************
            CAN Controller Baudrate Configurations for Core0
********************************************************************************
           { CANx_NBTP value, Configured Baudrate ,FDBaudrate config Index ,
             FD Support Status  }
********************************************************************************
                           Baudrate Setting
    (uint32)((NSJW << 25)|(NBRP << 16)|(TSEG1 << 8)|(TSEG2))
    NSJW   -> CanControllerSyncJumpWidth - 1
    NTSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1
    NTSEG2 -> CanControllerSeg2 - 1
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerBaudrateConfigType \
  Can_17_McmCan_kBaudrateConfigCore0[2] =
{
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* NBRP   -> 0 */
    /* NSJW   -> 3  */
    /* NTSEG1 -> 62  */
    /* NTSEG2 -> 15  */
    0x6003e0fU,
    500U,
    0x0U,
    TRUE
  },
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* NBRP   -> 0 */
    /* NSJW   -> 3  */
    /* NTSEG1 -> 62  */
    /* NTSEG2 -> 15  */
    0x6003e0fU,
    500U,
    0x1U,
    TRUE
  }
};

/*******************************************************************************
                CAN Controller FD Config Parameters for Core0
********************************************************************************
           { CANx_DBTP value, TrcvDelayCompensationOffset, BRS Status }
********************************************************************************

        (uint32)((DBRP << 16)|(DTSEG1 << 8)|(DTSEG2 << 4)|(DSJW ))
        DSJW   -> CanControllerSyncJumpWidth - 1
        DTSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1
        DTSEG2 -> CanControllerSeg2 - 1
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerFDBaudrateConfigType \
  Can_17_McmCan_kFDBaudrateConfigCore0[2] =
{
  {
    /* Configured FD Baudrate -> 2000 kbps */
    /* Actual Baudrate     -> 2000.0 kbps */
    /* DBRP   -> 0 */
    /* DSJW   -> 3  */
    /* DTSEG1 -> 14  */
    /* DTSEG2 -> 3  */
    0xe33U,
    0x0U,
    TRUE
  },
  {
    /* Configured FD Baudrate -> 2000 kbps */
    /* Actual Baudrate     -> 2000.0 kbps */
    /* DBRP   -> 0 */
    /* DSJW   -> 3  */
    /* DTSEG1 -> 14  */
    /* DTSEG2 -> 3  */
    0xe33U,
    0x0U,
    TRUE
  }
};

/*******************************************************************************
    CAN Controller Handling of Events for Core0 : Interrupt/Polling
********************************************************************************
        { CanTxProcessing Mode, CanRxProcessing Mode,
          CanBusoffProcessing Mode, CanWakeupProcessing Mode }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/
/* CanConfigSet -> CAN Controller - Handling of Events */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_EventHandlingType \
  Can_17_McmCan_kEventHandlingConfigCore0[2] =
{
  {
    {
      (CAN_17_MCMCAN_INTERRUPT),
      (CAN_17_MCMCAN_INTERRUPT),
      (CAN_17_MCMCAN_INTERRUPT),
      (CAN_17_MCMCAN_INTERRUPT)
    }
  },
  {
    {
      (CAN_17_MCMCAN_INTERRUPT),
      (CAN_17_MCMCAN_INTERRUPT),
      (CAN_17_MCMCAN_INTERRUPT),
      (CAN_17_MCMCAN_INTERRUPT)
    }
  }
};
/*******************************************************************************
               Receive Hardware Object Configurations for Core0
********************************************************************************
        This is the combination of SID filter elements
        Rx Object -> { Combination of Mask and filter value S0, HRH HwObject Id,
        Hw Controller Id, Rx BufferType, [Pretended Support Status] }
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   Hw Controller Id -> 255
             [2] If CanFilterMaskRef is not configured then,
                   Mask -> 0x7ff - for STANDARD Msg Id Type
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_SIDFilterConfigType \
  Can_17_McmCan_kSIDFilterConfigCore0[27] =
{
  {
    0xb80a0000U,
    0U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbe010001U,
    1U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbf650002U,
    2U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbea10000U,
    3U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbfdf0001U,
    4U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0x8f2b07ffU,
    5U,
    1U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0xb9960003U,
    6U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9140004U,
    7U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9950005U,
    8U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9920006U,
    9U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9160007U,
    10U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9120008U,
    11U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbde20009U,
    12U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbab0000aU,
    13U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9d2000bU,
    14U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbb4b000cU,
    15U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb915000dU,
    16U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0x94000780U,
    17U,
    1U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0xb91b000fU,
    18U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9130010U,
    19U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9190011U,
    20U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9340012U,
    21U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbb2a0013U,
    22U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbbf00014U,
    23U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbb9a0015U,
    24U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb8b00016U,
    25U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbbb50017U,
    26U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  }
};
/*******************************************************************************
           Transmit Hardware Object Configurations for Core0
********************************************************************************
 Tx Object -> { CanTxHwObjId, CanTxBuffIndx, HwControllerId, [CanFdPaddValue],
               CanTxHwObjIdType , CanTxBufferType, CanTrigTxStatus}
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   this shall not be generated.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_TxHwObjectConfigType \
  Can_17_McmCan_kTxHwObjectConfigCore0[16] =
{
  {
    27U,
    0U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    28U,
    1U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    29U,
    2U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    30U,
    0U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    31U,
    1U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    32U,
    2U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    33U,
    3U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    34U,
    4U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    35U,
    5U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    36U,
    6U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    37U,
    7U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    38U,
    8U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    39U,
    9U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    40U,
    10U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    41U,
    11U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  },
  {
    42U,
    12U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER
  }
};

/******************************************************************************/
             /* CAN Configuration Pointer for Core0 */
/******************************************************************************/
    /* Core sepcific CAN configurations */
/******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_CoreConfigType \
  Can_17_McmCan_kMcmCanConfigCore0=
{
  /* Number of controllers configured for the core */
  2,
  /* Array of all the controllers configured */
  &Can_17_McmCan_kControllerIndexingCore0[0],
  /* Pointer to CAN controller configuration settings */
  &Can_17_McmCan_kControllerConfigCore0[0],
  /* Pointer to Message RAM configuration settings */
  &Can_17_McmCan_kControllerMsgRAMMapConfigCore0[0],
  /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
  &Can_17_McmCan_kEventHandlingConfigCore0[0],
  /* Pointer to Baudrate configuration settings */
  &Can_17_McmCan_kBaudrateConfigCore0[0],
  /* Pointer to FDBaudrate configuration settings */
  &Can_17_McmCan_kFDBaudrateConfigCore0[0],
  /* Pointer to CAN Controller <-> Tx Hardware Objects Mapping */
  &Can_17_McmCan_kTxHwObjectConfigCore0[0],
  /* Pointer to CAN Controller <-> Rx Hardware Objects Mapping for Standard
     messages */
  &Can_17_McmCan_kSIDFilterConfigCore0[0],
  /* Pointer to CAN Controller <-> Rx Hardware Objects Mapping for Extended
  messages */
  NULL_PTR
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
              CAN Kernel configuration parameters
********************************************************************************
     { CAN Global Kernel Address, The status of the nodes in the configured
     kernel }
********************************************************************************
           Note: 1. If any of CAN controllers in the kernel is not activated
                 then, the configuration for that kernel will not be generated.
                 2. CAN controllers that are activated in the kernel will be
                 set to True state and the pending controller nodes shall be
                 set to False state.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_McmModuleConfigType \
  Can_17_McmCan_kMcmCanModuleConfig[2] =
{
  {
    /* The Global Base address of Kernel module */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Kernel structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN*) 0xf0200000U,
    /* The CAN node is enabled or not within the kernel*/
    {
      /* Node 0 of kernel enable state */
      FALSE,
      /* Node 1 of kernel enable state */
      TRUE,
      /* Node 2 of kernel enable state */
      FALSE,
      /* Node 3 of kernel enable state */
      FALSE
    }
  },
  {
    /* The Global Base address of Kernel module */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Kernel structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN*) 0xf0210000U,
    /* The CAN node is enabled or not within the kernel*/
    {
      /* Node 0 of kernel enable state */
      TRUE,
      /* Node 1 of kernel enable state */
      FALSE,
      /* Node 2 of kernel enable state */
      FALSE,
      /* Node 3 of kernel enable state */
      FALSE
    }
  }
};
/*******************************************************************************
              Overall CAN Hth Indexing Configuration
********************************************************************************
     { Hth handle Core assignment, Hth handle logical index (HOH ID),
     Hth handle core specific index}
********************************************************************************
           Note: 1. If there are no Transmit objects configured, this structure
           shall not be generated.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_HthIndexType \
  Can_17_McmCan_kMcmCanHthIndexConfig[16] =
{
  {0,0,0},
  {0,0,1},
  {0,0,2},
  {0,1,3},
  {0,1,4},
  {0,1,5},
  {0,1,6},
  {0,1,7},
  {0,1,8},
  {0,1,9},
  {0,1,10},
  {0,1,11},
  {0,1,12},
  {0,1,13},
  {0,1,14},
  {0,1,15}
};
/*******************************************************************************
              Overall CAN Logical Controller Indexing Configuration
********************************************************************************
     { CAN Controller Core assignment, CAN logical indexing indicating the core
       specific indexing,Physical node index and kernel index}
********************************************************************************
           Note:
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_LogicalControllerIndexType \
  Can_17_McmCan_kMcmCanLogicContIndexConfig[2] =
{
  {0,0,1,0},
  {0,1,0,1}
};
/******************************************************************************/
        /* Overall Physical CAN Controller Indexing Configuration */
/******************************************************************************/
      /* Physical CAN indexing indicating the Logical controller ID,
         Core specific controller ID and Core assignment.
         This has a constant array size of 12
         i.e.(PhyKernelID * No of Node in kernel)+(PhyNodeID)*/
/******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_PhyControllerIndexType \
  Can_17_McmCan_kMcmCanPhyContIndexConfig[8] =
{
  {255,255,255},
  {0,0,0},
  {255,255,255},
  {255,255,255},
  {1,1,0},
  {255,255,255},
  {255,255,255},
  {255,255,255}
};
/******************************************************************************/
                  /* Overall CAN Configuration */
/******************************************************************************/
      /* Over all CAN configurations, structure that points to one of the
           configuration is passed as parameter to Can_Init API */
/******************************************************************************/

/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
   declaration as per Autosar guidelines. This data structure may be needed
   by SW units using CAN Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */
const Can_17_McmCan_ConfigType \
  Can_17_McmCan_Config=
{
  /********************* Core specific configuration set **********************/

  /* Pointer to the Core specific CAN configuration set */
  {
    &Can_17_McmCan_kMcmCanConfigCore0,
    NULL_PTR,
    NULL_PTR
  },
  /****************** Global data shared amongst all cores ********************/

  /* Number of Kernels configured */
  2,
  /* Number of Hrh configured */
  27,
  /* Pointer to CAN Kernel configuration */
  &Can_17_McmCan_kMcmCanModuleConfig[0],
  /* Pointer holding physical controller index data */
  &Can_17_McmCan_kMcmCanPhyContIndexConfig[0],
  /* Pointer holding logical controller index data */
  &Can_17_McmCan_kMcmCanLogicContIndexConfig[0],
  /* Pointer holding configured Hth index data */
  &Can_17_McmCan_kMcmCanHthIndexConfig[0]};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
