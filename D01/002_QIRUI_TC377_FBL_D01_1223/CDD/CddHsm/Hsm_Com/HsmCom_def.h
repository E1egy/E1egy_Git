/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : HsmCom_def.h                                                  **
**                                                                            **
**  VERSION   : 5.0.0                                                         **
**                                                                            **
**  DATE      : 2017-06-22                                                    **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                 **
**              [Refer Release Package for Supported Device]                  **
**  AUTHOR    : Trivikram G                                                   **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains functionality of HsmCom module           **
**                                                                            **
**  SPECIFICATION(S) :  Aurix_SHE+_TC-CDRV_DS.docx                            **
**                                                                            **
**  MAY BE CHANGED BY USER : No                                               **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
<IFX_RCH>
</IFX_RCH>
*/
#ifndef HSMCOM_DEF_H
#define HSMCOM_DEF_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#define HSMCOM_MAX_SESSIONS         1U
/* LIMITATION: we only support one session at the moment. */


/*Bit positions in HT2HSMF register for sending the command */
#define HSMCOM_COMMAND_INTR_BIT_POS  0UL
#define HSMCOM_CANCEL_INTR_BIT_POS  1UL
#define HSMCOM_INIT_INTR_BIT_POS  2UL
#define HSMCOM_SESSION_BIT_POS  8UL
#define HSMCOM_AES_MODE_BIT_POS  12UL
#define HSMCOM_COMMAND_BIT_POS  16UL
#define HSMCOM_KEYADDR_BIT_POS  24UL
#define HSMCOM_STATUS_MASK      (0x00FFUL)


/*Tick count obtained for 100Mhz = 120
  Tick count obtained for 64Mhz = 187
  The timeout count is multiplied by a factor of 5
*/

/*Time out value for CANCEL Command */
#define HSMCOM_CANCEL_TIMEOUT  1200U

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef struct
{
  uint32 Data[4];
} HsmAes_Block;

typedef struct
{
  uint32 Data[3];
} HsmAesGcm_Block;

typedef struct
{
  HsmAes_Block             Blocks[4];
} HsmCom_ParamsBuffer;

typedef struct
{
  HsmCom_ParamsBuffer     Ht2Hsm[HSMCOM_MAX_SESSIONS];
} HsmCom_Buffers;

typedef uint32 HostAddr;
typedef uint32 HsmCom_SessionId;    /* */

