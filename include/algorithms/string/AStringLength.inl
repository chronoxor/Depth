/*!
 *  \file    AStringLength.inl Contains general template implementation of the
 *           algorithm to find length in characters of the given string.
 *  \brief   Algorithm to find length in characters of the given string (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find length in characters of the given string (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   30.11.2009 20:40:07

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
#ifndef __ASTRINGLENGTH_INL__
#define __ASTRINGLENGTH_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_StringType>
inline Tuint stringLength(const T_StringType& a_crString)
{ CALL
  return NDetails::CStringLengthHelper<NTraits::MIsStringClass<T_StringType>::yes>::stringLength(a_crString, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <typename T_StringType>
inline Tuint stringLength(const T_StringType& a_crString, const Tuint a_cStringLength)
{ CALL
  return NDetails::CStringLengthHelper<NTraits::MIsStringClass<T_StringType>::yes>::stringLength(a_crString, 0, a_cStringLength);
}
/*--------------------------------------------------------------------------*/
template <typename T_StringType>
inline Tuint stringLength(const T_StringType& a_crString, const Tuint a_cStringIndex, const Tuint a_cStringLength)
{ CALL
  return NDetails::CStringLengthHelper<NTraits::MIsStringClass<T_StringType>::yes>::stringLength(a_crString, a_cStringIndex, a_cStringLength);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
