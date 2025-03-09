#include <string.h>

#include "Std_Types.h"
#include "Rte_Dcm_Type.h"
#include "NvM_Cfg.h"
#include "NvM.h"
#include "NvM_Types.h"
#include "Rte_UDS.h"

#include "UDS_0x31.h"
#include "UDS_0x22_2E.h"

typedef uint8 EcuModeType;
#define ECU_MODE_FACTORY                0       /* 工厂模式 */
#define ECU_MODE_TRANSPORT              1       /* 运输模式 */
#define ECU_MODE_DYNOTEST               2       /* 动态记录模式 */
#define ECU_MODE_NORMAL                 3       /* 正常模式 */
#define ECU_MODE_SHOWROOM               4       /* 展车模式 */
#define ECU_MODE_CRASH                  5       /* 碰撞模式 */
#define ECU_MODE_SERVICE                6       /* 服务模式 */
#define ECU_MODE_NUM                    7

typedef uint8 RoutineIdType;
#define ROUTINE_DID_0x392A              0
#define ROUTINE_DID_0x392B              1
#define ROUTINE_DID_0x392C              2
#define ROUTINE_DID_0x392D              3
#define ROUTINE_DID_0x392E              4
#define ROUTINE_DID_0x392F              5
#define ROUTINE_DID_0x3930              6
#define ROUTINE_DID_0x3956              7
#define ROUTINE_DID_0x395A              8
#define ROUTINE_DID_0x395B              9
#define ROUTINE_DID_NUM                 10

typedef uint8 RoutineReqStatusType;
#define ROUTINE_REQUEST_STATUS_IDLE     0
#define ROUTINE_REQUEST_STATUS_START    1
#define ROUTINE_REQUEST_STATUS_STOP     2

typedef uint8 RoutineStatusType;
#define ROUTINE_STATUS_IDLE             0
#define ROUTINE_STATUS_FAIL             1
#define ROUTINE_STATUS_SUCCESS          2
#define ROUTINE_STATUS_INPROGRESS       3

#define ROUTINE_TIME_OUT_0x392A         2000     /* 20S */
#define ROUTINE_TIME_OUT_0x3930         15000     /* 150S */

typedef struct
{
    RoutineReqStatusType ReqStatus; ///< 例程请求
    RoutineStatusType RoutineStaus; ///< 例程状态
    uint16 TimeOut;                 ///< 例程时间限制
} RoutineDID_t;

uint8 *g_heightMsgRountingRam =      (uint8 *)0xB0026D9A;///< Mapping ram space of height sensor calibration information

//TODO
uint8 g_EcuMode = 0; //ECU模式
float32 g_CurrentVehicleSpeed = 0; //车速
boolean g_VehicleSpeedEffectiveness = TRUE; //车速有效性
uint8 g_VehicleStatus = TRUE; //车辆状态
uint8 g_VehicleGear = TRUE; //车辆档位
boolean HSCStartRoutineFlag = FALSE;
// uint8 HSCNVMWrtSts = 0;
// boolean g_HSCSts_EEM = FALSE;
// uint8 HSCRoutineSts = 0;
// boolean HSCValidFL = FALSE;
// boolean HSCValidFR = FALSE;
// boolean HSCValidRL = FALSE;
// boolean HSCValidRR = FALSE;
// boolean HSCNVMWrtReq = FALSE;

// float32 HSCWheelPosDevFL_EEM = 0;
// float32 HSCWheelPosDevFR_EEM = 0;
// float32 HSCWheelPosDevRL_EEM = 0;
// float32 HSCWheelPosDevRR_EEM = 0;

// float32 HSCWheelPosDevFL;
// float32 HSCWheelPosDevFR;
// float32 HSCWheelPosDevRL;
// float32 HSCWheelPosDevRR;

STATIC RoutineDID_t RoutineDID[ROUTINE_DID_NUM];

/* BSW将高度标定的结果写入NVM */
#define NVM_BLOCK_RAM_ADDR_3928 0xB0026E08

// void EEM_Get_HSCWheelData(void)
// {
//     sint16 data[4];

//     memcpy((uint8 *)data, (uint8 *)NVM_BLOCK_RAM_ADDR_3928, 8);
//     HSCWheelPosDevFL_EEM = (float32)data[0] / 10;
//     HSCWheelPosDevFR_EEM = (float32)data[1] / 10;
//     HSCWheelPosDevRL_EEM = (float32)data[2] / 10;
//     HSCWheelPosDevRR_EEM = (float32)data[3] / 10;
// }

STATIC uint8 Routine_Set_EcuMode(EcuModeType data)
{
    uint8 result = E_NOT_OK;

    if (data < ECU_MODE_NUM)
    {
        g_EcuMode = data;
        result = E_OK;
    }

    return result;
}

EcuModeType Routine_Get_EcuMode(void)
{
    return g_EcuMode;
}

STATIC void Routine_Set_ReqStatus_Idle(RoutineIdType routineId)
{

}

STATIC void Routine_Set_ReqStatus_Start(RoutineIdType routineId)
{

}

STATIC void Routine_Set_ReqStatus_Stop(RoutineIdType routineId)
{

}

STATIC void Routine_Set_TimeOut(RoutineIdType routineId, uint16 timeOut)
{

}

STATIC RoutineIdType Routine_Get_ReqStatus(RoutineIdType routineId)
{
    return E_OK;
}

Dcm_NegativeResponseCodeType Routine_Check_0x392A_ConditionsNotCorrect(void)
{


    return E_OK;
}

void Routine_Call_0x392A_Idle(void)
{

}

void Routine_Call_0x3930_Idle(void)
{

}

void Routine_Call_0x392A_Start(uint8 *outBuffer)
{

}

void Routine_Call_0x3930_Start(uint8 *inBuffer,uint8 *outBuffer)
{

}

void Routine_Call_0x392A_Result(uint8 *outBuffer)
{

}

void Routine_Call_0x3930_Result(uint8 *outBuffer)
{

}

Dcm_NegativeResponseCodeType Routine_Check_0x3955_ConditionsNotCorrect(void)
{

    return E_OK;
}

Dcm_NegativeResponseCodeType Routine_Call_0x3955_Start(uint8 *data)
{


    return E_OK;
}

/* NVM写入成功标志 */
#define HSC_NVM_WRITER_STATUS_NC 0     /* 无动作 */
#define HSC_NVM_WRITER_STATUS_OK 1     /* 写入成功 */
#define HSC_NVM_WRITER_STATUS_NOT_OK 2 /* 写入失败 */
STATIC void Routine_0x392A(void)
{
  
}


STATIC void Routine_0x3930(void)
{
 

}


void Routine_Task(void)
{
    Routine_0x392A();
    Routine_0x3930();
}
