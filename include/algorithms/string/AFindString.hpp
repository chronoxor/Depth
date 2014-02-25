/*!
 *  \file    AFindString.hpp Contains general template implementation of
 *           the algorithm to find (sub)string in the given string object
 *           using Brute Force searching algorithm.
 *  \brief   Algorithm to find (sub)string in the given string using Brute Force searching algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.12.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find (sub)string in the given string using Brute Force searching algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   03.12.2009 20:04:19

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
#ifndef __AFINDSTRING_HPP__
#define __AFINDSTRING_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/AStringLength.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
#include <Depth/include/string/CCharacter.hpp>
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
//! Algorithm: Find (sub)string in the given string using Brute Force searching algorithm.
/*!
    Find  (sub)string  in  the  given  string  using  Brute  Force   searching
    algorithm.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundStart - Reference to the found start index position.
    \param a_rFoundEnd - Reference to the found end index position.
    \param a_crSource - Constant reference to the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \return true  - if (sub)string was found. \n
            false - if (sub)string was not found. \n
*/
template <typename T_SourceStringType, typename T_PatternStringType>
Tbool findString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const T_PatternStringType& a_crPattern);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find (sub)string in the given string using Brute Force searching algorithm (maximal length version).
/*!
    Find  (sub)string  in  the  given  string  using  Brute  Force   searching
    algorithm.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundStart - Reference to the found start index position.
    \param a_rFoundEnd - Reference to the found end index position.
    \param a_crSource - Constant reference to the source string.
    \param a_cSourceLength - Maximal length value of the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_cPatternLength - Maximal length value of the pattern string.
    \return true  - if (sub)string was found. \n
            false - if (sub)string was not found. \n
*/
template <typename T_SourceStringType, typename T_PatternStringType>
Tbool findString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find (sub)string in the given string using Brute Force searching algorithm (index offset and maximal length version).
/*!
    Find  (sub)string  in  the  given  string  using  Brute  Force   searching
    algorithm.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundStart - Reference to the found start index position.
    \param a_rFoundEnd - Reference to the found end index position.
    \param a_crSource - Constant reference to the source string.
    \param a_cSourceIndex - Index offset value of the source string.
    \param a_cSourceLength - Maximal length value of the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_cPatternIndex - Index offset value of the pattern string.
    \param a_cPatternLength - Maximal length value of the pattern string.
    \return true  - if (sub)string was found. \n
            false - if (sub)string was not found. \n
*/
template <typename T_SourceStringType, typename T_PatternStringType>
Tbool findString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/AFindString.inl>
/*==========================================================================*/
#endif
