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
**  FILENAME   : Cry_HsmTypes.h                                              **
**                                                                           **
**  VERSION    : 3.0.0                                                       **
**                                                                           **
**  DATE       : 2016-07-11                                                  **
**                                                                           **
**  VARIANT    : NA                                                          **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR    : Trivikram G                                                  **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the type definitions used in CRY module **
**                                                                           **
**                                                                           **
**                                                                           **
**  SPECIFICATION(S) : Aurix_SHE+_TC-CDRV_DS.docx                            **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
#ifndef CRY_HSM_TYPES_H
#define CRY_HSM_TYPES_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Csm_Cfg.h"
#include "Csm_Types.h"
/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 413]                             **
******************************************************************************/
typedef struct
{
  /*  Timeout value for Cry_<Primitive>Start or
  Cry_<Primitive> function */
  uint32 TimeoutStart;
  /*  Timeout constant for Cry_<Primitive>Update function */
  uint32 TimeoutUpdateConst;
  /*  Timeout constant for Cry_<Primitive>Update function */
  uint32 TimeoutUpdateperByte;
  /*  Timeout value for Cry_<Primitive>Finish function */
  uint32 TimeoutFinish;
} Cry_HsmTimeoutType;

typedef struct
{
  Cry_HsmTimeoutType  TimeOut; /*  Timeout configuration */
} Cry_HsmBasicConfigType;

/* Chained AES operation mode */
/** Traceability    : [$Satisfies $CDS_CDRV 415]                              **
*******************************************************************************/
typedef enum
{
  CRY_HSM_AES_MODE_DUMMY = 0U,
  CRY_HSM_AES_MODE_CBC = 0U,  /* (0x0),specifies the CBC operation mode*/
  CRY_HSM_AES_MODE_CTR = 1U,  /* (0x1),specifies the CTR operation mode*/
  CRY_HSM_AES_MODE_OFB = 2U,  /* (0x2),specifies the OFB operation mode*/
  CRY_HSM_AES_MODE_CFB = 3U,  /* (0x3),specifies the CFB operation mode*/
  CRY_HSM_AES_MODE_GCM = 4U,  /* (0x4),specifies the GCM operation mode*/
  CRY_HSM_AES_MODE_XTS = 5U,  /* (0x5),specifies the XTS operation mode*/
  CRY_HSM_INVALID_AES_MODE = 0xFF
} Cry_HsmAesModeType;


