//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: vehicle_control.h
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
#ifndef RTW_HEADER_vehicle_control_h_
#define RTW_HEADER_vehicle_control_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "vehicle_control_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  real_T accel;                        // '<Root>/Chart'
  SL_Bus_vehicle_control_std_msgs_Int8 In1;// '<S5>/In1'
} B_vehicle_control_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slroscpp_internal_block_P_T obj; // '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_p;// '<S4>/SourceBlock'
  uint16_T temporalCounter_i1;         // '<Root>/Chart'
  uint8_T is_active_c3_vehicle_control;// '<Root>/Chart'
  uint8_T is_c3_vehicle_control;       // '<Root>/Chart'
} DW_vehicle_control_T;

// Parameters (default storage)
struct P_vehicle_control_T_ {
  SL_Bus_vehicle_control_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                            //  Referenced by: '<S1>/Constant'

  SL_Bus_vehicle_control_std_msgs_Int8 Out1_Y0;// Computed Parameter: Out1_Y0
                                                  //  Referenced by: '<S5>/Out1'

  SL_Bus_vehicle_control_std_msgs_Int8 Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                           //  Referenced by: '<S4>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_vehicle_control_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_vehicle_control_T vehicle_control_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_vehicle_control_T vehicle_control_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_vehicle_control_T vehicle_control_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void vehicle_control_initialize(void);
  extern void vehicle_control_step(void);
  extern void vehicle_control_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_vehicle_control_T *const vehicle_control_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'vehicle_control'
//  '<S1>'   : 'vehicle_control/Blank Message'
//  '<S2>'   : 'vehicle_control/Chart'
//  '<S3>'   : 'vehicle_control/Publish'
//  '<S4>'   : 'vehicle_control/Subscribe'
//  '<S5>'   : 'vehicle_control/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_vehicle_control_h_

//
// File trailer for generated code.
//
// [EOF]
//
