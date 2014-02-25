/*!
 *  \file    ASignZero.hpp Contains general template implementation of the
 *           find sign of number algorithm (zero version).
 *  \brief   Sign of number algorithm (zero version).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sign of number algorithm (zero version).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Numeric algorithms
    VERSION:   1.0
    CREATED:   03.04.2006 21:52:53

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
#ifndef __ASIGNZERO_HPP__
#define __ASIGNZERO_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolEqualZero.hpp>
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
//! Algorithm: Find sign of number (with zero).
/*!
    \param a_crX - Constant reference to the number.
    \return One of the following values: \n
            -1 - if X < 0 \n
             0 - if X = 0 \n
            +1 - if X > 0 \n
*/
template <typename T_Type>
Tsint signZero(const T_Type& a_crX);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find sign of number (with zero) with 'LessThanZero' and 'EqualZero' unary predicates.
/*!
    In this algorithm 'LessThanZero' unary predicate  should  return 'true' if
    X < 0 and 'false' otherwise.

    In  this  algorithm 'EqualZero' unary  predicate  should  return 'true' if
    X == 0 and 'false' otherwise.

    \param a_crX - Constant reference to the number.
    \param a_fLessThanZero - 'LessThanZero' unary predicate.
    \param a_fEqualZero - 'EqualZero' unary predicate.
    \return One of the following values: \n
            -1 - if X < 0 \n
             0 - if X = 0 \n
            +1 - if X > 0 \n
*/
template <typename T_Type, typename T_LessThanZeroUnaryPredicate, typename T_EqualZeroUnaryPredicate>
Tsint signZero(const T_Type& a_crX, T_LessThanZeroUnaryPredicate a_fLessThanZero, T_EqualZeroUnaryPredicate a_fEqualZero);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/numeric/ASignZero.inl>
/*==========================================================================*/
#endif
