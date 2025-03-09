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
#include "Std_Types.h"

#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
uint32 TEST_HSM_CACHE_TEST_1[4] = {0xAA,0xAA,0xAA,0xAA};
uint32 TEST_HSM_CACHE_TEST_2[4] = {0xBB,0xBB,0xBB,0xBB};
uint32 TEST_HSM_CACHE_TEST_3[4] = {0xCC,0xCC,0xCC,0xCC};
uint32 TEST_HSM_CACHE_TEST_4[4] = {0xDD,0xDD,0xDD,0xDD};
uint32 TEST_HSM_CACHE_TEST_5[4] = {0xEE,0xEE,0xEE,0xEE};
uint32 TEST_HSM_CACHE_TEST_6[4]=  {0xEE,0xEE,0xEE,0xEE};
#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"

#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
/*****************************************************************************************
**                                                                                      **
*****************************************************************************************/
void Cache_Test(void)
{
 int i;
 for(i=0;i<4;i++)
 {
	TEST_HSM_CACHE_TEST_1[i]=0xAA;
	TEST_HSM_CACHE_TEST_2[i]=0xBB;
	TEST_HSM_CACHE_TEST_3[i]=0xCC;
	TEST_HSM_CACHE_TEST_4[i]=0xDD;
	TEST_HSM_CACHE_TEST_5[i]=0xEE;
	TEST_HSM_CACHE_TEST_6[i]=0xEE;
 }
}
#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=Required for Cry_MemMap.h inclusion*/
#include "Cry_MemMap.h"
