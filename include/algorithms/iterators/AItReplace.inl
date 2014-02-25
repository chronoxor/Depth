/*!
 *  \file    AItReplace.inl Contains general template implementation of the
 *           replace algorithm.
 *  \brief   Replace algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Replace algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   11.06.2007 21:45:48

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
#ifndef __AITREPLACE_INL__
#define __AITREPLACE_INL__
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
template <class T_Iterator, typename T_OldValueType, typename T_NewValueType>
inline Tuint replaceNext(const T_Iterator& a_crIterator, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue)
{ CALL
  return replaceNext(a_crIterator, a_crOldValue, a_crNewValue, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const T_OldValueType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_OldValueType, typename T_NewValueType, typename T_BinaryPredicate>
inline Tuint replaceNext(const T_Iterator& a_crIterator, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_NewValueType type constraint to be a convertible to the iterator's item type.
  NConcept::MConstraint::requiresConcept<NConcept::NCommon::MConceptConvert<T_NewValueType, typename T_Iterator::TReturn&> >();

  Tuint result = 0;

  T_Iterator it_first = findNext(a_crIterator, a_crOldValue, a_fEqual);
  T_Iterator it_current = it_first;
  if (it_first.isValid())
  {
    do
    {
      ++result;
      // Replace current item.
      it_current.getValueRef() = a_crNewValue;
      // Move to the next item.
      if ((it_current.stepForward() == 0) || (it_current == a_crIterator))
        break;
      // Find the next item.
      it_current = findNext(it_current, a_crOldValue, a_fEqual);
    } while (it_current.isValid() && (it_current != it_first));
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_OldValueType, typename T_NewValueType>
inline Tuint replacePrev(const T_Iterator& a_crIterator, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue)
{ CALL
  return replaceNext(reverseIt(a_crIterator), a_crOldValue, a_crNewValue, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const T_OldValueType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_OldValueType, typename T_NewValueType, typename T_BinaryPredicate>
inline Tuint replacePrev(const T_Iterator& a_crIterator, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue, T_BinaryPredicate a_fEqual)
{ CALL
  return replaceNext(reverseIt(a_crIterator), a_crOldValue, a_crNewValue, a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
