/*!
 *  \file    AStringCompareIgnoreCase.inl Contains general template
 *           implementation of the strings compare algorithm with ignore case.
 *  \brief   Algorithm to compare of the two given strings ignoring their cases (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to compare of the two given strings ignoring their cases (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   30.11.2009 22:52:04

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
#ifndef __ASTRINGCOMPAREIGNORECASE_INL__
#define __ASTRINGCOMPAREIGNORECASE_INL__
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
inline Tsint stringCompareIgnoreCase(const T_StringType1& a_crString1, const T_StringType2& a_crString2)
{ CALL
  return stringCompareIgnoreCase(a_crString1, 0, NConstants::CConstants::uintMax, a_crString2, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <typename T_StringType1, typename T_StringType2>
inline Tsint stringCompareIgnoreCase(const T_StringType1& a_crString1, const Tuint a_cString1Length, const T_StringType2& a_crString2, const Tuint a_cString2Length)
{ CALL
  return stringCompareIgnoreCase(a_crString1, 0, a_cString1Length, a_crString2, 0, a_cString2Length);
}
/*--------------------------------------------------------------------------*/
template <typename T_StringType1, typename T_StringType2>
inline Tsint stringCompareIgnoreCase(const T_StringType1& a_crString1, const Tuint a_cString1Index, const Tuint a_cString1Length, const T_StringType2& a_crString2, const Tuint a_cString2Index, const Tuint a_cString2Length)
{ CALL
  // Check T_StringType1 template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType1> >();
  // Check T_StringType2 template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType2> >();

  Tuint length1 = stringLength(a_crString1, a_cString1Index, a_cString1Length);
  Tuint length2 = stringLength(a_crString2, a_cString2Index, a_cString2Length);

  Tuint index1 = a_cString1Index;
  Tuint index2 = a_cString2Index;
  Tuint length = (length1 < length2) ? length1 : length2;
  Tsint sublength = (Tsint)(length1 - length2);
  Tsint result = 0;

  while ((length > 0) && ((result = (NDepth::NString::CCharacter(a_crString1[index1++]).toLowerCase() - NDepth::NString::CCharacter(a_crString2[index2++]).toLowerCase())) == 0))
    --length;

  if ((sublength == 0) || (length > 0))
    return result;
  else
    return sublength;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
