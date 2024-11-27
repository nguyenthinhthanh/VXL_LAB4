/*
 * fsm.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ADMINS
 */

#include "fsm.h"

/*Default Mode*/
int FSM_State;

void setEnviromentStateInit(void){
	/*Led13_Count = 5;
	Led24_Count = 3;

	Update 7Seg buffer for scanning
	updateLedBuffer(0, Led13_Count);
	updateLedBuffer(1, 0);				In mode 1,2 this 7Seg is 0
	updateLedBuffer(2, 0);				In mode 1,2 this 7Seg is 0
	updateLedBuffer(3, Led24_Count);

	Set timer for blinking led
	setTimer(BLINKING_LED_RED_TIMER, (Time_LedRed_Duration * TIME_SCALER)/2);
	setTimer(BLINKING_LED_YELLOW_TIMER, (Time_LedYellow_Duration * TIME_SCALER)/2);
	setTimer(BLINKING_LED_GREEN_TIMER, (Time_LedGreen_Duration * TIME_SCALER)/2);

	setEnviromentState0();
	FSM_State = RED_GREEN_STATE_MODE1;*/
}

void setEnviromentState0(void){
	/*Led13_Count = 5;
	Led24_Count = 3;

	Enable 7Seg we use and disable 7Seg we not use
	disable7SEG(1);
	disable7SEG(2);
	enable7SEGNoClear(0);
	enable7SEGNoClear(3);

	7Seg display immediate
	display7SEG_13(Led13_Count);
	display7SEG_24(Led24_Count);

	Active timer
	activeTimer(DELAY_TIMER);
	activeTimer(TRAFFIC_TIMER);
	ignoreTimer(BLINKING_LED_RED_TIMER);
	ignoreTimer(BLINKING_LED_YELLOW_TIMER);
	ignoreTimer(BLINKING_LED_GREEN_TIMER);

	We not use scanning 7Seg in Mode 1
	ignoreTimer(SEVENT_SEG_SCAN_TIMER);

	Set timer for scanning 7Seg for reset counter value
	setTimer(SEVENT_SEG_SCAN_TIMER, DURATION_FOR_SEVENT_SEG_SCAN_LED);

	setTimer(DELAY_TIMER, 0);
	setTimer(TRAFFIC_TIMER, 3000);*/

	Led13_Count = 5;
	Led24_Count = 3;

	/*Enable 7Seg we use and disable 7Seg we not use*/
	disable7SEG(1);
	disable7SEG(2);
	enable7SEGNoClear(0);
	enable7SEGNoClear(3);

	/*7Seg display immediate*/
	display7SEG_13(Led13_Count);
	display7SEG_24(Led24_Count);

	ignoreTimer(BLINKING_LED_RED_TIMER);
	ignoreTimer(BLINKING_LED_YELLOW_TIMER);
	ignoreTimer(BLINKING_LED_GREEN_TIMER);

	state_traffic = RED_GREEN_STATE;
	FSM_State = RED_GREEN_STATE_MODE1;
}

void setEnviromentState1(void){
	//Led24_Count = 2;
	//setTimer(TRAFFIC_TIMER, 2000);
}
void setEnviromentState2(void){
	/*Led13_Count = 3;
	Led24_Count = 5;
	setTimer(TRAFFIC_TIMER, 3000);*/
}

void setEnviromentState3(void){
	/*Led13_Count = 2;
	setTimer(TRAFFIC_TIMER, 2000);*/
}

void setEnviromentState4(void){
	/*Clear all traffic led in mode 1*/
	/*clearAllTraffic();
	Ignore timer delay and timer traffic
	ignoreTimer(DELAY_TIMER);
	ignoreTimer(TRAFFIC_TIMER);

	activeTimer(SEVENT_SEG_SCAN_TIMER);*/

	clearAllTraffic();
}

void setEnviromentState5(void){
	/*Clear all traffic led in mode 1
	clearAllTraffic();
	Ignore timer delay and timer traffic
	ignoreTimer(DELAY_TIMER);
	ignoreTimer(TRAFFIC_TIMER);*/

	clearAllTraffic();
}

