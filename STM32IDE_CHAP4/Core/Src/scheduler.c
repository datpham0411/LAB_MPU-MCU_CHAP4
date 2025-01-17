/*
 * scheduler.c
 *
 *  Created on: Nov 9, 2024
 *      Author: datph
 */
#include "scheduler.h"
//sTasks SCH_tasks_G[SCH_MAX_TASKS];
//uint8_t current_index_task = 0;
//int timer_counter = 0;
//void SCH_Init(void){
//	current_index_task = 0;
//}
//
//void SCH_Add_Task (void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
//	if (current_index_task < SCH_MAX_TASKS) {
//		SCH_tasks_G[current_index_task].pTask = pFunction;
//		SCH_tasks_G[current_index_task].Delay = DELAY;
//		SCH_tasks_G[current_index_task].Period = PERIOD;
//		SCH_tasks_G[current_index_task].RunMe = 0;
//		SCH_tasks_G[current_index_task].TaskID = current_index_task;
//		current_index_task++;
//	}
//}
//
//void SCH_Update(void) {
//	for (int i = 0; i < current_index_task; i++) {
//		if (SCH_tasks_G[i].Delay > 0) {
//			SCH_tasks_G[i].Delay--;
//		}
//		else {
//			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
//			SCH_tasks_G[i].RunMe += 1;
//		}
//	}
//}
//
//void SCH_Dispatch_Tasks(void) {
//	for (uint32_t i = 0; i < current_index_task; i++) {
//		if(SCH_tasks_G[i].RunMe > 0) {
//			SCH_tasks_G[i].RunMe--;
//			(*SCH_tasks_G[i].pTask)();
//
//			if(SCH_tasks_G[i].Period == 0) {
//				SCH_Delete_Task(i);
//			}
//		}
//	}
//}
//
//void SCH_Delete_Task (uint32_t ID) {
//	for (uint32_t i = ID; i < current_index_task; i++) {
//		if (i == (current_index_task - 1)) {
//			SCH_tasks_G[i].pTask = 0x0000;
//			SCH_tasks_G[i]. Delay = 0;
//			SCH_tasks_G[i]. Period = 0;
//			SCH_tasks_G[i].RunMe = 0;
//			SCH_tasks_G[i].TaskID = 0;
//		}
//		else {
//		SCH_tasks_G[i].pTask = SCH_tasks_G[i + 1].pTask;
//		SCH_tasks_G[i]. Delay = SCH_tasks_G[i + 1].Delay;
//		SCH_tasks_G[i]. Period = SCH_tasks_G[i + 1].Period;
//		SCH_tasks_G[i].RunMe = SCH_tasks_G[i + 1].RunMe;
//		SCH_tasks_G[i].TaskID = SCH_tasks_G[i + 1].TaskID;
//		}
//	}
//	--current_index_task;
//}
// ----------- O(1)
sTasks* head = NULL;
sTasks* tail = NULL;

void SCH_Init(void) {
    head = NULL;
    tail = NULL;
}

void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
    sTasks* newTask = (sTasks*)malloc(sizeof(sTasks));
    if (newTask) {
        newTask->pTask = pFunction;
        newTask->Delay = DELAY;
        newTask->Period = PERIOD;
        newTask->RunMe = 0;
        newTask->next = NULL;
        newTask->prev = tail;

        if (tail) {
            tail->next = newTask;
        }
        else {
            head = newTask;
        }
        tail = newTask;
    }
}

void SCH_Update(void) {
    sTasks* current = head;
    while (current) {
        if (current->Delay > 0) {
            current->Delay--;
        } else {
            current->Delay = current->Period;
            current->RunMe++;
        }
        current = current->next;
    }
}

void SCH_Dispatch_Tasks(void) {
    sTasks* current = head;
    while (current) {
        if (current->RunMe > 0) {
            current->RunMe--;
            (*current->pTask)();

            if (current->Period == 0) {
                sTasks* toDelete = current;
                current = current->next;
                SCH_Delete_Task(toDelete);
            }
            else {
                current = current->next;
            }
        }
        else {
            current = current->next;
        }
    }
}

void SCH_Delete_Task(sTasks* task) {
    if (!task) return;

    if (task->prev) {
        task->prev->next = task->next;
    }
    else {
        head = task->next;
    }

    if (task->next) {
        task->next->prev = task->prev;
    }
    else {
        tail = task->prev;
    }

    free(task);
}

