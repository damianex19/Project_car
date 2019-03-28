/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __GPIO_BSP_PIN_H__
#define __GPIO_BSP_PIN_H__

#include <FreeRTOS.h>
#include "stm32f4xx_hal_conf.h"

#include "gpio_bsp_con.h"

#define CN7_1_PIN           GPIO_PIN_10
#define CN7_1_PORT          GPIOC

#define CN7_3_PIN           GPIO_PIN_12
#define CN7_3_PORT          GPIOC

#define CN7_13_PIN          GPIO_PIN_13
#define CN7_13_PORT         GPIOA

#define CN7_15_PIN          GPIO_PIN_14
#define CN7_15_PORT         GPIOA

#define CN7_17_PIN          GPIO_PIN_15
#define CN7_17_PORT         GPIOA

#define CN7_21_PIN          GPIO_PIN_7
#define CN7_21_PORT         GPIOB

#define CN7_23_PIN          GPIO_PIN_13
#define CN7_23_PORT         GPIOC

#define CN7_25_PIN          GPIO_PIN_14
#define CN7_25_PORT         GPIOC

#define CN7_27_PIN          GPIO_PIN_15
#define CN7_27_PORT         GPIOC

#define CN7_29_PIN          GPIO_PIN_0
#define CN7_29_PORT         GPIOH

#define CN7_31_PIN          GPIO_PIN_1
#define CN7_31_PORT         GPIOH

#define CN7_35_PIN          GPIO_PIN_2
#define CN7_35_PORT         GPIOC

#define CN7_37_PIN          GPIO_PIN_3
#define CN7_37_PORT         GPIOC

#define CN7_2_PIN           GPIO_PIN_11
#define CN7_2_PORT          GPIOC

#define CN7_4_PIN           GPIO_PIN_2
#define CN7_4_PORT          GPIOD

#define CN7_28_PIN          GPIO_PIN_0
#define CN7_28_PORT         GPIOA

#define CN7_30_PIN          GPIO_PIN_1
#define CN7_30_PORT         GPIOA

#define CN7_32_PIN          GPIO_PIN_4
#define CN7_32_PORT         GPIOA

#define CN7_34_PIN          GPIO_PIN_0
#define CN7_34_PORT         GPIOB

#define CN7_36_PIN          GPIO_PIN_1
#define CN7_36_PORT         GPIOC

#define CN7_38_PIN          GPIO_PIN_0
#define CN7_38_PORT         GPIOC

#define CN10_1_PIN          GPIO_PIN_9
#define CN10_1_PORT         GPIOC

#define CN10_3_PIN          GPIO_PIN_8
#define CN10_3_PORT         GPIOB

#define CN10_5_PIN          GPIO_PIN_9
#define CN10_5_PORT         GPIOB

#define CN10_11_PIN         GPIO_PIN_5
#define CN10_11_PORT        GPIOA

#define CN10_13_PIN         GPIO_PIN_6
#define CN10_13_PORT        GPIOA

#define CN10_15_PIN         GPIO_PIN_7
#define CN10_15_PORT        GPIOA

#define CN10_17_PIN         GPIO_PIN_6
#define CN10_17_PORT        GPIOB

#define CN10_19_PIN         GPIO_PIN_7
#define CN10_19_PORT        GPIOC

#define CN10_21_PIN         GPIO_PIN_9
#define CN10_21_PORT        GPIOA

#define CN10_23_PIN         GPIO_PIN_8
#define CN10_23_PORT        GPIOA

#define CN10_25_PIN         GPIO_PIN_10
#define CN10_25_PORT        GPIOB

#define CN10_27_PIN         GPIO_PIN_4
#define CN10_27_PORT        GPIOB

#define CN10_29_PIN         GPIO_PIN_5
#define CN10_29_PORT        GPIOB

#define CN10_31_PIN         GPIO_PIN_3
#define CN10_31_PORT        GPIOB

#define CN10_33_PIN         GPIO_PIN_10
#define CN10_33_PORT        GPIOA

#define CN10_35_PIN         GPIO_PIN_2
#define CN10_35_PORT        GPIOA

#define CN10_37_PIN         GPIO_PIN_3
#define CN10_37_PORT        GPIOA

#define CN10_2_PIN          GPIO_PIN_8
#define CN10_2_PORT         GPIOC

#define CN10_4_PIN          GPIO_PIN_6
#define CN10_4_PORT         GPIOC

#define CN10_6_PIN          GPIO_PIN_5
#define CN10_6_PORT         GPIOC

#define CN10_12_PIN         GPIO_PIN_12
#define CN10_12_PORT        GPIOA

#define CN10_14_PIN         GPIO_PIN_11
#define CN10_14_PORT        GPIOA

#define CN10_16_PIN         GPIO_PIN_12
#define CN10_16_PORT        GPIOB

#define CN10_22_PIN         GPIO_PIN_2
#define CN10_22_PORT        GPIOB

#define CN10_24_PIN         GPIO_PIN_1
#define CN10_24_PORT        GPIOB

#define CN10_26_PIN         GPIO_PIN_15
#define CN10_26_PORT        GPIOB

#define CN10_28_PIN         GPIO_PIN_14
#define CN10_28_PORT        GPIOB

#define CN10_30_PIN         GPIO_PIN_13
#define CN10_30_PORT        GPIOB

#define CN10_34_PIN         GPIO_PIN_4
#define CN10_34_PORT        GPIOC

