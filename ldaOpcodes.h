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

void opcode0xA9(uint8_t* data); // | Immediate   | LDA #15    | $A9/169 | 2 |
void opcode0xA5(uint8_t* data); // | Zero Page   | LDA 15     | $A5/165 | 2 |
void opcode0xB5(uint8_t* data); // | Zero Page,X | LDA 15,X   | $B5/181 | 2 |
void opcode0xAD(uint8_t* data); // | Absolute    | LDA 1500   | $AD/173 | 3 |
void opcode0xBD(uint8_t* data); // | Absolute,X  | LDA 1500,X | $BD/189 | 3 |
void opcode0xB9(uint8_t* data); // | Absolute,Y  | LDA 1500,Y | $B9/185 | 3 |
void opcode0xA1(uint8_t* data); // | Indirect,X  | LDA (15,X) | $A1/161 | 2 |
void opcode0xB1(uint8_t* data); // | Indirect,Y  | LDA (15),Y | $B1/177 | 2 |
