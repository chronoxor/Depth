/*!
 *  \file    AItSetsIntersectionCopy.hpp Contains general template
 *           implementation of the iterator intersection and copy
 *           of two sets algorithm.
 *  \brief   Iterator intersection and copy of two sets algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator intersection and copy of two sets algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   18.08.2007 02:14:34

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
#ifndef __AITSETSINTERSECTIONCOPY_HPP__
#define __AITSETSINTERSECTIONCOPY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertBackward.hpp>
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
//! Algorithm: Forward intersection and copy two set sequences.
/*!
    Algorithm intersects forward all items from two sequences represented with
    their forward iterators and puts them into the copy sequence.

    Important: This algorithm requires both containers to be sorted.

    Important: This algorithm updates data under the copy sequence's  iterator
    so make sure to update its value after the algorithm returns.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \param a_crIteratorCopy - Constant reference to the copy sequence's forward iterator.
    \return Count of copied items from the set intersection.
*/
template <class T_Iterator1, class T_Iterator2, class T_IteratorCopy>
Tuint setsIntersectionCopyNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, const T_IteratorCopy& a_crIteratorCopy);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward intersection and copy two set sequences using 'LessThan' predicate.
/*!
    Algorithm intersects forward all items from two sequences represented with
    their forward iterators and puts them into the copy sequence.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    Important: This algorithm requires both containers to be sorted.

    Important: This algorithm updates data under the copy sequence's  iterator
    so make sure to update its value after the algorithm returns.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \param a_crIteratorCopy - Constant reference to the copy sequence's forward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Count of copied items from the set intersection.
*/
template <class T_Iterator1, class T_Iterator2, class T_IteratorCopy, typename T_BinaryPredicate>
Tuint setsIntersectionCopyNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, const T_IteratorCopy& a_crIteratorCopy, T_BinaryPredicate a_fLessThan);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward intersection and copy two set sequences.
/*!
    Algorithm intersects backward all items  from  two  sequences  represented
    with their backward iterators and puts them into the copy sequence.

    Important: This algorithm requires both containers to be sorted.

    Important: This algorithm updates data under the copy sequence's  iterator
    so make sure to update its value after the algorithm returns.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \param a_crIteratorCopy - Constant reference to the copy sequence's backward iterator.
    \return Count of copied items from the set intersection.
*/
template <class T_Iterator1, class T_Iterator2, class T_IteratorCopy>
Tuint setsIntersectionCopyPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, const T_IteratorCopy& a_crIteratorCopy);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward intersection and copy two set sequences using 'LessThan' predicate.
/*!
    Algorithm intersects backward all items  from  two  sequences  represented
    with their backward iterators and puts them into the copy sequence.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    Important: This algorithm requires both containers to be sorted.

    Important: This algorithm updates data under the copy sequence's  iterator
    so make sure to update its value after the algorithm returns.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \param a_crIteratorCopy - Constant reference to the copy sequence's backward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Count of copied items from the set intersection.
*/
template <class T_Iterator1, class T_Iterator2, class T_IteratorCopy, typename T_BinaryPredicate>
Tuint setsIntersectionCopyPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, const T_IteratorCopy& a_crIteratorCopy, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItSetsIntersectionCopy.inl>
/*==========================================================================*/
#endif
