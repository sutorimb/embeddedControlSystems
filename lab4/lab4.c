/*
  EECS461
  Lab 4
  Original version by Scott Kenyon
  Updated July 6, 2014 by GPCz
*/
#include "MPC5643L.h"

#include "qd.h"
#include "pwm.h"
#include "gpio.h"
#include "adc.h"
#include "worlds.h"
#include "eecs461.h"

#define ADC0_NUMCHANNELS 1
static char channelArray[ADC0_NUMCHANNELS] = {0};

int main(void) 
{
  int analogInput;
  int pad_num;
  float angle;
  float scaled;
  float torque;
  int i;
  initEECS461();

  initQD();
  initADC0_oneshot(ADC0_NUMCHANNELS, channelArray);
  initPCRs();
for(i=0;i<2;i++){
	pad_num=43+i;
	SIU.PCR[pad_num].B.APC=0;
	SIU.PCR[pad_num].B.PA=0;
	SIU.PCR[pad_num].B.OBE=1;
	}
  //Fill in Lab 4 code here
  
  //Initialize PWMs
  initPWM(0,20000,0.5);
  initPWM(1,1000000,0.5);
  while(1){
  //scaled=((float)readADC0_oneshot(0)-9.0)*(0.76-0.24)/(float)(4095.0-9.0)+0.24;
  //setPWM(0,20000,scaled);
  SIU.GPDO[44].B.PDO=0;
  angle=updateAngle();
  torque=virtualWall(angle);
  outputTorque(torque);
  if (angle<0){
  SIU.GPDO[43].B.PDO=0;

  }
  else {
  SIU.GPDO[43].B.PDO=1;
  }
 SIU.GPDO[44].B.PDO=1;
  }
  
  
  
}
