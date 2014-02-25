/*!
 *  \file    AItFindLastIf.hpp Contains general template implementation of
 *           the find last algorithm with given unary 'If' predicate.
 *  \brief   Find last algorithm with given unary 'If' predicate.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find last algorithm with given unary 'If' predicate.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   13.04.2007 23:26:43

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
#ifndef __AITFINDLASTIF_HPP__
#define __AITFINDLASTIF_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItFindIf.hpp>
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
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
//! Algorithm: Forward searching for the last iterator with given unary 'If' predicate.
/*!
    Algorithm searches forward for the last iterator accepted with  the  given
    unary  'If'  predicate.  It  implements  searching  in  container   which
    represented with given forward iterator. It stops searching  process  when
    iterator cannot step forward anymore, or if iteration cycle restarts  (for
    cycled containers).

    In this algorithm unary 'If' predicate should return 'true' if it  accepts
    the value and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_fIf - Unary 'If' predicate.
    \return Forward iterator to the last found value, or invalid iterator.
*/
template <class T_Iterator, typename T_UnaryIfPredicate>
T_Iterator findLastIfNext(const T_Iterator& a_crIterator, T_UnaryIfPredicate a_fIf);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward searching for the last iterator with given unary 'If' predicate.
/*!
    Algorithm searches backward for the last iterator accepted with the  given
    unary  'If'  predicate.  It  implements  searching  in  container   which
    represented with given backward iterator. It stops searching process  when
    iterator cannot step backward anymore, or if iteration cycle restarts (for
    cycled containers).

    In this algorithm unary 'If' predicate should return 'true' if it  accepts
    the value and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_fIf - Unary 'If' predicate.
    \return Backward iterator to the last found value, or invalid iterator.
*/
template <class T_Iterator, typename T_UnaryIfPredicate>
T_Iterator findLastIfPrev(const T_Iterator& a_crIterator, T_UnaryIfPredicate a_fIf);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItFindLastIf.inl>
/*==========================================================================*/
#endif
