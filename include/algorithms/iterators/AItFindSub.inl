/*!
 *  \file    AItFindSub.inl Contains general template implementation of the
 *           find subsequence algorithm.
 *  \brief   Find subsequence algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find subsequence algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   15.04.2007 02:47:18

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
#ifndef __AITFINDSUB_INL__
#define __AITFINDSUB_INL__
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
template <class T_Iterator, class T_SubsequenceIterator>
inline T_Iterator findSubNext(const T_Iterator& a_crIterator, const T_SubsequenceIterator& a_crSubsequenceIterator)
{ CALL
  return findSubNext(a_crIterator, a_crSubsequenceIterator, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_SubsequenceIterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_SubsequenceIterator, typename T_BinaryPredicate>
inline T_Iterator findSubNext(const T_Iterator& a_crIterator, const T_SubsequenceIterator& a_crSubsequenceIterator, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_SubsequenceIterator::TReturn&> >();

  // For invalid main iterator return the invalid one.
  if (!a_crIterator.isValid())
    return T_Iterator();
  // For invalid subsequence iterator return the first one.
  if (!a_crSubsequenceIterator.isValid())
    return a_crIterator;

  // In general case try to find an iterator to the first subsequence value.
  T_Iterator first;
  T_Iterator result;
  T_Iterator it_main(findNext(a_crIterator, a_crSubsequenceIterator.getValueRef(), a_fEqual));
  T_SubsequenceIterator it_sqnc(a_crSubsequenceIterator);
  Tbool resume(it_main.isValid());
  Tbool main_end(false);
  Tbool sqnc_end(false);

  // Try to find other values.
  first = it_main;
  while (resume && !main_end && !sqnc_end)
  {
    // Move to the next value.
    result = it_main;
    if ((it_main.stepForward() == 0) || (it_main == a_crIterator))
    {
      resume = false;
      main_end = true;
      break;
    }
    if ((it_sqnc.stepForward() == 0) || (it_sqnc == a_crSubsequenceIterator))
    {
      resume = false;
      sqnc_end = true;
      break;
    }

    // Try to match other subsequence values.
    while (resume && !main_end && !sqnc_end)
    {
      if (!a_fEqual(it_main.getValueRef(), it_sqnc.getValueRef()))
        break;
      if ((it_main.stepForward() == 0) || (it_main == a_crIterator))
      {
        resume = false;
        main_end = true;
        break;
      }
      if ((it_sqnc.stepForward() == 0) || (it_sqnc == a_crSubsequenceIterator))
      {
        resume = false;
        sqnc_end = true;
        break;
      }
    }

    // Find the next possible subsequence first value.
    if (resume && !main_end && !sqnc_end)
    {
      it_main = findNext(it_main, a_crSubsequenceIterator.getValueRef(), a_fEqual);
      resume = (it_main.isValid() && (it_main != first));
      it_sqnc = a_crSubsequenceIterator;
      main_end = false;
      sqnc_end = false;
    }
  }
  return (sqnc_end ? result : T_Iterator());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_SubsequenceIterator>
inline T_Iterator findSubPrev(const T_Iterator& a_crIterator, const T_SubsequenceIterator& a_crSubsequenceIterator)
{ CALL
  return findSubNext(reverseIt(a_crIterator), reverseIt(a_crSubsequenceIterator), NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_SubsequenceIterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_SubsequenceIterator, typename T_BinaryPredicate>
inline T_Iterator findSubPrev(const T_Iterator& a_crIterator, const T_SubsequenceIterator& a_crSubsequenceIterator, T_BinaryPredicate a_fEqual)
{ CALL
  return findSubNext(reverseIt(a_crIterator), reverseIt(a_crSubsequenceIterator), a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
