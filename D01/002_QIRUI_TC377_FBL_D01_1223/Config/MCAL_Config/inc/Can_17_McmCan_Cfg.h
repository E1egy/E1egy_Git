
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
**  FILENAME  : Can_17_McmCan_Cfg.h                                           **
**                                                                            **
**  VERSION   : 1.40.0_8.0.0                                                  **
**                                                                            **
**  DATE, TIME: 2023-02-27, 20:40:54          !!!IGNORE-LINE!!!               **
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


#ifndef CAN_17_MCMCAN_CFG_H
#define CAN_17_MCMCAN_CFG_H



/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
/* [cover parentID={7BE20AAE-30B8-46f5-ABBC-F2E65FBCEEE8}]
[/cover] */
#define CAN_17_MCMCAN_AR_RELEASE_MAJOR_VERSION          (4U)
/* [cover parentID={B0D7A378-F23B-4f83-86A7-50682CB089E5}]
[/cover] */
#define CAN_17_MCMCAN_AR_RELEASE_MINOR_VERSION          (2U)
/* [cover parentID={F34E3ADE-341D-4e08-9A3B-B454B00382E4}]
[/cover] */
#define CAN_17_MCMCAN_AR_RELEASE_REVISION_VERSION       (2U)

/* [cover parentID={98E1F5ED-AA8E-49af-8DBB-E84CD1B0960B}]
[/cover] */
#define CAN_17_MCMCAN_SW_MAJOR_VERSION                  (10U)
/* [cover parentID={EAB7012E-044A-4fb7-84E1-245B81493A73}]
[/cover] */
#define CAN_17_MCMCAN_SW_MINOR_VERSION                  (40U)
/* [cover parentID={4763C7E9-3BE5-4b3b-96DA-1E92B11A9191}]
[/cover] */
#define CAN_17_MCMCAN_SW_PATCH_VERSION                  (2U)
/*******************************************************************************
**          Global Macro Definitions                                          **
*******************************************************************************/

/* L-PDU receive callout support enabled or not */
#define CAN_17_MCMCAN_LPDU_RX_CALLOUT                    (STD_OFF)

/* Master core is allocated with CAN controllers */
#define CAN_17_MCMCAN_MASTER_CORE_ALLOCATION                       (STD_ON)

/* Multicore Enabled or not */
#define CAN_17_MCMCAN_MULTICORE_ERROR_DETECT                       (STD_OFF)

/* Maximum number of CAN Controllers configured in a ConfigSet */
#define CAN_17_MCMCAN_NOOF_CONTROLLER                       (uint8)(2U)

/* Maximum number of CAN Controllers configured in a ConfigSet for CORE0 */
#define CAN_17_MCMCAN_CORE0_NOOF_CONTROLLER      (uint8)(2U)

/* The number of hardware objects (includes Tx and Rx) configured in a
ConfigSet */
#define CAN_17_MCMCAN_NOOF_HARDWARE_OBJECTS          (Can_HwHandleType) (43U)

/* [cover parentID={22BF2529-8DA1-4094-9A12-F0EEFE184EF5}]
[/cover] */
/* Trigger transmit Enabled or not */
#define CAN_17_MCMCAN_TRIG_TRANSMIT                                 (STD_OFF)

/* Maximum number of main function RW periods configured in a ConfigSet */
#define CAN_17_MCMCAN_NOOF_RX_TX_PERIODS_CONFIG              (0U)

/* Multiple cycle period for Recieve is configured in a ConfigSet */
#define CAN_17_MCMCAN_RX_MULTI_PERIODS_SUPPORT               (STD_OFF)

/* Multiple cycle period for Transmit is configured in a ConfigSet */
#define CAN_17_MCMCAN_TX_MULTI_PERIODS_SUPPORT               (STD_OFF)


/* Initialization and De-Initilaization user mode configuration */
#define CAN_17_MCMCAN_INIT_DEINIT_API_MODE   (CAN_17_MCMCAN_MCAL_USER1)

