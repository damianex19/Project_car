/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <lukasz.stempien@gmail.com> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return.
 *                                                              Lukasz Stempien
 * ----------------------------------------------------------------------------
 */
#ifndef __ACC_MAG_LSM303D_H__
#define __ACC_MAG_LSM303D_H__

#include <stdint.h>
#include "i2c.h"

typedef enum acc_la_fs_e {
  LA_FS_2G  = 0,
  LA_FS_4G  = 1,
  LA_FS_6G  = 2,
  LA_FS_8G  = 3,
  LA_FS_16G = 4,
} acc_la_fs_t;

typedef enum acc_data_rate_e {
  ACC_DATA_RATE_PWR_DOWN = 0x0,
  ACC_DATA_RATE_3_125Hz = 0x1,
  ACC_DATA_RATE_6_25Hz = 0x2,
  ACC_DATA_RATE_12_5Hz = 0x3,
  ACC_DATA_RATE_25Hz = 0x4,
  ACC_DATA_RATE_50Hz = 0x5,
  ACC_DATA_RATE_100Hz = 0x6,
  ACC_DATA_RATE_200Hz = 0x7,
  ACC_DATA_RATE_400Hz = 0x8,
  ACC_DATA_RATE_800Hz = 0x9,
  ACC_DATA_RATE_1600Hz = 0xA,
  ACC_DATA_RATE_END,
} acc_data_rate_t;

typedef struct acc_config_s {
  uint8_t           SDO_SA0_pin_state;
  acc_la_fs_t       acc_range;
  acc_data_rate_t   acc_rate;
} acc_config_t;

int8_t lsm303d_acc_init(acc_config_t *config);
void lsm303d_acc_deinit(acc_config_t *config);
int8_t lsm303d_acc_read_acc_val(float *val);

#endif /* __ACC_MAG_LSM303D_H__ */
