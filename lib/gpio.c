/*
   gpio.c
   University of Michigan
   EECS 461, Embedded Control Systems
   General-Purpose Input/Output module
   Read Chapter 47 in MPC5643 User's Manual
 */

#include "MPC5643L.h"
#include "gpio.h"

const int LED[16] = {43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58};
const int DIP[16] = {5,6,7,8,9,10,11,12,13,14,51,52,53,55,56,57};

void initGPDI(unsigned short port) 
{
  SIU.PCR[port].B.APC = 0;
  SIU.PCR[port].B.PA  = 0;
  SIU.PCR[port].B.WPE = 0;
  SIU.PCR[port].B.WPS = 0;
  SIU.PCR[port].B.OBE = 0;
  SIU.PCR[port].B.IBE = 1;
}

void initGPDO(unsigned short port)
{
  SIU.PCR[port].B.APC = 0;
  SIU.PCR[port].B.PA  = 0;
  SIU.PCR[port].B.WPE = 0;
  SIU.PCR[port].B.WPS = 0;
  SIU.PCR[port].B.OBE = 1;
  SIU.PCR[port].B.IBE = 0;
}

unsigned short readGPIO(unsigned short port) {
  return (unsigned short)SIU.GPDI[port].B.PDI;
}

void writeGPIO(unsigned short port, unsigned short val) {
  SIU.GPDO[port].R = (vuint8_t)val;
}
