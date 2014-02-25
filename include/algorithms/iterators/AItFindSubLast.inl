/*!
 *  \file    AItFindSubLast.inl Contains general template implementation of
 *           the find last subsequence algorithm.
 *  \brief   Find last subsequence algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find last subsequence algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   18.04.2007 22:55:27

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
#ifndef __AITFINDSUBLAST_INL__
#define __AITFINDSUBLAST_INL__
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
template <class T_Iterator, class T_SubsequenceIterator>
inline T_Iterator findSubLastNext(const T_Iterator& a_crIterator, const T_SubsequenceIterator& a_crSubsequenceIterator)
{ CALL
  return findSubLastNext(a_crIterator, a_crSubsequenceIterator, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_SubsequenceIterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_SubsequenceIterator, typename T_BinaryPredicate>
inline T_Iterator findSubLastNext(const T_Iterator& a_crIterator, const T_SubsequenceIterator& a_crSubsequenceIterator, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_SubsequenceIterator::TReturn&> >();

  // For invalid main iterator return the invalid one.
  if (!a_crIterator.isValid())
    return T_Iterator();
  // For invalid subsequence iterator return the first one.
  if (!a_crSubsequenceIterator.isValid())
    return a_crIterator;

  // Find the first value.
  Tuint length(distanceNext(a_crSubsequenceIterator) + 1);
  T_Iterator first;
  T_Iterator result;
  T_Iterator it(findSubNext(a_crIterator, a_crSubsequenceIterator, a_fEqual));

  // Try to find other values.
  first = it;
  while (it.isValid())
  {
    // Move to the next value.
    result = it;
    if ((it.stepForward(length) != length) || (it == a_crIterator))
      break;

    // Find the next value.
    it = findSubNext(it, a_crSubsequenceIterator, a_fEqual);
    // Check if the main sequence restarts.
    if (it == first)
      break;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_SubsequenceIterator>
inline T_Iterator findSubLastPrev(const T_Iterator& a_crIterator, const T_SubsequenceIterator& a_crSubsequenceIterator)
{ CALL
  return findSubLastNext(reverseIt(a_crIterator), reverseIt(a_crSubsequenceIterator), NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_SubsequenceIterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_SubsequenceIterator, typename T_BinaryPredicate>
inline T_Iterator findSubLastPrev(const T_Iterator& a_crIterator, const T_SubsequenceIterator& a_crSubsequenceIterator, T_BinaryPredicate a_fEqual)
{ CALL
  return findSubLastNext(reverseIt(a_crIterator), reverseIt(a_crSubsequenceIterator), a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
