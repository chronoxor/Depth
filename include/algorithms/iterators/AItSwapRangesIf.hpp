/*!
 *  \file    AItSwapRangesIf.hpp Contains general template implementation of
 *           the iterator two sequences swap ranges algorithm with given
 *           binary 'If' predicate.
 *  \brief   Iterator two sequences swap ranges algorithm with given binary 'If' predicate.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator two sequences swap ranges algorithm with given binary 'If' predicate.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   10.05.2007 20:42:23

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
#ifndef __AITSWAPRANGESIF_HPP__
#define __AITSWAPRANGESIF_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/ASwap.hpp>
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorNonConstForward.hpp>
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
//! Algorithm: Forward iterator two sequences swap ranges with given binary 'If' predicate.
/*!
    Algorithm swaps values of two sequences  represented  with  their  forward
    iterators. It swaps only values from sequences which accepted by the given
    binary 'If' predicate.

    In this algorithm binary 'If' predicate should return 'true' if it accepts
    values form both sequences and 'false' otherwise.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \param a_fIf - Binary 'If' predicate.
    \return Count of swapped items.
*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryIfPredicate>
Tuint swapRangesIfNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryIfPredicate a_fIf);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator two sequences swap ranges with given binary 'If' predicate.
/*!
    Algorithm swaps values of two sequences represented  with  their  backward
    iterators. It swaps only values from sequences which accepted by the given
    binary 'If' predicate.

    In this algorithm binary 'If' predicate should return 'true' if it accepts
    values form both sequences and 'false' otherwise.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \param a_fIf - Binary 'If' predicate.
    \return Count of swapped items.
*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryIfPredicate>
Tuint swapRangesIfPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryIfPredicate a_fIf);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItSwapRangesIf.inl>
/*==========================================================================*/
#endif
