/*!
 *  \file    AEqualSub.hpp Contains general template implementation of the
 *           container two subsequences equal test algorithm.
 *  \brief   Container two subsequences equal test algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container two subsequences equal test algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   31.03.2007 22:24:17

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
#ifndef __AEQUALSUB_HPP__
#define __AEQUALSUB_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItEqualSub.hpp>
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
//! Algorithm: Container two subsequences equal test.
/*!
    \param a_rContainer1 - Reference to the first container.
    \param a_rContainer2 - Reference to the second container.
    \return true  - if two subsequences are equal. \n
            false - if two subsequences are not equal. \n
    \see NDepth::NAlgorithms::NIterators::equalNext()
    \see NDepth::NAlgorithms::NIterators::equalPrev()
*/
template <class T_Container1, class T_Container2>
Tbool equalSub(T_Container1& a_rContainer1, T_Container2& a_rContainer2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container two subsequences equal test using 'Equal' predicate.
/*!
    \param a_rContainer1 - Reference to the first container.
    \param a_rContainer2 - Reference to the second container.
    \param a_fEqual - 'Equal' binary predicate.
    \return true  - if two subsequences are equal. \n
            false - if two subsequences are not equal. \n
    \see NDepth::NAlgorithms::NIterators::equalNext()
    \see NDepth::NAlgorithms::NIterators::equalPrev()
*/
template <class T_Container1, class T_Container2, typename T_BinaryPredicate>
Tbool equalSub(T_Container1& a_rContainer1, T_Container2& a_rContainer2, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AEqualSub.inl>
/*==========================================================================*/
#endif
