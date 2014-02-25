/*!
 *  \file    AItUniqueCount.hpp Contains general template implementation of
 *           the iterator get count of unique items algorithm.
 *  \brief   Iterator get count of unique items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator get count of unique items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   01.06.2007 02:04:52

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
#ifndef __AITUNIQUECOUNT_HPP__
#define __AITUNIQUECOUNT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
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
//! Algorithm: Forward iterator get count of unique items.
/*!
    Algorithm gets count of unique items inside the sequence represented  with
    its forward iterator.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \return Count of unique items.
*/
template <class T_Iterator>
Tuint uniqueCountNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator get count of unique items using 'Equal' predicate.
/*!
    Algorithm gets count of unique items inside the sequence represented  with
    its forward iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of unique items.
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tuint uniqueCountNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator get count of unique items.
/*!
    Algorithm gets count of unique items inside the sequence represented  with
    its backward iterator.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \return Count of unique items.
*/
template <class T_Iterator>
Tuint uniqueCountPrev(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator get count of unique items using 'Equal' predicate.
/*!
    Algorithm gets count of unique items inside the sequence represented  with
    its backward iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of unique items.
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tuint uniqueCountPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItUniqueCount.inl>
/*==========================================================================*/
#endif
