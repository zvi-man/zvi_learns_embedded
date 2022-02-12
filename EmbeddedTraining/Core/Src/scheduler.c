/*
 * scheduler.c
 *
 *  Created on: Feb 9, 2022
 *      Author: צבי
 */

#include "main.h"
#include "scheduler.h"
#include "task_handler.h"


SCHEDULER_SLOT_t slot_list[MAX_SLOTS];
uint32_t current_time_ticks = 0;

void tick_slot(SCHEDULER_SLOT_t *slot);

void SCHEDULER_init()
{
	for(int i=0; i < MAX_SLOTS; i++)
	{
		slot_list[i].is_active = false;
	}
}


SCHEDULER_slot_num SCHEDULER_register_slot(uint32_t period_in_ticks, bool is_priodic, SCHEDULER_CALLBACK_t pf_callback)
{
	for(int i=0; i < MAX_SLOTS; i++)
	{
		if(!slot_list[i].is_active)
		{
			slot_list[i].is_active = true;
			slot_list[i].is_priodic = is_priodic;
			slot_list[i].period_in_ticks = period_in_ticks;
			slot_list[i].pf_callback = pf_callback;
			slot_list[i].ticks_remaining = period_in_ticks;
			return i;
		}
	}
	return -1;

}

void SCHEDULER_tick()
{
	for(int i=0; i < MAX_SLOTS; i++)
		{
			if(slot_list[i].is_active)
			{
				tick_slot(&slot_list[i]);
			}
		}
}



void tick_slot(SCHEDULER_SLOT_t *slot)
{
	slot->ticks_remaining--;
	if(slot->ticks_remaining == 0)
	{
		TASK_HANDLER_InsertTask(slot->pf_callback);
		if(slot->is_priodic)
		{
			slot->ticks_remaining = slot->period_in_ticks;
		} else
		{
			slot->is_active = false;
		}
	}
}


void SCHEDULER_set_slot_period(SCHEDULER_slot_num slot_num, uint32_t period_in_ticks)
{
	slot_list[slot_num].period_in_ticks = period_in_ticks;
	slot_list[slot_num].ticks_remaining = period_in_ticks;
}
