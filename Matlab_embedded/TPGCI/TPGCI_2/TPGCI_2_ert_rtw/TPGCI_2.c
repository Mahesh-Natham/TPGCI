/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TPGCI_2.c
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

#include "TPGCI_2.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>
#include "math.h"

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile real_T Grid_wt;               /* '<Root>/Grid_wt' */
volatile real_T PWMCH1;                /* '<Root>/PWMCH1' */
volatile real_T PWMCH2;                /* '<Root>/PWMCH2' */
volatile real_T PWMCH3;                /* '<Root>/PWMCH3' */
volatile real_T Vd_g;                  /* '<Root>/Vd_g' */
volatile real_T ib;                    /* '<Root>/ib' */
volatile real_T ir;                    /* '<Root>/ir' */
volatile real_T iy;                    /* '<Root>/iy' */
volatile real_T vb_g;                  /* '<Root>/vb_g' */
volatile real_T vr_g;                  /* '<Root>/vr_g' */
volatile real_T vy_g;                  /* '<Root>/vy_g' */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_modd_snf(real_T u0, real_T u1);
static void abcto(real_T rtu_r, real_T rtu_y, real_T rtu_b, real_T *rty_alpha,
                  real_T *rty_beta, real_T *rty_zero);
static void todq(real_T rtu_alpha, real_T rtu_beta, real_T rtu_theta, real_T
                 *rty_d, real_T *rty_q);
static void MovingRMSExp(real_T rtu_u, real_T *rty_y, DW_MovingRMSExp *localDW);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
real_T rtNaN = -(real_T)NAN;
real_T rtInf = (real_T)INFINITY;
real_T rtMinusInf = -(real_T)INFINITY;
real32_T rtNaNF = -(real32_T)NAN;
real32_T rtInfF = (real32_T)INFINITY;
real32_T rtMinusInfF = -(real32_T)INFINITY;

/* Return rtNaN needed by the generated code. */
static real_T rtGetNaN(void)
{
  return rtNaN;
}

