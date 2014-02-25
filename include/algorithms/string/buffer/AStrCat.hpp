/*!
 *  \file    AStrCat.hpp Contains general template implementation of the
 *           append one string to another one.
 *  \brief   Concatenate two strings algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Concatenate two strings algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   01.04.2008 03:50:07

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
#ifndef __ASTRCAT_HPP__
#define __ASTRCAT_HPP__
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptString.hpp>
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
//! Algorithm: Concatenate two strings.
/*!
    Append content of the one string to another one, including the terminating
    '\\0' character.

    \param a_rDstString - Reference to the destination string.
    \param a_crSrcString - Constant reference to the source string.
    \return The count of the appended characters.
    \see NDepth::NAlgorithms::NString::strNCat()
*/
template <typename T_StringType1, typename T_StringType2>
Tuint strCat(T_StringType1& a_rDstString, const T_StringType2& a_crSrcString);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/buffer/AStrCat.inl>
/*==========================================================================*/
#endif
