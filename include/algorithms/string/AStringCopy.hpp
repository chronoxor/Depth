/*!
 *  \file    AStringCopy.hpp Contains general template implementation of the
 *           string copy algorithm.
 *  \brief   Algorithm to copy the given source string into the destination one.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to copy the given source string into the destination one.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   30.11.2009 23:37:54

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
#ifndef __ASTRINGCOPY_HPP__
#define __ASTRINGCOPY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/algorithms/string/AStringLength.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
#include <Depth/include/concept/base/MConceptString.hpp>
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
//! Algorithm: Compare two strings taken into account their cases.
/*!
    Algorithm copies the given source string into the destination  one  taking
    into account minimal length of two strings.

    \param a_rDestination - Reference to the destination string.
    \param a_crSource - Constant reference to the destination string.
    \return Count of copied characters.
*/
template <typename T_StringType1, typename T_StringType2>
Tuint stringCopy(T_StringType1& a_rDestination, const T_StringType2& a_crSource);
/*--------------------------------------------------------------------------*/
//! Algorithm: Compare two strings taken into account their cases (maximal length version).
/*!
    Algorithm copies the given source string into the destination  one  taking
    into account minimal length of two strings.

    \param a_rDestination - Reference to the destination string.
    \param a_cDestinationLength - Maximal destination length value.
    \param a_crSource - Constant reference to the destination string.
    \param a_cSourceLength - Maximal source length value.
    \return Count of copied characters.
*/
template <typename T_StringType1, typename T_StringType2>
Tuint stringCopy(T_StringType1& a_rDestination, const Tuint a_cDestinationLength, const T_StringType2& a_crSource, const Tuint a_cSourceLength);
/*--------------------------------------------------------------------------*/
//! Algorithm: Compare two strings taken into account their cases (index offset and maximal length version).
/*!
    Algorithm copies the given source string into the destination  one  taking
    into account minimal length of two strings.

    \param a_rDestination - Reference to the destination string.
    \param a_cDestinationIndex - Destination index offset value.
    \param a_cDestinationLength - Maximal destination length value.
    \param a_crSource - Constant reference to the destination string.
    \param a_cSourceIndex - Source index offset value.
    \param a_cSourceLength - Maximal source length value starting from offset.
    \return Count of copied characters.
*/
template <typename T_StringType1, typename T_StringType2>
Tuint stringCopy(T_StringType1& a_rDestination, const Tuint a_cDestinationIndex, const Tuint a_cDestinationLength, const T_StringType2& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/AStringCopy.inl>
/*==========================================================================*/
#endif
