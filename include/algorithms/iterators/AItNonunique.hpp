/*!
 *  \file    AItNonunique.hpp Contains general template implementation of the
 *           iterator non unique all items algorithm.
 *  \brief   Iterator non unique all items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator non unique all items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   05.06.2007 03:37:53

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
#ifndef __AITNONUNIQUE_HPP__
#define __AITNONUNIQUE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
#include <Depth/include/base/CInteger.hpp>
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
//! Algorithm: Forward iterator non unique all items.
/*!
    Algorithm keeps all non unique items, which  count  bounds  in  the  given
    minimum/maximum value, inside the sequence represented  with  its  forward
    iterator.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::NBase::CUnsignedInteger::getMax()).
    \return true  - if non unique operation completed successfully for all items in the sequence. \n
            false - if non unique operation did not complete successfully for all items in the sequence. \n
*/
template <class T_Iterator>
Tbool nonuniqueNext(const T_Iterator& a_crIterator, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator non unique all items using 'Equal' predicate.
/*!
    Algorithm keeps all non unique items, which  count  bounds  in  the  given
    minimum/maximum value, inside the sequence represented  with  its  forward
    iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::NBase::CUnsignedInteger::getMax()).
    \return true  - if non unique operation completed successfully for all items in the sequence. \n
            false - if non unique operation did not complete successfully for all items in the sequence. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool nonuniqueNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator non unique all items.
/*!
    Algorithm keeps all non unique items, which  count  bounds  in  the  given
    minimum/maximum value, inside the sequence represented with  its  backward
    iterator.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return true  - if non unique operation completed successfully for all items in the sequence. \n
            false - if non unique operation did not complete successfully for all items in the sequence. \n
*/
template <class T_Iterator>
Tbool nonuniquePrev(const T_Iterator& a_crIterator, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator non unique all items using 'Equal' predicate.
/*!
    Algorithm keeps all non unique items, which  count  bounds  in  the  given
    minimum/maximum value, inside the sequence represented with  its  backward
    iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return true  - if non unique operation completed successfully for all items in the sequence. \n
            false - if non unique operation did not complete successfully for all items in the sequence. \n
*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool nonuniquePrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItNonunique.inl>
/*==========================================================================*/
#endif
