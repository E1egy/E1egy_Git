/*!
********************************************************************************
*
*  Copyright © 2021 - 2023 Shanghai Baolong Automotive Corporation. All Rights Reserved.
*
* \file:   TLF35584.h
* \author  BL_zq
* \version 1.0
* \date    2022.03.23
* \btief   The header file of Tlf35584_Driver.c
*
*----------------------------------------------------------------------------
* \attention
*
*
*****************************************************************************
*/

/**********************************************************************************
    change history:
        1.date : 2022.03.23
         author: BL_zq
         change: create file

**********************************************************************************/

#ifndef  TLF35584_DRIVER_H
#define  TLF35584_DRIVER_H

/***************************************Includes***********************************/
#include "Platform_Types.h"
#include "Spi.h"
#include "Spi_Cfg.h"

/***************************************Macros***********************************/
#define DUMMY_DATA                  (0u)        /* Dummy data used to read the content of the TLF35584 registers     */
#define CLEAR_STATUS_FLAGS          0x3F        /* Mask used to clear system status flags given in SYSSF register    */
#define SPI_DATA_BUFFER_SIZE        (1u)
#define Ifx_Ssw_getStmFrequency() 100000000

#define SPI_BUS_NOT_START_COMMUNICATION 1
#define SPI_BUS_COMMUNICATION_FALSE     2
#define SPI_BUS_COMMUNICATION_TRUE      3

#define TLF35584_5V_NORMAL 0
#define TLF35584_5V_SHORTOUT_TO_GND 1
#define TLF35584_5V_SHORTOUT_TO_POWER 2
/***************************************Enum***********************************/
/* TLF35584 SPI commands */
typedef enum
{
    SpiCommand_read  = 0,                       /* Read operation SPI command                   */
    SpiCmd_Write = 1,                        /* Write operation SPI command                  */
} SpiCommandType;

/* TLF35584 register address space */
typedef enum
{
    Devcfg0RegAddr       = 0x00, 
    Devcfg1RegAddr      = 0x01,    
    Devcfg2RegAddr      = 0x02,   
    ProtcfgRegAddr      = 0x03,                 /* Protection register                          */
    Syspcfg0RegAddr     = 0x04,                 /* Protected System configuration request 0     */
    Syspcfg1RegAddr     = 0x05,                 /* Protected System configuration request 1     */
    Wdcfg0RegAddr       = 0x06,                 /* Protected Watchdog configuration request 0   */
    Rsyspcfg0RegAddr = 0x0B,                 /* System configuration  0 status               */
    Rsyspcfg1RegAddr    = 0x0C,                 /* System configuration 1 status                */
    Rwdcfg0RegAddr      = 0x0D,                 /* Watchdog configuration 0 status              */
    DevctrlRegAddr      = 0x15,                 /* Device control request                       */
    DevctrlnRegAddr     = 0x16,                 /* Device control inverted request              */
    WwdscmdRegAddr      = 0x17,                 /* Window watchdog service command              */
    SyssfRegAddr        = 0x1D,                 /* System status flags                          */
    WakeupstatusflagRegAddr = 0x1E,             /* System wakeup status flags */
    SpisfRegAddr        = 0x1F,                 /* SPI status flags                             */
    DevstatRegAddr      = 0x27,                 /* Device status                                */
    IniterrorRegAddr    = 0x1B,                 /* Init error status flags                      */
} Tlf35584RegAddr;

/* Protection key
*Protect Register Unlock Sequence:1:0XAB 2:0XEF 3:0X56 4:0X12
*Protect Register   lock Sequence:1:0XDF 2:0X34 3:0XBE 4:0XCA
 */
