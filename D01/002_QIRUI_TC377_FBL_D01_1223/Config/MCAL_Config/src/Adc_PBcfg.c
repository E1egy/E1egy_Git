/*****************************************************************************
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
**  FILENAME  : Adc_PBcfg.c                                                   **
**                                                                            **
**  VERSION   : 8.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2022-10-27, 12:12:49            !!!IGNORE-LINE!!!             **
**                                                                            **
**  GENERATOR : Build b170330-0431              !!!IGNORE-LINE!!!             **
**                                                                            **
**  BSW MODULE DECRIPTION : Adc.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION :  Adc configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of ADC Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of module header file */
#include "Adc.h"

/***********Configuration for External HW trigger and gating signals***********/
/*Gtm Trigger Configuration for SysVoltage of HW Unit 0 */
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

static const Mcu_17_Gtm_TomAtomChConfigType Adc_kHwUnit0GrpSysVoltageGtmTrig_Config=
{
  MCU_GTM_TIMER_TOM, /*GTM_TOM Timer Type Used*/
  0x00000006U, /* Timer ID */
  0x00001800U, /*Control Register Value for GTM_TOM_0 */
  0x00000000U, /*CN0 Register value*/
  0x0000186aU, /*CM0 register value*/
  0x00000c35U, /*CM1 register value*/
  0x0000186aU, /*SR0 register value*/
  0x00000c35U, /*SR1 register value*/
  0U, /*Timer Channel output Config*/
  0x00U /*Interrupt Enable and Interrupt Mode values*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*Gtm Trigger Configuration for PWMVol of HW Unit 1 */
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

static const Mcu_17_Gtm_TomAtomChConfigType Adc_kHwUnit1GrpPWMVolGtmTrig_Config=
{
  MCU_GTM_TIMER_TOM, /*GTM_TOM Timer Type Used*/
  0x00000007U, /* Timer ID */
  0x00000800U, /*Control Register Value for GTM_TOM_0 */
  0x00000000U, /*CN0 Register value*/
  0x000005dcU, /*CM0 register value*/
  0x000002eeU, /*CM1 register value*/
  0x000005dcU, /*SR0 register value*/
  0x000002eeU, /*SR1 register value*/
  0U, /*Timer Channel output Config*/
  0x00U /*Interrupt Enable and Interrupt Mode values*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*Gtm Trigger Configuration for Enviro_Current of HW Unit 2 */
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

static const Mcu_17_Gtm_TomAtomChConfigType Adc_kHwUnit2GrpEnviro_CurrentGtmTrig_Config=
{
  MCU_GTM_TIMER_TOM, /*GTM_TOM Timer Type Used*/
  0x0000000dU, /* Timer ID */
  0x00000800U, /*Control Register Value for GTM_TOM_0 */
  0x00000000U, /*CN0 Register value*/
  0x0000060eU, /*CM0 register value*/
  0x00000307U, /*CM1 register value*/
  0x0000060eU, /*SR0 register value*/
  0x00000307U, /*SR1 register value*/
  0U, /*Timer Channel output Config*/
  0x00U /*Interrupt Enable and Interrupt Mode values*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*Gtm Trigger Configuration for HighSensor of HW Unit 8 */
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

static const Mcu_17_Gtm_TomAtomChConfigType Adc_kHwUnit8GrpHighSensorGtmTrig_Config=
{
  MCU_GTM_TIMER_TOM, /*GTM_TOM Timer Type Used*/
  0x0000000eU, /* Timer ID */
  0x00000800U, /*Control Register Value for GTM_TOM_0 */
  0x00000000U, /*CN0 Register value*/
  0x00000c1cU, /*CM0 register value*/
  0x0000060eU, /*CM1 register value*/
  0x00000c1cU, /*SR0 register value*/
  0x0000060eU, /*SR1 register value*/
  0U, /*Timer Channel output Config*/
  0x00U /*Interrupt Enable and Interrupt Mode values*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*******************Group Definition - Channel Sequence*******************/

/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

static const Mcu_17_Gtm_TomAtomChConfigType Adc_kHwUnit3GrpSensor_diagGtmTrig_Config=
{
  MCU_GTM_TIMER_TOM, /*GTM_TOM Timer Type Used*/
  0x00000106U, /* Timer ID */
  0x00001800U, /*Control Register Value for GTM_TOM_1 */
  0x00000000U, /*CN0 Register value*/
  0x0000061aU, /*CM0 register value*/
  0x0000030dU, /*CM1 register value*/
  0x0000061aU, /*SR0 register value*/
  0x0000030dU, /*SR1 register value*/
  0U, /*Timer Channel output Config*/
  0x00U /*Interrupt Enable and Interrupt Mode values*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*******************Group Definition - Channel Sequence*******************/

/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of SysVoltage- ID0 of HW Unit 0 */
static const Adc_GroupDefType Adc_kHwUnit0GrpSysVoltage_Config[8]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/
  {  0U,                   0U,                0U  },
  {  1U,                   1U,                1U  },
  {  2U,                   2U,                2U  },
  {  3U,                   3U,                3U  },
  {  4U,                   4U,                4U  },
  {  5U,                   5U,                5U  },
  {  6U,                   6U,                6U  },
  {  7U,                   7U,                7U  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of PWMVol- ID32 of HW Unit 1 */
static const Adc_GroupDefType Adc_kHwUnit1GrpPWMVol_Config[8]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/
  {  0U,                   0U,                0U  },
  {  1U,                   1U,                1U  },
  {  2U,                   2U,                2U  },
  {  3U,                   3U,                3U  },
  {  4U,                   4U,                4U  },
  {  5U,                   5U,                5U  },
  {  6U,                   6U,                6U  },
  {  7U,                   7U,                7U  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of Enviro_Current- ID64 of HW Unit 2 */
static const Adc_GroupDefType Adc_kHwUnit2GrpEnviro_Current_Config[4]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/
  {  0U,                   4U,                0U  },
  {  1U,                   5U,                1U  },
  {  2U,                   6U,                2U  },
  {  3U,                   7U,                3U  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of HighSensor- ID256 of HW Unit 8 */
static const Adc_GroupDefType Adc_kHwUnit8GrpHighSensor_Config[4]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/
  {  0U,                   8U,                0U  },
  {  1U,                   9U,                1U  },
  {  2U,                   10U,                2U  },
  {  3U,                   11U,                3U  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of Sensor_diag- ID96 of HW Unit 3 */
static const Adc_GroupDefType Adc_kHwUnit3GrpSensor_diag_Config[8]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/
  {  0U,                   0U,                0U  },
  {  1U,                   1U,                1U  },
  {  2U,                   2U,                2U  },
  {  3U,                   3U,                3U  },
  {  4U,                   4U,                4U  },
  {  5U,                   5U,                5U  },
  {  6U,                   6U,                6U  },
  {  7U,                   7U,                7U  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/***********************Group Configuration Definition***********************/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 0 ******/
static const Adc_GroupCfgType Adc_kHwUnit0Grp_Config[1]=
{

  {/*Group Configuration structure for SysVoltage - ID0*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_HW
      Trigger Edge: ADC_HW_TRIG_RISING_EDGE
      HW Trigger Source: ADC_TRIG_8_GxREQTRI_GTM_ADCx_TRIG0
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    (Adc_NotifyFnPtrType)0U,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit0GrpSysVoltage_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)&Adc_kHwUnit0GrpSysVoltageGtmTrig_Config,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G0QCTRL register*/
    0x00004800U,
    /*Configuration value for the G0QMR register*/
    0x00000005U,
    /*Configuration value for the G0ALIAS register*/
    0x00000100U,
    /* Configuration value for G0REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x00ffU,
    /*Bit Mask for all the result registers configured for the group*/
    0x00ffU,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_HW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_GTM_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    8U, /*Channel Count for the group*/
    0U /*Limit Check enabled for the group*/
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 1 ******/
static const Adc_GroupCfgType Adc_kHwUnit1Grp_Config[1]=
{

  {/*Group Configuration structure for PWMVol - ID32*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_HW
      Trigger Edge: ADC_HW_TRIG_RISING_EDGE
      HW Trigger Source: ADC_TRIG_8_GxREQTRI_GTM_ADCx_TRIG0
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    (Adc_NotifyFnPtrType)0U,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit1GrpPWMVol_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)&Adc_kHwUnit1GrpPWMVolGtmTrig_Config,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G1QCTRL register*/
    0x00004800U,
    /*Configuration value for the G1QMR register*/
    0x00000005U,
    /*Configuration value for the G1ALIAS register*/
    0x00000100U,
    /* Configuration value for G1REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x00ffU,
    /*Bit Mask for all the result registers configured for the group*/
    0x00ffU,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_HW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_GTM_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    8U, /*Channel Count for the group*/
    0U /*Limit Check enabled for the group*/
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 2 ******/
static const Adc_GroupCfgType Adc_kHwUnit2Grp_Config[1]=
{

  {/*Group Configuration structure for Enviro_Current - ID64*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_HW
      Trigger Edge: ADC_HW_TRIG_RISING_EDGE
      HW Trigger Source: ADC_TRIG_8_GxREQTRI_GTM_ADCx_TRIG0
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    (Adc_NotifyFnPtrType)0U,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit2GrpEnviro_Current_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)&Adc_kHwUnit2GrpEnviro_CurrentGtmTrig_Config,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G2QCTRL register*/
    0x00004800U,
    /*Configuration value for the G2QMR register*/
    0x00000005U,
    /*Configuration value for the G2ALIAS register*/
    0x00000100U,
    /* Configuration value for G2REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x00f0U,
    /*Bit Mask for all the result registers configured for the group*/
    0x000fU,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_HW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_GTM_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    4U, /*Channel Count for the group*/
    0U /*Limit Check enabled for the group*/
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 8 ******/
static const Adc_GroupCfgType Adc_kHwUnit8Grp_Config[1]=
{

  {/*Group Configuration structure for HighSensor - ID256*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_HW
      Trigger Edge: ADC_HW_TRIG_RISING_EDGE
      HW Trigger Source: ADC_TRIG_8_GxREQTRI_GTM_ADCx_TRIG0
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    (Adc_NotifyFnPtrType)0U,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit8GrpHighSensor_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)&Adc_kHwUnit8GrpHighSensorGtmTrig_Config,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G8QCTRL register*/
    0x00004800U,
    /*Configuration value for the G8QMR register*/
    0x00000005U,
    /*Configuration value for the G8ALIAS register*/
    0x00000100U,
    /* Configuration value for G8REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0f00U,
    /*Bit Mask for all the result registers configured for the group*/
    0x000fU,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_HW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_GTM_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    4U, /*Channel Count for the group*/
    0U /*Limit Check enabled for the group*/
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 3 ******/
static const Adc_GroupCfgType Adc_kHwUnit3Grp_Config[1]=
{

  {/*Group Configuration structure for Sensor_diag - ID96*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_HW
      Trigger Edge: ADC_HW_TRIG_RISING_EDGE
      HW Trigger Source: ADC_TRIG_8_GxREQTRI_GTM_ADCx_TRIG0
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    (Adc_NotifyFnPtrType)0U,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit3GrpSensor_diag_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)&Adc_kHwUnit3GrpSensor_diagGtmTrig_Config,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G3QCTRL register*/
    0x00004800U,
    /*Configuration value for the G3QMR register*/
    0x00000005U,
    /*Configuration value for the G3ALIAS register*/
    0x00000100U,
    /* Configuration value for G3REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x00ffU,
    /*Bit Mask for all the result registers configured for the group*/
    0x00ffU,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_HW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_LINEAR,
    1U, /*Number of streaming samples for the group*/
    ADC_GTM_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    8U, /*Channel Count for the group*/
    0U /*Limit Check enabled for the group*/
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"



/***********************Channel Configuration Definition***********************/
/*****Channel Configuration Definition of HW Unit 0 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit0Ch_Config[8]=
{
  {
    0x50000002U, /*Configuration value for the G0CHCTR0 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G0CHCTR1 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    1U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G0CHCTR2 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    2U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G0CHCTR3 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    3U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G0CHCTR4 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    4U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G0CHCTR5 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    5U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G0CHCTR6 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    6U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G0CHCTR7 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    7U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 1 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit1Ch_Config[8]=
{
  {
    0x50000002U, /*Configuration value for the G1CHCTR0 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G1CHCTR1 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    1U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G1CHCTR2 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    2U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G1CHCTR3 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    3U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G1CHCTR4 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    4U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G1CHCTR5 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    5U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G1CHCTR6 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    6U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G1CHCTR7 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    7U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 2 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit2Ch_Config[4]=
{
  {
    0x50000002U, /*Configuration value for the G2CHCTR4 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    4U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G2CHCTR5 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    5U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G2CHCTR6 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    6U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G2CHCTR7 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    7U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 8 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit8Ch_Config[4]=
{
  {
    0x50000002U, /*Configuration value for the G8CHCTR8 register*/
    0x00000000U, /*Configuration value for the G8BOUND register*/
    8U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G8CHCTR9 register*/
    0x00000000U, /*Configuration value for the G8BOUND register*/
    9U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G8CHCTR10 register*/
    0x00000000U, /*Configuration value for the G8BOUND register*/
    10U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000002U, /*Configuration value for the G8CHCTR11 register*/
    0x00000000U, /*Configuration value for the G8BOUND register*/
    11U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 3 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit3Ch_Config[8]=
{
  {
    0x50000000U, /*Configuration value for the G3CHCTR0 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000000U, /*Configuration value for the G3CHCTR1 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    1U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000000U, /*Configuration value for the G3CHCTR2 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    2U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000000U, /*Configuration value for the G3CHCTR3 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    3U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000000U, /*Configuration value for the G3CHCTR4 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    4U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000000U, /*Configuration value for the G3CHCTR5 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    5U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x50000000U, /*Configuration value for the G3CHCTR6 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    6U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },
  {
    0x00000000U, /*Configuration value for the G3CHCTR7 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    7U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/********************HW Unit Converter Configurations********************/

/**HW Unit 0 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit0Hw_Config=
{
  0x00300004U, /*Configuration value for G0ANCFG register*/
  0x00000003U, /*Configuration value for G0ARBCFG register*/
  0x01000000U, /*Configuration value for G0ARBPR register*/
  0x00000008U, /*Configuration value for G0ICLASS0 register*/
  0x00000008U, /*Configuration value for G0ICLASS1 register*/
  0x00000000U /*Configuration value for G0SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"



/**HW Unit 1 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit1Hw_Config=
{
  0x00300004U, /*Configuration value for G1ANCFG register*/
  0x00000003U, /*Configuration value for G1ARBCFG register*/
  0x01000000U, /*Configuration value for G1ARBPR register*/
  0x00000004U, /*Configuration value for G1ICLASS0 register*/
  0x00000004U, /*Configuration value for G1ICLASS1 register*/
  0x00000000U /*Configuration value for G1SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"



/**HW Unit 2 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit2Hw_Config=
{
  0x00300004U, /*Configuration value for G2ANCFG register*/
  0x00000003U, /*Configuration value for G2ARBCFG register*/
  0x01000000U, /*Configuration value for G2ARBPR register*/
  0x00000000U, /*Configuration value for G2ICLASS0 register*/
  0x00000000U, /*Configuration value for G2ICLASS1 register*/
  0x00000000U /*Configuration value for G2SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"



/**HW Unit 8 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit8Hw_Config=
{
  0x00300004U, /*Configuration value for G8ANCFG register*/
  0x00000003U, /*Configuration value for G8ARBCFG register*/
  0x01000000U, /*Configuration value for G8ARBPR register*/
  0x00000000U, /*Configuration value for G8ICLASS0 register*/
  0x00000000U, /*Configuration value for G8ICLASS1 register*/
  0x00000000U /*Configuration value for G8SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"



/**HW Unit 3 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit3Hw_Config=
{
  0x00300004U, /*Configuration value for G3ANCFG register*/
  0x00000003U, /*Configuration value for G3ARBCFG register*/
  0x01000000U, /*Configuration value for G3ARBPR register*/
  0x00000300U, /*Configuration value for G3ICLASS0 register*/
  0x00000300U, /*Configuration value for G3ICLASS1 register*/
  0x00000000U /*Configuration value for G3SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"



/***************************HW Unit Configuration ***************************/

/*************HW Unit 0 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit0_Config=
{
  &Adc_kHwUnit0Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit0Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit0Grp_Config[0U], /*Group Configuration structure*/
  0x00000000U, /* Mask for SW triggered groups*/
  0x00000001U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  1U, /* Group Count for HW Unit 0*/
  1U /* Bit Mask for SRNs used for HW Unit 0*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 1 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit1_Config=
{
  &Adc_kHwUnit1Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit1Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit1Grp_Config[0U], /*Group Configuration structure*/
  0x00000000U, /* Mask for SW triggered groups*/
  0x00000001U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  1U, /* Group Count for HW Unit 1*/
  1U /* Bit Mask for SRNs used for HW Unit 1*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 2 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit2_Config=
{
  &Adc_kHwUnit2Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit2Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit2Grp_Config[0U], /*Group Configuration structure*/
  0x00000000U, /* Mask for SW triggered groups*/
  0x00000001U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  1U, /* Group Count for HW Unit 2*/
  1U /* Bit Mask for SRNs used for HW Unit 2*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 8 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit8_Config=
{
  &Adc_kHwUnit8Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit8Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit8Grp_Config[0U], /*Group Configuration structure*/
  0x00000000U, /* Mask for SW triggered groups*/
  0x00000001U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  1U, /* Group Count for HW Unit 8*/
  1U /* Bit Mask for SRNs used for HW Unit 8*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 3 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit3_Config=
{
  &Adc_kHwUnit3Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit3Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit3Grp_Config[0U], /*Group Configuration structure*/
  0x00000000U, /* Mask for SW triggered groups*/
  0x00000001U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  1U, /* Group Count for HW Unit 3*/
  1U /* Bit Mask for SRNs used for HW Unit 3*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/******************Global Configuration*******************/

static const Adc_GlobalCfgType Adc_kGlob_Config=
{
  0x00000000U, /*Configuration value for GLOBCFG register */
  0x00000145U, /*Configuration value for GLOBICLASS0 register */
  0x00000145U /*Configuration value for GLOBICLASS1 register */
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/***************************Core Configuration ***************************/

/*******Core0 Configuration*******/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_CoreConfigType Adc_kCore0_Config=
{
  {
    &Adc_kHwUnit0_Config, /* HW Unit 1 Configuration */
    &Adc_kHwUnit1_Config, /* HW Unit 2 Configuration */
    &Adc_kHwUnit2_Config, /* HW Unit 3 Configuration */
    &Adc_kHwUnit3_Config, /* HW Unit 4 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 5 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 6 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 7 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 8 Configuration */
    &Adc_kHwUnit8_Config, /* HW Unit 9 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 10 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 11 Configuration */
    (Adc_HwUnitCfgType*)0U /* HW Unit 12 Configuration */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
  

/*******Configuration Root*******/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/ 
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
   declaration is as per Autosar guidelines. This data structure is needed
   by SW units using Adc Driver APIs hence it should be declared as extern in 
   the SW unit from where it is used */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Module configuration data structure
   declaration is as per Autosar guidelines. This data structure is needed
   by SW units using Adc Driver APIs hence it should be declared as extern in 
   the SW unit from where it is used */
const Adc_ConfigType Adc_Config=
{
  &Adc_kGlob_Config, /* Global Configuration */
  {
    &Adc_kCore0_Config, /* Core0 Configuration */
    (const Adc_CoreConfigType*)0U, /* Core1 Configuration */
    (const Adc_CoreConfigType*)0U /* Core2 Configuration */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond 
   32 chars and this macro is used only inside the ADC module*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


