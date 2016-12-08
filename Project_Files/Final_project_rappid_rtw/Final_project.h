/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_project.h
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

#ifndef RTW_HEADER_Final_project_h_
#define RTW_HEADER_Final_project_h_
#include <string.h>
#include <math.h>
#ifndef Final_project_COMMON_INCLUDES_
# define Final_project_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Final_project_COMMON_INCLUDES_ */

#include "Final_project_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T RateTransition[22];         /* '<Root>/Rate Transition' */
  real32_T BytestoSingle;              /* '<S29>/Bytes to Single' */
  real32_T BytestoSingle1;             /* '<S29>/Bytes to Single1' */
  real32_T BytestoSingle2;             /* '<S29>/Bytes to Single2' */
  real32_T BytestoSingle3;             /* '<S29>/Bytes to Single3' */
  real32_T BytestoSingle_m;            /* '<S30>/Bytes to Single' */
  real32_T BytestoSingle1_k;           /* '<S30>/Bytes to Single1' */
  real32_T BytestoSingle10;            /* '<S30>/Bytes to Single10' */
  real32_T BytestoSingle11;            /* '<S30>/Bytes to Single11' */
  real32_T BytestoSingle12;            /* '<S30>/Bytes to Single12' */
  real32_T BytestoSingle13;            /* '<S30>/Bytes to Single13' */
  real32_T BytestoSingle14;            /* '<S30>/Bytes to Single14' */
  real32_T BytestoSingle15;            /* '<S30>/Bytes to Single15' */
  real32_T BytestoSingle16;            /* '<S30>/Bytes to Single16' */
  real32_T BytestoSingle17;            /* '<S30>/Bytes to Single17' */
  real32_T BytestoSingle18;            /* '<S30>/Bytes to Single18' */
  real32_T BytestoSingle19;            /* '<S30>/Bytes to Single19' */
  real32_T BytestoSingle2_k;           /* '<S30>/Bytes to Single2' */
  real32_T BytestoSingle3_l;           /* '<S30>/Bytes to Single3' */
  real32_T BytestoSingle4;             /* '<S30>/Bytes to Single4' */
  real32_T BytestoSingle5;             /* '<S30>/Bytes to Single5' */
  real32_T BytestoSingle6;             /* '<S30>/Bytes to Single6' */
  real32_T BytestoSingle7;             /* '<S30>/Bytes to Single7' */
  real32_T BytestoSingle8;             /* '<S30>/Bytes to Single8' */
  real32_T BytestoSingle9;             /* '<S30>/Bytes to Single9' */
  real32_T BytestoSingle_h;            /* '<S31>/Bytes to Single' */
  real32_T BytestoSingle1_j;           /* '<S31>/Bytes to Single1' */
  real32_T BytestoSingle2_g;           /* '<S31>/Bytes to Single2' */
  real32_T BytestoSingle3_g;           /* '<S31>/Bytes to Single3' */
  real32_T Switch[24];                 /* '<S25>/Switch' */
  real32_T Gain;                       /* '<S7>/Gain' */
  real32_T DiscreteTimeIntegrator;     /* '<S4>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1;    /* '<S4>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2;    /* '<S4>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3;    /* '<S4>/Discrete-Time Integrator3' */
  real32_T UnitDelay;                  /* '<S13>/Unit Delay' */
  real32_T LookupRightVector_o1;       /* '<S9>/Look up Right Vector' */
  real32_T LookupRightVector_o2;       /* '<S9>/Look up Right Vector' */
  real32_T Delay[4];                   /* '<S1>/Delay' */
  real32_T SFunctionBuilder_o4;        /* '<S16>/S-Function Builder' */
  real32_T SFunctionBuilder_o5;        /* '<S16>/S-Function Builder' */
  real32_T Merge;                      /* '<S5>/Merge' */
  real32_T SFunctionBuilder_o1;        /* '<S4>/S-Function Builder' */
  real32_T SFunctionBuilder_o2;        /* '<S4>/S-Function Builder' */
  real32_T SFunctionBuilder_o3;        /* '<S4>/S-Function Builder' */
  real32_T SFunctionBuilder_o4_m;      /* '<S4>/S-Function Builder' */
  real32_T us;                         /* '<S4>/us ' */
  real32_T LookupP_o1;                 /* '<S10>/Look up P' */
  real32_T LookupP_o2;                 /* '<S10>/Look up P' */
  real32_T LookupRightVector_o1_c;     /* '<S12>/Look up Right Vector' */
  real32_T LookupRightVector_o2_k;     /* '<S12>/Look up Right Vector' */
  real32_T LookupRightVector_o1_h;     /* '<S10>/Look up Right Vector' */
  real32_T LookupRightVector_o2_a;     /* '<S10>/Look up Right Vector' */
  real32_T Sum1;                       /* '<S15>/Sum1' */
  real32_T LookupRightVector_o1_m;     /* '<S38>/Look up Right Vector' */
  real32_T LookupRightVector_o2_i;     /* '<S38>/Look up Right Vector' */
  real32_T LookupP_o1_f;               /* '<S38>/Look up P' */
  real32_T LookupP_o2_n;               /* '<S38>/Look up P' */
  real32_T LookupRightVector_o1_e;     /* '<S45>/Look up Right Vector' */
  real32_T LookupRightVector_o2_o;     /* '<S45>/Look up Right Vector' */
  real32_T LookupP_o1_f5;              /* '<S45>/Look up P' */
  real32_T LookupP_o2_e;               /* '<S45>/Look up P' */
  real32_T LookupRightVector_o1_o;     /* '<S46>/Look up Right Vector' */
  real32_T LookupRightVector_o2_h;     /* '<S46>/Look up Right Vector' */
  real32_T LookupP_o1_g;               /* '<S46>/Look up P' */
  real32_T LookupP_o2_f;               /* '<S46>/Look up P' */
  real32_T LookupRightVector_o1_p;     /* '<S47>/Look up Right Vector' */
  real32_T LookupRightVector_o2_ku;    /* '<S47>/Look up Right Vector' */
  real32_T LookupP_o1_l;               /* '<S47>/Look up P' */
  real32_T LookupP_o2_i;               /* '<S47>/Look up P' */
  real32_T LookupRightVector_o1_b;     /* '<S48>/Look up Right Vector' */
  real32_T LookupRightVector_o2_b;     /* '<S48>/Look up Right Vector' */
  real32_T LookupP_o1_ld;              /* '<S48>/Look up P' */
  real32_T LookupP_o2_nc;              /* '<S48>/Look up P' */
  real32_T LookupRightVector_o1_mi;    /* '<S49>/Look up Right Vector' */
  real32_T LookupRightVector_o2_l;     /* '<S49>/Look up Right Vector' */
  real32_T LookupP_o1_n;               /* '<S49>/Look up P' */
  real32_T LookupP_o2_k;               /* '<S49>/Look up P' */
  real32_T LookupRightVector_o1_l;     /* '<S50>/Look up Right Vector' */
  real32_T LookupRightVector_o2_c;     /* '<S50>/Look up Right Vector' */
  real32_T LookupP_o1_lw;              /* '<S50>/Look up P' */
  real32_T LookupP_o2_d;               /* '<S50>/Look up P' */
  real32_T OutportBufferForSerial[22]; /* '<S1>/Outputs' */
  real32_T DiscreteTimeIntegrator_l;   /* '<S22>/Discrete-Time Integrator' */
  real32_T Product1;                   /* '<S22>/Product1' */
  uint32_T DataTypeConversion1;        /* '<S37>/Data Type Conversion1' */
  uint16_T eTimerCNTRRegisterRead;     /* '<S28>/eTimer CNTR Register Read' */
  uint16_T CAN_Receive_data15_o4;      /* '<S29>/CAN_Receive_data15' */
  uint16_T CAN_Receive_data16_o4;      /* '<S29>/CAN_Receive_data16' */
  uint16_T CAN_Receive_data_o4;        /* '<S30>/CAN_Receive_data' */
  uint16_T CAN_Receive_data5_o4;       /* '<S30>/CAN_Receive_data5' */
  uint16_T CAN_Receive_data6_o4;       /* '<S30>/CAN_Receive_data6' */
  uint16_T CAN_Receive_data7_o4;       /* '<S30>/CAN_Receive_data7' */
  uint16_T CAN_Receive_data8_o4;       /* '<S30>/CAN_Receive_data8' */
  uint16_T CAN_Receive_data9_o4;       /* '<S30>/CAN_Receive_data9' */
  uint16_T CAN_Receive_data1_o4;       /* '<S30>/CAN_Receive_data1' */
  uint16_T CAN_Receive_data2_o4;       /* '<S30>/CAN_Receive_data2' */
  uint16_T CAN_Receive_data3_o4;       /* '<S30>/CAN_Receive_data3' */
  uint16_T CAN_Receive_data4_o4;       /* '<S30>/CAN_Receive_data4' */
  uint16_T CAN_Receive_data18_o4;      /* '<S31>/CAN_Receive_data18' */
  uint16_T CAN_Receive_data19_o4;      /* '<S31>/CAN_Receive_data19' */
  uint16_T ADCChannel;                 /* '<S27>/ADC Channel' */
  uint8_T CAN_Receive_data15_o1;       /* '<S29>/CAN_Receive_data15' */
  uint8_T CAN_Receive_data15_o2;       /* '<S29>/CAN_Receive_data15' */
  uint8_T CAN_Receive_data15_o3[8];    /* '<S29>/CAN_Receive_data15' */
  uint8_T CAN_Receive_data16_o1;       /* '<S29>/CAN_Receive_data16' */
  uint8_T CAN_Receive_data16_o2;       /* '<S29>/CAN_Receive_data16' */
  uint8_T CAN_Receive_data16_o3[8];    /* '<S29>/CAN_Receive_data16' */
  uint8_T CAN_Receive_data_o1;         /* '<S30>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o2;         /* '<S30>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o3[8];      /* '<S30>/CAN_Receive_data' */
  uint8_T CAN_Receive_data5_o1;        /* '<S30>/CAN_Receive_data5' */
  uint8_T CAN_Receive_data5_o2;        /* '<S30>/CAN_Receive_data5' */
  uint8_T CAN_Receive_data5_o3[8];     /* '<S30>/CAN_Receive_data5' */
  uint8_T CAN_Receive_data6_o1;        /* '<S30>/CAN_Receive_data6' */
  uint8_T CAN_Receive_data6_o2;        /* '<S30>/CAN_Receive_data6' */
  uint8_T CAN_Receive_data6_o3[8];     /* '<S30>/CAN_Receive_data6' */
  uint8_T CAN_Receive_data7_o1;        /* '<S30>/CAN_Receive_data7' */
  uint8_T CAN_Receive_data7_o2;        /* '<S30>/CAN_Receive_data7' */
  uint8_T CAN_Receive_data7_o3[8];     /* '<S30>/CAN_Receive_data7' */
  uint8_T CAN_Receive_data8_o1;        /* '<S30>/CAN_Receive_data8' */
  uint8_T CAN_Receive_data8_o2;        /* '<S30>/CAN_Receive_data8' */
  uint8_T CAN_Receive_data8_o3[8];     /* '<S30>/CAN_Receive_data8' */
  uint8_T CAN_Receive_data9_o1;        /* '<S30>/CAN_Receive_data9' */
  uint8_T CAN_Receive_data9_o2;        /* '<S30>/CAN_Receive_data9' */
  uint8_T CAN_Receive_data9_o3[8];     /* '<S30>/CAN_Receive_data9' */
  uint8_T CAN_Receive_data1_o1;        /* '<S30>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o2;        /* '<S30>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o3[8];     /* '<S30>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data2_o1;        /* '<S30>/CAN_Receive_data2' */
  uint8_T CAN_Receive_data2_o2;        /* '<S30>/CAN_Receive_data2' */
  uint8_T CAN_Receive_data2_o3[8];     /* '<S30>/CAN_Receive_data2' */
  uint8_T CAN_Receive_data3_o1;        /* '<S30>/CAN_Receive_data3' */
  uint8_T CAN_Receive_data3_o2;        /* '<S30>/CAN_Receive_data3' */
  uint8_T CAN_Receive_data3_o3[8];     /* '<S30>/CAN_Receive_data3' */
  uint8_T CAN_Receive_data4_o1;        /* '<S30>/CAN_Receive_data4' */
  uint8_T CAN_Receive_data4_o2;        /* '<S30>/CAN_Receive_data4' */
  uint8_T CAN_Receive_data4_o3[8];     /* '<S30>/CAN_Receive_data4' */
  uint8_T CAN_Receive_data18_o1;       /* '<S31>/CAN_Receive_data18' */
  uint8_T CAN_Receive_data18_o2;       /* '<S31>/CAN_Receive_data18' */
  uint8_T CAN_Receive_data18_o3[8];    /* '<S31>/CAN_Receive_data18' */
  uint8_T CAN_Receive_data19_o1;       /* '<S31>/CAN_Receive_data19' */
  uint8_T CAN_Receive_data19_o2;       /* '<S31>/CAN_Receive_data19' */
  uint8_T CAN_Receive_data19_o3[8];    /* '<S31>/CAN_Receive_data19' */
  uint8_T SingletoBytes[4];            /* '<S36>/Single to Bytes' */
  uint8_T SingletoBytes1[4];           /* '<S36>/Single to Bytes1' */
  uint8_T TmpSignalConversionAtCANTransmi[8];
  uint8_T SingletoBytes3[4];           /* '<S36>/Single to Bytes3' */
  uint8_T SingletoBytes2[4];           /* '<S36>/Single to Bytes2' */
  uint8_T TmpSignalConversionAtCANTrans_i[8];
  uint8_T SingletoBytes_j[4];          /* '<S3>/Single to Bytes' */
  uint8_T SingletoBytes1_o[4];         /* '<S3>/Single to Bytes1' */
  uint8_T SingletoBytes2_n[4];         /* '<S3>/Single to Bytes2' */
  uint8_T SingletoBytes3_e[4];         /* '<S3>/Single to Bytes3' */
  uint8_T SingletoBytes4[4];           /* '<S3>/Single to Bytes4' */
  uint8_T SingletoBytes5[4];           /* '<S3>/Single to Bytes5' */
  uint8_T SingletoBytes6[4];           /* '<S3>/Single to Bytes6' */
  uint8_T SingletoBytes7[4];           /* '<S3>/Single to Bytes7' */
  uint8_T SingletoBytes8[4];           /* '<S3>/Single to Bytes8' */
  uint8_T SingletoBytes9[4];           /* '<S3>/Single to Bytes9' */
  uint8_T SingletoBytes10[4];          /* '<S3>/Single to Bytes10' */
  uint8_T SingletoBytes11[4];          /* '<S3>/Single to Bytes11' */
  uint8_T SingletoBytes12[4];          /* '<S3>/Single to Bytes12' */
  uint8_T SingletoBytes13[4];          /* '<S3>/Single to Bytes13' */
  uint8_T SingletoBytes14[4];          /* '<S3>/Single to Bytes14' */
  uint8_T SingletoBytes15[4];          /* '<S3>/Single to Bytes15' */
  uint8_T SingletoBytes16[4];          /* '<S3>/Single to Bytes16' */
  uint8_T SingletoBytes17[4];          /* '<S3>/Single to Bytes17' */
  uint8_T SingletoBytes18[4];          /* '<S3>/Single to Bytes18' */
  uint8_T SingletoBytes19[4];          /* '<S3>/Single to Bytes19' */
  uint8_T SingletoBytes20[4];          /* '<S3>/Single to Bytes20' */
  uint8_T SingletoBytes21[4];          /* '<S3>/Single to Bytes21' */
  uint8_T IndexVector;                 /* '<S51>/Index Vector' */
  boolean_T DigitalInput;              /* '<S7>/Digital Input' */
  boolean_T DigitalInput1;             /* '<S26>/Digital Input1' */
  boolean_T DigitalInput2;             /* '<S26>/Digital Input2' */
  boolean_T DigitalInput3;             /* '<S26>/Digital Input3' */
  boolean_T DigitalInput4;             /* '<S26>/Digital Input4' */
  boolean_T DigitalInput5;             /* '<S26>/Digital Input5' */
  boolean_T DigitalInput6;             /* '<S26>/Digital Input6' */
  boolean_T DigitalInput7;             /* '<S26>/Digital Input7' */
  boolean_T DigitalInput8;             /* '<S26>/Digital Input8' */
  boolean_T DigitalInput1_k;           /* '<S7>/Digital Input1' */
  boolean_T SFunctionBuilder_o1_e;     /* '<S16>/S-Function Builder' */
  boolean_T SFunctionBuilder_o2_i;     /* '<S16>/S-Function Builder' */
  boolean_T SFunctionBuilder_o3_l;     /* '<S16>/S-Function Builder' */
} B_Final_project_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Controller_DSTATE;            /* '<S10>/Controller' */
  real32_T Delay1_DSTATE;              /* '<S33>/Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S4>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S4>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S4>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S4>/Discrete-Time Integrator3' */
  real32_T UnitDelay_DSTATE;           /* '<S13>/Unit Delay' */
  real32_T Delay_DSTATE[4];            /* '<S1>/Delay' */
  real32_T UD_DSTATE;                  /* '<S23>/UD' */
  real32_T UD_DSTATE_n;                /* '<S24>/UD' */
  real32_T DiscreteTimeIntegrator_DSTATE_d;/* '<S22>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_d;         /* '<S21>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S4>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_PREV_U;/* '<S4>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_PREV_U;/* '<S4>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3_PREV_U;/* '<S4>/Discrete-Time Integrator3' */
  real32_T DiscreteTimeIntegrator_PREV_U_k;/* '<S22>/Discrete-Time Integrator' */
  uint32_T HighLevelDesign_ELAPS_T;    /* '<Root>/High Level Design' */
  uint32_T HighLevelDesign_PREV_T;     /* '<Root>/High Level Design' */
  uint32_T Controller_ELAPS_T;         /* '<S6>/Controller' */
  uint32_T Controller_PREV_T;          /* '<S6>/Controller' */
  uint16_T Delay_DSTATE_p;             /* '<S33>/Delay' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S4>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_SYSTEM_;/* '<S4>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator2_SYSTEM_;/* '<S4>/Discrete-Time Integrator2' */
  uint8_T DiscreteTimeIntegrator3_SYSTEM_;/* '<S4>/Discrete-Time Integrator3' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_k;/* '<S22>/Discrete-Time Integrator' */
  boolean_T HighLevelDesign_RESET_ELAPS_T;/* '<Root>/High Level Design' */
  boolean_T Controller_RESET_ELAPS_T;  /* '<S6>/Controller' */
  boolean_T Controller_MODE;           /* '<S6>/Controller' */
} DW_Final_project_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: H)
   * Referenced by:
   *   '<S5>/Constant'
   *   '<S16>/Constant'
   */
  real_T pooled9;
} ConstP_Final_project_T;

