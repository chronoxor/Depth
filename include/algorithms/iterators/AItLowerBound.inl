/*!
 *  \file    AItLowerBound.inl Contains general template implementation of the
 *           lower bound searching algorithm.
 *  \brief   Lower bound searching algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Lower bound searching algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   23.08.2006 01:18:57

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
#ifndef __AITLOWERBOUND_INL__
#define __AITLOWERBOUND_INL__
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
inline T_Iterator lowerBoundNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue)
{ CALL
  return NDetails::CLowerBoundHelper<((NTraits::MTraitsIterator<T_Iterator>::isMoveTree && NTraits::MTraitsIterator<T_Iterator>::isMoveAssociative) ? 1 :
                                       0)>::lowerBoundNext(a_crIterator, a_crValue, NFunctions::FBoolLessThan<const T_ValueType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_Iterator lowerBoundNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fLessThan)
{ CALL
  return NDetails::CLowerBoundHelper<((NTraits::MTraitsIterator<T_Iterator>::isMoveTree && NTraits::MTraitsIterator<T_Iterator>::isMoveAssociative) ? 1 :
                                       0)>::lowerBoundNext(a_crIterator, a_crValue, a_fLessThan);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType>
inline T_Iterator lowerBoundPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue)
{ CALL
  return NDetails::CLowerBoundHelper<((NTraits::MTraitsIterator<T_Iterator>::isMoveTree && NTraits::MTraitsIterator<T_Iterator>::isMoveAssociative) ? 1 :
                                       0)>::lowerBoundPrev(a_crIterator, a_crValue, NFunctions::FBoolLessThan<const T_ValueType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
inline T_Iterator lowerBoundPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fLessThan)
{ CALL
  return NDetails::CLowerBoundHelper<((NTraits::MTraitsIterator<T_Iterator>::isMoveTree && NTraits::MTraitsIterator<T_Iterator>::isMoveAssociative) ? 1 :
                                       0)>::lowerBoundPrev(a_crIterator, a_crValue, a_fLessThan);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
