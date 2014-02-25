/*!
 *  \file    ASearchDepthPreOrder.inl Contains template implementations of
 *           the tree container depth pre-order search algorithms.
 *  \brief   Tree container depth pre-order search algorithms (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree container depth pre-order search algorithms (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template tree containers algorithms
    VERSION:   1.0
    CREATED:   29.03.2007 21:40:31

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
#ifndef __ASEARCHDEPTHPREORDER_INL__
#define __ASEARCHDEPTHPREORDER_INL__
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
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_TreeContainer, typename T_ValueType>
inline typename NTraits::MTraitsContainer<T_TreeContainer>::iterator searchDepthPreOrder(T_TreeContainer& a_rTreeContainer, const T_ValueType& a_crValue)
{ CALL
  return NIterators::NTree::searchDepthPreOrderNext(getItLeftmostChild(a_rTreeContainer), a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_TreeContainer, typename T_ValueType, typename T_BinaryPredicate>
inline typename NTraits::MTraitsContainer<T_TreeContainer>::iterator searchDepthPreOrder(T_TreeContainer& a_rTreeContainer, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual)
{ CALL
  return NIterators::NTree::searchDepthPreOrderNext(getItLeftmostChild(a_rTreeContainer), a_crValue, a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
