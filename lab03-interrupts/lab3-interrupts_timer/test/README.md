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
   #define TIM1_stop()           TCCR1B &= ~((1<<CS12) | (1<<CS11) | (1<<CS10));
   /** @brief Set overflow 4ms, prescaler 001 --> 1 */
   #define TIM1_overflow_4ms()   TCCR1B &= ~((1<<CS12) | (1<<CS11)); TCCR1B |= (1<<CS10);
   /** @brief Set overflow 33ms, prescaler 010 --> 8 */
   #define TIM1_overflow_33ms()  TCCR1B &= ~((1<<CS12) | (1<<CS10)); TCCR1B |= (1<<CS11);
   /** @brief Set overflow 262ms, prescaler 011 --> 64 */
   #define TIM1_overflow_262ms() TCCR1B &= ~(1<<CS12); TCCR1B |= (1<<CS11) | (1<<CS10);
   /** @brief Set overflow 1s, prescaler 100 --> 256 */
   #define TIM1_overflow_1s()    TCCR1B &= ~((1<<CS11) | (1<<CS10)); TCCR1B |= (1<<CS12);
   /** @brief Set overflow 4s, prescaler // 101 --> 1024 */
   #define TIM1_overflow_4s()    TCCR1B &= ~(1<<CS11); TCCR1B |= (1<<CS12) | (1<<CS10);

   /** @brief Enable overflow interrupt, 1 --> enable */
   #define TIM1_overflow_interrupt_enable()  TIMSK1 |= (1<<TOIE1);
   /** @brief Disable overflow interrupt, 0 --> disable */
   #define TIM1_overflow_interrupt_disable() TIMSK1 &= ~(1<<TOIE1);
   ```
