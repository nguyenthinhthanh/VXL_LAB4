/*
 * traffic.h
 *
 *  Created on: Oct 6, 2024
 *      Author: ADMINS
 */

#ifndef INC_TRAFFIC_H_
#define INC_TRAFFIC_H_

#include "main.h"

#define TIME_RED		5
#define TIME_GREEN		3
#define TIME_YELLOW		2

void clearAllTraffic(void);

void doRedGreen_Traffic(void);

void doRedYellow_Traffic(void);

void doGreenRed_Traffic(void);

void doYellowRed_Traffic(void);

#endif /* INC_TRAFFIC_H_ */
