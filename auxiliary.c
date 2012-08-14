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

#include "auxiliary.h"

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