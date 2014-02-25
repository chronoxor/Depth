/*!
 *  \file    AReplace.inl Contains general template implementation of the
 *           container replace algorithm.
 *  \brief   Container replace algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container replace algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   11.06.2007 22:52:38

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
#ifndef __AREPLACE_INL__
#define __AREPLACE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_Container, typename T_OldValueType, typename T_NewValueType>
inline Tuint replace(T_Container& a_rContainer, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue)
{ CALL
  return NIterators::replaceNext(getItFirst(a_rContainer), a_crOldValue, a_crNewValue);
}
/*--------------------------------------------------------------------------*/
template <class T_Container, typename T_OldValueType, typename T_NewValueType, typename T_BinaryPredicate>
inline Tuint replace(T_Container& a_rContainer, const T_OldValueType& a_crOldValue, const T_NewValueType& a_crNewValue, T_BinaryPredicate a_fEqual)
{ CALL
  return NIterators::replaceNext(getItFirst(a_rContainer), a_crOldValue, a_crNewValue, a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
