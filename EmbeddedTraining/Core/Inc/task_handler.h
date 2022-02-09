/*
 * task_handler.h
 *
 *  Created on: 25 Dec 2021
 *      Author: zvi
 */

#ifndef INC_TASK_HANDLER_H_
#define INC_TASK_HANDLER_H_

#include <stdbool.h>

#define MAX_NUM_TASKS 20


typedef void task(void);

void TASK_HANDLER_Init();
task* TASK_HANDLER_PopNextTask();
bool TASK_HANDLER_InsertTask(task* p_task);
bool TASK_HANDLER_IsTaskWaiting();


#endif /* INC_TASK_HANDLER_H_ */
