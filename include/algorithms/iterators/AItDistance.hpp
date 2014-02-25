/*!
 *  \file    AItDistance.hpp Contains general template implementation of the
 *           iterator distance algorithm.
 *  \brief   Iterator distance algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator distance algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   03.08.2006 02:37:23

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
#ifndef __AITDISTANCE_HPP__
#define __AITDISTANCE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/details/CDistanceHelper.hpp>
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Find distance to the container's end.
/*!
    Algorithm finds distance from current forward iterator to the  container's
    end.

    \param a_crIterator - Constant reference to the forward iterator.
    \return Distance from the iterator to the container's end.
*/
template <class T_Iterator>
Tuint distanceNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find distance to the container's begin.
/*!
    Algorithm finds distance from current backward iterator to the container's
    begin.

    \param a_crIterator - Constant reference to the backward iterator.
    \return Distance from the iterator to the container's begin.
*/
template <class T_Iterator>
Tuint distancePrev(const T_Iterator& a_crIterator);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItDistance.inl>
/*==========================================================================*/
#endif
