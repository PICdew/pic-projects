/*
 * Copyright (C) 2017 Johan Bergkvist
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdio.h>
#include <stdlib.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "servo.h"
#include "mpu6050.h"

/*
 * 
 */
int main() {
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    /*
     * Flash the LED ten times to show that we have reset.
     */
    for (int i = 0; i < 10; i++) {
        LED_SetHigh();
        __delay_ms(100);
        LED_SetLow();
        __delay_ms(100);
    }

    ServoInit();
    Mpu6050Init();
    
    /*
     * Read the gyro and accelerometers. Use the servo to indicate rotation
     * around the Z axis.
     */
    while (1) {
        MPU6050_VALUES values;
        if (Mpu6050Read(&values)) {
            ServoSet(values.gyro_z >> 8);
        }
        __delay_ms(20);
    }
}

