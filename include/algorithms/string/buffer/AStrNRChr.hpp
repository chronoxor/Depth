/*!
 *  \file    AStrNRChr.hpp Contains general template implementation of the
 *           find last character position in the fixed-size string.
 *  \brief   Find lasr character position in the fixed-size string algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find last character position in the fixed-size string algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   28.03.2008 22:52:12

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
#ifndef __ASTRNRCHR_HPP__
#define __ASTRNRCHR_HPP__
/*==========================================================================*/
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
/*--------------------------------------------------------------------------*/
namespace NBuffer {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Find last character position in the fixed-size string.
/*!
    Find last character position in the fixed-size string, not  including  the
    terminating '\\0' character, but at most maximum length.

    \param a_crString - Constant reference to the string.
    \param a_cMaxLength - Maximum length of the string.
    \param a_crCharacter - Constant reference to the searching character.
    \return Index of the last character position or -1 if the last character position does not exist.
    \see NDepth::NAlgorithms::NString::strChr()
    \see NDepth::NAlgorithms::NString::strRChr()
    \see NDepth::NAlgorithms::NString::strNChr()
*/
template <typename T_StringType, typename T_CharacterType>
Tsint strNRChr(const T_StringType& a_crString, const Tuint a_cMaxLength, const T_CharacterType& a_crCharacter);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/buffer/AStrNRChr.inl>
/*==========================================================================*/
#endif
