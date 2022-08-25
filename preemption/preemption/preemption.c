/*
 * Preemption : Creating 2 tasks with different priorities and enable/disable preemption and test the output 
 * Created: Aug, 2022
 * Author: Ahmed Shindy
 * Supervisor : Eng. Mohamed Zaghloul
 */


#include <avr/io.h>
#define  F_CPU 8000000ul
#include <util/delay.h>
#include "FreeRTOS.h"
#include "task.h"
void task1(void *pv);
void task2(void *pv);


int main(void)
{
	char x=7;
	char y=6;
	/*create the tasks */
	xTaskCreate(task1,"Ahmed",100,&x,1,NULL);  // parameter is pin Number 6 of port D
	xTaskCreate(task2,"Shindy",100,&y,2,NULL); /* PortD -> Pin 7*/
	/*start os scheduler*/
	vTaskStartScheduler();
	while(1)
	{
		
	}
}


void task1(void *pv)
{
	/*some initializations*/
	DDRD|=(1<<*((char*)pv));
	while(1)
	{
		PORTD^=(1<<*((char*)pv));
		_delay_ms(1000);  // on this delay the task is running 
	}
}
void task2(void *pv)
{
	vTaskDelay(4000);
	/*some initializations*/
	DDRD|=(1<<*((char*)pv));
	while(1)
	{
		PORTD^=(1<<*((char*)pv));
		_delay_ms(1000);
	}
}

