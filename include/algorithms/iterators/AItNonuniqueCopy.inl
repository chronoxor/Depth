/*!
 *  \file    AItNonuniqueCopy.inl Contains general template implementation of
 *           the iterator non unique and copy all items algorithm.
 *  \brief   Iterator non unique and copy all items algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator non unique and copy all items algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   05.06.2007 02:36:53

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
#ifndef __AITNONUNIQUECOPY_INL__
#define __AITNONUNIQUECOPY_INL__
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
template <class T_Iterator, class T_IteratorCopy>
inline Tuint nonuniqueCopyNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  return nonuniqueCopyNext(a_crIterator, a_crIteratorCopy, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>(), a_cMinCount, a_cMaxCount);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_BinaryPredicate>
inline Tuint nonuniqueCopyNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_IteratorCopy> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tuint count = 0;
  Tuint result = 0;
  Tbool update = true;
  Tbool meet = false;

  // Make values non unique only of valid iterator.
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);
  T_IteratorCopy it3(a_crIteratorCopy);
  if (it1.isValid() && it2.isValid() && it3.isValidContainer())
  {
    do
    {
      count = 1;
      update = true;
      meet = false;
      it2 = a_crIterator;
      // Check other sequence items.
      do
      {
      	if (it1 == it2)
      	{
      	  meet = true;
      	  continue;
      	}
        if (a_fEqual(it1.getValueRef(), it2.getValueRef()))
        {
          ++count;
          update &= meet;
        }
      } while ((it2.stepForward() > 0) && (it2 != a_crIterator));
      if ((count >= a_cMinCount) && (count <= a_cMaxCount) && update)
      {
        // Copy current value.
        if (it3.isValid())
        {
          if (!it3.insertNext(it1.getValueRef()) || (it3.stepForward() == 0))
            return result;
        }
        else
        {
          if (!it3.insertBackward(it1.getValueRef()))
            return result;
        }
        ++result;
      }
    } while ((it1.stepForward() > 0) && (it1 != a_crIterator));
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy>
inline Tuint nonuniqueCopyPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  return nonuniqueCopyPrev(a_crIterator, a_crIteratorCopy, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>(), a_cMinCount, a_cMaxCount);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_BinaryPredicate>
inline Tuint nonuniqueCopyPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_IteratorCopy> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tuint count = 0;
  Tuint result = 0;
  Tbool update = true;
  Tbool meet = false;

  // Make values non unique only of valid iterator.
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);
  T_IteratorCopy it3(a_crIteratorCopy);
  if (it1.isValid() && it2.isValid() && it3.isValidContainer())
  {
    do
    {
      count = 1;
      update = true;
      meet = false;
      it2 = a_crIterator;
      // Check other sequence items.
      do
      {
      	if (it1 == it2)
      	{
      	  meet = true;
      	  continue;
      	}
        if (a_fEqual(it1.getValueRef(), it2.getValueRef()))
        {
          ++count;
          update &= meet;
        }
      } while ((it2.stepBackward() > 0) && (it2 != a_crIterator));
      if ((count >= a_cMinCount) && (count <= a_cMaxCount) && update)
      {
        // Copy current value.
        if (it3.isValid())
        {
          if (!it3.insertPrev(it1.getValueRef()) || (it3.stepBackward() == 0))
            return result;
        }
        else
        {
          if (!it3.insertForward(it1.getValueRef()))
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
