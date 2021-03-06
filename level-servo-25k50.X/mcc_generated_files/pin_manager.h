/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC18F25K50
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set DEBUG_0 aliases
#define DEBUG_0_TRIS               TRISAbits.TRISA0
#define DEBUG_0_LAT                LATAbits.LATA0
#define DEBUG_0_PORT               PORTAbits.RA0
#define DEBUG_0_ANS                ANSELAbits.ANSA0
#define DEBUG_0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define DEBUG_0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define DEBUG_0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define DEBUG_0_GetValue()           PORTAbits.RA0
#define DEBUG_0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define DEBUG_0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define DEBUG_0_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define DEBUG_0_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set DEBUG_1 aliases
#define DEBUG_1_TRIS               TRISAbits.TRISA1
#define DEBUG_1_LAT                LATAbits.LATA1
#define DEBUG_1_PORT               PORTAbits.RA1
#define DEBUG_1_ANS                ANSELAbits.ANSA1
#define DEBUG_1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define DEBUG_1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define DEBUG_1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define DEBUG_1_GetValue()           PORTAbits.RA1
#define DEBUG_1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define DEBUG_1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define DEBUG_1_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define DEBUG_1_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()    do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()   do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()   do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()         PORTBbits.RB0
#define RB0_SetDigitalInput()   do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()  do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()     do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()   do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode() do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()    do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()   do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()   do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()         PORTBbits.RB1
#define RB1_SetDigitalInput()   do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()  do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()     do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()   do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode() do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set MPU_POWER aliases
#define MPU_POWER_TRIS               TRISBbits.TRISB2
#define MPU_POWER_LAT                LATBbits.LATB2
#define MPU_POWER_PORT               PORTBbits.RB2
#define MPU_POWER_WPU                WPUBbits.WPUB2
#define MPU_POWER_ANS                ANSELBbits.ANSB2
#define MPU_POWER_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define MPU_POWER_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define MPU_POWER_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define MPU_POWER_GetValue()           PORTBbits.RB2
#define MPU_POWER_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define MPU_POWER_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define MPU_POWER_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define MPU_POWER_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)
#define MPU_POWER_SetAnalogMode()  do { ANSELBbits.ANSB2 = 1; } while(0)
#define MPU_POWER_SetDigitalMode() do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set SERVO aliases
#define SERVO_TRIS               TRISCbits.TRISC1
#define SERVO_LAT                LATCbits.LATC1
#define SERVO_PORT               PORTCbits.RC1
#define SERVO_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SERVO_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SERVO_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SERVO_GetValue()           PORTCbits.RC1
#define SERVO_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SERVO_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS               TRISCbits.TRISC6
#define LED_LAT                LATCbits.LATC6
#define LED_PORT               PORTCbits.RC6
#define LED_ANS                ANSELCbits.ANSC6
#define LED_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LED_GetValue()           PORTCbits.RC6
#define LED_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LED_SetAnalogMode()  do { ANSELCbits.ANSC6 = 1; } while(0)
#define LED_SetDigitalMode() do { ANSELCbits.ANSC6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/