/*
  EECS461
  Lab 7
*/
#include "MPC5643L.h"
#include "serial.h"
#include "eecs461.h"
#include "pwm.h"
#include "pit.h"
#include "flexcan.h" 
#include "qd.h"

#ifdef VWALLA
void virt_wall_A(void);
#endif

#ifdef VWALLB
void virt_wall_B(void);
#endif

#ifdef VCHAIN
void virt_chain();
#endif


//*************************************************************************************
// EDIT STATION IDS
#define STATIONBASEID 40 /* ID of your lab station */
#define VWPARTNERID  30/* fill in */ /* ID of your partner's lab station for the virtual wall */
#define CHAIN_A_ID  30/* fill in */ /* ID of the station to your "left" */
#define CHAIN_B_ID  50/* fill in */ /* ID of the station to your "right" */
//*************************************************************************************

uint16_t vwA_tx_ID = 0 + STATIONBASEID;
uint16_t vwA_rx_ID = 1 + VWPARTNERID;
uint16_t vwB_tx_ID = 1 + STATIONBASEID;
uint16_t vwB_rx_ID = 0 + VWPARTNERID;

const uint8_t vwA_tx_buffnum = 0;
const uint8_t vwA_rx_buffnum = 1;
const uint8_t vwB_tx_buffnum = 2;
const uint8_t vwB_rx_buffnum = 3;

uint16_t chain_tx_ID = 2 + STATIONBASEID;
uint16_t chainA_rx_ID = 2 + CHAIN_A_ID;
uint16_t chainB_rx_ID = 2 + CHAIN_B_ID;

const uint8_t chain_tx_buff_num = 0;
const uint8_t chainA_rx_buff_num = 1;
const uint8_t chainB_rx_buff_num = 2;

/* Shared Data: the CAN message-received ISR copies new data into
 * the following variables */
static volatile float vw_torque=0;	/* wall torque (FLOAT32, N-mm) */
static volatile float posA=0;		/* chain position A (FLOAT32, N-mm) */
static volatile float velA=0;		/* chain velocity A (FLOAT32, N-mm) */
static volatile float posB=0;		/* chain position B (FLOAT32, N-mm) */
static volatile float velB=0;		/* chain velocity B (FLOAT32, N-mm) */


/***************************************************************************
 * Function:	rx_ISR()
 * Description:	This interrupt is called when a CAN message is received.
 ***************************************************************************/
void rx_ISR(void)
{
	CAN_RXBUFF rxbuff;
	int ret;

	#ifdef VWALLA
		/* Message for: Virtual Wall A */
		/* First check to see if there is a new message in the buffer */
		if ( can_get_buff_flag(vwA_rx_buffnum) == 1 )
		{
			rxbuff.buff_num=vwA_rx_buffnum;
			/* Read the CAN message and copy torque to global variable */
			ret=can_rxmsg(&rxbuff);
			/* is the read successful and is the message the right length? */
			if(ret!=0){
				exit (-2); /*error*/
			}
			if (ret==0 && rxbuff.length==4){
			//Copy over the data from the CAN buffer to rxbuff and
			//set the contents of rxbuff correctly
			memcpy(&vw_torque,rxbuff.data, sizeof(vw_torque));
			}	

			// If the message was properly sent and makes sense, then
			// update our virtual torque with it.
			
		}
	#endif

	#ifdef VWALLB
		/* Message for: Virtual Wall B */
		/* First check to see if there is a new message in the buffer */
		if ( can_get_buff_flag(vwB_rx_buffnum) == 1 ) {
			/* Let virt_wall_B() handle this */
			virt_wall_B();
		}
	#endif

	#ifdef VCHAIN
		/* Message for: Virtual Chain (from A) */
		/* First check to see if there is a new message in the buffer */

		//** NOTE: position and velocity are sent together as a package.
		//**       position is the first four bytes, and velocity is
		//**       the second 4 bytes.
		
		if( can_get_buff_flag(chainA_rx_buff_num) == 1 )
		{
			/* 1. Set the contents of rxbuff correctly */
			rxbuff.buff_num=chainA_rx_buff_num;		
			/* 2. Receive CAN message */
			ret=can_rxmsg(&rxbuff);
			if(ret!=0){
				exit (-2); /*error*/
			}
			/* 3. Check if read is successful and message has the right length */
			/* Copy position and velocity to global variable */
			if (ret==0 &&rxbuff.length==8){
			memcpy(&posA,rxbuff.data, sizeof(posA));
			memcpy(&velA,rxbuff.data+4, sizeof(velA));
			}

		}

		/* Message for: Virtual Chain (from B) */
		/* First check to see if there is a new message in the buffer */
		if( can_get_buff_flag(chainB_rx_buff_num) == 1 )
		{
			/* 1. Set the contents of rxbuff correctly */
			rxbuff.buff_num=chainB_rx_buff_num;		
			/* 2. Receive CAN message */
			ret=can_rxmsg(&rxbuff);
			if(ret!=0){
				exit (-2); /*error*/
			}

			/* 3. Check if read is successful and message has the right length */
			/* Copy position and velocity to global variable */
			if (ret==0 &&rxbuff.length==8){
			memcpy(&posB,rxbuff.data, sizeof(posB));
			memcpy(&velB,rxbuff.data+4, sizeof(velB));
			}
		}
	#endif
	PIT.CH[CAN_RX_ISR_CHANNEL].TFLG.B.TIF = 1;
}



