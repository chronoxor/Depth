/*!
 *  \file    AItSortBubble.hpp Contains general template implementation of
 *           the iterator bubble sort algorithm.
 *  \brief   Iterator bubble sort algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator bubble sort algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   19.08.2007 23:38:01

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
#ifndef __AITSORTBUBBLE_HPP__
#define __AITSORTBUBBLE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/ASwap.hpp>
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
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
//! Algorithm: Forward iterator sort items with bubble algorithm.
/*!
    Algorithm sorts all items inside the sequence represented with its forward
    iterator using bubble algorithm.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \return true  - if sort operation completed successfully. \n
            false - if sort operation did not complete successfully. \n
*/
template <class T_Iterator>
Tbool sortBubbleNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator sort items with bubble algorithm using 'LessThan' predicate.
/*!
    Algorithm sorts all items inside the sequence represented with its forward
    iterator using bubble algorithm.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return true  - if sort operation completed successfully. \n
            false - if sort operation did not complete successfully. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool sortBubbleNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator sort items with bubble algorithm.
/*!
    Algorithm sorts  all  items  inside  the  sequence  represented  with  its
    backward iterator using bubble algorithm.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \return true  - if sort operation completed successfully. \n
            false - if sort operation did not complete successfully. \n
*/
template <class T_Iterator>
Tbool sortBubblePrev(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator sort items with bubble algorithm using 'LessThan' predicate.
/*!
    Algorithm sorts  all  items  inside  the  sequence  represented  with  its
    backward iterator using bubble algorithm.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return true  - if sort operation completed successfully. \n
            false - if sort operation did not complete successfully. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool sortBubblePrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItSortBubble.inl>
/*==========================================================================*/
#endif
