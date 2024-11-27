/*
 * led_display.c
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#include "led_display.h"

const int MAX_LED = 4;

/*int Led13_Count;
int Led24_Count;*/

int index_led = 0;
int led_buffer[4] = {5,0,0,3};

void updateLedBuffer(int index, int value){
	led_buffer[index] = value;
}

void disable7SEG(int index){
	if(index == 0){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
	}
	else if(index == 1){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
	}
	else if(index == 2){
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
	}
	else if(index == 3){
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
	}
	else{

	}
}

void enable7SEGNoClear(int index){
	if(index == 0){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
	}
	else if(index == 1){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
	}
	else if(index == 2){
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
	}
	else if(index == 3){
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
	}
	else{

	}
}

void enable7SEG(int index){
	if(index == 0){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
	}
	else if(index == 1){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
	}
	else if(index == 2){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
	}
	else if(index == 3){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
	}
	else{

	}
}

void display7SEG(int index){
	switch(index){
	case 0:
		enable7SEG(index);
		display7SEG_13(led_buffer[index]);
		break;
	case 1:
		enable7SEG(index);
		display7SEG_13(led_buffer[index]);
		break;
	case 2:
		enable7SEG(index);
		display7SEG_24(led_buffer[index]);
		break;
	case 3:
		enable7SEG(index);
		display7SEG_24(led_buffer[index]);
		break;
	default:
		break;
	}
}

void display7SEG_13(int number){
	if(number == 0){
		/*Number 0 */
		HAL_GPIO_WritePin(SEG13_A_GPIO_Port, SEG13_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG13_B_GPIO_Port, SEG13_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG13_C_GPIO_Port, SEG13_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG13_D_GPIO_Port, SEG13_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG13_E_GPIO_Port, SEG13_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG13_F_GPIO_Port, SEG13_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG13_G_GPIO_Port, SEG13_G_Pin, GPIO_PIN_SET);
	}
	else if(number == 1){
		  /*Number 1 */
		  HAL_GPIO_WritePin(SEG13_A_GPIO_Port, SEG13_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG13_B_GPIO_Port, SEG13_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG13_C_GPIO_Port, SEG13_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG13_D_GPIO_Port, SEG13_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG13_E_GPIO_Port, SEG13_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG13_F_GPIO_Port, SEG13_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG13_G_GPIO_Port, SEG13_G_Pin, GPIO_PIN_SET);


	}
	else if(number == 2){
		  /*Number 2 */
		  HAL_GPIO_WritePin(SEG13_A_GPIO_Port, SEG13_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG13_B_GPIO_Port, SEG13_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG13_C_GPIO_Port, SEG13_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG13_D_GPIO_Port, SEG13_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG13_E_GPIO_Port, SEG13_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG13_F_GPIO_Port, SEG13_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG13_G_GPIO_Port, SEG13_G_Pin, GPIO_PIN_RESET);


	}
	else if(number == 3){
		/*Number 3 */
			  HAL_GPIO_WritePin(SEG13_A_GPIO_Port, SEG13_A_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_B_GPIO_Port, SEG13_B_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_C_GPIO_Port, SEG13_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_D_GPIO_Port, SEG13_D_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_E_GPIO_Port, SEG13_E_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG13_F_GPIO_Port, SEG13_F_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG13_G_GPIO_Port, SEG13_G_Pin, GPIO_PIN_RESET);
	}
	else if(number == 4){
		/*Number 4 */
			  HAL_GPIO_WritePin(SEG13_A_GPIO_Port, SEG13_A_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG13_B_GPIO_Port, SEG13_B_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_C_GPIO_Port, SEG13_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_D_GPIO_Port, SEG13_D_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG13_E_GPIO_Port, SEG13_E_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG13_F_GPIO_Port, SEG13_F_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_G_GPIO_Port, SEG13_G_Pin, GPIO_PIN_RESET);
	}
	else if(number == 5){
		  /*Number 5 */
		  HAL_GPIO_WritePin(SEG13_A_GPIO_Port, SEG13_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG13_B_GPIO_Port, SEG13_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG13_C_GPIO_Port, SEG13_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG13_D_GPIO_Port, SEG13_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG13_E_GPIO_Port, SEG13_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG13_F_GPIO_Port, SEG13_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG13_G_GPIO_Port, SEG13_G_Pin, GPIO_PIN_RESET);
	}
	else if(number == 6){
		 /*Number 6 */
			  HAL_GPIO_WritePin(SEG13_A_GPIO_Port, SEG13_A_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_B_GPIO_Port, SEG13_B_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG13_C_GPIO_Port, SEG13_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_D_GPIO_Port, SEG13_D_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_E_GPIO_Port, SEG13_E_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_F_GPIO_Port, SEG13_F_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_G_GPIO_Port, SEG13_G_Pin, GPIO_PIN_RESET);
	}
	else if(number == 7){
		/*Number 7 */
			  HAL_GPIO_WritePin(SEG13_A_GPIO_Port, SEG13_A_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_B_GPIO_Port, SEG13_B_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_C_GPIO_Port, SEG13_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_D_GPIO_Port, SEG13_D_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG13_E_GPIO_Port, SEG13_E_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG13_F_GPIO_Port, SEG13_F_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG13_G_GPIO_Port, SEG13_G_Pin, GPIO_PIN_SET);
	}
	else if(number == 8){
		/*Number 8 */
			  HAL_GPIO_WritePin(SEG13_A_GPIO_Port, SEG13_A_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_B_GPIO_Port, SEG13_B_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_C_GPIO_Port, SEG13_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_D_GPIO_Port, SEG13_D_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_E_GPIO_Port, SEG13_E_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_F_GPIO_Port, SEG13_F_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_G_GPIO_Port, SEG13_G_Pin, GPIO_PIN_RESET);
	}
	else if(number == 9){
		/*Number 9 */
			  HAL_GPIO_WritePin(SEG13_A_GPIO_Port, SEG13_A_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_B_GPIO_Port, SEG13_B_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_C_GPIO_Port, SEG13_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_D_GPIO_Port, SEG13_D_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_E_GPIO_Port, SEG13_E_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG13_F_GPIO_Port, SEG13_F_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG13_G_GPIO_Port, SEG13_G_Pin, GPIO_PIN_RESET);
	}
	else{
		/*This is fault in number value > 9 || number value < 0*/
	}
}

