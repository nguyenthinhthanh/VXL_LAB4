/*
 * watch_dog.h
 *
 *  Created on: Nov 5, 2024
 *      Author: ADMINS
 */

#ifndef INC_WATCH_DOG_H_
#define INC_WATCH_DOG_H_

#include "main.h"

void MX_IWDG_Init(void);

void Watchdog_Refresh(void);

unsigned char Is_Watchdog_Reset(void);

void Watchdog_Counting(void);

void Reset_Watchdog_Counting(void);

#endif /* INC_WATCH_DOG_H_ */
