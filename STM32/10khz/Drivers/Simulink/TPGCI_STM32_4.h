/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TPGCI_STM32_4.h
 *
 * Code generated for Simulink model 'TPGCI_STM32_4'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Mar 31 15:17:32 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: All passed
 */

#ifndef TPGCI_STM32_4_h_
#define TPGCI_STM32_4_h_
#ifndef TPGCI_STM32_4_COMMON_INCLUDES_
#define TPGCI_STM32_4_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#endif                                 /* TPGCI_STM32_4_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>/RMS Exp' */
typedef struct {
  double rmsSquared;                   /* '<Root>/RMS Exp' */
  bool rmsSquared_not_empty;           /* '<Root>/RMS Exp' */
} DW_RMSExp;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_RMSExp sf_RMSExp1;                /* '<Root>/RMS Exp1' */
  DW_RMSExp sf_RMSExp;                 /* '<Root>/RMS Exp' */
  double Fcn_n;                        /* '<S177>/Fcn' */
  double Fcn1_h;                       /* '<S177>/Fcn1' */
  double Fcn_k1;                       /* '<S176>/Fcn' */
  double Fcn1_j;                       /* '<S176>/Fcn1' */
  double Fcn_a;                        /* '<S171>/Fcn' */
  double Fcn1_ic;                      /* '<S171>/Fcn1' */
  double Fcn_nk;                       /* '<S170>/Fcn' */
  double Fcn1_l;                       /* '<S170>/Fcn1' */
  double DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  double Integrator_DSTATE;            /* '<S99>/Integrator' */
  double Integrator_DSTATE_e;          /* '<S149>/Integrator' */
  double Integrator_DSTATE_f;          /* '<S49>/Integrator' */
  double Filter_DSTATE;                /* '<S44>/Filter' */
} DW;

