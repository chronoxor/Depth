/*!
 *  \file    AUnique.hpp Contains general template implementation of the
 *           container unique all items algorithm.
 *  \brief   Container unique all items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container unique all items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   01.06.2007 20:19:52

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
#ifndef __AUNIQUE_HPP__
#define __AUNIQUE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItUnique.hpp>
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
//! Algorithm: Container unique all items.
/*!
    \param a_rContainer - Reference to the container.
    \return true  - if unique operation successfully completed for all items in the container. \n
            false - if unique operation did not successfully complete for all items in the container. \n
    \see NDepth::NAlgorithms::NIterators::uniqueNext()
    \see NDepth::NAlgorithms::NIterators::uniquePrev()
*/
template <class T_Container>
Tbool unique(T_Container& a_rContainer);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container unique all items using 'Equal' predicate.
/*!
    \param a_rContainer - Reference to the container.
    \param a_fEqual - 'Equal' binary predicate.
    \return true  - if unique operation successfully completed for all items in the container. \n
            false - if unique operation did not successfully complete for all items in the container. \n
    \see NDepth::NAlgorithms::NIterators::uniqueNext()
    \see NDepth::NAlgorithms::NIterators::uniquePrev()
*/
template <class T_Container, typename T_BinaryPredicate>
Tbool unique(T_Container& a_rContainer, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AUnique.inl>
/*==========================================================================*/
//! \example example-algorithms-AUnique.cpp
/*--------------------------------------------------------------------------*/
//! \test test-algorithms-AUnique.cpp
/*==========================================================================*/
#endif
