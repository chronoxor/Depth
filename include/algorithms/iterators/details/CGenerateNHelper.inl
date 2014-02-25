/*!
 *  \file    CGenerateNHelper.inl Contains template implementations of the
 *           iterator generate N items algorithm for different types of
 *           iterators.
 *  \brief   Iterator generate N items algorithm helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator generate N items algorithm helper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   23.05.2007 22:20:03

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
#ifndef __CGENERATENHELPER_INL__
#define __CGENERATENHELPER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <Tuint t_Algorithm>
template <class T_Iterator, typename T_Generator>
inline Tuint CGenerateNHelper<t_Algorithm>::generateNNext(const T_Iterator& a_crIterator, const Tuint a_cN, T_Generator a_fGenerator)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_Generator type constraint to be a suitable generator function.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptFunction0<T_Generator, typename T_Iterator::TReturn> >();

  Tuint result = a_cN;

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid() && (result > 0))
  {
    // Generate and fill existent items.
    do
    {
      it.getValueRef() = a_fGenerator();
    } while ((--result > 0) && (it.stepForward() > 0) && (it != a_crIterator));
  }
  return (a_cN - result);
}
/*--------------------------------------------------------------------------*/
template <>
template <class T_Iterator, typename T_Generator>
inline Tuint CGenerateNHelper<1>::generateNNext(const T_Iterator& a_crIterator, const Tuint a_cN, T_Generator a_fGenerator)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_Iterator class constraint to be a forward insert iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_Iterator> >();
  // Check T_Generator type constraint to be a suitable generator function.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptFunction0<T_Generator, typename T_Iterator::TReturn> >();

  Tuint result = a_cN;

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  T_Iterator it_next(a_crIterator);
  if (it.isValid() && (result > 0))
  {
    // Generate and fill existent items.
    do
    {
      it = it_next;
      it.getValueRef() = a_fGenerator();
    } while ((--result > 0) && (it_next.stepForward() > 0) && (it_next != a_crIterator));
    // Generate and insert new items.
    while (result > 0)
    {
      if (!it.insertNext(a_fGenerator()) || (it.stepForward() == 0))
        break;
      else
        --result;
    }
  }
  return (a_cN - result);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_Algorithm>
template <class T_Iterator, typename T_Generator>
inline Tuint CGenerateNHelper<t_Algorithm>::generateNPrev(const T_Iterator& a_crIterator, const Tuint a_cN, T_Generator a_fGenerator)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_Generator type constraint to be a suitable generator function.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptFunction0<T_Generator, typename T_Iterator::TReturn> >();

  Tuint result = a_cN;

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid() && (result > 0))
  {
    // Generate and fill existent items.
    do
    {
      it.getValueRef() = a_fGenerator();
    } while ((--result > 0) && (it.stepBackward() > 0) && (it != a_crIterator));
  }
  return (a_cN - result);
}
/*--------------------------------------------------------------------------*/
template <>
template <class T_Iterator, typename T_Generator>
inline Tuint CGenerateNHelper<1>::generateNPrev(const T_Iterator& a_crIterator, const Tuint a_cN, T_Generator a_fGenerator)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_Iterator class constraint to be a backward insert iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_Iterator> >();
  // Check T_Generator type constraint to be a suitable generator function.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptFunction0<T_Generator, typename T_Iterator::TReturn> >();

  Tuint result = a_cN;

  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  T_Iterator it_prev(a_crIterator);
  if (it.isValid() && (result > 0))
  {
    // Generate and fill existent items.
    do
    {
      it = it_prev;
      it.getValueRef() = a_fGenerator();
    } while ((--result > 0) && (it_prev.stepBackward() > 0) && (it_prev != a_crIterator));
    // Generate and insert new items.
    while (result > 0)
    {
      if (!it.insertPrev(a_fGenerator()) || (it.stepBackward() == 0))
        break;
      else
        --result;
    }
  }
  return (a_cN - result);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
