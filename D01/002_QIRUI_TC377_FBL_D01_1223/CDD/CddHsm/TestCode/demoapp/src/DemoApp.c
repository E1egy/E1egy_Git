/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : DemoApp.c $                                                **
**                                                                           **
**  $CC VERSION : \main\dev_tc23x\6 $                                        **
**                                                                           **
**  $DATE       : 2014-05-26 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - sample Demo Test for all the  modules                    **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Test_Print.h"
#include "Test_Time.h"
#include "DemoApp_Cfg.h"
#if (PORT_DELIVERY == STD_ON)
#include "Port.h"
#endif
#include "DemoApp_FctCall.h"


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/* Module header files _ Module_Demo.h will include the Module.h*/
#if (MCU_DELIVERY == STD_ON)
#include "Mcu.h"
#endif

#if (HSSL_DELIVERY == STD_ON)
#include "Hssl_Demo.h"
#endif

#if (DIO_DELIVERY == STD_ON)
#include "Dio.h"
#endif

#if (GPT_DELIVERY == STD_ON)
#include "Gpt_Demo.h"
#endif

#if (SPI_DELIVERY == STD_ON)
#include "Spi_Demo.h"
#endif

#if (PWM_DELIVERY == STD_ON)
#include "Pwm_17_Gtm_Demo.h"
#endif

#if (ADC_DELIVERY == STD_ON)
#include "Adc_Demo.h"
#endif

#if (ICU_DELIVERY == STD_ON)
#include "Icu_17_GtmCcu6_Demo.h"
#endif

#if (WDG_DELIVERY == STD_ON)
#include "Wdg_17_Scu_Demo.h"
#endif

#if (FLS_DELIVERY == STD_ON)
#include "Fls_17_Pmu_Demo.h"
#endif

#if (FLSLOADER_DELIVERY == STD_ON)
#include "FlsLoader_Demo.h"
#endif

#if (FEE_DELIVERY == STD_ON)
#include "Fee_Demo.h"
#endif

#if (GTM_DELIVERY == STD_ON)
#include "Gtm_Demo.h"
#endif

#if (CAN_DELIVERY == STD_ON)
#include "Can_17_MCanP_Demo.h"
#endif

#if (FR_DELIVERY == STD_ON)
#include "Fr_17_Eray_Demo.h"
#endif

#if (LIN_DELIVERY == STD_ON)
#include "Lin_17_AscLin_Demo.h"
#endif

#if (ETH_DELIVERY == STD_ON)
#include "Eth_17_EthMac_Demo.h"
#endif

#if (CRC_DELIVERY == STD_ON)
#include "Crc_Demo.h"
#endif

#if (MSC_DELIVERY == STD_ON)
#include "Msc_Demo.h"
#endif

#if (UART_DELIVERY == STD_ON)
#include "Uart_Demo.h"
#endif

#if (SENT_DELIVERY == STD_ON)
#include "Sent_Demo.h"
#endif

#if (STM_DELIVERY == STD_ON)
#include "Stm_Demo.h"
#endif

#if (IOM_DELIVERY == STD_ON)
#include "Iom_Demo.h"
#endif

#if (DMA_DELIVERY == STD_ON)
#include "Dma_Demo.h"
#endif

#ifdef BFX_DELIVERY
#if (BFX_DELIVERY == STD_ON)
#include "Bfx_Demo.h"
#endif
#endif

#if (STDLIN_DELIVERY == STD_ON)
#include "StdLin_Demo.h"
#endif

#if (DSADC_DELIVERY == STD_ON)
#include "Dsadc_Demo.h"
#endif

#if (I2C_DELIVERY == STD_ON)
#include "I2c_Demo.h"
#endif

