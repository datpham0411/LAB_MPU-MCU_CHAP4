/*
 * fsm_traffic.c
 *
 *  Created on: Oct 26, 2024
 *      Author: datph
 */
#include "fsm_manual.h"

int status = NORMAL;
int red_duration = 3000;
int red_duration_temp = 0;
int amber_duration = 1000;
int amber_duration_temp = 0;
int green_duration = 2000;
int green_duration_temp = 0;

void fsm_manual_run() {
	switch(status) {
		case NORMAL:
			fsm_automatic_run();

			if (isButton1Pressed()) {
				status = INITIAL;
			}
			break;
		case INITIAL:
			setColor(GPIOA, LED_RED_A_Pin, LED_AMBER_A_Pin, LED_GREEN_A_Pin, OFF, OFF, OFF);
			setColor(GPIOA, LED_RED_B_Pin, LED_AMBER_B_Pin, LED_GREEN_B_Pin, OFF, OFF, OFF);
			setColor(GPIOA, ENA1_Pin, ENA2_Pin, ENA2_Pin, ON, ON, ON);
			setColor(GPIOA, ENB1_Pin, ENB2_Pin, ENB2_Pin, ON, ON, ON);
			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, OFF, OFF, OFF);
			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, OFF, OFF, OFF);
			setColor(GPIOB, SEG_6_Pin, SEG_A_Pin, SEG_B_Pin, OFF, OFF, OFF);
			setColor(GPIOB, SEG_C_Pin, SEG_D_Pin, SEG_E_Pin, OFF, OFF, OFF);
			setColor(GPIOB, SEG_F_Pin, SEG_G_Pin, SEG_G_Pin, OFF, OFF, OFF);

			status = MODIFY_RED;
			setTimer3(250);
			setTimer2(147);
			setTimer1(153);
			break;
		case MODIFY_RED:
			if (timer1_flag == 1 && idx == 0) {
				setTimer1(153);
				display_num('A', 1, (red_duration)/10000);
			}
			else if (timer1_flag == 1 && idx == 1) {
				setTimer1(153);
				display_num('A', 2, ((red_duration)%10000)/1000);
			}

			if (timer2_flag == 1 && idx == 0) { // B mode, A value
				setTimer2(147);
				display_num('B', 1, 0);
			}
			else if (timer2_flag == 1 && idx == 1) {
				setTimer2(147);
				display_num('B', 2, MODIFY_RED);
			}

			setColor(GPIOA, LED_AMBER_A_Pin, LED_AMBER_B_Pin, LED_AMBER_B_Pin, OFF, OFF, OFF);
			setColor(GPIOA, LED_GREEN_A_Pin, LED_GREEN_B_Pin, LED_GREEN_B_Pin, OFF, OFF, OFF);
			if (timer3_flag == 1) {
				setTimer3(250);
				setColorToggle(GPIOA, LED_RED_A_Pin, LED_RED_B_Pin, LED_RED_B_Pin);
			}

			if(isButton3Pressed()) red_duration = red_duration;

			if(isButton2Pressed()) {
				red_duration_temp = red_duration;
				red_duration = red_duration + 1000;
				if (red_duration > 99000) red_duration = 1000;
			}

			if (isButton1Pressed()) {
				status = MODIFY_AMBER;
				setTimer3(250);
				setTimer2(147);
				setTimer1(153);
			}
			break;
		case MODIFY_AMBER:
			if (timer1_flag == 1 && idx == 0) {
				setTimer1(153);
				display_num('A', 1, (amber_duration)/10000);
			}
			else if (timer1_flag == 1 && idx == 1) {
				setTimer1(153);
				display_num('A', 2, ((amber_duration)%10000)/1000);
			}

			if (timer2_flag == 1 && idx == 0) { // B mode, A value
				setTimer2(147);
				display_num('B', 1, 0);
			}
			else if (timer2_flag == 1 && idx == 1) {
				setTimer2(147);
				display_num('B', 2, MODIFY_AMBER);
			}

			setColor(GPIOA, LED_RED_A_Pin, LED_RED_B_Pin, LED_RED_B_Pin, OFF, OFF, OFF);
			setColor(GPIOA, LED_GREEN_A_Pin, LED_GREEN_B_Pin, LED_GREEN_B_Pin, OFF, OFF, OFF);
			if (timer3_flag == 1) {
				setTimer3(250);
				setColorToggle(GPIOA, LED_AMBER_A_Pin, LED_AMBER_B_Pin, LED_AMBER_B_Pin);
			}

			if(isButton3Pressed()) amber_duration = amber_duration;

			if(isButton2Pressed()) {
				amber_duration_temp = amber_duration;
				amber_duration = amber_duration + 1000;
				if (amber_duration > 99000) amber_duration = 1000;
			}

			if (isButton1Pressed()) {
				status = MODIFY_GREEN;
				setTimer3(250);
				setTimer2(147);
				setTimer1(153);
			}
			break;
		case MODIFY_GREEN:
			if (timer1_flag == 1 && idx == 0) {
				setTimer1(153);
				display_num('A', 1, (green_duration)/10000);
			}
			else if (timer1_flag == 1 && idx == 1) {
				setTimer1(153);
				display_num('A', 2, ((green_duration)%10000)/1000);
			}

			if (timer2_flag == 1 && idx == 0) { // B mode, A value
				setTimer2(147);
				display_num('B', 1, 0);
			}
			else if (timer2_flag == 1 && idx == 1) {
				setTimer2(147);
				display_num('B', 2, MODIFY_GREEN);
			}

			setColor(GPIOA, LED_RED_A_Pin, LED_RED_B_Pin, LED_RED_B_Pin, OFF, OFF, OFF);
			setColor(GPIOA, LED_AMBER_A_Pin, LED_AMBER_B_Pin, LED_AMBER_B_Pin, OFF, OFF, OFF);
			if (timer3_flag == 1) {
				setTimer3(250);
				setColorToggle(GPIOA, LED_GREEN_A_Pin, LED_GREEN_B_Pin, LED_GREEN_B_Pin);
			}

			if(isButton3Pressed()) {
				if(isErrorOccured()) {
					setTimer1(153);
					setTimer2(147);
					status = FAULT_CONDITION;
				}
			}

			if(isButton2Pressed()) {
				green_duration_temp = green_duration;
				green_duration = green_duration + 1000;
				if (green_duration > 99000) green_duration = 1000;
			}

			if (isButton1Pressed()) {
				if(isErrorOccured()) {
					setTimer1(153);
					setTimer2(147);
					status = FAULT_CONDITION;
				}
				else status = NORMAL;
			}
			break;
		case FAULT_CONDITION:
			setColor(GPIOA, LED_AMBER_A_Pin, LED_AMBER_B_Pin, LED_AMBER_B_Pin, OFF, OFF, OFF);
			setColor(GPIOA, LED_RED_A_Pin, LED_RED_B_Pin, LED_RED_B_Pin, OFF, OFF, OFF);
			setColor(GPIOA, LED_GREEN_A_Pin, LED_GREEN_B_Pin, LED_GREEN_B_Pin, OFF, OFF, OFF);
			if (timer1_flag == 1 && idx == 0) {
				setTimer1(153);
				display_num('A', 1, 11);
			}
			else if (timer1_flag == 1 && idx == 1) {
				setTimer1(153);
				display_num('A', 2, 12);
			}
			if (timer2_flag == 1 && idx == 0) { // B mode, A value
				setTimer2(147);
				display_num('B', 1, 0);
			}
			else if (timer2_flag == 1 && idx == 1) {
				setTimer2(147);
				display_num('B', 2, FAULT_CONDITION);
			}

			red_duration = red_duration_temp;
			amber_duration = amber_duration_temp;
			green_duration = green_duration_temp;

			if (isButton1Pressed()) status = MODIFY_RED;

			if (isButton3Pressed()) status = NORMAL;
			break;
		default:
			break;
	}
}

