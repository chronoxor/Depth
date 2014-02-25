/*!
 *  \file    ASetsSubtractionCopy.hpp Contains general template
 *           implementation of the container subtraction and copy
 *           of two sets algorithm.
 *  \brief   Container subtraction and copy of two sets algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container subtraction and copy of two sets algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   18.08.2007 00:04:38

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
#ifndef __ASETSSUBTRACTIONCOPY_HPP__
#define __ASETSSUBTRACTIONCOPY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/containers/AGetItLast.hpp>
#include <Depth/include/algorithms/iterators/AItSetsSubtractionCopy.hpp>
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
//! Algorithm: Container subtraction and copy two set sequences.
/*!
    Important: All copied items will be appended  into  the  copy  container's
    end.

    \param a_rContainer1 - Reference to the first sorted container.
    \param a_rContainer2 - Reference to the second sorted container.
    \param a_rContainerCopy - Reference to the copy container.
    \return Count of copied items from the set subtraction.
    \see NDepth::NAlgorithms::NIterators::setSubtractionCopyNext()
    \see NDepth::NAlgorithms::NIterators::setSubtractionCopyPrev()
*/
template <class T_Container1, class T_Container2, class T_ContainerCopy>
Tuint setsSubtractionCopy(T_Container1& a_rContainer1, T_Container2& a_rContainer2, T_ContainerCopy& a_rContainerCopy);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container subtraction and copy two set sequences 'LessThan' predicate.
/*!
    Important: All copied items will be appended  into  the  copy  container's
    end.

    \param a_rContainer1 - Reference to the first sorted container.
    \param a_rContainer2 - Reference to the second sorted container.
    \param a_rContainerCopy - Reference to the copy container.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Count of copied items from the set subtraction.
    \see NDepth::NAlgorithms::NIterators::setSubtractionCopyNext()
    \see NDepth::NAlgorithms::NIterators::setSubtractionCopyPrev()
*/
template <class T_Container1, class T_Container2, class T_ContainerCopy, typename T_BinaryPredicate>
Tuint setsSubtractionCopy(T_Container1& a_rContainer1, T_Container2& a_rContainer2, T_ContainerCopy& a_rContainerCopy, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ASetsSubtractionCopy.inl>
/*==========================================================================*/
#endif
