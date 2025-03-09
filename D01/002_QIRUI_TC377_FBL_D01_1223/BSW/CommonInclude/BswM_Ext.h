/*
 * BswM_Ext.h
 *
 *  Created on: 2019Äê3ÔÂ7ÈÕ
 *      Author: Administrator
 */

#ifndef BSW_SOURCE_COMMONINCLUDE_BSWM_EXT_H_
#define BSW_SOURCE_COMMONINCLUDE_BSWM_EXT_H_

extern uint8 EcuShutdownFlag;

void Communication_ON(void);

void Communication_OFF(void);

void BswM_AllowECU_Sleep(void);
void BswM_NotAllowECU_Sleep(void);

void BswM_CanTrcv_ModeShiftToNormal(void);
void BswM_CanTrcv_ModeShiftToStandBy(void);
void WakeupSource_Disable(void);
void WakeupSource_Enable(void);

void GenericSwitch_CanSmBusOff_NoCom_Ch0(void);

void GenericSwitch_CanSmBusOff_BusOffSilent_Ch0(void);

void GenericSwitch_CanSmBusOff_NoCom_Ch1(void);

void GenericSwitch_CanSmBusOff_BusOffSilent_Ch1(void);

void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_Ch1(void);

void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_Local(void);

void User_Dem_Init(void);

void BSW_User_Shutdown(void);

void BswM_EcuM_RequestRun(void);

void BswM_EcuM_ReleaseRun(void);

void BswM_EcuM_RequestPostRun(void);

void BswM_EcuM_ReleasePostRun(void);


#endif /* BSW_SOURCE_COMMONINCLUDE_BSWM_EXT_H_ */
