/*!
 *  \file    AItSortCopy.inl Contains general template implementation of
 *           the iterator sort and copy algorithm.
 *  \brief   Iterator sort and copy algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator sort and copy algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   20.08.2007 21:06:18

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
#ifndef __AITSORTCOPY_INL__
#define __AITSORTCOPY_INL__
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
template <class T_Iterator, class T_IteratorCopy>
inline Tuint sortCopyNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy)
{ CALL
  return sortCopyNext(a_crIterator, a_crIteratorCopy, NFunctions::FBoolLessThan<const typename T_Iterator::TReturn&, const typename T_IteratorCopy::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_BinaryPredicate>
inline Tuint sortCopyNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_IteratorCopy> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_IteratorCopy::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_IteratorCopy::TReturn&, const typename T_Iterator::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_IteratorCopy::TReturn&, const typename T_IteratorCopy::TReturn&> >();

  Tbool stop;
  Tbool backward = false;
  Tuint result = 0;

  // Copy values only of valid iterators.
  T_Iterator it1(a_crIterator);
  T_IteratorCopy it2(a_crIteratorCopy);
  T_IteratorCopy it_first;
  T_IteratorCopy it_next;
  if (it1.isValid() && it2.isValidContainer())
  {
    // Copy sequence values.
    do
    {
      // Find a place to insert.
      if (it_first.isValid())
      {
        it_next = it_first;
        do
        {
          if (a_fLessThan(it1.getValueRef(), it_next.getValueRef()))
          {
            backward = true;
            // Reset first copy iterator.
            if (it_next == it_first)
              it_first = T_IteratorCopy();
            it2 = it_next;
            break;
          }
          it2 = it_next;
          stop = ((it_next.stepForward() == 0) || (it_next == it_first));
          if (!stop && a_fLessThan(it_next.getValueRef(), it2.getValueRef()) && a_fLessThan(it_next.getValueRef(), it1.getValueRef()))
            break;
        } while (!stop);
      }

      // Copy current value.
      if (it2.isValid() && !backward)
      {
        if (!it2.insertNext(it1.getValueRef()) || (it2.stepForward() == 0))
          return result;
      }
      else
      {
        backward = false;
        if (!it2.insertBackward(it1.getValueRef()))
          return result;
      }
      // Update first copy iterator.
      if (!it_first.isValid())
        it_first = it2;
      ++result;
    } while ((it1.stepForward() > 0) && (it1 != a_crIterator));
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy>
inline Tuint sortCopyPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy)
{ CALL
  return sortCopyPrev(a_crIterator, a_crIteratorCopy, NFunctions::FBoolLessThan<const typename T_Iterator::TReturn&, const typename T_IteratorCopy::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_BinaryPredicate>
inline Tuint sortCopyPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_IteratorCopy> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_IteratorCopy::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_IteratorCopy::TReturn&, const typename T_Iterator::TReturn&> >();

  Tbool stop;
  Tbool forward = false;
  Tuint result = 0;

  // Copy values only of valid iterators.
  T_Iterator it1(a_crIterator);
  T_IteratorCopy it2(a_crIteratorCopy);
  T_IteratorCopy it_last;
  T_IteratorCopy it_prev;
  if (it1.isValid() && it2.isValidContainer())
  {
    // Copy sequence values.
    do
    {
      // Find a place to insert.
      if (it_last.isValid())
      {
        it_prev = it_last;
        do
        {
          if (!a_fLessThan(it1.getValueRef(), it_prev.getValueRef()) || a_fLessThan(it_prev.getValueRef(), it1.getValueRef()))
          {
            forward = true;
            // Reset first copy iterator.
            if (it_prev == it_last)
              it_last = T_IteratorCopy();
            it2 = it_prev;
            break;
          }
          it2 = it_prev;
          stop = ((it_prev.stepBackward() == 0) || (it_prev == it_last));
          if (!stop && (!a_fLessThan(it_prev.getValueRef(), it2.getValueRef()) || a_fLessThan(it2.getValueRef(), it_prev.getValueRef())) && (!a_fLessThan(it_prev.getValueRef(), it1.getValueRef()) || a_fLessThan(it1.getValueRef(), it_prev.getValueRef())))
            break;
        } while (!stop);
      }

      // Copy current value.
      if (it2.isValid() && !forward)
      {
        if (!it2.insertPrev(it1.getValueRef()) || (it2.stepBackward() == 0))
          return result;
      }
      else
      {
        forward = false;
        if (!it2.insertForward(it1.getValueRef()))
          return result;
      }
      // Update first copy iterator.
      if (!it_last.isValid())
        it_last = it2;
      ++result;
    } while ((it1.stepBackward() > 0) && (it1 != a_crIterator));
  }
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
