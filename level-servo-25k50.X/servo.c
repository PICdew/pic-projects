/*
 * Copyright (C) 2017 Johan Bergkvist
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include "servo.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"

#define SERVO_PULSE      0  // Servo signal is high (1ms - 2ms).
#define SERVO_POSTPULSE  1  // Servo signal is low (18ms - 19ms).

volatile uint16_t g_servo_state;      // SERVO_PULSE or SERVO_POSTPULSE
volatile uint16_t g_servo_high_value; // TMR0 value to load when starting SERVO_PULSE
volatile uint16_t g_servo_low_value;  // TMR0 value to load when starting SERVO_POSTPULSE

/*
 * Invoked when TMR1 goes from 0xffff to 0x0000.
 */
void OnTMR0Interrupt(void) {
    switch (g_servo_state) {
    case SERVO_PULSE:
        TMR0_WriteTimer(g_servo_low_value);
        SERVO_SetLow();
        g_servo_state = SERVO_POSTPULSE;
        break;
    case SERVO_POSTPULSE:
        TMR0_WriteTimer(g_servo_high_value);
        SERVO_SetHigh();
        g_servo_state = SERVO_PULSE;
        break;
    }
}

/*
 * Initializes the servo related resources.
 */
void ServoInit() {
    TMR0_SetInterruptHandler(OnTMR0Interrupt);
    
    ServoSet(0);
    g_servo_state = SERVO_POSTPULSE;
    TMR0_WriteTimer(0);
}

/*
 * Set the servo position. A value of zero centers the servo. Positive values
 * moves the servo clockwise. Negative values moves the servo counter clockwise.
 */
void ServoSet(int8_t value) {
    /*
     * The timer runs at 2MHz, so 0.5ms is 1000 ticks. We need a "value" of 128
     * to translate into 1000 ticks, so we multiply by eight. Not exactly 1000,
     * but close enough.
     * 
     * Likewise, a value of -128 will yield approximately -1000.
     */

    int16_t bigger_value = value;
    g_servo_high_value = (uint16_t)((int16_t)3000 + bigger_value * 8);
    
    /*
     * The full period is 20ms, which is 40000 ticks. So we need to stay low
     * whatever time is left after the high pulse.
     */
    g_servo_low_value = 40000 - g_servo_high_value;
    
    /*
     * The timer will run from the given value until it wraps around after
     * 65535, so the value we need to load is the number of ticks subtracted
     * from 65536. We use 65535 to avoid a 16 bit overflow.
     */
    g_servo_high_value = 65535 - g_servo_high_value;
    g_servo_low_value = 65535 - g_servo_low_value;
}

