/*!
 *  \file    AStrNRStr.hpp Contains general template implementation of the
 *           find last occurrence of the substring in the fixed-size string.
 *  \brief   Find last occurrence of the substring in the fixed-size string algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find last occurrence of the substring in the fixed-size string algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   28.03.2008 21:01:37

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
#ifndef __ASTRNRSTR_HPP__
#define __ASTRNRSTR_HPP__
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
//! Algorithm: Find last occurrence of the substring in the fixed-size string.
/*!
    Find last occurrence of  the  substring  in  the  fixed-size  string,  not
    including the terminating '\\0' character, but at most maximum length.

    \param a_crString - Constant reference to the string.
    \param a_cMaxLength - Maximum length of the string.
    \param a_crSubstring - Constant reference to the searching string.
    \return Index of the last occurrence of the substring or -1 if the fixed-size string does not contain given substring.
    \see NDepth::NAlgorithms::NString::strStr()
    \see NDepth::NAlgorithms::NString::strRStr()
    \see NDepth::NAlgorithms::NString::strNStr()
*/
template <typename T_StringType1, typename T_StringType2>
Tsint strNRStr(const T_StringType1& a_crString, const Tuint a_cMaxLength, const T_StringType2& a_crSubstring);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/buffer/AStrNRStr.inl>
/*==========================================================================*/
#endif
