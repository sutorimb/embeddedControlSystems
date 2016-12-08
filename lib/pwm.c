/*
   pwm.c
   University of Michigan
   EECS 461, Embedded Control Systems
   Pulse-Width Modulation module
   Read Chapter 25 in MPC5643 User's Manual
 */

#include "pwm.h"

/* PWM Parameters */
#define MOTOR_PCR 59
#define MOTOR_PSMI 24
#define MOTOR_PADSEL 1

#define FILTER_PCR 38
#define FILTER_PSMI 25
#define FILTER_PADSEL 0

#define DC_UPPER_LIMIT 0.76
#define DC_LOWER_LIMIT 0.24

/******************************************************************************
 * Function:    setPWM0
 * Description: Sets the output PWM
 ******************************************************************************/
void setPWM(int submodule, int frequency, float dutyCycle)
{
  vuint16_t cthres;
  vuint16_t cmax;

 

  cmax = (10000000/frequency)-1;
  cthres = dutyCycle*(cmax+1)-1;

  /* PWM Frequency */
  mcPWM_A.SUB[submodule].INIT.R = 0;        // Init count
  mcPWM_A.SUB[submodule].VAL[0].R = 0;    // Phase count - Not Used
  mcPWM_A.SUB[submodule].VAL[1].R = cmax;   // Final count
   
  /* PWM A */
  mcPWM_A.SUB[submodule].VAL[2].R = 0;      // Rising count
  mcPWM_A.SUB[submodule].VAL[3].R = cthres; // Falling count
  /* PWM B */
  mcPWM_A.SUB[submodule].VAL[4].R = 0;      // Rising count
  mcPWM_A.SUB[submodule].VAL[5].R = cthres; // Falling count

  /* Load Okay */
  mcPWM_A.MCTRL.B.LDOK = 1 << submodule;
}

/******************************************************************************
 * Function:    initPWM
 * Description: Initializes PWM
 ******************************************************************************/
void initPWM(int submodule, int frequency, float dutyCycle)
{
  /* Control 1 Register */
  // PWM Reload is set to Full Cycle  (counter = VAL1)
  mcPWM_A.SUBMOD[submodule].CTRL1.B.FULL = 1;
  // Buffered registers are loaded at the next PWM reload if LDOK is set
  mcPWM_A.SUBMOD[submodule].CTRL1.B.LDMOD = 0;
  // Prescaler - Use fclk
  mcPWM_A.SUBMOD[submodule].CTRL1.B.PRSC = 0;

  /* Control 2 Register */
  mcPWM_A.SUBMOD[submodule].CTRL2.B.INDEP = 1;
  mcPWM_A.SUBMOD[submodule].CTRL2.B.CLK_SEL = 0; // Use IPBus clock
  
  // Enable PWM in debug mode
  mcPWM_A.SUBMOD[submodule].CTRL2.B.DBGEN = 1;
  
  // PWMA Initial Value
  mcPWM_A.SUBMOD[submodule].CTRL2.B.PWM23_INIT = 0;
  
  // PWMB Initial Value
  mcPWM_A.SUBMOD[submodule].CTRL2.B.PWM45_INIT = 0;
  
  // PWMX Initial Value
  mcPWM_A.SUBMOD[submodule].CTRL2.B.PWMX_INIT = 0;

  // Disable Faults - Note Jay
  mcPWM_A.SUBMOD[submodule].DISMAP.R = 0xF000;
  // Deadtime count in IPBus clock cycles for PWMA
  mcPWM_A.SUBMOD[submodule].DTCNT0.R = 0x0000;
  // Deadtime count in IPBus clock cycles for PWMB
  mcPWM_A.SUBMOD[submodule].DTCNT1.R = 0x0000;
  

  // Set the PWM 
  setPWM(submodule,frequency,dutyCycle);
    
  mcPWM_A.OUTEN.B.PWMA_EN = 0b00; // Disable PWMA
  mcPWM_A.OUTEN.B.PWMB_EN = 0b11; // Enable PWMB


  // PRSC bits of CTRL1 and the INIT, FRACx, and
  // VALx registers take effect at the next PWM reload if LDMOD is clear or
  // immediately if LDMOD is set
  mcPWM_A.MCTRL.B.RUN = 0b11;     // Enable PWM generator
	
  }

void initPCRs() {
	/*Setup for PCR corresponding to Motor */
  SIU.PCR[MOTOR_PCR].R = 0b10000000000;
  SIU.PSMI[MOTOR_PSMI].B.PADSEL = MOTOR_PADSEL;
  
  /*Setup for PCR corresponding to SC Filter */
  SIU.PCR[FILTER_PCR].R = 0b100000000000;
  SIU.PSMI[FILTER_PSMI].B.PADSEL = FILTER_PADSEL;
}

/******************************************************************************
 * Function:    outputTorque
 * Description: Outputs the torque to the haptic wheel in N-mm
 ******************************************************************************/
void outputTorque(float torque) {
    float duty_cycle=torque*0.001/3.1625+0.5;
    if (duty_cycle>0.76) {
        duty_cycle=0.76;
    }
    else if (duty_cycle<0.24){
        duty_cycle=0.24;
    }
    
    setPWM(0,20000,duty_cycle);

  
  //Enforce Duty Cycle Limits
  
}
