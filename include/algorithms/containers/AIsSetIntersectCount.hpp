/*!
 *  \file    AIsSetIntersectCount.hpp Contains general template
 *           implementation of the container check and get count
 *           of the two sets intersection algorithm.
 *  \brief   Container check and get count of the two sets intersection algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container check and get count of the two sets intersection algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   24.05.2007 21:36:22

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
#ifndef __AISSETINTERSECTCOUNT_HPP__
#define __AISSETINTERSECTCOUNT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItIsSetIntersectCount.hpp>
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
//! Algorithm: Check if two sorted set containers are intersect each other and get count of the intersected items.
/*!
    \param a_rContainer1 - Reference to the first container.
    \param a_rContainer2 - Reference to the second container.
    \return Count of the intersected items of 0.
    \see NDepth::NAlgorithms::NIterators::isSetIntersectCheckNext()
    \see NDepth::NAlgorithms::NIterators::isSetIntersectCheckPrev()
*/
template <class T_Container1, class T_Container2>
Tuint isSetIntersectCount(T_Container1& a_rContainer1, T_Container2& a_rContainer2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Check if two sorted set containers are intersect each other and get count of the intersected items using 'LessThan' predicate.
/*!
    \param a_rContainer1 - Reference to the first container.
    \param a_rContainer2 - Reference to the second container.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Count of the intersected items of 0.
    \see NDepth::NAlgorithms::NIterators::isSetIntersectCheckNext()
    \see NDepth::NAlgorithms::NIterators::isSetIntersectCheckPrev()
*/
template <class T_Container1, class T_Container2, typename T_BinaryPredicate>
Tuint isSetIntersectCount(T_Container1& a_rContainer1, T_Container2& a_rContainer2, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AIsSetIntersectCount.inl>
/*==========================================================================*/
#endif
