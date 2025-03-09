/***********************************************************************************************************************
**--------------------------------------------------------------------------------------------------------------------**
** Copyright (c) 2019 by G-Pulse.		All rights reserved.
** This software is copyright protected and proprietary to G-Pulse.
** G-Pulse grants to you only those rights as set out in the license conditions.
** All other rights remain with G-Pulse.
**--------------------------------------------------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \TestCode\UserTestTask$
* $Class_____: C$
* $Name______: UserTestTaskCore3.c$
* $Variant___: 1.0.1$
* $Revision__: 0$
* $Author____: YM$
**
**--------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**--------------------------------------------------------------------------------------------------------------------**
** DESCRIPTION:
** UserTestTask driver source code
***********************************************************************************************************************/

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "UserTestTask.h"

//#include "Gp_CsaMonitor.h"
//#include "Gp_StackMonitor.h"
//#include "Gp_TimeCal.h"
/***********************************************************************************************************************
**                        					  Macro Definition                        								  **
***********************************************************************************************************************/
#if(USER_TEST_TASK_ENABLE_CORE3 == 1U)

/***********************************************************************************************************************
**                        					 Typedef Definition                        								  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                   					Static Local Variables Definition    						          		  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                  					   Global Variables Definition            						  		      **
***********************************************************************************************************************/
#define USER_TEST_TASK_INIT_FAR_DATA_START
#include "UserTestTask_MemMap.h"

uint32 UserTestCodeCore3_InitFlag = 0U;
uint32 UserTestCodeCore3_10msCnt = 0U;

#define USER_TEST_TASK_INIT_FAR_DATA_STOP
#include "UserTestTask_MemMap.h"

#define USER_TEST_TASK_CLEAR_FAR_DATA_START
#include "UserTestTask_MemMap.h"

#define USER_TEST_TASK_CLEAR_FAR_DATA_STOP
#include "UserTestTask_MemMap.h"

/***********************************************************************************************************************
**                						Static Local Function Declaration    					        		      **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                 							  Function Source Code          					  		              **
***********************************************************************************************************************/
#define USER_TEST_TASK_CODE_START
#include "UserTestTask_MemMap.h"
/***********************************************************************************************************************
** Function Name	: UserTestTaskCore3_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore3_Init
***********************************************************************************************************************/
void UserTestTaskCore3_Init(void)
{
	UserTestCodeCore3_InitFlag = 1U;
	Gp_StackMonitor_Init();
	Gp_CsaMonitor_Init();
}

/***********************************************************************************************************************
** Function Name	: UserTestTaskCore0_10Ms
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore3_10Ms
***********************************************************************************************************************/
void UserTestTaskCore3_10Ms(void)
{
	UserTestCodeCore3_10msCnt++;
	Gp_StackMonitor_Monitoring();
	Gp_CsaMonitor_Monitoring();

}
#define USER_TEST_TASK_CODE_STOP
#include "UserTestTask_MemMap.h"

#endif	/*#if(USER_TEST_TASK_ENABLE_CORE3 == 1U)*/

/***********************************************************************************************************************
* $History__:$
* V1.0.0; 0     04.11.2019 YM
*  N: new created
* V1.0.1; 0 	16.06.2020 YM
*  I:  Update MemMap
***********************************************************************************************************************/


