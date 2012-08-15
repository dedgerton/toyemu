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

// ADC opcodes
void adcBackbone(uint8_t value); // Backbone of the ADC opcodes, to reduce redundancy
void opcode0x69(uint8_t* data); // | Immediate   | ADC #15    | $69/105 | 2 |
void opcode0x65(uint8_t* data); // | Zero Page	 | ADC 15     | $65/101 | 2 |
void opcode0x75(uint8_t* data); // | Zero Page,X | ADC 15,X   | $75/117 | 2 |
void opcode0x6D(uint8_t* data); // | Absolute    | ADC 1500   | $6D/109 | 3 |
void opcode0x7D(uint8_t* data); // | Absolute,X  | ADC 1500,X | $7D/125 | 3 |
void opcode0x79(uint8_t* data); // | Absolute,Y  | ADC 1500,Y | $79/121 | 3 |
void opcode0x61(uint8_t* data); // | Indirect,X  | ADC (15,X) | $61/97  | 2 |
void opcode0x71(uint8_t* data); // | Indirect,Y  | ADC (15),Y | $71/113 | 2 |

