/*
   worlds.c
   University of Michigan
   EECS 461, Embedded Control Systems
   Virtual Worlds

   Revision History
     2011-12-01  Jay Patel
     2014-02-24  Scott Kenyon
 */

#include "worlds.h"
#include "gpio.h"
#include "typedefs.h"
extern float k;
extern float J;


//====================LAB 4================================
/***************************************************************************
 * Virtual Wall
 ***************************************************************************/
float virtualWall(float angle)
{
    if (angle<0){
        return 0;
    }
    else {
        return -500*angle;
    }
}

/***************************************************************************
 * Virtual Spring 
 ***************************************************************************/
float virtualSpring(float angle)
{
    return -10*angle;
}

//====================LAB 6================================
/***************************************************************************
 * Virtual Spring Damper
***************************************************************************/
float virtualSpringDamper(float angle, float velocity)
{
    return -10*angle-0.25*velocity;
}

/**************************************************.6479*************************
 * Virtual Wall Damper
***************************************************************************/
float virtualWallDamper(float angle, float velocity)
{
    if (angle<0){
        return 0;
    }
    else {
        return -500*angle-500*velocity;
    }
}

/***************************************************************************
 * Virtual Spring Mass
***************************************************************************/
float virtualSpringMass(float angle)
{   static float T=0.001;
    static float x1old=0;
    static float x2old=0;
    float x1new;
    float x2new;
    
    x1new = x1old + T*x2old;
    x2new = x2old-T*k/J*(-angle+x1old);
    x1old = x1new;
    x2old = x2new;
    return -k*(angle-x1new);
}

/***************************************************************************
 * Virtual Spring Mass Damper
***************************************************************************/
float virtualSpringMassDamper(float angle, float velocity) {
    static float x1old =0;
    static float x2old =0;
    static float T=0.001;
    float b=k*T;
    float x1new;
    float x2new; 
    
    x1new = x1old + T*x2old;
    x2new = x2old-T*k/J*(-angle+x1old)-T*b/J*x2old;
    x1old = x1new;
    x2old = x2new;
    return -k*(angle-x1new)-b*(velocity-x2new);
}

/***************************************************************************
 * Virtual Knob
***************************************************************************/ 
float virtualKnob(float angle, float velocity) {
if(angle>0){
	while(angle>30){
	angle=angle-30;
	}
}
else if (angle<0){
	while(angle<30){
	angle=angle+30;
	}
}
if (angle==30){
	return -500*angle-2*velocity;
}
else {
    return -2*velocity;
    }
}

