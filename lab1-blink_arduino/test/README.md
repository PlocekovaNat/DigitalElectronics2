# Lab 1: Natalia Plocekova

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c
int main(void)
{
    // Set pin where on-board LED is connected as output
    pinMode(LED_RED, OUTPUT);

    while (1)
    {
        int SHORT_DELAY = 250;
        int LONG_DELAY = 750;
        
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
