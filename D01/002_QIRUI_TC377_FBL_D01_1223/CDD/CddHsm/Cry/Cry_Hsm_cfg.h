/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Cry_Hsm_Cfg.h                                                 **
**                                                                            **
**  $CC VERSION : \main\74 $                                                  **
**                                                                            **
**  DATE, TIME: 2020-09-27, 14:08:37                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains functionality of Cry module             **
**                 and can be modified via GUI                                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

#ifndef CRY_HSM_CFG_H
#define CRY_HSM_CFG_H


/*******************************************************************************
**                                                                            **
**  TRACEABILITY : [cover parentID=] [/cover]                                 **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*
Configuration: CRY_HSM_USER_TIMER_FILE_NAME
User specified user timer
*/
#include "Cry_CustomerTimeoutApi.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
Configuration: CRY_HSM_TRIGGERED_INIT
- STD_ON  : The HSM init is triggered from TriCore
- STD_OFF : The HSM init is performed independently from any TriCore trigger
*/
/* Traceability    : [$Satisfies $CDS_CDRV 430]                               */
#define CRY_HSM_TRIGGERED_INIT              (STD_OFF)

/*
Configuration: CRY_HSM_USE_SYNC_INIT
- STD_ON  : The HSM init is triggered in synchronous mode
- STD_OFF : The HSM init is triggered in asynchronous mode
*/
/* Traceability    : [$Satisfies $CDS_CDRV 592]                               */
#define CRY_HSM_USE_SYNC_INIT              (STD_ON)

/*
Configuration: CRY_HSM_MAC_SAFE_VERIFY
Pre-processor switch to implement all safety measures described by safety
concept
- STD_ON  : The MAC verify is performed to support safety
- STD_OFF : The MAC verify is QM
*/
/* Traceability    : [$Satisfies $CDS_CDRV 431]                               */
#define CRY_HSM_MAC_SAFE_VERIFY             (STD_OFF)

/*
Configuration: CRY_HSM_SECURE_BOOT
Pre-processor switch to enable and disable secure boot
- STD_ON  : The HSM Secure Boot is enabled
- STD_OFF : The HSM Secure Boot is disabled
*/
/* Traceability    : [$Satisfies $CDS_CDRV 432]                               */
#define CRY_HSM_SECURE_BOOT                (STD_OFF)

/*
Configuration: CRY_HSM_USER_TIMEOUT_API
Pre-processor switch to implement the interfaces for timeout calculation.
- STD_ON  : The user defined timeout interfaces used
- STD_OFF : The AUTOSAR Gpt timeout Interfaces used
*/
/* Traceability    : [$Satisfies $CDS_CDRV 433]  [$Satisfies $CDS_CDRV 580]   */
#define CRY_HSM_USER_TIMEOUT_API           (STD_ON)


/*
Configuration: CRY_HSM_USER_START_TIMER_API_NAME
User specified start timer API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 434]                               */
#define CRY_HSM_USER_START_TIMER_API_NAME   SwFrt_GetRawCount


/*
Configuration: CRY_HSM_USER_DELTA_TIMER_API_NAME
User specified elapsed time API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 435]                               */
#define CRY_HSM_USER_DELTA_TIMER_API_NAME   SwFrt_GetRawDelta


/*
Configuration: CRY_HSM_USER_STOP_TIMER_API_NAME
User specified stop timer API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 436]                               */
#define CRY_HSM_USER_STOP_TIMER_API_NAME    SwFrt_StopTimer


/*
Configuration: CRY_HSM_TICK_COUNT_VALUE
Tick count for one micro second used for converting specified timeout value
from micro second to timer ticks
*/
/* Traceability    : [$Satisfies $CDS_CDRV 437]                               */

#define CRY_HSM_TICK_COUNT_VALUE                      (100.0)

       
/*
Number of ticks per microsecond is 100.0

Configured timer has a maximum number of ticks of 4294967295

Safety factor set at 3.0

Maximum time in microseconds supported with
configured timer is: 1.431655765E7
*/

/*Time out in micro seconds for HsmCom_WaitForHsm*/
#define HSMCOM_WAIT_STATE_TIMEOUT   (20000000U)

