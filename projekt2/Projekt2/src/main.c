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

/* Define pins for button ---------------------------------------------*/
#define BUTTON1 PB0          // Button 1

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <stdlib.h>         // C library. Needed for number conversions

/* Arduino world -----------------------------------------------------*/
#include "Arduino.h"
#define PB1 9          // PWM source 1
#define PB2 10         // PWM source 2
#define PD2 2          // Button 1

/* Define parameters for servo ---------------------------------------------------------*/
# define ZERO_ANGLE 124
# define ANGLE_180 260
# define SHORT_DELAY 2000 // Delay in milliseconds

volatile uint32_t servo1_position = ANGLE_180;
volatile uint32_t servo2_position = ANGLE_180;
volatile uint8_t MOVE = 0;

int main(void)
{
    /* ----------------------------- Timer for SERVO 1 ---------------------------------*/
    // Configure 8-bit Timer/Counter0 to control servo motors
    // Set prescaler to 16 ms and enable overflow interrupt
    TIM0_overflow_16ms();
    TIM0_overflow_interrupt_enable();

    /* ------------------------- Set pins with gpio library ----------------------------*/
    GPIO_mode_output(&DDRB, servo1);        // First servo motor
    GPIO_mode_output(&DDRB, servo2);        // Second servo motor
    GPIO_mode_input_pullup(&DDRB,BUTTON1);  // Button with enabled pull-up resistor

    // Set 10. waveform generation mode (1010)
    TCCR1A |= (1 << WGM11);                  
    TCCR1B |= (1 << WGM13);

    // Set compare output mode
    TCCR1A |= (1 << COM0A1) | (1 << COM0B1); 

     // Set TOP value
    ICR1 = 2500;
                         
    // Set duty cycle
    OCR1A = servo1_position;
    OCR1B = servo2_position;
    
    // Set prescaler to 64
    TCCR1B |= (1 << CS11) | (1 << CS10 ); 

    PCICR |= (1<<PCIE0);                    // Any change of any enable PCINT[7:0] pins will cause an interrupt
    PCMSK0 |= (1<<PCINT0);                  // Enable PCINT0 change interrupt  
    _delay_ms(SHORT_DELAY); // Wait 2 s

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

ISR(TIMER0_OVF_vect)
{
    static uint8_t servo1_direction = 0;        // Default direction setup for first servo motor
    static uint8_t servo2_direction = 0;        // Default direction setup for second servo motor
    /* ------------- First servo motor  ------------------------------*/
    if (MOVE == 0)                                                      
    {
        // Direction
        if (servo1_position == ANGLE_180)       // Maximum value
            {
                servo1_direction = 1;           // Clockwise direction
            }
        else if (servo1_position == ZERO_ANGLE) // Minimum value
            {
                servo1_direction = 0;           // Counterclockwise direction
            }
        // Motion
        if (servo1_direction == 0)
        {
            servo1_position += 2;               // Increment variable 
        }
        if (servo1_direction == 1)
        {
            servo1_position -= 2;               // Decrement variable  
        }
        OCR1A = servo1_position;                // Put value from variable into arduino register
        }
    /* ------------- Second servo motor  ------------------------------*/    
    if (MOVE == 1) 
    {
        // Direction
        if (servo2_position == ANGLE_180)       // Maximum value
        {
            servo2_direction = 1;               // Clockwise direction
        }
        else if (servo2_position == ZERO_ANGLE) // Minimum value
        {
            servo2_direction = 0;               // Counterclockwise direction
        }
        // Motion
        if (servo2_direction == 0)
        {
            servo2_position += 2;               // Increment variable 
        }
        if (servo2_direction == 1)
        {
            servo2_position -= 2;               // Decrement variable   
        }
        OCR1B = servo2_position;                // Put value from variable into arduino register
    }
}
/**********************************************************************
 * Function: Pin PB0 change interrupt
 * Purpose:  Defines if the first or second servo motor should move
 **********************************************************************/

ISR(PCINT0_vect)
{
    uint8_t sw1 = GPIO_read(&PINB, BUTTON1);     // Read value from digital pin 8
    if (sw1 == LOW)                              // Button is pushed down  
    {
        if (MOVE == 1) 
        { 
            MOVE = 0;                            
        }
        else if (MOVE == 0) 
        { 
            MOVE = 1;
        }
    } 
}





