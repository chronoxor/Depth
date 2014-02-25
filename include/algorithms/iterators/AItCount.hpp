/*!
 *  \file    AItCount.hpp Contains general template implementation of the
 *           iterator counting algorithm.
 *  \brief   Iterator counting algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator counting algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   12.09.2006 20:54:43

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
#ifndef __AITCOUNT_HPP__
#define __AITCOUNT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
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
//! Algorithm: Forward iterator counting.
/*!
    Algorithm returns count of the forward iterators.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \return Count of forward iterators including the given iterator.
*/
template <class T_Iterator>
Tuint countNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator counting with given value.
/*!
    Algorithm returns count of the forward iterators with given value.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crValue - Constant reference to the counting value.
    \return Count of forward iterators with given value.
*/
template <class T_Iterator, typename T_ValueType>
Tuint countNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator counting with given value using 'Equal' predicate.
/*!
    Algorithm returns count of the forward iterators with given value.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crValue - Constant reference to the counting value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of forward iterators with given value.
*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
Tuint countNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator counting.
/*!
    Algorithm returns count of the backward iterators.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \return Count of backward iterators including the given iterator.
*/
template <class T_Iterator>
Tuint countPrev(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator counting with given value.
/*!
    Algorithm returns count of the backward iterators with given value.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crValue - Constant reference to the counting value.
    \return Count of backward iterators with given value.
*/
template <class T_Iterator, typename T_ValueType>
Tuint countPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator counting with given value using 'Equal' predicate.
/*!
    Algorithm returns count of the backward iterators with given value.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crValue - Constant reference to the counting value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of backward iterators with given value.
*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
Tuint countPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItCount.inl>
/*==========================================================================*/
#endif
