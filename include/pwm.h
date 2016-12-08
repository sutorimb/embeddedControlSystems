/*
   pwm.h
   University of Michigan
   EECS 461, Embedded Control Systems
   Pulse-Width Modulation module
   Read Chapter 25 in MPC5643 User's Manual
 */

#include "MPC5643L.h"
#include "eecs461.h"

#define MOTOR_FREQUENCY 20000
#define MOTOR_SUBMODULE 0
#define FILTER_FREQUENCY 1000000
#define FILTER_SUBMODULE 1
#define FILTER_DUTY_CYCLE 0.5f

/* Functions for PWM */
void setPWM(int submodule, int frequency, float dutyCycle);
void initPWM(int submodule, int frequency, float dutyCycle);
void initPCRs();
void outputTorque(float torque);
