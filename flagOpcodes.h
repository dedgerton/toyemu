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

void opcode0x18(uint8_t* data); // | Implied     | CLC        | $18/24  | 1 |
void opcode0xD8(uint8_t* data); // | Implied     | CLD        | $D8/216 | 1 |
void opcode0x58(uint8_t* data); // | Implied     | CLI        | $58/88  | 1 |
void opcode0xB8(uint8_t* data); // | Implied     | CLV        | $B8/184 | 1 |
void opcode0x38(uint8_t* data); // | Implied     | SEC        | $38/56  | 1 |
void opcode0xF8(uint8_t* data); // | Implied     | SED        | $F8/248 | 1 |
void opcode0x78(uint8_t* data); // | Implied     | SEI        | $78/120 | 1 |
