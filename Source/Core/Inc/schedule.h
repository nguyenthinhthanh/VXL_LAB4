/*
 * schedule.h
 *
 *  Created on: Oct 20, 2024
 *      Author: ADMINS
 */

#ifndef INC_SCHEDULE_H_
#define INC_SCHEDULE_H_

#include <stdint.h>
#include <stdlib.h>
#include "Timer.h"

#define NO_TASK_ID			0
#define MAX_SCHEDULE_TASK	10

typedef struct {
	void (*pTask)(void);

	uint32_t Delay;
	uint32_t Period;
	uint32_t RunMe;

	//uint32_t TaskId;
}sTasks;

typedef struct Node {
	sTasks Task;
	struct Node* next;
}Node_t;

void SCH_Init(void);

void SCH_Add_Task(void(*pTask)(void), uint32_t Delay, uint32_t Period, uint32_t RunMe);

void SCH_ReAdd_Task(void(*pTask)(void), uint32_t Delay, uint32_t Period, uint32_t RunMe);

void SCH_Update(void);

void SCH_Dispatch_Task(void);

void SCH_Delete_Task(void);

#endif /* INC_SCHEDULE_H_ */
