I2C_MASTER_TEST_DIR = $(PWD)
I2C_MASTER_TEST_OBJ = $(I2C_MASTER_TEST_DIR)/main.o \
					   $(I2C_MASTER_TEST_DIR)/leds_blink.o

CFLAGS += -I$(I2C_MASTER_TEST_DIR)

$(I2C_MASTER_TEST_DIR)/i2c_master_test.elf: $(TARGET_OBJ) $(I2C_MASTER_TEST_OBJ)
	$(CC) -mthumb -mcpu=$(CPU) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T$(ROOT_DIR)/$(LNK_SCRIPT) -Wl,--gc-sections -o $@ $^
	$(OBJCOPY) -Oihex $(I2C_MASTER_TEST_DIR)/i2c_master_test.elf $(I2C_MASTER_TEST_DIR)/i2c_master_test.hex

test/I2CMaster: $(I2C_MASTER_TEST_DIR)/i2c_master_test.elf

test/I2CMaster_clean:
	rm -rf $(I2C_MASTER_TEST_OBJ)
	rm -rf $(I2C_MASTER_TEST_DIR)/i2c_master_test.elf $(I2C_MASTER_TEST_DIR)/i2c_master_test.hex
	rm -rf soc
	rm -rf bsp
	rm -rf hal