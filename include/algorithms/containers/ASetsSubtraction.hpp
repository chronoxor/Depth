/*!
 *  \file    ASetsSubtraction.hpp Contains general template implementation
 *           of the container subtraction of two sets algorithm.
 *  \brief   Container subtraction of two sets algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container subtraction of two sets algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   18.08.2007 23:58:08

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
#ifndef __ASETSSUBTRACTION_HPP__
#define __ASETSSUBTRACTION_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItSetsSubtraction.hpp>
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
//! Algorithm: Container subtraction two set sequences.
/*!
    \param a_rContainer1 - Reference to the first sorted container.
    \param a_rContainer2 - Reference to the second sorted container.
    \return true  - if subtraction operation completed successfully. \n
            false - if subtraction operation did not complete successfully. \n
    \see NDepth::NAlgorithms::NIterators::setsSubtractionNext()
    \see NDepth::NAlgorithms::NIterators::setsSubtractionPrev()
*/
template <class T_Container1, class T_Container2>
Tbool setsSubtraction(T_Container1& a_rContainer1, T_Container2& a_rContainer2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container subtraction two set sequences using 'LessThan' predicate.
/*!
    \param a_rContainer1 - Reference to the first sorted container.
    \param a_rContainer2 - Reference to the second sorted container.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return true  - if subtraction operation completed successfully. \n
            false - if subtraction operation did not complete successfully. \n
    \see NDepth::NAlgorithms::NIterators::setsSubtractionNext()
    \see NDepth::NAlgorithms::NIterators::setsSubtractionPrev()
*/
template <class T_Container1, class T_Container2, typename T_BinaryPredicate>
Tbool setsSubtraction(T_Container1& a_rContainer1, T_Container2& a_rContainer2, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ASetsSubtraction.inl>
/*==========================================================================*/
//! \example example-algorithms-ASetsSubtraction.cpp
/*--------------------------------------------------------------------------*/
//! \test test-algorithms-ASetsSubtraction.cpp
/*==========================================================================*/
#endif
