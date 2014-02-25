/*!
 *  \file    ALowerBound.hpp Contains general template implementation of the
 *           container lower bound searching algorithm.
 *  \brief   Container lower bound searching algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container lower bound searching algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   31.03.2007 01:14:35

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
#ifndef __ALOWERBOUND_HPP__
#define __ALOWERBOUND_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItLowerBound.hpp>
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
//! Algorithm: Container lower bound searching.
/*!
    \param a_rContainer - Reference to the container.
    \param a_crValue - Constant reference to the lower bound searching value.
    \return Forward iterator to the lower bound value, or invalid iterator.
    \see NDepth::NAlgorithms::NIterators::lowerBoundNext()
    \see NDepth::NAlgorithms::NIterators::lowerBoundPrev()
*/
template <class T_Container, typename T_ValueType>
typename NTraits::MTraitsContainer<T_Container>::iterator lowerBound(T_Container& a_rContainer, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container lower bound searching using 'LessThan' predicate.
/*!
    \param a_rContainer - Reference to the container.
    \param a_crValue - Constant reference to the lower bound searching value.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Forward iterator to the lower bound value, or invalid iterator.
    \see NDepth::NAlgorithms::NIterators::lowerBoundNext()
    \see NDepth::NAlgorithms::NIterators::lowerBoundPrev()
*/
template <class T_Container, typename T_ValueType, typename T_BinaryPredicate>
typename NTraits::MTraitsContainer<T_Container>::iterator lowerBound(T_Container& a_rContainer, const T_ValueType& a_crValue, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ALowerBound.inl>
/*==========================================================================*/
//! \example example-algorithms-ALowerBound.cpp
/*--------------------------------------------------------------------------*/
//! \test test-algorithms-ALowerBound.cpp
/*==========================================================================*/
#endif
