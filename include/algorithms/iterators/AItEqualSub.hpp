/*!
 *  \file    AItEqualSub.hpp Contains general template implementation of the
 *           iterator two subsequences equal test algorithm.
 *  \brief   Iterator two subsequences equal test algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator two subsequences equal test algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   15.09.2006 02:27:35

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
#ifndef __AITEQUALSUB_HPP__
#define __AITEQUALSUB_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
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
//! Algorithm: Forward iterator two subsequences equal test.
/*!
    Algorithm tests on equal two subsequences represented with  their  forward
    iterators.

    \param a_crIterator1 - Constant reference to the first subsequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second subsequence's forward iterator.
    \return true  - if two subsequences are equal. \n
            false - if two subsequences are not equal. \n
*/
template <class T_Iterator1, class T_Iterator2>
Tbool equalSubNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator two subsequences equal test using 'Equal' predicate.
/*!
    Algorithm tests on equal two subsequences represented with  their  forward
    iterators.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator1 - Constant reference to the first subsequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second subsequence's forward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return true  - if two subsequences are equal. \n
            false - if two subsequences are not equal. \n
*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
Tbool equalSubNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator two subsequences equal test.
/*!
    Algorithm tests on equal two subsequences represented with  their  backward
    iterators.

    \param a_crIterator1 - Constant reference to the first subsequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second subsequence's backward iterator.
    \return true  - if two subsequences are equal. \n
            false - if two subsequences are not equal. \n
*/
template <class T_Iterator1, class T_Iterator2>
Tbool equalSubPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator two subsequences equal test using 'Equal' predicate.
/*!
    Algorithm tests on equal two subsequences represented with  their  backward
    iterators.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crIterator1 - Constant reference to the first subsequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second subsequence's backward iterator.
    \param a_fEqual - 'Equal' binary predicate.
    \return true  - if two subsequences are equal. \n
            false - if two subsequences are not equal. \n
*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
Tbool equalSubPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItEqualSub.inl>
/*==========================================================================*/
#endif
