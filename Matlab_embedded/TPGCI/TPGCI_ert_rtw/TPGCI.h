/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TPGCI.h
 *
 * Code generated for Simulink model 'TPGCI'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Feb 23 17:53:21 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef TPGCI_h_
#define TPGCI_h_
#ifndef TPGCI_COMMON_INCLUDES_
#define TPGCI_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* TPGCI_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE;            /* '<S97>/Integrator' */
  real_T Integrator_DSTATE_l;          /* '<S147>/Integrator' */
  real_T Filter_DSTATE;                /* '<S36>/Filter' */
  real_T Integrator_DSTATE_m;          /* '<S41>/Integrator' */
  real_T rmsSquared;                   /* '<S2>/Moving RMS Exp' */
  real_T rmsSquared_f;                 /* '<S1>/Moving RMS Exp' */
  boolean_T rmsSquared_not_empty;      /* '<S2>/Moving RMS Exp' */
  boolean_T rmsSquared_not_empty_p;    /* '<S1>/Moving RMS Exp' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Id_ref;                       /* '<Root>/Id_ref' */
  real_T Iq_ref;                       /* '<Root>/Iq_ref' */
  real_T VDC;                          /* '<Root>/VDC' */
  real_T CCR_Max;                      /* '<Root>/CCR_Max' */
  real_T Vd_g_max;                     /* '<Root>/Vd_g_max' */
  real_T Vd_g_min;                     /* '<Root>/Vd_g_min' */
  real_T Id_g_max;                     /* '<Root>/Id_g_max' */
  real_T Phase_dif;                    /* '<Root>/Phase_dif' */
  real_T Vd_FF;                        /* '<Root>/Vd_FF' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Vd_pid_out;                   /* '<Root>/Vd_pid_out' */
  boolean_T OV_check;                  /* '<Root>/OV_check' */
  boolean_T UV_check;                  /* '<Root>/UV_check' */
  boolean_T OI_check;                  /* '<Root>/OI_check' */
  boolean_T GridCheck;                 /* '<Root>/GridCheck' */
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
extern void TPGCI_initialize(void);
extern void TPGCI_step(void);

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile real_T Grid_wt;        /* '<Root>/Grid_wt' */
extern volatile real_T Id;             /* '<Root>/Id' */
extern volatile real_T Iq;             /* '<Root>/Iq' */
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
 * Block '<S94>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S144>/Integral Gain' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'TPGCI'
 * '<S1>'   : 'TPGCI/Phase locked loop'
 * '<S2>'   : 'TPGCI/Subsystem'
 * '<S3>'   : 'TPGCI/Subsystem1'
 * '<S4>'   : 'TPGCI/Phase locked loop/Moving RMS Exp'
 * '<S5>'   : 'TPGCI/Phase locked loop/PID Controller'
 * '<S6>'   : 'TPGCI/Phase locked loop/abc to &#x3B1;&#x3B2;'
 * '<S7>'   : 'TPGCI/Phase locked loop/&#x3B1;&#x3B2; to dq'
 * '<S8>'   : 'TPGCI/Phase locked loop/PID Controller/Anti-windup'
 * '<S9>'   : 'TPGCI/Phase locked loop/PID Controller/D Gain'
 * '<S10>'  : 'TPGCI/Phase locked loop/PID Controller/External Derivative'
 * '<S11>'  : 'TPGCI/Phase locked loop/PID Controller/Filter'
 * '<S12>'  : 'TPGCI/Phase locked loop/PID Controller/Filter ICs'
 * '<S13>'  : 'TPGCI/Phase locked loop/PID Controller/I Gain'
 * '<S14>'  : 'TPGCI/Phase locked loop/PID Controller/Ideal P Gain'
 * '<S15>'  : 'TPGCI/Phase locked loop/PID Controller/Ideal P Gain Fdbk'
 * '<S16>'  : 'TPGCI/Phase locked loop/PID Controller/Integrator'
 * '<S17>'  : 'TPGCI/Phase locked loop/PID Controller/Integrator ICs'
 * '<S18>'  : 'TPGCI/Phase locked loop/PID Controller/N Copy'
 * '<S19>'  : 'TPGCI/Phase locked loop/PID Controller/N Gain'
 * '<S20>'  : 'TPGCI/Phase locked loop/PID Controller/P Copy'
 * '<S21>'  : 'TPGCI/Phase locked loop/PID Controller/Parallel P Gain'
 * '<S22>'  : 'TPGCI/Phase locked loop/PID Controller/Reset Signal'
 * '<S23>'  : 'TPGCI/Phase locked loop/PID Controller/Saturation'
 * '<S24>'  : 'TPGCI/Phase locked loop/PID Controller/Saturation Fdbk'
 * '<S25>'  : 'TPGCI/Phase locked loop/PID Controller/Sum'
 * '<S26>'  : 'TPGCI/Phase locked loop/PID Controller/Sum Fdbk'
 * '<S27>'  : 'TPGCI/Phase locked loop/PID Controller/Tracking Mode'
 * '<S28>'  : 'TPGCI/Phase locked loop/PID Controller/Tracking Mode Sum'
 * '<S29>'  : 'TPGCI/Phase locked loop/PID Controller/Tsamp - Integral'
 * '<S30>'  : 'TPGCI/Phase locked loop/PID Controller/Tsamp - Ngain'
 * '<S31>'  : 'TPGCI/Phase locked loop/PID Controller/postSat Signal'
 * '<S32>'  : 'TPGCI/Phase locked loop/PID Controller/preSat Signal'
 * '<S33>'  : 'TPGCI/Phase locked loop/PID Controller/Anti-windup/Passthrough'
 * '<S34>'  : 'TPGCI/Phase locked loop/PID Controller/D Gain/Internal Parameters'
 * '<S35>'  : 'TPGCI/Phase locked loop/PID Controller/External Derivative/Error'
 * '<S36>'  : 'TPGCI/Phase locked loop/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S37>'  : 'TPGCI/Phase locked loop/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S38>'  : 'TPGCI/Phase locked loop/PID Controller/I Gain/Internal Parameters'
 * '<S39>'  : 'TPGCI/Phase locked loop/PID Controller/Ideal P Gain/Passthrough'
 * '<S40>'  : 'TPGCI/Phase locked loop/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'TPGCI/Phase locked loop/PID Controller/Integrator/Discrete'
 * '<S42>'  : 'TPGCI/Phase locked loop/PID Controller/Integrator ICs/Internal IC'
 * '<S43>'  : 'TPGCI/Phase locked loop/PID Controller/N Copy/Disabled'
 * '<S44>'  : 'TPGCI/Phase locked loop/PID Controller/N Gain/Internal Parameters'
 * '<S45>'  : 'TPGCI/Phase locked loop/PID Controller/P Copy/Disabled'
 * '<S46>'  : 'TPGCI/Phase locked loop/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'TPGCI/Phase locked loop/PID Controller/Reset Signal/Disabled'
 * '<S48>'  : 'TPGCI/Phase locked loop/PID Controller/Saturation/Passthrough'
 * '<S49>'  : 'TPGCI/Phase locked loop/PID Controller/Saturation Fdbk/Disabled'
 * '<S50>'  : 'TPGCI/Phase locked loop/PID Controller/Sum/Sum_PID'
 * '<S51>'  : 'TPGCI/Phase locked loop/PID Controller/Sum Fdbk/Disabled'
 * '<S52>'  : 'TPGCI/Phase locked loop/PID Controller/Tracking Mode/Disabled'
 * '<S53>'  : 'TPGCI/Phase locked loop/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'TPGCI/Phase locked loop/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S55>'  : 'TPGCI/Phase locked loop/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'TPGCI/Phase locked loop/PID Controller/postSat Signal/Forward_Path'
 * '<S57>'  : 'TPGCI/Phase locked loop/PID Controller/preSat Signal/Forward_Path'
 * '<S58>'  : 'TPGCI/Subsystem/Moving RMS Exp'
 * '<S59>'  : 'TPGCI/Subsystem/abc to &#x3B1;&#x3B2;'
 * '<S60>'  : 'TPGCI/Subsystem/&#x3B1;&#x3B2; to dq'
 * '<S61>'  : 'TPGCI/Subsystem1/PID Controller1'
 * '<S62>'  : 'TPGCI/Subsystem1/PID Controller2'
 * '<S63>'  : 'TPGCI/Subsystem1/dq to abc'
 * '<S64>'  : 'TPGCI/Subsystem1/PID Controller1/Anti-windup'
 * '<S65>'  : 'TPGCI/Subsystem1/PID Controller1/D Gain'
 * '<S66>'  : 'TPGCI/Subsystem1/PID Controller1/External Derivative'
 * '<S67>'  : 'TPGCI/Subsystem1/PID Controller1/Filter'
 * '<S68>'  : 'TPGCI/Subsystem1/PID Controller1/Filter ICs'
 * '<S69>'  : 'TPGCI/Subsystem1/PID Controller1/I Gain'
 * '<S70>'  : 'TPGCI/Subsystem1/PID Controller1/Ideal P Gain'
 * '<S71>'  : 'TPGCI/Subsystem1/PID Controller1/Ideal P Gain Fdbk'
 * '<S72>'  : 'TPGCI/Subsystem1/PID Controller1/Integrator'
 * '<S73>'  : 'TPGCI/Subsystem1/PID Controller1/Integrator ICs'
 * '<S74>'  : 'TPGCI/Subsystem1/PID Controller1/N Copy'
 * '<S75>'  : 'TPGCI/Subsystem1/PID Controller1/N Gain'
 * '<S76>'  : 'TPGCI/Subsystem1/PID Controller1/P Copy'
 * '<S77>'  : 'TPGCI/Subsystem1/PID Controller1/Parallel P Gain'
 * '<S78>'  : 'TPGCI/Subsystem1/PID Controller1/Reset Signal'
 * '<S79>'  : 'TPGCI/Subsystem1/PID Controller1/Saturation'
 * '<S80>'  : 'TPGCI/Subsystem1/PID Controller1/Saturation Fdbk'
 * '<S81>'  : 'TPGCI/Subsystem1/PID Controller1/Sum'
 * '<S82>'  : 'TPGCI/Subsystem1/PID Controller1/Sum Fdbk'
 * '<S83>'  : 'TPGCI/Subsystem1/PID Controller1/Tracking Mode'
 * '<S84>'  : 'TPGCI/Subsystem1/PID Controller1/Tracking Mode Sum'
 * '<S85>'  : 'TPGCI/Subsystem1/PID Controller1/Tsamp - Integral'
 * '<S86>'  : 'TPGCI/Subsystem1/PID Controller1/Tsamp - Ngain'
 * '<S87>'  : 'TPGCI/Subsystem1/PID Controller1/postSat Signal'
 * '<S88>'  : 'TPGCI/Subsystem1/PID Controller1/preSat Signal'
 * '<S89>'  : 'TPGCI/Subsystem1/PID Controller1/Anti-windup/Passthrough'
 * '<S90>'  : 'TPGCI/Subsystem1/PID Controller1/D Gain/Disabled'
 * '<S91>'  : 'TPGCI/Subsystem1/PID Controller1/External Derivative/Disabled'
 * '<S92>'  : 'TPGCI/Subsystem1/PID Controller1/Filter/Disabled'
 * '<S93>'  : 'TPGCI/Subsystem1/PID Controller1/Filter ICs/Disabled'
 * '<S94>'  : 'TPGCI/Subsystem1/PID Controller1/I Gain/Internal Parameters'
 * '<S95>'  : 'TPGCI/Subsystem1/PID Controller1/Ideal P Gain/Passthrough'
 * '<S96>'  : 'TPGCI/Subsystem1/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S97>'  : 'TPGCI/Subsystem1/PID Controller1/Integrator/Discrete'
 * '<S98>'  : 'TPGCI/Subsystem1/PID Controller1/Integrator ICs/Internal IC'
 * '<S99>'  : 'TPGCI/Subsystem1/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S100>' : 'TPGCI/Subsystem1/PID Controller1/N Gain/Disabled'
 * '<S101>' : 'TPGCI/Subsystem1/PID Controller1/P Copy/Disabled'
 * '<S102>' : 'TPGCI/Subsystem1/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S103>' : 'TPGCI/Subsystem1/PID Controller1/Reset Signal/Disabled'
 * '<S104>' : 'TPGCI/Subsystem1/PID Controller1/Saturation/Enabled'
 * '<S105>' : 'TPGCI/Subsystem1/PID Controller1/Saturation Fdbk/Disabled'
 * '<S106>' : 'TPGCI/Subsystem1/PID Controller1/Sum/Sum_PI'
 * '<S107>' : 'TPGCI/Subsystem1/PID Controller1/Sum Fdbk/Disabled'
 * '<S108>' : 'TPGCI/Subsystem1/PID Controller1/Tracking Mode/Disabled'
 * '<S109>' : 'TPGCI/Subsystem1/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S110>' : 'TPGCI/Subsystem1/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S111>' : 'TPGCI/Subsystem1/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S112>' : 'TPGCI/Subsystem1/PID Controller1/postSat Signal/Forward_Path'
 * '<S113>' : 'TPGCI/Subsystem1/PID Controller1/preSat Signal/Forward_Path'
 * '<S114>' : 'TPGCI/Subsystem1/PID Controller2/Anti-windup'
 * '<S115>' : 'TPGCI/Subsystem1/PID Controller2/D Gain'
 * '<S116>' : 'TPGCI/Subsystem1/PID Controller2/External Derivative'
 * '<S117>' : 'TPGCI/Subsystem1/PID Controller2/Filter'
 * '<S118>' : 'TPGCI/Subsystem1/PID Controller2/Filter ICs'
 * '<S119>' : 'TPGCI/Subsystem1/PID Controller2/I Gain'
 * '<S120>' : 'TPGCI/Subsystem1/PID Controller2/Ideal P Gain'
 * '<S121>' : 'TPGCI/Subsystem1/PID Controller2/Ideal P Gain Fdbk'
 * '<S122>' : 'TPGCI/Subsystem1/PID Controller2/Integrator'
 * '<S123>' : 'TPGCI/Subsystem1/PID Controller2/Integrator ICs'
 * '<S124>' : 'TPGCI/Subsystem1/PID Controller2/N Copy'
 * '<S125>' : 'TPGCI/Subsystem1/PID Controller2/N Gain'
 * '<S126>' : 'TPGCI/Subsystem1/PID Controller2/P Copy'
 * '<S127>' : 'TPGCI/Subsystem1/PID Controller2/Parallel P Gain'
 * '<S128>' : 'TPGCI/Subsystem1/PID Controller2/Reset Signal'
 * '<S129>' : 'TPGCI/Subsystem1/PID Controller2/Saturation'
 * '<S130>' : 'TPGCI/Subsystem1/PID Controller2/Saturation Fdbk'
 * '<S131>' : 'TPGCI/Subsystem1/PID Controller2/Sum'
 * '<S132>' : 'TPGCI/Subsystem1/PID Controller2/Sum Fdbk'
 * '<S133>' : 'TPGCI/Subsystem1/PID Controller2/Tracking Mode'
 * '<S134>' : 'TPGCI/Subsystem1/PID Controller2/Tracking Mode Sum'
 * '<S135>' : 'TPGCI/Subsystem1/PID Controller2/Tsamp - Integral'
 * '<S136>' : 'TPGCI/Subsystem1/PID Controller2/Tsamp - Ngain'
 * '<S137>' : 'TPGCI/Subsystem1/PID Controller2/postSat Signal'
 * '<S138>' : 'TPGCI/Subsystem1/PID Controller2/preSat Signal'
 * '<S139>' : 'TPGCI/Subsystem1/PID Controller2/Anti-windup/Passthrough'
 * '<S140>' : 'TPGCI/Subsystem1/PID Controller2/D Gain/Disabled'
 * '<S141>' : 'TPGCI/Subsystem1/PID Controller2/External Derivative/Disabled'
 * '<S142>' : 'TPGCI/Subsystem1/PID Controller2/Filter/Disabled'
 * '<S143>' : 'TPGCI/Subsystem1/PID Controller2/Filter ICs/Disabled'
 * '<S144>' : 'TPGCI/Subsystem1/PID Controller2/I Gain/Internal Parameters'
 * '<S145>' : 'TPGCI/Subsystem1/PID Controller2/Ideal P Gain/Passthrough'
 * '<S146>' : 'TPGCI/Subsystem1/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S147>' : 'TPGCI/Subsystem1/PID Controller2/Integrator/Discrete'
 * '<S148>' : 'TPGCI/Subsystem1/PID Controller2/Integrator ICs/Internal IC'
 * '<S149>' : 'TPGCI/Subsystem1/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S150>' : 'TPGCI/Subsystem1/PID Controller2/N Gain/Disabled'
 * '<S151>' : 'TPGCI/Subsystem1/PID Controller2/P Copy/Disabled'
 * '<S152>' : 'TPGCI/Subsystem1/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S153>' : 'TPGCI/Subsystem1/PID Controller2/Reset Signal/Disabled'
 * '<S154>' : 'TPGCI/Subsystem1/PID Controller2/Saturation/Enabled'
 * '<S155>' : 'TPGCI/Subsystem1/PID Controller2/Saturation Fdbk/Disabled'
 * '<S156>' : 'TPGCI/Subsystem1/PID Controller2/Sum/Sum_PI'
 * '<S157>' : 'TPGCI/Subsystem1/PID Controller2/Sum Fdbk/Disabled'
 * '<S158>' : 'TPGCI/Subsystem1/PID Controller2/Tracking Mode/Disabled'
 * '<S159>' : 'TPGCI/Subsystem1/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S160>' : 'TPGCI/Subsystem1/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S161>' : 'TPGCI/Subsystem1/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S162>' : 'TPGCI/Subsystem1/PID Controller2/postSat Signal/Forward_Path'
 * '<S163>' : 'TPGCI/Subsystem1/PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* TPGCI_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
