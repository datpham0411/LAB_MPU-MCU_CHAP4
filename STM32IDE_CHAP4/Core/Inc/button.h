/*
 * button.h
 *
 *  Created on: Oct 25, 2024
 *      Author: datph
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

void getKeyInputButton1();
void getKeyInputButton2();
void getKeyInputButton3();

#endif /* INC_BUTTON_H_ */