/*
Configuration: CRY_HSM_BSWM_ERROR_NOTIFICATION
Pre-processor switch to enable and disable BswM module error reporting
BswM_RequestMode interface.
- STD_ON  : SHE error reported to BswM module
- STD_OFF : SHE error not reported to BswM module
*/
/* Traceability    : [$Satisfies $CDS_CDRV 438] [$Satisfies $CDS_CDRV 576]    */
#define CRY_HSM_BSWM_ERROR_NOTIFICATION               (STD_OFF)

/* Timeout in ticks for Cry initialization
*/
/* Traceability    : [$Satisfies $CDS_CDRV 439]                               */
#define CRY_HSM_INIT_TIMEOUT   (1250100U)

/*
Timeout in ticks for Cry_HsmRandomSeedInitStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmRandomSeedInitStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 440]                               */
#define CRY_HSM_RND_SEED_INIT_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for Cry_HsmRandomSeedInitUpdate
API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 441]                               */
#define CRY_HSM_RND_SEED_INIT_UPDATE_TIMEOUT   (9600U)

/*
Timeout in ticks, which is variable part for Cry_HsmRandomSeedInitUpdate API.
This parameter is dummy for Cry_HsmRandomSeedInitUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 442]                               */
#define CRY_HSM_RND_SEED_INIT_PER_BYTE_UPDATE_TIMEOUT   (0U)

/* Timeout in ticks for Cry_HsmRandomSeedInitFinish API.
This parameter is dummy as timeout is not applicable for
Cry_HsmRandomSeedInitFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 443]                               */
#define CRY_HSM_RND_SEED_INIT_FINISH_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmRandomSeedExtendStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmRandomSeedExtendStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 444]                               */
#define CRY_HSM_RND_SEED_EXTEND_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for
Cry_HsmRndSeedExtendUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 445]                               */
#define CRY_HSM_RND_SEED_EXTEND_UPDATE_TIMEOUT   (8400U)

/*
Timeout in ticks, which is variable part for Cry_HsmRandomSeedExtendUpdate API.
This parameter is dummy for Cry_HsmRandomSeedExtendUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 446]                               */
#define CRY_HSM_RND_SEED_EXTEND_PER_BYTE_UPDATE_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmRandomSeedExtendFinish API.
This parameter is dummy as timeout is not applicable for
Cry_HsmRandomSeedExtendFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 447]                               */
#define CRY_HSM_RND_SEED_EXTEND_FINISH_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmRandomGenerate API.
This parameter is dummy as Random generate service has no START function */
/* Traceability    : [$Satisfies $CDS_CDRV 448]                               */
#define CRY_HSM_RND_GENERATE_START_TIMEOUT   (0U)

#define CRY_HSM_HASH_START_TIMEOUT   (0U)


/*
Timeout in ticks, which is the constant part for Cry_HsmRandomGenerateUpdate
API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 449]                               */
#define CRY_HSM_RND_GENERATE_UPDATE_TIMEOUT   (5700U)

#define CRY_HSM_HASH_UPDATE_TIMEOUT   (800000000U)


/*
Timeout in ticks, which is variable part for Cry_HsmRandomGenerate API
This parameter is dummy for Cry_HsmRandomGenerate API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 450]                               */
#define CRY_HSM_RND_GENERATE_PER_BYTE_UPDATE_TIMEOUT   (0U)

#define CRY_HSM_HASH_PER_BYTE_UPDATE_TIMEOUT   (4800U)

/*
Timeout in ticks for Cry_HsmRandomGenerate API
This parameter is dummy as Random generate service has no FINISH function
*/
/* Traceability    : [$Satisfies $CDS_CDRV 451]                               */
#define CRY_HSM_RND_GENERATE_FINISH_TIMEOUT   (0U)

#define CRY_HSM_HASH_FINISH_TIMEOUT   (0U)


/* Timeout in ticks for Cry_HsmDebugStart API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 632]                               */
#define CRY_HSM_DEBUG_START_TIMEOUT   (8100U)

/* Timeout in ticks for Cry_HsmDebugFinish API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 633]                               */
#define CRY_HSM_DEBUG_FINISH_TIMEOUT   (344824800U)

