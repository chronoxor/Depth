/*!
 *  \file    AItCount.inl Contains general template implementation of the
 *           iterator counting algorithm.
 *  \brief   Iterator counting algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator counting algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   12.09.2006 20:54:43

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
#ifndef __AITCOUNT_INL__
#define __AITCOUNT_INL__
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
inline Tuint countNext(const T_Iterator& a_crIterator)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();

  Tuint result = 0;

  // Count only valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid())
  {
    do
    {
      ++result;
    } while ((it.stepForward() > 0) && (it != a_crIterator));
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType>
inline Tuint countNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue)
{ CALL
  return countNext(a_crIterator, a_crValue, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const T_ValueType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline Tuint countNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const T_ValueType&> >();

  Tuint result = 0;

  // Count only valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid())
  {
    do
    {
      if (a_fEqual(it.getValueRef(), a_crValue))
        ++result;
    } while ((it.stepForward() > 0) && (it != a_crIterator));
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline Tuint countPrev(const T_Iterator& a_crIterator)
{ CALL
  return countNext(reverseIt(a_crIterator));
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType>
inline Tuint countPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue)
{ CALL
  return countNext(reverseIt(a_crIterator), a_crValue);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline Tuint countPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual)
{ CALL
  return countNext(reverseIt(a_crIterator), a_crValue, a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
