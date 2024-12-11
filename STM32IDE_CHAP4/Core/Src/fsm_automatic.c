/*
 * fsm_normal.c
 *
 *  Created on: Oct 26, 2024
 *      Author: datph
 */
#include <fsm_automatic.h>

int color = INIT;

void fsm_automatic_run() {
	switch (color) {
		case INIT:
			setColor(GPIOA, LED_RED_A_Pin, LED_AMBER_A_Pin, LED_GREEN_A_Pin, OFF, OFF, OFF);
			setColor(GPIOA, LED_RED_B_Pin, LED_AMBER_B_Pin, LED_GREEN_B_Pin, OFF, OFF, OFF);

			color = RED;
			setTimer1(red_duration);
			break;
		case RED:
			display_time();
			setColor(GPIOA, LED_RED_A_Pin, LED_AMBER_A_Pin, LED_GREEN_A_Pin, ON, OFF, OFF);
			if (isTimer1Paused(red_duration - green_duration)) {
				if (idx == 0) {
					display_num('B', 1, (timer1_counter + 100)/1000);
				}
				else if (idx == 1) {
					display_num('B', 2, ((timer1_counter + 100)%1000)/100);
				}
				setColor(GPIOA, LED_RED_B_Pin, LED_AMBER_B_Pin, LED_GREEN_B_Pin, OFF, ON, OFF);
			}
			else {
				if (idx == 0) {
					display_num('B', 1, ((timer1_counter + 100)/100 - amber_duration/1000)/10);
				}
				else if (idx == 1) {
					display_num('B', 2, ((timer1_counter + 100)/100 - amber_duration/1000)%10);
				}
				setColor(GPIOA, LED_RED_B_Pin, LED_AMBER_B_Pin, LED_GREEN_B_Pin, OFF, OFF, ON);
			}

			if (timer1_flag == 1) {
				color = GREEN;
				setTimer1(green_duration);
			}
			break;
		case AMBER:
			display_time();
			setColor(GPIOA, LED_RED_A_Pin, LED_AMBER_A_Pin, LED_GREEN_A_Pin, OFF, ON, OFF);

			if (idx == 0) {
				display_num('B', 1, (timer1_counter + 100)/1000);
			}
			else if (idx == 1) {
				display_num('B', 2, ((timer1_counter + 100)%1000)/100);
			}
			setColor(GPIOA, LED_RED_B_Pin, LED_AMBER_B_Pin, LED_GREEN_B_Pin, ON, OFF, OFF);

			if (timer1_flag == 1) {
				color = RED;
				setTimer1(red_duration);
			}
			break;
		case GREEN:
			display_time();
			setColor(GPIOA, LED_RED_A_Pin, LED_AMBER_A_Pin, LED_GREEN_A_Pin, OFF, OFF, ON);

			if (idx == 0) {
				display_num('B', 1, ((timer1_counter + 100)/100 + amber_duration/1000)/10);
			}
			else if (idx == 1) {
				display_num('B', 2, ((timer1_counter + 100)/100 + amber_duration/1000)%10);
			}
			setColor(GPIOA, LED_RED_B_Pin, LED_AMBER_B_Pin, LED_GREEN_B_Pin, ON, OFF, OFF);

			if (timer1_flag == 1) {
				color = AMBER;
				setTimer1(amber_duration);
			}
			break;
		default:
			break;
	}
}

