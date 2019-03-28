/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"

#include "gpio.h"
#include "encoder.h"
#include "drv8835.h"
#include "leds.h"
#include "usart.h"

#define DRV8835_MIN 0
#define DRV8835_MAX 100

static const drv8835_init_t drv8835_conf_1 = {
    .dir_pin = D8,
    .pwm = PWM_TIMER_4
};

static const drv8835_init_t drv8835_conf_2 = {
    .dir_pin = D7,
    .pwm = PWM_TIMER_8
};

static portTASK_FUNCTION_PROTO( vMotorsTask, pvParameters );
static TaskHandle_t xMotorsTask;

static portTASK_FUNCTION_PROTO( vUartTask, pvParameters );
static TaskHandle_t xUartTask;

static drv8835_handle_t drv8835_handle_1; 
static drv8835_handle_t drv8835_handle_2; 
static usart_handle_t usart_handle;

static int direction = NON_INVERTED;
static int speed = 0;

int drv8835_test_init( void )
{
    BaseType_t ret = 0;

    ret = xTaskCreate( vMotorsTask, "MOTORS", 2 * configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &xMotorsTask );
    configASSERT(ret == pdPASS)

    ret = xTaskCreate( vUartTask, "UART", 2 * configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &xUartTask );
    configASSERT(ret == pdPASS)    

    ret = encoder_init(ENCODER_TIMER_2, ENCODER_TYPE_DUAL);
    configASSERT(ret == 0);
    ret = encoder_init(ENCODER_TIMER_3, ENCODER_TYPE_DUAL);
    configASSERT(ret == 0);

    drv8835_handle_1 = drv8835_init(&drv8835_conf_1);
    configASSERT(drv8835_handle_1);

    drv8835_handle_2 = drv8835_init(&drv8835_conf_2);
    configASSERT(drv8835_handle_2);

    usart_handle = usart_init(USART_PORT_2, 115200, USART_WORLD_LENGTH_8, UART_STOPBITS_1, UART_PARITY_NONE, UART_HWCONTROL_NONE);
    configASSERT(usart_handle != NULL);

    leds_init(LEDS_GREEN);
    
    return pdPASS;
}

static portTASK_FUNCTION( vMotorsTask, pvParameters )
{
    int32_t enc1_val = encoder_get_value(ENCODER_TIMER_2);
    int32_t enc2_val = encoder_get_value(ENCODER_TIMER_3);
    uint8_t report[32];
    
    for( ;; )
    {
        drv8835_set_direction(drv8835_handle_1, direction);
        drv8835_set_direction(drv8835_handle_2, direction);
        
        drv8835_set_speed(drv8835_handle_1, speed);
        drv8835_set_speed(drv8835_handle_2, speed);

        enc1_val = encoder_get_value(ENCODER_TIMER_2);
        enc2_val = encoder_get_value(ENCODER_TIMER_3);        

        sprintf((char *)report, "%ld, %ld\n\r", enc1_val, enc2_val);
        usart_send(usart_handle, report, strlen((char *)report), -1);        
        
        vTaskDelay( 250 / portTICK_PERIOD_MS );
    }
}

static portTASK_FUNCTION( vUartTask, pvParameters ) {
    int ret = 0;
    uint8_t in;

    while(1) {
        ret = usart_recv(usart_handle, &in, sizeof(in), -1);
        if (ret == 0) {
            switch(in) {
                case ' ':
                    if (direction == NON_INVERTED) {
                    direction = INVERTED;
                    leds_set(LEDS_GREEN, 0);
                    }
                    else {
                        direction = NON_INVERTED;
                        leds_set(LEDS_GREEN, 1);
                    }
                    break;
                case '<':
                    speed = (speed == 0 ? speed : speed - 1);
                    break;
                case '>':
                    speed = (speed == 100 ? speed : speed + 1);
                    break;
                case '0':
                    speed = 0;
            }
        }
    }
}