/******************************************************************************
**                  Global Enumeration Type Definition                       **
******************************************************************************/
/* Accessible key slots */
/** Traceability    : [$Satisfies $CDS_CDRV 417] [$Satisfies $CDS_CDRV 570]  **
*******************************************************************************/
typedef enum
{
  CRY_HSM_RAM_KEY = 0U,      /*  RAM key slot */
  CRY_HSM_KEY_1   = 1U,      /*  Key slot 1  */
  CRY_HSM_KEY_2   = 2U,      /*  Key slot 2  */
  CRY_HSM_KEY_3   = 3U,      /*  Key slot 3  */
  CRY_HSM_KEY_4   = 4U,      /*  Key slot 4  */
  CRY_HSM_KEY_5   = 5U,      /*  Key slot 5  */
  CRY_HSM_KEY_6   = 6U,      /*  Key slot 6  */
  CRY_HSM_KEY_7   = 7U,      /*  Key slot 7  */
  CRY_HSM_KEY_8   = 8U,      /*  Key slot 8  */
  CRY_HSM_KEY_9   = 9U,      /*  Key slot 9  */
  CRY_HSM_KEY_10  = 10U,     /*  Key slot 10 */
  CRY_HSM_KEY_11  = 11U,     /*  Key slot 11 */
  CRY_HSM_KEY_12  = 12U,     /*  Key slot 12 */
  CRY_HSM_KEY_13  = 13U,     /*  Key slot 13 */
  CRY_HSM_KEY_14  = 14U,     /*  Key slot 14 */
  CRY_HSM_KEY_15  = 15U,     /*  Key slot 15 */
  CRY_HSM_KEY_16  = 16U,     /*  Key slot 16 */
  CRY_HSM_KEY_17  = 17U,     /*  Key slot 17 */
  CRY_HSM_KEY_18  = 18U,     /*  Key slot 18 */
  CRY_HSM_KEY_19  = 19U,     /*  Key slot 19 */
  CRY_HSM_KEY_20  = 20U,      /*  Key slot 20 */

  /* Keys that may only be used as authId */
  CRY_HSM_MASTER_ECU_KEY = 21U, /*  master ECU key */
  CRY_HSM_BOOT_MAC_KEY   = 22U, /*  Boot MAC key */
  CRY_HSM_BOOT_MAC       = 23U, /*  Boot MAC */

  /*plain key,slot id*/
  CRY_HSM_PLAIN_KEY_1    = 24U, /*  ECDSA PUBLIC KEY */
  CRY_HSM_PLAIN_KEY_2    = 25U, /*  ECDSA PRIVATE KEY */
  CRY_HSM_PLAIN_KEY_3    = 26U, /*  RSA2048 private exponent KEY */
  CRY_HSM_PLAIN_KEY_4    = 27U, /*  RSA2048 public exponent KEY */
  CRY_HSM_PLAIN_KEY_5    = 28U, /*  RSA2048 modulus exponent KEY */
  CRY_HSM_PLAIN_KEY_6    = 29U, /*  RSA2048 prime1 exponent KEY */
  CRY_HSM_PLAIN_KEY_7    = 30U, /*  RSA2048 prime2 exponent KEY */
  CRY_HSM_PLAIN_KEY_8    = 31U, /*  SM2 public KEY */
  CRY_HSM_PLAIN_KEY_9    = 32U, /*  SM2 private KEY */
  CRY_HSM_PLAIN_KEY_10    = 33U, /*  AES256 KEY */
  CRY_HSM_PLAIN_KEY_11    = 34U, /*  iv */
  CRY_HSM_PLAIN_KEY_12    = 35U, /*  RSA3072 private exponent KEY */
  CRY_HSM_PLAIN_KEY_13    = 36U, /*  RSA3072 public exponent KEY */
  CRY_HSM_PLAIN_KEY_14    = 37U, /*  RSA3072 modulus exponent KEY */
  CRY_HSM_PLAIN_KEY_15    = 38U, /*  RSA3072 prime1 exponent KEY */
  CRY_HSM_PLAIN_KEY_16    = 39U, /*  RSA3072 prime2 exponent KEY */
  CRY_HSM_PLAIN_KEY_17    = 40U, /*  RSA4096 private exponent KEY */
  CRY_HSM_PLAIN_KEY_18    = 41U, /*  RSA4096 public exponent KEY */
  CRY_HSM_PLAIN_KEY_19    = 42U, /*  RSA4096 modulus exponent KEY */
  CRY_HSM_PLAIN_KEY_20    = 43U, /*  RSA4096 prime1 exponent KEY */
  CRY_HSM_PLAIN_KEY_21    = 44U, /*  RSA4096 prime2 exponent KEY */
  CRY_HSM_KEY_MAX        = 44U /*  MAX KEY */
} Cry_HsmKeySlotIdType;


/*algrithm mode*/
typedef uint8 Crypto_AlgorithmModeType;

# ifndef CRYPTO_ALGOMODE_NOT_SET /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_NOT_SET                                     0x00u
# endif
# ifndef CRYPTO_ALGOMODE_ECB /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_ECB                                         0x01u
# endif
# ifndef CRYPTO_ALGOMODE_CBC /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_CBC                                         0x02u
# endif
# ifndef CRYPTO_ALGOMODE_CFB /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_CFB                                         0x03u
# endif
# ifndef CRYPTO_ALGOMODE_OFB /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_OFB                                         0x04u
# endif
# ifndef CRYPTO_ALGOMODE_CTR /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_CTR                                         0x05u
# endif
# ifndef CRYPTO_ALGOMODE_XTS /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_XTS                                         0x06u
# endif
# ifndef CRYPTO_ALGOMODE_GCM /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_GCM                                         0x07u
# endif
# ifndef CRYPTO_ALGOMODE_RSAES_OAEP /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_RSAES_OAEP                                  0x08u
# endif
# ifndef CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5 /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5                            0x09u
# endif
# ifndef CRYPTO_ALGOMODE_RSASSA_PSS /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_RSASSA_PSS                                  0x0Au
# endif
# ifndef CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 /* COV_CSM_USER_DEFINES */
#  define CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5                           0x0Bu
# endif


#endif /* End of CRY_HSMTYPES_H */
