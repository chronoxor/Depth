/*!
 *  \file    AItLexCompare.hpp Contains general template implementation of the
 *           iterator two sequences lexicographical compare algorithm.
 *  \brief   Iterator two sequences lexicographical compare algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator two sequences lexicographical compare algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   15.09.2006 20:53:25

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
#ifndef __AITLEXCOMPARE_HPP__
#define __AITLEXCOMPARE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/algorithms/functions/FComparator.hpp>
#include <Depth/include/concept/functions/MConceptFunction2.hpp>
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
//! Algorithm: Forward iterator two sequences lexicographical compare.
/*!
    Algorithm lexicographical compares two sequences  represented  with  their
    forward iterators.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \return One of the following values: \n
            <0 - if first sequence is lexicographically less than second one. \n
            =0 - if first sequence is lexicographically equal than second one. \n
            >0 - if first sequence is lexicographically greater than second one. \n
*/
template <class T_Iterator1, class T_Iterator2>
Tsint lexCompareNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator two sequences lexicographical compare using binary comparator function.
/*!
    Algorithm lexicographical compares two sequences  represented  with  their
    forward iterators.

    In this algorithm binary comparator function should return value less than
    0 if X < Y, value 0 if X is equal to Y, value greater than 0 if X > Y.

    \param a_crIterator1 - Constant reference to the first sequence's forward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's forward iterator.
    \param a_fComparator - Binary comparator function.
    \return One of the following values: \n
            <0 - if first sequence is lexicographically less than second one. \n
            =0 - if first sequence is lexicographically equal than second one. \n
            >0 - if first sequence is lexicographically greater than second one. \n
*/
template <class T_Iterator1, class T_Iterator2, typename T_Comparator>
Tsint lexCompareNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_Comparator a_fComparator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator two sequences lexicographical compare.
/*!
    Algorithm lexicographical compares two sequences  represented  with  their
    backward iterators.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \return One of the following values: \n
            <0 - if first sequence is lexicographically less than second one. \n
            =0 - if first sequence is lexicographically equal than second one. \n
            >0 - if first sequence is lexicographically greater than second one. \n
*/
template <class T_Iterator1, class T_Iterator2>
Tsint lexComparePrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator two sequences lexicographical compare using binary comparator function.
/*!
    Algorithm lexicographical compares two sequences  represented  with  their
    backward iterators.

    In this algorithm binary comparator function should return value less than
    0 if X < Y, value 0 if X is equal to Y, value greater than 0 if X > Y.

    \param a_crIterator1 - Constant reference to the first sequence's backward iterator.
    \param a_crIterator2 - Constant reference to the second sequence's backward iterator.
    \param a_fComparator - Binary comparator function.
    \return One of the following values: \n
            <0 - if first sequence is lexicographically less than second one. \n
            =0 - if first sequence is lexicographically equal than second one. \n
            >0 - if first sequence is lexicographically greater than second one. \n
*/
template <class T_Iterator1, class T_Iterator2, typename T_Comparator>
Tsint lexComparePrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_Comparator a_fComparator);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItLexCompare.inl>
/*==========================================================================*/
#endif
