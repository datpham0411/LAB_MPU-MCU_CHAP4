/*
 * list_tasks.c
 *
 *  Created on: Nov 11, 2024
 *      Author: datph
 */
#include "list_tasks.h"

void LED_RED_test() {
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
void LED_GREEN_test() {
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}
void LED_YELLOW_test() {
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
}
void LED_PURPLE_test() {
	HAL_GPIO_TogglePin(LED_PURPLE_GPIO_Port, LED_PURPLE_Pin);
}
void LED_PINK_test() {
	HAL_GPIO_TogglePin(LED_PINK_GPIO_Port, LED_PINK_Pin);
}

