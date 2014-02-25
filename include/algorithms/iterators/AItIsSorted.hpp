/*!
 *  \file    AItIsSorted.hpp Contains general template implementation of the
 *           iterator sorted test algorithm.
 *  \brief   Iterator sorted test algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator sorted test algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   02.04.2006 22:24:45

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
#ifndef __AITISSORTED_HPP__
#define __AITISSORTED_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
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
//! Algorithm: Forward iterator sorted test.
/*!
    Algorithm checks if the sequence represented by the forward iterator is in
    the sorted order.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \return true  - if the sequence is in the sorted order. \n
            false - if the sequence is not in the sorted order. \n
*/
template <class T_Iterator>
Tbool isSortedNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator sorted test using 'LessThan' predicate.
/*!
    Algorithm checks if the sequence represented by the forward iterator is in
    the sorted order.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return true  - if the sequence is in the sorted order. \n
            false - if the sequence is not in the sorted order. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool isSortedNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator sorted test.
/*!
    Algorithm checks if the sequence represented by the backward  iterator  is
    in the sorted order.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \return true  - if the sequence is in the sorted order. \n
            false - if the sequence is not in the sorted order. \n
*/
template <class T_Iterator>
Tbool isSortedPrev(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator sorted test using 'LessThan' predicate.
/*!
    Algorithm checks if the sequence represented by the backward  iterator  is
    in the sorted order.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return true  - if the sequence is in the sorted order. \n
            false - if the sequence is not in the sorted order. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool isSortedPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItIsSorted.inl>
/*==========================================================================*/
#endif
