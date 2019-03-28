/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include "stm32f4xx_hal_conf.h"

#ifdef UART_STLINK_UART_TX
	#define UART_USART2_TX_PIN STLINK_UART_TX
#endif

#ifdef UART_STLINK_UART_RX
	#define UART_USART2_RX_PIN STLINK_UART_RX
#endif

#ifdef UART_USART1_TX_CN10_21 //AF7
	#define UART_USART1_TX_PIN CN10_21
#endif

#ifdef UART_USART1_RX_CN7_21 //AF7
	#define UART_USART1_RX_PIN CN7_21
#endif

#ifdef UART_USART1_RX_CN10_33 //AF7
	#define UART_USART1_RX_PIN CN10_33
#endif

#ifdef UART_USART2_TX_CN10_35
	#define UART_USART2_TX_PIN CN10_35
#endif

#ifdef UART_USART2_RX_CN10_37
	#define UART_USART2_RX_PIN CN10_37
#endif

#ifdef UART_USART3_TX_CN10_25 //AF7
	#define UART_USART3_TX_PIN CN10_25
#endif

#ifdef UART_USART3_TX_CN7_1 //AF7
	#define UART_USART3_TX_PIN CN7_1
#endif

#ifdef UART_USART3_RX_CN7_2 //AF7
	#define UART_USART3_RX_PIN CN7_2
#endif

#ifdef UART_UART4_TX_CN7_1 //AF8
	#define UART_UART4_TX_PIN CN7_1
#endif

#ifdef UART_UART4_RX_CN7_2 //AF8
	#define UART_UART4_RX_PIN CN7_2
#endif

#ifdef UART_UART4_TX_CN7_28 //AF8
	#define UART_UART4_TX_PIN CN7_28
#endif

#ifdef UART_UART4_RX_CN7_30 //AF8
	#define UART_UART4_RX_PIN CN7_30
#endif

#ifdef UART_UART5_TX_CN7_3 //AF8
	#define UART_UART5_TX_PIN CN7_3
#endif

#ifdef UART_UART5_RX_CN7_4 //AF8
	#define UART_UART5_RX_PIN CN7_4
#endif

#ifdef UART_USART1_TX_CN10_17 //AF7
	#define UART_USART1_TX_PIN CN10_17
#endif

#ifdef UART_USART6_RX_CN10_19 //AF7
	#define UART_USART6_RX_PIN CN10_19
#endif
