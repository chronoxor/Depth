/*!
 *  \file    AItUnique.inl Contains general template implementation of the
 *           iterator unique all items algorithm.
 *  \brief   Iterator unique all items algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator unique all items algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   01.06.2007 03:36:33

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
#ifndef __AITUNIQUE_INL__
#define __AITUNIQUE_INL__
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
inline Tbool uniqueNext(const T_Iterator& a_crIterator)
{ CALL
  return uniqueNext(a_crIterator, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline Tbool uniqueNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_Iterator class constraint to be a remove forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorRemoveForward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tbool end = false;

  // Make values unique only of valid iterator.
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);
  if (it1.isValid() && it2.isValid())
  {
    while ((it2.stepForward() > 0) && (it2 != a_crIterator))
    {
      end = false;
      // Check other sequence items.
      while (!end)
      {
        if (a_fEqual(it1.getValueRef(), it2.getValueRef()))
        {
          if (!it2.removeForward())
            return false;
          if (!it2.isValid() || (it1 == it2))
            end = true;
        }
        else
        {
          // Get next sequence item.
          if ((it2.stepForward() == 0) || (it2 == a_crIterator))
            end = true;
        }
      }
      // Get next sequence item.
      if ((it1.stepForward() == 0) || (it1 == a_crIterator))
        break;
      // Update iterators.
      it2 = it1;
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline Tbool uniquePrev(const T_Iterator& a_crIterator)
{ CALL
  return uniquePrev(a_crIterator, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryPredicate>
inline Tbool uniquePrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_Iterator class constraint to be a remove backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorRemoveBackward<T_Iterator> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tbool end = false;

  // Make values unique only of valid iterator.
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);
  if (it1.isValid() && it2.isValid())
  {
    while ((it2.stepBackward() > 0) && (it2 != a_crIterator))
    {
      end = false;
      // Check other sequence items.
      while (!end)
      {
        if (a_fEqual(it1.getValueRef(), it2.getValueRef()))
        {
          if (!it2.removeBackward())
            return false;
          if (!it2.isValid() || (it1 == it2))
            end = true;
        }
        else
        {
          // Get previous sequence item.
          if ((it2.stepBackward() == 0) || (it2 == a_crIterator))
            end = true;
        }
      }
      // Get previous sequence item.
      if ((it1.stepBackward() == 0) || (it1 == a_crIterator))
        break;
      // Update iterators.
      it2 = it1;
    }
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
