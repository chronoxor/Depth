/*!
 *  \file    AItCopyIf.inl Contains general template implementation of the
 *           iterator copy algorithm with unary 'If' predicate.
 *  \brief   Iterator copy algorithm with unary 'If' predicate (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator copy algorithm with unary 'If' predicate (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   10.05.2007 22:51:12

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
#ifndef __AITCOPYIF_INL__
#define __AITCOPYIF_INL__
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
template <class T_Iterator, class T_IteratorCopy, typename T_UnaryIfPredicate>
inline Tuint copyIfNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_UnaryIfPredicate a_fIf)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_IteratorCopy> >();
  // Check T_UnaryIfPredicate type constraint to be a suitable unary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate1<T_UnaryIfPredicate, const typename T_Iterator::TReturn&> >();

  Tuint result = 0;

  // Copy values only of valid iterators.
  T_Iterator it1(a_crIterator);
  T_IteratorCopy it2(a_crIteratorCopy);
  if (it1.isValid() && it2.isValidContainer())
  {
    // Copy sequence values.
    do
    {
      if (a_fIf(it1.getValueRef()))
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
      }
    } while ((it1.stepForward() > 0) && (it1 != a_crIterator));
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_UnaryIfPredicate>
inline Tuint copyIfPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_UnaryIfPredicate a_fIf)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_IteratorCopy> >();
  // Check T_UnaryIfPredicate type constraint to be a suitable unary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate1<T_UnaryIfPredicate, const typename T_Iterator::TReturn&> >();

  Tuint result = 0;

  // Copy values only of valid iterators.
  T_Iterator it1(a_crIterator);
  T_IteratorCopy it2(a_crIteratorCopy);
  if (it1.isValid() && it2.isValidContainer())
  {
    // Copy sequence values.
    do
    {
      if (a_fIf(it1.getValueRef()))
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
      }
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
