#ifndef UDS_0X31_H
#define UDS_0X31_H

extern void EEM_Get_HSCWheelData(void);
extern uint8 Routine_Get_EcuMode(void);
extern Dcm_NegativeResponseCodeType Routine_Check_0x392A_ConditionsNotCorrect(void);
extern Dcm_NegativeResponseCodeType Routine_Check_0x3955_ConditionsNotCorrect(void);
extern void Routine_Call_0x392A_Start(uint8 *outBuffer);
extern void Routine_Call_0x392A_Result(uint8 *outBuffer);
void Routine_Call_0x3930_Start(uint8 *inBuffer,uint8 *outBuffer);
extern void Routine_Call_0x3930_Result(uint8 *outBuffer);
extern Dcm_NegativeResponseCodeType Routine_Call_0x3955_Start(uint8 *data);
extern void Routine_Task(void);

#endif
