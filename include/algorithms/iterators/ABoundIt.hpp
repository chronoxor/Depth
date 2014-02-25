/*!
 *  \file    ABoundIt.hpp Iterator sequence bound algorithm.
 *  \brief   Iterator sequence bound algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator sequence bound algorithm.

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
#ifndef __ABOUNDIT_HPP__
#define __ABOUNDIT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/details/MBoundItHelper.hpp>
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
//! Algorithm: Bound iterator from the one side.
/*!
    This algorithm constructs and returns iterator sequence bound wrapper  for
    the current and the  end  iterators.  This  may  be  useful  for  applying
    algorithms for partial container's sequences.

    \param a_crCurrentIterator - Constant reference to the current iterator instance.
    \param a_crEndIterator - Constant reference to the end iterator instance.
    \return Bound iterator wrapper.
*/
template <class T_Iterator>
typename NDetails::MBoundItHelper<T_Iterator>::TBoundIteratorWrapper boundIt(const T_Iterator& a_crCurrentIterator, const T_Iterator& a_crEndIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Bound iterator from two sides (start, end).
/*!
    This algorithm constructs and returns  iterator  sequence  bound  wrapper.
    This may  be  useful  for  applying  algorithms  for  partial  container's
    sequences.

    \param a_crCurrentIterator - Constant reference to the current iterator instance.
    \param a_crStartIterator - Constant reference to the start iterator instance.
    \param a_crEndIterator - Constant reference to the end iterator instance.
    \return Bound iterator wrapper.
*/
template <class T_Iterator>
typename NDetails::MBoundItHelper<T_Iterator>::TBoundIteratorWrapper boundIt(const T_Iterator& a_crCurrentIterator, const T_Iterator& a_crStartIterator, const T_Iterator& a_crEndIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Bound forward iterator from the end side.
/*!
    This algorithm constructs and  returns  forward  iterator  sequence  bound
    wrapper.  This  may  be  useful  for  applying  algorithms   for   partial
    container's sequences.

    \param a_crCurrentIterator - Constant reference to the current forward iterator instance.
    \param a_crEndIterator - Constant reference to the end forward iterator instance.
    \return Bound forward iterator wrapper.
*/
template <class T_Iterator>
typename NDetails::MBoundItHelper<T_Iterator>::TBoundIteratorWrapper boundItForward(const T_Iterator& a_crCurrentIterator, const T_Iterator& a_crEndIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Bound backward iterator from the start side.
/*!
    This algorithm constructs and returns  backward  iterator  sequence  bound
    wrapper.  This  may  be  useful  for  applying  algorithms   for   partial
    container's sequences.

    \param a_crCurrentIterator - Constant reference to the current backward iterator instance.
    \param a_crStartIterator - Constant reference to the start backward iterator instance.
    \return Bound backward iterator wrapper.
*/
template <class T_Iterator>
typename NDetails::MBoundItHelper<T_Iterator>::TBoundIteratorWrapper boundItBackward(const T_Iterator& a_crCurrentIterator, const T_Iterator& a_crStartIterator);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/ABoundIt.inl>
/*==========================================================================*/
#endif
