/*
   pit.h
   University of Michigan
   EECS 461, Embedded Control Systems
   PIT module
 */

#include "MPC5643L.h"
#include "eecs461.h"
#include "IntcInterrupts.h"

/* PIT Parameters */
#define ADCISR_PIT_CHANNEL 2

/* Functions for PIT */
void initPIT(unsigned short channel,
                        int frequency,
            INTCInterruptFn interruptHandler,
              unsigned char priority);

void enable_interrupts(void);
void disable_interrupts(void);
