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
* $Name______: UserTestTask.h$
* $Variant___: 1.0.1$
* $Revision__: 0$
* $Author____: YM$
**
**--------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**--------------------------------------------------------------------------------------------------------------------**
** DESCRIPTION:
** UserTestTask driver header file
***********************************************************************************************************************/
#ifndef USER_TEST_TASK_H_
#define USER_TEST_TASK_H_

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "UserTestTask_Cfg.h"

/***********************************************************************************************************************
**                        				Macro Definition                        								      **
***********************************************************************************************************************/

/***********************************************************************************************************************
**										Typedef Definition															  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                        				Global Variables With Extern Linkage                			  		  	  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                 						Global Function Prototypes          					  		              **
***********************************************************************************************************************/

#if(USER_TEST_TASK_ENABLE_CORE0 == 1U)
/***********************************************************************************************************************
** Function Name	: UserTestTaskCore0_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore0_Init
***********************************************************************************************************************/
extern	void UserTestTaskCore0_Init(void);

/***********************************************************************************************************************
** Function Name	: UserTestTaskCore0_10Ms
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore0_10Ms
***********************************************************************************************************************/
extern	void UserTestTaskCore0_10Ms(void);
#endif	/*#if(USER_TEST_TASK_ENABLE_CORE0 == 1U)*/

#if(USER_TEST_TASK_ENABLE_CORE1 == 1U)
/***********************************************************************************************************************
** Function Name	: UserTestTaskCore1_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore1_Init
***********************************************************************************************************************/
extern	void UserTestTaskCore1_Init(void);

/***********************************************************************************************************************
** Function Name	: UserTestTaskCore1_10Ms
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore1_10Ms
***********************************************************************************************************************/
extern	void UserTestTaskCore1_10Ms(void);
#endif	/*#if(USER_TEST_TASK_ENABLE_CORE1 == 1U)*/

#if(USER_TEST_TASK_ENABLE_CORE2 == 1U)
/***********************************************************************************************************************
** Function Name	: UserTestTaskCore2_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore2_Init
***********************************************************************************************************************/
extern	void UserTestTaskCore2_Init(void);

/***********************************************************************************************************************
** Function Name	: UserTestTaskCore2_10Ms
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore2_10Ms
***********************************************************************************************************************/
extern	void UserTestTaskCore2_10Ms(void);
#endif	/*#if(USER_TEST_TASK_ENABLE_CORE2 == 1U)*/

#if(USER_TEST_TASK_ENABLE_CORE3 == 1U)
/***********************************************************************************************************************
** Function Name	: UserTestTaskCore3_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore3_Init
***********************************************************************************************************************/
extern	void UserTestTaskCore3_Init(void);

/***********************************************************************************************************************
** Function Name	: UserTestTaskCore3_10Ms
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore3_10Ms
***********************************************************************************************************************/
extern	void UserTestTaskCore3_10Ms(void);
#endif	/*#if(USER_TEST_TASK_ENABLE_CORE3 == 1U)*/

#if(USER_TEST_TASK_ENABLE_CORE4 == 1U)
/***********************************************************************************************************************
** Function Name	: UserTestTaskCore4_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore4_Init
***********************************************************************************************************************/
extern	void UserTestTaskCore4_Init(void);

/***********************************************************************************************************************
** Function Name	: UserTestTaskCore4_10Ms
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore4_10Ms
***********************************************************************************************************************/
extern	void UserTestTaskCore4_10Ms(void);
#endif	/*#if(USER_TEST_TASK_ENABLE_CORE4 == 1U)*/

#if(USER_TEST_TASK_ENABLE_CORE5 == 1U)
/***********************************************************************************************************************
** Function Name	: UserTestTaskCore5_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore5_Init
***********************************************************************************************************************/
extern	void UserTestTaskCore5_Init(void);

/***********************************************************************************************************************
** Function Name	: UserTestTaskCore5_10Ms
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: UserTestTaskCore5_10Ms
***********************************************************************************************************************/
extern	void UserTestTaskCore5_10Ms(void);
#endif	/*#if(USER_TEST_TASK_ENABLE_CORE5 == 1U)*/

#endif /* USER_TEST_TASK_H_ */

/***********************************************************************************************************************
* $History__:$
* V1.0.0; 0     04.11.2019 YM
*  N: new created
* V1.0.1; 0 	16.06.2020 YM
*  I:  Update MemMap
***********************************************************************************************************************/
