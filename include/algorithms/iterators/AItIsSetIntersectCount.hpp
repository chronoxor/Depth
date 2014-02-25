/*!
 *  \file    AItIsSetIntersectCount.hpp Contains general template
 *           implementation of the check and get count of the two
 *           sets intersection algorithm.
 *  \brief   Check and get count of the two sets intersection algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Check and get count of the two sets intersection algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   24.05.2007 21:06:42

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
#ifndef __AITISSETINTERSECTCOUNT_HPP__
#define __AITISSETINTERSECTCOUNT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItLowerBound.hpp>
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
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
//! Algorithm: Check if two forward sorted set sequences are intersect each other and get count of the intersected items.
/*!
    Algorithm test  on  intersection  two  sequences  represented  with  their
    forward iterators and get count of the intersected items.

    Important: This algorithm requires both containers to be sorted.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \return Count of the intersected items of 0.
*/
template <class T_Iterator1, class T_Iterator2>
Tuint isSetIntersectCountNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Check if two forward sorted set sequences are intersect each other and get count of the intersected items using 'LessThan' predicate.
/*!
    Algorithm test  on  intersection  two  sequences  represented  with  their
    forward iterators and get count of the intersected items.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    Important: This algorithm requires both containers to be sorted.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Count of the intersected items of 0.
*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
Tuint isSetIntersectCountNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fLessThan);
/*--------------------------------------------------------------------------*/
//! Algorithm: Check if two backward sorted set sequences are intersect each other and get count of the intersected items.
/*!
    Algorithm test  on  intersection  two  sequences  represented  with  their
    backward iterators and get count of the intersected items.

    Important: This algorithm requires both containers to be sorted.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \return Count of the intersected items of 0.
*/
template <class T_Iterator1, class T_Iterator2>
Tuint isSetIntersectCountPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Check if two backward sorted set sequences are intersect each other and get count of the intersected items using 'LessThan' predicate.
/*!
    Algorithm test  on  intersection  two  sequences  represented  with  their
    backward iterators and get count of the intersected items.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    Important: This algorithm requires both containers to be sorted.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Count of the intersected items of 0.
*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
Tuint isSetIntersectCountPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItIsSetIntersectCount.inl>
/*==========================================================================*/
#endif
