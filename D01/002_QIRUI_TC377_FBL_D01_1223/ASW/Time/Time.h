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
**  FILENAME    : Time.h                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yongxing.jia                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>      <AUTHOR>       <REVISION LOG>
 *    V0.1.0       2020-05-20  yongxing.jia   Initial version.
 */
/*============================================================================*/
#ifndef TIME_H_
#define TIME_H_

#include "Std_Types.h"


void Gpt_1ms_Notification(void);

void Time_Tick_Mainfunction(void);

extern boolean GetTime_1ms_Status(void);

extern boolean GetTime_5ms_Status(void);

extern boolean GetTime_10ms_Status(void);

extern boolean GetTime_50ms_Status(void);

extern boolean GetTime_100ms_Status(void);

extern boolean GetTime_500ms_Status(void);

extern boolean GetTime_1000ms_Status(void);


#endif /* TIME_TIME_H_ */
