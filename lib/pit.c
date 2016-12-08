/*
   pit.c
   University of Michigan
   EECS 461, Embedded Control Systems
   Periodic Interrupt Timer (PIT) module
   Read Chapter 36 in MPC5643 User's Manual
 */

#include "pit.h"

/******************************************************************************
 * Function: initPIT
 * Description: Initializes Periodic Interrupt Timer
 * Note: You must call INTC_InitINTCInterrupts() to initialize interrupts
 ******************************************************************************/
void initPIT(unsigned short channel, int frequency,
             volatile INTCInterruptFn interruptHandler, unsigned char priority)
{
  unsigned int startValue;
  unsigned short pitIrqNum;
  
  /* Determine number of counts in one period of PIT */
  startValue = 120000000/frequency-1;
  
  PIT.PITMCR.B.MDIS = 1;  // Clock for PIT Timers is disabled
  PIT.PITMCR.B.FRZ  = 1;  // Timers are stopped in debug mode
  
  /* Initialize PIT */
  PIT.CH[channel].LDVAL.R = startValue;         // Timeout Period
  PIT.CH[channel].TCTRL.B.TIE = 1;  // Enable Interrupts	
  PIT.CH[channel].TCTRL.B.TEN = 1;  // Start Timer
  
  PIT.PITMCR.B.MDIS = 0;    // Clock for PIT Timers is enabled
  
  /* Determine IRQ number - See Chapter 28.7 */
  switch (channel)
  {
	case 0:
      pitIrqNum = 59;
	break;
	case 1:
      pitIrqNum = 60;
	break;
	case 2:
      pitIrqNum = 61;
	break;
	case 3:
	  pitIrqNum = 127;
	break;
  }
  
  /* Install an interrupt handler for interrupt vector */
  INTC_InstallINTCInterruptHandler(interruptHandler, pitIrqNum, priority);
}

void enable_interrupts(void)
{
  asm (" wrteei 1");            /* Enable External interrupts (MSR.EE=1) */
}

void disable_interrupts(void)
{
  asm (" wrteei 0");            /* (MSR.EE=0) */
}