/***************************************************************************
 * Function:	virt_wall_A()
 * Description:	Implements the sensing and actuation of the virtual wall.
 *				It applies the calculated torque received from wall B. 
 *				It then reads the wheel position and transmits it to wall B. 
 * Shared Data: vw_torque (FLOAT32, N-mm)
 * 
 * 1. Apply the current torque value (last received)
 * 2. Read the wheel position
 * 3. Transmit the wheel position & velocity in a CAN message
 ***************************************************************************/
#ifdef VWALLA
void virt_wall_A() {
	CAN_TXBUFF txbuff;		/* buffer to tx wheel angle & velocity */
	float   curr_angle=0;

	/* 1. Apply the current torque value (last received) */
	outputTorque(vw_torque);
	
	/* 2. Read the wheel position */
	curr_angle = updateAngle();
	/* 3. Transmit the wheel position in a CAN message */
	memcpy(txbuff.data,&curr_angle, sizeof(curr_angle));
	txbuff.buff_num=vwA_tx_buffnum;
	txbuff.length = sizeof(curr_angle);
	txbuff.id = vwA_tx_ID;
	if(can_txmsg(&txbuff)!=0){
		exit(-3); 
	}
	// clear interrupt flag
	PIT.CH[CAN_TX_ISR_CHANNEL].TFLG.B.TIF = 1;
}
#endif


 /***************************************************************************
 * Function:	virt_wall_B()
 * Description:	Implements the computation of the virtual wall.
 *				It calculates torque from the received position  
 *				value from wall A. 
 * 
 * 1. Read the CAN message
 * 2. Calculate the torque
 * 3. Transmit the torque as a CAN message
 ***************************************************************************/
#ifdef VWALLB
 void virt_wall_B(void) {
  
	CAN_RXBUFF rxbuff;
	CAN_TXBUFF txbuff;
	
	float curr_angle;
	float k_vw = 500;		/* spring constant of the wall (N-mm/deg) */
	float torque;
	int ret;

	/* 1. Read the CAN message */
	/**** is the read successful and is the message the right length? ***/
	rxbuff.buff_num=vwB_rx_buffnum;
	/* Read the CAN message and copy torque to global variable */
	ret=can_rxmsg(&rxbuff);
	/* is the read successful and is the message the right length? */
	if(ret!=0){
		exit (-2); /*error*/
	}
	if (ret==0 &&rxbuff.length==4){
	memcpy(&curr_angle,rxbuff.data, 4);

	/* 2. Calculate the torque */
if (curr_angle<0){
       torque=0;
    }
    else {
        torque= -500*curr_angle;
    }	/* 3. Transmit the torque back */
	txbuff.buff_num=vwB_tx_buffnum;
	memcpy(txbuff.data,&torque, sizeof(torque));
	txbuff.length = sizeof(torque);
	txbuff.id = vwB_tx_ID;
		if(can_txmsg(&txbuff)!=0){
			exit(-3); 
		}
	}
}
#endif



 /***************************************************************************
 * Function:	virt_chain()
 * Description:	Implements one station in part of a chain.  The position and
 *				velocity of neighboring stations are received and the 
 *				appropriate torque calculations are applied.
 * Equation:	k*(posA+posB-2*pos) + b*(velA+velB-2*vel)
 * Shared Data: posA (float, deg)
 *				velA (float, deg/s)
 *				posB (float, deg)
 *				velB (float, deg/s)
 * 
 * 1. Read wheel angle (deg)
 * 2. Calculate wheel velocity (deg/s)
 * 3. Calculate & apply torque
 * 4. Transmit the wheel position and velocity
 ***************************************************************************/
