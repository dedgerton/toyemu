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

#include "incrementOpcodes.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////INC opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void opcode0xE6(uint8_t* data)
{
    uint8_t original, result;
    printf("%s%s%s", opcodeEncStart, opcode0xE6Encountered, opcodeEncEnd);
    printf("OP_PARSE: Operand is 0x%02X\n", data[1]);

    original = readMemory(data[1]);
    result = original + 1;
    writeMemory(data[1], result);

    // Set the zero flag accordingly
    if (result == 0)
        zeroFlag = 1;
    else zeroFlag = 0;

    // Set the negative flag accordingly
    if ((result >> 7) == 1)
        negativeFlag = 1;
    else negativeFlag = 0;

    pcnt += 2;

    return;
}

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////end INC opcodes//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
