/*
 * schedule.c
 *
 *  Created on: Oct 20, 2024
 *      Author: ADMINS
 */

#include "schedule.h"


uint32_t Task_Index;

/*We implement linking list for O(1) SCH_Update*/
Node_t* taskList;
int size_list;

int arr[20] = {0};

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
	size_list = 0;
	taskList = NULL;

	Error_code_G = 0;

	Task_Index = 0;
}

void SCH_Add_Task(void(*pTask)(void), uint32_t Delay, uint32_t Period, uint32_t RunMe){
//	if(size_list >= MAX_SCHEDULE_TASK){
//		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
//		return;
//	}
	Node_t* tmp_node = taskList;
	Node_t* prev_node = NULL;
	Node_t* new_node = createTaskNode(pTask, Delay / TIMER_CYCLE, Period / TIMER_CYCLE, RunMe);
	//Node_t* travel_node = NULL;

	/*Linking list is empty*/
	if(tmp_node == NULL){
		taskList = new_node;
		size_list++;
		return;
	}

	while(tmp_node != NULL){
		if(new_node->Task.Delay >= tmp_node->Task.Delay){
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
		new_node->next = taskList;
		taskList = new_node;

		/*We need to subtract the counter of task behind*/
		/*travel_node = taskList->next;
		while(travel_node != NULL){
			travel_node->Task.Delay = travel_node->Task.Delay - new_node->Task.Delay;

			travel_node = travel_node->next;
		}*/
		taskList->next->Task.Delay = taskList->next->Task.Delay - taskList->Task.Delay;
	}
	else if(prev_node != NULL && tmp_node == NULL){
		/*Tail node, add to tail*/
		prev_node->next = new_node;
	}
	else{
		/*Add in mid*/
		prev_node->next = new_node;
		new_node->next = tmp_node;

		/*travel_node = tmp_node;
		while(travel_node != NULL){
			travel_node->Task.Delay = travel_node->Task.Delay - new_node->Task.Delay;

			travel_node = travel_node->next;
		}*/
		tmp_node->Task.Delay = tmp_node->Task.Delay - new_node->Task.Delay;
	}

	size_list++;
}

void SCH_ReAdd_Task(void(*pTask)(void), uint32_t Delay, uint32_t Period, uint32_t RunMe){
	/*if(size_list >= MAX_SCHEDULE_TASK){
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		return;
	}*/

	Node_t* tmp_node = taskList;
	Node_t* prev_node = NULL;
	Node_t* new_node = createTaskNode(pTask, Delay, Period, RunMe);
	//Node_t* travel_node = NULL;

	/*Linking list is empty*/
	if(tmp_node == NULL){
		taskList = new_node;
		size_list++;
		return;
	}

	while(tmp_node != NULL){
		if(new_node->Task.Delay >= tmp_node->Task.Delay){
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
		new_node->next = taskList;
		taskList = new_node;

		/*We need to subtract the counter of task behind*/
		/*travel_node = taskList->next;
		while(travel_node != NULL){
			travel_node->Task.Delay = travel_node->Task.Delay - new_node->Task.Delay;

			travel_node = travel_node->next;
		}*/
		taskList->next->Task.Delay = taskList->next->Task.Delay - taskList->Task.Delay;
	}
	else if(prev_node != NULL && tmp_node == NULL){
		/*Tail node, add to tail*/
		prev_node->next = new_node;
	}
	else{
		/*Add in mid*/
		prev_node->next = new_node;
		new_node->next = tmp_node;

		/*travel_node = tmp_node;
		while(travel_node != NULL){
			travel_node->Task.Delay = travel_node->Task.Delay - new_node->Task.Delay;

			travel_node = travel_node->next;
		}*/
		tmp_node->Task.Delay = tmp_node->Task.Delay - new_node->Task.Delay;
	}

	size_list++;
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
		//get_List();

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
		tmp->Task.RunMe = tmp->Task.RunMe - 1;

		(*tmp->Task.pTask)();

		/*Store task before delete*/
		void(*pTask)(void) = tmp->Task.pTask;
		uint32_t Delay = tmp->Task.Delay;
		uint32_t Period = tmp->Task.Period;
		uint32_t RunMe = tmp->Task.RunMe;

		if(tmp->Task.Period == 0){
			/*Oneshot task*/
			SCH_Delete_Task();
		}
		else{
			//SCH_ReAdd_Task(tmp->Task.pTask, tmp->Task.Delay, tmp->Task.Period, tmp->Task.RunMe);
			SCH_Delete_Task();
			SCH_ReAdd_Task(pTask, Delay, Period, RunMe);
		}
	}

	SCH_Report_Status();
}

void SCH_Delete_Task(void){
	/*Delete head node because we using linking list*/
	Node_t* tmp = taskList;
	if(tmp == NULL){
		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		return;
	}

	taskList = taskList->next;

	size_list--;

	free(tmp);
}

void SCH_Report_Status(void){
	#ifdef SCH_REPORT_ERRORS
		//ONLY APPLIES IF WE ARE REPORTING ERRORS
		// Check for a new error code
		if (Error_code_G != Last_error_code_G){
			// Negative logic onLEDs assumed


			Error_port->ODR = 255 - Error_code_G;
			Last_error_code_G= Error_code_G;

			if (Error_code_G != 0){
				Error_tick_count_G = 60000;
			} else {
				Error_tick_count_G = 0;
			}
		}
		else {
			if (Error_tick_count_G != 0){
				if (--Error_tick_count_G == 0) {
					Error_code_G = 0; // Reset error code
				}
			}
		}
	#endif
}

void get_List(void){
	Node_t* tmp = taskList;

	int i = 0;
	while(tmp != NULL){
		arr[i] = tmp->Task.Delay;
		tmp = tmp->next;
		i++;
	}
}



