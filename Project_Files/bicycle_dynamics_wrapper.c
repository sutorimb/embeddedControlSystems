

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void bicycle_dynamics_Outputs_wrapper(const real32_T *Fd,
			const real32_T *delta,
			const real32_T *u,
			const real32_T *psi,
			real32_T *x_dot,
			real32_T *y_dot,
			real32_T *psi_dot,
			real32_T *u_dot)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
static double m=2000;
static double l_2=0.8;
static double l_1=1.6;
static double b=100;

u_dot[0]=1/m*(Fd[0]-b*u[0]);
x_dot[0] = (-l_2/l_1*sin(delta[0])*sin(psi[0])+cos(delta[0])*cos(psi[0]))*u[0];
y_dot[0] = ( l_2/l_1*sin(delta[0])*cos(psi[0])+cos(delta[0])*sin(psi[0]))*u[0];
psi_dot[0]=(1/l_1*sin(delta[0]))*u[0];
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
