/*
  EECS461
  Lab 6
  Original version by Scott Kenyon
  Updated July 6, 2014 by GPCz
*/

#include<eecs461.h>
#include<serial.h>
#include "qd.h"
#include "pwm.h"
#include "pit.h"
#include "IntcInterrupts.h"
#include "gpio.h"
#include "worlds.h"

#define ENTER_CRITICAL() asm (" wrteei 0"); /* disable all interrupts */
#define LEAVE_CRITICAL() asm (" wrteei 1"); /* enable all interrupts */
int pad_num_DIP122=5;
char byte_in;
extern float k=17.78;
extern float J=0.4504;
void wallDamper(void)
{
static float x_old=0;
float x_new;
float vel;
float torque;
x_new=updateAngle();

vel=((float)x_new-x_old)/0.001;
if (SIU.GPDI[pad_num_DIP122].B.PDI==0){
	vel=0;
	}
torque=virtualWallDamper((float)x_new, vel);
outputTorque(torque);
x_old=(float)x_new;

PIT.CH[WORLDISR_PIT_CHANNEL].TFLG.B.TIF=1;
}

void springDamper(void)
{
static float x_old=0;
float x_new;
float vel;
float torque;
x_new=updateAngle();
vel=((float)x_new-x_old)/0.001;
if (SIU.GPDI[pad_num_DIP122].B.PDI==0){
	vel=0;
	}
torque=virtualSpringDamper((float)x_new, vel);
outputTorque(torque);
x_old=(float)x_new;

PIT.CH[WORLDISR_PIT_CHANNEL].TFLG.B.TIF=1;
}

void springMass(void)
{
static float x_old=0;
float x_new;
float vel;
float torque;
x_new=updateAngle();
vel=((float)x_new-x_old)/0.001;
if (SIU.GPDI[pad_num_DIP122].B.PDI==0){
	vel=0;
	}
torque=virtualSpringMass((float)x_new);
outputTorque(torque);
x_old=(float)x_new;

PIT.CH[WORLDISR_PIT_CHANNEL].TFLG.B.TIF=1;
}

void springMassDamper(void)
{
static float x_old=0;
float x_new;
float vel;
float torque;
x_new=updateAngle();
vel=((float)x_new-x_old)/0.001;
if (SIU.GPDI[pad_num_DIP122].B.PDI==0){
	vel=0;
	}
torque=virtualSpringMassDamper((float)x_new, vel);
outputTorque(torque);
x_old=(float)x_new;

PIT.CH[WORLDISR_PIT_CHANNEL].TFLG.B.TIF=1;
}

void knobIndents(void)
{
static float x_old=0;
float x_new;
float vel;
float torque;
x_new=updateAngle();
vel=((float)x_new-x_old)/0.001;
torque=virtualKnob((float)x_new, vel);
outputTorque(torque);
x_old=(float)x_new;

PIT.CH[WORLDISR_PIT_CHANNEL].TFLG.B.TIF=1;
}

void main()
{
	

  
  
  initEECS461();
  initQD();
  initUART(9600);
  serial_puts("\n\n\n\n\n\n\n\n\rSerial Output Enabled.");
  initPCRs();
  initGPDI(5);
  initPWM(MOTOR_SUBMODULE,MOTOR_FREQUENCY, 0.50f);
  initPWM(FILTER_SUBMODULE,FILTER_FREQUENCY, 0.50f);
  SIUL.PCR[43].B.PA = 0;
  SIUL.PCR[43].B.OBE = 1;
  SIU.PCR[pad_num_DIP122].B.APC=0;
  SIU.PCR[pad_num_DIP122].B.PA=0;
  SIU.PCR[pad_num_DIP122].B.IBE=1;
  
  
  //Fill in the interrupt routine for the particular part of the lab
  initPIT(WORLDISR_PIT_CHANNEL, WORLDISR_FREQUENCY, &knobIndents, 0xC);
  INTC.CPR.R = 0x0A;
  enable_interrupts();

  
  
  while(1){
  /*if (serial_readyToReceive(1)){
		ENTER_CRITICAL();
		byte_in=serial_getchar(1);
		switch (byte_in){
		case '1':
		k=k/1.1;
		case '2':
		k=k*1.1;
		case '3':
		J=J/1.1;
		case '4':
		J=J*1.1;
		}
		LEAVE_CRITICAL();
	}*/
  
	
  }
}
