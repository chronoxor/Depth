/*!
 *  \file    AStrCmp.inl Contains general template implementation of the
 *           case-sensitive compare of two strings.
 *  \brief   Case-sensitive compare of two strings algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Case-sensitive compare of two strings algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   31.03.2008 22:26:52

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
#ifndef __ASTRCMP_INL__
#define __ASTRCMP_INL__
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
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_StringType1, typename T_StringType2>
inline Tsint strCmp(const T_StringType1& a_crString1, const T_StringType2& a_crString2)
{ CALL
  // Check T_StringType1 template argument constraint to be a constant string.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType1> >();
  // Check T_StringType2 template argument constraint to be a constant string.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType2> >();

  // Check the given first string not to be NULL.
  ASSERT(((Tcptr)a_crString1 != NULL), STR("Algorithm 'strcmp()' cannot work with a NULL first string."))
  {
    return -1;
  }
  // Check the given second string not to be NULL.
  ASSERT(((Tcptr)a_crString2 != NULL), STR("Algorithm 'strcmp()' cannot work with a NULL last string."))
  {
    return 1;
  }

  Tuint index = 0;
  Tsint result = 0;

  while (((result = (((typename NTraits::MTraitsString<T_StringType1>::ucharacter)a_crString1[index]) - ((typename NTraits::MTraitsString<T_StringType2>::ucharacter)a_crString2[index]))) == 0) && (a_crString1[index] != 0) && (a_crString2[index] != 0))
    ++index;
  return result;
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
