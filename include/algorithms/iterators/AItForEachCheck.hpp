/*!
 *  \file    AItForEachCheck.hpp Contains general template implementation of
 *           the iterator for each check calling algorithm.
 *  \brief   Iterator for each check calling algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator for each check calling algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   12.09.2006 22:44:37

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
#ifndef __AITFOREACHCHECK_HPP__
#define __AITFOREACHCHECK_HPP__
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
//! Algorithm: Forward iterator for each check calling.
/*!
    Algorithm calls given predicate  for  each  forward  iterator  until  this
    predicate returns 'true'. Algorithm returns count of the forward iterators
    which were called with given predicate.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_fPredicate - Unary predicate.
    \return Count of the forward iterators which were called with given predicate.
*/
template <class T_Iterator, typename T_UnaryPredicate>
Tuint forEachCheckNext(const T_Iterator& a_crIterator, T_UnaryPredicate a_fPredicate);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator for each check calling.
/*!
    Algorithm calls given predicate for  each  backward  iterator  until  this
    predicate  returns  'true'.  Algorithm  returns  count  of  the   backward
    iterators which were called with given predicate.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_fPredicate - Unary predicate.
    \return Count of the backward iterators which were called with given predicate.
*/
template <class T_Iterator, typename T_UnaryPredicate>
Tuint forEachCheckPrev(const T_Iterator& a_crIterator, T_UnaryPredicate a_fPredicate);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItForEachCheck.inl>
/*==========================================================================*/
#endif
