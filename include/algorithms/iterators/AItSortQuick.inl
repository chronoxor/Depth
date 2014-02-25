/*!
 *  \file    AItSortQuick.inl Contains general template implementation of
 *           the iterator quick sort algorithm.
 *  \brief   Iterator quick sort algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator quick sort algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   19.08.2007 23:58:26

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
#ifndef __AITSORTQUICK_INL__
#define __AITSORTQUICK_INL__
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
inline Tbool sortQuickNext(const T_Iterator& a_crIterator)
{ CALL
  return sortQuickNext(a_crIterator, NFunctions::FBoolLessThan<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline Tbool sortQuickNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an non constant forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorNonConstForward<T_Iterator> >();

  Tuint distance = distanceNext(a_crIterator);
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);

  if ((distance > 1) && (it2.stepForward(distance) == distance))
    return NDetails::sortQuickHelper(it1, it2, a_fLessThan);
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline Tbool sortQuickPrev(const T_Iterator& a_crIterator)
{ CALL
  return sortQuickPrev(a_crIterator, NFunctions::FBoolLessThan<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline Tbool sortQuickPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an non constant backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorNonConstBackward<T_Iterator> >();

  Tuint distance = distancePrev(a_crIterator);
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);

  if ((distance > 1) && (it1.stepBackward(distance) == distance))
    return NDetails::sortQuickHelper(it1, it2, a_fLessThan);
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
