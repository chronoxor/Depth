/*!
 *  \file    CUpperBoundHelper.inl Contains template implementations of the
 *           upper bound searching algorithm for different types of iterators.
 *  \brief   Upper bound searching algorithm helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Upper bound searching algorithm helper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   23.08.2006 20:46:25

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
#ifndef __CUPPERBOUNDHELPER_INL__
#define __CUPPERBOUNDHELPER_INL__
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
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <Tuint t_Algorithm>
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_Iterator CUpperBoundHelper<t_Algorithm>::upperBoundNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const T_ValueType&, const typename T_Iterator::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  T_Iterator it_first(a_crIterator);
  T_Iterator it_result(a_crIterator);
  T_Iterator it_middle;
  Tuint length = NIterators::distanceNext(a_crIterator);
  Tuint half;

  // Search only in valid iterators.
  if (it_first.isValid())
  {
    // Check single container value.
    if (a_fLessThan(a_crValue, it_first.getValueRef()))
      return T_Iterator();
    // Check other values.
    while (length > 0)
    {
      half = length >> 1;
      it_middle = it_first;
      // Step forward by half a length steps.
      if (it_middle.stepForward(half) < half)
        return T_Iterator();
      // Compare values and choose right or left bound.
      if (a_fLessThan(a_crValue, it_middle.getValueRef()))
        length = half;
      else
      {
        it_first = it_middle;
        it_result = it_first;
        if (it_first.stepForward() != 1)
          return T_Iterator();
        length = length - half - 1;
      }
    }
    // Return upper bound iterator.
    if (a_fLessThan(it_first.getValueRef(), it_result.getValueRef()))
      return it_result;
    if (a_fLessThan(a_crValue, it_first.getValueRef()))
      return it_result;
    else
      return it_first;
  }

  // If we found nothing, than return invalid iterator.
  return T_Iterator();
}
/*--------------------------------------------------------------------------*/
template <>
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_Iterator CUpperBoundHelper<1>::upperBoundNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an any associative iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyAssociative<T_Iterator> >();
  // Check T_Iterator class constraint to be an any tree iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyTree<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const T_ValueType&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  T_Iterator it_root;
  T_Iterator it_result;
  T_Iterator it_next(a_crIterator);
  Tbool is_root_found = false;

  if (it_next.isValid())
  {
    // Find root iterator.
    while (!is_root_found)
    {
      it_root = it_next;
      // Get parent iterator.
      it_next = it_root.getParent();
      // Check if we have already found global binary tree root iterator.
      if (!it_next.isValid())
      {
        is_root_found = true;
        break;
      }
    }
    // Perform binary tree search from root iterator.
    while (it_root.isValid())
    {
      // Skip boundless values.
      if (a_fLessThan(it_root.getValueRef(), a_crIterator.getValueRef()))
      {
        it_root = it_root.getRightChildLast();
        continue;
      }
      // Choose next search step.
      if (a_fLessThan(a_crValue, it_root.getValueRef()))
      {
        // Next posible iterator is the left child.
        it_root = it_root.getLeftChildLast();
      }
      else
      {
        // Update result iterator.
        it_result = it_root;
        // Next posible iterator is the right child.
        it_root = it_root.getRightChildLast();
      }
    }
    // Return result iterator.
    return it_result;
  }

  // If we found nothing, than return invalid iterator.
  return T_Iterator();
}
/*--------------------------------------------------------------------------*/
template <Tuint t_Algorithm>
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_Iterator CUpperBoundHelper<t_Algorithm>::upperBoundPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const T_ValueType&, const typename T_Iterator::TReturn&> >();

  T_Iterator it_first(a_crIterator);
  T_Iterator it_middle;
  Tuint length = NIterators::distancePrev(a_crIterator);
  Tuint half;

  // Search only in valid iterators.
  if (it_first.isValid())
  {
    // Check single container value.
    if (a_fLessThan(a_crValue, it_first.getValueRef()))
    {
      if (length == 0)
        return T_Iterator();
    }
    else
      return it_first;
    // Check other values.
    while (length > 0)
    {
      half = length >> 1;
      it_middle = it_first;
      // Step backward by half a length steps.
      if (it_middle.stepBackward(half) < half)
        return T_Iterator();
      // Compare values and choose right or left bound.
      if (a_fLessThan(a_crValue, it_middle.getValueRef()))
      {
        it_first = it_middle;
        if (it_first.stepBackward() != 1)
          return T_Iterator();
        length = length - half - 1;
      }
      else
        length = half;
    }
    // Return upper bound iterator.
    if (a_fLessThan(a_crValue, it_first.getValueRef()))
      return T_Iterator();
    else
      return it_first;
  }

  // If we found nothing, than return invalid iterator.
  return T_Iterator();
}
/*--------------------------------------------------------------------------*/
template <>
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_Iterator CUpperBoundHelper<1>::upperBoundPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an any associative iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyAssociative<T_Iterator> >();
  // Check T_Iterator class constraint to be an any tree iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyTree<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const T_ValueType&, const typename T_Iterator::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const T_ValueType&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  T_Iterator it_root;
  T_Iterator it_result;
  T_Iterator it_next(a_crIterator);
  Tbool is_root_found = false;

  if (it_next.isValid())
  {
    // Find root iterator.
    while (!is_root_found)
    {
      it_root = it_next;
      // Get parent iterator.
      it_next = it_root.getParent();
      // Check if we have already found global binary tree root iterator.
      if (!it_next.isValid())
      {
        is_root_found = true;
        break;
      }
    }
    // Perform binary tree search from root iterator.
    while (it_root.isValid())
    {
      // Skip boundless values.
      if (a_fLessThan(a_crIterator.getValueRef(), it_root.getValueRef()))
      {
        it_root = it_root.getLeftChildLast();
        continue;
      }
      // Choose next search step.
      if (a_fLessThan(a_crValue, it_root.getValueRef()))
      {
        // Next posible iterator is the left child.
        it_root = it_root.getLeftChildLast();
      }
      else
      {
        // Update result iterator.
        it_result = it_root;
        // Next posible iterator is the right child.
        it_root = it_root.getRightChildLast();
      }
    }
    // Return result iterator.
    return it_result;
  }

  // If we found nothing, than return invalid iterator.
  return T_Iterator();
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
