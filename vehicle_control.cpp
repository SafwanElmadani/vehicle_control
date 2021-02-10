//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: vehicle_control.cpp
//
// Code generated for Simulink model 'vehicle_control'.
//
// Model version                  : 1.40
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Wed Feb 10 12:57:37 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "vehicle_control.h"
#include "vehicle_control_private.h"

// Named constants for Chart: '<Root>/Chart'
const uint8_T vehicle_control_IN_decelerate = 1U;
const uint8_T vehicle_control_IN_idle = 2U;
const uint8_T vehicle_control_IN_s1 = 3U;
const uint8_T vehicle_control_IN_s2 = 4U;
const uint8_T vehicle_control_IN_slow_down1 = 5U;
const uint8_T vehicle_control_IN_speed_up1 = 6U;
const uint8_T vehicle_control_IN_speed_up2 = 7U;
const uint8_T vehicle_control_IN_wait = 8U;

// Block signals (default storage)
B_vehicle_control_T vehicle_control_B;

// Block states (default storage)
DW_vehicle_control_T vehicle_control_DW;

// Real-time model
RT_MODEL_vehicle_control_T vehicle_control_M_ = RT_MODEL_vehicle_control_T();
RT_MODEL_vehicle_control_T *const vehicle_control_M = &vehicle_control_M_;

// Model step function
void vehicle_control_step(void)
{
  SL_Bus_vehicle_control_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_vehicle_control_std_msgs_Int8 b_varargout_2;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S5>/In1'

  b_varargout_1 = Sub_vehicle_control_14.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (b_varargout_1) {
    vehicle_control_B.In1 = b_varargout_2;
  }

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Chart: '<Root>/Chart'
  if (vehicle_control_DW.temporalCounter_i1 < 511U) {
    vehicle_control_DW.temporalCounter_i1 = static_cast<uint16_T>
      (vehicle_control_DW.temporalCounter_i1 + 1U);
  }

  if (vehicle_control_DW.is_active_c3_vehicle_control == 0U) {
    vehicle_control_DW.is_active_c3_vehicle_control = 1U;
    vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_idle;
    vehicle_control_B.accel = 0.0;
  } else {
    switch (vehicle_control_DW.is_c3_vehicle_control) {
     case vehicle_control_IN_decelerate:
      vehicle_control_B.accel = -1.0;
      if (vehicle_control_DW.temporalCounter_i1 >= 300U) {
        vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_s1;
        vehicle_control_B.accel = 0.0;
      }
      break;

     case vehicle_control_IN_idle:
      vehicle_control_B.accel = 0.0;
      vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_wait;
      break;

     case vehicle_control_IN_s1:
      vehicle_control_B.accel = 0.0;
      if (vehicle_control_B.In1.Data == 2) {
        vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_s1;
        vehicle_control_B.accel = 0.0;
      } else {
        if (vehicle_control_B.In1.Data != 2) {
          vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_idle;
          vehicle_control_B.accel = 0.0;
        }
      }
      break;

     case vehicle_control_IN_s2:
      vehicle_control_B.accel = 0.0;
      if (vehicle_control_B.In1.Data != 1) {
        vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_idle;
        vehicle_control_B.accel = 0.0;
      } else {
        if (vehicle_control_B.In1.Data == 1) {
          vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_s2;
          vehicle_control_B.accel = 0.0;
        }
      }
      break;

     case vehicle_control_IN_slow_down1:
      vehicle_control_B.accel = 0.0;
      if (vehicle_control_DW.temporalCounter_i1 >= 300U) {
        vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_speed_up2;
        vehicle_control_DW.temporalCounter_i1 = 0U;
        vehicle_control_B.accel = 1.5;
      }
      break;

     case vehicle_control_IN_speed_up1:
      vehicle_control_B.accel = 1.0;
      if (vehicle_control_DW.temporalCounter_i1 >= 300U) {
        vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_slow_down1;
        vehicle_control_DW.temporalCounter_i1 = 0U;
        vehicle_control_B.accel = 0.0;
      }
      break;

     case vehicle_control_IN_speed_up2:
      vehicle_control_B.accel = 1.5;
      if (vehicle_control_DW.temporalCounter_i1 >= 300U) {
        vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_s2;
        vehicle_control_B.accel = 0.0;
      }
      break;

     default:
      // case IN_wait:
      switch (vehicle_control_B.In1.Data) {
       case 2:
        vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_decelerate;
        vehicle_control_DW.temporalCounter_i1 = 0U;
        vehicle_control_B.accel = -1.0;
        break;

       case 1:
        vehicle_control_DW.is_c3_vehicle_control = vehicle_control_IN_speed_up1;
        vehicle_control_DW.temporalCounter_i1 = 0U;
        vehicle_control_B.accel = 1.0;
        break;
      }
      break;
    }
  }

  // End of Chart: '<Root>/Chart'

  // BusAssignment: '<Root>/Bus Assignment'
  rtb_BusAssignment.Data = vehicle_control_B.accel;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_vehicle_control_30.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void vehicle_control_initialize(void)
{
  {
    static const char_T tmp_0[12] = { '/', 't', 'i', 'm', 'e', 'd', '_', 'a',
      'c', 'c', 'e', 'l' };

    static const char_T tmp[7] = { '/', 'c', 'h', 'o', 'i', 'c', 'e' };

    int32_T i;
    char_T b_zeroDelimTopic_0[13];
    char_T b_zeroDelimTopic[8];

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S5>/Out1' incorporates:
    //   Inport: '<S5>/In1'

    vehicle_control_B.In1 = vehicle_control_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    vehicle_control_DW.obj_p.matlabCodegenIsDeleted = false;
    vehicle_control_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Sub_vehicle_control_14.createSubscriber(&b_zeroDelimTopic[0], 1);
    vehicle_control_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    vehicle_control_DW.obj.matlabCodegenIsDeleted = false;
    vehicle_control_DW.obj.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Pub_vehicle_control_30.createPublisher(&b_zeroDelimTopic_0[0], 1);
    vehicle_control_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void vehicle_control_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!vehicle_control_DW.obj_p.matlabCodegenIsDeleted) {
    vehicle_control_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!vehicle_control_DW.obj.matlabCodegenIsDeleted) {
    vehicle_control_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
