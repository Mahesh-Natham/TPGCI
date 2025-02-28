/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TPGCI_2.h
 *
 * Code generated for Simulink model 'TPGCI_2'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Feb 27 17:58:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef TPGCI_2_h_
#define TPGCI_2_h_
#ifndef TPGCI_2_COMMON_INCLUDES_
#define TPGCI_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* TPGCI_2_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<S2>/Moving RMS Exp' */
typedef struct {
  real_T rmsSquared;                   /* '<S2>/Moving RMS Exp' */
  boolean_T rmsSquared_not_empty;      /* '<S2>/Moving RMS Exp' */
} DW_MovingRMSExp;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_MovingRMSExp sf_MovingRMSExp_e;   /* '<S3>/Moving RMS Exp' */
  DW_MovingRMSExp sf_MovingRMSExp_h;   /* '<S2>/Moving RMS Exp' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE;            /* '<S98>/Integrator' */
  real_T Integrator_DSTATE_e;          /* '<S148>/Integrator' */
  real_T Filter_DSTATE;                /* '<S36>/Filter' */
  real_T Integrator_DSTATE_p;          /* '<S41>/Integrator' */
  real_T rmsSquared;                   /* '<S1>/Moving RMS Exp' */
  boolean_T rmsSquared_not_empty;      /* '<S1>/Moving RMS Exp' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Id_ref;                       /* '<Root>/Id_ref' */
  real_T Iq_ref;                       /* '<Root>/Iq_ref' */
  real_T VDC;                          /* '<Root>/VDC' */
  real_T Phase_dif;                    /* '<Root>/Phase_dif' */
  real_T Vd_FF;                        /* '<Root>/Vd_FF' */
  real_T CCRMAX;                       /* '<Root>/CCRMAX' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Id;                           /* '<Root>/Id' */
  real_T Iq;                           /* '<Root>/Iq' */
  real_T Ma;                           /* '<Root>/Ma' */
  real_T Mb;                           /* '<Root>/Mb' */
  real_T Mc;                           /* '<Root>/Mc' */
  real_T Vd_pid_out;                   /* '<Root>/Vd_pid_out' */
  real_T Id_pi_error;                  /* '<Root>/Id_pi_error' */
  real_T Id_pi_out;                    /* '<Root>/Id_pi_out' */
  real_T Id_pi_out2;                   /* '<Root>/Id_pi_out2' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void TPGCI_2_initialize(void);
extern void TPGCI_2_step(void);

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile real_T Grid_wt;        /* '<Root>/Grid_wt' */
extern volatile real_T PWMCH1;         /* '<Root>/PWMCH1' */
extern volatile real_T PWMCH2;         /* '<Root>/PWMCH2' */
extern volatile real_T PWMCH3;         /* '<Root>/PWMCH3' */
extern volatile real_T Vd_g;           /* '<Root>/Vd_g' */
extern volatile real_T ib;             /* '<Root>/ib' */
extern volatile real_T ir;             /* '<Root>/ir' */
extern volatile real_T iy;             /* '<Root>/iy' */
extern volatile real_T vb_g;           /* '<Root>/vb_g' */
extern volatile real_T vr_g;           /* '<Root>/vr_g' */
extern volatile real_T vy_g;           /* '<Root>/vy_g' */

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S95>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S145>/Integral Gain' : Eliminated nontunable gain of 1
 */

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
 * '<Root>' : 'TPGCI_2'
 * '<S1>'   : 'TPGCI_2/Phase locked loop'
 * '<S2>'   : 'TPGCI_2/Subsystem'
 * '<S3>'   : 'TPGCI_2/Subsystem1'
 * '<S4>'   : 'TPGCI_2/Phase locked loop/Moving RMS Exp'
 * '<S5>'   : 'TPGCI_2/Phase locked loop/PID Controller'
 * '<S6>'   : 'TPGCI_2/Phase locked loop/abc to &#x3B1;&#x3B2;'
 * '<S7>'   : 'TPGCI_2/Phase locked loop/&#x3B1;&#x3B2; to dq'
 * '<S8>'   : 'TPGCI_2/Phase locked loop/PID Controller/Anti-windup'
 * '<S9>'   : 'TPGCI_2/Phase locked loop/PID Controller/D Gain'
 * '<S10>'  : 'TPGCI_2/Phase locked loop/PID Controller/External Derivative'
 * '<S11>'  : 'TPGCI_2/Phase locked loop/PID Controller/Filter'
 * '<S12>'  : 'TPGCI_2/Phase locked loop/PID Controller/Filter ICs'
 * '<S13>'  : 'TPGCI_2/Phase locked loop/PID Controller/I Gain'
 * '<S14>'  : 'TPGCI_2/Phase locked loop/PID Controller/Ideal P Gain'
 * '<S15>'  : 'TPGCI_2/Phase locked loop/PID Controller/Ideal P Gain Fdbk'
 * '<S16>'  : 'TPGCI_2/Phase locked loop/PID Controller/Integrator'
 * '<S17>'  : 'TPGCI_2/Phase locked loop/PID Controller/Integrator ICs'
 * '<S18>'  : 'TPGCI_2/Phase locked loop/PID Controller/N Copy'
 * '<S19>'  : 'TPGCI_2/Phase locked loop/PID Controller/N Gain'
 * '<S20>'  : 'TPGCI_2/Phase locked loop/PID Controller/P Copy'
 * '<S21>'  : 'TPGCI_2/Phase locked loop/PID Controller/Parallel P Gain'
 * '<S22>'  : 'TPGCI_2/Phase locked loop/PID Controller/Reset Signal'
 * '<S23>'  : 'TPGCI_2/Phase locked loop/PID Controller/Saturation'
 * '<S24>'  : 'TPGCI_2/Phase locked loop/PID Controller/Saturation Fdbk'
 * '<S25>'  : 'TPGCI_2/Phase locked loop/PID Controller/Sum'
 * '<S26>'  : 'TPGCI_2/Phase locked loop/PID Controller/Sum Fdbk'
 * '<S27>'  : 'TPGCI_2/Phase locked loop/PID Controller/Tracking Mode'
 * '<S28>'  : 'TPGCI_2/Phase locked loop/PID Controller/Tracking Mode Sum'
 * '<S29>'  : 'TPGCI_2/Phase locked loop/PID Controller/Tsamp - Integral'
 * '<S30>'  : 'TPGCI_2/Phase locked loop/PID Controller/Tsamp - Ngain'
 * '<S31>'  : 'TPGCI_2/Phase locked loop/PID Controller/postSat Signal'
 * '<S32>'  : 'TPGCI_2/Phase locked loop/PID Controller/preSat Signal'
 * '<S33>'  : 'TPGCI_2/Phase locked loop/PID Controller/Anti-windup/Passthrough'
 * '<S34>'  : 'TPGCI_2/Phase locked loop/PID Controller/D Gain/Internal Parameters'
 * '<S35>'  : 'TPGCI_2/Phase locked loop/PID Controller/External Derivative/Error'
 * '<S36>'  : 'TPGCI_2/Phase locked loop/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S37>'  : 'TPGCI_2/Phase locked loop/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S38>'  : 'TPGCI_2/Phase locked loop/PID Controller/I Gain/Internal Parameters'
 * '<S39>'  : 'TPGCI_2/Phase locked loop/PID Controller/Ideal P Gain/Passthrough'
 * '<S40>'  : 'TPGCI_2/Phase locked loop/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'TPGCI_2/Phase locked loop/PID Controller/Integrator/Discrete'
 * '<S42>'  : 'TPGCI_2/Phase locked loop/PID Controller/Integrator ICs/Internal IC'
 * '<S43>'  : 'TPGCI_2/Phase locked loop/PID Controller/N Copy/Disabled'
 * '<S44>'  : 'TPGCI_2/Phase locked loop/PID Controller/N Gain/Internal Parameters'
 * '<S45>'  : 'TPGCI_2/Phase locked loop/PID Controller/P Copy/Disabled'
 * '<S46>'  : 'TPGCI_2/Phase locked loop/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'TPGCI_2/Phase locked loop/PID Controller/Reset Signal/Disabled'
 * '<S48>'  : 'TPGCI_2/Phase locked loop/PID Controller/Saturation/Passthrough'
 * '<S49>'  : 'TPGCI_2/Phase locked loop/PID Controller/Saturation Fdbk/Disabled'
 * '<S50>'  : 'TPGCI_2/Phase locked loop/PID Controller/Sum/Sum_PID'
 * '<S51>'  : 'TPGCI_2/Phase locked loop/PID Controller/Sum Fdbk/Disabled'
 * '<S52>'  : 'TPGCI_2/Phase locked loop/PID Controller/Tracking Mode/Disabled'
 * '<S53>'  : 'TPGCI_2/Phase locked loop/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'TPGCI_2/Phase locked loop/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S55>'  : 'TPGCI_2/Phase locked loop/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'TPGCI_2/Phase locked loop/PID Controller/postSat Signal/Forward_Path'
 * '<S57>'  : 'TPGCI_2/Phase locked loop/PID Controller/preSat Signal/Forward_Path'
 * '<S58>'  : 'TPGCI_2/Subsystem/Moving RMS Exp'
 * '<S59>'  : 'TPGCI_2/Subsystem/abc to &#x3B1;&#x3B2;'
 * '<S60>'  : 'TPGCI_2/Subsystem/&#x3B1;&#x3B2; to dq'
 * '<S61>'  : 'TPGCI_2/Subsystem1/Moving RMS Exp'
 * '<S62>'  : 'TPGCI_2/Subsystem1/PID Controller1'
 * '<S63>'  : 'TPGCI_2/Subsystem1/PID Controller2'
 * '<S64>'  : 'TPGCI_2/Subsystem1/dq to abc'
 * '<S65>'  : 'TPGCI_2/Subsystem1/PID Controller1/Anti-windup'
 * '<S66>'  : 'TPGCI_2/Subsystem1/PID Controller1/D Gain'
 * '<S67>'  : 'TPGCI_2/Subsystem1/PID Controller1/External Derivative'
 * '<S68>'  : 'TPGCI_2/Subsystem1/PID Controller1/Filter'
 * '<S69>'  : 'TPGCI_2/Subsystem1/PID Controller1/Filter ICs'
 * '<S70>'  : 'TPGCI_2/Subsystem1/PID Controller1/I Gain'
 * '<S71>'  : 'TPGCI_2/Subsystem1/PID Controller1/Ideal P Gain'
 * '<S72>'  : 'TPGCI_2/Subsystem1/PID Controller1/Ideal P Gain Fdbk'
 * '<S73>'  : 'TPGCI_2/Subsystem1/PID Controller1/Integrator'
 * '<S74>'  : 'TPGCI_2/Subsystem1/PID Controller1/Integrator ICs'
 * '<S75>'  : 'TPGCI_2/Subsystem1/PID Controller1/N Copy'
 * '<S76>'  : 'TPGCI_2/Subsystem1/PID Controller1/N Gain'
 * '<S77>'  : 'TPGCI_2/Subsystem1/PID Controller1/P Copy'
 * '<S78>'  : 'TPGCI_2/Subsystem1/PID Controller1/Parallel P Gain'
 * '<S79>'  : 'TPGCI_2/Subsystem1/PID Controller1/Reset Signal'
 * '<S80>'  : 'TPGCI_2/Subsystem1/PID Controller1/Saturation'
 * '<S81>'  : 'TPGCI_2/Subsystem1/PID Controller1/Saturation Fdbk'
 * '<S82>'  : 'TPGCI_2/Subsystem1/PID Controller1/Sum'
 * '<S83>'  : 'TPGCI_2/Subsystem1/PID Controller1/Sum Fdbk'
 * '<S84>'  : 'TPGCI_2/Subsystem1/PID Controller1/Tracking Mode'
 * '<S85>'  : 'TPGCI_2/Subsystem1/PID Controller1/Tracking Mode Sum'
 * '<S86>'  : 'TPGCI_2/Subsystem1/PID Controller1/Tsamp - Integral'
 * '<S87>'  : 'TPGCI_2/Subsystem1/PID Controller1/Tsamp - Ngain'
 * '<S88>'  : 'TPGCI_2/Subsystem1/PID Controller1/postSat Signal'
 * '<S89>'  : 'TPGCI_2/Subsystem1/PID Controller1/preSat Signal'
 * '<S90>'  : 'TPGCI_2/Subsystem1/PID Controller1/Anti-windup/Passthrough'
 * '<S91>'  : 'TPGCI_2/Subsystem1/PID Controller1/D Gain/Disabled'
 * '<S92>'  : 'TPGCI_2/Subsystem1/PID Controller1/External Derivative/Disabled'
 * '<S93>'  : 'TPGCI_2/Subsystem1/PID Controller1/Filter/Disabled'
 * '<S94>'  : 'TPGCI_2/Subsystem1/PID Controller1/Filter ICs/Disabled'
 * '<S95>'  : 'TPGCI_2/Subsystem1/PID Controller1/I Gain/Internal Parameters'
 * '<S96>'  : 'TPGCI_2/Subsystem1/PID Controller1/Ideal P Gain/Passthrough'
 * '<S97>'  : 'TPGCI_2/Subsystem1/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S98>'  : 'TPGCI_2/Subsystem1/PID Controller1/Integrator/Discrete'
 * '<S99>'  : 'TPGCI_2/Subsystem1/PID Controller1/Integrator ICs/Internal IC'
 * '<S100>' : 'TPGCI_2/Subsystem1/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S101>' : 'TPGCI_2/Subsystem1/PID Controller1/N Gain/Disabled'
 * '<S102>' : 'TPGCI_2/Subsystem1/PID Controller1/P Copy/Disabled'
 * '<S103>' : 'TPGCI_2/Subsystem1/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S104>' : 'TPGCI_2/Subsystem1/PID Controller1/Reset Signal/Disabled'
 * '<S105>' : 'TPGCI_2/Subsystem1/PID Controller1/Saturation/Enabled'
 * '<S106>' : 'TPGCI_2/Subsystem1/PID Controller1/Saturation Fdbk/Disabled'
 * '<S107>' : 'TPGCI_2/Subsystem1/PID Controller1/Sum/Sum_PI'
 * '<S108>' : 'TPGCI_2/Subsystem1/PID Controller1/Sum Fdbk/Disabled'
 * '<S109>' : 'TPGCI_2/Subsystem1/PID Controller1/Tracking Mode/Disabled'
 * '<S110>' : 'TPGCI_2/Subsystem1/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S111>' : 'TPGCI_2/Subsystem1/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S112>' : 'TPGCI_2/Subsystem1/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S113>' : 'TPGCI_2/Subsystem1/PID Controller1/postSat Signal/Forward_Path'
 * '<S114>' : 'TPGCI_2/Subsystem1/PID Controller1/preSat Signal/Forward_Path'
 * '<S115>' : 'TPGCI_2/Subsystem1/PID Controller2/Anti-windup'
 * '<S116>' : 'TPGCI_2/Subsystem1/PID Controller2/D Gain'
 * '<S117>' : 'TPGCI_2/Subsystem1/PID Controller2/External Derivative'
 * '<S118>' : 'TPGCI_2/Subsystem1/PID Controller2/Filter'
 * '<S119>' : 'TPGCI_2/Subsystem1/PID Controller2/Filter ICs'
 * '<S120>' : 'TPGCI_2/Subsystem1/PID Controller2/I Gain'
 * '<S121>' : 'TPGCI_2/Subsystem1/PID Controller2/Ideal P Gain'
 * '<S122>' : 'TPGCI_2/Subsystem1/PID Controller2/Ideal P Gain Fdbk'
 * '<S123>' : 'TPGCI_2/Subsystem1/PID Controller2/Integrator'
 * '<S124>' : 'TPGCI_2/Subsystem1/PID Controller2/Integrator ICs'
 * '<S125>' : 'TPGCI_2/Subsystem1/PID Controller2/N Copy'
 * '<S126>' : 'TPGCI_2/Subsystem1/PID Controller2/N Gain'
 * '<S127>' : 'TPGCI_2/Subsystem1/PID Controller2/P Copy'
 * '<S128>' : 'TPGCI_2/Subsystem1/PID Controller2/Parallel P Gain'
 * '<S129>' : 'TPGCI_2/Subsystem1/PID Controller2/Reset Signal'
 * '<S130>' : 'TPGCI_2/Subsystem1/PID Controller2/Saturation'
 * '<S131>' : 'TPGCI_2/Subsystem1/PID Controller2/Saturation Fdbk'
 * '<S132>' : 'TPGCI_2/Subsystem1/PID Controller2/Sum'
 * '<S133>' : 'TPGCI_2/Subsystem1/PID Controller2/Sum Fdbk'
 * '<S134>' : 'TPGCI_2/Subsystem1/PID Controller2/Tracking Mode'
 * '<S135>' : 'TPGCI_2/Subsystem1/PID Controller2/Tracking Mode Sum'
 * '<S136>' : 'TPGCI_2/Subsystem1/PID Controller2/Tsamp - Integral'
 * '<S137>' : 'TPGCI_2/Subsystem1/PID Controller2/Tsamp - Ngain'
 * '<S138>' : 'TPGCI_2/Subsystem1/PID Controller2/postSat Signal'
 * '<S139>' : 'TPGCI_2/Subsystem1/PID Controller2/preSat Signal'
 * '<S140>' : 'TPGCI_2/Subsystem1/PID Controller2/Anti-windup/Passthrough'
 * '<S141>' : 'TPGCI_2/Subsystem1/PID Controller2/D Gain/Disabled'
 * '<S142>' : 'TPGCI_2/Subsystem1/PID Controller2/External Derivative/Disabled'
 * '<S143>' : 'TPGCI_2/Subsystem1/PID Controller2/Filter/Disabled'
 * '<S144>' : 'TPGCI_2/Subsystem1/PID Controller2/Filter ICs/Disabled'
 * '<S145>' : 'TPGCI_2/Subsystem1/PID Controller2/I Gain/Internal Parameters'
 * '<S146>' : 'TPGCI_2/Subsystem1/PID Controller2/Ideal P Gain/Passthrough'
 * '<S147>' : 'TPGCI_2/Subsystem1/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S148>' : 'TPGCI_2/Subsystem1/PID Controller2/Integrator/Discrete'
 * '<S149>' : 'TPGCI_2/Subsystem1/PID Controller2/Integrator ICs/Internal IC'
 * '<S150>' : 'TPGCI_2/Subsystem1/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S151>' : 'TPGCI_2/Subsystem1/PID Controller2/N Gain/Disabled'
 * '<S152>' : 'TPGCI_2/Subsystem1/PID Controller2/P Copy/Disabled'
 * '<S153>' : 'TPGCI_2/Subsystem1/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S154>' : 'TPGCI_2/Subsystem1/PID Controller2/Reset Signal/Disabled'
 * '<S155>' : 'TPGCI_2/Subsystem1/PID Controller2/Saturation/Enabled'
 * '<S156>' : 'TPGCI_2/Subsystem1/PID Controller2/Saturation Fdbk/Disabled'
 * '<S157>' : 'TPGCI_2/Subsystem1/PID Controller2/Sum/Sum_PI'
 * '<S158>' : 'TPGCI_2/Subsystem1/PID Controller2/Sum Fdbk/Disabled'
 * '<S159>' : 'TPGCI_2/Subsystem1/PID Controller2/Tracking Mode/Disabled'
 * '<S160>' : 'TPGCI_2/Subsystem1/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S161>' : 'TPGCI_2/Subsystem1/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S162>' : 'TPGCI_2/Subsystem1/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S163>' : 'TPGCI_2/Subsystem1/PID Controller2/postSat Signal/Forward_Path'
 * '<S164>' : 'TPGCI_2/Subsystem1/PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* TPGCI_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
