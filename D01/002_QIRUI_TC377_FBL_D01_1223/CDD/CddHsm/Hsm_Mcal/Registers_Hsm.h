/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : Registers_Hsm.h                                             **
**                                                                           **
**  VERSION    : 3.0.0                                                       **
**                                                                           **
**  DATE       : 2016-07-11                                                  **
**                                                                           **
**  VARIANT    : NA                                                          **
**                                                                           **
**  PLATFORM  : Infineon TC2xxxx Aurix Family                                **
**              [Refer Release Package for Supported Device]                 **
**  AUTHOR    : Trivikram G                                                  **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains registers description                   **
**                                                                           **
**                                                                           **
**                                                                           **
**  SPECIFICATION(S) : Aurix_SHE+_TC-CDRV_DS.docx                            **
**                                                                           **
**  MAY BE CHANGED BY USER : No                                              **
******************************************************************************/
#ifndef _REG_HSM_H
#define _REG_HSM_H
/******************************************************************************
**                      Includes                                             **
******************************************************************************/

/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/

#define HSM_ADDRESS_BASE               0xf0040000U
#define HSM_ADDRESS_RANGE              0x20000U

#define NUM_HSM 1



typedef volatile union
{
  unsigned U;
  int I;
  struct
  {

    unsigned MOD_REV:8;            /*  [7:0] Module Revision Number */
    unsigned MOD_TYPE:8;        /*  [15:8] Module Type */
    unsigned MOD_NUMBER:16;     /*  [31:16] Module Number Value */
  } B;
} HSM_ID_type;
#define HSM_ID (*( HSM_ID_type *) 0xf0040008u)  /* HSM Identifier Register */
/** Traceability    : [$Satisfies $CDS_CDRV 588]    **/
typedef volatile union
{
  unsigned U;
  int I;
  struct
  {
    unsigned HT2HSMF:32;        /*  [31:0] Host to HSM Flags */
  } B;
} HSM_HT2HSMF_type;
#define HSM_HT2HSMF (*( HSM_HT2HSMF_type *) 0xf0040020u)  /*Host to HSM Flags*/
/** Traceability    : [$Satisfies $CDS_CDRV 588]    **/
typedef volatile union
{
  unsigned U;
  int I;
  struct
  {
    unsigned HSM2HTF:32;        /*  [31:0] HSM to Host Flags */
  } B;
} HSM_HSM2HTF_type;
/* HSM to Host Flags */
#define HSM_HSM2HTF (*( HSM_HSM2HTF_type *) 0xf0040028u)

typedef volatile union
{
  unsigned U;
  int I;
  struct
  {
    unsigned HSM2HTIE:32;       /*  [31:0] HSM to Host Interrupt Enable */
  } B;
} HSM_HSM2HTIE_type;
/* HSM to Host Interrupt Enable */
#define HSM_HSM2HTIE (*( HSM_HSM2HTIE_type *) 0xf004002cu)

typedef volatile union
{
  unsigned U;
  int I;
  struct
  {
    unsigned HSM2HTIS:32;       /*  [31:0] HSM to Host Interrupt Select */
  } B;
} HSM_HSM2HTIS_type;
/* HSM to Host Interrupt Select */
#define HSM_HSM2HTIS (*( HSM_HSM2HTIS_type *) 0xf0040030u)
/** Traceability    : [$Satisfies $CDS_CDRV 588]    **/
typedef volatile union
{
  unsigned U;
  int I;
  struct
  {
    unsigned HSM2HTS:32;        /*  [31:0] HSM to Host Status */
  } B;
} HSM_HSM2HTS_type;
/* HSM to Host Status */
#define HSM_HSM2HTS (*( HSM_HSM2HTS_type *) 0xf0040034u)
/** Traceability    : [$Satisfies $CDS_CDRV 588]    **/
typedef volatile union
{
  unsigned U;
  int I;
  struct
  {
    unsigned HT2HSMS:32;        /*  [31:0] Host to HSM Status */
  } B;
} HSM_HT2HSMS_type;
/* Host to HSM Status */
#define HSM_HT2HSMS (*( HSM_HT2HSMS_type *) 0xf0040038u)

