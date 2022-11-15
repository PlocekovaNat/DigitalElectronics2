# Lab 8: Combining C and assembly language

<a name="preparation"></a>
## Pre-Lab preparation

1. Use **AVR® Instruction Set Manual** from Microchip [Online Technical Documentation](https://onlinedocs.microchip.com/), find the description of selected instructions, and complete the table.

   | **Instruction** | **Operation** | **Description** | **Cycles** |
   | :-- | :-: | :-- | :-: |
   | `add Rd, Rr` | Rd ← Rd + Rr | Adds two registers without the C flag and places the result in the destination register Rd. | 1 |
   | `andi Rd, K` | Rd = Rd and K | Logical AND between register Rd and 8-bit constant K | 1 |
   | `bld Rd, b` | Rd(b) ← T | Copies the T bit in the SREG (Status Register) to bit b in register Rd. | 1 |
   | `bst Rd, b` | T ← Rd(b) | Stores bit b from Rd to the T bit in SREG (Status Register). | 1 |
   | `com Rd` | Rd ← 0xFF - Rd | This instruction performs a One’s Complement of register Rd. | 1 |
   | `eor Rd, Rr` | Rd ← Rd ⊕ Rr | Performs the logical EOR between the contents of register Rd and register Rr and places the result in the destination register Rd. | 1 |
   | `mul Rd, Rr` | R1:R0 ← Rd × Rr (unsigned ← unsigned × unsigned) | The multiplicand Rd and the multiplier Rr are two registers containing unsigned numbers. The 16-bit unsigned product is placed in R1 (high byte) and R0 (low byte) | 1 |
   | `pop Rd` | Rd ← STACK | This instruction loads register Rd with a byte from the STACK. The Stack Pointer is pre-incremented by 1 before the POP. | 1 |
   | `push Rr` | STACK ← Rr | This instruction stores the contents of register Rr on the STACK. The Stack Pointer is post-decremented by 1 after the PUSH. | 1 |
   | `ret` | PC(15:0) ← STACK or PC(21:0) ← STACK | Returns from the subroutine. The return address is loaded from the STACK. The Stack Pointer uses a pre-increment scheme during RET. | 2/3 |
   | `rol Rd` | ![Snímka obrazovky 2022-11-15 o 12 44 16](https://user-images.githubusercontent.com/99497162/201911553-de9ce3fe-adc2-491c-a8fb-afc8c8aa6ead.png) | Shifts all bits in Rd one place to the left. The C flag is shifted into bit 0 of Rd. Bit 7 is shifted into the C flag. This operation, combined with LSL, effectively multiplies multi-byte signed and unsigned values by two. | 1 |
   | `ror Rd` | ![Snímka obrazovky 2022-11-15 o 12 43 13](https://user-images.githubusercontent.com/99497162/201911386-cb5c0211-cdd1-45e7-9c63-d086fe63f6ea.png) | Shifts all bits in Rd one place to the right. The C flag is shifted into bit 7 of Rd. Bit 0 is shifted into the C flag. | 1 |

<a name="part1"></a>

