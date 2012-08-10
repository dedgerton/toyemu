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

extern uint16_t pcnt;
extern uint8_t  accu;
extern uint8_t  xreg;
extern uint8_t  yreg;
extern uint8_t  spnt;
extern uint8_t  carryFlag, zeroFlag, interruptFlag, decimalFlag, breakFlag, overflowFlag, negativeFlag;

extern uint8_t readMemory(uint16_t address);
extern void writeMemory(uint16_t address, uint8_t value);

void opcode0x29(uint8_t* data); // | Immediate   | AND #15    | $29/41  | 2 |
void opcode0x25(uint8_t* data); // | Zero Page   | AND 15     | $25/37  | 2 |
void opcode0x35(uint8_t* data); // | Zero Page,X | AND 15,X   | $35/53  | 2 |
void opcode0x2D(uint8_t* data); // | Absolute    | AND 1500   | $2D/45  | 3 |
void opcode0x3D(uint8_t* data); // | Absolute,X  | AND 1500,X | $3D/61  | 3 |
void opcode0x39(uint8_t* data); // | Absolute,Y  | AND 1500,Y | $39/57  | 3 |
void opcode0x21(uint8_t* data); // | Indirect,X  | AND (15,X) | $21/33  | 2 |
void opcode0x31(uint8_t* data); // | Indirect,Y  | AND (15),Y | $31/49  | 2 |
