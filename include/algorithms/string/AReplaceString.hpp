/*!
 *  \file    AReplaceString.hpp Contains general template implementation of
 *           the algorithm to find and replace (sub)string in the given string
 *           object using Brute Force searching algorithm.
 *  \brief   Algorithm to find and replace (sub)string in the given string using Brute Force searching algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find and replace (sub)string in the given string using Brute Force searching algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   11.01.2010 20:42:42

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
#ifndef __AREPLACESTRING_HPP__
#define __AREPLACESTRING_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/AFindString.hpp>
#include <Depth/include/algorithms/string/details/CStringSearchHelper.hpp>
#include <Depth/include/concept/types/MConceptIString.hpp>
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
//! Algorithm: Find and replace (sub)string in the given string using Brute Force searching algorithm.
/*!
    Find and replace  (sub)string  in  the  given  string  using  Brute  Force
    searching algorithm.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundStart - Reference to the found start index position.
    \param a_rFoundEnd - Reference to the found end index position.
    \param a_rSource - Reference to the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_crReplacePattern - Constant reference to the replace pattern string.
    \return true  - if (sub)string was successfully found and replaced. \n
            false - if (sub)string was not successfully found and replaced. \n
*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType>
Tbool replaceString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const T_PatternStringType& a_crPattern, const T_ReplacePatternStringType& a_crReplacePattern);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find and replace (sub)string in the given string using Brute Force searching algorithm (maximal length version).
/*!
    Find and replace  (sub)string  in  the  given  string  using  Brute  Force
    searching algorithm.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundStart - Reference to the found start index position.
    \param a_rFoundEnd - Reference to the found end index position.
    \param a_rSource - Reference to the source string.
    \param a_cSourceLength - Maximal length value of the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_cPatternLength - Maximal length value of the pattern string.
    \param a_crReplacePattern - Constant reference to the replace pattern string.
    \param a_cReplacePatternLength - Maximal length value of the replace pattern string.
    \return true  - if (sub)string was successfully found and replaced. \n
            false - if (sub)string was not successfully found and replaced. \n
*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType>
Tbool replaceString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternLength);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find and replace (sub)string in the given string using Brute Force searching algorithm (index offset and maximal length version).
/*!
    Find and replace  (sub)string  in  the  given  string  using  Brute  Force
    searching algorithm.

    \param a_cReverseSearch - Reverse search flag.
    \param a_cIgnoreCase - Ignore case comparison flag.
    \param a_rFoundStart - Reference to the found start index position.
    \param a_rFoundEnd - Reference to the found end index position.
    \param a_rSource - Reference to the source string.
    \param a_cSourceIndex - Index offset value of the source string.
    \param a_cSourceLength - Maximal length value of the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_cPatternIndex - Index offset value of the pattern string.
    \param a_cPatternLength - Maximal length value of the pattern string.
    \param a_crReplacePattern - Constant reference to the replace pattern string.
    \param a_cReplacePatternIndex - Index offset value of the replace pattern string.
    \param a_cReplacePatternLength - Maximal length value of the replace pattern string.
    \return true  - if (sub)string was successfully found and replaced. \n
            false - if (sub)string was not successfully found and replaced. \n
*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType>
Tbool replaceString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternIndex, const Tuint a_cReplacePatternLength);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/AReplaceString.inl>
/*==========================================================================*/
#endif
