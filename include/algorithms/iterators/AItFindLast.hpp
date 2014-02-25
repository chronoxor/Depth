/*!
 *  \file    AItFindLast.hpp Contains general template implementation of the
 *           find last algorithm.
 *  \brief   Find last algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find last algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   13.04.2007 23:18:23

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
#ifndef __AITFINDLAST_HPP__
#define __AITFINDLAST_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItFind.hpp>
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
//! Algorithm: Forward searching for the last iterator with given value.
/*!
    Algorithm searches forward for the last  iterator  with  given  value.  It
    implements searching in container which  represented  with  given  forward
    iterator. It stops searching process when  iterator  cannot  step  forward
    anymore, or if iteration cycle restarts (for cycled containers).

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crValue - Constant reference to the searching value.
    \return Forward iterator to the last found value, or invalid iterator.
*/
template <class T_Iterator, typename T_ValueType>
T_Iterator findLastNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward searching for the last iterator with given value using 'Equal' predicate.
/*!
    Algorithm searches forward for the last  iterator  with  given  value.  It
    implements searching in container which  represented  with  given  forward
    iterator. It stops searching process when  iterator  cannot  step  forward
    anymore, or if iteration cycle restarts (for cycled containers).

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crValue - Constant reference to the searching value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Forward iterator to the last found value, or invalid iterator.
*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
T_Iterator findLastNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward searching for the last iterator with given value.
/*!
    Algorithm searches backward for the last iterator  with  given  value.  It
    implements searching in container which represented  with  given  backward
    iterator. It stops searching process when iterator  cannot  step  backward
    anymore, or if iteration cycle restarts (for cycled containers).

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crValue - Constant reference to the searching value.
    \return Backward iterator to the last found value, or invalid iterator.
*/
template <class T_Iterator, typename T_ValueType>
T_Iterator findLastPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward searching for the last iterator with given value.
/*!
    Algorithm searches backward for the last iterator  with  given  value.  It
    implements searching in container which represented  with  given  backward
    iterator. It stops searching process when iterator  cannot  step  backward
    anymore, or if iteration cycle restarts (for cycled containers).

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crValue - Constant reference to the searching value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Backward iterator to the last found value, or invalid iterator.
*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
T_Iterator findLastPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItFindLast.inl>
/*==========================================================================*/
#endif
