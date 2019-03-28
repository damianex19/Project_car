/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __USART_H__
#define __USART_H__

#include "usart_soc.h"

typedef struct usart_desc_s *usart_handle_t;

usart_handle_t usart_init(usart_t port, uint32_t baud_rate, usart_world_length_t world_length, usart_stop_bits_t stop_bits, usart_parity_t parity, usart_hw_control_t hw_control);
void usart_deinit(usart_handle_t port);

int usart_send(usart_handle_t port, uint8_t *data, size_t length, int timeout);
int usart_recv(usart_handle_t port, uint8_t *data, size_t length, int timeout);

#endif //__USART_H__
