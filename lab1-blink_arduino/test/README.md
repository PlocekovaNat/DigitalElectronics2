# Lab 1: YOUR_FIRSTNAME LASTNAME

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c

/* Defines -----------------------------------------------------------*/
#define LED_RED PB0   // PB5 is AVR pin where red LED is connected

#define SHORT_DELAY 250 // Delay in miliseconds representing dot
#define LONG_DELAY 750 // Delay in milliseconds representing dash

#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops

#include "Arduino.h"

#define PB0 8          // In Arduino world, PB0 is called "8"


int main(void)
{
    // Set pin where on-board LED is connected as output
    pinMode(LED_RED, OUTPUT);

    while (1)
    {
        // Generate a lettre `A` Morse code
        
        // Turn ON/OFF on-board LED
        digitalWrite(LED_RED, led_value);

        led_value = LOW;        // LED is connected for LOW mode - turn on LED
        _delay_ms(SHORT_DELAY); // dot
        led_value = HIGH;       // turn off LED
        _delay_ms(SHORT_DELAY);
        led_value = LOW;
        _delay_ms(LONG_DELAY);  // dash
        led_value = HIGH;
        _delay_ms(LONG_DELAY);
           
    }
  
    // Will never reach this
    return 0;
}

```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![your figure]()
