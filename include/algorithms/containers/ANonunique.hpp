/*!
 *  \file    ANonunique.hpp Contains general template implementation of the
 *           container non unique all items algorithm.
 *  \brief   Container non unique all items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container non unique all items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   05.06.2007 03:49:33

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
#ifndef __ANONUNIQUE_HPP__
#define __ANONUNIQUE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItNonunique.hpp>
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
//! Algorithm: Container non unique all items.
/*!
    \param a_rContainer - Reference to the container.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return true  - if non unique operation successfully completed for all items in the container. \n
            false - if non unique operation did not successfully complete for all items in the container. \n
    \see NDepth::NAlgorithms::NIterators::nonuniqueNext()
    \see NDepth::NAlgorithms::NIterators::nonuniquePrev()
*/
template <class T_Container>
Tbool nonunique(T_Container& a_rContainer, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*--------------------------------------------------------------------------*/
//! Algorithm: Container non unique all items using 'Equal' predicate.
/*!
    \param a_rContainer - Reference to the container.
    \param a_fEqual - 'Equal' binary predicate.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return true  - if non unique operation successfully completed for all items in the container. \n
            false - if non unique operation did not successfully complete for all items in the container. \n
    \see NDepth::NAlgorithms::NIterators::nonuniqueNext()
    \see NDepth::NAlgorithms::NIterators::nonuniquePrev()
*/
template <class T_Container, typename T_BinaryPredicate>
Tbool nonunique(T_Container& a_rContainer, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ANonunique.inl>
/*==========================================================================*/
//! \example example-algorithms-ANonunique.cpp
/*--------------------------------------------------------------------------*/
//! \test test-algorithms-ANonunique.cpp
/*==========================================================================*/
#endif
