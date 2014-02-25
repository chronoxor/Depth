/*!
 *  \file    AItUniqueSortedCount.hpp Contains general template implementation
 *           of the iterator get count of unique sorted items algorithm.
 *  \brief   Iterator get count of unique sorted items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator get count of unique sorted items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   04.06.2007 02:44:23

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
#ifndef __AITUNIQUESORTEDCOUNT_HPP__
#define __AITUNIQUESORTEDCOUNT_HPP__
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
//! Algorithm: Forward iterator get count of unique sorted items.
/*!
    Algorithm  gets  count  of  unique  items  inside  the   sorted   sequence
    represented with its forward iterator.

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the sorted sequence's forward iterator.
    \return Count of unique items.
*/
template <class T_Iterator>
Tuint uniqueSortedCountNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator get count of unique sorted items using 'Equal' predicate.
/*!
    Algorithm  gets  count  of  unique  items  inside  the   sorted   sequence
    represented with its forward iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the sorted sequence's forward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of unique items.
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tuint uniqueSortedCountNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator get count of unique sorted items.
/*!
    Algorithm  gets  count  of  unique  items  inside  the   sorted   sequence
    represented with its backward iterator.

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the sorted sequence's backward iterator.
    \return Count of unique items.
*/
template <class T_Iterator>
Tuint uniqueSortedCountPrev(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator get count of unique sorted items using 'Equal' predicate.
/*!
    Algorithm  gets  count  of  unique  items  inside  the   sorted   sequence
    represented with its backward iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the sorted sequence's backward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of unique items.
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tuint uniqueSortedCountPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItUniqueSortedCount.inl>
/*==========================================================================*/
#endif