/*\  Constants specifying HSM commands, e.g. used by HsmCom_sendCommand()*/
typedef enum
{
  HSMCOM_CMD_NOTHINGTODO        = 0x00,
  HSMCOM_CMD_ECB_ENCRYPT        = 0x01,         /*Request ECB encryption */
  HSMCOM_CMD_ECB_DECRYPT        = 0x02,        /*Request ECB decryption */
  HSMCOM_CMD_AES_ENCRYPT_UPDATE = 0x03, /*Request to update AES encryption */
  HSMCOM_CMD_AES_ENCRYPT_FINISH = 0x04, /*Request to finish AES encryption */
  HSMCOM_CMD_AES_DECRYPT_UPDATE = 0x05, /*Request to update AES decryption */
  HSMCOM_CMD_AES_DECRYPT_FINISH = 0x06, /*Request to finish AES decryption */
  HSMCOM_CMD_MAC_GEN_UPDATE     = 0x07, /*Request to update CMAC generation*/
  HSMCOM_CMD_MAC_GEN_FINISH     = 0x08, /*Request to finalize CMAC
                                                            generation */
  HSMCOM_CMD_MAC_VER_UPDATE     = 0x09, /*Request to update CMAC generation*/
  HSMCOM_CMD_MAC_VER_FINISH     = 0x0A, /*Request to finalize CMAC
                                                          verification */
  HSMCOM_CMD_KEY_LOAD           = 0x0B,  /*Request to load a protected key */
  HSMCOM_CMD_KEY_LOAD_PLAIN     = 0x0C,     /*Request to load a plain
                                          key into HSMCOM_RAM_KEY */
  HSMCOM_CMD_KEY_EXPORT         = 0x0D,      /*Request to export protected
                                                      HSMCOM_RAM_KEY */
  HSMCOM_CMD_RND_INIT           = 0x0E,    /*Request to initialize the RNG */
  HSMCOM_CMD_RND_SEED_EXTEND    = 0x0F,  /*Request to extend the RNG seed */
  HSMCOM_CMD_RND_GEN            = 0x10,  /*Request to generate random number
                                                                          */
  HSMCOM_CMD_GET_ID             = 0x11,   /*Request to get the UID of the
                                                                      device */
  HSMCOM_CMD_BOOT_FAILURE       = 0x12,       /*Request to impose sanctions
                                                       during invalid boot */
  HSMCOM_CMD_BOOT_OK            = 0x13,            /*Request to finish boot
                                                              verification */
  HSMCOM_CMD_DEBUG_START        = 0x14,     /*Request to start debugger
                                                                  activation */
  HSMCOM_CMD_DEBUG_FINISH       = 0x15,   /* Request to finish debugger
                                                               activation */
  HSMCOM_CMD_SAFE_MAC_VER_FINISH = 0x16,       /*Request to finalize CMAC
                                               verification in safety mode */
  HSMCOM_CMD_SAFE_MAC_VER_FINISH_CHECK = 0x17, /*Request to execute redundant
                                          CMAC verification in safety mode */
  HSMCOM_CMD_TRNG_GEN            = 0x18,       /*Request to generate a true
                                                           random number */
  HSMCOM_CMD_GCM_ENCRYPT_UPDATE  = 0x19,  /*Request to update GCM encryption */
  HSMCOM_CMD_GCM_ENCRYPT_FINISH  = 0x1A,  /*Request to finish GCM encryption */
  HSMCOM_CMD_GCM_DECRYPT_UPDATE  = 0x1B,  /*Request to update GCM decryption */
  HSMCOM_CMD_GCM_DECRYPT_FINISH  = 0x1C,  /*Request to finish GCM decryption */
  HSMCOM_CMD_XTS_ENCRYPT_UPDATE  = 0x1D,  /*Request to update XTS encryption */
  HSMCOM_CMD_XTS_ENCRYPT_FINISH  = 0x1E,  /*Request to finish XTS encryption */
  HSMCOM_CMD_XTS_DECRYPT_UPDATE  = 0x1F,  /*Request to update XTS decryption */
  HSMCOM_CMD_XTS_DECRYPT_FINISH  = 0x20,  /*Request to finish XTS decryption */
  HSMCOM_INIT_SET_BUFFER         = 0x21,  /*Communicate start address of
                                              shared memory from host to HSM */
  HSMCOM_CMD_HASH         = 0x22,
  HSMCOM_CMD_SIGNATURE_GEN       = 0x23,
  HSMCOM_CMD_SIGNATURE_VERIFY    = 0x24,
  HSMCOM_CMD_ENCRYPT = 0x25,
  HSMCOM_CMD_DECRYPT = 0x26,
  HSMCOM_MAX_CMD_VALUE           = 0x26
} HsmCom_Command;

