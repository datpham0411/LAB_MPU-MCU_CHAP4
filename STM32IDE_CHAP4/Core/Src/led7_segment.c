/*
 * led7_segment.c
 *
 *  Created on: Oct 28, 2024
 *      Author: datph
 */
#include "led7_segment.h"

void display_num (char group, int index, int num) {
	if (group == 'A' && index == 1) {
		HAL_GPIO_WritePin(GPIOA, ENA1_Pin, ON);
		HAL_GPIO_WritePin(GPIOA, ENA2_Pin, OFF);
		select_num('A', num);
	}
	else if (group == 'A' && index == 2) {
		HAL_GPIO_WritePin(GPIOA, ENA2_Pin, ON);
		HAL_GPIO_WritePin(GPIOA, ENA1_Pin, OFF);
		select_num('A', num);
	}
	else if (group == 'B' && index == 1) {
		HAL_GPIO_WritePin(GPIOA, ENB1_Pin, ON);
		HAL_GPIO_WritePin(GPIOA, ENB2_Pin, OFF);
		select_num('B', num);
	}
	else if (group == 'B' && index == 2) {
		HAL_GPIO_WritePin(GPIOA, ENB2_Pin, ON);
		HAL_GPIO_WritePin(GPIOA, ENB1_Pin, OFF);
		select_num('B', num);
	}
}

void display_time() {
	if (timer2_flag == 1 && idx == 0) {
		setTimer2(150);
		display_num('A', 1, (timer1_counter + 100)/1000);
	}
	else if (timer2_flag == 1 && idx == 1) {
		setTimer2(150);
		display_num('A', 2, ((timer1_counter + 100)%1000)/100);
	}
}
