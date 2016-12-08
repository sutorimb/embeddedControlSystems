/*
 qd.c
 University of Michigan
 EECS 461, Embedded Control Systems
 Enhanced Motor Control Timer (eTimer) module
 Read Chapter 20 in MPC5643 User's Manual
 */
#include "qd.h"

/* Quadrature Decoding Parameters */
#define INITIAL_POSITION 0x8000
#define ETIMER0_CHANNEL 0
#define ENCODER_COUNT 4000.0

/******************************************************************************
 * Function:    init_QD
 * Description: Initializes Quadrature Decoding
 ******************************************************************************/
void initQD()
{
    // Counter #0 PCR 0
    
    SIU.PCR[0].B.PA = 01; // ALT[1]
    SIU.PCR[0].B.IBE = 1;
    
    SIU.PSMI[35].B.PADSEL = 0;
    
    // Counter #1 PCR 1
    
    SIU.PCR[1].B.PA = 01; // ALT[1]
    SIU.PCR[1].B.IBE = 1;
    
    SIU.PSMI[36].B.PADSEL = 0;
    
    ETIMER_0.ENBL.R = 0; // Disable all Timers
    // Quadrature count mode, uses primary and secondary sources
    ETIMER_0.CHANNEL[ETIMER0_CHANNEL].CTRL1.B.CNTMODE = 100;
    ETIMER_0.CHANNEL[ETIMER0_CHANNEL].CTRL1.B.PRISRC = 00000; // Counter #0 input pin
    ETIMER_0.CHANNEL[ETIMER0_CHANNEL].CTRL1.B.SECSRC = 00001; // Counter #1 input pin
    
    ETIMER_0.ENBL.R = 0b111111; // Enable all Timers
    
    ETIMER_0.CHANNEL[0].CNTR.R = INITIAL_POSITION;
    
    return;
}

/******************************************************************************
 * Function:    updateCounter
 * Description: Returns an updated counter value that keeps track of wheel
 *              position
 ******************************************************************************/
int32_t updateCounter()
{   static int32_t total_count=0;
    static uint16_t curr_count=0;
    static uint16_t last_count=INITIAL_POSITION;
   curr_count=ETIMER_0.CHANNEL[0].CNTR.R;
    total_count=(total_count + (int16_t)(curr_count-last_count));
    last_count=curr_count;
    return total_count;
}


/******************************************************************************
 * Function:    updateAngle
 * Description: Returns the angle of the wheel
 ******************************************************************************/
float updateAngle()
{
    float angle=((float)updateCounter())*360/ENCODER_COUNT;
    return angle;
}