/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __USART_SOC_H__
#define __USART_SOC_H__

#include "stm32f4xx_hal_conf.h"

#include "usart_bsp.h"

typedef void (*usart_send_done_clbk)(void *data, int result);
typedef void (*usart_recv_done_clbk)(void *data, int result);

typedef enum usart_world_length_e {
	USART_WORLD_LENGTH_8 = UART_WORDLENGTH_8B,
	USART_WORLD_LENGTH_9 = UART_WORDLENGTH_9B
} usart_world_length_t;

typedef enum usart_stop_bits_e {
	USART_STOPBITS_1 = UART_STOPBITS_1,
	USART_STOPBITS_2 = UART_STOPBITS_2
} usart_stop_bits_t;

typedef enum  usart_parity_e {
	USART_PARITY_NONE = UART_PARITY_NONE,
	USART_PARITY_EVEN = UART_PARITY_EVEN,
	USART_PARITY_ODD = UART_PARITY_ODD
} usart_parity_t;

typedef enum usart_hw_control_e {
	USART_HWCONTROL_NONE = UART_HWCONTROL_NONE,
	USART_HWCONTROL_RTS = UART_HWCONTROL_RTS,
	USART_HWCONTROL_CTS = UART_HWCONTROL_CTS,
	USART_HWCONTROL_RTS_CTS = UART_HWCONTROL_RTS_CTS
} usart_hw_control_t;

int usart_soc_init(usart_t port, uint32_t baud_rate, usart_world_length_t world_length, usart_stop_bits_t stop_bits, usart_parity_t parity, usart_hw_control_t hw_control);
void usart_soc_deinit(usart_t port);

int usart_soc_send(usart_t port, uint8_t *data, size_t length, usart_send_done_clbk clbk, void *clbk_data);
int usart_soc_abort_send(usart_t port);

int usart_soc_recv(usart_t port, uint8_t *data, size_t length, usart_recv_done_clbk clbk, void *clbk_data);
int usart_soc_abort_recv(usart_t port);

#endif //__USART_SOC_H__
