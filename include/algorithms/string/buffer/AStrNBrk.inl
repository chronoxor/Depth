/*!
 *  \file    AStrNBrk.inl Contains general template implementation of the
 *           find break position in the fixed-size string.
 *  \brief   Find break position in the fixed-size string algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find break position in the fixed-size string algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   28.03.2008 21:32:45

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
#ifndef __ASTRNBRK_INL__
#define __ASTRNBRK_INL__
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
inline Tsint strNBrk(const T_StringType1& a_crString, const Tuint a_cMaxLength, const T_StringType2& a_crCharSet)
{ CALL
  // Check T_StringType1 template argument constraint to be a constant string.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType1> >();
  // Check T_StringType2 template argument constraint to be a constant string.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType2> >();

  // Check the given string not to be NULL.
  ASSERT(((Tcptr)a_crString != NULL), STR("Algorithm 'strnbrk()' cannot work with a NULL string."))
  {
    return -1;
  }
  // Check the given character set not to be NULL.
  ASSERT(((Tcptr)a_crCharSet != NULL), STR("Algorithm 'strnbrk()' cannot work with a NULL character set."))
  {
    return 0;
  }

  Tuint index = 0;
  Tuint indexSet = 0;

  while ((a_crString[index] != 0) && (index < a_cMaxLength))
  {
    indexSet = 0;
    while (a_crCharSet[indexSet] != 0)
    {
      if (((typename NTraits::MTraitsString<T_StringType1>::ucharacter)a_crString[index]) == ((typename NTraits::MTraitsString<T_StringType2>::ucharacter)a_crCharSet[indexSet]))
        return (Tsint)index;
      ++indexSet;
    }
    ++index;
  }
  return -1;
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
