/*!
 *  \file    CDistanceHelper.inl Contains template implementations of the
 *           forward iterator distance algorithm for different types of
 *           forward iterators.
 *  \brief   Forward iterator distance algorithm helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Forward iterator distance algorithm helper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   03.08.2006 02:43:27

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
#ifndef __CDISTANCEHELPER_INL__
#define __CDISTANCEHELPER_INL__
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
template <class T_Iterator>
inline Tuint CDistanceHelper<t_Algorithm>::distanceNext(const T_Iterator& a_crIterator)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();

  Tuint d = 0;
  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid())
    while (it.stepForward() > 0)
      ++d;
  return d;
}
/*--------------------------------------------------------------------------*/
template <>
template <class T_Iterator>
inline Tuint CDistanceHelper<1>::distanceNext(const T_Iterator& a_crIterator)
{ CALL
  // Check T_Iterator class constraint to be an any random iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyRandom<T_Iterator> >();

  Tuint d = 0;
  // Search only in valid iterators.
  if (a_crIterator.isValid())
    d = a_crIterator.getSize() - a_crIterator.getPosition() - 1;
  return d;
}
/*--------------------------------------------------------------------------*/
template <>
template <class T_Iterator>
inline Tuint CDistanceHelper<2>::distanceNext(const T_Iterator& a_crIterator)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();

  Tuint d = 0;
  // Search only in valid iterators.
  T_Iterator it(a_crIterator);
  if (it.isValid())
    while (it.stepForward() > 0)
    {
      if (it == a_crIterator)
        break;
      ++d;
    }
  return d;
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
