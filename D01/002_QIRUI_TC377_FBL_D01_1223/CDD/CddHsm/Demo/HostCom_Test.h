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

/**
 * \file HostCom_Test.h
 *
 */
#ifndef HOSTCOM_TEST_H
#define HOSTCOM_TEST_H

#define HOSTCOM_TESTAPP 0

#if (HOSTCOM_TESTAPP == 1)
void HostCom_Test_InitSharedBuffer(void);
void HostCom_Test_WriteValue(void);
void HostCom_Test_WriteBlock(void);
void HostCom_Test_ReadBlock(void);
void HostCom_Test_UpdateCommand(void);
void HostCom_Test_SetHsm2HtStatus(void);
void HostCom_Test_GetHt2HsmStatus(void);
void HostCom_Test_GetKeyAddress(void);
void HostCom_Test_GetAesMode(void);
void HostCom_Test_UpdateParams_SizeEqualAes(void);
void HostCom_Test_UpdateParams_SizeMoreAes(void);
#endif /*HOSTCOM_TESTAPP*/

#endif /*HOSTCOM_TEST_H*/
