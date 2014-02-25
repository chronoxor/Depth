/*!
 *  \file    AFindSubN.hpp Contains general template implementation of the
 *           container find N'th subsequence algorithm.
 *  \brief   Container find N'th subsequence algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container find N'th subsequence algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   19.04.2007 00:05:39

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
#ifndef __AFINDSUBN_HPP__
#define __AFINDSUBN_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItFindSubN.hpp>
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
//! Algorithm: Find N'th subsequence iterator with given value.
/*!
    \param a_rContainer - Reference to the container.
    \param a_rSubsequenceContainer - Reference to the subsequence container.
    \param a_cN - The N'th count of the searching subsequence.
    \return Iterator to the N'th subsequence begin, or invalid iterator.
    \see NDepth::NAlgorithms::NIterators::findSubNNext()
    \see NDepth::NAlgorithms::NIterators::findSubNPrev()
*/
template <class T_Container, class T_SubsequenceContainer>
typename NTraits::MTraitsContainer<T_Container>::iterator findSubN(T_Container& a_rContainer, T_SubsequenceContainer& a_rSubsequenceContainer, const Tuint a_cN);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find N'th subsequence iterator with given value using 'Equal' predicate.
/*!
    \param a_rContainer - Reference to the container.
    \param a_rSubsequenceContainer - Reference to the subsequence container.
    \param a_cN - The N'th count of the searching subsequence.
    \param a_fEqual - 'Equal' binary predicate.
    \return Iterator to the N'th subsequence end, or invalid iterator.
    \see NDepth::NAlgorithms::NIterators::findSubNNext()
    \see NDepth::NAlgorithms::NIterators::findSubNPrev()
*/
template <class T_Container, class T_SubsequenceContainer, typename T_BinaryPredicate>
typename NTraits::MTraitsContainer<T_Container>::iterator findSubN(T_Container& a_rContainer, T_SubsequenceContainer& a_rSubsequenceContainer, const Tuint a_cN, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AFindSubN.inl>
/*==========================================================================*/
#endif
