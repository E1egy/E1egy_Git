#include <string.h>

#include "Std_Types.h"
#include "Rte_Dcm_Type.h"
#include "Rte_UDS.h"
#include "UDS_0x22_2E.h"

#define DID_F031_VEHICLE_MANUFACTURER_CALIB_DPN         					"A01_58X_YYXX2304"   
#define DID_F032_VEHICLE_MANUFACTURER_CALIB_VERSION_NUMBER          		"A01_58X_YYXX_XXYY_202304"  
#define DID_F187_VEHICLE_MANUFACTURER_SPAREPARTNUMBERDATAIDENTIFIER         "202003795AA"
#define DID_F089_VEHICLE_MANUFACTURER_ECU_HARDWARE_VERSION        			"0.0.1"
#define DID_F013_VEHICLE_MANUFACTURER_SOFTWARE_PARTBUMBERS_VERSION        	"S0000002809"
#define DID_F18A_SYSTEM_SUPPLIER_IDENTIFIERDATAIDENTIFIER                   "9HH"
#define DID_F18B_ECU_MANUFACTRING_DATE                  					"0524"
#define DID_F197_SYSTEM_NAME_DATAIDENTIFIER                                 "ASU"

#define  DataLength_DcmDspData_0xF180 		32
#define  DataLength_DcmDspData_0xF187 		16
#define  DataLength_DcmDspData_0xF089 		24
#define  DataLength_DcmDspData_0xF18A 		10
#define  DataLength_DcmDspData_0xF186 		1

//boolean HSCMesWheelPosInput = FALSE;

//TODO
// uint16 HSCMesWheelPosFL;
// uint16 HSCMesWheelPosFR;
// uint16 HSCMesWheelPosRL;
// uint16 HSCMesWheelPosRR;

#define DataLength_DcmDspData_0x3928 8

const uint8 g_bootSoftwareVersion[]  __attribute__((used,protect)) = "00.05.01";
const uint8 *g_F189ManufactureEcuSoftwareVersion = (uint8 *)0x802FFFA0;
const uint8 g_F187ManufactureEcuPartNODataIdentifier[] = DID_F187_VEHICLE_MANUFACTURER_SPAREPARTNUMBERDATAIDENTIFIER;

void ReadBuffer_DcmDspData_0xF180(uint8* Data)
{
	uint8 Version[DataLength_DcmDspData_0xF180];

	memset(Version, 0x20, sizeof(Version));
	memcpy(Version, g_bootSoftwareVersion, sizeof(g_bootSoftwareVersion)-1);
	memcpy(Data, &Version, sizeof(Version));
}

void ReadBuffer_DcmDspData_0xF187(uint8* Data)
{
	uint8 Version[DataLength_DcmDspData_0xF187];

	memset(Version, 0x20, sizeof(Version));
	memcpy(Version, DID_F187_VEHICLE_MANUFACTURER_SPAREPARTNUMBERDATAIDENTIFIER, sizeof(DID_F187_VEHICLE_MANUFACTURER_SPAREPARTNUMBERDATAIDENTIFIER)-1);
	memcpy(Data, &Version, sizeof(Version));
}

extern uint8 g_hwVersion ;
void ReadBuffer_DcmDspData_0xF089(uint8* Data)
{
	uint8 Version[DataLength_DcmDspData_0xF089];

	memset(Version, 0x20, sizeof(Version));
	memcpy(Version, DID_F089_VEHICLE_MANUFACTURER_ECU_HARDWARE_VERSION, sizeof(DID_F089_VEHICLE_MANUFACTURER_ECU_HARDWARE_VERSION)-1);

	if(g_hwVersion >= 10)
	{
		Version[2] = 0x30 + g_hwVersion /10;
		Version[4] = 0x30 + g_hwVersion %10;
	}else
	{
		Version[4] = 0x30 + g_hwVersion;
	}

	memcpy(Data, &Version, sizeof(Version));
}

void ReadBuffer_DcmDspData_0xF18A(uint8* Data)
{
	uint8 Version[DataLength_DcmDspData_0xF18A];

	memset(Version, 0x20, sizeof(Version));
	memcpy(Version, DID_F18A_SYSTEM_SUPPLIER_IDENTIFIERDATAIDENTIFIER, sizeof(DID_F18A_SYSTEM_SUPPLIER_IDENTIFIERDATAIDENTIFIER)-1);
	memcpy(Data, &Version, sizeof(Version));
}

void ReadBuffer_DcmDspData_0xF186(uint8* Data)
{
	uint8 Version[DataLength_DcmDspData_0xF186];
	Std_ReturnType ret;
	memset(Version, 0xFF, sizeof(Version));
	ret = Dcm_GetSesCtrlType(&Version[0]);
	memcpy(Data, &Version[0], sizeof(Version));
}

boolean WriteDID_Is_HSCMesWheelPosInput(void)
{
    boolean *dataReasult = NULL_PTR;

    dataReasult = Rte_IWriteRef_RE_UDS_pPort_HSCMesWheelPosInput_HSCMesWheelPosInput();
    return *dataReasult;
}
