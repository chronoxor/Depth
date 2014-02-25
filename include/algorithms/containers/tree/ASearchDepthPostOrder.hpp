/*!
 *  \file    ASearchDepthPostOrder.hpp Contains template implementations of
 *           the tree container depth post-order search algorithms.
 *  \brief   Tree container depth post-order search algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree container depth post-order search algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template tree containers algorithms
    VERSION:   1.0
    CREATED:   29.03.2007 21:38:40

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
#ifndef __ASEARCHDEPTHPOSTORDER_HPP__
#define __ASEARCHDEPTHPOSTORDER_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/tree/AGetItLeftmostChild.hpp>
#include <Depth/include/algorithms/iterators/tree/AItSearchDepthPostOrder.hpp>
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
//! Algorithm: Tree container depth post-order search for the first iterator with given value.
/*!
    \param a_rTreeContainer - Reference to the tree container.
    \param a_crValue - Constant reference to the searching value.
    \return Tree iterator to the found value, or invalid iterator.
    \see NDepth::NAlgorithms::NIterators::NTree::searchDepthPostOrderNext()
    \see NDepth::NAlgorithms::NIterators::NTree::searchDepthPostOrderPrev()
*/
template <class T_TreeContainer, typename T_ValueType>
typename NTraits::MTraitsContainer<T_TreeContainer>::iterator searchDepthPostOrder(T_TreeContainer& a_rTreeContainer, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tree container depth post-order search for the first iterator with given value using 'Equal' predicate.
/*!
    \param a_rTreeContainer - Reference to the tree container.
    \param a_crValue - Constant reference to the searching value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Tree iterator to the found value, or invalid iterator.
    \see NDepth::NAlgorithms::NIterators::NTree::searchDepthPostOrderNext()
    \see NDepth::NAlgorithms::NIterators::NTree::searchDepthPostOrderPrev()
*/
template <typename T_TreeContainer, typename T_ValueType, typename T_BinaryPredicate>
typename NTraits::MTraitsContainer<T_TreeContainer>::iterator searchDepthPostOrder(T_TreeContainer& a_rTreeContainer, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/tree/ASearchDepthPostOrder.inl>
/*==========================================================================*/
#endif
