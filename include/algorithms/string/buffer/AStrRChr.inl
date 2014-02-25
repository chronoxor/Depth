/*!
 *  \file    AStrRChr.inl Contains general template implementation of the
 *           find last character position in the string.
 *  \brief   Find lasr character position in the string algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find last character position in the string algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   28.03.2008 22:47:32

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
#ifndef __ASTRRCHR_INL__
#define __ASTRRCHR_INL__
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
template <typename T_StringType, typename T_CharacterType>
inline Tsint strRChr(const T_StringType& a_crString, const T_CharacterType& a_crCharacter)
{ CALL
  // Check T_StringType template argument constraint to be a constant string.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType> >();
  // Check T_CharacterType template argument constraint to be a character.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptChar<T_CharacterType> >();

  // Check the given string not to be NULL.
  ASSERT(((Tcptr)a_crString != NULL), STR("Algorithm 'strrchr()' cannot work with a NULL string."))
  {
    return -1;
  }

  Tuint index = 0;
  Tsint result = -1;

  while (a_crString[index] != 0)
  {
    if (((typename NTraits::MTraitsString<T_StringType>::ucharacter)a_crString[index]) == ((typename NTraits::MTraitsCharacter<T_CharacterType>::ucharacter)a_crCharacter))
      result = (Tsint)index;
    ++index;
  }
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