#ifdef VCHAIN
const uint32_t vc_f = 250; /* frequency of the chain wall (Hz) */
const float k = 25.0;      /* spring-rate (N-mm/deg) */
const float b = 0.2;       /* damping (N-mm/(deg/s)) */

void virt_chain()
{
	CAN_TXBUFF txbuff; 		/* buffer to transmit pos and velocity */
	float curr_angle, velocity,torque_left,torque_right,torque;
	static float prev_angle=0;

	/* 1. Read wheel angle (deg) */
	curr_angle=updateAngle();

	/* 2. Calculate wheel velocity (deg/s) */
	velocity=(curr_angle-prev_angle)*vc_f;
	
	/* 3. Calculate & apply torque  */
	torque_left=k*(posA-curr_angle)+b*(velA-velocity);
	torque_right=k*(posB-curr_angle)+b*(velB-velocity);
	torque=torque_left+torque_right;
	outputTorque(torque);	

	prev_angle=curr_angle;

	/* 4. Transmit your wheel position and velocity */
	/**** 8-bytes (first 4 for position and second 4 for velocity) ****/
	memcpy(txbuff.data,&curr_angle,sizeof(curr_angle));
 	memcpy(txbuff.data+4,&velocity,sizeof(velocity));
	txbuff.buff_num=chain_tx_buff_num;
	txbuff.length = sizeof(curr_angle)+sizeof(velocity);
	txbuff.id = chain_tx_ID;
	if(can_txmsg(&txbuff)!=0){
		exit(-3); 
	}
	
	// clear interrupt flag
	PIT.CH[CAN_TX_ISR_CHANNEL].TFLG.B.TIF = 1;
	return;
}
#endif



void main() {

	float angle = 0.0f;

	/* Processor initialization */
	initEECS461();

	/* Configure QD module */
	initQD();
	
	/* Configure PWM module for motor */
	initPCRs();
	initPWM(MOTOR_SUBMODULE,MOTOR_FREQUENCY, 0.50f);
	initPWM(FILTER_SUBMODULE,FILTER_FREQUENCY, 0.50f);
	
	/* Configure FlexCan module */
	initFlexcan();	
	/* Set the CAN receive ISR */
	can_set_rxisr(&rx_ISR);	
	
	#ifdef VWALLA
	if(can_rxbuff_init(vwA_rx_buffnum,vwA_rx_ID, 1 ) != 0 ) 
		exit(-2); /* failed to initialize buffer */
	#endif

	#ifdef VWALLB
	if( can_rxbuff_init(vwB_rx_buffnum,vwB_rx_ID, 1 ) != 0 ) 
		exit(-2); /* failed to initialize buffer */
	#endif
	
	#ifdef VCHAIN
	if(can_rxbuff_init(chainA_rx_buff_num,chainA_rx_ID, 1 ) != 0 ) 
		exit(-2); /* failed to initialize buffer */
	if(can_rxbuff_init(chainB_rx_buff_num,chainB_rx_ID, 1 ) != 0 ) 
		exit(-2); /* failed to initialize buffer */
	#endif

	/* Initialize the shared global variables */
	vw_torque = 0 ;	/* wall torque (FLOAT32, N-mm) */
	posA = 0 ;		/* chain position A (FLOAT32, N-mm) */
	velA = 0 ;		/* chain velocity A (FLOAT32, N-mm) */
	posB = 0 ;		/* chain position B (FLOAT32, N-mm) */
	velB = 0 ;		/* chain velocity B (FLOAT32, N-mm) */
	
	
		
	#ifdef VWALLA
		initPIT(CAN_TX_ISR_CHANNEL, 250/*Hz*/, &virt_wall_A, 0xB);
	#endif

	#ifdef VWALLB
		enable_interrupts(); // VWALLB interrupted by CAN Rx only
	#endif

	#ifdef VCHAIN
		initPIT(CAN_TX_ISR_CHANNEL, 250/*Hz*/, &virt_chain, 0xB);
	#endif
	INTC.CPR.R = 0x00;
	enable_interrupts();
	
	
	// idle loop
	while (1) 
	{};
}