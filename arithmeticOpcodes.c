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

 #include "arithmeticOpcodes.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////ADC opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void adcBackbone(uint8_t value)
{
    uint16_t tempResult = accu + value + carryFlag;

    // Set the carry flag accordingly
    if (tempResult > 0xFF)
        carryFlag = 1;
    else carryFlag = 0;

    // Set the overflow flag accordingly
    if ((tempResult >> 7) > 0)
        overflowFlag = 1;
    else overflowFlag = 0;

    // Set the zero flag accordingly
    if (tempResult == 0)
        zeroFlag = 0;
    else zeroFlag = 1;

    accu = tempResult & 0x00FF;

    // Set the negative flag accordingly
    if ((accu >> 7) == 1)
        negativeFlag = 1;
    else negativeFlag = 0;

    return;
}

void opcode0x69(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x69Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    adcBackbone(data[1]);
    pcnt += 2;

    return;
}

void opcode0x65(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x65Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    adcBackbone(readMemory(data[1])); // Load the value at memory address [OPERAND] into accumulator
    pcnt += 2;

    return;
}

void opcode0x75(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x75Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    adcBackbone(readMemory(data[1] + xreg));
    pcnt += 2;

    return;
}

void opcode0x6D(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x6DEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    adcBackbone(readMemory(memoryAddress));
    pcnt += 3;

    return;
}

void opcode0x7D(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x7DEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    adcBackbone(readMemory(memoryAddress + xreg));
    pcnt += 3;

    return;
}

void opcode0x79(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x79Encountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    adcBackbone(readMemory(memoryAddress + yreg));
    pcnt += 3;

    return;
}

void opcode0x61(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x61Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    adcBackbone(readMemory(data[1] + xreg));
    pcnt += 2;

    return;
}

void opcode0x71(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x71Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    adcBackbone(readMemory(data[1]) + yreg);
    pcnt += 2;

    return;
}
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end ADC opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



