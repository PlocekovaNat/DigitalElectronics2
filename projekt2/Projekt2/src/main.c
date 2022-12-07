/***********************************************************************
 * 
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 * 
 *
 
 /* Define pins for joystick ------------------------------------------*/
#define Rx PC0 
#define Ry PC1 
#define SW PD2 

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
#define PC0 A0
#define PC1 A1
#define PD2 2

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD screen when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
// Define global variables for position
uint8_t no_of_overflows = 0;

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
    TIM1_overflow_33ms();
    TIM1_overflow_interrupt_enable();
    TIM2_overflow_1ms();
    TIM2_overflow_interrupt_enable();
    
        /* -----------------------------Joystick-----------------------------------*/
    // Configure Analog-to-Digital Convertion unit
    // Select ADC voltage reference to "AVcc with external capacitor at AREF pin"
    ADMUX = ADMUX |  (1<<REFS0);
    // Enable ADC module
    ADCSRA |= (1<<ADEN); // into the variable ADCSRA counting a new value
    // Enable conversion complete interrupt
    ADCSRA |= (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);

    // Enables interrupts by setting the global interrupt mask
    sei();

    EIMSK |= (1 << INT0);                   // External interrupt mask register - enable INT0 bit   

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
/* POTREBA PEROBIT NA PWM GENERATOR !!!
ISR(TIMER0_OVF_vect)
{
    //GPIO_mode_output(&DDRB, servo1);
    GPIO_write_high(&PORTB, servo1);
    _delay_ms(1.5); // Wait 1 ms
    GPIO_write_low(&PORTB, servo2); 
}  
*/

ISR(TIMER2_OVF_vect)
{
    no_of_overflows++;
    if (no_of_overflows >= 20) { 
        EIMSK |= (1 << INT0);
        no_of_overflows = 0;
    }
}
*/

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/1 overflow interrupt
 * Purpose:  Use single conversion mode and start conversion every 33 ms.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // Start ADC conversion
    ADCSRA |= (1<<ADSC);
}

/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display converted value on LCD screen.
 **********************************************************************/
ISR(ADC_vect)
{
    uint16_t x, y;   // Set variables x, y as 16-bit integer
    char string[4];  // String for converted numbers by itoa()

    // Read x value ----------------------------------------------------------
    // Note that, register pair ADCH and ADCL can be read as a 16-bit value ADC
    // Select input channel ADC1 (voltage divider pin)
    uint8_t channel = ADMUX & 0b00001111; // Get last 4 bits from ADMUX
    if (channel == 0)
    {
    x = ADC;    // Get ADC value

    if ((x<411)|(x>611))
    {
        if(x<411)
        {
            lcd_gotoxy(h, v);
            lcd_puts(" ");
            if (v == 1){
                v--;
            }
            lcd_gotoxy(h, v);
            itoa(ch, string, 10);
            lcd_puts(string);
        }
        else if(x>611)
        {
            lcd_gotoxy(h, v);
            lcd_puts(" ");
            if (v == 0){
                v++;
            }
            lcd_gotoxy(h, v);
            itoa(ch, string, 10);
            lcd_puts(string);
        }
    }
    ADMUX = ADMUX & ~(1<<MUX3 | 1<<MUX2 | 1<<MUX1); ADMUX |= (1<<MUX0) ;    // Change ADMUX to 1
    }

    else if (channel == 1)
    {
        // Read y value ----------------------------------------------------------
        // Note that, register pair ADCH and ADCL can be read as a 16-bit value ADC
        y = ADC;    // Get ADC value

        if(y<411)
        {
            lcd_gotoxy(h, v);
            lcd_puts(" ");
            if (h < 15){
                h++;
            }
            lcd_gotoxy(h, v);
            itoa(ch, string, 10);
            lcd_puts(string);
        }
        else if(y>611)
        {
            lcd_gotoxy(h, v);
            lcd_puts(" ");
            if (h > 0){
                h--;
            }
            lcd_gotoxy(h, v);
            itoa(ch, string, 10);
            lcd_puts(string);
        }
        ADMUX = ADMUX & ~(1<<MUX3 | 1<<MUX2 | 1<<MUX1 | 1<<MUX0);   // Change ADMUX to 0
        }
}





