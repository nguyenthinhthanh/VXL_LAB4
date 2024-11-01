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

Node_t* createTaskNode(void(*pTask)(void),uint32_t Delay, uint32_t Period, uint32_t RunMe){
	Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));

	new_node->Task.pTask = pTask;
	new_node->Task.Delay = Delay;
	new_node->Task.Period = Period;
	new_node->Task.RunMe = RunMe;
	//new_node->Task.TaskId = -1;

	new_node->next = NULL;

	return new_node;
}

void SCH_Init(void){
	taskList = NULL;

	Task_Index = 0;
}

void SCH_Add_Task(void(*pTask)(void), uint32_t Delay, uint32_t Period, uint32_t RunMe){
	Node_t* tmp_node = taskList;
	Node_t* prev_node = NULL;
	Node_t* new_node = createTaskNode(pTask, Delay / TIMER_CYCLE, Period / TIMER_CYCLE, RunMe);

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
		else{
			break;
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

void SCH_ReAdd_Task(void(*pTask)(void), uint32_t Delay, uint32_t Period, uint32_t RunMe){
	Node_t* tmp_node = taskList;
	Node_t* prev_node = NULL;
	Node_t* new_node = createTaskNode(pTask, Delay, Period, RunMe);

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
		else{
			break;
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

void SCH_Dispatch_Task(void){
	Node_t* tmp = taskList;

	if(tmp == NULL){
		return;
	}

	if(tmp->Task.RunMe > 0){
		(*tmp->Task.pTask)();

		tmp->Task.RunMe = tmp->Task.RunMe - 1;

		/*Store task before delete*/
		void(*pTask)(void) = tmp->Task.pTask;
		uint32_t Delay = tmp->Task.Delay;
		uint32_t Period = tmp->Task.Period;
		uint32_t RunMe = tmp->Task.RunMe;

		SCH_Delete_Task();
		SCH_ReAdd_Task(pTask, Delay, Period, RunMe);
	}
}

void SCH_Delete_Task(void){
	/*Delete head node because we using linking list*/
	Node_t* tmp = taskList;
	if(tmp == NULL){
		return;
	}

	taskList = taskList->next;

	free(tmp);
}


