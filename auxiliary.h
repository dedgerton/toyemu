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

#include <stdint.h>

extern uint16_t pcnt;
extern uint8_t  accu;
extern uint8_t  xreg;
extern uint8_t  yreg;
extern uint8_t  spnt;
extern uint8_t  carryFlag, zeroFlag, interruptFlag, decimalFlag, breakFlag, overflowFlag, negativeFlag;

extern uint8_t readMemory(uint16_t address);
extern void writeMemory(uint16_t address, uint8_t value);

uint8_t getSreg(); // Auxiliary to access the status flags as a register
void setSreg(uint8_t value); // Auxiliary to access the status flags as a register

void auxSetAccuFlags(); // Auxiliary to set the negative and zero flag after LD'ing the accumulator
void auxSetXregFlags(); // Auxiliary to set the negative and zero flag after LD'ing the X register
void auxSetYregFlags(); // Auxiliary to set the negative and zero flag after LD'ing the Y register

inline void auxSetNegativeFlag(uint8_t argument); // Auxiliary to set the negative flag if bit 7 (8, really) is set in the argument passed
inline void auxSetCarryFlag(uint8_t argument); // Auxiliary to set the carry flag if bit 7 (8, really) is set in the argument passed
inline void auxSetZeroFlag(uint8_t argument); // Auxiliary to set the zero flag if the argument passed is zero
