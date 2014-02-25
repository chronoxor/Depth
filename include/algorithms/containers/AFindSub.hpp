/*!
 *  \file    AFindSub.hpp Contains general template implementation of the
 *           container find subsequence algorithm.
 *  \brief   Container find subsequence algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container find subsequence algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   15.04.2007 02:24:35

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
#ifndef __AFINDSUB_HPP__
#define __AFINDSUB_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItFindSub.hpp>
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
//! Algorithm: Find subsequence iterator with given value.
/*!
    \param a_rContainer - Reference to the container.
    \param a_rSubsequenceContainer - Reference to the subsequence container.
    \return Iterator to the subsequence begin, or invalid iterator.
    \see NDepth::NAlgorithms::NIterators::findSubNext()
    \see NDepth::NAlgorithms::NIterators::findSubPrev()
*/
template <class T_Container, class T_SubsequenceContainer>
typename NTraits::MTraitsContainer<T_Container>::iterator findSub(T_Container& a_rContainer, T_SubsequenceContainer& a_rSubsequenceContainer);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find subsequence iterator with given value using 'Equal' predicate.
/*!
    \param a_rContainer - Reference to the container.
    \param a_rSubsequenceContainer - Reference to the subsequence container.
    \param a_fEqual - 'Equal' binary predicate.
    \return Iterator to the subsequence end, or invalid iterator.
    \see NDepth::NAlgorithms::NIterators::findSubNext()
    \see NDepth::NAlgorithms::NIterators::findSubPrev()
*/
template <class T_Container, class T_SubsequenceContainer, typename T_BinaryPredicate>
typename NTraits::MTraitsContainer<T_Container>::iterator findSub(T_Container& a_rContainer, T_SubsequenceContainer& a_rSubsequenceContainer, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AFindSub.inl>
/*==========================================================================*/
//! \example example-algorithms-AFindSub.cpp
/*--------------------------------------------------------------------------*/
//! \test test-algorithms-AFindSub.cpp
/*==========================================================================*/
#endif