/* Constants specifying a key in HSM operations */
typedef enum
{
  HSMCOM_KEY_DUMMY        = 0x00U, /*  Default value */
  HSMCOM_SECRET_KEY       = 0x00U, /*  Code 0x00 */
  HSMCOM_MASTER_ECU_KEY   = 0x01U, /*  Code 0x01 */
  HSMCOM_BOOT_MAC_KEY     = 0x02U, /*  Code 0x02 */
  HSMCOM_BOOT_MAC         = 0x03U, /*  Code 0x03 */

  HSMCOM_KEY_1            = 0x04U, /*  Code 0x04 */
  HSMCOM_KEY_2            = 0x05U, /*  Code 0x05 */
  HSMCOM_KEY_3            = 0x06U, /*  Code 0x06 */
  HSMCOM_KEY_4            = 0x07U, /*  Code 0x07 */
  HSMCOM_KEY_5            = 0x08U, /*  Code 0x08 */
  HSMCOM_KEY_6            = 0x09U, /*  Code 0x09 */
  HSMCOM_KEY_7            = 0x0AU, /*  Code 0x0A */
  HSMCOM_KEY_8            = 0x0BU, /*  Code 0x0B */
  HSMCOM_KEY_9            = 0x0CU, /*  Code 0x0C */
  HSMCOM_KEY_10           = 0x0DU, /*  Code 0x0D */

  HSMCOM_RAM_KEY          = 0x0EU, /*  Code 0x0E */

  HSMCOM_KEY_11           = 0x14U, /*  Code 0x14 */
  HSMCOM_KEY_12           = 0x15U, /*  Code 0x15 */
  HSMCOM_KEY_13           = 0x16U, /*  Code 0x16 */
  HSMCOM_KEY_14           = 0x17U, /*  Code 0x17 */
  HSMCOM_KEY_15           = 0x18U, /*  Code 0x18 */
  HSMCOM_KEY_16           = 0x19U, /*  Code 0x19 */
  HSMCOM_KEY_17           = 0x1AU, /*  Code 0x1A */
  HSMCOM_KEY_18           = 0x1BU, /*  Code 0x1B */
  HSMCOM_KEY_19           = 0x1CU, /*  Code 0x1C */
  HSMCOM_KEY_20           = 0x1DU, /*  Code 0x1D */

  PLAIN_KEY_1             = 0x20,  /*ECDSA public key*/
  PLAIN_KEY_2             = 0x21, /*ECDSA private key*/
  PLAIN_KEY_3             = 0x22, /*rsa2048 private exponent*/
  PLAIN_KEY_4             = 0x23, /*rsa2048 public exponent*/
  PLAIN_KEY_5             = 0x24, /*rsa2048 modulus*/
  PLAIN_KEY_6             = 0x25, /*rsa2048 p prime1*/
  PLAIN_KEY_7             = 0x26, /*rsa2048 q prime2*/
  PLAIN_KEY_8             = 0x27, /*SM2 public key*/
  PLAIN_KEY_9             = 0x28, /*SM2 private key*/
  PLAIN_KEY_10            = 0x29, /*AES256  key*/
  PLAIN_KEY_11            = 0x2A, /*iv*/
  PLAIN_KEY_12             = 0x2B, /*rsa3072 private exponent*/
  PLAIN_KEY_13             = 0x2C, /*rsa3072 public exponent*/
  PLAIN_KEY_14             = 0x2D, /*rsa3072 modulus*/
  PLAIN_KEY_15             = 0x2E, /*rsa3072 p prime1*/
  PLAIN_KEY_16             = 0x2F, /*rsa3072 q prime2*/
  PLAIN_KEY_17             = 0x30, /*rsa4096 private exponent*/
  PLAIN_KEY_18             = 0x31, /*rsa4096 public exponent*/
  PLAIN_KEY_19             = 0x32, /*rsa4096 modulus*/
  PLAIN_KEY_20             = 0x33, /*rsa4096 p prime1*/
  PLAIN_KEY_21             = 0x34, /*rsa4096 q prime2*/
  

  HSMCOM_INVALID_KEY  = 0xFF
} HsmCom_KeyAddr;


