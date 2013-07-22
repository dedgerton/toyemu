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

#include "auxiliary.h"

uint8_t getSreg()
{
    return (carryFlag | (zeroFlag << 1) | (interruptFlag << 2) | (decimalFlag << 3) | (breakFlag << 4) | 0x20 | (overflowFlag << 6) |   (negativeFlag << 7));
}

void setSreg(uint8_t value)
{
    carryFlag     = (value & 0x01);
    zeroFlag      = (value & 0x02) >> 1;
    interruptFlag = (value & 0x04) >> 2;
    decimalFlag   = (value & 0x08) >> 3;
    breakFlag     = (value & 0x10) >> 4;
    overflowFlag  = (value & 0x40) >> 6;
    negativeFlag  = (value & 0x80) >> 7;
    return;
}

void auxSetAccuFlags()
{
    // Set the zero flag accordingly
    if (accu == 0)
        zeroFlag = 1;
    else zeroFlag = 0;

    // Set the negative flag accordingly
    if (((accu & 0xF0) >> 7) == 1)
        negativeFlag = 1;
    else negativeFlag = 0;

    return;
}

void auxSetXregFlags()
{
    // Set the zero flag accordingly
    if (xreg == 0)
        zeroFlag = 1;
    else zeroFlag = 0;

    // Set the negative flag accordingly
    if (((xreg & 0xF0) >> 7) == 1)
        negativeFlag = 1;
    else negativeFlag = 0;

    return;
}

void auxSetYregFlags()
{
    // Set the zero flag accordingly
    if (yreg == 0)
        zeroFlag = 1;
    else zeroFlag = 0;

    // Set the negative flag accordingly
    if (((yreg & 0xF0) >> 7) == 1)
        negativeFlag = 1;
    else negativeFlag = 0;

    return;
}

inline void auxSetNegativeFlag(uint8_t argument)
{
    // Set the negative flag if bit 7 (8) is set, clear it otherwise
    if ((argument >> 7) == 1)
        negativeFlag = 1;
    else negativeFlag = 0;
    return;
}

inline void auxSetCarryFlag(uint8_t argument)
{
    // Set the negative flag if bit 7 (8) is set, clear it otherwise
    if ((argument >> 7) == 1)
        carryFlag = 1;
    else carryFlag = 0;
    return;
}

inline void auxSetZeroFlag(uint8_t argument)
{
    // Set the zero flag if zero, clear it otherwise
    if (argument == 0)
        negativeFlag = 1;
    else negativeFlag = 0;
    return;
}
