/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include <string.h>

#include "FreeRTOS.h"
#include "task.h"

#include "usart.h"

#include "stlink_uart_test.h"

static portTASK_FUNCTION_PROTO( vSTlinkUartTestTask, pvParameters );
static TaskHandle_t xSTlinkUartTestTask;

static usart_handle_t usart_handle;

int stlink_uart_test(void) {
	int ret = 0;
	
	usart_handle = usart_init(USART_PORT_2, 115200, USART_WORLD_LENGTH_8, UART_STOPBITS_1, UART_PARITY_NONE, UART_HWCONTROL_NONE);
	configASSERT(usart_handle != NULL);

	ret = xTaskCreate(vSTlinkUartTestTask, "Encoder measure task", 3 * configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &xSTlinkUartTestTask);
	configASSERT(ret == pdPASS);

	return 0;
}

static portTASK_FUNCTION( vSTlinkUartTestTask, pvParameters ) {
	int ret = 0;
	uint8_t in[1];
	uint8_t out[1];

	while(1) {
		ret = usart_recv(usart_handle, in, sizeof(in), 500);
		if (ret == 0) {
			memcpy(out, in, sizeof(in));
			usart_send(usart_handle, out, sizeof(out), -1);
		}
	}
}
