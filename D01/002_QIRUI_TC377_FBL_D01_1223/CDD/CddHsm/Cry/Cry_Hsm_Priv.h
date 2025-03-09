/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : Cry_Hsm_Priv.h                                              **
**                                                                           **
**  VERSION :     4.0.0                                                      **
**                                                                           **
**  DATE       : 2018-06-13                                                  **
**                                                                           **
**  AUTHOR      :  Prashant K                                                **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of Cry module                                **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
**                                                                           **
******************************************************************************/

#ifndef CRY_HSM_PRIV_H
#define CRY_HSM_PRIV_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "HsmCom_Priv.h"
#include "Hsm_Mcal.h"
#include "Cry_HsmTypes.h"
#include "Csm.h"
#include "McalLib.h"

#if CSM_USE_SYNC_JOB_PROCESSING == STD_OFF
#include "Csm_Cbk.h"
#endif

#if (CRY_HSM_DEV_ERROR_DETECT != STD_OFF)
#include "Det.h"
#endif

/* As null is not defined STD_OFF is taken as replacement */
#if(CRY_HSM_E_POLICY_VIOLATION != 0U)
#include "Dem.h"
#endif

#if(CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF)
#include "BswM.h"
#endif


/******************************************************************************
**                     Global Macro Definition                               **
******************************************************************************/

#define DEV_NO_ERROR FALSE
#define DEV_ERROR TRUE

#define CRY_HSM_KEY_EXTRACT_SIZE    64UL  /**Total M1, M2, M3 size in bytes */
#define CRY_HSM_KEY_M4M5_SIZE    48UL  /* Total size of M4 and M5 in
                                                       key structure */
#define CRY_HSM_BLOCK_SIZE          16UL  /*Default data block size in bytes */
#define CRY_HSM_KEY_M5OFFSET    96U
#define CRY_HSM_KEY_M1OFFSET    0U   /* M1 offset in key structure */
#define CRY_HSM_KEY_M2OFFSET    16U /* M2 offset in key structure */
#define CRY_HSM_KEY_M3OFFSET    48U /* M3 offset in key structure */
#define CRY_HSM_KEY_M4OFFSET    64U /* M4 offset in key structure */
#define CRY_HSM_KEY_M5OFFSET    96U /* M5 offset in key structure */
#define CRY_HSM_OFFSET_KEY1    3U
#define CRY_HSM_OFFSET_KEY11    9U
#define CRY_HSM_OFFSET_PLAINKEY  8U
#define CRY_HSM_OFFSET_MASTER    20U
#define CRY_HSM_INVALID_KEY    0xFFU
#define CRY_HSM_ZERO   (0U)
#define CRY_UID_LEN (15U)
#define CRY_GCM_IV_LENGTH        12U

#define UNUSED_POINTER(PointerName) {if((PointerName) != NULL_PTR)\
                                    {/* Do Nothing*/ }}

#if CSM_USE_SYNC_JOB_PROCESSING == STD_OFF
#define CRY_HSM_MAINFUNCTION_SID    255UL
#endif

#if (CRY_HSM_DEV_ERROR_DETECT != STD_OFF)

#define DET_REPORT(SvId, ErrId, DetErrStat)                                  \
{    Det_ReportError(CSM_MODULE_ID,                                          \
                        CRY_HSM_INSTANCE_ID, (uint8)(SvId), (uint8)(ErrId)); \
     DetErrStat = DEV_ERROR;                                                 \
}

#define PTR_VALIDATION(SvId, InPtr, DetErrStat)                               \
{                                                                           \
    if ((InPtr) == NULL_PTR)                                                  \
    {                                                                       \
        DET_REPORT(SvId, CRY_HSM_E_PARAM_PTR_INVALID, DetErrStat)   \
    }                                                   \
}
#define INIT_VALIDATION(SvId,Status, DetErrStat)                    \
{                                                       \
    if (Status != CRY_HSM_INITIALIZED)                  \
    {                                                   \
        DET_REPORT(SvId, CRY_HSM_E_UNINIT, DetErrStat)              \
    }                                                   \
}
#define START_VALIDATION(SvId,Status, DetErrStat)                   \
{                                                       \
    if (Status != CRY_HSM_PRIM_STARTED)                 \
    {                                                   \
        DET_REPORT(SvId, CRY_HSM_E_SERVICE_NOT_STARTED, DetErrStat) \
    }                                                   \
}
#define KEY_VALIDATION(SvId,KeyId, DetErrStat)                     \
{                                                                   \
    if ((KeyId == HSMCOM_INVALID_KEY)||                             \
            ((KeyId > HSMCOM_RAM_KEY)&&(KeyId < HSMCOM_KEY_11))||   \
            (KeyId > HSMCOM_KEY_20))                                \
    {                                                               \
        DET_REPORT(SvId, CRY_HSM_E_PARAM_KEY_TYPE_INVALID, DetErrStat)      \
    }                                                               \
}