#if (SHE_DELIVERY == STD_ON)
#include "She_Demo.h"
#endif
/*******************************************************************************
**               Private Macro Definitions                                    **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/



/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
void DemoApp(void);
void DemoApp_PrintChoices(void);
void DemoApp_CallAnyFct (char *my_fct_name);
void DemoApp_CallMenuFct (char *my_fct_name);

void DemoApp_GotoDemoMenu(void);

void DemoApp_GotoMainMenu(void);
void DemoApp_DummyFct(void);
#ifdef CALL_BY_FUNCTION_AVAILABLE 
uint32 DemoApp_GetIndex (char *my_fct_name,
                         DemoApp_AnyFctListType const *list, 
                         uint32 list_size);
void DemoApp_GotoAnyFctMenu(void);
void DemoApp_ListFct(void);
#endif
#if (IFX_SAFETLIB_USED == STD_ON) 
_EXTERN_ void RA_DisableCyclicTest(void);
_EXTERN_ void RA_SetupDTI(void);
#endif
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
const DemoApp_FctListType DemoApp_FctList[] = 
{
  {" "  , DemoApp_DummyFct, "............ AUTOSAR DRIVERS..............."},
  #if (MCU_DELIVERY == STD_ON)  
  {"0"  ,Mcu_SWResetDemo, "  MCU: Mcu_Reset,Software Reset"},
  {"1"  ,Mcu_GetResetReasonDemo, "  MCU: Mcu_Reset,Get Reset Reason"},
  #if (MCU_SAFETY_ENABLE == STD_ON) && (MCU_INITCHECK_API == STD_ON)
  {"a"  ,Mcu_InitCheckDemo, "  MCU: Verify MCU Initialization"},  
  #endif
  #if (MCU_SET_STANDBY_CONTROL_API == STD_ON)
  {"b", Mcu_GotoStandbyDemoMenu, "MCU Standby Menu"},
  #endif
  #endif
  #if (DIO_DELIVERY == STD_ON)
  {"2"  ,DemoApp_Dio, "  DIO: Demo For DIO Driver"},
  #endif
  #if (GPT_DELIVERY == STD_ON)
  {"3"  ,Gpt_StartDemo, "  GPT:StartContinuousTimer : LED must start blinking for Every 4 Seconds."},
  {"4"  ,Gpt_StopDemo, "  GPT:StopTimer:LED must stop blinking. "},
  #endif
  #if (PWM_DELIVERY == STD_ON)
  {"5"  ,Pwm_17_Gtm_StartDemo, "  PWM: Start PWM,Default DutyCycle :50%"},
  {"6"  ,Pwm_17_Gtm_ChangeDutyDemo, "  PWM: Enter New DutyCycle as 0 NewDC:"},
  {"7"  ,Pwm_17_Gtm_DemoDisableNotification, "  PWM: Stop  PWM "},
  #endif
  #if (ICU_DELIVERY == STD_ON)
  {"8"  ,Icu_17_GtmCcu6_Demo, "  ICU: Read the PWM Duty Cycle and Period"},
  #endif
  #if (ADC_DELIVERY == STD_ON)
  {"9"  ,Adc_SWGroupDemo, "  ADC:Start ADC SW group: AdcSWGroup"},
  #endif
  #if (WDG_DELIVERY == STD_ON)
  {"c",Wdg_17_Scu_Demo, "  WDG: WDG Demo"},
  #endif
  #if (SPI_DELIVERY == STD_ON)
  {"d",Spi_EepromAccessDemo, "  SPI:EEPROM Demo using QSPI"},
  #endif
  #if (ETH_DELIVERY == STD_ON)
  {"e",Eth_17_Demo, "  ETH: ETH Demo "},
  #endif  
  #if (FLS_DELIVERY == STD_ON)
  {"f",Fls_17_Pmu_Demo, "  FLS: Demo"},
  #endif
  #if (FEE_DELIVERY == STD_ON)
  {"g",Fee_Demo, "  FEE: Demo"},
  #endif
  #if (GTM_DELIVERY == STD_ON)
  {"k",Gtm_Demo, "  GTM:GTM PWM Signal Generation"},
  #endif
  #if (LIN_DELIVERY == STD_ON)
  {"l",Lin_Demo, "  LIN  Demo "},
  #endif
  #if (CAN_DELIVERY == STD_ON)
  {"m",Can_17_MCanP_Demo, "  CAN: Demo"},
  #endif
  #if (STDLIN_DELIVERY == STD_ON)
  {"n",StdLin_Demo, "  StdLin:  Demo "},
  #endif
  #if (FLSLOADER_DELIVERY == STD_ON)
  {"o",FlsLoader_Demo, "  FLS_LOADER: Demo"},
  #endif
  #if (MSC_DELIVERY == STD_ON)
  {"p",Msc_Demo, "  MSC: Demo"},
  #endif
  #if (FR_DELIVERY == STD_ON)
  #ifdef FR_17_ERAY_PBCFG_0
  {"s",Fr_17_Eray_Demo, "  FlexRay Demo"},
  #endif
  #endif
  #if (DMA_DELIVERY == STD_ON)
  {"t",Dma_Demo, "  DMA  Demo "},
  #endif
  #if (UART_DELIVERY == STD_ON)
  {"u",Uart_Demo, "  UART Demo"},
  #endif
  #if (CRC_DELIVERY == STD_ON)
  {"x",Crc_Demo, "  CRC  Demo "},
  #endif  
  #if (STM_DELIVERY == STD_ON)
  {"y",Stm_StartDemo, "  STM  Demo "}, 
  #endif  
  #if (SENT_DELIVERY == STD_ON)
  {"z",Sent_StartDemo, "  SENT  Demo "},
  #endif  
  #if (IOM_DELIVERY == STD_ON)
  {"$",Iom_Demo, "  IOM  Demo "},
  #endif
  #ifdef BFX_DELIVERY
  #if (BFX_DELIVERY == STD_ON)
  {"j",Bfx_Demo, "  Bfx  Demo "},
  #endif
  #endif
  #if (HSSL_DELIVERY == STD_ON)  
  {"A"  ,Hssl_Demo, "  HSSL Demo"},
  #endif    
  #if (DSADC_DELIVERY == STD_ON)
  {"I",Dsadc_Demo, "  DSADC Demo "},
  #endif 
  #if (I2C_DELIVERY == STD_ON)
  {"J",I2c_Demo, "  I2c Demo "},
  #endif 
  #if (SHE_DELIVERY == STD_ON)
  {"S"  ,DemoApp_She, "  SHE: Demo For SHE "},
  #endif

  { ".", DemoApp_GotoMainMenu , "Goto main menu" }

};

const DemoApp_MenuType DemoApp_DemoMenu=
{
  sizeof(DemoApp_FctList) / sizeof(DemoApp_FctListType),
  &DemoApp_FctList[0]
};

const DemoApp_FctListType DemoApp_MainList[]=
{
  { " " , DemoApp_DummyFct             , "------------- MAIN Menu ------------- "  },
  { "0" , DemoApp_GotoDemoMenu,   "go to Demo List"  },
#ifdef CALL_BY_FUNCTION_AVAILABLE  
  { "1" , DemoApp_GotoAnyFctMenu,  "Call any function"  },
#endif
  #if (IFX_SAFETLIB_USED == STD_ON)
  { "2" , RA_SetupDTI,  "SafeTlib- Enable Cyclic tests"  },
  { "3" , RA_DisableCyclicTest,  "SafeTlib- Enable PostRun tests (Disable Cyclic tests)"  },
  #endif
};
const DemoApp_MenuType DemoApp_MainMenu=
{
  sizeof(DemoApp_MainList) / sizeof(DemoApp_FctListType),
  &DemoApp_MainList[0]
};

#ifdef CALL_BY_FUNCTION_AVAILABLE 
const DemoApp_FctListType DemoApp_AnyFctList[]=
{
  { " " , DemoApp_DummyFct             , "------------- CALL any function ------------- "  },
  { "xx", DemoApp_DummyFct             , "Type the name the function you want to call" },
  { "1" , DemoApp_ListFct      , "list all available functions" },
  { ".", DemoApp_GotoMainMenu , "Goto main menu" },
};
const DemoApp_MenuType DemoApp_AnyFct_menu=
{
  sizeof(DemoApp_AnyFctList) / sizeof(DemoApp_FctListType),
  &DemoApp_AnyFctList[0]
};
#endif
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
DemoApp_MenuType const *DemoApp_Menu_p;
char szString[80];
uint32 str_pos; /* position of the pointer in the receive buffer */
char fct_str[35];
uint32 uwData[4];
volatile uint32 DemoApp_LedGlowDur = 0xFFFFFFFF;
volatile uint8 DemoApp_GlowLed;

