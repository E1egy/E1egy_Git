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
* \file:   ReadDTCInformation_0x19.h
*
* \brief  The header file of ReadDTCInformation_0x19.c
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
* <tr><td>2023-03-09 <td>1.0     <td>BL_zq     <td>内容
* @endinternal
*******************************************************************************/

#ifndef  READDTCINFORMATION_0X19_H
#define  READDTCINFORMATION_0X19_H

/***************************************Includes***************************************/
#include "Platform_Types.h"

/***************************************Macros****************************************/
#define IGN_STATE_OFF       ((Ign_StateType)0x00u)
#define IGN_STATE_ON        ((Ign_StateType)0x01u)

#define DTC_NUMBER_MAX 191
/***************************************Enum*****************************************/
typedef enum
{
    GROUPNoNum0 = 0,
    GROUPNoNum1 ,
    GROUPNoNum2 ,
    GROUPNoNum3 ,
    GROUPNoNum4 ,
    GROUPNoNum5 ,
    GROUPNoNum6 ,
}GroupEnum;
/***************************************Union****************************************/

/***************************************Struct***************************************/
typedef uint8 Ign_StateType;
/***************************************Variables*************************************/
//extern 
/***************************************Functions************************************/
extern void DTC_Init(void);
extern void DTC_ConditionHandle(void);
extern void DTC_EventListTask(void);
extern void SET_DTCBUSOFF_Flag(boolean DTC_BUSOFF_flag);
extern boolean GET_DTCBUSOFF_Flag(void);
#endif
/*  END OF FILE */