/* This structure specifies the HT2HSMS coding */
typedef union {
  struct {
  unsigned CmdInterrupt  :  1;        /*Interrupt that triggers start
                                                  of a SHE command to the HSM.*/
  unsigned CmdCancelInterrupt  :  1; /*Interrupt that triggers
                                             cancellation of running command*/
  unsigned CmdInitInterrupt  :  1;   /*Interrupt for host-triggered
                                              init. Used in pre-init state */
  unsigned Reserved  : 5;             /*Reserved for future usage.*/
  unsigned Session   :4;                /*Session ID */
  unsigned AesMode   :4;                /*Mode of operation for AES
                                                 encryption/decryption  */
  unsigned Command   :8;                /*The command to be executed
                                                               by the HSM*/
  unsigned KeyAddr   :8;        /*Key address that is used to identify
                                        key slots.*/
  } B;
  uint32 U;
} HsmCom_PackedParams;

/*Data structure for \ref HSMCOM_CMD_KEY_LOAD operation */
typedef struct
{
  HostAddr M1Addr;    /*  Address for reading the 128-bit M1 data */
  HostAddr M2Addr;    /*  Address for reading the 256-bit M2 data */
  HostAddr M3Addr;    /*  Address for reading the 128-bit M3 data */
  HostAddr M4Addr;    /*  Address for writing the 256-bit M4 data */
  HostAddr M5Addr;    /*  Address for writing the 128-bit M5 data */
} HsmCom_LoadKeyParams;

/*Data structure for \ref HSMCOM_CMD_KEY_EXPORT operation. */
typedef struct
{
  HostAddr M1Addr;    /*  Address for writing the 128-bit M1 data */
  HostAddr M2Addr;    /*  Address for writing the 256-bit M2 data */
  HostAddr M3Addr;    /*  Address for writing the 128-bit M3 data */
  HostAddr M4Addr;    /*  Address for writing the 256-bit M4 data */
  HostAddr M5Addr;    /*  Address for writing the 128-bit M5 data */
} HsmCom_ExportKeyParams;

/*Data structure for \ref HSMCOM_CMD_KEY_LOAD_PLAIN operation */
typedef struct
{
  /*  Address for reading the N-bit plain key */
  HostAddr KeyAddr;
  uint32 PlainKeyLen;
} HsmCom_LoadPlainKeyParams;

/* Data structure for \ref HSMCOM_CMD_MAC_UPDATE operation */
typedef struct
{
  /*  Address for reading the input message */
  HostAddr SourceAddr;
  /*  Message length in bits */
  uint32   SizeBytes;
} HsmCom_MacUpdateParams;

/* Data structure for \ref HSMCOM_CMD_SIGNATURE_UPDATE operation */
typedef struct
{
  /*  Address for reading the input message */
  HostAddr SourceAddr;
  /*  Message length in bits */
  uint32   SizeBytes;
} HsmCom_SignatureUpdateParams;


/* Data structure for dummy MAC verification */
typedef struct
{
  /*  Address for reading the input message */
  HostAddr SourceAddr;
  /* Address for reading the reference Mac */
  HostAddr RefMacAddr;
  /* Address for reading the inverted reference Mac */
  HostAddr InvertedRefMacAddr;
  /* MAC Verification result address */
  HostAddr MacVerAddr;
}HsmCom_DummyMacVerification;

/*Data structure for \ref HSMCOM_CMD_MAC_GEN_FINISH operation */
typedef struct
{
  /*Address for writing the 128-bit calculated CMAC  */
  HostAddr MacOutputAddr;
  /*Address where MAC length in bytes to be returned is stored */
  uint32 MacLength;
} HsmCom_MacGenerateParams;

/*Data structure for \ref HSMCOM_CMD_MAC_VER_FINISH operation */
typedef struct
{
  /*Address for reading the reference CMAC  */
  HostAddr MacInputAddr;
  uint32   VerifyBits;    /*  Number of CMAC bits to compare */
  uint32   MacVerAddr;
} HsmCom_MacVerifyParams;

/*Data structure for \ref HSMCOM_CMD_RND_SEED_EXTEND operation */
typedef struct
{
  /*Address for reading the 128-bit seed (entropy) */
  HostAddr SeedAddr;
} HsmCom_RandomSeedParams;