void display7SEG_24(int number){
	if(number == 0){
		/*Number 0 */
		HAL_GPIO_WritePin(SEG24_A_GPIO_Port, SEG24_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG24_B_GPIO_Port, SEG24_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG24_C_GPIO_Port, SEG24_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG24_D_GPIO_Port, SEG24_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG24_E_GPIO_Port, SEG24_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG24_F_GPIO_Port, SEG24_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG24_G_GPIO_Port, SEG24_G_Pin, GPIO_PIN_SET);
	}
	else if(number == 1){
		  /*Number 1 */
		  HAL_GPIO_WritePin(SEG24_A_GPIO_Port, SEG24_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG24_B_GPIO_Port, SEG24_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG24_C_GPIO_Port, SEG24_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG24_D_GPIO_Port, SEG24_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG24_E_GPIO_Port, SEG24_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG24_F_GPIO_Port, SEG24_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG24_G_GPIO_Port, SEG24_G_Pin, GPIO_PIN_SET);


	}
	else if(number == 2){
		  /*Number 2 */
		  HAL_GPIO_WritePin(SEG24_A_GPIO_Port, SEG24_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG24_B_GPIO_Port, SEG24_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG24_C_GPIO_Port, SEG24_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG24_D_GPIO_Port, SEG24_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG24_E_GPIO_Port, SEG24_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG24_F_GPIO_Port, SEG24_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG24_G_GPIO_Port, SEG24_G_Pin, GPIO_PIN_RESET);


	}
	else if(number == 3){
		/*Number 3 */
			  HAL_GPIO_WritePin(SEG24_A_GPIO_Port, SEG24_A_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_B_GPIO_Port, SEG24_B_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_C_GPIO_Port, SEG24_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_D_GPIO_Port, SEG24_D_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_E_GPIO_Port, SEG24_E_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG24_F_GPIO_Port, SEG24_F_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG24_G_GPIO_Port, SEG24_G_Pin, GPIO_PIN_RESET);
	}
	else if(number == 4){
		/*Number 4 */
			  HAL_GPIO_WritePin(SEG24_A_GPIO_Port, SEG24_A_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG24_B_GPIO_Port, SEG24_B_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_C_GPIO_Port, SEG24_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_D_GPIO_Port, SEG24_D_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG24_E_GPIO_Port, SEG24_E_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG24_F_GPIO_Port, SEG24_F_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_G_GPIO_Port, SEG24_G_Pin, GPIO_PIN_RESET);
	}
	else if(number == 5){
		  /*Number 5 */
		  HAL_GPIO_WritePin(SEG24_A_GPIO_Port, SEG24_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG24_B_GPIO_Port, SEG24_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG24_C_GPIO_Port, SEG24_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG24_D_GPIO_Port, SEG24_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG24_E_GPIO_Port, SEG24_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG24_F_GPIO_Port, SEG24_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG24_G_GPIO_Port, SEG24_G_Pin, GPIO_PIN_RESET);
	}
	else if(number == 6){
		 /*Number 6 */
			  HAL_GPIO_WritePin(SEG24_A_GPIO_Port, SEG24_A_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_B_GPIO_Port, SEG24_B_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG24_C_GPIO_Port, SEG24_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_D_GPIO_Port, SEG24_D_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_E_GPIO_Port, SEG24_E_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_F_GPIO_Port, SEG24_F_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_G_GPIO_Port, SEG24_G_Pin, GPIO_PIN_RESET);
	}
	else if(number == 7){
		/*Number 7 */
			  HAL_GPIO_WritePin(SEG24_A_GPIO_Port, SEG24_A_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_B_GPIO_Port, SEG24_B_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_C_GPIO_Port, SEG24_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_D_GPIO_Port, SEG24_D_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG24_E_GPIO_Port, SEG24_E_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG24_F_GPIO_Port, SEG24_F_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG24_G_GPIO_Port, SEG24_G_Pin, GPIO_PIN_SET);
	}
	else if(number == 8){
		/*Number 8 */
			  HAL_GPIO_WritePin(SEG24_A_GPIO_Port, SEG24_A_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_B_GPIO_Port, SEG24_B_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_C_GPIO_Port, SEG24_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_D_GPIO_Port, SEG24_D_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_E_GPIO_Port, SEG24_E_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_F_GPIO_Port, SEG24_F_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_G_GPIO_Port, SEG24_G_Pin, GPIO_PIN_RESET);
	}
	else if(number == 9){
		/*Number 9 */
			  HAL_GPIO_WritePin(SEG24_A_GPIO_Port, SEG24_A_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_B_GPIO_Port, SEG24_B_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_C_GPIO_Port, SEG24_C_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_D_GPIO_Port, SEG24_D_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_E_GPIO_Port, SEG24_E_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(SEG24_F_GPIO_Port, SEG24_F_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(SEG24_G_GPIO_Port, SEG24_G_Pin, GPIO_PIN_RESET);
	}
	else{
		/*This is fault in number value > 9 || number value < 0*/
	}
}

void run7Seg(void){
	/*if(getTimerFlags(SEVENT_SEG_SCAN_TIMER)){
		display7SEG(index_led);

		index_led++;
		if(index_led >= MAX_LED){
			index_led = 0;
		}

		setTimer(SEVENT_SEG_SCAN_TIMER, DURATION_FOR_SEVENT_SEG_SCAN_LED);
	}*/

	display7SEG(index_led);

	index_led++;
	if(index_led >= MAX_LED){
		index_led = 0;
	}
}
