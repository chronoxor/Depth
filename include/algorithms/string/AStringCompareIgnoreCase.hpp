/*!
 *  \file    AStringCompareIgnoreCase.hpp Contains general template
 *           implementation of the strings compare algorithm with ignore case.
 *  \brief   Algorithm to compare of the two given strings ignoring their cases.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to compare of the two given strings ignoring their cases.

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
#ifndef __ASTRINGCOMPAREIGNORECASE_HPP__
#define __ASTRINGCOMPAREIGNORECASE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/AStringLength.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
#include <Depth/include/string/CCharacter.hpp>
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
//! Algorithm: Compare two strings ignoring their cases.
/*!
    Algorithm returns value less than 0 if the first string  lexicographically
    less than the second one. Algorithm returns value  great  than  0  if  the
    first string  lexicographically  great  than  the  second  one.  Algorithm
    returns 0 if the first string lexicographically equals to the second one.

    If sizes of the strings are different, algorithm  returns  the  difference
    between the first string size and the second one.

    If sizes of the  strings  are  equal,  algorithm  returns  the  difference
    between the first two different characters in lowercase on a same place in
    the strings.

    \param a_crString1 - Constant reference to the first string.
    \param a_crString2 - Constant reference to the second string.
    \return One of the following values: \n
            <0 - if the first string is lexicographically less than the second one. \n
            =0 - two strings are equal. \n
            >0 - if the first string is lexicographically great than the second one. \n
*/
template <typename T_StringType1, typename T_StringType2>
Tsint stringCompareIgnoreCase(const T_StringType1& a_crString1, const T_StringType2& a_crString2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Compare two strings ignoring their cases (maximal length version).
/*!
    Algorithm returns value less than 0 if the first string  lexicographically
    less than the second one. Algorithm returns value  great  than  0  if  the
    first string  lexicographically  great  than  the  second  one.  Algorithm
    returns 0 if the first string lexicographically equals to the second one.

    If sizes of the strings are different, algorithm  returns  the  difference
    between the first string size and the second one.

    If sizes of the  strings  are  equal,  algorithm  returns  the  difference
    between the first two different characters in lowercase on a same place in
    the strings.

    \param a_crString1 - Constant reference to the first string.
    \param a_cString1Length - Maximal destination length value of the first string.
    \param a_crString2 - Constant reference to the second string.
    \param a_cString2Length - Maximal destination length value of the second string.
    \return One of the following values: \n
            <0 - if the first string is lexicographically less than the second one. \n
            =0 - two strings are equal. \n
            >0 - if the first string is lexicographically great than the second one. \n
*/
template <typename T_StringType1, typename T_StringType2>
Tsint stringCompareIgnoreCase(const T_StringType1& a_crString1, const Tuint a_cString1Length, const T_StringType2& a_crString2, const Tuint a_cString2Length);
/*--------------------------------------------------------------------------*/
//! Algorithm: Compare two strings ignoring their cases (index offset and maximal length version).
/*!
    Algorithm returns value less than 0 if the first string  lexicographically
    less than the second one. Algorithm returns value  great  than  0  if  the
    first string  lexicographically  great  than  the  second  one.  Algorithm
    returns 0 if the first string lexicographically equals to the second one.

    If sizes of the strings are different, algorithm  returns  the  difference
    between the first string size and the second one.

    If sizes of the  strings  are  equal,  algorithm  returns  the  difference
    between the first two different characters in lowercase on a same place in
    the strings.

    \param a_crString1 - Constant reference to the first string.
    \param a_cString1Index - Index offset value of the first string.
    \param a_cString1Length - Maximal destination length value of the first string starting from offset.
    \param a_crString2 - Constant reference to the second string.
    \param a_cString2Index - Index offset value of the second string.
    \param a_cString2Length - Maximal destination length value of the second string starting from offset.
    \return One of the following values: \n
            <0 - if the first string is lexicographically less than the second one. \n
            =0 - two strings are equal. \n
            >0 - if the first string is lexicographically great than the second one. \n
*/
template <typename T_StringType1, typename T_StringType2>
Tsint stringCompareIgnoreCase(const T_StringType1& a_crString1, const Tuint a_cString1Index, const Tuint a_cString1Length, const T_StringType2& a_crString2, const Tuint a_cString2Index, const Tuint a_cString2Length);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/AStringCompareIgnoreCase.inl>
/*==========================================================================*/
#endif
