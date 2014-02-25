/*!
 *  \file    AItIncludesSub.inl Contains general template implementation of
 *           the iterator two subsequences include test algorithm.
 *  \brief   Iterator two subsequences include test algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator two subsequences include test algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   10.04.2007 02:54:18

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
#ifndef __AITINCLUDESSUB_INL__
#define __AITINCLUDESSUB_INL__
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
template <class T_Iterator1, class T_Iterator2>
inline Tbool includesSubNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2)
{ CALL
  return includesSubNext(a_crIterator1, a_crIterator2, NFunctions::FBoolLessThan<const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
inline Tbool includesSubNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator1> >();
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator2> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator2::TReturn&, const typename T_Iterator1::TReturn&> >();

  // Search only in valid iterators.
  T_Iterator1 it1(a_crIterator1);
  T_Iterator2 it2(a_crIterator2);
  if (it1.isValid() && it2.isValid())
  {
    bool increase_one;
    do
    {
      if (a_fLessThan(it2.getValueRef(), it1.getValueRef()))
        return false;
      increase_one = (a_fLessThan(it1.getValueRef(), it2.getValueRef()));
    } while ((it1.stepForward() > 0) && (it1 != a_crIterator1) && (!increase_one && (it2.stepForward() > 0) && (it2 != a_crIterator2)));
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2>
inline Tbool includesSubPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2)
{ CALL
  return includesSubPrev(a_crIterator1, a_crIterator2, NFunctions::FBoolLessThan<const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
inline Tbool includesSubPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fLessThan)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator1> >();
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator2> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator2::TReturn&, const typename T_Iterator1::TReturn&> >();

  // Search only in valid iterators.
  T_Iterator1 it1(a_crIterator1);
  T_Iterator2 it2(a_crIterator2);
  if (it1.isValid() && it2.isValid())
  {
    bool decrease_one;
    do
    {
      if (a_fLessThan(it1.getValueRef(), it2.getValueRef()))
        return false;
      decrease_one = (a_fLessThan(it2.getValueRef(), it1.getValueRef()));
    } while ((it1.stepBackward() > 0) && (it1 != a_crIterator1) && (!decrease_one && (it2.stepBackward() > 0) && (it2 != a_crIterator2)));
  }
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
