/*!
 *  \file    AGetItRightmostChild.hpp Contains general template implementation
 *           of the get tree container's rightmost child iterator algorithm.
 *  \brief   Get tree container's rightmost child iterator algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Get tree container's rightmost child iterator algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template tree containers algorithms
    VERSION:   1.0
    CREATED:   29.03.2007 01:49:25

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
#ifndef __AGETITRIGHTMOSTCHILD_HPP__
#define __AGETITRIGHTMOSTCHILD_HPP__
/*==========================================================================*/
#include <Depth/include/concept/containers/MConceptTreeConst.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NTree {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Get tree container's rightmost child iterator algorithm.
/*!
    \param a_rTreeContainer - Reference to the tree container.
    \return Iterator to the tree container's rightmost child value, or invalid iterator.
*/
template <class T_TreeContainer>
typename NTraits::MTraitsContainer<T_TreeContainer>::iterator getItRightmostChild(T_TreeContainer& a_rTreeContainer);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/tree/AGetItRightmostChild.inl>
/*==========================================================================*/
#endif
