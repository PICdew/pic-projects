/*
 * Copyright (C) 2017 Johan Bergkvist
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include "mcc_generated_files/i2c1.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mpu6050.h"

#define MPU6050_ADDRESS        0x68 // When AD0 == 0

#define MPU6050_CONFIG_REG       26
#define MPU6050_ACCEL_X_REG      59
#define MPU6050_ACCEL_Y_REG      61
#define MPU6050_ACCEL_Z_REG      63
#define MPU6050_GYRO_X_REG       67
#define MPU6050_GYRO_Y_REG       69
#define MPU6050_GYRO_Z_REG       71
#define MPU6050_PWR_MGMT_1_REG  107
#define MPU6050_PWR_MGMT_2_REG  108
#define MPU6050_WHO_AM_I_REG    117

/*
 * Write "value" to register "reg". Returns true if successful, false otherwise.
 */
bool Mpu6050WriteRegister(uint8_t reg, uint8_t value) {
    uint8_t buffer[2];
    buffer[0] = reg;
    buffer[1] = value;
    
    I2C1_TRANSACTION_REQUEST_BLOCK trb;
    I2C1_MasterWriteTRBBuild(&trb, buffer, 2, MPU6050_ADDRESS);
    
    I2C1_MESSAGE_STATUS status = I2C1_MESSAGE_ADDRESS_NO_ACK;
    while (status == I2C1_MESSAGE_ADDRESS_NO_ACK
            || status == I2C1_DATA_NO_ACK) {
        I2C1_MasterTRBInsert(1, &trb, &status);
        while(status == I2C1_MESSAGE_PENDING);
    }
    
    return status != I2C1_MESSAGE_FAIL; 
}

/*
 * Read "value" from register "reg". Returns true if successful, false otherwise.
 */
bool Mpu6050ReadRegister(uint8_t reg, uint8_t *value) {
    I2C1_TRANSACTION_REQUEST_BLOCK trb[2];
    I2C1_MasterWriteTRBBuild(&trb[0], &reg, 1, MPU6050_ADDRESS);
    I2C1_MasterReadTRBBuild(&trb[1], value, 1, MPU6050_ADDRESS);
    
    I2C1_MESSAGE_STATUS status = I2C1_MESSAGE_ADDRESS_NO_ACK;
    while (status == I2C1_MESSAGE_ADDRESS_NO_ACK
            || status == I2C1_DATA_NO_ACK) {
        I2C1_MasterTRBInsert(2, trb, &status);
        while(status == I2C1_MESSAGE_PENDING);
    }
    
    return status != I2C1_MESSAGE_FAIL;
}

/*
 * Initializes the I2C bus and the MPU6050. Returns true if successful, false
 * otherwise.
 */
bool Mpu6050Init() {
    I2C1_Initialize();
    
    /*
     * Turn off then on the power and wait a bit.
     */
    MPU_POWER_SetLow();
    __delay_ms(100);
    MPU_POWER_SetHigh();
    __delay_ms(100);
    
    /*
     * Reset the device and wait for the device to come out of reset.
     */
    Mpu6050WriteRegister(MPU6050_PWR_MGMT_1_REG, 0x80);
    uint8_t value = 0x80;
    while (value & 0x80) {
        Mpu6050ReadRegister(MPU6050_PWR_MGMT_1_REG, &value);
        __delay_ms(100);
    }
    
    /*
     * Disable the temperature sensor, disable sleep mode, use X gyro as clock
     * source.
     */
    Mpu6050WriteRegister(MPU6050_PWR_MGMT_1_REG, 0x09);

    /*
     * No sensor in standby mode.
     */
    Mpu6050WriteRegister(MPU6050_PWR_MGMT_2_REG, 0x00);
    
    /*
     * Digital Low Pass Filter: ACC=184Hz, 2ms delay  GYR=188Hz, 1.9ms delay, Fs 1kHz
     */
    Mpu6050WriteRegister(MPU6050_CONFIG_REG, 0x01);

    /*
     * Check that the MPU6050 is online.
     */
    uint8_t identity;
    Mpu6050ReadRegister(MPU6050_WHO_AM_I_REG, &identity);
    return identity == MPU6050_ADDRESS;
}

/*
 * Read the accelerometer and gyro values. Returns true if successful, false
 * otherwise.
 */
bool Mpu6050Read(MPU6050_VALUES *values) {
    uint8_t reg = MPU6050_ACCEL_X_REG;
    uint8_t buffer[14]; // Six bytes for accel, two for temp, six for gyro.
    
    I2C1_TRANSACTION_REQUEST_BLOCK trb[2];
    I2C1_MasterWriteTRBBuild(&trb[0], &reg, 1, MPU6050_ADDRESS);
    I2C1_MasterReadTRBBuild(&trb[1], buffer, 14, MPU6050_ADDRESS);
    
    I2C1_MESSAGE_STATUS status = I2C1_MESSAGE_ADDRESS_NO_ACK;
    while (status == I2C1_MESSAGE_ADDRESS_NO_ACK
            || status == I2C1_DATA_NO_ACK) {
        I2C1_MasterTRBInsert(2, trb, &status);
        while(status == I2C1_MESSAGE_PENDING);
    }
    
    values->accel_x = (buffer[ 0] << 8) | buffer[ 1];
    values->accel_y = (buffer[ 2] << 8) | buffer[ 3];
    values->accel_z = (buffer[ 4] << 8) | buffer[ 5];
    values->gyro_x  = (buffer[ 8] << 8) | buffer[ 9];
    values->gyro_y  = (buffer[10] << 8) | buffer[11];
    values->gyro_z  = (buffer[12] << 8) | buffer[13];
    
    return status != I2C1_MESSAGE_FAIL;
}

