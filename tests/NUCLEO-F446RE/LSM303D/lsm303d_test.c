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

#include "acc_mag_LSM303D.h"
#include "usart.h"
#include "i2c.h"

static portTASK_FUNCTION_PROTO( vLsm303dTestTask, pvParameters );
static TaskHandle_t xLsm303dTestTask;

static usart_handle_t usart_handle;

BaseType_t lsm303d_test_init( void )
{
    BaseType_t ret = 0;

    usart_handle = usart_init(USART_PORT_2, 115200, USART_WORLD_LENGTH_8, UART_STOPBITS_1, UART_PARITY_NONE, UART_HWCONTROL_NONE);
    configASSERT(usart_handle != NULL);

    i2c_master_init(I2C_BUS_1, I2C_ADDRESSING_MODE_7BIT, 400000);

    ret = xTaskCreate( vLsm303dTestTask, "LSM303D test", configMINIMAL_STACK_SIZE + 512, NULL, tskIDLE_PRIORITY + 1, &xLsm303dTestTask );
    if( ret != pdPASS )
    {
        return pdFAIL;
    }

    return pdPASS;
}

static portTASK_FUNCTION( vLsm303dTestTask, pvParameters )
{
    acc_config_t config = {I2C_BUS_1, 1, LA_FS_2G, ACC_DATA_RATE_25Hz};
    float accXYZ[3];
    char buf[100];
    int delay = 100;
    int ret, size;

    ret = lsm303d_acc_init(&config);
    if (ret) {
        vTaskDelete(NULL);
    }

    for(;;)
    {
        lsm303d_acc_read_acc_val(accXYZ);
        size = sprintf(buf, "ACC: %.04f\t%.04f\t%.04f [G]\n\r", accXYZ[0], accXYZ[1], accXYZ[2]);
        usart_send(usart_handle, (uint8_t *)buf, size, -1);
        vTaskDelay(delay / portTICK_PERIOD_MS);
    }
}