/*******************************************************************************
**                      CAN General Information                               **
*******************************************************************************/
/* Configuration: CAN_17_MCMCAN_INSTANCE_ID
- Specifies the InstanceId of this module instance
*/
#define CAN_17_MCMCAN_INSTANCE_ID                     (0U)

/* Configuration: CAN_17_MCMCAN_DEV_ERROR_DETECT
- STD_ON  - DET is enabled
- STD_OFF - DET is disabled
*/
#define CAN_17_MCMCAN_DEV_ERROR_DETECT                            (STD_OFF)

/* Configuration: CAN_17_MCMCAN_VERSION_INFO_API
- STD_ON  - Can_17_McmCan_GetVersionInfo API is enabled
- STD_OFF - Can_17_McmCan_GetVersionInfo API is disabled
*/
#define CAN_17_MCMCAN_VERSION_INFO_API                            (STD_OFF)

/* Configuration: CAN_17_MCMCAN_MULTIPLEXED_TRANSMISSION
- STD_ON  - Multiplexed transmission feature is enabled
- STD_OFF - Multiplexed transmission feature is disabled
*/
#define CAN_17_MCMCAN_MULTIPLEXED_TRANSMISSION                    (STD_ON)

/* Configuration: CAN_17_MCMCAN_TIMEOUT_DURATION
- Specifies the maximum amount of time for a blocking function until
a time-out is raised in short term wait loops
*/
#define CAN_17_MCMCAN_TIMEOUT_DURATION                            (100000000U)

/* Configuration: CAN_17_MCMCAN_SET_BAUDRATE_API
- STD_ON  - Can_17_McmCan_SetBaudrate API is enabled
- STD_OFF - Can_17_McmCan_SetBaudrate API is Disabled
*/
#define CAN_17_MCMCAN_SET_BAUDRATE_API                           (STD_OFF)

/* Configuration: CanControllerFdBaudrateConfig
- STD_ON  - FD Operation is Enabled
- STD_OFF - FD Operation is Disabled
*/
#define CAN_17_MCMCAN_FD_ENABLE                                   (STD_ON)
/* Configuration: CAN_17_MCMCAN_DEINIT_API
- STD_ON  - CAN De-initialization API is enabled
- STD_OFF - CAN De-initialization API is not enabled
*/
#define CAN_17_MCMCAN_DEINIT_API                                  (STD_ON)

/* Configuration: CAN_17_MCMCAN_PUBLIC_ICOM_SUPPORT
- STD_ON  - CAN Pretended networking is enabled
- STD_OFF - CAN Pretended networking is not enabled
*/
#define CAN_17_MCMCAN_PUBLIC_ICOM_SUPPORT                         (STD_OFF)

/******************************************************************************/
/* CAN Controller Configurations */
/******************************************************************************/
/* CAN Activation on CORE0
- STD_ON  - A CAN Kernel is activated on Core 0
- STD_OFF - No CAN Kernel is activated on Core 0
*/
#define CAN_17_MCMCAN_CORE0_ACTIVATION                     (STD_ON)
/* CAN Activation on CORE1
- STD_ON  - A CAN Kernel is activated on Core 1
- STD_OFF - No CAN Kernel is activated on Core 1
*/
#define CAN_17_MCMCAN_CORE1_ACTIVATION                     (STD_OFF)
/* CAN Activation on CORE2
- STD_ON  - A CAN Kernel is activated on Core 2
- STD_OFF - No CAN Kernel is activated on Core 2
*/
#define CAN_17_MCMCAN_CORE2_ACTIVATION                     (STD_OFF)
/* CAN Activation on CORE3
- STD_ON  - A CAN Kernel is activated on Core 3
- STD_OFF - No CAN Kernel is activated on Core 3
*/
#define CAN_17_MCMCAN_CORE3_ACTIVATION                     (STD_OFF)
/* CAN Activation on CORE4
- STD_ON  - A CAN Kernel is activated on Core 4
- STD_OFF - No CAN Kernel is activated on Core 4
*/
#define CAN_17_MCMCAN_CORE4_ACTIVATION                     (STD_OFF)
/* CAN Activation on CORE5
- STD_ON  - A CAN Kernel is activated on Core 5
- STD_OFF - No CAN Kernel is activated on Core 5
*/
#define CAN_17_MCMCAN_CORE5_ACTIVATION                     (STD_OFF)

