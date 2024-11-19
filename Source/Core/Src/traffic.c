/*
 * Traffic.c
 *
 *  Created on: Sep 28, 2024
 *      Author: ADMINS
 */


#include "Traffic.h"

int Led13_Count = 5;
int Led24_Count = 3;

int state_traffic = RED_GREEN_STATE;

void doRedGreen_Traffic(void){
	HAL_GPIO_WritePin(LED13_RED_GPIO_Port, LED13_RED_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED24_GREEN_GPIO_Port, LED24_GREEN_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED13_GREEN_GPIO_Port, LED13_GREEN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED13_YELLOW_GPIO_Port, LED13_YELLOW_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED24_RED_GPIO_Port, LED24_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED24_YELLOW_GPIO_Port, LED24_YELLOW_Pin, GPIO_PIN_RESET);
}

void doRedYellow_Traffic(void){
	HAL_GPIO_WritePin(LED24_GREEN_GPIO_Port, LED24_GREEN_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED24_YELLOW_GPIO_Port, LED24_YELLOW_Pin, GPIO_PIN_SET);
}

void doGreenRed_Traffic(void){
	HAL_GPIO_WritePin(LED13_RED_GPIO_Port, LED13_RED_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED24_YELLOW_GPIO_Port, LED24_YELLOW_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED24_RED_GPIO_Port, LED24_RED_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED13_GREEN_GPIO_Port, LED13_GREEN_Pin, GPIO_PIN_SET);
}

void doYellowRed_Traffic(void){
	HAL_GPIO_WritePin(LED13_GREEN_GPIO_Port, LED13_GREEN_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED13_YELLOW_GPIO_Port, LED13_YELLOW_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED24_RED_GPIO_Port, LED24_RED_Pin, GPIO_PIN_SET);
}

void runLed(void){
	if(state_traffic == RED_GREEN_STATE){
		doRedGreen_Traffic();
	}
	else if(state_traffic == RED_YELLOW_STATE){
		doRedYellow_Traffic();
	}
	else if(state_traffic == GREEN_RED_STATE){
		doGreenRed_Traffic();
	}
	else if(state_traffic == YELLOW_RED_STATE){
		doYellowRed_Traffic();
	}
	else{
		/*This is fault state*/
	}
}

void runTraffic(void){
	Led13_Count--;
	Led24_Count--;

	if(Led13_Count == 2 && Led24_Count == 0){
		Led24_Count = 2;
		state_traffic = RED_YELLOW_STATE;

		return;
	}

	if(Led13_Count == 0 && Led24_Count == 0&& state_traffic == RED_YELLOW_STATE){
		Led13_Count = 3;
		Led24_Count = 5;
		state_traffic = GREEN_RED_STATE;

		return;
	}

	if(Led24_Count == 2 && Led13_Count == 0){
		state_traffic = YELLOW_RED_STATE;
		Led13_Count = 2;

		return;
	}

	if(Led13_Count == 0 && Led24_Count == 0&& state_traffic == YELLOW_RED_STATE){
		Led13_Count = 5;
		Led24_Count = 3;
		state_traffic = RED_GREEN_STATE;

		return;
	}
}
