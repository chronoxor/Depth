/*!
 *  \file    ARemoveCopyAll.hpp Contains general template implementation of
 *           the container remove and copy all items algorithm.
 *  \brief   Container remove and copy all items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container remove and copy all items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   16.05.2007 22:50:18

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
#ifndef __AREMOVECOPYALL_HPP__
#define __AREMOVECOPYALL_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/containers/AGetItLast.hpp>
#include <Depth/include/algorithms/iterators/AItRemoveCopyAll.hpp>
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
//! Algorithm: Container remove and copy all items.
/*!
    Important: All copied items will be appended  into  the  copy  container's
    end.

    \param a_rContainer - Reference to the container.
    \param a_rContainerCopy - Reference to the copy container.
    \return Count of removed items.
    \see NDepth::NAlgorithms::NIterators::removeCopyNext()
    \see NDepth::NAlgorithms::NIterators::removeCopyPrev()
*/
template <class T_Container, class T_ContainerCopy>
Tuint removeCopyAll(T_Container& a_rContainer, T_ContainerCopy& a_rContainerCopy);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container remove and copy all items with given value.
/*!
    Important: All copied items will be appended  into  the  copy  container's
    end.

    \param a_rContainer - Reference to the container.
    \param a_rContainerCopy - Reference to the copy container.
    \param a_crValue - Constant reference to the removing value.
    \return Count of removed items.
    \see NDepth::NAlgorithms::NIterators::removeCopyNext()
    \see NDepth::NAlgorithms::NIterators::removeCopyPrev()
*/
template <class T_Container, class T_ContainerCopy, typename T_ValueType>
Tuint removeCopyAll(T_Container& a_rContainer, T_ContainerCopy& a_rContainerCopy, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container remove and copy all items with given value using 'Equal' predicate.
/*!
    Important: All copied items will be appended  into  the  copy  container's
    end.

    \param a_rContainer - Reference to the container.
    \param a_rContainerCopy - Reference to the copy container.
    \param a_crValue - Constant reference to the removing value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of removed items.
    \see NDepth::NAlgorithms::NIterators::removeCopyNext()
    \see NDepth::NAlgorithms::NIterators::removeCopyPrev()
*/
template <class T_Container, class T_ContainerCopy, typename T_ValueType, typename T_BinaryPredicate>
Tuint removeCopyAll(T_Container& a_rContainer, T_ContainerCopy& a_rContainerCopy, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ARemoveCopyAll.inl>
/*==========================================================================*/
#endif
