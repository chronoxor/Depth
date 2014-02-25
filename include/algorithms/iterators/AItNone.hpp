/*!
 *  \file    AItNone.hpp Contains general template implementation of the
 *           check for none algorithm with given unary 'Check' predicate.
 *  \brief   Check for none algorithm with given unary 'Check' predicate.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Check for none algorithm with given unary 'Check' predicate.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   17.05.2007 20:22:12

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
#ifndef __AITNONE_HPP__
#define __AITNONE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItFindIf.hpp>
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
//! Algorithm: Forward iterator check for non items with given unary 'Check' predicate.
/*!
    Algorithm check if  forward  iterator  sequence  does  not  contain  items
    acceptable by the given unary predicate.

    In this algorithm unary 'Check'  predicate  should  return  'true'  if  it
    accepts the value and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_fCheck - Unary 'Check' predicate.
    \return true  - if the sequence does not contain acceptable items. \n
            false - if the sequence contains acceptable items. \n
*/
template <class T_Iterator, typename T_UnaryCheckPredicate>
Tbool noneNext(const T_Iterator& a_crIterator, T_UnaryCheckPredicate a_fCheck);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator check for none items with given unary 'Check' predicate.
/*!
    Algorithm check if backward  iterator  sequence  does  not  contain  items
    acceptable by the given unary predicate.

    In this algorithm unary 'Check'  predicate  should  return  'true'  if  it
    accepts the value and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_fCheck - Unary 'Check' predicate.
    \return true  - if the sequence does not contain acceptable items. \n
            false - if the sequence contains acceptable items. \n
*/
template <class T_Iterator, typename T_UnaryCheckPredicate>
Tbool nonePrev(const T_Iterator& a_crIterator, T_UnaryCheckPredicate a_fCheck);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItNone.inl>
/*==========================================================================*/
#endif
