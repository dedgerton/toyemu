/**
 * toyemu - 6502 CPU emulator
 * Copyright (C) 2012-2013 Dakota Edgerton
 * mail: dedgerton97@gmail.com
 *
 * This file is part of toyemu.
 *
 * toyemu is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * toyemu is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with toyemu.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "incrementOpcodes.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////INC opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0xE6(uint8_t* data)
{
    uint8_t value;
    printf("%s%s%s", opcodeEncStart, opcode0xE6Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);

    value = readMemory(data[1]);
    value ++;
    writeMemory(data[1], value);

    auxSetZeroFlag(value); // Set the zero flag accordingly
    auxSetNegativeFlag(value); // Set the negative flag accordingly

    pcnt += 2;

    return;
}

void opcode0xF6(uint8_t* data)
{
    uint8_t value;
    printf("%s%s%s", opcodeEncStart, opcode0xF6Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);

    value = readMemory(data[1] + xreg);
    value ++;
    writeMemory(data[1] + xreg, value);

    auxSetZeroFlag(value); // Set the zero flag accordingly
    auxSetNegativeFlag(value); // Set the negative flag accordingly

    pcnt += 2;

    return;
}

void opcode0xEE(uint8_t* data)
{
    uint8_t value;
    printf("%s%s%s", opcodeEncStart, opcode0xEEEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);

    value = readMemory(memoryAddress);
    value ++;
    writeMemory(memoryAddress, value);

    auxSetZeroFlag(value); // Set the zero flag accordingly
    auxSetNegativeFlag(value); // Set the negative flag accordingly

    pcnt += 3;

    return;
}

void opcode0xFE(uint8_t* data)
{
    uint8_t value;
    printf("%s%s%s", opcodeEncStart, opcode0xFEEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);

    value = readMemory(memoryAddress + xreg);
    value ++;
    writeMemory(memoryAddress + xreg, value);

    auxSetZeroFlag(value); // Set the zero flag accordingly
    auxSetNegativeFlag(value); // Set the negative flag accordingly

    pcnt += 3;

    return;
}
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end INC opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void opcode0xE8(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xE8Encountered, opcodeEncEnd);

    xreg ++;

    auxSetZeroFlag(xreg); // Set the zero flag accordingly
    auxSetNegativeFlag(xreg); // Set the negative flag accordingly

    pcnt += 1;

    return;
}

void opcode0xC8(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xC8Encountered, opcodeEncEnd);

    yreg ++;

    auxSetZeroFlag(yreg); // Set the zero flag accordingly
    auxSetNegativeFlag(yreg); // Set the negative flag accordingly

    pcnt += 1;

    return;
}

