/*!
 *  \file    ASign.hpp Contains general template implementation of the find
 *           sign of number algorithm.
 *  \brief   Sign of number algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sign of number algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Numeric algorithms
    VERSION:   1.0
    CREATED:   03.04.2006 21:47:42

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
#ifndef __ASIGN_HPP__
#define __ASIGN_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolLessThanZero.hpp>
#include <Depth/include/concept/functions/MConceptPredicate1.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NNumeric {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Find sign of number (without zero).
/*!
    \param a_crX - Constant reference to the number.
    \return One of the following values: \n
            -1 - if X < 0 \n
            +1 - if X > 0 \n
*/
template <typename T_Type>
Tsint sign(const T_Type& a_crX);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find sign of number (without zero) with 'LessThanZero' unary predicate.
/*!
    In this algorithm 'LessThanZero' unary  predicate should  return 'true' if
    X < 0 and 'false' otherwise.

    \param a_crX - Constant reference to the number.
    \param a_fLessThanZero - 'LessThanZero' unary predicate.
    \return One of the following values: \n
            -1 - if X < 0 \n
            +1 - if X > 0 \n
*/
template <typename T_Type, typename T_LessThanZeroUnaryPredicate>
Tsint sign(const T_Type& a_crX, T_LessThanZeroUnaryPredicate a_fLessThanZero);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/numeric/ASign.inl>
/*==========================================================================*/
#endif