typedef enum
{
    UnlockKey0  = 0xAB,                         /* Key 1 to unlock protected registers          */
    UnlockKey1  = 0xEF,                         /* Key 2 to unlock protected registers          */
    UnlockKey2  = 0x56,                         /* Key 3 to unlock protected registers          */
    UnlockKey3  = 0x12,                         /* Key 4 to unlock protected registers          */
    LockKey0    = 0xDF,                         /* Key 1 to lock protected registers            */
    LockKey1    = 0x34,                         /* Key 2 to lock protected registers            */
    LockKey2    = 0xBE,                         /* Key 3 to lock protected registers            */
    LockKey3    = 0xCA,                         /* Key 4 to lock protected registers            */
} keyType;

typedef enum
{
    StandbyRegulatorQST_disable = 0,
    StandbyRegulatorQST_enable = 1,
} StbyenStatus;

/* Request ERR pin monitor recovery time */
typedef enum
{
    ErrPinMonitorRecoveryTime_1ms   = 0,        /* 1ms      */
    ErrPinMonitorRecoveryTime_2_5ms = 1,        /* 2.5ms    */
    ErrPinMonitorRecoveryTime_5ms   = 2,        /* 5ms      */
    ErrPinMonitorRecoveryTime_10ms  = 3,         /* 10ms     */
} ErrRecType;

/* Request ERR pin monitor recovery enable */
typedef enum
{
    ErrPinMonitorRecovery_disabled = 0,         /* Disabled */
    ErrPinMonitorRecovery_enabled  = 1,          /* Enabled  */
} ErrRecEnType;

/* Request ERR pin monitor enable */
typedef enum
{
    ErrPinMonitor_disabled = 0,                 /* Disabled */
    ErrPinMonitor_enabled  = 1,                  /* Enabled  */
} ErrEnType;

/* Request ERR pin monitor functionality enable while the system is in SLEEP */
typedef enum
{
    ErrPinMonitorInSleep_disabled = 0,          /* ERR pin monitor is disabled in SLEEP                                 */
    ErrPinMonitorInSleep_enabled  = 1,           /* ERR pin monitor can be active in SLEEP depending on ERREN bit value  */
} ErrSlpEnType;

/* Request safe state 2 delay */
typedef enum
{
    SafeState2Delay_noDelay = 0,                /* No delay */
    SafeState2Delay_10ms    = 1,                /* 10ms     */
    SafeState2Delay_50ms    = 2,                /* 50ms     */
    SafeState2Delay_100ms   = 3,                /* 100ms    */
    SafeState2Delay_250ms   = 4,                 /* 250ms    */
} SS2DelType;

/* Request watchdog cycle time */
typedef enum
{
    WatchdogCycleTime_0_1ms = 0,                /* 0.1ms tick period */
    WatchdogCycleTime_1ms   = 1,                 /* 1ms tick period */
} WdCycType;

/* Request window watchdog trigger selection */
typedef enum
{
    WindowWatchdogTriggerSelection_external   = 0,  /* External WDI input used as a WWD trigger             */
    WindowWatchdogTriggerSelection_spiCommand = 1,   /* WWD is triggered by SPI write to WWDSCMD register    */
} WWdtTrigSelType;

/* Request functional watchdog enable */
typedef enum
{
    FunctionalWatchdog_disabled = 0,            /* Disabled */
    FunctionalWatchdog_enabled  = 1,             /* Enabled  */
} WdEnType;

/* Request window watchdog enable */
typedef enum
{
    WindowWatchdog_disabled = 0,                /* Disabled */
    WindowWatchdog_enabled  = 1,                 /* Enabled  */
} WWdEnType;

/* Request for device state transition
 * Cleared to 0b000 by the HW after the request is processed. After writing a new state
 * value a user should not change the value before it's cleared by HW.
 */
typedef enum
{
    DeviceStateTransition_none     = 0,         /* NONE     */
    DeviceStateTransition_init     = 1,         /* INIT     */
    DeviceStateTransition_normal   = 2,         /* NORMAL   */
    DeviceStateTransition_sleep    = 3,         /* SLEEP    */
    DeviceStateTransition_standby  = 4,         /* STANDBY  */
    DeviceStateTransition_wake     = 5,         /* WAKE     */
    DeviceStateTransition_reserved = 6,         /* RESERVED */
} DeviceStateTranType;

