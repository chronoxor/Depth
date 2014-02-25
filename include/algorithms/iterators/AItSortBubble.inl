/*!
 *  \file    AItSortBubble.inl Contains general template implementation of
 *           the iterator bubble sort algorithm.
 *  \brief   Iterator bubble sort algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator bubble sort algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   19.08.2007 23:38:01

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
#ifndef __AITSORTBUBBLE_INL__
#define __AITSORTBUBBLE_INL__
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
template <class T_Iterator>
inline Tbool sortBubbleNext(const T_Iterator& a_crIterator)
{ CALL
  return sortBubbleNext(a_crIterator, NFunctions::FBoolLessThan<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline Tbool sortBubbleNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an non constant forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorNonConstForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  // Sort only valid iterators.
  T_Iterator it1(a_crIterator);
  T_Iterator it2;
  if (it1.isValid())
  {
    // Go 'forward' from begin.
    do
    {
      it2 = it1;
      // Go 'forward' from current.
      while ((it2.stepForward() > 0) && (it2 != a_crIterator))
      {
        // Compare two neighbor items and if need swap them.
        if (a_fLessThan(it2.getValueRef(), it1.getValueRef()))
          NCommon::swap(it1.getValueRef(), it2.getValueRef());
      }
    } while ((it1.stepForward() > 0) && (it1 != a_crIterator));
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline Tbool sortBubblePrev(const T_Iterator& a_crIterator)
{ CALL
  return sortBubblePrev(a_crIterator, NFunctions::FBoolLessThan<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline Tbool sortBubblePrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an non constant backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorNonConstBackward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  // Sort only valid iterators.
  T_Iterator it1(a_crIterator);
  T_Iterator it2;
  if (it1.isValid())
  {
    // Go 'backward' from end.
    do
    {
      it2 = it1;
      // Go 'backward' from current.
      while ((it2.stepBackward() > 0) && (it2 != a_crIterator))
      {
        // Compare two neighbor items and if need swap them.
        if (a_fLessThan(it1.getValueRef(), it2.getValueRef()))
          NCommon::swap(it1.getValueRef(), it2.getValueRef());
      }
    } while ((it1.stepBackward() > 0) && (it1 != a_crIterator));
  }
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