#define STLINK_UART_RX_PIN  GPIO_PIN_3
#define STLINK_UART_RX_PORT GPIOA

#define STLINK_UART_TX_PIN  GPIO_PIN_2
#define STLINK_UART_TX_PORT GPIOA

typedef struct gpio_pin_s
{
    uint16_t pin;
    GPIO_TypeDef *port;
} gpio_pin_t;

const gpio_pin_t connector[] = {
    [CN7_1]             {.pin = CN7_1_PIN, .port = CN7_1_PORT},
    [CN7_3]             {.pin = CN7_3_PIN, .port = CN7_3_PORT},
    [CN7_13]            {.pin = CN7_13_PIN, .port = CN7_13_PORT},
    [CN7_15]            {.pin = CN7_15_PIN, .port = CN7_15_PORT},
    [CN7_17]            {.pin = CN7_17_PIN, .port = CN7_17_PORT},
    [CN7_21]            {.pin = CN7_21_PIN, .port = CN7_21_PORT},
    [CN7_23]            {.pin = CN7_23_PIN, .port = CN7_23_PORT},
    [CN7_25]            {.pin = CN7_25_PIN, .port = CN7_25_PORT},
    [CN7_27]            {.pin = CN7_27_PIN, .port = CN7_27_PORT},
    [CN7_29]            {.pin = CN7_29_PIN, .port = CN7_29_PORT},
    [CN7_31]            {.pin = CN7_31_PIN, .port = CN7_31_PORT},
    [CN7_35]            {.pin = CN7_35_PIN, .port = CN7_35_PORT},
    [CN7_37]            {.pin = CN7_37_PIN, .port = CN7_37_PORT},
    [CN7_2]             {.pin = CN7_2_PIN, .port = CN7_2_PORT},
    [CN7_4]             {.pin = CN7_4_PIN, .port = CN7_4_PORT},
    [CN7_28]            {.pin = CN7_28_PIN, .port = CN7_28_PORT},
    [CN7_30]            {.pin = CN7_30_PIN, .port = CN7_30_PORT},
    [CN7_32]            {.pin = CN7_32_PIN, .port = CN7_32_PORT},
    [CN7_34]            {.pin = CN7_34_PIN, .port = CN7_34_PORT},
    [CN7_36]            {.pin = CN7_36_PIN, .port = CN7_36_PORT},
    [CN7_38]            {.pin = CN7_38_PIN, .port = CN7_38_PORT},
    [CN10_1]            {.pin = CN10_1_PIN, .port = CN10_1_PORT},
    [CN10_3]            {.pin = CN10_3_PIN, .port = CN10_3_PORT},
    [CN10_5]            {.pin = CN10_5_PIN, .port = CN10_5_PORT},
    [CN10_11]           {.pin = CN10_11_PIN, .port = CN10_11_PORT},
    [CN10_13]           {.pin = CN10_13_PIN, .port = CN10_13_PORT},
    [CN10_15]           {.pin = CN10_15_PIN, .port = CN10_15_PORT},
    [CN10_17]           {.pin = CN10_17_PIN, .port = CN10_17_PORT},
    [CN10_19]           {.pin = CN10_19_PIN, .port = CN10_19_PORT},
    [CN10_21]           {.pin = CN10_21_PIN, .port = CN10_21_PORT},
    [CN10_23]           {.pin = CN10_23_PIN, .port = CN10_23_PORT},
    [CN10_25]           {.pin = CN10_25_PIN, .port = CN10_25_PORT},
    [CN10_27]           {.pin = CN10_27_PIN, .port = CN10_27_PORT},
    [CN10_29]           {.pin = CN10_29_PIN, .port = CN10_29_PORT},
    [CN10_31]           {.pin = CN10_31_PIN, .port = CN10_31_PORT},
    [CN10_33]           {.pin = CN10_33_PIN, .port = CN10_33_PORT},
    [CN10_35]           {.pin = CN10_35_PIN, .port = CN10_35_PORT},
    [CN10_37]           {.pin = CN10_37_PIN, .port = CN10_37_PORT},
    [CN10_2]            {.pin = CN10_2_PIN, .port = CN10_2_PORT},
    [CN10_4]            {.pin = CN10_4_PIN, .port = CN10_4_PORT},
    [CN10_6]            {.pin = CN10_6_PIN, .port = CN10_6_PORT},
    [CN10_12]           {.pin = CN10_12_PIN, .port = CN10_12_PORT},
    [CN10_14]           {.pin = CN10_14_PIN, .port = CN10_14_PORT},
    [CN10_16]           {.pin = CN10_16_PIN, .port = CN10_16_PORT},
    [CN10_22]           {.pin = CN10_22_PIN, .port = CN10_22_PORT},
    [CN10_24]           {.pin = CN10_24_PIN, .port = CN10_24_PORT},
    [CN10_26]           {.pin = CN10_26_PIN, .port = CN10_26_PORT},
    [CN10_28]           {.pin = CN10_28_PIN, .port = CN10_28_PORT},
    [CN10_30]           {.pin = CN10_30_PIN, .port = CN10_30_PORT},
    
    [STLINK_UART_RX]    {.pin = STLINK_UART_RX_PIN, .port = STLINK_UART_RX_PORT},
    [STLINK_UART_TX]    {.pin = STLINK_UART_TX_PIN, .port = STLINK_UART_TX_PORT}
};

#endif // __GPIO_BSP_PIN_H__
