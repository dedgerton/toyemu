/**
 * toyemu - 6502 CPU emulator
 * Copyright (C) 2012 Dakota Edgerton
 * mail: dedgerton97@gmail.com
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
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
