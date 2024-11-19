/*
 * fsm.h
 *
 *  Created on: Oct 6, 2024
 *      Author: ADMINS
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "timer.h"
#include "traffic.h"
#include "led_display.h"
#include "blinking_led.h"
#include "input_reading.h"
#include "input_processing.h"

/*Macro for mode 1*/
#define RED_GREEN_STATE_MODE1			0
#define RED_YELLOW_STATE_MODE1			1
#define GREEN_RED_STATE_MODE1			2
#define YELLOW_RED_STATE_MODE1			3

/*Macro for mode 2*/
#define NORMAL_STATE_MODE_2				4

/*Macro for mode 3*/
#define NORMAL_STATE_MODE_3				5

/*Macro for mode 4*/
#define NORMAL_STATE_MODE_4				6

extern int FSM_State;

void setEnviromentStateInit(void);

void setEnviromentState0(void);
void setEnviromentState1(void);
void setEnviromentState2(void);
void setEnviromentState3(void);
void setEnviromentState4(void);
void setEnviromentState5(void);
void setEnviromentState6(void);

void doState0(void);
void doState1(void);
void doState2(void);
void doState3(void);
void doState4(void);
void doState5(void);
void doState6(void);

void runFSM(void);

void fsm_automatic(void);
void fsm_manual(void);
void fsm_setting(void);

#endif /* INC_FSM_H_ */