/* Request voltage reference QVR enable */
typedef enum
{
    OutputVoltageReferenceQVR_disabled = 0,           /* QVR will be disabled after valid request */
    OutputVoltageReferenceQVR_enabled  = 1,            /* QVR will be enabled after valid request  */
} QVROutVolRefType;

/* Request communication LDO QCO enable */
typedef enum
{
    CommunicationLdoQCO_disabled = 0,           /* QCO will be disabled after valid request */
    CommunicationLdoQCO_enabled  = 1,            /* QCO will be enabled after valid request  */
} QCOCommType;

/* Request tracker1 QT1 enable */
typedef enum
{
    Tracker1QT_disabled = 0,                    /* QT1 will be disabled after valid request */
    Tracker1QT_enabled  = 1,                     /* QT1 will be enabled after valid request  */
} QTITrk1EnType;

/* Request tracker2 QT2 enable */
typedef enum
{
    Tracker2QT_disabled = 0,                    /* QT2 will be disabled after valid request */
    Tracker2QT_enabled  = 1,                     /* QT2 will be enabled after valid request  */
} QTITrk2EnType;

/* State transition request failure flag
 * Requested state transition via DEVCTRL & DEVCTRLN could not be performed because of wrong protocol
 */
typedef enum
{
    StateTransitionRequest_noError = 0,         /* Write 0 - no action                          */
    StateTransitionRequest_errorDetected = 1,    /* Event detected, write 1 to clear the flag    */
} StateTransReqfailType;

/* Transition to low power failed flag
 * Transition to low power failed either due to the QUC current monitor,
 * WAK high level or a rising edge on ENA during TRDEL time
 */
typedef enum
{
    TransitionToLowPower_noError = 0,           /* Write 0 - no action                          */
    TransitionToLowPower_errorDetected = 1,      /* Event detected, write 1 to clear the flag    */
} TransToLowPowfailType;

/* MCU error miss status flag
 * Set only when SYSPCFG1.ERRRECEN='1'
 */
typedef enum
{
    McuErrorMiss_noError = 0,                   /* Write 0 - no action                          */
    McuErrorMiss_errorDetected = 1,              /* Event detected, write 1 to clear the flag    */
} ErrmissType;

/* Functional watchdog error interrupt flag */
typedef enum
{
    FunctionalWatchdog_noError = 0,             /* Write 0 - no action                          */
    FunctionalWatchdog_errorDetected = 1,        /* Event detected, write 1 to clear the flag    */
} WdErrIntType;

/* Window watchdog error interrupt flag */
typedef enum
{
    WindowWatchdog_noError = 0,                 /* Write 0 - no action                          */
    WindowWatchdog_errorDetected = 1,            /* Event detected, write 1 to clear the flag    */
} WWdErrIntType;

/* Protected configuration double bit error flag
 * Double bit error occurred on protected configuration register.
 * Status registers shall be read in order to determine which configuration has changed.
 */
typedef enum
{
    ProtectedConfigurationDoubleBit_noError = 0,        /* Write 0 - no action                          */
    ProtectedConfigurationDoubleBit_errorDetected = 1,   /* Event detected, write 1 to clear the flag    */
} ProtectCfgeErrType;

/* SPI frame parity error flag
 * Number of detected SPI clock cycles different than 16.
 */
typedef enum
{
    SpiFrameParity_noError       = 0,           /* Write 0 - no action                          */
    SpiFrameParity_errorDetected = 1,            /* Event detected, write 1 to clear the flag    */
} FrameParityErrType;

/* SPI frame parity error flag
 * Number of detected SPI clock cycles different than 16.
 */
typedef enum
{
    SpiFrameLengthInvalid_noError       = 0,    /* Write 0 - no action                          */
    SpiFrameLengthInvalid_errorDetected = 1,     /* Event detected, write 1 to clear the flag    */
} FramelengthErrType;

