/*!
 *  \file    CFindHelper.inl Contains template implementations of the find
 *           algorithm for different types of iterators.
 *  \brief   Find algorithm helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find algorithm helper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   13.09.2006 22:22:52

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
#ifndef __CFINDHELPER_INL__
#define __CFINDHELPER_INL__
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
inline T_Iterator CFindHelper<t_Algorithm>::findNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const T_ValueType&> >();

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid())
  {
    do
    {
      if (a_fEqual(it.getValueRef(), a_crValue))
        return it;
    } while ((it.stepForward() > 0) && (it != a_crIterator));
  }

  // If we found nothing, than return invalid iterator.
  return T_Iterator();
}
/*--------------------------------------------------------------------------*/
template <>
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_Iterator CFindHelper<1>::findNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any random iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyRandom<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const T_ValueType&> >();

  // Search only in valid iterators.
  if (a_crIterator.isValid())
  {
    Tuint size = a_crIterator.getSize();
    T_Iterator it_first(a_crIterator);
    T_Iterator it_last(a_crIterator[((size > 0) ? (size - 1) : 0)]);

    if (it_first.isValid() && it_last.isValid() && (it_first <= it_last))
    {
      Tuint trip_count = (it_last.getPosition() - it_first.getPosition()) >> 2;

      for (; trip_count > 0; --trip_count)
      {
        if (a_fEqual(it_first.getValueRef(), a_crValue))
          return it_first;
        if (it_first.stepForward() != 1)
          return T_Iterator();

        if (a_fEqual(it_first.getValueRef(), a_crValue))
          return it_first;
        if (it_first.stepForward() != 1)
          return T_Iterator();

        if (a_fEqual(it_first.getValueRef(), a_crValue))
          return it_first;
        if (it_first.stepForward() != 1)
          return T_Iterator();

        if (a_fEqual(it_first.getValueRef(), a_crValue))
          return it_first;
        if (it_first.stepForward() != 1)
          return T_Iterator();
      }

      switch (it_last.getPosition() - it_first.getPosition())
      {
        case 3:
          if (a_fEqual(it_first.getValueRef(), a_crValue))
            return it_first;
          if (it_first.stepForward() != 1)
            return T_Iterator();
        case 2:
          if (a_fEqual(it_first.getValueRef(), a_crValue))
            return it_first;
          if (it_first.stepForward() != 1)
            return T_Iterator();
        case 1:
          if (a_fEqual(it_first.getValueRef(), a_crValue))
            return it_first;
          if (it_first.stepForward() != 1)
            return T_Iterator();
        default:
          if (a_fEqual(it_first.getValueRef(), a_crValue))
            return it_first;
          else
            return T_Iterator();
      }
    }
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
