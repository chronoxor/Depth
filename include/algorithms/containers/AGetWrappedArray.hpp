/*!
 *  \file    AGetWrappedArray.hpp Contains general template implementation of
 *           the get wrapped array container algorithm.
 *  \brief   Get wrapped array container algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Get wrapped array container algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   25.04.2007 00:23:56

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
#ifndef __AGETWRAPPEDARRAY_HPP__
#define __AGETWRAPPEDARRAY_HPP__
/*==========================================================================*/
#include <Depth/include/containers/CWrappedArray.hpp>
#include <Depth/include/containers/CWrappedConstArray.hpp>
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
//! Algorithm: Get wrapped array container based on a single item.
/*!
    \param a_rValue - Initialize value.
    \return Wrapped array container.
*/
template <class T_Type>
NDepth::NContainers::CWrappedArray<T_Type> getWrappedArray(T_Type& a_rValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Get wrapped constant array container based on a single constant item.
/*!
    \param a_crValue - Initialize constant value.
    \return Wrapped constant array container.
*/
template <class T_Type>
NDepth::NContainers::CWrappedArray<const T_Type> getWrappedArray(const T_Type& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Get wrapped array container based on an array of fixed size.
/*!
    \param a_pArray - Pointer to the array of fixed size.
    \return Wrapped array container.
*/
template <class T_Type, Tuint t_Size>
NDepth::NContainers::CWrappedArray<T_Type> getWrappedArray(T_Type (&a_pArray)[t_Size]);
/*--------------------------------------------------------------------------*/
//! Algorithm: Get wrapped constant array container based on a constant array of fixed size.
/*!
    \param a_cpArray - Constant pointer to the array of fixed size.
    \return Wrapped constant array container.
*/
template <class T_Type, Tuint t_Size>
NDepth::NContainers::CWrappedArray<const T_Type> getWrappedArray(const T_Type (&a_cpArray)[t_Size]);
/*--------------------------------------------------------------------------*/
//! Algorithm: Get wrapped array container based on a buffer of given size.
/*!
    \param a_pBuffer - Pointer to the buffer.
    \param a_cSize - Buffer size.
    \return Wrapped array container.
*/
template <class T_Type>
NDepth::NContainers::CWrappedArray<T_Type> getWrappedArray(T_Type* a_pBuffer, const Tuint a_cSize);
/*--------------------------------------------------------------------------*/
//! Algorithm: Get wrapped constant array container based on a constant buffer of given size.
/*!
    \param a_cpBuffer - Constant pointer to the buffer.
    \param a_cSize - Buffer size.
    \return Wrapped constant array container.
*/
template <class T_Type>
NDepth::NContainers::CWrappedArray<const T_Type> getWrappedArray(const T_Type* a_cpBuffer, const Tuint a_cSize);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetWrappedArray.inl>
/*==========================================================================*/
#endif
