/*!
 *  \file    AItFindOneOf.inl Contains general template implementation of the
 *           iterator find one of algorithm.
 *  \brief   Iterator find one of algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator find one of algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   12.09.2006 23:08:36

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
#ifndef __AITFINDONEOF_INL__
#define __AITFINDONEOF_INL__
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
template <class T_Iterator, class T_MatchIterator>
inline T_Iterator findOneOfNext(const T_Iterator& a_crIterator, const T_MatchIterator& a_crMatchIterator)
{ CALL
  return findOneOfNext(a_crIterator, a_crMatchIterator, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_MatchIterator::TType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_MatchIterator, typename T_BinaryPredicate>
inline T_Iterator findOneOfNext(const T_Iterator& a_crIterator, const T_MatchIterator& a_crMatchIterator, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_MatchIterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_MatchIterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_MatchIterator::TType&> >();

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  T_MatchIterator it_match(a_crMatchIterator);
  if (it.isValid() && it_match.isValid())
  {
    do
    {
      do
      {
        if (a_fEqual(it.getValueRef(), it_match.getValueRef()))
          return it;
      } while ((it_match.stepForward() > 0) && (it_match != a_crMatchIterator));
      it_match = a_crMatchIterator;
    } while ((it.stepForward() > 0) && (it != a_crIterator));
  }

  // If we found nothing, than return invalid iterator.
  return T_Iterator();
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_MatchIterator>
inline T_Iterator findOneOfPrev(const T_Iterator& a_crIterator, const T_MatchIterator& a_crMatchIterator)
{ CALL
  return findOneOfNext(reverceIt(a_crIterator), reverceIt(a_crMatchIterator), NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_MatchIterator::TType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_MatchIterator, typename T_BinaryPredicate>
inline T_Iterator findOneOfPrev(const T_Iterator& a_crIterator, const T_MatchIterator& a_crMatchIterator, T_BinaryPredicate a_fEqual)
{ CALL
  return findOneOfNext(reverceIt(a_crIterator), reverceIt(a_crMatchIterator), a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
