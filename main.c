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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "loadOpcodes.h"
#include "storeOpcodes.h"
#include "logicalOpcodes.h"
#include "transferOpcodes.h"
#include "arithmeticOpcodes.h"
#include "incrementOpcodes.h"
#include "decrementOpcodes.h"
#include "flagOpcodes.h"
#include "stackOpcodes.h"
#include "shiftOpcodes.h"

uint16_t pcnt = 0x0000;
uint8_t  accu = 0x00;
uint8_t  xreg = 0x00;
uint8_t  yreg = 0x00;
uint8_t  spnt = 0xFF;
uint8_t  carryFlag=0, zeroFlag=0, interruptFlag=0, decimalFlag=0, breakFlag=0, overflowFlag=0, negativeFlag=0;
uint8_t  memory[0xFFFF];

void unknowOpcode(uint8_t* data)
{
    printf("\n\nOP_PARSE: Encountered an unknown opcode (0x%02X).\n", data[0]);
    printf("OP_PARSE: Last three bytes: 0x%02X 0x%02X 0x%02X\n", data[0], data[1], data[2]);
    printf("OP_PARSE: Incerementing PC by 2. Expect instability.\n\n\n");
    pcnt ++;
}

typedef void (*pt2Function)(uint8_t*);
pt2Function funcArr[10] = {NULL};


uint8_t readMemory(uint16_t address)
{
    return memory[address];
}

void writeMemory(uint16_t address, uint8_t value)
{
    memory[address] = value;
    return;
}

void printCpuState()
{
    printf("CPU_STATE:  PC    Accu Xreg Yreg Sreg Spnt  N V - B D I Z C\n");
    printf("CPU_STATE:  %02X     %02X   %02X   %02X   %02X   %02X   %d %d 1 %d %d %d %d %d\n", pcnt, accu, xreg, yreg, getSreg(), spnt, negativeFlag, overflowFlag, breakFlag, decimalFlag, interruptFlag, zeroFlag, carryFlag);
    return;
}

void parseProgram(uint8_t* program)
{
    uint8_t  currentByte[3];
    currentByte[0] = program[pcnt+0];
    currentByte[1] = program[pcnt+1];
    currentByte[2] = program[pcnt+2];

    printCpuState();
    funcArr[currentByte[0]](currentByte);

    return;
}

