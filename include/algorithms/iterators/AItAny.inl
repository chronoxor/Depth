/*!
 *  \file    AItAny.inl Contains general template implementation of the check
 *           for any algorithm with given unary 'Check' predicate.
 *  \brief   Check for any algorithm with given unary 'Check' predicate (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Check for any algorithm with given unary 'Check' predicate (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   17.05.2007 20:08:42

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
#ifndef __AITANY_INL__
#define __AITANY_INL__
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
template <class T_Iterator, typename T_UnaryCheckPredicate>
inline Tbool anyNext(const T_Iterator& a_crIterator, T_UnaryCheckPredicate a_fCheck)
{ CALL
  return findIfNext(a_crIterator, a_fCheck).isValid();
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_ValueType, typename T_UnaryCheckPredicate>
inline Tbool anyPrev(const T_Iterator& a_crIterator, T_UnaryCheckPredicate a_fCheck)
{ CALL
  return findIfPrev(a_crIterator, a_fCheck).isValid();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
