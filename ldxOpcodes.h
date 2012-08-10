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

void opcode0xA2(uint8_t* data); // | Immediate   | LDX #15    | $A2/162 | 2 |
void opcode0xA6(uint8_t* data); // | Zero Page   | LDX 15     | $A6/166 | 2 |
void opcode0xB6(uint8_t* data); // | Zero Page,Y | LDX 15,Y   | $B6/182 | 2 |
void opcode0xAE(uint8_t* data); // | Absolute    | LDX 1500   | $AE/174 | 3 |
void opcode0xBE(uint8_t* data); // | Absolute,Y  | LDX 1500,Y | $BE/190 | 3 |
