/*!
 *  \file    AItAdjacentFind.inl Contains general template implementation of
 *           the adjacent find algorithm.
 *  \brief   Adjacent find algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Adjacent find algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   13.09.2006 22:08:24

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
#ifndef __AITADJACENTFIND_INL__
#define __AITADJACENTFIND_INL__
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
inline T_Iterator adjacentFindNext(const T_Iterator& a_crIterator)
{ CALL
  return adjacentFindNext(a_crIterator, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline T_Iterator adjacentFindNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  // Search only in valid iterators.
  T_Iterator it_current(a_crIterator);
  T_Iterator it_next(a_crIterator);
  if (it_current.isValid())
  {
    while ((it_next.stepForward() > 0) && (it_next != a_crIterator));
    {
      if (a_fEqual(it_current.getValueRef(), it_next.getValueRef()))
        return it_current;
      else
        it_current = it_next;
    }
  }

  // If we found nothing, than return invalid iterator.
  return T_Iterator();
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline T_Iterator adjacentFindPrev(const T_Iterator& a_crIterator)
{ CALL
  return adjacentFindNext(reverceIt(a_crIterator), NFunctions::FBoolEqual<const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline T_Iterator adjacentFindPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual)
{ CALL
  return adjacentFindNext(reverceIt(a_crIterator), a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
