/*!
 *  \file    AItGenerateN.hpp Contains general template implementation of the
 *           iterator generate N items algorithm.
 *  \brief   Iterator generate N items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator generate N items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   23.05.2007 22:13:30

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
#ifndef __AITGENERATEN_HPP__
#define __AITGENERATEN_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/details/CGenerateNHelper.hpp>
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
//! Algorithm: Generate N forward iterator items using the given generator.
/*!
    Algorithm  generates  N  items  from  the  current  forward  iterator.  If
    container has less items than N, new items will be created if possible.

    \param a_crIterator - Constant reference to the forward iterator.
    \param a_cN - Count of requested items to fill.
    \param a_fGenerator - Generator function.
    \return Count of generated items.
*/
template <class T_Iterator, typename T_Generator>
Tuint generateNNext(const T_Iterator& a_crIterator, const Tuint a_cN, T_Generator a_fGenerator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Generate N backward iterator items using the given generator.
/*!
    Algorithm generates  N  items  from  the  current  backward  iterator.  If
    container has less items than N, new items will be created if possible.

    \param a_crIterator - Constant reference to the backward iterator.
    \param a_cN - Count of requested items to fill.
    \param a_fGenerator - Generator function.
    \return Count of generated items.
*/
template <class T_Iterator, typename T_Generator>
Tuint generateNPrev(const T_Iterator& a_crIterator, const Tuint a_cN, T_Generator a_fGenerator);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItGenerateN.inl>
/*==========================================================================*/
#endif
