/*
 * schedule.c
 *
 *  Created on: Oct 20, 2024
 *      Author: ADMINS
 */

#include "schedule.h"


uint32_t Task_Index;
sTasks SCH_Tasks[MAX_SCHEDULE_TASK];

/*We implement linking list for O(1) SCH_Update*/
Node_t* taskList;

Node_t* createTaskNode(void(*pTask)(),uint32_t Delay, uint32_t Period){
	Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));

	new_node->Task.pTask = pTask;
	new_node->Task.Delay = Delay / TIMER_CYCLE;
	new_node->Task.Period = Period / TIMER_CYCLE;
	new_node->Task.RunMe = 0;
	//new_node->Task.TaskId = -1;

	new_node->next = NULL;

	return new_node;
}

void SCH_Init(void){
	taskList = NULL;

	Task_Index = 0;
}

void SCH_Add_Task(void(*pTask)(void), uint32_t Delay, uint32_t Period){
	Node_t* tmp_node = taskList;
	Node_t* prev_node = NULL;
	Node_t* new_node = createTaskNode(pTask, Delay, Period);

	/*Linking list is empty*/
	if(tmp_node == NULL){
		taskList = new_node;
		return;
	}

	while(tmp_node != NULL){
		if(new_node->Task.Delay > tmp_node->Task.Delay){
			new_node->Task.Delay = new_node->Task.Delay - tmp_node->Task.Delay;

			prev_node = tmp_node;
			tmp_node = tmp_node->next;
		}
	}

	if(prev_node == NULL){
		/*First node head, add to head*/
		new_node->next = tmp_node;
		taskList = new_node;
	}
	else if(prev_node != NULL && tmp_node == NULL){
		/*Tail node, add to tail*/
		prev_node->next = new_node;
	}
	else{
		/*Add in mid*/
		prev_node->next = new_node;
		new_node->next = tmp_node;
	}
}

/*void SCH_Add_Task(void(*pTask)(void), uint32_t Delay, uint32_t Period){
	if(Task_Index < MAX_SCHEDULE_TASK){
		SCH_Tasks[Task_Index].pTask = pTask;

		SCH_Tasks[Task_Index].Delay = Delay / TIMER_CYCLE;
		SCH_Tasks[Task_Index].Period = Period / TIMER_CYCLE;
		SCH_Tasks[Task_Index].RunMe = 0;

		SCH_Tasks[Task_Index].TaskId = Task_Index;

		Task_Index = Task_Index + 1;
	}
}*/

void SCH_Update(void){
	if(taskList == NULL){
		return;
	}

	Node_t* tmp = taskList;

	if(tmp->Task.Delay > 0){
		tmp->Task.Delay--;
	}
	else{
		tmp->Task.Delay = tmp->Task.Period;
		tmp->Task.RunMe = tmp->Task.RunMe + 1;
	}
}

/*void SCH_Update(void){
	for(int i = 0;i < Task_Index; i++){
		if(SCH_Tasks[i].Delay > 0){
			SCH_Tasks[i].Delay--;
		}
		else{
			SCH_Tasks[i].Delay = SCH_Tasks[i].Period;
			SCH_Tasks[i].RunMe = SCH_Tasks[i].RunMe + 1;
		}
	}
}*/

void SCH_Dispatch_Task(void){
	Node_t* tmp = taskList;

	if(tmp == NULL){
		return;
	}

	if(tmp->Task.RunMe > 0){
		(*tmp->Task.pTask)();

		tmp->Task.RunMe = tmp->Task.RunMe - 1;

		SCH_Delete_Task();
		SCH_Add_Task(tmp->Task.pTask, tmp->Task.Delay, tmp->Task.Period);
	}
}

/*void SCH_Dispatch_Task(void){
	for(int i = 0;i < Task_Index; i++){
		if(SCH_Tasks[i].RunMe > 0){
			SCH_Tasks[i].RunMe = SCH_Tasks[i].RunMe - 1;
			(*SCH_Tasks[i].pTask)();
		}
	}
}*/

void SCH_Delete_Task(void){
	/*Delete head node because we using linking list*/
	Node_t* tmp = taskList;
	if(tmp == NULL){
		return;
	}

	taskList = taskList->next;

	free(tmp);
}
