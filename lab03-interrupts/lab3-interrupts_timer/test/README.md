# Lab 3: YOUR_FIRSTNAME LASTNAME

### Overflow times

1. Complete table with overflow times.

   | **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
   | Timer/Counter0 | 8  | 16u | 128u | -- | 1m | -- | 4.1m | 16.4m |
   | Timer/Counter1 | 16 | 4.1m | 32.8m | -- | 262.1m | -- | 1.49 | 4.194 |
   | Timer/Counter2 | 8  |  16u | 128u | 512u | 1m | 2m | 4.1m | 16.4m |

### Interrupts

2. In `timer.h` header file, define macros also for Timer/Counter2. Listing of part of the header file with settings for Timer/Counter2. Always use syntax highlighting, meaningful comments, and follow C guidelines:

   ```c
   /**
    * @name  Definitions for 8-bit Timer/Counter2
    * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 8, F_CPU = 16 MHz
    */
    /** @brief Stop timer, prescaler 000 --> STOP */
    #define TIM2_stop()           TCCR2B &= ~((1<<CS022) | (1<<CS01) | (1<<CS00));
    /** @brief Set overflow 16us, prescaler 001 --> 1 */
    #define TIM0_overflow_16us()   TCCR2B &= ~((1<<CS02) | (1<<CS01)); TCCR2B |= (1<<CS00);
    /** @brief Set overflow 128us, prescaler 010 --> 8 */
    #define TIM0_overflow_128us()  TCCR2B &= ~((1<<CS02) | (1<<CS10)); TCCR2B |= (1<<CS01);
    /** @brief Set overflow 512us, prescaler 011 --> 32 */
    #define TIM0_overflow_512us()  TCCR2B &= ~((1<<CS02); TCCR2B |= (1<<CS01) | (1<<CS20));
    /** @brief Set overflow 1ms, prescaler 100 --> 64 */
    #define TIM0_overflow_1ms() TCCR2B &= ~(1<<CS02); TCCR2B |= (1<<CS01) | (1<<CS00);
    /** @brief Set overflow 2ms, prescaler 101 --> 128 */
    #define TIM0_overflow_2ms() TCCR2B &= ~(1<<CS02); TCCR2B |= (1<<CS01) | (1<<CS00);
    /** @brief Set overflow 4ms, prescaler 110 --> 256 */
    #define TIM0_overflow_4ms()    TCCR2B &= ~((1<<CS01) | (1<<CS00)); TCCR2B |= (1<<CS02);
    /** @brief Set overflow 16ms, prescaler // 111 --> 1024 */
    #define TIM0_overflow_16ms()    TCCR2B &= ~(1<<CS01); TCCR2B |= (1<<CS02) TCCR2B |= (1<<CS01) || (1<<CS00);

   /** @brief Enable overflow interrupt, 1 --> enable */
   #define TIM0_overflow_interrupt_enable()  TIMSK0 |= (1<<TOIE0);
   /** @brief Disable overflow interrupt, 0 --> disable */
   #define TIM0_overflow_interrupt_disable() TIMSK0 &= ~(1<<TOIE0);
   ```
