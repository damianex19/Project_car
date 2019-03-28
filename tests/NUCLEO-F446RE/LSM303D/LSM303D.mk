LDM303D_TEST_DIR = $(PWD)
I2C_MASTER_TEST_OBJ = $(LDM303D_TEST_DIR)/main.o \
					   $(LDM303D_TEST_DIR)/lsm303d_test.o

CFLAGS += -I$(LDM303D_TEST_DIR)

$(LDM303D_TEST_DIR)/lsm303d_test.elf: $(TARGET_OBJ) $(I2C_MASTER_TEST_OBJ)
	$(CC) -mthumb -mcpu=$(CPU) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T$(ROOT_DIR)/$(LNK_SCRIPT) -Wl,--gc-sections -o $@ $^
	$(OBJCOPY) -Oihex $(LDM303D_TEST_DIR)/lsm303d_test.elf $(LDM303D_TEST_DIR)/lsm303d_test.hex

test/LSM303D: $(LDM303D_TEST_DIR)/lsm303d_test.elf

test/LSM303D_clean:
	rm -rf $(I2C_MASTER_TEST_OBJ)
	rm -rf $(LDM303D_TEST_DIR)/lsm303d_test.elf $(LDM303D_TEST_DIR)/lsm303d_test.hex
	rm -rf soc
	rm -rf bsp
	rm -rf hal