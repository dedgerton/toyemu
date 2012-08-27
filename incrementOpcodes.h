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

// INC opcodes
void opcode0xE6(uint8_t* data); // | Zero Page   | INC 15     | $E6/230 | 2 |
void opcode0xF6(uint8_t* data); // | Zero Page,X | INC 15,X   | $F6/246 | 2 |
void opcode0xEE(uint8_t* data); // | Absolute    | INC 1500   | $EE/238 | 3 |
void opcode0xFE(uint8_t* data); // | Absolute,X  | INC 1500,X | $FE/254 | 3 |

void opcode0xE8(uint8_t* data); // | Implied     | INX        | $E8/232 | 1 |
void opcode0xC8(uint8_t* data); // | Implied     | INY        | $C8/200 | 1 |
