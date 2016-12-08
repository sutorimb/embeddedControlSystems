/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_project.c
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

#include "Final_project.h"
#include "Final_project_private.h"

/* Block signals (auto storage) */
B_Final_project_T Final_project_B;

/* Block states (auto storage) */
DW_Final_project_T Final_project_DW;

/* Real-time model */
RT_MODEL_Final_project_T Final_project_M_;
RT_MODEL_Final_project_T *const Final_project_M = &Final_project_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Final_project_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Final_project_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  Final_project_M->Timing.RateInteraction.TID0_1 =
    (Final_project_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Final_project_M->Timing.TaskCounters.TID[1])++;
  if ((Final_project_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.05s, 0.0s] */
    Final_project_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Final_project_step0(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_DataTypeConversion;
  real_T rtb_Product1;
  real32_T rtb_Gain_ie;
  real32_T rtb_Sum1_mn;
  real32_T rtb_Gain_l;
  real32_T rtb_Product;
  real32_T rtb_Sum1_a2;
  real32_T rtb_C_o_idx_1;
  real32_T rtb_C_j_idx_0;
  real32_T rtb_C_j_idx_1;
  real32_T rtb_C_p_idx_0;
  real32_T rtb_C_p_idx_1;
  real32_T rtb_C_pd_idx_0;
  real32_T rtb_C_pd_idx_1;
  real32_T rtb_C_d_idx_0;
  real32_T rtb_C_d_idx_1;
  real_T tmp;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (fcncallgen): '<Root>/Function-Call Top' incorporates:
   *  SubSystem: '<Root>/High Level Design'
   */
  if (Final_project_DW.HighLevelDesign_RESET_ELAPS_T) {
    Final_project_DW.HighLevelDesign_ELAPS_T = 0U;
  } else {
    Final_project_DW.HighLevelDesign_ELAPS_T =
      Final_project_M->Timing.clockTick0 -
      Final_project_DW.HighLevelDesign_PREV_T;
  }

  Final_project_DW.HighLevelDesign_PREV_T = Final_project_M->Timing.clockTick0;
  Final_project_DW.HighLevelDesign_RESET_ELAPS_T = false;

  /* S-Function (eTimer_564xL_cntr): '<S28>/eTimer CNTR Register Read' */
  Final_project_B.eTimerCNTRRegisterRead = mcTIMER0.CHANNEL[0].CNTR.R;

  /* Sum: '<S33>/Sum1' incorporates:
   *  DataTypeConversion: '<S33>/Data Type Conversion1'
   *  DataTypeConversion: '<S33>/Data Type Conversion2'
   *  Delay: '<S33>/Delay'
   *  Delay: '<S33>/Delay1'
   *  Gain: '<S33>/Gain'
   *  Sum: '<S33>/Sum'
   */
  rtb_Sum1_mn = (real32_T)(int16_T)(Final_project_B.eTimerCNTRRegisterRead -
    Final_project_DW.Delay_DSTATE_p) * -0.00157079636F +
    Final_project_DW.Delay1_DSTATE;

  /* S-Function (can_564xl_receive_data): '<S29>/CAN_Receive_data15' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 4)) {
      Final_project_B.CAN_Receive_data15_o1 = flexcan_564xl_get_id(0, 4);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 4);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data15_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data15_o2 = flexcan_564xl_get_idtype(0, 4);
      Final_project_B.CAN_Receive_data15_o4 = flexcan_564xl_get_ts(0, 4);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 4);
    }
  }

  /* S-Function (bytes2single): '<S29>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle), (void*)
         (&(Final_project_B.CAN_Receive_data15_o3[0])), sizeof
         (Final_project_B.BytestoSingle) );

  /* S-Function (bytes2single): '<S29>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle1), (void*)
         (&(Final_project_B.CAN_Receive_data15_o3[4])), sizeof
         (Final_project_B.BytestoSingle1) );

  /* S-Function (can_564xl_receive_data): '<S29>/CAN_Receive_data16' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 5)) {
      Final_project_B.CAN_Receive_data16_o1 = flexcan_564xl_get_id(0, 5);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 5);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data16_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data16_o2 = flexcan_564xl_get_idtype(0, 5);
      Final_project_B.CAN_Receive_data16_o4 = flexcan_564xl_get_ts(0, 5);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 5);
    }
  }

  /* S-Function (bytes2single): '<S29>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle2), (void*)
         (&(Final_project_B.CAN_Receive_data16_o3[0])), sizeof
         (Final_project_B.BytestoSingle2) );

  /* S-Function (bytes2single): '<S29>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle3), (void*)
         (&(Final_project_B.CAN_Receive_data16_o3[4])), sizeof
         (Final_project_B.BytestoSingle3) );

  /* S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 6)) {
      Final_project_B.CAN_Receive_data_o1 = flexcan_564xl_get_id(0, 6);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 6);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data_o2 = flexcan_564xl_get_idtype(0, 6);
      Final_project_B.CAN_Receive_data_o4 = flexcan_564xl_get_ts(0, 6);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 6);
    }
  }

  /* S-Function (bytes2single): '<S30>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle_m), (void*)
         (&(Final_project_B.CAN_Receive_data_o3[0])), sizeof
         (Final_project_B.BytestoSingle_m) );

  /* S-Function (bytes2single): '<S30>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle1_k), (void*)
         (&(Final_project_B.CAN_Receive_data_o3[4])), sizeof
         (Final_project_B.BytestoSingle1_k) );

  /* S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data5' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 11)) {
      Final_project_B.CAN_Receive_data5_o1 = flexcan_564xl_get_id(0, 11);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 11);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data5_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data5_o2 = flexcan_564xl_get_idtype(0, 11);
      Final_project_B.CAN_Receive_data5_o4 = flexcan_564xl_get_ts(0, 11);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 11);
    }
  }

  /* S-Function (bytes2single): '<S30>/Bytes to Single10' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle10), (void*)
         (&(Final_project_B.CAN_Receive_data5_o3[0])), sizeof
         (Final_project_B.BytestoSingle10) );

  /* S-Function (bytes2single): '<S30>/Bytes to Single11' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle11), (void*)
         (&(Final_project_B.CAN_Receive_data5_o3[4])), sizeof
         (Final_project_B.BytestoSingle11) );

  /* S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data6' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 12)) {
      Final_project_B.CAN_Receive_data6_o1 = flexcan_564xl_get_id(0, 12);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 12);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data6_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data6_o2 = flexcan_564xl_get_idtype(0, 12);
      Final_project_B.CAN_Receive_data6_o4 = flexcan_564xl_get_ts(0, 12);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 12);
    }
  }

  /* S-Function (bytes2single): '<S30>/Bytes to Single12' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle12), (void*)
         (&(Final_project_B.CAN_Receive_data6_o3[0])), sizeof
         (Final_project_B.BytestoSingle12) );

  /* S-Function (bytes2single): '<S30>/Bytes to Single13' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle13), (void*)
         (&(Final_project_B.CAN_Receive_data6_o3[4])), sizeof
         (Final_project_B.BytestoSingle13) );

  /* S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data7' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 13)) {
      Final_project_B.CAN_Receive_data7_o1 = flexcan_564xl_get_id(0, 13);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 13);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data7_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data7_o2 = flexcan_564xl_get_idtype(0, 13);
      Final_project_B.CAN_Receive_data7_o4 = flexcan_564xl_get_ts(0, 13);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 13);
    }
  }

  /* S-Function (bytes2single): '<S30>/Bytes to Single14' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle14), (void*)
         (&(Final_project_B.CAN_Receive_data7_o3[0])), sizeof
         (Final_project_B.BytestoSingle14) );

  /* S-Function (bytes2single): '<S30>/Bytes to Single15' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle15), (void*)
         (&(Final_project_B.CAN_Receive_data7_o3[4])), sizeof
         (Final_project_B.BytestoSingle15) );

  /* S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data8' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 14)) {
      Final_project_B.CAN_Receive_data8_o1 = flexcan_564xl_get_id(0, 14);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 14);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data8_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data8_o2 = flexcan_564xl_get_idtype(0, 14);
      Final_project_B.CAN_Receive_data8_o4 = flexcan_564xl_get_ts(0, 14);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 14);
    }
  }

  /* S-Function (bytes2single): '<S30>/Bytes to Single16' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle16), (void*)
         (&(Final_project_B.CAN_Receive_data8_o3[0])), sizeof
         (Final_project_B.BytestoSingle16) );

  /* S-Function (bytes2single): '<S30>/Bytes to Single17' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle17), (void*)
         (&(Final_project_B.CAN_Receive_data8_o3[4])), sizeof
         (Final_project_B.BytestoSingle17) );

  /* S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data9' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 15)) {
      Final_project_B.CAN_Receive_data9_o1 = flexcan_564xl_get_id(0, 15);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 15);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data9_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data9_o2 = flexcan_564xl_get_idtype(0, 15);
      Final_project_B.CAN_Receive_data9_o4 = flexcan_564xl_get_ts(0, 15);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 15);
    }
  }

  /* S-Function (bytes2single): '<S30>/Bytes to Single18' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle18), (void*)
         (&(Final_project_B.CAN_Receive_data9_o3[0])), sizeof
         (Final_project_B.BytestoSingle18) );

  /* S-Function (bytes2single): '<S30>/Bytes to Single19' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle19), (void*)
         (&(Final_project_B.CAN_Receive_data9_o3[4])), sizeof
         (Final_project_B.BytestoSingle19) );

  /* S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 7)) {
      Final_project_B.CAN_Receive_data1_o1 = flexcan_564xl_get_id(0, 7);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 7);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data1_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data1_o2 = flexcan_564xl_get_idtype(0, 7);
      Final_project_B.CAN_Receive_data1_o4 = flexcan_564xl_get_ts(0, 7);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 7);
    }
  }

  /* S-Function (bytes2single): '<S30>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle2_k), (void*)
         (&(Final_project_B.CAN_Receive_data1_o3[0])), sizeof
         (Final_project_B.BytestoSingle2_k) );

  /* S-Function (bytes2single): '<S30>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle3_l), (void*)
         (&(Final_project_B.CAN_Receive_data1_o3[4])), sizeof
         (Final_project_B.BytestoSingle3_l) );

  /* S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data2' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 8)) {
      Final_project_B.CAN_Receive_data2_o1 = flexcan_564xl_get_id(0, 8);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 8);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data2_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data2_o2 = flexcan_564xl_get_idtype(0, 8);
      Final_project_B.CAN_Receive_data2_o4 = flexcan_564xl_get_ts(0, 8);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 8);
    }
  }

  /* S-Function (bytes2single): '<S30>/Bytes to Single4' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle4), (void*)
         (&(Final_project_B.CAN_Receive_data2_o3[0])), sizeof
         (Final_project_B.BytestoSingle4) );

  /* S-Function (bytes2single): '<S30>/Bytes to Single5' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle5), (void*)
         (&(Final_project_B.CAN_Receive_data2_o3[4])), sizeof
         (Final_project_B.BytestoSingle5) );

  /* S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data3' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 9)) {
      Final_project_B.CAN_Receive_data3_o1 = flexcan_564xl_get_id(0, 9);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 9);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data3_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data3_o2 = flexcan_564xl_get_idtype(0, 9);
      Final_project_B.CAN_Receive_data3_o4 = flexcan_564xl_get_ts(0, 9);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 9);
    }
  }

  /* S-Function (bytes2single): '<S30>/Bytes to Single6' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle6), (void*)
         (&(Final_project_B.CAN_Receive_data3_o3[0])), sizeof
         (Final_project_B.BytestoSingle6) );

  /* S-Function (bytes2single): '<S30>/Bytes to Single7' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle7), (void*)
         (&(Final_project_B.CAN_Receive_data3_o3[4])), sizeof
         (Final_project_B.BytestoSingle7) );

  /* S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data4' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 10)) {
      Final_project_B.CAN_Receive_data4_o1 = flexcan_564xl_get_id(0, 10);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 10);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data4_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data4_o2 = flexcan_564xl_get_idtype(0, 10);
      Final_project_B.CAN_Receive_data4_o4 = flexcan_564xl_get_ts(0, 10);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 10);
    }
  }

  /* S-Function (bytes2single): '<S30>/Bytes to Single8' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle8), (void*)
         (&(Final_project_B.CAN_Receive_data4_o3[0])), sizeof
         (Final_project_B.BytestoSingle8) );

  /* S-Function (bytes2single): '<S30>/Bytes to Single9' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle9), (void*)
         (&(Final_project_B.CAN_Receive_data4_o3[4])), sizeof
         (Final_project_B.BytestoSingle9) );

  /* S-Function (can_564xl_receive_data): '<S31>/CAN_Receive_data18' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 2)) {
      Final_project_B.CAN_Receive_data18_o1 = flexcan_564xl_get_id(0, 2);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 2);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data18_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data18_o2 = flexcan_564xl_get_idtype(0, 2);
      Final_project_B.CAN_Receive_data18_o4 = flexcan_564xl_get_ts(0, 2);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 2);
    }
  }

  /* S-Function (bytes2single): '<S31>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle_h), (void*)
         (&(Final_project_B.CAN_Receive_data18_o3[0])), sizeof
         (Final_project_B.BytestoSingle_h) );

  /* S-Function (bytes2single): '<S31>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle1_j), (void*)
         (&(Final_project_B.CAN_Receive_data18_o3[4])), sizeof
         (Final_project_B.BytestoSingle1_j) );

  /* S-Function (can_564xl_receive_data): '<S31>/CAN_Receive_data19' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 3)) {
      Final_project_B.CAN_Receive_data19_o1 = flexcan_564xl_get_id(0, 3);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 3);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (&Final_project_B.CAN_Receive_data19_o3[0])[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      Final_project_B.CAN_Receive_data19_o2 = flexcan_564xl_get_idtype(0, 3);
      Final_project_B.CAN_Receive_data19_o4 = flexcan_564xl_get_ts(0, 3);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 3);
    }
  }

  /* S-Function (bytes2single): '<S31>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle2_g), (void*)
         (&(Final_project_B.CAN_Receive_data19_o3[0])), sizeof
         (Final_project_B.BytestoSingle2_g) );

  /* S-Function (bytes2single): '<S31>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(Final_project_B.BytestoSingle3_g), (void*)
         (&(Final_project_B.CAN_Receive_data19_o3[4])), sizeof
         (Final_project_B.BytestoSingle3_g) );

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   */
  Final_project_B.Switch[0] = Final_project_B.BytestoSingle_h;
  Final_project_B.Switch[1] = Final_project_B.BytestoSingle1_j;
  Final_project_B.Switch[2] = Final_project_B.BytestoSingle3_g;
  Final_project_B.Switch[3] = Final_project_B.BytestoSingle2_g;
  Final_project_B.Switch[4] = 0.0F;
  Final_project_B.Switch[5] = 0.0F;
  Final_project_B.Switch[6] = 0.0F;
  Final_project_B.Switch[7] = 0.0F;
  Final_project_B.Switch[8] = 0.0F;
  Final_project_B.Switch[9] = 0.0F;
  Final_project_B.Switch[10] = 0.0F;
  Final_project_B.Switch[11] = 0.0F;
  Final_project_B.Switch[12] = 0.0F;
  Final_project_B.Switch[13] = 0.0F;
  Final_project_B.Switch[14] = 0.0F;
  Final_project_B.Switch[15] = 0.0F;
  Final_project_B.Switch[16] = 0.0F;
  Final_project_B.Switch[17] = 0.0F;
  Final_project_B.Switch[18] = 0.0F;
  Final_project_B.Switch[19] = 0.0F;
  Final_project_B.Switch[20] = 0.0F;
  Final_project_B.Switch[21] = 0.0F;
  Final_project_B.Switch[22] = 0.0F;
  Final_project_B.Switch[23] = 0.0F;

  /* S-Function (gpio_564xl_input): '<S7>/Digital Input' */
  Final_project_B.DigitalInput = gpi_pin_read_564xl_fnc(13);/* GPI Pin Data Input Registers  */

  /* S-Function (gpio_564xl_input): '<S26>/Digital Input1' */
  Final_project_B.DigitalInput1 = gpi_pin_read_564xl_fnc(5);/* GPI Pin Data Input Registers  */

  /* S-Function (gpio_564xl_input): '<S26>/Digital Input2' */
  Final_project_B.DigitalInput2 = gpi_pin_read_564xl_fnc(6);/* GPI Pin Data Input Registers  */

  /* S-Function (gpio_564xl_input): '<S26>/Digital Input3' */
  Final_project_B.DigitalInput3 = gpi_pin_read_564xl_fnc(7);/* GPI Pin Data Input Registers  */

  /* S-Function (gpio_564xl_input): '<S26>/Digital Input4' */
  Final_project_B.DigitalInput4 = gpi_pin_read_564xl_fnc(8);/* GPI Pin Data Input Registers  */

  /* S-Function (gpio_564xl_input): '<S26>/Digital Input5' */
  Final_project_B.DigitalInput5 = gpi_pin_read_564xl_fnc(9);/* GPI Pin Data Input Registers  */

  /* S-Function (gpio_564xl_input): '<S26>/Digital Input6' */
  Final_project_B.DigitalInput6 = gpi_pin_read_564xl_fnc(10);/* GPI Pin Data Input Registers  */

  /* S-Function (gpio_564xl_input): '<S26>/Digital Input7' */
  Final_project_B.DigitalInput7 = gpi_pin_read_564xl_fnc(11);/* GPI Pin Data Input Registers  */

  /* S-Function (gpio_564xl_input): '<S26>/Digital Input8' */
  Final_project_B.DigitalInput8 = gpi_pin_read_564xl_fnc(12);/* GPI Pin Data Input Registers  */

  /* Gain: '<S26>/Gain' incorporates:
   *  ArithShift: '<S26>/Shift Arithmetic'
   *  ArithShift: '<S26>/Shift Arithmetic1'
   *  ArithShift: '<S26>/Shift Arithmetic2'
   *  ArithShift: '<S26>/Shift Arithmetic3'
   *  ArithShift: '<S26>/Shift Arithmetic4'
   *  ArithShift: '<S26>/Shift Arithmetic5'
   *  ArithShift: '<S26>/Shift Arithmetic6'
   *  DataTypeConversion: '<S26>/Data Type Conversion'
   *  DataTypeConversion: '<S26>/Data Type Conversion1'
   *  DataTypeConversion: '<S26>/Data Type Conversion2'
   *  DataTypeConversion: '<S26>/Data Type Conversion3'
   *  DataTypeConversion: '<S26>/Data Type Conversion4'
   *  DataTypeConversion: '<S26>/Data Type Conversion5'
   *  DataTypeConversion: '<S26>/Data Type Conversion6'
   *  DataTypeConversion: '<S26>/Data Type Conversion7'
   *  DataTypeConversion: '<S26>/Data Type Conversion8'
   *  Sum: '<S26>/Add'
   */
  rtb_Gain_ie = (real32_T)((((((((uint32_T)(Final_project_B.DigitalInput2 << 1)
    + Final_project_B.DigitalInput1) + (Final_project_B.DigitalInput3 << 2)) +
    (Final_project_B.DigitalInput4 << 3)) + (Final_project_B.DigitalInput5 << 4))
    + (Final_project_B.DigitalInput6 << 5)) + (Final_project_B.DigitalInput7 <<
    6)) + (Final_project_B.DigitalInput8 << 7)) * 0.25F;

  /* Gain: '<S7>/Gain' */
  Final_project_B.Gain = 0.02F * rtb_Sum1_mn;

  /* S-Function (adc_564xl_input): '<S27>/ADC Channel' */

  /* ADC Data Input ADC_0 Channel 0  */
  Final_project_B.ADCChannel = adc_read_chan( 0, 0 );

  /* Gain: '<S27>/Gain' incorporates:
   *  Constant: '<S27>/Constant'
   *  Sum: '<S27>/Sum'
   */
  rtb_Gain_l = ((real32_T)Final_project_B.ADCChannel - 512.0F) * 0.33F;

  /* S-Function (gpio_564xl_input): '<S7>/Digital Input1' */
  Final_project_B.DigitalInput1_k = gpi_pin_read_564xl_fnc(14);/* GPI Pin Data Input Registers  */

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  if (Final_project_DW.DiscreteTimeIntegrator_SYSTEM_E != 0) {
    Final_project_B.DiscreteTimeIntegrator =
      Final_project_DW.DiscreteTimeIntegrator_DSTATE;
  } else {
    Final_project_B.DiscreteTimeIntegrator = 0.01F * (real32_T)
      Final_project_DW.HighLevelDesign_ELAPS_T
      * Final_project_DW.DiscreteTimeIntegrator_PREV_U +
      Final_project_DW.DiscreteTimeIntegrator_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  if (Final_project_DW.DiscreteTimeIntegrator1_SYSTEM_ != 0) {
    Final_project_B.DiscreteTimeIntegrator1 =
      Final_project_DW.DiscreteTimeIntegrator1_DSTATE;
  } else {
    Final_project_B.DiscreteTimeIntegrator1 = 0.01F * (real32_T)
      Final_project_DW.HighLevelDesign_ELAPS_T
      * Final_project_DW.DiscreteTimeIntegrator1_PREV_U +
      Final_project_DW.DiscreteTimeIntegrator1_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */
  if (Final_project_DW.DiscreteTimeIntegrator2_SYSTEM_ != 0) {
    Final_project_B.DiscreteTimeIntegrator2 =
      Final_project_DW.DiscreteTimeIntegrator2_DSTATE;
  } else {
    Final_project_B.DiscreteTimeIntegrator2 = 0.01F * (real32_T)
      Final_project_DW.HighLevelDesign_ELAPS_T
      * Final_project_DW.DiscreteTimeIntegrator2_PREV_U +
      Final_project_DW.DiscreteTimeIntegrator2_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator3' */
  if (Final_project_DW.DiscreteTimeIntegrator3_SYSTEM_ != 0) {
    Final_project_B.DiscreteTimeIntegrator3 =
      Final_project_DW.DiscreteTimeIntegrator3_DSTATE;
  } else {
    Final_project_B.DiscreteTimeIntegrator3 = 0.01F * (real32_T)
      Final_project_DW.HighLevelDesign_ELAPS_T
      * Final_project_DW.DiscreteTimeIntegrator3_PREV_U +
      Final_project_DW.DiscreteTimeIntegrator3_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S4>/Discrete-Time Integrator3' */

  /* UnitDelay: '<S13>/Unit Delay' */
  Final_project_B.UnitDelay = Final_project_DW.UnitDelay_DSTATE;

  /* S-Function (get_rvec1): '<S9>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        Final_project_B.LookupRightVector_o1 = fy;
        Final_project_B.LookupRightVector_o2 = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        Final_project_B.LookupRightVector_o1 = cos(r);
        Final_project_B.LookupRightVector_o2 = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S4>/Constant'
   */
  rtb_Product = -100.0F * Final_project_B.DiscreteTimeIntegrator *
    Final_project_B.Gain;

  /* Delay: '<S1>/Delay' */
  Final_project_B.Delay[0] = Final_project_DW.Delay_DSTATE[0];
  Final_project_B.Delay[1] = Final_project_DW.Delay_DSTATE[1];
  Final_project_B.Delay[2] = Final_project_DW.Delay_DSTATE[2];
  Final_project_B.Delay[3] = Final_project_DW.Delay_DSTATE[3];

  /* S-Function (calc_lead_vehicle): '<S16>/S-Function Builder' */
  calc_lead_vehicle_Outputs_wrapper(&Final_project_B.DigitalInput,
    &Final_project_B.Switch[0], &Final_project_B.Switch[4],
    &Final_project_B.Switch[8], &Final_project_B.Switch[12],
    &Final_project_B.Switch[16], &Final_project_B.Switch[20],
    &Final_project_B.Delay[0], &Final_project_B.Switch[3],
    &Final_project_B.Switch[7], &Final_project_B.Switch[11],
    &Final_project_B.Switch[15], &Final_project_B.Switch[19],
    &Final_project_B.Switch[23], &Final_project_B.Delay[3],
    &Final_project_ConstP.pooled9, &Final_project_B.SFunctionBuilder_o1_e,
    &Final_project_B.SFunctionBuilder_o2_i,
    &Final_project_B.SFunctionBuilder_o3_l, &Final_project_B.SFunctionBuilder_o4,
    &Final_project_B.SFunctionBuilder_o5 );

  /* Outputs for Enabled SubSystem: '<S5>/Position Ctrl' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (Final_project_B.SFunctionBuilder_o3_l) {
    /* Sum: '<S18>/Sum5' incorporates:
     *  Constant: '<S5>/Constant'
     *  Gain: '<S18>/D-gain'
     *  Gain: '<S18>/Feed-forward'
     *  Gain: '<S18>/P-gain'
     *  Sum: '<S18>/Sum1'
     *  Sum: '<S18>/Sum2'
     *  Sum: '<S18>/Sum3'
     *  Sum: '<S18>/Sum4'
     */
    Final_project_B.Merge = (real32_T)(((20.0 -
      (Final_project_B.SFunctionBuilder_o4 - Final_project_B.Delay[0])) *
      -3000.0 + (Final_project_B.SFunctionBuilder_o5 - Final_project_B.Delay[3])
      * 4900.0F) + 100.0F * Final_project_B.SFunctionBuilder_o5);
  }

  /* End of Outputs for SubSystem: '<S5>/Position Ctrl' */

  /* Outputs for Enabled SubSystem: '<S5>/Speed Ctrl' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (Final_project_B.SFunctionBuilder_o2_i) {
    /* Sum: '<S19>/Sum1' */
    rtb_Sum1_a2 = rtb_Gain_ie - Final_project_B.Delay[3];

    /* Sum: '<S19>/Sum' incorporates:
     *  Gain: '<S19>/Gain'
     *  Gain: '<S20>/Gain1'
     *  Sum: '<S20>/Sum'
     *  UnitDelay: '<S21>/Unit Delay'
     */
    Final_project_B.Merge = (5000.0F * rtb_Sum1_a2 +
      Final_project_DW.UnitDelay_DSTATE_d) + 100.0F * rtb_Gain_ie;

    /* Update for UnitDelay: '<S21>/Unit Delay' incorporates:
     *  Gain: '<S20>/Gain'
     *  Gain: '<S21>/Gain'
     *  Sum: '<S21>/Sum'
     *  UnitDelay: '<S21>/Unit Delay'
     */
    Final_project_DW.UnitDelay_DSTATE_d += 50.0F * rtb_Sum1_a2 * 0.01F;
  }

  /* End of Outputs for SubSystem: '<S5>/Speed Ctrl' */

  /* Outputs for Enabled SubSystem: '<S5>/Manual Fd' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (Final_project_B.SFunctionBuilder_o1_e) {
    /* Inport: '<S17>/Fd' */
    Final_project_B.Merge = rtb_Gain_l;
  }

  /* End of Outputs for SubSystem: '<S5>/Manual Fd' */

  /* S-Function (bicycle_dynamics): '<S4>/S-Function Builder' */
  bicycle_dynamics_Outputs_wrapper(&Final_project_B.Merge, &Final_project_B.Gain,
    &Final_project_B.DiscreteTimeIntegrator,
    &Final_project_B.DiscreteTimeIntegrator1,
    &Final_project_B.SFunctionBuilder_o1, &Final_project_B.SFunctionBuilder_o2,
    &Final_project_B.SFunctionBuilder_o3, &Final_project_B.SFunctionBuilder_o4_m
    );

  /* Sum: '<S4>/Sum' */
  rtb_Gain_ie = Final_project_B.DiscreteTimeIntegrator1 + Final_project_B.Gain;

  /* Product: '<S4>/us ' incorporates:
   *  Gain: '<S9>/Gain'
   *  Product: '<S4>/x comp'
   *  Product: '<S4>/y comp'
   *  Sum: '<S4>/Sum1'
   *  Trigonometry: '<S4>/Trigonometric Function'
   *  Trigonometry: '<S4>/Trigonometric Function1'
   */
  Final_project_B.us = ((real32_T)sin(rtb_Gain_ie) *
                        Final_project_B.LookupRightVector_o1 + (real32_T)cos
                        (rtb_Gain_ie) * -Final_project_B.LookupRightVector_o2) *
    Final_project_B.DiscreteTimeIntegrator;

  /* S-Function (get_path1): '<S10>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      Final_project_B.LookupP_o1 = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      Final_project_B.LookupP_o2 = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      Final_project_B.LookupP_o1 = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      Final_project_B.LookupP_o2 = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S10>/Sum' */
  rtb_Gain_ie = Final_project_B.DiscreteTimeIntegrator2 -
    Final_project_B.LookupP_o1;
  rtb_Gain_l = Final_project_B.DiscreteTimeIntegrator3 -
    Final_project_B.LookupP_o2;

  /* S-Function (get_rvec1): '<S12>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        Final_project_B.LookupRightVector_o1_c = fy;
        Final_project_B.LookupRightVector_o2_k = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        Final_project_B.LookupRightVector_o1_c = cos(r);
        Final_project_B.LookupRightVector_o2_k = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* DataTypeConversion: '<S10>/Data  Type  Conversion' incorporates:
   *  Gain: '<S12>/Gain'
   *  Product: '<S14>/Product'
   *  Sum: '<S14>/Sum1'
   */
  rtb_DataTypeConversion = rtb_Gain_ie * -Final_project_B.LookupRightVector_o2_k
    + rtb_Gain_l * Final_project_B.LookupRightVector_o1_c;

  /* DiscreteStateSpace: '<S10>/Controller' */
  {
    rtb_Product1 = 0.38289220218870362*Final_project_DW.Controller_DSTATE;
    rtb_Product1 += 150.12501387153085*rtb_DataTypeConversion;
  }

  /* S-Function (get_rvec1): '<S10>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        Final_project_B.LookupRightVector_o1_h = fy;
        Final_project_B.LookupRightVector_o2_a = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        Final_project_B.LookupRightVector_o1_h = cos(r);
        Final_project_B.LookupRightVector_o2_a = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Update for UnitDelay: '<S13>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S11>/Conversion'
   *  Gain: '<S13>/Gain'
   *  Sum: '<S13>/Sum'
   */
  Final_project_DW.UnitDelay_DSTATE = 0.01F * (real32_T)rtb_Product1 +
    Final_project_B.UnitDelay;

  /* Product: '<S15>/Product' */
  rtb_Gain_ie *= Final_project_B.LookupRightVector_o1_h;

  /* Sum: '<S15>/Sum1' incorporates:
   *  Product: '<S15>/Product'
   */
  Final_project_B.Sum1 = rtb_Gain_l * Final_project_B.LookupRightVector_o2_a +
    rtb_Gain_ie;

  /* Outputs for Enabled SubSystem: '<S6>/Controller' incorporates:
   *  EnablePort: '<S22>/Enable'
   */
  if (Final_project_B.DigitalInput1_k) {
    if (!Final_project_DW.Controller_MODE) {
      Final_project_DW.Controller_RESET_ELAPS_T = true;

      /* Enable for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
      Final_project_DW.DiscreteTimeIntegrator_SYSTEM_k = 1U;
      Final_project_DW.Controller_MODE = true;
    }

    if (Final_project_DW.Controller_RESET_ELAPS_T) {
      Final_project_DW.Controller_ELAPS_T = 0U;
    } else {
      Final_project_DW.Controller_ELAPS_T = Final_project_M->Timing.clockTick0 -
        Final_project_DW.Controller_PREV_T;
    }

    Final_project_DW.Controller_PREV_T = Final_project_M->Timing.clockTick0;
    Final_project_DW.Controller_RESET_ELAPS_T = false;

    /* SampleTimeMath: '<S23>/TSamp' incorporates:
     *  Constant: '<S6>/Constant'
     *  Sum: '<S22>/Sum2'
     *
     * About '<S23>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_Gain_ie = (real32_T)((real_T)(0.5F - Final_project_B.Sum1) / (real32_T)
      ((real_T)Final_project_DW.Controller_ELAPS_T * 0.01));

    /* Sum: '<S22>/Sum3' incorporates:
     *  Constant: '<S6>/Constant'
     *  Gain: '<S22>/D-n'
     *  Gain: '<S22>/P-n'
     *  Product: '<S22>/Product'
     *  Sum: '<S22>/Sum1'
     *  Sum: '<S22>/Sum2'
     *  Sum: '<S23>/Diff'
     *  UnitDelay: '<S23>/UD'
     */
    rtb_Gain_l = -((0.5F - Final_project_B.Sum1) * 0.2F + (rtb_Gain_ie -
      Final_project_DW.UD_DSTATE) * 0.05F) - Final_project_B.Gain;

    /* SampleTimeMath: '<S24>/TSamp'
     *
     * About '<S24>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_Sum1_a2 = (real32_T)((real_T)rtb_Gain_l / (real32_T)((real_T)
      Final_project_DW.Controller_ELAPS_T * 0.01));

    /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
    if (Final_project_DW.DiscreteTimeIntegrator_SYSTEM_k != 0) {
      Final_project_B.DiscreteTimeIntegrator_l =
        Final_project_DW.DiscreteTimeIntegrator_DSTATE_d;
    } else {
      Final_project_B.DiscreteTimeIntegrator_l = 0.01F * (real32_T)
        Final_project_DW.Controller_ELAPS_T
        * Final_project_DW.DiscreteTimeIntegrator_PREV_U_k +
        Final_project_DW.DiscreteTimeIntegrator_DSTATE_d;
    }

    /* End of DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */

    /* Product: '<S22>/Product1' incorporates:
     *  Gain: '<S22>/D-delta'
     *  Gain: '<S22>/I-delta'
     *  Gain: '<S22>/P_delta'
     *  Sum: '<S22>/Sum4'
     *  Sum: '<S24>/Diff'
     *  UnitDelay: '<S24>/UD'
     */
    Final_project_B.Product1 = -(((rtb_Sum1_a2 - Final_project_DW.UD_DSTATE_n) *
      400.0F + 500.0F * rtb_Gain_l) + 0.005F *
      Final_project_B.DiscreteTimeIntegrator_l);

    /* Update for UnitDelay: '<S23>/UD' */
    Final_project_DW.UD_DSTATE = rtb_Gain_ie;

    /* Update for UnitDelay: '<S24>/UD' */
    Final_project_DW.UD_DSTATE_n = rtb_Sum1_a2;

    /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
    Final_project_DW.DiscreteTimeIntegrator_SYSTEM_k = 0U;
    Final_project_DW.DiscreteTimeIntegrator_DSTATE_d =
      Final_project_B.DiscreteTimeIntegrator_l;
    Final_project_DW.DiscreteTimeIntegrator_PREV_U_k = rtb_Gain_l;
  } else {
    if (Final_project_DW.Controller_MODE) {
      Final_project_DW.Controller_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S6>/Controller' */

  /* S-Function (get_rvec1): '<S38>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        Final_project_B.LookupRightVector_o1_m = fy;
        Final_project_B.LookupRightVector_o2_i = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        Final_project_B.LookupRightVector_o1_m = cos(r);
        Final_project_B.LookupRightVector_o2_i = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_path1): '<S38>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      Final_project_B.LookupP_o1_f = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      Final_project_B.LookupP_o2_n = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      Final_project_B.LookupP_o1_f = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      Final_project_B.LookupP_o2_n = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S45>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[0]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        Final_project_B.LookupRightVector_o1_e = fy;
        Final_project_B.LookupRightVector_o2_o = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        Final_project_B.LookupRightVector_o1_e = cos(r);
        Final_project_B.LookupRightVector_o2_o = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Product: '<S45>/Product' */
  rtb_Gain_ie = Final_project_B.Switch[1] *
    Final_project_B.LookupRightVector_o1_e;
  rtb_Gain_l = Final_project_B.Switch[1] *
    Final_project_B.LookupRightVector_o2_o;

  /* S-Function (get_path1): '<S45>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[0]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      Final_project_B.LookupP_o1_f5 = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      Final_project_B.LookupP_o2_e = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      Final_project_B.LookupP_o1_f5 = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      Final_project_B.LookupP_o2_e = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S45>/Sum' */
  rtb_Gain_ie += Final_project_B.LookupP_o1_f5;

  /* S-Function (get_rvec1): '<S46>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[4]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        Final_project_B.LookupRightVector_o1_o = fy;
        Final_project_B.LookupRightVector_o2_h = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        Final_project_B.LookupRightVector_o1_o = cos(r);
        Final_project_B.LookupRightVector_o2_h = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Product: '<S46>/Product' */
  rtb_Sum1_a2 = Final_project_B.Switch[5] *
    Final_project_B.LookupRightVector_o1_o;
  rtb_C_o_idx_1 = Final_project_B.Switch[5] *
    Final_project_B.LookupRightVector_o2_h;

  /* S-Function (get_path1): '<S46>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[4]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      Final_project_B.LookupP_o1_g = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      Final_project_B.LookupP_o2_f = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      Final_project_B.LookupP_o1_g = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      Final_project_B.LookupP_o2_f = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S46>/Sum' */
  rtb_Sum1_a2 += Final_project_B.LookupP_o1_g;

  /* S-Function (get_rvec1): '<S47>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[8]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        Final_project_B.LookupRightVector_o1_p = fy;
        Final_project_B.LookupRightVector_o2_ku = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        Final_project_B.LookupRightVector_o1_p = cos(r);
        Final_project_B.LookupRightVector_o2_ku = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Product: '<S47>/Product' */
  rtb_C_j_idx_0 = Final_project_B.Switch[9] *
    Final_project_B.LookupRightVector_o1_p;
  rtb_C_j_idx_1 = Final_project_B.Switch[9] *
    Final_project_B.LookupRightVector_o2_ku;

  /* S-Function (get_path1): '<S47>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[8]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      Final_project_B.LookupP_o1_l = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      Final_project_B.LookupP_o2_i = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      Final_project_B.LookupP_o1_l = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      Final_project_B.LookupP_o2_i = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S47>/Sum' */
  rtb_C_j_idx_0 += Final_project_B.LookupP_o1_l;

  /* S-Function (get_rvec1): '<S48>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[12]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        Final_project_B.LookupRightVector_o1_b = fy;
        Final_project_B.LookupRightVector_o2_b = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        Final_project_B.LookupRightVector_o1_b = cos(r);
        Final_project_B.LookupRightVector_o2_b = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Product: '<S48>/Product' */
  rtb_C_p_idx_0 = Final_project_B.Switch[13] *
    Final_project_B.LookupRightVector_o1_b;
  rtb_C_p_idx_1 = Final_project_B.Switch[13] *
    Final_project_B.LookupRightVector_o2_b;

  /* S-Function (get_path1): '<S48>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[12]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      Final_project_B.LookupP_o1_ld = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      Final_project_B.LookupP_o2_nc = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      Final_project_B.LookupP_o1_ld = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      Final_project_B.LookupP_o2_nc = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S48>/Sum' */
  rtb_C_p_idx_0 += Final_project_B.LookupP_o1_ld;

  /* S-Function (get_rvec1): '<S49>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[16]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        Final_project_B.LookupRightVector_o1_mi = fy;
        Final_project_B.LookupRightVector_o2_l = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        Final_project_B.LookupRightVector_o1_mi = cos(r);
        Final_project_B.LookupRightVector_o2_l = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Product: '<S49>/Product' */
  rtb_C_pd_idx_0 = Final_project_B.Switch[17] *
    Final_project_B.LookupRightVector_o1_mi;
  rtb_C_pd_idx_1 = Final_project_B.Switch[17] *
    Final_project_B.LookupRightVector_o2_l;

  /* S-Function (get_path1): '<S49>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[16]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      Final_project_B.LookupP_o1_n = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      Final_project_B.LookupP_o2_k = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      Final_project_B.LookupP_o1_n = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      Final_project_B.LookupP_o2_k = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S49>/Sum' */
  rtb_C_pd_idx_0 += Final_project_B.LookupP_o1_n;

  /* S-Function (get_rvec1): '<S50>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[20]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        Final_project_B.LookupRightVector_o1_l = fy;
        Final_project_B.LookupRightVector_o2_c = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        Final_project_B.LookupRightVector_o1_l = cos(r);
        Final_project_B.LookupRightVector_o2_c = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Product: '<S50>/Product' */
  rtb_C_d_idx_0 = Final_project_B.Switch[21] *
    Final_project_B.LookupRightVector_o1_l;
  rtb_C_d_idx_1 = Final_project_B.Switch[21] *
    Final_project_B.LookupRightVector_o2_c;

  /* S-Function (get_path1): '<S50>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (Final_project_B.Switch[20]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      Final_project_B.LookupP_o1_lw = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      Final_project_B.LookupP_o2_d = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      Final_project_B.LookupP_o1_lw = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      Final_project_B.LookupP_o2_d = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* SignalConversion: '<S1>/OutportBufferForSerial' incorporates:
   *  Product: '<S38>/Product'
   *  Sum: '<S38>/Sum'
   *  Sum: '<S45>/Sum'
   *  Sum: '<S46>/Sum'
   *  Sum: '<S47>/Sum'
   *  Sum: '<S48>/Sum'
   *  Sum: '<S49>/Sum'
   *  Sum: '<S50>/Sum'
   */
  Final_project_B.OutportBufferForSerial[0] = Final_project_B.Sum1 *
    Final_project_B.LookupRightVector_o1_m + Final_project_B.LookupP_o1_f;
  Final_project_B.OutportBufferForSerial[1] = Final_project_B.Sum1 *
    Final_project_B.LookupRightVector_o2_i + Final_project_B.LookupP_o2_n;
  Final_project_B.OutportBufferForSerial[2] =
    Final_project_B.DiscreteTimeIntegrator1;
  Final_project_B.OutportBufferForSerial[3] =
    Final_project_B.DiscreteTimeIntegrator;
  Final_project_B.OutportBufferForSerial[6] = Final_project_B.Switch[2];
  Final_project_B.OutportBufferForSerial[9] = Final_project_B.Switch[6];
  Final_project_B.OutportBufferForSerial[12] = Final_project_B.Switch[10];
  Final_project_B.OutportBufferForSerial[15] = Final_project_B.Switch[14];
  Final_project_B.OutportBufferForSerial[18] = Final_project_B.Switch[18];
  Final_project_B.OutportBufferForSerial[4] = rtb_Gain_ie;
  Final_project_B.OutportBufferForSerial[7] = rtb_Sum1_a2;
  Final_project_B.OutportBufferForSerial[10] = rtb_C_j_idx_0;
  Final_project_B.OutportBufferForSerial[13] = rtb_C_p_idx_0;
  Final_project_B.OutportBufferForSerial[16] = rtb_C_pd_idx_0;
  Final_project_B.OutportBufferForSerial[19] = rtb_C_d_idx_0 +
    Final_project_B.LookupP_o1_lw;
  Final_project_B.OutportBufferForSerial[5] = rtb_Gain_l +
    Final_project_B.LookupP_o2_e;
  Final_project_B.OutportBufferForSerial[8] = rtb_C_o_idx_1 +
    Final_project_B.LookupP_o2_f;
  Final_project_B.OutportBufferForSerial[11] = rtb_C_j_idx_1 +
    Final_project_B.LookupP_o2_i;
  Final_project_B.OutportBufferForSerial[14] = rtb_C_p_idx_1 +
    Final_project_B.LookupP_o2_nc;
  Final_project_B.OutportBufferForSerial[17] = rtb_C_pd_idx_1 +
    Final_project_B.LookupP_o2_k;
  Final_project_B.OutportBufferForSerial[20] = rtb_C_d_idx_1 +
    Final_project_B.LookupP_o2_d;
  Final_project_B.OutportBufferForSerial[21] = Final_project_B.Switch[22];

  /* S-Function (single2bytes): '<S36>/Single to Bytes' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes[0] = ((uint8_T*)&Final_project_B.UnitDelay)[0];
  Final_project_B.SingletoBytes[1] = ((uint8_T*)&Final_project_B.UnitDelay)[1];
  Final_project_B.SingletoBytes[2] = ((uint8_T*)&Final_project_B.UnitDelay)[2];
  Final_project_B.SingletoBytes[3] = ((uint8_T*)&Final_project_B.UnitDelay)[3];

  /* S-Function (single2bytes): '<S36>/Single to Bytes1' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes1[0] = ((uint8_T*)&Final_project_B.Sum1)[0];
  Final_project_B.SingletoBytes1[1] = ((uint8_T*)&Final_project_B.Sum1)[1];
  Final_project_B.SingletoBytes1[2] = ((uint8_T*)&Final_project_B.Sum1)[2];
  Final_project_B.SingletoBytes1[3] = ((uint8_T*)&Final_project_B.Sum1)[3];

  /* SignalConversion: '<S36>/TmpSignal ConversionAtCAN TransmitInport1' */
  Final_project_B.TmpSignalConversionAtCANTransmi[0] =
    Final_project_B.SingletoBytes[0];
  Final_project_B.TmpSignalConversionAtCANTransmi[4] =
    Final_project_B.SingletoBytes1[0];
  Final_project_B.TmpSignalConversionAtCANTransmi[1] =
    Final_project_B.SingletoBytes[1];
  Final_project_B.TmpSignalConversionAtCANTransmi[5] =
    Final_project_B.SingletoBytes1[1];
  Final_project_B.TmpSignalConversionAtCANTransmi[2] =
    Final_project_B.SingletoBytes[2];
  Final_project_B.TmpSignalConversionAtCANTransmi[6] =
    Final_project_B.SingletoBytes1[2];
  Final_project_B.TmpSignalConversionAtCANTransmi[3] =
    Final_project_B.SingletoBytes[3];
  Final_project_B.TmpSignalConversionAtCANTransmi[7] =
    Final_project_B.SingletoBytes1[3];

  /* S-Function (can_564xl_transmit): '<S36>/CAN Transmit' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    uint8_t* data = &Final_project_B.TmpSignalConversionAtCANTransmi[0];
    uint8_t datalen = ((uint8_T)8U);
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    ptr_FLEXCAN_MsgBufferStructure->length = datalen;
    if (45&0xFFFF800)
      ptr_FLEXCAN_MsgBufferStructure->ext = 1;
    ptr_FLEXCAN_MsgBufferStructure->id = 45;
    for (i=0;i<datalen;i++) {
      ptr_FLEXCAN_MsgBufferStructure->data[i] = *(data++);
    }

    ptr_FLEXCAN_MsgBufferStructure->code = CAN_TX_MSG;
    flexcan_564xl_buffer_transmit(ptr_FLEXCAN_MsgBufferStructure,0,0);
    flexcan_564xl_release_mb_lock(0);
    flexcan_564xl_clear_mask(0, 0);
  }

  /* S-Function (single2bytes): '<S36>/Single to Bytes3' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes3[0] = ((uint8_T*)&Final_project_B.us)[0];
  Final_project_B.SingletoBytes3[1] = ((uint8_T*)&Final_project_B.us)[1];
  Final_project_B.SingletoBytes3[2] = ((uint8_T*)&Final_project_B.us)[2];
  Final_project_B.SingletoBytes3[3] = ((uint8_T*)&Final_project_B.us)[3];

  /* S-Function (single2bytes): '<S36>/Single to Bytes2' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes2[0] = ((uint8_T*)
    &Final_project_B.DiscreteTimeIntegrator1)[0];
  Final_project_B.SingletoBytes2[1] = ((uint8_T*)
    &Final_project_B.DiscreteTimeIntegrator1)[1];
  Final_project_B.SingletoBytes2[2] = ((uint8_T*)
    &Final_project_B.DiscreteTimeIntegrator1)[2];
  Final_project_B.SingletoBytes2[3] = ((uint8_T*)
    &Final_project_B.DiscreteTimeIntegrator1)[3];

  /* SignalConversion: '<S36>/TmpSignal ConversionAtCAN Transmit2Inport1' */
  Final_project_B.TmpSignalConversionAtCANTrans_i[0] =
    Final_project_B.SingletoBytes3[0];
  Final_project_B.TmpSignalConversionAtCANTrans_i[4] =
    Final_project_B.SingletoBytes2[0];
  Final_project_B.TmpSignalConversionAtCANTrans_i[1] =
    Final_project_B.SingletoBytes3[1];
  Final_project_B.TmpSignalConversionAtCANTrans_i[5] =
    Final_project_B.SingletoBytes2[1];
  Final_project_B.TmpSignalConversionAtCANTrans_i[2] =
    Final_project_B.SingletoBytes3[2];
  Final_project_B.TmpSignalConversionAtCANTrans_i[6] =
    Final_project_B.SingletoBytes2[2];
  Final_project_B.TmpSignalConversionAtCANTrans_i[3] =
    Final_project_B.SingletoBytes3[3];
  Final_project_B.TmpSignalConversionAtCANTrans_i[7] =
    Final_project_B.SingletoBytes2[3];

  /* S-Function (can_564xl_transmit): '<S36>/CAN Transmit2' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    uint8_t* data = &Final_project_B.TmpSignalConversionAtCANTrans_i[0];
    uint8_t datalen = ((uint8_T)8U);
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    ptr_FLEXCAN_MsgBufferStructure->length = datalen;
    if (46&0xFFFF800)
      ptr_FLEXCAN_MsgBufferStructure->ext = 1;
    ptr_FLEXCAN_MsgBufferStructure->id = 46;
    for (i=0;i<datalen;i++) {
      ptr_FLEXCAN_MsgBufferStructure->data[i] = *(data++);
    }

    ptr_FLEXCAN_MsgBufferStructure->code = CAN_TX_MSG;
    flexcan_564xl_buffer_transmit(ptr_FLEXCAN_MsgBufferStructure,1,0);
    flexcan_564xl_release_mb_lock(0);
    flexcan_564xl_clear_mask(0, 1);
  }

  /* Sum: '<S37>/Sum' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   *  Product: '<S37>/Product'
   *  Sum: '<S8>/Sum1'
   */
  rtb_Product = (rtb_Product + Final_project_B.Product1) * 0.00031625F + 0.5F;

  /* Saturate: '<S37>/Saturation' */
  if (rtb_Product > 0.9F) {
    rtb_Product = 0.9F;
  } else {
    if (rtb_Product < 0.1F) {
      rtb_Product = 0.1F;
    }
  }

  /* Product: '<S37>/Product1' incorporates:
   *  Constant: '<S37>/Constant2'
   *  Saturate: '<S37>/Saturation'
   */
  rtb_Product1 = 100.0 * rtb_Product;

  /* DataTypeConversion: '<S37>/Data Type Conversion1' */
  tmp = floor(rtb_Product1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  Final_project_B.DataTypeConversion1 = tmp < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S37>/Data Type Conversion1' */

  /* S-Function (Simple_PWM_564xL_output): '<S37>/Simple PWM Output' */

  /* Simple PWM Outputs with Deadtime update: Module, Sub Module, Frequency, Resolution, DutyCycle, PWMH Dead time, PWML Dead time */
  pwm_update_564xL_simple_B_phase_shift(0, 0, 20000U, 1, 0U,
    Final_project_B.DataTypeConversion1, 0U);

  /* Update for Delay: '<S33>/Delay' */
  Final_project_DW.Delay_DSTATE_p = Final_project_B.eTimerCNTRRegisterRead;

  /* Update for Delay: '<S33>/Delay1' */
  Final_project_DW.Delay1_DSTATE = rtb_Sum1_mn;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  Final_project_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
  Final_project_DW.DiscreteTimeIntegrator_DSTATE =
    Final_project_B.DiscreteTimeIntegrator;
  Final_project_DW.DiscreteTimeIntegrator_PREV_U =
    Final_project_B.SFunctionBuilder_o4_m;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  Final_project_DW.DiscreteTimeIntegrator1_SYSTEM_ = 0U;
  Final_project_DW.DiscreteTimeIntegrator1_DSTATE =
    Final_project_B.DiscreteTimeIntegrator1;
  Final_project_DW.DiscreteTimeIntegrator1_PREV_U =
    Final_project_B.SFunctionBuilder_o3;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */
  Final_project_DW.DiscreteTimeIntegrator2_SYSTEM_ = 0U;
  Final_project_DW.DiscreteTimeIntegrator2_DSTATE =
    Final_project_B.DiscreteTimeIntegrator2;
  Final_project_DW.DiscreteTimeIntegrator2_PREV_U =
    Final_project_B.SFunctionBuilder_o1;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator3' */
  Final_project_DW.DiscreteTimeIntegrator3_SYSTEM_ = 0U;
  Final_project_DW.DiscreteTimeIntegrator3_DSTATE =
    Final_project_B.DiscreteTimeIntegrator3;
  Final_project_DW.DiscreteTimeIntegrator3_PREV_U =
    Final_project_B.SFunctionBuilder_o2;

  /* Update for Delay: '<S1>/Delay' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAtDelayInport1'
   */
  Final_project_DW.Delay_DSTATE[0] = Final_project_B.UnitDelay;
  Final_project_DW.Delay_DSTATE[1] = Final_project_B.Sum1;
  Final_project_DW.Delay_DSTATE[2] = Final_project_B.DiscreteTimeIntegrator1;
  Final_project_DW.Delay_DSTATE[3] = Final_project_B.us;

  /* Update for DiscreteStateSpace: '<S10>/Controller' */
  {
    real_T xnew[1];
    xnew[0] = 1.0*Final_project_DW.Controller_DSTATE;
    xnew[0] += 0.65292519369349644*rtb_DataTypeConversion;
    (void) memcpy(&Final_project_DW.Controller_DSTATE, xnew,
                  sizeof(real_T)*1);
  }

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Top' */

  /* RateTransition: '<Root>/Rate Transition' */
  if (Final_project_M->Timing.RateInteraction.TID0_1) {
    memcpy(&Final_project_B.RateTransition[0],
           &Final_project_B.OutportBufferForSerial[0], 22U * sizeof(real32_T));
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* S-Function (Simple_PWM_564xL_output): '<S2>/Simple PWM Output' */

  /* Simple PWM Outputs with Deadtime update: Module, Sub Module, Frequency, Resolution, DutyCycle, PWMH Dead time, PWML Dead time */
  pwm_update_564xL_simple_edge_align(0, 1, 1000000U, 1, 0U, 50U);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Final_project_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void Final_project_step1(void)         /* Sample time: [0.05s, 0.0s] */
{
  int8_T s51_iter;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/Serial'
   */

  /* S-Function (single2bytes): '<S3>/Single to Bytes' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes_j[0] = ((uint8_T*)
    &Final_project_B.RateTransition[0])[0];
  Final_project_B.SingletoBytes_j[1] = ((uint8_T*)
    &Final_project_B.RateTransition[0])[1];
  Final_project_B.SingletoBytes_j[2] = ((uint8_T*)
    &Final_project_B.RateTransition[0])[2];
  Final_project_B.SingletoBytes_j[3] = ((uint8_T*)
    &Final_project_B.RateTransition[0])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes1' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes1_o[0] = ((uint8_T*)
    &Final_project_B.RateTransition[1])[0];
  Final_project_B.SingletoBytes1_o[1] = ((uint8_T*)
    &Final_project_B.RateTransition[1])[1];
  Final_project_B.SingletoBytes1_o[2] = ((uint8_T*)
    &Final_project_B.RateTransition[1])[2];
  Final_project_B.SingletoBytes1_o[3] = ((uint8_T*)
    &Final_project_B.RateTransition[1])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes2' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes2_n[0] = ((uint8_T*)
    &Final_project_B.RateTransition[2])[0];
  Final_project_B.SingletoBytes2_n[1] = ((uint8_T*)
    &Final_project_B.RateTransition[2])[1];
  Final_project_B.SingletoBytes2_n[2] = ((uint8_T*)
    &Final_project_B.RateTransition[2])[2];
  Final_project_B.SingletoBytes2_n[3] = ((uint8_T*)
    &Final_project_B.RateTransition[2])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes3' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes3_e[0] = ((uint8_T*)
    &Final_project_B.RateTransition[3])[0];
  Final_project_B.SingletoBytes3_e[1] = ((uint8_T*)
    &Final_project_B.RateTransition[3])[1];
  Final_project_B.SingletoBytes3_e[2] = ((uint8_T*)
    &Final_project_B.RateTransition[3])[2];
  Final_project_B.SingletoBytes3_e[3] = ((uint8_T*)
    &Final_project_B.RateTransition[3])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes4' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes4[0] = ((uint8_T*)
    &Final_project_B.RateTransition[4])[0];
  Final_project_B.SingletoBytes4[1] = ((uint8_T*)
    &Final_project_B.RateTransition[4])[1];
  Final_project_B.SingletoBytes4[2] = ((uint8_T*)
    &Final_project_B.RateTransition[4])[2];
  Final_project_B.SingletoBytes4[3] = ((uint8_T*)
    &Final_project_B.RateTransition[4])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes5' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes5[0] = ((uint8_T*)
    &Final_project_B.RateTransition[5])[0];
  Final_project_B.SingletoBytes5[1] = ((uint8_T*)
    &Final_project_B.RateTransition[5])[1];
  Final_project_B.SingletoBytes5[2] = ((uint8_T*)
    &Final_project_B.RateTransition[5])[2];
  Final_project_B.SingletoBytes5[3] = ((uint8_T*)
    &Final_project_B.RateTransition[5])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes6' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes6[0] = ((uint8_T*)
    &Final_project_B.RateTransition[6])[0];
  Final_project_B.SingletoBytes6[1] = ((uint8_T*)
    &Final_project_B.RateTransition[6])[1];
  Final_project_B.SingletoBytes6[2] = ((uint8_T*)
    &Final_project_B.RateTransition[6])[2];
  Final_project_B.SingletoBytes6[3] = ((uint8_T*)
    &Final_project_B.RateTransition[6])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes7' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes7[0] = ((uint8_T*)
    &Final_project_B.RateTransition[7])[0];
  Final_project_B.SingletoBytes7[1] = ((uint8_T*)
    &Final_project_B.RateTransition[7])[1];
  Final_project_B.SingletoBytes7[2] = ((uint8_T*)
    &Final_project_B.RateTransition[7])[2];
  Final_project_B.SingletoBytes7[3] = ((uint8_T*)
    &Final_project_B.RateTransition[7])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes8' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes8[0] = ((uint8_T*)
    &Final_project_B.RateTransition[8])[0];
  Final_project_B.SingletoBytes8[1] = ((uint8_T*)
    &Final_project_B.RateTransition[8])[1];
  Final_project_B.SingletoBytes8[2] = ((uint8_T*)
    &Final_project_B.RateTransition[8])[2];
  Final_project_B.SingletoBytes8[3] = ((uint8_T*)
    &Final_project_B.RateTransition[8])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes9' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes9[0] = ((uint8_T*)
    &Final_project_B.RateTransition[9])[0];
  Final_project_B.SingletoBytes9[1] = ((uint8_T*)
    &Final_project_B.RateTransition[9])[1];
  Final_project_B.SingletoBytes9[2] = ((uint8_T*)
    &Final_project_B.RateTransition[9])[2];
  Final_project_B.SingletoBytes9[3] = ((uint8_T*)
    &Final_project_B.RateTransition[9])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes10' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes10[0] = ((uint8_T*)
    &Final_project_B.RateTransition[10])[0];
  Final_project_B.SingletoBytes10[1] = ((uint8_T*)
    &Final_project_B.RateTransition[10])[1];
  Final_project_B.SingletoBytes10[2] = ((uint8_T*)
    &Final_project_B.RateTransition[10])[2];
  Final_project_B.SingletoBytes10[3] = ((uint8_T*)
    &Final_project_B.RateTransition[10])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes11' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes11[0] = ((uint8_T*)
    &Final_project_B.RateTransition[11])[0];
  Final_project_B.SingletoBytes11[1] = ((uint8_T*)
    &Final_project_B.RateTransition[11])[1];
  Final_project_B.SingletoBytes11[2] = ((uint8_T*)
    &Final_project_B.RateTransition[11])[2];
  Final_project_B.SingletoBytes11[3] = ((uint8_T*)
    &Final_project_B.RateTransition[11])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes12' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes12[0] = ((uint8_T*)
    &Final_project_B.RateTransition[12])[0];
  Final_project_B.SingletoBytes12[1] = ((uint8_T*)
    &Final_project_B.RateTransition[12])[1];
  Final_project_B.SingletoBytes12[2] = ((uint8_T*)
    &Final_project_B.RateTransition[12])[2];
  Final_project_B.SingletoBytes12[3] = ((uint8_T*)
    &Final_project_B.RateTransition[12])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes13' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes13[0] = ((uint8_T*)
    &Final_project_B.RateTransition[13])[0];
  Final_project_B.SingletoBytes13[1] = ((uint8_T*)
    &Final_project_B.RateTransition[13])[1];
  Final_project_B.SingletoBytes13[2] = ((uint8_T*)
    &Final_project_B.RateTransition[13])[2];
  Final_project_B.SingletoBytes13[3] = ((uint8_T*)
    &Final_project_B.RateTransition[13])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes14' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes14[0] = ((uint8_T*)
    &Final_project_B.RateTransition[14])[0];
  Final_project_B.SingletoBytes14[1] = ((uint8_T*)
    &Final_project_B.RateTransition[14])[1];
  Final_project_B.SingletoBytes14[2] = ((uint8_T*)
    &Final_project_B.RateTransition[14])[2];
  Final_project_B.SingletoBytes14[3] = ((uint8_T*)
    &Final_project_B.RateTransition[14])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes15' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes15[0] = ((uint8_T*)
    &Final_project_B.RateTransition[15])[0];
  Final_project_B.SingletoBytes15[1] = ((uint8_T*)
    &Final_project_B.RateTransition[15])[1];
  Final_project_B.SingletoBytes15[2] = ((uint8_T*)
    &Final_project_B.RateTransition[15])[2];
  Final_project_B.SingletoBytes15[3] = ((uint8_T*)
    &Final_project_B.RateTransition[15])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes16' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes16[0] = ((uint8_T*)
    &Final_project_B.RateTransition[16])[0];
  Final_project_B.SingletoBytes16[1] = ((uint8_T*)
    &Final_project_B.RateTransition[16])[1];
  Final_project_B.SingletoBytes16[2] = ((uint8_T*)
    &Final_project_B.RateTransition[16])[2];
  Final_project_B.SingletoBytes16[3] = ((uint8_T*)
    &Final_project_B.RateTransition[16])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes17' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes17[0] = ((uint8_T*)
    &Final_project_B.RateTransition[17])[0];
  Final_project_B.SingletoBytes17[1] = ((uint8_T*)
    &Final_project_B.RateTransition[17])[1];
  Final_project_B.SingletoBytes17[2] = ((uint8_T*)
    &Final_project_B.RateTransition[17])[2];
  Final_project_B.SingletoBytes17[3] = ((uint8_T*)
    &Final_project_B.RateTransition[17])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes18' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes18[0] = ((uint8_T*)
    &Final_project_B.RateTransition[18])[0];
  Final_project_B.SingletoBytes18[1] = ((uint8_T*)
    &Final_project_B.RateTransition[18])[1];
  Final_project_B.SingletoBytes18[2] = ((uint8_T*)
    &Final_project_B.RateTransition[18])[2];
  Final_project_B.SingletoBytes18[3] = ((uint8_T*)
    &Final_project_B.RateTransition[18])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes19' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes19[0] = ((uint8_T*)
    &Final_project_B.RateTransition[19])[0];
  Final_project_B.SingletoBytes19[1] = ((uint8_T*)
    &Final_project_B.RateTransition[19])[1];
  Final_project_B.SingletoBytes19[2] = ((uint8_T*)
    &Final_project_B.RateTransition[19])[2];
  Final_project_B.SingletoBytes19[3] = ((uint8_T*)
    &Final_project_B.RateTransition[19])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes20' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes20[0] = ((uint8_T*)
    &Final_project_B.RateTransition[20])[0];
  Final_project_B.SingletoBytes20[1] = ((uint8_T*)
    &Final_project_B.RateTransition[20])[1];
  Final_project_B.SingletoBytes20[2] = ((uint8_T*)
    &Final_project_B.RateTransition[20])[2];
  Final_project_B.SingletoBytes20[3] = ((uint8_T*)
    &Final_project_B.RateTransition[20])[3];

  /* S-Function (single2bytes): '<S3>/Single to Bytes21' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  Final_project_B.SingletoBytes21[0] = ((uint8_T*)
    &Final_project_B.RateTransition[21])[0];
  Final_project_B.SingletoBytes21[1] = ((uint8_T*)
    &Final_project_B.RateTransition[21])[1];
  Final_project_B.SingletoBytes21[2] = ((uint8_T*)
    &Final_project_B.RateTransition[21])[2];
  Final_project_B.SingletoBytes21[3] = ((uint8_T*)
    &Final_project_B.RateTransition[21])[3];

  /* Outputs for Iterator SubSystem: '<S3>/For Iterator Subsystem' incorporates:
   *  ForIterator: '<S51>/For Iterator'
   */
  for (s51_iter = 0; s51_iter < 90; s51_iter++) {
    /* MultiPortSwitch: '<S51>/Index Vector' incorporates:
     *  Constant: '<S3>/Constant2'
     *  Constant: '<S3>/Constant3'
     */
    switch (s51_iter) {
     case 0:
      Final_project_B.IndexVector = 115U;
      break;

     case 1:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes_j[0];
      break;

     case 2:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes_j[1];
      break;

     case 3:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes_j[2];
      break;

     case 4:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes_j[3];
      break;

     case 5:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes1_o[0];
      break;

     case 6:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes1_o[1];
      break;

     case 7:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes1_o[2];
      break;

     case 8:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes1_o[3];
      break;

     case 9:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes2_n[0];
      break;

     case 10:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes2_n[1];
      break;

     case 11:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes2_n[2];
      break;

     case 12:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes2_n[3];
      break;

     case 13:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes3_e[0];
      break;

     case 14:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes3_e[1];
      break;

     case 15:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes3_e[2];
      break;

     case 16:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes3_e[3];
      break;

     case 17:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes4[0];
      break;

     case 18:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes4[1];
      break;

     case 19:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes4[2];
      break;

     case 20:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes4[3];
      break;

     case 21:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes5[0];
      break;

     case 22:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes5[1];
      break;

     case 23:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes5[2];
      break;

     case 24:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes5[3];
      break;

     case 25:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes6[0];
      break;

     case 26:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes6[1];
      break;

     case 27:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes6[2];
      break;

     case 28:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes6[3];
      break;

     case 29:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes7[0];
      break;

     case 30:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes7[1];
      break;

     case 31:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes7[2];
      break;

     case 32:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes7[3];
      break;

     case 33:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes8[0];
      break;

     case 34:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes8[1];
      break;

     case 35:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes8[2];
      break;

     case 36:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes8[3];
      break;

     case 37:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes9[0];
      break;

     case 38:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes9[1];
      break;

     case 39:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes9[2];
      break;

     case 40:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes9[3];
      break;

     case 41:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes10[0];
      break;

     case 42:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes10[1];
      break;

     case 43:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes10[2];
      break;

     case 44:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes10[3];
      break;

     case 45:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes11[0];
      break;

     case 46:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes11[1];
      break;

     case 47:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes11[2];
      break;

     case 48:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes11[3];
      break;

     case 49:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes12[0];
      break;

     case 50:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes12[1];
      break;

     case 51:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes12[2];
      break;

     case 52:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes12[3];
      break;

     case 53:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes13[0];
      break;

     case 54:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes13[1];
      break;

     case 55:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes13[2];
      break;

     case 56:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes13[3];
      break;

     case 57:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes14[0];
      break;

     case 58:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes14[1];
      break;

     case 59:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes14[2];
      break;

     case 60:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes14[3];
      break;

     case 61:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes15[0];
      break;

     case 62:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes15[1];
      break;

     case 63:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes15[2];
      break;

     case 64:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes15[3];
      break;

     case 65:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes16[0];
      break;

     case 66:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes16[1];
      break;

     case 67:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes16[2];
      break;

     case 68:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes16[3];
      break;

     case 69:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes17[0];
      break;

     case 70:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes17[1];
      break;

     case 71:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes17[2];
      break;

     case 72:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes17[3];
      break;

     case 73:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes18[0];
      break;

     case 74:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes18[1];
      break;

     case 75:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes18[2];
      break;

     case 76:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes18[3];
      break;

     case 77:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes19[0];
      break;

     case 78:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes19[1];
      break;

     case 79:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes19[2];
      break;

     case 80:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes19[3];
      break;

     case 81:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes20[0];
      break;

     case 82:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes20[1];
      break;

     case 83:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes20[2];
      break;

     case 84:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes20[3];
      break;

     case 85:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes21[0];
      break;

     case 86:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes21[1];
      break;

     case 87:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes21[2];
      break;

     case 88:
      Final_project_B.IndexVector = Final_project_B.SingletoBytes21[3];
      break;

     case 89:
      Final_project_B.IndexVector = 101U;
      break;
    }

    /* End of MultiPortSwitch: '<S51>/Index Vector' */

    /* S-Function (SerialSend): '<S51>/S-Function' */
    {
      LINFLEX_0.BDRL.B.DATA0 = Final_project_B.IndexVector;
      while (!LINFLEX_0.UARTSR.B.DTF_TFF) ;//wait untill completing transmission
      LINFLEX_0.UARTSR.R = 0x2;        //Clear DTF after completing transmission
    }
  }

  /* End of Outputs for SubSystem: '<S3>/For Iterator Subsystem' */
  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Generator1' */
}

/* Model step wrapper function for compatibility with a static main program */
void Final_project_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Final_project_step0();
    break;

   case 1 :
    Final_project_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Final_project_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Final_project_M, 0,
                sizeof(RT_MODEL_Final_project_T));

  /* block I/O */
  (void) memset(((void *) &Final_project_B), 0,
                sizeof(B_Final_project_T));

  /* states (dwork) */
  (void) memset((void *)&Final_project_DW, 0,
                sizeof(DW_Final_project_T));

  /* Start for S-Function (can_564xl_config): '<Root>/CAN Config' */
  flexcan_564xl_init( 0, 1342177343, 82640898);
  flexcan_564xl_pin_init( 0);

  /* Start for S-Function (can_564xl_receive_data): '<S29>/CAN_Receive_data15' */
  {
    if ((15U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 4, 15U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 4, 15U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S29>/CAN_Receive_data16' */
  {
    if ((16U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 5, 16U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 5, 16U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data' */
  {
    if ((25U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 6, 25U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 6, 25U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data5' */
  {
    if ((76U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 11, 76U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 11, 76U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data6' */
  {
    if ((65U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 12, 65U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 12, 65U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data7' */
  {
    if ((66U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 13, 66U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 13, 66U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data8' */
  {
    if ((55U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 14, 55U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 14, 55U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data9' */
  {
    if ((56U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 15, 56U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 15, 56U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data1' */
  {
    if ((26U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 7, 26U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 7, 26U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data2' */
  {
    if ((35U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 8, 35U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 8, 35U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data3' */
  {
    if ((36U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 9, 36U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 9, 36U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S30>/CAN_Receive_data4' */
  {
    if ((75U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 10, 75U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 10, 75U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S31>/CAN_Receive_data18' */
  {
    if ((105U & 0x1FFFF800) != 0x0) {  //extended tag
      flexcan_564xl_set_filter_id(0, 2, 105U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 2, 105U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S31>/CAN_Receive_data19' */
  {
    if ((106U & 0x1FFFF800) != 0x0) {  //extended tag
      flexcan_564xl_set_filter_id(0, 3, 106U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 3, 106U, 0);
    }
  }

  /* Start for S-Function (gpio_564xl_input): '<S7>/Digital Input' */

  /* Initialize Pad Configuration Register 13 as Input */
  gpi_init_pcr_in_564xl_fnc( 13 );

  /* Start for S-Function (gpio_564xl_input): '<S26>/Digital Input1' */

  /* Initialize Pad Configuration Register 5 as Input */
  gpi_init_pcr_in_564xl_fnc( 5 );

  /* Start for S-Function (gpio_564xl_input): '<S26>/Digital Input2' */

  /* Initialize Pad Configuration Register 6 as Input */
  gpi_init_pcr_in_564xl_fnc( 6 );

  /* Start for S-Function (gpio_564xl_input): '<S26>/Digital Input3' */

  /* Initialize Pad Configuration Register 7 as Input */
  gpi_init_pcr_in_564xl_fnc( 7 );

  /* Start for S-Function (gpio_564xl_input): '<S26>/Digital Input4' */

  /* Initialize Pad Configuration Register 8 as Input */
  gpi_init_pcr_in_564xl_fnc( 8 );

  /* Start for S-Function (gpio_564xl_input): '<S26>/Digital Input5' */

  /* Initialize Pad Configuration Register 9 as Input */
  gpi_init_pcr_in_564xl_fnc( 9 );

  /* Start for S-Function (gpio_564xl_input): '<S26>/Digital Input6' */

  /* Initialize Pad Configuration Register 10 as Input */
  gpi_init_pcr_in_564xl_fnc( 10 );

  /* Start for S-Function (gpio_564xl_input): '<S26>/Digital Input7' */

  /* Initialize Pad Configuration Register 11 as Input */
  gpi_init_pcr_in_564xl_fnc( 11 );

  /* Start for S-Function (gpio_564xl_input): '<S26>/Digital Input8' */

  /* Initialize Pad Configuration Register 12 as Input */
  gpi_init_pcr_in_564xl_fnc( 12 );

  /* Start for S-Function (adc_564xl_input): '<S27>/ADC Channel' */
  adc_pin_init( 0, 0);
  adc_channelmode_setup( 0, 0, 1);
  adc_presample( 0, 0, 0);

  /* Start for S-Function (gpio_564xl_input): '<S7>/Digital Input1' */

  /* Initialize Pad Configuration Register 14 as Input */
  gpi_init_pcr_in_564xl_fnc( 14 );

  /* Start for Merge: '<S5>/Merge' */
  Final_project_B.Merge = 0.0F;

  /* InitializeConditions for Enabled SubSystem: '<S6>/Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  Final_project_DW.DiscreteTimeIntegrator_PREV_U_k = 0.0F;

  /* End of InitializeConditions for SubSystem: '<S6>/Controller' */
  /* Start for S-Function (Simple_PWM_564xL_output): '<S37>/Simple PWM Output' */

  /* Initialize Pad Configuration Registers PAn & PBn as Output */
  pwm_init_pcr_out_564xL(0,0,0,58);
  pwm_init_pcr_out_564xL(0,0,1,59);
  pwm_init_pcr_out_564xL(0,0,2,255);

  /* Initialize PWM Submodule 0 to correct dutycycle and frequency */
  pwm_init_564xL_simple(0,0, 20000, 1, 0, 50, 0, 0, 0, 60, 0, 0, 0);

  /* End of Start for S-Function (fcncallgen): '<Root>/Function-Call Top' */

  /* Start for S-Function (Simple_PWM_564xL_output): '<S2>/Simple PWM Output' */

  /* Initialize Pad Configuration Registers PAn & PBn as Output */
  pwm_init_pcr_out_564xL(0,1,0,255);
  pwm_init_pcr_out_564xL(0,1,1,38);
  pwm_init_pcr_out_564xL(0,1,2,255);

  /* Initialize PWM Submodule 1 to correct dutycycle and frequency */
  pwm_init_564xL_simple(0,1, 1000000, 1, 0, 50, 0, 0, 0, 48, 0, 0, 0);

  /* Start for S-Function (SerialInit): '<Root>/Serial Initialization' */
  {
    unsigned long SYSTEM_FREQUENCY = 120000000;
    int baudrate = 115200;

    /* Configure LINFlex 0 pins */
    SIU.PCR[19].B.PA = 1;              // Pin asigned to LINFlex0 Rx
    SIU.PCR[19].B.IBE = 1;             // Input buffer enable
    SIU.PCR[18].B.PA = 1;              // Pin asigned to LINFlex0 Tx
    SIU.PCR[18].B.OBE = 1;             // Output buffer enable

    /* configure linflex0 */
    LINFLEX_0.LINCR1.B.SLEEP = 0x0;    // disable sleep mode
    LINFLEX_0.LINCR1.B.INIT = 0x1;     // init mode
    LINFLEX_0.UARTCR.B.UART = 0x1;     // UART mode
    LINFLEX_0.UARTCR.B.TDFL_TFC = 0x0; // buffer size = 1 byte
    LINFLEX_0.UARTCR.B.RDFL_RFC0 = 0x0;// buffer size = 1 byte
    LINFLEX_0.UARTCR.B.RFBM = 0;       // UART buffer mode
    LINFLEX_0.UARTCR.B.TFBM = 0;       // UART buffer mode
    LINFLEX_0.UARTCR.B.RXEN = 0x1;     // receiver enable
    LINFLEX_0.UARTCR.B.TXEN = 0x1;     // transmitter enable
    LINFLEX_0.UARTCR.B.PCE = 0x0;      // parity control disable
    LINFLEX_0.UARTCR.B.WL0 = 0x1;      // word length 8-bit data
    LINFLEX_0.LINIBRR.B.IBR = (int)(SYSTEM_FREQUENCY/16/baudrate);

    // Baud rate calculation
    LINFLEX_0.LINFBRR.B.FBR = (SYSTEM_FREQUENCY/16/baudrate-
      (int)(SYSTEM_FREQUENCY/16/baudrate))*16;
    LINFLEX_0.LINCR1.B.INIT = 0x0;     // normal mode
  }

  /* Start for S-Function (eTimer_564xL_config): '<Root>/eTimer configuration' */
  etimer_init_pcr_in_out_564xL(0,0,0);
  etimer_init_pcr_in_out_564xL(0,1,1);
  etimer_init_pcr_in_out_564xL(0,2,255);
  etimer_init_pcr_in_out_564xL(0,3,255);
  etimer_init_pcr_in_out_564xL(0,4,255);
  etimer_init_pcr_in_out_564xL(0,5,255);
  etimer_init_564xL (0,0,4,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0);

  /* InitializeConditions for S-Function (fcncallgen): '<Root>/Function-Call Top' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/High Level Design'
   */
  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  Final_project_DW.DiscreteTimeIntegrator_PREV_U = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  Final_project_DW.DiscreteTimeIntegrator1_PREV_U = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */
  Final_project_DW.DiscreteTimeIntegrator2_PREV_U = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator3' */
  Final_project_DW.DiscreteTimeIntegrator3_PREV_U = 0.0F;

  /* Enable for S-Function (fcncallgen): '<Root>/Function-Call Top' incorporates:
   *  Enable for SubSystem: '<Root>/High Level Design'
   */
  Final_project_DW.HighLevelDesign_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  Final_project_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* Enable for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
  Final_project_DW.DiscreteTimeIntegrator1_SYSTEM_ = 1U;

  /* Enable for DiscreteIntegrator: '<S4>/Discrete-Time Integrator2' */
  Final_project_DW.DiscreteTimeIntegrator2_SYSTEM_ = 1U;

  /* Enable for DiscreteIntegrator: '<S4>/Discrete-Time Integrator3' */
  Final_project_DW.DiscreteTimeIntegrator3_SYSTEM_ = 1U;

  /* End of Enable for S-Function (fcncallgen): '<Root>/Function-Call Top' */
}

/* Model terminate function */
void Final_project_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