/* Invariant block signals (default storage) */
typedef struct {
  const uint8_t Compare_i;             /* '<S169>/Compare' */
  const uint8_t Compare_b;             /* '<S175>/Compare' */
} ConstB;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ] )
   * Referenced by:
   *   '<S167>/Gain3'
   *   '<S173>/Gain3'
   */
  double pooled5[9];

  /* Expression: [ 1   0   1; -1/2  sqrt(3)/2   1; -1/2  -sqrt(3)/2  1 ]
   * Referenced by: '<S178>/Gain3'
   */
  double Gain3_Gain[9];
} ConstP;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  double pi_out;                       /* '<Root>/pi_out' */
  double Vdc_cal;                      /* '<Root>/Vdc_cal' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;
extern const ConstB rtConstB;          /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void TPGCI_STM32_4_initialize(void);
extern void TPGCI_STM32_4_step(void);

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile double CCR_max;        /* '<Root>/CCR_max' */
extern volatile double Freq;           /* '<Root>/Freq' */
extern volatile double Ia_g;           /* '<Root>/Ia_g' */
extern volatile double Iabc_gain;      /* '<Root>/Iabc_gain' */
extern volatile double Ib_g;           /* '<Root>/Ib_g' */
extern volatile double Ic_g;           /* '<Root>/Ic_g' */
extern volatile double Id;             /* '<Root>/Id' */
extern volatile double Id_ref;         /* '<Root>/Id_ref' */
extern volatile double Iq;             /* '<Root>/Iq' */
extern volatile double PWMch1;         /* '<Root>/PWMch1' */
extern volatile double PWMch2;         /* '<Root>/PWMch2' */
extern volatile double PWMch3;         /* '<Root>/PWMch3' */
extern volatile double Theta_g;        /* '<Root>/Theta_g' */
extern volatile double VDC;            /* '<Root>/VDC' */
extern volatile double Va_g;           /* '<Root>/Va_g' */
extern volatile double Vabc_gain;      /* '<Root>/Vabc_gain' */
extern volatile double Vb_g;           /* '<Root>/Vb_g' */
extern volatile double Vc_g;           /* '<Root>/Vc_g' */
extern volatile double Vd_g;           /* '<Root>/Vd_g' */
extern volatile double Vdc_gain;       /* '<Root>/Vdc_gain' */
extern volatile double Vq_g;           /* '<Root>/Vq_g' */
extern volatile double m_abc[3];       /* '<Root>/m_abc' */
extern volatile double phasedelay;     /* '<Root>/phase delay' */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S104>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S154>/Proportional Gain' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'TPGCI_STM32_4'
 * '<S1>'   : 'TPGCI_STM32_4/1//Vabc_gain'
 * '<S2>'   : 'TPGCI_STM32_4/1//Vabc_gain1'
 * '<S3>'   : 'TPGCI_STM32_4/1//Vdc_gain'
 * '<S4>'   : 'TPGCI_STM32_4/1//Vdc_gain1'
 * '<S5>'   : 'TPGCI_STM32_4/PID Controller1'
 * '<S6>'   : 'TPGCI_STM32_4/PID Controller4'
 * '<S7>'   : 'TPGCI_STM32_4/PID Controller5'
 * '<S8>'   : 'TPGCI_STM32_4/RMS Exp'
 * '<S9>'   : 'TPGCI_STM32_4/RMS Exp1'
 * '<S10>'  : 'TPGCI_STM32_4/abc to dq0'
 * '<S11>'  : 'TPGCI_STM32_4/abc to dq1'
 * '<S12>'  : 'TPGCI_STM32_4/dq0 to abc1'
 * '<S13>'  : 'TPGCI_STM32_4/theta+delay'
 * '<S14>'  : 'TPGCI_STM32_4/wl*id'
 * '<S15>'  : 'TPGCI_STM32_4/wl*iq'
 * '<S16>'  : 'TPGCI_STM32_4/PID Controller1/Anti-windup'
 * '<S17>'  : 'TPGCI_STM32_4/PID Controller1/D Gain'
 * '<S18>'  : 'TPGCI_STM32_4/PID Controller1/External Derivative'
 * '<S19>'  : 'TPGCI_STM32_4/PID Controller1/Filter'
 * '<S20>'  : 'TPGCI_STM32_4/PID Controller1/Filter ICs'
 * '<S21>'  : 'TPGCI_STM32_4/PID Controller1/I Gain'
 * '<S22>'  : 'TPGCI_STM32_4/PID Controller1/Ideal P Gain'
 * '<S23>'  : 'TPGCI_STM32_4/PID Controller1/Ideal P Gain Fdbk'
 * '<S24>'  : 'TPGCI_STM32_4/PID Controller1/Integrator'
 * '<S25>'  : 'TPGCI_STM32_4/PID Controller1/Integrator ICs'
 * '<S26>'  : 'TPGCI_STM32_4/PID Controller1/N Copy'
 * '<S27>'  : 'TPGCI_STM32_4/PID Controller1/N Gain'
 * '<S28>'  : 'TPGCI_STM32_4/PID Controller1/P Copy'
 * '<S29>'  : 'TPGCI_STM32_4/PID Controller1/Parallel P Gain'
 * '<S30>'  : 'TPGCI_STM32_4/PID Controller1/Reset Signal'
 * '<S31>'  : 'TPGCI_STM32_4/PID Controller1/Saturation'
 * '<S32>'  : 'TPGCI_STM32_4/PID Controller1/Saturation Fdbk'
 * '<S33>'  : 'TPGCI_STM32_4/PID Controller1/Sum'
 * '<S34>'  : 'TPGCI_STM32_4/PID Controller1/Sum Fdbk'
 * '<S35>'  : 'TPGCI_STM32_4/PID Controller1/Tracking Mode'
 * '<S36>'  : 'TPGCI_STM32_4/PID Controller1/Tracking Mode Sum'
 * '<S37>'  : 'TPGCI_STM32_4/PID Controller1/Tsamp - Integral'
 * '<S38>'  : 'TPGCI_STM32_4/PID Controller1/Tsamp - Ngain'
 * '<S39>'  : 'TPGCI_STM32_4/PID Controller1/postSat Signal'
 * '<S40>'  : 'TPGCI_STM32_4/PID Controller1/preSat Signal'
 * '<S41>'  : 'TPGCI_STM32_4/PID Controller1/Anti-windup/Passthrough'
 * '<S42>'  : 'TPGCI_STM32_4/PID Controller1/D Gain/Internal Parameters'
 * '<S43>'  : 'TPGCI_STM32_4/PID Controller1/External Derivative/Error'
 * '<S44>'  : 'TPGCI_STM32_4/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S45>'  : 'TPGCI_STM32_4/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S46>'  : 'TPGCI_STM32_4/PID Controller1/I Gain/Internal Parameters'
 * '<S47>'  : 'TPGCI_STM32_4/PID Controller1/Ideal P Gain/Passthrough'
 * '<S48>'  : 'TPGCI_STM32_4/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S49>'  : 'TPGCI_STM32_4/PID Controller1/Integrator/Discrete'
 * '<S50>'  : 'TPGCI_STM32_4/PID Controller1/Integrator ICs/Internal IC'
 * '<S51>'  : 'TPGCI_STM32_4/PID Controller1/N Copy/Disabled'
 * '<S52>'  : 'TPGCI_STM32_4/PID Controller1/N Gain/Internal Parameters'
 * '<S53>'  : 'TPGCI_STM32_4/PID Controller1/P Copy/Disabled'
 * '<S54>'  : 'TPGCI_STM32_4/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S55>'  : 'TPGCI_STM32_4/PID Controller1/Reset Signal/Disabled'
 * '<S56>'  : 'TPGCI_STM32_4/PID Controller1/Saturation/Passthrough'
 * '<S57>'  : 'TPGCI_STM32_4/PID Controller1/Saturation Fdbk/Disabled'
 * '<S58>'  : 'TPGCI_STM32_4/PID Controller1/Sum/Sum_PID'
 * '<S59>'  : 'TPGCI_STM32_4/PID Controller1/Sum Fdbk/Disabled'
 * '<S60>'  : 'TPGCI_STM32_4/PID Controller1/Tracking Mode/Disabled'
 * '<S61>'  : 'TPGCI_STM32_4/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S62>'  : 'TPGCI_STM32_4/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S63>'  : 'TPGCI_STM32_4/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S64>'  : 'TPGCI_STM32_4/PID Controller1/postSat Signal/Forward_Path'
 * '<S65>'  : 'TPGCI_STM32_4/PID Controller1/preSat Signal/Forward_Path'
 * '<S66>'  : 'TPGCI_STM32_4/PID Controller4/Anti-windup'
 * '<S67>'  : 'TPGCI_STM32_4/PID Controller4/D Gain'
 * '<S68>'  : 'TPGCI_STM32_4/PID Controller4/External Derivative'
 * '<S69>'  : 'TPGCI_STM32_4/PID Controller4/Filter'
 * '<S70>'  : 'TPGCI_STM32_4/PID Controller4/Filter ICs'
 * '<S71>'  : 'TPGCI_STM32_4/PID Controller4/I Gain'
 * '<S72>'  : 'TPGCI_STM32_4/PID Controller4/Ideal P Gain'
 * '<S73>'  : 'TPGCI_STM32_4/PID Controller4/Ideal P Gain Fdbk'
 * '<S74>'  : 'TPGCI_STM32_4/PID Controller4/Integrator'
 * '<S75>'  : 'TPGCI_STM32_4/PID Controller4/Integrator ICs'
 * '<S76>'  : 'TPGCI_STM32_4/PID Controller4/N Copy'
 * '<S77>'  : 'TPGCI_STM32_4/PID Controller4/N Gain'
 * '<S78>'  : 'TPGCI_STM32_4/PID Controller4/P Copy'
 * '<S79>'  : 'TPGCI_STM32_4/PID Controller4/Parallel P Gain'
 * '<S80>'  : 'TPGCI_STM32_4/PID Controller4/Reset Signal'
 * '<S81>'  : 'TPGCI_STM32_4/PID Controller4/Saturation'
 * '<S82>'  : 'TPGCI_STM32_4/PID Controller4/Saturation Fdbk'
 * '<S83>'  : 'TPGCI_STM32_4/PID Controller4/Sum'
 * '<S84>'  : 'TPGCI_STM32_4/PID Controller4/Sum Fdbk'
 * '<S85>'  : 'TPGCI_STM32_4/PID Controller4/Tracking Mode'
 * '<S86>'  : 'TPGCI_STM32_4/PID Controller4/Tracking Mode Sum'
 * '<S87>'  : 'TPGCI_STM32_4/PID Controller4/Tsamp - Integral'
 * '<S88>'  : 'TPGCI_STM32_4/PID Controller4/Tsamp - Ngain'
 * '<S89>'  : 'TPGCI_STM32_4/PID Controller4/postSat Signal'
 * '<S90>'  : 'TPGCI_STM32_4/PID Controller4/preSat Signal'
 * '<S91>'  : 'TPGCI_STM32_4/PID Controller4/Anti-windup/Passthrough'
 * '<S92>'  : 'TPGCI_STM32_4/PID Controller4/D Gain/Disabled'
 * '<S93>'  : 'TPGCI_STM32_4/PID Controller4/External Derivative/Disabled'
 * '<S94>'  : 'TPGCI_STM32_4/PID Controller4/Filter/Disabled'
 * '<S95>'  : 'TPGCI_STM32_4/PID Controller4/Filter ICs/Disabled'
 * '<S96>'  : 'TPGCI_STM32_4/PID Controller4/I Gain/Internal Parameters'
 * '<S97>'  : 'TPGCI_STM32_4/PID Controller4/Ideal P Gain/Passthrough'
 * '<S98>'  : 'TPGCI_STM32_4/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S99>'  : 'TPGCI_STM32_4/PID Controller4/Integrator/Discrete'
 * '<S100>' : 'TPGCI_STM32_4/PID Controller4/Integrator ICs/Internal IC'
 * '<S101>' : 'TPGCI_STM32_4/PID Controller4/N Copy/Disabled wSignal Specification'
 * '<S102>' : 'TPGCI_STM32_4/PID Controller4/N Gain/Disabled'
 * '<S103>' : 'TPGCI_STM32_4/PID Controller4/P Copy/Disabled'
 * '<S104>' : 'TPGCI_STM32_4/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S105>' : 'TPGCI_STM32_4/PID Controller4/Reset Signal/Disabled'
 * '<S106>' : 'TPGCI_STM32_4/PID Controller4/Saturation/Enabled'
 * '<S107>' : 'TPGCI_STM32_4/PID Controller4/Saturation Fdbk/Disabled'
 * '<S108>' : 'TPGCI_STM32_4/PID Controller4/Sum/Sum_PI'
 * '<S109>' : 'TPGCI_STM32_4/PID Controller4/Sum Fdbk/Disabled'
 * '<S110>' : 'TPGCI_STM32_4/PID Controller4/Tracking Mode/Disabled'
 * '<S111>' : 'TPGCI_STM32_4/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S112>' : 'TPGCI_STM32_4/PID Controller4/Tsamp - Integral/TsSignalSpecification'
 * '<S113>' : 'TPGCI_STM32_4/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S114>' : 'TPGCI_STM32_4/PID Controller4/postSat Signal/Forward_Path'
 * '<S115>' : 'TPGCI_STM32_4/PID Controller4/preSat Signal/Forward_Path'
 * '<S116>' : 'TPGCI_STM32_4/PID Controller5/Anti-windup'
 * '<S117>' : 'TPGCI_STM32_4/PID Controller5/D Gain'
 * '<S118>' : 'TPGCI_STM32_4/PID Controller5/External Derivative'
 * '<S119>' : 'TPGCI_STM32_4/PID Controller5/Filter'
 * '<S120>' : 'TPGCI_STM32_4/PID Controller5/Filter ICs'
 * '<S121>' : 'TPGCI_STM32_4/PID Controller5/I Gain'
 * '<S122>' : 'TPGCI_STM32_4/PID Controller5/Ideal P Gain'
 * '<S123>' : 'TPGCI_STM32_4/PID Controller5/Ideal P Gain Fdbk'
 * '<S124>' : 'TPGCI_STM32_4/PID Controller5/Integrator'
 * '<S125>' : 'TPGCI_STM32_4/PID Controller5/Integrator ICs'
 * '<S126>' : 'TPGCI_STM32_4/PID Controller5/N Copy'
 * '<S127>' : 'TPGCI_STM32_4/PID Controller5/N Gain'
 * '<S128>' : 'TPGCI_STM32_4/PID Controller5/P Copy'
 * '<S129>' : 'TPGCI_STM32_4/PID Controller5/Parallel P Gain'
 * '<S130>' : 'TPGCI_STM32_4/PID Controller5/Reset Signal'
 * '<S131>' : 'TPGCI_STM32_4/PID Controller5/Saturation'
 * '<S132>' : 'TPGCI_STM32_4/PID Controller5/Saturation Fdbk'
 * '<S133>' : 'TPGCI_STM32_4/PID Controller5/Sum'
 * '<S134>' : 'TPGCI_STM32_4/PID Controller5/Sum Fdbk'
 * '<S135>' : 'TPGCI_STM32_4/PID Controller5/Tracking Mode'
 * '<S136>' : 'TPGCI_STM32_4/PID Controller5/Tracking Mode Sum'
 * '<S137>' : 'TPGCI_STM32_4/PID Controller5/Tsamp - Integral'
 * '<S138>' : 'TPGCI_STM32_4/PID Controller5/Tsamp - Ngain'
 * '<S139>' : 'TPGCI_STM32_4/PID Controller5/postSat Signal'
 * '<S140>' : 'TPGCI_STM32_4/PID Controller5/preSat Signal'
 * '<S141>' : 'TPGCI_STM32_4/PID Controller5/Anti-windup/Passthrough'
 * '<S142>' : 'TPGCI_STM32_4/PID Controller5/D Gain/Disabled'
 * '<S143>' : 'TPGCI_STM32_4/PID Controller5/External Derivative/Disabled'
 * '<S144>' : 'TPGCI_STM32_4/PID Controller5/Filter/Disabled'
 * '<S145>' : 'TPGCI_STM32_4/PID Controller5/Filter ICs/Disabled'
 * '<S146>' : 'TPGCI_STM32_4/PID Controller5/I Gain/Internal Parameters'
 * '<S147>' : 'TPGCI_STM32_4/PID Controller5/Ideal P Gain/Passthrough'
 * '<S148>' : 'TPGCI_STM32_4/PID Controller5/Ideal P Gain Fdbk/Disabled'
 * '<S149>' : 'TPGCI_STM32_4/PID Controller5/Integrator/Discrete'
 * '<S150>' : 'TPGCI_STM32_4/PID Controller5/Integrator ICs/Internal IC'
 * '<S151>' : 'TPGCI_STM32_4/PID Controller5/N Copy/Disabled wSignal Specification'
 * '<S152>' : 'TPGCI_STM32_4/PID Controller5/N Gain/Disabled'
 * '<S153>' : 'TPGCI_STM32_4/PID Controller5/P Copy/Disabled'
 * '<S154>' : 'TPGCI_STM32_4/PID Controller5/Parallel P Gain/Internal Parameters'
 * '<S155>' : 'TPGCI_STM32_4/PID Controller5/Reset Signal/Disabled'
 * '<S156>' : 'TPGCI_STM32_4/PID Controller5/Saturation/Passthrough'
 * '<S157>' : 'TPGCI_STM32_4/PID Controller5/Saturation Fdbk/Disabled'
 * '<S158>' : 'TPGCI_STM32_4/PID Controller5/Sum/Sum_PI'
 * '<S159>' : 'TPGCI_STM32_4/PID Controller5/Sum Fdbk/Disabled'
 * '<S160>' : 'TPGCI_STM32_4/PID Controller5/Tracking Mode/Disabled'
 * '<S161>' : 'TPGCI_STM32_4/PID Controller5/Tracking Mode Sum/Passthrough'
 * '<S162>' : 'TPGCI_STM32_4/PID Controller5/Tsamp - Integral/TsSignalSpecification'
 * '<S163>' : 'TPGCI_STM32_4/PID Controller5/Tsamp - Ngain/Passthrough'
 * '<S164>' : 'TPGCI_STM32_4/PID Controller5/postSat Signal/Forward_Path'
 * '<S165>' : 'TPGCI_STM32_4/PID Controller5/preSat Signal/Forward_Path'
 * '<S166>' : 'TPGCI_STM32_4/abc to dq0/Alpha-Beta-Zero to dq0'
 * '<S167>' : 'TPGCI_STM32_4/abc to dq0/abc to Alpha-Beta-Zero'
 * '<S168>' : 'TPGCI_STM32_4/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S169>' : 'TPGCI_STM32_4/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S170>' : 'TPGCI_STM32_4/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S171>' : 'TPGCI_STM32_4/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S172>' : 'TPGCI_STM32_4/abc to dq1/Alpha-Beta-Zero to dq0'
 * '<S173>' : 'TPGCI_STM32_4/abc to dq1/abc to Alpha-Beta-Zero'
 * '<S174>' : 'TPGCI_STM32_4/abc to dq1/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S175>' : 'TPGCI_STM32_4/abc to dq1/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S176>' : 'TPGCI_STM32_4/abc to dq1/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S177>' : 'TPGCI_STM32_4/abc to dq1/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S178>' : 'TPGCI_STM32_4/dq0 to abc1/Alpha-Beta-Zero to abc'
 * '<S179>' : 'TPGCI_STM32_4/dq0 to abc1/dq0 to Alpha-Beta-Zero'
 * '<S180>' : 'TPGCI_STM32_4/dq0 to abc1/dq0 to Alpha-Beta-Zero/Compare To Constant'
 * '<S181>' : 'TPGCI_STM32_4/dq0 to abc1/dq0 to Alpha-Beta-Zero/Compare To Constant1'
 * '<S182>' : 'TPGCI_STM32_4/dq0 to abc1/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay'
 * '<S183>' : 'TPGCI_STM32_4/dq0 to abc1/dq0 to Alpha-Beta-Zero/Subsystem1'
 */
#endif                                 /* TPGCI_STM32_4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
