/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __GPIO_CON_BSP_H__
#define __GPIO_CON_BSP_H__

//Morpho connectors
#define CN7_1           0
#define CN7_3           (CN7_1 + 1)
#define CN7_13          (CN7_3 + 1)
#define CN7_15          (CN7_13 + 1)
#define CN7_17          (CN7_15 + 1)
#define CN7_21          (CN7_17 + 1)
#define CN7_23          (CN7_21 + 1)
#define CN7_25          (CN7_23 + 1)
#define CN7_27          (CN7_25 + 1)
#define CN7_29          (CN7_27 + 1)
#define CN7_31          (CN7_29 + 1)
#define CN7_35          (CN7_31 + 1)
#define CN7_37          (CN7_35 + 1)
#define CN7_2           (CN7_37 + 1)
#define CN7_4           (CN7_2 + 1)
#define CN7_28          (CN7_4 + 1)
#define CN7_30          (CN7_28 + 1)
#define CN7_32          (CN7_30 + 1)
#define CN7_34          (CN7_32 + 1)
#define CN7_36          (CN7_34 + 1)
#define CN7_38          (CN7_36 + 1)

#define CN10_1          (CN7_38 + 1)
#define CN10_3          (CN10_1 + 1)
#define CN10_5          (CN10_3 + 1)
#define CN10_11         (CN10_5 + 1)
#define CN10_13         (CN10_11 + 1)
#define CN10_15         (CN10_13 + 1)
#define CN10_17         (CN10_15 + 1)
#define CN10_19         (CN10_17 + 1)
#define CN10_21         (CN10_19 + 1)
#define CN10_23         (CN10_21 + 1)
#define CN10_25         (CN10_23 + 1)
#define CN10_27         (CN10_25 + 1)
#define CN10_29         (CN10_27 + 1)
#define CN10_31         (CN10_29 + 1)
#define CN10_33         (CN10_31 + 1)
#define CN10_35         (CN10_33 + 1)
#define CN10_37         (CN10_35 + 1)

#define CN10_2          (CN10_37 + 1)
#define CN10_4          (CN10_2 + 1)
#define CN10_6          (CN10_4 + 1)
#define CN10_12         (CN10_6 + 1)
#define CN10_14         (CN10_12 + 1)
#define CN10_16         (CN10_14 + 1)
#define CN10_22         (CN10_16 + 1)
#define CN10_24         (CN10_22 + 1)
#define CN10_26         (CN10_24 + 1)
#define CN10_28         (CN10_26 + 1)
#define CN10_30         (CN10_28 + 1)
#define CN10_34         (CN10_30 + 1)

#define STLINK_UART_RX  (CN10_34 + 1)
#define STLINK_UART_TX  (STLINK_UART_RX +1)

//Arduino connectors
#define CN8_1           CN7_28
#define A0              CN8_1
#define CN8_2           CN7_30
#define A1              CN8_2
#define CN8_3           CN7_32
#define A2              CN8_3
#define CN8_4           CN7_34
#define A3              CN8_4
#define CN8_5           CN7_36
#define A4              CN8_5
#define CN8_6           CN7_38
#define A5              CN8_6

#define CN5_1           CN10_21
#define D8              CN5_1
#define CN5_2           CN10_19
#define D9              CN5_2
#define CN5_3           CN10_17
#define D10             CN5_3
#define CN5_4           CN10_15
#define D11             CN5_4
#define CN5_5           CN10_13
#define D12             CN5_5
#define CN5_6           CN10_11
#define D13             CN5_6
#define CN5_9           CN10_5
#define D14             CN5_9
#define CN5_10          CN10_3
#define D15             CN5_10

#define CN9_1           CN10_37
#define D0              CN9_1
#define CN9_2           CN10_35
#define D1              CN9_2
#define CN9_3           CN10_33
#define D2              CN9_3
#define CN9_4           CN10_31
#define D3              CN9_4
#define CN9_5           CN10_29
#define D4              CN9_5
#define CN9_6           CN10_27
#define D5              CN9_6
#define CN9_7           CN10_25
#define D6              CN9_7
#define CN9_8           CN10_23
#define D7              CN9_8

#define LED_1			D13
#define USER_BUTTON		CN7_23

#endif /* __GPIO_CON_BSP_H__ */