/* Timeout in ticks for Cry_HsmGetSheUID API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 640]                               */
#define CRY_HSM_GET_UID_TIMEOUT   (9600U)

/* Timeout in ticks for Cry_HsmSheBootFailure API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 732]                               */
#define CRY_HSM_BOOT_FAILURE_TIMEOUT   (3000U)

/* Timeout in ticks for Cry_HsmSheBootOk API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 733]                               */
#define CRY_HSM_BOOT_OK_TIMEOUT   (2700U)

/*
Timeout in ticks for Cry_HsmAesXtsEncryptStart API
This parameter is dummy as timeout is not applicable for
Cry_HsmAesXtsEncryptStart API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 702]                               */
#define CRY_HSM_AES_XTS_ENCRYPT_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is constant part for Cry_HsmAesXtsEncryptUpdate API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 703]                               */
#define CRY_HSM_AES_XTS_ENCRYPT_UPDATE_TIMEOUT   (11700U)

/*
Timeout in ticks, which is variable part for Cry_HsmAesXtsEncryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 704]                               */
#define CRY_HSM_AES_XTS_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT   (300U)
/*
The maximum number of bytes for XTS encrypt update
is: 14316518 byte(s)
*/

/*
Timeout in ticks for Cry_HsmAesXtsEncryptFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 705]                               */
#define CRY_HSM_AES_XTS_ENCRYPT_FINISH_TIMEOUT   (3600U)

/*
Timeout in ticks for Cry_HsmAesXtsDecryptStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmAesXtsDecryptStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 706]                               */
#define CRY_HSM_AES_XTS_DECRYPT_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for
Cry_HsmAesXtsDecryptUpdate API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 707]                               */
#define CRY_HSM_AES_XTS_DECRYPT_UPDATE_TIMEOUT   (12300U)

/*
Timeout in ticks, which is variable part for Cry_HsmAesXtsDecryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 708]                               */
#define CRY_HSM_AES_XTS_DECRYPT_PER_BYTE_UPDATE_TIMEOUT   (300U)
/*
The maximum number of bytes for XTS decrypt update
is: 14316516 byte(s)
*/

/*
Timeout in ticks for Cry_HsmAesXtsDecryptFinish API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 709]                               */
#define CRY_HSM_AES_XTS_DECRYPT_FINISH_TIMEOUT   (4500U)

/*
Timeout in ticks for Cry_HsmAesGcmEncryptStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmAesGcmEncryptStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 654]                               */
#define CRY_HSM_AES_GCM_ENCRYPT_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for
Cry_HsmAesGcmEncryptUpdate API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 655]                               */
#define CRY_HSM_AES_GCM_ENCRYPT_UPDATE_TIMEOUT   (13500U)

/*
Timeout in ticks, which is variable part for Cry_HsmAesGcmEncryptUpdate API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 656]                               */
#define CRY_HSM_AES_GCM_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT   (300U)
/*
The maximum number of bytes for GCM encrypt update
is: 14316512 byte(s)
*/

/*
Timeout in ticks for Cry_HsmAesGcmEncryptFinish API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 657]                               */
#define CRY_HSM_AES_GCM_ENCRYPT_FINISH_TIMEOUT   (8400U)

/*
Timeout in ticks for Cry_HsmAesGcmDecryptStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmAesGcmDecryptStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 658]                               */
#define CRY_HSM_AES_GCM_DECRYPT_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for
Cry_HsmAesGcmDecryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 659]                               */
#define CRY_HSM_AES_GCM_DECRYPT_UPDATE_TIMEOUT   (13500U)

/*
Timeout in ticks, which is variable part for Cry_HsmAesGcmDecryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 660]                               */
#define CRY_HSM_AES_GCM_DECRYPT_PER_BYTE_UPDATE_TIMEOUT   (300U)
/*
The maximum number of bytes for GCM decrypt update
is: 14316512 byte(s)
*/

/*
Timeout in ticks for Cry_HsmAesGcmDecryptFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 661]                               */
#define CRY_HSM_AES_GCM_DECRYPT_FINISH_TIMEOUT   (7800U)

