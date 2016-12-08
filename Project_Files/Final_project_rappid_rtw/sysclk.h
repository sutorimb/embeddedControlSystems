/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sysclk.h
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

#ifndef RTW_HEADER_sysclk_h_
#define RTW_HEADER_sysclk_h_

/*                                    Parameters for 40Mhz XTAL 120Mhz Clk   */
#define IDF_0                          4 - 1                     /* Input Division Factor: 4   */
#define ODF_0                          1                         /* Output Division Factor: 4   */
#define NDIV_0                         48                        /* Loop Division Factor: 48    */

/* XTAL_40MHz / 4 / 4 * 48 = 120MHz  */
#define IDF_1                          4 - 1                     /* Input Division Factor: 4   */
#define ODF_1                          1                         /* Output Division Factor: 4   */
#define NDIV_1                         48                        /* Loop Division Factor: 48    */

/* XTAL_40MHz / 4 / 4 * 48 = 120MHz  */
#define MC_DIV                         11                        /* Motor Control Clock Divider Value: (11 + 1), Frequency 10000000 Hz */
#define SW_DIV                         5                         /* Sinewave Generator Clock Divider Value: (5 + 1), Frequency 20000000 Hz */
#define MC_CLOCK                       10000000                  /* Motor Control Clock */
#define SWG_CLOCK                      20000000                  /* Sinewave Generator Clock */
#endif                                 /* RTW_HEADER_sysclk_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
