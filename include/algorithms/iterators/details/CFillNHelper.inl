/*!
 *  \file    CFillNHelper.inl Contains template implementations of the
 *           iterator fill N items algorithm for different types of iterators.
 *  \brief   Iterator fill N items algorithm helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator fill N items algorithm helper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   22.05.2007 23:44:23

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
#ifndef __CFILLNHELPER_INL__
#define __CFILLNHELPER_INL__
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
template <class T_Iterator, typename T_ValueType>
inline Tuint CFillNHelper<t_Algorithm>::fillNNext(const T_Iterator& a_crIterator, const Tuint a_cN, const T_ValueType& a_crValue)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_ValueType constraint to be a convertible to the iterator value type.
  NConcept::MConstraint::requiresConcept<NConcept::NCommon::MConceptConvert<T_ValueType, typename T_Iterator::TReturn&> >();

  Tuint result = a_cN;

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid() && (result > 0))
  {
    // Fill existent items.
    do
    {
      it.getValueRef() = a_crValue;
    } while ((--result > 0) && (it.stepForward() > 0) && (it != a_crIterator));
  }
  return (a_cN - result);
}
/*--------------------------------------------------------------------------*/
template <>
template <class T_Iterator, typename T_ValueType>
inline Tuint CFillNHelper<1>::fillNNext(const T_Iterator& a_crIterator, const Tuint a_cN, const T_ValueType& a_crValue)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_Iterator class constraint to be a forward insert iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_Iterator> >();
  // Check T_ValueType constraint to be a convertible to the iterator value type.
  NConcept::MConstraint::requiresConcept<NConcept::NCommon::MConceptConvert<T_ValueType, typename T_Iterator::TReturn&> >();

  Tuint result = a_cN;

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  T_Iterator it_next(a_crIterator);
  if (it.isValid() && (result > 0))
  {
    // Fill existent items.
    do
    {
      it = it_next;
      it.getValueRef() = a_crValue;
    } while ((--result > 0) && (it_next.stepForward() > 0) && (it_next != a_crIterator));
    // Insert and fill new items.
    while (result > 0)
    {
      if (!it.insertNext(a_crValue) || (it.stepForward() == 0))
        break;
      else
        --result;
    }
  }
  return (a_cN - result);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_Algorithm>
template <class T_Iterator, typename T_ValueType>
inline Tuint CFillNHelper<t_Algorithm>::fillNPrev(const T_Iterator& a_crIterator, const Tuint a_cN, const T_ValueType& a_crValue)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_ValueType constraint to be a convertible to the iterator value type.
  NConcept::MConstraint::requiresConcept<NConcept::NCommon::MConceptConvert<T_ValueType, typename T_Iterator::TReturn&> >();

  Tuint result = a_cN;

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid() && (result > 0))
  {
    // Fill existent items.
    do
    {
      it.getValueRef() = a_crValue;
    } while ((--result > 0) && (it.stepBackward() > 0) && (it != a_crIterator));
  }
  return (a_cN - result);
}
/*--------------------------------------------------------------------------*/
template <>
template <class T_Iterator, typename T_ValueType>
inline Tuint CFillNHelper<1>::fillNPrev(const T_Iterator& a_crIterator, const Tuint a_cN, const T_ValueType& a_crValue)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_Iterator class constraint to be a backward insert iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_Iterator> >();
  // Check T_ValueType constraint to be a convertible to the iterator value type.
  NConcept::MConstraint::requiresConcept<NConcept::NCommon::MConceptConvert<T_ValueType, typename T_Iterator::TReturn&> >();

  Tuint result = a_cN;

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  T_Iterator it_prev(a_crIterator);
  if (it.isValid() && (result > 0))
  {
    // Fill existent items.
    do
    {
      it = it_prev;
      it.getValueRef() = a_crValue;
    } while ((--result > 0) && (it_prev.stepBackward() > 0) && (it_prev != a_crIterator));
    // Insert and fill new items.
    while (result > 0)
    {
      if (!it.insertPrev(a_crValue) || (it.stepBackward() == 0))
        break;
      else
        --result;
    }
  }
  return (a_cN - result);
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
