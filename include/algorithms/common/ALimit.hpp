/*!
 *  \file    ALimit.hpp Contains general template implementation of the limit
 *           algorithm.
 *  \brief   Limit algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Limit algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   03.04.2006 20:43:31

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
#ifndef __ALIMIT_HPP__
#define __ALIMIT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
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
//! Algorithm: Find limit of the value A <= X <= B.
/*!
    \param a_crA - Constant reference to the value A.
    \param a_crB - Constant reference to the value B.
    \param a_crX - Constant reference to the value X.
    \return Limit value.
*/
template <typename T_Type>
T_Type limit(const T_Type& a_crA, const T_Type& a_crB, const T_Type& a_crX);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find limit of the value A <= X <= B. Use 'LessThan' binary predicate.
/*!
    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    \param a_crA - Constant reference to the value A.
    \param a_crB - Constant reference to the value B.
    \param a_crX - Constant reference to the value X.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Limit value.
*/
template <typename T_Type, typename T_LessThanBinaryPredicate>
T_Type limit(const T_Type& a_crA, const T_Type& a_crB, const T_Type& a_crX, T_LessThanBinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/common/ALimit.inl>
/*==========================================================================*/
#endif