/*******************************************************************************
**                      Private  Constant Definitions                         **
*******************************************************************************/


/*******************************************************************************
**                     Private  Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
** Syntax : void DemoApp(void)                                                **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Demo Tests for all the delivered Modules.                    **
*******************************************************************************/
void DemoApp(void)
{
/*******************************************************************************
**                    Menu options on the hyperterminal                       **
*******************************************************************************/
#ifdef CALL_BY_FUNCTION_AVAILABLE 
  uint32 cnt;
#endif  
  int char_val;

  DemoApp_Menu_p = &DemoApp_MainMenu;
  str_pos=0;
  
  print_flushfifo();
  
#if (FR_DELIVERY == STD_ON)
#ifdef FR_17_ERAY_PBCFG_1
  /*
    Call FlexRay node 1 demo application. This application infinitely
    waits for Flexray node 0 to synchronise and transmit/receive data.
    This is done in an infinite loop, so it never goes to next statement in
    this program.
    Preprocessor switch FR_17_ERAY_PBCFG_1 is defined during build time.
  */
  Fr_17_Eray_Demo();
#endif
#endif
  DemoApp_PrintChoices();
  print_f("\nEnter Option Number: ");
  for (;;)
  {
    //char_val = getlineWithPos(szString, sizeof szString - 1,&str_pos);
     char_val = 0x0D;
    if (char_val == 0x0D)
    {
	  str_pos = 0;
      print_f("\n\n");
      DemoApp_CallMenuFct(szString);
      DemoApp_PrintChoices();
      print_f("\nEnter Option Number: ");
    }
#ifdef CALL_BY_FUNCTION_AVAILABLE     
    else if (char_val == TAB && DemoApp_Menu_p == &DemoApp_AnyFct_menu)
    {
      cnt = DemoApp_GetIndex(szString,DemoApp_AllFctList,DemoApp_AnyFctListSize);
      if(cnt<DemoApp_AnyFctListSize)
      {
        /* if the name correspond exactly to a name of the list, propose the 
        next one */
        cnt++;
        if ( cnt >= DemoApp_AnyFctListSize)
        {
          cnt = 0;
        }
        erase_line(szString,&str_pos);
        put_buffer(szString, sizeof szString - 1,
                   DemoApp_AllFctList[cnt].fct_name,&str_pos);
      }
      else if (cnt & 0x80000000)
      {
        /* the name does not exist in the list, propose the nearest one's */
        cnt = cnt & 0x7FFFFFFF;
        erase_line(szString,&str_pos);
        put_buffer(szString, sizeof szString - 1,
                   DemoApp_AllFctList[cnt].fct_name,&str_pos);
      }
    }
#endif    

  }  
}/*End of Demo App */

