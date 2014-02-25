/*!
 *  \file    AItUniqueSorted.hpp Contains general template implementation of
 *           the iterator unique all sorted items algorithm.
 *  \brief   Iterator unique all sorted items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator unique all sorted items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   04.06.2007 02:24:03

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
#ifndef __AITUNIQUESORTED_HPP__
#define __AITUNIQUESORTED_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorRemoveForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorRemoveBackward.hpp>
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
//! Algorithm: Forward iterator unique all sorted items.
/*!
    Algorithm makes all items unique inside the  sorted  sequence  represented
    with its forward iterator.

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the sorted sequence's forward iterator.
    \return true  - if unique operation completed successfully for all items in the sorted sequence. \n
            false - if unique operation did not complete successfully for all items in the sorted sequence. \n
*/
template <class T_Iterator>
Tbool uniqueSortedNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator unique all sorted items using 'Equal' predicate.
/*!
    Algorithm makes all items unique inside the  sorted  sequence  represented
    with its forward iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the sorted sequence's forward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return true  - if unique operation completed successfully for all items in the sorted sequence. \n
            false - if unique operation did not complete successfully for all items in the sorted sequence. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool uniqueSortedNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator unique all sorted items.
/*!
    Algorithm makes all items unique inside the  sorted  sequence  represented
    with its backward iterator.

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the sorted sequence's backward iterator.
    \return true  - if unique operation completed successfully for all items in the sorted sequence. \n
            false - if unique operation did not complete successfully for all items in the sorted sequence. \n
*/
template <class T_Iterator>
Tbool uniqueSortedPrev(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator unique all sorted items using 'Equal' predicate.
/*!
    Algorithm makes all items unique inside the  sorted  sequence  represented
    with its backward iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the sorted sequence's backward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return true  - if unique operation completed successfully for all items in the sorted sequence. \n
            false - if unique operation did not complete successfully for all items in the sorted sequence. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool uniqueSortedPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItUniqueSorted.inl>
/*==========================================================================*/
#endif
