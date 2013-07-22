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

// INC opcodes
void opcode0xE6(uint8_t* data); // | Zero Page   | INC 15     | $E6/230 | 2 |
void opcode0xF6(uint8_t* data); // | Zero Page,X | INC 15,X   | $F6/246 | 2 |
void opcode0xEE(uint8_t* data); // | Absolute    | INC 1500   | $EE/238 | 3 |
void opcode0xFE(uint8_t* data); // | Absolute,X  | INC 1500,X | $FE/254 | 3 |

void opcode0xE8(uint8_t* data); // | Implied     | INX        | $E8/232 | 1 |
void opcode0xC8(uint8_t* data); // | Implied     | INY        | $C8/200 | 1 |
