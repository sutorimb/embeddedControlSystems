/*
   pit.c
   University of Michigan
   EECS 461, Embedded Control Systems
   Periodic Interrupt Timer (PIT) module
   Read Chapter 36 in MPC5643 User's Manual
 */

#include "pitLab3.h"

/******************************************************************************
 * Function: initPITLab3
 * Description: Initializes Periodic Interrupt Timer
 * Note: You must call INTC_InitINTCInterrupts() to initialize interrupts
 * This is not a general purpose pit initialization function, and is used only
 * for the virtual oscilloscope in lab 3, were we
 * work with  pit channel 1 and pit frequency 50kHz
 ******************************************************************************/
void initPITLab3(volatile INTCInterruptFn interruptHandler, unsigned char priority)
{
  unsigned int startValue;
  unsigned short pitIrqNum;
  
  /* Calculate initial timer value */
  startValue = 2399;
  
  PIT.PITMCR.B.MDIS = 0b1;             // Clock for PIT Timers is disabled
  PIT.PITMCR.B.FRZ = 0b1;              // Timers are stopped in debug mode
  
  /* Initialize PIT */
  PIT.CH[LAB3_PIT_CHANNEL].LDVAL.R = startValue; // Load initial timer value
  PIT.CH[LAB3_PIT_CHANNEL].TCTRL.B.TIE = 0x1;    // Enable Interrupts	
  PIT.CH[LAB3_PIT_CHANNEL].TCTRL.B.TEN = 0x1;    // Start Timer
  
  PIT.PITMCR.B.MDIS = 0b0;             // Clock for PIT Timers is enabled
  
  /*  IRQ number - See Chapter 28.7 */
  pitIrqNum = 60;
 
  /* Install an interrupt handler for interrupt vector */
  INTC_InstallINTCInterruptHandler(interruptHandler, pitIrqNum, priority);
  pitIrqNum = 0;
}

void enable_interrupts(void)
{
  asm (" wrteei 1");            /* Enable External interrupts (MSR.EE=1) */
}

void disable_interrupts(void)
{
  asm (" wrteei 0");            /* (MSR.EE=0) */
}
