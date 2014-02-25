/*!
 *  \file    AItForEach.inl Contains general template implementation of the
 *           iterator for each calling algorithm.
 *  \brief   Iterator for each calling algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator for each calling algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   12.09.2006 00:23:52

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
#ifndef __AITFOREACH_INL__
#define __AITFOREACH_INL__
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
template <class T_Iterator, typename T_UnaryFunction>
inline Tuint forEachNext(const T_Iterator& a_crIterator, T_UnaryFunction a_fFunction)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_UnaryFunction type constraint to be a suitable unary function.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptFunction1<T_UnaryFunction, void, const typename T_Iterator::TReturn&> >();

  Tuint result = 0;

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid())
  {
    do
    {
      a_fFunction(it.getValueRef());
      ++result;
    } while ((it.stepForward() > 0) && (it != a_crIterator));
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_UnaryFunction>
inline Tuint forEachPrev(const T_Iterator& a_crIterator, T_UnaryFunction a_fFunction)
{ CALL
  return forEachNext(reverseIt(a_crIterator), a_fFunction);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
