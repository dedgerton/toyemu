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


// ASL opcodes
void opcode0x0A(uint8_t* data); // | Accumulator | ASL        | $0A/10  | 1 |
void opcode0x06(uint8_t* data); // | Zero Page   | ASL 15     | $06/6   | 2 |
void opcode0x16(uint8_t* data); // | Zero Page,X | ASL 15,X   | $16/22  | 2 |
void opcode0x0E(uint8_t* data); // | Absolute    | ASL 1500   | $0E/14  | 3 |
void opcode0x1E(uint8_t* data); // | Absolute,X  | ASL 1500,X | $1E/30  | 3 |
