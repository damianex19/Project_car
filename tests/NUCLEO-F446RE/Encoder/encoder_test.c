/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"

#include "leds.h"
#include "encoder.h"

static portTASK_FUNCTION_PROTO( vEncoderTask, pvParameters );

static TaskHandle_t xEncoderTask;

int encoder_test_init( void )
{
    BaseType_t ret = 0;

    leds_init( LEDS_GREEN );
    ret = encoder_init(ENCODER_TIMER_2, ENCODER_TYPE_DUAL);
    configASSERT(ret == 0);

    ret = encoder_init(ENCODER_TIMER_3, ENCODER_TYPE_DUAL);
    configASSERT(ret == 0);

    ret = xTaskCreate( vEncoderTask, "Encoder test ENC", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &xEncoderTask );
    if( ret != pdPASS )
    {
        /*TODO - add error logging*/
        leds_deinit( LEDS_GREEN );
        return pdFAIL;
    }

    return pdPASS;
}

static portTASK_FUNCTION( vEncoderTask, pvParameters )
{
    int32_t val_1, val_2;
    for( ;; )
    {
        val_1 = encoder_get_value(ENCODER_TIMER_2);
        val_2 = encoder_get_value(ENCODER_TIMER_3);
        
        if(abs(val_1 - val_2) < 100)
            leds_set(LEDS_GREEN, 1);
        else
            leds_set(LEDS_GREEN, 0);

        vTaskDelay( 100 / portTICK_PERIOD_MS );
    }
}
