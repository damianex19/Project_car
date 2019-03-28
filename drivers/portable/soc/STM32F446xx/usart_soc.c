/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include <string.h>

#include <FreeRTOS.h>
#include "task.h"
#include "queue.h"

#include "stm32f4xx_hal_conf.h"

#include "usart_soc.h"
#include <tools/container_of.h>

#define USART_SOC_RETRIES     5

typedef struct usart_handle_s {
} usart_handle_t;

int usart_soc_init(usart_t port, uint32_t baud_rate, usart_world_length_t world_length, usart_stop_bits_t stop_bits, usart_parity_t parity, usart_hw_control_t hw_control)
{
	return -1;
}

void usart_soc_deinit(usart_t port) {
	return;
}

int usart_soc_send(usart_t port, uint8_t *data, size_t length, usart_send_done_clbk clbk, void *clbk_data) {
	return -1;
}

int usart_soc_abort_send(usart_t port) {
	return -1;
}

int usart_soc_recv(usart_t port, uint8_t *data, size_t length, usart_recv_done_clbk clbk, void *clbk_data) {
	return -1;
}

int usart_soc_abort_recv(usart_t port) {
	return -1;
}
