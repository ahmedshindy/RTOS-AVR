/*
 * event group : just an example 
 * Created: Aug, 2022
 * Author: Ahmed Shindy
 * Supervisor : Eng. Mohamed Zaghloul
 */

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
# define F_CPU 8000000UL
#include "util/delay.h"
#include "event_groups.h"

/*Create Event Handler*/
EventGroupHandle_t myEventGroup = NULL;

void SetBit0( void *pvParameters);
void SetBit1( void *pvParameters);
void Task2( void *pvParameters);

int main(void)
{
	
	// Create Tasks
	xTaskCreate(SetBit0,"Bit0",100,NULL,3,NULL);
	xTaskCreate(SetBit1,"Bit1",100,NULL,2,NULL);
	xTaskCreate(Task2,"Task 2",200,NULL,1,NULL);
	//Create Event Group
	myEventGroup = xEventGroupCreate();
	vTaskStartScheduler();

	while(1)
	{

	}
}

void SetBit0( void *pvParameters)
{
	while(1)
	{
		vTaskDelay(5000);
		xEventGroupSetBits(myEventGroup,0x01);
	}
}

void SetBit1( void *pvParameters)
{
	while(1)
	{
		vTaskDelay(2000);
		xEventGroupSetBits(myEventGroup,0x02);
	}
}

void Task2( void *pvParameters)
{

	/*Some initializations*/
	DDRD |= (1<<7);
	DDRD |= (1<<6);
	DDRD |= (1<<5);
	EventBits_t myBitsReturned = 0X00;
	while(1)
	{
		myBitsReturned = xEventGroupWaitBits(myEventGroup,0x03,pdTRUE,pdFALSE,1000);
		if (myBitsReturned == 0x01)
		{
			PORTD ^= (1<<7);
		}
		else if(myBitsReturned == 0x02)
		{
			PORTD ^= (1<<6);
		}
		else if (myBitsReturned == 0x03)
		{
			PORTD ^= (1<<5);
		}
		
	}
}


