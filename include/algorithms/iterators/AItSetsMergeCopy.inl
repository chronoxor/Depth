/*!
 *  \file    AItSetsMergeCopy.inl Contains general template implementation of
 *           the iterator merge and copy of two sets algorithm.
 *  \brief   Iterator merge and copy of two sets algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator merge and copy of two sets algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   18.08.2007 02:14:34

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
#ifndef __AITSETSMERGECOPY_INL__
#define __AITSETSMERGECOPY_INL__
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
template <class T_Iterator1, class T_Iterator2, class T_IteratorCopy>
inline Tuint setsMergeCopyNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, const T_IteratorCopy& a_crIteratorCopy)
{ CALL
  return setsMergeCopyNext(a_crIterator1, a_crIterator2, a_crIteratorCopy, NFunctions::FBoolLessThan<const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2, class T_IteratorCopy, typename T_BinaryPredicate>
inline Tuint setsMergeCopyNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, const T_IteratorCopy& a_crIteratorCopy, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator1 class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator1> >();
  // Check T_Iterator2 class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator2> >();
  // Check T_IteratorCopy class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_IteratorCopy> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator2::TReturn&, const typename T_Iterator1::TReturn&> >();

  Tbool first;
  Tbool skip;
  Tuint result = 0;

  // Copy values only of valid iterators.
  T_Iterator1 it1(a_crIterator1);
  T_Iterator2 it2(a_crIterator2);
  T_IteratorCopy it_copy(a_crIteratorCopy);
  if ((it1.isValid() || it2.isValid()) && it_copy.isValidContainer())
  {
    // Copy sequence values.
    do
    {
      // Select current item to copy.
      skip = false;
      if (!it1.isValid())
        first = false;
      else if (!it2.isValid())
        first = true;
      else
      {
        first = a_fLessThan(it1.getValueRef(), it2.getValueRef());
        skip = (!first && !a_fLessThan(it2.getValueRef(), it1.getValueRef()));
      }

      // Copy current item.
      if (it_copy.isValid())
      {
        if (!it_copy.insertNext(first ? it1.getValueRef() : it2.getValueRef()) || (it_copy.stepForward() == 0))
          return result;
      }
      else
      {
        if (!it_copy.insertBackward(first ? it1.getValueRef() : it2.getValueRef()))
          return result;
      }
      ++result;

      // Switch to the next item.
      if (first || skip)
      {
        if ((it1.stepForward() == 0) || (it1 == a_crIterator1))
          it1 = T_Iterator1();
      }
      if (!first || skip)
      {
        if ((it2.stepForward() == 0) || (it2 == a_crIterator2))
          it2 = T_Iterator2();
      }
    } while (it1.isValid() || it2.isValid());
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2, class T_IteratorCopy>
inline Tuint setsMergeCopyPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, const T_IteratorCopy& a_crIteratorCopy)
{ CALL
  return setsMergeCopyPrev(a_crIterator1, a_crIterator2, a_crIteratorCopy, NFunctions::FBoolLessThan<const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2, class T_IteratorCopy, typename T_BinaryPredicate>
inline Tuint setsMergeCopyPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, const T_IteratorCopy& a_crIteratorCopy, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator1 class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator1> >();
  // Check T_Iterator2 class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator2> >();
  // Check T_IteratorCopy class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_IteratorCopy> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator2::TReturn&, const typename T_Iterator1::TReturn&> >();

  Tbool first;
  Tbool skip;
  Tuint result = 0;

  // Copy values only of valid iterators.
  T_Iterator1 it1(a_crIterator1);
  T_Iterator2 it2(a_crIterator2);
  T_IteratorCopy it_copy(a_crIteratorCopy);
  if ((it1.isValid() || it2.isValid()) && it_copy.isValidContainer())
  {
    // Copy sequence values.
    do
    {
      // Select current item to copy.
      skip = false;
      if (!it1.isValid())
        first = false;
      else if (!it2.isValid())
        first = true;
      else
      {
        first = a_fLessThan(it2.getValueRef(), it1.getValueRef());
        skip = (!first && !a_fLessThan(it1.getValueRef(), it2.getValueRef()));
      }

      // Copy current item.
      if (it_copy.isValid())
      {
        if (!it_copy.insertPrev(first ? it1.getValueRef() : it2.getValueRef()) || (it_copy.stepBackward() == 0))
          return result;
      }
      else
      {
        if (!it_copy.insertForward(first ? it1.getValueRef() : it2.getValueRef()))
          return result;
      }
      ++result;

      // Switch to the previous item.
      if (first || skip)
      {
        if ((it1.stepBackward() == 0) || (it1 == a_crIterator1))
          it1 = T_Iterator1();
      }
      if (!first || skip)
      {
        if ((it2.stepBackward() == 0) || (it2 == a_crIterator2))
          it2 = T_Iterator2();
      }
    } while (it1.isValid() || it2.isValid());
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
