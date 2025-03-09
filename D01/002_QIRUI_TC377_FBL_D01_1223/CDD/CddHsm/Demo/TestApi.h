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

#ifndef TESTAPI_H
#define TESTAPI_H 1
/*
#define _EXTERN_ extern
#define IFX_LOCAL_INLINE static inline
#define IFX_INLINE inline

#ifndef LOCAL_INLINE
#define LOCAL_INLINE    static inline
#endif

#define UNUSED_PARAMETER(VariableName)   (void)(VariableName);
*/
#include "HsmCom_Priv.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"


#if (0)
/*
 *These functions not used any more
 */
HsmCom_Error TestApi_aesEncrypt(HsmCom_KeyAddr keyAddr, HsmCom_AesMode mode, const void *initVect, const void *input, void *output, uint32 nBlocks);
HsmCom_Error TestApi_aesDecrypt(HsmCom_KeyAddr keyAddr, HsmCom_AesMode mode, const void *initVect, const void *input, void *output, uint32 nBlocks);
HsmCom_Error TestApi_ecbEncrypt(HsmCom_KeyAddr keyAddr, const void *input, void *output);
HsmCom_Error TestApi_ecbDecrypt(HsmCom_KeyAddr keyAddr, const void *input, void *output);
HsmCom_Error TestApi_exportRamKey(void *m1, void *m2, void *m3, void *m4, void *m5);
HsmCom_Error TestApi_exportKey(HsmCom_KeyAddr id, HsmCom_KeyAddr authId, void *m1, void *m2, void *m3, void *m4, void *m5);
HsmCom_Error TestApi_loadKey(const void *m1, const void *m2, const void *m3, void *m4, void *m5);
HsmCom_Error TestApi_loadPlainKey(const void *key);
HsmCom_Error TestApi_generateMac(HsmCom_KeyAddr keyAddr, const void *msg, uint32 msgBits, void *mac);
HsmCom_Error TestApi_verifyMac(HsmCom_KeyAddr keyAddr, const void *msg, uint32 msgBits, const void *mac, uint32 macBits, boolean *result);
HsmCom_Error TestApi_randomInit(void);
HsmCom_Error TestApi_randomExtendSeed(const void *entropy);
#endif

HsmCom_Error TestApi_randomGenerate(void *output);
HsmCom_Error TestApi_randomSetSeed(const void *seed);

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*
extern inline void Sleep(uint32 a)
{
    UNUSED_PARAMETER(a);
}
*/
#endif /* TESTAPI_H */
