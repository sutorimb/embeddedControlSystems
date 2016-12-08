/*
   flexcan.h
   University of Michigan
   EECS 461, Embedded Control Systems
   Controller-Area Network module
   Read Chapter 24 in MPC5643 User's Manual
 */

#ifndef  _FLEXCAN_INIT_H
#define  _FLEXCAN_INIT_H

#include "mpc5643l.h"
#include "typedefs.h"
#include "IntcInterrupts.h"

#define CAN_RX_ISR_CHANNEL   1
#define CAN_TX_ISR_CHANNEL   2
#define CAN_ISR_FREQUENCY    1000

typedef struct can_rxbuff 
{
  uint8_t  buff_num;         /* buffer to be filled */
  uint8_t  isFilled;         /* was a message received? */
  uint8_t  length;           /* length of data (bytes) */
  uint32_t id;               /* id registers */
  uint8_t  data[8];          /* data received */
  uint16_t frt;              /* free running-timer */
} CAN_RXBUFF;

typedef struct can_txbuff 
{                                         
  uint8_t  buff_num;         /* buffer to use for sending */
  uint32_t id;               /* id registers */
  uint8_t  length;           /* length of data to tx (bytes) */
  uint8_t  data[8];          /* data to transmit */
} CAN_TXBUFF;

void initFlexcan(void);
int can_txmsg(CAN_TXBUFF *buff);
int can_rxmsg(CAN_RXBUFF *buff);
int can_rxbuff_init(int buff_num, int id, int useIRQ);
void can_set_rxisr(volatile INTCInterruptFn can_isr);
int can_clear_buff_flag(int buff);

#endif  
