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

#define SERVO_NOPULSE    0
#define SERVO_PULSE      1
#define SERVO_POSTPULSE  2

volatile uint16_t g_servo_high_value;
volatile uint16_t g_servo_low_value;
volatile uint16_t g_servo_state;

/*
 * This function will be called every 100us.
 */
void OnTMR0Interrupt(void) {
    switch (g_servo_state) {
    case SERVO_NOPULSE:
        g_servo_state = SERVO_POSTPULSE;
        TMR0_WriteTimer(0); // Wait for as long as possible.
        break;
    case SERVO_PULSE:
        g_servo_state = SERVO_POSTPULSE;
        SERVO_SetLow();
        TMR0_WriteTimer(g_servo_low_value);
        break;
    case SERVO_POSTPULSE:
        g_servo_state = SERVO_PULSE;
        SERVO_SetHigh();
        TMR0_WriteTimer(g_servo_high_value);
        break;
    }
}

/*
 * Calculates servo values. A value of 0 gives full left. A value of 50 centers
 * the servo. A value of 100 gives full right.
 */
void CalculateServoValues(uint8_t value) {
    /*
     * Dividing one ms into 100 bits yields 10us per bit.
     * At 2MHz (Fosc/4 and prescaler 1:2) gives 20 ticks per bit.
     * The first ms is 2000 ticks.
     * The remaining 19ms is 38000 ticks. Subtract from that the length of the
     * pulse excluding the first ms.
     */
    g_servo_high_value = 65535 - (2000 + 20 * value);
    g_servo_low_value = 65535 - (38000 - 20 * value);
}

/*
 * 
 */
int main() {
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    g_servo_state = SERVO_NOPULSE;
    
    TMR0_SetInterruptHandler(OnTMR0Interrupt);
    
    /*
     * Calculate the servo values for the ISR and kick it off.
     */
    CalculateServoValues(50);
    OnTMR0Interrupt();
    
    /*
     * Flash the LED ten times to show that we have reset.
     */
    for (int i = 0; i < 10; i++) {
        LED_SetHigh();
        __delay_ms(100);
        LED_SetLow();
        __delay_ms(100);
    }
    
    while (1) {
        LED_SetHigh();
        __delay_ms(200);
        LED_SetLow();
        __delay_ms(500);
    }
}

