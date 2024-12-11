/*
 * button1.c
 *
 *  Created on: Oct 25, 2024
 *      Author: datph
 */
#include <button.h>

int KeyReg0Button1 = NORMAL_STATE;
int KeyReg1Button1 = NORMAL_STATE;
int KeyReg2Button1 = NORMAL_STATE;
int KeyReg3Button1 = NORMAL_STATE;

int KeyReg0Button2 = NORMAL_STATE;
int KeyReg1Button2 = NORMAL_STATE;
int KeyReg2Button2 = NORMAL_STATE;
int KeyReg3Button2 = NORMAL_STATE;

int KeyReg0Button3 = NORMAL_STATE;
int KeyReg1Button3 = NORMAL_STATE;
int KeyReg2Button3 = NORMAL_STATE;
int KeyReg3Button3 = NORMAL_STATE;

int TimerForKeyPressButton1 = 200;
int button1_flag = 0;

int TimerForKeyPressButton2 = 200;
int button2_flag = 0;

int TimerForKeyPressButton3 = 200;
int button3_flag = 0;

int isButton1Pressed() {
	if(button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcessButton1(){
	button1_flag = 1;
}

void getKeyInputButton1() {
	KeyReg0Button1 = KeyReg1Button1;
	KeyReg1Button1 = KeyReg2Button1;
	KeyReg2Button1 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);

	if ((KeyReg0Button1 == KeyReg1Button1) && (KeyReg1Button1 == KeyReg2Button1)) {
		if (KeyReg3Button1 != KeyReg2Button1) {
			KeyReg3Button1 = KeyReg2Button1;
			if (KeyReg2Button1 == PRESSED_STATE) {
				// TODO
				subKeyProcessButton1();
				TimerForKeyPressButton1 = 200;
			}
		}
		else {
			--TimerForKeyPressButton1;
			if (TimerForKeyPressButton1 == 0) {
				//TODO
				if (KeyReg2Button1 == PRESSED_STATE) {
					KeyReg3Button1 = NORMAL_STATE;
				}
			}
		}
	}
}

int isButton2Pressed() {
	if(button2_flag == 1) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcessButton2(){
	button2_flag = 1;
}

void getKeyInputButton2() {
	KeyReg0Button2 = KeyReg1Button2;
	KeyReg1Button2 = KeyReg2Button2;
	KeyReg2Button2 = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);

	if ((KeyReg0Button2 == KeyReg1Button2) && (KeyReg1Button2 == KeyReg2Button2)) {
		if (KeyReg3Button2 != KeyReg2Button2) {
			KeyReg3Button2 = KeyReg2Button2;
			if (KeyReg2Button2 == PRESSED_STATE) {
				// TODO
				subKeyProcessButton2();
				TimerForKeyPressButton2 = 200;
			}
		}
		else {
			--TimerForKeyPressButton2;
			if (TimerForKeyPressButton2 == 0) {
				//TODO
				if (KeyReg2Button2 == PRESSED_STATE) {
					KeyReg3Button2 = NORMAL_STATE;
				}
			}
		}
	}
}

int isButton3Pressed() {
	if(button3_flag == 1) {
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcessButton3(){
	button3_flag = 1;
}

void getKeyInputButton3() {
	KeyReg0Button3 = KeyReg1Button3;
	KeyReg1Button3 = KeyReg2Button3;
	KeyReg2Button3 = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);

	if ((KeyReg0Button3 == KeyReg1Button3) && (KeyReg1Button3 == KeyReg2Button3)) {
		if (KeyReg3Button3 != KeyReg2Button3) {
			KeyReg3Button3 = KeyReg2Button3;
			if (KeyReg2Button3 == PRESSED_STATE) {
				// TODO
				subKeyProcessButton3();
				TimerForKeyPressButton3 = 200;
			}
		}
		else {
			--TimerForKeyPressButton3;
			if (TimerForKeyPressButton3 == 0) {
				//TODO
				if (KeyReg2Button3 == PRESSED_STATE) {
					KeyReg3Button3 = NORMAL_STATE;
				}
			}
		}
	}
}

