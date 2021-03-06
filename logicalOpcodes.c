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

#include "logicalOpcodes.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////AND opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0x29(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x29Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu & data[1];
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x25(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x25Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu & readMemory(data[1]);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x35(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x35Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu & readMemory(data[1] + xreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x2D(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x2DEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = accu & readMemory(memoryAddress);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0x3D(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x3DEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = accu & readMemory(memoryAddress + xreg);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0x39(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x39Encountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = accu & readMemory(memoryAddress + yreg);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0x21(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x21Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu & readMemory(data[1] + xreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x31(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x31Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu & (readMemory(data[1]) + yreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end AND opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////EOR opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0x49(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x49Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu ^ data[1];
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x45(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x45Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu ^ readMemory(data[1]);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x55(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x55Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu ^ readMemory(data[1] + xreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x4D(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x4DEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = accu ^ readMemory(memoryAddress);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0x5D(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x5DEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = accu ^ readMemory(memoryAddress + xreg);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0x59(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x59Encountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = accu ^ readMemory(memoryAddress + yreg);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0x41(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x41Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu ^ readMemory(data[1] + xreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x51(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x51Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu ^ (readMemory(data[1]) + yreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end EOR opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////ORA opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0x09(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x09Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu | data[1];
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x05(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x05Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu | readMemory(data[1]);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x15(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x15Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu | readMemory(data[1] + xreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x0D(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x0DEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = accu | readMemory(memoryAddress);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0x1D(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x1DEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = accu | readMemory(memoryAddress + xreg);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0x19(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x19Encountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);
    accu = accu | readMemory(memoryAddress + yreg);
    auxSetAccuFlags();
    pcnt += 3;

    return;
}

void opcode0x01(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x01Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu | readMemory(data[1] + xreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}

void opcode0x11(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x11Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);
    accu = accu | (readMemory(data[1]) + yreg);
    auxSetAccuFlags();
    pcnt += 2;

    return;
}
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end ORA opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////BIT opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0x24(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x24Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);

    uint8_t memoryValue = readMemory(data[1]);
    uint8_t result = accu & memoryValue;

    // Set the zero flag accordingly
    if (result == 0)
        zeroFlag = 1;
    else zeroFlag = 0;

    // Set the overflow flag accordingly
    overflowFlag = (memoryValue & 0x40) >>  6;

    // Set the overflow flag accordingly
    negativeFlag = (memoryValue & 0x80) >>  7;

    pcnt += 2;

    return;
}

void opcode0x2C(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x2CEncountered, opcodeEncEnd);
    uint16_t memoryAddress = (data[1] << 8) | data[2];
    printf("OP_PARSE: Operand is 0x%04X\n", memoryAddress);

    uint8_t memoryValue = readMemory(memoryAddress);
    uint8_t result = accu & memoryValue;

    // Set the zero flag accordingly
    if (result == 0)
        zeroFlag = 1;
    else zeroFlag = 0;

    // Set the overflow flag accordingly
    overflowFlag = (memoryValue & 0x40) >>  6;

    // Set the overflow flag accordingly
    negativeFlag = (memoryValue & 0x80) >>  7;

    pcnt += 3;

    return;
}
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end BIT opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

