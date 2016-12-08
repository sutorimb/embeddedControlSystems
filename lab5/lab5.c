/*
  EECS461
  Lab 5
  Updated: March 17th, 2014 by Scott Kenyon
           June 30th, 2014 by GPCz
*/

#include "MPC5643L.h"

#include "pwm.h"
#include "pit.h"
#include "adc.h"
#include "IntcInterrupts.h"
#include "GPIO.h"
#include "math.h"


#define ADC0_NUMCHANNELS 1
static char channelArray[ADC0_NUMCHANNELS] = {0};
float sin_arr[10]={0,0.5878,0.9511,0.9511,0.5878,0.0000,-0.5878,-0.9511,-0.9511,-0.5878};
int pad_num_LED=43;
int pad_num_DIP122=5;
int pad_num_DIP123=6;
float Pi = 3.14159f;
int k=0;


void IsrA(void)
{
	float dutyCycle;
	int freq;
	vuint16_t sin_val;
	
	/* Turn on LED */
	SIU.GPDO[pad_num_LED].B.PDO=1;
	
	/* Read sine value */
	sin_val=readADC0_oneshot(channelArray[0]);

	/* Set PWM frequency only if dipSwitch 122 changes */
	if (SIU.GPDI[pad_num_DIP122].B.PDI==1){
		freq=60000;
	}
		
	else {
		freq=20000;
	}

	if(SIU.GPDI[pad_num_DIP123].B.PDI==1){
	dutyCycle=0.000195*(float)sin_val+.1;
	}

	else{
	dutyCycle=0.000049*(float)sin_val+.4;
	}

	/* Calculate PWM duty cycle */

	/* Set PWM duty cycle */
	setPWM(MOTOR_SUBMODULE,freq,dutyCycle);

	/* Turn off LED */
	SIU.GPDO[pad_num_LED].B.PDO=0;
	
	/* Clear interupt flag */
	PIT.CH[ADCISR_PIT_CHANNEL].TFLG.B.TIF=1;	 
}

void IsrB(void)
{ 
	double dutyCycle;

	/* Turn on LED */
	SIU.GPDO[pad_num_LED].B.PDO=1;

	dutyCycle=0.5+0.4*sinf(2*Pi*k/10);
	k=k+1;
	if (k>=10){
		k=0;
	}
	/* Calculate and Set PWM duty cycle */
	setPWM(MOTOR_SUBMODULE,60000,dutyCycle);
	
	/* Turn off LED */
	SIU.GPDO[pad_num_LED].B.PDO=0;
	
	/* Clear interupt flag */
	PIT.CH[ADCISR_PIT_CHANNEL].TFLG.B.TIF=1;
}

void IsrC(void)
{
	double dutyCycle;

	/* Turn on LED */
	SIU.GPDO[pad_num_LED].B.PDO=1;
	
	
	/* Calculate and Set PWM duty cycle */
	dutyCycle=0.5+0.4*sin_arr[k];
	k=k+1;
	if (k>=10){
		k=0;
	}
	setPWM(MOTOR_SUBMODULE,60000,dutyCycle);
	
	/* Turn off LED */
	SIU.GPDO[pad_num_LED].B.PDO=0;
	
	/* Clear interupt flag */
	PIT.CH[ADCISR_PIT_CHANNEL].TFLG.B.TIF=1;
}

void main()
{
  initEECS461();
  initADC0_oneshot(ADC0_NUMCHANNELS, channelArray);
  initPCRs();
  initPWM(MOTOR_SUBMODULE,MOTOR_FREQUENCY, 0.50f);
  initPWM(FILTER_SUBMODULE,FILTER_FREQUENCY, 0.50f);

  
	SIU.PCR[pad_num_LED].B.APC=0;
	SIU.PCR[pad_num_LED].B.PA=0;
	SIU.PCR[pad_num_LED].B.OBE=1;

	SIU.PCR[pad_num_DIP122].B.APC=0;
	SIU.PCR[pad_num_DIP122].B.PA=0;
	SIU.PCR[pad_num_DIP122].B.IBE=1;

	SIU.PCR[pad_num_DIP123].B.APC=0;
	SIU.PCR[pad_num_DIP123].B.PA=0;
	SIU.PCR[pad_num_DIP123].B.IBE=1;
  
	
	INTC_InitINTCInterrupts();
    initPIT(ADCISR_PIT_CHANNEL, 40000, &IsrC, 0xC);
    INTC.CPR.R = 0x0A;
	enable_interrupts();
	
	
  while(1)
  {
	/*Loop forever */
  };
}
