/*******************************************************************************
*                                   BAOLONG
*                          -------------------------
*                          Details to create profits
*
@copyright Copyright (c) 2023  ShangHai BAOLONG Electronics Stock Co., Ltd. All rights reserved.
*
Contact information:
web site:    https://www.baolong.biz/
e-mail:      sbic@baolong.biz
*******************************************************************************/
 

/*******************************************************************************
* \file:   ReadDTCInformation_0x19.c
*
* \brief  The header file of ReadDTCInformation_0x19.h
*
* \author  BL_zq
*
* \version v1.0
*
* \date  : 2023-03-09
*
* @par modification history:
* @internal
* <tr><th>Date       <th>Version <th>Author       <th>Description
* <tr><td>2023-03-09 <td>1.0     <td>BL_zq     <td>鍐呭
* @endinternal
*******************************************************************************/
#include <string.h>

/***************************************Includes***************************************/
#include "ReadDTCInformation_0x19.h"

///< CDD
#include "Tlf35584_Driver.h"
#include "RemoteDia.h"

///< BSW
#include "Dem.h"
#include "UDS.h"
#include "Rte_Cbk.h"

///< Config

/***************************************Variables*************************************/
uint8 DtcStatus[DTC_NUMBER_MAX];
boolean DTC_BUSOFF_flag = TRUE;

/***************************************Functions************************************/
void DTC_Init(void)
{
    memset(DtcStatus, TRUE, DTC_NUMBER_MAX);
}

void SET_DTCBUSOFF_Flag(boolean busoff_flag)
{
	DTC_BUSOFF_flag = busoff_flag;
}

boolean GET_DTCBUSOFF_Flag(void)
{
	return DTC_BUSOFF_flag;
}


#if 0
void DTC_SetDtcStatus(uint8 dtcNum ,boolean dtcStatus)
{
    DtcStatus[dtcNum] = dtcStatus;
}
#endif

void DTC_SetDtcStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
    Dem_SetEventStatus(EventId, EventStatus);
    if (DEM_EVENT_STATUS_PASSED == EventStatus)
    {
        DtcStatus[EventId] = TRUE;
    }
    else if (DEM_EVENT_STATUS_FAILED == EventStatus)
    {
        DtcStatus[EventId] = FALSE;
    }
}


// ABM
void DTC_EventList_0xC15187(void)
{

}

// EPB
void DTC_EventList_0xC12887(void)
{

}

//EPS
void DTC_EventList_0xC13187(void)
{

}

//IPB
void DTC_EventList_0xC12987(void)
{

}

//MDC  娌℃湁瀵瑰簲淇″彿鎺ユ敹锛屾殏鏈疄鐜�
void DTC_EventList_0xC15C87(void)
{

}

//TBOX
void DTC_EventList_0xC19887(void)
{

}

//VIU2
void DTC_EventList_0xC14787(void)
{

}

#if 1
//CAN BUSOFF
void DTC_EventList_0xC07988(void)
{

}
#endif

//鏁磋溅鏃堕棿澶辨晥
void DTC_EventList_0x620986(void)
{

}

//婢舵牜鏅〒鈺佸婢惰鲸鏅�
void DTC_EventList_0x620A86(void)
{

}

//鍔犻�熻笍鏉夸俊鍙疯秴鑼冨洿
void DTC_EventList_0x626128(void)
{

}

//鍔犻�熻笍鏉夸俊鍙锋棤鏁�
void DTC_EventList_0x626129(void)
{

}

/**
 * @brief : zq
 * @function : ECU_Power_Battery
 */
void DTC_EventList_0x6200(void)
{

}

/**
 * @brief : zq
 * @function : Body_Acceleration_Sensor_FL_Signal_Fault
 */
void DTC_EventList_0x6202(void)
{

}

/**
 * @brief : zq
 * @function : acceleration sensor front left: signal failure/sensor defect
 */
void DTC_EventList_0x621B(void)
{

}

/**
 * @brief : zq
 * @function : Body_Acceleration_Sensor_FR_Signal_Fault
 */
void DTC_EventList_0x6203(void)
{

}

/**
 * @brief : zq
 * @function : acceleration sensor front right: signal failure/sensor defect
 */
void DTC_EventList_0x621A(void)
{

}

/**
 * @brief : zq
 * @function : Body_Acceleration_Sensor_Rr_Signal_Fault
 */
void DTC_EventList_0x6204(void)
{

}

/**
 * @brief : zq
 * @function : acceleration sensor front rear: signal failure/sensor defect
 */
