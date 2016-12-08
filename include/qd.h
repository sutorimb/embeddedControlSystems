/*
   qd.h
   University of Michigan
   EECS 461, Embedded Control Systems
   Enhanced Motor Control Timer (eTimer) module
   Read Chapter 20 in MPC5643 User's Manual
 */
#include "MPC5643L.h"
#include "eecs461.h"

/* Functions for Quadrature Decoding */
void initQD();
int32_t updateCounter();
float updateAngle();