/*******************************************************************************
** Syntax : void DemoApp_CallMenuFct(char *)                                  **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): char describing the function                              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : call the demo function corresponding to the parameter        **
*******************************************************************************/
void DemoApp_CallMenuFct (char *my_fct_name)
{

uint32 cnt;
uint32 cnt_max = DemoApp_Menu_p->size;

    my_fct_name[0] = 'S';
  for (cnt=0;cnt<cnt_max;cnt++)
  {
    if(DemoApp_Menu_p->list[cnt].fct_name[0] == my_fct_name[0])
    {
        (* DemoApp_Menu_p->list[cnt].fct_p)();
        return;
    }
  }
  
#ifdef CALL_BY_FUNCTION_AVAILABLE   
  if(DemoApp_Menu_p == &DemoApp_AnyFct_menu)
  {
    DemoApp_CallAnyFct(my_fct_name);
    return;
  }
  if(my_fct_name[0] == '&')
  {
    DemoApp_CallAnyFct(&my_fct_name[1]);
    return;
  }
#endif

}

/*******************************************************************************
** Syntax : void DemoApp_PrintChoices(void)                                   **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : print choices                                                **
*******************************************************************************/
void DemoApp_PrintChoices(void)
{
uint32 cnt;
uint32 cnt_max = DemoApp_Menu_p->size;
  print_f("\n");
  for (cnt=0;cnt<cnt_max;cnt++)
  {
    print_f(" <%s>: %s\n",DemoApp_Menu_p->list[cnt].fct_name,
                          DemoApp_Menu_p->list[cnt].fct_desc);
  }
}
/*******************************************************************************
** Syntax : void DemoApp_GotoDemoMenu(void)                                   **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Reentrant                                                  **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Initializes the Menu Pointer to the Demo Menu.               **
*******************************************************************************/
void DemoApp_GotoDemoMenu(void)
{
  DemoApp_Menu_p = &DemoApp_DemoMenu;
}