/* Real-time Model Data Structure */
struct tag_RTM_Final_project_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals (auto storage) */
extern B_Final_project_T Final_project_B;

/* Block states (auto storage) */
extern DW_Final_project_T Final_project_DW;

/* Constant parameters (auto storage) */
extern const ConstP_Final_project_T Final_project_ConstP;

/* External function called from main */
extern void Final_project_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Final_project_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Final_project_initialize(void);
extern void Final_project_step(int_T tid);
extern void Final_project_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Final_project_T *const Final_project_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Final_project'
 * '<S1>'   : 'Final_project/High Level Design'
 * '<S2>'   : 'Final_project/SC Filter'
 * '<S3>'   : 'Final_project/Serial'
 * '<S4>'   : 'Final_project/High Level Design/	Vehicle Model'
 * '<S5>'   : 'Final_project/High Level Design/Automatic Cruise Control'
 * '<S6>'   : 'Final_project/High Level Design/Automatic Steering'
 * '<S7>'   : 'Final_project/High Level Design/Inputs'
 * '<S8>'   : 'Final_project/High Level Design/Outputs'
 * '<S9>'   : 'Final_project/High Level Design/	Vehicle Model/Look up Forward Vector'
 * '<S10>'  : 'Final_project/High Level Design/	Vehicle Model/x,y to s,n'
 * '<S11>'  : 'Final_project/High Level Design/	Vehicle Model/x,y to s,n/Data Type Conversion Inherited'
 * '<S12>'  : 'Final_project/High Level Design/	Vehicle Model/x,y to s,n/Look up the Forward Vector'
 * '<S13>'  : 'Final_project/High Level Design/	Vehicle Model/x,y to s,n/My Discrete Integrator'
 * '<S14>'  : 'Final_project/High Level Design/	Vehicle Model/x,y to s,n/My Dot Product1'
 * '<S15>'  : 'Final_project/High Level Design/	Vehicle Model/x,y to s,n/My Dot Product2'
 * '<S16>'  : 'Final_project/High Level Design/Automatic Cruise Control/ACC State Logic'
 * '<S17>'  : 'Final_project/High Level Design/Automatic Cruise Control/Manual Fd'
 * '<S18>'  : 'Final_project/High Level Design/Automatic Cruise Control/Position Ctrl'
 * '<S19>'  : 'Final_project/High Level Design/Automatic Cruise Control/Speed Ctrl'
 * '<S20>'  : 'Final_project/High Level Design/Automatic Cruise Control/Speed Ctrl/PI'
 * '<S21>'  : 'Final_project/High Level Design/Automatic Cruise Control/Speed Ctrl/PI/My Discrete Integrator'
 * '<S22>'  : 'Final_project/High Level Design/Automatic Steering/Controller'
 * '<S23>'  : 'Final_project/High Level Design/Automatic Steering/Controller/Discrete Derivative'
 * '<S24>'  : 'Final_project/High Level Design/Automatic Steering/Controller/Discrete Derivative1'
 * '<S25>'  : 'Final_project/High Level Design/Inputs/Other Cars'
 * '<S26>'  : 'Final_project/High Level Design/Inputs/Select Speed (GPI 122-129)'
 * '<S27>'  : 'Final_project/High Level Design/Inputs/Throttle (Potentiometer)'
 * '<S28>'  : 'Final_project/High Level Design/Inputs/get wheel position'
 * '<S29>'  : 'Final_project/High Level Design/Inputs/Other Cars/ Car1'
 * '<S30>'  : 'Final_project/High Level Design/Inputs/Other Cars/Cars 2-5'
 * '<S31>'  : 'Final_project/High Level Design/Inputs/Other Cars/GSI Car'
 * '<S32>'  : 'Final_project/High Level Design/Inputs/Other Cars/Zeros (16)'
 * '<S33>'  : 'Final_project/High Level Design/Inputs/get wheel position/Counts to Radians'
 * '<S34>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi'
 * '<S35>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)'
 * '<S36>'  : 'Final_project/High Level Design/Outputs/Output s,n,psi,us'
 * '<S37>'  : 'Final_project/High Level Design/Outputs/write torque'
 * '<S38>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi/s,n to x,y'
 * '<S39>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi'
 * '<S40>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi1'
 * '<S41>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi2'
 * '<S42>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi3'
 * '<S43>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi4'
 * '<S44>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi5'
 * '<S45>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi/s,n to x,y'
 * '<S46>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi1/s,n to x,y'
 * '<S47>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi2/s,n to x,y'
 * '<S48>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi3/s,n to x,y'
 * '<S49>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi4/s,n to x,y'
 * '<S50>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi5/s,n to x,y'
 * '<S51>'  : 'Final_project/Serial/For Iterator Subsystem'
 */
#endif                                 /* RTW_HEADER_Final_project_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
