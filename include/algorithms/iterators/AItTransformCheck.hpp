/*!
 *  \file    AItTransformCheck.hpp Contains general template implementation of
 *           the iterator check transform all items algorithm.
 *  \brief   Iterator check transform all items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator check transform all items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   24.05.2007 03:28:42

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
#ifndef __AITTRANSFORMCHECK_HPP__
#define __AITTRANSFORMCHECK_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/concept/functions/MConceptPredicate1.hpp>
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
//! Algorithm: Check transform all forward iterator items next to the container's end.
/*!
    Algorithm transforms all items from the current forward  iterator  to  the
    container's  end  with  the  given  unary  transformation  predicate.   It
    transforms items until this predicate returns 'true'.

    \param a_crIterator - Constant reference to the forward iterator.
    \param a_fPredicate - Unary transformation predicate.
    \return Count of transformed items.
*/
template <class T_Iterator, typename T_UnaryPredicate>
Tuint transformCheckNext(const T_Iterator& a_crIterator, T_UnaryPredicate a_fPredicate);
/*--------------------------------------------------------------------------*/
//! Algorithm: Check transform all backward iterator items back to the container's begin.
/*!
    Algorithm transforms all items from the current backward iterator  to  the
    container's begin  with  the  given  unary  transformation  predicate.  It
    transforms items until this predicate returns 'true'.

    \param a_crIterator - Constant reference to the backward iterator.
    \param a_fPredicate - Unary transformation predicate.
    \return Count of transformed items.
*/
template <class T_Iterator, typename T_UnaryPredicate>
Tuint transformCheckPrev(const T_Iterator& a_crIterator, T_UnaryPredicate a_fPredicate);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItTransformCheck.inl>
/*==========================================================================*/
#endif
