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
**************************************************************************************//**
*
*  \FILE      SampleCode.h
*
*  \BRIEF     Sample code for handling the HSM SHE+ module using Cry
*
*  \DATE      2014.09.18
*
*  \AUTHOR    Volker Elies [volker.elies@hitex.de]
*
*  \VENDOR    Infineon Technologies, A.G.
*
*  \REFERENCE <spec name, version>
*
*//**************************************************************************************/

#ifndef SAMPLECODE_H_
#define SAMPLECODE_H_

#include "HsmCom_def.h"
#include "Cry_Hsm.h"

#define __REV(x)    ((((x) & 0xff) << 24) | \
                     (((x) & 0xff00) << 8) | \
                     (((x) & 0xff0000UL) >> 8) | \
                     (((x) & 0xff000000UL) >> 24))
typedef struct
{
	HsmAes_Block key;
	uint32       flags;
	uint32       counter;
} SampleCode_KeyType;

typedef struct
{
    HsmAes_Block M1[1];
    HsmAes_Block M2[2];
    HsmAes_Block M3[1];
    HsmAes_Block M4[2];
    HsmAes_Block M5[1];
} ProtectedKey;

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"

extern Csm_ReturnType SampleCode_LoadEncryptedKey (Cry_HsmKeySlotIdType keySlotId, Cry_HsmKeySlotIdType authSlotId,
		                                           const HsmAes_Block* newKey, uint32 flags, uint32 counter,
		                                           boolean guiWildCard, ProtectedKey* protKeyPtr);
extern Csm_ReturnType SampleCode_LoadPlainKey (HsmCom_KeyAddr KeyAddr,const HsmAes_Block *keyPtr,uint32 KeyLength);
extern Csm_ReturnType SampleCode_ExportKey    (ProtectedKey *protKeyPtr);
extern Csm_ReturnType SampleCode_LoadRamKey   (ProtectedKey* protKeyPtr);

extern Csm_ReturnType SampleCode_CMacGenerate(const Csm_SymKeyType* symKeyPtr, const HsmAes_Block* inputPtr, uint32 inputLength,
		                                      HsmAes_Block* macPtr, uint32 macLength);
extern Csm_ReturnType SampleCode_ComputeBootMac(const HsmAes_Block *keyPtr, HsmAes_Block *bootMacPtr);
extern void SampleCode_InvalidBootMac(const HsmAes_Block *keyPtr , HsmAes_Block *bootMacPtr);
extern Csm_ReturnType SampleCode_CMacGenerateB(const Csm_SymKeyType* symKeyPtr, const uint32* inputPtr, uint32 inputLength,
                                          HsmAes_Block* macPtr, const HsmAes_Block* headerPtr);

extern Csm_ReturnType SampleCode_HsmAesEcbEncrypt(const Csm_SymKeyType *symKeyPtr, const HsmAes_Block *plainTextPtr, HsmAes_Block* cipherTextPtr);

extern Csm_ReturnType SampleCode_HsmAesEncrypt(const Cry_HsmAesEncryptConfigType* configPtr, const Csm_SymKeyType* symKeyPtr,
                                               const uint8* initVectPtr, uint32 initVectLength,
                                               const uint8* plainTextPtr, uint32 inputLength, uint8* cipherTextPtr);

extern uint32 SampleCode_GetKeyFlags(Cry_HsmKeySlotIdType keySlotId);
extern uint32 SampleCode_GetNextKeyCounter(Cry_HsmKeySlotIdType keySlotId);
extern void   SampleCode_ClearKeySlot(Cry_HsmKeySlotIdType keySlotId);
extern void Read_g_KeyStorageFunc(Cry_HsmKeySlotIdType authId, HsmAes_Block *keyPtr);
extern void Update_g_KeyStorageFunc(Cry_HsmKeySlotIdType authId, const HsmAes_Block *keyPtr);

extern Csm_ReturnType SampleCode_Hash (Hsm_HashAlgorithmType HashAlgorithm,const uint8 *MessagePtr,uint32 MessageLength, uint8 *DigestPtr,uint32 *DigestLengthPtr,Hsm_CryptoOperationMode OperationMode);
extern Csm_ReturnType SampleCode_SignatureGenerate(const Csm_PlainKeyType *symKeyPtr,Hsm_SignatureAlgorithmType SignatureAlgorithm,const uint8 *UserId,uint32 UserIdLen,
		const uint8 *input, uint32 inputLength,uint8 *SignatureDataPtr,uint32 *SignatureLenth,Hsm_CryptoOperationMode OperationMode);
extern Csm_ReturnType SampleCode_SignatureVerify(const Csm_PlainKeyType *symKeyPtr,Hsm_SignatureAlgorithmType SignatureAlgorithm,const uint8 *UserId,uint32 UserIdLen,
		const uint8 *input, uint32 inputLength,uint8 *SignatureDataPtr,uint32 SignatureLenth,
		Csm_VerifyResultType *ResultPtr,Hsm_CryptoOperationMode OperationMode);
extern Csm_ReturnType SampleCode_Encrypt(const Csm_SymKeyType *symKeyPtr,const uint8 *IV,Hsm_CipherAlgorithmType EncryptAlgorithm,Crypto_AlgorithmModeType mode,
									 const uint8 *input, uint32 inputLength,uint8 *OutPutDataPtr,uint32 *OutPutDataLenPtr,Hsm_CryptoOperationMode OperationMode);

extern Csm_ReturnType SampleCode_Decrypt(const Csm_SymKeyType *symKeyPtr,const uint8 *IV,Hsm_CipherAlgorithmType EncryptAlgorithm,Crypto_AlgorithmModeType mode,
									 const uint8 *input, uint32 inputLength,uint8 *OutPutDataPtr,uint32 *OutPutDataLenPtr,Hsm_CryptoOperationMode OperationMode);

#if ITF
extern void KeyExport_ITF(void);
extern void KeyLoadPlain_ITF(void);
extern void KeyLoad_ITF(void);
#endif
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for Cry_MemMap.h*/
#include "Cry_MemMap.h"
#endif /* SAMPLECODE_H_ */
