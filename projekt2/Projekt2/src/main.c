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

#define SHORT_DELAY 0.5 // Delay in milliseconds

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
#define PB1 9
#define PB2 10

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
    
    /* ----------------------------- */
    // GPIO_mode_output(&DDRB, servo1);
    GPIO_mode_output(&DDRB, servo2);


    /* -----------------------------Timer for SERVO 1-----------------------------------*/
    // Configure 16-bit Timer/Counter1 to start ADC conversion
    // Set prescaler to 33 ms and enable overflow interrupt
    TIM0_overflow_16ms();
    TIM0_overflow_interrupt_enable();

    TIM2_overflow_16ms();
    TIM2_overflow_interrupt_enable();



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
/*
ISR(TIMER1_OVF_vect)
{
    static uint8_t no_of_overflows = 0;

    no_of_overflows++;
    if (no_of_overflows >= 10) {
        no_of_overflows = 0;
        GPIO_write_high(&PORTB, servo1);

}
}

*/
ISR(TIMER0_OVF_vect)
{
      static uint8_t no_of_overflows = 0;

    no_of_overflows++;
    if (no_of_overflows >= 100) {
        no_of_overflows = 0;
        GPIO_mode_output(&DDRB, servo1);
        GPIO_write_high(&PORTB, servo1);
        _delay_ms(5); // Wait 1 ms
        GPIO_write_low(&PORTB, servo2); 
    }  
}

ISR(TIMER2_OVF_vect)
{
    GPIO_write_high(&PORTB, servo2);
    _delay_ms(5); // Wait 1 ms
    GPIO_write_low(&PORTB, servo2); 
    _delay_ms(10); // Wait 1 ms     
}




