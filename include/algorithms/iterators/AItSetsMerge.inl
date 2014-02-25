/*!
 *  \file    AItSetsMerge.inl Contains general template implementation of the
 *           iterator merge of two sets algorithm.
 *  \brief   Iterator merge of two sets algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator merge of two sets algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   18.08.2007 03:57:00

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
#ifndef __AITSETSMERGE_INL__
#define __AITSETSMERGE_INL__
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
template <class T_Iterator1, class T_Iterator2>
inline Tbool setsMergeNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2)
{ CALL
  return setsMergeNext(a_crIterator1, a_crIterator2, NFunctions::FBoolLessThan<const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
inline Tbool setsMergeNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator1 class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator1> >();
  // Check T_Iterator1 class constraint to be an insert forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_Iterator1> >();
  // Check T_Iterator2 class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator2> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator2::TReturn&, const typename T_Iterator1::TReturn&> >();

  Tbool first;
  Tbool skip;

  // Copy values only of valid iterators.
  T_Iterator1 it1(a_crIterator1);
  T_Iterator2 it2(a_crIterator2);
  T_Iterator1 it_copy;
  if ((it1.isValid() || it2.isValid()) && it1.isValidContainer())
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
      if (!first && !skip)
      {
        if (it_copy.isValid())
        {
          if (!it_copy.insertNext(it2.getValueRef()) || (it_copy.stepForward() == 0))
            return false;
        }
        else
        {
          it_copy = it1;
          if (it_copy.isValid())
          {
            if (!it_copy.insertNext(it2.getValueRef()) || (it_copy.stepForward() == 0))
              return false;

            // Swap neighbor items.
            NCommon::swap(it1.getValueRef(), it_copy.getValueRef());
            it1 = it_copy;
          }
          else
          {
            if (!it_copy.insertBackward(it2.getValueRef()))
              return false;
          }
        }
      }

      // Switch to the next item.
      if (first || skip)
      {
        it_copy = it1;
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
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2>
inline Tbool setsMergePrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2)
{ CALL
  return setsMergePrev(a_crIterator1, a_crIterator2, NFunctions::FBoolLessThan<const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
inline Tbool setsMergePrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator1 class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator1> >();
  // Check T_Iterator1 class constraint to be an insert backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_Iterator1> >();
  // Check T_Iterator2 class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator2> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator2::TReturn&, const typename T_Iterator1::TReturn&> >();

  Tbool first;
  Tbool skip;

  // Copy values only of valid iterators.
  T_Iterator1 it1(a_crIterator1);
  T_Iterator2 it2(a_crIterator2);
  T_Iterator1 it_copy;
  if ((it1.isValid() || it2.isValid()) && it1.isValidContainer())
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
      if (!first && !skip)
      {
        if (it_copy.isValid())
        {
          if (!it_copy.insertPrev(it2.getValueRef()) || (it_copy.stepBackward() == 0))
            return false;
        }
        else
        {
          it_copy = it1;
          if (it_copy.isValid())
          {
            if (!it_copy.insertPrev(it2.getValueRef()) || (it_copy.stepBackward() == 0))
              return false;

            // Swap neighbor items.
            NCommon::swap(it1.getValueRef(), it_copy.getValueRef());
            it1 = it_copy;
          }
          else
          {
            if (!it_copy.insertForward(it2.getValueRef()))
              return false;
          }
        }
      }

      // Switch to the previous item.
      if (first || skip)
      {
        it_copy = it1;
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
