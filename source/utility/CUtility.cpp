/*!
 *  \file    CUtility.cpp Utility class contains common functionality for
 *           various programming aims.
 *  \brief   Static class with utility functionality (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class with utility functionality (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   04.01.2006 01:12:24

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#include <Depth/include/utility/CUtility.hpp>
/*==========================================================================*/
#ifndef __CUTILITY_CPP__
#define __CUTILITY_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tuint32 CUtility::reverseBytes(const Tuint32 a_cX)
{ CALL
  Tuint32 temp = a_cX;
  temp = ((temp & 0xFF00FF00) >> 8) | ((temp & 0x00FF00FF) << 8);
  return NAlgorithms::NNumeric::cyclicRotateLeft(temp, 16);
}
/*--------------------------------------------------------------------------*/
Tuint64 CUtility::reverseBytes(const Tuint64 a_cX)
{ CALL
  Tuint64 temp = a_cX;
  temp = ((temp & 0xFF00FF00FF00FF00ll) >>  8) | ((temp & 0x00FF00FF00FF00FFll) <<  8);
  temp = ((temp & 0xFFFF0000FFFF0000ll) >> 16) | ((temp & 0x0000FFFF0000FFFFll) << 16);
  return NAlgorithms::NNumeric::cyclicRotateLeft(temp, 32);
}
/*--------------------------------------------------------------------------*/
Tuint08 CUtility::reverseBits(const Tuint08 a_cX)
{ CALL
  Tuint08 temp = a_cX;
  temp = ((temp&0xAA)>>1)|((temp&0x55)<<1);
  temp = ((temp&0xCC)>>2)|((temp&0x33)<<2);
  return NAlgorithms::NNumeric::cyclicRotateLeft(temp, 4);
}
/*--------------------------------------------------------------------------*/
Tuint16 CUtility::reverseBits(const Tuint16 a_cX)
{ CALL
  Tuint16 temp = a_cX;
  temp = ((temp & 0xAAAA) >> 1) | ((temp & 0x5555) << 1);
  temp = ((temp & 0xCCCC) >> 2) | ((temp & 0x3333) << 2);
  temp = ((temp & 0xF0F0) >> 4) | ((temp & 0x0F0F) << 4);
  return CUtility::reverseBytes(temp);
}
/*--------------------------------------------------------------------------*/
Tuint32 CUtility::reverseBits(const Tuint32 a_cX)
{ CALL
  Tuint32 temp = a_cX;
  temp = ((temp & 0xAAAAAAAA) >> 1) | ((temp & 0x55555555) << 1);
  temp = ((temp & 0xCCCCCCCC) >> 2) | ((temp & 0x33333333) << 2);
  temp = ((temp & 0xF0F0F0F0) >> 4) | ((temp & 0x0F0F0F0F) << 4);
  return CUtility::reverseBytes(temp);
}
/*--------------------------------------------------------------------------*/
Tuint64 CUtility::reverseBits(const Tuint64 a_cX)
{ CALL
  Tuint64 temp = a_cX;
  temp = ((temp & 0xAAAAAAAAAAAAAAAAll) >> 1) | ((temp & 0x5555555555555555ll) << 1);
  temp = ((temp & 0xCCCCCCCCCCCCCCCCll) >> 2) | ((temp & 0x3333333333333333ll) << 2);
  temp = ((temp & 0xF0F0F0F0F0F0F0F0ll) >> 4) | ((temp & 0x0F0F0F0F0F0F0F0Fll) << 4);
  return CUtility::reverseBytes(temp);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