typedef volatile union
{
  unsigned U;
  int I;
  struct
  {
    unsigned EOMBT:2;           /*  [1:0] End of Memory BIST test. */
    unsigned RES:30;            /*  [31:2] Reserved */
  } B;
} HSM_HSMCTRL_type;
#define HSM_HSMCTRL (*( HSM_HSMCTRL_type *) 0xf0041000u)     /* HSM Control */

typedef volatile union
{
  unsigned U;
  int I;
  struct
  {
    unsigned RES:16;            /*  [15:0] Reserved */
    unsigned BASE:16;           /*  [31:16] Base Address. */
  } B;
} HSM_DBGBASE_type;
/* Debug Window Base Address */
#define HSM_DBGBASE (*( HSM_DBGBASE_type *) 0xf0041010u)

typedef volatile union
{
  unsigned U;
  int I;
  struct
  {
    unsigned TGS:2;             /*  [1:0] Trigger Set for OTGB0/1 */
    unsigned TGB:1;             /*  [2:2] OTGB0/1 Bus Select */
    unsigned TG_P:1;            /*  [3:3] TGS, TGB Write Protection */
    unsigned RES:28;            /*  [31:4] Reserved */
  } B;
} HSM_HSMOTGB_type;

/* OCDS Suspend and Trigger Bus Control */
#define HSM_HSMOTGB (*( HSM_HSMOTGB_type *) 0xf0041020u)


typedef union
{
  volatile unsigned char U8[131072];
  volatile unsigned short U16[65536];
  volatile unsigned int U32[32768];
  volatile unsigned U[32768];
  volatile int I[32768];
  struct
  {
    volatile unsigned RESERVED_00;
    volatile unsigned RESERVED_04;
    HSM_ID_type ID;             /*  0x08 */
    volatile unsigned RESERVED_0C_1C[5];
    HSM_HT2HSMF_type HT2HSMF;   /*  0x20 */
    volatile unsigned RESERVED_24;
    HSM_HSM2HTF_type HSM2HTF;   /*  0x28 */
    HSM_HSM2HTIE_type HSM2HTIE; /*  0x2c */
    HSM_HSM2HTIS_type HSM2HTIS; /*  0x30 */
    HSM_HSM2HTS_type HSM2HTS;   /*  0x34 */
    HSM_HT2HSMS_type HT2HSMS;   /*  0x38 */
    volatile unsigned RESERVED_3C_FFC[1009];
    HSM_HSMCTRL_type HSMCTRL;   /*  0x1000 */
    volatile unsigned RESERVED_1004;
    volatile unsigned RESERVED_1008;
    volatile unsigned RESERVED_100C;
    HSM_DBGBASE_type DBGBASE;   /*  0x1010 */
    volatile unsigned RESERVED_1014;
    volatile unsigned RESERVED_1018;
    volatile unsigned RESERVED_101C;
    HSM_HSMOTGB_type HSMOTGB;   /*  0x1020 */
  } SFR;
} hsm_sfrs_t;

#ifdef __WIN32__
#undef HSM_DBGBASE
#undef HSM_HT2HSMF
#undef HSM_HSM2HTF
#undef HSM_HSM2HTIE
#undef HSM_HSM2HTIS
#undef HSM_HSM2HTS
#undef HSM_HT2HSMS

extern HSM_DBGBASE_type  DBGBASE ;  /*  0x1010 */
extern HSM_HT2HSMF_type  HT2HSMF ;  /*  0x20 */
extern HSM_HSM2HTF_type  HSM2HTF ;  /*  0x28 */
extern HSM_HSM2HTIE_type HSM2HTIE;  /*  0x2c */
extern HSM_HSM2HTIS_type HSM2HTIS;  /*  0x30 */
extern HSM_HSM2HTS_type  HSM2HTS ;  /*  0x34 */
extern HSM_HT2HSMS_type  HT2HSMS ;  /*  0x38 */

#define HSM_DBGBASE     DBGBASE
#define HSM_HT2HSMF     HT2HSMF
#define HSM_HSM2HTF     HSM2HTF
#define HSM_HSM2HTIE    HSM2HTIE
#define HSM_HSM2HTIS    HSM2HTIS
#define HSM_HSM2HTS     HSM2HTS
#define HSM_HT2HSMS     HT2HSMS

#endif

/* _REG_HSM_H */
#endif
