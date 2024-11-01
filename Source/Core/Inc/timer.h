/*
 * timer.h
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

#define FREQUENCY				8000000	/*8Mhz frequency*/

#define MAX_TIMER				10

extern int TIMER_CYCLE;
extern int COUNTER;
extern int PRESCALER;

extern int Timer_Counter[MAX_TIMER];
extern int Timer_Flag[MAX_TIMER];


int getTimerFlags(int index);

void setTimer(int index, int duration);

void runTimer(void);

#endif /* INC_TIMER_H_ */
