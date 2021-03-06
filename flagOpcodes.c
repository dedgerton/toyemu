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

#include "flagOpcodes.h"


void opcode0x18(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x18Encountered, opcodeEncEnd);
    carryFlag = 0;
    pcnt += 1;
    return;
}

void opcode0xD8(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xD8Encountered, opcodeEncEnd);
    decimalFlag = 0;
    pcnt += 1;
    return;
}

void opcode0x58(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x58Encountered, opcodeEncEnd);
    interruptFlag = 0;
    pcnt += 1;
    return;
}

void opcode0xB8(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xB8Encountered, opcodeEncEnd);
    overflowFlag = 0;
    pcnt += 1;
    return;
}

void opcode0x38(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x38Encountered, opcodeEncEnd);
    carryFlag = 1;
    pcnt += 1;
    return;
}

void opcode0xF8(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xF8Encountered, opcodeEncEnd);
    decimalFlag = 1;
    pcnt += 1;
    return;
}

void opcode0x78(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x78Encountered, opcodeEncEnd);
    interruptFlag = 1;
    pcnt += 1;
    return;
}
