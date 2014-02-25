/*!
 *  \file    AItSearchBreadth.inl Contains template implementations of the
 *           tree breadth search algorithms.
 *  \brief   Tree breadth search algorithms (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree breadth search algorithms (inline).

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
#ifndef __AITSEARCHBREADTH_INL__
#define __AITSEARCHBREADTH_INL__
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
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_TreeIterator, typename T_ValueType>
inline T_TreeIterator searchBreadthNext(const T_TreeIterator& a_crTreeIterator, const T_ValueType& a_crValue)
{ CALL
  return searchBreadthNext(a_crTreeIterator, a_crValue, NFunctions::FBoolEqual<typename T_TreeIterator::TReturn&, const T_ValueType&>());
}
/*--------------------------------------------------------------------------*/
template <typename T_TreeIterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_TreeIterator searchBreadthNext(const T_TreeIterator& a_crTreeIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_TreeIterator class constraint to be an any move tree iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorMoveTree<T_TreeIterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, typename T_TreeIterator::TReturn&, const T_ValueType&> >();

  NDepth::NContainers::NIterators::CTreeIteratorBreadthNext<T_TreeIterator> it(a_crTreeIterator);

  // Check if the iterator is in the valid state.
  ASSERT(it.isValid(), STR("Cannot perform the algorithm to the the invalid tree iterator."))
  {
    return T_TreeIterator();
  }

  do
  {
    if (a_fEqual(it.getValueRef(), a_crValue))
      return T_TreeIterator(it);
  } while (it.stepForward() > 0);

  // If nothing was found, than return invalid iterator.
  return T_TreeIterator();
}
/*--------------------------------------------------------------------------*/
template <typename T_TreeIterator, typename T_ValueType>
inline T_TreeIterator searchBreadthPrev(const T_TreeIterator& a_crTreeIterator, const T_ValueType& a_crValue)
{ CALL
  return searchBreadthPrev(a_crTreeIterator, a_crValue, NFunctions::FBoolEqual<typename T_TreeIterator::TReturn&, const T_ValueType&>());
}
/*--------------------------------------------------------------------------*/
template <typename T_TreeIterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_TreeIterator searchBreadthPrev(const T_TreeIterator& a_crTreeIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_TreeIterator class constraint to be an any move tree iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorMoveTree<T_TreeIterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, typename T_TreeIterator::TReturn&, const T_ValueType&> >();

  NDepth::NContainers::NIterators::CTreeIteratorBreadthPrev<T_TreeIterator> it(a_crTreeIterator);

  // Check if the iterator is in the valid state.
  ASSERT(it.isValid(), STR("Cannot perform the algorithm to the the invalid tree iterator."))
  {
    return T_TreeIterator();
  }

  do
  {
    if (a_fEqual(it.getValueRef(), a_crValue))
      return T_TreeIterator(it);
  } while (it.stepForward() > 0);

  // If nothing was found, than return invalid iterator.
  return T_TreeIterator();
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
