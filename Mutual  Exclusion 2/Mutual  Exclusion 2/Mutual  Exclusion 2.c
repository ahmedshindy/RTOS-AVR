/*
 * Mutual Exclusion : Implementig by Disable/Enable Scheduling 
 * Created: Aug, 2022
 * Author: Ahmed Shindy
 * Supervisor : Eng. Mohamed Zaghloul
 */



#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "FreeRTOS.h"
#include "task.h"
#include <avr/interrupt.h>
int x,y;
void task1(void *pv);
void task2 (void *pv);
int main(void)
{
	/* create the tasks */
	xTaskCreate(task1,"M",100,NULL,2,NULL);
	xTaskCreate(task2,"N",100,NULL,1,NULL);
	/* start os*/
	vTaskStartScheduler();
	while(1)
	{
		
	}
}
void task1(void *pv)
{
	DDRD|=(1<<7);
	while(1)
	{
		if(x==y)
		{
			PORTD^=(1<<7);
		}
		vTaskDelay(100);
	}
}

void task2(void *pv)
{
	while(1)
	{
		vTaskSuspendAll();
		++x;
		_delay_ms(200);
		++y;
		xTaskResumeAll();
	}
}
