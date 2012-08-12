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


// AND opcodes
void opcode0x29(uint8_t* data); // | Immediate   | AND #15    | $29/41  | 2 |
void opcode0x25(uint8_t* data); // | Zero Page   | AND 15     | $25/37  | 2 |
void opcode0x35(uint8_t* data); // | Zero Page,X | AND 15,X   | $35/53  | 2 |
void opcode0x2D(uint8_t* data); // | Absolute    | AND 1500   | $2D/45  | 3 |
void opcode0x3D(uint8_t* data); // | Absolute,X  | AND 1500,X | $3D/61  | 3 |
void opcode0x39(uint8_t* data); // | Absolute,Y  | AND 1500,Y | $39/57  | 3 |
void opcode0x21(uint8_t* data); // | Indirect,X  | AND (15,X) | $21/33  | 2 |
void opcode0x31(uint8_t* data); // | Indirect,Y  | AND (15),Y | $31/49  | 2 |

// EOR opcodes
void opcode0x49(uint8_t* data); // | Immediate   | EOR #15    | $49/73  | 2 |
void opcode0x45(uint8_t* data); // | Zero Page   | EOR 15     | $45/68  | 2 |
void opcode0x55(uint8_t* data); // | Zero Page,X | EOR 15,X   | $55/85  | 2 |
void opcode0x4D(uint8_t* data); // | Absolute    | EOR 1500   | $4D/77  | 3 |
void opcode0x5D(uint8_t* data); // | Absolute,X  | EOR 1500,X | $5D/93  | 3 |
void opcode0x59(uint8_t* data); // | Absolute,Y  | EOR 1500,Y | $59/89  | 3 |
void opcode0x41(uint8_t* data); // | Indirect,X  | EOR (15,X) | $41/65  | 2 |
void opcode0x51(uint8_t* data); // | Indirect,Y  | EOR (15),Y | $51/81  | 2 |

// ORA opcodes
void opcode0x09(uint8_t* data); // | Immediate   | ORA #15    | $09/9   | 2 |
void opcode0x05(uint8_t* data); // | Zero Page   | ORA 15     | $05/5   | 2 |
void opcode0x15(uint8_t* data); // | Zero Page,X | ORA 15,X   | $15/21  | 2 |
void opcode0x0D(uint8_t* data); // | Absolute    | ORA 1500   | $0D/13  | 3 |
void opcode0x1D(uint8_t* data); // | Absolute,X  | ORA 1500,X | $1D/29  | 3 |
void opcode0x19(uint8_t* data); // | Absolute,Y  | ORA 1500,Y | $19/25  | 3 |
void opcode0x01(uint8_t* data); // | Indirect,X  | ORA (15,X) | $01/1   | 2 |
void opcode0x11(uint8_t* data); // | Indirect,Y  | ORA (15),Y | $11/17  | 2 |
