# Lab 6: Universal Asynchronous Receiver-Transmitter (UART)

## Pre-Lab preparation

1. Use schematic of [Arduino Uno](https://oshwlab.com/tomas.fryza/arduino-shields) and find out on which Arduino Uno pins the UART transmitter (Tx) and receiver (Rx) are located.

![UART_transmitter](https://github.com/PlocekovaNat/DigitalElectronics2/blob/main/lab06-uart/images/UART_transmitter.png)

2. Remind yourself, what an [ASCII table](http://www.asciitable.com/) is. What codes are defined for control characters `Esc`, `Space`, `Tab`, and `Enter`?

<a name="part1"></a>

## Part 3: Communication between Arduino board and computer

In the lab, we are using [UART library](http://www.peterfleury.epizy.com/avr-software.html) developed by Peter Fleury.

1. Use online manual of UART library and add the input parameters and description of the following functions.

   | **Function name** | **Function parameter(s)** | **Description** | **Example** |
   | :-- | :-- | :-- | :-- |
   | `uart_init` | `UART_BAUD_SELECT(9600, F_CPU)` | Initialize UART to 8N1 and set baudrate to 9600&nbsp;Bd | `uart_init(UART_BAUD_SELECT(9600, F_CPU));` |
   | `uart_getc` | no parameter | Get received byte of USART1 from ringbuffer. |
   | `uart_putc` | no parameter | Put byte to ringbuffer for transmitting via USART1 |
   | `uart_puts` | `s` | Put string to ringbuffer for transmitting via USART1 |
