/*
 * Traffic.h
 *
 *  Created on: Sep 28, 2024
 *      Author: ADMINS
 */

#ifndef INC_TRAFFIC_H_
#define INC_TRAFFIC_H_

#include "main.h"

#define RED_GREEN_STATE			0
#define RED_YELLOW_STATE		1
#define GREEN_RED_STATE			2
#define YELLOW_RED_STATE		3

#define TIME_RED		5
#define TIME_GREEN		3
#define TIME_YELLOW		2

extern int Led13_Count;
extern int Led24_Count;

extern int state_traffic;

void doRedGreen_Traffic(void);

void doRedYellow_Traffic(void);

void doGreenRed_Traffic(void);

void doYellowRed_Traffic(void);

void runLed(void);

void runTraffic(void);

#endif /* INC_TRAFFIC_H_ */
