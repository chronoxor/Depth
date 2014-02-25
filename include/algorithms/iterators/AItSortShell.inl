/*!
 *  \file    AItSortShell.inl Contains general template implementation of
 *           the iterator shell sort algorithm.
 *  \brief   Iterator shell sort algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator shell sort algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   19.08.2007 23:57:14

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
#ifndef __AITSORTSHELL_INL__
#define __AITSORTSHELL_INL__
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
inline Tbool sortShellNext(const T_Iterator& a_crIterator)
{ CALL
  return sortShellNext(a_crIterator, NFunctions::FBoolLessThan<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline Tbool sortShellNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an non constant forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorNonConstForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tuint distance = distanceNext(a_crIterator) + 1;
  Tuint length = distance;
  Tuint counter1;
  Tuint counter2;
  T_Iterator it1(a_crIterator);
  T_Iterator it2;

  while (distance > 1)
  {
    // Short the sorting distance.
    distance /= 2;
    // Init begin iterator.
    it1 = a_crIterator;
    // Go 'forward' from begin.
    counter1 = 0;
    do
    {
      it2 = it1;
      // Go 'forward' from current.
      counter2 = counter1 + distance;
      while ((counter2 < length) && (it2.stepForward(distance) == distance))
      {
        counter2 += distance;
        // Compare two neighbor items and if need swap them.
        if (a_fLessThan(it2.getValueRef(), it1.getValueRef()))
          NCommon::swap(it1.getValueRef(), it2.getValueRef());
      }
      counter1 += distance;
    } while ((counter1 < length) && (it1.stepForward(distance) == distance));
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline Tbool sortShellPrev(const T_Iterator& a_crIterator)
{ CALL
  return sortShellPrev(a_crIterator, NFunctions::FBoolLessThan<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline Tbool sortShellPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an non constant backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorNonConstBackward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tuint distance = distancePrev(a_crIterator) + 1;
  Tuint length = distance;
  Tuint current = length;
  Tuint counter1;
  Tuint counter2;
  T_Iterator it1(a_crIterator);
  T_Iterator it2;

  while (distance > 1)
  {
    // Short the sorting distance.
    distance /= 2;
    // Init end iterator.
    it1 = a_crIterator;
    // Go 'backward' from end.
    counter1 = 0;
    do
    {
      it2 = it1;
      // Go 'backward' from current.
      counter2 = counter1 + distance;
      while ((counter2 < length) && (it2.stepBackward(distance) == distance))
      {
        counter2 += distance;
        // Compare two neighbor items and if need swap them.
        if (a_fLessThan(it1.getValueRef(), it2.getValueRef()))
          NCommon::swap(it1.getValueRef(), it2.getValueRef());
      }
      counter1 += distance;
    } while ((counter1 < length) && (it1.stepBackward(distance) == distance));
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
