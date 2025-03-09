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
*  \FILE      Csm_MacVerify.h
*
*  \BRIEF     Interface of the Csm_MacVerify service
*
*  \DATE      2014.11.11
*
*  \AUTHOR    Volker Elies [volker.elies@hitex.de]
*
*  \VENDOR    Infineon Technologies, A.G.
*
*  \REFERENCE <spec name, version>
*
*//**************************************************************************************/
#ifndef CSM_MAC_VERIFY_H
#define CSM_MAC_VERIFY_H 1

#include "Csm_Types.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/* Define some value to be passed as cfgId */
#define MyCsmApplication_MacVerify_Id 0x0123

Csm_ReturnType Csm_MacVerifyStart( Csm_ConfigIdType cfgId, const Csm_SymKeyType* keyPtr );

Csm_ReturnType Csm_MacVerifyUpdate( Csm_ConfigIdType cfgId, const uint8* dataPtr, uint32 dataLength );

Csm_ReturnType Csm_MacVerifyFinish( Csm_ConfigIdType cfgId, const uint8* MacPtr, uint32 MacLength, Csm_VerifyResultType* resultPtr );

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
#endif