void initializeFunctionTable()
{
    int i = 0;

    for (i=0; i<256; i++)
        funcArr[i] = &unknowOpcode;

    // LDA opcodes
    funcArr[0xA9] = &opcode0xA9;
    funcArr[0xA5] = &opcode0xA5;
    funcArr[0xB5] = &opcode0xB5;
    funcArr[0xAD] = &opcode0xAD;
    funcArr[0xBD] = &opcode0xBD;
    funcArr[0xB9] = &opcode0xB9;
    funcArr[0xA1] = &opcode0xA1;
    funcArr[0xB1] = &opcode0xB1;

    // LDX opcodes
    funcArr[0xA2] = &opcode0xA2;
    funcArr[0xA6] = &opcode0xA6;
    funcArr[0xB6] = &opcode0xB6;
    funcArr[0xAE] = &opcode0xAE;
    funcArr[0xBE] = &opcode0xBE;

    // LDY opcodes
    funcArr[0xA0] = &opcode0xA0;
    funcArr[0xA4] = &opcode0xA4;
    funcArr[0xB4] = &opcode0xB4;
    funcArr[0xAC] = &opcode0xAC;
    funcArr[0xBC] = &opcode0xBC;

    // AND opcodes
    funcArr[0x29] = &opcode0x29;
    funcArr[0x25] = &opcode0x25;
    funcArr[0x35] = &opcode0x35;
    funcArr[0x2D] = &opcode0x2D;
    funcArr[0x3D] = &opcode0x3D;
    funcArr[0x39] = &opcode0x39;
    funcArr[0x21] = &opcode0x21;
    funcArr[0x31] = &opcode0x31;

    // EOR opcodes
    funcArr[0x49] = &opcode0x49;
    funcArr[0x45] = &opcode0x45;
    funcArr[0x55] = &opcode0x55;
    funcArr[0x4D] = &opcode0x4D;
    funcArr[0x5D] = &opcode0x5D;
    funcArr[0x59] = &opcode0x59;
    funcArr[0x41] = &opcode0x41;
    funcArr[0x51] = &opcode0x51;

    // ORA opcodes
    funcArr[0x09] = &opcode0x09;
    funcArr[0x05] = &opcode0x05;
    funcArr[0x15] = &opcode0x15;
    funcArr[0x0D] = &opcode0x0D;
    funcArr[0x1D] = &opcode0x1D;
    funcArr[0x19] = &opcode0x19;
    funcArr[0x01] = &opcode0x01;
    funcArr[0x11] = &opcode0x11;

    // BIT opcodes
    funcArr[0x24] = &opcode0x24;
    funcArr[0x2C] = &opcode0x2C;

    // STA opcodes
    funcArr[0x85] = &opcode0x85;
    funcArr[0x95] = &opcode0x95;
    funcArr[0x8D] = &opcode0x8D;
    funcArr[0x9D] = &opcode0x9D;
    funcArr[0x99] = &opcode0x99;
    funcArr[0x81] = &opcode0x81;
    funcArr[0x91] = &opcode0x91;

    // STX opcodes
    funcArr[0x86] = &opcode0x86;
    funcArr[0x96] = &opcode0x96;
    funcArr[0x8E] = &opcode0x8E;

    // STY opcodes
    funcArr[0x84] = &opcode0x84;
    funcArr[0x94] = &opcode0x94;
    funcArr[0x8C] = &opcode0x8C;

    // Register transfer opcodes
    funcArr[0xAA] = &opcode0xAA;
    funcArr[0xA8] = &opcode0xA8;
    funcArr[0x8A] = &opcode0x8A;
    funcArr[0x98] = &opcode0x98;

    // ADC opcodes
    funcArr[0x69] = &opcode0x69;
    funcArr[0x65] = &opcode0x65;
    funcArr[0x75] = &opcode0x75;
    funcArr[0x6D] = &opcode0x6D;
    funcArr[0x7D] = &opcode0x7D;
    funcArr[0x79] = &opcode0x79;
    funcArr[0x61] = &opcode0x61;
    funcArr[0x71] = &opcode0x71;

    // Increment opcodes
    funcArr[0xE6] = &opcode0xE6;
    funcArr[0xF6] = &opcode0xF6;
    funcArr[0xEE] = &opcode0xEE;
    funcArr[0xFE] = &opcode0xFE;
    funcArr[0xE8] = &opcode0xE8;
    funcArr[0xC8] = &opcode0xC8;

    // Decrement opcodes
    funcArr[0xC6] = &opcode0xC6;
    funcArr[0xD6] = &opcode0xD6;
    funcArr[0xCE] = &opcode0xCE;
    funcArr[0xDE] = &opcode0xDE;
    funcArr[0xCA] = &opcode0xCA;
    funcArr[0x88] = &opcode0x88;

    // Flag opcodes
    funcArr[0x18] = &opcode0x18;
    funcArr[0xD8] = &opcode0xD8;
    funcArr[0x58] = &opcode0x58;
    funcArr[0xB8] = &opcode0xB8;
    funcArr[0x38] = &opcode0x38;
    funcArr[0xF8] = &opcode0xF8;
    funcArr[0x78] = &opcode0x78;

    // Stack opcodes
    funcArr[0xBA] = &opcode0xBA;
    funcArr[0x9A] = &opcode0x9A;
    funcArr[0x48] = &opcode0x48;
    funcArr[0x08] = &opcode0x08;
    funcArr[0x68] = &opcode0x68;
    funcArr[0x28] = &opcode0x28;

    // Shift opcodes
    funcArr[0x0A] = &opcode0x0A;
    funcArr[0x06] = &opcode0x06;
    funcArr[0x16] = &opcode0x16;
    funcArr[0x0E] = &opcode0x0E;
    funcArr[0x1E] = &opcode0x1E;

    return;
}

int main()
{
    uint8_t myProgram[] = {0xA9, 0xFF, 0x29, 0xAA};
    uint16_t programLength = 4;

    initializeFunctionTable();

    while (pcnt < programLength)
    {
        printf("\n");
        parseProgram(myProgram);
        printf("\n");
    }

    printf("\n\n\n\n\n\n\n");
    printCpuState();

    return 0;
}
