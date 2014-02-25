/*!
 *  \file    AFindCharOneOf.hpp Contains general template implementation of
 *           the algorithm to find one of the given characters in the given
 *           string object.
 *  \brief   Algorithm to find one of the given characters in the given string.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find one of the given characters in the given string.

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
#ifndef __AFINDCHARONEOF_HPP__
#define __AFINDCHARONEOF_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/algorithms/string/AStringLength.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
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
//! Algorithm: Find one of the given characters in the given string.
/*!
    Find one of the given characters in the given string.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundIndex - Reference to the found position index.
    \param a_crString - Constant reference to the string.
    \param a_crCharacterSet - Constant reference to the character set string.
    \return true  - if one of the given characters was found. \n
            false - if none of the given characters was found. \n
*/
template <typename T_StringType, typename T_CharacterSet>
Tbool findCharOneOf(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const T_CharacterSet& a_crCharacterSet);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find one of the given characters in the given string (maximal length version).
/*!
    Find one of the given characters in the given string.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundIndex - Reference to the found position index.
    \param a_crString - Constant reference to the string.
    \param a_cStringLength - Maximal length value of the string.
    \param a_crCharacterSet - Constant reference to the character set string.
    \param a_cCharacterSetLength - Maximal length value of the character set string.
    \return true  - if one of the given characters was found. \n
            false - if none of the given characters was found. \n
*/
template <typename T_StringType, typename T_CharacterSet>
Tbool findCharOneOf(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const Tuint a_cStringLength, const T_CharacterSet& a_crCharacterSet, const Tuint a_cCharacterSetLength);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find one of the given characters in the given string (index offset and maximal length version).
/*!
    Find one of the given characters in the given string.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundIndex - Reference to the found position index.
    \param a_crString - Constant reference to the string.
    \param a_cStringIndex - Index offset value of the string.
    \param a_cStringLength - Maximal length value of the string.
    \param a_crCharacterSet - Constant reference to the character set string.
    \param a_cCharacterSetIndex - Index offset value of the character set string.
    \param a_cCharacterSetLength - Maximal length value of the character set string.
    \return true  - if one of the given characters was found. \n
            false - if none of the given characters was found. \n
*/
template <typename T_StringType, typename T_CharacterSet>
Tbool findCharOneOf(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundIndex, const T_StringType& a_crString, const Tuint a_cStringIndex, const Tuint a_cStringLength, const T_CharacterSet& a_crCharacterSet, const Tuint a_cCharacterSetIndex, const Tuint a_cCharacterSetLength);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/AFindCharOneOf.inl>
/*==========================================================================*/
#endif