/* Timeout in ticks for Cry_HsmTrueRandomGenerate API.
This parameter is dummy as true random generate service has no START function
*/
/* Traceability    : [$Satisfies $CDS_CDRV 641]                               */
#define CRY_HSM_TRUE_RND_GENERATE_START_TIMEOUT   (0U)

/* Timeout in ticks, which is the constant part for
Cry_HsmTrueRandomGenerateUpdate API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 642]                               */
#define CRY_HSM_TRUE_RND_GENERATE_UPDATE_TIMEOUT   (4800U)

/*Timeout in ticks, which is variable part for Cry_HsmTrueRandomGenerate API.
This parameter is dummy for Cry_HsmTrueRandomGenerate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 643]                               */
#define CRY_HSM_TRUE_RND_GENERATE_PER_BYTE_UPDATE_TIMEOUT   (0U)

/* Timeout in ticks for Cry_HsmTrueRandomGenerate API.
This parameter is dummy as true random generate service has no FINISH function.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 644]                               */
#define CRY_HSM_TRUE_RND_GENERATE_FINISH_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmAesEcbEncryptStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmAesEcbEncryptStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 452]                               */
#define CRY_HSM_AES_ECB_ENCRYPT_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for
Cry_HsmAesEcbEncryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 453]                               */
#define CRY_HSM_AES_ECB_ENCRYPT_UPDATE_TIMEOUT   (6000U)

/*
Timeout in ticks, which is variable part for Cry_HsmAesEcbEncryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 454]                               */
#define CRY_HSM_AES_ECB_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT   (0U)
/*
The maximum number of bytes for ECB encrypt update
is: 4294967295 byte(s)
*/
      
/*
Timeout in ticks for Cry_HsmAesEcbEncryptFinish API.
This parameter is dummy for Cry_HsmAesEcbEncryptFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 455]                               */
#define CRY_HSM_AES_ECB_ENCRYPT_FINISH_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmAesEcbDecryptStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmAesEcbDecryptStart API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 456]                               */
#define CRY_HSM_AES_ECB_DECRYPT_START_TIMEOUT   (0U)
/*
Timeout in ticks, which is the constant part for
Cry_HsmAesEcbDecryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 457]                               */
#define CRY_HSM_AES_ECB_DECRYPT_UPDATE_TIMEOUT   (6300U)

/*
Timeout in ticks, which is variable part for Cry_HsmAesEcbDecryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 458]                               */
#define CRY_HSM_AES_ECB_DECRYPT_PER_BYTE_UPDATE_TIMEOUT   (0U)
/*
The maximum number of bytes for ECB decrypt update
is: 4294967295 byte(s)
*/
      
/*
Timeout in ticks for Cry_HsmAesEcbDecryptFinish API.
This parameter is dummy for Cry_HsmAesEcbDecryptFinish API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 459]                               */
#define CRY_HSM_AES_ECB_DECRYPT_FINISH_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmAesEncryptStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmAesEncryptStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 460]                               */
#define CRY_HSM_AES_ENCRYPT_START_TIMEOUT   (0U)

#define CRY_HSM_ENCRYPT_START_TIMEOUT   (0U)

#define CRY_HSM_DECRYPT_START_TIMEOUT   (0U)


/*
Timeout in ticks, which is the constant part for
Cry_HsmAesEncryptUpdate timeout
*/
/* Traceability    : [$Satisfies $CDS_CDRV 461]                               */
#define CRY_HSM_AES_ENCRYPT_UPDATE_TIMEOUT   (6300U)

#define CRY_HSM_ENCRYPT_UPDATE_TIMEOUT   (48000U)

#define CRY_HSM_DECRYPT_UPDATE_TIMEOUT   (48000U)


/*
Timeout in ticks, which is variable part for Cry_HsmAesEncryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 462]                               */
#define CRY_HSM_AES_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT   (300U)

#define CRY_HSM_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT   (3000U)

#define CRY_HSM_DECRYPT_PER_BYTE_UPDATE_TIMEOUT   (3000U)

/*
The maximum number of bytes for AES encrypt update
is: 14316536 byte(s)
*/

/*
Timeout in ticks for Cry_HsmAesEncryptFinish API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 463]                               */
#define CRY_HSM_AES_ENCRYPT_FINISH_TIMEOUT   (2700U)

