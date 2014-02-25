/*!
 *  \file    AItSetsSubtraction.hpp Contains general template implementation
 *           of the iterator subtraction of two sets algorithm.
 *  \brief   Iterator subtraction of two sets algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator subtraction of two sets algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   18.08.2007 03:57:00

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
#ifndef __AITSETSSUBTRACTION_HPP__
#define __AITSETSSUBTRACTION_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
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
//! Algorithm: Forward subtraction two set sequences.
/*!
    Algorithm subtracts forward all items from two sequences represented  with
    their forward iterators and puts them into the first one.

    Important: This algorithm requires both containers to be sorted.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \return true  - if subtraction operation completed successfully. \n
            false - if subtraction operation did not complete successfully. \n
*/
template <class T_Iterator1, class T_Iterator2>
Tbool setsSubtractionNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward subtraction two set sequences using 'LessThan' predicate.
/*!
    Algorithm subtracts forward all items from two sequences represented  with
    their forward iterators and puts them into the first one.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    Important: This algorithm requires both containers to be sorted.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return true  - if subtraction operation completed successfully. \n
            false - if subtraction operation did not complete successfully. \n
*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
Tbool setsSubtractionNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fLessThan);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward subtraction two set sequences.
/*!
    Algorithm subtracts backward all items from two sequences represented with
    their forward iterators and puts them into the first one.

    Important: This algorithm requires both containers to be sorted.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \return true  - if subtraction operation completed successfully. \n
            false - if subtraction operation did not complete successfully. \n
*/
template <class T_Iterator1, class T_Iterator2>
Tbool setsSubtractionPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward subtraction two set sequences using 'LessThan' predicate.
/*!
    Algorithm subtracts backward all items from two sequences represented with
    their forward iterators and puts them into the first one.

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    Important: This algorithm requires both containers to be sorted.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return true  - if subtraction operation completed successfully. \n
            false - if subtraction operation did not complete successfully. \n
*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
Tbool setsSubtractionPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItSetsSubtraction.inl>
/*==========================================================================*/
#endif
