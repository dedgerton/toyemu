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
#include <stdio.h>
#include "stringRes.h"
#include "auxiliary.h"

// STA opcodes
void opcode0x85(uint8_t* data); // | Zero Page 	 | STA 15     | $85/133 | 2 |
void opcode0x95(uint8_t* data); // | Zero Page,X | STA 15,X   | $95/149 | 2 |
void opcode0x8D(uint8_t* data); // | Absolute    | STA 1500   | $8D/141 | 2 |
void opcode0x9D(uint8_t* data); // | Absolute,X  | STA 1500,X | $9D/157 | 3 |
void opcode0x99(uint8_t* data); // | Absolute,Y  | STA 1500,Y | $99/153 | 3 |
void opcode0x81(uint8_t* data); // | Indirect,X  | STA (15,X) | $81/129 | 2 |
void opcode0x91(uint8_t* data); // | Indirect,Y  | STA (15),Y | $91/145 | 2 |

// STX opcodes
void opcode0x84(uint8_t* data); // | Zero Page   | STY 15     | $84/132 | 2 |
void opcode0x94(uint8_t* data); // | Zero Page,X | STY 15,X   | $94/148 | 2 |
void opcode0x8C(uint8_t* data); // | Absolute    | STY 1500   | $8C/140 | 3 |

// STY opcodes
void opcode0x86(uint8_t* data); // | Zero Page   | STX 15     | $86/134 | 2 |
void opcode0x96(uint8_t* data); // | Zero Page,Y | STX 15,Y   | $96/150 | 2 |
void opcode0x8E(uint8_t* data); // | Absolute    | STX 1500   | $8E/142	| 3 |
