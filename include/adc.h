/*
   adc.h
   University of Michigan
   EECS 461, Embedded Control Systems
   Analog to Digital Converter module
   Read Chapter 8 in MPC5643 User's Manual
 */

#include "MPC5643L.h"
#include "eecs461.h"

/* Functions for Analog to Digital Conversion */
void initSIUADC0(char numChannels, char channelArray[]);
void initADC0_oneshot(char numChannels, char channelArray[]);
void initADC0_scan(char numChannels, char channelArray[]);
vuint16_t readADC0_oneshot(int channel);
vuint16_t readADC0_scan(int channel);