/* SPI address invalid flag */
typedef enum
{
    SpiAddressInvalid_noError       = 0,        /* Write 0 - no action                          */
    SpiAddressInvalid_errorDetected = 1,         /* Event detected, write 1 to clear the flag    */
} SpiAddErrType;

/* SPI frame duration error flag
 * SCS low for more than 2ms.
 */
typedef enum
{
    SpiFrameDuration_noError       = 0,         /* Write 0 - no action                          */
    SpiFrameDuration_errorDetected = 1,          /* Event detected, write 1 to clear the flag    */
} SpiFrameDurErrType;

/* LOCK or UNLOCK procedure error flag */
typedef enum
{
    LockOrUnlockProcedure_noError       = 0,    /* Write 0 - no action                          */
    LockOrUnlockProcedure_errorDetected = 1,     /* Event detected, write 1 to clear the flag    */
} lockErrType;

/* Device state */
typedef enum
{
    DeviceState_none     = 0,                   /* NONE     */
    DeviceState_init     = 1,                   /* INIT     */
    DeviceState_normal   = 2,                   /* NORMAL   */
    DeviceState_sleep    = 3,                   /* SLEEP    */
    DeviceState_standby  = 4,                   /* STANDBY  */
    DeviceState_wake     = 5,                   /* WAKE     */
    DeviceState_reserved = 6,                   /* RESERVED */
} DeviceStateType;

/* Reference voltage enable status */
typedef enum
{
    ReferenceVoltage_disabled = 0,              /* Voltage is disabled  */
    ReferenceVoltage_enabled  = 1,               /* Voltage is enabled   */
} ReferenceVolEnType;

/* Standby LDO enable status */
typedef enum
{
    StandbyLdoVoltage_disabled = 0,             /* Voltage is disabled  */
    StandbyLdoVoltage_enabled  = 1,              /* Voltage is enabled   */
} StandbyLdoVolEnType;

/* Communication LDO enable status */
typedef enum
{
    CommunicationLdoVoltage_disabled = 0,       /* Voltage is disabled  */
    CommunicationLdoVoltage_enabled  = 1,        /* Voltage is enabled   */
} ComunLdoVolEnType;

/* Tracker1 voltage enable status */
typedef enum
{
    Tracker1Voltage_disabled = 0,               /* Voltage is disabled  */
    Tracker1Voltage_enabled  = 1,                /* Voltage is enabled   */
} Trk1VolEnType;

/* Tracker2 voltage enable status */
typedef enum
{
    Tracker2Voltage_disabled = 0,               /* Voltage is disabled  */
    Tracker2Voltage_enabled  = 1,                /* Voltage is enabled   */
} Trk2VolEnType;

/* Init error status flags */
typedef enum
{
    VoltageMonitorFailureFlag = 0,
    WindowsWdgErrorCounterOverflowFailureFlag = 1,
    FuncWdgErrorCounterOverflowFailureFlag = 2, 
    MCUErrorMonitorFailureFlag =3, 
    SoftResetFlag = 4,
    HardResetFlag = 5,               
} InitErrorStatusFlags;

/* Wake timer enable */
typedef enum
{
    WakeTimer_disabled = 0,     /* Wake timer disabled */
    WakeTimer_enabled = 0,      /* Wake timer enabled in SLEEP or STANDBY state */
} WakeTimerEnType;

/* Wake timer cycle period */
typedef enum
{
    WakeTimerCyclePeriod_10us = 0,
    WakeTimerCyclePeriod_10ms = 1,
} WakeTimerCyclePeriod;

/* Transition delay into low power states */
typedef enum
{
    TransitionDelayTime_100us = 0,
    TransitionDelayTime_200us = 1,
    TransitionDelayTime_300us = 2,
    TransitionDelayTime_400us = 3,
    TransitionDelayTime_500us = 4,
    TransitionDelayTime_600us = 5,
    TransitionDelayTime_700us = 6,
    TransitionDelayTime_800us = 7,
    TransitionDelayTime_900us = 8,
    TransitionDelayTime_1000us = 9,
    TransitionDelayTime_1100us = 10,
    TransitionDelayTime_1200us = 11,
    TransitionDelayTime_1300us = 12,
    TransitionDelayTime_1400us = 13,
    TransitionDelayTime_1500us = 14,
    TransitionDelayTime_1600us = 15,
} TransitionDelayTime;

