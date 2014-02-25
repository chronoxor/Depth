/*!
 *  \file    AStrCmp.hpp Contains general template implementation of the
 *           case-sensitive compare of two strings.
 *  \brief   Case-sensitive compare of two strings algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Case-sensitive compare of two strings algorithm.

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
#ifndef __ASTRCMP_HPP__
#define __ASTRCMP_HPP__
/*==========================================================================*/
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
/*--------------------------------------------------------------------------*/
namespace NBuffer {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Case-sensitive compare of two strings algorithm.
/*!
    Case-sensitive compare two strings, not  including  the  terminating '\\0'
    character.  Algorithm  returns  difference  between   two   first   differ
    characters from the first string and the second one.

    \param a_crString1 - Constant reference to the first string.
    \param a_crString2 - Constant reference to the second string.
    \return One of the following values: \n
            <0 - if the first string is lexicographically less than the second one. \n
            =0 - two strings are equal. \n
            >0 - if the first string is lexicographically great than the second one. \n
    \see NDepth::NAlgorithms::NString::strICmp()
    \see NDepth::NAlgorithms::NString::strNCmp()
    \see NDepth::NAlgorithms::NString::strNICmp()
*/
template <typename T_StringType1, typename T_StringType2>
Tsint strCmp(const T_StringType1& a_crString1, const T_StringType2& a_crString2);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/buffer/AStrCmp.inl>
/*==========================================================================*/
#endif
