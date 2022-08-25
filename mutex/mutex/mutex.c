/*
 * Mutex : Using Mutex
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
#include "semphr.h"
int x,y;
void task1(void *pv);
void task2 (void *pv);
SemaphoreHandle_t my_mutex;
int main(void)
{
	xTaskCreate(task1,"M",100,NULL,2,NULL);
	xTaskCreate(task2,"N",100,NULL,1,NULL);
	my_mutex=xSemaphoreCreateMutex();
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
		xSemaphoreTake(my_mutex,20);
		if(x!=y)
		{
			PORTD^=(1<<7);
			_delay_ms(1000);
			PORTD^=(1<<7);
			_delay_ms(1000);
		}
		xSemaphoreGive(my_mutex);
		vTaskDelay(1000);
	}
	
}	
void task2 (void *pv)
{
	while(1)
	{
		xSemaphoreTake(my_mutex,1000);
		++x;
		_delay_ms(200);
		++y;
		 xSemaphoreGive(my_mutex);
	}
}

