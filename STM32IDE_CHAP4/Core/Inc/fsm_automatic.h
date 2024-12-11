/*
 * fsm_automatic.h
 *
 *  Created on: Oct 26, 2024
 *      Author: datph
 */

#ifndef INC_FSM_NORMAL_H_
#define INC_FSM_NORMAL_H_

#include "fsm_manual.h"
#include "led7_segment.h"
#include "traffic_light.h"
#include "software_timer.h"

#define INIT 1
#define RED 2
#define AMBER 3
#define GREEN 4

void fsm_automatic_run();

#endif /* INC_FSM_NORMAL_H_ */
