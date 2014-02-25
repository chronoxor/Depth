/*!
 *  \file    AFindChar.hpp Contains general template implementation of the
 *           algorithm to find given character in the given string.
 *  \brief   Algorithm to find character in the given string.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find character in the given string.

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
#ifndef __AFINDCHAR_HPP__
#define __AFINDCHAR_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/algorithms/string/AStringLength.hpp>
#include <Depth/include/concept/base/MConceptChar.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
#include <Depth/include/traits/MTraitsCharacter.hpp>
#include <Depth/include/traits/MTraitsString.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Find character in the given string.
/*!
    Find first character position in the given string.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundIndex - Reference to the found position index.
    \param a_crString - Constant reference to the string.
    \param a_crCharacter - Constant reference to the searching character.
    \return true  - if the given character was found. \n
            false - if the given character was not found. \n
*/
template <typename T_StringType, typename T_CharacterType>
Tbool findChar(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const T_CharacterType& a_crCharacter);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find character in the given string (maximal length version).
/*!
    Find first character position in the given string.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundIndex - Reference to the found position index.
    \param a_crString - Constant reference to the string.
    \param a_cStringLength - Maximal length value of the string.
    \param a_crCharacter - Constant reference to the searching character.
    \return true  - if the given character was found. \n
            false - if the given character was not found. \n
*/
template <typename T_StringType, typename T_CharacterType>
Tbool findChar(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const Tuint a_cStringLength, const T_CharacterType& a_crCharacter);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find character in the given string (index offset and maximal length version).
/*!
    Find first character position in the given string.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundIndex - Reference to the found position index.
    \param a_crString - Constant reference to the string.
    \param a_cStringIndex - Index offset value of the string.
    \param a_cStringLength - Maximal length value of the string starting from offset.
    \param a_crCharacter - Constant reference to the searching character.
    \return true  - if the given character was found. \n
            false - if the given character was not found. \n
*/
template <typename T_StringType, typename T_CharacterType>
Tbool findChar(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const Tuint a_cStringIndex, const Tuint a_cStringLength, const T_CharacterType& a_crCharacter);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/AFindChar.inl>
/*==========================================================================*/
#endif