/*add hash sha256*/
typedef struct
{
  /* Address for reading the input message */
  HostAddr SourceAddr;
  /* Address for writing the hash message */
  HostAddr DestAddr;
  /* The amount of message bytes */
  uint32 MessageLength;
  /* The amount of hash bytes */
  uint32 DigestLength;
  /*the crypto operation mode*/
  uint32 OperationMode;
  /*hash algorithm*/
  uint32 AlgorithmType;
} HsmCom_HashGenerateParamsType;

/*Data structure for \ref HSMCOM_CMD_RND_GEN operation */
typedef struct
{
  HostAddr DestAddr; /*Address for writing the 128-bit generated random
                         number */
  uint32 RndLength; /* Number of bytes to be generated incase of TRNG */
} HsmCom_RandomGenerateParams;

/*Data structure for \ref HSMCOM_CMD_DEBUG_START operation */
typedef struct

{
  /*Address for reading the challenge */
  HostAddr Challenge;
} HsmCom_DebugStartParams;

/*Data structure for \ref HSMCOM_CMD_DEBUG_FINISH operation */
typedef struct
{
  /*Address for sending the authorization */
  HostAddr Authorization;
} HsmCom_DebugFinishParams;

/* Data structure for HSMCOM_CMD_AES_ENCRYPT_UPDATE and
   HSMCOM_CMD_AES_DECRYPT_UPDATE operations */
typedef struct
{
  HostAddr SourceAddr;    /* Address for reading input data */
  HostAddr DestAddr;      /* Address for writing output data */
  HostAddr InitialVarAddr; /* Address for reading initialization vector */
  uint32   NBlocks; /* Number of 128-bits blocks for the AES operation */
} HsmCom_CryptParams;


/******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 734]                             **
******************************************************************************/
/* Data structure for HSMCOM_CMD_GCM_ENCRYPT_UPDATE and
   HSMCOM_CMD_GCM_DECRYPT_UPDATE operations */
typedef struct
{
  HostAddr SourceAddr;    /* Address for reading input data */
  HostAddr DestAddr;      /* Address for writing output data */
  HostAddr InitialVarAddr; /* Address for reading initialization vector */
  uint32 InputLength; /* Input text length in bytes */
  HostAddr AADSource;  /* Additional authenticated data address */
  uint32 AADLen;     /* Additional authenticated data length in bytes */
} HsmCom_CryptGcmUpdateParams;

/******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 735]                             **
******************************************************************************/
/* Data structure for HSMCOM_CMD_GCM_ENCRYPT_FINISH and
   HSMCOM_CMD_GCM_DECRYPT_FINISH operations */
typedef struct
{
  HostAddr AuthTagSource; /* Authentication tag address */
  HostAddr AuthTagLength; /* Authentication tag length address for encryption
                             Authentication tag length for decryption */
  HostAddr AuthTagResultAddr; /* Authentication tag result address. Used only
                                 for decryption */
} HsmCom_CryptGcmFinishParams;

/* Data structure for HSMCOM_CMD_XTS_ENCRYPT_UPDATE and
   HSMCOM_CMD_XTS_DECRYPT_UPDATE operations */
/** Traceability    : [$Satisfies $CDS_CDRV 738]                             */
/*****************************************************************************/
typedef struct
{
  HostAddr SourceAddr;    /* Address for reading input data */
  HostAddr DestAddr;      /* Address for writing output data */
  HostAddr InitialVarAddr; /* Address for reading initialization vector */
  uint32 InputLength; /* Input text length in bytes */
  HsmCom_KeyAddr KeyId2; /* Key2 ID */
} HsmCom_CryptXtsParams;

typedef struct
{
    HostAddr ChalleangeAddr; /* Address for reading Challeange data */
    HostAddr MacAddr; /* Address for writing MAC data */
    HostAddr UidSregAddr; /* Address for writing UID and Status register data*/
}HsmCom_GetUidParams;


