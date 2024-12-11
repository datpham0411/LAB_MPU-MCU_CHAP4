/*
 * traffic_light.h
 *
 *  Created on: Oct 28, 2024
 *      Author: datph
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"

#define ON GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

void select_num (char group, int num);
void setColor(GPIO_TypeDef *GPIOx, uint16_t Led_1, uint16_t Led_2, uint16_t Led_3, GPIO_PinState Led_1_State, GPIO_PinState Led_2_State, GPIO_PinState Led_3_State);
void setColorToggle(GPIO_TypeDef *GPIOx, uint16_t Led_1, uint16_t Led_2, uint16_t Led_3);

#endif /* INC_TRAFFIC_LIGHT_H_ */