#endif

typedef enum
{
  CRY_HSM_UNINITIALIZED,
  CRY_HSM_INITIALIZED
} Cry_HsmStateRef;

typedef enum
{
  DET_NOERROR,
  DET_ERROR
} Cry_DetResult;

typedef enum
{
  CRY_HSM_PRIM_NOT_STARTED,
  CRY_HSM_PRIM_STARTED,
  CRY_HSM_PRIM_FINISHED
} Cry_PrimStatusVal;


#if(CRY_HSM_E_POLICY_VIOLATION != 0U)
#define DEM_REPORT(DemErr)                                          \
{                                                                   \
  if((DemErr == HSMCOM_ERC_KEY_NOT_AVAILABLE)||                     \
            (DemErr == HSMCOM_ERC_KEY_INVALID)||                    \
            (DemErr == HSMCOM_ERC_KEY_EMPTY)||                      \
            (DemErr == HSMCOM_ERC_KEY_WRITE_PROTECTED))             \
  {                                                               \
    Dem_ReportErrorStatus((uint16)(CRY_HSM_E_POLICY_VIOLATION)   \
                         , (uint8)(DEM_EVENT_STATUS_FAILED));       \
  }                                                               \
}
#endif
/** Traceability    : [$Satisfies $CDS_CDRV 577] [$Satisfies $CDS_CDRV 578]  **/
#if(CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF)
#define BSWM_REPORT(ErrorVal)                                                \
{                                                                            \
  if ((ErrorVal) != HSMCOM_ERC_NO_ERROR)                                   \
  {                                                                        \
    if ( (ErrorVal == HSMCOM_ERC_TRNG_FIFO_EMPTY) ||                     \
         (ErrorVal == HSMCOM_ERC_CRYPTO_ERROR)    ||                     \
         (ErrorVal == HSMCOM_ERC_COMMAND_INVALID) ||                     \
         (ErrorVal == HSMCOM_ERC_CANCELLED)  )                            \
    {                                                                    \
      ErrorVal =  HSMCOM_ERC_GENERAL_FAILURE;                          \
    }                                                                    \
    //BswM_RequestMode((uint16)(CRY_MODULE_ID), (uint8)(ErrorVal));        \
  }                                                                        \
}
#endif


/* Macro for static initialization of a Cry_HsmTimeoutType structure
 * This macro is used in the static initialization of the
 *  Cry_<Primitive>ConfigType constants
 * defined in Cry_Hsm_Cfg.c
 * Parameters:
 * Ts  : .timeoutStart value
 * Tuc : .timeoutUpdateConst value
 * Tub : .timeoutUpdateperByte value
 * Tf  : .timeoutFinish value
 * */

#define CRY_HSM_TIMEOUT_CONST(Ts,Tuc,Tub,Tf) \
            {.TimeoutStart = (Ts),        \
             .TimeoutUpdateConst = (Tuc),   \
             .TimeoutUpdateperByte = (Tub), \
             .TimeoutFinish = (Tf) }


/* Macros to get the timeOut values for the Cry_<Primitive>* functions,
 * converted to microseconds
 */
#define CRY_HSM_GET_UPDATE_TIMEOUT_TICKS(CfgPtr,Nb)\
            ((CfgPtr)->TimeOut.TimeoutUpdateConst + \
            ((CfgPtr)->TimeOut.TimeoutUpdateperByte * (Nb)))

#define CRY_HSM_GET_START_TIMEOUT_TICKS(cfgPtr) ((cfgPtr)->TimeOut.TimeoutStart)
#define CRY_HSM_GET_FINISH_TIMEOUT_TICKS(cfgPtr) \
                                       ((cfgPtr)->TimeOut.TimeoutFinish)


/* Macros defining the timeouts for the Cry_<Primitive>ConfigType constants
 * The names of these macros are fixed, they are used in Cry_Hsm_Cfg.c for
 * static initialization of the Cry_<Primitive> configurations
 */
