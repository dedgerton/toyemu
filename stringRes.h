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

#ifndef __STRINGRES_H__
#define __STRINGRES_H__

// LDA opcodes
static const char opcode0xA9Encountered[] = "OP_PARSE: Opcode LDA imm (0xA9) encountered.\n";
static const char opcode0xA5Encountered[] = "OP_PARSE: Opcode LDA zp (0xA5) encountered.\n";
static const char opcode0xB5Encountered[] = "OP_PARSE: Opcode LDA zp,x (0xB5) encountered.\n";
static const char opcode0xADEncountered[] = "OP_PARSE: Opcode LDA abs (0xAD) encountered.\n";
static const char opcode0xBDEncountered[] = "OP_PARSE: Opcode LDA abs,x (0xBD) encountered.\n";
static const char opcode0xB9Encountered[] = "OP_PARSE: Opcode LDA abs,y (0xB9) encountered.\n";
static const char opcode0xA1Encountered[] = "OP_PARSE: Opcode LDA ind,x (0xA1) encountered.\n";
static const char opcode0xB1Encountered[] = "OP_PARSE: Opcode LDA ind,y (0xB1) encountered.\n";

// LDX opcodes
static const char opcode0xA2Encountered[] = "OP_PARSE: Opcode LDX imm (0xA2) encountered.\n";
static const char opcode0xA6Encountered[] = "OP_PARSE: Opcode LDX zp (0xA6) encountered.\n";
static const char opcode0xB6Encountered[] = "OP_PARSE: Opcode LDX zp,y (0xB6) encountered.\n";
static const char opcode0xAEEncountered[] = "OP_PARSE: Opcode LDX abs (0xAE) encountered.\n";
static const char opcode0xBEEncountered[] = "OP_PARSE: Opcode LDX abs,y (0xBE) encountered.\n";

// LDY opcodes
static const char opcode0xA0Encountered[] = "OP_PARSE: Opcode LDY imm (0xA0) encountered.\n";
static const char opcode0xA4Encountered[] = "OP_PARSE: Opcode LDY zp (0xA4) encountered.\n";
static const char opcode0xB4Encountered[] = "OP_PARSE: Opcode LDY zp,x (0xB4) encountered.\n";
static const char opcode0xACEncountered[] = "OP_PARSE: Opcode LDY abs (0xAC) encountered.\n";
static const char opcode0xBCEncountered[] = "OP_PARSE: Opcode LDY abs,x (0xBC) encountered.\n";

// AND opcodes
static const char opcode0x29Encountered[] = "OP_PARSE: Opcode AND imm (0x29) encountered.\n";
static const char opcode0x25Encountered[] = "OP_PARSE: Opcode AND zp (0x25) encountered.\n";
static const char opcode0x35Encountered[] = "OP_PARSE: Opcode AND zp,x (0x35) encountered.\n";
static const char opcode0x2DEncountered[] = "OP_PARSE: Opcode AND abs (0x2D) encountered.\n";
static const char opcode0x3DEncountered[] = "OP_PARSE: Opcode AND abs,x (0x3D) encountered.\n";
static const char opcode0x39Encountered[] = "OP_PARSE: Opcode AND abs,y (0x39) encountered.\n";
static const char opcode0x21Encountered[] = "OP_PARSE: Opcode AND ind,x (0x21) encountered.\n";
static const char opcode0x31Encountered[] = "OP_PARSE: Opcode AND ind,y (0x31) encountered.\n";

// STA opcodes
static const char opcode0x85Encountered[] = "OP_PARSE: Opcode STA zp (0x85) encountered.\n";
static const char opcode0x95Encountered[] = "OP_PARSE: Opcode STA zp,x (0x95) encountered.\n";
static const char opcode0x8DEncountered[] = "OP_PARSE: Opcode STA abs (0x8D) encountered.\n";
static const char opcode0x9DEncountered[] = "OP_PARSE: Opcode STA abs,x (0x9D) encountered.\n";
static const char opcode0x99Encountered[] = "OP_PARSE: Opcode STA abs,y (0x99) encountered.\n";
static const char opcode0x81Encountered[] = "OP_PARSE: Opcode STA ind,x (0x81) encountered.\n";
static const char opcode0x91Encountered[] = "OP_PARSE: Opcode STA ind,y (0x91) encountered.\n";

#endif /* __STRINGRES_H__ */
