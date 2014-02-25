/*!
 *  \file    AGetItFirst.inl Contains general template implementation of the
 *           get first container's iterator algorithm.
 *  \brief   Get first container's iterator algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Get first container's iterator algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   28.03.2007 00:04:52

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
#ifndef __AGETITFIRST_INL__
#define __AGETITFIRST_INL__
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
template <class T_Container>
inline typename NTraits::MTraitsContainer<T_Container>::iterator getItFirst(T_Container& a_rContainer)
{ CALL
  return NDetails::CGetItFirstHelper<(NTraits::MTraitsContainer<T_Container>::isTreeConst ? 1 :
                                     (NTraits::MTraitsContainer<T_Container>::isCircleDLConst ? 2 :
                                     (NTraits::MTraitsContainer<T_Container>::isCircleSLConst ? 3 :
                                     (NTraits::MTraitsContainer<T_Container>::isQueueConst ? 4 :
                                     (NTraits::MTraitsContainer<T_Container>::isStackConst ? 5 :
                                      0)))))>::getItFirst(a_rContainer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
