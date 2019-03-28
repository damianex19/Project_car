/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include "FreeRTOS.h"
#include "task.h"

#include "leds.h"

static portTASK_FUNCTION_PROTO( vLedRedTestTask, pvParameters );
static portTASK_FUNCTION_PROTO( vLedBlueTestTask, pvParameters );
static portTASK_FUNCTION_PROTO( vLedGreenTestTask, pvParameters );

static TaskHandle_t xLedRedTask;
static TaskHandle_t xLedBlueTask;
static TaskHandle_t xLedGreenTask;

BaseType_t xLedsBlinkStart( void )
{
    BaseType_t ret = 0;

    leds_init( LEDS_GREEN );
    ret = xTaskCreate( vLedRedTestTask, "LED_RED_Test", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &xLedRedTask );
    if( ret != pdPASS )
    {
        /*TODO - add error logging*/
        leds_deinit( LEDS_GREEN );
        return pdFAIL;
    }

    return pdPASS;
}

void vLedsBlinkStop( void )
{
    vTaskDelete( xLedRedTask );
    
    leds_deinit( LEDS_GREEN );
}

static portTASK_FUNCTION( vLedRedTestTask, pvParameters )
{
    for( ;; )
    {
        leds_toggle( LEDS_GREEN );
        vTaskDelay( 500 / portTICK_PERIOD_MS );
    }
}
