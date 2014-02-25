/*!
 *  \file    AItFillN.hpp Contains general template implementation of the
 *           iterator fill N items algorithm.
 *  \brief   Iterator fill N items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator fill N items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   22.05.2007 22:21:56

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
#ifndef __AITFILLN_HPP__
#define __AITFILLN_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/details/CFillNHelper.hpp>
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
//! Algorithm: Fill N forward iterator items with the given value.
/*!
    Algorithm fills N items from the current forward  iterator.  If  container
    has less items than N, new items will be created if possible.

    \param a_crIterator - Constant reference to the forward iterator.
    \param a_cN - Count of requested items to fill.
    \param a_crValue - Constant reference to the filled value.
    \return Count of filled items.
*/
template <class T_Iterator, typename T_ValueType>
Tuint fillNNext(const T_Iterator& a_crIterator, const Tuint a_cN, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Fill N backward iterator items with the given value.
/*!
    Algorithm fills N items from the current backward iterator.  If  container
    has less items than N, new items will be created if possible.

    \param a_crIterator - Constant reference to the backward iterator.
    \param a_cN - Count of requested items to fill.
    \param a_crValue - Constant reference to the filled value.
    \return Count of filled items.
*/
template <class T_Iterator, typename T_ValueType>
Tuint fillNPrev(const T_Iterator& a_crIterator, const Tuint a_cN, const T_ValueType& a_crValue);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItFillN.inl>
/*==========================================================================*/
#endif
