HAL_DIR = $(CUBE_DIR)/Drivers/STM32F4xx_HAL_Driver
HAL_INC_DIR = $(HAL_DIR)/Inc
HAL_SRC_DIR = $(HAL_DIR)/Src

CFLAGS += -I$(HAL_INC_DIR)
CFLAGS += -I$(CUBE_DIR)/Drivers/CMSIS/Device/ST/STM32F4xx/Include/
CFLAGS += -I$(CUBE_DIR)/Drivers/CMSIS/Include/

TARGET_OBJ +=	$(PROJECT_DIR)/hal/stm32f4xx_hal.o \
				$(PROJECT_DIR)/hal/stm32f4xx_hal_rcc.o \
				$(PROJECT_DIR)/hal/stm32f4xx_hal_pwr_ex.o \
				$(PROJECT_DIR)/hal/stm32f4xx_hal_gpio.o \
				$(PROJECT_DIR)/hal/stm32f4xx_hal_cortex.o

ifeq ($(CONFIG_HAL_SPI), 'y')
	CONFIG_HAL_DMA = 'y'
	TARGET_OBJ += $(PROJECT_DIR)/hal/stm32f4xx_hal_spi.o
endif

ifeq ($(CONFIG_HAL_I2C), 'y')
	CONFIG_HAL_DMA = 'y'
	TARGET_OBJ += $(PROJECT_DIR)/hal/stm32f4xx_hal_i2c.o
endif

ifeq ($(CONFIG_HAL_TIM), 'y')
	CONFIG_HAL_DMA = 'y'
	CONFIG_HAL_TIM_EX = 'y'
	TARGET_OBJ += $(PROJECT_DIR)/hal/stm32f4xx_hal_tim.o
endif

ifeq ($(CONFIG_HAL_DMA), 'y')
	TARGET_OBJ += $(PROJECT_DIR)/hal/stm32f4xx_hal_dma.o
endif

ifeq ($(CONFIG_HAL_TIM_EX), 'y')
	TARGET_OBJ += $(PROJECT_DIR)/hal/stm32f4xx_hal_tim_ex.o
endif

ifeq ($(CONFIG_HAL_RCC_EX), 'y')
	TARGET_OBJ += $(PROJECT_DIR)/hal/stm32f4xx_hal_rcc_ex.o
endif

ifeq ($(CONFIG_HAL_UART), 'y')
	CONFIG_HAL_DMA = 'y'
	TARGET_OBJ += $(PROJECT_DIR)/hal/stm32f4xx_hal_uart.o
endif

$(PROJECT_DIR)/hal/%.o: $(HAL_SRC_DIR)/%.c
	mkdir -p $(PROJECT_DIR)/hal
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@