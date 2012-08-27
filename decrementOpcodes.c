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

#include "decrementOpcodes.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////DEC opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0xC6(uint8_t* data)
{
    uint8_t value;
    printf("%s%s%s", opcodeEncStart, opcode0xC6Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);

    value = readMemory(data[1]);
    value --;
    writeMemory(data[1], value);

    auxSetZeroFlag(value); // Set the zero flag accordingly
    auxSetNegativeFlag(value); // Set the negative flag accordingly

    pcnt += 2;

    return;
}

void opcode0xD6(uint8_t* data)
{
    uint8_t value;
    printf("%s%s%s", opcodeEncStart, opcode0xD6Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);

    value = readMemory(data[1] + xreg);
    value --;
    writeMemory(data[1] + xreg, value);

    auxSetZeroFlag(value); // Set the zero flag accordingly
    auxSetNegativeFlag(value); // Set the negative flag accordingly

    pcnt += 2;

    return;
}

void opcode0xCE(uint8_t* data)
{
    uint8_t value;
    printf("%s%s%s", opcodeEncStart, opcode0xCEEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);

    value = readMemory(memoryAddress);
    value --;
    writeMemory(memoryAddress, value);

    auxSetZeroFlag(value); // Set the zero flag accordingly
    auxSetNegativeFlag(value); // Set the negative flag accordingly

    pcnt += 3;

    return;
}

void opcode0xDE(uint8_t* data)
{
    uint8_t value;
    printf("%s%s%s", opcodeEncStart, opcode0xDEEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);

    value = readMemory(memoryAddress + xreg);
    value --;
    writeMemory(memoryAddress + xreg, value);

    auxSetZeroFlag(value); // Set the zero flag accordingly
    auxSetNegativeFlag(value); // Set the negative flag accordingly

    pcnt += 3;

    return;
}
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end DEC opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void opcode0xCA(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xCAEncountered, opcodeEncEnd);

    xreg --;

    auxSetZeroFlag(xreg); // Set the zero flag accordingly
    auxSetNegativeFlag(xreg); // Set the negative flag accordingly

    pcnt += 1;

    return;
}

void opcode0x88(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x88Encountered, opcodeEncEnd);

    yreg --;

    auxSetZeroFlag(yreg); // Set the zero flag accordingly
    auxSetNegativeFlag(yreg); // Set the negative flag accordingly

    pcnt += 1;

    return;
}

