/*!
 *  \file    AItRemoveCopyAllIf.hpp Contains general template implementation
 *           of the iterator remove and copy all items algorithm with unary
 *           'If' predicate.
 *  \brief   Iterator remove and copy all items algorithm with unary 'If' predicate.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator remove and copy all items algorithm with unary 'If' predicate.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   16.05.2007 20:19:53

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
#ifndef __AITREMOVECOPYALLIF_HPP__
#define __AITREMOVECOPYALLIF_HPP__
/*==========================================================================*/
#include <Depth/include/concept/functions/MConceptPredicate1.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertBackward.hpp>
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
//! Algorithm: Forward iterator remove all items with unary 'If' predicate and copy them into the another sequence.
/*!
    Algorithm removes all items which  accepted  with  the  given  unary  'If'
    predicate from the sequence represented with its forward iterator and copy
    them into the another sequence.

    In this algorithm unary 'If' predicate should return 'true' if it  accepts
    the value and 'false' otherwise.

    Important: This algorithm updates data under  the  copy   and  the  second
    sequences' iterators so  make  sure  to  update  their  values  after  the
    algorithm returns.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_crIteratorCopy - Constant reference to the copy sequence's forward iterator.
    \param a_fIf - Unary 'If' predicate.
    \return Count of removed items.
*/
template <class T_Iterator, class T_IteratorCopy, typename T_UnaryIfPredicate>
Tuint removeCopyAllIfNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_UnaryIfPredicate a_fIf);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator remove all items with unary 'If' predicate and copy them into the another sequence.
/*!
    Algorithm removes all items which  accepted  with  the  given  unary  'If'
    predicate from the sequence represented with  its  backward  iterator  and
    copy them into the another sequence.

    In this algorithm unary 'If' predicate should return 'true' if it  accepts
    the value and 'false' otherwise.

    Important: This algorithm updates data under  the  copy   and  the  second
    sequences' iterators so  make  sure  to  update  their  values  after  the
    algorithm returns.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_crIteratorCopy - Constant reference to the copy sequence's backward iterator.
    \param a_fIf - Unary 'If' predicate.
    \return Count of removed items.
*/
template <class T_Iterator, class T_IteratorCopy, typename T_UnaryIfPredicate>
Tuint removeCopyAllIfPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_UnaryIfPredicate a_fIf);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItRemoveCopyAllIf.inl>
/*==========================================================================*/
#endif
