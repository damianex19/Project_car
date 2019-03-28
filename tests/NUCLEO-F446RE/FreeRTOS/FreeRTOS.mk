FREE_RTOS_TEST_DIR = $(PWD)
FREE_RTOS_TEST_OBJ = $(FREE_RTOS_TEST_DIR)/main.o

CFLAGS += -I$(FREE_RTOS_TEST_DIR)

$(FREE_RTOS_TEST_DIR)/freertos_test.elf: $(TARGET_OBJ) $(FREE_RTOS_TEST_OBJ)
	$(CC) -mthumb -mcpu=$(CPU) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T$(ROOT_DIR)/$(LNK_SCRIPT) -Wl,--gc-sections -o $@ $^
	$(OBJCOPY) -Oihex $(FREE_RTOS_TEST_DIR)/freertos_test.elf $(FREE_RTOS_TEST_DIR)/freertos_test.hex

test/FreeRTOS: $(FREE_RTOS_TEST_DIR)/freertos_test.elf

test/FreeRTOS_clean:
	rm -rf $(FREE_RTOS_TEST_OBJ)
	rm -rf $(FREE_RTOS_TEST_DIR)/freertos_test.elf $(FREE_RTOS_TEST_DIR)/freertos_test.hex
	rm -rf soc
	rm -rf bsp
	rm -rf hal