#ifdef CALL_BY_FUNCTION_AVAILABLE
/*******************************************************************************
** Syntax : void DemoApp_GotoAnyFctMenu(void)                                 **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Reentrant                                                  **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Initializes the Menu Pointer to the any Function Menu.       **
*******************************************************************************/
void DemoApp_GotoAnyFctMenu(void)
{
  DemoApp_Menu_p = &DemoApp_AnyFct_menu;
}
#endif
/*******************************************************************************
** Syntax : void DemoApp_GotoMainMenu(void)                                   **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Reentrant                                                  **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Initializes the Menu Pointer to the Main Menu.               **
*******************************************************************************/
void DemoApp_GotoMainMenu(void)
{
  DemoApp_Menu_p = &DemoApp_MainMenu;
}
/*******************************************************************************
** Syntax : void DemoApp_DummyFct(void)                                       **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Reentrant                                                  **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Dummy function to call when no operation has to be performed **
*******************************************************************************/
void DemoApp_DummyFct(void)
{
}

#ifdef CALL_BY_FUNCTION_AVAILABLE 
/*******************************************************************************
** Syntax : void DemoApp_ListFct(void)                                        **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Reentrant                                                  **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Function to list all the functions present                   **
*******************************************************************************/
void DemoApp_ListFct(void)
{
  uint32 cnt;
  uint32 cnt_max = DemoApp_AnyFctListSize;

  for (cnt=0;cnt<cnt_max;cnt++)
  {
    print_f("\n%d: ",cnt);
    print_f("%s",DemoApp_AllFctList[cnt].fct_name);
  }
  print_f("\n");
}

