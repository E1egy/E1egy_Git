/**
 * *******************************************************************************
 *                                     BAOLONG
 *                            -------------------------
 *                            Details to create profits
 * 
 * @copyright Copyright (c) 2023  ShangHai BAOLONG Electronics Stock Co., Ltd. All rights reserved.
 * 
 * Contact information:
 * web site:    https://www.baolong.biz/
 * e-mail:      sbic@baolong.biz
 * *******************************************************************************
 * 
 * @file HscXcp.h
 * 
 * @brief 
 * 
 * @author xiatianxiong (xiatianxiong@chinabaolong.net)
 * 
 * @version v1.0
 * 
 * @date 2023-03-30
 * 
 * @par modification history:
 * <table>
 * <tr><th>Date       <th>Version <th>Author       <th>Description
 * <tr><td>2023-03-30 <td>1.0     <td>zhangqin     <td>内容
 * </table>
 */
#ifndef _HSCXCP_H_
#define _HSCXCP_H_

#include "Os.h"
#include "Rte_Data.h"


extern  void RE_MemModeBSW_Init(void);
extern  void Mem_CdcModeBsw(void);
extern  void HeightMsgCalibrationBsw(void);

// 0 : no NVM OPERATION ;  1 : NVM operation start ;  2 : NVM operation sucessful
/**
* @brief State of NVM for complex drive operation
*
*/
typedef enum
{
	NVM_NO_OPERATION = 0,///<NO NVM OPERATION
	NVM_PENDING, ///< NVM operation start
	NVM_SUCESS,///< NVM operation sucessful
	NVM_FAULT ///< NVM operation fault
}NVM_WRITE_STATUS;

#endif
