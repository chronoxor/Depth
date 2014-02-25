/*!
 *  \file    AGetWrappedArray.inl Contains general template implementation of
 *           the get wrapped array container algorithm.
 *  \brief   Get wrapped array container algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Get wrapped array container algorithm (inline).

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
#ifndef __AGETWRAPPEDARRAY_INL__
#define __AGETWRAPPEDARRAY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_Type>
inline NDepth::NContainers::CWrappedArray<T_Type> getWrappedArray(T_Type& a_rValue)
{ CALL
  return NDepth::NContainers::CWrappedArray<T_Type>(a_rValue);
}
/*--------------------------------------------------------------------------*/
template <class T_Type>
inline NDepth::NContainers::CWrappedArray<const T_Type> getWrappedArray(const T_Type& a_crValue)
{ CALL
  return NDepth::NContainers::CWrappedArray<const T_Type>(a_crValue);
}
/*--------------------------------------------------------------------------*/
template <class T_Type, Tuint t_Size>
inline NDepth::NContainers::CWrappedArray<T_Type> getWrappedArray(T_Type (&a_pArray)[t_Size])
{ CALL
  return NDepth::NContainers::CWrappedArray<T_Type>(a_pArray);
}
/*--------------------------------------------------------------------------*/
template <class T_Type, Tuint t_Size>
inline NDepth::NContainers::CWrappedArray<const T_Type> getWrappedArray(const T_Type (&a_cpArray)[t_Size])
{ CALL
  return NDepth::NContainers::CWrappedArray<const T_Type>(a_cpArray);
}
/*--------------------------------------------------------------------------*/
template <class T_Type>
inline NDepth::NContainers::CWrappedArray<T_Type> getWrappedArray(T_Type* a_pBuffer, const Tuint a_cSize)
{ CALL
  return NDepth::NContainers::CWrappedArray<T_Type>(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <class T_Type>
inline NDepth::NContainers::CWrappedArray<const T_Type> getWrappedArray(const T_Type* a_cpBuffer, const Tuint a_cSize)
{ CALL
  return NDepth::NContainers::CWrappedArray<const T_Type>(a_cpBuffer, a_cSize);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
