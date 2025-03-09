/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Nm_MemMap.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#if defined NM_START_SEC_CODE
    #undef NM_START_SEC_CODE
    #define START_SEC_CODE
#elif defined NM_STOP_SEC_CODE
    #undef NM_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined NM_START_SEC_VAR_CLEARED_BOOLEAN
    #undef NM_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN
#elif defined NM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef NM_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR_CLEARED_BOOLEAN

#elif defined NM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef NM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined NM_START_SEC_CONST_UNSPECIFIED
    #undef NM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined NM_STOP_SEC_CONST_UNSPECIFIED
    #undef NM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST_UNSPECIFIED

#elif defined NM_START_SEC_NM_NETWORKSTARTINDICATION_CALLBACK_CODE
    #undef NM_START_SEC_NM_NETWORKSTARTINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_NETWORKSTARTINDICATION_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_NETWORKSTARTINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_NETWORKMODE_CALLBACK_CODE
    #undef NM_START_SEC_NM_NETWORKMODE_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_NETWORKMODE_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_NETWORKMODE_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_BUSSLEEPMODE_CALLBACK_CODE
    #undef NM_START_SEC_NM_BUSSLEEPMODE_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_BUSSLEEPMODE_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_BUSSLEEPMODE_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_PREPAREBUSSLEEPMODE_CALLBACK_CODE
    #undef NM_START_SEC_NM_PREPAREBUSSLEEPMODE_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_PREPAREBUSSLEEPMODE_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_PREPAREBUSSLEEPMODE_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_REMOTESLEEPINDICATION_CALLBACK_CODE
    #undef NM_START_SEC_NM_REMOTESLEEPINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_REMOTESLEEPINDICATION_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_REMOTESLEEPINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_REMOTESLEEPCANCELLATION_CALLBACK_CODE
    #undef NM_START_SEC_NM_REMOTESLEEPCANCELLATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_REMOTESLEEPCANCELLATION_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_REMOTESLEEPCANCELLATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_SYNCHRONIZATIONPOINT_CALLBACK_CODE
    #undef NM_START_SEC_NM_SYNCHRONIZATIONPOINT_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_SYNCHRONIZATIONPOINT_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_SYNCHRONIZATIONPOINT_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_COORDREADYTOSLEEPINDICATION_CALLBACK_CODE
    #undef NM_START_SEC_NM_COORDREADYTOSLEEPINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_COORDREADYTOSLEEPINDICATION_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_COORDREADYTOSLEEPINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_COORDREADYTOSLEEPCANCELLATION_CALLBACK_CODE
    #undef NM_START_SEC_NM_COORDREADYTOSLEEPCANCELLATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_COORDREADYTOSLEEPCANCELLATION_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_COORDREADYTOSLEEPCANCELLATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_PDURXINDICATION_CALLBACK_CODE
    #undef NM_START_SEC_NM_PDURXINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_PDURXINDICATION_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_PDURXINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_STATECHANGENOTIFICATION_CALLBACK_CODE
    #undef NM_START_SEC_NM_STATECHANGENOTIFICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_STATECHANGENOTIFICATION_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_STATECHANGENOTIFICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_REPEATMESSAGEINDICATION_CALLBACK_CODE
    #undef NM_START_SEC_NM_REPEATMESSAGEINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_REPEATMESSAGEINDICATION_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_REPEATMESSAGEINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
    #undef NM_START_SEC_NM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined NM_START_SEC_NM_CARWAKEUPINDICATION_CALLBACK_CODE
    #undef NM_START_SEC_NM_CARWAKEUPINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined NM_STOP_SEC_NM_CARWAKEUPINDICATION_CALLBACK_CODE
    #undef NM_STOP_SEC_NM_CARWAKEUPINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE
#else
#error "Nm not include this section"
#endif
#include "MemMap.h"
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
