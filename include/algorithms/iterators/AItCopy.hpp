/*!
 *  \file    AItCopy.hpp Contains general template implementation of the
 *           iterator copy algorithm.
 *  \brief   Iterator copy algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator copy algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   10.05.2007 22:06:23

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
#ifndef __AITCOPY_HPP__
#define __AITCOPY_HPP__
/*==========================================================================*/
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertBackward.hpp>
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
//! Algorithm: Forward iterator copy.
/*!
    Algorithm copies values of  one  sequence  represented  with  its  forward
    iterator into the another one.

    Important: This algorithm updates data under the copy sequence's  iterator
    so make sure to update its value after the algorithm returns.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_crIteratorCopy - Constant reference to the copy sequence's forward iterator.
    \return Count of copied items.
*/
template <class T_Iterator, class T_IteratorCopy>
Tuint copyNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator copy.
/*!
    Algorithm copies values of one  sequence  represented  with  its  backward
    iterator into the another one.

    Important: This algorithm updates data under the copy sequence's  iterator
    so make sure to update its value after the algorithm returns.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_crIteratorCopy - Constant reference to the copy sequence's backward iterator.
    \return Count of copied items.
*/
template <class T_Iterator, class T_IteratorCopy>
Tuint copyPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItCopy.inl>
/*==========================================================================*/
#endif
