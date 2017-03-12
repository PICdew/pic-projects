/*
 * Copyright (C) 2017 Johan Bergkvist
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#ifndef MPU6050_H
#define	MPU6050_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int16_t accel_x;
    int16_t accel_y;
    int16_t accel_z;
    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;
} MPU6050_VALUES;

bool Mpu6050Init();
bool Mpu6050Read(MPU6050_VALUES *values);

#endif	/* MPU6050_H */