/* External core supply enable status*/
typedef enum
{
    ExternalCoreSupply_disable = 0,
    ExternalCoreSupply_enable = 1,
} ExternalCoreSupplyEnableStatus;

/*Step-up converter enable status */
typedef enum
{
    StepupConverterOnLow = 0,
    StepupConverterOnHigh = 1,
} StepupConverterEnableStatus;

/*Step-down converter frequency selection status */
typedef enum
{
    StepdownConverterOnLow = 0,
    StepdownConverterOnHigh = 1,
} StepdownConverterEnableStatus;

/* QUC current monitor enable for transition to a low power state*/
typedef enum
{
    QucCurrentMonitor_disable = 0,
    QucCurrentMonitor_enable = 1,
} QucCurrentMonitorEnableStatus;

/* QUC current monitoring threshold value*/
typedef enum
{
    QucCurrentMonitorThresholdValue_10mA = 0,
    QucCurrentMonitorThresholdValue_30mA = 1,
    QucCurrentMonitorThresholdValue_60mA = 2,
    QucCurrentMonitorThresholdValue_100mA = 3,
} QucCurrentMonitorThresholdValue;

/* External synchronization output phase*/
typedef enum
{
    NoPhaseShift = 0,
    PhaseShift180 = 1,
} ExternalSynchronizationOutputPhase;

/* Synchronization output for external switchmode regulator enable*/
typedef enum
{
    ExternalSwitchmodeRegulator_disable = 0,
    ExternalSwitchmodeRegulator_enable = 1,
} ExternalSwitchmodeRegulatorEnable;

/* WAK signal wakeup flag */
typedef enum
{
    WakSignal_disable = 0,
    WakSignal_enable = 1,
} WakSignalWakeupFlag;

/* ENA signal wakeup flag */
typedef enum
{
    EnaSignal_disable = 0,
    EnaSignal_enable = 1,
} EnaSignalWakeupFlag;

/* QUC current monitor threshold wakeup flag */
typedef enum
{
    QucCurrentMonitorThresholdWakeup_disable = 0,
    QucCurrentMonitorThresholdWakeup_enable = 1,
} QucCurrentMonitorThresholdWakeupFlag;

/* Wake timer wakeup flag */
typedef enum 
{
    WakeTimerWakeup_disable = 0,
    WakeTimerWakeup_enable = 1,
} WakeTimerWakeupFlag;

/* Wakeup from SLEEP by SPI flag (GoToWAKE) */
typedef enum 
{
    WakeupBySpi_disable = 0,
    WakeupBySpi_enable = 1,
} WakeupBySpiFlag;


/***************************************Struct***********************************/
/* Device configuration 0*/
typedef struct
{
    TransitionDelayTime  TRDEL:4;             
    uint8                reserved:2;
    WakeTimerCyclePeriod WKTIMCYC:1;
    WakeTimerEnType      WKTIMEN:1;
} Tlf35584Devcfg0Bits;

/* Device configuration 2*/
typedef struct
{
    ExternalSwitchmodeRegulatorEnable   ESYNEN:1;
    ExternalSynchronizationOutputPhase  ESYNPHA:1; 
    QucCurrentMonitorThresholdValue     CTHR:2;
    QucCurrentMonitorEnableStatus       CMONEN:1;
    StepdownConverterEnableStatus       FRE:1;
    StepupConverterEnableStatus         STU:1;
    ExternalCoreSupplyEnableStatus      EVCEN:1;
}Tlf35584Devcfg2Bits;

/* Protected System configuration request 1 bitfields*/
typedef struct
{
    StbyenStatus    STBYEN:1;
    uint8           reserved:7;
} Tlf35584ProSyscfgReq0Bits;

