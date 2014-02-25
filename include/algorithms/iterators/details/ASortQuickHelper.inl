/*!
 *  \file    ASortQuickHelper.inl Contains template implementations of the
 *           iterator quick sort helper algorithm.
 *  \brief   Iterator quick sort helper algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator quick sort helper algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   23.08.2007 22:10:25

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
#ifndef __ASORTQUICKHELPER_INL__
#define __ASORTQUICKHELPER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_Iterator, typename T_BinaryPredicate>
Tbool sortQuickHelper(const T_Iterator& a_crFisrtIterator, const T_Iterator& a_crLastIterator, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an non constant backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorNonConstBackward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tbool condition = true;
  Tbool forward = false;
  T_Iterator it1(a_crFisrtIterator);
  T_Iterator it2(a_crLastIterator);

  // If nothing to sort...
  if (it1 == it2)
    return true;

  // Sorting from the left side to the right one.
  do
  {
    // Compare opposite items and if need swap them.
    if (condition == a_fLessThan(it2.getValueRef(), it1.getValueRef()))
    {
      NCommon::swap(it1.getValueRef(), it2.getValueRef());
      NCommon::swap(it1, it2);
      condition = !condition;
      forward = !forward;
    }

    // Step next with the current iterator.
    if (forward)
      it2.stepForward();
    else
      it2.stepBackward();
  } while (it1 != it2);

  // Copy current iterator.
  it2 = it1;
  // Step backward with the first iterator.
  if (it1 != a_crFisrtIterator)
    it1.stepBackward();
  // Step forward with the last iterator.
  if (it2 != a_crLastIterator)
    it2.stepForward();

  // Finish sorting.
  return (sortQuickHelper(a_crFisrtIterator, it1, a_fLessThan) && sortQuickHelper(it2, a_crLastIterator, a_fLessThan));
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
