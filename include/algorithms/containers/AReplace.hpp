/*!
 *  \file    AReplace.hpp Contains general template implementation of the
 *           container replace algorithm.
 *  \brief   Container replace algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container replace algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   11.06.2007 22:52:38

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
#ifndef __AREPLACE_HPP__
#define __AREPLACE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItReplace.hpp>
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
//! Algorithm: Replace all container's items with the given value.
/*!
    \param a_rContainer - Reference to the container.
    \param a_crOldValue - Constant reference to the old searched value.
    \param a_crNewValue - Constant reference to the new replaced value.
    \return Count of replaced items.
    \see NDepth::NAlgorithms::NIterators::replaceNext()
    \see NDepth::NAlgorithms::NIterators::replacePrev()
*/
template <class T_Container, typename T_OldValueType, typename T_NewValueType>
Tuint replace(T_Container& a_rContainer, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Replace all container's items with the given value using 'Equal' predicate.
/*!
    \param a_rContainer - Reference to the container.
    \param a_crOldValue - Constant reference to the old searched value.
    \param a_crNewValue - Constant reference to the new replaced value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of replaced items.
    \see NDepth::NAlgorithms::NIterators::replaceNext()
    \see NDepth::NAlgorithms::NIterators::replacePrev()
*/
template <class T_Container, typename T_OldValueType, typename T_NewValueType, typename T_BinaryPredicate>
Tuint replace(T_Container& a_rContainer, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AReplace.inl>
/*==========================================================================*/
//! \example example-algorithms-AReplace.cpp
/*--------------------------------------------------------------------------*/
//! \test test-algorithms-AReplace.cpp
/*==========================================================================*/
#endif
