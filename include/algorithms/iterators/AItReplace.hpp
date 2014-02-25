/*!
 *  \file    AItReplace.hpp Contains general template implementation of the
 *           replace algorithm.
 *  \brief   Replace algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Replace algorithm.

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
#ifndef __AITREPLACE_HPP__
#define __AITREPLACE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItFind.hpp>
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
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
//! Algorithm: Forward replace all items with the given value.
/*!
    Algorithm searches forward and replaces all items with the given value. It
    stops searching process when iterator cannot step forward anymore,  or  if
    iteration cycle restarts (for cycled containers).

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crOldValue - Constant reference to the old searched value.
    \param a_crNewValue - Constant reference to the new replaced value.
    \return Count of replaced items.
*/
template <class T_Iterator, typename T_OldValueType, typename T_NewValueType>
Tuint replaceNext(const T_Iterator& a_crIterator, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward replace all items with the given value using 'Equal' predicate.
/*!
    Algorithm searches forward and replaces all items with the given value. It
    stops searching process when iterator cannot step forward anymore,  or  if
    iteration cycle restarts (for cycled containers).

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crOldValue - Constant reference to the old searched value.
    \param a_crNewValue - Constant reference to the new replaced value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of replaced items.
*/
template <class T_Iterator, typename T_OldValueType, typename T_NewValueType, typename T_BinaryPredicate>
Tuint replaceNext(const T_Iterator& a_crIterator, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward replace all items with the given value.
/*!
    Algorithm searches backward and replaces all items with the  given  value.
    It stops searching process when iterator cannot step backward anymore,  or
    if iteration cycle restarts (for cycled containers).

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crOldValue - Constant reference to the old searched value.
    \param a_crNewValue - Constant reference to the new replaced value.
    \return Count of replaced items.
*/
template <class T_Iterator, typename T_OldValueType, typename T_NewValueType>
Tuint replacePrev(const T_Iterator& a_crIterator, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward replace all items with the given value using 'Equal' predicate.
/*!
    Algorithm searches backward and replaces all items with the  given  value.
    It stops searching process when iterator cannot step backward anymore,  or
    if iteration cycle restarts (for cycled containers).

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crOldValue - Constant reference to the old searched value.
    \param a_crNewValue - Constant reference to the new replaced value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of replaced items.
*/
template <class T_Iterator, typename T_OldValueType, typename T_NewValueType, typename T_BinaryPredicate>
Tuint replacePrev(const T_Iterator& a_crIterator, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItReplace.inl>
/*==========================================================================*/
#endif
