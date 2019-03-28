BSP_DRIVERS_SRC_DIR = $(ROOT_DIR)/drivers/portable/bsp/NUCLEO-F446RE/
CFLAGS += -I$(BSP_DRIVERS_SRC_DIR)

ifeq ($(CONFIG_BSP_LEDS),'y')
	TARGET_OBJ += bsp/leds.o
endif

ifeq ($(CONFIG_BSP_I2C),'y')
	TARGET_OBJ += bsp/i2c_bsp.o
endif

ifeq ($(CONFIG_BSP_USART),'y')
	TARGET_OBJ += bsp/usart_bsp.o
endif

ifeq ($(CONFIG_BSP_ENCODER),'y')
	TARGET_OBJ += bsp/encoder_bsp.o
endif

ifeq ($(CONFIG_BSP_PWM),'y')
	TARGET_OBJ += bsp/pwm_bsp.o
endif

ifeq ($(CONFIG_BSP_I2C),'y')
	TARGET_OBJ += bsp/i2c_bsp.o
endif

bsp/%.o: $(BSP_DRIVERS_SRC_DIR)/%.c
	mkdir -p $(PROJECT_DIR)/bsp
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
