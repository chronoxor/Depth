/*!
 *  \file    AStrCSpn.hpp Contains general template implementation of the
 *           calculate the length of the initial string segment which
 *           consists entirely of characters not from the given set.
 *  \brief   Calculate the length of the not included initial string segment algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Calculate the length of the not included initial string segment algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   31.03.2008 20:11:09

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
#ifndef __ASTRCSPN_HPP__
#define __ASTRCSPN_HPP__
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
//! Algorithm: Calculate the length of the not included initial string segment.
/*!
    Calculates the  length  of  the  initial  string  segment  which  consists
    entirely  of  characters  not  from  the  given  set,  not  including  the
    terminating '\\0' character.

    \param a_crString - Constant reference to the string.
    \param a_crCharSet - Constant reference to the character set string.
    \return The length of the not included initial string segment.
    \see NDepth::NAlgorithms::NString::strSpn()
    \see NDepth::NAlgorithms::NString::strNSpn()
    \see NDepth::NAlgorithms::NString::strNCSpn()
*/
template <typename T_StringType1, typename T_StringType2>
Tuint strCSpn(const T_StringType1& a_crString, const T_StringType2& a_crCharSet);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/buffer/AStrCSpn.inl>
/*==========================================================================*/
#endif
