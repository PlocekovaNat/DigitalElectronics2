/***********************************************************************
 * 
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 * 
 * 

/* Define pins for motor 1 ------------------------------------------*/
#define servo1 PB1 

/* Define pins for motor 2 ---------------------------------------------*/
#define servo2 PB2

#define SHORT_DELAY 5 // Delay in milliseconds

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions

/* Arduino world -----------------------------------------------------*/
#include "Arduino.h"
#define PB1 10
#define PB2 11

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD screen when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
// Define global variables for position
uint16_t pos = 0;

int main(void)
{
    /* -------------------------Initialize display-----------------------------*/
    lcd_init(LCD_DISP_ON_CURSOR);
    
    /* -----------------------------

    /* -----------------------------Timer for SERVO 1-----------------------------------*/
    // Configure 16-bit Timer/Counter1 to start ADC conversion
    // Set prescaler to 33 ms and enable overflow interrupt
    TIM1_overflow_1s();
    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;

}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/1 overflow interrupt
 * Purpose:  Use single conversion mode and start conversion every 33 ms.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    static uint8_t no_of_overflows = 0;

    no_of_overflows++;
    if (no_of_overflows >= 10) {
        no_of_overflows = 0;
        for(pos=0;pos<=180;pos++){
            Myservo.write(pos);
            delay(15);
}
    }
}



