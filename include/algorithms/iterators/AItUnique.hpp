/*!
 *  \file    AItUnique.hpp Contains general template implementation of the
 *           iterator unique all items algorithm.
 *  \brief   Iterator unique all items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator unique all items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   01.06.2007 03:36:33

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
#ifndef __AITUNIQUE_HPP__
#define __AITUNIQUE_HPP__
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
//! Algorithm: Forward iterator unique all items.
/*!
    Algorithm makes all items unique inside the sequence represented with  its
    forward iterator.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \return true  - if unique operation completed successfully for all items in the sequence. \n
            false - if unique operation did not complete successfully for all items in the sequence. \n
*/
template <class T_Iterator>
Tbool uniqueNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator unique all items using 'Equal' predicate.
/*!
    Algorithm makes all items unique inside the sequence represented with  its
    forward iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return true  - if unique operation completed successfully for all items in the sequence. \n
            false - if unique operation did not complete successfully for all items in the sequence. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool uniqueNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator unique all items.
/*!
    Algorithm makes all items unique inside the sequence represented with  its
    backward iterator.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \return true  - if unique operation completed successfully for all items in the sequence. \n
            false - if unique operation did not complete successfully for all items in the sequence. \n
*/
template <class T_Iterator>
Tbool uniquePrev(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator unique all items using 'Equal' predicate.
/*!
    Algorithm makes all items unique inside the sequence represented with  its
    backward iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return true  - if unique operation completed successfully for all items in the sequence. \n
            false - if unique operation did not complete successfully for all items in the sequence. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool uniquePrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItUnique.inl>
/*==========================================================================*/
#endif
