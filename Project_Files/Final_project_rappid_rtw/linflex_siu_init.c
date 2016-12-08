/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: linflex_siu_init.c
 *
 * Code generated for Simulink model 'Final_project'.
 *
 * Model version                  : 1.107
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Fri Dec 02 14:00:56 2016
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objective: Traceability
 * Validation result: Not run
 */

/********************  Dependent Include files here **********************/
#include "target.h"

/**********************  Initialization Function(s) *************************/
void linflex_siu_init(void)
{
  /* ----------------------------------------------------------------------- */

  /*      Pad Configuration Register PCR[18]  LIN_TXD */

  /* ----------------------------------------------------------------------- */
  SIU.PCR[18].R = 0x400;

  /*	Selected Function : LIN_TXD_0        */

  /*	Output Buffers : Enabled          */

  /*	Input Buffers : Disabled          */

  /*	Output Drain : Disabled           */

  /*	Slew Rate Control : Minimum       */

  /*	Weak Pull Up/Down : Disabled      */

  /*	Weak Pull Up/Down Select : Down   */

  /* ----------------------------------------------------------- */

  /*      Pad Configuration Register PCR[19]  LIN_RXD */

  /* ----------------------------------------------------------- */
  SIU.PCR[19].R = 0x0100;

  /*	Selected Function : PB[3] I        */

  /*	Output Buffers : Disabled         */

  /*	Input Buffers : Enabled           */

  /*	Output Drain : Disabled           */

  /*	Slew Rate Control : Minimum       */

  /*	Weak Pull Up/Down : Disabled      */

  /*	Weak Pull Up/Down Select : Down   */
  SIU.PSMI[31].B.PADSEL = 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
