//#############################################################################
//
// FILE:   pfc1ph3ilttpl_settings.h
//
// TITLE:  pfc1ph3ilttpl_settings.h
//
//#############################################################################
// $TI Release: $
// $Release Date: $
// Copyright (C) {2015} Texas Instruments Incorporated - http://www.ti.com/
// * ALL RIGHTS RESERVED*
//#############################################################################

#ifndef _PROJSETTINGS_H
#define _PROJSETTINGS_H

#ifdef __cplusplus

extern "C" {
#endif

//*****************************************************************************
//defines
//*****************************************************************************

/* Device Related Defines */
#define CPU_SYS_CLOCK (100*1000000)
#define PWMSYSCLOCK_FREQ (100*1000000)
#define ECAPSYSCLOCK_FREQ	(100*1000000)

/* Project Options*/
//=============================================================================
// Incremental Build options for System check-out
//=============================================================================
// BUILD 1 	 Open Loop Check
// BUILD 2   Closed Current Loop Check
// BUILD 3   Closed Voltage Loop Check
#define INCR_BUILD 3

// 1 means control runs on C28x , otherwise it will run on CLA
#define C28x_CORE 1
#define CLA_CORE 2
#define CONTROL_RUNNING_ON 1

// Check system under DC condition (cleanest SFRA curves) 0 is FALSE, 1 is TRUE
#define DC_CHECK 0 

//Enable Disable Adaptive Deadtime
#define ADAPTIVE_DEADTIME 0

// set 1 to enable phase shedding 0 to disable 
#define PHASE_SHEDDING_ENABLED 0

// set 1 to enable non linear voltage loop 0 to disable 
#define NON_LINEAR_VOLTAGE_LOOP 0

/* Power Stage Related Values*/
#define PFC_PWM_SWITCHING_FREQUENCY ((float32_t)100*1000)
#define PFC_PWM_PERIOD ((PWMSYSCLOCK_FREQ)/(PFC_PWM_SWITCHING_FREQUENCY))

#define PFC_DEADBAND_RED_HS_US 0.2f
#define PFC_DEADBAND_FED_HS_US 0.2f

#define HIGH_FREQ_PWM_DEADBAND_FED_COUNT (int)((float32_t)PFC_DEADBAND_FED_HS_US*(float32_t)PWMSYSCLOCK_FREQ*(float32_t)0.000001)
#define HIGH_FREQ_PWM_DEADBAND_RED_COUNT (int)((float32_t)PFC_DEADBAND_RED_HS_US*(float32_t)PWMSYSCLOCK_FREQ*(float32_t)0.000001)

#define VAC_MAX_SENSE       676.1f
#define VDCBUS_MAX_SENSE    654.28f
#define I_MAX_SENSE         54.5f
#define I_TRIP_LIMIT        30
#define VAC_TYPICAL         120

#define VBUS_TYPICAL 		400

#define PFC_INDUCTOR_VALUE  ((float32_t)0.276*0.001)

/* Control Loop Design */
#define CONTROL_ISR_FREQUENCY ((PFC_PWM_SWITCHING_FREQUENCY)/(CNTRL_ISR_FREQ_RATIO))
#define	CNTRL_ISR_FREQ_RATIO	1
#define VOLTAGE_LOOP_RUN_RATIO	1

//SFRA Options 	
#define SFRA_DISABLED 0
#define SFRA_CURRENT 1
#define SFRA_VOLTAGE 2

#define SFRA_TYPE			1
#if SFRA_TYPE == SFRA_CURRENT
#define SFRA_ISR_FREQ       CONTROL_ISR_FREQUENCY
#else
#define SFRA_ISR_FREQ       INSTRUMENTATION_ISR_FREQUENCY
#endif

#define PI_VALUE 3.141592653589f

#define GI_PI_KP	(float32_t) 0.3496701328
#define GI_PI_KI	(float32_t) 0.0018867338

#define GV_PI_KP	(float32_t) 0.7999321416
#define GV_PI_KI	(float32_t) 0.0001357168

//=============================================================================
// User code settings file
//=============================================================================
#include "pfc1ph3ilttpl_user_settings.h"

#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif //_PROJSETTINGS_H