/* Protected System configuration request 1 bitfields*/
typedef struct
{
    ErrRecType      ERRREC:2;           /* Request ERR pin monitor recovery time                                     */
    ErrRecEnType    ERRRECEN:1;         /* Request ERR pin monitor recovery enable                                   */
    ErrEnType       ERREN:1;            /* Request ERR pin monitor enable                                            */
    ErrSlpEnType    ERRSLPEN:1;         /* Request ERR pin monitor functionality enable while the system is in SLEEP */
    SS2DelType      SS2DEL:2;           /* Request safe state 2 delay                                                */
} Tlf35584ProSyscfgReq1Bits;

/* Protected Watchdog configuration request 0 bitfields */
typedef struct
{
    WdCycType       WDCYC:1;            /* Request watchdog cycle time                                               */
    WWdtTrigSelType WWDTSEL:1;          /* Request window watchdog trigger selection                                 */
    WdEnType        FWDEN:1;            /* Request functional watchdog enable                                        */
    WWdEnType       WWDEN:1;            /* Request window watchdog enable                                            */
    uint8           WWDETHR:4;          /* Request window watchdog error threshold                                   */
} Tlf35584WdCfgReq0Bits;

/* Device control request bitfields*/
typedef struct
{
    DeviceStateTranType  STATEREQ:3;         /* Request for device state transition                                       */
    QVROutVolRefType     VREFEN:1;           /* Request voltage reference QVR enable                                      */
    uint8                reserved:1;         /* unused bit                                                                */
    QCOCommType          COMEN:1;            /* Request communication ldo QCO enable                                      */
    QTITrk1EnType        TRK1EN:1;           /* Request tracker1 QT1 enable                                               */
    QTITrk2EnType        TRK2EN:1;           /* Request tracker2 QT2 enable                                               */
} Tlf35584DevCtlReqBits;

/* Window watchdog service command bitfields*/
typedef struct
{
    uint8           TRIG:1;             /* Window watchdog SPI trigger command                                       */
    uint8           reserved:6;         /* unused bits                                                               */
    uint8           TRIG_STATUS:1;      /* Last SPI trigger received                                                 */
} Tlf35584WWdsCmdBits;

/* System status flags bitfields*/
typedef struct
{
    ProtectCfgeErrType    CFGE:1;             /* Protected configuration double bit error flag                             */
    WWdErrIntType         WWDE:1;             /* Window watchdog error interrupt flag                                      */
    WdErrIntType          FWDE:1;             /* Functional watchdog error interrupt flag                                  */
    ErrmissType           ERRMISS:1;          /* MCU error miss status flag                                                */
    TransToLowPowfailType TRFAIL:1;           /* Transition to low power failed flag                                       */
    StateTransReqfailType TRSREQFAIL:1;            /* State transition request failure flag                                     */
    uint8                 reserved:2;         /* unused bits                                                               */
} Tlf35584SysStateFlagBits;

/* SPI status flags bitfields*/
typedef struct
{
    FrameParityErrType  PARE:1;             /* SPI frame parity error flag                                               */
    FramelengthErrType     LENE:1;             /* SPI frame length invalid flag                                             */
    SpiAddErrType       ADDRE:1;            /* SPI address invalid flag                                                  */
    SpiFrameDurErrType  DURE:1;             /* SPI frame duration error flag                                             */
    lockErrType         LOCK:1;             /* LOCK or UNLOCK procedure error flag                                       */
    uint8               reserved:3;         /* unused bits                                                               */
} Tlf35584SpiStateFlagBits;

/* Device status bitfields */
typedef struct
{
    DeviceStateType     STATE:3;        /* Device status                                                             */
    ReferenceVolEnType  VREFEN:1;       /* Reference voltage enable status                                           */
    StandbyLdoVolEnType STBYEN:1;       /* Standby LDO enable status                                                 */
    ComunLdoVolEnType   COMEN:1;        /* Communication LDO enable status                                           */
    Trk1VolEnType       TRK1EN:1;       /* Tracker1 voltage enable status                                            */
    Trk2VolEnType       TRK2EN:1;       /* Tracker2 voltage enable status                                            */
} Tlf35584DevStateBits;

