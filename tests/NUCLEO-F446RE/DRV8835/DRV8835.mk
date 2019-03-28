DRV8835_TEST_DIR = $(PWD)
DRV8835_TEST_OBJ = $(DRV8835_TEST_DIR)/main.o \
				   $(DRV8835_TEST_DIR)/drv8835_test.o

CFLAGS += -I$(DRV8835_TEST_DIR)

$(DRV8835_TEST_DIR)/drv8835_test.elf: $(TARGET_OBJ) $(DRV8835_TEST_OBJ)
	$(CC) -mthumb -mcpu=$(CPU) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T$(ROOT_DIR)/$(LNK_SCRIPT) -Wl,--gc-sections -o $@ $^
	$(OBJCOPY) -Oihex $(DRV8835_TEST_DIR)/drv8835_test.elf $(DRV8835_TEST_DIR)/drv8835_test.hex

test/DRV8835: $(DRV8835_TEST_DIR)/drv8835_test.elf

test/DRV8835_clean: 
	rm -rf $(DRV8835_TEST_OBJ)
	rm -f $(DRV8835_TEST_DIR)/drv8835_test.elf $(DRV8835_TEST_DIR)/drv8835_test.hex
	rm -rf soc
	rm -rf bsp
	rm -rf hal