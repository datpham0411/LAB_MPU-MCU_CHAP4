/*
 * global.h
 *
 *  Created on: Oct 28, 2024
 *      Author: datph
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

extern int status;
extern int red_duration;
extern int amber_duration;
extern int green_duration;

extern int timer1_counter;
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

extern int idx; // Variable for LED Scanning

extern int color; // Variable for convert state in fsm_manual: INIT, RED, AMBER and GREEN

#endif /* INC_GLOBAL_H_ */
