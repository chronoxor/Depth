/*!
 *  \file    AItFindMin.inl Contains general template implementation of the
 *           find minimum value algorithm.
 *  \brief   Find minimum value algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find minimum value algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   03.04.2007 02:06:37

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
#ifndef __AITFINDMIN_INL__
#define __AITFINDMIN_INL__
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
T_Iterator findMinNext(const T_Iterator& a_crIterator)
{ CALL
  return findMinNext(a_crIterator, NFunctions::FBoolLessThan<const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
T_Iterator findMinNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid())
  {
    T_Iterator result(it);
    while ((it.stepForward() > 0) && (it != a_crIterator))
      if (a_fLessThan(it.getValueRef(), result.getValueRef()))
        result = it;
    return result;
  }
  else
    return T_Iterator();
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
T_Iterator findMinPrev(const T_Iterator& a_crIterator)
{ CALL
  return findMinNext(reverseIt(a_crIterator), NFunctions::FBoolLessThan<const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
T_Iterator findMinPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan)
{ CALL
  return findMinNext(reverseIt(a_crIterator), a_fLessThan);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
