/*!
 *  \file    AStringLength.hpp Contains general template implementation of the
 *           algorithm to find length in characters of the given string.
 *  \brief   Algorithm to find length in characters of the given string.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find length in characters of the given string.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   30.11.2009 20:40:07

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
#ifndef __ASTRINGLENGTH_HPP__
#define __ASTRINGLENGTH_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/details/CStringLengthHelper.hpp>
#include <Depth/include/traits/MIsStringClass.hpp>
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
//! Algorithm: Find length in characters of the given string.
/*!
    Find length in characters of the given string based on  string  type:  'C'
    string buffer or string class.

    \param a_crString - Constant reference to the given string.
    \return Length of the given string in characters.
*/
template <typename T_StringType>
Tuint stringLength(const T_StringType& a_crString);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find minimal length in characters of the given string.
/*!
    Find length in characters of the given string based on  string  type:  'C'
    string buffer or string class and return minimal of found length  and  the
    given one.

    \param a_crString - Constant reference to the given string.
    \param a_cStringLength - Maximal string length value.
    \return Minimal length of the given string in characters.
*/
template <typename T_StringType>
Tuint stringLength(const T_StringType& a_crString, const Tuint a_cStringLength);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find minimal length in characters of the given string with an index offset.
/*!
    Find length in characters of the given string with an index  offset  based
    on string type: 'C' string buffer or string class and  return  minimal  of
    found length and the given one.

    \param a_crString - Constant reference to the given string.
    \param a_cStringIndex - String index offset value.
    \param a_cStringLength - Maximal string length value.
    \return Minimal length of the given string in characters starting from offset.
*/
template <typename T_StringType>
Tuint stringLength(const T_StringType& a_crString, const Tuint a_cStringIndex, const Tuint a_cStringLength);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/AStringLength.inl>
/*==========================================================================*/
#endif
