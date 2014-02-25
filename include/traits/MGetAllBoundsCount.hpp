/*!
 *  \file    MGetAllBoundsCount.hpp Traits meta-class that helps to get the
 *           number of dimensions possessed by an array type.
 *  \brief   Traits meta-class: array's dimensions receiving trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: array's dimensions receiving trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   14.12.2006 02:23:52

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
#ifndef __MGETALLBOUNDSCOUNT_HPP__
#define __MGETALLBOUNDSCOUNT_HPP__
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
//! Traits meta-class: array's dimensions receiving trait. General declaration for non array types.
/*!
    Traits meta-class helps to get the number of dimensions  possessed  by  an
    array type. Here comes some examples of using this trait:

    Expression:                                                  Result value:
    MGetAllBoundsCount<bool>::value                              0
    MGetAllBoundsCount<int[N]>::value                            1
    MGetAllBoundsCount<int[N][M]>::value                         2
*/
template <typename T_Type>
class MGetAllBoundsCount :
  public MType<T_Type>
{
public:
  //! Array's dimension is 0 for non array types.
  static const Tuint value = 0;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array's dimensions receiving trait. Array type with fixed size specialization.
template <typename T_Type, Tuint t_N>
class MGetAllBoundsCount<T_Type[t_N]> :
  public MType<T_Type[t_N]>
{
public:
  //! Array's dimension for the given array type with fixed size.
  static const Tuint value = 1 + MGetAllBoundsCount<T_Type>::value;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: array's dimensions receiving trait. Array type specialization.
template <typename T_Type>
class MGetAllBoundsCount<T_Type[]> :
  public MType<T_Type[]>
{
public:
  //! Array's dimension for the given array type.
  static const Tuint value = 1 + MGetAllBoundsCount<T_Type>::value;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
//! \example example-traits-MGetAllBoundsCount.cpp
/*--------------------------------------------------------------------------*/
//! \test test-traits-MGetAllBoundsCount.cpp
/*==========================================================================*/
#endif