/*******************************************************************************
** Syntax : void DemoApp_CallAnyFct(char *)                                   **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : call any SW function                                         **
*******************************************************************************/
void DemoApp_CallAnyFct (char *my_fct_name)
{

  uint32 cnt;
  uint32 return_val = 0;
  uint32 cnt_max    = DemoApp_AnyFctListSize;
  uint32 InputParamCnt;
  uint32 InputPtrParamCode = 0;
  cnt = DemoApp_GetIndex(my_fct_name,DemoApp_AllFctList,cnt_max);
  
  if(cnt<cnt_max)
  {

    /* print_f("found index number: %d\n",cnt); */

    if (sscanf(my_fct_name, "%s %lx %lx %lx %lx", fct_str, &uwData[0],         \
        &uwData[1], &uwData[2],                                                \
        &uwData[3]) == DemoApp_AllFctList[cnt].num_in_par + 1)
    {
      /* print_f("correct number of input parameter\n"); */
      /* from Tricore EABI (Embedded Applications Binary Interface): */
      /* Non-Pointer Arguments:
         Up to four 32-bit non-pointer arguments are passed in registers D[4] 
         through D[7],
         with no more than one argument assigned per register.
         Integral arguments whose natural size in memory is less than 32-bits 
         (characters and short integers) are expanded to 32-bits 
         for purposes of argument passing. 
      */
      /* Pointer Arguments:
         Up to four pointer arguments are passed in registers A[4] through A[7].
         Pointer arguments include the base address 
         for arrays passed as arguments and 
         for structure arguments whose size is greater than 64-bits.
      */
      if (DemoApp_AllFctList[cnt].num_in_par == 0)
      {
        return_val = ((uint32 (*) (void))DemoApp_AllFctList[cnt].fct_p)();
      }
      else
      {
        for (InputParamCnt = 0 ; 
             InputParamCnt < DemoApp_AllFctList[cnt].num_in_par ; 
             InputParamCnt++)
        {
          if(DemoApp_AllFctList[cnt].fct_in_par[InputParamCnt] == 33)
          {
            InputPtrParamCode = InputPtrParamCode | (1U<<InputParamCnt);
          }
        }
      }
      switch (InputPtrParamCode)
      {
        case 0:
        {
          return_val = ((uint32 (*) (uint32,uint32,uint32,uint32)) \
          DemoApp_AllFctList[cnt].fct_p)(uwData[0],uwData[1],uwData[2],
          uwData[3]);
          break;
        }
        case 1:
        {
          return_val = ((uint32 (*) (uint32*,uint32,uint32,uint32)) \
          DemoApp_AllFctList[cnt].fct_p)((uint32 *)uwData[0],uwData[1],uwData[2]
          ,uwData[3]);
          break;
        }
        case 2:
        {
          return_val = ((uint32 (*) (uint32,uint32*,uint32,uint32)) \
          DemoApp_AllFctList[cnt].fct_p)(uwData[0],(uint32 *)uwData[1],uwData[2]
          ,uwData[3]);
          break;
        }
        case 3:
        {
          return_val = ((uint32 (*) (uint32*,uint32*,uint32,uint32)) \
          DemoApp_AllFctList[cnt].fct_p)((uint32 *)uwData[0],(uint32 *)uwData[1]
          ,uwData[2],uwData[3]);
          break;
        }
        case 4:
        {
          return_val = ((uint32 (*) (uint32,uint32,uint32*,uint32)) \
          DemoApp_AllFctList[cnt].fct_p)(uwData[0],uwData[1],(uint32 *)uwData[2]
          ,uwData[3]);
          break;
        }
        case 5:
        {
          return_val = ((uint32 (*) (uint32*,uint32,uint32*,uint32)) \
          DemoApp_AllFctList[cnt].fct_p)((uint32 *)uwData[0],uwData[1],
          (uint32 *)uwData[2],uwData[3]);
          break;
        }
        case 6:
        {
          return_val = ((uint32 (*) (uint32,uint32*,uint32*,uint32)) \
          DemoApp_AllFctList[cnt].fct_p)(uwData[0],(uint32 *)uwData[1],
          (uint32 *)uwData[2],uwData[3]);
          break;
        }
        case 7:
        {
          return_val = ((uint32 (*) (uint32*,uint32*,uint32*,uint32)) \
          DemoApp_AllFctList[cnt].fct_p)((uint32 *)uwData[0],
          (uint32 *)uwData[1],(uint32 *)uwData[2],uwData[3]);
          break;
        }
        case 8:
        {
          return_val = ((uint32 (*) (uint32,uint32,uint32,uint32*)) \
          DemoApp_AllFctList[cnt].fct_p)(uwData[0],uwData[1],uwData[2],
          (uint32 *)uwData[3]);
          break;
        }
        case 9:
        {
          return_val = ((uint32 (*) (uint32*,uint32,uint32,uint32*)) \
          DemoApp_AllFctList[cnt].fct_p)((uint32 *)uwData[0],uwData[1],
          uwData[2],(uint32 *)uwData[3]);
          break;
        }
        case 10:
        {
          return_val = ((uint32 (*) (uint32,uint32*,uint32,uint32*)) \
          DemoApp_AllFctList[cnt].fct_p)(uwData[0],(uint32 *)uwData[1],
          uwData[2],(uint32 *)uwData[3]);
          break;
        }
        case 11:
        {
          return_val = ((uint32 (*) (uint32*,uint32*,uint32,uint32*)) \
          DemoApp_AllFctList[cnt].fct_p)((uint32 *)uwData[0],
          (uint32 *)uwData[1],uwData[2],(uint32 *)uwData[3]);
          break;
        }
        case 12:
        {
          return_val = ((uint32 (*) (uint32,uint32,uint32*,uint32*)) \
          DemoApp_AllFctList[cnt].fct_p)(uwData[0],uwData[1],
          (uint32 *)uwData[2],(uint32 *)uwData[3]);
          break;
        }
        case 13:
        {
          return_val = ((uint32 (*) (uint32*,uint32,uint32*,uint32*)) \
          DemoApp_AllFctList[cnt].fct_p)((uint32 *)uwData[0],uwData[1],
          (uint32 *)uwData[2],(uint32 *)uwData[3]);
          break;
        }
        case 14:
        {
          return_val = ((uint32 (*) (uint32,uint32*,uint32*,uint32*)) \
          DemoApp_AllFctList[cnt].fct_p)(uwData[0],(uint32 *)uwData[1],
          (uint32 *)uwData[2],(uint32 *)uwData[3]);
          break;
        }
        case 15:
        {
          return_val = ((uint32 (*) (uint32*,uint32*,uint32*,uint32*)) \
          DemoApp_AllFctList[cnt].fct_p)((uint32 *)uwData[0],
          (uint32 *)uwData[1],(uint32 *)uwData[2],(uint32 *)uwData[3]);
          break;
        }
        default:
        {
          print_f("The DemoApp only supports pointers up to the 4th position\n");
        }
      }

      if (DemoApp_AllFctList[cnt].out_par > 0)
      {
        print_f("return value:%x\n",return_val);
      }
    }
    else if (DemoApp_AllFctList[cnt].num_in_par > 4)
    {
      print_f("error:functions with more than 4 parameters are not supported\n\n");
    }
    else
    {
      print_f("error: incorrect number of input parameter !! \n\n");
    }
  }
  else if (cnt & 0x80000000)
  {
    cnt = cnt & 0x7FFFFFFF;
    print_f("The function does not exist!\nThe nearest index found: %d : %s\n",\
            cnt,DemoApp_AllFctList[cnt].fct_name);
  }

}

