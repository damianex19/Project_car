SOC_DRIVERS_SRC_DIR = $(ROOT_DIR)/drivers/portable/soc/STM32F446xx/
CFLAGS += -I$(SOC_DRIVERS_SRC_DIR)

ifeq ($(CONFIG_SOC_GPIO),'y')
	TARGET_OBJ += soc/gpio_soc.o
endif

ifeq ($(CONFIG_SOC_USART),'y')
	CONFIG_HAL_UART = 'y'
	CONFIG_HAL_DMA = 'y'
	CONFIG_BSP_USART = 'y'
	TARGET_OBJ += soc/usart_soc.o
endif

ifeq ($(CONFIG_SOC_ENCODER),'y')
	CONFIG_HAL_TIM = 'y'
	CONFIG_BSP_ENCODER = 'y'
	TARGET_OBJ += soc/encoder_soc.o
endif   

ifeq ($(CONFIG_SOC_PWM),'y')
	CONFIG_HAL_TIM = 'y'
	CONFIG_HAL_RCC_EX = 'y'
	CONFIG_BSP_PWM = 'y'
	TARGET_OBJ += soc/pwm_soc.o
endif

ifeq ($(CONFIG_SOC_I2C),'y')
	CONFIG_HAL_I2C = 'y'
	CONFIG_BSP_I2C = 'y'
	TARGET_OBJ += soc/i2c_common_soc.o \
				  soc/i2c_master_soc.o
endif


soc/%.o: $(SOC_DRIVERS_SRC_DIR)/%.c
	mkdir -p $(PROJECT_DIR)/soc
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
