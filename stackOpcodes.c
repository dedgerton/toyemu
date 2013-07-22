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

#include "stackOpcodes.h"

void opcode0xBA(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xBAEncountered, opcodeEncEnd);
    xreg = spnt;
    auxSetZeroFlag(xreg);
    auxSetNegativeFlag(xreg);
    pcnt += 1;
    return;
}

void opcode0x9A(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x9AEncountered, opcodeEncEnd);
    spnt = xreg;
    pcnt += 1;
    return;
}

void opcode0x48(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x48Encountered, opcodeEncEnd);
    writeMemory((0x0100+spnt), accu);
    spnt --;
    pcnt += 1;
    return;
}

void opcode0x08(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x08Encountered, opcodeEncEnd);
    writeMemory((0x0100+spnt), getSreg());
    spnt --;
    pcnt += 1;
    return;
}

void opcode0x68(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x68Encountered, opcodeEncEnd);
    spnt ++;
    accu = readMemory(0x0100+spnt);
    auxSetZeroFlag(accu);
    auxSetNegativeFlag(accu);
    pcnt += 1;
    return;
}

void opcode0x28(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x28Encountered, opcodeEncEnd);
    spnt ++;
    setSreg(readMemory(0x0100+spnt));
    pcnt += 1;
    return;
}
