/*
   serial.c
   University of Michigan
   EECS 461, Embedded Control Systems
   UART serial module
   Read Chapter 30 in MPC5643 User's Manual
 */

#include "MPC5643L.h"
#include "eecs461.h"
#include "serial.h"

/******************************************************************************
 * Function:    initUART
 * Description: Initializes UART mode
 ******************************************************************************/
void initUART(int baudrate)
{
  unsigned long SYSTEM_FREQUENCY;
  /* Configure LINFlex 0 pins */
  SIU.PCR[19].B.PA = 1;               // Pin asigned to LINFlex0 Rx
  SIU.PCR[19].B.IBE = 1;              // Input buffer enable
  SIU.PCR[18].B.PA = 1;               // Pin asigned to LINFlex0 Tx
  SIU.PCR[18].B.OBE = 1;              // Output buffer enable
  SYSTEM_FREQUENCY = getSysFreq();
  
  /* configure linflex0 */
  LINFLEX_0.LINCR1.B.SLEEP = 0x0;     // disable sleep mode
  LINFLEX_0.LINCR1.B.INIT  = 0x1;     // init mode
  LINFLEX_0.UARTCR.B.UART  = 0x1;     // UART mode

  LINFLEX_0.UARTCR.B.TDFL_TFC = 0x0;  // buffer size = 1 byte
  LINFLEX_0.UARTCR.B.RDFL_RFC0 = 0x0; // buffer size = 1 byte
  LINFLEX_0.UARTCR.B.RFBM = 0;        // UART buffer mode
  LINFLEX_0.UARTCR.B.TFBM = 0;        // UART buffer mode
  LINFLEX_0.UARTCR.B.RXEN = 0x1;      // receiver enable
  LINFLEX_0.UARTCR.B.TXEN = 0x1;      // transmitter enable
  LINFLEX_0.UARTCR.B.PCE  = 0x0;      // parity control disable
  LINFLEX_0.UARTCR.B.WL0 = 0x1;       // word length 8-bit data
  LINFLEX_0.LINIBRR.B.IBR = (int)(SYSTEM_FREQUENCY/16/baudrate);  
  // Baud rate calculation
  LINFLEX_0.LINFBRR.B.FBR = (SYSTEM_FREQUENCY/16/baudrate-
                             (int)(SYSTEM_FREQUENCY/16/baudrate))*16;
  
  LINFLEX_0.LINCR1.B.INIT = 0x0;      // normal mode
}

/******************************************************************************
 * Function:    serial_putchar
 * Description: outputs sbyte
 ******************************************************************************/
char serial_putchar(unsigned char sbyte)
{ 
  LINFLEX_0.BDRL.B.DATA0 = sbyte;

  while(!LINFLEX_0.UARTSR.B.DTF_TFF); //wait untill completing transmission
  LINFLEX_0.UARTSR.R = 0x2;           //Clear DTF after completing transmission
  return 0;
}

/******************************************************************************
 * Function:    serial_puts
 * Description: Increases the pointer
 ******************************************************************************/
void serial_puts(char *sptr)
{
  while(*sptr)
  {
    serial_putchar(*sptr);
    sptr++;
  }
}

char serial_readyToReceive()
{
  return (char)LINFLEX_0.UARTSR.B.DRF_RFE;
}

/******************************************************************************
 * Function:    serial_getchar
 * Description: Gets the input from the keyboard
 ******************************************************************************/
char serial_getchar()
{
  char data; 

  while(!LINFLEX_0.UARTSR.B.DRF_RFE) ; /* wait for new incoming data */

  data = (char)(LINFLEX_0.BDRM.B.DATA4) & 0x00FF; // read data
  LINFLEX_0.UARTSR.B.RMB = 0;                     // buffer is free
  LINFLEX_0.UARTSR.B.DRF_RFE = 0;                 /* Clear DRF */
  return data;
}