void setEnviromentState6(void){
	/*Clear all traffic led in mode 1
	clearAllTraffic();
	Ignore timer delay and timer traffic
	ignoreTimer(DELAY_TIMER);
	ignoreTimer(TRAFFIC_TIMER);*/

	clearAllTraffic();
}

void doState0(void){
	doRedGreen_Traffic();

	if(getTimeFlag()){

		/*Just for debug
		HAL_GPIO_WritePin(CHECK_GPIO_Port, CHECK_Pin, GPIO_PIN_RESET);*/

		display7SEG_13(Led13_Count);
		display7SEG_24(Led24_Count);

		/*Led13_Count--;
		Led24_Count--;*/

		//updateLedBuffer(0, Led13_Count);
		//updateLedBuffer(3, Led24_Count);

		clearTimeFlag();
	}
}

void doState1(void){
	doRedYellow_Traffic();

	if(getTimeFlag()){
		display7SEG_13(Led13_Count);
		display7SEG_24(Led24_Count);

		/*Led13_Count--;
		Led24_Count--;*/

		//updateLedBuffer(0, Led13_Count);
		//updateLedBuffer(3, Led24_Count);

		clearTimeFlag();
	}
}

void doState2(void){
	doGreenRed_Traffic();

	if(getTimeFlag()){
		display7SEG_13(Led13_Count);
		display7SEG_24(Led24_Count);

		/*Led13_Count--;
		Led24_Count--;*/

		//updateLedBuffer(0, Led13_Count);
		//updateLedBuffer(3, Led24_Count);

		clearTimeFlag();
	}
}

void doState3(void){
	doYellowRed_Traffic();

	if(getTimeFlag()){
		display7SEG_13(Led13_Count);
		display7SEG_24(Led24_Count);

		/*Led13_Count--;
		Led24_Count--;*/

		//updateLedBuffer(0, Led13_Count);
		//updateLedBuffer(3, Led24_Count);

		clearTimeFlag();
	}
}

void doState4(void){
	/*Display two 7seg for time duration value
	and one 7seg for mode becaue mode 1->4*/
	//display7SEG_13((int)(Time_LedRed_Duration_Temp / 10));
	//display7SEG_Time((int)(Time_LedRed_Duration_Temp % 10));
	/*Display mode*/
	//display7SEG_24(FSM_State - 2);
	updateLedBuffer(0, Time_LedRed_Duration_Temp / 10);
	updateLedBuffer(1, Time_LedRed_Duration_Temp % 10);
	updateLedBuffer(2, (FSM_State - 2) / 10);
	updateLedBuffer(3, (FSM_State - 2) % 10);

	if(buttonState[1] == BUTTON_PRESSED){
		/*Increase time duration by one*/
		Time_LedRed_Duration_Temp++;

		if(Time_LedRed_Duration_Temp > 99){
			Time_LedRed_Duration_Temp = 1;
		}
	}

	if(buttonState[2] == BUTTON_PRESSED){
		/*Update blinking time duration*/
		Time_LedRed_Duration = Time_LedRed_Duration_Temp;
		//setTimer(BLINKING_LED_RED_TIMER, (Time_LedRed_Duration * TIME_SCALER)/2);
	}
}

void doState5(void){
	/*Display two 7seg for time duration value
	and one 7seg for mode becaue mode 1->4*/
	//display7SEG_13((int)(Time_LedYellow_Duration_Temp / 10));
	//display7SEG_Time((int)(Time_LedYellow_Duration_Temp % 10));
	/*Display mode*/
	//display7SEG_24(FSM_State - 2);

	updateLedBuffer(0, Time_LedYellow_Duration_Temp / 10);
	updateLedBuffer(1, Time_LedYellow_Duration_Temp % 10);
	updateLedBuffer(2, (FSM_State - 2) / 10);
	updateLedBuffer(3, (FSM_State - 2) % 10);

	if(buttonState[1] == BUTTON_PRESSED){
		/*Increase time duration by one*/
		Time_LedYellow_Duration_Temp++;

		if(Time_LedYellow_Duration_Temp > 99){
			Time_LedYellow_Duration_Temp = 1;
		}
	}

	if(buttonState[2] == BUTTON_PRESSED){
		/*Update blinking time duration*/
		Time_LedYellow_Duration = Time_LedYellow_Duration_Temp;
		//setTimer(BLINKING_LED_YELLOW_TIMER, (Time_LedGreen_Duration * TIME_SCALER)/2);
	}
}

