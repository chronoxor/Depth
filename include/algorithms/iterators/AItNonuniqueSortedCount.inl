/*!
 *  \file    AItNonuniqueSortedCount.inl Contains general template
 *           implementation of the iterator get count of non unique
 *           sorted items algorithm.
 *  \brief   Iterator get count of non unique sorted items algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator get count of non unique sorted items algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   05.06.2007 02:53:23

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
#ifndef __AITNONUNIQUESORTEDCOUNT_INL__
#define __AITNONUNIQUESORTEDCOUNT_INL__
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
inline Tuint nonuniqueSortedCountNext(const T_Iterator& a_crIterator, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  return nonuniqueSortedCountNext(a_crIterator, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>(), a_cMinCount, a_cMaxCount);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline Tuint nonuniqueSortedCountNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tuint count = 1;
  Tuint result = 0;

  // Make values non unique only of valid iterator.
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);
  if (it1.isValid() && it2.isValid())
  {
    while ((it2.stepForward() > 0) && (it2 != a_crIterator))
    {
      count = 1;
      // Check if items are unique.
      while (a_fEqual(it1.getValueRef(), it2.getValueRef()))
      {
        ++count;
        // Get next sequence item.
        if ((it2.stepForward() == 0) || (it2 == a_crIterator))
        {
          if ((count >= a_cMinCount) && (count <= a_cMaxCount))
            ++result;
          return result;
        }
      }
      // Count non unique item.
      if ((count >= a_cMinCount) && (count <= a_cMaxCount))
        ++result;
      count = 0;
      // Update iterators.
      it1 = it2;
    }
    // Count the last non unique item.
    if ((count > 0) && (count >= a_cMinCount) && (count <= a_cMaxCount))
      ++result;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline Tuint nonuniqueSortedCountPrev(const T_Iterator& a_crIterator, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  return nonuniqueSortedCountPrev(a_crIterator, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>(), a_cMinCount, a_cMaxCount);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline Tuint nonuniqueSortedCountPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tuint count = 1;
  Tuint result = 0;

  // Make values non unique only of valid iterator.
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);
  if (it1.isValid() && it2.isValid())
  {
    while ((it2.stepBackward() > 0) && (it2 != a_crIterator))
    {
      count = 1;
      // Check if items are unique.
      while (a_fEqual(it1.getValueRef(), it2.getValueRef()))
      {
        ++count;
        // Get previous sequence item.
        if ((it2.stepBackward() == 0) || (it2 == a_crIterator))
        {
          if ((count >= a_cMinCount) && (count <= a_cMaxCount))
            ++result;
          return result;
        }
      }
      // Count non unique item.
      if ((count >= a_cMinCount) && (count <= a_cMaxCount))
        ++result;
      count = 0;
      // Update iterators.
      it1 = it2;
    }
    // Count the last non unique item.
    if ((count > 0) && (count >= a_cMinCount) && (count <= a_cMaxCount))
      ++result;
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
