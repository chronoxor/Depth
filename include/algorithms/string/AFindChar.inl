/*!
 *  \file    AFindChar.inl Contains general template implementation of the
 *           algorithm to find given character in the given string.
 *  \brief   Algorithm to find character in the given string (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find character in the given string (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   21.04.2009 22:22:16

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
#ifndef __AFINDCHAR_INL__
#define __AFINDCHAR_INL__
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
template <typename T_StringType, typename T_CharacterType>
inline Tbool findChar(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const T_CharacterType& a_crCharacter)
{ CALL
  if (a_cReverseSearch)
    return findChar(a_cReverseSearch, a_cIgnoreCase, a_rFoundIndex, a_crString, NConstants::CConstants::uintMax, NConstants::CConstants::uintMax, a_crCharacter);
  else
    return findChar(a_cReverseSearch, a_cIgnoreCase, a_rFoundIndex, a_crString, 0, NConstants::CConstants::uintMax, a_crCharacter);
}
/*--------------------------------------------------------------------------*/
template <typename T_StringType, typename T_CharacterType>
inline Tbool findChar(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const Tuint a_cStringLength, const T_CharacterType& a_crCharacter)
{ CALL
  if (a_cReverseSearch)
    return findChar(a_cReverseSearch, a_cIgnoreCase, a_rFoundIndex, a_crString, NConstants::CConstants::uintMax, a_cStringLength, a_crCharacter);
  else
    return findChar(a_cReverseSearch, a_cIgnoreCase, a_rFoundIndex, a_crString, 0, a_cStringLength, a_crCharacter);
}
/*--------------------------------------------------------------------------*/
template <typename T_StringType, typename T_CharacterType>
inline Tbool findChar(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const Tuint a_cStringIndex, const Tuint a_cStringLength, const T_CharacterType& a_crCharacter)
{ CALL
  // Check T_StringType template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType> >();
  // Check T_CharacterType template argument constraint to be a character.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptChar<T_CharacterType> >();

  if (a_cReverseSearch)
  {
    Tuint index = NCommon::min((a_cStringIndex < NConstants::CConstants::uintMax) ? (a_cStringIndex + 1) : a_cStringIndex, stringLength(a_crString));
    Tuint length = NCommon::min(index, a_cStringLength);

    if (a_cIgnoreCase)
    {
      while (length-- > 0)
      {
        if (NDepth::NString::CCharacter(a_crString[--index]).toLowerCase() == NDepth::NString::CCharacter(a_crCharacter).toLowerCase())
        {
          a_rFoundIndex = index;
          return true;
        }
      }
    }
    else
    {
      while (length-- > 0)
      {
        if (((typename NTraits::MTraitsString<T_StringType>::ucharacter)a_crString[--index]) == ((typename NTraits::MTraitsCharacter<T_CharacterType>::ucharacter)a_crCharacter))
        {
          a_rFoundIndex = index;
          return true;
        }
      }
    }
    return false;
  }
  else
  {
    Tuint index = a_cStringIndex;
    Tuint length = stringLength(a_crString, a_cStringIndex, a_cStringLength);

    if (a_cIgnoreCase)
    {
      while (index < length)
      {
        if (NDepth::NString::CCharacter(a_crString[index]).toLowerCase() == NDepth::NString::CCharacter(a_crCharacter).toLowerCase())
        {
          a_rFoundIndex = index;
          return true;
        }
        ++index;
      }
    }
    else
    {
      while (index < length)
      {
        if (((typename NTraits::MTraitsString<T_StringType>::ucharacter)a_crString[index]) == ((typename NTraits::MTraitsCharacter<T_CharacterType>::ucharacter)a_crCharacter))
        {
          a_rFoundIndex = index;
          return true;
        }
        ++index;
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
