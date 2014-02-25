/*!
 *  \file    ASortShell.hpp Contains general template implementation of the
 *           container shell sort algorithm.
 *  \brief   Container shell sort algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container shell sort algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   20.08.2007 21:13:49

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
#ifndef __ASORTSHELL_HPP__
#define __ASORTSHELL_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItSortShell.hpp>
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
//! Algorithm: Container sort items with shell algorithm.
/*!
    \param a_rContainer - Reference to the container.
    \return true  - if sort operation completed successfully. \n
            false - if sort operation did not complete successfully. \n
    \see NDepth::NAlgorithms::NIterators::sortShellNext()
    \see NDepth::NAlgorithms::NIterators::sortShellPrev()
*/
template <class T_Container>
Tbool sortShell(T_Container& a_rContainer);
/*--------------------------------------------------------------------------*/
//! Algorithm: Container sort items with shell algorithm using 'LessThan' predicate.
/*!
    \param a_rContainer - Reference to the container.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return true  - if sort operation completed successfully. \n
            false - if sort operation did not complete successfully. \n
    \see NDepth::NAlgorithms::NIterators::sortShellNext()
    \see NDepth::NAlgorithms::NIterators::sortShellPrev()
*/
template <class T_Container, typename T_BinaryPredicate>
Tbool sortShell(T_Container& a_rContainer, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ASortShell.inl>
/*==========================================================================*/
#endif