/* Timeout value for Cry_HsmRandomSeedInit   */
#define CRY_HSM_RANDOM_SEED_INIT_ALL_TIMEOUT  \
             CRY_HSM_TIMEOUT_CONST(CRY_HSM_RND_SEED_INIT_START_TIMEOUT,\
                     CRY_HSM_RND_SEED_INIT_UPDATE_TIMEOUT,\
                     CRY_HSM_RND_SEED_INIT_PER_BYTE_UPDATE_TIMEOUT,\
                     CRY_HSM_RND_SEED_INIT_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmRandomSeedExtend */
#define CRY_HSM_RANDOM_SEED_EXTEND_ALL_TIMEOUT \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_RND_SEED_EXTEND_START_TIMEOUT,\
                      CRY_HSM_RND_SEED_EXTEND_UPDATE_TIMEOUT,\
                      CRY_HSM_RND_SEED_EXTEND_PER_BYTE_UPDATE_TIMEOUT,\
                      CRY_HSM_RND_SEED_EXTEND_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmRandomGenerate   */
#define CRY_HSM_RANDOM_GENERATE_ALL_TIMEOUT    \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_RND_GENERATE_START_TIMEOUT,\
                      CRY_HSM_RND_GENERATE_UPDATE_TIMEOUT,\
                      CRY_HSM_RND_GENERATE_PER_BYTE_UPDATE_TIMEOUT,\
                      CRY_HSM_RND_GENERATE_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmHash   */
#define CRY_HSM_HASH_ALL_TIMEOUT    \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_HASH_START_TIMEOUT,\
                      CRY_HSM_HASH_UPDATE_TIMEOUT,\
                      CRY_HSM_HASH_PER_BYTE_UPDATE_TIMEOUT,\
                      CRY_HSM_HASH_FINISH_TIMEOUT)


/* Timeout value for Cry_HsmTrueRandomGenerate   */
#define CRY_HSM_TRUE_RANDOM_GENERATE_ALL_TIMEOUT    \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_TRUE_RND_GENERATE_START_TIMEOUT,\
                      CRY_HSM_TRUE_RND_GENERATE_UPDATE_TIMEOUT,\
                      CRY_HSM_TRUE_RND_GENERATE_PER_BYTE_UPDATE_TIMEOUT,\
                      CRY_HSM_TRUE_RND_GENERATE_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmAesEncrypt
*/
#define CRY_HSM_AES_ENCRYPT_ALL_TIMEOUT      \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_AES_ENCRYPT_START_TIMEOUT,\
                      CRY_HSM_AES_ENCRYPT_UPDATE_TIMEOUT,\
                      CRY_HSM_AES_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT,\
                      CRY_HSM_AES_ENCRYPT_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmAesDecrypt
*/
#define CRY_HSM_AES_DECRYPT_ALL_TIMEOUT  \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_AES_DECRYPT_START_TIMEOUT,\
                    CRY_HSM_AES_DECRYPT_UPDATE_TIMEOUT,\
                    CRY_HSM_AES_DECRYPT_PER_BYTE_UPDATE_TIMEOUT,\
                    CRY_HSM_AES_DECRYPT_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmAesEcbEncrypt */
#define CRY_HSM_AES_ECB_ENCRYPT_ALL_TIMEOUT \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_AES_ECB_ENCRYPT_START_TIMEOUT,\
                            CRY_HSM_AES_ECB_ENCRYPT_UPDATE_TIMEOUT,\
                            CRY_HSM_AES_ECB_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT,\
                            CRY_HSM_AES_ECB_ENCRYPT_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmAesEcbDecrypt*/
