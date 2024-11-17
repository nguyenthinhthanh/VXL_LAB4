/*
 * 7Seg.c
 *
 *  Created on: Sep 28, 2024
 *      Author: ADMINS
 */

#include "7Seg.h"

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
	display7SEG_13(Led13_Count);
	display7SEG_24(Led24_Count);
}
