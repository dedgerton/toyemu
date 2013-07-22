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

#include "shiftOpcodes.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////ASL opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0x0A(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x0AEncountered, opcodeEncEnd);

    // Set the carry flag if bit 7 (8) is set
    auxSetCarryFlag(accu);

    accu = accu << 1;

    // Set the negative flag if bit 7 (8) is set
    auxSetNegativeFlag(accu);

    // Set the zero flag if accu is zero
    if (accu == 0)
        zeroFlag = 1;
    else zeroFlag = 0;

    pcnt += 1;
    return;
}

void opcode0x06(uint8_t* data)
{
    uint8_t memoryValue=0;
    printf("%s%s%s", opcodeEncStart, opcode0x06Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);

    memoryValue = readMemory(data[1]);

    // Set the carry flag if bit 7 (8) is set
    auxSetCarryFlag(memoryValue);

    memoryValue = memoryValue << 1;

    // Set the negative flag if bit 7 (8) is set
    auxSetNegativeFlag(memoryValue);

    writeMemory(data[1], memoryValue);

    pcnt += 2;
    return;
}

void opcode0x16(uint8_t* data)
{
    uint8_t memoryValue=0;
    printf("%s%s%s", opcodeEncStart, opcode0x16Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);

    memoryValue = readMemory(data[1] + xreg);

    // Set the carry flag if bit 7 (8) is set
    auxSetCarryFlag(memoryValue);

    memoryValue = memoryValue << 1;

    // Set the negative flag if bit 7 (8) is set
    auxSetNegativeFlag(memoryValue);

    writeMemory((data[1] + xreg), memoryValue);

    pcnt += 2;
    return;
}

void opcode0x0E(uint8_t* data)
{
    uint8_t memoryValue=0;
    printf("%s%s%s", opcodeEncStart, opcode0x0EEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);

    memoryValue = readMemory(memoryAddress);

    // Set the carry flag if bit 7 (8) is set
    auxSetCarryFlag(memoryValue);

    memoryValue = memoryValue << 1;

    // Set the negative flag if bit 7 (8) is set
    auxSetNegativeFlag(memoryValue);

    writeMemory(memoryAddress, memoryValue);

    pcnt += 3;
    return;
}

void opcode0x1E(uint8_t* data)
{
    uint8_t memoryValue=0;
    printf("%s%s%s", opcodeEncStart, opcode0x1EEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);

    memoryValue = readMemory(memoryAddress + xreg);

    // Set the carry flag if bit 7 (8) is set
    auxSetCarryFlag(memoryValue);

    memoryValue = memoryValue << 1;

    // Set the negative flag if bit 7 (8) is set
    auxSetNegativeFlag(memoryValue);

    writeMemory((memoryAddress + xreg), memoryValue);

    pcnt += 3;
    return;
}
