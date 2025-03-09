/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Type.h>
 *  @brief      <>
 *  
 *  <MCU:TC377>
 *  
 *  @author     <>
 *  @date       <2022-10-20 11:46:02>
 */
/*============================================================================*/

/* Rte_Type.h */

#ifndef RTE_TYPE_H
#define RTE_TYPE_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/

#if 1
typedef uint8 EcuM_BootTargetType;
#ifndef ECUM_BOOT_TARGET_APP
#define ECUM_BOOT_TARGET_APP ((EcuM_BootTargetType)0)
#endif /*ECUM_BOOT_TARGET_APP*/
#ifndef ECUM_BOOT_TARGET_OEM_BOOTLOADER
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER ((EcuM_BootTargetType)1)
#endif /*ECUM_BOOT_TARGET_OEM_BOOTLOADER*/
#ifndef ECUM_BOOT_TARGET_SYS_BOOTLOADER
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER ((EcuM_BootTargetType)2)
#endif /*ECUM_BOOT_TARGET_SYS_BOOTLOADER*/
#define EcuM_BootTargetType_LowerLimit 0
#define EcuM_BootTargetType_UpperLimit 2



#define _DEFINED_TYPEDEF_FOR_EcuM_BootTargetType_

typedef uint8 EcuM_ShutdownCauseType;
#ifndef ECUM_CAUSE_UNKNOWN
#define ECUM_CAUSE_UNKNOWN ((EcuM_ShutdownCauseType)0)
#endif /*ECUM_CAUSE_UNKNOWN*/
#ifndef ECUM_CAUSE_ECU_STATE
#define ECUM_CAUSE_ECU_STATE ((EcuM_ShutdownCauseType)1)
#endif /*ECUM_CAUSE_ECU_STATE*/
#ifndef ECUM_CAUSE_WDGM
#define ECUM_CAUSE_WDGM ((EcuM_ShutdownCauseType)2)
#endif /*ECUM_CAUSE_WDGM*/
#ifndef ECUM_CAUSE_DCM
#define ECUM_CAUSE_DCM ((EcuM_ShutdownCauseType)3)
#endif /*ECUM_CAUSE_DCM*/
#define EcuM_ShutdownCauseType_LowerLimit 0
#define EcuM_ShutdownCauseType_UpperLimit 3



#define _DEFINED_TYPEDEF_FOR_EcuM_ShutdownCauseType_

typedef uint16 EcuM_ShutdownModeType;



#define _DEFINED_TYPEDEF_FOR_EcuM_ShutdownModeType_

typedef uint8 EcuM_ShutdownTargetType;
#ifndef ECUM_SHUTDOWN_TARGET_SLEEP
#define ECUM_SHUTDOWN_TARGET_SLEEP ((EcuM_ShutdownTargetType)0x0)
#endif /*ECUM_SHUTDOWN_TARGET_SLEEP*/
#ifndef ECUM_SHUTDOWN_TARGET_RESET
#define ECUM_SHUTDOWN_TARGET_RESET ((EcuM_ShutdownTargetType)0x1)
#endif /*ECUM_SHUTDOWN_TARGET_RESET*/
#ifndef ECUM_SHUTDOWN_TARGET_OFF
#define ECUM_SHUTDOWN_TARGET_OFF ((EcuM_ShutdownTargetType)0x2)
#endif /*ECUM_SHUTDOWN_TARGET_OFF*/



#define _DEFINED_TYPEDEF_FOR_EcuM_ShutdownTargetType_

typedef uint32 EcuM_TimeType;
#define EcuM_TimeType_LowerLimit 0
#define EcuM_TimeType_UpperLimit 4294967295



#define _DEFINED_TYPEDEF_FOR_EcuM_TimeType_

typedef uint8 EcuM_UserType;
#define EcuM_UserType_LowerLimit 0
#define EcuM_UserType_UpperLimit 31



#define _DEFINED_TYPEDEF_FOR_EcuM_UserType_

typedef uint8 Rte_ModeGroupType;
#define RTE_MODE_EcuM_Mode ((Rte_ModeGroupType)0)


