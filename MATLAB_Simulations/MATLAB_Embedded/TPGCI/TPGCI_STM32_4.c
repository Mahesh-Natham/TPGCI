/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TPGCI_STM32_4.c
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

#include "TPGCI_STM32_4.h"
#include <stdint.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile double CCR_max;               /* '<Root>/CCR_max' */
volatile double Freq;                  /* '<Root>/Freq' */
volatile double Ia_g;                  /* '<Root>/Ia_g' */
volatile double Iabc_gain;             /* '<Root>/Iabc_gain' */
volatile double Ib_g;                  /* '<Root>/Ib_g' */
volatile double Ic_g;                  /* '<Root>/Ic_g' */
volatile double Id;                    /* '<Root>/Id' */
volatile double Id_ref;                /* '<Root>/Id_ref' */
volatile double Iq;                    /* '<Root>/Iq' */
volatile double PWMch1;                /* '<Root>/PWMch1' */
volatile double PWMch2;                /* '<Root>/PWMch2' */
volatile double PWMch3;                /* '<Root>/PWMch3' */
volatile double Theta_g;               /* '<Root>/Theta_g' */
volatile double VDC;                   /* '<Root>/VDC' */
volatile double Va_g;                  /* '<Root>/Va_g' */
volatile double Vabc_gain;             /* '<Root>/Vabc_gain' */
volatile double Vb_g;                  /* '<Root>/Vb_g' */
volatile double Vc_g;                  /* '<Root>/Vc_g' */
volatile double Vd_g;                  /* '<Root>/Vd_g' */
volatile double Vdc_gain;              /* '<Root>/Vdc_gain' */
volatile double Vq_g;                  /* '<Root>/Vq_g' */
volatile double m_abc[3];              /* '<Root>/m_abc' */
volatile double phasedelay;            /* '<Root>/phase delay' */

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
extern double rt_modd(double u0, double u1);
static void RMSExp(double rtu_u, double *rty_y, DW_RMSExp *localDW);
static void Subsystempi2delay(uint8_t rtu_Enable, const double rtu_alpha_beta[2],
  double rtu_wt, double *rty_dq, double *rty_dq_j);
static void Subsystem1(uint8_t rtu_Enable, const double rtu_alpha_beta[2],
  double rtu_wt, double *rty_dq, double *rty_dq_e);

/*
 * Output and update for atomic system:
 *    '<Root>/RMS Exp'
 *    '<Root>/RMS Exp1'
 */
static void RMSExp(double rtu_u, double *rty_y, DW_RMSExp *localDW)
{
  if (!localDW->rmsSquared_not_empty) {
    localDW->rmsSquared = rtu_u * rtu_u;
    localDW->rmsSquared_not_empty = true;
  }

  localDW->rmsSquared = rtu_u * rtu_u * 0.01 + 0.99 * localDW->rmsSquared;
  *rty_y = localDW->rmsSquared;
  *rty_y = sqrt(*rty_y);
}

/*
 * Output and update for enable system:
 *    '<S166>/Subsystem - pi//2 delay'
 *    '<S172>/Subsystem - pi//2 delay'
 */
static void Subsystempi2delay(uint8_t rtu_Enable, const double rtu_alpha_beta[2],
  double rtu_wt, double *rty_dq, double *rty_dq_j)
{
  /* Outputs for Enabled SubSystem: '<S166>/Subsystem - pi//2 delay' incorporates:
   *  EnablePort: '<S170>/Enable'
   */
  if (rtu_Enable > 0) {
    double tmp;
    double tmp_0;

    /* Fcn: '<S170>/Fcn' incorporates:
     *  Fcn: '<S170>/Fcn1'
     */
    tmp = cos(rtu_wt);
    tmp_0 = sin(rtu_wt);
    *rty_dq = rtu_alpha_beta[0] * tmp_0 - rtu_alpha_beta[1] * tmp;

    /* Fcn: '<S170>/Fcn1' */
    *rty_dq_j = rtu_alpha_beta[0] * tmp + rtu_alpha_beta[1] * tmp_0;
  }

  /* End of Outputs for SubSystem: '<S166>/Subsystem - pi//2 delay' */
}

/*
 * Output and update for enable system:
 *    '<S166>/Subsystem1'
 *    '<S172>/Subsystem1'
 */
