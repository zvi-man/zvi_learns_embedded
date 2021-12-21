#ifndef __TASK_HANDLER_H
#define __TASK_HANDLER_H

#include <stdbool.h>

#define MAX_NUM_TASKS 20

typedef void task();

static void TASK_HANDLER_Init();
static task* TASK_HANDLER_PopNextTask();
static bool TASK_HANDLER_InsertTask(task* p_task);
static bool TASK_HANDLER_IsTaskWaiting();


#endif
