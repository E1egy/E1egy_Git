/**
 * *******************************************************************************
 *                                     BAOLONG
 *                            -------------------------
 *                            Details to create profits
 * 
 * @copyright Copyright (c) 2022  ShangHai BAOLONG Electronics Stock Co., Ltd. All rights reserved.
 * 
 * Contact information:
 * web site:    https://www.baolong.biz/
 * e-mail:      sbic@baolong.biz
 * *******************************************************************************
 * 
 * @file PCTest.h
 * 
 * @brief 
 * 
 * @author xiatianxiong (xiatianxiong@chinabaolong.net)
 * 
 * @version v1.0
 * 
 * @date 2022-12-22
 * 
 * @par modification history:
 * <table>
 * <tr><th>Date       <th>Version <th>Author       <th>Description
 * <tr><td>2022-12-22 <td>1.0     <td>zhangqin     <td>内容
 * </table>
 */
#ifndef _PCTEST_H_
#define _PCTEST_H_
#include "Std_Types.h"


#define  EOL_TEST_STATUS1       1
#define  EOL_TEST_STATUS2       2

/** 
* @brief
*
*/
typedef struct
{
    uint8  lossCmdCount;///<
    uint8 magicNum;///<
    boolean CDCEnableFlag;///<
    boolean ValveEnableFlag;///<
    boolean rxCmd;
    boolean pcCommandIsActive;
    uint8 rxMsg[7];  
}PcCommandMsg;


extern void PcTestMainFunction(void);
extern boolean GetPcCommandIsActive(void);
extern void SendPcTestCanMsg(void);
extern void PctestPackMsg(void);
extern void SetPcCommandMsg(boolean flag,uint8 *data, uint8 len);
#endif