/*BusOff Processing Event used as Interrupt
- STD_ON - BusOff event is notified through Interrupt mechanism by the
configured controller
- STD_OFF - BusOff event is notified through Interrupt mechanism by the
configured controller
*/
#define CAN_17_MCMCAN_BO_INTERRUPT_PROCESSING                     (STD_ON)

/* Transmission Processing Event used as Interrupt
- STD_ON - Transmission event is notified through Interrupt mechanism by the
configured controller
- STD_OFF - Transmission event is notified through Interrupt mechanism by the
configured controller
*/
#define CAN_17_MCMCAN_TX_INTERRUPT_PROCESSING                     (STD_ON)

/* Reception Processing Event used as Interrupt
- STD_ON - Reception event is notified through Interrupt mechanism by the
configured controller
- STD_OFF - Reception event is notified through Interrupt mechanism by the
configured controller
*/
#define CAN_17_MCMCAN_RX_INTERRUPT_PROCESSING                     (STD_ON)

/*BusOff Processing Event used as POLLING
- STD_ON - BusOff event is notified through Polling mechanism by the
configured controller
- STD_OFF - BusOff event is notified through Polling mechanism by the
configured controller
*/
#define CAN_17_MCMCAN_BO_POLLING_PROCESSING                       (STD_OFF)

/* Transmission Processing Event used as POLLING
- STD_ON - Transmission event is notified through Polling mechanism by the
configured controller
- STD_OFF - Transmission event is notified through Polling mechanism by the
configured controller
*/
#define CAN_17_MCMCAN_TX_POLLING_PROCESSING                       (STD_OFF)

/* Reception Processing Event used as POLLING
- STD_ON - Reception event is notified through Polling mechanism by the
configured controller
- STD_OFF - Reception event is notified through Polling mechanism by the
configured controller
*/
#define CAN_17_MCMCAN_RX_POLLING_PROCESSING                       (STD_OFF)

/* WakeUp Processing Event used as POLLING
- STD_ON - WakeUp event is notified through Polling mechanism by the
configured controller
- STD_OFF - WakeUp event is notified through Polling mechanism by the
configured controller
*/
#define CAN_17_MCMCAN_WU_POLLING_PROCESSING                       (STD_OFF)

/* Controller Handle Id */

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanController_CanController_TEST_CAN             0

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanController_CanController_CAN1_FD             1

/* Hardware object Handle Id */

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ScrToECAS         0

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_XCP_Master_0x601         1

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_CANBOOT_Private_Master         2

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_Req         3

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_Diag_FuncReq         4

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_Diag_PhyReq         5

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_EPB_State_R         6

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_EPS_State         7

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_IPB_ADS         8

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_IPB_State1         9

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_IPB_Tq         10

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_IPB_Wheel         11

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_TBOX_TimeInfo         12

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_VIU_DoorLock         13

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_VIU_Info         14

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_VIU_Route_SUS         15

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_VDC_FMtTq         16

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_TBOX_NM         17

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_VDC_PTSt         18

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_VDC_RMtTq         19

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ABM_State         20

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ADS_ECAS         21

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ADS_State         22

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_VDC_CDCSet         23

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_VIU_Config         24

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_VIU_ConfigTrig         25

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_VDC_VIU_BodyInfo         26

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECASToScr         27

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_XCP_Slave_0x60f         28

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_CANBOOT_Private_Slave         29

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_Height         30

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_AccSensor_TEMP         31

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_CDC_PRESS         32

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_VALVE_VERSION         33

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_VOLTAGE         34

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_DV_BA_SYS         35

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_EDC_Test         36

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_NM         37

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_RemoteDiag         38

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_State         39

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_Diag_Resp         40

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_EDC_RemoteDiag         41

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_ECAS_EDC_State         42

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

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/


#endif  /* CAN_17_MCMCAN_CFG_H */
