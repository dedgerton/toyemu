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

 #include "loadOpcodes.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////LDA opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0xA9(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xA9Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = data[1];
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0xA5(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xA5Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = readMemory(data[1]); // Load the value at memory address [OPERAND] into accumulator
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0xB5(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xB5Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = readMemory(data[1] + xreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0xAD(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xADEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = readMemory(memoryAddress);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0xBD(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xBDEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = readMemory(memoryAddress + xreg);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0xB9(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xB9Encountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = readMemory(memoryAddress + yreg);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0xA1(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xA1Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = readMemory(data[1] + xreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0xB1(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xB1Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = readMemory(data[1]) + yreg;
    auxSetAccuFlags();
    pcnt += 2;

    return;
}
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end LDA opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////LDX opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0xA2(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xA2Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    xreg = data[1];
    auxSetXregFlags();
    pcnt += 2;

    return;
}

void opcode0xA6(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xA6Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    xreg = readMemory(data[1]); // Load the value at memory address [OPERAND] into accumulator
    auxSetXregFlags();
    pcnt += 2;

    return;
}

void opcode0xB6(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xB6Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    xreg = readMemory(data[1] + yreg);
    auxSetXregFlags();
    pcnt += 2;

    return;
}

void opcode0xAE(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xAEEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    xreg = readMemory(memoryAddress);
    auxSetXregFlags();
    pcnt += 3;

    return;
}

void opcode0xBE(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xBEEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    xreg = readMemory(memoryAddress + yreg);
    auxSetXregFlags();
    pcnt += 3;

    return;
}
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end LDX opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////LDY opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0xA0(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xA0Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    yreg = data[1];
    auxSetYregFlags();
    pcnt += 2;
}

void opcode0xA4(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xA4Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    yreg = readMemory(data[1]); // Load the value at memory address [OPERAND] into accumulator
    auxSetYregFlags();
    pcnt += 2;
}

void opcode0xB4(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xB4Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    yreg = readMemory(data[1] + xreg);
    auxSetYregFlags();
    pcnt += 2;
}

void opcode0xAC(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xACEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    yreg = readMemory(memoryAddress);
    auxSetYregFlags();
    pcnt += 3;
}

void opcode0xBC(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xBCEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    yreg = readMemory(memoryAddress + xreg);
    auxSetYregFlags();
    pcnt += 3;
}
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end LDY opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
