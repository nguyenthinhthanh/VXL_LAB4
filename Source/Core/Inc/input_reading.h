/*
 * input_reading.h
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "led_display.h"

//we aim to work with more than one buttons
#define N0_OF_BUTTONS 				       3

/*Just for debug*/
/*extern uint8_t flagForButtonPress[N0_OF_BUTTONS];*/

unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);
void button_reading(void);

#endif /* INC_INPUT_READING_H_ */