typedef uint8 Rte_ModeType_EcuM_Mode;
#define RTE_TRANSITION_EcuM_Mode ((Rte_ModeType_EcuM_Mode)5)
#define RTE_MODE_EcuM_Mode_STARTUP ((Rte_ModeType_EcuM_Mode)4)
#define RTE_MODE_EcuM_Mode_RUN ((Rte_ModeType_EcuM_Mode)1)
#define RTE_MODE_EcuM_Mode_POST_RUN ((Rte_ModeType_EcuM_Mode)0)
#define RTE_MODE_EcuM_Mode_SLEEP ((Rte_ModeType_EcuM_Mode)3)
#define RTE_MODE_EcuM_Mode_SHUTDOWN ((Rte_ModeType_EcuM_Mode)2)

#endif


typedef boolean Boolean;



#define _DEFINED_TYPEDEF_FOR_Boolean_ 

typedef float64 Double;



#define _DEFINED_TYPEDEF_FOR_Double_ 

typedef float32 Float;



#define _DEFINED_TYPEDEF_FOR_Float_ 

typedef float32 Float32;



#define _DEFINED_TYPEDEF_FOR_Float32_ 

typedef float64 Float64;



#define _DEFINED_TYPEDEF_FOR_Float64_ 

typedef sint16 SInt16;
#define SInt16_LowerLimit -32768
#define SInt16_UpperLimit 32767



#define _DEFINED_TYPEDEF_FOR_SInt16_ 

typedef sint32 SInt32;
#define SInt32_LowerLimit -2147483648
#define SInt32_UpperLimit 2147483647



#define _DEFINED_TYPEDEF_FOR_SInt32_ 

typedef sint8 SInt8;
#define SInt8_LowerLimit -128
#define SInt8_UpperLimit 127



#define _DEFINED_TYPEDEF_FOR_SInt8_ 

typedef uint16 UInt16;
#define UInt16_LowerLimit 0
#define UInt16_UpperLimit 65535



#define _DEFINED_TYPEDEF_FOR_UInt16_ 

typedef uint32 UInt32;
#define UInt32_LowerLimit 0
#define UInt32_UpperLimit 4294967295



#define _DEFINED_TYPEDEF_FOR_UInt32_ 

typedef uint64 UInt64;
#define UInt64_LowerLimit 0
#define UInt64_UpperLimit 18446744073709551615



#define _DEFINED_TYPEDEF_FOR_UInt64_ 

typedef uint8 UInt8;
#define UInt8_LowerLimit 0
#define UInt8_UpperLimit 255



#define _DEFINED_TYPEDEF_FOR_UInt8_ 

typedef Float rt_Array_Float_10[10];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_10_ 

typedef Float rt_Array_Float_104[104];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_104_ 

typedef Float rt_Array_Float_11[11];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_11_ 

typedef Float rt_Array_Float_120[120];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_120_ 

typedef Float rt_Array_Float_13[13];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_13_ 

typedef Float rt_Array_Float_136[136];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_136_ 

typedef Float rt_Array_Float_15[15];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_15_ 

typedef Float rt_Array_Float_168[168];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_168_ 

typedef Float rt_Array_Float_17[17];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_17_ 

typedef Float rt_Array_Float_184[184];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_184_ 

typedef Float rt_Array_Float_2[2];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_2_ 

typedef Float rt_Array_Float_21[21];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_21_ 

typedef Float rt_Array_Float_23[23];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_23_ 

typedef Float rt_Array_Float_33[33];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_33_

typedef Float rt_Array_Float_4[4];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_4_ 

typedef Float rt_Array_Float_5[5];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_5_ 

typedef Float rt_Array_Float_6[6];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_6_ 

typedef Float rt_Array_Float_51[51];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_51_ 

typedef Float rt_Array_Float_64[64];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_64_ 

typedef Float rt_Array_Float_72[72];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_72_ 

typedef Float rt_Array_Float_8[8];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_8_ 

typedef Float rt_Array_Float_88[88];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_88_ 

typedef Float rt_Array_Float_9[9];


#define _DEFINED_TYPEDEF_FOR_rt_Array_Float_9_ 



#if 0
typedef uint8 uint8_T;

typedef uint16 uint16_T;

typedef uint32 uint32_T;

typedef boolean boolean_T;

typedef uint16_T rt_Array_UInt16_100[100];

typedef float64 Double_T;

typedef uint32 imask_t;
#endif
#endif

