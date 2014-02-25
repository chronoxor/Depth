/*!
 *  \file    ARotate.hpp Contains general template implementation of the
 *           number rotating algorithms.
 *  \brief   Number rotating algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Number rotating algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Numeric algorithms
    VERSION:   1.0
    CREATED:   03.04.2006 22:17:27

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
#ifndef __AROTATE_HPP__
#define __AROTATE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptInteger.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NNumeric {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Cyclic rotate integer value to the left.
/*!
    \param a_crX - Constant reference to the integer value X.
    \param a_cLength - Rotate length.
    \return Rotated value.
*/
template <typename T_Type>
T_Type cyclicRotateLeft(const T_Type& a_crX, const Tuint a_cLength);
/*--------------------------------------------------------------------------*/
//! Algorithm: Cyclic rotate integer value to the right.
/*!
    \param a_crX - Constant reference to the integer value X.
    \param a_cLength - Rotate length.
    \return Rotated value.
*/
template <typename T_Type>
T_Type cyclicRotateRight(const T_Type& a_crX, const Tuint a_cLength);
/*--------------------------------------------------------------------------*/
//! Algorithm: Non-cyclic rotate integer value to the left.
/*!
    \param a_crX - Constant reference to the integer value X.
    \param a_cLength - Rotate length.
    \return Rotated value.
*/
template <typename T_Type>
T_Type rotateLeft(const T_Type& a_crX, const Tuint a_cLength);
/*--------------------------------------------------------------------------*/
//! Algorithm: Non-cyclic rotate integer value to the right.
/*!
    \param a_crX - Constant reference to the integer value X.
    \param a_cLength - Rotate length.
    \return Rotated value.
*/
template <typename T_Type>
T_Type rotateRight(const T_Type& a_crX, const Tuint a_cLength);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/numeric/ARotate.inl>
/*==========================================================================*/
#endif
