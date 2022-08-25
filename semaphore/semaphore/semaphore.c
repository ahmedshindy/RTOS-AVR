/*
 * Semaphores : Example, The task is waiting for a semaphore which is given from an interrupt on DIO pin.
 * Created: Aug, 2022
 * Author: Ahmed Shindy
 * Supervisor : Eng. Mohamed Zaghloul
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
void task1(void *PV);

SemaphoreHandle_t my_sem ;
int main(void)
{
	
	xTaskCreate(task1,"M",100,NULL,1,NULL);
	sei();
	GICR|=(1<<INT0);
	MCUCR|=(1<<ISC00)|(1<<ISC01);
	my_sem=xSemaphoreCreateBinary();
	vTaskStartScheduler();
    while(1)
    {
        
    }
}

void task1(void *PV)
{
	char x;
	DDRD|=(1<<7);
	while(1)
	{
	x=xSemaphoreTake(my_sem,100);
	if(x==1)
		{
		PORTD^=(1<<7);
		_delay_ms(1000);
		xSemaphoreGive(my_sem);
		}		
	}
}

ISR(INT0_vect)
{
	xSemaphoreGiveFromISR(my_sem,NULL);
}
 