static void Subsystem1(uint8_t rtu_Enable, const double rtu_alpha_beta[2],
  double rtu_wt, double *rty_dq, double *rty_dq_e)
{
  /* Outputs for Enabled SubSystem: '<S166>/Subsystem1' incorporates:
   *  EnablePort: '<S171>/Enable'
   */
  if (rtu_Enable > 0) {
    double tmp;
    double tmp_0;

    /* Fcn: '<S171>/Fcn' incorporates:
     *  Fcn: '<S171>/Fcn1'
     */
    tmp = sin(rtu_wt);
    tmp_0 = cos(rtu_wt);
    *rty_dq = rtu_alpha_beta[0] * tmp_0 + rtu_alpha_beta[1] * tmp;

    /* Fcn: '<S171>/Fcn1' */
    *rty_dq_e = -rtu_alpha_beta[0] * tmp + rtu_alpha_beta[1] * tmp_0;
  }

  /* End of Outputs for SubSystem: '<S166>/Subsystem1' */
}

double rt_modd(double u0, double u1)
{
  double y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else {
    bool yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      double q;
      q = fabs(u0 / u1);
      yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
    }

    if (yEq) {
      y = 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void TPGCI_STM32_4_step(void)
{
  double rtb_Gain1[3];
  double rtb_Gain1_p[3];
  double rtb_Add2;
  double rtb_Divide;
  double rtb_Divide1;
  double rtb_Divide_idx_0_tmp;
  double rtb_Divide_idx_0_tmp_0;
  double rtb_Filter;
  double rtb_Integrator_l;
  double rtb_Mod1;
  double rtb_Saturation;
  double rtb_Sum8;
  int32_t i;
  for (i = 0; i < 3; i++) {
    /* Gain: '<S173>/Gain3' */
    rtb_Mod1 = rtConstP.pooled5[i + 3];
    rtb_Sum8 = rtConstP.pooled5[i];
    rtb_Saturation = rtConstP.pooled5[i + 6];

    /* Gain: '<S173>/Gain1' incorporates:
     *  Gain: '<S173>/Gain3'
     *  Inport: '<Root>/Ia_g'
     *  Inport: '<Root>/Ib_g'
     *  Inport: '<Root>/Ic_g'
     */
    rtb_Gain1[i] = ((rtb_Mod1 * Ib_g + rtb_Sum8 * Ia_g) + rtb_Saturation * Ic_g)
      * 0.66666666666666663;

    /* Gain: '<S167>/Gain1' incorporates:
     *  Gain: '<S167>/Gain3'
     *  Inport: '<Root>/Va_g'
     *  Inport: '<Root>/Vb_g'
     *  Inport: '<Root>/Vc_g'
     */
    rtb_Gain1_p[i] = ((rtb_Mod1 * Vb_g + rtb_Sum8 * Va_g) + rtb_Saturation *
                      Vc_g) * 0.66666666666666663;
  }

  /* Math: '<Root>/Mod1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   */
  rtb_Mod1 = rt_modd(rtDW.DiscreteTimeIntegrator_DSTATE, 6.2831853071795862);

  /* Outputs for Enabled SubSystem: '<S172>/Subsystem1' */
  Subsystem1(0, &rtb_Gain1[0], rtb_Mod1, &rtDW.Fcn_n, &rtDW.Fcn1_h);

  /* End of Outputs for SubSystem: '<S172>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S172>/Subsystem - pi//2 delay' */
  Subsystempi2delay(rtConstB.Compare_b, &rtb_Gain1[0], rtb_Mod1, &rtDW.Fcn_k1,
                    &rtDW.Fcn1_j);

  /* End of Outputs for SubSystem: '<S172>/Subsystem - pi//2 delay' */

  /* MATLAB Function: '<Root>/RMS Exp1' incorporates:
   *  Outport: '<Root>/Id'
   *  Switch: '<S172>/Switch'
   */
  RMSExp(rtDW.Fcn_k1, (double *)&Id, &rtDW.sf_RMSExp1);

  /* Product: '<Root>/Product3' incorporates:
   *  Inport: '<Root>/Iabc_gain'
   *  Inport: '<Root>/Id_ref'
   *  Product: '<Root>/Product4'
   */
  rtb_Integrator_l = Id_ref * Iabc_gain;

  /* Sum: '<Root>/Sum8' incorporates:
   *  Outport: '<Root>/Id'
   *  Product: '<Root>/Product3'
   */
  rtb_Sum8 = rtb_Integrator_l - Id;

  /* Sum: '<S108>/Sum' incorporates:
   *  DiscreteIntegrator: '<S99>/Integrator'
   */
  rtb_Saturation = rtb_Sum8 + rtDW.Integrator_DSTATE;

  /* Saturate: '<S106>/Saturation' */
  if (rtb_Saturation > 10.0) {
    rtb_Saturation = 10.0;
  } else if (rtb_Saturation < -10.0) {
    rtb_Saturation = -10.0;
  }

  /* End of Saturate: '<S106>/Saturation' */

  /* Outputs for Enabled SubSystem: '<S166>/Subsystem1' */
  Subsystem1(0, &rtb_Gain1_p[0], rtb_Mod1, &rtDW.Fcn_a, &rtDW.Fcn1_ic);

  /* End of Outputs for SubSystem: '<S166>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S166>/Subsystem - pi//2 delay' */
  Subsystempi2delay(rtConstB.Compare_i, &rtb_Gain1_p[0], rtb_Mod1, &rtDW.Fcn_nk,
                    &rtDW.Fcn1_l);

  /* End of Outputs for SubSystem: '<S166>/Subsystem - pi//2 delay' */

  /* MATLAB Function: '<Root>/RMS Exp' incorporates:
   *  Outport: '<Root>/Vd_g'
   *  Switch: '<S166>/Switch'
   */
  RMSExp(rtDW.Fcn_nk, (double *)&Vd_g, &rtDW.sf_RMSExp);

  /* Sum: '<Root>/Sum10' incorporates:
   *  Outport: '<Root>/Vd_g'
   *  Sum: '<Root>/Sum9'
   */
  rtb_Filter = rtb_Saturation + Vd_g;

  /* Product: '<Root>/Product6' incorporates:
   *  Constant: '<S3>/Constant5'
   *  Inport: '<Root>/VDC'
   *  Inport: '<Root>/Vdc_gain'
   *  Product: '<Root>/Product8'
   *  Product: '<S3>/Divide2'
   */
  rtb_Add2 = 1.0 / Vdc_gain * VDC;

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S1>/Constant5'
   *  Inport: '<Root>/Vabc_gain'
   *  Product: '<Root>/Product'
   *  Product: '<Root>/Product5'
   *  Product: '<Root>/Product6'
   *  Product: '<S1>/Divide2'
   */
  rtb_Divide = rtb_Filter * 2.0 * (1.0 / Vabc_gain) / rtb_Add2;

  /* Sum: '<Root>/Sum11' incorporates:
   *  Switch: '<S172>/Switch'
   */
  rtb_Integrator_l -= rtDW.Fcn1_j;

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/Constant9'
   *  Constant: '<S2>/Constant5'
   *  DiscreteIntegrator: '<S149>/Integrator'
   *  Inport: '<Root>/Vabc_gain'
   *  Product: '<Root>/Product1'
   *  Product: '<Root>/Product7'
   *  Product: '<S2>/Divide2'
   *  Sum: '<Root>/Sum13'
   *  Sum: '<S158>/Sum'
   *  Switch: '<S166>/Switch'
   */
  rtb_Divide1 = ((rtb_Integrator_l + rtDW.Integrator_DSTATE_e) + rtDW.Fcn1_l) *
    2.0 * (1.0 / Vabc_gain) / rtb_Add2;

  /* Sum: '<S13>/Add2' incorporates:
   *  Gain: '<S13>/Gain1'
   *  Inport: '<Root>/phase delay'
   */
  rtb_Add2 = 0.017453292519943295 * phasedelay + rtb_Mod1;

  /* Outputs for Enabled SubSystem: '<S179>/Subsystem - pi//2 delay' incorporates:
   *  EnablePort: '<S182>/Enable'
   */
  /* Fcn: '<S182>/Fcn' incorporates:
   *  Fcn: '<S182>/Fcn1'
   */
  rtb_Divide_idx_0_tmp = cos(rtb_Add2);
  rtb_Divide_idx_0_tmp_0 = sin(rtb_Add2);

  /* Switch: '<S179>/Switch' incorporates:
   *  Fcn: '<S182>/Fcn'
   *  Fcn: '<S182>/Fcn1'
   */
  rtb_Add2 = rtb_Divide * rtb_Divide_idx_0_tmp_0 + rtb_Divide1 *
    rtb_Divide_idx_0_tmp;
  rtb_Divide = -rtb_Divide * rtb_Divide_idx_0_tmp + rtb_Divide1 *
    rtb_Divide_idx_0_tmp_0;

  /* End of Outputs for SubSystem: '<S179>/Subsystem - pi//2 delay' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S178>/Gain3' incorporates:
     *  Switch: '<S179>/Switch'
     */
    rtb_Divide1 = rtConstP.Gain3_Gain[i + 3] * rtb_Divide +
      rtConstP.Gain3_Gain[i] * rtb_Add2;

    /* Saturate: '<Root>/Saturation' incorporates:
     *  Gain: '<S178>/Gain3'
     */
    if (rtb_Divide1 > 0.95) {
      rtb_Divide1 = 0.95;
    } else if (rtb_Divide1 < -0.95) {
      rtb_Divide1 = -0.95;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Outport: '<Root>/m_abc' */
    m_abc[i] = rtb_Divide1;

    /* Product: '<Root>/Product2' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Gain: '<Root>/Gain'
     *  Inport: '<Root>/CCR_max'
     *  Sum: '<Root>/Add1'
     */
    rtb_Gain1[i] = (rtb_Divide1 + 1.0) * 0.5 * CCR_max;
  }

  /* Outport: '<Root>/PWMch1' */
  PWMch1 = rtb_Gain1[0];

  /* Outport: '<Root>/PWMch2' */
  PWMch2 = rtb_Gain1[1];

  /* Outport: '<Root>/PWMch3' */
  PWMch3 = rtb_Gain1[2];

  /* Outport: '<Root>/Vq_g' incorporates:
   *  Switch: '<S166>/Switch'
   */
  Vq_g = rtDW.Fcn1_l;

  /* Outport: '<Root>/Iq' incorporates:
   *  Switch: '<S172>/Switch'
   */
  Iq = rtDW.Fcn1_j;

  /* Outport: '<Root>/Vdc_cal' */
  rtY.Vdc_cal = rtb_Filter;

  /* Gain: '<S52>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S44>/Filter'
   *  Gain: '<S42>/Derivative Gain'
   *  Sum: '<S44>/SumD'
   */
  rtb_Divide = (0.0 - rtDW.Filter_DSTATE) * 100.0;

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/w_ff'
   *  DiscreteIntegrator: '<S49>/Integrator'
   *  Gain: '<S54>/Proportional Gain'
   *  Sum: '<S58>/Sum'
   *  Switch: '<S166>/Switch'
   */
  rtb_Divide1 = ((10.0 * rtDW.Fcn1_l + rtDW.Integrator_DSTATE_f) + rtb_Divide) +
    314.15926535897933;

  /* Outport: '<Root>/Freq' incorporates:
   *  Gain: '<Root>/Gain12'
   */
  Freq = 0.15915 * rtb_Divide1;

  /* Outport: '<Root>/pi_out' */
  rtY.pi_out = rtb_Saturation;

  /* Outport: '<Root>/Theta_g' */
  Theta_g = rtb_Mod1;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.0001 * rtb_Divide1;

  /* Update for DiscreteIntegrator: '<S99>/Integrator' incorporates:
   *  Gain: '<S96>/Integral Gain'
   */
  rtDW.Integrator_DSTATE += 100.0 * rtb_Sum8 * 0.0001;
  if (rtDW.Integrator_DSTATE > 10.0) {
    rtDW.Integrator_DSTATE = 10.0;
  } else if (rtDW.Integrator_DSTATE < -10.0) {
    rtDW.Integrator_DSTATE = -10.0;
  }

  /* End of Update for DiscreteIntegrator: '<S99>/Integrator' */

  /* Update for DiscreteIntegrator: '<S149>/Integrator' incorporates:
   *  Gain: '<S146>/Integral Gain'
   */
  rtDW.Integrator_DSTATE_e += 100.0 * rtb_Integrator_l * 0.0001;

  /* Update for DiscreteIntegrator: '<S49>/Integrator' incorporates:
   *  Gain: '<S46>/Integral Gain'
   *  Switch: '<S166>/Switch'
   */
  rtDW.Integrator_DSTATE_f += 10000.0 * rtDW.Fcn1_l * 0.0001;

  /* Update for DiscreteIntegrator: '<S44>/Filter' */
  rtDW.Filter_DSTATE += 0.0001 * rtb_Divide;
}

/* Model initialize function */
void TPGCI_STM32_4_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
