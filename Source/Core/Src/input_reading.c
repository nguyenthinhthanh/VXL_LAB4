/*
 * input_reading.c
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */


#include "main.h"
#include "input_reading.h"

//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   100
#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET
//the buffer that the final result is stored after
//debouncing
//static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS] = {BUTTON_IS_RELEASED};
//we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS] = {BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS] = {BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer3[N0_OF_BUTTONS] = {BUTTON_IS_RELEASED};
//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress[N0_OF_BUTTONS] = {0};
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS] = {0};
//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS] = {0};

unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;

	if(flagForButtonPress[index]){
		flagForButtonPress[index] = 0;
		return 1;
	}

	return 0;
}

unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xff;

	if(flagForButtonPress1s[index]){
		flagForButtonPress1s[index] = 0;
		return 1;
	}

	return 0;
}

/*Many bug in input_reading :))*/
void button_reading(void){
	for(int i = 0; i < N0_OF_BUTTONS; i++){
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		// Chose button port
		if(i == 0){
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port, BUTTON_0_Pin);
		}
		else if(i == 1){
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
		}
		else if( i == 2){
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
		}
		else{
			/*This is fault value of index button*/
		}

		if((debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) &&
				(debounceButtonBuffer2[i] == debounceButtonBuffer3[i])){
			if(debounceButtonBuffer1[i] != buttonBuffer[i]){
				buttonBuffer[i] = debounceButtonBuffer1[i];
				if(buttonBuffer[i] == BUTTON_IS_PRESSED){
					counterForButtonPress1s[i] = DURATION_FOR_AUTO_INCREASING;
					flagForButtonPress[i] = 1;
				}
			}
			else{
				counterForButtonPress1s[i]--;
				if(counterForButtonPress1s <= 0){
					counterForButtonPress1s[i] = DURATION_FOR_AUTO_INCREASING;
					if(buttonBuffer[i] == BUTTON_IS_PRESSED){
						flagForButtonPress1s[i] = 1;
					}
				}
			}
		}
	}
}

/*
KeyReg2 = KeyReg1;
KeyReg1 = KeyReg0;
// Add your key
KeyReg0 = HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin);

 if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
	    if (KeyReg2 != KeyReg3){
			KeyReg3 = KeyReg2;
			if (KeyReg3 == PRESSED_STATE){
				TimeOutForKeyPress = 500;
				//subKeyProcess();
				button1_flag = 1;
			}
	    }
		else{
			TimeOutForKeyPress --;
			if (TimeOutForKeyPress == 0){
				TimeOutForKeyPress = 500;
				if (KeyReg3 == PRESSED_STATE){
					//subKeyProcess();
					button1_flag = 1;
				}
			}
		}
	}
*/

