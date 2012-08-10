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

#include "ldxOpcodes.h"

void opcode0xA2(uint8_t* data)
{
    printf(opcode0xA2Encountered);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    xreg = data[1];
    auxSetXregFlags();
    pcnt += 2;

    return;
}

void opcode0xA6(uint8_t* data)
{
    printf(opcode0xA6Encountered);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    xreg = readMemory(data[1]); // Load the value at memory address [OPERAND] into accumulator
    auxSetXregFlags();
    pcnt += 2;

    return;
}

void opcode0xB6(uint8_t* data)
{
    printf(opcode0xB6Encountered);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    xreg = readMemory(data[1] + yreg);
    auxSetXregFlags();
    pcnt += 2;

    return;
}

void opcode0xAE(uint8_t* data)
{
    printf(opcode0xAEEncountered);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    xreg = readMemory(memoryAddress);
    auxSetXregFlags();
    pcnt += 3;

    return;
}

void opcode0xBE(uint8_t* data)
{
    printf(opcode0xBEEncountered);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    xreg = readMemory(memoryAddress + yreg);
    auxSetXregFlags();
    pcnt += 3;

    return;
}