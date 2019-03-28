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

#include "i2c.h"

static portTASK_FUNCTION_PROTO( vLedI2c1Task, pvParameters );
static TaskHandle_t xLedI2c1Task;

BaseType_t xLedsBlinkStart( void )
{
    BaseType_t ret = 0;

    i2c_master_init(I2C_BUS_1, I2C_ADDRESSING_MODE_7BIT, 400000);

    ret = xTaskCreate( vLedI2c1Task, "LED I2C1 Test", configMINIMAL_STACK_SIZE + 512, NULL, tskIDLE_PRIORITY + 1, &xLedI2c1Task );
    if( ret != pdPASS )
    {
        return pdFAIL;
    }

    return pdPASS;
}

void vLedsBlinkStop( void )
{
    vTaskDelete( xLedI2c1Task );
}

static portTASK_FUNCTION( vLedI2c1Task, pvParameters )
{
    uint8_t data_1 = 0xF0;
   
    i2c_master_send(I2C_BUS_1, 0x76, &data_1, sizeof(uint8_t));

    for( ;; )
    {
        i2c_master_recv(I2C_BUS_1, 0x76, &data_1, sizeof(uint8_t));
        data_1 = (data_1 + 1) & 0x0F;
        i2c_master_send(I2C_BUS_1, 0x76, &data_1, sizeof(uint8_t));

        vTaskDelay( 125 / portTICK_PERIOD_MS );
    }
}
