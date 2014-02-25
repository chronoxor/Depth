/*!
 *  \file    MRemoveBounds.hpp Traits meta-class that helps to remove array
 *           bounds from template parameter.
 *  \brief   Traits meta-class: removes array bounds.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: removes array bounds.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   09.03.2006 21:55:36

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
#ifndef __MREMOVEBOUNDS_HPP__
#define __MREMOVEBOUNDS_HPP__
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
//! Traits meta-class: removes array bounds.
/*!
    Traits meta-class removes array bounds from given type and put transformed
    type  to  the  result  meta-class  type.  Here  comes  some  examples   of
    transformations:

    Expression:                                                   Result type:
    MRemoveBounds<int>::type                                      int
    MRemoveBounds<int const[2]>::type                             int const
    MRemoveBounds<int[][2]>::type                                 int[2]
    MRemoveBounds<int[2][3][4]>::type                             int[3][4]
    MRemoveBounds<int const*>::type                               int const*
*/
template <typename T_Type>
class MRemoveBounds :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes array bounds (array specialization).
template <typename T_Type>
class MRemoveBounds<T_Type[]> :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes array bounds (constant array specialization).
template <typename T_Type>
class MRemoveBounds<const T_Type[]> :
  public MType<const T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes array bounds (volatile array specialization).
template <typename T_Type>
class MRemoveBounds<volatile T_Type[]> :
  public MType<volatile T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes array bounds (constant volatile array specialization).
template <typename T_Type>
class MRemoveBounds<const volatile T_Type[]> :
  public MType<const volatile T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes array bounds (indexed array specialization).
template <typename T_Type, Tuint t_N>
class MRemoveBounds<T_Type[t_N]> :
  public MType<T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes array bounds (indexed constant array specialization).
template <typename T_Type, Tuint t_N>
class MRemoveBounds<const T_Type[t_N]> :
  public MType<const T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes array bounds (indexed volatile array specialization).
template <typename T_Type, Tuint t_N>
class MRemoveBounds<volatile T_Type[t_N]> :
  public MType<volatile T_Type>
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: removes array bounds (indexed constant volatile array specialization).
template <typename T_Type, Tuint t_N>
class MRemoveBounds<const volatile T_Type[t_N]> :
  public MType<const volatile T_Type>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
