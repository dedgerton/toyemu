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

#include <stdint.h>
#include <stdio.h>
#include "stringRes.h"
#include "auxiliary.h"

// DEC opcodes
void opcode0xC6(uint8_t* data); // | Zero Page   | DEC 15     | $C6/198 | 2 |
void opcode0xD6(uint8_t* data); // | Zero Page,X | DEC 15,X   | $D6/214 | 2 |
void opcode0xCE(uint8_t* data); // | Absolute    | DEC 1500   | $CE/206 | 3 |
void opcode0xDE(uint8_t* data); // | Absolute,X  | DEC 1500,X | $DE/222 | 3 |

void opcode0xCA(uint8_t* data); // | Implied     | DEX        | $CA/202 | 1 |
void opcode0x88(uint8_t* data); // | Implied     | DEY        | $88/136 | 1 |
