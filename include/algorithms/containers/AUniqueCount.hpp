/*!
 *  \file    AUniqueCount.hpp Contains general template implementation of the
 *           container get count of the unique items algorithm.
 *  \brief   Container get count of the unique items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container get count of the unique items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   01.06.2007 20:28:35

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
#ifndef __AUNIQUECOUNT_HPP__
#define __AUNIQUECOUNT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItUniqueCount.hpp>
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
//! Algorithm: Container get count of the unique items.
/*!
    \param a_rContainer - Reference to the container.
    \return Count of unique items.
    \see NDepth::NAlgorithms::NIterators::uniqueCountNext()
    \see NDepth::NAlgorithms::NIterators::uniqueCountPrev()
*/
template <class T_Container>
Tuint uniqueCount(T_Container& a_rContainer);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container get count of the unique items using 'Equal' predicate.
/*!
    \param a_rContainer - Reference to the container.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of unique items.
    \see NDepth::NAlgorithms::NIterators::uniqueCountNext()
    \see NDepth::NAlgorithms::NIterators::uniqueCountPrev()
*/
template <class T_Container, typename T_BinaryPredicate>
Tuint uniqueCount(T_Container& a_rContainer, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AUniqueCount.inl>
/*==========================================================================*/
#endif
