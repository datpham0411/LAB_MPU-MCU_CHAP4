/*
 * fsm_setting.c
 *
 *  Created on: Oct 28, 2024
 *      Author: datph
 */
#include "fsm_setting.h"

int isErrorOccured() {
	if ((amber_duration + green_duration) != red_duration) return 1;
	return 0;
}