void doState6(void){
	/*Display two 7seg for time duration value
	and one 7seg for mode becaue mode 1->4*/
	//display7SEG_13((int)(Time_LedGreen_Duration_Temp / 10));
	//display7SEG_Time((int)(Time_LedGreen_Duration_Temp % 10));
	/*Display mode*/
	//display7SEG_24(FSM_State - 2);

	updateLedBuffer(0, Time_LedGreen_Duration_Temp / 10);
	updateLedBuffer(1, Time_LedGreen_Duration_Temp % 10);
	updateLedBuffer(2, (FSM_State - 2) / 10);
	updateLedBuffer(3, (FSM_State - 2) % 10);

	if(buttonState[1] == BUTTON_PRESSED){
		/*Increase time duration by one*/
		Time_LedGreen_Duration_Temp++;

		if(Time_LedGreen_Duration_Temp > 99){
			Time_LedGreen_Duration_Temp = 1;
		}
	}

	if(buttonState[2] == BUTTON_PRESSED){
		/*Update blinking time duration*/
		Time_LedGreen_Duration = Time_LedGreen_Duration_Temp;
		//setTimer(BLINKING_LED_GREEN_TIMER, (Time_LedGreen_Duration * TIME_SCALER)/2);
	}
}

void fsm_automatic(){
	switch(FSM_State){
		case RED_GREEN_STATE_MODE1:
			doState0();

			if(state_traffic == RED_YELLOW_STATE){
				setEnviromentState1();
				FSM_State = RED_YELLOW_STATE_MODE1;
			}

			if(is_button_pressed(0)){
				setEnviromentState4();	/*Mode 2*/
				FSM_State = NORMAL_STATE_MODE_2;
			}
			break;
		case RED_YELLOW_STATE_MODE1:
			doState1();

			if(state_traffic == GREEN_RED_STATE){
				setEnviromentState2();
				FSM_State = GREEN_RED_STATE_MODE1;
			}

			if(buttonState[0] == BUTTON_PRESSED){
				setEnviromentState4();	/*Mode 2*/
				FSM_State = NORMAL_STATE_MODE_2;
			}
			break;
		case GREEN_RED_STATE_MODE1:
			doState2();

			if(state_traffic == YELLOW_RED_STATE){
				setEnviromentState3();
				FSM_State = YELLOW_RED_STATE_MODE1;
			}

			if(buttonState[0] == BUTTON_PRESSED){
				setEnviromentState4();	/*Mode 2*/
				FSM_State = NORMAL_STATE_MODE_2;
			}
			break;
		case YELLOW_RED_STATE_MODE1:
			doState3();

			if(state_traffic == RED_GREEN_STATE){
				setEnviromentState0();
				FSM_State = RED_GREEN_STATE_MODE1;
			}

			if(buttonState[0] == BUTTON_PRESSED){
				setEnviromentState4();	/*Mode 2*/
				FSM_State = NORMAL_STATE_MODE_2;
			}
			break;
		default:
			break;
		}

		return;
}

void fsm_manual(){
	switch(FSM_State){
	case NORMAL_STATE_MODE_2:
		doState4();

		if(buttonState[0] == BUTTON_PRESSED){
			setEnviromentState5();	/*Mode 3*/
			FSM_State = NORMAL_STATE_MODE_3;
		}
		break;
	case NORMAL_STATE_MODE_3:
		doState5();

		if(buttonState[0] == BUTTON_PRESSED){
			setEnviromentState6();	/*Mode 4*/
			FSM_State = NORMAL_STATE_MODE_4;
		}
		break;
	case NORMAL_STATE_MODE_4:
		doState6();

		if(buttonState[0] == BUTTON_PRESSED){
			setEnviromentState0();	/*Mode 1*/
			FSM_State = RED_GREEN_STATE_MODE1;
		}
		break;
	default:
		break;
	}

	return;
}

void fsm_setting(){
	return;
}
