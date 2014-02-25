/*!
 *  \file    CUtility.inl Utility class contains common functionality for
 *           various programming aims.
 *  \brief   Static class with utility functionality (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class with utility functionality (inline).

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
#ifndef __CUTILITY_INL__
#define __CUTILITY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline Tuint16 CUtility::makeInteger(const Tbyte a_cByte1, const Tbyte a_cByte2)
{ CALL
  return (Tuint16)(((Tuint16)a_cByte1 << 8) | a_cByte2);
}
/*--------------------------------------------------------------------------*/
inline Tuint32 CUtility::makeInteger(const Tbyte a_cByte1, const Tbyte a_cByte2, const Tbyte a_cByte3, const Tbyte a_cByte4)
{ CALL
  return (Tuint32)(((Tuint32)a_cByte1 << 24) | ((Tuint32)a_cByte2 << 16) | ((Tuint32)a_cByte3 << 8) | a_cByte4);
}
/*--------------------------------------------------------------------------*/
inline Tuint64 CUtility::makeInteger(const Tbyte a_cByte1, const Tbyte a_cByte2, const Tbyte a_cByte3, const Tbyte a_cByte4, const Tbyte a_cByte5, const Tbyte a_cByte6, const Tbyte a_cByte7, const Tbyte a_cByte8)
{ CALL
  return (Tuint64)(((Tuint64)a_cByte1 << 56) | ((Tuint64)a_cByte2 << 48) | ((Tuint64)a_cByte3 << 40) | ((Tuint64)a_cByte4 << 32) | ((Tuint64)a_cByte5 << 24) | ((Tuint64)a_cByte6 << 16) | ((Tuint64)a_cByte7 << 8) | a_cByte8);
}
/*--------------------------------------------------------------------------*/
inline Tuint16 CUtility::reverseBytes(const Tuint16 a_cX)
{ CALL
  return NAlgorithms::NNumeric::cyclicRotateLeft(a_cX, 8);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
