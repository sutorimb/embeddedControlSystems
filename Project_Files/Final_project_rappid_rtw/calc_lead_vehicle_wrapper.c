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
#define u_width                        1
#define y_width                        1

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
void calc_lead_vehicle_Outputs_wrapper(const boolean_T *ACC_Enable,
  const real32_T *s1,
  const real32_T *s2,
  const real32_T *s3,
  const real32_T *s4,
  const real32_T *s5,
  const real32_T *s6,
  const real32_T *s,
  const real32_T *us1,
  const real32_T *us2,
  const real32_T *us3,
  const real32_T *us4,
  const real32_T *us5,
  const real32_T *us6,
  const real32_T *us,
  const real_T *H,
  boolean_T *en_man,
  boolean_T *en_vel,
  boolean_T *en_pos,
  real32_T *lead_s,
  real32_T *lead_us)
{
  /* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
  /* This sample sets the output equal to the input
     y0[0] = u0[0];
     For complex signals use: y0[0].re = u0[0].re;
     y0[0].im = u0[0].im;
     y1[0].re = u1[0].re;
     y1[0].im = u1[0].im;
   */
  if (s1[0]>s[0] && (s2[0]>s1[0] || s2[0]<s[0]) && (s3[0]>s1[0] || s3[0]<s[0]) &&
      (s4[0]>s1[0] || s4[0]<s[0]) && (s5[0]>s1[0] || s5[0]<s[0]) && (s6[0]>s1[0]
       || s6[0]<s[0])) {
    lead_s[0]= s1[0];
    lead_us[0]= us1[0];
    if (lead_us[0]<=us[0] && lead_s[0]-s[0]<=H[0]) {
      en_pos[0]= 1;
      en_vel[0]= 0;
    } else {
      en_pos[0]= 0;
      en_vel[0]= 1;
    }
  } else if (s2[0]>s[0] && (s1[0]>s2[0] || s1[0]<s[0]) && (s3[0]>s2[0] || s3[0]<
              s[0]) && (s4[0]>s2[0] || s4[0]<s[0]) && (s5[0]>s2[0] || s5[0]<s[0])
             && (s6[0]>s2[0] || s6[0]<s[0])) {
    lead_s[0]= s2[0];
    lead_us[0]= us2[0];
    if (lead_us[0]<=us[0] && lead_s[0]-s[0]<=H[0]) {
      en_pos[0]= 1;
      en_vel[0]= 0;
    } else {
      en_pos[0]= 0;
      en_vel[0]= 1;
    }
  } else if (s3[0]>s[0] && (s1[0]>s3[0] || s1[0]<s[0]) && (s2[0]>s3[0] || s2[0]<
              s[0]) && (s4[0]>s3[0] || s4[0]<s[0]) && (s5[0]>s3[0] || s5[0]<s[0])
             && (s6[0]>s3[0] || s6[0]<s[0])) {
    lead_s[0]= s3[0];
    lead_us[0]= us3[0];
    if (lead_us[0]<=us[0] && lead_s[0]-s[0]<=H[0]) {
      en_pos[0]= 1;
      en_vel[0]= 0;
    } else {
      en_pos[0]= 0;
      en_vel[0]= 1;
    }
  } else if (s4[0]>s[0] && (s1[0]>s4[0] || s1[0]<s[0]) && (s2[0]>s4[0] || s2[0]<
              s[0]) && (s3[0]>s4[0] || s3[0]<s[0]) && (s5[0]>s4[0] || s5[0]<s[0])
             && (s6[0]>s4[0] || s6[0]<s[0])) {
    lead_s[0]= s4[0];
    lead_us[0]= us4[0];
    if (lead_us[0]<=us[0] && lead_s[0]-s[0]<=H[0]) {
      en_pos[0]= 1;
      en_vel[0]= 0;
    } else {
      en_pos[0]= 0;
      en_vel[0]= 1;
    }
  } else if (s5[0]>s[0] && (s1[0]>s5[0] || s1[0]<s[0]) && (s2[0]>s5[0] || s2[0]<
              s[0]) && (s3[0]>s5[0] || s3[0]<s[0]) && (s4[0]>s5[0] || s4[0]<s[0])
             && (s6[0]>s5[0] || s6[0]<s[0])) {
    lead_s[0]= s5[0];
    lead_us[0]= us5[0];
    if (lead_us[0]<=us[0] && lead_s[0]-s[0]<=H[0]) {
      en_pos[0]= 1;
      en_vel[0]= 0;
    } else {
      en_pos[0]= 0;
      en_vel[0]= 1;
    }
  } else if (s6[0]>s[0] && (s1[0]>s6[0] || s1[0]<s[0]) && (s2[0]>s6[0] || s2[0]<
              s[0]) && (s3[0]>s6[0] || s3[0]<s[0]) && (s4[0]>s6[0] || s4[0]<s[0])
             && (s5[0]>s6[0] || s5[0]<s[0])) {
    lead_s[0]= s6[0];
    lead_us[0]= us6[0];
    if (lead_us[0]<=us[0] && lead_s[0]-s[0]<=H[0]) {
      en_pos[0]= 1;
      en_vel[0]= 0;
    } else {
      en_pos[0]= 0;
      en_vel[0]= 1;
    }
  } else {
    lead_s[0]= s[0];
    lead_us[0]= us[0];
    en_pos[0]= 0;
    en_vel[0]= 1;
  }

  if (ACC_Enable[0]==0) {
    en_pos[0]= 0;
    en_vel[0]= 0;
    en_man[0]= 1;
  } else {
    en_man[0]= 0;
  }

  /* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
