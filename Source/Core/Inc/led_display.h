/*
 * led_display.h
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"
#include "timer.h"

#define	DURATION_FOR_SEVENT_SEG_SCAN_LED	250	/*50ms for scanning 7Seg led*/

extern int Led13_Count;
extern int Led24_Count;

void updateLedBuffer(int index, int value);

void disable7SEG(int index);

void enable7SEGNoClear(int index);

void enable7SEG(int index);

void display7SEG(int number);

void display7SEG_13(int number);

void display7SEG_24(int number);

void run7Seg(void);

#endif /* INC_LED_DISPLAY_H_ */