/** Traceability    :  [$Satisfies $CDS_CDRV 568] [$Satisfies $CDS_CDRV 569]**
   [$Satisfies $CDS_CDRV 575]                                              **/
/* Values as requested by first customer */
typedef enum
{
  HSMCOM_ERC_NO_ERROR             = 0x00, /* No error has occured */
  HSMCOM_ERC_SEQUENCE_ERROR       = 0x01,  /*The sequence of
                                            commands or subcommands is out of
                                            sequence */
  HSMCOM_ERC_BUSY                 = 0x02,  /*Another function is
                                       still processing */
  HSMCOM_ERC_KEY_NOT_AVAILABLE    = 0x10,  /*The key is locked due
                                       to failed boot measurement or an
                                       active debugger */
  HSMCOM_ERC_KEY_INVALID          = 0x11, /* The key is not allowed
                                         for the given operation */
  HSMCOM_ERC_KEY_EMPTY            = 0x12,  /* The key has not been
                                       initialized yet */
  HSMCOM_ERC_NO_SECURE_BOOT       = 0x20,
  HSMCOM_ERC_KEY_WRITE_PROTECTED  = 0x30,  /*The key is memory
                                       protected */
  HSMCOM_ERC_KEY_UPDATE_ERROR     = 0x31,  /* Key update operation
                                       did not succeed */
  HSMCOM_ERC_RNG_SEED             = 0x40, /* Random seed has not
                                       been initialized yet */
  HSMCOM_ERC_MEMORY_FAILURE       = 0x50, /* Error in memory during
                                       read or write operations */
  HSMCOM_ERC_ECC_MEMORY_FAILURE   = 0x51, /* Error in ECC RAM */
  HSMCOM_ERC_NO_DEBUGGING         = 0x60,
  HSMCOM_ERC_TRNG_FIFO_EMPTY      = 0x70,
  HSMCOM_ERC_CRYPTO_ERROR         = 0x71,
  HSMCOM_ERC_COMMAND_INVALID      = 0x80, /* Invalid command */
  HSMCOM_ERC_CANCELLED            = 0x90,

  HSMCOM_ERC_TIMEOUT              = 0xE0,  /*command timeout.
                                              This is not part of HSM errors */
  HSMCOM_ERC_GENERAL_FAILURE      = 0xFF   /*Unknown error */
} HsmCom_Error;

/* This structure specifies the HSM2HTF coding */
typedef union {
  struct {

  unsigned CmdSrc:    1;       /*This bit is set if the command
                                          was received by the SHE command
                                             interrupt */
  unsigned CmdCancelSrc:1;     /*This bit is set if the command
                                            was cancelled by CMD_CANCEL*/
  unsigned Reserved1:6;        /* Reserved for future usage.*/
  unsigned Session:4;         /*Session ID that is used to map an HSM
                                      response to the corresponding request.*/
  unsigned Reserved2:4;         /*Return code of the command */
  unsigned Command:8;          /*The command which was originally sent
                                    to the HSM*/
  unsigned Error:8;            /*Reserved for future usage.*/
  } B; /*  Bitfields */
  uint32 U;
} HsmCom_PackedResponse;


typedef enum
{
  HSMCOM_STAT_BUSY         = 0X0001,
  HSMCOM_STAT_SECUREBOOT   = 0X0002,
  HSMCOM_STAT_BOOTINIT     = 0X0004,
  HSMCOM_STAT_BOOTFINISHED = 0X0008,
  HSMCOM_STAT_BOOTOK       = 0X0010,
  HSMCOM_STAT_RNDINIT      = 0X0020,
  HSMCOM_STAT_EXTDEBUGGER  = 0X0040,
  HSMCOM_STAT_INTDEBUGGER  = 0X0080,
  HSMCOM_STAT_PREINIT      = 0X0100,
  HSMCOM_STAT_WAIT_COMMAND = 0X0200,
  HSMCOM_STAT_WAITINIT     = 0X0400,
  HSMCOM_STAT_EXCEPTION    = 0X0800,
  HSMCOM_STAT_INITFAIL     = 0x1000
} HsmCom_StatusType;