#define CRY_HSM_ENCRYPT_FINISH_TIMEOUT   (2700U)

#define CRY_HSM_DECRYPT_FINISH_TIMEOUT   (2700U)


/*
Timeout in ticks for Cry_HsmAesDecryptStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmAesDecryptStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 464]                               */
#define CRY_HSM_AES_DECRYPT_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for
Cry_HsmAesDecryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 465]                               */
#define CRY_HSM_AES_DECRYPT_UPDATE_TIMEOUT   (6300U)

/*
Timeout in ticks, which is variable part for Cry_HsmAesDecryptUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 466]                               */
#define CRY_HSM_AES_DECRYPT_PER_BYTE_UPDATE_TIMEOUT   (300U)
/*
The maximum number of bytes for AES decrypt update
is: 14316536 byte(s)
*/

/*
Timeout in ticks for Cry_HsmAesDecryptFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 467]                               */
#define CRY_HSM_AES_DECRYPT_FINISH_TIMEOUT   (2700U)

/*
Timeout in ticks for Cry_HsmAesCMacGenerateStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmAesCMacGenerateStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 468]                               */
#define CRY_HSM_AES_CMAC_GENERATE_START_TIMEOUT   (0U)

#define CRY_HSM_SIGNATURE_GENERATE_START_TIMEOUT   (0U)

#define CRY_HSM_SIGNATURE_VERIFY_START_TIMEOUT   (0U)



/*
Timeout in ticks, which is the constant part for
Cry_HsmAesCMacGenerateUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 469]                               */
#define CRY_HSM_AES_CMAC_GENERATE_UPDATE_TIMEOUT   (4500U)

#define CRY_HSM_SIGNATURE_GENERATE_UPDATE_TIMEOUT   (3000000000U)

#define CRY_HSM_SIGNATURE_VERIFY_UPDATE_TIMEOUT   (3000000000U)


/*
Timeout in ticks, which is variable part for Cry_HsmAesCMacGenerateUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 470]                               */
#define CRY_HSM_AES_CMAC_GENERATE_PER_BYTE_UPDATE_TIMEOUT   (300U)

#define CRY_HSM_SIGNATURE_GENERATE_PER_BYTE_UPDATE_TIMEOUT   (300U)

#define CRY_HSM_SIGNATURE_VERIFY_PER_BYTE_UPDATE_TIMEOUT   (300U)


/*
The maximum number of bytes for AES CMAC generate update
is: 14316542 byte(s)
*/

/*
Timeout in ticks for Cry_HsmAesCMacGenerateFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 471]                               */
#define CRY_HSM_AES_CMAC_GENERATE_FINISH_TIMEOUT   (4800U)

#define CRY_HSM_SIGNATURE_GENERATE_FINISH_TIMEOUT   (480000U)

#define CRY_HSM_SIGNATURE_VERIFY_FINISH_TIMEOUT   (480000U)



/*
Timeout in ticks for Cry_HsmAesCMacVerifyStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmAesCMacVerifyStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 472]                               */
#define CRY_HSM_AES_CMAC_VERIFY_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for
Cry_HsmAesCMacVerifyUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 473]                               */
#define CRY_HSM_AES_CMAC_VERIFY_UPDATE_TIMEOUT   (4200U)

/*
Timeout in ticks, which is variable part for Cry_HsmAesCMacVerifyUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 474]                               */
#define CRY_HSM_AES_CMAC_VERIFY_PER_BYTE_UPDATE_TIMEOUT   (300U)
/*
The maximum number of bytes for AES CMAC verify update
is: 14316543 byte(s)
*/

/*
Timeout in ticks for Cry_HsmAesCMacVerifyFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 475]                               */
#define CRY_HSM_AES_CMAC_VERIFY_FINISH_TIMEOUT   (7800U)

/*
Timeout in ticks for Cry_HsmKeyLoadStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmKeyLoadStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 476]                               */
#define CRY_HSM_KEY_LOAD_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for
Cry_HsmKeyLoadUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 477]                               */
#define CRY_HSM_KEY_LOAD_UPDATE_TIMEOUT   (345416400U)

