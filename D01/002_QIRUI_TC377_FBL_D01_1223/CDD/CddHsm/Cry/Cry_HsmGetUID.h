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
**  FILENAME    : Cry_HsmGetUID.h                                            **
**                                                                           **
**  VERSION     :  1.0.0                                                     **
**                                                                           **
**  DATE        : 2016-09-08                                                 **
**                                                                           **
**  VARIANT     : NA                                                         **
**                                                                           **
**  PLATFORM    : Infineon TC2xxxx Aurix Family                              **
**                [Refer Release Package for Supported Device]               **
**  AUTHOR      : Trivikram G                                                **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This is the corresponding header file for                  **
**                Cry_HsmGetUID.c file                                       **
**                                                                           **
**  SPECIFICATION(S) :  Aurix_SHE+_TC-CDRV_DS.docx                           **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
#ifndef CRY_HSM_GET_UID_H
#define CRY_HSM_GET_UID_H
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*
<IFX_RCH>
</IFX_RCH>
*/
/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Cry_HsmTypes.h"
/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/

/******************************************************************************
**                     Global Type Definition                                **
******************************************************************************/
/** Traceability    : [$Satisfies $CDS_CDRV 403]                              **
*******************************************************************************/

/******************************************************************************
**                     Global Constant Definition                            **
******************************************************************************/

/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
#define CRY_START_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmGetUIDFinishAction(void)                    **
**                                                                           **
** Description     : This function is used to copy the UID, Mac and Status   **
**                   into destination pointer                                **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
extern void Cry_HsmGetUIDFinishAction(void);

/******************************************************************************
**                     Global Function Declaration                           **
******************************************************************************/
/******************************************************************************
** Traceability    :                                                         **
**                                                                           **
** Syntax          : void Cry_HsmGetUIDClearBuffer(void)                     **
**                                                                           **
** Description     : This function is used to clear the input buffer         **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/
extern void Cry_HsmGetUIDClearBuffer(void);

/******************************************************************************
** Traceability    :  [$Satisfies $CDS_CDRV 612]  [$Satisfies $CDS_CDRV 613] **
**                    [$Satisfies $CDS_CDRV 614]  [$Satisfies $CDS_CDRV 615] **
**                    [$Satisfies $CDS_CDRV 616]  [$Satisfies $CDS_CDRV 617] **
**                    [$Satisfies $CDS_CDRV 579]                             **
** Syntax          : Cry_HsmGetSheUID(const uint8 *Challenge,                **
**                   uint8* She_UidPtr, uint8 *She_SregPtr, uint8 *MacPtr)   **
**                                                                           **
** Description     :  The function returns the identity (UID) and the value  **
**                    of the status register protected by a MAC over         **
**                    a challenge and the data.                              **
**                                                                           **
** Service ID      : CRY_HSM_SID_GETUID                                      **
**                                                                           **
** Sync/Async      : Synchronous or Asynchronous depending on configuration  **
**                   CSM_USE_SYNC_JOB_PROCESSING                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : Challenge    - Pointer to Challenge for MAC(16 bytes)   **
**                                                                           **
** Parameters (out): She_UidPtr   - Pointer to the SHE UID (15 bytes)        **
**                   She_SregPtr  - Pointer to the value of the SHE          **
**                                  status register                          **
**                   MacPtr       - Pointer to the MAC value over            **
**                                  the challenge, id and sreg.              **
**                                                                           **
** Return value    : CSM_E_OK - Request successful                           **
**                   CSM_E_BUSY - Request failed as underlying HSM           **
**                                 communication is busy                     **
**                   CSM_E_NOT_OK - Request failed                           **
**                                                                           **
******************************************************************************/
extern Csm_ReturnType Cry_HsmGetSheUID(const uint8 *Challenge,
        uint8* She_UidPtr,uint8 *She_SregPtr, uint8 *MacPtr);

#if CRY_HSM_USE_SYNC_JOB_PROCESSING == STD_OFF
/******************************************************************************
** Traceability    : [$Satisfies $CDS_CDRV 618] [$Satisfies $CDS_CDRV 579]   **
**                                                                           **
** Syntax          : void Cry_HsmGetUIDMainFunction(void)                    **
**                                                                           **
** Description     : In case of asynchronous operation, this function checks **
**                   the command response for HSMCOM_CMD_GET_ID command and  **
**                   closes the session                                      **
**                                                                           **
**                                                                           **
** [/cover]                                                                  **
**                                                                           **
** Service ID      : NA                                                      **
**                                                                           **
** Sync/Async      : Synchronous                                             **
**                                                                           **
** Reentrancy      : Non - Reentrant                                         **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value    : None                                                    **
**                                                                           **
******************************************************************************/

extern void Cry_HsmGetUIDMainFunction(void);
#endif

#define CRY_STOP_SEC_CODE
/*IFX_MISRA_RULE_20_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "Cry_MemMap.h"

#endif
/* CRY_HSM_RANDOM_GENERATE_H */
