/*!
 *  \file    AItCopy.inl Contains general template implementation of the
 *           iterator copy algorithm.
 *  \brief   Iterator copy algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator copy algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   10.05.2007 22:06:23

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
#ifndef __AITCOPY_INL__
#define __AITCOPY_INL__
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
template <class T_Iterator, class T_IteratorCopy>
inline Tuint copyNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_IteratorCopy> >();

  Tuint result = 0;

  // Copy values only of valid iterators.
  T_Iterator it1(a_crIterator);
  T_IteratorCopy it2(a_crIteratorCopy);
  if (it1.isValid() && it2.isValidContainer())
  {
    // Copy sequence values.
    do
    {
      // Copy current value.
      if (it2.isValid())
      {
        if (!it2.insertNext(it1.getValueRef()) || (it2.stepForward() == 0))
          return result;
      }
      else
      {
        if (!it2.insertBackward(it1.getValueRef()))
          return result;
      }
      ++result;
    } while ((it1.stepForward() > 0) && (it1 != a_crIterator));
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy>
inline Tuint copyPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_IteratorCopy> >();

  Tuint result = 0;

  // Copy values only of valid iterators.
  T_Iterator it1(a_crIterator);
  T_IteratorCopy it2(a_crIteratorCopy);
  if (it1.isValid() && it2.isValidContainer())
  {
    // Copy sequence values.
    do
    {
      // Copy current value.
      if (it2.isValid())
      {
        if (!it2.insertPrev(it1.getValueRef()) || (it2.stepBackward() == 0))
          return result;
      }
      else
      {
        if (!it2.insertForward(it1.getValueRef()))
          return result;
      }
      ++result;
    } while ((it1.stepBackward() > 0) && (it1 != a_crIterator));
  }
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
