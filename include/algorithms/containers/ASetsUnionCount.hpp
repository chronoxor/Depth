/*!
 *  \file    ASetsUnionCount.hpp Contains general template implementation of
 *           the container get items count of union of two sets algorithm.
 *  \brief   Container get items count of union of two sets algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container get items count of union of two sets algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   18.08.2007 00:22:25

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
#ifndef __ASETSUNIONCOUNT_HPP__
#define __ASETSUNIONCOUNT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItSetsUnionCount.hpp>
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
//! Algorithm: Container get items count of union of two set sequences.
/*!
    \param a_rContainer1 - Reference to the first sorted container.
    \param a_rContainer2 - Reference to the second sorted container.
    \return Count of union items of two sets.
    \see NDepth::NAlgorithms::NIterators::setsUnionCountNext()
    \see NDepth::NAlgorithms::NIterators::setsUnionCountPrev()
*/
template <class T_Container1, class T_Container2>
Tuint setsUnionCount(T_Container1& a_rContainer1, T_Container2& a_rContainer2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container get items count of union of two set sequences using 'LessThan' predicate.
/*!
    \param a_rContainer1 - Reference to the first sorted container.
    \param a_rContainer2 - Reference to the second sorted container.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Count of union items of two sets.
    \see NDepth::NAlgorithms::NIterators::setsUnionCountNext()
    \see NDepth::NAlgorithms::NIterators::setsUnionCountPrev()
*/
template <class T_Container1, class T_Container2, typename T_BinaryPredicate>
Tuint setsUnionCount(T_Container1& a_rContainer1, T_Container2& a_rContainer2, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ASetsUnionCount.inl>
/*==========================================================================*/
#endif
