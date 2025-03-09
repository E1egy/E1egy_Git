#ifndef CSM_CBK_H
#define CSM_CBK_H 1

#include "Csm_Types.h"

/* CSM service callbacks: */
void Csm_RandomSeedCallbackNotification(Csm_ReturnType result);
void Csm_RandomSeedServiceFinishNotification(void);

void Csm_RandomGenerateCallbackNotification(Csm_ReturnType result);
void Csm_RandomGenerateServiceFinishNotification(void);

void Csm_MacGenerateCallbackNotification(Csm_ReturnType result);
void Csm_MacGenerateServiceFinishNotification(void);

void Csm_MacVerifyCallbackNotification(Csm_ReturnType result);
void Csm_MacVerifyServiceFinishNotification(void);

void Csm_SymEncryptCallbackNotification(Csm_ReturnType result);
void Csm_SymEncryptServiceFinishNotification(void);

void Csm_SymDecryptCallbackNotification(Csm_ReturnType result);
void Csm_SymDecryptServiceFinishNotification(void);

void Csm_SymBlockEncryptCallbackNotification(Csm_ReturnType result);
void Csm_SymBlockEncryptServiceFinishNotification(void);

void Csm_SymBlockDecryptCallbackNotification(Csm_ReturnType result);
void Csm_SymBlockDecryptServiceFinishNotification(void);

void Csm_SymKeyExtractCallbackNotification(Csm_ReturnType result);
void Csm_SymKeyExtractServiceFinishNotification(void);

void Csm_SymKeyWrapSymCallbackNotification(Csm_ReturnType result);
void Csm_SymKeyWrapSymServiceFinishNotification(void);

void Csm_GetUidCallbackNotification(Csm_ReturnType result);
void Csm_GetUidServiceFinishNotification(void);

void Csm_DebugCallbackNotification(Csm_ReturnType result);
void Csm_DebugServiceFinishNotification(void);

void Csm_BootFailureCallbackNotification(Csm_ReturnType result);
void Csm_BootFailureServiceFinishNotification(void);

void Csm_BootOkCallbackNotification(Csm_ReturnType result);
void Csm_BootOkServiceFinishNotification(void);

void Csm_SymXtsEncryptCallbackNotification(Csm_ReturnType result);
void Csm_SymXtsEncryptServiceFinishNotification(void);

void Csm_SymXtsDecryptCallbackNotification(Csm_ReturnType result);
void Csm_SymXtsDecryptServiceFinishNotification(void);

void Csm_SymGcmEncryptCallbackNotification(Csm_ReturnType result);
void Csm_SymGcmEncryptServiceFinishNotification(void);

void Csm_SymGcmDecryptCallbackNotification(Csm_ReturnType result);
void Csm_SymGcmDecryptServiceFinishNotification(void);
#endif /* CSM_CBK_H */
