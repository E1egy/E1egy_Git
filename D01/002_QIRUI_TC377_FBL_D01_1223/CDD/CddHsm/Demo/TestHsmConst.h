/*****************************************************************************************
**                                                                                      **
** Copyright (C) Infineon Technologies (2014)                                           **
**                                                                                      **
** All rights reserved.                                                                 **
**                                                                                      **
** This document contains proprietary information belonging to Infineon                 **
** Technologies. Passing on and copying of this document, and communication             **
** of its contents is not permitted without prior written authorization.                **
**                                                                                      **
** THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. INFINEON TECHNOLOGIES          **
** RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER          **
** REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR         **
** THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.                          **
**                                                                                      **
** INFINEON TECHNOLOGIES SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR                **
** CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR        **
** ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR              **
** PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE        **
** DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION         **
** WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR        **
** PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON        **
** WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.                                   **
**                                                                                      **
******************************************************************************************/

#ifndef TESTHSMCONST_H
#define TESTHSMCONST_H 1
#include "Mcal_Compiler.h"

/* #define TEST_CRYPT_SIZE   (32*1024) */
#define TEST_CRYPT_SIZE   (1024)
#define TEST_CRYPT_BLOCKS (TEST_CRYPT_SIZE / 16)

_EXTERN_ uint8 TrngSeed[16];
_EXTERN_ uint32 TEST_HSM_BUF_TEMP_A[TEST_CRYPT_SIZE/4];
_EXTERN_ uint32 TEST_HSM_BUF_TEMP_B[TEST_CRYPT_SIZE/4];
_EXTERN_ uint32 TEST_HSM_BUF_TEMP_C[4];
_EXTERN_ uint32 TEST_HSM_BUF_TEMP_D[4];
_EXTERN_ uint32 TEST_HSM_BUF_TEMP_F[4];
_EXTERN_ uint32 TEST_HSM_BUF_TEMP_G[4];
_EXTERN_ uint32 TEST_HSM_BUF_TEMP_H[8];
_EXTERN_ uint32 TEST_HSM_BUF_TEMP_I[16];
_EXTERN_ uint32 TEST_HSM_BUF_TEMP_J[16];
_EXTERN_ uint8 TEST_CONST_MAC22_2[12];
_EXTERN_ uint8 Test_Hsm_TempMacBuf[32];
_EXTERN_ uint8 Test_Hsm_TempUIDBuf[16];
_EXTERN_ uint8 Test_Hsm_TempSregBuf[4];
_EXTERN_ uint8 Test_Hsm_TempMainMacBuf[16];
_EXTERN_ uint8 Test_Hsm_TempGenMacBuf[16];

_EXTERN_ const uint8 TEST_CONST_KEY[16];
_EXTERN_ const uint8 TEST_CONST_INIT_VEC[16];
_EXTERN_ const uint8 TEST_GCM_CONST_INIT_VEC[12];
_EXTERN_ const uint8 TEST_CONST_PLAIN[64];
_EXTERN_ const uint8 TEST_CONST_PLAIN_1[16];
_EXTERN_ const uint8 TEST_CONST_PLAIN_GCM[10];
_EXTERN_ const uint8 TEST_CONST_PLAIN_2[16];
_EXTERN_ const uint8 TEST_CONST_PLAIN_3[16];
_EXTERN_ const uint8 TEST_CONST_PLAIN_4[16];
_EXTERN_ const uint8 TEST_CONST_PLAIN_48 [48];
_EXTERN_  const uint8 TEST_CONST_PLAIN_32 [32];

_EXTERN_ const uint8 TEST_CONST_ECB_CIPH[16];
_EXTERN_ const uint8 TEST_CONST_CBC_CIPH[64];
_EXTERN_ const uint8 TEST_CONST_CTR_CIPH[64];
_EXTERN_ const uint8 TEST_CONST_OFB_CIPH[64];
_EXTERN_ const uint8 TEST_CONST_CFB_CIPH[64];
_EXTERN_ const uint8 TEST_CONST_XTS_CIPH[64];

_EXTERN_ const uint8 TEST_CONST_L[16];
_EXTERN_ const uint8 TEST_CONST_KEY1[16];
_EXTERN_ const uint8 TEST_CONST_KEY2[16];
_EXTERN_ const uint8 TEST_CONST_MAC0[16];
_EXTERN_ const uint8 TEST_CONST_MAC16[16];
_EXTERN_ const uint8 TEST_CONST_MAC21[16];
_EXTERN_ const uint8 TEST_CONST_MAC22[16];
_EXTERN_ const uint8 TEST_CONST_MAC18[4];
_EXTERN_ const uint8 TEST_CONST_MAC23[16];
_EXTERN_ const uint8 TEST_CONST_MAC40[16];
_EXTERN_ const uint8 TEST_CONST_MAC64[16];
_EXTERN_ const uint8 TEST_CONST_MIYAGUCHI_PRENEEL[16];
_EXTERN_ const uint8 TEST_CONST_RANDOM_SEED[16];
_EXTERN_ const uint8 TEST_CONST_RANDOM_NUMBER[16];
_EXTERN_ const uint8 TEST_CONST_RANDOM_ENTROPY[16];
_EXTERN_ const uint8 TEST_CONST_KEY_UPDATE_M1[16];
_EXTERN_ const uint8 TEST_CONST_CHALLENGE_BYTES[16];
_EXTERN_ const uint32 TEST_CONST_GCM_PLAIN_TEXT[15];
_EXTERN_ const uint32 TEST_CONST_GCM_PLAIN_TEXT_32BYTES[8];
_EXTERN_ const uint32 TEST_CONST_GCM_PLAIN_TEXT_28BYTES[7];

#define AESBLOCK16(a)   (uint8)((a) >> 8),(uint8)(a)
#define AESBLOCK32(a)   AESBLOCK16((uint16)((a) >> 16)),AESBLOCK16((uint16)(a))
#define AESBLOCK64(a)   AESBLOCK32((uint32)((a) >> 32)),AESBLOCK32((uint32)(a))
#define AESBLOCK(a,b)   AESBLOCK64(a),AESBLOCK64(b)

#endif
