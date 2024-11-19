/*
 * input_processing.c
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */


#include "input_processing.h"

enum ButtonState buttonState[N0_OF_BUTTONS] = {BUTTON_RELEASED,BUTTON_RELEASED,BUTTON_RELEASED};

void fsm_for_input_processing(void){
	for(int i=0;i<N0_OF_BUTTONS;i++){
		switch(buttonState[i]){
		case BUTTON_RELEASED:
			if(is_button_pressed(i)){
				buttonState[i] = BUTTON_PRESSED;
				// Increase value PORTA by one
			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(i)){
				buttonState[i] = BUTTON_RELEASED;
			} else {
				if(is_button_pressed_1s(i)){
					// Set timer 500ms for auto increase
					//setTimer(AUTO_INCREASE, 500);
					buttonState[i] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(i)){
				buttonState[i] = BUTTON_RELEASED;
			}
			else{
				// If timer flag 500ms increase one value
				/*if(getTimerFlags(AUTO_INCREASE)){
					// Increase value PORTA by one
					//setTimer(AUTO_INCREASE, 500);
				}*/
			}
			break;
		}
	}
}
