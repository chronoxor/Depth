/*!
 *  \file    AItFindIf.inl Contains general template implementation of the
 *           find algorithm with given unary 'If' predicate.
 *  \brief   Find algorithm with given unary 'If' predicate (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find algorithm with given unary 'If' predicate (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   13.09.2006 22:58:36

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
#ifndef __AITFINDIF_INL__
#define __AITFINDIF_INL__
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
inline T_Iterator findIfNext(const T_Iterator& a_crIterator, T_UnaryIfPredicate a_fIf)
{ CALL
  return NDetails::CFindIfHelper<(NTraits::MTraitsIterator<T_Iterator>::isMoveRandom ? 1 :
                                  0)>::findIfNext(a_crIterator, a_fIf);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType, typename T_UnaryIfPredicate>
inline T_Iterator findIfPrev(const T_Iterator& a_crIterator, T_UnaryIfPredicate a_fIf)
{ CALL
  return findIfNext(reverseIt(a_crIterator), a_fIf);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
