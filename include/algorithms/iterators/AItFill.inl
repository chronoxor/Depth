/*!
 *  \file    AItFill.inl Contains general template implementation of the
 *           iterator fill all items algorithm.
 *  \brief   Iterator fill all items algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator fill all items algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   22.05.2007 22:06:47

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
#ifndef __AITFILL_INL__
#define __AITFILL_INL__
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
template <class T_Iterator, typename T_ValueType>
inline Tuint fillNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_ValueType constraint to be a convertible to the iterator value type.
  NConcept::MConstraint::requiresConcept<NConcept::NCommon::MConceptConvert<T_ValueType, typename T_Iterator::TReturn&> >();

  Tuint result = 0;

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid())
  {
    // Fill existent items.
    do
    {
      it.getValueRef() = a_crValue;
      ++result;
    } while ((it.stepForward() > 0) && (it != a_crIterator));
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType>
inline Tuint fillPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue)
{ CALL
  return fillNext(reverseIt(a_crIterator), a_crValue);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
