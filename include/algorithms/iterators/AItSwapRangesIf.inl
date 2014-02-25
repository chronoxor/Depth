/*!
 *  \file    AItSwapRangesIf.inl Contains general template implementation of
 *           the iterator two sequences swap ranges algorithm with given
 *           binary 'If' predicate.
 *  \brief   Iterator two sequences swap ranges algorithm with given binary 'If' predicate (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator two sequences swap ranges algorithm with given binary 'If' predicate (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   10.05.2007 20:42:23

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
#ifndef __AITSWAPRANGESIF_INL__
#define __AITSWAPRANGESIF_INL__
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
template <class T_Iterator1, class T_Iterator2, typename T_BinaryIfPredicate>
inline Tuint swapRangesIfNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryIfPredicate a_fIf)
{ CALL
  // Check T_Iterator1 class constraint to be an non constant forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorNonConstForward<T_Iterator1> >();
  // Check T_Iterator2 class constraint to be an non constant forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorNonConstForward<T_Iterator2> >();
  // Check T_BinaryIfPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryIfPredicate, const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&> >();

  Tuint result = 0;

  // Swap values only of valid iterators.
  T_Iterator1 it1(a_crIterator1);
  T_Iterator2 it2(a_crIterator2);
  if (it1.isValid() && it2.isValid())
  {
    do
    {
      if (a_fIf(it1.getValueRef(), it2.getValueRef()))
      {
        NCommon::swap(it1.getValueRef(), it2.getValueRef());
        ++result;
      }
    } while ((it1.stepForward() > 0) && (it1 != a_crIterator1) && (it2.stepForward() > 0) && (it2 != a_crIterator2));
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryIfPredicate>
inline Tuint equalRangesIfPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryIfPredicate a_fIf)
{ CALL
  return swapRangesIfNext(reverseIt(a_crIterator1), reverseIt(a_crIterator2), a_fIf);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
