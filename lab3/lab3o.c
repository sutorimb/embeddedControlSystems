/*===========================================================================
#
# EECS461 at the University of Michigan
# Lab 3 solution (oscope)
#
# Created 2004 ericjw
#
# Revision History::
#   7-25-06 lovelljc
#   1-24-07 ericjw
#   11-6-09 wangyef
#   1-25-13 jmapatel
===========================================================================*/

#include <MPC5643L.h>
//#include "parameters.h"
#include "pitLab3.h"
#include <serial.h>
//#include <qadc.h>
#include "adc.h"

#define NUM_POINTS    500

#define ONE_SHOT_CHANNEL     0



#define ADC0_NUMCHANNELS 1
static char channelArray[ADC0_NUMCHANNELS] = {ONE_SHOT_CHANNEL};

char command = '0';
//static vuint32_t num_used[1];
uint16_t buffer[NUM_POINTS];
vuint32_t *used;

void ocIsr (void){
  if (*used >= NUM_POINTS)
    disable_interrupts();
  else {
    //buffer[num_used] = qadcReadQ1();
    buffer[*used] = readADC0_oneshot(0);
    (*used)++;
  }
  /* Clear PIT Timer Interrupt Acknowledgement Flag */
  PIT.CH[LAB3_PIT_CHANNEL].TFLG.B.TIF = 1;
}

int main(void) {
  uint16_t tmp2;
  uint16_t cnt;
  /* If you make num_used a global variable, the C compiler puts
     num_used into a register within main() for reasons unknown,
     which turns the while-loop later in this function into an
     infinite loop.  Setting the variable to volatile changes
     nothing.  The "used" pointer is a hack designed to force
     the compiler to make a memory lookup, don't touch it. */
  vuint32_t num_used;
  used = &num_used;

  initEECS461();
  initGPDO(43);
  initGPDO(44);

  initUART(57600);

  initADC0_oneshot(ADC0_NUMCHANNELS, channelArray);

  INTC_InitINTCInterrupts();
  // initializes the periodic interrupt timer to provide 50kHz sample
  // rate for the virtual oscilloscope and use pit channel 1
  initPITLab3(&ocIsr, 0xC);
  INTC.CPR_PRC0.R = 0x00;

  while (1) {
    disable_interrupts();
    /*initialize variables*/
    num_used = 0;
    /*Check serial port for command*/
    while (!serial_readyToReceive(1)){}

    /*If command received, read ADC*/
    command = serial_getchar(1);
    enable_interrupts();
    while (num_used < NUM_POINTS){}

    /*clear command*/
    command = '0';

    /* send data */
    for (cnt = 0; cnt < num_used; cnt++)
    {
      tmp2 = buffer[cnt];
      serial_putchar((unsigned char)(tmp2 & 0x00FF));
      serial_putchar((unsigned char)((tmp2 & 0xFF00) >> 8));
    } 
  }

  return 0;
}

/* EOF */
