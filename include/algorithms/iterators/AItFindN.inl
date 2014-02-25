/*!
 *  \file    AItFindN.inl Contains general template implementation of the find
 *           N'th algorithm.
 *  \brief   Find N'th algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find N'th algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   12.04.2007 22:39:42

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
#ifndef __AITFINDN_INL__
#define __AITFINDN_INL__
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
inline T_Iterator findNNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, const Tuint a_cN)
{ CALL
  return findNNext(a_crIterator, a_crValue, a_cN, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const T_ValueType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_Iterator findNNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, const Tuint a_cN, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const T_ValueType&> >();

  if (a_cN > 0)
  {
    // Find the first value.
    Tuint count(a_cN);
    T_Iterator first;
    T_Iterator it(findNext(a_crIterator, a_crValue, a_fEqual));
    Tbool resume(it.isValid());

    // Try to find other values.
    first = it;
    while (resume)
    {
      // Move to the next value.
      if ((--count == 0) || (it.stepForward() == 0) || (it == a_crIterator))
      {
        resume = false;
        break;
      }

      // Skip the same values.
      while (resume)
      {
        if (!a_fEqual(it.getValueRef(), a_crValue))
          break;
        if ((--count == 0) || (it.stepForward() == 0) || (it == a_crIterator))
        {
          resume = false;
          break;
        }
      }

      // Find the next value.
      if (resume)
      {
        it = findNext(it, a_crValue, a_fEqual);
        resume = (it.isValid() && (it != first));
      }
    }
    return ((count == 0) ? it : T_Iterator());
  }
  else
    return T_Iterator();
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType>
inline T_Iterator findNPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, const Tuint a_cN)
{ CALL
  return findNNext(reverseIt(a_crIterator), a_crValue, a_cN, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const T_ValueType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_Iterator findNPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, const Tuint a_cN, T_BinaryPredicate a_fEqual)
{ CALL
  return findNNext(reverseIt(a_crIterator), a_crValue, a_cN, a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
