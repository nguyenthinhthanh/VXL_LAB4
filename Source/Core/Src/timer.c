/*
 * timer.c
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#include "timer.h"

int TIMER_CYCLE = 10;
int COUNTER		= 9;
int PRESCALER	= 7999;

int Timer_Ignore[MAX_TIMER] = {0};
int Timer_Flag[MAX_TIMER] = {0};
int Timer_Counter[MAX_TIMER] = {0};

int getTimerFlags(int index){
	return Timer_Flag[index];
}

void ignoreTimer(int index){
	Timer_Ignore[index] = 1;
}

void activeTimer(int index){
	Timer_Ignore[index] = 0;
}

void setTimer(int index, int duration){
	Timer_Counter[index] = duration/TIMER_CYCLE;
	Timer_Flag[index] = 0;
}

void runTimer(void){
	for(int i=0;i<MAX_TIMER;i++){
		if(Timer_Ignore[i]){
			continue;
		}

		Timer_Counter[i]--;
		if(Timer_Counter[i] <= 0){
			Timer_Flag[i] = 1;
		}
	}
}


