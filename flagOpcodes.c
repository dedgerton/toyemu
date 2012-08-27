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

#include "flagOpcodes.h"


void opcode0x18(uint8_t* data)
{
    carryFlag = 0;
    return;
}

void opcode0xD8(uint8_t* data)
{
    decimalFlag = 0;
    return;
}

void opcode0x58(uint8_t* data)
{
    interruptFlag = 0;
    return;
}

void opcode0xB8(uint8_t* data)
{
    overflowFlag = 0;
    return;
}

void opcode0x38(uint8_t* data)
{
    carryFlag = 1;
    return;
}

void opcode0xF8(uint8_t* data)
{
    decimalFlag = 1;
    return;
}

void opcode0x78(uint8_t* data)
{
    interruptFlag = 1;
    return;
}
