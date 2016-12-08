/*
   gpio.c
   University of Michigan
   EECS 461, Embedded Control Systems
   General-Purpose Input/Output module
   Read Chapter 47 in MPC5643 User's Manual

   Revision History:
     2014-02-08  Yitian Chen
     2014-07-04  GPCz
 */
#ifndef __GPIO_H__
#define __GPIO_H__

extern const int LED[16];
extern const int DIP[16];

/*=============================================================================
    Section 1: GPIO initialization
    The module provides dedicated general-purpose pads
    that can be configured as either inputs or outputs.
=============================================================================*/

// Sets up port as GPDI, given PCR number
void initGPDI(unsigned short port);

// Sets up port as GPDO, given PCR number
void initGPDO(unsigned short port);

/*=============================================================================
    Section 2: GPIO utilization
=============================================================================*/
/*
    When configured as an input, you can detect the
    state of the associated pad by reading the value
    from an internal register.
*/
unsigned short readGPIO(unsigned short port);

/*
    When configured as an output, you can write to an
    internal register to control the state driven on the
    associated output pad.
*/
void writeGPIO(unsigned short port, unsigned short val);

/*
    When configured as an input and output, the pad value
    can be read back, which can be used a method of checking
    if the written value appeared on the pad.
*/

#endif
