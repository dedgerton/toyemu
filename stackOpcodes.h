/**
 * toyemu - 6502 CPU emulator
 * Copyright (C) 2012-2013 Dakota Edgerton
 * mail: dedgerton97@gmail.com
 *
 * This file is part of toyemu.
 *
 * toyemu is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * toyemu is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with toyemu.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include <stdio.h>
#include "stringRes.h"
#include "auxiliary.h"

void opcode0xBA(uint8_t* data); // | Implied     | TSX        | $BA/186 | 1 |
void opcode0x9A(uint8_t* data); // | Implied     | TXS        | $9A/154 | 1 |
void opcode0x48(uint8_t* data); // | Implied     | PHA        | $48/72  | 1 |
void opcode0x08(uint8_t* data); // | Implied     | PHP        | $08/8   | 1 |
void opcode0x68(uint8_t* data); // | Implied     | PLA        | $68/104 | 1 |
void opcode0x28(uint8_t* data); // | Implied     | PLP        | $28/40  | 1 |