typedef struct
{
    uint32                  evenParityBit:1;     
    uint32                  data:8;     /* Data part of the SPI frame structure             */
    Tlf35584RegAddr         addr:6;     /* Address part of the SPI frame structure          */
    SpiCommandType          cmd:1;      /* Command part of the SPI frame structure          */
    uint32                  reserved:1; /* Parity part is automatically generated by the HW */
} Tlf35584SpiFrameTypeBits;

/* Wakeup status flags */
typedef struct
{
    WakSignalWakeupFlag WAK:1;
    EnaSignalWakeupFlag ENA:1;
    QucCurrentMonitorThresholdWakeupFlag CMON:1;
    WakeTimerWakeupFlag WKTIM:1;
    WakeupBySpiFlag WKSPI:1;
    uint8                reserved:3;
} Tlf35584WakeupstatusflagBits;

/* Standby regulator QST enable status */
typedef struct
{
    StbyenStatus STBYEN:1;
    uint8        reserved:7;
} Tlf35584StandbyRegulatorQSTEnableStatusBits;
/***************************************Union***********************************/
typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584StandbyRegulatorQSTEnableStatusBits B;     /* Bitfield access  */
}Tlf35584SysConfig0Status;

typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584WakeupstatusflagBits B;     /* Bitfield access  */
}Tlf35584WakeupstatusFlag;

typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584Devcfg0Bits B;              /* Bitfield access  */
}Tlf35584Devcfg0;

typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584Devcfg2Bits B;              /* Bitfield access  */
}Tlf35584Devcfg2;

/* Protection register bitfields*/
typedef struct
{
    keyType KEY:8;            /* Protection key   */
} Tlf35584ProtRegCfgBits;

/* Protection register */
typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584ProtRegCfgBits B;              /* Bitfield access  */
} Tlf35584ProtRegCfg;

/* Protected System configuration request 1 */
typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584ProSyscfgReq0Bits B;             /* Bitfield access  */
} Tlf35584ProSysCfgReq0;


/* Protected System configuration request 1 */
typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584ProSyscfgReq1Bits B;             /* Bitfield access  */
} Tlf35584ProSysCfgReq1;

/* Protected Watchdog configuration request 0 */
typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584WdCfgReq0Bits B;               /* Bitfield access  */
} Tlf35584WdCfgReq0;

/* Device control request */
typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584DevCtlReqBits B;              /* Bitfield access  */
} Tlf35584DevCtlReq;

/* Window watchdog service command*/
typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584WWdsCmdBits B;              /* Bitfield access  */
} Tlf35584WWdsCmd;

/* System status flags */
typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584SysStateFlagBits B;                /* Bitfield access  */
} Tlf35584SysStateFlag;

/* SPI status flags */
typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584SpiStateFlagBits B;                /* Bitfield access  */
} Tlf35584SpiStateFlag;

/* Device status */
typedef union
{
    uint8 U;                            /* Unsigned access  */
    sint8 I;                            /* Signed access    */
    Tlf35584DevStateBits B;              /* Bitfield access  */
} Tlf35584DevState;

typedef union
{
    uint16 U;                           /* Unsigned access  */
    sint16 I;                           /* Signed access    */
    Tlf35584SpiFrameTypeBits B;         /* Bitfield access  */
} Tlf35584SpiFrameType;

typedef union
{
    uint16 U; /* Unsigned access */
    sint16 I; 
    InitErrorStatusFlags B;
}Tlf35584InitErrorStatusFlagsType;