/*
Timeout in ticks, which is variable part for Cry_HsmKeyLoadUpdate API
This parameter is dummy for Cry_HsmKeyLoadUpdate API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 478]                               */
#define CRY_HSM_KEY_LOAD_PER_BYTE_UPDATE_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmKeyLoadFinish API.
This parameter is dummy as timeout is not applicable for
Cry_HsmKeyLoadFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 479]                               */
#define CRY_HSM_KEY_LOAD_FINISH_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmKeyLoadPlainStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmKeyLoadPlainStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 480]                               */
#define CRY_HSM_KEY_LOAD_PLAIN_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for
Cry_HsmKeyLoadPlainUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 481]                               */
#define CRY_HSM_KEY_LOAD_PLAIN_UPDATE_TIMEOUT   (345416400U)

/*
Timeout in ticks, which is variable part for Cry_HsmKeyLoadPlainUpdate API.
This parameter is dummy for Cry_HsmKeyLoadPlainUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 482]                               */
#define CRY_HSM_KEY_LOAD_PLAIN_PER_BYTE_UPDATE_TIMEOUT   (0U)

/*
Timeout in ticks Cry_HsmKeyLoadPlainFinish API.
This parameter is dummy as timeout is not applicable for
Cry_HsmKeyLoadPlainFinish API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 483]                               */
#define CRY_HSM_KEY_LOAD_PLAIN_FINISH_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmKeyLoadStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmKeyLoadStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 484]                               */
#define CRY_HSM_KEY_LOAD_RAMKEY_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for
Cry_HsmKeyLoadUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 485]                               */
#define CRY_HSM_KEY_LOAD_RAMKEY_UPDATE_TIMEOUT   (345416400U)

/*
Timeout in ticks, which is variable part for Cry_HsmKeyLoadUpdate API.
This parameter is dummy for Cry_HsmKeyLoadUpdate API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 486]                               */
#define CRY_HSM_KEY_LOAD_RAMKEY_PER_BYTE_UPDATE_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmKeyLoadFinish API.
This parameter is dummy as timeout is not applicable for
Cry_HsmKeyLoadFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 487]                               */
#define CRY_HSM_KEY_LOAD_RAMKEY_FINISH_TIMEOUT   (0U)
/*
Timeout in ticks for Cry_HsmKeyExportStart API.
This parameter is dummy as timeout is not applicable for
Cry_HsmKeyExportStart API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 488]                               */
#define CRY_HSM_KEY_EXPORT_START_TIMEOUT   (0U)

/*
Timeout in ticks, which is the constant part for Cry_HsmKeyExportUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 489]                               */
#define CRY_HSM_KEY_EXPORT_UPDATE_TIMEOUT   (45900U)

/*
Timeout in ticks, which is variable part for Cry_HsmKeyExportUpdate API.
This parameter is dummy for Cry_HsmKeyExportUpdate API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 490]                               */
#define CRY_HSM_KEY_EXPORT_PER_BYTE_UPDATE_TIMEOUT   (0U)

/*
Timeout in ticks for Cry_HsmKeyExportFinish API.
This parameter is dummy as timeout is not applicable for
Cry_HsmKeyExportFinish API.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 491]                               */
#define CRY_HSM_KEY_EXPORT_FINISH_TIMEOUT   (0U)

/* Service ID for Cry_HsmAesCMacGenerateStart API  */
/* Traceability    : [$Satisfies $CDS_CDRV 492]                               */
#define CRY_HSM_SID_MAC_GENERATE_START                               (6U)

/* Service ID for Cry_HsmMacGenerateUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 493]*/
#define CRY_HSM_SID_MAC_GENERATE_UPDATE                              (7U)

/* Service ID for Cry_HsmMacGenerateFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 494]*/
#define CRY_HSM_SID_MAC_GENERATE_FINISH                              (8U)

/* Service ID for Cry_HsmMacVerifyStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 495]*/
#define CRY_HSM_SID_MAC_VERIFY_START                                 (9U)

/* Service ID for Cry_HsmMacVerifyUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 496]*/
#define CRY_HSM_SID_MAC_VERIFY_UPDATE                                (10U)

