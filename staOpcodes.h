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

void opcode0x85(uint8_t* data); // | Zero Page 	 | STA 15     | $85/133 | 2 |
void opcode0x95(uint8_t* data); // | Zero Page,X | STA 15,X   | $95/149 | 2 |
void opcode0x8D(uint8_t* data); // | Absolute    | STA 1500   | $8D/141 | 2 |
void opcode0x9D(uint8_t* data); // | Absolute,X  | STA 1500,X | $9D/157 | 3 |
void opcode0x99(uint8_t* data); // | Absolute,Y  | STA 1500,Y | $99/153 | 3 |
void opcode0x81(uint8_t* data); // | Indirect,X  | STA (15,X) | $81/129 | 2 |
void opcode0x91(uint8_t* data); // | Indirect,Y  | STA (15),Y | $91/145 | 2 |
