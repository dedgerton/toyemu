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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "loadOpcodes.h"
#include "storeOpcodes.h"
#include "logicalOpcodes.h"
#include "taxOpcode.h"

uint16_t pcnt = 0x0000;
uint8_t  accu = 0x00;
uint8_t  xreg = 0x00;
uint8_t  yreg = 0x00;
uint8_t  spnt = 0x00;
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

uint8_t getSreg()
{
    return (carryFlag | (zeroFlag << 1) | (interruptFlag << 2) | (decimalFlag << 3) | (breakFlag << 4) | 0x20 | (overflowFlag << 6) |   (negativeFlag << 7));
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

int main()
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

    // STX opcodes
    funcArr[0x84] = &opcode0x84;
    funcArr[0x94] = &opcode0x94;
    funcArr[0x8C] = &opcode0x8C;

    // TAX opcode
    funcArr[0xAA] = &opcode0xAA;

    uint8_t myProgram[] = {0xA9, 0xFF, 0x29, 0xAA};
    uint16_t programLength = 4;

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
