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

#include "ldaOpcodes.h"

void opcode0xA9(uint8_t* data)
{
    printf(opcode0xA9Encountered);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = data[1];
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0xA5(uint8_t* data)
{
    printf(opcode0xA5Encountered);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = readMemory(data[1]); // Load the value at memory address [OPERAND] into accumulator
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0xB5(uint8_t* data)
{
    printf(opcode0xB5Encountered);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = readMemory(data[1] + xreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0xAD(uint8_t* data)
{
    printf(opcode0xADEncountered);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = readMemory(memoryAddress);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0xBD(uint8_t* data)
{
    printf(opcode0xBDEncountered);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = readMemory(memoryAddress + xreg);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0xB9(uint8_t* data)
{
    printf(opcode0xB9Encountered);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = readMemory(memoryAddress + yreg);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0xA1(uint8_t* data)
{
    printf(opcode0xA1Encountered);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = readMemory(data[1] + xreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0xB1(uint8_t* data)
{
    printf(opcode0xB1Encountered);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = readMemory(data[1]) + yreg;
    auxSetAccuFlags();
    pcnt += 2;

    return;
}
