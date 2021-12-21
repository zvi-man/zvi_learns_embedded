/*
 * task_handler.c
 *
 *  Created on: Dec 20, 2021
 *      Author: zvi
 */


#include "task_handler.h"
#include <stdio.h>
#include <stdlib.h>

#define TASK_LIST_LEN MAX_NUM_TASKS + 1

task* p_task_p_list[TASK_LIST_LEN];
uint32_t next_task, task_list_head;


static void TASK_HANDLER_Init()
{
	next_task = 0;
	task_list_head = 0;
}

static task* TASK_HANDLER_PopNextTask()
{
	if (next_task == task_list_head)
	{
		return NULL;
	}
	task *p_next_task = p_task_p_list[next_task];
	next_task = (next_task + 1) % TASK_LIST_LEN;
	return p_next_task;
}

static bool TASK_HANDLER_InsertTask(task* p_task)
{
	if ( ((task_list_head + 1) % TASK_LIST_LEN) == next_task )
	{
		return false;
	}
	p_task_p_list[task_list_head] = p_task;
	task_list_head++;
	return true;
}

static bool TASK_HANDLER_IsTaskWaiting()
{
	if (next_task == task_list_head)
	{
		return false;
	}
	return true;
}

