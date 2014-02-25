/*!
 *  \file    AFillN.hpp Contains general template implementation of the
 *           container fill N items algorithm.
 *  \brief   Container fill N items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container fill N items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   22.05.2007 22:44:15

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
#ifndef __AFILLN_HPP__
#define __AFILLN_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItFillN.hpp>
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
//! Algorithm: Fill N container's items with the given value.
/*!
    Algorithm fills N items in the given  container.  If  container  has  less
    items than N, new items will be created if possible.

    \param a_rContainer - Reference to the container.
    \param a_cN - Count of requested items to fill.
    \param a_crValue - Constant reference to the filled value.
    \return Count of filled items.
    \see NDepth::NAlgorithms::NIterators::fillNNext()
    \see NDepth::NAlgorithms::NIterators::fillNPrev()
*/
template <class T_Container, typename T_ValueType>
Tuint fillN(T_Container& a_rContainer, const Tuint a_cN, const T_ValueType& a_crValue);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AFillN.inl>
/*==========================================================================*/
//! \example example-algorithms-AFillN.cpp
/*--------------------------------------------------------------------------*/
//! \test test-algorithms-AFillN.cpp
/*==========================================================================*/
#endif
