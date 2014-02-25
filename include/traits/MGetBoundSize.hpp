/*!
 *  \file    MGetBoundSize.hpp Traits meta-class that helps to get the number
 *           of elements in the multidimensional array type.
 *  \brief   Traits meta-class: array's dimension size receiving trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: array's dimension size receiving trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   14.12.2006 21:57:27

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
#ifndef __MGETBOUNDSIZE_HPP__
#define __MGETBOUNDSIZE_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: array's dimension size receiving trait. General declaration for types without requested extent.
/*!
    Traits  meta-class  helps  to  get  the  number   of   elements   in   the
    multidimensional array type. Here comes some examples of using this trait:

    Expression:                                                  Result value:
    MGetBoundSize<bool, 0>::value                                0
    MGetBoundSize<int[], 0>::value                               0
    MGetBoundSize<int[N], 0>::value                              N
    MGetBoundSize<int[N][M], 0>::value                           N
    MGetBoundSize<int[N][M], 1>::value                           M
    MGetBoundSize<int[N][M], 2>::value                           0
*/
template <typename T_Type, Tuint t_Extent>
class MGetBoundSize :
  public MType<T_Type>
{
public:
  //! Requested array's dimension size is 0 for non array types.
  static const Tuint value = 0;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array's dimension size receiving trait. Array type with fixed size specialization.
template <typename T_Type, Tuint t_Extent, Tuint t_N>
class MGetBoundSize<T_Type[t_N], t_Extent> :
  public MType<T_Type[t_N]>
{
public:
  //! Requested array's dimension size for the given array type with fixed size.
  static const Tuint value = (t_Extent == 0) ? t_N : MGetBoundSize<T_Type, t_Extent - 1>::value;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array's dimension size receiving trait. Array type specialization.
template <typename T_Type, Tuint t_Extent>
class MGetBoundSize<T_Type[], t_Extent> :
  public MType<T_Type[]>
{
public:
  //! Requested array's dimension size for the given array type.
  static const Tuint value = (t_Extent == 0) ? 0 : MGetBoundSize<T_Type, t_Extent - 1>::value;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
//! \example example-traits-MGetBoundSize.cpp
/*--------------------------------------------------------------------------*/
//! \test test-traits-MGetBoundSize.cpp
/*==========================================================================*/
#endif
