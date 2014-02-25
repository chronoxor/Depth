/*!
 *  \file    AItSearchBreadth.hpp Contains template implementations of the
 *           tree breadth search algorithms.
 *  \brief   Tree breadth search algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree breadth search algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template tree iterators algorithms
    VERSION:   1.0
    CREATED:   14.07.2006 03:35:24

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
#ifndef __AITSEARCHBREADTH_HPP__
#define __AITSEARCHBREADTH_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/containers/iterators/CTreeIteratorBreadthNext.hpp>
#include <Depth/include/containers/iterators/CTreeIteratorBreadthPrev.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
namespace NTree {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Tree breadth next search for the first iterator with given value.
/*!
    Algorithm searches tree with breadth next strategy for the first  iterator
    with  given  value.  It  implements  searching  in  tree  container  which
    represented with given tree iterator.  It  stops  searching  process  when
    iterator cannot step forward any more.

    \param a_crTreeIterator - Constant reference to the tree iterator.
    \param a_crValue - Constant reference to the searching value.
    \return Tree iterator to the found value, or invalid iterator.
*/
template <class T_TreeIterator, typename T_ValueType>
T_TreeIterator searchBreadthNext(const T_TreeIterator& a_crTreeIterator, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tree breadth next search for the first iterator with given value using 'Equal' predicate.
/*!
    Algorithm searches tree with breadth next strategy for the first  iterator
    with  given  value.  It  implements  searching  in  tree  container  which
    represented with given tree iterator.  It  stops  searching  process  when
    iterator cannot step forward any more.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crTreeIterator - Constant reference to the tree iterator.
    \param a_crValue - Constant reference to the searching value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Tree iterator to the found value, or invalid iterator.
*/
template <typename T_TreeIterator, typename T_ValueType, typename T_BinaryPredicate>
T_TreeIterator searchBreadthNext(const T_TreeIterator& a_crTreeIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tree breadth previous search for the first iterator with given value.
/*!
    Algorithm searches tree with  breadth  previous  strategy  for  the  first
    iterator with given value. It implements searching in tree container which
    represented with given tree iterator.  It  stops  searching  process  when
    iterator cannot step forward any more.

    \param a_crTreeIterator - Constant reference to the tree iterator.
    \param a_crValue - Constant reference to the searching value.
    \return Tree iterator to the found value, or invalid iterator.
*/
template <typename T_TreeIterator, typename T_ValueType>
T_TreeIterator searchBreadthPrev(const T_TreeIterator& a_crTreeIterator, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tree breadth previous search for the first iterator with given value using 'Equal' predicate.
/*!
    Algorithm searches tree with  breadth  previous  strategy  for  the  first
    iterator with given value. It implements searching in tree container which
    represented with given tree iterator.  It  stops  searching  process  when
    iterator cannot step forward any more.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    \param a_crTreeIterator - Constant reference to the tree iterator.
    \param a_crValue - Constant reference to the searching value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Tree iterator to the found value, or invalid iterator.
*/
template <typename T_TreeIterator, typename T_ValueType, typename T_BinaryPredicate>
T_TreeIterator searchBreadthPrev(const T_TreeIterator& a_crTreeIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/tree/AItSearchBreadth.inl>
/*==========================================================================*/
#endif
