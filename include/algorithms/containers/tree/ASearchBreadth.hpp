/*!
 *  \file    ASearchBreadth.hpp Contains template implementations of the tree
 *           container breadth search algorithms.
 *  \brief   Tree container breadth search algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree container breadth search algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template tree containers algorithms
    VERSION:   1.0
    CREATED:   29.03.2007 21:37:49

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
#ifndef __ASEARCHBREADTH_HPP__
#define __ASEARCHBREADTH_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/tree/AGetItFirstRoot.hpp>
#include <Depth/include/algorithms/iterators/tree/AItSearchBreadth.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NTree {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Tree container breadth search for the first iterator with given value.
/*!
    \param a_rTreeContainer - Reference to the tree container.
    \param a_crValue - Constant reference to the searching value.
    \return Tree iterator to the found value, or invalid iterator.
    \see NDepth::NAlgorithms::NIterators::NTree::searchBreadthNext()
    \see NDepth::NAlgorithms::NIterators::NTree::searchBreadthPrev()
*/
template <class T_TreeContainer, typename T_ValueType>
typename NTraits::MTraitsContainer<T_TreeContainer>::iterator searchBreadth(T_TreeContainer& a_rTreeContainer, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tree container breadth search for the first iterator with given value using 'Equal' predicate.
/*!
    \param a_rTreeContainer - Reference to the tree container.
    \param a_crValue - Constant reference to the searching value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Tree iterator to the found value, or invalid iterator.
    \see NDepth::NAlgorithms::NIterators::NTree::searchBreadthNext()
    \see NDepth::NAlgorithms::NIterators::NTree::searchBreadthPrev()
*/
template <typename T_TreeContainer, typename T_ValueType, typename T_BinaryPredicate>
typename NTraits::MTraitsContainer<T_TreeContainer>::iterator searchBreadth(T_TreeContainer& a_rTreeContainer, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/tree/ASearchBreadth.inl>
/*==========================================================================*/
#endif
