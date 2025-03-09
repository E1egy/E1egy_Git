#ifndef UDS_0X22_2E_H
#define UDS_0X22_2E_H

extern const uint8 g_F187ManufactureEcuPartNODataIdentifier[];

extern boolean WriteDID_Is_HSCMesWheelPosInput(void);
extern void ReadBuffer_DcmDspData_0xF187(uint8* Data);
extern void ReadBuffer_DcmDspData_0xF180(uint8* Data);
extern void ReadBuffer_DcmDspData_0xF089(uint8* Data);
extern void ReadBuffer_DcmDspData_0xF18A(uint8* Data);
extern void ReadBuffer_DcmDspData_0xF186(uint8* Data);
#endif