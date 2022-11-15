# Lab 8: Combining C and assembly language

<a name="preparation"></a>
## Pre-Lab preparation

1. Use **AVR® Instruction Set Manual** from Microchip [Online Technical Documentation](https://onlinedocs.microchip.com/), find the description of selected instructions, and complete the table.

   | **Instruction** | **Operation** | **Description** | **Cycles** |
   | :-- | :-: | :-- | :-: |
   | `add Rd, Rr` | Rd ← Rd + Rr | Adds two registers without the C flag and places the result in the destination register Rd. | 1 |
   | `andi Rd, K` | Rd = Rd and K | Logical AND between register Rd and 8-bit constant K | 1 |
   | `bld Rd, b` | Rd(b) ← T | Copies the T bit in the SREG (Status Register) to bit b in register Rd. | 1 |
   | `bst Rd, b` |  |  |  |
   | `com Rd` |  |  |  |
   | `eor Rd, Rr` |  |  |  |
   | `mul Rd, Rr` |  |  |  |
   | `pop Rd` |  |  |  |
   | `push Rr` |  |  |  |
   | `ret` |  |  |  |
   | `rol Rd` |  |  |  |
   | `ror Rd` |  |  |  |

<a name="part1"></a>

