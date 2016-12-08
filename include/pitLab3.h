/*
   pitLab3.h
   University of Michigan
   EECS 461, Embedded Control Systems
   PIT Modile for SW oScope
 */

#include "MPC5643L.h"
#include "eecs461.h"
#include "IntcInterrupts.h"

#define LAB3_PIT_CHANNEL 1

/* Functions for PIT */
void initPITLab3(INTCInterruptFn interruptHandler,
              unsigned char priority);

void enable_interrupts(void);
void disable_interrupts(void);
