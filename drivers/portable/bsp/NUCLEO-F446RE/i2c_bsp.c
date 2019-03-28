/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include "stm32f4xx_hal_conf.h"

#ifdef I2C1_SCL_CN10_17
	#define I2C1_SCL_PIN CN10_17
#endif

#ifdef I2C1_SCL_CN10_3
	#define I2C1_SCL_PIN CN10_3
#endif

#ifdef I2C1_SDA_CN7_21
	#define I2C1_SDA_PIN CN7_21
#endif

#ifdef I2C1_SDA_CN10_5
	#define I2C1_SDA_PIN CN10_5
#endif

#ifdef I2C3_SCL_CN10_23
	#define I2C3_SCL_PIN CN10_23
#endif

#ifdef I2C3_SDA_CN10_27
	#define I2C3_SDA_PIN CN10_27
#endif

#ifdef I2C3_SDA_CN10_1
	#define I2C3_SDA_PIN CN10_1
#endif

#ifdef I2C2_SCL_CN10_25
	#define I2C2_SCL_PIN CN10_25
#endif

#ifdef I2C2_SDA_CN10_31
	#define I2C2_SDA_PIN CN10_31
#endif

#ifdef I2C2_SDA_CN10_18
	#define I2C2_SDA_PIN CN10_18
#endif

#ifdef I2C2_SDA_CN7_3
	#define I2C2_SDA_PIN CN7_3
#endif