/* Return rtNaNF needed by the generated code. */
static real32_T rtGetNaNF(void)
{
  return rtNaNF;
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/*
 * Output and update for atomic system:
 *    '<S1>/abc to &#x3B1;&#x3B2;'
 *    '<S2>/abc to &#x3B1;&#x3B2;'
 */
static void abcto(real_T rtu_r, real_T rtu_y, real_T rtu_b, real_T *rty_alpha,
                  real_T *rty_beta, real_T *rty_zero)
{
  *rty_alpha = (0.66666666667 * rtu_r - 0.33333333333 * rtu_y) - 0.33333333333 *
    rtu_b;
  *rty_beta = (rtu_y - rtu_b) * 0.57735026919;
  *rty_zero = ((rtu_r + rtu_y) + rtu_b) * 0.33333333333;
}

/*
 * Output and update for atomic system:
 *    '<S1>/&#x3B1;&#x3B2; to dq'
 *    '<S2>/&#x3B1;&#x3B2; to dq'
 */
static void todq(real_T rtu_alpha, real_T rtu_beta, real_T rtu_theta, real_T
                 *rty_d, real_T *rty_q)
{
  real_T cos_theta;
  real_T sin_theta;
  cos_theta = cos(rtu_theta);
  sin_theta = sin(rtu_theta);
  *rty_d = rtu_alpha * cos_theta + rtu_beta * sin_theta;
  *rty_q = -rtu_alpha * sin_theta + rtu_beta * cos_theta;
}

/*
 * Output and update for atomic system:
 *    '<S2>/Moving RMS Exp'
 *    '<S3>/Moving RMS Exp'
 */
static void MovingRMSExp(real_T rtu_u, real_T *rty_y, DW_MovingRMSExp *localDW)
{
  if (!localDW->rmsSquared_not_empty) {
    localDW->rmsSquared = rtu_u * rtu_u;
    localDW->rmsSquared_not_empty = true;
  }

  localDW->rmsSquared = rtu_u * rtu_u * 0.001 + 0.999 * localDW->rmsSquared;
  *rty_y = localDW->rmsSquared;
  *rty_y = sqrt(*rty_y);
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void TPGCI_2_step(void)
{
  real_T rtb_Add;
  real_T rtb_Add_h;
  real_T rtb_Divide;
  real_T rtb_Divide1;
  real_T rtb_Filter;
  real_T rtb_Integrator_j;
  real_T rtb_Integrator_p;
  real_T rtb_Mod;
  real_T rtb_Sum3;
  real_T rtb_q_o;
  real_T rtb_y_d;
  real_T rtb_zero_au;

  /* MATLAB Function: '<S1>/abc to &#x3B1;&#x3B2;' incorporates:
   *  Inport: '<Root>/vb_g'
   *  Inport: '<Root>/vr_g'
   *  Inport: '<Root>/vy_g'
   */
  abcto(vr_g, vy_g, vb_g, &rtb_Filter, &rtb_Integrator_p, &rtb_zero_au);

  /* Math: '<S1>/Mod' incorporates:
   *  Constant: '<S1>/Constant1'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   */
  rtb_Mod = rt_modd_snf(rtDW.DiscreteTimeIntegrator_DSTATE, -6.2831853071795862);

  /* MATLAB Function: '<S1>/&#x3B1;&#x3B2; to dq' */
  todq(rtb_Filter, rtb_Integrator_p, rtb_Mod, &rtb_Add_h, &rtb_q_o);

  /* MATLAB Function: '<S1>/Moving RMS Exp' */
  if (!rtDW.rmsSquared_not_empty) {
    rtDW.rmsSquared = rtb_Add_h * rtb_Add_h;
    rtDW.rmsSquared_not_empty = true;
  }

  rtDW.rmsSquared = rtb_Add_h * rtb_Add_h * 0.001 + 0.999 * rtDW.rmsSquared;
  rtb_y_d = sqrt(rtDW.rmsSquared);

  /* End of MATLAB Function: '<S1>/Moving RMS Exp' */

  /* Outport: '<Root>/Vd_g' */
  Vd_g = rtb_y_d;

  /* MATLAB Function: '<S2>/abc to &#x3B1;&#x3B2;' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ir'
   *  Inport: '<Root>/iy'
   */
  abcto(ir, iy, ib, &rtb_Filter, &rtb_Integrator_p, &rtb_zero_au);

  /* MATLAB Function: '<S2>/&#x3B1;&#x3B2; to dq' incorporates:
   *  Outport: '<Root>/Iq'
   */
  todq(rtb_Filter, rtb_Integrator_p, rtb_Mod, &rtb_Add_h, &rtY.Iq);

  /* MATLAB Function: '<S2>/Moving RMS Exp' incorporates:
   *  Outport: '<Root>/Id'
   */
  MovingRMSExp(rtb_Add_h, &rtY.Id, &rtDW.sf_MovingRMSExp_h);

  /* Sum: '<S3>/Sum1' incorporates:
   *  Inport: '<Root>/Id_ref'
   *  Outport: '<Root>/Id'
   */
  rtb_Integrator_p = rtU.Id_ref - rtY.Id;

  /* Sum: '<S107>/Sum' incorporates:
   *  DiscreteIntegrator: '<S98>/Integrator'
   *  Gain: '<S103>/Proportional Gain'
   */
  rtb_zero_au = 0.01 * rtb_Integrator_p + rtDW.Integrator_DSTATE;

  /* Saturate: '<S105>/Saturation' */
  if (rtb_zero_au > 10.0) {
    rtb_zero_au = 10.0;
  } else if (rtb_zero_au < -10.0) {
    rtb_zero_au = -10.0;
  }

  /* End of Saturate: '<S105>/Saturation' */

  /* Sum: '<S3>/Sum2' incorporates:
   *  Gain: '<S3>/Gain1'
   *  Outport: '<Root>/Iq'
   */
  rtb_Integrator_j = 0.15707963267948966 * rtY.Iq + rtb_zero_au;

  /* Sum: '<S3>/Sum3' incorporates:
   *  Inport: '<Root>/Vd_FF'
   *  Sum: '<S3>/Sum7'
   */
  rtb_Sum3 = (rtU.Vd_FF + rtb_y_d) + rtb_Integrator_j;

  /* MATLAB Function: '<S3>/Moving RMS Exp' */
  MovingRMSExp(rtb_Sum3, &rtb_Add_h, &rtDW.sf_MovingRMSExp_e);

  /* Product: '<S3>/Divide' incorporates:
   *  Gain: '<S3>/Gain3'
   *  Inport: '<Root>/VDC'
   */
  rtb_Divide = 2.0 * rtb_Add_h / rtU.VDC;

  /* Sum: '<S3>/Sum4' incorporates:
   *  Inport: '<Root>/Iq_ref'
   *  Outport: '<Root>/Iq'
   */
  rtb_y_d = rtU.Iq_ref - rtY.Iq;

  /* Sum: '<S157>/Sum' incorporates:
   *  DiscreteIntegrator: '<S148>/Integrator'
   *  Gain: '<S153>/Proportional Gain'
   */
  rtb_Filter = 0.01 * rtb_y_d + rtDW.Integrator_DSTATE_e;

  /* Saturate: '<S155>/Saturation' */
  if (rtb_Filter > 10.0) {
    rtb_Filter = 10.0;
  } else if (rtb_Filter < -10.0) {
    rtb_Filter = -10.0;
  }

  /* Product: '<S3>/Divide1' incorporates:
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain4'
   *  Inport: '<Root>/VDC'
   *  Outport: '<Root>/Id'
   *  Saturate: '<S155>/Saturation'
   *  Sum: '<S3>/Sum5'
   *  Sum: '<S3>/Sum6'
   */
  rtb_Divide1 = ((rtb_Filter - 0.15707963267948966 * rtY.Id) + rtb_q_o) * 2.0 /
    rtU.VDC;

  /* Sum: '<S3>/Add' incorporates:
   *  Inport: '<Root>/Phase_dif'
   */
  rtb_Add = rtU.Phase_dif + rtb_Mod;

  /* MATLAB Function: '<S3>/dq to abc' */
  rtb_Filter = rtb_Divide * cos(rtb_Add) - rtb_Divide1 * sin(rtb_Add);

  /* Saturate: '<S3>/Saturation2' */
  if (rtb_Filter > 0.95) {
    rtb_Filter = 0.95;
  } else if (rtb_Filter < -0.95) {
    rtb_Filter = -0.95;
  }

  /* End of Saturate: '<S3>/Saturation2' */

  /* Outport: '<Root>/PWMCH1' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/CCRMAX'
   *  Product: '<S3>/Divide2'
   *  Product: '<S3>/Product'
   *  Sum: '<S3>/Add1'
   */
  PWMCH1 = (rtb_Filter + 1.0) / 2.0 * rtU.CCRMAX;

  /* MATLAB Function: '<S3>/dq to abc' */
  rtb_Add_h = cos(rtb_Add - 2.0943951023931948) * rtb_Divide - sin(rtb_Add -
    2.0943951023931948) * rtb_Divide1;

  /* Saturate: '<S3>/Saturation1' */
  if (rtb_Add_h > 0.95) {
    rtb_Add_h = 0.95;
  } else if (rtb_Add_h < -0.95) {
    rtb_Add_h = -0.95;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* Outport: '<Root>/PWMCH2' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/CCRMAX'
   *  Product: '<S3>/Divide3'
   *  Product: '<S3>/Product1'
   *  Sum: '<S3>/Add2'
   */
  PWMCH2 = (rtb_Add_h + 1.0) / 2.0 * rtU.CCRMAX;

  /* Outport: '<Root>/Mb' */
  rtY.Mb = rtb_Add_h;

  /* MATLAB Function: '<S3>/dq to abc' */
  rtb_Add_h = cos(rtb_Add + 2.0943951023931948) * rtb_Divide - sin(rtb_Add +
    2.0943951023931948) * rtb_Divide1;

  /* Saturate: '<S3>/Saturation3' */
  if (rtb_Add_h > 0.95) {
    rtb_Add_h = 0.95;
  } else if (rtb_Add_h < -0.95) {
    rtb_Add_h = -0.95;
  }

  /* End of Saturate: '<S3>/Saturation3' */

  /* Outport: '<Root>/PWMCH3' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/CCRMAX'
   *  Product: '<S3>/Divide4'
   *  Product: '<S3>/Product2'
   *  Sum: '<S3>/Add3'
   */
  PWMCH3 = (rtb_Add_h + 1.0) / 2.0 * rtU.CCRMAX;

  /* Outport: '<Root>/Mc' */
  rtY.Mc = rtb_Add_h;

  /* Outport: '<Root>/Ma' */
  rtY.Ma = rtb_Filter;

  /* Outport: '<Root>/Vd_pid_out' */
  rtY.Vd_pid_out = rtb_Sum3;

  /* Outport: '<Root>/Id_pi_out2' */
  rtY.Id_pi_out2 = rtb_Integrator_j;

  /* Outport: '<Root>/Id_pi_out' */
  rtY.Id_pi_out = rtb_zero_au;

  /* Outport: '<Root>/Id_pi_error' */
  rtY.Id_pi_error = rtb_Integrator_p;

  /* Gain: '<S44>/Filter Coefficient' incorporates:
   *  Constant: '<S1>/Constant'
   *  DiscreteIntegrator: '<S36>/Filter'
   *  Gain: '<S34>/Derivative Gain'
   *  Sum: '<S1>/Add'
   *  Sum: '<S36>/SumD'
   */
  rtb_Filter = ((0.0 - rtb_q_o) * 0.0 - rtDW.Filter_DSTATE) * 100.0;

  /* Outport: '<Root>/Grid_wt' */
  Grid_wt = rtb_Mod;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   *  DiscreteIntegrator: '<S41>/Integrator'
   *  Gain: '<S46>/Proportional Gain'
   *  Sum: '<S1>/Add'
   *  Sum: '<S50>/Sum'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE += (((0.0 - rtb_q_o) * 10.0 +
    rtDW.Integrator_DSTATE_p) + rtb_Filter) * 2.0E-5;

  /* Update for DiscreteIntegrator: '<S98>/Integrator' */
  rtDW.Integrator_DSTATE += 2.0E-5 * rtb_Integrator_p;
  if (rtDW.Integrator_DSTATE > 10.0) {
    rtDW.Integrator_DSTATE = 10.0;
  } else if (rtDW.Integrator_DSTATE < -10.0) {
    rtDW.Integrator_DSTATE = -10.0;
  }

  /* End of Update for DiscreteIntegrator: '<S98>/Integrator' */

  /* Update for DiscreteIntegrator: '<S148>/Integrator' */
  rtDW.Integrator_DSTATE_e += 2.0E-5 * rtb_y_d;
  if (rtDW.Integrator_DSTATE_e > 10.0) {
    rtDW.Integrator_DSTATE_e = 10.0;
  } else if (rtDW.Integrator_DSTATE_e < -10.0) {
    rtDW.Integrator_DSTATE_e = -10.0;
  }

  /* End of Update for DiscreteIntegrator: '<S148>/Integrator' */

  /* Update for DiscreteIntegrator: '<S36>/Filter' */
  rtDW.Filter_DSTATE += 2.0E-5 * rtb_Filter;

  /* Update for DiscreteIntegrator: '<S41>/Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S38>/Integral Gain'
   *  Sum: '<S1>/Add'
   */
  rtDW.Integrator_DSTATE_p += (0.0 - rtb_q_o) * 1000.0 * 2.0E-5;
}

/* Model initialize function */
void TPGCI_2_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