void DTC_EventList_0x621C(void)
{

}

/**
 * @brief : zq
 * @function : pressure sensor
 */
void DTC_EventList_0x6211(void)
{


}

/**
 * @brief : zq
 * @function : temperature sensor
 */
void DTC_EventList_0x6212(void)
{

}

/**
 * @brief : zq
 * @function : High Sensor Signal Fault-FL
 */
void DTC_EventList_0x6229(void)
{

}

/**
 * @brief : zq
 * @function : High Sensor Signal Fault-FL(PWM Duty Too High锛�
 */
void DTC_EventList_0x621F(void)
{

}

/**
 * @brief : zq
 * @function : High Sensor Signal Fault-FR
 */
void DTC_EventList_0x622A(void)
{

}

/**
 * @brief : zq
 * @function : High Sensor Signal Fault-FR(PWM Duty Too High锛�
 */
void DTC_EventList_0x621E(void)
{

}

/**
 * @brief : zq
 * @function : High Sensor Signal Fault-RL
 */
void DTC_EventList_0x622B(void)
{

}

/**
 * @brief : zq
 * @function : High Sensor Signal Fault-RL(PWM Duty Too High锛�
 */
void DTC_EventList_0x621D(void)
{

}

/**
 * @brief : zq
 * @function : High Sensor Signal Fault-RR
 */
void DTC_EventList_0x622C(void)
{

}

#if 0
/**
 * @brief : zq
 * @function : High Sensor Signal Fault-RR(PWM Duty Too High锛�
 */
void DTC_EventList_0x621C(void)
{
    uint8 highStatus = GetHighSensorDiagStatus(HIGH_SENSOR_RR);

    switch (highStatus)
    {
        case SENSOR_DIAG_STATUS_NORMAL:
            DTC_SetDtcStatus(DemEventParameter_0x621C29, DEM_EVENT_STATUS_PASSED);
            break;

        case HEIGHT_SENSOR_DIAG_STATUS_INPUT_PWM_TOO_LOW:
        case HEIGHT_SENSOR_DIAG_STATUS_INPUT_PWM_TOO_HIGH:
            DTC_SetDtcStatus(DemEventParameter_0x621C29, DEM_EVENT_STATUS_FAILED);
            break;
        
        default:
            DTC_SetDtcStatus(DemEventParameter_0x621C29, DEM_EVENT_STATUS_PASSED);
            break;
    }
}
#endif

/**
 * @brief : zq
 * @function : damper valve rear right  鍚庡彸鍑忔尟鍣ㄧ數纾侀榾
 */
void DTC_EventList_0x620C(void)
{

}

/**
 * @brief : zq
 * @function : damper valve rear left  鍚庡乏鍑忔尟鍣ㄧ數纾侀榾
 */
void DTC_EventList_0x620D(void)
{

}

/**
 * @brief : zq
 * @function : damper valve front right  鍓嶅彸鍑忔尟鍣ㄧ數纾侀榾
 */
void DTC_EventList_0x620E(void)
{
 
}

/**
 * @brief : zq
 * @function : damper valve front left  鍓嶅乏鍑忔尟鍣ㄧ數纾侀榾
 */
void DTC_EventList_0x620F(void)
{

}

/**
 * @brief : zq
 * @function : level control valve front left 鍓嶅乏楂樺害鎺у埗鐢电闃�
 */
void DTC_EventList_0x6218(void)
{

}

/**
 * @brief : zq
 * @function : level control valve front right 鍓嶅彸楂樺害鎺у埗鐢电闃�
 */
void DTC_EventList_0x6217(void)
{

}

/**
 * @brief : zq
 * @function : level control valve rear left 鍚庡乏楂樺害鎺у埗鐢电闃�
 */
void DTC_EventList_0x6216(void)
{

}

/**
 * @brief : zq
 * @function : level control valve rear right 鍚庡彸楂樺害鎺у埗鐢电闃�
 */
void DTC_EventList_0x6215(void)
{

}

/**
 * @brief : zq
 * @function : reservoir valve 鍌ㄦ皵缃愮數纾侀榾
 */
void DTC_EventList_0x6214(void)
{

}

/**
 * @brief : zq
 * @function : exhaust valve 鎺掓皵鐢电闃�
 */
void DTC_EventList_0x6213(void)
{

}

#define T_1S5 150
#define T_3S 300
void DTC_ConditionHandle(void)
{

}

GroupEnum g_dtcGroup = GROUPNoNum0; 
void DTC_EventListTask(void)
{
    
}
/*  END OF FILE */
