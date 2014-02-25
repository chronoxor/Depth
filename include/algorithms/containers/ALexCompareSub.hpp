/*!
 *  \file    ALexCompareSub.hpp Contains general template implementation of
 *           the container two subsequences lexicographical compare algorithm.
 *  \brief   Container two subsequences lexicographical compare algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container two subsequences lexicographical compare algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   31.03.2007 22:45:29

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
#ifndef __ALEXCOMPARESUB_HPP__
#define __ALEXCOMPARESUB_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItLexCompareSub.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Container two subsequences lexicographical compare.
/*!
    \param a_rContainer1 - Reference to the first container.
    \param a_rContainer2 - Reference to the second container.
    \return One of the following values: \n
            <0 - if first subsequence is lexicographically less than second one. \n
            =0 - if first subsequence is lexicographically equal than second one. \n
            >0 - if first subsequence is lexicographically greater than second one. \n
    \see NDepth::NAlgorithms::NIterators::lexCompareSubNext()
    \see NDepth::NAlgorithms::NIterators::lexCompareSubPrev()
*/
template <class T_Container1, class T_Container2>
Tsint lexCompareSub(T_Container1& a_rContainer1, T_Container2& a_rContainer2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container two subsequences lexicographical compare using binary comparator function.
/*!
    In this algorithm binary comparator function should return value less than
    0 if X < Y, value 0 if X is equal to Y, value greater than 0 if X > Y.

    \param a_rContainer1 - Reference to the first container.
    \param a_rContainer2 - Reference to the second container.
    \param a_fComparator - Binary comparator function.
    \return One of the following values: \n
            <0 - if first subsequence is lexicographically less than second one. \n
            =0 - if first subsequence is lexicographically equal than second one. \n
            >0 - if first subsequence is lexicographically greater than second one. \n
    \see NDepth::NAlgorithms::NIterators::lexCompareSubNext()
    \see NDepth::NAlgorithms::NIterators::lexCompareSubPrev()
*/
template <class T_Container1, class T_Container2, typename T_Comparator>
Tsint lexCompareSub(T_Container1& a_rContainer1, T_Container2& a_rContainer2, T_Comparator a_fComparator);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ALexCompareSub.inl>
/*==========================================================================*/
#endif
