/*!
 *  \file    AItSortQuick.hpp Contains general template implementation of
 *           the iterator quick sort algorithm.
 *  \brief   Iterator quick sort algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator quick sort algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   19.08.2007 23:58:26

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
#ifndef __AITSORTQUICK_HPP__
#define __AITSORTQUICK_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/algorithms/iterators/AItDistance.hpp>
#include <Depth/include/algorithms/iterators/details/ASortQuickHelper.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorNonConstForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorNonConstBackward.hpp>
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
//! Algorithm: Forward iterator sort items with quick algorithm.
/*!
    Algorithm sorts all items inside the sequence represented with its forward
    iterator using quick algorithm.

    Important: Quick sort algorithm works only with bi-directional iterators.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \return true  - if sort operation completed successfully. \n
            false - if sort operation did not complete successfully. \n
*/
template <class T_Iterator>
Tbool sortQuickNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator sort items with quick algorithm using 'LessThan' predicate.
/*!
    Algorithm sorts all items inside the sequence represented with its forward
    iterator using quick algorithm.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    Important: Quick sort algorithm works only with bi-directional iterators.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return true  - if sort operation completed successfully. \n
            false - if sort operation did not complete successfully. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool sortQuickNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator sort items with quick algorithm.
/*!
    Algorithm sorts  all  items  inside  the  sequence  represented  with  its
    backward iterator using quick algorithm.

    Important: Quick sort algorithm works only with bi-directional iterators.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \return true  - if sort operation completed successfully. \n
            false - if sort operation did not complete successfully. \n
*/
template <class T_Iterator>
Tbool sortQuickPrev(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator sort items with quick algorithm using 'LessThan' predicate.
/*!
    Algorithm sorts  all  items  inside  the  sequence  represented  with  its
    backward iterator using quick algorithm.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    Important: Quick sort algorithm works only with bi-directional iterators.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return true  - if sort operation completed successfully. \n
            false - if sort operation did not complete successfully. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool sortQuickPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItSortQuick.inl>
/*==========================================================================*/
#endif
