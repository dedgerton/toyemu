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

#include "transferOpcodes.h"

void opcode0xAA(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xAAEncountered, opcodeEncEnd);
    xreg = accu;
    pcnt += 1;

    return;
}

void opcode0xA8(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0xA8Encountered, opcodeEncEnd);
    yreg = accu;
    pcnt += 1;

    return;
}

void opcode0x8A(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x8AEncountered, opcodeEncEnd);
    accu = xreg;
    pcnt += 1;

    return;
}

void opcode0x98(uint8_t* data)
{
    printf("%s%s%s", opcodeEncStart, opcode0x98Encountered, opcodeEncEnd);
    accu = yreg;
    pcnt += 1;

    return;
}
