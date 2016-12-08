/*
   flexcan.c
   University of Michigan
   EECS 461, Embedded Control Systems
   Controller-Area Network module
   Read Chapter 24 in MPC5643 User's Manual
 */

#include "flexcan.h"
#include "IntcInterrupts.h"

#define NUM_BUFFERS 16
#define BUSY_BIT 0x01

#ifndef NULL
#define NULL ((void *) 0)
#endif


void initFlexcan()
{
	uint16_t i, x;
	volatile uint16_t j;

	/* PCR 16 = TX pin.  Enable by setting to ALT1.
	 See page 99 of MPC5643 manual. */
	SIU.PCR[16].B.PA = 0b01;
	SIU.PCR[16].B.OBE = 0b1;

	/* PCR 17 = RX pin.  Enable by setting PSMI[33].PADSEL = 1.
	 We also want to set PCR input pin up. */
	SIU.PCR[17].B.IBE = 1;
	SIU.PSMI[33].R = 0x01;

	/*Enable the CAN module */
	CAN_0.MCR.B.MDIS = 0;

	/* Reset FlexCAN Module */
	CAN_0.MCR.B.SOFT_RST = 1;
	while( CAN_0.MCR.B.SOFT_RST == 1){}

	/*Disable the CAN module */
	CAN_0.MCR.B.MDIS = 1;

	/* Set CAN clock source 1: bus , 0: oscillator */
	CAN_0.CR.B.CLK_SRC = 0;

	/*Enable the CAN module */
	CAN_0.MCR.B.MDIS = 0;

	CAN_0.MCR.B.FRZ = 1;
	CAN_0.MCR.B.HALT = 1;
	CAN_0.MCR.B.SUPV = 1;
	CAN_0.MCR.B.MAXMB = NUM_BUFFERS - 1;  // we are using 16 buffers
	CAN_0.MCR.B.SRX_DIS = 0;

	CAN_0.CTRL.B.PRESDIV = 4;
	CAN_0.CTRL.B.RJW = 3;
	CAN_0.CTRL.B.PSEG1 = 5;
	CAN_0.CTRL.B.PSEG2 = 5;
	CAN_0.CTRL.B.PROPSEG = 2;

	/* clear memory from message buffer 0 to 15 */
	for(x=0; x < 16; x++)
	{
		CAN_0.BUF[x].CS.R = 0;
		CAN_0.BUF[x].ID.R = 0;
		for(i=0; i < 2; i++) 
		{
			CAN_0.BUF[x].DATA.W[i] = 0;
		}
	}

	CAN_0.RXGMASK.R  = 0x1FFFFFFF;
	CAN_0.RX14MASK.R = 0x0;
	CAN_0.RX15MASK.R = 0x0;

	CAN_0.IMASK1.R = 0x00000000;
	CAN_0.CTRL.B.LPB = 0;
	
	CAN_0.MCR.B.HALT = 0;
	CAN_0.MCR.B.FRZ  = 0;
    
	/* await synchronization (delay) */
	for(j=1; j < 255; j++){}
}



// Refer to table 24-4 message buffer code for Rx buffers
int can_rxbuff_init(int buff_num, int id, int useIRQ )
{

  /* check for valid buff_num */
	if( buff_num > 15)    // Only enabled 15 buffers for now
		return(-3);
	
	// inactive the buffer first
	CAN_0.BUF[buff_num].CS.B.CODE = 0x0;
	// set ID to standard mode
	CAN_0.BUF[buff_num].CS.B.IDE = 0x0;
	// assign frame identifier
	CAN_0.BUF[buff_num].ID.B.STD_ID = id;
	// active the message buffer now
	CAN_0.BUF[buff_num].CS.B.CODE = 0x4;

	if ( useIRQ ) {
		//  receive buffer we're initializing
		CAN_0.IMASK1.R |= 1<<buff_num; // OR mask with existing masks
	}

	return 0;
}



void can_set_rxisr(volatile INTCInterruptFn can_isr){

	/* We only need four buffers, 0-3, for module FlexCAN_0 */
        /* see Table 28-4 of the reference manual */
    unsigned short canIrqNum = 68;
	INTC_InstallINTCInterruptHandler(can_isr,canIrqNum,0xC);
	disable_interrupts();
}



int can_txmsg(CAN_TXBUFF *buff)
{
	int i;
	// disable buffer from tx first
	CAN_0.BUF[buff->buff_num].CS.B.CODE = 0x8;
	// frame format is standard, not extended
	CAN_0.BUF[buff->buff_num].CS.B.IDE= 0x0;
	// buffer identifier
	CAN_0.BUF[buff->buff_num].ID.B.STD_ID = buff->id;
	// remote transmission request, 0, has a data frame to be transmitted
	CAN_0.BUF[buff->buff_num].CS.B.RTR = 0x0;
	// receive data, length is in bytes
	for (i = (buff->length)-1; i >= 0; i--)
	CAN_0.BUF[buff->buff_num].DATA.B[i] = buff->data[i];

	CAN_0.BUF[buff->buff_num].CS.B.LENGTH = buff->length;
	CAN_0.BUF[buff->buff_num].CS.B.CODE = 0xC;

	return 0;
}



int can_rxmsg(CAN_RXBUFF *buff)
{
	int i;

	if ( buff == NULL )
		return -1;

	if( can_get_buff_flag(buff->buff_num)) 
	{
		/* For more information about what you must do after a message is received,
		   consult page 636-637 of MPC5643L Microcontroller Reference Manual. */

		/* It is mandatory to read the Control and Status word, as it activates
		   an internal lock for the buffer.  Likewise, we must check if the
		   BUSY bit is set in the Code field and if so then wait until it's not. */
		while( CAN_0.BUF[buff->buff_num].CS.B.CODE & BUSY_BIT );

		/* Next, we must read the ID field. */
		buff->id = CAN_0.BUF[buff->buff_num].ID.B.STD_ID;

		/* These aren't mandatory by the processor, but populating these fields
		   is convenient. */
		buff->isFilled = 1;
		buff->length = (unsigned char)( CAN_0.BUF[buff->buff_num].CS.B.LENGTH );    
		buff->length = (buff->length > 8 ? 8 : buff->length);

		/* Get the data.  Mandatory step. */
		for(i=0; i < buff->length; i++)
			buff->data[i] = CAN_0.BUF[buff->buff_num].DATA.B[i]; /* Read data byte 
																	by byte */
		/* Read the free running timer, which unlocks the buffer.
		   Mandatory step. */
		buff->frt = CAN_0.TIMER.R;

		/* Clear IFLAG so the next receive is visible to us when it happens. */
		can_clear_buff_flag(buff->buff_num);
	} 
	else 
	{
		/* Message is NOT in buff because someone didn't bother checking whether
		there was a message to receive before trying to receive it. */
		buff->isFilled = 0;
		return 1;
	}
	return 0;
}



int can_get_buff_flag(int buff)
{
	if ( buff < 0 || buff > NUM_BUFFERS-1 )
		return -3;

	/* Return the appropriate IFLAG bit. */
	return (((CAN_0.IFLAG1.R) >> buff) & 0x01);
}



int can_clear_buff_flag(int buff)
{
	if ( buff < 0 || buff > NUM_BUFFERS-1 )
		return -3;

	/* Clear the appropriate IFLAG bit. */
	CAN_0.IFLAG1.R = (1 << buff);
	return 0;
}