/*crypto opreation mode*/
typedef enum
{
  CRYPTO_OPERATIONMODE_START  = 0x01,    /* 0x1: start */
  CRYPTO_OPERATIONMODE_UPDATE  = 0x02,   /* 0x2: update */
  CRYPTO_OPERATIONMODE_FINISH  = 0x04,   /* 0x4: finish */
  CRYPTO_OPERATIONMODE_SINGLECALL = 0x7  /* 0x7: singlecall */
} Hsm_CryptoOperationMode;


/*signature algrithm type*/
typedef enum
{
  HSM_SIGNATURE_ALGORITHM_ECDSA  = 0x00,         /* 0x0: ECDSA signature */
  HSM_SIGNATURE_ALGORITHM_RSA_v15  = 0x01,   /* 0x1: RSA signature */
  HSM_SIGNATURE_ALGORITHM_RSA_v21  = 0x02,   /* 0x2: RSA signature */
  HSM_SIGNATURE_ALGORITHM_SM2  = 0x03,           /* 0x3: SM2 signature */
  HSM_INVALID_SIGNATURE_ALGORITHM = 0xFF
} Hsm_SignatureAlgorithmType;

/*hash algrithm type*/
typedef enum
{
  HSM_HASH_ALGORITHM_SHA256  = 0x00,   /* 0x0: sha256 hash */
  HSM_HASH_ALGORITHM_SM3  = 0x01,   /* 0x1: sm3 hash */
  HSM_HASH_ALGORITHM_SHA512  = 0x02,   /* 0x0: sha512 hash */
 
  HSM_INVALID_HASH_ALGORITHM = 0xFF
} Hsm_HashAlgorithmType;


/*signature*/
typedef struct
{
  HostAddr SourceAddr; /*Address for writing the input message*/
  uint32 MessageSize;            /*Message length in bytes*/
  HostAddr SignatureOutputAddr; /*Address for writing the n-bytes
                                     calculated Signature*/
  uint32 SignatureResultLenAddr;      /* Signature Result Length n bytes */
  HostAddr SignatureInputAddr;             /*Address for reading the
                                                reference SIGNATURE*/
  uint32 SignatureVerifyBytes;                         /*Number of SIGNATURE bytes to
                                                compare*/
  HostAddr VerifificationResultAddr; /*Address for writing the
                                               result of the SIGNATURE verification
                                               0:verification successful,
                                               1: verification failed*/
  uint32 Algorithm_type; /*signature algrithm type*/
  HostAddr UserIdAddr; /*SM2 input user id*/
  uint32 UserIdLen;   /*SM2 input user id length*/
  uint32 OperationMode;/*the crypto operation mode*/
} Hsm_SignatureParamsType;

/*encrypt/decrypt algrithm type*/
typedef enum
{
  HSM_CIPHER_ALGORITHM_SM4  = 0x00,   /* 0x0: SM4 */
  HSM_CIPHER_ALGORITHM_AES256  = 0x01,   /* 0x1: AES256 */
  
  HSM_INVALID_SYMMETRY_ALGORITHM = 0xFF
} Hsm_CipherAlgorithmType;


/*encrypt/decrypt*/
typedef struct
{
  HostAddr SourceAddr; /*Address for reading input data*/
  uint32 InputLen;
  HostAddr DestAddr;   /*Address for writing output data*/
  HostAddr OutputLenAddr;
  HostAddr IVAddr;     /*Address for reading the
                                 initialization vector */
  uint32 Algorithm_type;
  uint32 mode;
  uint32 OperationMode;/*the crypto operation mode*/
} Hsm_CipherParamsType;


/******************************************************************************
**                      Global Constant Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/

#endif /* HSMCOM_DEF_H */
