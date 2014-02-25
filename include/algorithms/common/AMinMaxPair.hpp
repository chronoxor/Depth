/*!
 *  \file    AMinMaxPair.hpp Contains general template implementation of the
 *           min and max algorithm which returns values in pair.
 *  \brief   Min and max pair algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Min and max pair algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   26.04.2006 23:56:57

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
#ifndef __AMINMAXPAIR_HPP__
#define __AMINMAXPAIR_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/utility/CPair.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Find maximum and minimum of two values in pair.
/*!
    First pair value contains minimum  of  two  values,  second  one  contains
    maximum of two values.

    \param a_crX - Constant reference to first value.
    \param a_crY - Constant reference to second value.
    \return Pair of minimum and maximum values.
*/
template <typename T_Type>
NUtility::CPair<T_Type, T_Type> minMaxPair(const T_Type& a_crX, const T_Type& a_crY);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find maximum and minimum of two values in pair. Use 'LessThan' binary predicate.
/*!
    First pair value contains minimum of two values, second one contains
    maximum of two values.

    In this algorithm 'LessThan' binary predicate should return 'true' if X  <
    Y and 'false' otherwise.

    \param a_crX - Constant reference to first value.
    \param a_crY - Constant reference to second value.
    \param a_fLessThan - 'LessThan' binary predicate (default is FBoolLessThan).
    \return Pair of minimum and maximum values.
*/
template <typename T_Type, typename T_LessThanBinaryPredicate>
NUtility::CPair<T_Type, T_Type> minMaxPair(const T_Type& a_crX, const T_Type& a_crY, T_LessThanBinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMinMaxPair.inl>
/*==========================================================================*/
#endif
