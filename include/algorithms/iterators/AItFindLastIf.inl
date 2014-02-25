/*!
 *  \file    AItFindLastIf.inl Contains general template implementation of
 *           the find last algorithm with given unary 'If' predicate.
 *  \brief   Find last algorithm with given unary 'If' predicate (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find last algorithm with given unary 'If' predicate (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   13.04.2007 23:26:43

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
#ifndef __AITFINDLASTIF_INL__
#define __AITFINDLASTIF_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_Iterator, typename T_UnaryIfPredicate>
inline T_Iterator findLastIfNext(const T_Iterator& a_crIterator, T_UnaryIfPredicate a_fIf)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_UnaryIfPredicate type constraint to be a suitable unary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate1<T_UnaryIfPredicate, const typename T_Iterator::TReturn&> >();

  // Find the first value.
  T_Iterator first;
  T_Iterator result;
  T_Iterator it(findIfNext(a_crIterator, a_fIf));
  Tbool resume(it.isValid());

  // Try to find other values.
  first = it;
  while (resume)
  {
    // Move to the next value.
    result = it;
    if ((it.stepForward() == 0) || (it == a_crIterator))
    {
      resume = false;
      break;
    }

    // Skip the same values.
    while (resume)
    {
      if (!a_fIf(it.getValueRef()))
        break;
      result = it;
      if ((it.stepForward() == 0) || (it == a_crIterator))
      {
        resume = false;
        break;
      }
    }

    // Find the next value.
    if (resume)
    {
      it = findIfNext(it, a_fIf);
      resume = (it.isValid() && (it != first));
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType, typename T_UnaryIfPredicate>
inline T_Iterator findLastIfPrev(const T_Iterator& a_crIterator, T_UnaryIfPredicate a_fIf)
{ CALL
  return findLastIfNext(reverseIt(a_crIterator), a_fIf);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
