/*!
 *  \file    CHashWAIS.cpp Thinking Machines WAIS project hash function
 *           algorithm.
 *  \brief   Thinking Machines WAIS project hash function algorithm (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Thinking Machines WAIS project hash function algorithm (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   11.03.2007 00:54:25

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
#include <Depth/include/algorithms/hash/CHashWAIS.hpp>
/*==========================================================================*/
#ifndef __CHASHWAIS_CPP__
#define __CHASHWAIS_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NHash {
/*==========================================================================*/
/* ALGORITHM IMPLEMENTATIONS                                                */
/*==========================================================================*/
BASE_API Tuint CHashWAIS::ms_cRandomHash[] =
{
  0x4BEF74B7, 0x7FE1F5A6, 0xB4C08BF6, 0xC2CF0CD0,
  0x788E2A29, 0xB043B6B9, 0x5B56C90C, 0x324D8FE7,
  0x8D9C854A, 0xCAE06AC8, 0x902076A1, 0x949EAA31,
  0xDC070A08, 0xF7499B6D, 0x17883EAA, 0x22A65A35,
  0x34FC6407, 0x8322F367, 0xD105BB0F, 0xD8A29526,
  0x8A1B708A, 0xBE85B1E1, 0xC66AC334, 0xC1B13A1C,
  0xEDF644E4, 0x3EA3806C, 0x2732D31D, 0xEBF504A9,
  0x08BB2B52, 0x4775992C, 0x3C0B8CF7, 0x5FA0AEA2,
  0x7616D761, 0x66AA86DB, 0xC73305C0, 0x09E6EA99,
  0xC9789DD6, 0xF47340F1, 0x3941303E, 0x7542233A,
  0xE0812ED1, 0xFF2E54FE, 0x07B887EB, 0x68CD0E93,
  0xB124C17F, 0xD01A9C5B, 0x96B490ED, 0xA7CAE5FC,
  0x18D41F37, 0x6E8DA1BC, 0x9B631940, 0x35ABCFD4,
  0xACA1FB0A, 0x2F71B921, 0x6F10A747, 0xA6680796,
  0x01F12271, 0xFDBE0378, 0x02F0FF79, 0xEC3FF2D2,
  0x84485C9C, 0x60BF9113, 0x98CC35E3, 0xAA2A8D4D,
  0xA5CBA2E9, 0xF0AE1EF2, 0x990118E2, 0x64A966F5,
  0x8595490D, 0x7E9B4391, 0xE8311B7D, 0x2474BCBF,
  0x19D6E286, 0xDFD32D5C, 0xAB5116CA, 0x7D72D6D5,
  0x0BF44F5E, 0x6170B3D3, 0x2C471CC2, 0x2EFD1118,
  0x8C878836, 0x62FE52E0, 0x2B8C1277, 0x2ACEBDEC,
  0xB2E8A8A3, 0x30B757AE, 0x708BBA8D, 0x501EF654,
  0x49A7EF1E, 0xFE7636AD, 0xB54BBE4F, 0x1ADBDB8C,
  0x72E24DD9, 0xF68A2517, 0xF56FEEDF, 0x5A7EB75D,
  0xD606F9E6, 0xC32526B8, 0x5EB613F3, 0x0C08CBDE,
  0x8B965E59, 0xB361EB75, 0x3FADE465, 0xB8FFD16F,
  0x26442988, 0x00D2D830, 0x3D58FE41, 0x3B386E44,
  0x1297E914, 0xAFC11083, 0xC5EBE8B6, 0x15A49ECD,
  0xF950C263, 0xA0DA0982, 0x4CBDF101, 0xE227F77E,
  0x556DB8DA, 0xA1BA2125, 0x1E3BD409, 0xFCF25155,
  0x110A983B, 0x7B7F1A4C, 0xE7FB4C69, 0xC8994E1F,
  0x586C4A42, 0x5C1FAF2F, 0xAD777D48, 0x9186696B,
  0xD52181B4, 0xE94C39EF, 0x9EDEB2FF, 0x802FDA20,
  0xA228D902, 0x52BC7CFD, 0x53DD47AC, 0x6D12D25F,
  0xCE1D6D8F, 0xF12C8E2B, 0xDD5700C1, 0x9A402851,
  0x386E53D7, 0x0DF88281, 0x4A55CDC4, 0x653692B0,
  0x203CAC8E, 0x747C6164, 0xC47A02B2, 0x1B4FC82D,
  0xF8934B7A, 0x36A82CB5, 0x690CD080, 0x2800A524,
  0x1C045D0E, 0xBF09CAF0, 0x8814ABB3, 0xE3D0776A,
  0x219AA6D8, 0xCC375653, 0xFA2327A8, 0x57F75F27,
  0x732DA903, 0x8F696738, 0x3A453223, 0xDA1C9F32,
  0xCF90152A, 0x0F64BFF4, 0xD7533FA5, 0x8E7D55DC,
  0xBC598998, 0x45110DBA, 0x4D92E6FB, 0x7746C01A,
  0x951348A0, 0xBBFA7E9B, 0x055EAD7B, 0x06B36BBB,
  0x0EE31D97, 0x37297F11, 0xEF529450, 0x51C6E168,
  0x1F67C63F, 0x6B023443, 0x449F5BFA, 0x48C39A4B,
  0xD30E426E, 0x0ADFE31B, 0x467B6085, 0x7CC49676,
  0x140DFA60, 0xE16B7274, 0x235AEC05, 0xD2D7DCC6,
  0x13946212, 0x339D2462, 0xFB82F8EE, 0xB6197970,
  0xBD0F3C9D, 0xE64E3B28, 0xE4B07A87, 0x54C92F95,
  0x6CC583AB, 0xD4182015, 0x86DC755A, 0xA930A333,
  0x82B273EA, 0x923EED7C, 0xF354A02E, 0xEEEEA439,
  0x1D89089A, 0xD9EDDEE8, 0x1017B504, 0xA45CB0C7,
  0x93C7E0A4, 0x43D95858, 0xDB654594, 0x31D578CF,
  0xCDF98489, 0xB915C7F9, 0x67846FE5, 0x04D150AF,
  0x5DF314DD, 0xCB911772, 0xA8627156, 0x258FC573,
  0xEAA5E79F, 0x633D4119, 0x793501C9, 0x7AD80F0B,
  0x4E5DF04E, 0x97AF6884, 0xAE3A9745, 0xA3ACF48B,
  0x16398A10, 0xDE8346C3, 0x42C20606, 0x03EAB4B1,
  0x8798FDCC, 0x9CE4FC22, 0x81B5DD3D, 0x563431BE,
  0x2D799349, 0xF2036C92, 0xB7E97B3C, 0x71E559C5,
  0x5960C4BD, 0x295B63F8, 0xBA5F0B57, 0xE5B93DCE,
  0x6A4ACC90, 0x89EC6516, 0x4180D566, 0x40263300,
  0x9DE738CB, 0x4F2B3746, 0x9F66DF9E, 0xC0C8CEA7
};
/*--------------------------------------------------------------------------*/
Tuint CHashWAIS::hash(Tcbuffer a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint i = a_cSize;
  while (i-- > 0)
    m_Hash += ms_cRandomHash[0xFF & ((m_Hash >> 24) ^ (*a_cpBuffer++))];
  return a_cSize;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
