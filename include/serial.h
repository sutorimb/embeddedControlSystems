/*
   serial.h
   University of Michigan
   EECS 461, Embedded Control Systems
   UART serial module
   Read Chapter 30 in MPC5643 User's Manual
 */

#include "MPC5643L.h"
#include "eecs461.h"

void initUART(int baudrate);
char serial_putchar(unsigned char sbyte);
void serial_puts(char *sptr);
char serial_readyToReceive();
char serial_getchar();
