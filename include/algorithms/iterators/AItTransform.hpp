/*!
 *  \file    AItTransform.hpp Contains general template implementation of the
 *           iterator transform all items algorithm.
 *  \brief   Iterator transform all items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator transform all items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   24.05.2007 03:19:52

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
#ifndef __AITTRANSFORM_HPP__
#define __AITTRANSFORM_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/concept/functions/MConceptFunction1.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
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
//! Algorithm: Transform all forward iterator items next to the container's end.
/*!
    Algorithm transforms all items from the current forward  iterator  to  the
    container's end with the given unary transformation function.

    \param a_crIterator - Constant reference to the forward iterator.
    \param a_fFunction - Unary transformation function.
    \return Count of transformed items.
*/
template <class T_Iterator, typename T_UnaryFunction>
Tuint transformNext(const T_Iterator& a_crIterator, T_UnaryFunction a_fFunction);
/*--------------------------------------------------------------------------*/
//! Algorithm: Transform all backward iterator items back to the container's begin.
/*!
    Algorithm transforms all items from the current backward iterator  to  the
    container's begin with the given unary transformation function.

    \param a_crIterator - Constant reference to the backward iterator.
    \param a_fFunction - Unary transformation function.
    \return Count of transformed items.
*/
template <class T_Iterator, typename T_UnaryFunction>
Tuint transformPrev(const T_Iterator& a_crIterator, T_UnaryFunction a_fFunction);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItTransform.inl>
/*==========================================================================*/
#endif
