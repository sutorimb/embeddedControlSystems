/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_project_private.h
 *
 * Code generated for Simulink model 'Final_project'.
 *
 * Model version                  : 1.107
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Fri Dec 02 14:00:56 2016
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Final_project_private_h_
#define RTW_HEADER_Final_project_private_h_
#include "rtwtypes.h"
#include "MPC5643L.h"
#include "flexcan_564xl_library.h"
#include "gpio_564xl_library.h"
#include "adc_564xl_library.h"
#include "adc0_config.h"
#include "path_data.h"
#include "path_data.h"
#include "FlexPWM_564xL_library.h"
#include "flexpwm_init.h"
#include "eTimer_564xL_library.h"

extern void calc_lead_vehicle_Outputs_wrapper(const boolean_T *ACC_Enable,
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
  real32_T *lead_us);
extern void bicycle_dynamics_Outputs_wrapper(const real32_T *Fd,
  const real32_T *delta,
  const real32_T *u,
  const real32_T *psi,
  real32_T *x_dot,
  real32_T *y_dot,
  real32_T *psi_dot,
  real32_T *u_dot);
extern void SerialInit_Outputs_wrapper();
extern void Final_project_step0(void);
extern void Final_project_step1(void);

#endif                                 /* RTW_HEADER_Final_project_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
