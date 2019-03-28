/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include "stm32f4xx_hal.h"

#include "FreeRTOS.h"
#include "task.h"

#include "lsm303d_test.h"

extern void SystemClock_Config(void);

int main(void)
{
	HAL_Init();

	SystemClock_Config();

	SystemCoreClock = HAL_RCC_GetHCLKFreq();

	lsm303d_test_init();

	vTaskStartScheduler();
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{ 
	while (1)
	{
	}
	}
#endif /* USE_FULL_ASSERT */ 

void vApplicationMallocFailedHook( void )
{
	for( ;; );
}

void vApplicationTickHook( void )
{
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	taskDISABLE_INTERRUPTS();
	for( ;; );
	}

void vApplicationIdleHook( void )
{
}
