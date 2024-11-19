/*
 * input_processing.h
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

#include "main.h"
#include "timer.h"
#include "input_reading.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
extern enum ButtonState buttonState[N0_OF_BUTTONS];

void fsm_for_input_processing(void);

#endif /* INC_INPUT_PROCESSING_H_ */
