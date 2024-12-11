/*
 * fsm_traffic.h
 *
 *  Created on: Oct 26, 2024
 *      Author: datph
 */

#ifndef INC_FSM_TRAFFIC_H_
#define INC_FSM_TRAFFIC_H_

#include "button.h"
#include "fsm_setting.h"
#include "fsm_automatic.h"
#include "global.h"

#define NORMAL 			1
#define INITIAL			0
#define MODIFY_RED 		2
#define MODIFY_AMBER 	3
#define MODIFY_GREEN 	4
#define FAULT_CONDITION 5

void fsm_manual_run();

#endif /* INC_FSM_TRAFFIC_H_ */
