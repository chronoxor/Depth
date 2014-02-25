/*!
 *  \file    AToASCIIUpper.cpp Contains implementation of the fast ASCII to
 *           upper case converting string algorithm.
 *  \brief   Fast ASCII to upper case converting string algorithm (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Fast ASCII to upper case converting string algorithm (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   20.11.2009 02:31:19

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

    This program is distributed in the  hope  that  it  will  be  useful,  but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
    for more details.

    You should have received a copy of the GNU General  Public  License  along
    with this program; if not, write to the Free Software Foundation, Inc., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/algorithms/string/buffer/AToASCIIUpper.hpp>
/*==========================================================================*/
#ifndef __ATOASCIIUPPER_CPP__
#define __ATOASCIIUPPER_CPP__
/*==========================================================================*/
/* LOCAL NAMESPACE DECLARATIONS                                             */
/*==========================================================================*/
namespace {
/*==========================================================================*/
/* LOCAL CONSTANTS DECLARATIONS                                             */
/*==========================================================================*/
//! ASCII to upper case converting table.
static const NDepth::NTypes::Tschar loc_cASCIIUpperTable[256] =
{
    '\0', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07',
  '\x08',   '\t',   '\n', '\x0B', '\x0C',   '\r', '\x0E', '\x0F',
  '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
  '\x18', '\x19', '\x1A', '\x1B', '\x1C', '\x1D', '\x1E', '\x1F',
     ' ',    '!',    '"',    '#',    '$',    '%',    '&',   '\'',
     '(',    ')',    '*',    '+',    ',',    '-',    '.',    '/',
     '0',    '1',    '2',    '3',    '4',    '5',    '6',    '7',
     '8',    '9',    ':',    ';',    '<',    '=',    '>',    '?',
     '@',    'A',    'B',    'C',    'D',    'E',    'F',    'G',
     'H',    'I',    'J',    'K',    'L',    'M',    'N',    'O',
     'P',    'Q',    'R',    'S',    'T',    'U',    'V',    'W',
     'X',    'Y',    'Z',    '[',   '\\',    ']',    '^',    '_',
     '`',    'A',    'B',    'C',    'D',    'E',    'F',    'G',
     'H',    'I',    'J',    'K',    'L',    'M',    'N',    'O',
     'P',    'Q',    'R',    'S',    'T',    'U',    'V',    'W',
     'X',    'Y',    'Z',    '{',    '|',    '}',    '~', '\x7F',
  '\x80', '\x81', '\x82', '\x83', '\x84', '\x85', '\x86', '\x87',
  '\x88', '\x89', '\x8A', '\x8B', '\x8C', '\x8D', '\x8E', '\x8F',
  '\x90', '\x91', '\x92', '\x93', '\x94', '\x95', '\x96', '\x97',
  '\x98', '\x99', '\x9A', '\x9B', '\x9C', '\x9D', '\x9E', '\x9F',
  '\xA0', '\xA1', '\xA2', '\xA3', '\xA4', '\xA5', '\xA6', '\xA7',
  '\xA8', '\xA9', '\xAA', '\xAB', '\xAC', '\xAD', '\xAE', '\xAF',
  '\xB0', '\xB1', '\xB2', '\xB3', '\xB4', '\xB5', '\xB6', '\xB7',
  '\xB8', '\xB9', '\xBA', '\xBB', '\xBC', '\xBD', '\xBE', '\xBF',
  '\xC0', '\xC1', '\xC2', '\xC3', '\xC4', '\xC5', '\xC6', '\xC7',
  '\xC8', '\xC9', '\xCA', '\xCB', '\xCC', '\xCD', '\xCE', '\xCF',
  '\xD0', '\xD1', '\xD2', '\xD3', '\xD4', '\xD5', '\xD6', '\xD7',
  '\xD8', '\xD9', '\xDA', '\xDB', '\xDC', '\xDD', '\xDE', '\xDF',
  '\xE0', '\xE1', '\xE2', '\xE3', '\xE4', '\xE5', '\xE6', '\xE7',
  '\xE8', '\xE9', '\xEA', '\xEB', '\xEC', '\xED', '\xEE', '\xEF',
  '\xF0', '\xF1', '\xF2', '\xF3', '\xF4', '\xF5', '\xF6', '\xF7',
  '\xF8', '\xF9', '\xFA', '\xFB', '\xFC', '\xFD', '\xFE', '\xFF'
};
/*==========================================================================*/
}
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NBuffer {
/*==========================================================================*/
/* ALGORITHM IMPLEMENTATIONS                                                */
/*==========================================================================*/
BASE_API void toASCIIUpper(Tsstr a_pDestination, Tcsstr a_cpSource, const Tuint a_cSize)
{ CALL
  const Tuint leftover = a_cSize % 4;
  const Tuint imax = a_cSize / 4;
  const Tcbuffer s = (Tcbuffer)a_cpSource;

  Tuint i;
  Tuint32 eax, ebx;
  Tcbuffer ustr = (Tcbuffer)a_cpSource;
  Tbuffer dest = (Tbuffer)a_pDestination;
  Tuint32* d = (Tuint32*)a_pDestination;

  for (i = 0; i != imax; ++i)
  {
    eax = s[i];

    // This is based on the algorithm by Paul Hsieh
    // http://www.azillionmonkeys.com/qed/asmexample.html
    ebx = (CONSTU32(0x7F7F7F7F) & eax) + CONSTU32(0x05050505);
    ebx = (CONSTU32(0x7F7F7F7F) & ebx) + CONSTU32(0x1A1A1A1A);
    ebx = ((ebx & ~eax) >> 2)  & CONSTU32(0x20202020);
    *d++ = eax - ebx;
  }

  i = imax * 4;
  dest = (Tbuffer)d;
  switch (leftover)
  {
    case 3: *dest++ = loc_cASCIIUpperTable[ustr[i++]];
    case 2: *dest++ = loc_cASCIIUpperTable[ustr[i++]];
    case 1: *dest++ = loc_cASCIIUpperTable[ustr[i]];
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
