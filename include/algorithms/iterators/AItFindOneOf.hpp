/*!
 *  \file    AItFindOneOf.hpp Contains general template implementation of the
 *           iterator find one of algorithm.
 *  \brief   Iterator find one of algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator find one of algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   12.09.2006 23:08:36

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
#ifndef __AITFINDONEOF_HPP__
#define __AITFINDONEOF_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Forward iterator find one of.
/*!
    Algorithm looks forward for the one of the given values.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crMatchIterator - Constant reference to the match forward iterator.
    \return Forward iterator to the found value, or invalid iterator.
*/
template <class T_Iterator, class T_MatchIterator>
T_Iterator findOneOfNext(const T_Iterator& a_crIterator, const T_MatchIterator& a_crMatchIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator find one of using 'Equal' predicate.
/*!
    Algorithm looks forward for the one of the given values.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crMatchIterator - Constant reference to the match forward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return Forward iterator to the found value, or invalid iterator.
*/
template <class T_Iterator, class T_MatchIterator, typename T_BinaryPredicate>
T_Iterator findOneOfNext(const T_Iterator& a_crIterator, const T_MatchIterator& a_crMatchIterator, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator find one of.
/*!
    Algorithm looks backward for the one of the given values.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crMatchIterator - Constant reference to the match backward iterator.
    \return Backward iterator to the found value, or invalid iterator.
*/
template <class T_Iterator, class T_MatchIterator>
T_Iterator findOneOfPrev(const T_Iterator& a_crIterator, const T_MatchIterator& a_crMatchIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator find one of using 'Equal' predicate.
/*!
    Algorithm looks backward for the one of the given values.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crMatchIterator - Constant reference to the match backward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return Backward iterator to the found value, or invalid iterator.
*/
template <class T_Iterator, class T_MatchIterator, typename T_BinaryPredicate>
T_Iterator findOneOfPrev(const T_Iterator& a_crIterator, const T_MatchIterator& a_crMatchIterator, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItFindOneOf.inl>
/*==========================================================================*/
#endif