/* Service ID for Cry_HsmMacVerifyFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 497]*/
#define CRY_HSM_SID_MAC_VERIFY_FINISH                               (11U)

/* Service ID for Cry_HsmRandomSeedInitStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 498]*/
#define CRY_HSM_SID_RND_SEED_INIT_START                            (12U)

/* Service ID for Cry_HsmRandomSeedInitUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 499]*/
#define CRY_HSM_SID_RND_SEED_INIT_UPDATE                           (13U)

/* Service ID for Cry_HsmRandomSeedInitFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 500]*/
#define CRY_HSM_SID_RND_SEED_INIT_FINISH                           (14U)

/* Service ID for Cry_HsmRandomSeedExtendStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 501]*/
#define CRY_HSM_SID_RND_SEED_EXTEND_START                          (15U)

/* Service ID for Cry_HsmRandomSeedExtendUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 502]*/
#define CRY_HSM_SID_RND_SEED_EXTEND_UPDATE                         (16U)

/* Service ID for Cry_HsmRandomSeedExtendFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 503]*/
#define CRY_HSM_SID_RND_SEED_EXTEND_FINISH                         (17U)

/* Service ID for Cry_HsmRandomGenerate API */
/* Traceability    : [$Satisfies $CDS_CDRV 504]*/
#define CRY_HSM_SID_RND_GENERATE                                   (18U)

/* Service ID for Cry_HsmTrueRandomGenerate API */
/* Traceability    : [$Satisfies $CDS_CDRV 505]*/
#define CRY_HSM_SID_TRUE_RND_GENERATE                              (19U)

/* Service ID for Cry_HsmAesEncryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 506]*/
#define CRY_HSM_SID_AES_ENCRYPT_START                                 (20U)

/* Service ID for Cry_HsmAesEncryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 507]*/
#define CRY_HSM_SID_AES_ENCRYPT_UPDATE                                (21U)

/* Service ID for Cry_HsmAesEncryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 508]*/
#define CRY_HSM_SID_AES_ENCRYPT_FINISH                                (22U)

/* Service ID for Cry_HsmAesDecryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 509]*/
#define CRY_HSM_SID_AES_DECRYPT_START                                 (23U)

/* Service ID for Cry_HsmAesDecryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 510]*/
#define CRY_HSM_SID_AES_DECRYPT_UPDATE                                (24U)

/* Service ID for Cry_HsmAesDecryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 511]*/
#define CRY_HSM_SID_AES_DECRYPT_FINISH                                (25U)

/* Service ID for Cry_HsmAesEcbEncryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 512]*/
#define CRY_HSM_SID_AES_ECB_ENCRYPT_START                              (26U)

/* Service ID for Cry_HsmAesEcbEncryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 513]*/
#define CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE                             (27U)

/* Service ID for Cry_HsmAesEcbEncryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 514]*/
#define CRY_HSM_SID_AES_ECB_ENCRYPT_FINISH                             (28U)

/* Service ID for Cry_HsmAesEcbDecryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 515]*/
#define CRY_HSM_SID_AES_ECB_DECRYPT_START                               (29U)

/* Service ID for Cry_HsmAesEcbDecryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 516]*/
#define CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE                              (30U)

/* Service ID for Cry_HsmAesEcbDecryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 517]*/
#define CRY_HSM_SID_AES_ECB_DECRYPT_FINISH                              (31U)

/* Service ID for Cry_HsmKeyLoadStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 524]*/
#define CRY_HSM_SID_KEY_LOAD_START                                       (38U)

/* Service ID for Cry_HsmKeyLoadUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 525]*/
#define CRY_HSM_SID_KEY_LOAD_UPDATE                                      (39U)

/* Service ID for Cry_HsmKeyLoadFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 526]*/
#define CRY_HSM_SID_KEY_LOAD_FINISH                                      (40U)

/* Service ID for Cry_HsmKeyLoadPlainStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 527]*/
#define CRY_HSM_SID_KEY_LOAD_PLAIN_START                                 (41U)

/* Service ID for CryHsmKeyLoadPlainUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 528]*/
#define CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE                                 (48U)

/* Service ID for Cry_HsmKeyLoadPlainFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 529]*/
#define CRY_HSM_SID_KEY_LOAD_PLAIN_FINISH                                 (49U)

