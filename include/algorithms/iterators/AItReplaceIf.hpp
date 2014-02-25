/*!
 *  \file    AItReplaceIf.hpp Contains general template implementation of the
 *           replace algorithm with unary 'If' predicate.
 *  \brief   Replace algorithm with unary 'If' predicate.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Replace algorithm with unary 'If' predicate.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   11.06.2007 21:45:48

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
#ifndef __AITREPLACEIF_HPP__
#define __AITREPLACEIF_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItFindIf.hpp>
#include <Depth/include/concept/common/MConceptConvert.hpp>
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
//! Algorithm: Forward replace all items with the given value with unary 'If' predicate.
/*!
    Algorithm searches forward and replaces all items, which accepted with the
    given unary 'If' predicate, with  the  given  value.  It  stops  searching
    process when iterator cannot step forward anymore, or if  iteration  cycle
    restarts (for cycled containers).

    In this algorithm unary 'If' predicate should return 'true' if it  accepts
    the value and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crNewValue - Constant reference to the new replaced value.
    \param a_fIf - Unary 'If' predicate.
    \return Count of replaced items.
*/
template <class T_Iterator, typename T_NewValueType, typename T_UnaryIfPredicate>
Tuint replaceIfNext(const T_Iterator& a_crIterator, const T_NewValueType& a_crNewValue, T_UnaryIfPredicate a_fIf);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward replace all items with the given value with unary 'If' predicate.
/*!
    Algorithm searches backward and replaces all items,  which  accepted  with
    the given unary 'If' predicate, with the given value. It  stops  searching
    process when iterator cannot step backward anymore, or if iteration  cycle
    restarts (for cycled containers).

    In this algorithm unary 'If' predicate should return 'true' if it  accepts
    the value and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crNewValue - Constant reference to the new replaced value.
    \param a_fIf - Unary 'If' predicate.
    \return Count of replaced items.
*/
template <class T_Iterator, typename T_NewValueType, typename T_UnaryIfPredicate>
Tuint replaceIfPrev(const T_Iterator& a_crIterator, const T_NewValueType& a_crNewValue, T_UnaryIfPredicate a_fIf);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItReplaceIf.inl>
/*==========================================================================*/
#endif
