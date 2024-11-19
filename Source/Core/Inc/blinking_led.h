/*
 * blinking_led.h
 *
 *  Created on: Oct 8, 2024
 *      Author: ADMINS
 */

#ifndef INC_BLINKING_LED_H_
#define INC_BLINKING_LED_H_

#include "fsm.h"
#include "timer.h"

#define TIME_SCALER				1000	/*Because we use timer is in ms*/

#define TIME_DURATION_MIN		1
#define TIME_DURATION_MAX		99

extern int Time_LedRed_Duration;
extern int Time_LedYellow_Duration;
extern int Time_LedGreen_Duration;

extern int Time_LedRed_Duration_Temp;
extern int Time_LedYellow_Duration_Temp;
extern int Time_LedGreen_Duration_Temp;

void runBlinkingLed(void);

#endif /* INC_BLINKING_LED_H_ */
