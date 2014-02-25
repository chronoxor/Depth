/*!
 *  \file    AReplaceIf.hpp Contains general template implementation of the
 *           container replace algorithm with given unary 'If' predicate.
 *  \brief   Container replace algorithm with given unary 'If' predicate.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container replace algorithm with given unary 'If' predicate.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   11.06.2007 23:00:32

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
#ifndef __AREPLACEIF_HPP__
#define __AREPLACEIF_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItReplaceIf.hpp>
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
//! Algorithm: Replace all container's items with the given value with given unary 'If' predicate.
/*!
    \param a_rContainer - Reference to the container.
    \param a_crNewValue - Constant reference to the new replaced value.
    \param a_fIf - Unary 'If' predicate.
    \return Count of replaced items.
    \see NDepth::NAlgorithms::NIterators::replaceIfNext()
    \see NDepth::NAlgorithms::NIterators::replaceIfPrev()
*/
template <class T_Container, typename T_NewValueType, typename T_UnaryIfPredicate>
Tuint replaceIf(T_Container& a_rContainer, const T_NewValueType& a_crNewValue, T_UnaryIfPredicate a_fIf);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AReplaceIf.inl>
/*==========================================================================*/
#endif
