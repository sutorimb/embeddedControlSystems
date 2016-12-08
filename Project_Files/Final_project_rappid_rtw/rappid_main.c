/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rappid_main.c
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

/* Model's headers */
#include "Final_project.h"
#include "target.h"
#include "sys_init.h"
#include "linflex_init.h"
#include "linflex_siu_init.h"
#include "freemaster_cfg.h"
#include "adc_init.h"
#include "adc_trigger_init.h"
#include<adc0_config.h>
#include "flexpwm_init.h"

extern const vuint32_t ISRVectorTable[];
void SYSTEM_INIT_TASK(void)
{
  /* Initialize model */
  Final_project_initialize();
}

void SYSTEM_TASK(void)
{
  boolean_T eventFlags[2];             /* Model has 2 rates */

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  Final_project_SetEventsForThisBaseStep(eventFlags);

  /* Set model inputs associated with base rate here */
  Final_project_step(0);

  /* Get model outputs here */
  if (eventFlags[1]) {
    /* Set model inputs associated with subrates here */
    Final_project_step(1);

    /* Get model outputs here */
  }
}

void pit_init_fnc(void)
{
  //PIT.PITMCR.R = 0x00000001;

  /* ----------------------------------------------------------- */

  /*               Configure Load Value Registers                */

  /* ----------------------------------------------------------- */

  //    PIT.CH[1].LDVAL.R  =  0x00124F7F;    /* The model's base sample time is 0.01 seconds. */

  /* ----------------------------------------------------------- */

  /*                     Enable Interrupts                       */

  /* ----------------------------------------------------------- */

  //    PIT.CH[1].TCTRL.R  = 0x00000003;
  PIT.PITMCR.B.MDIS = 1 ;

  /*Disable PIT for initialization         */

  /* ----------------------------------------------------------- */

  /*                     Configure Load Value Registers                */

  /* ----------------------------------------------------------- */
  PIT.CH[0].LDVAL.R = 0x00124F7F;      /* The model's base sample time is 0.01 seconds. */

  /* ----------------------------------------------------------- */

  /*                     Enable Interrupts                  */

  /* ----------------------------------------------------------- */
  PIT.CH[0].TCTRL.B.TIE = 0x1 ;

  /* ----------------------------------------------------------- */

  /*                   Start Timers                 */

  /* ----------------------------------------------------------- */
  PIT.CH[0].TCTRL.B.TEN = 0x1 ;

  /*Start Timer 0 is : Enabled    */
  PIT.PITMCR.B.MDIS = 0 ;

  /*PIT Module : Enabled        */
}

void PIT_Ch0_ISR(void)
{
  /* Attach SYSTEM_TASK to a timer or interrupt service routine with

   * period 0.01 seconds (the model's base sample time) here.  The

   * call syntax for SYSTEM_TASK is  SYSTEM_TASK();

   */
  PIT.CH[0].TFLG.B.TIF = 1 ;
  SYSTEM_TASK();
}

void main(void)
{
  /* Shut Down Software Watchdog Timer */

  /* remove the SWT Soft lock  */
  SWT.SR.R = 0x0000C520;
  SWT.SR.R = 0x0000D928;

  /* Disable SWT  */
  SWT.CR.B.WEN = 0x0;
  sys_init_fnc();                      /* Disable Watchdog */
  adc_init_fnc();                      /* Adc configuration */
  adc0_config();
  adc_normal_start_fnc();
  flexpwm_init_fnc();                  /* General FlexPWM initialization */
  linflex_init_fnc();
  linflex_siu_init();
  FMSTR_Init();
  SYSTEM_INIT_TASK();                  /* Initialize the processor. */
  pit_init_fnc();                      /* Initialize PIT Timer Module */
  INTC.CPR.B.PRI = 0;                  /* Ensure INTC's current priority is 0 */
  intc_init_fnc();
  asm(" wrteei 1");                    /* Enable IRQ */
  INTC.CPR.R = 0x0A;                   /* Global Minimum Interrupt Priority */
  while (1) {
    FMSTR_Poll();
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
