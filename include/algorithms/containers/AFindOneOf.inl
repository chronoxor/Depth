/*!
 *  \file    AFindOneOf.inl Contains general template implementation of the
 *           container find one of algorithm.
 *  \brief   Container find one of algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container find one of algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   31.03.2007 22:28:53

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
#ifndef __AFINDONEOF_INL__
#define __AFINDONEOF_INL__
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
template <class T_Container, class T_MatchContainer>
inline typename NTraits::MTraitsContainer<T_Container>::iterator findOneOf(T_Container& a_rContainer, T_MatchContainer& a_rMatchContainer)
{ CALL
  return NIterators::findOneOfNext(getItFirst(a_rContainer), getItFirst(a_rMatchContainer));
}
/*--------------------------------------------------------------------------*/
template <class T_Container, class T_MatchContainer, typename T_BinaryPredicate>
inline typename NTraits::MTraitsContainer<T_Container>::iterator findOneOf(T_Container& a_rContainer, T_MatchContainer& a_rMatchContainer, T_BinaryPredicate a_fEqual)
{ CALL
  return NIterators::findOneOfNext(getItFirst(a_rContainer), getItFirst(a_rMatchContainer), a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
