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

#include "staOpcodes.h"

void opcode0x85(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x85Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    writeMemory(data[1], accu); // Load the value at memory address [OPERAND] into accumulator
    pcnt += 2;

    return;
}

void opcode0x95(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x95Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    writeMemory(data[1] + xreg, accu);
    pcnt += 2;

    return;
}

void opcode0x8D(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x8DEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    writeMemory(memoryAddress, accu);
    pcnt += 3;

    return;
}

void opcode0x9D(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x9DEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    writeMemory(memoryAddress + xreg, accu);
    pcnt += 3;

    return;
}

void opcode0x99(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x99Encountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    writeMemory(memoryAddress + yreg, accu);
    pcnt += 3;

    return;
}

void opcode0x81(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x81Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    writeMemory(data[1] + xreg, accu);
    pcnt += 2;

    return;
}

void opcode0x91(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x91Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    writeMemory((data[1]) + yreg, accu);
    pcnt += 2;

    return;
}
