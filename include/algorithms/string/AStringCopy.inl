/*!
 *  \file    AStringCopy.inl Contains general template implementation of the
 *           string copy algorithm.
 *  \brief   Algorithm to copy the given source string into the destination one (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to copy the given source string into the destination one (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   30.11.2009 23:37:54

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
#ifndef __ASTRINGCOPY_INL__
#define __ASTRINGCOPY_INL__
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
template <typename T_StringType1, typename T_StringType2>
inline Tuint stringCopy(T_StringType1& a_rDestination, const T_StringType2& a_crSource)
{ CALL
  return stringCopy(a_rDestination, 0, NConstants::CConstants::uintMax, a_crSource, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <typename T_StringType1, typename T_StringType2>
inline Tuint stringCopy(T_StringType1& a_rDestination, const Tuint a_cDestinationLength, const T_StringType2& a_crSource, const Tuint a_cSourceLength)
{ CALL
  return stringCopy(a_rDestination, 0, a_cDestinationLength, a_crSource, 0, a_cSourceLength);
}
/*--------------------------------------------------------------------------*/
template <typename T_StringType1, typename T_StringType2>
inline Tuint stringCopy(T_StringType1& a_rDestination, const Tuint a_cDestinationIndex, const Tuint a_cDestinationLength, const T_StringType2& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  // Check T_StringType1 template argument constraint to be a non constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptString<T_StringType1> >();
  // Check T_StringType2 template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType2> >();

  Tuint length1 = stringLength(a_rDestination, a_cDestinationIndex, a_cDestinationLength);
  Tuint length2 = stringLength(a_crSource, a_cSourceIndex, a_cSourceLength);
  Tuint length = NCommon::min(length1, length2);

  Tuint count = 0;
  Tuint index1 = a_cDestinationIndex;
  Tuint index2 = a_cSourceIndex;

  while (count < length)
  {
    ++count;
    a_rDestination[index1++] = a_crSource[index2++];
  }

  return count;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
