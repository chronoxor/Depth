/*!
 *  \file    ASwapRangesIf.hpp Contains general template implementation of the
 *           container two sequences swap ranges algorithm with given binary
 *           'If' predicate.
 *  \brief   Container two sequences swap ranges algorithm with given binary 'If' predicate.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container two sequences swap ranges algorithm with given binary 'If' predicate.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   10.05.2007 20:57:34

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
#ifndef __ASWAPRANGESIF_HPP__
#define __ASWAPRANGESIF_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItSwapRangesIf.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Container two sequences swap ranges with given binary 'If' predicate.
/*!
    \param a_rContainer1 - Reference to the first container.
    \param a_rContainer2 - Reference to the second container.
    \param a_fIf - Binary 'If' predicate.
    \return Count of swapped items.
    \see NDepth::NAlgorithms::NIterators::swapRangesIfNext()
    \see NDepth::NAlgorithms::NIterators::swapRangesIfPrev()
*/
template <class T_Container1, class T_Container2, typename T_BinaryIfPredicate>
Tuint swapRangesIf(T_Container1& a_rContainer1, T_Container2& a_rContainer2, T_BinaryIfPredicate a_fIf);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ASwapRangesIf.inl>
/*==========================================================================*/
#endif
