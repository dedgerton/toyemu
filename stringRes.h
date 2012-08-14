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

static const char opcodeEncStart[]        = "OP_PARSE: Opcode ";
static const char opcodeEncEnd[]          = " encountered.\n";


///////////////////////////////////////////////////////////////////////////////
////////////////////////////////load opcodes///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// LDA opcodes
static const char opcode0xA9Encountered[] = "LDA imm (0xA9)";
static const char opcode0xA5Encountered[] = "LDA zp (0xA5)";
static const char opcode0xB5Encountered[] = "LDA zp,x (0xB5)";
static const char opcode0xADEncountered[] = "LDA abs (0xAD)";
static const char opcode0xBDEncountered[] = "LDA abs,x (0xBD)";
static const char opcode0xB9Encountered[] = "LDA abs,y (0xB9)";
static const char opcode0xA1Encountered[] = "LDA ind,x (0xA1)";
static const char opcode0xB1Encountered[] = "LDA ind,y (0xB1)";

// LDX opcodes
static const char opcode0xA2Encountered[] = "LDX imm (0xA2)";
static const char opcode0xA6Encountered[] = "LDX zp (0xA6)";
static const char opcode0xB6Encountered[] = "LDX zp,y (0xB6)";
static const char opcode0xAEEncountered[] = "LDX abs (0xAE)";
static const char opcode0xBEEncountered[] = "LDX abs,y (0xBE)";

// LDY opcodes
static const char opcode0xA0Encountered[] = "LDY imm (0xA0)";
static const char opcode0xA4Encountered[] = "LDY zp (0xA4)";
static const char opcode0xB4Encountered[] = "LDY zp,x (0xB4)";
static const char opcode0xACEncountered[] = "LDY abs (0xAC)";
static const char opcode0xBCEncountered[] = "LDY abs,x (0xBC)";

///////////////////////////////////////////////////////////////////////////////
////////////////////////////end load opcodes///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/////////////////////////////logical opcodes///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// AND opcodes
static const char opcode0x29Encountered[] = "AND imm (0x29)";
static const char opcode0x25Encountered[] = "AND zp (0x25)";
static const char opcode0x35Encountered[] = "AND zp,x (0x35)";
static const char opcode0x2DEncountered[] = "AND abs (0x2D)";
static const char opcode0x3DEncountered[] = "AND abs,x (0x3D)";
static const char opcode0x39Encountered[] = "AND abs,y (0x39)";
static const char opcode0x21Encountered[] = "AND ind,x (0x21)";
static const char opcode0x31Encountered[] = "AND ind,y (0x31)";

// EOR opcodes
static const char opcode0x49Encountered[] = "EOR imm (0x49)";
static const char opcode0x45Encountered[] = "EOR zp (0x45)";
static const char opcode0x55Encountered[] = "EOR zp,x (0x55)";
static const char opcode0x4DEncountered[] = "EOR abs (0x4D)";
static const char opcode0x5DEncountered[] = "EOR abs,x (0x5D)";
static const char opcode0x59Encountered[] = "EOR abs,y (0x59)";
static const char opcode0x41Encountered[] = "EOR ind,x (0x41)";
static const char opcode0x51Encountered[] = "EOR ind,y (0x51)";

// ORA opcodes
static const char opcode0x09Encountered[] = "ORA imm (0x09)";
static const char opcode0x05Encountered[] = "ORA zp (0x05)";
static const char opcode0x15Encountered[] = "ORA zp,x (0x15)";
static const char opcode0x0DEncountered[] = "ORA abs (0x0D)";
static const char opcode0x1DEncountered[] = "ORA abs,x (0x1D)";
static const char opcode0x19Encountered[] = "ORA abs,y (0x19)";
static const char opcode0x01Encountered[] = "ORA ind,x (0x01)";
static const char opcode0x11Encountered[] = "ORA ind,y (0x11)";

///////////////////////////////////////////////////////////////////////////////
/////////////////////////end logical opcodes///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




// STA opcodes
static const char opcode0x85Encountered[] = "STA zp (0x85)";
static const char opcode0x95Encountered[] = "STA zp,x (0x95)";
static const char opcode0x8DEncountered[] = "STA abs (0x8D)";
static const char opcode0x9DEncountered[] = "STA abs,x (0x9D)";
static const char opcode0x99Encountered[] = "STA abs,y (0x99)";
static const char opcode0x81Encountered[] = "STA ind,x (0x81)";
static const char opcode0x91Encountered[] = "STA ind,y (0x91)";

// STX opcodes
static const char opcode0x86Encountered[] = "STX zp (0x86)";
static const char opcode0x96Encountered[] = "STX zp,y (0x96)";
static const char opcode0x8EEncountered[] = "STX abs (0x8E)";

// STY opcodes
static const char opcode0x84Encountered[] = "STY zp (0x84)";
static const char opcode0x94Encountered[] = "STY zp,x (0x94)";
static const char opcode0x8CEncountered[] = "STY abs (0x8C)";

// TAX opcode
static const char opcode0xAAEncountered[] = "TAX imp (0xAA)";

#endif /* __STRINGRES_H__ */