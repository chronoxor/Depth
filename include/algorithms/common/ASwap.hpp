/*!
 *  \file    ASwap.hpp Contains general template implementation of the swap
 *           algorithm.
 *  \brief   Swap algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Swap algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   28.01.2006 01:03:25

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
#ifndef __ASWAP_HPP__
#define __ASWAP_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/details/ASwapHelper.hpp>
#include <Depth/include/traits/MIsClassOrUnion.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Swap two values.
/*!
    \param a_rFirst - Reference to the first value.
    \param a_rSecond - Reference to the second value.
*/
template <typename T_Type>
void swap(T_Type& a_rFirst, T_Type& a_rSecond);
/*--------------------------------------------------------------------------*/
//! Algorithm: Swap two buffer values.
/*!
    \param a_rFirst - Reference to the first buffer value.
    \param a_rSecond - Reference to the second buffer value.
    \param a_cSize - Size of the buffers.
*/
template <typename T_Type>
void swap(T_Type& a_rFirst, T_Type& a_rSecond, const Tuint a_cSize);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/common/ASwap.inl>
/*==========================================================================*/
#endif