/* Service ID for Cry_HsmKeyExportStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 530]*/
#define CRY_HSM_SID_KEY_EXPORT_START                                     (50U)

/* Service ID for Cry_HsmKeyExportUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 531]*/
#define CRY_HSM_SID_KEY_EXPORT_UPDATE                                    (51U)

/* Service ID for Cry_HsmKeyExportFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 532]*/
#define CRY_HSM_SID_KEY_EXPORT_FINISH                                    (52U)

/* Service ID for CryHsmDebugStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 634]*/
#define CRY_HSM_SID_DEBUG_START                                           (254U)

/* Service ID for CryHsmDebugFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 635]*/
#define CRY_HSM_SID_DEBUG_FINISH                                          (253U)

/* Service ID for CryHsmGetUid API */
/* Traceability    : [$Satisfies $CDS_CDRV 639]*/
#define CRY_HSM_SID_GETUID                                              (252U)

/* Service ID for CryHsmSidBootFailure API */
/* Traceability    : [$Satisfies $CDS_CDRV 739]*/
#define CRY_HSM_SID_BOOT_FAILURE                                        (251U)

/* Service ID for CryHsmSidBootOk API */
/* Traceability    : [$Satisfies $CDS_CDRV 740]*/
#define CRY_HSM_SID_BOOT_OK                                             (250U)

/* Service ID for Cry_HsmAesGcmEncryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 518]*/
#define CRY_HSM_SID_AES_GCM_ENCRYPT_START                                (238U)

/* Service ID for Cry_HsmAesGcmEncryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 519]*/
#define CRY_HSM_SID_AES_GCM_ENCRYPT_UPDATE                               (239U)

/* Service ID for Cry_HsmAesGcmEncryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 520]*/
#define CRY_HSM_SID_AES_GCM_ENCRYPT_FINISH                               (240U)

/* Service ID for Cry_HsmAesGcmDecryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 521]*/
#define CRY_HSM_SID_AES_GCM_DECRYPT_START                                (241U)

/* Service ID for Cry_HsmAesGcmDecryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 522]*/
#define CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE                               (242U)

/* Service ID for Cry_HsmAesGcmDecryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 523]*/
#define CRY_HSM_SID_AES_GCM_DECRYPT_FINISH                               (243U)

/* Service ID for CryHsmSidAesXtsEncryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 710]*/
#define CRY_HSM_SID_AES_XTS_ENCRYPT_START                               (244U)

/* Service ID for CryHsmSidAesXtsEncryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 711]*/
#define CRY_HSM_SID_AES_XTS_ENCRYPT_UPDATE                               (245U)

/* Service ID for CryHsmSidAesXtsEncryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 712]*/
#define CRY_HSM_SID_AES_XTS_ENCRYPT_FINISH                               (246U)

/* Service ID for CryHsmSidAesXtsDecryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 713]*/
#define CRY_HSM_SID_AES_XTS_DECRYPT_START                               (247U)

/* Service ID for CryHsmSidAesXtsDecryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 714]*/
#define CRY_HSM_SID_AES_XTS_DECRYPT_UPDATE                               (248U)

/* Service ID for CryHsmSidAesXtsDecryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 715]*/
#define CRY_HSM_SID_AES_XTS_DECRYPT_FINISH                               (249U)

/* Service ID for Cry_HsmInit API */
/* Traceability    : [$Satisfies $CDS_CDRV 533]*/
#define CRY_HSM_SID_INIT                                                 (53U)

#define CRY_HSM_SID_SIGNATURE_GENERATE                             (54U)

#define CRY_HSM_SID_SIGNATURE_VERIFY                            (55U)

#define CRY_HSM_SID_ENCRYPT                           (56U)

#define CRY_HSM_SID_DECRYPT                             (57U)


/* Service ID for CryModule API */
/* Traceability    : [$Satisfies $CDS_CDRV 534][$Satisfies $CDS_CDRV 202]*/
#define CRY_MODULE_ID                                                 (255U)

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
**                      Global Inline Function Definitions                    **
*******************************************************************************/

/* end of CRY_HSM_CFG_H */
#endif