/* TLF35584 register structure */
typedef volatile struct
{
    Tlf35584Devcfg0       DEVCFG0;
    Tlf35584Devcfg2       DEVCFG2;
    Tlf35584ProtRegCfg    PROTCFG;       /* 0x03, Protection register                        */
    Tlf35584ProSysCfgReq0 SYSPCFG0;      /* 0x05, Protected System configuration request 1   */
    Tlf35584ProSysCfgReq1 SYSPCFG1;      /* 0x05, Protected System configuration request 1   */
    Tlf35584WdCfgReq0     WDCFG0;        /* 0x06, Protected Watchdog configuration request 0 */
    Tlf35584ProSysCfgReq1 RSYSPCFG1;     /* 0x0C, System configuration 1 status              */
    Tlf35584WdCfgReq0     RWDCFG0;       /* 0x0D, Watchdog configuration 0 status            */
    Tlf35584DevCtlReq     DEVCTRL;       /* 0x15, Device control request                     */
    Tlf35584DevCtlReq     DEVCTRLN;      /* 0x16, Device control inverted request            */
    Tlf35584WWdsCmd       WWDSCMD;       /* 0x17, Window watchdog service command            */
    Tlf35584SysStateFlag  SYSSF;         /* 0x1D, System status flags                        */
    Tlf35584SpiStateFlag  SPISF;         /* 0x1F, SPI status flags                           */
    Tlf35584DevState      DEVSTAT;       /* 0x27, Device status                              */
    Tlf35584InitErrorStatusFlagsType INITERR;
    Tlf35584WakeupstatusFlag WKSF;
    Tlf35584SysConfig0Status RSYSPCFG0;
} Tlf35584Reg;

/* TLF35584 Device Information */
typedef struct
{
    uint8 spiChananelId;
    uint8 spiSequenceId;
    uint16 *writeBuff;
    const uint8 writeBuffMaxLen;
    uint16 *readBuff;
    const uint8 readBuffMaxLen;
} Tlf35584DevInfo;

/***************************************Variables***********************************/
extern Tlf35584Reg g_TlfDeviceReg;
extern uint16  Tlf35584SpiWrite_Data_Buffer[SPI_DATA_BUFFER_SIZE];
extern uint16  Tlf35584SpiRead_Data_Buffer[SPI_DATA_BUFFER_SIZE];
extern Tlf35584DevInfo g_TlfDeviceInfo[1];
/***************************************Functions***********************************/
extern uint8 Tlf35584DataTransfer(SpiCommandType cmd, Tlf35584RegAddr addr, uint8 data);
extern void Tlf35584UnlockRegister(void);
extern void Tlf35584LockRegister(void);
extern void Tlf35584DisableWindowWatchdog(Tlf35584Reg *tlfDevice);
extern void Tlf35584EnableWindowWatchdog(Tlf35584Reg *tlfDevice);
extern void Tlf35584DisableErrPinMonitor(Tlf35584Reg *tlfDevice);
extern void Tlf35584EnableErrPinMonitor(Tlf35584Reg *tlfDevice);
extern void Tlf35584EnableVoltageSupplyRails(Tlf35584Reg *tlfDevice);
extern void Tlf35584SetStateTransition(Tlf35584Reg *tlfDevice, DeviceStateTranType requestedStateTransition);
extern DeviceStateType Tlf35584GetCurrentStateTransition(Tlf35584Reg *tlfDevice);
extern uint8 Tlf35584SetStateTransition_To_Normal(void);
extern uint8 Tlf35584SetStateTransition_NormalToSleep(void);
extern uint8 Tlf35584SetStateTransition_NormalToStandby(void);
extern uint8 Tlf35584GetSystemStatusFlags(Tlf35584Reg *tlfDevice);
extern void Tlf35584ClearSystemStatusFlags(Tlf35584Reg *tlfDevice);
extern uint8 Tlf35584GetInitErrortatusFlags(Tlf35584Reg *tlfDevice);
extern void Tlf35584Init(void);
extern uint8 GetTlf35584ChipStatus(void);
extern boolean GetVQT1ErrorStatus(void);
extern void EnableVQT1Recovery(void);
extern boolean GetVQT2ErrorStatus(void);
extern void EnableVQT2Recovery(void);
extern uint8 GetVQCODiagStatus(void);
#endif
/*  END OF FILE */