/*******************************************************************************
** Syntax : void DemoApp_GetIndex(char *my_fct_name,                          **
**                                DemoApp_AnyFctListType const *list,         **
**                                uint32 list_size)                           **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): my_fct_name  - Function Name                              **
**                  list - Pointer to the list for searching                  **
**                  list_size - size of the list                              **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : get index of a list with type DemoApp_AnyFctListType and     **
** return an ored value with 0x80000000 to give the nearest index if no exact **
** string was found                                                           **
*******************************************************************************/
uint32 DemoApp_GetIndex (char *my_fct_name,DemoApp_AnyFctListType const *list, 
                         uint32 list_size)
{
uint32 idx_l;
uint8  idx_c;
uint32 best_idx_l=0;
uint8  best_idx_c=0;
uint32 found_idx = 0x80000000;

  /* loop on line */
  for(idx_l=0;idx_l<list_size;idx_l++)
  {
    idx_c=0;
    /*Loop on character in the line.Stop loop if one string arrives to the end*/
    while ( list->fct_name[idx_c] != 0 && my_fct_name[idx_c] != 0 && \
            my_fct_name[idx_c] != 0x20)
    {
      if (list->fct_name[idx_c] != my_fct_name[idx_c])
      {
        break; /* the 2 strings are not equal */
      }
      idx_c++;
    }
    if (list->fct_name[idx_c] == 0 && ( my_fct_name[idx_c] == 0 || \
        my_fct_name[idx_c] == 0x20))
    {
      /* found ! */
      found_idx = idx_l;
      break;
    }
    else
    {
      /* check if there are more good characters in this line */
      if(idx_c > best_idx_c)
        {
          best_idx_c = idx_c;
          best_idx_l = idx_l;
        }
    }
    list++;
  }
  /* if not found or the best line with 0x80000000 */
  if (found_idx == 0x80000000)
  {
    found_idx = 0x80000000 | best_idx_l;
  }
  return(found_idx);
}
#endif



