/*!
 *  \file    AItMismatch.hpp Contains general template implementation of the
 *           iterator two sequences mismatch test algorithm.
 *  \brief   Iterator two sequences mismatch test algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator two sequences mismatch test algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   15.09.2006 02:42:53

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
#ifndef __AITMISMATCH_HPP__
#define __AITMISMATCH_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/utility/CPair.hpp>
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
//! Algorithm: Forward iterator two sequences mismatch test.
/*!
    Algorithm tests on mismatch two sequences represented with  their  forward
    iterators. It  returns  pair  of  the  first  mismatch  iterator  in  each
    sequence. If two sequences are equal then both iterators in pair  will  be
    invalid.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \return Pair of the first mismatch iterator in each sequence.
*/
template <class T_Iterator1, class T_Iterator2>
NUtility::CPair<T_Iterator1, T_Iterator2> mismatchNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator two sequences mismatch test using 'Equal' predicate.
/*!
    Algorithm tests on mismatch two sequences represented with  their  forward
    iterators. It  returns  pair  of  the  first  mismatch  iterator  in  each
    sequence. If two sequences are equal then both iterators in pair  will  be
    invalid.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return Pair of the first mismatch iterator in each sequence.
*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
NUtility::CPair<T_Iterator1, T_Iterator2> mismatchNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator two sequences mismatch test.
/*!
    Algorithm tests on mismatch two sequences represented with their  backward
    iterators. It  returns  pair  of  the  first  mismatch  iterator  in  each
    sequence. If two sequences are equal then both iterators in pair  will  be
    invalid.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \return Pair of the first mismatch iterator in each sequence.
*/
template <class T_Iterator1, class T_Iterator2>
NUtility::CPair<T_Iterator1, T_Iterator2> mismatchPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator two sequences mismatch test using 'Equal' predicate.
/*!
    Algorithm tests on mismatch two sequences represented with their  backward
    iterators. It  returns  pair  of  the  first  mismatch  iterator  in  each
    sequence. If two sequences are equal then both iterators in pair  will  be
    invalid.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return Pair of the first mismatch iterator in each sequence.
*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
NUtility::CPair<T_Iterator1, T_Iterator2> mismatchPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItMismatch.inl>
/*==========================================================================*/
#endif
