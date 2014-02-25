/*!
 *  \file    binary.hpp Contains binary converting macros.
 *  \brief   Binary converting macros.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Binary converting macros.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Macro
    VERSION:   1.0
    CREATED:   02.11.2006 02:27:52

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
#ifndef __BINARY_HPP__
#define __BINARY_HPP__
/*==========================================================================*/
/* MACRO DECLARATIONS                                                       */
/*==========================================================================*/
/*!
    \def BIN_HELPER_EXTRACT(bin)
    Extract binary numbers from hexadecimal representation.
*/
#define BIN_HELPER_EXTRACT(bin) ((bin) | ((bin) >> 3) | ((bin) >> 6) | ((bin) >> 9))
/*!
    \def BIN_HELPER_PACK(bin)
    Pack extracted numbers to the number of byte type.
*/
#define BIN_HELPER_PACK(bin) (((bin) & 0xF) | (((bin) >> 12) & 0xF0))
/*!
    \def BIN8(bin)
    Defines the binary converting macro. It gives ability  to  convert  single
    byte from binary code to the number of byte type.
    For example: BIN8(00001010) == 0xA
*/
#define BIN8(bin) Tsint08(BIN_HELPER_PACK(BIN_HELPER_EXTRACT(0x ## bin)))
/*!
    \def BIN16(bin1, bin2)
    Defines the binary converting macro. It gives ability to convert two bytes
    from binary code to the number of two bytes type.
    For example: BIN16(00001010, 00001010) == 0xA0A
*/
#define BIN16(bin1, bin2) ((Tsint16(BIN8(bin1)) << 8) + Tsint16(BIN8(bin2)))
/*!
    \def BIN24(bin1, bin2, bin3)
    Defines the binary converting macro. It gives  ability  to  convert  three
    bytes from binary code to the number of three bytes type.
    For example: BIN24(00001010, 00001010, 00001010) == 0xA0A0A
*/
#define BIN24(bin1, bin2, bin3) ((Tsint32(BIN8(bin1)) << 16) + (Tsint32(BIN8(bin2)) << 8) + Tsint32(BIN8(bin3)))
/*!
    \def BIN32(bin1, bin2, bin3, bin4)
    Defines the binary converting macro. It  gives  ability  to  convert  four
    bytes from binary code to the number of four bytes type.
    For example: BIN32(00001010, 00001010, 00001010, 00001010) == 0xA0A0A0A
*/
#define BIN32(bin1, bin2, bin3, bin4) ((Tsint32(BIN8(bin1)) << 24) + (Tsint32(BIN8(bin2)) << 16) + (Tsint32(BIN8(bin3)) << 8) + Tsint32(BIN8(bin4)))
/*!
    \def BIN40(bin1, bin2, bin3, bin4, bin5)
    Defines the binary converting macro. It  gives  ability  to  convert  five
    bytes from binary code to the number of five bytes type.
    For example: BIN40(00001010, 00001010, 00001010, 00001010, 00001010) == 0xA0A0A0A0A
*/
#define BIN40(bin1, bin2, bin3, bin4, bin5) ((Tsint64(BIN8(bin1)) << 32) + (Tsint64(BIN8(bin2)) << 24) + (Tsint64(BIN8(bin3)) << 16) + (Tsint64(BIN8(bin4)) << 8) + Tsint64(BIN8(bin5)))
/*!
    \def BIN48(bin1, bin2, bin3, bin4, bin5, bin6)
    Defines the binary converting macro. It gives ability to convert six bytes
    from binary code to the number of six bytes type.
    For example: BIN48(00001010, 00001010, 00001010, 00001010, 00001010, 00001010) == 0xA0A0A0A0A0A
*/
#define BIN48(bin1, bin2, bin3, bin4, bin5, bin6) ((Tsint64(BIN8(bin1)) << 40) + (Tsint64(BIN8(bin2)) << 32) + (Tsint64(BIN8(bin3)) << 24) + (Tsint64(BIN8(bin4)) << 16) + (Tsint64(BIN8(bin5)) << 8) + Tsint64(BIN8(bin6)))
/*!
    \def BIN56(bin1, bin2, bin3, bin4, bin5, bin6, bin7)
    Defines the binary converting macro. It gives  ability  to  convert  seven
    bytes from binary code to the number of seven bytes type.
    For example: BIN56(00001010, 00001010, 00001010, 00001010, 00001010, 00001010, 00001010) == 0xA0A0A0A0A0A0A
*/
#define BIN56(bin1, bin2, bin3, bin4, bin5, bin6, bin7) ((Tsint64(BIN8(bin1)) << 48) + (Tsint64(BIN8(bin2)) << 40) + (Tsint64(BIN8(bin3)) << 32) + (Tsint64(BIN8(bin4)) << 24) + (Tsint64(BIN8(bin5)) << 16) + (Tsint64(BIN8(bin6)) << 8) + Tsint64(BIN8(bin7)))
/*!
    \def BIN64(bin1, bin2, bin3, bin4, bin5, bin6, bin7, bin8)
    Defines the binary converting macro. It gives  ability  to  convert  eight
    bytes from binary code to the number of eight bytes type.
    For example: BIN64(00001010, 00001010, 00001010, 00001010, 00001010, 00001010, 00001010, 00001010) == 0xA0A0A0A0A0A0A0A
*/
#define BIN64(bin1, bin2, bin3, bin4, bin5, bin6, bin7, bin8) ((Tsint64(BIN8(bin1)) << 56) + (Tsint64(BIN8(bin2)) << 48) + (Tsint64(BIN8(bin3)) << 40) + (Tsint64(BIN8(bin4)) << 32) + (Tsint64(BIN8(bin5)) << 24) + (Tsint64(BIN8(bin6)) << 16) + (Tsint64(BIN8(bin7)) << 8) + Tsint64(BIN8(bin8)))
/*==========================================================================*/
#endif
