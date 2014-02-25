/*!
 *  \file    AFindCharOneOf.inl Contains general template implementation of
 *           the algorithm to find one of the given characters in the given
 *           string object.
 *  \brief   Algorithm to find one of the given characters in the given string (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find one of the given characters in the given string (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   21.04.2009 23:59:17

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
#ifndef __AFINDCHARONEOF_INL__
#define __AFINDCHARONEOF_INL__
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
template <typename T_StringType, typename T_CharacterSet>
inline Tbool findCharOneOf(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const T_CharacterSet& a_crCharacterSet)
{ CALL
  if (a_cReverseSearch)
    return findCharOneOf(a_cReverseSearch, a_cIgnoreCase, a_rFoundIndex, a_crString, NConstants::CConstants::uintMax, NConstants::CConstants::uintMax, a_crCharacterSet, 0, NConstants::CConstants::uintMax);
  else
    return findCharOneOf(a_cReverseSearch, a_cIgnoreCase, a_rFoundIndex, a_crString, 0, NConstants::CConstants::uintMax, a_crCharacterSet, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <typename T_StringType, typename T_CharacterSet>
inline Tbool findCharOneOf(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const Tuint a_cStringLength, const T_CharacterSet& a_crCharacterSet, const Tuint a_cCharacterSetLength)
{ CALL
  if (a_cReverseSearch)
    return findCharOneOf(a_cReverseSearch, a_cIgnoreCase, a_rFoundIndex, a_crString, NConstants::CConstants::uintMax, a_cStringLength, a_crCharacterSet, 0, a_cCharacterSetLength);
  else
    return findCharOneOf(a_cReverseSearch, a_cIgnoreCase, a_rFoundIndex, a_crString, 0, a_cStringLength, a_crCharacterSet, 0, a_cCharacterSetLength);
}
/*--------------------------------------------------------------------------*/
template <typename T_StringType, typename T_CharacterSet>
inline Tbool findCharOneOf(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const Tuint a_cStringIndex, const Tuint a_cStringLength, const T_CharacterSet& a_crCharacterSet, const Tuint a_cCharacterSetIndex, const Tuint a_cCharacterSetLength)
{ CALL
  // Check T_StringType template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType> >();
  // Check T_CharacterSet template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_CharacterSet> >();

  if (a_cReverseSearch)
  {
    Tuint index1 = NCommon::min((a_cStringIndex < NConstants::CConstants::uintMax) ? (a_cStringIndex + 1) : a_cStringIndex, stringLength(a_crString));
    Tuint index2 = a_cCharacterSetIndex;
    Tuint length1 = NCommon::min(index1, a_cStringLength);
    Tuint length2 = stringLength(a_crCharacterSet, a_cCharacterSetIndex, a_cCharacterSetLength);

    if (a_cIgnoreCase)
    {
      while (length1-- > 0)
      {
        --index1;
        index2 = a_cCharacterSetIndex;
        while (index2 < length2)
        {
          if (NDepth::NString::CCharacter(a_crString[index1]).toLowerCase() == NDepth::NString::CCharacter(a_crCharacterSet[index2]).toLowerCase())
          {
            a_rFoundIndex = index1;
            return true;
          }
          ++index2;
        }
      }
    }
    else
    {
      while (length1-- > 0)
      {
        --index1;
        index2 = a_cCharacterSetIndex;
        while (index2 < length2)
        {
          if (((typename NTraits::MTraitsString<T_StringType>::ucharacter)a_crString[index1]) == ((typename NTraits::MTraitsString<T_CharacterSet>::ucharacter)a_crCharacterSet[index2]))
          {
            a_rFoundIndex = index1;
            return true;
          }
          ++index2;
        }
      }
    }
    return false;
  }
  else
  {
    Tuint index1 = a_cStringIndex;
    Tuint index2 = a_cCharacterSetIndex;
    Tuint length1 = stringLength(a_crString, a_cStringIndex, a_cStringLength);;
    Tuint length2 = stringLength(a_crCharacterSet, a_cCharacterSetIndex, a_cCharacterSetLength);

    if (a_cIgnoreCase)
    {
      while (index1 < length1)
      {
        index2 = a_cCharacterSetIndex;
        while (index2 < length2)
        {
          if (NDepth::NString::CCharacter(a_crString[index1]).toLowerCase() == NDepth::NString::CCharacter(a_crCharacterSet[index2]).toLowerCase())
          {
            a_rFoundIndex = index1;
            return true;
          }
          ++index2;
        }
        ++index1;
      }
    }
    else
    {
      while (index1 < length1)
      {
        index2 = a_cCharacterSetIndex;
        while (index2 < length2)
        {
          if (((typename NTraits::MTraitsString<T_StringType>::ucharacter)a_crString[index1]) == ((typename NTraits::MTraitsString<T_CharacterSet>::ucharacter)a_crCharacterSet[index2]))
          {
            a_rFoundIndex = index1;
            return true;
          }
          ++index2;
        }
        ++index1;
      }
    }
    return false;
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
