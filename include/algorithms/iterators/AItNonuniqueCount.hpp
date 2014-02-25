/*!
 *  \file    AItNonuniqueCount.hpp Contains general template implementation of
 *           the iterator get count of non unique items algorithm.
 *  \brief   Iterator get count of non unique items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator get count of non unique items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   05.06.2007 02:53:23

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
#ifndef __AITNONUNIQUECOUNT_HPP__
#define __AITNONUNIQUECOUNT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
#include <Depth/include/base/CInteger.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
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
//! Algorithm: Forward iterator get count of non unique items.
/*!
    Algorithm gets count of non unique items, which count bounds in the  given
    minimum/maximum value, inside the sequence represented  with  its  forward
    iterator.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return Count of non unique items.
*/
template <class T_Iterator>
Tuint nonuniqueCountNext(const T_Iterator& a_crIterator, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator get count of non unique items using 'Equal' predicate.
/*!
    Algorithm gets count of non unique items, which count bounds in the  given
    minimum/maximum value, inside the sequence represented  with  its  forward
    iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return Count of non unique items.
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tuint nonuniqueCountNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator get count of non unique items.
/*!
    Algorithm gets count of non unique items, which count bounds in the  given
    minimum/maximum value, inside the sequence represented with  its  backward
    iterator.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return Count of non unique items.
*/
template <class T_Iterator>
Tuint nonuniqueCountPrev(const T_Iterator& a_crIterator, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator get count of non unique items using 'Equal' predicate.
/*!
    Algorithm gets count of non unique items, which count bounds in the  given
    minimum/maximum value, inside the sequence represented with  its  backward
    iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return Count of non unique items.
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tuint nonuniqueCountPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItNonuniqueCount.inl>
/*==========================================================================*/
#endif
