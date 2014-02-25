/*!
 *  \file    AItRemoveAllIf.inl Contains general template implementation
 *           of the iterator remove all items algorithm with unary 'If'
 *           predicate.
 *  \brief   Iterator remove all items algorithm with unary 'If' predicate (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator remove all items algorithm with unary 'If' predicate (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   16.05.2007 20:58:37

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
#ifndef __AITREMOVEALLIF_INL__
#define __AITREMOVEALLIF_INL__
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
template <class T_Iterator, typename T_UnaryIfPredicate>
inline Tuint removeAllIfNext(const T_Iterator& a_crIterator, T_UnaryIfPredicate a_fIf)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_Iterator class constraint to be a remove forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorRemoveForward<T_Iterator> >();
  // Check T_UnaryIfPredicate type constraint to be a suitable unary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate1<T_UnaryIfPredicate, const typename T_Iterator::TReturn&> >();

  Tuint result = 0;

  // Remove values only of valid iterator.
  T_Iterator it(a_crIterator);
  while (it.isValid())
  {
    if (a_fIf(it.getValueRef()))
    {
      if (!it.removeForward())
        return result;
      ++result;
    }
    else
    {
      if ((it.stepForward() == 0) || (it == a_crIterator))
        return result;
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_UnaryIfPredicate>
inline Tuint removeAllIfPrev(const T_Iterator& a_crIterator, T_UnaryIfPredicate a_fIf)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_Iterator class constraint to be a remove backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorRemoveBackward<T_Iterator> >();
  // Check T_UnaryIfPredicate type constraint to be a suitable unary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate1<T_UnaryIfPredicate, const typename T_Iterator::TReturn&> >();

  Tuint result = 0;

  // Remove values only of valid iterator.
  T_Iterator it(a_crIterator);
  while (it.isValid())
  {
    if (a_fIf(it.getValueRef()))
    {
      if (!it.removeBackward())
        return result;
      ++result;
    }
    else
    {
      if ((it.stepBackward() == 0) || (it == a_crIterator))
        return result;
    }
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