#define CRY_HSM_AES_ECB_DECRYPT_ALL_TIMEOUT \
               CRY_HSM_TIMEOUT_CONST(CRY_HSM_AES_ECB_DECRYPT_START_TIMEOUT,\
                            CRY_HSM_AES_ECB_DECRYPT_UPDATE_TIMEOUT,\
                            CRY_HSM_AES_ECB_DECRYPT_PER_BYTE_UPDATE_TIMEOUT,\
                            CRY_HSM_AES_ECB_DECRYPT_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmAesXtsEncrypt */
#define CRY_HSM_AES_XTS_ENCRYPT_ALL_TIMEOUT \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_AES_XTS_ENCRYPT_START_TIMEOUT,\
                            CRY_HSM_AES_XTS_ENCRYPT_UPDATE_TIMEOUT,\
                            CRY_HSM_AES_XTS_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT,\
                            CRY_HSM_AES_XTS_ENCRYPT_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmAesXtsDecrypt*/
#define CRY_HSM_AES_XTS_DECRYPT_ALL_TIMEOUT \
               CRY_HSM_TIMEOUT_CONST(CRY_HSM_AES_XTS_DECRYPT_START_TIMEOUT,\
                            CRY_HSM_AES_XTS_DECRYPT_UPDATE_TIMEOUT,\
                            CRY_HSM_AES_XTS_DECRYPT_PER_BYTE_UPDATE_TIMEOUT,\
                            CRY_HSM_AES_XTS_DECRYPT_FINISH_TIMEOUT)
/* Timeout value for Cry_HsmAesCMacGenerate
*/
#define CRY_HSM_AES_CMAC_GENERATE_ALL_TIMEOUT \
               CRY_HSM_TIMEOUT_CONST(CRY_HSM_AES_CMAC_GENERATE_START_TIMEOUT,\
                        CRY_HSM_AES_CMAC_GENERATE_UPDATE_TIMEOUT,\
                        CRY_HSM_AES_CMAC_GENERATE_PER_BYTE_UPDATE_TIMEOUT,\
                        CRY_HSM_AES_CMAC_GENERATE_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmSignatureGenerate
*/
#define CRY_HSM_SIGNATURE_GENERATE_ALL_TIMEOUT \
               CRY_HSM_TIMEOUT_CONST(CRY_HSM_SIGNATURE_GENERATE_START_TIMEOUT,\
                        CRY_HSM_SIGNATURE_GENERATE_UPDATE_TIMEOUT,\
                        CRY_HSM_SIGNATURE_GENERATE_PER_BYTE_UPDATE_TIMEOUT,\
                        CRY_HSM_SIGNATURE_GENERATE_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmSignatureVerify
*/
#define CRY_HSM_SIGNATURE_VERIFY_ALL_TIMEOUT \
               CRY_HSM_TIMEOUT_CONST(CRY_HSM_SIGNATURE_VERIFY_START_TIMEOUT,\
                        CRY_HSM_SIGNATURE_VERIFY_UPDATE_TIMEOUT,\
                        CRY_HSM_SIGNATURE_VERIFY_PER_BYTE_UPDATE_TIMEOUT,\
                        CRY_HSM_SIGNATURE_VERIFY_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmEncrypt
*/
#define CRY_HSM_ENCRYPT_ALL_TIMEOUT      \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_ENCRYPT_START_TIMEOUT,\
                      CRY_HSM_ENCRYPT_UPDATE_TIMEOUT,\
                      CRY_HSM_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT,\
                      CRY_HSM_ENCRYPT_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmDecrypt
*/
#define CRY_HSM_DECRYPT_ALL_TIMEOUT      \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_DECRYPT_START_TIMEOUT,\
                      CRY_HSM_DECRYPT_UPDATE_TIMEOUT,\
                      CRY_HSM_DECRYPT_PER_BYTE_UPDATE_TIMEOUT,\
                      CRY_HSM_DECRYPT_FINISH_TIMEOUT)


/* Timeout value for Cry_HsmAesCMacVerify
*/
#define CRY_HSM_AES_CMAC_VERIFY_ALL_TIMEOUT \
               CRY_HSM_TIMEOUT_CONST(CRY_HSM_AES_CMAC_VERIFY_START_TIMEOUT,\
                            CRY_HSM_AES_CMAC_VERIFY_UPDATE_TIMEOUT,\
                            CRY_HSM_AES_CMAC_VERIFY_PER_BYTE_UPDATE_TIMEOUT,\
                            CRY_HSM_AES_CMAC_VERIFY_FINISH_TIMEOUT)

/* Timeout constant for Cry_HsmKeyLoad
*/
#define CRY_HSM_KEY_LOAD_ALL_TIMEOUT  \
               CRY_HSM_TIMEOUT_CONST(CRY_HSM_KEY_LOAD_START_TIMEOUT,\
                            CRY_HSM_KEY_LOAD_UPDATE_TIMEOUT,\
                            CRY_HSM_KEY_LOAD_PER_BYTE_UPDATE_TIMEOUT,\
                            CRY_HSM_KEY_LOAD_FINISH_TIMEOUT)

/* Timeout constant for Cry_HsmKeyLoad
*/
#define CRY_HSM_KEY_LOAD_RAMKEY_ALL_TIMEOUT \
               CRY_HSM_TIMEOUT_CONST(CRY_HSM_KEY_LOAD_RAMKEY_START_TIMEOUT,\
                       CRY_HSM_KEY_LOAD_RAMKEY_UPDATE_TIMEOUT,\
                       CRY_HSM_KEY_LOAD_RAMKEY_PER_BYTE_UPDATE_TIMEOUT,\
                       CRY_HSM_KEY_LOAD_RAMKEY_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmKeyLoadPlain     */
#define CRY_HSM_KEY_LOAD_PLAIN_ALL_TIMEOUT \
               CRY_HSM_TIMEOUT_CONST(CRY_HSM_KEY_LOAD_PLAIN_START_TIMEOUT,\
                              CRY_HSM_KEY_LOAD_PLAIN_UPDATE_TIMEOUT,\
                              CRY_HSM_KEY_LOAD_PLAIN_PER_BYTE_UPDATE_TIMEOUT,\
                              CRY_HSM_KEY_LOAD_PLAIN_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmKeyExport        */
#define CRY_HSM_KEY_EXPORT_ALL_TIMEOUT  \
               CRY_HSM_TIMEOUT_CONST(CRY_HSM_KEY_EXPORT_START_TIMEOUT,\
                       CRY_HSM_KEY_EXPORT_UPDATE_TIMEOUT,\
                       CRY_HSM_KEY_EXPORT_PER_BYTE_UPDATE_TIMEOUT,\
                       CRY_HSM_KEY_EXPORT_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmGcmEncrypt*/
#define CRY_HSM_AES_GCM_ENCRYPT_ALL_TIMEOUT      \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_AES_GCM_ENCRYPT_START_TIMEOUT,\
                      CRY_HSM_AES_GCM_ENCRYPT_UPDATE_TIMEOUT,\
                      CRY_HSM_AES_GCM_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT,\
                      CRY_HSM_AES_GCM_ENCRYPT_FINISH_TIMEOUT)

/* Timeout value for Cry_HsmGcmDecrypt*/
#define CRY_HSM_AES_GCM_DECRYPT_ALL_TIMEOUT      \
              CRY_HSM_TIMEOUT_CONST(CRY_HSM_AES_GCM_DECRYPT_START_TIMEOUT,\
                      CRY_HSM_AES_GCM_DECRYPT_UPDATE_TIMEOUT,\
                      CRY_HSM_AES_GCM_DECRYPT_PER_BYTE_UPDATE_TIMEOUT,\
                      CRY_HSM_AES_GCM_DECRYPT_FINISH_TIMEOUT)

/* INTERNAL_DEBUG is used for debugging purpose */
#define INTERNAL_DEBUG    STD_OFF


/******************************************************************************
**                     Global Enumeration Definitions                        **
******************************************************************************/

typedef enum
{
  ASYNC_STATE_IDLE,
  ASYNC_STATE_START,
  ASYNC_STATE_UPDATE,
  ASYNC_STATE_FINISH
} Cry_HsmStateType;
/** Traceability    : [$Satisfies $CDS_CDRV 566]                            **/
typedef enum
{
  CRY_HSM_E_PARAM_PTR_INVALID         = CSM_E_PARAM_PTR_INVALID,
  CRY_HSM_E_SERVICE_NOT_STARTED       = CSM_E_SERVICE_NOT_STARTED,
  CRY_HSM_E_PARAM_METHOD_INVALID      = CSM_E_PARAM_METHOD_INVALID,
  CRY_HSM_E_PARAM_KEY_TYPE_INVALID    = CSM_E_PARAM_KEY_TYPE_INVALID,
  CRY_HSM_E_UNINIT                    = CSM_E_UNINIT,
  CRY_HSM_E_BUFFER_TOO_SMALL          = CSM_E_BUFFER_TOO_SMALL
} Cry_DetErrorType;

typedef enum
{
  CRY_HSM_RANDOM_SEED_INIT   ,
  CRY_HSM_RANDOM_SEED_EXTEND ,
  CRY_HSM_RANDOM_GENERATE    ,
  CRY_HSM_TRUE_RANDOM_GENERATE ,
  CRY_HSM_MAC_GENERATE       ,
  CRY_HSM_MAC_VERIFY         ,
  CRY_HSM_SYM_ENCRYPT        ,
  CRY_HSM_SYM_DECRYPT        ,
  CRY_HSM_KEY_LOAD           ,
  CRY_HSM_KEY_LOAD_PLAIN     ,
  CRY_HSM_KEY_WRAP           ,
  CRY_HSM_SYM_ECB_ENCRYPT    ,
  CRY_HSM_SYM_ECB_DECRYPT    ,
  CRY_HSM_UID                ,
  CRY_HSM_DEBUG              ,
#if (CRY_HSM_SECURE_BOOT == STD_ON)
  CRY_HSM_BOOT_FAILURE       ,
  CRY_HSM_BOOT_OK            ,
#endif
  CRY_HSM_SYM_XTS_ENCRYPT    ,
  CRY_HSM_SYM_XTS_DECRYPT    ,
  CRY_HSM_SYM_GCM_ENCRYPT    ,
  CRY_HSM_SYM_GCM_DECRYPT    ,
  CRY_HSM_SYM_HASH			 ,
  CRY_HSM_SYM_SIGNATURE_GENERATE ,
  CRY_HSM_SYM_SIGNATURE_VERIFY ,
  CRY_HSM_SYM_gENCRYPT ,
  CRY_HSM_SYM_gDECRYPT ,
  CRY_HSM_NUM_SERVICES
} Cry_HsmPrimitiveIdType;

typedef enum
{
  CRY_HSM_STATEWAITFORRESPONSE,
  CRY_HSM_STATEREADY,
  CRY_HSM_STATETIMEOUT
} Cry_HsmStatesType;


/******************************************************************************
**                 Global Structure Typde Definitions                        **
******************************************************************************/

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
typedef struct
{
  Cry_HsmPrimitiveIdType PrimitiveId;
  void (*CallbackNotification)(Csm_ReturnType Result);
  void (*FinishNotification)(void);
} Cry_HsmCallbacksType;
#endif

typedef struct
{
  HsmCom_Session       Session;
} Cry_Hsm;

/******************************************************************************
**                     Global Exported Variables                            **
******************************************************************************/
#define CRY_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"


extern Cry_Hsm Cry_HsmData[CRY_HSM_NUM_SERVICES];

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
extern Cry_HsmStateType Cry_PrimStatusAsync[CRY_HSM_NUM_SERVICES];
extern Csm_ReturnType Cry_PrimErr[CRY_HSM_NUM_SERVICES];
#endif

#if((CRY_HSM_E_POLICY_VIOLATION != STD_OFF)||  \
    (CRY_HSM_BSWM_ERROR_NOTIFICATION != STD_OFF))
extern boolean Cry_MacVerError;
#endif

#define CRY_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_20_01_STATUS=Required for MemMap.h inclusion*/
#include "Cry_MemMap.h"

#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
extern Cry_PrimStatusVal Cry_PrimStatus[CRY_HSM_NUM_SERVICES];
#endif

/* Status to indicate that Cry module is initialized */
/* This variable is used in all other Cry_Hsm<primitive>.c files */
#if(CRY_HSM_DEV_ERROR_DETECT == STD_ON)
extern Cry_HsmStateRef Cry_HsmInitStatus;
#endif

#define CRY_STOP_SEC_VAR_8BIT
#include "Cry_MemMap.h"


/******************************************************************************
**                     Global Function Typedef                               **
******************************************************************************/

typedef void (*Cry_HsmAction)(void);

/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
#define CRY_START_SEC_RAMCODE
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : IFX_INLINE Csm_ReturnType Cry_HsmSendCommandCommon     **
**                      (Cry_Hsm *HandlePtr,HsmCom_Command Command,          **
**                               uint32 UsTimeOut)                           **
**                                                                           **
** Description     :                                                         **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Sync or Async, depending on configuration               **
**                   "CSM_USE_SYNC_JOB_PROCESSING"                           **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : HandlePtr- Handle pointer that contains the session     **
**                              pointer                                      **
**                   Command- Command to be processed by HSM                 **
**                   UsTimeOut- Timeout value                                **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK- Request successful                            **
**                   CSM_E_BUSY- Request failed due to underlying HSM        **
**                               communication is busy                       **
**                   CSM_E_NOT_OK- Request failed                            **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType Cry_HsmSendCommandCommon(
                Cry_Hsm *HandlePtr, HsmCom_Command Command, uint32 TimeOut);

/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmPrimitiveMainFunction                       **
**                          (Cry_HsmPrimitiveIdType PrimitiveId,             **
**                              Cry_HsmAction FinishAction)                  **
** Description     : This is the common mainfunction for all the primitives  **
**                   in case of asynchronous mode                            **
**                                                                           **
**                                                                           **
** Service ID      : CRY_HSM_MAINFUNCTION_SID                                **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Reentrant                                               **
**                                                                           **
** Parameters (in) : PrimitiveId                                             **
**                   FinishAction: Function that cotains the action to be    **
**                    taken after the command is executed successfully.      **
**                    Ex: Copying the results to the application buffers     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
extern void Cry_HsmPrimitiveMainFunction(
        Cry_HsmPrimitiveIdType PrimitiveId, Cry_HsmAction FinishAction);
#endif

/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : HsmCom_Error FinishCommandErrorValidate(HsmCom_Error    **
**                   Err, HsmCom_Command Command)                            **
**                                                                           **
** Description     : Function validates the HSM return value for Finish      **
**                   command, if corresponding update command returned       **
**                   KEY EMPTY or KEY INVALID                                **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : Err: Command response returned by HSM                   **
                     Command: Command sent to HSM                            **
**                                                                           **
** Parameters (out): Modified command response                               **
**                                                                           **
******************************************************************************/
HsmCom_Error FinishCommandErrorValidate(HsmCom_Error Err, HsmCom_Command
                                                           Command);
#define CRY_STOP_SEC_RAMCODE
#include "Cry_MemMap.h"
/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/

#define CRY_START_SEC_RAMCODE
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmPrimitiveStart(                   **
**                                    Cry_HsmPrimitiveIdType PrimitiveId)    **
** Description     : This function initiates the handle for the primitive    **
**                   if the session is opened successfully.                  **
**                   This API is used by Cry_<Primitive>Start services.      **
**                                                                           **
**                                                                           **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : PrimitiveId                                             **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_BUSY: session not available / HsmCom busy         **
**                   CSM_E_OK: Session opened and handle initiated           **
**                             successfully for the primitive                **
******************************************************************************/
extern Csm_ReturnType Cry_HsmPrimitiveStart(
                           Cry_HsmPrimitiveIdType PrimitiveId);

/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmPrimitiveFinish                   **
**                                   (Cry_HsmPrimitiveIdType PrimitiveId)    **
** Description     : This API deinitiates the handle by closing the session  **
**                   for synchronous mode.                                   **
**                   For asynchronous mode, this API checks if the session   **
**                   is valid                                                **
**                   This API is used by Cry_<Primitive>Finish services.     **
**                                                                           **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous based on the configuration  **
**                    parameter CRY_HSM_USE_SYNC_JOB_PROCESSING              **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : PrimitiveId                                             **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK: Synchronous mode: Session closed and handle   **
**                                                deinitiated successfully   **
**                             Asynchronous mode: Session is valid           **
**                                                (handle is deinitiated by  **
**                                                    main function)         **
**                   CSM_E_NOT_OK: Session is invalid                        **
******************************************************************************/
extern Csm_ReturnType Cry_HsmPrimitiveFinish
                   (Cry_HsmPrimitiveIdType PrimitiveId);
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : Csm_ReturnType Cry_HsmStatusCheck                       **
**                                  (Cry_HsmPrimitiveIdType PrimitiveId      **
** Description     :  This API checks the present status of Hsm.             **
**                    This API is used in Cry_<Primitive>Update              **
**                     and Cry_<Primitive>Finish services to check the status**
**                     of HSM, before sending a new command                  **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : PrimitiveId                                             **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM_E_OK: Hsm is free to send a new command             **
**                   CSM_E_BUSY: Hsm is busy as previous command is          **
**                                 not completed                             **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType Cry_HsmStatusCheck
                                    (Cry_HsmPrimitiveIdType PrimitiveId);

#define CRY_STOP_SEC_RAMCODE
#include "Cry_MemMap.h"

/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : IFX_INLINE Cry_Hsm *Cry_lHsmInitiateHandle               **
**                          (Cry_HsmPrimitiveIdType PrimitiveId)             **
**                                                                           **
** Description     :  This inline opens the session and initiates the handle **
**                     for the primitive                                     **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : PrimitiveId                                             **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
******************************************************************************/
LOCAL_INLINE Cry_Hsm *Cry_lHsmInitiateHandle
                                        (Cry_HsmPrimitiveIdType PrimitiveId)
{
  Cry_Hsm *HandlePtr;
  HsmCom_Session SessionDataPtr;

  HandlePtr= NULL_PTR;
  SessionDataPtr = HsmCom_OpenSession();

  if (SessionDataPtr != HSMCOM_INVALID_SESSION)
  {
    HandlePtr = &Cry_HsmData[PrimitiveId];
    HandlePtr->Session = SessionDataPtr;
  }
  return HandlePtr;
}
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          :  IFX_INLINE void Cry_lHsmDeinitiateHandle                **
**                                      (Cry_Hsm *HandlePtr)                 **
**                                                                           **
** Description     : This inline deinitiates the handle by closing
**                          the session                                       **
**                                                                           **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : Handle Pointer                                          **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
LOCAL_INLINE void Cry_lHsmDeinitiateHandle(Cry_Hsm *HandlePtr)
{
  HsmCom_CloseSession(HandlePtr->Session);
  HandlePtr->Session = HSMCOM_INVALID_SESSION;
}


/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : IFX_INLINE HsmCom_KeyAddr Cry_lCalcKeyAddr               **
**                      (const Csm_SymKeyType *KeyPtr)                       **
**                                                                           **
** Description     : This inline calculates key ID for the input key slot    **
**                                                                           **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : Key slot                                                **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : KEY ID                                                  **
**                                                                           **
******************************************************************************/
LOCAL_INLINE HsmCom_KeyAddr Cry_lCalcKeyAddr(const Csm_SymKeyType *KeyPtr)
{
  HsmCom_KeyAddr KeyAddress;
  Cry_HsmKeySlotIdType SlotId;
  uint8 InputKey;
  /*IFX_MISRA_RULE_10_03_STATUS=Type casting is required as
   input key slot from CSM is of typt uint8 */
  /*IFX_MISRA_RULE_10_05_STATUS=Type casting is required as
  input key slot from CSM is of typt uint8 */
  SlotId = (Cry_HsmKeySlotIdType)KeyPtr->data[0];
  InputKey = KeyPtr->data[0];
  if (SlotId == CRY_HSM_RAM_KEY)
  {
    KeyAddress = HSMCOM_RAM_KEY;
  }
  else
  {
    if (SlotId <= CRY_HSM_KEY_10)
    {
      InputKey = InputKey+CRY_HSM_OFFSET_KEY1;
    }
    else if(SlotId <= CRY_HSM_KEY_20)
    {
      InputKey = InputKey+CRY_HSM_OFFSET_KEY11;
    }
    else if(SlotId <= CRY_HSM_BOOT_MAC)
    {
      InputKey = InputKey-CRY_HSM_OFFSET_MASTER;
    }
	else if(SlotId <= CRY_HSM_KEY_MAX)
	{
        InputKey = InputKey+CRY_HSM_OFFSET_PLAINKEY;
	}
    else
    {
      InputKey = CRY_HSM_INVALID_KEY;
    }
    /*IFX_MISRA_RULE_10_03_STATUS=Type casting is required
    as the calculated key ID is of type HsmCom_KeyAddr */
    /*IFX_MISRA_RULE_10_05_STATUS=Type casting is required
    as the calculated key ID is of type HsmCom_KeyAddr */
    KeyAddress =(HsmCom_KeyAddr)InputKey;
  }
  return KeyAddress;
}
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : IFX_INLINE Csm_ReturnType                               **
**                   Cry_lHsmErrValidate(HsmCom_Error ComError)               **
**                                                                           **
** Description     : This inline convert HSM response to corresponding CSM   **
**                   response                                                **
**                                                                           **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : HSM error response                                      **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : CSM error response                                      **
**                                                                           **
******************************************************************************/
LOCAL_INLINE Csm_ReturnType Cry_lHsmErrValidate(HsmCom_Error ComError)
{
    Csm_ReturnType CsmErr;

    switch(ComError)
    {
        case HSMCOM_ERC_NO_ERROR:
        {
          CsmErr = CSM_E_OK;
          break;
        }

        case HSMCOM_ERC_BUSY:
        {
            CsmErr = CSM_E_BUSY;
            break;
        }

        case HSMCOM_ERC_TRNG_FIFO_EMPTY:
        {
            CsmErr = CSM_E_ENTROPY_EXHAUSTION;
            break;
        }

        default:
        {
            CsmErr = CSM_E_NOT_OK;
            break;
        }
    }

    return CsmErr;
}

/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : IFX_INLINE Cry_Hsm *Cry_lHsmGetActiveHandle             **
**                      (Cry_HsmPrimitiveIdType PrimitiveId)                 **
**                                                                           **
** Description     : This inline gets the active handle for the input        **
**                          primitive ID                                     **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : PrimitiveId                                             **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
******************************************************************************/
LOCAL_INLINE Cry_Hsm *Cry_lHsmGetActiveHandle
                                    (Cry_HsmPrimitiveIdType PrimitiveId)
{
  Cry_Hsm *HandlePtr;

  HandlePtr = &(Cry_HsmData[PrimitiveId]);

  if (HandlePtr->Session == HSMCOM_INVALID_SESSION)
  {
    HandlePtr = NULL_PTR;
  }
  return HandlePtr;
}

#endif  /* End of CRY_HSM_PRIV_H */

