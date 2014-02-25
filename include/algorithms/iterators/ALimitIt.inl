/*!
 *  \file    ALimitIt.inl Iterator sequence limit algorithm.
 *  \brief   Iterator sequence limit algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator sequence limit algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   03.04.2007 23:41:53

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
#ifndef __ALIMITIT_INL__
#define __ALIMITIT_INL__
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
inline typename NDetails::MLimitItHelper<T_Iterator>::TLimitIteratorWrapper LimitIt(const T_Iterator& a_crCurrentIterator, const Tuint a_cEndLimit)
{ CALL
  return typename NDetails::MLimitItHelper<T_Iterator>::TLimitIteratorWrapper(a_crCurrentIterator, a_cEndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline typename NDetails::MLimitItHelper<T_Iterator>::TLimitIteratorWrapper LimitIt(const T_Iterator& a_crCurrentIterator, const Tuint a_cStartLimit, const Tuint a_cEndLimit)
{ CALL
  return typename NDetails::MLimitItHelper<T_Iterator>::TLimitIteratorWrapper(a_crCurrentIterator, a_cStartLimit, a_cEndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline typename NDetails::MLimitItHelper<T_Iterator>::TLimitIteratorWrapper LimitItForward(const T_Iterator& a_crCurrentIterator, const Tuint a_cEndLimit)
{ CALL
  return typename NDetails::MLimitItHelper<T_Iterator>::TLimitIteratorWrapper(a_crCurrentIterator, a_cEndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator>
inline typename NDetails::MLimitItHelper<T_Iterator>::TLimitIteratorWrapper LimitItBackward(const T_Iterator& a_crCurrentIterator, const Tuint a_cStartLimit)
{ CALL
  return typename NDetails::MLimitItHelper<T_Iterator>::TLimitIteratorWrapper(a_crCurrentIterator, a_cStartLimit, NBase::CUnsignedInteger::getMax());
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
